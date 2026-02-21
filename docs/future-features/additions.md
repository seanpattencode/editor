# Future additions

Ordered by value. Each must justify its token cost.

## High — daily workflow gaps

fill-paragraph: wrap text to column 72. Essential for git commit
messages and email. Torvalds uses this constantly. Implementation:
walk region, reflow words at fill column. ~30 lines.

goto-matching-fence: jump cursor to matching {}/()/[]. Critical for
C code navigation. Implementation: scan forward/backward counting
nesting depth. ~20 lines.

reverse i-search: Ctrl-R to search backward. e only has forward
(Ctrl-F). The isearch machinery already exists — just needs a
direction flag. ~5 lines.

paragraph navigation: next-paragraph / previous-paragraph. Jump by
blank-line-delimited blocks. Fast movement in prose and code. ~15
lines.

## Medium — useful but not blocking

filter-buffer: pipe selection or buffer through external command.
Enables sort, fmt, awk, etc. without leaving editor. ~20 lines.

insert-file: read another file's contents at cursor position.
readin() mostly does this already — needs a prompt wrapper. ~10 lines.

word-wrap mode: auto-break lines at fill column during typing. Needs
a hook in selfinsert when column exceeds fill. ~10 lines.

trim-trailing: strip trailing whitespace from all lines. Walk buffer,
truncate each line. ~10 lines.

## Low — nice to have

count-words: display word/line/char count for region or buffer.
Walk lines, count spaces. ~15 lines.

entab/detab: convert between tabs and spaces. Walk buffer, expand
or compress. ~15 lines.

named macros: store recorded macros by name, recall by name. Currently
e has one anonymous macro slot (Ctrl-X ( and Ctrl-X )). ~20 lines.

## Rules

- Each addition must run and be tested before merge
- Measure token cost with a diff, reject if disproportionate
- No feature without a scream — if nobody misses it, don't build it
- Prefer fewer tokens over more features
