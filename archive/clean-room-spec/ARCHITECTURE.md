# Clean Room Micro Emacs - Architecture Overview

## Module Decomposition

This document describes the recommended module structure for implementing the editor.

---

## 1. Module Dependency Diagram

```
                    +-------------+
                    |    main     |
                    +------+------+
                           |
          +----------------+----------------+
          |                |                |
    +-----v-----+    +-----v-----+    +-----v-----+
    |  command  |    |  display  |    |  terminal |
    +-----------+    +-----------+    +-----------+
          |                |                |
    +-----v-----+    +-----v-----+          |
    |  editing  |    |  window   |          |
    +-----------+    +-----------+          |
          |                |                |
    +-----v-----+    +-----v-----+          |
    |   buffer  |<-->|   line    |          |
    +-----------+    +-----------+          |
          |                                 |
    +-----v-----+                           |
    |   file    |                           |
    +-----------+                           |
          |                                 |
    +-----v-----+    +-----v-----+          |
    |   utf8    |    |   input   |<---------+
    +-----------+    +-----------+
```

---

## 2. Module Descriptions

### 2.1 Core Modules

#### main
- Entry point and main event loop
- Command line argument parsing
- Initialization sequence
- Shutdown and cleanup

#### terminal
- Terminal initialization and restoration
- Raw character I/O
- Cursor positioning
- Screen clearing operations
- Terminal capability detection
- Resize handling (SIGWINCH)

#### input
- Keystroke reading and encoding
- Meta/Ctrl-X prefix handling
- Special key decoding (arrows, function keys)
- Type-ahead buffering

#### display
- Virtual screen management
- Screen update optimization
- Mode line rendering
- Message line handling
- Long line truncation

### 2.2 Data Structure Modules

#### line
- Line allocation and deallocation
- Text insertion and deletion within lines
- Line splitting and joining
- Character access (with UTF-8 awareness)

#### buffer
- Buffer creation and destruction
- Buffer lookup by name
- Buffer list management
- Mode flag handling
- Modified state tracking

#### window
- Window creation and destruction
- Window splitting and deletion
- Window list management
- Viewport calculations
- Point/mark per-window tracking

### 2.3 Operation Modules

#### command
- Key binding table management
- Command lookup by key
- Command execution framework
- Universal argument handling
- Named command execution (M-x)

#### editing
- Cursor movement operations
- Text insertion (single char, string)
- Deletion operations
- Kill/yank (cut/copy/paste)
- Transposition
- Case conversion

#### search
- Literal string search
- Regular expression compilation
- Pattern matching
- Search and replace
- Incremental search
- Query replace

#### file
- File reading into buffer
- File writing from buffer
- Filename completion
- Path handling
- Error reporting

### 2.4 Utility Modules

#### utf8
- UTF-8 to Unicode conversion
- Unicode to UTF-8 conversion
- Character width calculation
- Byte sequence validation

#### macro
- Keyboard macro recording
- Macro playback
- Macro storage

#### bind (key bindings)
- Default binding initialization
- Runtime binding modification
- Binding table lookup
- Key name parsing

---

## 3. Data Flow

### 3.1 Keystroke Processing

```
Terminal → Input → Command Lookup → Command Execution → Display Update
    ↑                                      |
    |                                      v
    +←←←←←←←←←←← Buffer/Window State ←←←←←+
```

### 3.2 File Read Flow

```
File System → File Module → Line Creation → Buffer → Window → Display
```

### 3.3 Display Update Flow

```
Buffer Content → Window Viewport → Virtual Screen → Terminal Output
                      ↓
              Mode Line Generation
```

---

## 4. Key Data Structures

### 4.1 Line (doubly-linked list node)

```
struct line {
    struct line *next;      // Forward link
    struct line *prev;      // Backward link
    int capacity;           // Allocated size
    int length;             // Used size
    char text[];            // Flexible array member
};
```

### 4.2 Buffer

```
struct buffer {
    struct buffer *next;    // Buffer list link
    struct line *lines;     // Header line (circular)
    struct line *dot_line;  // Current line
    int dot_offset;         // Current offset in line
    struct line *mark_line; // Mark line
    int mark_offset;        // Mark offset
    int flags;              // Modified, readonly, etc.
    int modes;              // Editing modes bitmask
    int window_count;       // Windows showing this buffer
    char name[NBUFN];       // Buffer name
    char filename[NFILEN];  // Associated file
};
```

### 4.3 Window

```
struct window {
    struct window *next;    // Window list link
    struct buffer *buffer;  // Displayed buffer
    struct line *top_line;  // First visible line
    struct line *dot_line;  // Cursor line
    int dot_offset;         // Cursor offset
    struct line *mark_line; // Mark line
    int mark_offset;        // Mark offset
    int top_row;            // Screen row of top
    int height;             // Text rows (excluding mode line)
    int flags;              // Redraw flags
};
```

