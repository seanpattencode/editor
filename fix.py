#!/usr/bin/env python3
"""Convert e.c K&R functions to ANSI C for strict clang -Weverything."""
import re

with open('e.c') as f:
    src = f.read()

# ── 0. Pre-fixes: include, escape sequences ──────────────────────────
src = src.replace(
    '#include\t<dirent.h>\n',
    '#include\t<dirent.h>\n#include\t<unistd.h>\n#include\t<sys/wait.h>\n'
)
src = src.replace(
    'write(1, "\\e[?1006h\\e[?1002h", 16);',
    'write(1, "\\033[?1006h\\033[?1002h", 16);'
)
src = src.replace(
    'write(1,"\\e[?1002l\\e[?1006l\\e[2J\\e[H",23);',
    'write(1,"\\033[?1002l\\033[?1006l\\033[2J\\033[H",23);'
)

# ── 1. Static globals ────────────────────────────────────────────────
# Only make static the globals that have NO extern forward reference
# elsewhere in the file. Variables with extern forward refs stay global.
static_globals = [
    ('int dirmode;',                'static int dirmode;'),
    ('int sb_top, sb_bot;',        'static int sb_top, sb_bot;'),
    ('int uc[4096],ut,ul,hoff;',   'static int uc[4096],ut,ul,hoff;'),
    ('char\tobuf[NOBUF]',           'static char\tobuf[NOBUF]'),
    ('int\tnobuf;',                 'static int\tnobuf;'),
    ('struct\ttermios\toldtty;',    'static struct\ttermios\toldtty;'),
    ('struct\ttermios\tnewtty;',    'static struct\ttermios\tnewtty;'),
    ('short\tlk201map[] = {',       'static short\tlk201map[] = {'),
    ('char\t*kbufp\t= NULL;',      'static char\t*kbufp\t= NULL;'),
    ('int\tkused\t= 0;',           'static int\tkused\t= 0;'),
    ('int\tksize\t= 0;',           'static int\tksize\t= 0;'),
    ('int\tsrch_lastdir = SRCH_NOPR;', 'static int\tsrch_lastdir = SRCH_NOPR;'),
    ('VIDEO\t*vscreen[NROW-1];',    'static VIDEO\t*vscreen[NROW-1];'),
    ('VIDEO\t*pscreen[NROW-1];',    'static VIDEO\t*pscreen[NROW-1];'),
    ('VIDEO\tvideo[2*(NROW-1)];',   'static VIDEO\tvideo[2*(NROW-1)];'),
    ('VIDEO\tblanks;',              'static VIDEO\tblanks;'),
    ('SCORE\tscore[NROW*NROW];',    'static SCORE\tscore[NROW*NROW];'),
    ('char\t*shellp\t= NULL;',     'static char\t*shellp\t= NULL;'),
]

for old, new in static_globals:
    src = src.replace('\n' + old, '\n' + new, 1)

# ── 2. Fix function pointer types in structs ─────────────────────────
src = src.replace(
    'int\t(*s_funcp)();',
    'int\t(*s_funcp)(int, int, int);'
)
src = src.replace(
    'int\t(*k_funcp)();',
    'int\t(*k_funcp)(int, int, int);'
)

# ── 3. Fix forward declarations to have prototypes ───────────────────
src = src.replace('BUFFER\t*bfind();',   'static BUFFER\t*bfind(char *, int);')
src = src.replace('BUFFER\t*bcreate();', 'static BUFFER\t*bcreate(char *);')
src = src.replace('WINDOW\t*wpopup();',  'static WINDOW\t*wpopup(void);')
src = src.replace('LINE\t*lalloc();',    'static LINE\t*lalloc(int);')
src = src.replace('SYMBOL\t*symlookup();','static SYMBOL\t*symlookup(char *);')

# ── 4. Convert "extern int func();" to static prototypes ─────────────
lines = src.split('\n')
new_lines = []
for line in lines:
    stripped = line.strip()
    m = re.match(r'^extern\s+int\s+(\w+)\(\s*\)\s*;', stripped)
    if m:
        name = m.group(1)
        if name == 'getenv':
            new_lines.append(line)  # keep, it's libc
        else:
            new_lines.append(f'static int\t{name}(int, int, int);')
    else:
        new_lines.append(line)
