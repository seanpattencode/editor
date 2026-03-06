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

## PGO (Profile-Guided Optimization)

Tested clang PGO (`-fprofile-instr-generate` / `-fprofile-instr-use`) with
`-O3 -march=native -flto`. Training workload: open e.c (5,584 lines), render,
exit. Benchmarked startup and 5 common actions at 10,000 iterations each.

Install line tested:

```sh
install) P=/tmp/e_pgo_$$;PD=${CC#clang};command -v llvm-profdata$PD &>/dev/null&&LP=llvm-profdata$PD||LP=llvm-profdata;mkdir -p "$P"&&sed 's/lastflag = 0;/update(); _exit(0);/' "$D/e.c">"$P/t.c"&&$CC -std=gnu89 -O3 -march=native -flto -fprofile-instr-generate -w -o "$P/t" "$P/t.c"&&LLVM_PROFILE_FILE="$P/e.profraw" "$P/t" "$D/e.c"&&$LP merge -output="$P/e.profdata" "$P/e.profraw"&&$CC -std=gnu89 -O3 -march=native -flto -fprofile-instr-use="$P/e.profdata" -w -o "$D/e" "$D/e.c"&&rm -rf "$P"&&mkdir -p "$HOME/.local/bin"&&ln -sf "$D/e" "$HOME/.local/bin/e"&&echo "pgo installed";;
```

Results (hyperfine, clang-23, Linux 6.17):

| Action (10k iter) | Normal (ms) | PGO (ms) | Diff |
|-------------------|-------------|----------|------|
| startup           | 0.47        | 0.51     | PGO 10% slower |
| scroll (pgdn)    | 1.1         | 1.1      | noise |
| cursor move       | 1.1         | 1.1      | noise |
| insert+delete     | 1.3         | 1.3      | noise |
| search ("int")    | 8.1         | 8.1      | noise |
| full redraw       | 127.6       | 128.8    | noise |

Result: no benefit anywhere. Startup regressed ~10%, likely from PGO
reshuffling code layout against this binary's icache profile. The codebase
is too small and the hot paths too short for profile-guided branch prediction
to improve anything. `-O3 -flto` already captures all available optimization.

Reverted to simple build for install.

## What actually dominates startup (0.55ms)

- Kernel process creation: ~100-200µs
- Dynamic linker (libc.so): ~100-200µs
- Terminal init (tcgetattr, ioctl TIOCGWINSZ): ~50µs
- filldir (opendir/readdir/qsort): workload-dependent, ~100µs for small dirs
- Everything else (keymapinit, edinit, update): ~50µs combined

Static linking (`-static`) could cut ~100-200µs but doesn't work on
macOS (Apple removed static libc) and is unreliable on Termux.
