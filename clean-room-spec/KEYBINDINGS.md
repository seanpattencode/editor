# Default Key Bindings Reference

This document lists all default key bindings for the micro emacs editor.

## Notation

| Notation | Meaning |
|----------|---------|
| C-x | Hold Ctrl and press x |
| M-x | Press Esc, release, press x (or hold Alt and press x) |
| C-x C-y | Ctrl-x followed by Ctrl-y |
| C-x y | Ctrl-x followed by y (no Ctrl) |

---

## Movement

### Character Movement
| Key | Command | Description |
|-----|---------|-------------|
| C-f | forward-char | Move forward one character |
| C-b | backward-char | Move backward one character |
| C-n | next-line | Move to next line |
| C-p | previous-line | Move to previous line |

### Word Movement
| Key | Command | Description |
|-----|---------|-------------|
| M-f | forward-word | Move to end of word |
| M-b | backward-word | Move to beginning of word |

### Line Movement
| Key | Command | Description |
|-----|---------|-------------|
| C-a | beginning-of-line | Move to line start |
| C-e | end-of-line | Move to line end |
| M-g | goto-line | Go to specific line number |

### Paragraph Movement
| Key | Command | Description |
|-----|---------|-------------|
| M-n | forward-paragraph | Move to next paragraph |
| M-p | backward-paragraph | Move to previous paragraph |

### Page Movement
| Key | Command | Description |
|-----|---------|-------------|
| C-v | scroll-down | Scroll down one page |
| C-z | scroll-up | Scroll up one page |
| M-v | scroll-up | Scroll up one page (alternate) |

### Buffer Movement
| Key | Command | Description |
|-----|---------|-------------|
| M-< | beginning-of-buffer | Move to buffer start |
| M-> | end-of-buffer | Move to buffer end |

---

## Deletion

### Character Deletion
| Key | Command | Description |
|-----|---------|-------------|
| C-d | delete-char | Delete character at point |
| C-h | delete-backward-char | Delete character before point |
| DEL | delete-backward-char | Delete character before point |
| Backspace | delete-backward-char | Delete character before point |

### Word Deletion
| Key | Command | Description |
|-----|---------|-------------|
| M-d | kill-word | Delete to end of word |
| M-DEL | backward-kill-word | Delete to start of word |
| M-C-h | backward-kill-word | Delete to start of word |

### Line Deletion
| Key | Command | Description |
|-----|---------|-------------|
| C-k | kill-line | Kill to end of line |
| C-x C-o | delete-blank-lines | Delete blank lines around point |

### Region Deletion
| Key | Command | Description |
|-----|---------|-------------|
| C-w | kill-region | Kill text between point and mark |
| M-w | copy-region | Copy text between point and mark |

---

## Insertion

| Key | Command | Description |
|-----|---------|-------------|
| C-m | newline | Insert newline |
| Enter | newline | Insert newline |
| C-j | newline-and-indent | Insert newline and indent |
| C-o | open-line | Insert newline, don't move |
| C-q | quoted-insert | Insert next character literally |
| C-y | yank | Insert killed text |
| C-c | insert-space | Insert a space |
| C-i | insert-tab | Insert a tab |
| Tab | insert-tab | Insert a tab |

---

## Region and Mark

| Key | Command | Description |
|-----|---------|-------------|
| M-Space | set-mark | Set mark at current point |
| M-. | set-mark | Set mark at current point |
| C-x C-x | exchange-point-and-mark | Swap point and mark |

---

## Search and Replace

| Key | Command | Description |
|-----|---------|-------------|
| C-s | search-forward | Search forward |
| M-s | search-forward | Search forward (alternate) |
| C-r | search-backward | Search backward |
| M-r | replace-string | Search and replace |
| M-C-r | query-replace | Interactive search and replace |
| C-x s | isearch-forward | Incremental search forward |
| C-x r | isearch-backward | Incremental search backward |

---

## Files

| Key | Command | Description |
|-----|---------|-------------|
| C-x C-f | find-file | Open file |
| C-x C-r | read-file | Read file (replace buffer) |
| C-x C-s | save-buffer | Save current buffer |
| C-x C-d | save-buffer | Save current buffer (alternate) |
| C-x C-w | write-file | Save to new filename |
| C-x C-i | insert-file | Insert file at point |
| C-x C-v | view-file | Open file read-only |
| C-x n | set-filename | Change buffer's filename |

---

## Buffers

| Key | Command | Description |
|-----|---------|-------------|
| C-x b | switch-to-buffer | Switch to named buffer |
| C-x x | next-buffer | Switch to next buffer |
| C-x k | kill-buffer | Delete a buffer |
| C-x C-b | list-buffers | Display buffer list |
| M-C-n | name-buffer | Rename current buffer |

