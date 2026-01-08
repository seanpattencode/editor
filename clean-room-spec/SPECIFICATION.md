# Micro Emacs Editor - Clean Room Technical Specification

**Version:** 1.0
**Purpose:** This document specifies the functional requirements for implementing a micro emacs-style text editor from scratch without reference to existing implementations.

---

## 1. Overview

### 1.1 Product Description

A lightweight, terminal-based text editor following the Emacs keybinding conventions. The editor provides:

- Multi-buffer editing
- Multiple windows (split views)
- Modal-less editing with chord-based commands
- Search and replace with regular expressions
- Keyboard macro recording and playback
- UTF-8 text support

### 1.2 Design Goals

1. **Fast startup** - Sub-10ms cold start
2. **Low memory footprint** - Minimal RAM usage
3. **Portability** - POSIX-compliant systems
4. **Single binary** - No external dependencies except curses/terminfo
5. **Responsive** - No perceptible lag on any operation

### 1.3 Non-Goals

- Syntax highlighting
- Plugin/extension system
- Mouse support
- GUI interface
- Undo/redo (optional enhancement)

---

## 2. Core Concepts

### 2.1 Text Storage Model

#### 2.1.1 Line Structure

Text is organized as a doubly-linked list of lines. Each line contains:

- Forward pointer to next line
- Backward pointer to previous line
- Allocated size (capacity)
- Used size (actual character count)
- Character array (the text content)

Lines do NOT store the newline character; it is implicit between lines.

#### 2.1.2 Line Operations

| Operation | Description |
|-----------|-------------|
| Allocate | Create a new line with specified initial capacity |
| Free | Deallocate a line and remove from list |
| Insert char | Insert character(s) at position, growing if needed |
| Delete char | Remove character(s) from position |
| Split | Break line at position, creating new line for remainder |
| Join | Merge line with following line |

### 2.2 Buffer Model

A buffer is a named container for text being edited.

#### 2.2.1 Buffer Properties

| Property | Description |
|----------|-------------|
| Name | Unique identifier (e.g., "main.c") |
| Filename | Associated file path, or empty if unsaved |
| Line list | Pointer to header line (circular list) |
| Dot | Current cursor position (line + offset) |
| Mark | Saved position for region operations |
| Flags | Modified, read-only, invisible, truncated |
| Modes | Active editing modes (bitmask) |
| Window count | Number of windows displaying this buffer |

#### 2.2.2 Buffer Modes

| Mode | Description |
|------|-------------|
| WRAP | Auto-wrap long lines at fill column |
| CMODE | C language indentation assistance |
| EXACT | Case-sensitive searching |
| VIEW | Read-only viewing |
| OVER | Overwrite mode (replace instead of insert) |
| MAGIC | Enable regex in search patterns |
| CRYPT | File encryption enabled |

#### 2.2.3 Special Buffers

- **[List]** - Buffer listing display
- **[Help]** - Help text display
- Buffers starting with `[` are invisible to normal buffer commands

### 2.3 Window Model

A window is a viewport into a buffer, displayed on a portion of the screen.

#### 2.3.1 Window Properties

| Property | Description |
|----------|-------------|
| Buffer | The buffer being displayed |
| Top line | First line visible in window |
| Dot | Cursor position (line + offset) |
| Mark | Selection anchor point |
| Top row | Screen row where window starts |
| Height | Number of text rows in window |
| Flags | Redraw hints (force, move, edit, hard, mode) |

#### 2.3.2 Window Layout

Windows are arranged vertically in a single column. Each window has:
- A text area showing buffer content
- A mode line (status bar) at the bottom

The bottom of the screen has a message line for prompts and feedback.

```
+----------------------------------+
| Window 1: text area              |
|                                  |
| == mode line for window 1 ====== |
| Window 2: text area              |
|                                  |
| == mode line for window 2 ====== |
| Message/prompt line              |
+----------------------------------+
```

### 2.4 Point and Mark

- **Point (Dot)**: The current cursor position
- **Mark**: A saved position set by the user
- **Region**: The text between point and mark

The region is used for operations like copy, cut, and case conversion.

### 2.5 Kill Ring

A single kill buffer stores deleted/copied text for later yanking (pasting).

- Kill operations append to the buffer if consecutive
- Non-kill commands reset the append behavior
- Kill buffer is stored as linked chunks for efficiency

