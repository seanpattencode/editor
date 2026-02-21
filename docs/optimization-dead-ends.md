# Optimization dead ends

## Static SYMBOL pool (keymapinit)

Replaced 75 individual `malloc(sizeof(SYMBOL))` calls with a static
`SYMBOL sym_pool[128]` and bump allocation. Hypothesis: eliminating
malloc overhead during init would reduce startup time.

Result: no measurable change. Before 556µs, after 562µs (within noise).

Why: glibc malloc serves small allocations from a pre-mapped arena —
no syscall per allocation. At 0.55ms total startup, time is dominated
by kernel exec, dynamic linker, and terminal ioctls, not userspace
allocation.

## Static WINDOW (edinit)

Made the initial WINDOW a static global instead of malloc'd.
One malloc eliminated.

Result: invisible. One malloc is ~50ns. Unmeasurable against 550µs.

## Navigation paths

forwline, backline, forwpage, backpage, update — no malloc in any of
these paths. Nothing to optimize via allocation changes. The screen
update loop is already direct memory writes to VIDEO structs.

## What actually dominates startup (0.55ms)

- Kernel process creation: ~100-200µs
- Dynamic linker (libc.so): ~100-200µs
- Terminal init (tcgetattr, ioctl TIOCGWINSZ): ~50µs
- filldir (opendir/readdir/qsort): workload-dependent, ~100µs for small dirs
- Everything else (keymapinit, edinit, update): ~50µs combined

Static linking (`-static`) could cut ~100-200µs but doesn't work on
macOS (Apple removed static libc) and is unreliable on Termux.