src = '\n'.join(new_lines)

# Fix backdir declaration (it's a command function, needs (int,int,int))
src = src.replace('int\tbackdir();', 'static int\tbackdir(int, int, int);')

# ── 5. Add forward declarations for functions called before definition ──
# We need VIDEO/SCORE forward struct typedefs so forward decls can reference them
fwd_decls = """/* Forward declarations — helpers called before definition */
static void\tttflush(void);
static void\tttputc(int);
static void\tasciiparm(int);
static void\tttwindow(int, int);
static void\tupdate(void);
static void\teputc(int);
static void\teerase(void);
static int\tctrlg(int, int, int);
static int\tquit(int, int, int);
static int\tbackdir(int, int, int);
static void\tfilldir(char *);
static int\treadin(char *);
static void\tkeydup(int, char *);
static void\tkeyadd(int, int (*)(int,int,int), char *);
static int\tmakelist(void);
static int\tpopblist(void);
static int\tbclear(BUFFER *);
static int\taddline(char *);
static void\titoa_(char *, int, int);
static int\tforwsrch(void);
static int\tbacksrch(void);
static int\treadpattern(char *);
static int\tinword(void);
static int\tgetregion(REGION *);
static int\tsetsize(REGION *, long);
static void\tsetgoal(void);
static int\tgetgoal(LINE *);
static int\texecute(int, int, int);
static int\twriteout(char *);
static int\tgetkey(void);
static int\tgetctl(void);
static void\tkeyname(char *, int);
static int\tsymhash(char *);
static void\tmodeline(WINDOW *);
static void\tvtmove(int, int);
static void\tvtputc(int);
static void\tvteeol(void);
static int\teread(char *, char *, int, int, va_list);
static void\teformat(char *, va_list);
static void\teputi(int, int);
static void\teputs(char *);
static int\tis_find(int);
static void\tis_cpush(int);
static void\tis_lpush(void);
static void\tis_pop(void);
static int\tis_peek(void);
static int\tis_undo(int *, int *);
static void\tis_prompt(int, int, int);
static void\tis_dspl(char *, int);
static int\tisearch(int);
static int\tgetkbd(void);
static int\teyesno(char *);
static int\twritemsg(char *);
static int\treadmsg(int, int, int);
static int\tffropen(char *);
static int\tffwopen(char *);
static int\tffclose(void);
static int\tffputline(char *, int);
static int\tffgetline(char *, int);
static int\tfbackupfile(char *);
static void\tadjustcase(char *);
static void\tmakename(char *, char *);
static void\tedinit(char *);
static void\tvtinit(void);
static void\tvttidy(void);
static int\tanycb(void);
static void\tkdelete(void);
static int\tkinsert(int);
static int\tkremove(int);
static void\tsetscores(int, int);
static void\ttraceback(int, int, int, int);
static int\tgetxtra(SYMBOL *, SYMBOL *, int);
static int\tlnewline(void);
static int\tldelnewline(void);
static void\tlchange(int);
static int\tbackchar(int, int, int);
static int\tforwchar(int, int, int);
static int\teq(int, int);
static int\tundo(int, int, int);"""


# Insert after "/* Forward declarations */" line
src = src.replace(
    '/* Forward declarations */\n'
    'static BUFFER\t*bfind(char *, int);\n'
    'static BUFFER\t*bcreate(char *);\n'
    'static WINDOW\t*wpopup(void);\n'
    'static LINE\t*lalloc(int);\n'
    'static SYMBOL\t*symlookup(char *);',
    fwd_decls + '\n'
    'static BUFFER\t*bfind(char *, int);\n'
    'static BUFFER\t*bcreate(char *);\n'
    'static WINDOW\t*wpopup(void);\n'
    'static LINE\t*lalloc(int);\n'
    'static SYMBOL\t*symlookup(char *);'
)

# ── 6. Extern variable forward references ─────────────────────────────
# Keep all extern variable declarations — they're valid forward refs
# for variables defined later in the same file. We don't make these
# vars static to avoid extern/static linkage conflicts.
# Nothing to do here — externs stay as-is.