---

## Windows

| Key | Command | Description |
|-----|---------|-------------|
| C-x 2 | split-window | Split window vertically |
| C-x 1 | delete-other-windows | Keep only current window |
| C-x 0 | delete-window | Delete current window |
| C-x o | other-window | Move to next window |
| C-x p | previous-window | Move to previous window |
| C-x ^ | enlarge-window | Grow window by one line |
| C-x z | enlarge-window | Grow window by one line |
| C-x C-z | shrink-window | Shrink window by one line |
| C-x C-n | scroll-down-other | Scroll other window down |
| C-x C-p | scroll-up-other | Scroll other window up |
| M-C-v | scroll-other-down | Scroll other window down |
| M-C-z | scroll-other-up | Scroll other window up |

---

## Screen

| Key | Command | Description |
|-----|---------|-------------|
| C-l | recenter | Redraw screen, center point |
| M-C-l | redraw-display | Redraw entire display |
| M-C-d | set-screen-size | Change screen height |
| M-C-t | set-screen-width | Change screen width |

---

## Modes

| Key | Command | Description |
|-----|---------|-------------|
| C-x m | add-mode | Enable buffer mode |
| C-x C-m | delete-mode | Disable buffer mode |
| M-m | add-global-mode | Enable global mode |
| M-C-m | delete-global-mode | Disable global mode |

---

## Macros

| Key | Command | Description |
|-----|---------|-------------|
| C-x ( | start-macro | Begin recording |
| C-x ) | end-macro | Stop recording |
| C-x e | execute-macro | Play back macro |

---

## Help and Information

| Key | Command | Description |
|-----|---------|-------------|
| M-? | help | Show help screen |
| C-x ? | describe-key | Show what key does |
| C-x = | what-cursor-position | Show cursor position info |
| M-a | apropos | Search for commands |

---

## Key Binding Management

| Key | Command | Description |
|-----|---------|-------------|
| M-k | bind-to-key | Bind key to command |
| M-C-k | unbind-key | Remove key binding |

---

## Case Conversion

| Key | Command | Description |
|-----|---------|-------------|
| M-u | upcase-word | Uppercase word |
| M-l | downcase-word | Lowercase word |
| M-c | capitalize-word | Capitalize word |
| C-x C-u | upcase-region | Uppercase region |
| C-x C-l | downcase-region | Lowercase region |

---

## Transposition

| Key | Command | Description |
|-----|---------|-------------|
| C-t | transpose-chars | Swap chars around point |

---

## Formatting

| Key | Command | Description |
|-----|---------|-------------|
| C-x f | set-fill-column | Set fill column |
| M-q | fill-paragraph | Fill/wrap paragraph |
| M-j | justify-paragraph | Justify paragraph |
| C-x C-t | trim-line | Remove trailing whitespace |

---

## Shell Access

| Key | Command | Description |
|-----|---------|-------------|
| C-x ! | shell-command | Run shell command |
| C-x c | spawn-shell | Start interactive shell |
| C-x @ | pipe-command | Run command, capture output |
| C-x # | filter-buffer | Filter buffer through command |
| C-x $ | execute-program | Run program |
| C-x d | suspend | Suspend editor (return to shell) |

---

## Miscellaneous

| Key | Command | Description |
|-----|---------|-------------|
| C-g | abort | Abort current operation |
| C-u | universal-argument | Provide numeric argument |
| M-x | execute-named-command | Run command by name |
| C-] | meta-prefix | Alternate meta prefix |
| M-~ | unmark-buffer | Clear modified flag |

---

## Exit

| Key | Command | Description |
|-----|---------|-------------|
| C-x C-c | quit | Exit editor |
| M-z | quick-exit | Save all and exit |

---

## Variables and Scripting

| Key | Command | Description |
|-----|---------|-------------|
| C-x a | set-variable | Set a variable |
| M-C-a | set-variable | Set a variable (alternate) |
| M-C-e | execute-procedure | Run a named procedure |
| M-e | set-encryption-key | Set file encryption key |
| M-C-c | word-count | Count words in region |

---

## Special Keys (Terminal Dependent)

| Key | Command |
|-----|---------|
| Up Arrow | previous-line |
| Down Arrow | next-line |
| Left Arrow | backward-char |
| Right Arrow | forward-char |
| Home | beginning-of-line |
| End | end-of-line |
| Page Up | scroll-up |
| Page Down | scroll-down |
| Insert | yank |
| Delete | delete-char |

---

*End of Key Bindings Reference*
