#!/bin/bash
# Realistic startup benchmark - measures time to first render

tmpf=$(mktemp)

echo "Editor startup+quit (time to render)"
echo "======================================"

# e - pty with actual render, quit with C-x C-c
start=$(date +%s.%N)
script -q -c "echo -ne '\x18\x03' | ./e demo.txt" /dev/null >/dev/null 2>&1
end=$(date +%s.%N)
printf "%-12s %.3f s\n" "e:" $(echo "$end - $start" | bc)

# neovim - real TUI in pty
start=$(date +%s.%N)
script -q -c "nvim +q demo.txt" /dev/null >/dev/null 2>&1
end=$(date +%s.%N)
printf "%-12s %.3f s\n" "neovim:" $(echo "$end - $start" | bc)

# emacs - real TUI in pty
start=$(date +%s.%N)
script -q -c "emacs -nw -Q demo.txt --eval '(kill-emacs)'" /dev/null >/dev/null 2>&1
end=$(date +%s.%N)
printf "%-12s %.3f s\n" "emacs:" $(echo "$end - $start" | bc)

# vscode - wait for window to actually appear
if command -v xdotool &>/dev/null; then
    start=$(date +%s.%N)
    code -n demo.txt &
    pid=$!
    while ! xdotool search --name "demo.txt" >/dev/null 2>&1; do sleep 0.05; done
    end=$(date +%s.%N)
    kill $pid 2>/dev/null; sleep 0.1; pkill -f "code.*demo" 2>/dev/null
    printf "%-12s %.3f s\n" "vscode:" $(echo "$end - $start" | bc)
else
    echo "vscode:      (install xdotool for window detection)"
fi

rm -f "$tmpf"