# ── 7. Add forward declarations for hash/uline/ucopy after VIDEO typedef
# These functions take VIDEO* params, so their declarations must come
# after the VIDEO typedef. Insert them right after the VIDEO typedef.
video_fwd_decls = (
    '\n/* Forward declarations for VIDEO functions */\n'
    'static void\thash(VIDEO *);\n'
    'static void\tuline(int, VIDEO *, VIDEO *);\n'
    'static void\tucopy(VIDEO *, VIDEO *);\n'
)
src = src.replace(
    '#define\tVFCHG\t0x0001',
    video_fwd_decls + '#define\tVFCHG\t0x0001'
)

# ── 8. Convert no-arg function definitions to ANSI ────────────────────

# Set of functions that are commands (called via key table with f,n,k)
# even though defined with no args in K&R style
command_funcs_noarg = {'readmsg'}

void_funcs = {
    'ttopen', 'ttclose', 'ttputc', 'ttflush', 'ttinit', 'tttidy',
    'ttmove', 'tteeol', 'tteeop', 'ttbeep', 'asciiparm',
    'ttinsl', 'ttdell', 'ttwindow', 'ttnowindow', 'ttcolor', 'ttresize',
    'kdelete', 'lchange', 'lfree',
    'vtinit', 'vttidy', 'vtmove', 'vtputc', 'vteeol',
    'update', 'ucopy', 'uline', 'modeline', 'hash',
    'keyname', 'keymapinit', 'keyadd', 'keydup', 'ttykeymapinit',
    'makename', 'adjustcase', 'edinit',
    'is_cpush', 'is_lpush', 'is_pop', 'is_prompt', 'is_dspl',
    'setgoal', 'itoa_', 'filldir', 'setscores', 'traceback',
    'eformat', 'eputi', 'eputs', 'eputc',
    'eerase',
}

# Functions with explicit return types on previous line
ptr_return_funcs = {
    'wpopup': 'static WINDOW *',
}

def convert_no_arg_func(src):
    """Convert name()\\n{ patterns to static TYPE name(void)\\n{ or (int f, int n, int k)."""
    # First handle TYPE *\nfunc()\n{ patterns
    for name, ret in ptr_return_funcs.items():
        src = re.sub(
            r'^[A-Z]+\s+\*\n' + name + r'\(\s*\)\s*\n\{',
            ret + '\n' + name + '(void)\n{',
            src, flags=re.MULTILINE
        )
    pattern = re.compile(r'^(\w+)\(\s*\)\s*\n\{', re.MULTILINE)
    def repl(m):
        name = m.group(1)
        if name == 'main':
            return m.group(0)
        if name in command_funcs_noarg:
            return f'static int\n{name}(int f, int n, int k)\n{{'
        if name in void_funcs:
            return f'static void\n{name}(void)\n{{'
        else:
            return f'static int\n{name}(void)\n{{'
    return pattern.sub(repl, src)

src = convert_no_arg_func(src)

# ── 9. Convert K&R functions with parameters to ANSI ─────────────────

