# Why e is 2.8x faster than Torvalds's uemacs

Same micro-emacs heritage, same basic job. e: 0.58ms, uemacs: 1.6ms.

## Extra dynamic library

e links only libc. uemacs links libc + libtinfo (ncurses terminfo).
The dynamic linker must resolve an extra .so — mmap, symbol lookup,
relocations. ~0.3ms added before main() even runs.

## termcap/terminfo database lookup

uemacs calls tgetent() at startup to parse the termcap database for
$TERM. This reads files from /usr/share/terminfo, parses capability
strings (cl, cm, ce, up, se, so), and stores them. e doesn't use
termcap — it writes VT100/xterm escape codes directly. Every
terminal made in the last 30 years speaks these natively.

## malloc per screen row

uemacs vtinit() calls xmalloc() once for the vscreen array, then
once per row (xmalloc(sizeof(video) + ncol*4)). On a 66-row terminal
that's 67 malloc calls just for the display. e uses a static VIDEO
array — zero allocations for the screen.

## startup file search

uemacs runs startup("") which calls flook() to search for emacs.rc
along HOME and PATH. This does multiple stat() calls on filesystem
paths looking for a config file that usually doesn't exist. e has
no config file — nothing to search for.

## hunspell initialization

uemacs calls Hunspell_create() to load spellcheck dictionaries from
/usr/share/hunspell/. Even with our stub (no-op), the code path
exists. With real hunspell, this loads and parses .aff and .dic files
at startup — hundreds of KB of dictionary data.

## variable system initialization

uemacs calls varinit() to set up a user variable system with named
variables, evaluation, and a macro language. e has no macro language.

## 27 compilation units vs 1

uemacs compiles 27 .c files into separate .o files linked together.
The linker must resolve cross-reference symbols, merge sections, apply
relocations. e is a single translation unit — the compiler sees
everything, inlines aggressively, eliminates dead code, and produces
a 106KB binary vs uemacs's 169KB.

## What uemacs gets for the cost

- termcap portability (for terminals that don't exist anymore)
- spellcheck (useful but costs startup time always)
- macro language (powerful, rarely used)
- named variable system (same)

e trades all of that for raw speed: direct VT100 output, static
allocation, no config files, no abstraction layers.
