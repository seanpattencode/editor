# Drag-to-Move Folders

## Overview

Enable drag-and-drop to move files/folders in directory mode, with a visual drag handle.

## Design

### Drag Handle

Use braille six-dot character `⠿` (U+283F) as the drag grip:

```
⠿ Documents/
⠿ Downloads/
⠿ notes.txt
```

This is the universal "drag me" indicator seen in Trello, Notion, iOS, Android, etc.

**Fallback:** `::` for terminals without Unicode support.

### Interaction Model

| Zone | Action |
|------|--------|
| Click on `⠿` (x < 2) | Start drag operation |
| Click on filename | Navigate/open instantly (unchanged) |
| Drag + release | Move item to target location |

This preserves instant click navigation while enabling drag-to-move.

### Why Not Click-to-Drag on Filename?

Currently, clicking a folder navigates into it immediately. If drag used the same zone:
- Must wait for mouse release to distinguish click vs drag
- Adds ~50-200ms delay to navigation
- Poor UX

The drag strip solves this with spatial separation - no timing needed.

## Implementation

### 1. Display Change (filldir)

```c
// In filldir(), change:
n=sprintf(s,"%s%s",e->d_name,e->d_type==DT_DIR?"/":"");

// To:
n=sprintf(s,"⠿ %s%s",e->d_name,e->d_type==DT_DIR?"/":"");
```

### 2. State Variables

```c
int drag_active = 0;
LINE *drag_line = NULL;
char drag_path[NFILEN];
```

### 3. Mouse Handler Changes (getkbd)

```c
// After calculating x, y, row in SGR mouse handler:

if(dirmode && x < 2 && ch=='M' && !(b&32)) {
    // Press on drag handle - start potential drag
    drag_active = 1;
    drag_line = lp;
    // Store path of item being dragged
    int i, n = llength(lp);
    for(i=0; i<n && i<NFILEN-1; i++) drag_path[i] = lgetc(lp,i);
    drag_path[i] = 0;
    goto loop;
}

if(drag_active && (b&32)) {
    // Motion while dragging - update cursor to show drop target
    // Visual feedback: highlight target line
    curwp->w_dotp = lp;
    curwp->w_flag |= WFMOVE;
    update();
    goto loop;
}

if(drag_active && ch=='m') {
    // Release - perform move
    drag_active = 0;
    if(lp != drag_line) {
        // Get target directory from current line
        char target[NFILEN];
        // ... build target path ...
        rename(drag_path, target);
        filldir("."); // Refresh
    }
    goto loop;
}

// Existing click handling (x >= 2) unchanged...
```

### 4. Visual Feedback During Drag

Options:
- Reverse video on drop target line
- Show insertion line indicator
- Status message: "Moving: filename"

## Termux Considerations

- Touch targets: 2-char drag strip is minimal but workable
- Unicode: Android handles `⠿` well
- Screen width: ~4% loss on 50-col phone screen (acceptable)

## Estimated Effort

- ~50-80 lines of code
- State machine for drag tracking
- Visual feedback in display
- File system rename() call

## Alternatives Considered

| Approach | Pros | Cons |
|----------|------|------|
| **Drag strip** (recommended) | Instant clicks, clear UX | Uses 2 cols |
| Long-press to drag | No space used | 300ms delay, complex timing |
| Right-click drag | Instant clicks | Less discoverable |
| Modifier key (Shift+drag) | Instant clicks | Requires keyboard |

## References

- SGR mouse protocol: `\e[<btn;x;yM` / `\e[<btn;x;ym`
- Button bits: `b&3`=button, `b&32`=motion, `b>=64`=scroll
- Current mouse handler: `e.c` line ~1033
