# Why e is faster than ls

e renders a full interactive directory browser in 0.56ms. ls prints
filenames in 1.8ms. Same job, 3x slower.

## What ls does that e doesn't (and why)

ls was written in 1971. Every feature was bolted on by a different
person solving their one problem:

- stat() every file: added for -l (permissions/sizes). Now runs always
  because color output needs file type from stat too.
- SELinux checks: security people mandated it. Runs every invocation
  even without SELinux.
- Locale handling: added for language-aware sorting. Loads locale
  databases on startup every time.
- Column formatting: added for multi-column output. Measures every
  filename width, computes a grid, handles terminal width — even
  though most people read top-to-bottom.
- 60+ flags: each one was someone's feature request over 55 years.
  All parsed every invocation.
- fork+exec: Unix philosophy says tools should be separate processes.
  Made sense at 300 baud. Now process creation costs more than the
  actual work.

None of it is necessary for "show me what's in this directory."

## What e does instead

- No fork/exec — already running.
- Reads d_type from readdir directly, no stat().
- One entry per line, no column width calculation.
- Writes directly to terminal buffer, no stdout formatting.
- Type-ahead search + enter to open. ls shows a static list you
  can't interact with — you read the name, type it yourself, hit
  enter. Three steps where e needs one.

ls is designed for pipes and scripts (ls | grep | xargs). That's
valid. But for a human looking at files and wanting to act on one,
ls is a round trip through your eyeballs and fingers that e eliminates.

Nobody can simplify ls because scripts depend on the exact behavior.
e starts from what the user actually needs with zero legacy.