---

## 3. Terminal Interface

### 3.1 Abstract Terminal Operations

The editor communicates with the terminal through an abstraction layer:

| Operation | Description |
|-----------|-------------|
| Open | Initialize terminal for editing |
| Close | Restore terminal to normal state |
| Move | Position cursor at (row, col) |
| Put char | Output a character at cursor |
| Clear EOL | Clear from cursor to end of line |
| Clear EOP | Clear from cursor to end of page |
| Beep | Audible or visible bell |
| Flush | Ensure output is sent to terminal |
| Get char | Read one character from keyboard |
| Set reverse | Enable/disable reverse video |

### 3.2 Screen Dimensions

| Property | Description |
|----------|-------------|
| Max rows | Maximum supported rows |
| Current rows | Actual rows in use |
| Max cols | Maximum supported columns |
| Current cols | Actual columns in use |

The editor should respond to terminal resize signals (SIGWINCH).

### 3.3 Keyboard Input

#### 3.3.1 Key Encoding

Keys are encoded as integers with modifier flags:

| Modifier | Description |
|----------|-------------|
| CONTROL | Ctrl key held (0x10000000) |
| META | Meta/Alt/Esc prefix (0x20000000) |
| CTLX | Ctrl-X prefix (0x40000000) |
| SPEC | Special/function key (0x80000000) |

#### 3.3.2 Special Keys

Function keys, arrow keys, and other special keys are encoded with the SPEC flag plus an identifier:

- Arrow keys: mapped to movement commands
- Function keys F1-F12: available for binding
- Insert, Delete, Home, End, PageUp, PageDown

#### 3.3.3 Meta Key Handling

If the terminal doesn't have a Meta key:
1. Escape acts as a Meta prefix
2. User presses Esc, releases, then presses the next key
3. The combination is treated as Meta + key

---

## 4. Display System

### 4.1 Virtual Screen

Maintain a virtual screen buffer to minimize actual terminal I/O:

- Track what is currently displayed on each cell
- Compare with desired content before updating
- Only send changes to the terminal

### 4.2 Display Update Algorithm

1. For each window, determine visible lines
2. Render each line to virtual screen
3. Handle long lines (extend right, show $ indicator)
4. Update mode line for each window
5. Compare virtual screen to physical screen
6. Send minimal updates to terminal
7. Position cursor at point

### 4.3 Mode Line Format

```
= Buffer: name == File: filename == Line: N/M == Col: C == Mode flags ==
```

Contents:
- Buffer name
- Filename (or [No File])
- Current line / total lines
- Current column
- Modified indicator (*)
- Active modes (WRAP, VIEW, etc.)

### 4.4 Long Line Handling

When a line extends beyond the screen:
- Display visible portion
- Show `$` at right edge to indicate continuation
- Allow horizontal scrolling via cursor movement

### 4.5 Tab Display

- Tab characters advance to next tab stop
- Default tab width: 8 characters
- Configurable tab width (4 or 8)

---

## 5. Command System

### 5.1 Command Binding

Commands are bound to key sequences. A key binding table maps:
- Key code (with modifiers) → Function pointer

Default bindings follow Emacs conventions.

### 5.2 Command Execution

Each command function receives:
- **f**: Flag indicating if argument was provided
- **n**: Numeric argument (default 1)

Commands return:
- TRUE: Success
- FALSE: Failure (operation not completed)
- ABORT: User cancelled (Ctrl-G)

### 5.3 Universal Argument

`Ctrl-U` provides a numeric argument to commands:
- `Ctrl-U` alone: multiply by 4
- `Ctrl-U N`: use N as argument
- Negative arguments reverse direction

### 5.4 Command Categories

#### 5.4.1 Movement Commands

| Command | Binding | Description |
|---------|---------|-------------|
| Forward char | Ctrl-F | Move right one character |
| Backward char | Ctrl-B | Move left one character |
| Next line | Ctrl-N | Move down one line |
| Previous line | Ctrl-P | Move up one line |
| Forward word | Meta-F | Move to end of word |
| Backward word | Meta-B | Move to start of word |
| Begin of line | Ctrl-A | Move to line start |
| End of line | Ctrl-E | Move to line end |
| Forward para | Meta-N | Move to next paragraph |
| Backward para | Meta-P | Move to previous paragraph |
| Forward page | Ctrl-V | Scroll down one page |
| Backward page | Ctrl-Z | Scroll up one page |
| Begin of buffer | Meta-< | Move to buffer start |
| End of buffer | Meta-> | Move to buffer end |
| Go to line | Meta-G | Jump to line number |