def convert_knr_functions(src):
    """Convert K&R function definitions to ANSI style."""
    lines = src.split('\n')
    result = []
    i = 0
    while i < len(lines):
        line = lines[i]

        # Skip already-converted functions (start with 'static')
        if line.startswith('static '):
            result.append(line)
            i += 1
            continue

        # Skip if previous line is already a static return type (from no-arg converter)
        if result and result[-1].strip().startswith('static '):
            result.append(line)
            i += 1
            continue

        # Match K&R function def: identifier(params) at column 0
        m = re.match(r'^(\w+)\(([^)]+)\)\s*$', line)
        if m and not line.startswith('#') and not line.startswith('//'):
            func_name = m.group(1)
            param_names = [p.strip() for p in m.group(2).split(',')]

            # Skip keywords
            keywords = {'if', 'while', 'for', 'switch', 'return', 'typedef',
                        'struct', 'union', 'enum', 'static', 'extern', 'void',
                        'int', 'char', 'short', 'long', 'unsigned', 'signed',
                        'register', 'const', 'volatile'}
            if func_name in keywords:
                result.append(line)
                i += 1
                continue

            # Skip if already has a return type (space before '(')
            if ' ' in line.split('(')[0]:
                result.append(line)
                i += 1
                continue

            # Collect K&R parameter declarations
            param_types = {}
            j = i + 1
            while j < len(lines):
                pline = lines[j].strip()
                if pline == '{':
                    break
                if pline == '':
                    j += 1
                    continue
                # "register TYPE name;" or "TYPE name;" or "TYPE *name;"
                pm = re.match(r'^(?:register\s+)?(.*?)\s+(\*?\w+)\s*;', pline)
                if pm:
                    ptype = pm.group(1).strip()
                    pname = pm.group(2).strip()
                    if pname.startswith('*'):
                        ptype = ptype + ' *'
                        pname = pname[1:]
                    param_types[pname] = ptype
                else:
                    # Array param: "char buf[];" or "char *argv[];"
                    pm2 = re.match(r'^(?:register\s+)?(.*?)\s+(\*?\w+)\[\]\s*;', pline)
                    if pm2:
                        ptype2 = pm2.group(1).strip()
                        pname2 = pm2.group(2).strip()
                        if pname2.startswith('*'):
                            ptype2 = ptype2 + ' *'
                            pname2 = pname2[1:]
                        param_types[pname2] = ptype2 + ' *'
                    else:
                        # va_list
                        pm3 = re.match(r'^(va_list)\s+(\w+)\s*;', pline)
                        if pm3:
                            param_types[pm3.group(2)] = pm3.group(1)
                        else:
                            # Function pointer param: "int (*name)();"
                            pm4 = re.match(r'^int\s+\(\*(\w+)\)\(\s*\)\s*;', pline)
                            if pm4:
                                param_types[pm4.group(1)] = 'int (*)(int, int, int)'
                            else:
                                # Unknown, stop collecting
                                break
                j += 1

            # Build ANSI parameter list
            ansi_params = []
            for pn in param_names:
                pn = pn.strip()
                if pn in param_types:
                    pt = param_types[pn]
                    # Function pointer needs special formatting
                    if pt.startswith('int (*)('):
                        ansi_params.append(f'int (*{pn})(int, int, int)')
                    else:
                        ansi_params.append(f'{pt} {pn}')
                else:
                    ansi_params.append(f'int {pn}')

            # Determine return type
            if func_name == 'main':
                ret_type = 'int'
            elif func_name in void_funcs:
                ret_type = 'static void'
            else:
                ret_type = 'static int'

            # Check if previous line has a pointer return type
            if i > 0:
                prev = result[-1].strip() if result else ''
                if prev in ('LINE\t*', 'LINE *'):
                    result.pop()
                    ret_type = 'static LINE *'
                elif prev in ('BUFFER\t*', 'BUFFER *'):
                    result.pop()
                    ret_type = 'static BUFFER *'
                elif prev in ('WINDOW\t*', 'WINDOW *'):
                    result.pop()
                    ret_type = 'static WINDOW *'
                elif prev in ('SYMBOL\t*', 'SYMBOL *'):
                    result.pop()
                    ret_type = 'static SYMBOL *'

            param_str = ', '.join(ansi_params)
            result.append(f'{ret_type}\n{func_name}({param_str})')

            i = j  # j points to the '{' line
            continue

        result.append(line)
        i += 1

    return '\n'.join(result)

src = convert_knr_functions(src)

# ── 10. Fix wallchart parentheses warning ─────────────────────────────
src = src.replace(
    'while (*cp1++ = *cp2++)',
    'while ((*cp1++ = *cp2++))'
)

# ── 11. Fix empty-body for loop in getkbd ─────────────────────────────
src = src.replace(
    "c=lgetc(lp,i++)==9?(c|7)+1:c+1);curwp->w_doto=i;}",
    "c=lgetc(lp,i++)==9?(c|7)+1:c+1){}curwp->w_doto=i;}"
)

