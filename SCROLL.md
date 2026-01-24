# Scrollbar Implementation Comparison

## Performance Benchmarks (conceptual)

| Implementation | Overhead | Lines of Code |
|----------------|----------|---------------|
| e (this editor) | ~0ms | 8 lines |
| tmux scrollbars | ~1-2ms | 500+ lines |
| satellite.nvim | ~5-10ms | 2000+ lines |
| VSCode | ~10-20ms | embedded in Electron |

## Why Others Are Slower

**Neovim plugins (satellite.nvim, nvim-scrollbar):**
- Use floating windows with transparency blending
- Handler system for cursor, search, diagnostics, git hunks
- Can't modify core render loop - forced to use plugin APIs
- Author admits "unideal and unoptimised workarounds"

**tmux:**
- Terminal multiplexer can't touch program content
- Must reserve separate columns and draw independently
- Manages scrollbar state across pane lifecycle

**VSCode:**
- Full DOM/canvas rendering in Electron
- Minimap, decorations, hover states
- JavaScript event handling overhead

## Our Approach: Direct Buffer Integration

```c
vp->v_text[ncol-2]=thumb?'|':' ';
vp->v_text[ncol-1]=thumb?'|':'.';
```

That's it. Write two characters into the existing screen buffer. Same diff-and-update pass as regular text. Zero additional overhead.

Mouse dragging:
```c
if(x>=(b&32?ncol/2:ncol-2)&&y>0&&row>=0&&row<curwp->w_ntrows){
    // calculate position, scroll, done
}
```

## Philosophy

This editor aims to be **VSCode in 1ms, in terminal**.

The approach:
1. Identify what people actually use (editing, navigation, scrolling)
2. Strip away what they don't (minimap decorations, diagnostic overlays in scrollbar)
3. Implement the core at the lowest possible level

Most users scroll to navigate. They don't need to see search results or git hunks in the scrollbar. A position indicator that responds instantly to dragging covers 99% of the use case.

## Trade-offs Accepted

What we don't have:
- Search result markers in scrollbar
- Diagnostic indicators
- Git change markers
- Minimap preview

What we gain:
- Zero overhead
- 8 lines of code
- Instant response
- No dependencies

## Conclusion

Complex scrollbar systems exist because they solve a different problem: information density. We solve a simpler problem: fast navigation. By refusing to solve the complex problem, we get performance that complex systems cannot match.

The best feature is the one that doesn't exist but isn't missed.
