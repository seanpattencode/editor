# Time to first edit

Tentative but illustrative: how long from intent to editing?

Using world record typing speed (305 WPM = 39ms/keystroke):

| | typing | startup | total |
|---|---|---|---|
| e | ~50ms (e and Enter overlap) | 0ms | ~50ms |
| emacs | 234ms (6 keys) | 46ms | ~280ms |
| nvim | 195ms (5 keys) | 1008ms | ~1203ms |

These numbers are approximate. The key insight is that a 1-character name
lets you overlap the key and Enter into one fluid motion (~50ms), while
longer names require sequential keystrokes at any speed. Startup times
measured via bench/bench.sh (real TUI via pty, overhead subtracted).