# ── 12. Fix shadow warnings ──────────────────────────────────────────
src = src.replace(
    'for(i=0;i<4;i++){LINE*n=b&1?lforw(p):lback(p);if(n!=curbp->b_linep)p=n;}',
    'for(i=0;i<4;i++){LINE*ln=b&1?lforw(p):lback(p);if(ln!=curbp->b_linep)p=ln;}'
)
src = src.replace(
    'curwp->w_dotp=lp;{int i,c;for(i=c=0;',
    'curwp->w_dotp=lp;{int i,cc;for(i=cc=0;'
)
src = src.replace(
    'i<llength(lp)&&c<x;c=lgetc(lp,i++)==9?(c|7)+1:cc+1)',
    'i<llength(lp)&&cc<x;cc=lgetc(lp,i++)==9?(cc|7)+1:cc+1)'
)
# Actually the original has c not cc in the second part, let me match original
# and replace both occurrences properly
src = src.replace(
    'i<llength(lp)&&c<x;c=lgetc(lp,i++)==9?(c|7)+1:c+1)',
    'i<llength(lp)&&cc<x;cc=lgetc(lp,i++)==9?(cc|7)+1:cc+1)'
)

# Shadow in getkbd: "int i,n=llength" -> rename n to nn
src = src.replace(
    'if(dirmode){char f[256];int i,n=llength(lp);',
    'if(dirmode){char f[256];int i,nn=llength(lp);'
)
src = src.replace(
    '\t\t\t\t\t\tfor(i=0;i<n;i++)f[i]=lgetc(lp,i);f[n]=0;',
    '\t\t\t\t\t\tfor(i=0;i<nn;i++)f[i]=lgetc(lp,i);f[nn]=0;'
)

# Shadow in newline: "char f[256];int i,n=llength(lp);" in dirmode block
src = src.replace(
    'if(dirmode){lp=curwp->w_dotp;char f[256];int i,n=llength(lp);for(i=0;i<n;i++)f[i]=lgetc(lp,i);f[n]=0;',
    'if(dirmode){lp=curwp->w_dotp;char f_[256];int i_,n_=llength(lp);for(i_=0;i_<n_;i_++)f_[i_]=lgetc(lp,i_);f_[n_]=0;'
)
src = src.replace(
    "if(n>1&&f[0]=='>')filldir(f+2);else{dirmode=0;readin(f+2);}return TRUE;}",
    "if(n_>1&&f_[0]=='>')filldir(f_+2);else{dirmode=0;readin(f_+2);}return TRUE;}"
)

# ── 13. implicit-int-conversion suppressed in Makefile ────────────────
# (too many legitimate int-to-char truncations in this editor)

# ── 14. Fix char-subscripts in macros ─────────────────────────────────
src = src.replace(
    "#define\tISWORD(c)\t((cinfo[(c)]&_W)!=0)",
    "#define\tISWORD(c)\t((cinfo[(unsigned char)(c)]&_W)!=0)"
)
src = src.replace(
    "#define\tISCTRL(c)\t((cinfo[(c)]&_C)!=0)",
    "#define\tISCTRL(c)\t((cinfo[(unsigned char)(c)]&_C)!=0)"
)
src = src.replace(
    "#define\tISUPPER(c)\t((cinfo[(c)]&_U)!=0)",
    "#define\tISUPPER(c)\t((cinfo[(unsigned char)(c)]&_U)!=0)"
)
src = src.replace(
    "#define\tISLOWER(c)\t((cinfo[(c)]&_L)!=0)",
    "#define\tISLOWER(c)\t((cinfo[(unsigned char)(c)]&_L)!=0)"
)

# ── 15. Fix signal handler types in spawncli ──────────────────────────
src = src.replace(
    'register int\t(*oqsig)();',
    'void\t(*oqsig)(int);'
)
src = src.replace(
    'register int\t(*oisig)();',
    'void\t(*oisig)(int);'
)

# ── 16. Remove duplicate ESC macro ───────────────────────────────────
src = src.replace(
    "#define\tESC\t0x1B\t\t\t/* Escape, arrows et al.\t*/\n#define\tAGRAVE\t0x60",
    "#define\tAGRAVE\t0x60"
)

