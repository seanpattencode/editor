#!/bin/bash
# startup benchmark — real TUI startup via pty

TMP=/tmp/e_bench_$$
sed 's/lastflag = 0;/update(); _exit(0);/' ~/projects/editor/e.c > $TMP.c
gcc -w -std=gnu89 -O2 -o $TMP $TMP.c 2>/dev/null

# install missing editors
command -v emacs >/dev/null || { command -v micromamba >/dev/null && micromamba install -y -n base emacs 2>/dev/null; }

# measure pty overhead
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
command -v nvim >/dev/null && bench "nvim" nvim -c q
command -v emacs >/dev/null && bench "emacs" "emacs -nw --eval '(kill-emacs)'"

rm -f $TMP $TMP.c
