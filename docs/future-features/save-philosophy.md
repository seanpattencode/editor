# Save philosophy: view-first, edit-rare

Most file opens are to view, not edit. The editor should optimize for that.

- No quit confirmation. Quit is instant. Viewing users (the majority) get
  zero friction.
- No auto-save. The file on disk is always in a known-good state. The buffer
  is ephemeral scratch space. Only explicit Ctrl+S makes changes real.
- Editing users are deliberate. They know Ctrl+S. They don't need "are you
  sure?" prompts.

The risk is an accidental keystroke while viewing. But without auto-save,
quitting discards it — the file on disk is untouched. The only danger is
accidentally typing AND accidentally saving. Two accidents in sequence is
unlikely enough to not design around.

Contract: no auto-save + no quit prompt + Ctrl+S = disk is always clean.

This is the same assumption as git: working state is cheap and disposable,
saved state is sacred. Nothing is permanent until you explicitly commit.
Discarding is instant, no confirmation needed.

Most things written are crap. Deleting by default is correct 99% of the
time — and often correct even when Ctrl+S was actually pressed. The default
should favor destruction, not preservation. Hoarding unsaved work "just in
case" optimizes for the rare case at the cost of the common one.

"Oh who will save my eiadksfsedflin?" Nobody, and that's the point. The
example proves itself — the very act of typing garbage to protest deletion
produces something that should be deleted.