# ── 17. Fix extern char *getenv() ────────────────────────────────────
src = src.replace("extern\tchar\t*getenv();", "/* getenv() provided by <stdlib.h> */")

# ── 18. Make dentcmp and eprintf/ereply static ───────────────────────
src = src.replace(
    'int dentcmp(const void*a,const void*b)',
    'static int dentcmp(const void*a,const void*b)'
)
src = src.replace(
    'void eprintf(char* fp, ...)',
    'static void eprintf(char* fp, ...)'
)
src = src.replace(
    'int ereply(char* fp, char* buf, int nbuf, ...);',
    'static int ereply(char* fp, char* buf, int nbuf, ...);'
)
src = src.replace(
    'int ereply(char* fp, char* buf, int nbuf, ...)\n',
    'static int ereply(char* fp, char* buf, int nbuf, ...)\n'
)

# ── 19. Fix nmsg+strlen type mismatch ────────────────────────────────
src = src.replace(
    'if (nmsg+strlen(sp)+1 > NMSG)',
    'if ((int)(nmsg+strlen(sp)+1) > NMSG)'
)

# ── 19b. Fix buf[cpos++] = c implicit int-to-char in eread ───────────
src = src.replace(
    '\t\t\t\t\tbuf[cpos++] = c;',
    '\t\t\t\t\tbuf[cpos++] = (char)c;',
)
# There's also a second occurrence in eread
src = src.replace(
    '\t\t\t\t\tbuf[cpos++] = c;\n\t\t\t\t}',
    '\t\t\t\t\tbuf[cpos++] = (char)c;\n\t\t\t\t}',
)

# ── 20. Make static only vars that have NO extern forward reference ────
# mpresf has no extern ref
src = src.replace('\nint\tmpresf;', '\nstatic int\tmpresf;', 1)

# ── 21. Fix compact one-line K&R functions ────────────────────────────
# filldir(p)char*p;{...} → static void filldir(char *p){...}
src = src.replace(
    'filldir(p)char*p;{',
    'static void\nfilldir(char *p)\n{'
)

# backdir(){...} → static int backdir(int f, int n, int k){...}
# (backdir is in key table, needs command signature)
src = src.replace(
    'backdir(){',
    'static int\nbackdir(int f, int n, int k)\n{'
)
# Fix call sites: backdir() → backdir(0, 1, KRANDOM)
src = src.replace('{backdir(0, 1, KRANDOM);}', '{backdir(0, 1, KRANDOM);}')  # no-op guard
src = src.replace('{backdir();}', '{backdir(0, 1, KRANDOM);}')

# Fix call site: readmsg() → readmsg(0, 1, KRANDOM)
src = src.replace('return (readmsg());', 'return (readmsg(0, 1, KRANDOM));')

# undo(f,n,k){...} → static int undo(int f, int n, int k){...}
src = src.replace(
    'undo(f,n,k){',
    'static int\nundo(int f, int n, int k)\n{'
)

# is_peek() has trailing tab: is_peek()\t\n{ → static int\nis_peek(void)\n{
src = re.sub(r'\nis_peek\(\)\s*\n\{', '\nstatic int\nis_peek(void)\n{', src)

# ── 22. Fix unused variable in bindtokey ──────────────────────────────
# After K&R conversion, the function header is different. Fix in the body.
src = src.replace(
    '{\n\tregister int\ts;\n\tregister char\t*cp;\n\tregister SYMBOL\t*sp;\n\tregister int\tc;\n\tchar\t\txname[NXNAME];\n\n\tif (kbdmip',
    '{\n\tregister int\ts;\n\tregister SYMBOL\t*sp;\n\tregister int\tc;\n\tchar\t\txname[NXNAME];\n\n\tif (kbdmip'
)

# ── 23. Add #include <sys/wait.h> already done in section 0 ──────────

# ── 24. Line ~3295 issue: check what function is there ───────────────
# The K&R converter may leave a dangling "static int" before a compact func

# ── Write output ──────────────────────────────────────────────────────
with open('e.c', 'w') as f:
    f.write(src)

print("Conversion complete.")
