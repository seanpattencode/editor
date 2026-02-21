#!/bin/bash
# startup benchmark — hyperfine + pty fallback

DIR="$(cd "$(dirname "$0")/.." && pwd)"
TMP=/tmp/e_bench_$$

CC=$(compgen -c clang- 2>/dev/null|grep -xE 'clang-[0-9]+'|sort -t- -k2 -rn|head -1)||CC=""
[[ -z "$CC" ]]&&for c in clang gcc;do command -v $c &>/dev/null&&CC=$c&&break;done
[[ -z "$CC" ]]&&echo "no C compiler"&&exit 1

sed 's/lastflag = 0;/update(); _exit(0);/' "$DIR/e.c" > $TMP.c
$CC -w -std=gnu89 -O3 -march=native -flto -o $TMP $TMP.c 2>/dev/null

# build uemacs (torvalds) once, cache at /tmp/uemacs_bench
UE=/tmp/uemacs_bench
if [[ ! -x "$UE" ]]; then
    UD=/tmp/uemacs
    [[ -d "$UD" ]] || timeout 5 git clone --depth 1 -q https://github.com/torvalds/uemacs "$UD" 2>/dev/null
    if [[ -d "$UD" ]]; then
        cat > "$UD/hstub.h" << 'STUB'
typedef void Hunhandle;
static inline Hunhandle*Hunspell_create(const char*a,const char*d){return(void*)0;}
static inline int Hunspell_spell(Hunhandle*h,const char*w){return 1;}
static inline void Hunspell_add_dic(Hunhandle*h,const char*f){}
STUB
        sed -i 's|LIBS=ncurses hunspell|LIBS=ncurses|;' "$UD/Makefile"
        sed -i 's|#include <hunspell.h>|#include "hstub.h"|' "$UD/main.c"
        timeout 5 make -C "$UD" -j$(nproc) -s 2>/dev/null && cp "$UD/em" "$UE"
    fi
fi

if command -v hyperfine >/dev/null 2>&1; then
    cmds=("$TMP" "$TMP $DIR/e.c" "ls $DIR")
    labels=("e" "e (5.6k file)" "ls")
    command -v nano  >/dev/null && { cmds+=("nano --help");  labels+=("nano"); }
    command -v micro >/dev/null && { cmds+=("micro -version"); labels+=("micro"); }
    command -v nvim  >/dev/null && { cmds+=("nvim -c q" "nvim -c q $DIR/e.c"); labels+=("nvim" "nvim (5.6k file)"); }
    command -v vi    >/dev/null && { cmds+=("printf '\\x1b:q\\n' | vi"); labels+=("vi"); }
    command -v emacs >/dev/null && { cmds+=("emacs -nw -Q --eval '(kill-emacs)'"); labels+=("emacs"); }
    [[ -x "$UE" ]] && { cmds+=("printf '\\x18\\x03' | $UE"); labels+=("uemacs"); }
    args=(--warmup 3 --min-runs 10 -N)
    for i in "${!cmds[@]}"; do
        args+=(-n "${labels[$i]}" "${cmds[$i]}")
    done
    timeout 60 hyperfine "${args[@]}"
else
    # fallback: direct timing
    bench() {
        name=$1; shift
        printf "%-16s " "$name"
        for i in 1 2 3 4 5; do
            start=$EPOCHREALTIME
            timeout 2 bash -c "$*" </dev/null >/dev/null 2>&1
            end=$EPOCHREALTIME
            python3 -c "print(f'{($end-$start)*1000:.1f}', end=' ')"
        done
        echo "ms"
    }
    bench "e" "$TMP"
    bench "e (file)" "$TMP $DIR/e.c"
    bench "ls" "ls $DIR"
    command -v nano  >/dev/null && bench "nano"  "nano --help"
    command -v micro >/dev/null && bench "micro" "micro -version"
    command -v nvim  >/dev/null && bench "nvim"  "nvim -c q"
    command -v nvim  >/dev/null && bench "nvim (file)" "nvim -c q $DIR/e.c"
    command -v vi    >/dev/null && bench "vi"    "printf '\\x1b:q\\n' | vi"
    command -v emacs >/dev/null && bench "emacs" "emacs -nw -Q --eval '(kill-emacs)'"
    [[ -x "$UE" ]] && bench "uemacs" "printf '\\x18\\x03' | $UE"
fi

rm -f $TMP $TMP.c
