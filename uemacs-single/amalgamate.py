#!/usr/bin/env python3
"""
Amalgamate uemacs source files into a single C file.
"""

import re
import os

SRC_DIR = "/home/seanpatten/projects/editor/uemacs"

# Order matters - headers first, then sources
HEADERS = [
    "utf8.h",
    "util.h",
    "usage.h",
    "wrapper.h",
    "version.h",
    "estruct.h",
    "line.h",
    "edef.h",
    "efunc.h",
    "evar.h",
    "epath.h",
    "ebind.h",
]

SOURCES = [
    "utf8.c",
    "util.c",
    "usage.c",
    "wrapper.c",
    "version.c",
    "globals.c",
    "line.c",
    "names.c",
    "basic.c",
    "bind.c",
    "buffer.c",
    "crypt.c",
    "display.c",
    "eval.c",
    "exec.c",
    "file.c",
    "fileio.c",
    "input.c",
    "isearch.c",
    "lock.c",
    "pklock.c",
    "random.c",
    "region.c",
    "search.c",
    "spawn.c",
    "tcap.c",
    "termio.c",
    "posix.c",
    "window.c",
    "word.c",
    "main.c",
    # Not needed for POSIX: ansi.c, ibmpc.c, vmsvt.c, vt52.c
]

# Local headers to strip from includes
LOCAL_HEADERS = set(HEADERS)

def strip_local_includes(content, filename):
    """Remove #include statements for local headers."""
    lines = content.split('\n')
    result = []
    for line in lines:
        # Check for local include
        match = re.match(r'\s*#\s*include\s*"([^"]+)"', line)
        if match:
            included = match.group(1)
            if included in LOCAL_HEADERS:
                result.append(f"/* #include \"{included}\" - amalgamated */")
                continue
        result.append(line)
    return '\n'.join(result)

def read_file(filename):
    path = os.path.join(SRC_DIR, filename)
    with open(path, 'r') as f:
        return f.read()

def main():
    output = []

    # File header
    output.append("""\
/*
 * uEmacs/PK 4.0 - Single File Amalgamation
 *
 * This is an automatically generated single-file version of uEmacs.
 * Original source: https://github.com/torvalds/uemacs
 *
 * Compile with:
 *   gcc -O2 -DAUTOCONF -DPOSIX -DUSG -D_XOPEN_SOURCE=600 -D_GNU_SOURCE \\
 *       -o em uemacs.c -lcurses
 */

/* Standard system headers */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/ioctl.h>
#include <sys/wait.h>
#include <termios.h>
#include <curses.h>
#include <term.h>
#include <time.h>
#include <pwd.h>

""")

    # Process headers (keep header guards - they're harmless)
    output.append("/* ========== HEADER FILES ========== */\n")
    for h in HEADERS:
        output.append(f"\n/* ----- {h} ----- */\n")
        content = read_file(h)
        content = strip_local_includes(content, h)
        output.append(content)
        output.append("\n")

    # Process source files
    output.append("\n/* ========== SOURCE FILES ========== */\n")
    for src in SOURCES:
        output.append(f"\n/* ----- {src} ----- */\n")
        content = read_file(src)
        content = strip_local_includes(content, src)
        # Also strip system includes that we've already added
        content = re.sub(r'^\s*#\s*include\s*<(stdio|stdlib|string|stdarg|unistd|signal|errno|fcntl|time|pwd)\.h>\s*$',
                        '/* system header already included */', content, flags=re.MULTILINE)
        content = re.sub(r'^\s*#\s*include\s*<sys/(stat|types|ioctl|wait)\.h>\s*$',
                        '/* system header already included */', content, flags=re.MULTILINE)
        content = re.sub(r'^\s*#\s*include\s*<(termios|curses|term)\.h>\s*$',
                        '/* system header already included */', content, flags=re.MULTILINE)
        output.append(content)
        output.append("\n")

    # Write output
    result = ''.join(output)
    print(result)

if __name__ == "__main__":
    main()