#### 5.4.2 Editing Commands

| Command | Binding | Description |
|---------|---------|-------------|
| Insert char | (self) | Insert typed character |
| Newline | Ctrl-M | Insert line break |
| Open line | Ctrl-O | Insert line break, stay put |
| Delete forward | Ctrl-D | Delete character at point |
| Delete backward | Ctrl-H, DEL | Delete character before point |
| Kill word forward | Meta-D | Kill to end of word |
| Kill word backward | Meta-DEL | Kill to start of word |
| Kill line | Ctrl-K | Kill to end of line |
| Kill region | Ctrl-W | Kill text in region |
| Copy region | Meta-W | Copy region to kill buffer |
| Yank | Ctrl-Y | Insert killed text |
| Transpose chars | Ctrl-T | Swap character before and at point |
| Set mark | Meta-Space | Set mark at point |
| Exchange mark | Ctrl-X Ctrl-X | Swap point and mark |

#### 5.4.3 File Commands

| Command | Binding | Description |
|---------|---------|-------------|
| Find file | Ctrl-X Ctrl-F | Open file in buffer |
| Read file | Ctrl-X Ctrl-R | Replace buffer with file |
| Save buffer | Ctrl-X Ctrl-S | Write buffer to file |
| Write file | Ctrl-X Ctrl-W | Write buffer to new file |
| Insert file | Ctrl-X Ctrl-I | Insert file at point |
| View file | Ctrl-X Ctrl-V | Open file read-only |

#### 5.4.4 Buffer Commands

| Command | Binding | Description |
|---------|---------|-------------|
| Switch buffer | Ctrl-X B | Switch to named buffer |
| Next buffer | Ctrl-X X | Switch to next buffer |
| Kill buffer | Ctrl-X K | Delete a buffer |
| List buffers | Ctrl-X Ctrl-B | Show buffer list |
| Name buffer | Meta-Ctrl-N | Rename current buffer |

#### 5.4.5 Window Commands

| Command | Binding | Description |
|---------|---------|-------------|
| Split window | Ctrl-X 2 | Divide window in two |
| One window | Ctrl-X 1 | Delete other windows |
| Delete window | Ctrl-X 0 | Delete current window |
| Next window | Ctrl-X O | Move to next window |
| Previous window | Ctrl-X P | Move to previous window |
| Grow window | Ctrl-X ^ | Increase window size |
| Shrink window | Ctrl-X Ctrl-Z | Decrease window size |

#### 5.4.6 Search Commands

| Command | Binding | Description |
|---------|---------|-------------|
| Search forward | Ctrl-S, Meta-S | Search forward for pattern |
| Search backward | Ctrl-R | Search backward for pattern |
| Search again | (varies) | Repeat last search |
| Replace | Meta-R | Search and replace |
| Query replace | Meta-Ctrl-R | Interactive search/replace |
| Incremental search | Ctrl-X S | Search as you type |

#### 5.4.7 Mode Commands

| Command | Binding | Description |
|---------|---------|-------------|
| Add mode | Ctrl-X M | Enable buffer mode |
| Delete mode | Ctrl-X Ctrl-M | Disable buffer mode |
| Add global mode | Meta-M | Enable global mode |
| Delete global mode | Meta-Ctrl-M | Disable global mode |

#### 5.4.8 Macro Commands

| Command | Binding | Description |
|---------|---------|-------------|
| Start macro | Ctrl-X ( | Begin recording |
| End macro | Ctrl-X ) | Stop recording |
| Execute macro | Ctrl-X E | Play back macro |

#### 5.4.9 Miscellaneous Commands

| Command | Binding | Description |
|---------|---------|-------------|
| Abort | Ctrl-G | Cancel current operation |
| Redraw | Ctrl-L | Refresh screen |
| Quote | Ctrl-Q | Insert next char literally |
| Help | Meta-? | Show help |
| Exit | Ctrl-X Ctrl-C | Quit editor |
| Quick exit | Meta-Z | Save all and quit |
| Execute command | Meta-X | Run command by name |
| Describe key | Ctrl-X ? | Show key binding |