### 4.4 Key Binding

```
struct binding {
    int key;                // Key code with modifiers
    int (*func)(int, int);  // Command function pointer
};
```

### 4.5 Kill Buffer

```
struct kill_chunk {
    struct kill_chunk *next;
    char data[KBLOCK];
};
```

---

## 5. Global State

### 5.1 Editor Globals

| Variable | Type | Description |
|----------|------|-------------|
| current_buffer | buffer* | Active buffer |
| current_window | window* | Active window |
| buffer_list | buffer* | Head of buffer list |
| window_list | window* | Head of window list |
| kill_buffer | kill_chunk* | Kill ring head |
| last_command | int | Previous command for chaining |
| goal_column | int | Target column for vertical movement |

### 5.2 Terminal Globals

| Variable | Type | Description |
|----------|------|-------------|
| term_rows | int | Terminal height |
| term_cols | int | Terminal width |
| cursor_row | int | Current cursor row |
| cursor_col | int | Current cursor column |

### 5.3 Search Globals

| Variable | Type | Description |
|----------|------|-------------|
| search_pattern | char[] | Current search string |
| replace_pattern | char[] | Current replacement |
| last_match | char* | Last matched text |
| match_line | line* | Line containing match |
| match_offset | int | Offset of match |
| match_length | int | Length of match |

---

## 6. Function Signatures

### 6.1 Line Operations

```c
struct line *line_alloc(int size);
void line_free(struct line *lp);
int line_insert_char(struct line *lp, int offset, int c);
int line_insert_string(struct line *lp, int offset, char *s, int len);
int line_delete(struct line *lp, int offset, int count);
struct line *line_split(struct line *lp, int offset);
int line_join(struct line *lp);  // Join with next line
```

### 6.2 Buffer Operations

```c
struct buffer *buffer_create(char *name);
struct buffer *buffer_find(char *name, int create);
void buffer_destroy(struct buffer *bp);
int buffer_clear(struct buffer *bp);
void buffer_set_modified(struct buffer *bp, int flag);
```

### 6.3 Window Operations

```c
struct window *window_create(struct buffer *bp);
void window_destroy(struct window *wp);
int window_split(struct window *wp);
void window_only(struct window *wp);
void window_next(void);
void window_resize(struct window *wp, int delta);
```

### 6.4 Display Operations

```c
void display_init(void);
void display_update(int force);
void display_mode_line(struct window *wp);
void display_message(char *fmt, ...);
void display_clear_message(void);
void display_beep(void);
```

### 6.5 Command Operations

```c
int command_execute(int key, int f, int n);
int (*command_lookup(int key))(int, int);
void command_bind(int key, int (*func)(int, int));
int command_by_name(char *name);
```

### 6.6 File Operations

```c
int file_read(char *filename, struct buffer *bp);
int file_write(char *filename, struct buffer *bp);
int file_insert(char *filename);
int file_exists(char *filename);
char *file_complete(char *partial);
```

---

## 7. Error Handling Strategy

### 7.1 Return Values

- Most functions return TRUE (1) on success, FALSE (0) on failure
- ABORT (2) indicates user cancellation
- File operations may return specific error codes

### 7.2 Error Reporting

- Use display_message() for user-visible errors
- Use display_beep() for invalid operations
- Never crash on user error
- Graceful degradation on system errors

### 7.3 Memory Errors

- Check all allocations
- On failure: display message and return FALSE
- Never leave data structures in inconsistent state

---

## 8. Implementation Order

Recommended order for incremental development:

1. **Phase 1: Foundation**
   - Terminal I/O
   - Line data structure
   - Basic display (single window, no mode line)

2. **Phase 2: Basic Editing**
   - Character insertion
   - Cursor movement (char, line)
   - Deletion (char forward/backward)
   - Simple file read/write

3. **Phase 3: Buffer Management**
   - Multiple buffers
   - Buffer switching
   - Buffer list display

4. **Phase 4: Window Management**
   - Window splitting
   - Multiple window display
   - Mode lines

5. **Phase 5: Advanced Editing**
   - Word/paragraph movement
   - Kill/yank
   - Search (literal)
   - Replace

6. **Phase 6: Polish**
   - Regular expression search
   - Keyboard macros
   - Initialization files
   - Completion

---

## 9. Testing Strategy

### 9.1 Unit Test Each Module

- Line operations in isolation
- Buffer operations with mock lines
- Window operations with mock buffers
- Display to mock terminal

### 9.2 Integration Milestones

1. Can display static text
2. Can move cursor
3. Can insert/delete text
4. Can save/load files
5. Can manage buffers
6. Can split windows
7. Can search/replace

### 9.3 Regression Tests

- Record key sequences
- Verify resulting buffer state
- Check for memory leaks

---

*End of Architecture Document*
