#!/bin/bash
# startup benchmark

bench() {
    name=$1
    cmd=$2
    command -v ${cmd%% *} >/dev/null || { echo "$name: not installed"; return; }
    echo "$name startup time (3 runs)"
    for i in 1 2 3; do
        start=$EPOCHREALTIME
        $cmd </dev/null >/dev/null 2>&1 & pid=$!
        sleep 0.001
        kill $pid 2>/dev/null
        end=$EPOCHREALTIME
        python3 -c "print(f'{$end - $start:.3f} s')"
    done
    echo ""
}

bench "e" ~/.local/bin/e
bench "vim" vim
bench "neovim" nvim
bench "emacs" "emacs -nw -Q"