---

## 6. Search and Replace

### 6.1 Simple Search

- Prompt user for search pattern
- Search forward or backward from point
- Wrap around buffer if not found before end
- Leave point at match location

### 6.2 Incremental Search

- Search updates as user types each character
- Backspace undoes last character and search step
- Repeating search key finds next match
- Escape exits at current position
- Ctrl-G aborts and returns to start

### 6.3 Regular Expression Search (MAGIC Mode)

When MAGIC mode is enabled, patterns support:

| Pattern | Meaning |
|---------|---------|
| `.` | Match any character except newline |
| `*` | Match zero or more of previous |
| `^` | Match beginning of line |
| `$` | Match end of line |
| `[abc]` | Match any character in set |
| `[^abc]` | Match any character not in set |
| `[a-z]` | Match character range |
| `\c` | Match literal character c |

### 6.4 Replace Operations

- **Replace**: Replace all occurrences
- **Query Replace**: For each match, prompt:
  - `Y` - Replace and continue
  - `N` - Skip and continue
  - `!` - Replace all remaining
  - `.` - Replace and stop
  - `Ctrl-G` - Abort

### 6.5 Match Storage

After a successful search, store:
- Matched text (for `&` substitution in replace)
- Match location (line and offset)
- Match length

---

## 7. File Operations

### 7.1 Reading Files

1. Create or find buffer for file
2. Clear buffer contents
3. Open file for reading
4. Read lines, creating line structures
5. Handle encoding (UTF-8)
6. Set buffer filename and clear modified flag
7. Close file
8. Report line count to user

### 7.2 Writing Files

1. Open file for writing
2. Write each line followed by newline
3. Handle encoding (UTF-8)
4. Close file
5. Clear modified flag
6. Report bytes written to user

### 7.3 File Locking (Optional)

For multi-user systems:
- Create lock file when editing
- Check for existing locks before editing
- Remove lock on buffer kill or exit

### 7.4 Backup Files (Optional)

Before overwriting a file:
- Rename original to backup name (add ~ suffix)
- Then write new content

### 7.5 Filename Completion

When prompting for filename:
- Tab/Space triggers completion
- Show matching files if ambiguous
- Complete unambiguous prefixes

---

## 8. Keyboard Macros

### 8.1 Recording

1. User invokes "start macro" (Ctrl-X ()
2. All keystrokes are recorded to macro buffer
3. User invokes "end macro" (Ctrl-X ))
4. Recording stops

### 8.2 Playback

1. User invokes "execute macro" (Ctrl-X E)
2. With argument N, execute N times
3. Keystrokes are fed from macro buffer
4. Any error aborts playback

### 8.3 Macro Storage

- Store as array of key codes
- Maximum size: 256 keystrokes
- Only one macro active at a time

---

## 9. Scripting and Variables (Optional)

### 9.1 Environment Variables

Readable/writable editor state:

| Variable | Description |
|----------|-------------|
| $fillcol | Fill column for wrapping |
| $curcol | Current column position |
| $curline | Current line number |
| $cbufname | Current buffer name |
| $cfname | Current file name |
| $search | Current search pattern |
| $replace | Current replace pattern |
| $version | Editor version string |

### 9.2 User Variables

Variables named %name can store arbitrary strings.

### 9.3 Functions

Built-in functions for:
- Arithmetic: add, sub, mul, div, mod, neg, abs
- Comparison: equ, les, gre (numeric); seq, sle, sgr (string)
- String: cat, len, left, right, mid, upper, lower
- Logical: and, or, not

### 9.4 Macro Language (Optional)

Command files can contain:
- Comments (lines starting with ;)
- Variable assignments
- Conditionals (!if, !else, !endif)
- Loops (!while, !endwhile)
- Procedures (!store, !endm)
- Flow control (!goto, !return)

---

## 10. Error Handling

### 10.1 User Errors

- Display message on message line
- Beep to alert user
- Do not exit or crash

Common messages:
- "[No mark set]"
- "[Not found]"
- "[Read only]"
- "[Buffer modified]"
- "[File not found]"

### 10.2 System Errors

- File I/O errors: report and continue
- Memory allocation: attempt recovery, report if critical
- Terminal errors: restore terminal and exit cleanly

### 10.3 Abort Handling

