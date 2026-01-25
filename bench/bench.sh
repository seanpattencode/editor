#!/bin/bash
# startup benchmark

TMP=/tmp/e_bench_$$
sed 's/lastflag = 0;/update(); _exit(0);/' ~/projects/editor/e.c > $TMP.c
gcc -w -std=gnu89 -O2 -o $TMP $TMP.c 2>/dev/null

bench() {
    name=$1; cmd=$2
    printf "%-10s " "$name"
    for i in 1 2 3 4 5; do
        start=$EPOCHREALTIME
        $cmd </dev/null >/dev/null 2>&1
        end=$EPOCHREALTIME
        python3 -c "print(f'{($end - $start)*1000:.1f}', end=' ')"
    done
    echo "ms"
}

bench "e" $TMP
bench "nvim" "nvim --headless -c q"
bench "emacs" "emacs --batch -Q"

rm -f $TMP $TMP.c
