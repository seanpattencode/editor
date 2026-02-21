#!/bin/bash
# startup benchmark — hyperfine + pty fallback

DIR="$(cd "$(dirname "$0")/.." && pwd)"
TMP=/tmp/e_bench_$$

CC=$(compgen -c clang- 2>/dev/null|grep -xE 'clang-[0-9]+'|sort -t- -k2 -rn|head -1)||CC=""
[[ -z "$CC" ]]&&for c in clang gcc;do command -v $c &>/dev/null&&CC=$c&&break;done
[[ -z "$CC" ]]&&echo "no C compiler"&&exit 1

sed 's/lastflag = 0;/update(); _exit(0);/' "$DIR/e.c" > $TMP.c
$CC -w -std=gnu89 -O3 -march=native -flto -o $TMP $TMP.c 2>/dev/null

if command -v hyperfine >/dev/null 2>&1; then
    # precise measurement, no shell overhead
    cmds=("$TMP" "$TMP $DIR/e.c")
    labels=("e" "e (5.6k file)")
    command -v nano  >/dev/null && { cmds+=("nano --help");  labels+=("nano --help"); }
    command -v micro >/dev/null && { cmds+=("micro -version"); labels+=("micro -version"); }
    command -v nvim  >/dev/null && { cmds+=("nvim -c q" "nvim -c q $DIR/e.c"); labels+=("nvim" "nvim (5.6k file)"); }
    args=(--warmup 3 --min-runs 10 -N)
    for i in "${!cmds[@]}"; do
        args+=(-n "${labels[$i]}" "${cmds[$i]}")
    done
    hyperfine "${args[@]}"

    # editors that need a real tty — wrap in script(1)
    command -v emacs >/dev/null &&
        hyperfine --warmup 1 --min-runs 5 -n emacs \
            "script -qec \"emacs -nw -Q --eval '(kill-emacs)'\" /dev/null"
    command -v vi >/dev/null &&
        hyperfine --warmup 1 --min-runs 5 -n vi \
            "script -qec 'vi -c q' /dev/null"
else
    # fallback: pty-based measurement
    OVH=0; for i in 1 2 3; do
        s=$EPOCHREALTIME; script -qec true /dev/null </dev/null >/dev/null 2>&1; e=$EPOCHREALTIME
        OVH=$(python3 -c "print(max($OVH,($e-$s)*1000))")
    done
    bench() {
        name=$1; shift
        printf "%-10s " "$name"
        for i in 1 2 3 4 5; do
            start=$EPOCHREALTIME
            script -qec "$*" /dev/null </dev/null >/dev/null 2>&1
            end=$EPOCHREALTIME
            python3 -c "print(f'{max(0,($end-$start)*1000-$OVH):.1f}', end=' ')"
        done
        echo "ms"
    }
    bench "e" $TMP
    bench "e (file)" "$TMP $DIR/e.c"
    command -v nano  >/dev/null && bench "nano"  nano --help
    command -v micro >/dev/null && bench "micro" micro -version
    command -v nvim  >/dev/null && bench "nvim"  nvim -c q
    command -v nvim  >/dev/null && bench "nvim (file)" nvim -c q "$DIR/e.c"
    command -v emacs >/dev/null && bench "emacs" "emacs -nw --eval '(kill-emacs)'"
    command -v vi    >/dev/null && bench "vi"    vi -c q
fi

rm -f $TMP $TMP.c