Ctrl-G (ABORT) should:
- Cancel any pending operation
- Clear message line
- Return to normal editing
- Beep once

---

## 11. Startup and Initialization

### 11.1 Command Line Arguments

| Argument | Description |
|----------|-------------|
| file | Open file for editing |
| +N | Start at line N |
| +/pattern | Start at first match of pattern |
| -g N | Go to line N |
| --help | Show usage and exit |
| --version | Show version and exit |

### 11.2 Initialization File

On startup, look for and execute:
1. System config (e.g., /usr/lib/.emacsrc)
2. User config (e.g., ~/.emacsrc)

### 11.3 Startup Sequence

1. Parse command line arguments
2. Initialize terminal
3. Initialize default key bindings
4. Initialize default modes
5. Create scratch buffer
6. Execute init files
7. Open files from command line
8. Enter main editing loop

---

## 12. Main Loop

```
WHILE not exit requested:
    Update display if needed
    Get keystroke from user
    Look up command for keystroke
    IF command found:
        Execute command with current argument
        Reset argument to 1
    ELSE:
        IF printable character:
            Insert character (argument times)
        ELSE:
            Beep (unknown command)
    Update flags for next iteration
```

---

## 13. Memory Management

### 13.1 Allocation Strategy

- Lines: allocate with initial size, grow as needed
- Buffers: allocate on creation, free on kill
- Kill buffer: chunked allocation, reuse chunks

### 13.2 Deallocation

On buffer kill:
- Free all lines in the buffer
- Free buffer structure

On exit:
- Free all buffers
- Free kill buffer
- Free any temporary storage

---

## 14. UTF-8 Support

### 14.1 Character Model

- Internal storage: UTF-8 encoded bytes
- Character operations work on Unicode code points
- Display width may differ from byte count

### 14.2 UTF-8 Handling

| Function | Description |
|----------|-------------|
| UTF-8 to codepoint | Decode bytes to Unicode value |
| Codepoint to UTF-8 | Encode Unicode value to bytes |
| Is start byte | Check if byte starts a sequence |
| Char width | Return display width (1 or 2 for wide) |

### 14.3 Cursor Movement

- Forward/backward by character, not byte
- Handle multi-byte sequences correctly
- Skip continuation bytes (0x80-0xBF)

---

## 15. Configuration Constants

| Constant | Typical Value | Description |
|----------|---------------|-------------|
| NFILEN | 256 | Max filename length |
| NBUFN | 16 | Max buffer name length |
| NLINE | 256 | Max input line length |
| NSTRING | 128 | Max string variable length |
| NPAT | 128 | Max search pattern length |
| NKBDM | 256 | Max keyboard macro length |
| NBINDS | 256 | Max key bindings |
| HUGE | 1000 | Large number for operations |
| KBLOCK | 250 | Kill buffer chunk size |

---

## 16. Testing Requirements

### 16.1 Unit Tests

- Line operations: insert, delete, split, join
- Buffer operations: create, find, kill
- Search: literal, regex, replace
- UTF-8: encode, decode, width

### 16.2 Integration Tests

- Open, edit, save file
- Multiple buffers
- Multiple windows
- Macro recording and playback
- Search and replace

### 16.3 Performance Tests

- Startup time < 10ms
- Open 1MB file < 100ms
- Search 1MB file < 50ms
- Responsive to keystrokes (no lag)

---

## 17. Platform Requirements

### 17.1 Required

- POSIX-compliant OS (Linux, macOS, BSD)
- C99 compiler
- ncurses or compatible library
- terminfo database

### 17.2 Optional

- SIGWINCH support for terminal resize
- Locale support for UTF-8

---

## Appendix A: Default Key Bindings Reference

See Section 5.4 for complete command list with bindings.

## Appendix B: Message Strings

| Situation | Message |
|-----------|---------|
| Search not found | "[Not found]" |
| No mark set | "[No mark set in this window]" |
| Buffer modified | "[Buffer modified, save first]" |
| Read only | "[Buffer is read-only]" |
| Wrote file | "Wrote N lines to filename" |
| File not found | "[File not found]" |
| Aborted | "[Aborted]" |

## Appendix C: Exit Codes

| Code | Meaning |
|------|---------|
| 0 | Normal exit |
| 1 | Error during operation |
| 2 | Command line error |

---

*End of Specification*
