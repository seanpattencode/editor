/*
 * uEmacs/PK 4.0 - Single File Amalgamation
 *
 * This is an automatically generated single-file version of uEmacs.
 * Original source: https://github.com/torvalds/uemacs
 *
 * Compile with:
 *   gcc -O2 -DAUTOCONF -DPOSIX -DUSG -D_XOPEN_SOURCE=600 -D_GNU_SOURCE \
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

/* ========== HEADER FILES ========== */

/* ----- utf8.h ----- */
#ifndef UTF8_H
#define UTF8_H

typedef unsigned int unicode_t;

unsigned utf8_to_unicode(char *line, unsigned index, unsigned len, unicode_t *res);
unsigned unicode_to_utf8(unsigned int c, char *utf8);

static inline int is_beginning_utf8(unsigned char c)
{
	return (c & 0xc0) != 0x80;
}

#endif


/* ----- util.h ----- */
#ifndef UTIL_H_
#define UTIL_H_

#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))
void mystrscpy(char *dst, const char *src, int size);

#endif  /* UTIL_H_ */


/* ----- usage.h ----- */
#ifndef USAGE_H_
#define USAGE_H_

extern void die(const char* err, ...);

#endif  /* USAGE_H_ */


/* ----- wrapper.h ----- */
#ifndef WRAPPER_H_
#define WRAPPER_H_

extern int xmkstemp(char *template);

extern void *xmalloc(size_t size);

#endif  /* WRAPPER_H_ */


/* ----- version.h ----- */
#ifndef VERSION_H_
#define VERSION_H_

#define PROGRAM_NAME "em"
#define PROGRAM_NAME_LONG "uEmacs/Pk"

#define	VERSION	"4.0.15"

/* Print the version string. */
void version(void);

#endif  /* VERSION_H_ */


/* ----- estruct.h ----- */
/*      ESTRUCT.H
 *
 *      Structure and preprocessor defines
 *
 *	written by Dave G. Conroy
 *	modified by Steve Wilhite, George Jones
 *      substantially modified by Daniel Lawrence
 *	modified by Petri Kutvonen
 */

#define MAXCOL	500
#define MAXROW	500

#ifdef	MSDOS
#undef	MSDOS
#endif
#ifdef	EGA
#undef	EGA
#endif
#ifdef	CTRLZ
#undef	CTRLZ
#endif

/* Machine/OS definitions. */

#if defined(AUTOCONF) || defined(MSDOS) || defined(BSD) || defined(SYSV) || defined(VMS)

/* Make an intelligent guess about the target system. */

#if defined(__TURBOC__)
#define MSDOS 1 /* MS/PC DOS 3.1-4.0 with Turbo C 2.0 */
#else
#define	MSDOS 0
#endif

#if defined(BSD) || defined(sun) || defined(ultrix) || (defined(vax) && defined(unix)) || defined(ultrix) || defined(__osf__)
#ifndef BSD
#define BSD 1 /* Berkeley UNIX */
#endif
#else
#define	BSD 0
#endif

#if defined(SVR4) || defined(__linux__)	/* ex. SunOS 5.3 */
#define SVR4 1
#define SYSV 1
#undef BSD
#endif

#if defined(SYSV) || defined(u3b2) || defined(_AIX) || (defined(i386) && defined(unix)) || defined(__hpux)
#define	USG 1 /* System V UNIX */
#else
#define	USG 0
#endif

#if defined(VMS) || (defined(vax) && ! defined(unix))
#define VMS 1 /* VAX/VMS */
#else
#define VMS 0
#endif

#define	V7 0 /* No more. */

#else

#define MSDOS   1		/* MS-DOS                       */
#define V7      0		/* V7 UNIX or Coherent or BSD4.2 */
#define	BSD	0		/* UNIX BSD 4.2 and ULTRIX      */
#define	USG	0		/* UNIX system V                */
#define VMS     0		/* VAX/VMS                      */

#endif				/*autoconf */

#ifndef	AUTOCONF

/*	Compiler definitions			*/
#define	UNIX	0		/* a random UNIX compiler */
#define	MSC	0		/* MicroSoft C compiler, versions 3 up */
#define	TURBO	1		/* Turbo C/MSDOS */

#else

#define	UNIX	(V7 | BSD | USG)
#define	MSC	0
#define	TURBO	MSDOS

#endif				/*autoconf */

/*	Debugging options	*/

#define	RAMSIZE	0		/* dynamic RAM memory usage tracking */
#define	RAMSHOW	0		/* auto dynamic RAM reporting */

#ifndef	AUTOCONF

/*   Special keyboard definitions            */

#define VT220	0		/* Use keypad escapes P.K.      */
#define VT100   0		/* Handle VT100 style keypad.   */

/*	Terminal Output definitions		*/

#define ANSI    0		/* ANSI escape sequences        */
#define	VMSVT	0		/* various VMS terminal entries */
#define VT52    0		/* VT52 terminal (Zenith).      */
#define TERMCAP 0		/* Use TERMCAP                  */
#define	IBMPC	1		/* IBM-PC CGA/MONO/EGA driver   */

#else

#define	VT220	(UNIX | VMS)
#define	VT100	0

#define	ANSI	0
#define	VMSVT	VMS
#define	VT52	0
#define	TERMCAP	UNIX
#define	IBMPC	MSDOS

#endif /* Autoconf. */

/*	Configuration options	*/

#define CVMVAS  1  /* arguments to page forward/back in pages      */
#define	CLRMSG	0  /* space clears the message line with no insert */
#define	CFENCE	1  /* fench matching in CMODE                      */
#define	TYPEAH	1  /* type ahead causes update to be skipped       */
#define DEBUGM	1  /* $debug triggers macro debugging              */
#define	VISMAC	0  /* update display during keyboard macros        */
#define	CTRLZ	0  /* add a ^Z at end of files under MSDOS only    */
#define ADDCR	0  /* ajout d'un CR en fin de chaque ligne (ST520) */
#define	NBRACE	1  /* new style brace matching command             */
#define	REVSTA	1  /* Status line appears in reverse video         */

#ifndef	AUTOCONF

#define	COLOR	1  /* color commands and windows                   */
#define	FILOCK	0  /* file locking under unix BSD 4.2              */

#else

#define	COLOR	MSDOS
#ifdef  SVR4
#define FILOCK  1
#else
#define	FILOCK	BSD
#endif

#endif /* Autoconf. */

#define	ISRCH	1  /* Incremental searches like ITS EMACS          */
#define	WORDPRO	1  /* Advanced word processing features            */
#define	APROP	1  /* Add code for Apropos command                 */
#define	CRYPT	1  /* file encryption enabled?                     */
#define MAGIC	1  /* include regular expression matching?         */
#define	AEDIT	1  /* advanced editing options: en/detabbing       */
#define	PROC	1  /* named procedures                             */
#define	CLEAN	0  /* de-alloc memory on exit                      */

#define ASCII	1  /* always using ASCII char sequences for now    */
#define EBCDIC	0  /* later IBM mainfraim versions will use EBCDIC */

#ifndef	AUTOCONF

#define	XONXOFF	0  /* don't disable XON-XOFF flow control P.K.     */
#define	NATIONL	0  /* interprete [,],\,{,},| as characters P.K.    */

#else

#define	XONXOFF	(UNIX | VMS)
#define	NATIONL	(UNIX | VMS)

#endif /* Autoconf. */

#define	PKCODE	1      /* include my extensions P.K., define always    */
#define	IBMCHR	MSDOS  /* use IBM PC character set P.K.                */
#define SCROLLCODE 1   /* scrolling code P.K.                          */

/* System dependant library redefinitions, structures and includes. */

#if TURBO
#include <dos.h>
#include <mem.h>
#undef peek
#undef poke
#define       peek(a,b,c,d)   movedata(a,b,FP_SEG(c),FP_OFF(c),d)
#define       poke(a,b,c,d)   movedata(FP_SEG(c),FP_OFF(c),a,b,d)
#endif

#if	VMS
#define	atoi	xatoi
#define	abs	xabs
#define	getname	xgetname
#endif

#if MSDOS & MSC
#include	<dos.h>
#include	<memory.h>
#define	peek(a,b,c,d)	movedata(a,b,FP_SEG(c),FP_OFF(c),d)
#define	poke(a,b,c,d)	movedata(FP_SEG(c),FP_OFF(c),a,b,d)
#define	movmem(a, b, c)		memcpy(b, a, c)
#endif

#if	VMS
#define	unlink(a)	delete(a)
#endif

/* Define some ability flags. */

#if	IBMPC
#define	MEMMAP	1
#else
#define	MEMMAP	0
#endif

#if	MSDOS | V7 | USG | BSD
#define	ENVFUNC	1
#else
#define	ENVFUNC	0
#endif

/* Emacs global flag bit definitions (for gflags). */

#define	GFREAD	1

/* Internal constants. */

#define	NBINDS	256		/* max # of bound keys          */
#define NFILEN  256		/* # of bytes, file name        */
#define NBUFN   16		/* # of bytes, buffer name      */
#define NLINE   256		/* # of bytes, input line       */
#define	NSTRING	128		/* # of bytes, string buffers   */
#define NKBDM   256		/* # of strokes, keyboard macro */
#define NPAT    128		/* # of bytes, pattern          */
#define HUGE    1000		/* Huge number                  */
#define	NLOCKS	100		/* max # of file locks active   */
#define	NCOLORS	8		/* number of supported colors   */
#define	KBLOCK	250		/* sizeof kill buffer chunks    */

#define CONTROL 0x10000000	/* Control flag, or'ed in       */
#define META    0x20000000	/* Meta flag, or'ed in          */
#define CTLX    0x40000000	/* ^X flag, or'ed in            */
#define	SPEC	0x80000000	/* special key (function keys)  */

#ifdef	FALSE
#undef	FALSE
#endif
#ifdef	TRUE
#undef	TRUE
#endif

#define FALSE   0		/* False, no, bad, etc.         */
#define TRUE    1		/* True, yes, good, etc.        */
#define ABORT   2		/* Death, ^G, abort, etc.       */
#define	FAILED	3		/* not-quite fatal false return */

#define	STOP	0		/* keyboard macro not in use    */
#define	PLAY	1		/*                playing       */
#define	RECORD	2		/*                recording     */

/*	Directive definitions	*/

#define	DIF		0
#define DELSE		1
#define DENDIF		2
#define DGOTO		3
#define DRETURN		4
#define DENDM		5
#define DWHILE		6
#define	DENDWHILE	7
#define	DBREAK		8
#define DFORCE		9

#define NUMDIRS		10

/*
 * PTBEG, PTEND, FORWARD, and REVERSE are all toggle-able values for
 * the scan routines.
 */
#define	PTBEG	0		/* Leave the point at the beginning on search   */
#define	PTEND	1		/* Leave the point at the end on search         */
#define	FORWARD	0		/* forward direction            */
#define REVERSE	1		/* backwards direction          */

#define FIOSUC  0		/* File I/O, success.           */
#define FIOFNF  1		/* File I/O, file not found.    */
#define FIOEOF  2		/* File I/O, end of file.       */
#define FIOERR  3		/* File I/O, error.             */
#define	FIOMEM	4		/* File I/O, out of memory      */
#define	FIOFUN	5		/* File I/O, eod of file/bad line */

#define CFCPCN  0x0001		/* Last command was C-P, C-N    */
#define CFKILL  0x0002		/* Last command was a kill      */

#define	BELL	0x07		/* a bell character             */
#define	TAB	0x09		/* a tab character              */

#if	V7 | USG | BSD
#define	PATHCHR	':'
#else
#define	PATHCHR	';'
#endif

#define	INTWIDTH	sizeof(int) * 3

/*	Macro argument token types					*/

#define	TKNUL	0		/* end-of-string                */
#define	TKARG	1		/* interactive argument         */
#define	TKBUF	2		/* buffer argument              */
#define	TKVAR	3		/* user variables               */
#define	TKENV	4		/* environment variables        */
#define	TKFUN	5		/* function....                 */
#define	TKDIR	6		/* directive                    */
#define	TKLBL	7		/* line label                   */
#define	TKLIT	8		/* numeric literal              */
#define	TKSTR	9		/* quoted string literal        */
#define	TKCMD	10		/* command name                 */

/*	Internal defined functions					*/

#define	nextab(a)	(a & ~tabmask) + (tabmask+1)
#ifdef	abs
#undef	abs
#endif

/* DIFCASE represents the integer difference between upper
   and lower case letters.  It is an xor-able value, which is
   fortunate, since the relative positions of upper to lower
   case letters is the opposite of ascii in ebcdic.
*/

#ifdef	islower
#undef	islower
#endif

#if	PKCODE
#ifdef	isupper
#undef	isupper
#endif
#endif

#if	ASCII

#define	DIFCASE		0x20

#if	NATIONL
#define LASTUL ']'
#define LASTLL '}'
#else
#define LASTUL 'Z'
#define LASTLL 'z'
#endif

#if	IBMCHR

#define isletter(c)	(('a' <= c && LASTLL >= c) || ('A' <= c && LASTUL >= c) || (128<=c && c<=167))
#define islower(c)	(('a' <= c && LASTLL >= c))
#define isupper(c)	(('A' <= c && LASTUL >= c))

#else

#define isletter(c)	isxletter((0xFF & (c)))
#define islower(c)	isxlower((0xFF & (c)))
#define isupper(c)	isxupper((0xFF & (c)))

#define isxletter(c)	(('a' <= c && LASTLL >= c) || ('A' <= c && LASTUL >= c) || (192<=c && c<=255))
#define isxlower(c)	(('a' <= c && LASTLL >= c) || (224 <= c && 252 >= c))
#define isxupper(c)	(('A' <= c && LASTUL >= c) || (192 <= c && 220 >= c))

#endif

#endif

#if	EBCDIC

#define	DIFCASE		0x40
#define isletter(c)	(('a' <= c && 'i' >= c) || ('j' <= c && 'r' >= c) || ('s' <= c && 'z' >= c) || ('A' <= c && 'I' >= c) || ('J' <= c && 'R' >= c) || ('S' <= c && 'Z' >= c))
#define islower(c)	(('a' <= c && 'i' >= c) || ('j' <= c && 'r' >= c) || ('s' <= c && 'z' >= c))
#if	PKCODE
#define isupper(c)	(('A' <= c && 'I' >= c) || ('J' <= c && 'R' >= c) || ('S' <= c && 'Z' >= c))
#endif

#endif

/*	Dynamic RAM tracking and reporting redefinitions	*/

#if	RAMSIZE
#define	malloc	allocate
#define	free	release
#endif

/*	De-allocate memory always on exit (if the operating system or
	main program can not
*/

#if	CLEAN
#define	exit(a)	cexit(a)
#endif

/*
 * There is a window structure allocated for every active display window. The
 * windows are kept in a big list, in top to bottom screen order, with the
 * listhead at "wheadp". Each window contains its own values of dot and mark.
 * The flag field contains some bits that are set by commands to guide
 * redisplay. Although this is a bit of a compromise in terms of decoupling,
 * the full blown redisplay is just too expensive to run for every input
 * character.
 */
struct window {
	struct window *w_wndp;	/* Next window                  */
	struct buffer *w_bufp;	/* Buffer displayed in window   */
	struct line *w_linep;	/* Top line in the window       */
	struct line *w_dotp;	/* Line containing "."          */
	struct line *w_markp;	/* Line containing "mark"       */
	int w_doto;		/* Byte offset for "."          */
	int w_marko;		/* Byte offset for "mark"       */
	int w_toprow;		/* Origin 0 top row of window   */
	int w_ntrows;		/* # of rows of text in window  */
	char w_force;		/* If NZ, forcing row.          */
	char w_flag;		/* Flags.                       */
#if	COLOR
	char w_fcolor;		/* current forground color      */
	char w_bcolor;		/* current background color     */
#endif
};

#define WFFORCE 0x01		/* Window needs forced reframe  */
#define WFMOVE  0x02		/* Movement from line to line   */
#define WFEDIT  0x04		/* Editing within a line        */
#define WFHARD  0x08		/* Better to a full display     */
#define WFMODE  0x10		/* Update mode line.            */
#define	WFCOLR	0x20		/* Needs a color change         */

#if SCROLLCODE
#define WFKILLS 0x40		/* something was deleted        */
#define WFINS   0x80		/* something was inserted       */
#endif


/*
 * Text is kept in buffers. A buffer header, described below, exists for every
 * buffer in the system. The buffers are kept in a big list, so that commands
 * that search for a buffer by name can find the buffer header. There is a
 * safe store for the dot and mark in the header, but this is only valid if
 * the buffer is not being displayed (that is, if "b_nwnd" is 0). The text for
 * the buffer is kept in a circularly linked list of lines, with a pointer to
 * the header line in "b_linep".
 * 	Buffers may be "Inactive" which means the files associated with them
 * have not been read in yet. These get read in at "use buffer" time.
 */
struct buffer {
        struct buffer *b_bufp;	/* Link to next struct buffer   */
	struct line *b_dotp;	/* Link to "." struct line structure   */
	struct line *b_markp;	/* The same as the above two,   */
	struct line *b_linep;	/* Link to the header struct line      */
	int b_doto;		/* Offset of "." in above struct line  */
	int b_marko;		/* but for the "mark"           */
	int b_mode;		/* editor mode of this buffer   */
	char b_active;		/* window activated flag        */
	char b_nwnd;		/* Count of windows on buffer   */
	char b_flag;		/* Flags                        */
	char b_fname[NFILEN];	/* File name                    */
	char b_bname[NBUFN];	/* Buffer name                  */
#if	CRYPT
	char b_key[NPAT];	/* current encrypted key        */
#endif
};

#define BFINVS  0x01		/* Internal invisable buffer    */
#define BFCHG   0x02		/* Changed since last write     */
#define	BFTRUNC	0x04		/* buffer was truncated when read */

/*	mode flags	*/
#define	NUMMODES	10	/* # of defined modes           */

#define	MDWRAP	0x0001		/* word wrap                    */
#define	MDCMOD	0x0002		/* C indentation and fence match */
#define	MDSPELL	0x0004		/* spell error parcing          */
#define	MDEXACT	0x0008		/* Exact matching for searches  */
#define	MDVIEW	0x0010		/* read-only buffer             */
#define MDOVER	0x0020		/* overwrite mode               */
#define MDMAGIC	0x0040		/* regular expresions in search */
#define	MDCRYPT	0x0080		/* encrytion mode active        */
#define	MDASAVE	0x0100		/* auto-save mode               */

/*
 * The starting position of a region, and the size of the region in
 * characters, is kept in a region structure.  Used by the region commands.
 */
struct region {
	struct line *r_linep;	/* Origin struct line address.         */
	int r_offset;		/* Origin struct line offset.          */
	long r_size;		/* Length in characters.        */
};

/*
 * The editor communicates with the display using a high level interface. A
 * "TERM" structure holds useful variables, and indirect pointers to routines
 * that do useful operations. The low level get and put routines are here too.
 * This lets a terminal, in addition to having non standard commands, have
 * funny get and put character code too. The calls might get changed to
 * "termp->t_field" style in the future, to make it possible to run more than
 * one terminal type.
 */
struct terminal {
	short t_mrow;		/* max number of rows allowable */
	short t_nrow;		/* current number of rows used  */
	short t_mcol;		/* max Number of columns.       */
	short t_ncol;		/* current Number of columns.   */
	short t_margin;		/* min margin for extended lines */
	short t_scrsiz;		/* size of scroll region "      */
	int t_pause;		/* # times thru update to pause */
	void (*t_open)(void);	/* Open terminal at the start.  */
	void (*t_close)(void);	/* Close terminal at end.       */
	void (*t_kopen)(void);	/* Open keyboard                */
	void (*t_kclose)(void);	/* close keyboard               */
	int (*t_getchar)(void);	/* Get character from keyboard. */
	int (*t_putchar)(int);	/* Put character to display.    */
	void (*t_flush) (void);	/* Flush output buffers.        */
	void (*t_move)(int, int);/* Move the cursor, origin 0.   */
	void (*t_eeol)(void);	/* Erase to end of line.        */
	void (*t_eeop)(void);	/* Erase to end of page.        */
	void (*t_beep)(void);	/* Beep.                        */
	void (*t_rev)(int);	/* set reverse video state      */
	int (*t_rez)(char *);	/* change screen resolution     */
#if	COLOR
	int (*t_setfor) ();	/* set forground color          */
	int (*t_setback) ();	/* set background color         */
#endif
#if     SCROLLCODE
	void (*t_scroll)(int, int,int);	/* scroll a region of the screen */
#endif
};

/*	TEMPORARY macros for terminal I/O  (to be placed in a machine
					    dependant place later)	*/

#define	TTopen		(*term.t_open)
#define	TTclose		(*term.t_close)
#define	TTkopen		(*term.t_kopen)
#define	TTkclose	(*term.t_kclose)
#define	TTgetc		(*term.t_getchar)
#define	TTputc		(*term.t_putchar)
#define	TTflush		(*term.t_flush)
#define	TTmove		(*term.t_move)
#define	TTeeol		(*term.t_eeol)
#define	TTeeop		(*term.t_eeop)
#define	TTbeep		(*term.t_beep)
#define	TTrev		(*term.t_rev)
#define	TTrez		(*term.t_rez)
#if	COLOR
#define	TTforg		(*term.t_setfor)
#define	TTbacg		(*term.t_setback)
#endif

/* Structure for the table of initial key bindings. */
struct key_tab {
	int k_code;		 /* Key code */
	int (*k_fp)(int, int);	 /* Routine to handle it */
};

/* Structure for the name binding table. */
struct name_bind {
	char *n_name;		 /* name of function key */
	int (*n_func)(int, int); /* function name is bound to */
};

/* The editor holds deleted text chunks in the struct kill buffer. The
 * kill buffer is logically a stream of ascii characters, however
 * due to its unpredicatable size, it gets implemented as a linked
 * list of chunks. (The d_ prefix is for "deleted" text, as k_
 * was taken up by the keycode structure).
 */
struct kill {
	struct kill *d_next;   /* Link to next chunk, NULL if last. */
	char d_chunk[KBLOCK];  /* Deleted text. */
};

/* When emacs' command interpetor needs to get a variable's name,
 * rather than it's value, it is passed back as a variable description
 * structure. The v_num field is a index into the appropriate variable table.
 */
struct variable_description {
	int v_type;  /* Type of variable. */
	int v_num;   /* Ordinal pointer to variable in list. */
};

/* The !WHILE directive in the execution language needs to
 * stack references to pending whiles. These are stored linked
 * to each currently open procedure via a linked list of
 * the following structure.
*/
struct while_block {
	struct line *w_begin;        /* ptr to !while statement */
	struct line *w_end;          /* ptr to the !endwhile statement */
	int w_type;		     /* block type */
	struct while_block *w_next;  /* next while */
};

#define	BTWHILE		1
#define	BTBREAK		2

/*
 * Incremental search defines.
 */
#if	ISRCH

#define	CMDBUFLEN	256	/* Length of our command buffer */

#define	IS_ABORT	0x07	/* Abort the isearch */
#define IS_BACKSP	0x08	/* Delete previous char */
#define	IS_TAB		0x09	/* Tab character (allowed search char) */
#define IS_NEWLINE	0x0D	/* New line from keyboard (Carriage return) */
#define	IS_QUOTE	0x11	/* Quote next character */
#define IS_REVERSE	0x12	/* Search backward */
#define	IS_FORWARD	0x13	/* Search forward */
#define	IS_VMSQUOTE	0x16	/* VMS quote character */
#define	IS_VMSFORW	0x18	/* Search forward for VMS */
#define	IS_QUIT		0x1B	/* Exit the search */
#define	IS_RUBOUT	0x7F	/* Delete previous character */

/* IS_QUIT is no longer used, the variable metac is used instead */

#endif

#if defined(MAGIC)
/*
 * Defines for the metacharacters in the regular expression
 * search routines.
 */
#define	MCNIL		0	/* Like the '\0' for strings. */
#define	LITCHAR		1	/* Literal character, or string. */
#define	ANY		2
#define	CCL		3
#define	NCCL		4
#define	BOL		5
#define	EOL		6
#define	DITTO		7
#define	CLOSURE		256	/* An or-able value. */
#define	MASKCL		(CLOSURE - 1)

#define	MC_ANY		'.'	/* 'Any' character (except newline). */
#define	MC_CCL		'['	/* Character class. */
#define	MC_NCCL		'^'	/* Negate character class. */
#define	MC_RCCL		'-'	/* Range in character class. */
#define	MC_ECCL		']'	/* End of character class. */
#define	MC_BOL		'^'	/* Beginning of line. */
#define	MC_EOL		'$'	/* End of line. */
#define	MC_CLOSURE	'*'	/* Closure - does not extend past newline. */
#define	MC_DITTO	'&'	/* Use matched string in replacement. */
#define	MC_ESC		'\\'	/* Escape - suppress meta-meaning. */

#define	BIT(n)		(1 << (n))	/* An integer with one bit set. */
#define	CHCASE(c)	((c) ^ DIFCASE)	/* Toggle the case of a letter. */

/* HICHAR - 1 is the largest character we will deal with.
 * HIBYTE represents the number of bytes in the bitmap.
 */
#define	HICHAR		256
#define	HIBYTE		HICHAR >> 3

/* Typedefs that define the meta-character structure for MAGIC mode searching
 * (struct magic), and the meta-character structure for MAGIC mode replacement
 * (struct magic_replacement).
 */
struct magic {
	short int mc_type;
	union {
		int lchar;
		char *cclmap;
	} u;
};

struct magic_replacement {
	short int mc_type;
	char *rstr;
};

#endif  /* MAGIC */


/* ----- line.h ----- */
#ifndef LINE_H_
#define LINE_H_

/* #include "utf8.h" - amalgamated */

/*
 * All text is kept in circularly linked lists of "struct line" structures. These
 * begin at the header line (which is the blank line beyond the end of the
 * buffer). This line is pointed to by the "struct buffer". Each line contains a the
 * number of bytes in the line (the "used" size), the size of the text array,
 * and the text. The end of line is not stored as a byte; it's implied. Future
 * additions will include update hints, and a list of marks into the line.
 */
struct line {
	struct line *l_fp;	/* Link to the next line        */
	struct line *l_bp;	/* Link to the previous line    */
	int l_size;		/* Allocated size               */
	int l_used;		/* Used size                    */
	char l_text[1];		/* A bunch of characters.       */
};

#define lforw(lp)       ((lp)->l_fp)
#define lback(lp)       ((lp)->l_bp)
#define lgetc(lp, n)    ((lp)->l_text[(n)]&0xFF)
#define lputc(lp, n, c) ((lp)->l_text[(n)]=(c))
#define llength(lp)     ((lp)->l_used)

extern void lfree(struct line *lp);
extern void lchange(int flag);
extern int insspace(int f, int n);
extern int linstr(char *instr);
extern int linsert(int n, int c);
extern int lowrite(int c);
extern int lover(char *ostr);
extern int lnewline(void);
extern int ldelete(long n, int kflag);
extern int ldelchar(long n, int kflag);
extern int lgetchar(unicode_t *);
extern char *getctext(void);
extern int putctext(char *iline);
extern int ldelnewline(void);
extern void kdelete(void);
extern int kinsert(int c);
extern int yank(int f, int n);
extern struct line *lalloc(int);  /* Allocate a line. */

#endif  /* LINE_H_ */


/* ----- edef.h ----- */
/*	edef.h
 *
 *	Global variable definitions
 *
 *	written by Dave G. Conroy
 *	modified by Steve Wilhite, George Jones
 *	greatly modified by Daniel Lawrence
 *	modified by Petri Kutvonen
 */
#ifndef EDEF_H_
#define EDEF_H_

#include <stdlib.h>
#include <string.h>

/* Some global fuction declarations. */
typedef int (*fn_t)(int, int);

/* Initialized global external declarations. */

extern int fillcol;		/* Fill column                  */
extern int kbdm[];		/* Holds kayboard macro data    */
extern char pat[];		/* Search pattern               */
extern char rpat[];		/* Replacement pattern          */
extern char *execstr;		/* pointer to string to execute */
extern char golabel[];		/* current line to go to        */
extern int execlevel;		/* execution IF level           */
extern int eolexist;		/* does clear to EOL exist?     */
extern int revexist;		/* does reverse video exist?    */
extern int flickcode;		/* do flicker supression?       */
extern char *modename[];	/* text names of modes          */
extern char *mode2name[];	/* text names of modes          */
extern char modecode[];		/* letters to represent modes   */
extern struct key_tab keytab[];	/* key bind to functions table  */
extern struct name_bind names[];/* name to function table */
extern int gmode;		/* global editor mode           */
extern int gflags;		/* global control flag          */
extern int gfcolor;		/* global forgrnd color (white) */
extern int gbcolor;		/* global backgrnd color (black) */
extern int gasave;		/* global ASAVE size            */
extern int gacount;		/* count until next ASAVE       */
extern int sgarbf;		/* State of screen unknown      */
extern int mpresf;		/* Stuff in message line        */
extern int clexec;		/* command line execution flag  */
extern int mstore;		/* storing text to macro flag   */
extern int discmd;		/* display command flag         */
extern int disinp;		/* display input characters     */
extern struct buffer *bstore;	/* buffer to store macro text to */
extern int vtrow;		/* Row location of SW cursor */
extern int vtcol;		/* Column location of SW cursor */
extern int ttrow;		/* Row location of HW cursor */
extern int ttcol;		/* Column location of HW cursor */
extern int lbound;		/* leftmost column of current line
				   being displayed */
extern int taboff;		/* tab offset for display       */
extern int metac;		/* current meta character */
extern int ctlxc;		/* current control X prefix char */
extern int reptc;		/* current universal repeat char */
extern int abortc;		/* current abort command char   */

extern int quotec;		/* quote char during mlreply() */
extern int tabmask;
extern char *cname[];		/* names of colors              */
extern struct kill *kbufp;		/* current kill buffer chunk pointer */
extern struct kill *kbufh;		/* kill buffer header pointer   */
extern int kused;		/* # of bytes used in KB        */
extern struct window *swindow;	/* saved window pointer         */
extern int cryptflag;		/* currently encrypting?        */
extern int *kbdptr;		/* current position in keyboard buf */
extern int *kbdend;		/* ptr to end of the keyboard */
extern int kbdmode;		/* current keyboard macro mode  */
extern int kbdrep;		/* number of repetitions        */
extern int restflag;		/* restricted use?              */
extern int lastkey;		/* last keystoke                */
extern int seed;		/* random number seed           */
extern long envram;		/* # of bytes current in use by malloc */
extern int macbug;		/* macro debuging flag          */
extern char errorm[];		/* error literal                */
extern char truem[];		/* true literal                 */
extern char falsem[];		/* false litereal               */
extern int cmdstatus;		/* last command status          */
extern char palstr[];		/* palette string               */
extern int saveflag;		/* Flags, saved with the $target var */
extern char *fline;		/* dynamic return line */
extern int flen;		/* current length of fline */
extern int rval;		/* return value of a subprocess */
#if	PKCODE
extern int nullflag;
extern int justflag;		/* justify, don't fill */
#endif
extern int overlap;		/* line overlap in forw/back page */
extern int scrollcount;		/* number of lines to scroll */

/* Uninitialized global external declarations. */

extern int currow;		/* Cursor row                   */
extern int curcol;		/* Cursor column                */
extern int thisflag;		/* Flags, this command          */
extern int lastflag;		/* Flags, last command          */
extern int curgoal;		/* Goal for C-P, C-N            */
extern struct window *curwp;		/* Current window               */
extern struct buffer *curbp;		/* Current buffer               */
extern struct window *wheadp;                /* Head of list of windows      */
extern struct buffer *bheadp;		/* Head of list of buffers      */
extern struct buffer *blistp;		/* Buffer for C-X C-B           */

extern char sres[NBUFN];	        /* Current screen resolution.   */
extern char pat[];		        /* Search pattern.              */
extern char tap[];		        /* Reversed pattern array.      */
extern char rpat[];		        /* Replacement pattern.         */

extern unsigned int matchlen;
extern unsigned int mlenold;
extern char *patmatch;
extern struct line *matchline;
extern int matchoff;

extern char *dname[];		/* Directive name table.        */

#if	DEBUGM
/* Vars needed for macro debugging output. */
extern char outline[];		/* Global string to hold debug line text. */
#endif

/* Terminal table defined only in term.c */
extern struct terminal term;

#endif  /* EDEF_H_ */


/* ----- efunc.h ----- */
/*	efunc.h
 *
 *	Function declarations and names.
 *
 *	This file list all the C code functions used and the names to use
 *      to bind keys to them. To add functions,	declare it here in both the
 *      extern function list and the name binding table.
 *
 *	modified by Petri Kutvonen
 */

/* External function declarations. */

/* word.c */
extern int wrapword(int f, int n);
extern int backword(int f, int n);
extern int forwword(int f, int n);
extern int upperword(int f, int n);
extern int lowerword(int f, int n);
extern int capword(int f, int n);
extern int delfword(int f, int n);
extern int delbword(int f, int n);
extern int inword(void);
extern int fillpara(int f, int n);
extern int justpara(int f, int n);
extern int killpara(int f, int n);
extern int wordcount(int f, int n);

/* window.c */
extern int reposition(int f, int n);
extern int redraw(int f, int n);
extern int nextwind(int f, int n);
extern int prevwind(int f, int n);
extern int mvdnwind(int f, int n);
extern int mvupwind(int f, int n);
extern int onlywind(int f, int n);
extern int delwind(int f, int n);
extern int splitwind(int f, int n);
extern int enlargewind(int f, int n);
extern int shrinkwind(int f, int n);
extern int resize(int f, int n);
extern int scrnextup(int f, int n);
extern int scrnextdw(int f, int n);
extern int savewnd(int f, int n);
extern int restwnd(int f, int n);
extern int newsize(int f, int n);
extern int newwidth(int f, int n);
extern int getwpos(void);
extern void cknewwindow(void);
extern struct window *wpopup(void);  /* Pop up window creation. */


/* basic.c */
extern int gotobol(int f, int n);
extern int backchar(int f, int n);
extern int gotoeol(int f, int n);
extern int forwchar(int f, int n);
extern int gotoline(int f, int n);
extern int gotobob(int f, int n);
extern int gotoeob(int f, int n);
extern int forwline(int f, int n);
extern int backline(int f, int n);
extern int gotobop(int f, int n);
extern int gotoeop(int f, int n);
extern int forwpage(int f, int n);
extern int backpage(int f, int n);
extern int setmark(int f, int n);
extern int swapmark(int f, int n);

/* random.c */
extern int tabsize;  /* Tab size (0: use real tabs). */
extern int setfillcol(int f, int n);
extern int showcpos(int f, int n);
extern int getcline(void);
extern int getccol(int bflg);
extern int setccol(int pos);
extern int twiddle(int f, int n);
extern int quote(int f, int n);
extern int insert_tab(int f, int n);
extern int detab(int f, int n);
extern int entab(int f, int n);
extern int trim(int f, int n);
extern int openline(int f, int n);
extern int insert_newline(int f, int n);
extern int cinsert(void);
extern int insbrace(int n, int c);
extern int inspound(void);
extern int deblank(int f, int n);
extern int indent(int f, int n);
extern int forwdel(int f, int n);
extern int backdel(int f, int n);
extern int killtext(int f, int n);
extern int setemode(int f, int n);
extern int delmode(int f, int n);
extern int setgmode(int f, int n);
extern int delgmode(int f, int n);
extern int adjustmode(int kind, int global);
extern int clrmes(int f, int n);
extern int writemsg(int f, int n);
extern int getfence(int f, int n);
extern int fmatch(int ch);
extern int istring(int f, int n);
extern int ovstring(int f, int n);

/* main.c */
extern void edinit(char *bname);
extern int execute(int c, int f, int n);
extern int quickexit(int f, int n);
extern int quit(int f, int n);
extern int ctlxlp(int f, int n);
extern int ctlxrp(int f, int n);
extern int ctlxe(int f, int n);
extern int ctrlg(int f, int n);
extern int rdonly(void);
extern int resterr(void);
extern int nullproc(int f, int n);
extern int metafn(int f, int n);
extern int cex(int f, int n);
extern int unarg(int f, int n);
extern int cexit(int status);

/* display.c */
extern void vtinit(void);
extern void vtfree(void);
extern void vttidy(void);
extern void vtmove(int row, int col);
extern int upscreen(int f, int n);
extern int update(int force);
extern void updpos(void);
extern void upddex(void);
extern void updgar(void);
extern int updupd(int force);
extern void upmode(void);
extern void movecursor(int row, int col);
extern void mlerase(void);
extern void mlwrite(const char *fmt, ...);
extern void mlforce(char *s);
extern void mlputs(char *s);
extern void getscreensize(int *widthp, int *heightp);
extern void sizesignal(int signr);

/* region.c */
extern int killregion(int f, int n);
extern int copyregion(int f, int n);
extern int lowerregion(int f, int n);
extern int upperregion(int f, int n);
extern int getregion(struct region *rp);

/* posix.c */
extern void ttopen(void);
extern void ttclose(void);
extern int ttputc(int c);
extern void ttflush(void);
extern int ttgetc(void);
extern int typahead(void);

/* input.c */
extern int mlyesno(char *prompt);
extern int mlreply(char *prompt, char *buf, int nbuf);
extern int mlreplyt(char *prompt, char *buf, int nbuf, int eolchar);
extern int ectoc(int c);
extern int ctoec(int c);
extern fn_t getname(void);
extern int tgetc(void);
extern int get1key(void);
extern int getcmd(void);
extern int getstring(char *prompt, char *buf, int nbuf, int eolchar);
extern void outstring(char *s);
extern void ostring(char *s);

/* bind.c */
extern int help(int f, int n);
extern int deskey(int f, int n);
extern int bindtokey(int f, int n);
extern int unbindkey(int f, int n);
extern int unbindchar(int c);
extern int desbind(int f, int n);
extern int apro(int f, int n);
extern int buildlist(int type, char *mstring);
extern int strinc(char *source, char *sub);
extern unsigned int getckey(int mflag);
extern int startup(char *sfname);
extern char *flook(char *fname, int hflag);
extern void cmdstr(int c, char *seq);
extern fn_t getbind(int c);
extern char *getfname(fn_t);
extern fn_t fncmatch(char *);
extern unsigned int stock(char *keyname);
extern char *transbind(char *skey);

/* buffer.c */
extern int usebuffer(int f, int n);
extern int nextbuffer(int f, int n);
extern int swbuffer(struct buffer *bp);
extern int killbuffer(int f, int n);
extern int zotbuf(struct buffer *bp);
extern int namebuffer(int f, int n);
extern int listbuffers(int f, int n);
extern int makelist(int iflag);
extern void ltoa(char *buf, int width, long num);
extern int addline(char *text);
extern int anycb(void);
extern int bclear(struct buffer *bp);
extern int unmark(int f, int n);
/* Lookup a buffer by name. */
extern struct buffer *bfind(char *bname, int cflag, int bflag);

/* file.c */
extern int fileread(int f, int n);
extern int insfile(int f, int n);
extern int filefind(int f, int n);
extern int viewfile(int f, int n);
extern int getfile(char *fname, int lockfl);
extern int readin(char *fname, int lockfl);
extern void makename(char *bname, char *fname);
extern void unqname(char *name);
extern int filewrite(int f, int n);
extern int filesave(int f, int n);
extern int writeout(char *fn);
extern int filename(int f, int n);
extern int ifile(char *fname);

/* fileio.c */
extern int ffropen(char *fn);
extern int ffwopen(char *fn);
extern int ffclose(void);
extern int ffputline(char *buf, int nbuf);
extern int ffgetline(void);
extern int fexist(char *fname);

/* exec.c */
extern int namedcmd(int f, int n);
extern int execcmd(int f, int n);
extern int docmd(char *cline);
extern char *token(char *src, char *tok, int size);
extern int macarg(char *tok);
extern int nextarg(char *prompt, char *buffer, int size, int terminator);
extern int storemac(int f, int n);
extern int storeproc(int f, int n);
extern int execproc(int f, int n);
extern int execbuf(int f, int n);
extern int dobuf(struct buffer *bp);
extern void freewhile(struct while_block *wp);
extern int execfile(int f, int n);
extern int dofile(char *fname);
extern int cbuf(int f, int n, int bufnum);
extern int cbuf1(int f, int n);
extern int cbuf2(int f, int n);
extern int cbuf3(int f, int n);
extern int cbuf4(int f, int n);
extern int cbuf5(int f, int n);
extern int cbuf6(int f, int n);
extern int cbuf7(int f, int n);
extern int cbuf8(int f, int n);
extern int cbuf9(int f, int n);
extern int cbuf10(int f, int n);
extern int cbuf11(int f, int n);
extern int cbuf12(int f, int n);
extern int cbuf13(int f, int n);
extern int cbuf14(int f, int n);
extern int cbuf15(int f, int n);
extern int cbuf16(int f, int n);
extern int cbuf17(int f, int n);
extern int cbuf18(int f, int n);
extern int cbuf19(int f, int n);
extern int cbuf20(int f, int n);
extern int cbuf21(int f, int n);
extern int cbuf22(int f, int n);
extern int cbuf23(int f, int n);
extern int cbuf24(int f, int n);
extern int cbuf25(int f, int n);
extern int cbuf26(int f, int n);
extern int cbuf27(int f, int n);
extern int cbuf28(int f, int n);
extern int cbuf29(int f, int n);
extern int cbuf30(int f, int n);
extern int cbuf31(int f, int n);
extern int cbuf32(int f, int n);
extern int cbuf33(int f, int n);
extern int cbuf34(int f, int n);
extern int cbuf35(int f, int n);
extern int cbuf36(int f, int n);
extern int cbuf37(int f, int n);
extern int cbuf38(int f, int n);
extern int cbuf39(int f, int n);
extern int cbuf40(int f, int n);

/* spawn.c */
extern int spawncli(int f, int n);
extern int bktoshell(int f, int n);
extern void rtfrmshell(void);
extern int spawn(int f, int n);
extern int execprg(int f, int n);
extern int pipecmd(int f, int n);
extern int filter_buffer(int f, int n);
extern int sys(char *cmd);
extern int shellprog(char *cmd);
extern int execprog(char *cmd);

/* search.c */
extern int forwsearch(int f, int n);
extern int forwhunt(int f, int n);
extern int backsearch(int f, int n);
extern int backhunt(int f, int n);
extern int mcscanner(struct magic *mcpatrn, int direct, int beg_or_end);
extern int scanner(const char *patrn, int direct, int beg_or_end);
extern int eq(unsigned char bc, unsigned char pc);
extern void savematch(void);
extern void rvstrcpy(char *rvstr, char *str);
extern int sreplace(int f, int n);
extern int qreplace(int f, int n);
extern int delins(int dlength, char *instr, int use_meta);
extern int expandp(char *srcstr, char *deststr, int maxlength);
extern int boundry(struct line *curline, int curoff, int dir);
extern void mcclear(void);
extern void rmcclear(void);

/* isearch.c */
extern int risearch(int f, int n);
extern int fisearch(int f, int n);
extern int isearch(int f, int n);
extern int checknext(char chr, char *patrn, int dir);
extern int scanmore(char *patrn, int dir);
extern int match_pat(char *patrn);
extern int promptpattern(char *prompt);
extern int get_char(void);
extern int uneat(void);
extern void reeat(int c);

/* eval.c */
extern void varinit(void);
extern char *gtfun(char *fname);
extern char *gtusr(char *vname);
extern char *gtenv(char *vname);
extern char *getkill(void);
extern int setvar(int f, int n);
extern void findvar(char *var, struct variable_description *vd, int size);
extern int svar(struct variable_description *var, char *value);
extern char *itoa(int i);
extern int gettyp(char *token);
extern char *getval(char *token, char *result, int size);
extern int stol(char *val);
extern char *ltos(int val);
extern char *mkupper(char *str);
extern char *mklower(char *str);
extern int abs(int x);
extern int ernd(void);
extern int sindex(char *source, char *pattern);
extern char *xlat(char *source, char *lookup, char *trans);

/* crypt.c */
extern int set_encryption_key(int f, int n);
extern void myencrypt(char *bptr, unsigned len);

/* lock.c */
extern int lockchk(char *fname);
extern int lockrel(void);
extern int lock(char *fname);
extern int unlock(char *fname);
extern void lckerror(char *errstr);

/* pklock.c */
extern char *dolock(char *fname);
extern char *undolock(char *fname);


/* ----- evar.h ----- */
/*	EVAR.H
 *
 *	Environment and user variable definitions
 *
 *	written 1986 by Daniel Lawrence
 *	modified by Petri Kutvonen
 */
#ifndef EVAR_H_
#define EVAR_H_

/* Max #chars in a var name. */
#define	NVSIZE	10

/* Structure to hold user variables and their definitions. */
struct user_variable {
	char u_name[NVSIZE + 1]; /* name of user variable */
	char *u_value;		 /* value (string) */
};

/* List of recognized environment variables. */

static char *envars[] = {
	"fillcol",		/* current fill column */
	"pagelen",		/* number of lines used by editor */
	"curcol",		/* current column pos of cursor */
	"curline",		/* current line in file */
	"ram",			/* ram in use by malloc */
	"flicker",		/* flicker supression */
	"curwidth",		/* current screen width */
	"cbufname",		/* current buffer name */
	"cfname",		/* current file name */
	"sres",			/* current screen resolution */
	"debug",		/* macro debugging */
	"status",		/* returns the status of the last command */
	"palette",		/* current palette string */
	"asave",		/* # of chars between auto-saves */
	"acount",		/* # of chars until next auto-save */
	"lastkey",		/* last keyboard char struck */
	"curchar",		/* current character under the cursor */
	"discmd",		/* display commands on command line */
	"version",		/* current version number */
	"progname",		/* returns current prog name - "MicroEMACS" */
	"seed",			/* current random number seed */
	"disinp",		/* display command line input characters */
	"wline",		/* # of lines in current window */
	"cwline",		/* current screen line in window */
	"target",		/* target for line moves */
	"search",		/* search pattern */
	"replace",		/* replacement pattern */
	"match",		/* last matched magic pattern */
	"kill",			/* kill buffer (read only) */
	"cmode",		/* mode of current buffer */
	"gmode",		/* global modes */
	"tpause",		/* length to pause for paren matching */
	"pending",		/* type ahead pending flag */
	"lwidth",		/* width of current line */
	"line",			/* text of current line */
	"gflags",		/* global internal emacs flags */
	"rval",			/* child process return value */
	"tab",			/* tab 4 or 8 */
	"overlap",
	"jump",
#if SCROLLCODE
	"scroll",		/* scroll enabled */
#endif
};

/* And its preprocesor definitions. */

#define	EVFILLCOL	0
#define	EVPAGELEN	1
#define	EVCURCOL	2
#define	EVCURLINE	3
#define	EVRAM		4
#define	EVFLICKER	5
#define	EVCURWIDTH	6
#define	EVCBUFNAME	7
#define	EVCFNAME	8
#define	EVSRES		9
#define	EVDEBUG		10
#define	EVSTATUS	11
#define	EVPALETTE	12
#define	EVASAVE		13
#define	EVACOUNT	14
#define	EVLASTKEY	15
#define	EVCURCHAR	16
#define	EVDISCMD	17
#define	EVVERSION	18
#define	EVPROGNAME	19
#define	EVSEED		20
#define	EVDISINP	21
#define	EVWLINE		22
#define EVCWLINE	23
#define	EVTARGET	24
#define	EVSEARCH	25
#define	EVREPLACE	26
#define	EVMATCH		27
#define	EVKILL		28
#define	EVCMODE		29
#define	EVGMODE		30
#define	EVTPAUSE	31
#define	EVPENDING	32
#define	EVLWIDTH	33
#define	EVLINE		34
#define	EVGFLAGS	35
#define	EVRVAL		36
#define EVTAB		37
#define EVOVERLAP	38
#define EVSCROLLCOUNT	39
#define EVSCROLL	40

enum function_type {
	NILNAMIC = 0,
	MONAMIC,
	DYNAMIC,
	TRINAMIC,
};

/* List of recognized user functions. */
struct user_function {
	char *f_name;
	enum function_type f_type;
};

static struct user_function funcs[] = {
	{ "add", DYNAMIC },	/* add two numbers together */
	{ "sub", DYNAMIC },	/* subtraction */
	{ "tim", DYNAMIC },	/* multiplication */
	{ "div", DYNAMIC },	/* division */
	{ "mod", DYNAMIC },	/* mod */
	{ "neg", MONAMIC },	/* negate */
	{ "cat", DYNAMIC },	/* concatinate string */
	{ "lef", DYNAMIC },	/* left string(string, len) */
	{ "rig", DYNAMIC },	/* right string(string, pos) */
	{ "mid", TRINAMIC },	/* mid string(string, pos, len) */
	{ "not", MONAMIC },	/* logical not */
	{ "equ", DYNAMIC },	/* logical equality check */
	{ "les", DYNAMIC },	/* logical less than */
	{ "gre", DYNAMIC },	/* logical greater than */
	{ "seq", DYNAMIC },	/* string logical equality check */
	{ "sle", DYNAMIC },	/* string logical less than */
	{ "sgr", DYNAMIC },	/* string logical greater than */
	{ "ind", MONAMIC },	/* evaluate indirect value */
	{ "and", DYNAMIC },	/* logical and */
	{ "or", DYNAMIC },	/* logical or */
	{ "len", MONAMIC },	/* string length */
	{ "upp", MONAMIC },	/* uppercase string */
	{ "low", MONAMIC },	/* lower case string */
	{ "tru", MONAMIC },	/* Truth of the universe logical test */
	{ "asc", MONAMIC },	/* char to integer conversion */
	{ "chr", MONAMIC },	/* integer to char conversion */
	{ "gtk", NILNAMIC },	/* get 1 charater */
	{ "rnd", MONAMIC },	/* get a random number */
	{ "abs", MONAMIC },	/* absolute value of a number */
	{ "sin", DYNAMIC },	/* find the index of one string in another */
	{ "env", MONAMIC },	/* retrieve a system environment var */
	{ "bin", MONAMIC },	/* loopup what function name is bound to a key */
	{ "exi", MONAMIC },	/* check if a file exists */
	{ "fin", MONAMIC },	/* look for a file on the path... */
	{ "ban", DYNAMIC },	/* bitwise and   9-10-87  jwm */
	{ "bor", DYNAMIC },	/* bitwise or    9-10-87  jwm */
	{ "bxo", DYNAMIC },	/* bitwise xor   9-10-87  jwm */
	{ "bno", MONAMIC },	/* bitwise not */
	{ "xla", TRINAMIC },	/* XLATE character string translation */
};

/* And its preprocesor definitions. */

#define	UFADD		0
#define	UFSUB		1
#define	UFTIMES		2
#define	UFDIV		3
#define	UFMOD		4
#define	UFNEG		5
#define	UFCAT		6
#define	UFLEFT		7
#define	UFRIGHT		8
#define	UFMID		9
#define	UFNOT		10
#define	UFEQUAL		11
#define	UFLESS		12
#define	UFGREATER	13
#define	UFSEQUAL	14
#define	UFSLESS		15
#define	UFSGREAT	16
#define	UFIND		17
#define	UFAND		18
#define	UFOR		19
#define	UFLENGTH	20
#define	UFUPPER		21
#define	UFLOWER		22
#define	UFTRUTH		23
#define	UFASCII		24
#define	UFCHR		25
#define	UFGTKEY		26
#define	UFRND		27
#define	UFABS		28
#define	UFSINDEX	29
#define	UFENV		30
#define	UFBIND		31
#define	UFEXIST		32
#define	UFFIND		33
#define UFBAND		34
#define UFBOR		35
#define UFBXOR		36
#define	UFBNOT		37
#define	UFXLATE		38

#endif  /* EVAR_H_ */


/* ----- epath.h ----- */
/*	EPATH.H
 *
 *	This file contains certain info needed to locate the
 *	initialization (etc) files on a system dependent basis
 *
 *	modified by Petri Kutvonen
 */
#ifndef EPATH_H_
#define EPATH_H_

/*	possible names and paths of help files under different OSs	*/
static char *pathname[] =
#if	MSDOS
{
	"emacs.rc",
	"emacs.hlp",
	"\\sys\\public\\",
	"\\usr\\bin\\",
	"\\bin\\",
	"\\",
	""
};
#endif

#if	V7 | BSD | USG
{
	".emacsrc", "emacs.hlp",
#if	PKCODE
	    "/usr/global/lib/", "/usr/local/bin/", "/usr/local/lib/",
#endif
"/usr/local/", "/usr/lib/", ""};
#endif

#if	VMS
{
	"emacs.rc", "emacs.hlp", "",
#if	PKCODE
	    "sys$login:", "emacs_dir:",
#endif
"sys$sysdevice:[vmstools]"};
#endif

#endif  /* EPATH_H_ */


/* ----- ebind.h ----- */
/*	ebind.h
 *
 *	Initial default key to function bindings
 *
 *	Modified by Petri Kutvonen
 */

#ifndef EBIND_H_
#define EBIND_H_

/* #include "line.h" - amalgamated */

/*
 * Command table.
 * This table  is *roughly* in ASCII order, left to right across the
 * characters of the command. This explains the funny location of the
 * control-X commands.
 */
struct key_tab keytab[NBINDS] = {
	{CONTROL | 'A', gotobol}
	,
	{CONTROL | 'B', backchar}
	,
	{CONTROL | 'C', insspace}
	,
	{CONTROL | 'D', forwdel}
	,
	{CONTROL | 'E', gotoeol}
	,
	{CONTROL | 'F', forwchar}
	,
	{CONTROL | 'G', ctrlg}
	,
	{CONTROL | 'H', backdel}
	,
	{CONTROL | 'I', insert_tab}
	,
	{CONTROL | 'J', indent}
	,
	{CONTROL | 'K', killtext}
	,
	{CONTROL | 'L', redraw}
	,
	{CONTROL | 'M', insert_newline}
	,
	{CONTROL | 'N', forwline}
	,
	{CONTROL | 'O', openline}
	,
	{CONTROL | 'P', backline}
	,
	{CONTROL | 'Q', quote}
	,
	{CONTROL | 'R', backsearch}
	,
	{CONTROL | 'S', forwsearch}
	,
	{CONTROL | 'T', twiddle}
	,
	{CONTROL | 'U', unarg}
	,
	{CONTROL | 'V', forwpage}
	,
	{CONTROL | 'W', killregion}
	,
	{CONTROL | 'X', cex}
	,
	{CONTROL | 'Y', yank}
	,
	{CONTROL | 'Z', backpage}
	,
	{CONTROL | ']', metafn}
	,
	{CTLX | CONTROL | 'B', listbuffers}
	,
	{CTLX | CONTROL | 'C', quit}
	,			/* Hard quit.           */
#if	PKCODE & AEDIT
	{CTLX | CONTROL | 'A', detab}
	,
#endif
#if	PKCODE
	{CTLX | CONTROL | 'D', filesave}
	,			/* alternative          */
#else
#if	AEDIT
	{CTLX | CONTROL | 'D', detab}
	,
#endif
#endif
#if	AEDIT
	{CTLX | CONTROL | 'E', entab}
	,
#endif
	{CTLX | CONTROL | 'F', filefind}
	,
	{CTLX | CONTROL | 'I', insfile}
	,
	{CTLX | CONTROL | 'L', lowerregion}
	,
	{CTLX | CONTROL | 'M', delmode}
	,
	{CTLX | CONTROL | 'N', mvdnwind}
	,
	{CTLX | CONTROL | 'O', deblank}
	,
	{CTLX | CONTROL | 'P', mvupwind}
	,
	{CTLX | CONTROL | 'R', fileread}
	,
	{CTLX | CONTROL | 'S', filesave}
	,
#if	AEDIT
	{CTLX | CONTROL | 'T', trim}
	,
#endif
	{CTLX | CONTROL | 'U', upperregion}
	,
	{CTLX | CONTROL | 'V', viewfile}
	,
	{CTLX | CONTROL | 'W', filewrite}
	,
	{CTLX | CONTROL | 'X', swapmark}
	,
	{CTLX | CONTROL | 'Z', shrinkwind}
	,
	{CTLX | '?', deskey}
	,
	{CTLX | '!', spawn}
	,
	{CTLX | '@', pipecmd}
	,
	{CTLX | '#', filter_buffer}
	,
	{CTLX | '$', execprg}
	,
	{CTLX | '=', showcpos}
	,
	{CTLX | '(', ctlxlp}
	,
	{CTLX | ')', ctlxrp}
	,
	{CTLX | '^', enlargewind}
	,
	{CTLX | '0', delwind}
	,
	{CTLX | '1', onlywind}
	,
	{CTLX | '2', splitwind}
	,
	{CTLX | 'A', setvar}
	,
	{CTLX | 'B', usebuffer}
	,
	{CTLX | 'C', spawncli}
	,
#if	BSD | __hpux | SVR4
	{CTLX | 'D', bktoshell}
	,
#endif
	{CTLX | 'E', ctlxe}
	,
	{CTLX | 'F', setfillcol}
	,
	{CTLX | 'K', killbuffer}
	,
	{CTLX | 'M', setemode}
	,
	{CTLX | 'N', filename}
	,
	{CTLX | 'O', nextwind}
	,
	{CTLX | 'P', prevwind}
	,
#if	PKCODE
	{CTLX | 'Q', quote}
	,			/* alternative  */
#endif
#if	ISRCH
	{CTLX | 'R', risearch}
	,
	{CTLX | 'S', fisearch}
	,
#endif
	{CTLX | 'W', resize}
	,
	{CTLX | 'X', nextbuffer}
	,
	{CTLX | 'Z', enlargewind}
	,
#if	WORDPRO
	{META | CONTROL | 'C', wordcount}
	,
#endif
#if	PKCODE
	{META | CONTROL | 'D', newsize}
	,
#endif
#if	PROC
	{META | CONTROL | 'E', execproc}
	,
#endif
#if	CFENCE
	{META | CONTROL | 'F', getfence}
	,
#endif
	{META | CONTROL | 'H', delbword}
	,
	{META | CONTROL | 'K', unbindkey}
	,
	{META | CONTROL | 'L', reposition}
	,
	{META | CONTROL | 'M', delgmode}
	,
	{META | CONTROL | 'N', namebuffer}
	,
	{META | CONTROL | 'R', qreplace}
	,
	{META | CONTROL | 'S', newsize}
	,
	{META | CONTROL | 'T', newwidth}
	,
	{META | CONTROL | 'V', scrnextdw}
	,
#if	WORDPRO
	{META | CONTROL | 'W', killpara}
	,
#endif
	{META | CONTROL | 'Z', scrnextup}
	,
	{META | ' ', setmark}
	,
	{META | '?', help}
	,
	{META | '!', reposition}
	,
	{META | '.', setmark}
	,
	{META | '>', gotoeob}
	,
	{META | '<', gotobob}
	,
	{META | '~', unmark}
	,
#if	APROP
	{META | 'A', apro}
	,
#endif
	{META | 'B', backword}
	,
	{META | 'C', capword}
	,
	{META | 'D', delfword}
	,
#if	CRYPT
	{META | 'E', set_encryption_key}
	,
#endif
	{META | 'F', forwword}
	,
	{META | 'G', gotoline}
	,
#if	PKCODE
#if	WORDPRO
	{META | 'J', justpara}
	,
#endif
#endif
	{META | 'K', bindtokey}
	,
	{META | 'L', lowerword}
	,
	{META | 'M', setgmode}
	,
#if	WORDPRO
	{META | 'N', gotoeop}
	,
	{META | 'P', gotobop}
	,
	{META | 'Q', fillpara}
	,
#endif
	{META | 'R', sreplace}
	,
#if	PKCODE
	{META | 'S', forwsearch}
	,			/* alternative P.K.     */
#else
#if	BSD
	{META | 'S', bktoshell}
	,
#endif
#endif
	{META | 'U', upperword}
	,
	{META | 'V', backpage}
	,
	{META | 'W', copyregion}
	,
	{META | 'X', namedcmd}
	,
	{META | 'Z', quickexit}
	,
	{META | 0x7F, delbword}
	,

#if	MSDOS
	{SPEC | CONTROL | '_', forwhunt}
	,
	{SPEC | CONTROL | 'S', backhunt}
	,
	{SPEC | 71, gotobol}
	,
	{SPEC | 72, backline}
	,
	{SPEC | 73, backpage}
	,
	{SPEC | 75, backchar}
	,
	{SPEC | 77, forwchar}
	,
	{SPEC | 79, gotoeol}
	,
	{SPEC | 80, forwline}
	,
	{SPEC | 81, forwpage}
	,
	{SPEC | 82, insspace}
	,
	{SPEC | 83, forwdel}
	,
	{SPEC | 115, backword}
	,
	{SPEC | 116, forwword}
	,
#if	WORDPRO
	{SPEC | 132, gotobop}
	,
	{SPEC | 118, gotoeop}
	,
#endif
	{SPEC | 84, cbuf1}
	,
	{SPEC | 85, cbuf2}
	,
	{SPEC | 86, cbuf3}
	,
	{SPEC | 87, cbuf4}
	,
	{SPEC | 88, cbuf5}
	,
	{SPEC | 89, cbuf6}
	,
	{SPEC | 90, cbuf7}
	,
	{SPEC | 91, cbuf8}
	,
	{SPEC | 92, cbuf9}
	,
	{SPEC | 93, cbuf10}
	,
#if PKCODE
	{SPEC | 117, gotoeob}
	,
	{SPEC | 119, gotobob}
	,
	{SPEC | 141, gotobop}
	,
	{SPEC | 145, gotoeop}
	,
	{SPEC | 146, yank}
	,
	{SPEC | 147, killregion}
	,
#endif
#endif

#if	VT220
	{SPEC | '1', fisearch}
	,			/* VT220 keys   */
	{SPEC | '2', yank}
	,
	{SPEC | '3', killregion}
	,
	{SPEC | '4', setmark}
	,
	{SPEC | '5', backpage}
	,
	{SPEC | '6', forwpage}
	,
	{SPEC | 'A', backline}
	,
	{SPEC | 'B', forwline}
	,
	{SPEC | 'C', forwchar}
	,
	{SPEC | 'D', backchar}
	,
	{SPEC | 'c', metafn}
	,
	{SPEC | 'd', backchar}
	,
	{SPEC | 'e', forwline}
	,
	{SPEC | 'f', gotobob}
	,
	{SPEC | 'h', help}
	,
	{SPEC | 'i', cex}
	,
#endif

	{0x7F, backdel}
	,

	/* special internal bindings */
	{ SPEC | META | 'W', wrapword },	/* called on word wrap */
	{ SPEC | META | 'C', nullproc },	/*  every command input */
	{ SPEC | META | 'R', nullproc },	/*  on file read */
	{ SPEC | META | 'X', nullproc },	/*  on window change P.K. */

	{0, NULL}
};

#endif  /* EBIND_H_ */


/* ========== SOURCE FILES ========== */

/* ----- utf8.c ----- */
/* #include "utf8.h" - amalgamated */

/*
 * utf8_to_unicode()
 *
 * Convert a UTF-8 sequence to its unicode value, and return the length of
 * the sequence in bytes.
 *
 * NOTE! Invalid UTF-8 will be converted to a one-byte sequence, so you can
 * either use it as-is (ie as Latin1) or you can check for invalid UTF-8
 * by checking for a length of 1 and a result > 127.
 *
 * NOTE 2! This does *not* verify things like minimality. So overlong forms
 * are happily accepted and decoded, as are the various "invalid values".
 */
unsigned utf8_to_unicode(char *line, unsigned index, unsigned len, unicode_t *res)
{
	unsigned value;
	unsigned char c = line[index];
	unsigned bytes, mask, i;

	*res = c;
	line += index;
	len -= index;

	/*
	 * 0xxxxxxx is valid utf8
	 * 10xxxxxx is invalid UTF-8, we assume it is Latin1
	 */
	if (c < 0xc0)
		return 1;

	/* Ok, it's 11xxxxxx, do a stupid decode */
	mask = 0x20;
	bytes = 2;
	while (c & mask) {
		bytes++;
		mask >>= 1;
	}

	/* Invalid? Do it as a single byte Latin1 */
	if (bytes > 6)
		return 1;
	if (bytes > len)
		return 1;

	value = c & (mask-1);

	/* Ok, do the bytes */
	for (i = 1; i < bytes; i++) {
		c = line[i];
		if ((c & 0xc0) != 0x80)
			return 1;
		value = (value << 6) | (c & 0x3f);
	}
	*res = value;
	return bytes;
}

static void reverse_string(char *begin, char *end)
{
	do {
		char a = *begin, b = *end;
		*end = a; *begin = b;
		begin++; end--;
	} while (begin < end);
}

/*
 * unicode_to_utf8()
 *
 * Convert a unicode value to its canonical utf-8 sequence.
 *
 * NOTE! This does not check for - or care about - the "invalid" unicode
 * values.  Also, converting a utf-8 sequence to unicode and back does
 * *not* guarantee the same sequence, since this generates the shortest
 * possible sequence, while utf8_to_unicode() accepts both Latin1 and
 * overlong utf-8 sequences.
 */
unsigned unicode_to_utf8(unsigned int c, char *utf8)
{
	int bytes = 1;

	*utf8 = c;
	if (c > 0x7f) {
		int prefix = 0x40;
		char *p = utf8;
		do {
			*p++ = 0x80 + (c & 0x3f);
			bytes++;
			prefix >>= 1;
			c >>= 6;
		} while (c > prefix);
		*p = c - 2*prefix;
		reverse_string(utf8, p);
	}
	return bytes;
}


/* ----- util.c ----- */
/* #include "util.h" - amalgamated */

/* Safe zeroing, no complaining about overlap */
void mystrscpy(char *dst, const char *src, int size)
{
	if (!size)
		return;
	while (--size) {
		char c = *src++;
		if (!c)
			break;
		*dst++ = c;
	}
	*dst = 0;
}




/* ----- usage.c ----- */
/* #include "usage.h" - amalgamated */
/* system header already included */
/* system header already included */
/* system header already included */
static void report(const char* prefix, const char *err, va_list params)
{
	char msg[4096];
	vsnprintf(msg, sizeof(msg), err, params);
	fprintf(stderr, "%s%s\n", prefix, msg);
}

void die(const char* err, ...)
{
	va_list params;

	va_start(params, err);
	report("fatal: ", err, params);
	va_end(params);
	exit(128);
}


/* ----- wrapper.c ----- */
/* #include "usage.h" - amalgamated */
/* system header already included */
/* Function copyright: git */
int xmkstemp(char *template)
{
	int fd;

	fd = mkstemp(template);
	if (fd < 0)
		die("Unable to create temporary file");
	return fd;
}

void *xmalloc(size_t size)
{
	void *ret = malloc(size);
	if (!ret)
		die("Out of memory");
	return ret;
}


/* ----- version.c ----- */
/* system header already included */
/* #include "version.h" - amalgamated */

void version(void)
{
	printf("%s version %s\n", PROGRAM_NAME_LONG, VERSION);
}


/* ----- globals.c ----- */
/* #include "estruct.h" - amalgamated */
/* #include "edef.h" - amalgamated */

/* initialized global definitions */

int fillcol = 72;		/* Current fill column          */
int kbdm[NKBDM];		/* Macro                        */
char *execstr = NULL;		/* pointer to string to execute */
char golabel[NPAT] = "";	/* current line to go to        */
int execlevel = 0;		/* execution IF level           */
int eolexist = TRUE;		/* does clear to EOL exist      */
int revexist = FALSE;		/* does reverse video exist?    */
int flickcode = FALSE;		/* do flicker supression?       */
char *modename[] = {		/* name of modes                */
	"WRAP", "CMODE", "SPELL", "EXACT", "VIEW", "OVER",
	"MAGIC", "CRYPT", "ASAVE", "UTF-8"
};
char *mode2name[] = {		/* name of modes                */
	"Wrap", "Cmode", "Spell", "Exact", "View", "Over",
	"Magic", "Crypt", "Asave", "utf-8"
};
char modecode[] = "WCSEVOMYAU";	/* letters to represent modes   */
int gmode = 0;			/* global editor mode           */
int gflags = GFREAD;		/* global control flag          */
#if	PKCODE & IBMPC
int gfcolor = 8;		/* global forgrnd color (white) */
#else
int gfcolor = 7;		/* global forgrnd color (white) */
#endif
int gbcolor = 0;		/* global backgrnd color (black) */
int gasave = 256;		/* global ASAVE size            */
int gacount = 256;		/* count until next ASAVE       */
int sgarbf = TRUE;		/* TRUE if screen is garbage    */
int mpresf = FALSE;		/* TRUE if message in last line */
int clexec = FALSE;		/* command line execution flag  */
int mstore = FALSE;		/* storing text to macro flag   */
int discmd = TRUE;		/* display command flag         */
int disinp = TRUE;		/* display input characters     */
struct buffer *bstore = NULL;	/* buffer to store macro text to */
int vtrow = 0;			/* Row location of SW cursor */
int vtcol = 0;			/* Column location of SW cursor */
int ttrow = HUGE;		/* Row location of HW cursor */
int ttcol = HUGE;		/* Column location of HW cursor */
int lbound = 0;			/* leftmost column of current line
				   being displayed */
int taboff = 0;			/* tab offset for display       */
int metac = CONTROL | '[';	/* current meta character */
int ctlxc = CONTROL | 'X';	/* current control X prefix char */
int reptc = CONTROL | 'U';	/* current universal repeat char */
int abortc = CONTROL | 'G';	/* current abort command char   */

int quotec = 0x11;		/* quote char during mlreply() */
int tabmask = 0x07;		/* tabulator mask */
char *cname[] = {		/* names of colors              */
	"BLACK", "RED", "GREEN", "YELLOW", "BLUE",
	"MAGENTA", "CYAN", "WHITE"
#if	PKCODE & IBMPC
	    , "HIGH"
#endif
};
struct kill *kbufp = NULL;		/* current kill buffer chunk pointer    */
struct kill *kbufh = NULL;		/* kill buffer header pointer           */
int kused = KBLOCK;		/* # of bytes used in kill buffer       */
struct window *swindow = NULL;	/* saved window pointer                 */
int cryptflag = FALSE;		/* currently encrypting?                */
int *kbdptr;			/* current position in keyboard buf */
int *kbdend = &kbdm[0];		/* ptr to end of the keyboard */
int kbdmode = STOP;		/* current keyboard macro mode  */
int kbdrep = 0;			/* number of repetitions        */
int restflag = FALSE;		/* restricted use?              */
int lastkey = 0;		/* last keystoke                */
int seed = 0;			/* random number seed           */
long envram = 0l;		/* # of bytes current in use by malloc */
int macbug = FALSE;		/* macro debuging flag          */
char errorm[] = "ERROR";	/* error literal                */
char truem[] = "TRUE";		/* true literal                 */
char falsem[] = "FALSE";	/* false litereal               */
int cmdstatus = TRUE;		/* last command status          */
char palstr[49] = "";		/* palette string               */
int saveflag = 0;		/* Flags, saved with the $target var */
char *fline = NULL;		/* dynamic return line */
int flen = 0;			/* current length of fline */
int rval = 0;			/* return value of a subprocess */
#if	PKCODE
int nullflag = FALSE;		/* accept null characters */
int justflag = FALSE;		/* justify, don't fill */
#endif
int overlap = 0;		/* line overlap in forw/back page */
int scrollcount = 1;		/* number of lines to scroll */

/* uninitialized global definitions */

int currow;			/* Cursor row                   */
int curcol;			/* Cursor column                */
int thisflag;			/* Flags, this command          */
int lastflag;			/* Flags, last command          */
int curgoal;			/* Goal for C-P, C-N            */
struct window *curwp;		/* Current window               */
struct buffer *curbp;			/* Current buffer               */
struct window *wheadp;		/* Head of list of windows      */
struct buffer *bheadp;			/* Head of list of buffers      */
struct buffer *blistp;			/* Buffer for C-X C-B           */

char sres[NBUFN];		/* current screen resolution    */
char pat[NPAT];			/* Search pattern               */
char tap[NPAT];			/* Reversed pattern array.      */
char rpat[NPAT];		/* replacement pattern          */

/* The variable matchlen holds the length of the matched
 * string - used by the replace functions.
 * The variable patmatch holds the string that satisfies
 * the search command.
 * The variables matchline and matchoff hold the line and
 * offset position of the *start* of match.
 */
unsigned int matchlen = 0;
unsigned int mlenold = 0;
char *patmatch = NULL;
struct line *matchline = NULL;
int matchoff = 0;

/* directive name table:
	This holds the names of all the directives....	*/

char *dname[] = {
	"if", "else", "endif",
	"goto", "return", "endm",
	"while", "endwhile", "break",
	"force"
};

#if	DEBUGM
/*	vars needed for macro debugging output	*/
char outline[NSTRING];		/* global string to hold debug line text */
#endif


/* ----- line.c ----- */
/*	line.c
 *
 * The functions in this file are a general set of line management utilities.
 * They are the only routines that touch the text. They also touch the buffer
 * and window structures, to make sure that the necessary updating gets done.
 * There are routines in this file that handle the kill buffer too. It isn't
 * here for any good reason.
 *
 * Note that this code only updates the dot and mark values in the window list.
 * Since all the code acts on the current window, the buffer that we are
 * editing must be being displayed, which means that "b_nwnd" is non zero,
 * which means that the dot and mark values in the buffer headers are nonsense.
 *
 */

/* #include "line.h" - amalgamated */
/* system header already included */
/* #include "estruct.h" - amalgamated */
/* #include "edef.h" - amalgamated */
/* #include "efunc.h" - amalgamated */
/* #include "utf8.h" - amalgamated */

#define	BLOCK_SIZE 16 /* Line block chunk size. */

/*
 * This routine allocates a block of memory large enough to hold a struct line
 * containing "used" characters. The block is always rounded up a bit. Return
 * a pointer to the new block, or NULL if there isn't any memory left. Print a
 * message in the message line if no space.
 */
struct line *lalloc(int used)
{
	struct line *lp;
	int size;

	size = (used + BLOCK_SIZE - 1) & ~(BLOCK_SIZE - 1);
	if (size == 0)	/* Assume that is an empty. */
		size = BLOCK_SIZE;  /* Line is for type-in. */
	if ((lp = (struct line *)malloc(sizeof(struct line) + size)) == NULL) {
		mlwrite("(OUT OF MEMORY)");
		return NULL;
	}
	lp->l_size = size;
	lp->l_used = used;
	return lp;
}

/*
 * Delete line "lp". Fix all of the links that might point at it (they are
 * moved to offset 0 of the next line. Unlink the line from whatever buffer it
 * might be in. Release the memory. The buffers are updated too; the magic
 * conditions described in the above comments don't hold here.
 */
void lfree(struct line *lp)
{
	struct buffer *bp;
	struct window *wp;

	wp = wheadp;
	while (wp != NULL) {
		if (wp->w_linep == lp)
			wp->w_linep = lp->l_fp;
		if (wp->w_dotp == lp) {
			wp->w_dotp = lp->l_fp;
			wp->w_doto = 0;
		}
		if (wp->w_markp == lp) {
			wp->w_markp = lp->l_fp;
			wp->w_marko = 0;
		}
		wp = wp->w_wndp;
	}
	bp = bheadp;
	while (bp != NULL) {
		if (bp->b_nwnd == 0) {
			if (bp->b_dotp == lp) {
				bp->b_dotp = lp->l_fp;
				bp->b_doto = 0;
			}
			if (bp->b_markp == lp) {
				bp->b_markp = lp->l_fp;
				bp->b_marko = 0;
			}
		}
		bp = bp->b_bufp;
	}
	lp->l_bp->l_fp = lp->l_fp;
	lp->l_fp->l_bp = lp->l_bp;
	free((char *) lp);
}

/*
 * This routine gets called when a character is changed in place in the current
 * buffer. It updates all of the required flags in the buffer and window
 * system. The flag used is passed as an argument; if the buffer is being
 * displayed in more than 1 window we change EDIT t HARD. Set MODE if the
 * mode line needs to be updated (the "*" has to be set).
 */
void lchange(int flag)
{
	struct window *wp;

	if (curbp->b_nwnd != 1)	/* Ensure hard.     */
		flag = WFHARD;
	if ((curbp->b_flag & BFCHG) == 0) {	/* First change, so     */
		flag |= WFMODE;	/* update mode lines.   */
		curbp->b_flag |= BFCHG;
	}
	wp = wheadp;
	while (wp != NULL) {
		if (wp->w_bufp == curbp)
			wp->w_flag |= flag;
		wp = wp->w_wndp;
	}
}

/*
 * insert spaces forward into text
 *
 * int f, n;		default flag and numeric argument
 */
int insspace(int f, int n)
{
	linsert(n, ' ');
	backchar(f, n);
	return TRUE;
}

/*
 * linstr -- Insert a string at the current point
 */

int linstr(char *instr)
{
	int status = TRUE;
	char tmpc;

	if (instr != NULL)
		while ((tmpc = *instr) && status == TRUE) {
			status =
			    (tmpc == '\n' ? lnewline() : linsert(1, tmpc));

			/* Insertion error? */
			if (status != TRUE) {
				mlwrite("%%Out of memory while inserting");
				break;
			}
			instr++;
		}
	return status;
}

/*
 * Insert "n" copies of the character "c" at the current location of dot. In
 * the easy case all that happens is the text is stored in the line. In the
 * hard case, the line has to be reallocated. When the window list is updated,
 * take special care; I screwed it up once. You always update dot in the
 * current window. You update mark, and a dot in another window, if it is
 * greater than the place where you did the insert. Return TRUE if all is
 * well, and FALSE on errors.
 */

static int linsert_byte(int n, int c)
{
	char *cp1;
	char *cp2;
	struct line *lp1;
	struct line *lp2;
	struct line *lp3;
	int doto;
	int i;
	struct window *wp;

	if (curbp->b_mode & MDVIEW)	/* don't allow this command if      */
		return rdonly();	/* we are in read only mode     */
	lchange(WFEDIT);
	lp1 = curwp->w_dotp;	/* Current line         */
	if (lp1 == curbp->b_linep) {	/* At the end: special  */
		if (curwp->w_doto != 0) {
			mlwrite("bug: linsert");
			return FALSE;
		}
		if ((lp2 = lalloc(n)) == NULL)	/* Allocate new line        */
			return FALSE;
		lp3 = lp1->l_bp;	/* Previous line        */
		lp3->l_fp = lp2;	/* Link in              */
		lp2->l_fp = lp1;
		lp1->l_bp = lp2;
		lp2->l_bp = lp3;
		for (i = 0; i < n; ++i)
			lp2->l_text[i] = c;
		curwp->w_dotp = lp2;
		curwp->w_doto = n;
		return TRUE;
	}
	doto = curwp->w_doto;	/* Save for later.      */
	if (lp1->l_used + n > lp1->l_size) {	/* Hard: reallocate     */
		if ((lp2 = lalloc(lp1->l_used + n)) == NULL)
			return FALSE;
		cp1 = &lp1->l_text[0];
		cp2 = &lp2->l_text[0];
		while (cp1 != &lp1->l_text[doto])
			*cp2++ = *cp1++;
		cp2 += n;
		while (cp1 != &lp1->l_text[lp1->l_used])
			*cp2++ = *cp1++;
		lp1->l_bp->l_fp = lp2;
		lp2->l_fp = lp1->l_fp;
		lp1->l_fp->l_bp = lp2;
		lp2->l_bp = lp1->l_bp;
		free((char *) lp1);
	} else {		/* Easy: in place       */
		lp2 = lp1;	/* Pretend new line     */
		lp2->l_used += n;
		cp2 = &lp1->l_text[lp1->l_used];
		cp1 = cp2 - n;
		while (cp1 != &lp1->l_text[doto])
			*--cp2 = *--cp1;
	}
	for (i = 0; i < n; ++i)	/* Add the characters       */
		lp2->l_text[doto + i] = c;
	wp = wheadp;		/* Update windows       */
	while (wp != NULL) {
		if (wp->w_linep == lp1)
			wp->w_linep = lp2;
		if (wp->w_dotp == lp1) {
			wp->w_dotp = lp2;
			if (wp == curwp || wp->w_doto > doto)
				wp->w_doto += n;
		}
		if (wp->w_markp == lp1) {
			wp->w_markp = lp2;
			if (wp->w_marko > doto)
				wp->w_marko += n;
		}
		wp = wp->w_wndp;
	}
	return TRUE;
}

int linsert(int n, int c)
{
	char utf8[6];
	int bytes = unicode_to_utf8(c, utf8), i;

	if (bytes == 1)
		return linsert_byte(n, (unsigned char) utf8[0]);
	for (i = 0; i < n; i++) {
		int j;
		for (j = 0; j < bytes; j++) {
			unsigned char c = utf8[j];
			if (!linsert_byte(1, c))
				return FALSE;
		}
	}
	return TRUE;
}

/*
 * Overwrite a character into the current line at the current position
 *
 * int c;	character to overwrite on current position
 */
int lowrite(int c)
{
	if (curwp->w_doto < curwp->w_dotp->l_used &&
	    (lgetc(curwp->w_dotp, curwp->w_doto) != '\t' ||
	     ((curwp->w_doto) & tabmask) == tabmask))
		ldelchar(1, FALSE);
	return linsert(1, c);
}

/*
 * lover -- Overwrite a string at the current point
 */
int lover(char *ostr)
{
	int status = TRUE;
	char tmpc;

	if (ostr != NULL)
		while ((tmpc = *ostr) && status == TRUE) {
			status =
			    (tmpc == '\n' ? lnewline() : lowrite(tmpc));

			/* Insertion error? */
			if (status != TRUE) {
				mlwrite
				    ("%%Out of memory while overwriting");
				break;
			}
			ostr++;
		}
	return status;
}

/*
 * Insert a newline into the buffer at the current location of dot in the
 * current window. The funny ass-backwards way it does things is not a botch;
 * it just makes the last line in the file not a special case. Return TRUE if
 * everything works out and FALSE on error (memory allocation failure). The
 * update of dot and mark is a bit easier then in the above case, because the
 * split forces more updating.
 */
int lnewline(void)
{
	char *cp1;
	char *cp2;
	struct line *lp1;
	struct line *lp2;
	int doto;
	struct window *wp;

	if (curbp->b_mode & MDVIEW)	/* don't allow this command if      */
		return rdonly();	/* we are in read only mode     */
#if SCROLLCODE
	lchange(WFHARD | WFINS);
#else
	lchange(WFHARD);
#endif
	lp1 = curwp->w_dotp;	/* Get the address and  */
	doto = curwp->w_doto;	/* offset of "."        */
	if ((lp2 = lalloc(doto)) == NULL)	/* New first half line      */
		return FALSE;
	cp1 = &lp1->l_text[0];	/* Shuffle text around  */
	cp2 = &lp2->l_text[0];
	while (cp1 != &lp1->l_text[doto])
		*cp2++ = *cp1++;
	cp2 = &lp1->l_text[0];
	while (cp1 != &lp1->l_text[lp1->l_used])
		*cp2++ = *cp1++;
	lp1->l_used -= doto;
	lp2->l_bp = lp1->l_bp;
	lp1->l_bp = lp2;
	lp2->l_bp->l_fp = lp2;
	lp2->l_fp = lp1;
	wp = wheadp;		/* Windows              */
	while (wp != NULL) {
		if (wp->w_linep == lp1)
			wp->w_linep = lp2;
		if (wp->w_dotp == lp1) {
			if (wp->w_doto < doto)
				wp->w_dotp = lp2;
			else
				wp->w_doto -= doto;
		}
		if (wp->w_markp == lp1) {
			if (wp->w_marko < doto)
				wp->w_markp = lp2;
			else
				wp->w_marko -= doto;
		}
		wp = wp->w_wndp;
	}
	return TRUE;
}

int lgetchar(unicode_t *c)
{
	int len = llength(curwp->w_dotp);
	char *buf = curwp->w_dotp->l_text;
	return utf8_to_unicode(buf, curwp->w_doto, len, c);
}

/*
 * ldelete() really fundamentally works on bytes, not characters.
 * It is used for things like "scan 5 words forwards, and remove
 * the bytes we scanned".
 *
 * If you want to delete characters, use ldelchar().
 */
int ldelchar(long n, int kflag)
{
	while (n-- > 0) {
		unicode_t c;
		if (!ldelete(lgetchar(&c), kflag))
			return FALSE;
	}
	return TRUE;
}

/*
 * This function deletes "n" bytes, starting at dot. It understands how do deal
 * with end of lines, etc. It returns TRUE if all of the characters were
 * deleted, and FALSE if they were not (because dot ran into the end of the
 * buffer. The "kflag" is TRUE if the text should be put in the kill buffer.
 *
 * long n;		# of chars to delete
 * int kflag;		 put killed text in kill buffer flag
 */
int ldelete(long n, int kflag)
{
	char *cp1;
	char *cp2;
	struct line *dotp;
	int doto;
	int chunk;
	struct window *wp;

	if (curbp->b_mode & MDVIEW)	/* don't allow this command if      */
		return rdonly();	/* we are in read only mode     */
	while (n != 0) {
		dotp = curwp->w_dotp;
		doto = curwp->w_doto;
		if (dotp == curbp->b_linep)	/* Hit end of buffer.       */
			return FALSE;
		chunk = dotp->l_used - doto;	/* Size of chunk.       */
		if (chunk > n)
			chunk = n;
		if (chunk == 0) {	/* End of line, merge.  */
#if SCROLLCODE
			lchange(WFHARD | WFKILLS);
#else
			lchange(WFHARD);
#endif
			if (ldelnewline() == FALSE
			    || (kflag != FALSE && kinsert('\n') == FALSE))
				return FALSE;
			--n;
			continue;
		}
		lchange(WFEDIT);
		cp1 = &dotp->l_text[doto];	/* Scrunch text.        */
		cp2 = cp1 + chunk;
		if (kflag != FALSE) {	/* Kill?                */
			while (cp1 != cp2) {
				if (kinsert(*cp1) == FALSE)
					return FALSE;
				++cp1;
			}
			cp1 = &dotp->l_text[doto];
		}
		while (cp2 != &dotp->l_text[dotp->l_used])
			*cp1++ = *cp2++;
		dotp->l_used -= chunk;
		wp = wheadp;	/* Fix windows          */
		while (wp != NULL) {
			if (wp->w_dotp == dotp && wp->w_doto >= doto) {
				wp->w_doto -= chunk;
				if (wp->w_doto < doto)
					wp->w_doto = doto;
			}
			if (wp->w_markp == dotp && wp->w_marko >= doto) {
				wp->w_marko -= chunk;
				if (wp->w_marko < doto)
					wp->w_marko = doto;
			}
			wp = wp->w_wndp;
		}
		n -= chunk;
	}
	return TRUE;
}

/*
 * getctext:	grab and return a string with the text of
 *		the current line
 */
char *getctext(void)
{
	struct line *lp;	/* line to copy */
	int size;	/* length of line to return */
	char *sp;	/* string pointer into line */
	char *dp;	/* string pointer into returned line */
	static char rline[NSTRING];	/* line to return */

	/* find the contents of the current line and its length */
	lp = curwp->w_dotp;
	sp = lp->l_text;
	size = lp->l_used;
	if (size >= NSTRING)
		size = NSTRING - 1;

	/* copy it across */
	dp = rline;
	while (size--)
		*dp++ = *sp++;
	*dp = 0;
	return rline;
}

/*
 * putctext:
 *	replace the current line with the passed in text
 *
 * char *iline;			contents of new line
 */
int putctext(char *iline)
{
	int status;

	/* delete the current line */
	curwp->w_doto = 0;	/* starting at the beginning of the line */
	if ((status = killtext(TRUE, 1)) != TRUE)
		return status;

	/* insert the new line */
	if ((status = linstr(iline)) != TRUE)
		return status;
	status = lnewline();
	backline(TRUE, 1);
	return status;
}

/*
 * Delete a newline. Join the current line with the next line. If the next line
 * is the magic header line always return TRUE; merging the last line with the
 * header line can be thought of as always being a successful operation, even
 * if nothing is done, and this makes the kill buffer work "right". Easy cases
 * can be done by shuffling data around. Hard cases require that lines be moved
 * about in memory. Return FALSE on error and TRUE if all looks ok. Called by
 * "ldelete" only.
 */
int ldelnewline(void)
{
	char *cp1;
	char *cp2;
	struct line *lp1;
	struct line *lp2;
	struct line *lp3;
	struct window *wp;

	if (curbp->b_mode & MDVIEW)	/* don't allow this command if      */
		return rdonly();	/* we are in read only mode     */
	lp1 = curwp->w_dotp;
	lp2 = lp1->l_fp;
	if (lp2 == curbp->b_linep) {	/* At the buffer end.   */
		if (lp1->l_used == 0)	/* Blank line.              */
			lfree(lp1);
		return TRUE;
	}
	if (lp2->l_used <= lp1->l_size - lp1->l_used) {
		cp1 = &lp1->l_text[lp1->l_used];
		cp2 = &lp2->l_text[0];
		while (cp2 != &lp2->l_text[lp2->l_used])
			*cp1++ = *cp2++;
		wp = wheadp;
		while (wp != NULL) {
			if (wp->w_linep == lp2)
				wp->w_linep = lp1;
			if (wp->w_dotp == lp2) {
				wp->w_dotp = lp1;
				wp->w_doto += lp1->l_used;
			}
			if (wp->w_markp == lp2) {
				wp->w_markp = lp1;
				wp->w_marko += lp1->l_used;
			}
			wp = wp->w_wndp;
		}
		lp1->l_used += lp2->l_used;
		lp1->l_fp = lp2->l_fp;
		lp2->l_fp->l_bp = lp1;
		free((char *) lp2);
		return TRUE;
	}
	if ((lp3 = lalloc(lp1->l_used + lp2->l_used)) == NULL)
		return FALSE;
	cp1 = &lp1->l_text[0];
	cp2 = &lp3->l_text[0];
	while (cp1 != &lp1->l_text[lp1->l_used])
		*cp2++ = *cp1++;
	cp1 = &lp2->l_text[0];
	while (cp1 != &lp2->l_text[lp2->l_used])
		*cp2++ = *cp1++;
	lp1->l_bp->l_fp = lp3;
	lp3->l_fp = lp2->l_fp;
	lp2->l_fp->l_bp = lp3;
	lp3->l_bp = lp1->l_bp;
	wp = wheadp;
	while (wp != NULL) {
		if (wp->w_linep == lp1 || wp->w_linep == lp2)
			wp->w_linep = lp3;
		if (wp->w_dotp == lp1)
			wp->w_dotp = lp3;
		else if (wp->w_dotp == lp2) {
			wp->w_dotp = lp3;
			wp->w_doto += lp1->l_used;
		}
		if (wp->w_markp == lp1)
			wp->w_markp = lp3;
		else if (wp->w_markp == lp2) {
			wp->w_markp = lp3;
			wp->w_marko += lp1->l_used;
		}
		wp = wp->w_wndp;
	}
	free((char *) lp1);
	free((char *) lp2);
	return TRUE;
}

/*
 * Delete all of the text saved in the kill buffer. Called by commands when a
 * new kill context is being created. The kill buffer array is released, just
 * in case the buffer has grown to immense size. No errors.
 */
void kdelete(void)
{
	struct kill *kp;		/* ptr to scan kill buffer chunk list */

	if (kbufh != NULL) {

		/* first, delete all the chunks */
		kbufp = kbufh;
		while (kbufp != NULL) {
			kp = kbufp->d_next;
			free(kbufp);
			kbufp = kp;
		}

		/* and reset all the kill buffer pointers */
		kbufh = kbufp = NULL;
		kused = KBLOCK;
	}
}

/*
 * Insert a character to the kill buffer, allocating new chunks as needed.
 * Return TRUE if all is well, and FALSE on errors.
 *
 * int c;			character to insert in the kill buffer
 */
int kinsert(int c)
{
	struct kill *nchunk;		/* ptr to newly malloced chunk */

	/* check to see if we need a new chunk */
	if (kused >= KBLOCK) {
		if ((nchunk = (struct kill *)malloc(sizeof(struct kill))) == NULL)
			return FALSE;
		if (kbufh == NULL)	/* set head ptr if first time */
			kbufh = nchunk;
		if (kbufp != NULL)	/* point the current to this new one */
			kbufp->d_next = nchunk;
		kbufp = nchunk;
		kbufp->d_next = NULL;
		kused = 0;
	}

	/* and now insert the character */
	kbufp->d_chunk[kused++] = c;
	return TRUE;
}

/*
 * Yank text back from the kill buffer. This is really easy. All of the work
 * is done by the standard insert routines. All you do is run the loop, and
 * check for errors. Bound to "C-Y".
 */
int yank(int f, int n)
{
	int c;
	int i;
	char *sp;	/* pointer into string to insert */
	struct kill *kp;		/* pointer into kill buffer */

	if (curbp->b_mode & MDVIEW)	/* don't allow this command if      */
		return rdonly();	/* we are in read only mode     */
	if (n < 0)
		return FALSE;
	/* make sure there is something to yank */
	if (kbufh == NULL)
		return TRUE;	/* not an error, just nothing */

	/* for each time.... */
	while (n--) {
		kp = kbufh;
		while (kp != NULL) {
			if (kp->d_next == NULL)
				i = kused;
			else
				i = KBLOCK;
			sp = kp->d_chunk;
			while (i--) {
				if ((c = *sp++) == '\n') {
					if (lnewline() == FALSE)
						return FALSE;
				} else {
					if (linsert_byte(1, c) == FALSE)
						return FALSE;
				}
			}
			kp = kp->d_next;
		}
	}
	return TRUE;
}


/* ----- names.c ----- */
/* Name to function binding table.
 *
 * This table gives the names of all the bindable functions
 * end their C function address. These are used for the bind-to-key
 * function.
*/

/* #include "estruct.h" - amalgamated */
/* #include "edef.h" - amalgamated */
/* #include "efunc.h" - amalgamated */
/* #include "line.h" - amalgamated */

struct name_bind names[] = {
	{"abort-command", ctrlg},
	{"add-mode", setemode},
	{"add-global-mode", setgmode},
#if	APROP
	{"apropos", apro},
#endif
	{"backward-character", backchar},
	{"begin-macro", ctlxlp},
	{"beginning-of-file", gotobob},
	{"beginning-of-line", gotobol},
	{"bind-to-key", bindtokey},
	{"buffer-position", showcpos},
	{"case-region-lower", lowerregion},
	{"case-region-upper", upperregion},
	{"case-word-capitalize", capword},
	{"case-word-lower", lowerword},
	{"case-word-upper", upperword},
	{"change-file-name", filename},
	{"change-screen-size", newsize},
	{"change-screen-width", newwidth},
	{"clear-and-redraw", redraw},
	{"clear-message-line", clrmes},
	{"copy-region", copyregion},
#if	WORDPRO
	{"count-words", wordcount},
#endif
	{"ctlx-prefix", cex},
	{"delete-blank-lines", deblank},
	{"delete-buffer", killbuffer},
	{"delete-mode", delmode},
	{"delete-global-mode", delgmode},
	{"delete-next-character", forwdel},
	{"delete-next-word", delfword},
	{"delete-other-windows", onlywind},
	{"delete-previous-character", backdel},
	{"delete-previous-word", delbword},
	{"delete-window", delwind},
	{"describe-bindings", desbind},
	{"describe-key", deskey},
#if	AEDIT
	{"detab-line", detab},
#endif
	{"end-macro", ctlxrp},
	{"end-of-file", gotoeob},
	{"end-of-line", gotoeol},
#if	AEDIT
	{"entab-line", entab},
#endif
	{"exchange-point-and-mark", swapmark},
	{"execute-buffer", execbuf},
	{"execute-command-line", execcmd},
	{"execute-file", execfile},
	{"execute-macro", ctlxe},
	{"execute-macro-1", cbuf1},
	{"execute-macro-2", cbuf2},
	{"execute-macro-3", cbuf3},
	{"execute-macro-4", cbuf4},
	{"execute-macro-5", cbuf5},
	{"execute-macro-6", cbuf6},
	{"execute-macro-7", cbuf7},
	{"execute-macro-8", cbuf8},
	{"execute-macro-9", cbuf9},
	{"execute-macro-10", cbuf10},
	{"execute-macro-11", cbuf11},
	{"execute-macro-12", cbuf12},
	{"execute-macro-13", cbuf13},
	{"execute-macro-14", cbuf14},
	{"execute-macro-15", cbuf15},
	{"execute-macro-16", cbuf16},
	{"execute-macro-17", cbuf17},
	{"execute-macro-18", cbuf18},
	{"execute-macro-19", cbuf19},
	{"execute-macro-20", cbuf20},
	{"execute-macro-21", cbuf21},
	{"execute-macro-22", cbuf22},
	{"execute-macro-23", cbuf23},
	{"execute-macro-24", cbuf24},
	{"execute-macro-25", cbuf25},
	{"execute-macro-26", cbuf26},
	{"execute-macro-27", cbuf27},
	{"execute-macro-28", cbuf28},
	{"execute-macro-29", cbuf29},
	{"execute-macro-30", cbuf30},
	{"execute-macro-31", cbuf31},
	{"execute-macro-32", cbuf32},
	{"execute-macro-33", cbuf33},
	{"execute-macro-34", cbuf34},
	{"execute-macro-35", cbuf35},
	{"execute-macro-36", cbuf36},
	{"execute-macro-37", cbuf37},
	{"execute-macro-38", cbuf38},
	{"execute-macro-39", cbuf39},
	{"execute-macro-40", cbuf40},
	{"execute-named-command", namedcmd},
#if	PROC
	{"execute-procedure", execproc},
#endif
	{"execute-program", execprg},
	{"exit-emacs", quit},
#if	WORDPRO
	{"fill-paragraph", fillpara},
#endif
	{"filter-buffer", filter_buffer},
	{"find-file", filefind},
	{"forward-character", forwchar},
	{"goto-line", gotoline},
#if	CFENCE
	{"goto-matching-fence", getfence},
#endif
	{"grow-window", enlargewind},
	{"handle-tab", insert_tab},
	{"hunt-forward", forwhunt},
	{"hunt-backward", backhunt},
	{"help", help},
	{"i-shell", spawncli},
#if	ISRCH
	{"incremental-search", fisearch},
#endif
	{"insert-file", insfile},
	{"insert-space", insspace},
	{"insert-string", istring},
#if	WORDPRO
#if	PKCODE
	{"justify-paragraph", justpara},
#endif
	{"kill-paragraph", killpara},
#endif
	{"kill-region", killregion},
	{"kill-to-end-of-line", killtext},
	{"list-buffers", listbuffers},
	{"meta-prefix", metafn},
	{"move-window-down", mvdnwind},
	{"move-window-up", mvupwind},
	{"name-buffer", namebuffer},
	{"newline", insert_newline},
	{"newline-and-indent", indent},
	{"next-buffer", nextbuffer},
	{"next-line", forwline},
	{"next-page", forwpage},
#if	WORDPRO
	{"next-paragraph", gotoeop},
#endif
	{"next-window", nextwind},
	{"next-word", forwword},
	{"nop", nullproc},
	{"open-line", openline},
	{"overwrite-string", ovstring},
	{"pipe-command", pipecmd},
	{"previous-line", backline},
	{"previous-page", backpage},
#if	WORDPRO
	{"previous-paragraph", gotobop},
#endif
	{"previous-window", prevwind},
	{"previous-word", backword},
	{"query-replace-string", qreplace},
	{"quick-exit", quickexit},
	{"quote-character", quote},
	{"read-file", fileread},
	{"redraw-display", reposition},
	{"resize-window", resize},
	{"restore-window", restwnd},
	{"replace-string", sreplace},
#if	ISRCH
	{"reverse-incremental-search", risearch},
#endif
#if	PROC
	{"run", execproc},
#endif
	{"save-file", filesave},
	{"save-window", savewnd},
	{"scroll-next-up", scrnextup},
	{"scroll-next-down", scrnextdw},
	{"search-forward", forwsearch},
	{"search-reverse", backsearch},
	{"select-buffer", usebuffer},
	{"set", setvar},
#if	CRYPT
	{"set-encryption-key", set_encryption_key},
#endif
	{"set-fill-column", setfillcol},
	{"set-mark", setmark},
	{"shell-command", spawn},
	{"shrink-window", shrinkwind},
	{"split-current-window", splitwind},
	{"store-macro", storemac},
#if	PROC
	{"store-procedure", storeproc},
#endif
#if	BSD | __hpux | SVR4
	{"suspend-emacs", bktoshell},
#endif
	{"transpose-characters", twiddle},
#if	AEDIT
	{"trim-line", trim},
#endif
	{"unbind-key", unbindkey},
	{"universal-argument", unarg},
	{"unmark-buffer", unmark},
	{"update-screen", upscreen},
	{"view-file", viewfile},
	{"wrap-word", wrapword},
	{"write-file", filewrite},
	{"write-message", writemsg},
	{"yank", yank},

	{"", NULL}
};


/* ----- basic.c ----- */
/*	basic.c
 *
 * The routines in this file move the cursor around on the screen. They
 * compute a new value for the cursor, then adjust ".". The display code
 * always updates the cursor location, so only moves between lines, or
 * functions that adjust the top line in the window and invalidate the
 * framing, are hard.
 *
 *	modified by Petri Kutvonen
 */
/* system header already included */
/* #include "estruct.h" - amalgamated */
/* #include "edef.h" - amalgamated */
/* #include "efunc.h" - amalgamated */
/* #include "line.h" - amalgamated */
/* #include "utf8.h" - amalgamated */

/*
 * This routine, given a pointer to a struct line, and the current cursor goal
 * column, return the best choice for the offset. The offset is returned.
 * Used by "C-N" and "C-P".
 */
static int getgoal(struct line *dlp)
{
	int col;
	int newcol;
	int dbo;
	int len = llength(dlp);

	col = 0;
	dbo = 0;
	while (dbo != len) {
		unicode_t c;
		int width = utf8_to_unicode(dlp->l_text, dbo, len, &c);
		newcol = col;

		/* Take tabs, ^X and \xx hex characters into account */
		if (c == '\t')
			newcol |= tabmask;
		else if (c < 0x20 || c == 0x7F)
			++newcol;
		else if (c >= 0x80 && c <= 0xa0)
			newcol += 2;

		++newcol;
		if (newcol > curgoal)
			break;
		col = newcol;
		dbo += width;
	}
	return dbo;
}

/*
 * Move the cursor to the beginning of the current line.
 */
int gotobol(int f, int n)
{
	curwp->w_doto = 0;
	return TRUE;
}

/*
 * Move the cursor backwards by "n" characters. If "n" is less than zero call
 * "forwchar" to actually do the move. Otherwise compute the new cursor
 * location. Error if you try and move out of the buffer. Set the flag if the
 * line pointer for dot changes.
 */
int backchar(int f, int n)
{
	struct line *lp;

	if (n < 0)
		return forwchar(f, -n);
	while (n--) {
		if (curwp->w_doto == 0) {
			if ((lp = lback(curwp->w_dotp)) == curbp->b_linep)
				return FALSE;
			curwp->w_dotp = lp;
			curwp->w_doto = llength(lp);
			curwp->w_flag |= WFMOVE;
		} else {
			do {
				unsigned char c;
				curwp->w_doto--;
				c = lgetc(curwp->w_dotp, curwp->w_doto);
				if (is_beginning_utf8(c))
					break;
			} while (curwp->w_doto);
		}
	}
	return TRUE;
}

/*
 * Move the cursor to the end of the current line. Trivial. No errors.
 */
int gotoeol(int f, int n)
{
	curwp->w_doto = llength(curwp->w_dotp);
	return TRUE;
}

/*
 * Move the cursor forwards by "n" characters. If "n" is less than zero call
 * "backchar" to actually do the move. Otherwise compute the new cursor
 * location, and move ".". Error if you try and move off the end of the
 * buffer. Set the flag if the line pointer for dot changes.
 */
int forwchar(int f, int n)
{
	if (n < 0)
		return backchar(f, -n);
	while (n--) {
		int len = llength(curwp->w_dotp);
		if (curwp->w_doto == len) {
			if (curwp->w_dotp == curbp->b_linep)
				return FALSE;
			curwp->w_dotp = lforw(curwp->w_dotp);
			curwp->w_doto = 0;
			curwp->w_flag |= WFMOVE;
		} else {
			do {
				unsigned char c;
				curwp->w_doto++;
				c = lgetc(curwp->w_dotp, curwp->w_doto);
				if (is_beginning_utf8(c))
					break;
			} while (curwp->w_doto < len);
		}
	}
	return TRUE;
}

/*
 * Move to a particular line.
 *
 * @n: The specified line position at the current buffer.
 */
int gotoline(int f, int n)
{
	int status;
	char arg[NSTRING]; /* Buffer to hold argument. */

	/* Get an argument if one doesnt exist. */
	if (f == FALSE) {
		if ((status =
		     mlreply("Line to GOTO: ", arg, NSTRING)) != TRUE) {
			mlwrite("(Aborted)");
			return status;
		}
		n = atoi(arg);
	}
        /* Handle the case where the user may be passed something like this:
         * em filename +
         * In this case we just go to the end of the buffer.
         */
	if (n == 0)
		return gotoeob(f, n);

	/* If a bogus argument was passed, then returns false. */
	if (n < 0)
		return FALSE;

	/* First, we go to the begin of the buffer. */
	gotobob(f, n);
	return forwline(f, n - 1);
}

/*
 * Goto the beginning of the buffer. Massive adjustment of dot. This is
 * considered to be hard motion; it really isn't if the original value of dot
 * is the same as the new value of dot. Normally bound to "M-<".
 */
int gotobob(int f, int n)
{
	curwp->w_dotp = lforw(curbp->b_linep);
	curwp->w_doto = 0;
	curwp->w_flag |= WFHARD;
	return TRUE;
}

/*
 * Move to the end of the buffer. Dot is always put at the end of the file
 * (ZJ). The standard screen code does most of the hard parts of update.
 * Bound to "M->".
 */
int gotoeob(int f, int n)
{
	curwp->w_dotp = curbp->b_linep;
	curwp->w_doto = 0;
	curwp->w_flag |= WFHARD;
	return TRUE;
}

/*
 * Move forward by full lines. If the number of lines to move is less than
 * zero, call the backward line function to actually do it. The last command
 * controls how the goal column is set. Bound to "C-N". No errors are
 * possible.
 */
int forwline(int f, int n)
{
	struct line *dlp;

	if (n < 0)
		return backline(f, -n);

	/* if we are on the last line as we start....fail the command */
	if (curwp->w_dotp == curbp->b_linep)
		return FALSE;

	/* if the last command was not note a line move,
	   reset the goal column */
	if ((lastflag & CFCPCN) == 0)
		curgoal = getccol(FALSE);

	/* flag this command as a line move */
	thisflag |= CFCPCN;

	/* and move the point down */
	dlp = curwp->w_dotp;
	while (n-- && dlp != curbp->b_linep)
		dlp = lforw(dlp);

	/* reseting the current position */
	curwp->w_dotp = dlp;
	curwp->w_doto = getgoal(dlp);
	curwp->w_flag |= WFMOVE;
	return TRUE;
}

/*
 * This function is like "forwline", but goes backwards. The scheme is exactly
 * the same. Check for arguments that are less than zero and call your
 * alternate. Figure out the new line and call "movedot" to perform the
 * motion. No errors are possible. Bound to "C-P".
 */
int backline(int f, int n)
{
	struct line *dlp;

	if (n < 0)
		return forwline(f, -n);

	/* if we are on the last line as we start....fail the command */
	if (lback(curwp->w_dotp) == curbp->b_linep)
		return FALSE;

	/* if the last command was not note a line move,
	   reset the goal column */
	if ((lastflag & CFCPCN) == 0)
		curgoal = getccol(FALSE);

	/* flag this command as a line move */
	thisflag |= CFCPCN;

	/* and move the point up */
	dlp = curwp->w_dotp;
	while (n-- && lback(dlp) != curbp->b_linep)
		dlp = lback(dlp);

	/* reseting the current position */
	curwp->w_dotp = dlp;
	curwp->w_doto = getgoal(dlp);
	curwp->w_flag |= WFMOVE;
	return TRUE;
}

#if	WORDPRO
static int is_new_para(void)
{
	int i, len;

	len = llength(curwp->w_dotp);

	for (i = 0; i < len; i++) {
		int c = lgetc(curwp->w_dotp, i);
		if (c == ' ' || c == TAB) {
#if PKCODE
			if (justflag)
				continue;
#endif
			return 1;
		}
		if (!isletter(c))
			return 1;
		return 0;
	}
	return 1;
}

/*
 * go back to the beginning of the current paragraph
 * here we look for a <NL><NL> or <NL><TAB> or <NL><SPACE>
 * combination to delimit the beginning of a paragraph
 *
 * int f, n;		default Flag & Numeric argument
 */
int gotobop(int f, int n)
{
	int suc;  /* success of last backchar */

	if (n < 0) /* the other way... */
		return gotoeop(f, -n);

	while (n-- > 0) {  /* for each one asked for */

		/* first scan back until we are in a word */
		suc = backchar(FALSE, 1);
		while (!inword() && suc)
			suc = backchar(FALSE, 1);
		curwp->w_doto = 0;	/* and go to the B-O-Line */

		/* and scan back until we hit a <NL><NL> or <NL><TAB>
		   or a <NL><SPACE>                                     */
		while (lback(curwp->w_dotp) != curbp->b_linep) {
			if (is_new_para())
				break;
			curwp->w_dotp = lback(curwp->w_dotp);
		}

		/* and then forward until we are in a word */
		suc = forwchar(FALSE, 1);
		while (suc && !inword())
			suc = forwchar(FALSE, 1);
	}
	curwp->w_flag |= WFMOVE;	/* force screen update */
	return TRUE;
}

/*
 * Go forword to the end of the current paragraph
 * here we look for a <NL><NL> or <NL><TAB> or <NL><SPACE>
 * combination to delimit the beginning of a paragraph
 *
 * int f, n;		default Flag & Numeric argument
 */
int gotoeop(int f, int n)
{
	int suc;  /* success of last backchar */

	if (n < 0)  /* the other way... */
		return gotobop(f, -n);

	while (n-- > 0) {  /* for each one asked for */
		/* first scan forward until we are in a word */
		suc = forwchar(FALSE, 1);
		while (!inword() && suc)
			suc = forwchar(FALSE, 1);
		curwp->w_doto = 0;	/* and go to the B-O-Line */
		if (suc)	/* of next line if not at EOF */
			curwp->w_dotp = lforw(curwp->w_dotp);

		/* and scan forword until we hit a <NL><NL> or <NL><TAB>
		   or a <NL><SPACE>                                     */
		while (curwp->w_dotp != curbp->b_linep) {
			if (is_new_para())
				break;
			curwp->w_dotp = lforw(curwp->w_dotp);
		}

		/* and then backward until we are in a word */
		suc = backchar(FALSE, 1);
		while (suc && !inword()) {
			suc = backchar(FALSE, 1);
		}
		curwp->w_doto = llength(curwp->w_dotp);	/* and to the EOL */
	}
	curwp->w_flag |= WFMOVE;  /* force screen update */
	return TRUE;
}
#endif

/*
 * Scroll forward by a specified number of lines, or by a full page if no
 * argument. Bound to "C-V". The "2" in the arithmetic on the window size is
 * the overlap; this value is the default overlap value in ITS EMACS. Because
 * this zaps the top line in the display window, we have to do a hard update.
 */
int forwpage(int f, int n)
{
	struct line *lp;

	if (f == FALSE) {
#if SCROLLCODE
		if (term.t_scroll != NULL)
			if (overlap == 0)
				n = curwp->w_ntrows / 3 * 2;
			else
				n = curwp->w_ntrows - overlap;
		else
#endif
			n = curwp->w_ntrows - 2;  /* Default scroll. */
		if (n <= 0)	/* Forget the overlap. */
			n = 1;	/* If tiny window. */
	} else if (n < 0)
		return backpage(f, -n);
#if     CVMVAS
	else			/* Convert from pages. */
		n *= curwp->w_ntrows;	/* To lines. */
#endif
	lp = curwp->w_linep;
	while (n-- && lp != curbp->b_linep)
		lp = lforw(lp);
	curwp->w_linep = lp;
	curwp->w_dotp = lp;
	curwp->w_doto = 0;
#if SCROLLCODE
	curwp->w_flag |= WFHARD | WFKILLS;
#else
	curwp->w_flag |= WFHARD;
#endif
	return TRUE;
}

/*
 * This command is like "forwpage", but it goes backwards. The "2", like
 * above, is the overlap between the two windows. The value is from the ITS
 * EMACS manual. Bound to "M-V". We do a hard update for exactly the same
 * reason.
 */
int backpage(int f, int n)
{
	struct line *lp;

	if (f == FALSE) {
#if SCROLLCODE
		if (term.t_scroll != NULL)
			if (overlap == 0)
				n = curwp->w_ntrows / 3 * 2;
			else
				n = curwp->w_ntrows - overlap;
		else
#endif
			n = curwp->w_ntrows - 2; /* Default scroll. */
		if (n <= 0)	/* Don't blow up if the. */
			n = 1;	/* Window is tiny. */
	} else if (n < 0)
		return forwpage(f, -n);
#if     CVMVAS
	else  /* Convert from pages. */
		n *= curwp->w_ntrows;  /* To lines. */
#endif
	lp = curwp->w_linep;
	while (n-- && lback(lp) != curbp->b_linep)
		lp = lback(lp);
	curwp->w_linep = lp;
	curwp->w_dotp = lp;
	curwp->w_doto = 0;
#if SCROLLCODE
	curwp->w_flag |= WFHARD | WFINS;
#else
	curwp->w_flag |= WFHARD;
#endif
	return TRUE;
}

/*
 * Set the mark in the current window to the value of "." in the window. No
 * errors are possible. Bound to "M-.".
 */
int setmark(int f, int n)
{
	curwp->w_markp = curwp->w_dotp;
	curwp->w_marko = curwp->w_doto;
	mlwrite("(Mark set)");
	return TRUE;
}

/*
 * Swap the values of "." and "mark" in the current window. This is pretty
 * easy, bacause all of the hard work gets done by the standard routine
 * that moves the mark about. The only possible error is "no mark". Bound to
 * "C-X C-X".
 */
int swapmark(int f, int n)
{
	struct line *odotp;
	int odoto;

	if (curwp->w_markp == NULL) {
		mlwrite("No mark in this window");
		return FALSE;
	}
	odotp = curwp->w_dotp;
	odoto = curwp->w_doto;
	curwp->w_dotp = curwp->w_markp;
	curwp->w_doto = curwp->w_marko;
	curwp->w_markp = odotp;
	curwp->w_marko = odoto;
	curwp->w_flag |= WFMOVE;
	return TRUE;
}


/* ----- bind.c ----- */
/*	bind.c
 *
 *	This file is for functions having to do with key bindings,
 *	descriptions, help commands and startup file.
 *
 *	Written 11-feb-86 by Daniel Lawrence
 *	Modified by Petri Kutvonen
 */
/* system header already included */
/* #include "estruct.h" - amalgamated */
/* #include "edef.h" - amalgamated */
/* #include "efunc.h" - amalgamated */
/* #include "epath.h" - amalgamated */
/* #include "line.h" - amalgamated */
/* #include "util.h" - amalgamated */

int help(int f, int n)
{				/* give me some help!!!!
				   bring up a fake buffer and read the help file
				   into it with view mode                 */
	struct window *wp;	/* scaning pointer to windows */
	struct buffer *bp;	/* buffer pointer to help */
	char *fname = NULL;	/* ptr to file returned by flook() */

	/* first check if we are already here */
	bp = bfind("emacs.hlp", FALSE, BFINVS);

	if (bp == NULL) {
		fname = flook(pathname[1], FALSE);
		if (fname == NULL) {
			mlwrite("(Help file is not online)");
			return FALSE;
		}
	}

	/* split the current window to make room for the help stuff */
	if (splitwind(FALSE, 1) == FALSE)
		return FALSE;

	if (bp == NULL) {
		/* and read the stuff in */
		if (getfile(fname, FALSE) == FALSE)
			return FALSE;
	} else
		swbuffer(bp);

	/* make this window in VIEW mode, update all mode lines */
	curwp->w_bufp->b_mode |= MDVIEW;
	curwp->w_bufp->b_flag |= BFINVS;
	wp = wheadp;
	while (wp != NULL) {
		wp->w_flag |= WFMODE;
		wp = wp->w_wndp;
	}
	return TRUE;
}

int deskey(int f, int n)
{				/* describe the command for a certain key */
	int c;		/* key to describe */
	char *ptr;	/* string pointer to scan output strings */
	char outseq[NSTRING];	/* output buffer for command sequence */

	/* prompt the user to type us a key to describe */
	mlwrite(": describe-key ");

	/* get the command sequence to describe
	   change it to something we can print as well */
	cmdstr(c = getckey(FALSE), &outseq[0]);

	/* and dump it out */
	ostring(outseq);
	ostring(" ");

	/* find the right ->function */
	if ((ptr = getfname(getbind(c))) == NULL)
		ptr = "Not Bound";

	/* output the command sequence */
	ostring(ptr);
	return TRUE;
}

/*
 * bindtokey:
 *	add a new key to the key binding table
 *
 * int f, n;		command arguments [IGNORED]
 */
int bindtokey(int f, int n)
{
	unsigned int c;	     /* command key to bind */
	fn_t kfunc;	     /* ptr to the requested function to bind to */
	struct key_tab *ktp; /* pointer into the command table */
	int found;	     /* matched command flag */
	char outseq[80];     /* output buffer for keystroke sequence */

	/* prompt the user to type in a key to bind */
	mlwrite(": bind-to-key ");

	/* get the function name to bind it to */
	kfunc = getname();
	if (kfunc == NULL) {
		mlwrite("(No such function)");
		return FALSE;
	}
	ostring(" ");

	/* get the command sequence to bind */
	c = getckey((kfunc == metafn) || (kfunc == cex) ||
		    (kfunc == unarg) || (kfunc == ctrlg));

	/* change it to something we can print as well */
	cmdstr(c, &outseq[0]);

	/* and dump it out */
	ostring(outseq);

	/* if the function is a prefix key */
	if (kfunc == metafn || kfunc == cex ||
	    kfunc == unarg || kfunc == ctrlg) {

		/* search for an existing binding for the prefix key */
		ktp = &keytab[0];
		found = FALSE;
		while (ktp->k_fp != NULL) {
			if (ktp->k_fp == kfunc)
				unbindchar(ktp->k_code);
			++ktp;
		}

		/* reset the appropriate global prefix variable */
		if (kfunc == metafn)
			metac = c;
		if (kfunc == cex)
			ctlxc = c;
		if (kfunc == unarg)
			reptc = c;
		if (kfunc == ctrlg)
			abortc = c;
	}

	/* search the table to see if it exists */
	ktp = &keytab[0];
	found = FALSE;
	while (ktp->k_fp != NULL) {
		if (ktp->k_code == c) {
			found = TRUE;
			break;
		}
		++ktp;
	}

	if (found) {		/* it exists, just change it then */
		ktp->k_fp = kfunc;
	} else {		/* otherwise we need to add it to the end */
		/* if we run out of binding room, bitch */
		if (ktp >= &keytab[NBINDS]) {
			mlwrite("Binding table FULL!");
			return FALSE;
		}

		ktp->k_code = c;	/* add keycode */
		ktp->k_fp = kfunc;	/* and the function pointer */
		++ktp;		/* and make sure the next is null */
		ktp->k_code = 0;
		ktp->k_fp = NULL;
	}
	return TRUE;
}

/*
 * unbindkey:
 *	delete a key from the key binding table
 *
 * int f, n;		command arguments [IGNORED]
 */
int unbindkey(int f, int n)
{
	int c;		/* command key to unbind */
	char outseq[80];	/* output buffer for keystroke sequence */

	/* prompt the user to type in a key to unbind */
	mlwrite(": unbind-key ");

	/* get the command sequence to unbind */
	c = getckey(FALSE);	/* get a command sequence */

	/* change it to something we can print as well */
	cmdstr(c, &outseq[0]);

	/* and dump it out */
	ostring(outseq);

	/* if it isn't bound, bitch */
	if (unbindchar(c) == FALSE) {
		mlwrite("(Key not bound)");
		return FALSE;
	}
	return TRUE;
}


/*
 * unbindchar()
 *
 * int c;		command key to unbind
 */
int unbindchar(int c)
{
	struct key_tab *ktp;   /* pointer into the command table */
	struct key_tab *sktp;  /* saved pointer into the command table */
	int found;             /* matched command flag */

	/* search the table to see if the key exists */
	ktp = &keytab[0];
	found = FALSE;
	while (ktp->k_fp != NULL) {
		if (ktp->k_code == c) {
			found = TRUE;
			break;
		}
		++ktp;
	}

	/* if it isn't bound, bitch */
	if (!found)
		return FALSE;

	/* save the pointer and scan to the end of the table */
	sktp = ktp;
	while (ktp->k_fp != NULL)
		++ktp;
	--ktp;			/* backup to the last legit entry */

	/* copy the last entry to the current one */
	sktp->k_code = ktp->k_code;
	sktp->k_fp = ktp->k_fp;

	/* null out the last one */
	ktp->k_code = 0;
	ktp->k_fp = NULL;
	return TRUE;
}

/* describe bindings
 * bring up a fake buffer and list the key bindings
 * into it with view mode
 */
int desbind(int f, int n)
#if	APROP
{
	buildlist(TRUE, "");
	return TRUE;
}

int apro(int f, int n)
{				/* Apropos (List functions that match a substring) */
	char mstring[NSTRING];	/* string to match cmd names to */
	int status;		/* status return */

	status = mlreply("Apropos string: ", mstring, NSTRING - 1);
	if (status != TRUE)
		return status;

	return buildlist(FALSE, mstring);
}

/*
 * build a binding list (limited or full)
 *
 * int type;		true = full list,   false = partial list
 * char *mstring;	match string if a partial list
 */
int buildlist(int type, char *mstring)
#endif
{
	struct window *wp;         /* scanning pointer to windows */
	struct key_tab *ktp;  /* pointer into the command table */
	struct name_bind *nptr;          /* pointer into the name binding table */
	struct buffer *bp;    /* buffer to put binding list into */
	int cpos;             /* current position to use in outseq */
	char outseq[80];      /* output buffer for keystroke sequence */

	/* split the current window to make room for the binding list */
	if (splitwind(FALSE, 1) == FALSE)
		return FALSE;

	/* and get a buffer for it */
	bp = bfind("*Binding list*", TRUE, 0);
	if (bp == NULL || bclear(bp) == FALSE) {
		mlwrite("Can not display binding list");
		return FALSE;
	}

	/* let us know this is in progress */
	mlwrite("(Building binding list)");

	/* disconect the current buffer */
	if (--curbp->b_nwnd == 0) {	/* Last use.            */
		curbp->b_dotp = curwp->w_dotp;
		curbp->b_doto = curwp->w_doto;
		curbp->b_markp = curwp->w_markp;
		curbp->b_marko = curwp->w_marko;
	}

	/* connect the current window to this buffer */
	curbp = bp;		/* make this buffer current in current window */
	bp->b_mode = 0;		/* no modes active in binding list */
	bp->b_nwnd++;		/* mark us as more in use */
	wp = curwp;
	wp->w_bufp = bp;
	wp->w_linep = bp->b_linep;
	wp->w_flag = WFHARD | WFFORCE;
	wp->w_dotp = bp->b_dotp;
	wp->w_doto = bp->b_doto;
	wp->w_markp = NULL;
	wp->w_marko = 0;

	/* build the contents of this window, inserting it line by line */
	nptr = &names[0];
	while (nptr->n_func != NULL) {

		/* add in the command name */
		strcpy(outseq, nptr->n_name);
		cpos = strlen(outseq);

#if	APROP
		/* if we are executing an apropos command..... */
		if (type == FALSE &&
		    /* and current string doesn't include the search string */
		    strinc(outseq, mstring) == FALSE)
			goto fail;
#endif
		/* search down any keys bound to this */
		ktp = &keytab[0];
		while (ktp->k_fp != NULL) {
			if (ktp->k_fp == nptr->n_func) {
				/* padd out some spaces */
				while (cpos < 28)
					outseq[cpos++] = ' ';

				/* add in the command sequence */
				cmdstr(ktp->k_code, &outseq[cpos]);
				strcat(outseq, "\n");

				/* and add it as a line into the buffer */
				if (linstr(outseq) != TRUE)
					return FALSE;

				cpos = 0;	/* and clear the line */
			}
			++ktp;
		}

		/* if no key was bound, we need to dump it anyway */
		if (cpos > 0) {
			outseq[cpos++] = '\n';
			outseq[cpos] = 0;
			if (linstr(outseq) != TRUE)
				return FALSE;
		}

	      fail:		/* and on to the next name */
		++nptr;
	}

	curwp->w_bufp->b_mode |= MDVIEW;	/* put this buffer view mode */
	curbp->b_flag &= ~BFCHG;	/* don't flag this as a change */
	wp->w_dotp = lforw(bp->b_linep);	/* back to the beginning */
	wp->w_doto = 0;
	wp = wheadp;		/* and update ALL mode lines */
	while (wp != NULL) {
		wp->w_flag |= WFMODE;
		wp = wp->w_wndp;
	}
	mlwrite("");		/* clear the mode line */
	return TRUE;
}

#if	APROP

/*
 * does source include sub?
 *
 * char *source;	string to search in
 * char *sub;		substring to look for
 */
int strinc(char *source, char *sub)
{
	char *sp;		/* ptr into source */
	char *nxtsp;		/* next ptr into source */
	char *tp;		/* ptr into substring */

	/* for each character in the source string */
	sp = source;
	while (*sp) {
		tp = sub;
		nxtsp = sp;

		/* is the substring here? */
		while (*tp) {
			if (*nxtsp++ != *tp)
				break;
			else
				tp++;
		}

		/* yes, return a success */
		if (*tp == 0)
			return TRUE;

		/* no, onward */
		sp++;
	}
	return FALSE;
}
#endif

/*
 * get a command key sequence from the keyboard
 *
 * int mflag;		going for a meta sequence?
 */
unsigned int getckey(int mflag)
{
	unsigned int c;	/* character fetched */
	char tok[NSTRING];	/* command incoming */

	/* check to see if we are executing a command line */
	if (clexec) {
		macarg(tok);	/* get the next token */
		return stock(tok);
	}

	/* or the normal way */
	if (mflag)
		c = get1key();
	else
		c = getcmd();
	return c;
}

/*
 * execute the startup file
 *
 * char *sfname;	name of startup file (null if default)
 */
int startup(char *sfname)
{
	char *fname;		/* resulting file name to execute */

	/* look up the startup file */
	if (*sfname != 0)
		fname = flook(sfname, TRUE);
	else
		fname = flook(pathname[0], TRUE);

	/* if it isn't around, don't sweat it */
	if (fname == NULL)
		return TRUE;

	/* otherwise, execute the sucker */
	return dofile(fname);
}

/*
 * Look up the existance of a file along the normal or PATH
 * environment variable. Look first in the HOME directory if
 * asked and possible
 *
 * char *fname;		base file name to search for
 * int hflag;		Look in the HOME environment variable first?
 */
char *flook(char *fname, int hflag)
{
	char *home;	/* path to home directory */
	char *path;	/* environmental PATH variable */
	char *sp;	/* pointer into path spec */
	int i;		/* index */
	static char fspec[NSTRING];	/* full path spec to search */

#if	ENVFUNC

	if (hflag) {
		home = getenv("HOME");
		if (home != NULL) {
			/* build home dir file spec */
			strcpy(fspec, home);
			strcat(fspec, "/");
			strcat(fspec, fname);

			/* and try it out */
			if (ffropen(fspec) == FIOSUC) {
				ffclose();
				return fspec;
			}
		}
	}
#endif

	/* always try the current directory first */
	if (ffropen(fname) == FIOSUC) {
		ffclose();
		return fname;
	}
#if	ENVFUNC
	/* get the PATH variable */
	path = getenv("PATH");
	if (path != NULL)
		while (*path) {

			/* build next possible file spec */
			sp = fspec;
			while (*path && (*path != PATHCHR))
				*sp++ = *path++;

			/* add a terminating dir separator if we need it */
			if (sp != fspec)
				*sp++ = '/';
			*sp = 0;
			strcat(fspec, fname);

			/* and try it out */
			if (ffropen(fspec) == FIOSUC) {
				ffclose();
				return fspec;
			}

			if (*path == PATHCHR)
				++path;
		}
#endif

	/* look it up via the old table method */
	for (i = 2; i < ARRAY_SIZE(pathname); i++) {
		strcpy(fspec, pathname[i]);
		strcat(fspec, fname);

		/* and try it out */
		if (ffropen(fspec) == FIOSUC) {
			ffclose();
			return fspec;
		}
	}

	return NULL;		/* no such luck */
}

/*
 * change a key command to a string we can print out
 *
 * int c;		sequence to translate
 * char *seq;		destination string for sequence
 */
void cmdstr(int c, char *seq)
{
	char *ptr;		/* pointer into current position in sequence */

	ptr = seq;

	/* apply meta sequence if needed */
	if (c & META) {
		*ptr++ = 'M';
		*ptr++ = '-';
	}

	/* apply ^X sequence if needed */
	if (c & CTLX) {
		*ptr++ = '^';
		*ptr++ = 'X';
	}

	/* apply SPEC sequence if needed */
	if (c & SPEC) {
		*ptr++ = 'F';
		*ptr++ = 'N';
	}

	/* apply control sequence if needed */
	if (c & CONTROL) {
		*ptr++ = '^';
	}

	/* and output the final sequence */

	*ptr++ = c & 255;	/* strip the prefixes */

	*ptr = 0;		/* terminate the string */
}

/*
 * This function looks a key binding up in the binding table
 *
 * int c;		key to find what is bound to it
 */
int (*getbind(int c))(int, int)
{
	struct key_tab *ktp;

	ktp = &keytab[0];  /* Look in key table. */
	while (ktp->k_fp != NULL) {
		if (ktp->k_code == c)
			return ktp->k_fp;
		++ktp;
	}

	/* no such binding */
	return NULL;
}

/*
 * getfname:
 *	This function takes a ptr to function and gets the name
 *	associated with it.
 */
char *getfname(fn_t func)
{
	struct name_bind *nptr;	/* pointer into the name binding table */

	/* skim through the table, looking for a match */
	nptr = &names[0];
	while (nptr->n_func != NULL) {
		if (nptr->n_func == func)
			return nptr->n_name;
		++nptr;
	}
	return NULL;
}

/*
 * match fname to a function in the names table
 * and return any match or NULL if none
 *
 * char *fname;		name to attempt to match
 */
int (*fncmatch(char *fname)) (int, int)
{
	struct name_bind *ffp;	/* pointer to entry in name binding table */

	/* scan through the table, returning any match */
	ffp = &names[0];
	while (ffp->n_func != NULL) {
		if (strcmp(fname, ffp->n_name) == 0)
			return ffp->n_func;
		++ffp;
	}
	return NULL;
}

/*
 * stock:
 *	String key name TO Command Key
 *
 * char *keyname;	name of key to translate to Command key form
 */
unsigned int stock(char *keyname)
{
	unsigned int c;	/* key sequence to return */

	/* parse it up */
	c = 0;

	/* first, the META prefix */
	if (*keyname == 'M' && *(keyname + 1) == '-') {
		c = META;
		keyname += 2;
	}

	/* next the function prefix */
	if (*keyname == 'F' && *(keyname + 1) == 'N') {
		c |= SPEC;
		keyname += 2;
	}

	/* control-x as well... (but not with FN) */
	if (*keyname == '^' && *(keyname + 1) == 'X' && !(c & SPEC)) {
		c |= CTLX;
		keyname += 2;
	}

	/* a control char? */
	if (*keyname == '^' && *(keyname + 1) != 0) {
		c |= CONTROL;
		++keyname;
	}
	if (*keyname < 32) {
		c |= CONTROL;
		*keyname += 'A';
	}


	/* make sure we are not lower case (not with function keys) */
	if (*keyname >= 'a' && *keyname <= 'z' && !(c & SPEC))
		*keyname -= 32;

	/* the final sequence... */
	c |= *keyname;
	return c;
}

/*
 * string key name to binding name....
 *
 * char *skey;		name of keey to get binding for
 */
char *transbind(char *skey)
{
	char *bindname;

	bindname = getfname(getbind(stock(skey)));
	if (bindname == NULL)
		bindname = "ERROR";

	return bindname;
}


/* ----- buffer.c ----- */
/*	buffer.c
 *
 *	Buffer management.
 *	Some of the functions are internal,
 *	and some are actually attached to user
 *	keys. Like everyone else, they set hints
 *	for the display system
 *
 *	modified by Petri Kutvonen
 */
/* system header already included */
/* #include "estruct.h" - amalgamated */
/* #include "edef.h" - amalgamated */
/* #include "efunc.h" - amalgamated */
/* #include "line.h" - amalgamated */

/*
 * Attach a buffer to a window. The
 * values of dot and mark come from the buffer
 * if the use count is 0. Otherwise, they come
 * from some other window.
 */
int usebuffer(int f, int n)
{
	struct buffer *bp;
	int s;
	char bufn[NBUFN];

	if ((s = mlreply("Use buffer: ", bufn, NBUFN)) != TRUE)
		return s;
	if ((bp = bfind(bufn, TRUE, 0)) == NULL)
		return FALSE;
	return swbuffer(bp);
}

/*
 * switch to the next buffer in the buffer list
 *
 * int f, n;		default flag, numeric argument
 */
int nextbuffer(int f, int n)
{
	struct buffer *bp = NULL;  /* eligable buffer to switch to */
	struct buffer *bbp;        /* eligable buffer to switch to */

	/* make sure the arg is legit */
	if (f == FALSE)
		n = 1;
	if (n < 1)
		return FALSE;

	bbp = curbp;
	while (n-- > 0) {
		/* advance to the next buffer */
		bp = bbp->b_bufp;

		/* cycle through the buffers to find an eligable one */
		while (bp == NULL || bp->b_flag & BFINVS) {
			if (bp == NULL)
				bp = bheadp;
			else
				bp = bp->b_bufp;

			/* don't get caught in an infinite loop! */
			if (bp == bbp)
				return FALSE;

		}

		bbp = bp;
	}

	return swbuffer(bp);
}

/*
 * make buffer BP current
 */
int swbuffer(struct buffer *bp)
{
	struct window *wp;

	if (--curbp->b_nwnd == 0) {	/* Last use.            */
		curbp->b_dotp = curwp->w_dotp;
		curbp->b_doto = curwp->w_doto;
		curbp->b_markp = curwp->w_markp;
		curbp->b_marko = curwp->w_marko;
	}
	curbp = bp;		/* Switch.              */
	if (curbp->b_active != TRUE) {	/* buffer not active yet */
		/* read it in and activate it */
		readin(curbp->b_fname, TRUE);
		curbp->b_dotp = lforw(curbp->b_linep);
		curbp->b_doto = 0;
		curbp->b_active = TRUE;
		curbp->b_mode |= gmode;	/* P.K. */
	}
	curwp->w_bufp = bp;
	curwp->w_linep = bp->b_linep;	/* For macros, ignored. */
	curwp->w_flag |= WFMODE | WFFORCE | WFHARD;	/* Quite nasty.         */
	if (bp->b_nwnd++ == 0) {	/* First use.           */
		curwp->w_dotp = bp->b_dotp;
		curwp->w_doto = bp->b_doto;
		curwp->w_markp = bp->b_markp;
		curwp->w_marko = bp->b_marko;
		cknewwindow();
		return TRUE;
	}
	wp = wheadp;		/* Look for old.        */
	while (wp != NULL) {
		if (wp != curwp && wp->w_bufp == bp) {
			curwp->w_dotp = wp->w_dotp;
			curwp->w_doto = wp->w_doto;
			curwp->w_markp = wp->w_markp;
			curwp->w_marko = wp->w_marko;
			break;
		}
		wp = wp->w_wndp;
	}
	cknewwindow();
	return TRUE;
}

/*
 * Dispose of a buffer, by name.
 * Ask for the name. Look it up (don't get too
 * upset if it isn't there at all!). Get quite upset
 * if the buffer is being displayed. Clear the buffer (ask
 * if the buffer has been changed). Then free the header
 * line and the buffer header. Bound to "C-X K".
 */
int killbuffer(int f, int n)
{
	struct buffer *bp;
	int s;
	char bufn[NBUFN];

	if ((s = mlreply("Kill buffer: ", bufn, NBUFN)) != TRUE)
		return s;
	if ((bp = bfind(bufn, FALSE, 0)) == NULL)	/* Easy if unknown.     */
		return TRUE;
	if (bp->b_flag & BFINVS)	/* Deal with special buffers        */
		return TRUE;	/* by doing nothing.    */
	return zotbuf(bp);
}

/*
 * kill the buffer pointed to by bp
 */
int zotbuf(struct buffer *bp)
{
	struct buffer *bp1;
	struct buffer *bp2;
	int s;

	if (bp->b_nwnd != 0) {	/* Error if on screen.  */
		mlwrite("Buffer is being displayed");
		return FALSE;
	}
	if ((s = bclear(bp)) != TRUE)	/* Blow text away.      */
		return s;
	free((char *) bp->b_linep);	/* Release header line. */
	bp1 = NULL;		/* Find the header.     */
	bp2 = bheadp;
	while (bp2 != bp) {
		bp1 = bp2;
		bp2 = bp2->b_bufp;
	}
	bp2 = bp2->b_bufp;	/* Next one in chain.   */
	if (bp1 == NULL)	/* Unlink it.           */
		bheadp = bp2;
	else
		bp1->b_bufp = bp2;
	free((char *) bp);	/* Release buffer block */
	return TRUE;
}

/*
 * Rename the current buffer
 *
 * int f, n;		default Flag & Numeric arg
 */
int namebuffer(int f, int n)
{
	struct buffer *bp;	/* pointer to scan through all buffers */
	char bufn[NBUFN];	/* buffer to hold buffer name */

	/* prompt for and get the new buffer name */
      ask:if (mlreply("Change buffer name to: ", bufn, NBUFN) !=
	    TRUE)
		return FALSE;

	/* and check for duplicates */
	bp = bheadp;
	while (bp != NULL) {
		if (bp != curbp) {
			/* if the names the same */
			if (strcmp(bufn, bp->b_bname) == 0)
				goto ask;	/* try again */
		}
		bp = bp->b_bufp;	/* onward */
	}

	strcpy(curbp->b_bname, bufn);	/* copy buffer name to structure */
	curwp->w_flag |= WFMODE;	/* make mode line replot */
	mlerase();
	return TRUE;
}

/*
 * List all of the active buffers.  First update the special
 * buffer that holds the list.  Next make sure at least 1
 * window is displaying the buffer list, splitting the screen
 * if this is what it takes.  Lastly, repaint all of the
 * windows that are displaying the list.  Bound to "C-X C-B". 
 *
 * A numeric argument forces it to list invisible buffers as
 * well.
 */
int listbuffers(int f, int n)
{
	struct window *wp;
	struct buffer *bp;
	int s;

	if ((s = makelist(f)) != TRUE)
		return s;
	if (blistp->b_nwnd == 0) {	/* Not on screen yet.   */
		if ((wp = wpopup()) == NULL)
			return FALSE;
		bp = wp->w_bufp;
		if (--bp->b_nwnd == 0) {
			bp->b_dotp = wp->w_dotp;
			bp->b_doto = wp->w_doto;
			bp->b_markp = wp->w_markp;
			bp->b_marko = wp->w_marko;
		}
		wp->w_bufp = blistp;
		++blistp->b_nwnd;
	}
	wp = wheadp;
	while (wp != NULL) {
		if (wp->w_bufp == blistp) {
			wp->w_linep = lforw(blistp->b_linep);
			wp->w_dotp = lforw(blistp->b_linep);
			wp->w_doto = 0;
			wp->w_markp = NULL;
			wp->w_marko = 0;
			wp->w_flag |= WFMODE | WFHARD;
		}
		wp = wp->w_wndp;
	}
	return TRUE;
}

/*
 * This routine rebuilds the
 * text in the special secret buffer
 * that holds the buffer list. It is called
 * by the list buffers command. Return TRUE
 * if everything works. Return FALSE if there
 * is an error (if there is no memory). Iflag
 * indicates wether to list hidden buffers.
 *
 * int iflag;		list hidden buffer flag
 */
#define MAXLINE	MAXCOL
int makelist(int iflag)
{
	char *cp1;
	char *cp2;
	int c;
	struct buffer *bp;
	struct line *lp;
	int s;
	int i;
	long nbytes;		/* # of bytes in current buffer */
	char b[7 + 1];
	char line[MAXLINE];

	blistp->b_flag &= ~BFCHG;	/* Don't complain!      */
	if ((s = bclear(blistp)) != TRUE)	/* Blow old text away   */
		return s;
	strcpy(blistp->b_fname, "");
	if (addline("ACT MODES        Size Buffer        File") == FALSE
	    || addline("--- -----        ---- ------        ----") ==
	    FALSE)
		return FALSE;
	bp = bheadp;		/* For all buffers      */

	/* build line to report global mode settings */
	cp1 = &line[0];
	*cp1++ = ' ';
	*cp1++ = ' ';
	*cp1++ = ' ';
	*cp1++ = ' ';

	/* output the mode codes */
	for (i = 0; i < NUMMODES; i++)
		if (gmode & (1 << i))
			*cp1++ = modecode[i];
		else
			*cp1++ = '.';
	strcpy(cp1, "         Global Modes");
	if (addline(line) == FALSE)
		return FALSE;

	/* output the list of buffers */
	while (bp != NULL) {
		/* skip invisable buffers if iflag is false */
		if (((bp->b_flag & BFINVS) != 0) && (iflag != TRUE)) {
			bp = bp->b_bufp;
			continue;
		}
		cp1 = &line[0];	/* Start at left edge   */

		/* output status of ACTIVE flag (has the file been read in? */
		if (bp->b_active == TRUE)	/* "@" if activated       */
			*cp1++ = '@';
		else
			*cp1++ = ' ';

		/* output status of changed flag */
		if ((bp->b_flag & BFCHG) != 0)	/* "*" if changed       */
			*cp1++ = '*';
		else
			*cp1++ = ' ';

		/* report if the file is truncated */
		if ((bp->b_flag & BFTRUNC) != 0)
			*cp1++ = '#';
		else
			*cp1++ = ' ';

		*cp1++ = ' ';	/* space */

		/* output the mode codes */
		for (i = 0; i < NUMMODES; i++) {
			if (bp->b_mode & (1 << i))
				*cp1++ = modecode[i];
			else
				*cp1++ = '.';
		}
		*cp1++ = ' ';	/* Gap.                 */
		nbytes = 0L;	/* Count bytes in buf.  */
		lp = lforw(bp->b_linep);
		while (lp != bp->b_linep) {
			nbytes += (long) llength(lp) + 1L;
			lp = lforw(lp);
		}
		ltoa(b, 7, nbytes);	/* 6 digit buffer size. */
		cp2 = &b[0];
		while ((c = *cp2++) != 0)
			*cp1++ = c;
		*cp1++ = ' ';	/* Gap.                 */
		cp2 = &bp->b_bname[0];	/* Buffer name          */
		while ((c = *cp2++) != 0)
			*cp1++ = c;
		cp2 = &bp->b_fname[0];	/* File name            */
		if (*cp2 != 0) {
			while (cp1 < &line[3 + 1 + 5 + 1 + 6 + 4 + NBUFN])
				*cp1++ = ' ';
			while ((c = *cp2++) != 0) {
				if (cp1 < &line[MAXLINE - 1])
					*cp1++ = c;
			}
		}
		*cp1 = 0;	/* Add to the buffer.   */
		if (addline(line) == FALSE)
			return FALSE;
		bp = bp->b_bufp;
	}
	return TRUE;		/* All done             */
}

void ltoa(char *buf, int width, long num)
{
	buf[width] = 0;		/* End of string.       */
	while (num >= 10) {	/* Conditional digits.  */
		buf[--width] = (int) (num % 10L) + '0';
		num /= 10L;
	}
	buf[--width] = (int) num + '0';	/* Always 1 digit.      */
	while (width != 0)	/* Pad with blanks.     */
		buf[--width] = ' ';
}

/*
 * The argument "text" points to
 * a string. Append this line to the
 * buffer list buffer. Handcraft the EOL
 * on the end. Return TRUE if it worked and
 * FALSE if you ran out of room.
 */
int addline(char *text)
{
	struct line *lp;
	int i;
	int ntext;

	ntext = strlen(text);
	if ((lp = lalloc(ntext)) == NULL)
		return FALSE;
	for (i = 0; i < ntext; ++i)
		lputc(lp, i, text[i]);
	blistp->b_linep->l_bp->l_fp = lp;	/* Hook onto the end    */
	lp->l_bp = blistp->b_linep->l_bp;
	blistp->b_linep->l_bp = lp;
	lp->l_fp = blistp->b_linep;
	if (blistp->b_dotp == blistp->b_linep)	/* If "." is at the end */
		blistp->b_dotp = lp;	/* move it to new line  */
	return TRUE;
}

/*
 * Look through the list of
 * buffers. Return TRUE if there
 * are any changed buffers. Buffers
 * that hold magic internal stuff are
 * not considered; who cares if the
 * list of buffer names is hacked.
 * Return FALSE if no buffers
 * have been changed.
 */
int anycb(void)
{
	struct buffer *bp;

	bp = bheadp;
	while (bp != NULL) {
		if ((bp->b_flag & BFINVS) == 0
		    && (bp->b_flag & BFCHG) != 0)
			return TRUE;
		bp = bp->b_bufp;
	}
	return FALSE;
}

/*
 * Find a buffer, by name. Return a pointer
 * to the buffer structure associated with it.
 * If the buffer is not found
 * and the "cflag" is TRUE, create it. The "bflag" is
 * the settings for the flags in in buffer.
 */
struct buffer *bfind(char *bname, int cflag, int bflag)
{
	struct buffer *bp;
	struct buffer *sb;	/* buffer to insert after */
	struct line *lp;

	bp = bheadp;
	while (bp != NULL) {
		if (strcmp(bname, bp->b_bname) == 0)
			return bp;
		bp = bp->b_bufp;
	}
	if (cflag != FALSE) {
		if ((bp = (struct buffer *)malloc(sizeof(struct buffer))) == NULL)
			return NULL;
		if ((lp = lalloc(0)) == NULL) {
			free((char *) bp);
			return NULL;
		}
		/* find the place in the list to insert this buffer */
		if (bheadp == NULL || strcmp(bheadp->b_bname, bname) > 0) {
			/* insert at the beginning */
			bp->b_bufp = bheadp;
			bheadp = bp;
		} else {
			sb = bheadp;
			while (sb->b_bufp != NULL) {
				if (strcmp(sb->b_bufp->b_bname, bname) > 0)
					break;
				sb = sb->b_bufp;
			}

			/* and insert it */
			bp->b_bufp = sb->b_bufp;
			sb->b_bufp = bp;
		}

		/* and set up the other buffer fields */
		bp->b_active = TRUE;
		bp->b_dotp = lp;
		bp->b_doto = 0;
		bp->b_markp = NULL;
		bp->b_marko = 0;
		bp->b_flag = bflag;
		bp->b_mode = gmode;
		bp->b_nwnd = 0;
		bp->b_linep = lp;
		strcpy(bp->b_fname, "");
		strcpy(bp->b_bname, bname);
#if	CRYPT
		bp->b_key[0] = 0;
#endif
		lp->l_fp = lp;
		lp->l_bp = lp;
	}
	return bp;
}

/*
 * This routine blows away all of the text
 * in a buffer. If the buffer is marked as changed
 * then we ask if it is ok to blow it away; this is
 * to save the user the grief of losing text. The
 * window chain is nearly always wrong if this gets
 * called; the caller must arrange for the updates
 * that are required. Return TRUE if everything
 * looks good.
 */
int bclear(struct buffer *bp)
{
	struct line *lp;
	int s;

	if ((bp->b_flag & BFINVS) == 0	/* Not scratch buffer.  */
	    && (bp->b_flag & BFCHG) != 0	/* Something changed    */
	    && (s = mlyesno("Discard changes")) != TRUE)
		return s;
	bp->b_flag &= ~BFCHG;	/* Not changed          */
	while ((lp = lforw(bp->b_linep)) != bp->b_linep)
		lfree(lp);
	bp->b_dotp = bp->b_linep;	/* Fix "."              */
	bp->b_doto = 0;
	bp->b_markp = NULL;	/* Invalidate "mark"    */
	bp->b_marko = 0;
	return TRUE;
}

/*
 * unmark the current buffers change flag
 *
 * int f, n;		unused command arguments
 */
int unmark(int f, int n)
{
	curbp->b_flag &= ~BFCHG;
	curwp->w_flag |= WFMODE;
	return TRUE;
}


/* ----- crypt.c ----- */
/*	CRYPT.C
 *
 *	Encryption routines
 *
 *	written by Dana Hoggatt and Daniel Lawrence
 */
/* system header already included */
/* #include "estruct.h" - amalgamated */
/* #include "edef.h" - amalgamated */
/* #include "efunc.h" - amalgamated */

#if	CRYPT

static int mod95(int);

/*
 * reset encryption key of current buffer
 *
 * int f;		default flag
 * int n;		numeric argument
 */
int set_encryption_key(int f, int n)
{
	int status;	/* return status */
	int odisinp;		/* original vlaue of disinp */
	char key[NPAT];		/* new encryption string */

	/* turn command input echo off */
	odisinp = disinp;
	disinp = FALSE;

	/* get the string to use as an encrytion string */
	status = mlreply("Encryption String: ", key, NPAT - 1);
	disinp = odisinp;
	if (status != TRUE)
		return status;

	/* and encrypt it */
	myencrypt((char *) NULL, 0);
	myencrypt(key, strlen(key));

	/* and save it off */
	strcpy(curbp->b_key, key);
	mlwrite(" ");		/* clear it off the bottom line */
	return TRUE;
}

/**********
 *
 *	myencrypt - in place encryption/decryption of a buffer
 *
 *	(C) Copyright 1986, Dana L. Hoggatt
 *	1216, Beck Lane, Lafayette, IN
 *
 *	When consulting directly with the author of this routine, 
 *	please refer to this routine as the "DLH-POLY-86-B CIPHER".  
 *
 *	This routine was written for Dan Lawrence, for use in V3.8 of
 *	MicroEMACS, a public domain text/program editor.  
 *
 *	I kept the following goals in mind when preparing this function:
 *
 *	    1.	All printable characters were to be encrypted back
 *		into the printable range, control characters and
 *		high-bit characters were to remain unaffected.  this
 *		way, encrypted would still be just as cheap to 
 *		transmit down a 7-bit data path as they were before.
 *
 *	    2.	The encryption had to be portable.  The encrypted 
 *		file from one computer should be able to be decrypted 
 *		on another computer.
 *
 *	    3.	The encryption had to be inexpensive, both in terms
 *		of speed and space.
 *
 *	    4.	The system needed to be secure against all but the
 *		most determined of attackers.
 *
 *	For encryption of a block of data, one calls myencrypt passing 
 *	a pointer to the data block and its length. The data block is 
 *	encrypted in place, that is, the encrypted output overwrites 
 *	the input.  Decryption is totally isomorphic, and is performed 
 *	in the same manner by the same routine.  
 *
 *	Before using this routine for encrypting data, you are expected 
 *	to specify an encryption key.  This key is an arbitrary string,
 *	to be supplied by the user.  To set the key takes two calls to 
 *	myencrypt().  First, you call 
 *
 *		myencrypt(NULL, vector)
 *
 *	This resets all internal control information.  Typically (and 
 *	specifically in the case on MICRO-emacs) you would use a "vector" 
 *	of 0.  Other values can be used to customize your editor to be 
 *	"incompatable" with the normally distributed version.  For 
 *	this purpose, the best results will be obtained by avoiding
 *	multiples of 95.
 *
 *	Then, you "encrypt" your password by calling 
 *
 *		myencrypt(pass, strlen(pass))
 *
 *	where "pass" is your password string.  Myencrypt() will destroy 
 *	the original copy of the password (it becomes encrypted), 
 *	which is good.  You do not want someone on a multiuser system 
 *	to peruse your memory space and bump into your password.  
 *	Still, it is a better idea to erase the password buffer to 
 *	defeat memory perusal by a more technical snooper.  
 *
 *	For the interest of cryptologists, at the heart of this 
 *	function is a Beaufort Cipher.  The cipher alphabet is the 
 *	range of printable characters (' ' to '~'), all "control" 
 *	and "high-bit" characters are left unaltered.
 *
 *	The key is a variant autokey, derived from a wieghted sum 
 *	of all the previous clear text and cipher text.  A counter 
 *	is used as salt to obiterate any simple cyclic behavior 
 *	from the clear text, and key feedback is used to assure 
 *	that the entire message is based on the original key, 
 *	preventing attacks on the last part of the message as if 
 *	it were a pure autokey system.
 *
 *	Overall security of encrypted data depends upon three 
 *	factors:  the fundamental cryptographic system must be 
 *	difficult to compromise; exhaustive searching of the key 
 *	space must be computationally expensive; keys and plaintext 
 *	must remain out of sight.  This system satisfies this set
 *	of conditions to within the degree desired for MicroEMACS.
 *
 *	Though direct methods of attack (against systems such as 
 *	this) do exist, they are not well known and will consume 
 *	considerable amounts of computing time.  An exhaustive
 *	search requires over a billion investigations, on average.
 *
 *	The choice, entry, storage, manipulation, alteration, 
 *	protection and security of the keys themselves are the 
 *	responsiblity of the user.  
 *
 *
 * char *bptr;		buffer of characters to be encrypted
 * unsigned len;	number of characters in the buffer
 *
 **********/

void myencrypt(char *bptr, unsigned len)
{
	int cc;	/* current character being considered */

	static long key = 0;	/* 29 bit encipherment key */
	static int salt = 0;	/* salt to spice up key with */

	if (!bptr) {		/* is there anything here to encrypt? */
		key = len;	/* set the new key */
		salt = len;	/* set the new salt */
		return;
	}
	while (len--) {		/* for every character in the buffer */

		cc = *bptr;	/* get a character out of the buffer */

		/* only encipher printable characters */
		if ((cc >= ' ') && (cc <= '~')) {

/**  If the upper bit (bit 29) is set, feed it back into the key.  This 
	assures us that the starting key affects the entire message.  **/

			key &= 0x1FFFFFFFL;	/* strip off overflow */
			if (key & 0x10000000L) {
				key ^= 0x0040A001L;	/* feedback */
			}

/**  Down-bias the character, perform a Beaufort encipherment, and 
	up-bias the character again.  We want key to be positive 
	so that the left shift here will be more portable and the 
	mod95() faster   **/

			cc = mod95((int) (key % 95) - (cc - ' ')) + ' ';

/**  the salt will spice up the key a little bit, helping to obscure 
	any patterns in the clear text, particularly when all the 
	characters (or long sequences of them) are the same.  We do 
	not want the salt to go negative, or it will affect the key 
	too radically.  It is always a good idea to chop off cyclics 
	to prime values.  **/

			if (++salt >= 20857) {	/* prime modulus */
				salt = 0;
			}

/**  our autokey (a special case of the running key) is being 
	generated by a wieghted checksum of clear text, cipher 
	text, and salt.   **/

			key = key + key + cc + *bptr + salt;
		}
		*bptr++ = cc;	/* put character back into buffer */
	}
	return;
}

static int mod95(int val)
{
	/*  The mathematical MOD does not match the computer MOD  */

	/*  Yes, what I do here may look strange, but it gets the
	   job done, and portably at that.  */

	while (val >= 9500)
		val -= 9500;
	while (val >= 950)
		val -= 950;
	while (val >= 95)
		val -= 95;
	while (val < 0)
		val += 95;
	return val;
}
#else
static void myennocrypt(void)
{
}
#endif


/* ----- display.c ----- */
/*	display.c
 *
 *      The functions in this file handle redisplay. There are two halves, the
 *      ones that update the virtual display screen, and the ones that make the
 *      physical display screen the same as the virtual display screen. These
 *      functions use hints that are left in the windows by the commands.
 *
 *	Modified by Petri Kutvonen
 */
/* system header already included */
/* system header already included */
/* system header already included */
/* system header already included */
/* #include "estruct.h" - amalgamated */
/* #include "edef.h" - amalgamated */
/* #include "efunc.h" - amalgamated */
/* #include "line.h" - amalgamated */
/* #include "version.h" - amalgamated */
/* #include "wrapper.h" - amalgamated */
/* #include "utf8.h" - amalgamated */

struct video {
	int v_flag;		/* Flags */
#if	COLOR
	int v_fcolor;		/* current forground color */
	int v_bcolor;		/* current background color */
	int v_rfcolor;		/* requested forground color */
	int v_rbcolor;		/* requested background color */
#endif
	unicode_t v_text[1];	/* Screen data. */
};

#define VFCHG   0x0001		/* Changed flag                 */
#define	VFEXT	0x0002		/* extended (beyond column 80)  */
#define	VFREV	0x0004		/* reverse video status         */
#define	VFREQ	0x0008		/* reverse video request        */
#define	VFCOL	0x0010		/* color change requested       */

static struct video **vscreen;		/* Virtual screen. */
#if	MEMMAP == 0 || SCROLLCODE
static struct video **pscreen;		/* Physical screen. */
#endif

static int displaying = TRUE;
#if UNIX
/* system header already included */
#endif
#ifdef SIGWINCH
/* system header already included */
/* for window size changes */
int chg_width, chg_height;
#endif

static int reframe(struct window *wp);
static void updone(struct window *wp);
static void updall(struct window *wp);
static int scrolls(int inserts);
static void scrscroll(int from, int to, int count);
static int texttest(int vrow, int prow);
static int endofline(unicode_t *s, int n);
static void updext(void);
static int updateline(int row, struct video *vp1, struct video *vp2);
static void modeline(struct window *wp);
static void mlputi(int i, int r);
static void mlputli(long l, int r);
static void mlputf(int s);
static int newscreensize(int h, int w);

#if RAINBOW
static void putline(int row, int col, char *buf);
#endif

/*
 * Initialize the data structures used by the display code. The edge vectors
 * used to access the screens are set up. The operating system's terminal I/O
 * channel is set up. All the other things get initialized at compile time.
 * The original window has "WFCHG" set, so that it will get completely
 * redrawn on the first call to "update".
 */
void vtinit(void)
{
	int i;
	struct video *vp;

	TTopen();		/* open the screen */
	TTkopen();		/* open the keyboard */
	TTrev(FALSE);
	vscreen = xmalloc(term.t_mrow * sizeof(struct video *));

#if	MEMMAP == 0 || SCROLLCODE
	pscreen = xmalloc(term.t_mrow * sizeof(struct video *));
#endif
	for (i = 0; i < term.t_mrow; ++i) {
		vp = xmalloc(sizeof(struct video) + term.t_mcol*4);
		vp->v_flag = 0;
#if	COLOR
		vp->v_rfcolor = 7;
		vp->v_rbcolor = 0;
#endif
		vscreen[i] = vp;
#if	MEMMAP == 0 || SCROLLCODE
		vp = xmalloc(sizeof(struct video) + term.t_mcol*4);
		vp->v_flag = 0;
		pscreen[i] = vp;
#endif
	}
}

#if	CLEAN
/* free up all the dynamically allocated video structures */

void vtfree(void)
{
	int i;
	for (i = 0; i < term.t_mrow; ++i) {
		free(vscreen[i]);
#if	MEMMAP == 0 || SCROLLCODE
		free(pscreen[i]);
#endif
	}
	free(vscreen);
#if	MEMMAP == 0 || SCROLLCODE
	free(pscreen);
#endif
}
#endif

/*
 * Clean up the virtual terminal system, in anticipation for a return to the
 * operating system. Move down to the last line and clear it out (the next
 * system prompt will be written in the line). Shut down the channel to the
 * terminal.
 */
void vttidy(void)
{
	mlerase();
	movecursor(term.t_nrow, 0);
	TTflush();
	TTclose();
	TTkclose();
#ifdef PKCODE
	write(1, "\r", 1);
#endif
}

/*
 * Set the virtual cursor to the specified row and column on the virtual
 * screen. There is no checking for nonsense values; this might be a good
 * idea during the early stages.
 */
void vtmove(int row, int col)
{
	vtrow = row;
	vtcol = col;
}

/*
 * Write a character to the virtual screen. The virtual row and
 * column are updated. If we are not yet on left edge, don't print
 * it yet. If the line is too long put a "$" in the last column.
 *
 * This routine only puts printing characters into the virtual
 * terminal buffers. Only column overflow is checked.
 */
static void vtputc(int c)
{
	struct video *vp;	/* ptr to line being updated */

	/* In case somebody passes us a signed char.. */
	if (c < 0) {
		c += 256;
		if (c < 0)
			return;
	}

	vp = vscreen[vtrow];

	if (vtcol >= term.t_ncol) {
		++vtcol;
		vp->v_text[term.t_ncol - 1] = '$';
		return;
	}

	if (c == '\t') {
		do {
			vtputc(' ');
		} while (((vtcol + taboff) & tabmask) != 0);
		return;
	}

	if (c < 0x20) {
		vtputc('^');
		vtputc(c ^ 0x40);
		return;
	}

	if (c == 0x7f) {
		vtputc('^');
		vtputc('?');
		return;
	}

	if (c >= 0x80 && c <= 0xA0) {
		static const char hex[] = "0123456789abcdef";
		vtputc('\\');
		vtputc(hex[c >> 4]);
		vtputc(hex[c & 15]);
		return;
	}
	
	if (vtcol >= 0)
		vp->v_text[vtcol] = c;
	++vtcol;
}

/*
 * Erase from the end of the software cursor to the end of the line on which
 * the software cursor is located.
 */
static void vteeol(void)
{
/*  struct video *vp;	*/
	unicode_t *vcp = vscreen[vtrow]->v_text;

/*  vp = vscreen[vtrow];	*/
	while (vtcol < term.t_ncol)
/*	vp->v_text[vtcol++] = ' ';	*/
		vcp[vtcol++] = ' ';
}

/*
 * upscreen:
 *	user routine to force a screen update
 *	always finishes complete update
 */
int upscreen(int f, int n)
{
	update(TRUE);
	return TRUE;
}

#if SCROLLCODE
static int scrflags;
#endif

/*
 * Make sure that the display is right. This is a three part process. First,
 * scan through all of the windows looking for dirty ones. Check the framing,
 * and refresh the screen. Second, make sure that "currow" and "curcol" are
 * correct for the current window. Third, make the virtual and physical
 * screens the same.
 *
 * int force;		force update past type ahead?
 */
int update(int force)
{
	struct window *wp;

#if	TYPEAH && ! PKCODE
	if (force == FALSE && typahead())
		return TRUE;
#endif
#if	VISMAC == 0
	if (force == FALSE && kbdmode == PLAY)
		return TRUE;
#endif

	displaying = TRUE;

#if SCROLLCODE

	/* first, propagate mode line changes to all instances of
	   a buffer displayed in more than one window */
	wp = wheadp;
	while (wp != NULL) {
		if (wp->w_flag & WFMODE) {
			if (wp->w_bufp->b_nwnd > 1) {
				/* make sure all previous windows have this */
				struct window *owp;
				owp = wheadp;
				while (owp != NULL) {
					if (owp->w_bufp == wp->w_bufp)
						owp->w_flag |= WFMODE;
					owp = owp->w_wndp;
				}
			}
		}
		wp = wp->w_wndp;
	}

#endif

	/* update any windows that need refreshing */
	wp = wheadp;
	while (wp != NULL) {
		if (wp->w_flag) {
			/* if the window has changed, service it */
			reframe(wp);	/* check the framing */
#if SCROLLCODE
			if (wp->w_flag & (WFKILLS | WFINS)) {
				scrflags |=
				    (wp->w_flag & (WFINS | WFKILLS));
				wp->w_flag &= ~(WFKILLS | WFINS);
			}
#endif
			if ((wp->w_flag & ~WFMODE) == WFEDIT)
				updone(wp);	/* update EDITed line */
			else if (wp->w_flag & ~WFMOVE)
				updall(wp);	/* update all lines */
#if SCROLLCODE
			if (scrflags || (wp->w_flag & WFMODE))
#else
			if (wp->w_flag & WFMODE)
#endif
				modeline(wp);	/* update modeline */
			wp->w_flag = 0;
			wp->w_force = 0;
		}
		/* on to the next window */
		wp = wp->w_wndp;
	}

	/* recalc the current hardware cursor location */
	updpos();

#if	MEMMAP && ! SCROLLCODE
	/* update the cursor and flush the buffers */
	movecursor(currow, curcol - lbound);
#endif

	/* check for lines to de-extend */
	upddex();

	/* if screen is garbage, re-plot it */
	if (sgarbf != FALSE)
		updgar();

	/* update the virtual screen to the physical screen */
	updupd(force);

	/* update the cursor and flush the buffers */
	movecursor(currow, curcol - lbound);
	TTflush();
	displaying = FALSE;
#if SIGWINCH
	while (chg_width || chg_height)
		newscreensize(chg_height, chg_width);
#endif
	return TRUE;
}

/*
 * reframe:
 *	check to see if the cursor is on in the window
 *	and re-frame it if needed or wanted
 */
static int reframe(struct window *wp)
{
	struct line *lp, *lp0;
	int i = 0;

	/* if not a requested reframe, check for a needed one */
	if ((wp->w_flag & WFFORCE) == 0) {
#if SCROLLCODE
		/* loop from one line above the window to one line after */
		lp = wp->w_linep;
		lp0 = lback(lp);
		if (lp0 == wp->w_bufp->b_linep)
			i = 0;
		else {
			i = -1;
			lp = lp0;
		}
		for (; i <= (int) (wp->w_ntrows); i++)
#else
		lp = wp->w_linep;
		for (i = 0; i < wp->w_ntrows; i++)
#endif
		{
			/* if the line is in the window, no reframe */
			if (lp == wp->w_dotp) {
#if SCROLLCODE
				/* if not _quite_ in, we'll reframe gently */
				if (i < 0 || i == wp->w_ntrows) {
					/* if the terminal can't help, then
					   we're simply outside */
					if (term.t_scroll == NULL)
						i = wp->w_force;
					break;
				}
#endif
				return TRUE;
			}

			/* if we are at the end of the file, reframe */
			if (lp == wp->w_bufp->b_linep)
				break;

			/* on to the next line */
			lp = lforw(lp);
		}
	}
#if SCROLLCODE
	if (i == -1) {		/* we're just above the window */
		i = scrollcount;	/* put dot at first line */
		scrflags |= WFINS;
	} else if (i == wp->w_ntrows) {	/* we're just below the window */
		i = -scrollcount;	/* put dot at last line */
		scrflags |= WFKILLS;
	} else			/* put dot where requested */
#endif
		i = wp->w_force;	/* (is 0, unless reposition() was called) */

	wp->w_flag |= WFMODE;

	/* how far back to reframe? */
	if (i > 0) {		/* only one screen worth of lines max */
		if (--i >= wp->w_ntrows)
			i = wp->w_ntrows - 1;
	} else if (i < 0) {	/* negative update???? */
		i += wp->w_ntrows;
		if (i < 0)
			i = 0;
	} else
		i = wp->w_ntrows / 2;

	/* backup to new line at top of window */
	lp = wp->w_dotp;
	while (i != 0 && lback(lp) != wp->w_bufp->b_linep) {
		--i;
		lp = lback(lp);
	}

	/* and reset the current line at top of window */
	wp->w_linep = lp;
	wp->w_flag |= WFHARD;
	wp->w_flag &= ~WFFORCE;
	return TRUE;
}

static void show_line(struct line *lp)
{
	int i = 0, len = llength(lp);

	while (i < len) {
		unicode_t c;
		i += utf8_to_unicode(lp->l_text, i, len, &c);
		vtputc(c);
	}
}

/*
 * updone:
 *	update the current line	to the virtual screen
 *
 * struct window *wp;		window to update current line in
 */
static void updone(struct window *wp)
{
	struct line *lp;	/* line to update */
	int sline;	/* physical screen line to update */

	/* search down the line we want */
	lp = wp->w_linep;
	sline = wp->w_toprow;
	while (lp != wp->w_dotp) {
		++sline;
		lp = lforw(lp);
	}

	/* and update the virtual line */
	vscreen[sline]->v_flag |= VFCHG;
	vscreen[sline]->v_flag &= ~VFREQ;
	vtmove(sline, 0);
	show_line(lp);
#if	COLOR
	vscreen[sline]->v_rfcolor = wp->w_fcolor;
	vscreen[sline]->v_rbcolor = wp->w_bcolor;
#endif
	vteeol();
}

/*
 * updall:
 *	update all the lines in a window on the virtual screen
 *
 * struct window *wp;		window to update lines in
 */
static void updall(struct window *wp)
{
	struct line *lp;	/* line to update */
	int sline;	/* physical screen line to update */

	/* search down the lines, updating them */
	lp = wp->w_linep;
	sline = wp->w_toprow;
	while (sline < wp->w_toprow + wp->w_ntrows) {

		/* and update the virtual line */
		vscreen[sline]->v_flag |= VFCHG;
		vscreen[sline]->v_flag &= ~VFREQ;
		vtmove(sline, 0);
		if (lp != wp->w_bufp->b_linep) {
			/* if we are not at the end */
			show_line(lp);
			lp = lforw(lp);
		}

		/* on to the next one */
#if	COLOR
		vscreen[sline]->v_rfcolor = wp->w_fcolor;
		vscreen[sline]->v_rbcolor = wp->w_bcolor;
#endif
		vteeol();
		++sline;
	}

}

/*
 * updpos:
 *	update the position of the hardware cursor and handle extended
 *	lines. This is the only update for simple moves.
 */
void updpos(void)
{
	struct line *lp;
	int i;

	/* find the current row */
	lp = curwp->w_linep;
	currow = curwp->w_toprow;
	while (lp != curwp->w_dotp) {
		++currow;
		lp = lforw(lp);
	}

	/* find the current column */
	curcol = 0;
	i = 0;
	while (i < curwp->w_doto) {
		unicode_t c;
		int bytes;

		bytes = utf8_to_unicode(lp->l_text, i, curwp->w_doto, &c);
		i += bytes;
		if (c == '\t')
			curcol |= tabmask;

		++curcol;
	}

	/* if extended, flag so and update the virtual line image */
	if (curcol >= term.t_ncol - 1) {
		vscreen[currow]->v_flag |= (VFEXT | VFCHG);
		updext();
	} else
		lbound = 0;
}

/*
 * upddex:
 *	de-extend any line that derserves it
 */
void upddex(void)
{
	struct window *wp;
	struct line *lp;
	int i;

	wp = wheadp;

	while (wp != NULL) {
		lp = wp->w_linep;
		i = wp->w_toprow;

		while (i < wp->w_toprow + wp->w_ntrows) {
			if (vscreen[i]->v_flag & VFEXT) {
				if ((wp != curwp) || (lp != wp->w_dotp) ||
				    (curcol < term.t_ncol - 1)) {
					vtmove(i, 0);
					show_line(lp);
					vteeol();

					/* this line no longer is extended */
					vscreen[i]->v_flag &= ~VFEXT;
					vscreen[i]->v_flag |= VFCHG;
				}
			}
			lp = lforw(lp);
			++i;
		}
		/* and onward to the next window */
		wp = wp->w_wndp;
	}
}

/*
 * updgar:
 *	if the screen is garbage, clear the physical screen and
 *	the virtual screen and force a full update
 */
void updgar(void)
{
	unicode_t *txt;
	int i, j;

	for (i = 0; i < term.t_nrow; ++i) {
		vscreen[i]->v_flag |= VFCHG;
#if	REVSTA
		vscreen[i]->v_flag &= ~VFREV;
#endif
#if	COLOR
		vscreen[i]->v_fcolor = gfcolor;
		vscreen[i]->v_bcolor = gbcolor;
#endif
#if	MEMMAP == 0 || SCROLLCODE
		txt = pscreen[i]->v_text;
		for (j = 0; j < term.t_ncol; ++j)
			txt[j] = ' ';
#endif
	}

	movecursor(0, 0);	/* Erase the screen. */
	(*term.t_eeop) ();
	sgarbf = FALSE;		/* Erase-page clears */
	mpresf = FALSE;		/* the message area. */
#if	COLOR
	mlerase();		/* needs to be cleared if colored */
#endif
}

/*
 * updupd:
 *	update the physical screen from the virtual screen
 *
 * int force;		forced update flag
 */
int updupd(int force)
{
	struct video *vp1;
	int i;

#if SCROLLCODE
	if (scrflags & WFKILLS)
		scrolls(FALSE);
	if (scrflags & WFINS)
		scrolls(TRUE);
	scrflags = 0;
#endif

	for (i = 0; i < term.t_nrow; ++i) {
		vp1 = vscreen[i];

		/* for each line that needs to be updated */
		if ((vp1->v_flag & VFCHG) != 0) {
#if	TYPEAH && ! PKCODE
			if (force == FALSE && typahead())
				return TRUE;
#endif
#if	MEMMAP && ! SCROLLCODE
			updateline(i, vp1);
#else
			updateline(i, vp1, pscreen[i]);
#endif
		}
	}
	return TRUE;
}

#if SCROLLCODE

/*
 * optimize out scrolls (line breaks, and newlines)
 * arg. chooses between looking for inserts or deletes
 */
static int scrolls(int inserts)
{				/* returns true if it does something */
	struct video *vpv;	/* virtual screen image */
	struct video *vpp;	/* physical screen image */
	int i, j, k;
	int rows, cols;
	int first, match, count, target, end;
	int longmatch, longcount;
	int from, to;

	if (!term.t_scroll)	/* no way to scroll */
		return FALSE;

	rows = term.t_nrow;
	cols = term.t_ncol;

	first = -1;
	for (i = 0; i < rows; i++) {	/* find first wrong line */
		if (!texttest(i, i)) {
			first = i;
			break;
		}
	}

	if (first < 0)
		return FALSE;	/* no text changes */

	vpv = vscreen[first];
	vpp = pscreen[first];

	if (inserts) {
		/* determine types of potential scrolls */
		end = endofline(vpv->v_text, cols);
		if (end == 0)
			target = first;	/* newlines */
		else if (memcmp(vpp->v_text, vpv->v_text, 4*end) == 0)
			target = first + 1;	/* broken line newlines */
		else
			target = first;
	} else {
		target = first + 1;
	}

	/* find the matching shifted area */
	match = -1;
	longmatch = -1;
	longcount = 0;
	from = target;
	for (i = from + 1; i < rows - longcount /* P.K. */ ; i++) {
		if (inserts ? texttest(i, from) : texttest(from, i)) {
			match = i;
			count = 1;
			for (j = match + 1, k = from + 1;
			     j < rows && k < rows; j++, k++) {
				if (inserts ? texttest(j, k) :
				    texttest(k, j))
					count++;
				else
					break;
			}
			if (longcount < count) {
				longcount = count;
				longmatch = match;
			}
		}
	}
	match = longmatch;
	count = longcount;

	if (!inserts) {
		/* full kill case? */
		if (match > 0 && texttest(first, match - 1)) {
			target--;
			match--;
			count++;
		}
	}

	/* do the scroll */
	if (match > 0 && count > 2) {	/* got a scroll */
		/* move the count lines starting at target to match */
		if (inserts) {
			from = target;
			to = match;
		} else {
			from = match;
			to = target;
		}
		if (2 * count < abs(from - to))
			return FALSE;
		scrscroll(from, to, count);
		for (i = 0; i < count; i++) {
			vpp = pscreen[to + i];
			vpv = vscreen[to + i];
			memcpy(vpp->v_text, vpv->v_text, 4*cols);
			vpp->v_flag = vpv->v_flag;	/* XXX */
			if (vpp->v_flag & VFREV) {
				vpp->v_flag &= ~VFREV;
				vpp->v_flag |= ~VFREQ;
			}
#if	MEMMAP
			vscreen[to + i]->v_flag &= ~VFCHG;
#endif
		}
		if (inserts) {
			from = target;
			to = match;
		} else {
			from = target + count;
			to = match + count;
		}
#if	MEMMAP == 0
		for (i = from; i < to; i++) {
			unicode_t *txt;
			txt = pscreen[i]->v_text;
			for (j = 0; j < term.t_ncol; ++j)
				txt[j] = ' ';
			vscreen[i]->v_flag |= VFCHG;
		}
#endif
		return TRUE;
	}
	return FALSE;
}

/* move the "count" lines starting at "from" to "to" */
static void scrscroll(int from, int to, int count)
{
	ttrow = ttcol = -1;
	(*term.t_scroll) (from, to, count);
}

/*
 * return TRUE on text match
 *
 * int vrow, prow;		virtual, physical rows
 */
static int texttest(int vrow, int prow)
{
	struct video *vpv = vscreen[vrow];	/* virtual screen image */
	struct video *vpp = pscreen[prow];	/* physical screen image */

	return !memcmp(vpv->v_text, vpp->v_text, 4*term.t_ncol);
}

/*
 * return the index of the first blank of trailing whitespace
 */
static int endofline(unicode_t *s, int n)
{
	int i;
	for (i = n - 1; i >= 0; i--)
		if (s[i] != ' ')
			return i + 1;
	return 0;
}

#endif				/* SCROLLCODE */

/*
 * updext:
 *	update the extended line which the cursor is currently
 *	on at a column greater than the terminal width. The line
 *	will be scrolled right or left to let the user see where
 *	the cursor is
 */
static void updext(void)
{
	int rcursor;	/* real cursor location */
	struct line *lp;	/* pointer to current line */

	/* calculate what column the real cursor will end up in */
	rcursor = ((curcol - term.t_ncol) % term.t_scrsiz) + term.t_margin;
	taboff = lbound = curcol - rcursor + 1;

	/* scan through the line outputing characters to the virtual screen */
	/* once we reach the left edge                                  */
	vtmove(currow, -lbound);	/* start scanning offscreen */
	lp = curwp->w_dotp;	/* line to output */
	show_line(lp);

	/* truncate the virtual line, restore tab offset */
	vteeol();
	taboff = 0;

	/* and put a '$' in column 1 */
	vscreen[currow]->v_text[0] = '$';
}

/*
 * Update a single line. This does not know how to use insert or delete
 * character sequences; we are using VT52 functionality. Update the physical
 * row and column variables. It does try an exploit erase to end of line. The
 * RAINBOW version of this routine uses fast video.
 */
#if	MEMMAP
/*	UPDATELINE specific code for the IBM-PC and other compatables */

static int updateline(int row, struct video *vp1, struct video *vp2)
{
#if	SCROLLCODE
	unicode_t *cp1;
	unicode_t *cp2;
	int nch;

	cp1 = &vp1->v_text[0];
	cp2 = &vp2->v_text[0];
	nch = term.t_ncol;
	do {
		*cp2 = *cp1;
		++cp2;
		++cp1;
	}
	while (--nch);
#endif
#if	COLOR
	scwrite(row, vp1->v_text, vp1->v_rfcolor, vp1->v_rbcolor);
	vp1->v_fcolor = vp1->v_rfcolor;
	vp1->v_bcolor = vp1->v_rbcolor;
#else
	if (vp1->v_flag & VFREQ)
		scwrite(row, vp1->v_text, 0, 7);
	else
		scwrite(row, vp1->v_text, 7, 0);
#endif
	vp1->v_flag &= ~(VFCHG | VFCOL);	/* flag this line as changed */

}

#else

/*
 * updateline()
 *
 * int row;		row of screen to update
 * struct video *vp1;	virtual screen image
 * struct video *vp2;	physical screen image
 */
static int updateline(int row, struct video *vp1, struct video *vp2)
{
#if RAINBOW
/*	UPDATELINE specific code for the DEC rainbow 100 micro	*/

	unicode_t *cp1;
	unicode_t *cp2;
	int nch;

	/* since we don't know how to make the rainbow do this, turn it off */
	flags &= (~VFREV & ~VFREQ);

	cp1 = &vp1->v_text[0];	/* Use fast video. */
	cp2 = &vp2->v_text[0];
	putline(row + 1, 1, cp1);
	nch = term.t_ncol;

	do {
		*cp2 = *cp1;
		++cp2;
		++cp1;
	}
	while (--nch);
	*flags &= ~VFCHG;
#else
/*	UPDATELINE code for all other versions		*/

	unicode_t *cp1;
	unicode_t *cp2;
	unicode_t *cp3;
	unicode_t *cp4;
	unicode_t *cp5;
	int nbflag;	/* non-blanks to the right flag? */
	int rev;		/* reverse video flag */
	int req;		/* reverse video request flag */


	/* set up pointers to virtual and physical lines */
	cp1 = &vp1->v_text[0];
	cp2 = &vp2->v_text[0];

#if	COLOR
	TTforg(vp1->v_rfcolor);
	TTbacg(vp1->v_rbcolor);
#endif

#if	REVSTA | COLOR
	/* if we need to change the reverse video status of the
	   current line, we need to re-write the entire line     */
	rev = (vp1->v_flag & VFREV) == VFREV;
	req = (vp1->v_flag & VFREQ) == VFREQ;
	if ((rev != req)
#if	COLOR
	    || (vp1->v_fcolor != vp1->v_rfcolor)
	    || (vp1->v_bcolor != vp1->v_rbcolor)
#endif
	    ) {
		movecursor(row, 0);	/* Go to start of line. */
		/* set rev video if needed */
		if (rev != req)
			(*term.t_rev) (req);

		/* scan through the line and dump it to the screen and
		   the virtual screen array                             */
		cp3 = &vp1->v_text[term.t_ncol];
		while (cp1 < cp3) {
			TTputc(*cp1);
			++ttcol;
			*cp2++ = *cp1++;
		}
		/* turn rev video off */
		if (rev != req)
			(*term.t_rev) (FALSE);

		/* update the needed flags */
		vp1->v_flag &= ~VFCHG;
		if (req)
			vp1->v_flag |= VFREV;
		else
			vp1->v_flag &= ~VFREV;
#if	COLOR
		vp1->v_fcolor = vp1->v_rfcolor;
		vp1->v_bcolor = vp1->v_rbcolor;
#endif
		return TRUE;
	}
#endif

	/* advance past any common chars at the left */
	while (cp1 != &vp1->v_text[term.t_ncol] && cp1[0] == cp2[0]) {
		++cp1;
		++cp2;
	}

/* This can still happen, even though we only call this routine on changed
 * lines. A hard update is always done when a line splits, a massive
 * change is done, or a buffer is displayed twice. This optimizes out most
 * of the excess updating. A lot of computes are used, but these tend to
 * be hard operations that do a lot of update, so I don't really care.
 */
	/* if both lines are the same, no update needs to be done */
	if (cp1 == &vp1->v_text[term.t_ncol]) {
		vp1->v_flag &= ~VFCHG;	/* flag this line is changed */
		return TRUE;
	}

	/* find out if there is a match on the right */
	nbflag = FALSE;
	cp3 = &vp1->v_text[term.t_ncol];
	cp4 = &vp2->v_text[term.t_ncol];

	while (cp3[-1] == cp4[-1]) {
		--cp3;
		--cp4;
		if (cp3[0] != ' ')	/* Note if any nonblank */
			nbflag = TRUE;	/* in right match. */
	}

	cp5 = cp3;

	/* Erase to EOL ? */
	if (nbflag == FALSE && eolexist == TRUE && (req != TRUE)) {
		while (cp5 != cp1 && cp5[-1] == ' ')
			--cp5;

		if (cp3 - cp5 <= 3)	/* Use only if erase is */
			cp5 = cp3;	/* fewer characters. */
	}

	movecursor(row, cp1 - &vp1->v_text[0]);	/* Go to start of line. */
#if	REVSTA
	TTrev(rev);
#endif

	while (cp1 != cp5) {	/* Ordinary. */
		TTputc(*cp1);
		++ttcol;
		*cp2++ = *cp1++;
	}

	if (cp5 != cp3) {	/* Erase. */
		TTeeol();
		while (cp1 != cp3)
			*cp2++ = *cp1++;
	}
#if	REVSTA
	TTrev(FALSE);
#endif
	vp1->v_flag &= ~VFCHG;	/* flag this line as updated */
	return TRUE;
#endif
}
#endif

/*
 * Redisplay the mode line for the window pointed to by the "wp". This is the
 * only routine that has any idea of how the modeline is formatted. You can
 * change the modeline format by hacking at this routine. Called by "update"
 * any time there is a dirty window.
 */
static void modeline(struct window *wp)
{
	char *cp;
	int c;
	int n;		/* cursor position count */
	struct buffer *bp;
	int i;		/* loop index */
	int lchar;	/* character to draw line in buffer with */
	int firstm;	/* is this the first mode? */
	char tline[NLINE];	/* buffer for part of mode line */

	n = wp->w_toprow + wp->w_ntrows;	/* Location. */
	vscreen[n]->v_flag |= VFCHG | VFREQ | VFCOL;	/* Redraw next time. */
#if	COLOR
	vscreen[n]->v_rfcolor = 0;	/* black on */
	vscreen[n]->v_rbcolor = 7;	/* white..... */
#endif
	vtmove(n, 0);		/* Seek to right line. */
	if (wp == curwp)	/* mark the current buffer */
#if	PKCODE
		lchar = '-';
#else
		lchar = '=';
#endif
	else
#if	REVSTA
	if (revexist)
		lchar = ' ';
	else
#endif
		lchar = '-';

	bp = wp->w_bufp;
#if	PKCODE == 0
	if ((bp->b_flag & BFTRUNC) != 0)
		vtputc('#');
	else
#endif
		vtputc(lchar);

	if ((bp->b_flag & BFCHG) != 0)	/* "*" if changed. */
		vtputc('*');
	else
		vtputc(lchar);

	n = 2;

	strcpy(tline, " ");
	strcat(tline, PROGRAM_NAME_LONG);
	strcat(tline, " ");
	strcat(tline, VERSION);
	strcat(tline, ": ");
	cp = &tline[0];
	while ((c = *cp++) != 0) {
		vtputc(c);
		++n;
	}

	cp = &bp->b_bname[0];
	while ((c = *cp++) != 0) {
		vtputc(c);
		++n;
	}

	strcpy(tline, " (");

	/* display the modes */

	firstm = TRUE;
	if ((bp->b_flag & BFTRUNC) != 0) {
		firstm = FALSE;
		strcat(tline, "Truncated");
	}
	for (i = 0; i < NUMMODES; i++)	/* add in the mode flags */
		if (wp->w_bufp->b_mode & (1 << i)) {
			if (firstm != TRUE)
				strcat(tline, " ");
			firstm = FALSE;
			strcat(tline, mode2name[i]);
		}
	strcat(tline, ") ");

	cp = &tline[0];
	while ((c = *cp++) != 0) {
		vtputc(c);
		++n;
	}

#if	PKCODE
	if (bp->b_fname[0] != 0 && strcmp(bp->b_bname, bp->b_fname) != 0)
#else
	if (bp->b_fname[0] != 0)	/* File name. */
#endif
	{
#if	PKCODE == 0
		cp = "File: ";

		while ((c = *cp++) != 0) {
			vtputc(c);
			++n;
		}
#endif

		cp = &bp->b_fname[0];

		while ((c = *cp++) != 0) {
			vtputc(c);
			++n;
		}

		vtputc(' ');
		++n;
	}

	while (n < term.t_ncol) {	/* Pad to full width. */
		vtputc(lchar);
		++n;
	}

	{			/* determine if top line, bottom line, or both are visible */
		struct line *lp = wp->w_linep;
		int rows = wp->w_ntrows;
		char *msg = NULL;

		vtcol = n - 7;	/* strlen(" top ") plus a couple */
		while (rows--) {
			lp = lforw(lp);
			if (lp == wp->w_bufp->b_linep) {
				msg = " Bot ";
				break;
			}
		}
		if (lback(wp->w_linep) == wp->w_bufp->b_linep) {
			if (msg) {
				if (wp->w_linep == wp->w_bufp->b_linep)
					msg = " Emp ";
				else
					msg = " All ";
			} else {
				msg = " Top ";
			}
		}
		if (!msg) {
			struct line *lp;
			int numlines, predlines, ratio;

			lp = lforw(bp->b_linep);
			numlines = 0;
			predlines = 0;
			while (lp != bp->b_linep) {
				if (lp == wp->w_linep) {
					predlines = numlines;
				}
				++numlines;
				lp = lforw(lp);
			}
			if (wp->w_dotp == bp->b_linep) {
				msg = " Bot ";
			} else {
				ratio = 0;
				if (numlines != 0)
					ratio =
					    (100L * predlines) / numlines;
				if (ratio > 99)
					ratio = 99;
				sprintf(tline, " %2d%% ", ratio);
				msg = tline;
			}
		}

		cp = msg;
		while ((c = *cp++) != 0) {
			vtputc(c);
			++n;
		}
	}
}

void upmode(void)
{				/* update all the mode lines */
	struct window *wp;

	wp = wheadp;
	while (wp != NULL) {
		wp->w_flag |= WFMODE;
		wp = wp->w_wndp;
	}
}

/*
 * Send a command to the terminal to move the hardware cursor to row "row"
 * and column "col". The row and column arguments are origin 0. Optimize out
 * random calls. Update "ttrow" and "ttcol".
 */
void movecursor(int row, int col)
{
	if (row != ttrow || col != ttcol) {
		ttrow = row;
		ttcol = col;
		TTmove(row, col);
	}
}

/*
 * Erase the message line. This is a special routine because the message line
 * is not considered to be part of the virtual screen. It always works
 * immediately; the terminal buffer is flushed via a call to the flusher.
 */
void mlerase(void)
{
	int i;

	movecursor(term.t_nrow, 0);
	if (discmd == FALSE)
		return;

#if	COLOR
	TTforg(7);
	TTbacg(0);
#endif
	if (eolexist == TRUE)
		TTeeol();
	else {
		for (i = 0; i < term.t_ncol - 1; i++)
			TTputc(' ');
		movecursor(term.t_nrow, 1);	/* force the move! */
		movecursor(term.t_nrow, 0);
	}
	TTflush();
	mpresf = FALSE;
}

/*
 * Write a message into the message line. Keep track of the physical cursor
 * position. A small class of printf like format items is handled. Assumes the
 * stack grows down; this assumption is made by the "++" in the argument scan
 * loop. Set the "message line" flag TRUE.
 *
 * char *fmt;		format string for output
 * char *arg;		pointer to first argument to print
 */
void mlwrite(const char *fmt, ...)
{
	int c;		/* current char in format string */
	va_list ap;

	/* if we are not currently echoing on the command line, abort this */
	if (discmd == FALSE) {
		movecursor(term.t_nrow, 0);
		return;
	}
#if	COLOR
	/* set up the proper colors for the command line */
	TTforg(7);
	TTbacg(0);
#endif

	/* if we can not erase to end-of-line, do it manually */
	if (eolexist == FALSE) {
		mlerase();
		TTflush();
	}

	movecursor(term.t_nrow, 0);
	va_start(ap, fmt);
	while ((c = *fmt++) != 0) {
		if (c != '%') {
			TTputc(c);
			++ttcol;
		} else {
			c = *fmt++;
			switch (c) {
			case 'd':
				mlputi(va_arg(ap, int), 10);
				break;

			case 'o':
				mlputi(va_arg(ap, int), 8);
				break;

			case 'x':
				mlputi(va_arg(ap, int), 16);
				break;

			case 'D':
				mlputli(va_arg(ap, long), 10);
				break;

			case 's':
				mlputs(va_arg(ap, char *));
				break;

			case 'f':
				mlputf(va_arg(ap, int));
				break;

			default:
				TTputc(c);
				++ttcol;
			}
		}
	}
	va_end(ap);

	/* if we can, erase to the end of screen */
	if (eolexist == TRUE)
		TTeeol();
	TTflush();
	mpresf = TRUE;
}

/*
 * Force a string out to the message line regardless of the
 * current $discmd setting. This is needed when $debug is TRUE
 * and for the write-message and clear-message-line commands
 *
 * char *s;		string to force out
 */
void mlforce(char *s)
{
	int oldcmd;	/* original command display flag */

	oldcmd = discmd;	/* save the discmd value */
	discmd = TRUE;		/* and turn display on */
	mlwrite(s);		/* write the string out */
	discmd = oldcmd;	/* and restore the original setting */
}

/*
 * Write out a string. Update the physical cursor position. This assumes that
 * the characters in the string all have width "1"; if this is not the case
 * things will get screwed up a little.
 */
void mlputs(char *s)
{
	int c;

	while ((c = *s++) != 0) {
		TTputc(c);
		++ttcol;
	}
}

/*
 * Write out an integer, in the specified radix. Update the physical cursor
 * position.
 */
static void mlputi(int i, int r)
{
	int q;
	static char hexdigits[] = "0123456789ABCDEF";

	if (i < 0) {
		i = -i;
		TTputc('-');
	}

	q = i / r;

	if (q != 0)
		mlputi(q, r);

	TTputc(hexdigits[i % r]);
	++ttcol;
}

/*
 * do the same except as a long integer.
 */
static void mlputli(long l, int r)
{
	long q;

	if (l < 0) {
		l = -l;
		TTputc('-');
	}

	q = l / r;

	if (q != 0)
		mlputli(q, r);

	TTputc((int) (l % r) + '0');
	++ttcol;
}

/*
 * write out a scaled integer with two decimal places
 *
 * int s;		scaled integer to output
 */
static void mlputf(int s)
{
	int i;			/* integer portion of number */
	int f;			/* fractional portion of number */

	/* break it up */
	i = s / 100;
	f = s % 100;

	/* send out the integer portion */
	mlputi(i, 10);
	TTputc('.');
	TTputc((f / 10) + '0');
	TTputc((f % 10) + '0');
	ttcol += 3;
}

#if RAINBOW

static void putline(int row, int col, char *buf)
{
	int n;

	n = strlen(buf);
	if (col + n - 1 > term.t_ncol)
		n = term.t_ncol - col + 1;
	Put_Data(row, col, n, buf);
}
#endif

/* Get terminal size from system.
   Store number of lines into *heightp and width into *widthp.
   If zero or a negative number is stored, the value is not valid.  */

void getscreensize(int *widthp, int *heightp)
{
#ifdef TIOCGWINSZ
	struct winsize size;
	*widthp = 0;
	*heightp = 0;
	if (ioctl(0, TIOCGWINSZ, &size) < 0)
		return;
	*widthp = size.ws_col;
	*heightp = size.ws_row;
#else
	*widthp = 0;
	*heightp = 0;
#endif
}

#ifdef SIGWINCH
void sizesignal(int signr)
{
	int w, h;
	int old_errno = errno;

	getscreensize(&w, &h);

	if (h && w && (h - 1 != term.t_nrow || w != term.t_ncol))
		newscreensize(h, w);

	signal(SIGWINCH, sizesignal);
	errno = old_errno;
}

static int newscreensize(int h, int w)
{
	/* do the change later */
	if (displaying) {
		chg_width = w;
		chg_height = h;
		return FALSE;
	}
	chg_width = chg_height = 0;
	if (h - 1 < term.t_mrow)
		newsize(TRUE, h);
	if (w < term.t_mcol)
		newwidth(TRUE, w);

	update(TRUE);
	return TRUE;
}

#endif


/* ----- eval.c ----- */
/*	eval.c
 *
 *	Expression evaluation functions
 *
 *	written 1986 by Daniel Lawrence
 *	modified by Petri Kutvonen
 */
/* system header already included */
/* #include "estruct.h" - amalgamated */
/* #include "edef.h" - amalgamated */
/* #include "efunc.h" - amalgamated */
/* #include "evar.h" - amalgamated */
/* #include "line.h" - amalgamated */
/* #include "util.h" - amalgamated */
/* #include "version.h" - amalgamated */

#define	MAXVARS	255

/* User variables */
static struct user_variable uv[MAXVARS + 1];

/* Initialize the user variable list. */
void varinit(void)
{
	int i;
	for (i = 0; i < MAXVARS; i++)
		uv[i].u_name[0] = 0;
}

/*
 * Evaluate a function.
 *
 * @fname: name of function to evaluate.
 */
char *gtfun(char *fname)
{
	int fnum;	/* index to function to eval */
	int status;	/* return status */
	char *tsp;	/* temporary string pointer */
	char arg1[NSTRING];	/* value of first argument */
	char arg2[NSTRING];	/* value of second argument */
	char arg3[NSTRING];	/* value of third argument */
	static char result[2 * NSTRING];	/* string result */

	/* look the function up in the function table */
	fname[3] = 0;		/* only first 3 chars significant */
	mklower(fname);		/* and let it be upper or lower case */
	for (fnum = 0; fnum < ARRAY_SIZE(funcs); fnum++)
		if (strcmp(fname, funcs[fnum].f_name) == 0)
			break;

	/* return errorm on a bad reference */
	if (fnum == ARRAY_SIZE(funcs))
		return errorm;

	/* if needed, retrieve the first argument */
	if (funcs[fnum].f_type >= MONAMIC) {
		if ((status = macarg(arg1)) != TRUE)
			return errorm;

		/* if needed, retrieve the second argument */
		if (funcs[fnum].f_type >= DYNAMIC) {
			if ((status = macarg(arg2)) != TRUE)
				return errorm;

			/* if needed, retrieve the third argument */
			if (funcs[fnum].f_type >= TRINAMIC)
				if ((status = macarg(arg3)) != TRUE)
					return errorm;
		}
	}


	/* and now evaluate it! */
	switch (fnum) {
	case UFADD:
		return itoa(atoi(arg1) + atoi(arg2));
	case UFSUB:
		return itoa(atoi(arg1) - atoi(arg2));
	case UFTIMES:
		return itoa(atoi(arg1) * atoi(arg2));
	case UFDIV:
		return itoa(atoi(arg1) / atoi(arg2));
	case UFMOD:
		return itoa(atoi(arg1) % atoi(arg2));
	case UFNEG:
		return itoa(-atoi(arg1));
	case UFCAT:
		strcpy(result, arg1);
		return strcat(result, arg2);
	case UFLEFT:
		return strncpy(result, arg1, atoi(arg2));
	case UFRIGHT:
		return (strcpy(result,
			       &arg1[(strlen(arg1) - atoi(arg2))]));
	case UFMID:
		return (strncpy(result, &arg1[atoi(arg2) - 1],
				atoi(arg3)));
	case UFNOT:
		return ltos(stol(arg1) == FALSE);
	case UFEQUAL:
		return ltos(atoi(arg1) == atoi(arg2));
	case UFLESS:
		return ltos(atoi(arg1) < atoi(arg2));
	case UFGREATER:
		return ltos(atoi(arg1) > atoi(arg2));
	case UFSEQUAL:
		return ltos(strcmp(arg1, arg2) == 0);
	case UFSLESS:
		return ltos(strcmp(arg1, arg2) < 0);
	case UFSGREAT:
		return ltos(strcmp(arg1, arg2) > 0);
	case UFIND:
		return getval(arg1, result, sizeof(result));
	case UFAND:
		return ltos(stol(arg1) && stol(arg2));
	case UFOR:
		return ltos(stol(arg1) || stol(arg2));
	case UFLENGTH:
		return itoa(strlen(arg1));
	case UFUPPER:
		return mkupper(arg1);
	case UFLOWER:
		return mklower(arg1);
	case UFTRUTH:
		return ltos(atoi(arg1) == 42);
	case UFASCII:
		return itoa((int) arg1[0]);
	case UFCHR:
		result[0] = atoi(arg1);
		result[1] = 0;
		return result;
	case UFGTKEY:
		result[0] = tgetc();
		result[1] = 0;
		return result;
	case UFRND:
		return itoa((ernd() % abs(atoi(arg1))) + 1);
	case UFABS:
		return itoa(abs(atoi(arg1)));
	case UFSINDEX:
		return itoa(sindex(arg1, arg2));
	case UFENV:
#if	ENVFUNC
		tsp = getenv(arg1);
		return tsp == NULL ? "" : tsp;
#else
		return "";
#endif
	case UFBIND:
		return transbind(arg1);
	case UFEXIST:
		return ltos(fexist(arg1));
	case UFFIND:
		tsp = flook(arg1, TRUE);
		return tsp == NULL ? "" : tsp;
	case UFBAND:
		return itoa(atoi(arg1) & atoi(arg2));
	case UFBOR:
		return itoa(atoi(arg1) | atoi(arg2));
	case UFBXOR:
		return itoa(atoi(arg1) ^ atoi(arg2));
	case UFBNOT:
		return itoa(~atoi(arg1));
	case UFXLATE:
		return xlat(arg1, arg2, arg3);
	}

	exit(-11);		/* never should get here */
}

/*
 * look up a user var's value
 *
 * char *vname;			name of user variable to fetch
 */
char *gtusr(char *vname)
{

	int vnum;	/* ordinal number of user var */

	/* scan the list looking for the user var name */
	for (vnum = 0; vnum < MAXVARS; vnum++) {
		if (uv[vnum].u_name[0] == 0)
			return errorm;
		if (strcmp(vname, uv[vnum].u_name) == 0)
			return uv[vnum].u_value;
	}

	/* return errorm if we run off the end */
	return errorm;
}

extern char *getkill(void);

/*
 * gtenv()
 *
 * char *vname;			name of environment variable to retrieve
 */
char *gtenv(char *vname)
{
	int vnum;	/* ordinal number of var refrenced */

	/* scan the list, looking for the referenced name */
	for (vnum = 0; vnum < ARRAY_SIZE(envars); vnum++)
		if (strcmp(vname, envars[vnum]) == 0)
			break;

	/* return errorm on a bad reference */
	if (vnum == ARRAY_SIZE(envars))
#if	ENVFUNC
	{
		char *ename = getenv(vname);

		if (ename != NULL)
			return ename;
		else
			return errorm;
	}
#else
		return errorm;
#endif

	/* otherwise, fetch the appropriate value */
	switch (vnum) {
	case EVFILLCOL:
		return itoa(fillcol);
	case EVPAGELEN:
		return itoa(term.t_nrow + 1);
	case EVCURCOL:
		return itoa(getccol(FALSE));
	case EVCURLINE:
		return itoa(getcline());
	case EVRAM:
		return itoa((int) (envram / 1024l));
	case EVFLICKER:
		return ltos(flickcode);
	case EVCURWIDTH:
		return itoa(term.t_ncol);
	case EVCBUFNAME:
		return curbp->b_bname;
	case EVCFNAME:
		return curbp->b_fname;
	case EVSRES:
		return sres;
	case EVDEBUG:
		return ltos(macbug);
	case EVSTATUS:
		return ltos(cmdstatus);
	case EVPALETTE:
		return palstr;
	case EVASAVE:
		return itoa(gasave);
	case EVACOUNT:
		return itoa(gacount);
	case EVLASTKEY:
		return itoa(lastkey);
	case EVCURCHAR:
		return (curwp->w_dotp->l_used ==
			curwp->w_doto ? itoa('\n') :
			itoa(lgetc(curwp->w_dotp, curwp->w_doto)));
	case EVDISCMD:
		return ltos(discmd);
	case EVVERSION:
		return VERSION;
	case EVPROGNAME:
		return PROGRAM_NAME_LONG;
	case EVSEED:
		return itoa(seed);
	case EVDISINP:
		return ltos(disinp);
	case EVWLINE:
		return itoa(curwp->w_ntrows);
	case EVCWLINE:
		return itoa(getwpos());
	case EVTARGET:
		saveflag = lastflag;
		return itoa(curgoal);
	case EVSEARCH:
		return pat;
	case EVREPLACE:
		return rpat;
	case EVMATCH:
		return (patmatch == NULL) ? "" : patmatch;
	case EVKILL:
		return getkill();
	case EVCMODE:
		return itoa(curbp->b_mode);
	case EVGMODE:
		return itoa(gmode);
	case EVTPAUSE:
		return itoa(term.t_pause);
	case EVPENDING:
#if	TYPEAH
		return ltos(typahead());
#else
		return falsem;
#endif
	case EVLWIDTH:
		return itoa(llength(curwp->w_dotp));
	case EVLINE:
		return getctext();
	case EVGFLAGS:
		return itoa(gflags);
	case EVRVAL:
		return itoa(rval);
	case EVTAB:
		return itoa(tabmask + 1);
	case EVOVERLAP:
		return itoa(overlap);
	case EVSCROLLCOUNT:
		return itoa(scrollcount);
#if SCROLLCODE
	case EVSCROLL:
		return ltos(term.t_scroll != NULL);
#else
	case EVSCROLL:
		return ltos(0);
#endif
	}
	exit(-12);		/* again, we should never get here */
}

/*
 * return some of the contents of the kill buffer
 */
char *getkill(void)
{
	int size;	/* max number of chars to return */
	static char value[NSTRING];	/* temp buffer for value */

	if (kbufh == NULL)
		/* no kill buffer....just a null string */
		value[0] = 0;
	else {
		/* copy in the contents... */
		if (kused < NSTRING)
			size = kused;
		else
			size = NSTRING - 1;
		strncpy(value, kbufh->d_chunk, size);
	}

	/* and return the constructed value */
	return value;
}

/*
 * set a variable
 *
 * int f;		default flag
 * int n;		numeric arg (can overide prompted value)
 */
int setvar(int f, int n)
{
	int status;	/* status return */
#if	DEBUGM
	char *sp;	/* temp string pointer */
	char *ep;	/* ptr to end of outline */
#endif
	struct variable_description vd;		/* variable num/type */
	char var[NVSIZE + 1];	/* name of variable to fetch */
	char value[NSTRING];	/* value to set variable to */

	/* first get the variable to set.. */
	if (clexec == FALSE) {
		status = mlreply("Variable to set: ", &var[0], NVSIZE);
		if (status != TRUE)
			return status;
	} else {		/* macro line argument */
		/* grab token and skip it */
		execstr = token(execstr, var, NVSIZE + 1);
	}

	/* check the legality and find the var */
	findvar(var, &vd, NVSIZE + 1);

	/* if its not legal....bitch */
	if (vd.v_type == -1) {
		mlwrite("%%No such variable as '%s'", var);
		return FALSE;
	}

	/* get the value for that variable */
	if (f == TRUE)
		strcpy(value, itoa(n));
	else {
		status = mlreply("Value: ", &value[0], NSTRING);
		if (status != TRUE)
			return status;
	}

	/* and set the appropriate value */
	status = svar(&vd, value);

#if	DEBUGM
	/* if $debug == TRUE, every assignment will echo a statment to
	   that effect here. */

	if (macbug) {
		strcpy(outline, "(((");

		/* assignment status */
		strcat(outline, ltos(status));
		strcat(outline, ":");

		/* variable name */
		strcat(outline, var);
		strcat(outline, ":");

		/* and lastly the value we tried to assign */
		strcat(outline, value);
		strcat(outline, ")))");

		/* expand '%' to "%%" so mlwrite wont bitch */
		sp = outline;
		while (*sp)
			if (*sp++ == '%') {
				/* advance to the end */
				ep = --sp;
				while (*ep++);
				/* null terminate the string one out */
				*(ep + 1) = 0;
				/* copy backwards */
				while (ep-- > sp)
					*(ep + 1) = *ep;

				/* and advance sp past the new % */
				sp += 2;
			}

		/* write out the debug line */
		mlforce(outline);
		update(TRUE);

		/* and get the keystroke to hold the output */
		if (get1key() == abortc) {
			mlforce("(Macro aborted)");
			status = FALSE;
		}
	}
#endif

	/* and return it */
	return status;
}

/*
 * Find a variables type and name.
 *
 * @var: name of variable to get.
 * @vd: structure to hold type and pointer.
 * @size: size of variable array.
 */
void findvar(char *var, struct variable_description *vd, int size)
{
	int vnum;	/* subscript in variable arrays */
	int vtype;	/* type to return */

	vnum = -1;
fvar:
	vtype = -1;
	switch (var[0]) {

	case '$':		/* check for legal enviromnent var */
		for (vnum = 0; vnum < ARRAY_SIZE(envars); vnum++)
			if (strcmp(&var[1], envars[vnum]) == 0) {
				vtype = TKENV;
				break;
			}
		break;

	case '%':		/* check for existing legal user variable */
		for (vnum = 0; vnum < MAXVARS; vnum++)
			if (strcmp(&var[1], uv[vnum].u_name) == 0) {
				vtype = TKVAR;
				break;
			}
		if (vnum < MAXVARS)
			break;

		/* create a new one??? */
		for (vnum = 0; vnum < MAXVARS; vnum++)
			if (uv[vnum].u_name[0] == 0) {
				vtype = TKVAR;
				strcpy(uv[vnum].u_name, &var[1]);
				break;
			}
		break;

	case '&':		/* indirect operator? */
		var[4] = 0;
		if (strcmp(&var[1], "ind") == 0) {
			/* grab token, and eval it */
			execstr = token(execstr, var, size);
			getval(var, var, size);
			goto fvar;
		}
	}

	/* return the results */
	vd->v_num = vnum;
	vd->v_type = vtype;
	return;
}

/*
 * Set a variable.
 *
 * @var: variable to set.
 * @value: value to set to.
 */
int svar(struct variable_description *var, char *value)
{
	int vnum;	/* ordinal number of var refrenced */
	int vtype;	/* type of variable to set */
	int status;	/* status return */
	int c;		/* translated character */
	char *sp;	/* scratch string pointer */

	/* simplify the vd structure (we are gonna look at it a lot) */
	vnum = var->v_num;
	vtype = var->v_type;

	/* and set the appropriate value */
	status = TRUE;
	switch (vtype) {
	case TKVAR:		/* set a user variable */
		if (uv[vnum].u_value != NULL)
			free(uv[vnum].u_value);
		sp = malloc(strlen(value) + 1);
		if (sp == NULL)
			return FALSE;
		strcpy(sp, value);
		uv[vnum].u_value = sp;
		break;

	case TKENV:		/* set an environment variable */
		status = TRUE;	/* by default */
		switch (vnum) {
		case EVFILLCOL:
			fillcol = atoi(value);
			break;
		case EVPAGELEN:
			status = newsize(TRUE, atoi(value));
			break;
		case EVCURCOL:
			status = setccol(atoi(value));
			break;
		case EVCURLINE:
			status = gotoline(TRUE, atoi(value));
			break;
		case EVRAM:
			break;
		case EVFLICKER:
			flickcode = stol(value);
			break;
		case EVCURWIDTH:
			status = newwidth(TRUE, atoi(value));
			break;
		case EVCBUFNAME:
			strcpy(curbp->b_bname, value);
			curwp->w_flag |= WFMODE;
			break;
		case EVCFNAME:
			strcpy(curbp->b_fname, value);
			curwp->w_flag |= WFMODE;
			break;
		case EVSRES:
			status = TTrez(value);
			break;
		case EVDEBUG:
			macbug = stol(value);
			break;
		case EVSTATUS:
			cmdstatus = stol(value);
			break;
		case EVASAVE:
			gasave = atoi(value);
			break;
		case EVACOUNT:
			gacount = atoi(value);
			break;
		case EVLASTKEY:
			lastkey = atoi(value);
			break;
		case EVCURCHAR:
			ldelchar(1, FALSE);	/* delete 1 char */
			c = atoi(value);
			if (c == '\n')
				lnewline();
			else
				linsert(1, c);
			backchar(FALSE, 1);
			break;
		case EVDISCMD:
			discmd = stol(value);
			break;
		case EVVERSION:
			break;
		case EVPROGNAME:
			break;
		case EVSEED:
			seed = atoi(value);
			break;
		case EVDISINP:
			disinp = stol(value);
			break;
		case EVWLINE:
			status = resize(TRUE, atoi(value));
			break;
		case EVCWLINE:
			status = forwline(TRUE, atoi(value) - getwpos());
			break;
		case EVTARGET:
			curgoal = atoi(value);
			thisflag = saveflag;
			break;
		case EVSEARCH:
			strcpy(pat, value);
			rvstrcpy(tap, pat);
#if	MAGIC
			mcclear();
#endif
			break;
		case EVREPLACE:
			strcpy(rpat, value);
			break;
		case EVMATCH:
			break;
		case EVKILL:
			break;
		case EVCMODE:
			curbp->b_mode = atoi(value);
			curwp->w_flag |= WFMODE;
			break;
		case EVGMODE:
			gmode = atoi(value);
			break;
		case EVTPAUSE:
			term.t_pause = atoi(value);
			break;
		case EVPENDING:
			break;
		case EVLWIDTH:
			break;
		case EVLINE:
			putctext(value);
		case EVGFLAGS:
			gflags = atoi(value);
			break;
		case EVRVAL:
			break;
		case EVTAB:
			tabmask = atoi(value) - 1;
			if (tabmask != 0x07 && tabmask != 0x03)
				tabmask = 0x07;
			curwp->w_flag |= WFHARD;
			break;
		case EVOVERLAP:
			overlap = atoi(value);
			break;
		case EVSCROLLCOUNT:
			scrollcount = atoi(value);
			break;
		case EVSCROLL:
#if SCROLLCODE
			if (!stol(value))
				term.t_scroll = NULL;
#endif
			break;
		}
		break;
	}
	return status;
}

/*
 * itoa:
 *	integer to ascii string.......... This is too
 *	inconsistant to use the system's
 *
 * int i;		integer to translate to a string
 */
char *itoa(int i)
{
	int digit;	/* current digit being used */
	char *sp;	/* pointer into result */
	int sign;	/* sign of resulting number */
	static char result[INTWIDTH + 1];	/* resulting string */

	/* record the sign... */
	sign = 1;
	if (i < 0) {
		sign = -1;
		i = -i;
	}

	/* and build the string (backwards!) */
	sp = result + INTWIDTH;
	*sp = 0;
	do {
		digit = i % 10;
		*(--sp) = '0' + digit;	/* and install the new digit */
		i = i / 10;
	} while (i);

	/* and fix the sign */
	if (sign == -1) {
		*(--sp) = '-';	/* and install the minus sign */
	}

	return sp;
}

/*
 * find the type of a passed token
 *
 * char *token;		token to analyze
 */
int gettyp(char *token)
{
	char c;	/* first char in token */

	/* grab the first char (this is all we need) */
	c = *token;

	/* no blanks!!! */
	if (c == 0)
		return TKNUL;

	/* a numeric literal? */
	if (c >= '0' && c <= '9')
		return TKLIT;

	switch (c) {
	case '"':
		return TKSTR;

	case '!':
		return TKDIR;
	case '@':
		return TKARG;
	case '#':
		return TKBUF;
	case '$':
		return TKENV;
	case '%':
		return TKVAR;
	case '&':
		return TKFUN;
	case '*':
		return TKLBL;

	default:
		return TKCMD;
	}
}

/*
 * find the value of a token
 *
 * char *token;		token to evaluate
 */
static char *internal_getval(char *token)
{
	int status;	/* error return */
	struct buffer *bp;	/* temp buffer pointer */
	int blen;	/* length of buffer argument */
	int distmp;	/* temporary discmd flag */
	static char buf[NSTRING];	/* string buffer for some returns */

	switch (gettyp(token)) {
	case TKNUL:
		return "";

	case TKARG:		/* interactive argument */
		getval(token+1, token, -1);
		distmp = discmd;	/* echo it always! */
		discmd = TRUE;
		status = getstring(token, buf, NSTRING, ctoec('\n'));
		discmd = distmp;
		if (status == ABORT)
			return errorm;
		return buf;

	case TKBUF:		/* buffer contents fetch */

		/* grab the right buffer */
		getval(token+1, token, -1);
		bp = bfind(token, FALSE, 0);
		if (bp == NULL)
			return errorm;

		/* if the buffer is displayed, get the window
		   vars instead of the buffer vars */
		if (bp->b_nwnd > 0) {
			curbp->b_dotp = curwp->w_dotp;
			curbp->b_doto = curwp->w_doto;
		}

		/* make sure we are not at the end */
		if (bp->b_linep == bp->b_dotp)
			return errorm;

		/* grab the line as an argument */
		blen = bp->b_dotp->l_used - bp->b_doto;
		if (blen > NSTRING)
			blen = NSTRING;
		strncpy(buf, bp->b_dotp->l_text + bp->b_doto, blen);
		buf[blen] = 0;

		/* and step the buffer's line ptr ahead a line */
		bp->b_dotp = bp->b_dotp->l_fp;
		bp->b_doto = 0;

		/* if displayed buffer, reset window ptr vars */
		if (bp->b_nwnd > 0) {
			curwp->w_dotp = curbp->b_dotp;
			curwp->w_doto = 0;
			curwp->w_flag |= WFMOVE;
		}

		/* and return the spoils */
		return buf;

	case TKVAR:
		return gtusr(token + 1);
	case TKENV:
		return gtenv(token + 1);
	case TKFUN:
		return gtfun(token + 1);
	case TKDIR:
		return errorm;
	case TKLBL:
		return errorm;
	case TKLIT:
		return token;
	case TKSTR:
		return token + 1;
	case TKCMD:
		return token;
	}
	return errorm;
}

char *getval(char *token, char *dst, int size)
{
	char *res = internal_getval(token);
	mystrscpy(dst, res, size);
	return dst;
}

/*
 * convert a string to a numeric logical
 *
 * char *val;		value to check for stol
 */
int stol(char *val)
{
	/* check for logical values */
	if (val[0] == 'F')
		return FALSE;
	if (val[0] == 'T')
		return TRUE;

	/* check for numeric truth (!= 0) */
	return (atoi(val) != 0);
}

/*
 * numeric logical to string logical
 *
 * int val;		value to translate
 */
char *ltos(int val)
{
	if (val)
		return truem;
	else
		return falsem;
}

/*
 * make a string upper case
 *
 * char *str;		string to upper case
 */
char *mkupper(char *str)
{
	char *sp;

	sp = str;
	while (*sp) {
		if ('a' <= *sp && *sp <= 'z')
			*sp += 'A' - 'a';
		++sp;
	}
	return str;
}

/*
 * make a string lower case
 *
 * char *str;		string to lower case
 */
char *mklower(char *str)
{
	char *sp;

	sp = str;
	while (*sp) {
		if ('A' <= *sp && *sp <= 'Z')
			*sp += 'a' - 'A';
		++sp;
	}
	return str;
}

/*
 * take the absolute value of an integer
 */
int abs(int x)
{
	return x < 0 ? -x : x;
}

/*
 * returns a random integer
 */
int ernd(void)
{
	seed = abs(seed * 1721 + 10007);
	return seed;
}

/*
 * find pattern within source
 *
 * char *source;	source string to search
 * char *pattern;	string to look for
 */
int sindex(char *source, char *pattern)
{
	char *sp;		/* ptr to current position to scan */
	char *csp;		/* ptr to source string during comparison */
	char *cp;		/* ptr to place to check for equality */

	/* scanning through the source string */
	sp = source;
	while (*sp) {
		/* scan through the pattern */
		cp = pattern;
		csp = sp;
		while (*cp) {
			if (!eq(*cp, *csp))
				break;
			++cp;
			++csp;
		}

		/* was it a match? */
		if (*cp == 0)
			return (int) (sp - source) + 1;
		++sp;
	}

	/* no match at all.. */
	return 0;
}

/*
 * Filter a string through a translation table
 *
 * char *source;	string to filter
 * char *lookup;	characters to translate
 * char *trans;		resulting translated characters
 */
char *xlat(char *source, char *lookup, char *trans)
{
	char *sp;	/* pointer into source table */
	char *lp;	/* pointer into lookup table */
	char *rp;	/* pointer into result */
	static char result[NSTRING];	/* temporary result */

	/* scan source string */
	sp = source;
	rp = result;
	while (*sp) {
		/* scan lookup table for a match */
		lp = lookup;
		while (*lp) {
			if (*sp == *lp) {
				*rp++ = trans[lp - lookup];
				goto xnext;
			}
			++lp;
		}

		/* no match, copy in the source char untranslated */
		*rp++ = *sp;

	      xnext:++sp;
	}

	/* terminate and return the result */
	*rp = 0;
	return result;
}


/* ----- exec.c ----- */
/*	exec.c
 *
 *	This file is for functions dealing with execution of
 *	commands, command lines, buffers, files and startup files.
 *
 *	written 1986 by Daniel Lawrence
 *	modified by Petri Kutvonen
 */
/* system header already included */
/* #include "estruct.h" - amalgamated */
/* #include "edef.h" - amalgamated */
/* #include "efunc.h" - amalgamated */
/* #include "line.h" - amalgamated */

/*
 * Execute a named command even if it is not bound.
 */
int namedcmd(int f, int n)
{
	fn_t kfunc;	/* ptr to the requexted function to bind to */

	/* prompt the user to type a named command */
	mlwrite(": ");

	/* and now get the function name to execute */
	kfunc = getname();
	if (kfunc == NULL) {
		mlwrite("(No such function)");
		return FALSE;
	}

	/* and then execute the command */
	return kfunc(f, n);
}

/*
 * execcmd:
 *	Execute a command line command to be typed in
 *	by the user
 *
 * int f, n;		default Flag and Numeric argument
 */
int execcmd(int f, int n)
{
	int status;	/* status return */
	char cmdstr[NSTRING];	/* string holding command to execute */

	/* get the line wanted */
	if ((status = mlreply(": ", cmdstr, NSTRING)) != TRUE)
		return status;

	execlevel = 0;
	return docmd(cmdstr);
}

/*
 * docmd:
 *	take a passed string as a command line and translate
 * 	it to be executed as a command. This function will be
 *	used by execute-command-line and by all source and
 *	startup files. Lastflag/thisflag is also updated.
 *
 *	format of the command line is:
 *
 *		{# arg} <command-name> {<argument string(s)>}
 *
 * char *cline;		command line to execute
 */
int docmd(char *cline)
{
	int f;		/* default argument flag */
	int n;		/* numeric repeat value */
	fn_t fnc;		/* function to execute */
	int status;		/* return status of function */
	int oldcle;		/* old contents of clexec flag */
	char *oldestr;		/* original exec string */
	char tkn[NSTRING];	/* next token off of command line */

	/* if we are scanning and not executing..go back here */
	if (execlevel)
		return TRUE;

	oldestr = execstr;	/* save last ptr to string to execute */
	execstr = cline;	/* and set this one as current */

	/* first set up the default command values */
	f = FALSE;
	n = 1;
	lastflag = thisflag;
	thisflag = 0;

	if ((status = macarg(tkn)) != TRUE) {	/* and grab the first token */
		execstr = oldestr;
		return status;
	}

	/* process leadin argument */
	if (gettyp(tkn) != TKCMD) {
		f = TRUE;
		getval(tkn, tkn, sizeof(tkn));
		n = atoi(tkn);

		/* and now get the command to execute */
		if ((status = macarg(tkn)) != TRUE) {
			execstr = oldestr;
			return status;
		}
	}

	/* and match the token to see if it exists */
	if ((fnc = fncmatch(tkn)) == NULL) {
		mlwrite("(No such Function)");
		execstr = oldestr;
		return FALSE;
	}

	/* save the arguments and go execute the command */
	oldcle = clexec;	/* save old clexec flag */
	clexec = TRUE;		/* in cline execution */
	status = (*fnc) (f, n);	/* call the function */
	cmdstatus = status;	/* save the status */
	clexec = oldcle;	/* restore clexec flag */
	execstr = oldestr;
	return status;
}

/*
 * token:
 *	chop a token off a string
 *	return a pointer past the token
 *
 * char *src, *tok;	source string, destination token string
 * int size;		maximum size of token
 */
char *token(char *src, char *tok, int size)
{
	int quotef;	/* is the current string quoted? */
	char c;	/* temporary character */

	/* first scan past any whitespace in the source string */
	while (*src == ' ' || *src == '\t')
		++src;

	/* scan through the source string */
	quotef = FALSE;
	while (*src) {
		/* process special characters */
		if (*src == '~') {
			++src;
			if (*src == 0)
				break;
			switch (*src++) {
			case 'r':
				c = 13;
				break;
			case 'n':
				c = 10;
				break;
			case 't':
				c = 9;
				break;
			case 'b':
				c = 8;
				break;
			case 'f':
				c = 12;
				break;
			default:
				c = *(src - 1);
			}
			if (--size > 0) {
				*tok++ = c;
			}
		} else {
			/* check for the end of the token */
			if (quotef) {
				if (*src == '"')
					break;
			} else {
				if (*src == ' ' || *src == '\t')
					break;
			}

			/* set quote mode if quote found */
			if (*src == '"')
				quotef = TRUE;

			/* record the character */
			c = *src++;
			if (--size > 0)
				*tok++ = c;
		}
	}

	/* terminate the token and exit */
	if (*src)
		++src;
	*tok = 0;
	return src;
}

/*
 * get a macro line argument
 *
 * char *tok;		buffer to place argument
 */
int macarg(char *tok)
{
	int savcle;		/* buffer to store original clexec */
	int status;

	savcle = clexec;	/* save execution mode */
	clexec = TRUE;		/* get the argument */
	status = nextarg("", tok, NSTRING, ctoec('\n'));
	clexec = savcle;	/* restore execution mode */
	return status;
}

/*
 * nextarg:
 *	get the next argument
 *
 * char *prompt;		prompt to use if we must be interactive
 * char *buffer;		buffer to put token into
 * int size;			size of the buffer
 * int terminator;		terminating char to be used on interactive fetch
 */
int nextarg(char *prompt, char *buffer, int size, int terminator)
{
	/* if we are interactive, go get it! */
	if (clexec == FALSE)
		return getstring(prompt, buffer, size, terminator);

	/* grab token and advance past */
	execstr = token(execstr, buffer, size);

	/* evaluate it */
	getval(buffer, buffer, size);
	return TRUE;
}

/*
 * storemac:
 *	Set up a macro buffer and flag to store all
 *	executed command lines there
 *
 * int f;		default flag
 * int n;		macro number to use
 */
int storemac(int f, int n)
{
	struct buffer *bp;	/* pointer to macro buffer */
	char bname[NBUFN];	/* name of buffer to use */

	/* must have a numeric argument to this function */
	if (f == FALSE) {
		mlwrite("No macro specified");
		return FALSE;
	}

	/* range check the macro number */
	if (n < 1 || n > 40) {
		mlwrite("Macro number out of range");
		return FALSE;
	}

	/* construct the macro buffer name */
	strcpy(bname, "*Macro xx*");
	bname[7] = '0' + (n / 10);
	bname[8] = '0' + (n % 10);

	/* set up the new macro buffer */
	if ((bp = bfind(bname, TRUE, BFINVS)) == NULL) {
		mlwrite("Can not create macro");
		return FALSE;
	}

	/* and make sure it is empty */
	bclear(bp);

	/* and set the macro store pointers to it */
	mstore = TRUE;
	bstore = bp;
	return TRUE;
}

#if	PROC
/*
 * storeproc:
 *	Set up a procedure buffer and flag to store all
 *	executed command lines there
 *
 * int f;		default flag
 * int n;		macro number to use
 */
int storeproc(int f, int n)
{
	struct buffer *bp;	/* pointer to macro buffer */
	int status;	/* return status */
	char bname[NBUFN];	/* name of buffer to use */

	/* a numeric argument means its a numbered macro */
	if (f == TRUE)
		return storemac(f, n);

	/* get the name of the procedure */
	if ((status =
	     mlreply("Procedure name: ", &bname[1], NBUFN - 2)) != TRUE)
		return status;

	/* construct the macro buffer name */
	bname[0] = '*';
	strcat(bname, "*");

	/* set up the new macro buffer */
	if ((bp = bfind(bname, TRUE, BFINVS)) == NULL) {
		mlwrite("Can not create macro");
		return FALSE;
	}

	/* and make sure it is empty */
	bclear(bp);

	/* and set the macro store pointers to it */
	mstore = TRUE;
	bstore = bp;
	return TRUE;
}

/*
 * execproc:
 *	Execute a procedure
 *
 * int f, n;		default flag and numeric arg
 */
int execproc(int f, int n)
{
	struct buffer *bp;	/* ptr to buffer to execute */
	int status;	/* status return */
	char bufn[NBUFN + 2];	/* name of buffer to execute */

	/* find out what buffer the user wants to execute */
	if ((status =
	     mlreply("Execute procedure: ", &bufn[1], NBUFN)) != TRUE)
		return status;

	/* construct the buffer name */
	bufn[0] = '*';
	strcat(bufn, "*");

	/* find the pointer to that buffer */
	if ((bp = bfind(bufn, FALSE, 0)) == NULL) {
		mlwrite("No such procedure");
		return FALSE;
	}

	/* and now execute it as asked */
	while (n-- > 0)
		if ((status = dobuf(bp)) != TRUE)
			return status;
	return TRUE;
}
#endif

/*
 * execbuf:
 *	Execute the contents of a buffer of commands
 *
 * int f, n;		default flag and numeric arg
 */
int execbuf(int f, int n)
{
	struct buffer *bp;	/* ptr to buffer to execute */
	int status;	/* status return */
	char bufn[NSTRING];	/* name of buffer to execute */

	/* find out what buffer the user wants to execute */
	if ((status = mlreply("Execute buffer: ", bufn, NBUFN)) != TRUE)
		return status;

	/* find the pointer to that buffer */
	if ((bp = bfind(bufn, FALSE, 0)) == NULL) {
		mlwrite("No such buffer");
		return FALSE;
	}

	/* and now execute it as asked */
	while (n-- > 0)
		if ((status = dobuf(bp)) != TRUE)
			return status;
	return TRUE;
}

/*
 * dobuf:
 *	execute the contents of the buffer pointed to
 *	by the passed BP
 *
 *	Directives start with a "!" and include:
 *
 *	!endm		End a macro
 *	!if (cond)	conditional execution
 *	!else
 *	!endif
 *	!return		Return (terminating current macro)
 *	!goto <label>	Jump to a label in the current macro
 *	!force		Force macro to continue...even if command fails
 *	!while (cond)	Execute a loop if the condition is true
 *	!endwhile
 *
 *	Line Labels begin with a "*" as the first nonblank char, like:
 *
 *	*LBL01
 *
 * struct buffer *bp;		buffer to execute
 */
int dobuf(struct buffer *bp)
{
	int status;	/* status return */
	struct line *lp;	/* pointer to line to execute */
	struct line *hlp;	/* pointer to line header */
	struct line *glp;	/* line to goto */
	struct line *mp;		/* Macro line storage temp */
	int dirnum;		/* directive index */
	int linlen;		/* length of line to execute */
	int i;			/* index */
	int c;			/* temp character */
	int force;		/* force TRUE result? */
	struct window *wp;		/* ptr to windows to scan */
	struct while_block *whlist;	/* ptr to !WHILE list */
	struct while_block *scanner;	/* ptr during scan */
	struct while_block *whtemp;	/* temporary ptr to a struct while_block */
	char *einit;		/* initial value of eline */
	char *eline;		/* text of line to execute */
	char tkn[NSTRING];	/* buffer to evaluate an expresion in */

#if	DEBUGM
	char *sp;		/* temp for building debug string */
	char *ep;	/* ptr to end of outline */
#endif

	/* clear IF level flags/while ptr */
	execlevel = 0;
	whlist = NULL;
	scanner = NULL;

	/* scan the buffer to execute, building WHILE header blocks */
	hlp = bp->b_linep;
	lp = hlp->l_fp;
	while (lp != hlp) {
		/* scan the current line */
		eline = lp->l_text;
		i = lp->l_used;

		/* trim leading whitespace */
		while (i-- > 0 && (*eline == ' ' || *eline == '\t'))
			++eline;

		/* if theres nothing here, don't bother */
		if (i <= 0)
			goto nxtscan;

		/* if is a while directive, make a block... */
		if (eline[0] == '!' && eline[1] == 'w' && eline[2] == 'h') {
			whtemp = (struct while_block *)malloc(sizeof(struct while_block));
			if (whtemp == NULL) {
			      noram:mlwrite
				    ("%%Out of memory during while scan");
			      failexit:freewhile
				    (scanner);
				freewhile(whlist);
				return FALSE;
			}
			whtemp->w_begin = lp;
			whtemp->w_type = BTWHILE;
			whtemp->w_next = scanner;
			scanner = whtemp;
		}

		/* if is a BREAK directive, make a block... */
		if (eline[0] == '!' && eline[1] == 'b' && eline[2] == 'r') {
			if (scanner == NULL) {
				mlwrite
				    ("%%!BREAK outside of any !WHILE loop");
				goto failexit;
			}
			whtemp = (struct while_block *)malloc(sizeof(struct while_block));
			if (whtemp == NULL)
				goto noram;
			whtemp->w_begin = lp;
			whtemp->w_type = BTBREAK;
			whtemp->w_next = scanner;
			scanner = whtemp;
		}

		/* if it is an endwhile directive, record the spot... */
		if (eline[0] == '!' && strncmp(&eline[1], "endw", 4) == 0) {
			if (scanner == NULL) {
				mlwrite
				    ("%%!ENDWHILE with no preceding !WHILE in '%s'",
				     bp->b_bname);
				goto failexit;
			}
			/* move top records from the scanner list to the
			   whlist until we have moved all BREAK records
			   and one WHILE record */
			do {
				scanner->w_end = lp;
				whtemp = whlist;
				whlist = scanner;
				scanner = scanner->w_next;
				whlist->w_next = whtemp;
			} while (whlist->w_type == BTBREAK);
		}

	      nxtscan:		/* on to the next line */
		lp = lp->l_fp;
	}

	/* while and endwhile should match! */
	if (scanner != NULL) {
		mlwrite("%%!WHILE with no matching !ENDWHILE in '%s'",
			bp->b_bname);
		goto failexit;
	}

	/* let the first command inherit the flags from the last one.. */
	thisflag = lastflag;

	/* starting at the beginning of the buffer */
	hlp = bp->b_linep;
	lp = hlp->l_fp;
	while (lp != hlp) {
		/* allocate eline and copy macro line to it */
		linlen = lp->l_used;
		if ((einit = eline = malloc(linlen + 1)) == NULL) {
			mlwrite("%%Out of Memory during macro execution");
			freewhile(whlist);
			return FALSE;
		}
		strncpy(eline, lp->l_text, linlen);
		eline[linlen] = 0;	/* make sure it ends */

		/* trim leading whitespace */
		while (*eline == ' ' || *eline == '\t')
			++eline;

		/* dump comments and blank lines */
		if (*eline == ';' || *eline == 0)
			goto onward;

#if	DEBUGM
		/* if $debug == TRUE, every line to execute
		   gets echoed and a key needs to be pressed to continue
		   ^G will abort the command */

		if (macbug) {
			strcpy(outline, "<<<");

			/* debug macro name */
			strcat(outline, bp->b_bname);
			strcat(outline, ":");

			/* debug if levels */
			strcat(outline, itoa(execlevel));
			strcat(outline, ":");

			/* and lastly the line */
			strcat(outline, eline);
			strcat(outline, ">>>");

			/* change all '%' to ':' so mlwrite won't expect arguments */
			sp = outline;
			while (*sp)
				if (*sp++ == '%') {
					/* advance to the end */
					ep = --sp;
					while (*ep++);
					/* null terminate the string one out */
					*(ep + 1) = 0;
					/* copy backwards */
					while (ep-- > sp)
						*(ep + 1) = *ep;

					/* and advance sp past the new % */
					sp += 2;
				}

			/* write out the debug line */
			mlforce(outline);
			update(TRUE);

			/* and get the keystroke */
			if ((c = get1key()) == abortc) {
				mlforce("(Macro aborted)");
				freewhile(whlist);
				return FALSE;
			}

			if (c == metac)
				macbug = FALSE;
		}
#endif

		/* Parse directives here.... */
		dirnum = -1;
		if (*eline == '!') {
			/* Find out which directive this is */
			++eline;
			for (dirnum = 0; dirnum < NUMDIRS; dirnum++)
				if (strncmp(eline, dname[dirnum],
					    strlen(dname[dirnum])) == 0)
					break;

			/* and bitch if it's illegal */
			if (dirnum == NUMDIRS) {
				mlwrite("%%Unknown Directive");
				freewhile(whlist);
				return FALSE;
			}

			/* service only the !ENDM macro here */
			if (dirnum == DENDM) {
				mstore = FALSE;
				bstore = NULL;
				goto onward;
			}

			/* restore the original eline.... */
			--eline;
		}

		/* if macro store is on, just salt this away */
		if (mstore) {
			/* allocate the space for the line */
			linlen = strlen(eline);
			if ((mp = lalloc(linlen)) == NULL) {
				mlwrite
				    ("Out of memory while storing macro");
				return FALSE;
			}

			/* copy the text into the new line */
			for (i = 0; i < linlen; ++i)
				lputc(mp, i, eline[i]);

			/* attach the line to the end of the buffer */
			bstore->b_linep->l_bp->l_fp = mp;
			mp->l_bp = bstore->b_linep->l_bp;
			bstore->b_linep->l_bp = mp;
			mp->l_fp = bstore->b_linep;
			goto onward;
		}


		force = FALSE;

		/* dump comments */
		if (*eline == '*')
			goto onward;

		/* now, execute directives */
		if (dirnum != -1) {
			/* skip past the directive */
			while (*eline && *eline != ' ' && *eline != '\t')
				++eline;
			execstr = eline;

			switch (dirnum) {
			case DIF:	/* IF directive */
				/* grab the value of the logical exp */
				if (execlevel == 0) {
					if (macarg(tkn) != TRUE)
						goto eexec;
					if (stol(tkn) == FALSE)
						++execlevel;
				} else
					++execlevel;
				goto onward;

			case DWHILE:	/* WHILE directive */
				/* grab the value of the logical exp */
				if (execlevel == 0) {
					if (macarg(tkn) != TRUE)
						goto eexec;
					if (stol(tkn) == TRUE)
						goto onward;
				}
				/* drop down and act just like !BREAK */

			case DBREAK:	/* BREAK directive */
				if (dirnum == DBREAK && execlevel)
					goto onward;

				/* jump down to the endwhile */
				/* find the right while loop */
				whtemp = whlist;
				while (whtemp) {
					if (whtemp->w_begin == lp)
						break;
					whtemp = whtemp->w_next;
				}

				if (whtemp == NULL) {
					mlwrite
					    ("%%Internal While loop error");
					freewhile(whlist);
					return FALSE;
				}

				/* reset the line pointer back.. */
				lp = whtemp->w_end;
				goto onward;

			case DELSE:	/* ELSE directive */
				if (execlevel == 1)
					--execlevel;
				else if (execlevel == 0)
					++execlevel;
				goto onward;

			case DENDIF:	/* ENDIF directive */
				if (execlevel)
					--execlevel;
				goto onward;

			case DGOTO:	/* GOTO directive */
				/* .....only if we are currently executing */
				if (execlevel == 0) {

					/* grab label to jump to */
					eline =
					    token(eline, golabel, NPAT);
					linlen = strlen(golabel);
					glp = hlp->l_fp;
					while (glp != hlp) {
						if (*glp->l_text == '*' &&
						    (strncmp
						     (&glp->l_text[1],
						      golabel,
						      linlen) == 0)) {
							lp = glp;
							goto onward;
						}
						glp = glp->l_fp;
					}
					mlwrite("%%No such label");
					freewhile(whlist);
					return FALSE;
				}
				goto onward;

			case DRETURN:	/* RETURN directive */
				if (execlevel == 0)
					goto eexec;
				goto onward;

			case DENDWHILE:	/* ENDWHILE directive */
				if (execlevel) {
					--execlevel;
					goto onward;
				} else {
					/* find the right while loop */
					whtemp = whlist;
					while (whtemp) {
						if (whtemp->w_type ==
						    BTWHILE
						    && whtemp->w_end == lp)
							break;
						whtemp = whtemp->w_next;
					}

					if (whtemp == NULL) {
						mlwrite
						    ("%%Internal While loop error");
						freewhile(whlist);
						return FALSE;
					}

					/* reset the line pointer back.. */
					lp = whtemp->w_begin->l_bp;
					goto onward;
				}

			case DFORCE:	/* FORCE directive */
				force = TRUE;

			}
		}

		/* execute the statement */
		status = docmd(eline);
		if (force)	/* force the status */
			status = TRUE;

		/* check for a command error */
		if (status != TRUE) {
			/* look if buffer is showing */
			wp = wheadp;
			while (wp != NULL) {
				if (wp->w_bufp == bp) {
					/* and point it */
					wp->w_dotp = lp;
					wp->w_doto = 0;
					wp->w_flag |= WFHARD;
				}
				wp = wp->w_wndp;
			}
			/* in any case set the buffer . */
			bp->b_dotp = lp;
			bp->b_doto = 0;
			free(einit);
			execlevel = 0;
			freewhile(whlist);
			return status;
		}

	      onward:		/* on to the next line */
		free(einit);
		lp = lp->l_fp;
	}

      eexec:			/* exit the current function */
	execlevel = 0;
	freewhile(whlist);
	return TRUE;
}

/*
 * free a list of while block pointers
 *
 * struct while_block *wp;		head of structure to free
 */
void freewhile(struct while_block *wp)
{
	if (wp == NULL)
		return;
	if (wp->w_next)
		freewhile(wp->w_next);
	free(wp);
}

/*
 * execute a series of commands in a file
 *
 * int f, n;		default flag and numeric arg to pass on to file
 */
int execfile(int f, int n)
{
	int status;	/* return status of name query */
	char fname[NSTRING];	/* name of file to execute */
	char *fspec;		/* full file spec */

	if ((status =
	     mlreply("File to execute: ", fname, NSTRING - 1)) != TRUE)
		return status;

#if	1
	/* look up the path for the file */
	fspec = flook(fname, FALSE);	/* used to by TRUE, P.K. */

	/* if it isn't around */
	if (fspec == NULL)
		return FALSE;

#endif
	/* otherwise, execute it */
	while (n-- > 0)
		if ((status = dofile(fspec)) != TRUE)
			return status;

	return TRUE;
}

/*
 * dofile:
 *	yank a file into a buffer and execute it
 *	if there are no errors, delete the buffer on exit
 *
 * char *fname;		file name to execute
 */
int dofile(char *fname)
{
	struct buffer *bp;	/* buffer to place file to exeute */
	struct buffer *cb;	/* temp to hold current buf while we read */
	int status;	/* results of various calls */
	char bname[NBUFN];	/* name of buffer */

	makename(bname, fname);	/* derive the name of the buffer */
	unqname(bname);		/* make sure we don't stomp things */
	if ((bp = bfind(bname, TRUE, 0)) == NULL)	/* get the needed buffer */
		return FALSE;

	bp->b_mode = MDVIEW;	/* mark the buffer as read only */
	cb = curbp;		/* save the old buffer */
	curbp = bp;		/* make this one current */
	/* and try to read in the file to execute */
	if ((status = readin(fname, FALSE)) != TRUE) {
		curbp = cb;	/* restore the current buffer */
		return status;
	}

	/* go execute it! */
	curbp = cb;		/* restore the current buffer */
	if ((status = dobuf(bp)) != TRUE)
		return status;

	/* if not displayed, remove the now unneeded buffer and exit */
	if (bp->b_nwnd == 0)
		zotbuf(bp);
	return TRUE;
}

/*
 * cbuf:
 *	Execute the contents of a numbered buffer
 *
 * int f, n;		default flag and numeric arg
 * int bufnum;		number of buffer to execute
 */
int cbuf(int f, int n, int bufnum)
{
	struct buffer *bp;	/* ptr to buffer to execute */
	int status;	/* status return */
	static char bufname[] = "*Macro xx*";

	/* make the buffer name */
	bufname[7] = '0' + (bufnum / 10);
	bufname[8] = '0' + (bufnum % 10);

	/* find the pointer to that buffer */
	if ((bp = bfind(bufname, FALSE, 0)) == NULL) {
		mlwrite("Macro not defined");
		return FALSE;
	}

	/* and now execute it as asked */
	while (n-- > 0)
		if ((status = dobuf(bp)) != TRUE)
			return status;
	return TRUE;
}

int cbuf1(int f, int n)
{
	return cbuf(f, n, 1);
}

int cbuf2(int f, int n)
{
	return cbuf(f, n, 2);
}

int cbuf3(int f, int n)
{
	return cbuf(f, n, 3);
}

int cbuf4(int f, int n)
{
	return cbuf(f, n, 4);
}

int cbuf5(int f, int n)
{
	return cbuf(f, n, 5);
}

int cbuf6(int f, int n)
{
	return cbuf(f, n, 6);
}

int cbuf7(int f, int n)
{
	return cbuf(f, n, 7);
}

int cbuf8(int f, int n)
{
	return cbuf(f, n, 8);
}

int cbuf9(int f, int n)
{
	return cbuf(f, n, 9);
}

int cbuf10(int f, int n)
{
	return cbuf(f, n, 10);
}

int cbuf11(int f, int n)
{
	return cbuf(f, n, 11);
}

int cbuf12(int f, int n)
{
	return cbuf(f, n, 12);
}

int cbuf13(int f, int n)
{
	return cbuf(f, n, 13);
}

int cbuf14(int f, int n)
{
	return cbuf(f, n, 14);
}

int cbuf15(int f, int n)
{
	return cbuf(f, n, 15);
}

int cbuf16(int f, int n)
{
	return cbuf(f, n, 16);
}

int cbuf17(int f, int n)
{
	return cbuf(f, n, 17);
}

int cbuf18(int f, int n)
{
	return cbuf(f, n, 18);
}

int cbuf19(int f, int n)
{
	return cbuf(f, n, 19);
}

int cbuf20(int f, int n)
{
	return cbuf(f, n, 20);
}

int cbuf21(int f, int n)
{
	return cbuf(f, n, 21);
}

int cbuf22(int f, int n)
{
	return cbuf(f, n, 22);
}

int cbuf23(int f, int n)
{
	return cbuf(f, n, 23);
}

int cbuf24(int f, int n)
{
	return cbuf(f, n, 24);
}

int cbuf25(int f, int n)
{
	return cbuf(f, n, 25);
}

int cbuf26(int f, int n)
{
	return cbuf(f, n, 26);
}

int cbuf27(int f, int n)
{
	return cbuf(f, n, 27);
}

int cbuf28(int f, int n)
{
	return cbuf(f, n, 28);
}

int cbuf29(int f, int n)
{
	return cbuf(f, n, 29);
}

int cbuf30(int f, int n)
{
	return cbuf(f, n, 30);
}

int cbuf31(int f, int n)
{
	return cbuf(f, n, 31);
}

int cbuf32(int f, int n)
{
	return cbuf(f, n, 32);
}

int cbuf33(int f, int n)
{
	return cbuf(f, n, 33);
}

int cbuf34(int f, int n)
{
	return cbuf(f, n, 34);
}

int cbuf35(int f, int n)
{
	return cbuf(f, n, 35);
}

int cbuf36(int f, int n)
{
	return cbuf(f, n, 36);
}

int cbuf37(int f, int n)
{
	return cbuf(f, n, 37);
}

int cbuf38(int f, int n)
{
	return cbuf(f, n, 38);
}

int cbuf39(int f, int n)
{
	return cbuf(f, n, 39);
}

int cbuf40(int f, int n)
{
	return cbuf(f, n, 40);
}


/* ----- file.c ----- */
/*	file.c
 *
 *	The routines in this file handle the reading, writing
 *	and lookup of disk files.  All of details about the
 *	reading and writing of the disk are in "fileio.c".
 *
 *	modified by Petri Kutvonen
 */
/* system header already included */
/* system header already included */
/* #include "estruct.h" - amalgamated */
/* #include "edef.h" - amalgamated */
/* #include "efunc.h" - amalgamated */
/* #include "line.h" - amalgamated */
/* #include "util.h" - amalgamated */

#if defined(PKCODE)
/* Max number of lines from one file. */
#define	MAXNLINE 10000000
#endif

/*
 * Read a file into the current
 * buffer. This is really easy; all you do it
 * find the name of the file, and call the standard
 * "read a file into the current buffer" code.
 * Bound to "C-X C-R".
 */
int fileread(int f, int n)
{
	int s;
	char fname[NFILEN];

	if (restflag)		/* don't allow this command if restricted */
		return resterr();
	if ((s = mlreply("Read file: ", fname, NFILEN)) != TRUE)
		return s;
	return readin(fname, TRUE);
}

/*
 * Insert a file into the current
 * buffer. This is really easy; all you do it
 * find the name of the file, and call the standard
 * "insert a file into the current buffer" code.
 * Bound to "C-X C-I".
 */
int insfile(int f, int n)
{
	int s;
	char fname[NFILEN];

	if (restflag)		/* don't allow this command if restricted */
		return resterr();
	if (curbp->b_mode & MDVIEW)	/* don't allow this command if      */
		return rdonly();	/* we are in read only mode     */
	if ((s = mlreply("Insert file: ", fname, NFILEN)) != TRUE)
		return s;
	if ((s = ifile(fname)) != TRUE)
		return s;
	return reposition(TRUE, -1);
}

/*
 * Select a file for editing.
 * Look around to see if you can find the
 * fine in another buffer; if you can find it
 * just switch to the buffer. If you cannot find
 * the file, create a new buffer, read in the
 * text, and switch to the new buffer.
 * Bound to C-X C-F.
 */
int filefind(int f, int n)
{
	char fname[NFILEN];	/* file user wishes to find */
	int s;		/* status return */

	if (restflag)		/* don't allow this command if restricted */
		return resterr();
	if ((s = mlreply("Find file: ", fname, NFILEN)) != TRUE)
		return s;
	return getfile(fname, TRUE);
}

int viewfile(int f, int n)
{				/* visit a file in VIEW mode */
	char fname[NFILEN];	/* file user wishes to find */
	int s;		/* status return */
	struct window *wp;	/* scan for windows that need updating */

	if (restflag)		/* don't allow this command if restricted */
		return resterr();
	if ((s = mlreply("View file: ", fname, NFILEN)) != TRUE)
		return s;
	s = getfile(fname, FALSE);
	if (s) {		/* if we succeed, put it in view mode */
		curwp->w_bufp->b_mode |= MDVIEW;

		/* scan through and update mode lines of all windows */
		wp = wheadp;
		while (wp != NULL) {
			wp->w_flag |= WFMODE;
			wp = wp->w_wndp;
		}
	}
	return s;
}

#if	CRYPT
static int resetkey(void)
{				/* reset the encryption key if needed */
	int s;		/* return status */

	/* turn off the encryption flag */
	cryptflag = FALSE;

	/* if we are in crypt mode */
	if (curbp->b_mode & MDCRYPT) {
		if (curbp->b_key[0] == 0) {
			s = set_encryption_key(FALSE, 0);
			if (s != TRUE)
				return s;
		}

		/* let others know... */
		cryptflag = TRUE;

		/* and set up the key to be used! */
		/* de-encrypt it */
		myencrypt((char *) NULL, 0);
		myencrypt(curbp->b_key, strlen(curbp->b_key));

		/* re-encrypt it...seeding it to start */
		myencrypt((char *) NULL, 0);
		myencrypt(curbp->b_key, strlen(curbp->b_key));
	}

	return TRUE;
}
#endif

/*
 * getfile()
 *
 * char fname[];	file name to find
 * int lockfl;		check the file for locks?
 */
int getfile(char *fname, int lockfl)
{
	struct buffer *bp;
	struct line *lp;
	int i;
	int s;
	char bname[NBUFN];	/* buffer name to put file */

#if	MSDOS
	mklower(fname);		/* msdos isn't case sensitive */
#endif
	for (bp = bheadp; bp != NULL; bp = bp->b_bufp) {
		if ((bp->b_flag & BFINVS) == 0
		    && strcmp(bp->b_fname, fname) == 0) {
			swbuffer(bp);
			lp = curwp->w_dotp;
			i = curwp->w_ntrows / 2;
			while (i-- && lback(lp) != curbp->b_linep)
				lp = lback(lp);
			curwp->w_linep = lp;
			curwp->w_flag |= WFMODE | WFHARD;
			cknewwindow();
			mlwrite("(Old buffer)");
			return TRUE;
		}
	}
	makename(bname, fname);	/* New buffer name.     */
	while ((bp = bfind(bname, FALSE, 0)) != NULL) {
		/* old buffer name conflict code */
		s = mlreply("Buffer name: ", bname, NBUFN);
		if (s == ABORT)	/* ^G to just quit      */
			return s;
		if (s == FALSE) {	/* CR to clobber it     */
			makename(bname, fname);
			break;
		}
	}
	if (bp == NULL && (bp = bfind(bname, TRUE, 0)) == NULL) {
		mlwrite("Cannot create buffer");
		return FALSE;
	}
	if (--curbp->b_nwnd == 0) {	/* Undisplay.           */
		curbp->b_dotp = curwp->w_dotp;
		curbp->b_doto = curwp->w_doto;
		curbp->b_markp = curwp->w_markp;
		curbp->b_marko = curwp->w_marko;
	}
	curbp = bp;		/* Switch to it.        */
	curwp->w_bufp = bp;
	curbp->b_nwnd++;
	s = readin(fname, lockfl);	/* Read it in.          */
	cknewwindow();
	return s;
}

/*
 * Read file "fname" into the current buffer, blowing away any text
 * found there.  Called by both the read and find commands.  Return
 * the final status of the read.  Also called by the mainline, to
 * read in a file specified on the command line as an argument.
 * The command bound to M-FNR is called after the buffer is set up
 * and before it is read.
 *
 * char fname[];	name of file to read
 * int lockfl;		check for file locks?
 */
int readin(char *fname, int lockfl)
{
	struct line *lp1;
	struct line *lp2;
	int i;
	struct window *wp;
	struct buffer *bp;
	int s;
	int nbytes;
	int nline;
	char mesg[NSTRING];

#if	(FILOCK && BSD) || SVR4
	if (lockfl && lockchk(fname) == ABORT)
#if PKCODE
	{
		s = FIOFNF;
		bp = curbp;
		strcpy(bp->b_fname, "");
		goto out;
	}
#else
		return ABORT;
#endif
#endif
#if	CRYPT
	s = resetkey();
	if (s != TRUE)
		return s;
#endif
	bp = curbp;		/* Cheap.               */
	if ((s = bclear(bp)) != TRUE)	/* Might be old.        */
		return s;
	bp->b_flag &= ~(BFINVS | BFCHG);
	mystrscpy(bp->b_fname, fname, NFILEN);

	/* let a user macro get hold of things...if he wants */
	execute(META | SPEC | 'R', FALSE, 1);

	if ((s = ffropen(fname)) == FIOERR)	/* Hard file open.      */
		goto out;

	if (s == FIOFNF) {	/* File not found.      */
		mlwrite("(New file)");
		goto out;
	}

	/* read the file in */
	mlwrite("(Reading file)");
	nline = 0;
	while ((s = ffgetline()) == FIOSUC) {
		nbytes = strlen(fline);
		if ((lp1 = lalloc(nbytes)) == NULL) {
			s = FIOMEM;	/* Keep message on the  */
			break;	/* display.             */
		}
#if	PKCODE
		if (nline > MAXNLINE) {
			s = FIOMEM;
			break;
		}
#endif
		lp2 = lback(curbp->b_linep);
		lp2->l_fp = lp1;
		lp1->l_fp = curbp->b_linep;
		lp1->l_bp = lp2;
		curbp->b_linep->l_bp = lp1;
		for (i = 0; i < nbytes; ++i)
			lputc(lp1, i, fline[i]);
		++nline;
	}
	ffclose();		/* Ignore errors.       */
	strcpy(mesg, "(");
	if (s == FIOERR) {
		strcat(mesg, "I/O ERROR, ");
		curbp->b_flag |= BFTRUNC;
	}
	if (s == FIOMEM) {
		strcat(mesg, "OUT OF MEMORY, ");
		curbp->b_flag |= BFTRUNC;
	}
	sprintf(&mesg[strlen(mesg)], "Read %d line", nline);
	if (nline != 1)
		strcat(mesg, "s");
	strcat(mesg, ")");
	mlwrite(mesg);

      out:
	for (wp = wheadp; wp != NULL; wp = wp->w_wndp) {
		if (wp->w_bufp == curbp) {
			wp->w_linep = lforw(curbp->b_linep);
			wp->w_dotp = lforw(curbp->b_linep);
			wp->w_doto = 0;
			wp->w_markp = NULL;
			wp->w_marko = 0;
			wp->w_flag |= WFMODE | WFHARD;
		}
	}
	if (s == FIOERR || s == FIOFNF)	/* False if error.      */
		return FALSE;
	return TRUE;
}

/*
 * Take a file name, and from it
 * fabricate a buffer name. This routine knows
 * about the syntax of file names on the target system.
 * I suppose that this information could be put in
 * a better place than a line of code.
 */
void makename(char *bname, char *fname)
{
	char *cp1;
	char *cp2;

	cp1 = &fname[0];
	while (*cp1 != 0)
		++cp1;

#if     VMS
#if	PKCODE
	while (cp1 != &fname[0] && cp1[-1] != ':' && cp1[-1] != ']'
	       && cp1[-1] != '>')
#else
	while (cp1 != &fname[0] && cp1[-1] != ':' && cp1[-1] != ']')
#endif
		--cp1;
#endif
#if     MSDOS
	while (cp1 != &fname[0] && cp1[-1] != ':' && cp1[-1] != '\\'
	       && cp1[-1] != '/')
		--cp1;
#endif
#if     V7 | USG | BSD
	while (cp1 != &fname[0] && cp1[-1] != '/')
		--cp1;
#endif
	cp2 = &bname[0];
	while (cp2 != &bname[NBUFN - 1] && *cp1 != 0 && *cp1 != ';')
		*cp2++ = *cp1++;
	*cp2 = 0;
}

/*
 * make sure a buffer name is unique
 *
 * char *name;		name to check on
 */
void unqname(char *name)
{
	char *sp;

	/* check to see if it is in the buffer list */
	while (bfind(name, 0, FALSE) != NULL) {

		/* go to the end of the name */
		sp = name;
		while (*sp)
			++sp;
		if (sp == name || (*(sp - 1) < '0' || *(sp - 1) > '8')) {
			*sp++ = '0';
			*sp = 0;
		} else
			*(--sp) += 1;
	}
}

/*
 * Ask for a file name, and write the
 * contents of the current buffer to that file.
 * Update the remembered file name and clear the
 * buffer changed flag. This handling of file names
 * is different from the earlier versions, and
 * is more compatable with Gosling EMACS than
 * with ITS EMACS. Bound to "C-X C-W".
 */
int filewrite(int f, int n)
{
	struct window *wp;
	int s;
	char fname[NFILEN];

	if (restflag)		/* don't allow this command if restricted */
		return resterr();
	if ((s = mlreply("Write file: ", fname, NFILEN)) != TRUE)
		return s;
	if ((s = writeout(fname)) == TRUE) {
		strcpy(curbp->b_fname, fname);
		curbp->b_flag &= ~BFCHG;
		wp = wheadp;	/* Update mode lines.   */
		while (wp != NULL) {
			if (wp->w_bufp == curbp)
				wp->w_flag |= WFMODE;
			wp = wp->w_wndp;
		}
	}
	return s;
}

/*
 * Save the contents of the current
 * buffer in its associatd file. No nothing
 * if nothing has changed (this may be a bug, not a
 * feature). Error if there is no remembered file
 * name for the buffer. Bound to "C-X C-S". May
 * get called by "C-Z".
 */
int filesave(int f, int n)
{
	struct window *wp;
	int s;

	if (curbp->b_mode & MDVIEW)	/* don't allow this command if      */
		return rdonly();	/* we are in read only mode     */
	if ((curbp->b_flag & BFCHG) == 0)	/* Return, no changes.  */
		return TRUE;
	if (curbp->b_fname[0] == 0) {	/* Must have a name.    */
		mlwrite("No file name");
		return FALSE;
	}

	/* complain about truncated files */
	if ((curbp->b_flag & BFTRUNC) != 0) {
		if (mlyesno("Truncated file ... write it out") == FALSE) {
			mlwrite("(Aborted)");
			return FALSE;
		}
	}

	if ((s = writeout(curbp->b_fname)) == TRUE) {
		curbp->b_flag &= ~BFCHG;
		wp = wheadp;	/* Update mode lines.   */
		while (wp != NULL) {
			if (wp->w_bufp == curbp)
				wp->w_flag |= WFMODE;
			wp = wp->w_wndp;
		}
	}
	return s;
}

/*
 * This function performs the details of file
 * writing. Uses the file management routines in the
 * "fileio.c" package. The number of lines written is
 * displayed. Sadly, it looks inside a struct line; provide
 * a macro for this. Most of the grief is error
 * checking of some sort.
 */
int writeout(char *fn)
{
	int s;
	struct line *lp;
	int nline;

#if	CRYPT
	s = resetkey();
	if (s != TRUE)
		return s;
#endif

	if ((s = ffwopen(fn)) != FIOSUC) {	/* Open writes message. */
		return FALSE;
	}
	mlwrite("(Writing...)");	/* tell us were writing */
	lp = lforw(curbp->b_linep);	/* First line.          */
	nline = 0;		/* Number of lines.     */
	while (lp != curbp->b_linep) {
		if ((s = ffputline(&lp->l_text[0], llength(lp))) != FIOSUC)
			break;
		++nline;
		lp = lforw(lp);
	}
	if (s == FIOSUC) {	/* No write error.      */
		s = ffclose();
		if (s == FIOSUC) {	/* No close error.      */
			if (nline == 1)
				mlwrite("(Wrote 1 line)");
			else
				mlwrite("(Wrote %d lines)", nline);
		}
	} else			/* Ignore close error   */
		ffclose();	/* if a write error.    */
	if (s != FIOSUC)	/* Some sort of error.  */
		return FALSE;
	return TRUE;
}

/*
 * The command allows the user
 * to modify the file name associated with
 * the current buffer. It is like the "f" command
 * in UNIX "ed". The operation is simple; just zap
 * the name in the buffer structure, and mark the windows
 * as needing an update. You can type a blank line at the
 * prompt if you wish.
 */
int filename(int f, int n)
{
	struct window *wp;
	int s;
	char fname[NFILEN];

	if (restflag)		/* don't allow this command if restricted */
		return resterr();
	if ((s = mlreply("Name: ", fname, NFILEN)) == ABORT)
		return s;
	if (s == FALSE)
		strcpy(curbp->b_fname, "");
	else
		strcpy(curbp->b_fname, fname);
	wp = wheadp;		/* Update mode lines.   */
	while (wp != NULL) {
		if (wp->w_bufp == curbp)
			wp->w_flag |= WFMODE;
		wp = wp->w_wndp;
	}
	curbp->b_mode &= ~MDVIEW;	/* no longer read only mode */
	return TRUE;
}

/*
 * Insert file "fname" into the current
 * buffer, Called by insert file command. Return the final
 * status of the read.
 */
int ifile(char *fname)
{
	struct line *lp0;
	struct line *lp1;
	struct line *lp2;
	int i;
	struct buffer *bp;
	int s;
	int nbytes;
	int nline;
	char mesg[NSTRING];

	bp = curbp;		/* Cheap.               */
	bp->b_flag |= BFCHG;	/* we have changed      */
	bp->b_flag &= ~BFINVS;	/* and are not temporary */
	if ((s = ffropen(fname)) == FIOERR)	/* Hard file open.      */
		goto out;
	if (s == FIOFNF) {	/* File not found.      */
		mlwrite("(No such file)");
		return FALSE;
	}
	mlwrite("(Inserting file)");

#if	CRYPT
	s = resetkey();
	if (s != TRUE)
		return s;
#endif
	/* back up a line and save the mark here */
	curwp->w_dotp = lback(curwp->w_dotp);
	curwp->w_doto = 0;
	curwp->w_markp = curwp->w_dotp;
	curwp->w_marko = 0;

	nline = 0;
	while ((s = ffgetline()) == FIOSUC) {
		nbytes = strlen(fline);
		if ((lp1 = lalloc(nbytes)) == NULL) {
			s = FIOMEM;	/* Keep message on the  */
			break;	/* display.             */
		}
		lp0 = curwp->w_dotp;	/* line previous to insert */
		lp2 = lp0->l_fp;	/* line after insert */

		/* re-link new line between lp0 and lp2 */
		lp2->l_bp = lp1;
		lp0->l_fp = lp1;
		lp1->l_bp = lp0;
		lp1->l_fp = lp2;

		/* and advance and write out the current line */
		curwp->w_dotp = lp1;
		for (i = 0; i < nbytes; ++i)
			lputc(lp1, i, fline[i]);
		++nline;
	}
	ffclose();		/* Ignore errors.       */
	curwp->w_markp = lforw(curwp->w_markp);
	strcpy(mesg, "(");
	if (s == FIOERR) {
		strcat(mesg, "I/O ERROR, ");
		curbp->b_flag |= BFTRUNC;
	}
	if (s == FIOMEM) {
		strcat(mesg, "OUT OF MEMORY, ");
		curbp->b_flag |= BFTRUNC;
	}
	sprintf(&mesg[strlen(mesg)], "Inserted %d line", nline);
	if (nline > 1)
		strcat(mesg, "s");
	strcat(mesg, ")");
	mlwrite(mesg);

      out:
	/* advance to the next line and mark the window for changes */
	curwp->w_dotp = lforw(curwp->w_dotp);
	curwp->w_flag |= WFHARD | WFMODE;

	/* copy window parameters back to the buffer structure */
	curbp->b_dotp = curwp->w_dotp;
	curbp->b_doto = curwp->w_doto;
	curbp->b_markp = curwp->w_markp;
	curbp->b_marko = curwp->w_marko;

	if (s == FIOERR)	/* False if error.      */
		return FALSE;
	return TRUE;
}


/* ----- fileio.c ----- */
/*	FILEIO.C
 *
 * The routines in this file read and write ASCII files from the disk. All of
 * the knowledge about files are here.
 *
 *	modified by Petri Kutvonen
 */
/* system header already included */
/* #include "estruct.h" - amalgamated */
/* #include "edef.h" - amalgamated */
/* #include "efunc.h" - amalgamated */

static FILE *ffp;			/* File pointer, all functions. */
static int eofflag;			/* end-of-file flag */

/*
 * Open a file for reading.
 */
int ffropen(char *fn)
{
	if ((ffp = fopen(fn, "r")) == NULL)
		return FIOFNF;
	eofflag = FALSE;
	return FIOSUC;
}

/*
 * Open a file for writing. Return TRUE if all is well, and FALSE on error
 * (cannot create).
 */
int ffwopen(char *fn)
{
#if     VMS
	int fd;

	if ((fd = creat(fn, 0666, "rfm=var", "rat=cr")) < 0
	    || (ffp = fdopen(fd, "w")) == NULL) {
#else
	if ((ffp = fopen(fn, "w")) == NULL) {
#endif
		mlwrite("Cannot open file for writing");
		return FIOERR;
	}
	return FIOSUC;
}

/*
 * Close a file. Should look at the status in all systems.
 */
int ffclose(void)
{
	/* free this since we do not need it anymore */
	if (fline) {
		free(fline);
		fline = NULL;
	}
	eofflag = FALSE;

#if	MSDOS & CTRLZ
	fputc(26, ffp);		/* add a ^Z at the end of the file */
#endif

#if     V7 | USG | BSD | (MSDOS & (MSC | TURBO))
	if (fclose(ffp) != FALSE) {
		mlwrite("Error closing file");
		return FIOERR;
	}
	return FIOSUC;
#else
	fclose(ffp);
	return FIOSUC;
#endif
}

/*
 * Write a line to the already opened file. The "buf" points to the buffer,
 * and the "nbuf" is its length, less the free newline. Return the status.
 * Check only at the newline.
 */
int ffputline(char *buf, int nbuf)
{
	int i;
#if	CRYPT
	char c;			/* character to translate */

	if (cryptflag) {
		for (i = 0; i < nbuf; ++i) {
			c = buf[i] & 0xff;
			myencrypt(&c, 1);
			fputc(c, ffp);
		}
	} else
		for (i = 0; i < nbuf; ++i)
			fputc(buf[i] & 0xFF, ffp);
#else
	for (i = 0; i < nbuf; ++i)
		fputc(buf[i] & 0xFF, ffp);
#endif

	fputc('\n', ffp);

	if (ferror(ffp)) {
		mlwrite("Write I/O error");
		return FIOERR;
	}

	return FIOSUC;
}

/*
 * Read a line from a file, and store the bytes in the supplied buffer. The
 * "nbuf" is the length of the buffer. Complain about long lines and lines
 * at the end of the file that don't have a newline present. Check for I/O
 * errors too. Return status.
 */
int ffgetline(void)
{
	int c;		/* current character read */
	int i;		/* current index into fline */
	char *tmpline;	/* temp storage for expanding line */

	/* if we are at the end...return it */
	if (eofflag)
		return FIOEOF;

	/* dump fline if it ended up too big */
	if (flen > NSTRING) {
		free(fline);
		fline = NULL;
	}

	/* if we don't have an fline, allocate one */
	if (fline == NULL)
		if ((fline = malloc(flen = NSTRING)) == NULL)
			return FIOMEM;

	/* read the line in */
#if	PKCODE
	if (!nullflag) {
		if (fgets(fline, NSTRING, ffp) == (char *) NULL) {	/* EOF ? */
			i = 0;
			c = EOF;
		} else {
			i = strlen(fline);
			c = 0;
			if (i > 0) {
				c = fline[i - 1];
				i--;
			}
		}
	} else {
		i = 0;
		c = fgetc(ffp);
	}
	while (c != EOF && c != '\n') {
#else
	i = 0;
	while ((c = fgetc(ffp)) != EOF && c != '\n') {
#endif
#if	PKCODE
		if (c) {
#endif
			fline[i++] = c;
			/* if it's longer, get more room */
			if (i >= flen) {
				if ((tmpline =
				     malloc(flen + NSTRING)) == NULL)
					return FIOMEM;
				strncpy(tmpline, fline, flen);
				flen += NSTRING;
				free(fline);
				fline = tmpline;
			}
#if	PKCODE
		}
		c = fgetc(ffp);
#endif
	}

	/* test for any errors that may have occured */
	if (c == EOF) {
		if (ferror(ffp)) {
			mlwrite("File read error");
			return FIOERR;
		}

		if (i != 0)
			eofflag = TRUE;
		else
			return FIOEOF;
	}

	/* terminate and decrypt the string */
	fline[i] = 0;
#if	CRYPT
	if (cryptflag)
		myencrypt(fline, strlen(fline));
#endif
	return FIOSUC;
}

/*
 * does <fname> exist on disk?
 *
 * char *fname;		file to check for existance
 */
int fexist(char *fname)
{
	FILE *fp;

	/* try to open the file for reading */
	fp = fopen(fname, "r");

	/* if it fails, just return false! */
	if (fp == NULL)
		return FALSE;

	/* otherwise, close it and report true */
	fclose(fp);
	return TRUE;
}


/* ----- input.c ----- */
/*	input.c
 *
 *	Various input routines
 *
 *	written by Daniel Lawrence 5/9/86
 *	modified by Petri Kutvonen
 */
/* system header already included */
/* system header already included */
/* #include "estruct.h" - amalgamated */
/* #include "edef.h" - amalgamated */
/* #include "efunc.h" - amalgamated */
/* #include "wrapper.h" - amalgamated */

#if	PKCODE
#if     MSDOS && TURBO
#include	<dir.h>
#endif
#endif

#if	PKCODE && (UNIX || (MSDOS && TURBO))
#define	COMPLC	1
#else
#define COMPLC	0
#endif

/*
 * Ask a yes or no question in the message line. Return either TRUE, FALSE, or
 * ABORT. The ABORT status is returned if the user bumps out of the question
 * with a ^G. Used any time a confirmation is required.
 */
int mlyesno(char *prompt)
{
	char c;			/* input character */
	char buf[NPAT];		/* prompt to user */

	for (;;) {
		/* build and prompt the user */
		strcpy(buf, prompt);
		strcat(buf, " (y/n)? ");
		mlwrite(buf);

		/* get the responce */
		c = tgetc();

		if (c == ectoc(abortc))	/* Bail out! */
			return ABORT;

		if (c == 'y' || c == 'Y')
			return TRUE;

		if (c == 'n' || c == 'N')
			return FALSE;
	}
}

/*
 * Write a prompt into the message line, then read back a response. Keep
 * track of the physical position of the cursor. If we are in a keyboard
 * macro throw the prompt away, and return the remembered response. This
 * lets macros run at full speed. The reply is always terminated by a carriage
 * return. Handle erase, kill, and abort keys.
 */

int mlreply(char *prompt, char *buf, int nbuf)
{
	return nextarg(prompt, buf, nbuf, ctoec('\n'));
}

int mlreplyt(char *prompt, char *buf, int nbuf, int eolchar)
{
	return nextarg(prompt, buf, nbuf, eolchar);
}

/*
 * ectoc:
 *	expanded character to character
 *	collapse the CONTROL and SPEC flags back into an ascii code
 */
int ectoc(int c)
{
	if (c & CONTROL)
		c = c & ~(CONTROL | 0x40);
	if (c & SPEC)
		c = c & 255;
	return c;
}

/*
 * ctoec:
 *	character to extended character
 *	pull out the CONTROL and SPEC prefixes (if possible)
 */
int ctoec(int c)
{
	if (c >= 0x00 && c <= 0x1F)
		c = CONTROL | (c + '@');
	return c;
}

/*
 * get a command name from the command line. Command completion means
 * that pressing a <SPACE> will attempt to complete an unfinished command
 * name if it is unique.
 */
fn_t getname(void)
{
	int cpos;	/* current column on screen output */
	int c;
	char *sp;	/* pointer to string for output */
	struct name_bind *ffp;	/* first ptr to entry in name binding table */
	struct name_bind *cffp;	/* current ptr to entry in name binding table */
	struct name_bind *lffp;	/* last ptr to entry in name binding table */
	char buf[NSTRING];	/* buffer to hold tentative command name */

	/* starting at the beginning of the string buffer */
	cpos = 0;

	/* if we are executing a command line get the next arg and match it */
	if (clexec) {
		if (macarg(buf) != TRUE)
			return NULL;
		return fncmatch(&buf[0]);
	}

	/* build a name string from the keyboard */
	while (TRUE) {
		c = tgetc();

		/* if we are at the end, just match it */
		if (c == 0x0d) {
			buf[cpos] = 0;

			/* and match it off */
			return fncmatch(&buf[0]);

		} else if (c == ectoc(abortc)) {	/* Bell, abort */
			ctrlg(FALSE, 0);
			TTflush();
			return NULL;

		} else if (c == 0x7F || c == 0x08) {	/* rubout/erase */
			if (cpos != 0) {
				TTputc('\b');
				TTputc(' ');
				TTputc('\b');
				--ttcol;
				--cpos;
				TTflush();
			}

		} else if (c == 0x15) {	/* C-U, kill */
			while (cpos != 0) {
				TTputc('\b');
				TTputc(' ');
				TTputc('\b');
				--cpos;
				--ttcol;
			}

			TTflush();

		} else if (c == ' ' || c == 0x1b || c == 0x09) {
/* <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< */
			/* attempt a completion */
			buf[cpos] = 0;	/* terminate it for us */
			ffp = &names[0];	/* scan for matches */
			while (ffp->n_func != NULL) {
				if (strncmp(buf, ffp->n_name, strlen(buf))
				    == 0) {
					/* a possible match! More than one? */
					if ((ffp + 1)->n_func == NULL ||
					    (strncmp
					     (buf, (ffp + 1)->n_name,
					      strlen(buf)) != 0)) {
						/* no...we match, print it */
						sp = ffp->n_name + cpos;
						while (*sp)
							TTputc(*sp++);
						TTflush();
						return ffp->n_func;
					} else {
/* << << << << << << << << << << << << << << << << << */
						/* try for a partial match against the list */

						/* first scan down until we no longer match the current input */
						lffp = (ffp + 1);
						while ((lffp +
							1)->n_func !=
						       NULL) {
							if (strncmp
							    (buf,
							     (lffp +
							      1)->n_name,
							     strlen(buf))
							    != 0)
								break;
							++lffp;
						}

						/* and now, attempt to partial complete the string, char at a time */
						while (TRUE) {
							/* add the next char in */
							buf[cpos] =
							    ffp->
							    n_name[cpos];

							/* scan through the candidates */
							cffp = ffp + 1;
							while (cffp <=
							       lffp) {
								if (cffp->
								    n_name
								    [cpos]
								    !=
								    buf
								    [cpos])
									goto onward;
								++cffp;
							}

							/* add the character */
							TTputc(buf
							       [cpos++]);
						}
/* << << << << << << << << << << << << << << << << << */
					}
				}
				++ffp;
			}

			/* no match.....beep and onward */
			TTbeep();
		      onward:;
			TTflush();
/* <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< */
		} else {
			if (cpos < NSTRING - 1 && c > ' ') {
				buf[cpos++] = c;
				TTputc(c);
			}

			++ttcol;
			TTflush();
		}
	}
}

/*	tgetc:	Get a key from the terminal driver, resolve any keyboard
		macro action					*/

int tgetc(void)
{
	int c;			/* fetched character */

	/* if we are playing a keyboard macro back, */
	if (kbdmode == PLAY) {

		/* if there is some left... */
		if (kbdptr < kbdend)
			return (int) *kbdptr++;

		/* at the end of last repitition? */
		if (--kbdrep < 1) {
			kbdmode = STOP;
#if	VISMAC == 0
			/* force a screen update after all is done */
			update(FALSE);
#endif
		} else {

			/* reset the macro to the begining for the next rep */
			kbdptr = &kbdm[0];
			return (int) *kbdptr++;
		}
	}

	/* fetch a character from the terminal driver */
	c = TTgetc();

	/* record it for $lastkey */
	lastkey = c;

	/* save it if we need to */
	if (kbdmode == RECORD) {
		*kbdptr++ = c;
		kbdend = kbdptr;

		/* don't overrun the buffer */
		if (kbdptr == &kbdm[NKBDM - 1]) {
			kbdmode = STOP;
			TTbeep();
		}
	}

	/* and finally give the char back */
	return c;
}

/*	GET1KEY:	Get one keystroke. The only prefixs legal here
			are the SPEC and CONTROL prefixes.
								*/

int get1key(void)
{
	int c;

	/* get a keystroke */
	c = tgetc();

#if	MSDOS
	if (c == 0) {		/* Apply SPEC prefix    */
		c = tgetc();
		if (c >= 0x00 && c <= 0x1F)	/* control key? */
			c = CONTROL | (c + '@');
		return SPEC | c;
	}
#endif

	if (c >= 0x00 && c <= 0x1F)	/* C0 control -> C-     */
		c = CONTROL | (c + '@');
	return c;
}

/*	GETCMD:	Get a command from the keyboard. Process all applicable
		prefix keys
							*/
int getcmd(void)
{
	int c;			/* fetched keystroke */
#if VT220
	int d;			/* second character P.K. */
	int cmask = 0;
#endif
	/* get initial character */
	c = get1key();

#if VT220
      proc_metac:
#endif
	if (c == 128+27)		/* CSI */
		goto handle_CSI;
	/* process META prefix */
	if (c == (CONTROL | '[')) {
		c = get1key();
#if VT220
		if (c == '[' || c == 'O') {	/* CSI P.K. */
handle_CSI:
			c = get1key();
			if (c >= 'A' && c <= 'D')
				return SPEC | c | cmask;
			if (c >= 'E' && c <= 'z' && c != 'i' && c != 'c')
				return SPEC | c | cmask;
			d = get1key();
			if (d == '~')	/* ESC [ n ~   P.K. */
				return SPEC | c | cmask;
			switch (c) {	/* ESC [ n n ~ P.K. */
			case '1':
				c = d + 32;
				break;
			case '2':
				c = d + 48;
				break;
			case '3':
				c = d + 64;
				break;
			default:
				c = '?';
				break;
			}
			if (d != '~')	/* eat tilde P.K. */
				get1key();
			if (c == 'i') {	/* DO key    P.K. */
				c = ctlxc;
				goto proc_ctlxc;
			} else if (c == 'c')	/* ESC key   P.K. */
				c = get1key();
			else
				return SPEC | c | cmask;
		}
#endif
#if VT220
		if (c == (CONTROL | '[')) {
			cmask = META;
			goto proc_metac;
		}
#endif
		if (islower(c))	/* Force to upper */
			c ^= DIFCASE;
		if (c >= 0x00 && c <= 0x1F)	/* control key */
			c = CONTROL | (c + '@');
		return META | c;
	}
#if	PKCODE
	else if (c == metac) {
		c = get1key();
#if VT220
		if (c == (CONTROL | '[')) {
			cmask = META;
			goto proc_metac;
		}
#endif
		if (islower(c))	/* Force to upper */
			c ^= DIFCASE;
		if (c >= 0x00 && c <= 0x1F)	/* control key */
			c = CONTROL | (c + '@');
		return META | c;
	}
#endif


#if	VT220
      proc_ctlxc:
#endif
	/* process CTLX prefix */
	if (c == ctlxc) {
		c = get1key();
#if VT220
		if (c == (CONTROL | '[')) {
			cmask = CTLX;
			goto proc_metac;
		}
#endif
		if (c >= 'a' && c <= 'z')	/* Force to upper */
			c -= 0x20;
		if (c >= 0x00 && c <= 0x1F)	/* control key */
			c = CONTROL | (c + '@');
		return CTLX | c;
	}

	/* otherwise, just return it */
	return c;
}

/*	A more generalized prompt/reply function allowing the caller
	to specify the proper terminator. If the terminator is not
	a return ('\n') it will echo as "<NL>"
							*/
int getstring(char *prompt, char *buf, int nbuf, int eolchar)
{
	int cpos;	/* current character position in string */
	int c;
	int quotef;	/* are we quoting the next char? */
#if	COMPLC
	int ffile, ocpos, nskip = 0, didtry = 0;
#if     MSDOS
	struct ffblk ffblk;
	char *fcp;
#endif
#if	UNIX
	static char tmp[] = "/tmp/meXXXXXX";
	FILE *tmpf = NULL;
#endif
	ffile = (strcmp(prompt, "Find file: ") == 0
		 || strcmp(prompt, "View file: ") == 0
		 || strcmp(prompt, "Insert file: ") == 0
		 || strcmp(prompt, "Write file: ") == 0
		 || strcmp(prompt, "Read file: ") == 0
		 || strcmp(prompt, "File to execute: ") == 0);
#endif

	cpos = 0;
	quotef = FALSE;

	/* prompt the user for the input string */
	mlwrite(prompt);

	for (;;) {
#if	COMPLC
		if (!didtry)
			nskip = -1;
		didtry = 0;
#endif
		/* get a character from the user */
		c = get1key();

		/* If it is a <ret>, change it to a <NL> */
#if	PKCODE
		if (c == (CONTROL | 0x4d) && !quotef)
#else
		if (c == (CONTROL | 0x4d))
#endif
			c = CONTROL | 0x40 | '\n';

		/* if they hit the line terminate, wrap it up */
		if (c == eolchar && quotef == FALSE) {
			buf[cpos++] = 0;

			/* clear the message line */
			mlwrite("");
			TTflush();

			/* if we default the buffer, return FALSE */
			if (buf[0] == 0)
				return FALSE;

			return TRUE;
		}

		/* change from command form back to character form */
		c = ectoc(c);

		if (c == ectoc(abortc) && quotef == FALSE) {
			/* Abort the input? */
			ctrlg(FALSE, 0);
			TTflush();
			return ABORT;
		} else if ((c == 0x7F || c == 0x08) && quotef == FALSE) {
			/* rubout/erase */
			if (cpos != 0) {
				outstring("\b \b");
				--ttcol;

				if (buf[--cpos] < 0x20) {
					outstring("\b \b");
					--ttcol;
				}
				if (buf[cpos] == '\n') {
					outstring("\b\b  \b\b");
					ttcol -= 2;
				}

				TTflush();
			}

		} else if (c == 0x15 && quotef == FALSE) {
			/* C-U, kill */
			while (cpos != 0) {
				outstring("\b \b");
				--ttcol;

				if (buf[--cpos] < 0x20) {
					outstring("\b \b");
					--ttcol;
				}
				if (buf[cpos] == '\n') {
					outstring("\b\b  \b\b");
					ttcol -= 2;
				}
			}
			TTflush();

#if	COMPLC
		} else if ((c == 0x09 || c == ' ') && quotef == FALSE
			   && ffile) {
			/* TAB, complete file name */
			char ffbuf[255];
#if	MSDOS
			char sffbuf[128];
			int lsav = -1;
#endif
			int n, iswild = 0;

			didtry = 1;
			ocpos = cpos;
			while (cpos != 0) {
				outstring("\b \b");
				--ttcol;

				if (buf[--cpos] < 0x20) {
					outstring("\b \b");
					--ttcol;
				}
				if (buf[cpos] == '\n') {
					outstring("\b\b  \b\b");
					ttcol -= 2;
				}
				if (buf[cpos] == '*' || buf[cpos] == '?')
					iswild = 1;
#if	MSDOS
				if (lsav < 0 && (buf[cpos] == '\\' ||
						 buf[cpos] == '/' ||
						 buf[cpos] == ':'
						 && cpos == 1))
					lsav = cpos;
#endif
			}
			TTflush();
			if (nskip < 0) {
				buf[ocpos] = 0;
#if	UNIX
				if (tmpf != NULL)
					fclose(tmpf);
				strcpy(tmp, "/tmp/meXXXXXX");
				strcpy(ffbuf, "echo ");
				strcat(ffbuf, buf);
				if (!iswild)
					strcat(ffbuf, "*");
				strcat(ffbuf, " >");
				xmkstemp(tmp);
				strcat(ffbuf, tmp);
				strcat(ffbuf, " 2>&1");
				system(ffbuf);
				tmpf = fopen(tmp, "r");
#endif
#if	MSDOS
				strcpy(sffbuf, buf);
				if (!iswild)
					strcat(sffbuf, "*.*");
#endif
				nskip = 0;
			}
#if	UNIX
			c = ' ';
			for (n = nskip; n > 0; n--)
				while ((c = getc(tmpf)) != EOF
				       && c != ' ');
#endif
#if	MSDOS
			if (nskip == 0) {
				strcpy(ffbuf, sffbuf);
				c = findfirst(ffbuf, &ffblk,
					      FA_DIREC) ? '*' : ' ';
			} else if (nskip > 0)
				c = findnext(&ffblk) ? 0 : ' ';
#endif
			nskip++;

			if (c != ' ') {
				TTbeep();
				nskip = 0;
			}
#if	UNIX
			while ((c = getc(tmpf)) != EOF && c != '\n'
			       && c != ' ' && c != '*')
#endif
#if	MSDOS
				if (c == '*')
					fcp = sffbuf;
				else {
					strncpy(buf, sffbuf, lsav + 1);
					cpos = lsav + 1;
					fcp = ffblk.ff_name;
				}
			while (c != 0 && (c = *fcp++) != 0 && c != '*')
#endif
			{
				if (cpos < nbuf - 1)
					buf[cpos++] = c;
			}
#if	UNIX
			if (c == '*')
				TTbeep();
#endif

			for (n = 0; n < cpos; n++) {
				c = buf[n];
				if ((c < ' ') && (c != '\n')) {
					outstring("^");
					++ttcol;
					c ^= 0x40;
				}

				if (c != '\n') {
					if (disinp)
						TTputc(c);
				} else {	/* put out <NL> for <ret> */
					outstring("<NL>");
					ttcol += 3;
				}
				++ttcol;
			}
			TTflush();
#if	UNIX
			rewind(tmpf);
			unlink(tmp);
#endif
#endif

		} else if ((c == quotec || c == 0x16) && quotef == FALSE) {
			quotef = TRUE;
		} else {
			quotef = FALSE;
			if (cpos < nbuf - 1) {
				buf[cpos++] = c;

				if ((c < ' ') && (c != '\n')) {
					outstring("^");
					++ttcol;
					c ^= 0x40;
				}

				if (c != '\n') {
					if (disinp)
						TTputc(c);
				} else {	/* put out <NL> for <ret> */
					outstring("<NL>");
					ttcol += 3;
				}
				++ttcol;
				TTflush();
			}
		}
	}
}

/*
 * output a string of characters
 *
 * char *s;		string to output
 */
void outstring(char *s)
{
	if (disinp)
		while (*s)
			TTputc(*s++);
}

/*
 * output a string of output characters
 *
 * char *s;		string to output
 */
void ostring(char *s)
{
	if (discmd)
		while (*s)
			TTputc(*s++);
}


/* ----- isearch.c ----- */
/*	isearch.c
 *
 * The functions in this file implement commands that perform incremental
 * searches in the forward and backward directions.  This "ISearch" command
 * is intended to emulate the same command from the original EMACS
 * implementation (ITS).  Contains references to routines internal to
 * SEARCH.C.
 *
 * REVISION HISTORY:
 *
 *	D. R. Banks 9-May-86
 *	- added ITS EMACSlike ISearch
 *
 *	John M. Gamble 5-Oct-86
 *	- Made iterative search use search.c's scanner() routine.
 *	  This allowed the elimination of bakscan().
 *	- Put isearch constants into estruct.h
 *	- Eliminated the passing of 'status' to scanmore() and
 *	  checknext(), since there were no circumstances where
 *	  it ever equalled FALSE.
 *
 *	Modified by Petri Kutvonen
 */
/* system header already included */
/* #include "estruct.h" - amalgamated */
/* #include "edef.h" - amalgamated */
/* #include "efunc.h" - amalgamated */
/* #include "line.h" - amalgamated */

#if	ISRCH

static int echo_char(int c, int col);

/* A couple of "own" variables for re-eat */

static int (*saved_get_char) (void);	/* Get character routine */
static int eaten_char = -1;		/* Re-eaten char */

/* A couple more "own" variables for the command string */

static int cmd_buff[CMDBUFLEN];	/* Save the command args here */
static int cmd_offset;			/* Current offset into command buff */
static int cmd_reexecute = -1;		/* > 0 if re-executing command */


/*
 * Subroutine to do incremental reverse search.  It actually uses the
 * same code as the normal incremental search, as both can go both ways.
 */
int risearch(int f, int n)
{
	struct line *curline;		/* Current line on entry              */
	int curoff;		/* Current offset on entry            */

	/* remember the initial . on entry: */

	curline = curwp->w_dotp;	/* Save the current line pointer      */
	curoff = curwp->w_doto;	/* Save the current offset            */

	/* Make sure the search doesn't match where we already are:               */

	backchar(TRUE, 1);	/* Back up a character                */

	if (!(isearch(f, -n))) {	/* Call ISearch backwards       *//* If error in search:                */
		curwp->w_dotp = curline;	/* Reset the line pointer             */
		curwp->w_doto = curoff;	/*  and the offset to original value  */
		curwp->w_flag |= WFMOVE;	/* Say we've moved                    */
		update(FALSE);	/* And force an update                */
		mlwrite("(search failed)");	/* Say we died                        */
#if	PKCODE
		matchlen = strlen(pat);
#endif
	} else
		mlerase();	/* If happy, just erase the cmd line  */
#if	PKCODE
	matchlen = strlen(pat);
#endif
	return TRUE;
}

/*
 * Again, but for the forward direction
 */
int fisearch(int f, int n)
{
	struct line *curline;		/* Current line on entry              */
	int curoff;		/* Current offset on entry            */

	/* remember the initial . on entry: */

	curline = curwp->w_dotp;	/* Save the current line pointer      */
	curoff = curwp->w_doto;	/* Save the current offset            */

	/* do the search */

	if (!(isearch(f, n))) {	/* Call ISearch forwards        *//* If error in search:                */
		curwp->w_dotp = curline;	/* Reset the line pointer             */
		curwp->w_doto = curoff;	/*  and the offset to original value  */
		curwp->w_flag |= WFMOVE;	/* Say we've moved                    */
		update(FALSE);	/* And force an update                */
		mlwrite("(search failed)");	/* Say we died                        */
#if	PKCODE
		matchlen = strlen(pat);
#endif
	} else
		mlerase();	/* If happy, just erase the cmd line  */
#if	PKCODE
	matchlen = strlen(pat);
#endif
	return TRUE;
}

/*
 * Subroutine to do an incremental search.  In general, this works similarly
 * to the older micro-emacs search function, except that the search happens
 * as each character is typed, with the screen and cursor updated with each
 * new search character.
 *
 * While searching forward, each successive character will leave the cursor
 * at the end of the entire matched string.  Typing a Control-S or Control-X
 * will cause the next occurrence of the string to be searched for (where the
 * next occurrence does NOT overlap the current occurrence).  A Control-R will
 * change to a backwards search, META will terminate the search and Control-G
 * will abort the search.  Rubout will back up to the previous match of the
 * string, or if the starting point is reached first, it will delete the
 * last character from the search string.
 *
 * While searching backward, each successive character will leave the cursor
 * at the beginning of the matched string.  Typing a Control-R will search
 * backward for the next occurrence of the string.  Control-S or Control-X
 * will revert the search to the forward direction.  In general, the reverse
 * incremental search is just like the forward incremental search inverted.
 *
 * In all cases, if the search fails, the user will be feeped, and the search
 * will stall until the pattern string is edited back into something that
 * exists (or until the search is aborted).
 */

int isearch(int f, int n)
{
	int status;		/* Search status */
	int col;		/* prompt column */
	int cpos;	/* character number in search string  */
	int c;		/* current input character */
	int expc;	/* function expanded input char       */
	char pat_save[NPAT];	/* Saved copy of the old pattern str  */
	struct line *curline;		/* Current line on entry              */
	int curoff;		/* Current offset on entry            */
	int init_direction;	/* The initial search direction       */

	/* Initialize starting conditions */

	cmd_reexecute = -1;	/* We're not re-executing (yet?)      */
	cmd_offset = 0;		/* Start at the beginning of the buff */
	cmd_buff[0] = '\0';	/* Init the command buffer            */
	strncpy(pat_save, pat, NPAT);	/* Save the old pattern string        */
	curline = curwp->w_dotp;	/* Save the current line pointer      */
	curoff = curwp->w_doto;	/* Save the current offset            */
	init_direction = n;	/* Save the initial search direction  */

	/* This is a good place to start a re-execution: */

      start_over:

	/* ask the user for the text of a pattern */
	col = promptpattern("ISearch: ");	/* Prompt, remember the col   */

	cpos = 0;		/* Start afresh               */
	status = TRUE;		/* Assume everything's cool   */

	/*
	   Get the first character in the pattern.  If we get an initial Control-S
	   or Control-R, re-use the old search string and find the first occurrence
	 */

	c = ectoc(expc = get_char());	/* Get the first character    */
	if ((c == IS_FORWARD) || (c == IS_REVERSE) || (c == IS_VMSFORW)) {	/* Reuse old search string?   */
		for (cpos = 0; pat[cpos] != 0; cpos++)	/* Yup, find the length           */
			col = echo_char(pat[cpos], col);	/*  and re-echo the string    */
		if (c == IS_REVERSE) {	/* forward search?            */
			n = -1;	/* No, search in reverse      */
			backchar(TRUE, 1);	/* Be defensive about EOB     */
		} else
			n = 1;	/* Yes, search forward        */
		status = scanmore(pat, n);	/* Do the search              */
		c = ectoc(expc = get_char());	/* Get another character      */
	}

	/* Top of the per character loop */

	for (;;) {		/* ISearch per character loop */
		/* Check for special characters first: */
		/* Most cases here change the search */

		if (expc == metac)	/* Want to quit searching?    */
			return TRUE;	/* Quit searching now         */

		switch (c) {	/* dispatch on the input char */
		case IS_ABORT:	/* If abort search request    */
			return FALSE;	/* Quit searching again       */

		case IS_REVERSE:	/* If backward search         */
		case IS_FORWARD:	/* If forward search          */
		case IS_VMSFORW:	/*  of either flavor          */
			if (c == IS_REVERSE)	/* If reverse search              */
				n = -1;	/* Set the reverse direction  */
			else	/* Otherwise,                     */
				n = 1;	/*  go forward                */
			status = scanmore(pat, n);	/* Start the search again     */
			c = ectoc(expc = get_char());	/* Get the next char          */
			continue;	/* Go continue with the search */

		case IS_NEWLINE:	/* Carriage return            */
			c = '\n';	/* Make it a new line         */
			break;	/* Make sure we use it        */

		case IS_QUOTE:	/* Quote character            */
		case IS_VMSQUOTE:	/*  of either variety         */
			c = ectoc(expc = get_char());	/* Get the next char          */

		case IS_TAB:	/* Generically allowed        */
		case '\n':	/*  controlled characters     */
			break;	/* Make sure we use it        */

		case IS_BACKSP:	/* If a backspace:            */
		case IS_RUBOUT:	/*  or if a Rubout:           */
			if (cmd_offset <= 1)	/* Anything to delete?            */
				return TRUE;	/* No, just exit              */
			--cmd_offset;	/* Back up over the Rubout    */
			cmd_buff[--cmd_offset] = '\0';	/* Yes, delete last char   */
			curwp->w_dotp = curline;	/* Reset the line pointer     */
			curwp->w_doto = curoff;	/*  and the offset            */
			n = init_direction;	/* Reset the search direction */
			strncpy(pat, pat_save, NPAT);	/* Restore the old search str */
			cmd_reexecute = 0;	/* Start the whole mess over  */
			goto start_over;	/* Let it take care of itself */

			/* Presumably a quasi-normal character comes here */

		default:	/* All other chars            */
			if (c < ' ') {	/* Is it printable?             *//* Nope.                      */
				reeat(c);	/* Re-eat the char            */
				return TRUE;	/* And return the last status */
			}
		}		/* Switch */

		/* I guess we got something to search for, so search for it           */

		pat[cpos++] = c;	/* put the char in the buffer */
		if (cpos >= NPAT) {	/* too many chars in string?  *//* Yup.  Complain about it    */
			mlwrite("? Search string too long");
			return TRUE;	/* Return an error            */
		}
		pat[cpos] = 0;	/* null terminate the buffer  */
		col = echo_char(c, col);	/* Echo the character         */
		if (!status) {	/* If we lost last time       */
			TTputc(BELL);	/* Feep again                 */
			TTflush();	/* see that the feep feeps    */
		} else /* Otherwise, we must have won */ if (!(status = checknext(c, pat, n)))	/* See if match         */
			status = scanmore(pat, n);	/*  or find the next match    */
		c = ectoc(expc = get_char());	/* Get the next char          */
	}			/* for {;;} */
}

/*
 * Trivial routine to insure that the next character in the search string is
 * still true to whatever we're pointing to in the buffer.  This routine will
 * not attempt to move the "point" if the match fails, although it will 
 * implicitly move the "point" if we're forward searching, and find a match,
 * since that's the way forward isearch works.
 *
 * If the compare fails, we return FALSE and assume the caller will call
 * scanmore or something.
 *
 * char chr;		Next char to look for
 * char *patrn;		The entire search string (incl chr)
 * int dir;		Search direction
 */
int checknext(char chr, char *patrn, int dir)	/* Check next character in search string */
{
	struct line *curline;	/* current line during scan           */
	int curoff;	/* position within current line       */
	int buffchar;	/* character at current position      */
	int status;		/* how well things go                 */


	/* setup the local scan pointer to current "." */

	curline = curwp->w_dotp;		/* Get the current line structure     */
	curoff = curwp->w_doto;			/* Get the offset within that line    */

	if (dir > 0) {				/* If searching forward                 */
		if (curoff == llength(curline)) {		/* If at end of line                    */
			curline = lforw(curline);		/* Skip to the next line              */
			if (curline == curbp->b_linep)
				return FALSE;			/* Abort if at end of buffer          */
			curoff = 0;				/* Start at the beginning of the line */
			buffchar = '\n';			/* And say the next char is NL        */
		} else
			buffchar = lgetc(curline, curoff++);	/* Get the next char         */
		if ((status = eq(buffchar, chr)) != 0) {	/* Is it what we're looking for?      */
			curwp->w_dotp = curline;		/* Yes, set the buffer's point        */
			curwp->w_doto = curoff;			/*  to the matched character          */
			curwp->w_flag |= WFMOVE;		/* Say that we've moved               */
		}
		return status;		/* And return the status              */
	} else					/* Else, if reverse search:       */
		return match_pat(patrn);	/* See if we're in the right place    */
}

/*
 * This hack will search for the next occurrence of <pat> in the buffer, either
 * forward or backward.  It is called with the status of the prior search
 * attempt, so that it knows not to bother if it didn't work last time.  If
 * we can't find any more matches, "point" is left where it was before.  If
 * we do find a match, "point" will be at the end of the matched string for
 * forward searches and at the beginning of the matched string for reverse
 * searches.
 *
 * char *patrn;			string to scan for
 * int dir;			direction to search
 */
int scanmore(char *patrn, int dir)	/* search forward or back for a pattern           */
{
	int sts;		/* search status                      */

	if (dir < 0) {		/* reverse search?              */
		rvstrcpy(tap, patrn);	/* Put reversed string in tap */
		sts = scanner(tap, REVERSE, PTBEG);
	} else
		sts = scanner(patrn, FORWARD, PTEND);	/* Nope. Go forward   */

	if (!sts) {
		TTputc(BELL);	/* Feep if search fails       */
		TTflush();	/* see that the feep feeps    */
	}

	return sts;		/* else, don't even try       */
}

/*
 * The following is a worker subroutine used by the reverse search.  It
 * compares the pattern string with the characters at "." for equality. If
 * any characters mismatch, it will return FALSE.
 *
 * This isn't used for forward searches, because forward searches leave "."
 * at the end of the search string (instead of in front), so all that needs to
 * be done is match the last char input.
 *
 * char *patrn;			String to match to buffer
 */
int match_pat(char *patrn)	/* See if the pattern string matches string at "."   */
{
	int i;		/* Generic loop index/offset          */
	int buffchar;	/* character at current position      */
	struct line *curline;	/* current line during scan           */
	int curoff;	/* position within current line       */

	/* setup the local scan pointer to current "." */

	curline = curwp->w_dotp;	/* Get the current line structure     */
	curoff = curwp->w_doto;	/* Get the offset within that line    */

	/* top of per character compare loop: */

	for (i = 0; i < strlen(patrn); i++) {	/* Loop for all characters in patrn   */
		if (curoff == llength(curline)) {	/* If at end of line                    */
			curline = lforw(curline);	/* Skip to the next line              */
			curoff = 0;	/* Start at the beginning of the line */
			if (curline == curbp->b_linep)
				return FALSE;	/* Abort if at end of buffer          */
			buffchar = '\n';	/* And say the next char is NL        */
		} else
			buffchar = lgetc(curline, curoff++);	/* Get the next char         */
		if (!eq(buffchar, patrn[i]))	/* Is it what we're looking for?      */
			return FALSE;	/* Nope, just punt it then            */
	}
	return TRUE;		/* Everything matched? Let's celebrate */
}

/*
 * Routine to prompt for I-Search string.
 */
int promptpattern(char *prompt)
{
	char tpat[NPAT + 20];

	strcpy(tpat, prompt);	/* copy prompt to output string */
	strcat(tpat, " (");	/* build new prompt string */
	expandp(pat, &tpat[strlen(tpat)], NPAT / 2);	/* add old pattern */
	strcat(tpat, ")<Meta>: ");

	/* check to see if we are executing a command line */
	if (!clexec) {
		mlwrite(tpat);
	}
	return strlen(tpat);
}

/*
 * routine to echo i-search characters
 *
 * int c;		character to be echoed
 * int col;		column to be echoed in
 */
static int echo_char(int c, int col)
{
	movecursor(term.t_nrow, col);	/* Position the cursor        */
	if ((c < ' ') || (c == 0x7F)) {	/* Control character?           */
		switch (c) {	/* Yes, dispatch special cases */
		case '\n':	/* Newline                    */
			TTputc('<');
			TTputc('N');
			TTputc('L');
			TTputc('>');
			col += 3;
			break;

		case '\t':	/* Tab                        */
			TTputc('<');
			TTputc('T');
			TTputc('A');
			TTputc('B');
			TTputc('>');
			col += 4;
			break;

		case 0x7F:	/* Rubout:                    */
			TTputc('^');	/* Output a funny looking     */
			TTputc('?');	/*  indication of Rubout      */
			col++;	/* Count the extra char       */
			break;

		default:	/* Vanilla control char       */
			TTputc('^');	/* Yes, output prefix         */
			TTputc(c + 0x40);	/* Make it "^X"               */
			col++;	/* Count this char            */
		}
	} else
		TTputc(c);	/* Otherwise, output raw char */
	TTflush();		/* Flush the output           */
	return ++col;		/* return the new column no   */
}

/*
 * Routine to get the next character from the input stream.  If we're reading
 * from the real terminal, force a screen update before we get the char. 
 * Otherwise, we must be re-executing the command string, so just return the
 * next character.
 */
int get_char(void)
{
	int c;			/* A place to get a character         */

	/* See if we're re-executing: */

	if (cmd_reexecute >= 0)	/* Is there an offset?                    */
		if ((c = cmd_buff[cmd_reexecute++]) != 0)
			return c;	/* Yes, return any character          */

	/* We're not re-executing (or aren't any more).  Try for a real char      */

	cmd_reexecute = -1;	/* Say we're in real mode again       */
	update(FALSE);		/* Pretty up the screen               */
	if (cmd_offset >= CMDBUFLEN - 1) {	/* If we're getting too big ...         */
		mlwrite("? command too long");	/* Complain loudly and bitterly       */
		return metac;	/* And force a quit                   */
	}
	c = get1key();		/* Get the next character             */
	cmd_buff[cmd_offset++] = c;	/* Save the char for next time        */
	cmd_buff[cmd_offset] = '\0';	/* And terminate the buffer           */
	return c;		/* Return the character               */
}

/*
 * Hacky routine to re-eat a character.  This will save the character to be
 * re-eaten by redirecting the input call to a routine here.  Hack, etc.
 */

/* Come here on the next term.t_getchar call: */

int uneat(void)
{
	int c;

	term.t_getchar = saved_get_char;	/* restore the routine address        */
	c = eaten_char;		/* Get the re-eaten char              */
	eaten_char = -1;	/* Clear the old char                 */
	return c;		/* and return the last char           */
}

void reeat(int c)
{
	if (eaten_char != -1)	/* If we've already been here             */
		return /*(NULL) */ ;	/* Don't do it again                  */
	eaten_char = c;		/* Else, save the char for later      */
	saved_get_char = term.t_getchar;	/* Save the char get routine          */
	term.t_getchar = uneat;	/* Replace it with ours               */
}
#else
int isearch(int f, int n)
{
}
#endif


/* ----- lock.c ----- */
/*	LOCK.C
 *
 *	File locking command routines
 *
 *	written by Daniel Lawrence
 */
/* system header already included */
/* #include "estruct.h" - amalgamated */
/* #include "edef.h" - amalgamated */
/* #include "efunc.h" - amalgamated */

#if	BSD | SVR4
#include <sys/errno.h>

static char *lname[NLOCKS];		/* names of all locked files */
static int numlocks;			/* # of current locks active */

/*
 * lockchk:
 *	check a file for locking and add it to the list
 *
 * char *fname;			file to check for a lock
 */
int lockchk(char *fname)
{
	int i;		/* loop indexes */
	int status;	/* return status */

	/* check to see if that file is already locked here */
	if (numlocks > 0)
		for (i = 0; i < numlocks; ++i)
			if (strcmp(fname, lname[i]) == 0)
				return TRUE;

	/* if we have a full locking table, bitch and leave */
	if (numlocks == NLOCKS) {
		mlwrite("LOCK ERROR: Lock table full");
		return ABORT;
	}

	/* next, try to lock it */
	status = lock(fname);
	if (status == ABORT)	/* file is locked, no override */
		return ABORT;
	if (status == FALSE)	/* locked, overriden, dont add to table */
		return TRUE;

	/* we have now locked it, add it to our table */
	lname[++numlocks - 1] = (char *) malloc(strlen(fname) + 1);
	if (lname[numlocks - 1] == NULL) {	/* malloc failure */
		undolock(fname);	/* free the lock */
		mlwrite("Cannot lock, out of memory");
		--numlocks;
		return ABORT;
	}

	/* everthing is cool, add it to the table */
	strcpy(lname[numlocks - 1], fname);
	return TRUE;
}

/*
 * lockrel:
 *	release all the file locks so others may edit
 */
int lockrel(void)
{
	int i;		/* loop index */
	int status;	/* status of locks */
	int s;		/* status of one unlock */

	status = TRUE;
	if (numlocks > 0)
		for (i = 0; i < numlocks; ++i) {
			if ((s = unlock(lname[i])) != TRUE)
				status = s;
			free(lname[i]);
		}
	numlocks = 0;
	return status;
}

/*
 * lock:
 *	Check and lock a file from access by others
 *	returns	TRUE = files was not locked and now is
 *		FALSE = file was locked and overridden
 *		ABORT = file was locked, abort command
 *
 * char *fname;		file name to lock
 */
int lock(char *fname)
{
	char *locker;	/* lock error message */
	int status;	/* return status */
	char msg[NSTRING];	/* message string */

	/* attempt to lock the file */
	locker = dolock(fname);
	if (locker == NULL)	/* we win */
		return TRUE;

	/* file failed...abort */
	if (strncmp(locker, "LOCK", 4) == 0) {
		lckerror(locker);
		return ABORT;
	}

	/* someone else has it....override? */
	strcpy(msg, "File in use by ");
	strcat(msg, locker);
	strcat(msg, ", override?");
	status = mlyesno(msg);	/* ask them */
	if (status == TRUE)
		return FALSE;
	else
		return ABORT;
}

/*
 * unlock:
 *	Unlock a file
 *	this only warns the user if it fails
 *
 * char *fname;		file to unlock
 */
int unlock(char *fname)
{
	char *locker;	/* undolock return string */

	/* unclock and return */
	locker = undolock(fname);
	if (locker == NULL)
		return TRUE;

	/* report the error and come back */
	lckerror(locker);
	return FALSE;
}

/*
 * report a lock error
 *
 * char *errstr;	lock error string to print out
 */
void lckerror(char *errstr)
{
	char obuf[NSTRING];	/* output buffer for error message */

	strcpy(obuf, errstr);
	strcat(obuf, " - ");
	strcat(obuf, strerror(errno));
	mlwrite(obuf);
}
#endif


/* ----- pklock.c ----- */
/*	PKLOCK.C
 *
 *	locking routines as modified by Petri Kutvonen
 */

/* #include "estruct.h" - amalgamated */
/* #include "edef.h" - amalgamated */
/* #include "efunc.h" - amalgamated */

#if (FILOCK && BSD) || SVR4
/* system header already included */
/* system header already included */
/* system header already included */
/* system header already included */
/* system header already included */
#ifdef SVR4
/* system header already included */
#else
#include <strings.h>
#endif
/* system header already included */
#define MAXLOCK 512
#define MAXNAME 128

#if defined(SVR4) && ! defined(__linux__)
#include <sys/systeminfo.h>

int gethostname(char *name, int namelen)
{
	return sysinfo(SI_HOSTNAME, name, namelen);
}
#endif



/**********************
 *
 * if successful, returns NULL  
 * if file locked, returns username of person locking the file
 * if other error, returns "LOCK ERROR: explanation"
 *
 *********************/
char *dolock(char *fname)
{
	int fd, n;
	static char lname[MAXLOCK], locker[MAXNAME + 1];
	int mask;
	struct stat sbuf;

	strcat(strcpy(lname, fname), ".lock~");

	/* check that we are not being cheated, qname must point to     */
	/* a regular file - even this code leaves a small window of     */
	/* vulnerability but it is rather hard to exploit it            */

#if defined(S_IFLNK)
	if (lstat(lname, &sbuf) == 0)
#else
	if (stat(lname, &sbuf) == 0)
#endif
#if defined(S_ISREG)
		if (!S_ISREG(sbuf.st_mode))
#else
		if (!(((sbuf.st_mode) & 070000) == 0))	/* SysV R2 */
#endif
			return "LOCK ERROR: not a regular file";

	mask = umask(0);
	fd = open(lname, O_RDWR | O_CREAT, 0666);
	umask(mask);
	if (fd < 0) {
		if (errno == EACCES)
			return NULL;
#ifdef EROFS
		if (errno == EROFS)
			return NULL;
#endif
		return "LOCK ERROR: cannot access lock file";
	}
	if ((n = read(fd, locker, MAXNAME)) < 1) {
		lseek(fd, 0, SEEK_SET);
/*		strcpy(locker, getlogin()); */
		cuserid(locker);
		strcat(locker + strlen(locker), "@");
		gethostname(locker + strlen(locker), 64);
		write(fd, locker, strlen(locker));
		close(fd);
		return NULL;
	}
	locker[n > MAXNAME ? MAXNAME : n] = 0;
	return locker;
}


/*********************
 *
 * undolock -- unlock the file fname
 *
 * if successful, returns NULL
 * if other error, returns "LOCK ERROR: explanation"
 *
 *********************/

char *undolock(char *fname)
{
	static char lname[MAXLOCK];

	strcat(strcpy(lname, fname), ".lock~");
	if (unlink(lname) != 0) {
		if (errno == EACCES || errno == ENOENT)
			return NULL;
#ifdef EROFS
		if (errno == EROFS)
			return NULL;
#endif
		return "LOCK ERROR: cannot remove lock file";
	}
	return NULL;
}
#endif


/* ----- random.c ----- */
/*	random.c
 *
 *      This file contains the command processing functions for a number of
 *      random commands. There is no functional grouping here, for sure.
 *
 *	Modified by Petri Kutvonen
 */
/* system header already included */
/* #include "estruct.h" - amalgamated */
/* #include "edef.h" - amalgamated */
/* #include "efunc.h" - amalgamated */
/* #include "line.h" - amalgamated */

int tabsize; /* Tab size (0: use real tabs) */

/*
 * Set fill column to n.
 */
int setfillcol(int f, int n)
{
	fillcol = n;
	mlwrite("(Fill column is %d)", n);
	return TRUE;
}

/*
 * Display the current position of the cursor, in origin 1 X-Y coordinates,
 * the character that is under the cursor (in hex), and the fraction of the
 * text that is before the cursor. The displayed column is not the current
 * column, but the column that would be used on an infinite width display.
 * Normally this is bound to "C-X =".
 */
int showcpos(int f, int n)
{
	struct line *lp;	/* current line */
	long numchars;	/* # of chars in file */
	int numlines;	/* # of lines in file */
	long predchars;	/* # chars preceding point */
	int predlines;	/* # lines preceding point */
	int curchar;	/* character under cursor */
	int ratio;
	int col;
	int savepos;		/* temp save for current offset */
	int ecol;		/* column pos/end of current line */

	/* starting at the beginning of the buffer */
	lp = lforw(curbp->b_linep);

	/* start counting chars and lines */
	numchars = 0;
	numlines = 0;
	predchars = 0;
	predlines = 0;
	curchar = 0;
	while (lp != curbp->b_linep) {
		/* if we are on the current line, record it */
		if (lp == curwp->w_dotp) {
			predlines = numlines;
			predchars = numchars + curwp->w_doto;
			if ((curwp->w_doto) == llength(lp))
				curchar = '\n';
			else
				curchar = lgetc(lp, curwp->w_doto);
		}
		/* on to the next line */
		++numlines;
		numchars += llength(lp) + 1;
		lp = lforw(lp);
	}

	/* if at end of file, record it */
	if (curwp->w_dotp == curbp->b_linep) {
		predlines = numlines;
		predchars = numchars;
#if	PKCODE
		curchar = 0;
#endif
	}

	/* Get real column and end-of-line column. */
	col = getccol(FALSE);
	savepos = curwp->w_doto;
	curwp->w_doto = llength(curwp->w_dotp);
	ecol = getccol(FALSE);
	curwp->w_doto = savepos;

	ratio = 0;		/* Ratio before dot. */
	if (numchars != 0)
		ratio = (100L * predchars) / numchars;

	/* summarize and report the info */
	mlwrite("Line %d/%d Col %d/%d Char %D/%D (%d%%) char = 0x%x",
		predlines + 1, numlines + 1, col, ecol,
		predchars, numchars, ratio, curchar);
	return TRUE;
}

int getcline(void)
{				/* get the current line number */
	struct line *lp;	/* current line */
	int numlines;	/* # of lines before point */

	/* starting at the beginning of the buffer */
	lp = lforw(curbp->b_linep);

	/* start counting lines */
	numlines = 0;
	while (lp != curbp->b_linep) {
		/* if we are on the current line, record it */
		if (lp == curwp->w_dotp)
			break;
		++numlines;
		lp = lforw(lp);
	}

	/* and return the resulting count */
	return numlines + 1;
}

/*
 * Return current column.  Stop at first non-blank given TRUE argument.
 */
int getccol(int bflg)
{
	int i, col;
	struct line *dlp = curwp->w_dotp;
	int byte_offset = curwp->w_doto;
	int len = llength(dlp);

	col = i = 0;
	while (i < byte_offset) {
		unicode_t c;

		i += utf8_to_unicode(dlp->l_text, i, len, &c);
		if (c != ' ' && c != '\t' && bflg)
			break;
		if (c == '\t')
			col |= tabmask;
		else if (c < 0x20 || c == 0x7F)
			++col;
		else if (c >= 0xc0 && c <= 0xa0)
			col += 2;
		++col;
	}
	return col;
}

/*
 * Set current column.
 *
 * int pos;		position to set cursor
 */
int setccol(int pos)
{
	int c;		/* character being scanned */
	int i;		/* index into current line */
	int col;	/* current cursor column   */
	int llen;	/* length of line in bytes */

	col = 0;
	llen = llength(curwp->w_dotp);

	/* scan the line until we are at or past the target column */
	for (i = 0; i < llen; ++i) {
		/* upon reaching the target, drop out */
		if (col >= pos)
			break;

		/* advance one character */
		c = lgetc(curwp->w_dotp, i);
		if (c == '\t')
			col |= tabmask;
		else if (c < 0x20 || c == 0x7F)
			++col;
		++col;
	}

	/* set us at the new position */
	curwp->w_doto = i;

	/* and tell weather we made it */
	return col >= pos;
}

/*
 * Twiddle the two characters on either side of dot. If dot is at the end of
 * the line twiddle the two characters before it. Return with an error if dot
 * is at the beginning of line; it seems to be a bit pointless to make this
 * work. This fixes up a very common typo with a single stroke. Normally bound
 * to "C-T". This always works within a line, so "WFEDIT" is good enough.
 */
int twiddle(int f, int n)
{
	struct line *dotp;
	int doto;
	int cl;
	int cr;

	if (curbp->b_mode & MDVIEW)	/* don't allow this command if      */
		return rdonly();	/* we are in read only mode     */
	dotp = curwp->w_dotp;
	doto = curwp->w_doto;
	if (doto == llength(dotp) && --doto < 0)
		return FALSE;
	cr = lgetc(dotp, doto);
	if (--doto < 0)
		return FALSE;
	cl = lgetc(dotp, doto);
	lputc(dotp, doto + 0, cr);
	lputc(dotp, doto + 1, cl);
	lchange(WFEDIT);
	return TRUE;
}

/*
 * Quote the next character, and insert it into the buffer. All the characters
 * are taken literally, with the exception of the newline, which always has
 * its line splitting meaning. The character is always read, even if it is
 * inserted 0 times, for regularity. Bound to "C-Q"
 */
int quote(int f, int n)
{
	int s;
	int c;

	if (curbp->b_mode & MDVIEW)	/* don't allow this command if      */
		return rdonly();	/* we are in read only mode     */
	c = tgetc();
	if (n < 0)
		return FALSE;
	if (n == 0)
		return TRUE;
	if (c == '\n') {
		do {
			s = lnewline();
		} while (s == TRUE && --n);
		return s;
	}
	return linsert(n, c);
}

/*
 * Set tab size if given non-default argument (n <> 1).  Otherwise, insert a
 * tab into file.  If given argument, n, of zero, change to true tabs.
 * If n > 1, simulate tab stop every n-characters using spaces. This has to be
 * done in this slightly funny way because the tab (in ASCII) has been turned
 * into "C-I" (in 10 bit code) already. Bound to "C-I".
 */
int insert_tab(int f, int n)
{
	if (n < 0)
		return FALSE;
	if (n == 0 || n > 1) {
		tabsize = n;
		return TRUE;
	}
	if (!tabsize)
		return linsert(1, '\t');
	return linsert(tabsize - (getccol(FALSE) % tabsize), ' ');
}

#if	AEDIT
/*
 * change tabs to spaces
 *
 * int f, n;		default flag and numeric repeat count
 */
int detab(int f, int n)
{
	int inc;	/* increment to next line [sgn(n)] */

	if (curbp->b_mode & MDVIEW)	/* don't allow this command if      */
		return rdonly();	/* we are in read only mode     */

	if (f == FALSE)
		n = 1;

	/* loop thru detabbing n lines */
	inc = ((n > 0) ? 1 : -1);
	while (n) {
		curwp->w_doto = 0;	/* start at the beginning */

		/* detab the entire current line */
		while (curwp->w_doto < llength(curwp->w_dotp)) {
			/* if we have a tab */
			if (lgetc(curwp->w_dotp, curwp->w_doto) == '\t') {
				ldelchar(1, FALSE);
				insspace(TRUE,
					 (tabmask + 1) -
					 (curwp->w_doto & tabmask));
			}
			forwchar(FALSE, 1);
		}

		/* advance/or back to the next line */
		forwline(TRUE, inc);
		n -= inc;
	}
	curwp->w_doto = 0;	/* to the begining of the line */
	thisflag &= ~CFCPCN;	/* flag that this resets the goal column */
	lchange(WFEDIT);	/* yes, we have made at least an edit */
	return TRUE;
}

/*
 * change spaces to tabs where posible
 *
 * int f, n;		default flag and numeric repeat count
 */
int entab(int f, int n)
{
	int inc;	/* increment to next line [sgn(n)] */
	int fspace;	/* pointer to first space if in a run */
	int ccol;	/* current cursor column */
	char cchar;	/* current character */

	if (curbp->b_mode & MDVIEW)	/* don't allow this command if      */
		return rdonly();	/* we are in read only mode     */

	if (f == FALSE)
		n = 1;

	/* loop thru entabbing n lines */
	inc = ((n > 0) ? 1 : -1);
	while (n) {
		curwp->w_doto = 0;	/* start at the beginning */

		/* entab the entire current line */
		fspace = -1;
		ccol = 0;
		while (curwp->w_doto < llength(curwp->w_dotp)) {
			/* see if it is time to compress */
			if ((fspace >= 0) && (nextab(fspace) <= ccol)) {
				if (ccol - fspace < 2)
					fspace = -1;
				else {
					/* there is a bug here dealing with mixed space/tabed
					   lines.......it will get fixed                */
					backchar(TRUE, ccol - fspace);
					ldelete((long) (ccol - fspace),
						FALSE);
					linsert(1, '\t');
					fspace = -1;
				}
			}

			/* get the current character */
			cchar = lgetc(curwp->w_dotp, curwp->w_doto);

			switch (cchar) {
			case '\t':	/* a tab...count em up */
				ccol = nextab(ccol);
				break;

			case ' ':	/* a space...compress? */
				if (fspace == -1)
					fspace = ccol;
				ccol++;
				break;

			default:	/* any other char...just count */
				ccol++;
				fspace = -1;
				break;
			}
			forwchar(FALSE, 1);
		}

		/* advance/or back to the next line */
		forwline(TRUE, inc);
		n -= inc;
	}
	curwp->w_doto = 0;	/* to the begining of the line */
	thisflag &= ~CFCPCN;	/* flag that this resets the goal column */
	lchange(WFEDIT);	/* yes, we have made at least an edit */
	return TRUE;
}

/*
 * trim trailing whitespace from the point to eol
 *
 * int f, n;		default flag and numeric repeat count
 */
int trim(int f, int n)
{
	struct line *lp;	/* current line pointer */
	int offset;	/* original line offset position */
	int length;	/* current length */
	int inc;	/* increment to next line [sgn(n)] */

	if (curbp->b_mode & MDVIEW)	/* don't allow this command if      */
		return rdonly();	/* we are in read only mode     */

	if (f == FALSE)
		n = 1;

	/* loop thru trimming n lines */
	inc = ((n > 0) ? 1 : -1);
	while (n) {
		lp = curwp->w_dotp;	/* find current line text */
		offset = curwp->w_doto;	/* save original offset */
		length = lp->l_used;	/* find current length */

		/* trim the current line */
		while (length > offset) {
			if (lgetc(lp, length - 1) != ' ' &&
			    lgetc(lp, length - 1) != '\t')
				break;
			length--;
		}
		lp->l_used = length;

		/* advance/or back to the next line */
		forwline(TRUE, inc);
		n -= inc;
	}
	lchange(WFEDIT);
	thisflag &= ~CFCPCN;	/* flag that this resets the goal column */
	return TRUE;
}
#endif

/*
 * Open up some blank space. The basic plan is to insert a bunch of newlines,
 * and then back up over them. Everything is done by the subcommand
 * procerssors. They even handle the looping. Normally this is bound to "C-O".
 */
int openline(int f, int n)
{
	int i;
	int s;

	if (curbp->b_mode & MDVIEW)	/* don't allow this command if      */
		return rdonly();	/* we are in read only mode     */
	if (n < 0)
		return FALSE;
	if (n == 0)
		return TRUE;
	i = n;			/* Insert newlines.     */
	do {
		s = lnewline();
	} while (s == TRUE && --i);
	if (s == TRUE)		/* Then back up overtop */
		s = backchar(f, n);	/* of them all.         */
	return s;
}

/*
 * Insert a newline. Bound to "C-M". If we are in CMODE, do automatic
 * indentation as specified.
 */
int insert_newline(int f, int n)
{
	int s;

	if (curbp->b_mode & MDVIEW)	/* don't allow this command if      */
		return rdonly();	/* we are in read only mode     */
	if (n < 0)
		return FALSE;

	/* if we are in C mode and this is a default <NL> */
	if (n == 1 && (curbp->b_mode & MDCMOD) &&
	    curwp->w_dotp != curbp->b_linep)
		return cinsert();

	/*
	 * If a newline was typed, fill column is defined, the argument is non-
	 * negative, wrap mode is enabled, and we are now past fill column,
	 * and we are not read-only, perform word wrap.
	 */
	if ((curwp->w_bufp->b_mode & MDWRAP) && fillcol > 0 &&
	    getccol(FALSE) > fillcol &&
	    (curwp->w_bufp->b_mode & MDVIEW) == FALSE)
		execute(META | SPEC | 'W', FALSE, 1);

	/* insert some lines */
	while (n--) {
		if ((s = lnewline()) != TRUE)
			return s;
#if SCROLLCODE
		curwp->w_flag |= WFINS;
#endif
	}
	return TRUE;
}

int cinsert(void)
{				/* insert a newline and indentation for C */
	char *cptr;	/* string pointer into text to copy */
	int tptr;	/* index to scan into line */
	int bracef;	/* was there a brace at the end of line? */
	int i;
	char ichar[NSTRING];	/* buffer to hold indent of last line */

	/* grab a pointer to text to copy indentation from */
	cptr = &curwp->w_dotp->l_text[0];

	/* check for a brace */
	tptr = curwp->w_doto - 1;
	bracef = (cptr[tptr] == '{');

	/* save the indent of the previous line */
	i = 0;
	while ((i < tptr) && (cptr[i] == ' ' || cptr[i] == '\t')
	       && (i < NSTRING - 1)) {
		ichar[i] = cptr[i];
		++i;
	}
	ichar[i] = 0;		/* terminate it */

	/* put in the newline */
	if (lnewline() == FALSE)
		return FALSE;

	/* and the saved indentation */
	linstr(ichar);

	/* and one more tab for a brace */
	if (bracef)
		insert_tab(FALSE, 1);

#if SCROLLCODE
	curwp->w_flag |= WFINS;
#endif
	return TRUE;
}

#if	NBRACE
/*
 * insert a brace into the text here...we are in CMODE
 *
 * int n;	repeat count
 * int c;	brace to insert (always } for now)
 */
int insbrace(int n, int c)
{
	int ch;	/* last character before input */
	int oc;	/* caractere oppose a c */
	int i, count;
	int target;	/* column brace should go after */
	struct line *oldlp;
	int oldoff;

	/* if we aren't at the beginning of the line... */
	if (curwp->w_doto != 0)

		/* scan to see if all space before this is white space */
		for (i = curwp->w_doto - 1; i >= 0; --i) {
			ch = lgetc(curwp->w_dotp, i);
			if (ch != ' ' && ch != '\t')
				return linsert(n, c);
		}

	/* chercher le caractere oppose correspondant */
	switch (c) {
	case '}':
		oc = '{';
		break;
	case ']':
		oc = '[';
		break;
	case ')':
		oc = '(';
		break;
	default:
		return FALSE;
	}

	oldlp = curwp->w_dotp;
	oldoff = curwp->w_doto;

	count = 1;
	backchar(FALSE, 1);

	while (count > 0) {
		if (curwp->w_doto == llength(curwp->w_dotp))
			ch = '\n';
		else
			ch = lgetc(curwp->w_dotp, curwp->w_doto);

		if (ch == c)
			++count;
		if (ch == oc)
			--count;

		backchar(FALSE, 1);
		if (boundry(curwp->w_dotp, curwp->w_doto, REVERSE))
			break;
	}

	if (count != 0) {	/* no match */
		curwp->w_dotp = oldlp;
		curwp->w_doto = oldoff;
		return linsert(n, c);
	}

	curwp->w_doto = 0;	/* debut de ligne */
	/* aller au debut de la ligne apres la tabulation */
	while ((ch = lgetc(curwp->w_dotp, curwp->w_doto)) == ' '
	       || ch == '\t')
		forwchar(FALSE, 1);

	/* delete back first */
	target = getccol(FALSE);	/* c'est l'indent que l'on doit avoir */
	curwp->w_dotp = oldlp;
	curwp->w_doto = oldoff;

	while (target != getccol(FALSE)) {
		if (target < getccol(FALSE))	/* on doit detruire des caracteres */
			while (getccol(FALSE) > target)
				backdel(FALSE, 1);
		else {		/* on doit en inserer */
			while (target - getccol(FALSE) >= 8)
				linsert(1, '\t');
			linsert(target - getccol(FALSE), ' ');
		}
	}

	/* and insert the required brace(s) */
	return linsert(n, c);
}

#else

/*
 * insert a brace into the text here...we are in CMODE
 *
 * int n;		repeat count
 * int c;		brace to insert (always { for now)
 */
int insbrace(int n, int c)
{
	int ch;	/* last character before input */
	int i;
	int target;	/* column brace should go after */

	/* if we are at the beginning of the line, no go */
	if (curwp->w_doto == 0)
		return linsert(n, c);

	/* scan to see if all space before this is white space */
	for (i = curwp->w_doto - 1; i >= 0; --i) {
		ch = lgetc(curwp->w_dotp, i);
		if (ch != ' ' && ch != '\t')
			return linsert(n, c);
	}

	/* delete back first */
	target = getccol(FALSE);	/* calc where we will delete to */
	target -= 1;
	target -= target % (tabsize == 0 ? 8 : tabsize);
	while (getccol(FALSE) > target)
		backdel(FALSE, 1);

	/* and insert the required brace(s) */
	return linsert(n, c);
}
#endif

int inspound(void)
{				/* insert a # into the text here...we are in CMODE */
	int ch;	/* last character before input */
	int i;

	/* if we are at the beginning of the line, no go */
	if (curwp->w_doto == 0)
		return linsert(1, '#');

	/* scan to see if all space before this is white space */
	for (i = curwp->w_doto - 1; i >= 0; --i) {
		ch = lgetc(curwp->w_dotp, i);
		if (ch != ' ' && ch != '\t')
			return linsert(1, '#');
	}

	/* delete back first */
	while (getccol(FALSE) >= 1)
		backdel(FALSE, 1);

	/* and insert the required pound */
	return linsert(1, '#');
}

/*
 * Delete blank lines around dot. What this command does depends if dot is
 * sitting on a blank line. If dot is sitting on a blank line, this command
 * deletes all the blank lines above and below the current line. If it is
 * sitting on a non blank line then it deletes all of the blank lines after
 * the line. Normally this command is bound to "C-X C-O". Any argument is
 * ignored.
 */
int deblank(int f, int n)
{
	struct line *lp1;
	struct line *lp2;
	long nld;

	if (curbp->b_mode & MDVIEW)	/* don't allow this command if      */
		return rdonly();	/* we are in read only mode     */
	lp1 = curwp->w_dotp;
	while (llength(lp1) == 0 && (lp2 = lback(lp1)) != curbp->b_linep)
		lp1 = lp2;
	lp2 = lp1;
	nld = 0;
	while ((lp2 = lforw(lp2)) != curbp->b_linep && llength(lp2) == 0)
		++nld;
	if (nld == 0)
		return TRUE;
	curwp->w_dotp = lforw(lp1);
	curwp->w_doto = 0;
	return ldelete(nld, FALSE);
}

/*
 * Insert a newline, then enough tabs and spaces to duplicate the indentation
 * of the previous line. Assumes tabs are every eight characters. Quite simple.
 * Figure out the indentation of the current line. Insert a newline by calling
 * the standard routine. Insert the indentation by inserting the right number
 * of tabs and spaces. Return TRUE if all ok. Return FALSE if one of the
 * subcomands failed. Normally bound to "C-J".
 */
int indent(int f, int n)
{
	int nicol;
	int c;
	int i;

	if (curbp->b_mode & MDVIEW)	/* don't allow this command if      */
		return rdonly();	/* we are in read only mode     */
	if (n < 0)
		return FALSE;
	while (n--) {
		nicol = 0;
		for (i = 0; i < llength(curwp->w_dotp); ++i) {
			c = lgetc(curwp->w_dotp, i);
			if (c != ' ' && c != '\t')
				break;
			if (c == '\t')
				nicol |= tabmask;
			++nicol;
		}
		if (lnewline() == FALSE
		    || ((i = nicol / 8) != 0 && linsert(i, '\t') == FALSE)
		    || ((i = nicol % 8) != 0 && linsert(i, ' ') == FALSE))
			return FALSE;
	}
	return TRUE;
}

/*
 * Delete forward. This is real easy, because the basic delete routine does
 * all of the work. Watches for negative arguments, and does the right thing.
 * If any argument is present, it kills rather than deletes, to prevent loss
 * of text if typed with a big argument. Normally bound to "C-D".
 */
int forwdel(int f, int n)
{
	if (curbp->b_mode & MDVIEW)	/* don't allow this command if      */
		return rdonly();	/* we are in read only mode     */
	if (n < 0)
		return backdel(f, -n);
	if (f != FALSE) {	/* Really a kill.       */
		if ((lastflag & CFKILL) == 0)
			kdelete();
		thisflag |= CFKILL;
	}
	return ldelchar((long) n, f);
}

/*
 * Delete backwards. This is quite easy too, because it's all done with other
 * functions. Just move the cursor back, and delete forwards. Like delete
 * forward, this actually does a kill if presented with an argument. Bound to
 * both "RUBOUT" and "C-H".
 */
int backdel(int f, int n)
{
	int s;

	if (curbp->b_mode & MDVIEW)	/* don't allow this command if      */
		return rdonly();	/* we are in read only mode     */
	if (n < 0)
		return forwdel(f, -n);
	if (f != FALSE) {	/* Really a kill.       */
		if ((lastflag & CFKILL) == 0)
			kdelete();
		thisflag |= CFKILL;
	}
	if ((s = backchar(f, n)) == TRUE)
		s = ldelchar(n, f);
	return s;
}

/*
 * Kill text. If called without an argument, it kills from dot to the end of
 * the line, unless it is at the end of the line, when it kills the newline.
 * If called with an argument of 0, it kills from the start of the line to dot.
 * If called with a positive argument, it kills from dot forward over that
 * number of newlines. If called with a negative argument it kills backwards
 * that number of newlines. Normally bound to "C-K".
 */
int killtext(int f, int n)
{
	struct line *nextp;
	long chunk;

	if (curbp->b_mode & MDVIEW)	/* don't allow this command if      */
		return rdonly();	/* we are in read only mode     */
	if ((lastflag & CFKILL) == 0)	/* Clear kill buffer if */
		kdelete();	/* last wasn't a kill.  */
	thisflag |= CFKILL;
	if (f == FALSE) {
		chunk = llength(curwp->w_dotp) - curwp->w_doto;
		if (chunk == 0)
			chunk = 1;
	} else if (n == 0) {
		chunk = curwp->w_doto;
		curwp->w_doto = 0;
	} else if (n > 0) {
		chunk = llength(curwp->w_dotp) - curwp->w_doto + 1;
		nextp = lforw(curwp->w_dotp);
		while (--n) {
			if (nextp == curbp->b_linep)
				return FALSE;
			chunk += llength(nextp) + 1;
			nextp = lforw(nextp);
		}
	} else {
		mlwrite("neg kill");
		return FALSE;
	}
	return ldelete(chunk, TRUE);
}

/*
 * prompt and set an editor mode
 *
 * int f, n;		default and argument
 */
int setemode(int f, int n)
{
#if 	PKCODE
	return adjustmode(TRUE, FALSE);
#else
	adjustmode(TRUE, FALSE);
#endif
}

/*
 * prompt and delete an editor mode
 *
 * int f, n;		default and argument
 */
int delmode(int f, int n)
{
#if	PKCODE
	return adjustmode(FALSE, FALSE);
#else
	adjustmode(FALSE, FALSE);
#endif
}

/*
 * prompt and set a global editor mode
 *
 * int f, n;		default and argument
 */
int setgmode(int f, int n)
{
#if	PKCODE
	return adjustmode(TRUE, TRUE);
#else
	adjustmode(TRUE, TRUE);
#endif
}

/*
 * prompt and delete a global editor mode
 *
 * int f, n;		default and argument
 */
int delgmode(int f, int n)
{
#if	PKCODE
	return adjustmode(FALSE, TRUE);
#else
	adjustmode(FALSE, TRUE);
#endif
}

/*
 * change the editor mode status
 *
 * int kind;		true = set,          false = delete
 * int global;		true = global flag,  false = current buffer flag
 */
int adjustmode(int kind, int global)
{
	char *scan;	/* scanning pointer to convert prompt */
	int i;		/* loop index */
	int status;	/* error return on input */
#if	COLOR
	int uflag;	/* was modename uppercase?      */
#endif
	char prompt[50];	/* string to prompt user with */
	char cbuf[NPAT];	/* buffer to recieve mode name into */

	/* build the proper prompt string */
	if (global)
		strcpy(prompt, "Global mode to ");
	else
		strcpy(prompt, "Mode to ");

	if (kind == TRUE)
		strcat(prompt, "add: ");
	else
		strcat(prompt, "delete: ");

	/* prompt the user and get an answer */

	status = mlreply(prompt, cbuf, NPAT - 1);
	if (status != TRUE)
		return status;

	/* make it uppercase */

	scan = cbuf;
#if	COLOR
	uflag = (*scan >= 'A' && *scan <= 'Z');
#endif
	while (*scan != 0) {
		if (*scan >= 'a' && *scan <= 'z')
			*scan = *scan - 32;
		scan++;
	}

	/* test it first against the colors we know */
#if	PKCODE & IBMPC
	for (i = 0; i <= NCOLORS; i++) {
#else
	for (i = 0; i < NCOLORS; i++) {
#endif
		if (strcmp(cbuf, cname[i]) == 0) {
			/* finding the match, we set the color */
#if	COLOR
			if (uflag) {
				if (global)
					gfcolor = i;
#if	PKCODE == 0
				else
#endif
					curwp->w_fcolor = i;
			} else {
				if (global)
					gbcolor = i;
#if	PKCODE == 0
				else
#endif
					curwp->w_bcolor = i;
			}

			curwp->w_flag |= WFCOLR;
#endif
			mlerase();
			return TRUE;
		}
	}

	/* test it against the modes we know */

	for (i = 0; i < NUMMODES; i++) {
		if (strcmp(cbuf, modename[i]) == 0) {
			/* finding a match, we process it */
			if (kind == TRUE)
				if (global)
					gmode |= (1 << i);
				else
					curbp->b_mode |= (1 << i);
			else if (global)
				gmode &= ~(1 << i);
			else
				curbp->b_mode &= ~(1 << i);
			/* display new mode line */
			if (global == 0)
				upmode();
			mlerase();	/* erase the junk */
			return TRUE;
		}
	}

	mlwrite("No such mode!");
	return FALSE;
}

/*
 * This function simply clears the message line,
 * mainly for macro usage
 *
 * int f, n;		arguments ignored
 */
int clrmes(int f, int n)
{
	mlforce("");
	return TRUE;
}

/*
 * This function writes a string on the message line
 * mainly for macro usage
 *
 * int f, n;		arguments ignored
 */
int writemsg(int f, int n)
{
	char *sp;	/* pointer into buf to expand %s */
	char *np;	/* ptr into nbuf */
	int status;
	char buf[NPAT];		/* buffer to recieve message into */
	char nbuf[NPAT * 2];	/* buffer to expand string into */

	if ((status =
	     mlreply("Message to write: ", buf, NPAT - 1)) != TRUE)
		return status;

	/* expand all '%' to "%%" so mlwrite won't expect arguments */
	sp = buf;
	np = nbuf;
	while (*sp) {
		*np++ = *sp;
		if (*sp++ == '%')
			*np++ = '%';
	}
	*np = '\0';

	/* write the message out */
	mlforce(nbuf);
	return TRUE;
}

#if	CFENCE
/*
 * the cursor is moved to a matching fence
 *
 * int f, n;		not used
 */
int getfence(int f, int n)
{
	struct line *oldlp;	/* original line pointer */
	int oldoff;	/* and offset */
	int sdir;	/* direction of search (1/-1) */
	int count;	/* current fence level count */
	char ch;	/* fence type to match against */
	char ofence;	/* open fence */
	char c;	/* current character in scan */

	/* save the original cursor position */
	oldlp = curwp->w_dotp;
	oldoff = curwp->w_doto;

	/* get the current character */
	if (oldoff == llength(oldlp))
		ch = '\n';
	else
		ch = lgetc(oldlp, oldoff);

	/* setup proper matching fence */
	switch (ch) {
	case '(':
		ofence = ')';
		sdir = FORWARD;
		break;
	case '{':
		ofence = '}';
		sdir = FORWARD;
		break;
	case '[':
		ofence = ']';
		sdir = FORWARD;
		break;
	case ')':
		ofence = '(';
		sdir = REVERSE;
		break;
	case '}':
		ofence = '{';
		sdir = REVERSE;
		break;
	case ']':
		ofence = '[';
		sdir = REVERSE;
		break;
	default:
		TTbeep();
		return FALSE;
	}

	/* set up for scan */
	count = 1;
	if (sdir == REVERSE)
		backchar(FALSE, 1);
	else
		forwchar(FALSE, 1);

	/* scan until we find it, or reach the end of file */
	while (count > 0) {
		if (curwp->w_doto == llength(curwp->w_dotp))
			c = '\n';
		else
			c = lgetc(curwp->w_dotp, curwp->w_doto);
		if (c == ch)
			++count;
		if (c == ofence)
			--count;
		if (sdir == FORWARD)
			forwchar(FALSE, 1);
		else
			backchar(FALSE, 1);
		if (boundry(curwp->w_dotp, curwp->w_doto, sdir))
			break;
	}

	/* if count is zero, we have a match, move the sucker */
	if (count == 0) {
		if (sdir == FORWARD)
			backchar(FALSE, 1);
		else
			forwchar(FALSE, 1);
		curwp->w_flag |= WFMOVE;
		return TRUE;
	}

	/* restore the current position */
	curwp->w_dotp = oldlp;
	curwp->w_doto = oldoff;
	TTbeep();
	return FALSE;
}
#endif

/*
 * Close fences are matched against their partners, and if
 * on screen the cursor briefly lights there
 *
 * char ch;			fence type to match against
 */
int fmatch(int ch)
{
	struct line *oldlp;	/* original line pointer */
	int oldoff;	/* and offset */
	struct line *toplp;	/* top line in current window */
	int count;	/* current fence level count */
	char opench;	/* open fence */
	char c;	/* current character in scan */
	int i;

	/* first get the display update out there */
	update(FALSE);

	/* save the original cursor position */
	oldlp = curwp->w_dotp;
	oldoff = curwp->w_doto;

	/* setup proper open fence for passed close fence */
	if (ch == ')')
		opench = '(';
	else if (ch == '}')
		opench = '{';
	else
		opench = '[';

	/* find the top line and set up for scan */
	toplp = curwp->w_linep->l_bp;
	count = 1;
	backchar(FALSE, 2);

	/* scan back until we find it, or reach past the top of the window */
	while (count > 0 && curwp->w_dotp != toplp) {
		if (curwp->w_doto == llength(curwp->w_dotp))
			c = '\n';
		else
			c = lgetc(curwp->w_dotp, curwp->w_doto);
		if (c == ch)
			++count;
		if (c == opench)
			--count;
		backchar(FALSE, 1);
		if (curwp->w_dotp == curwp->w_bufp->b_linep->l_fp &&
		    curwp->w_doto == 0)
			break;
	}

	/* if count is zero, we have a match, display the sucker */
	/* there is a real machine dependant timing problem here we have
	   yet to solve......... */
	if (count == 0) {
		forwchar(FALSE, 1);
		for (i = 0; i < term.t_pause; i++)
			update(FALSE);
	}

	/* restore the current position */
	curwp->w_dotp = oldlp;
	curwp->w_doto = oldoff;
	return TRUE;
}

/*
 * ask for and insert a string into the current
 * buffer at the current point
 *
 * int f, n;		ignored arguments
 */
int istring(int f, int n)
{
	int status;	/* status return code */
	char tstring[NPAT + 1];	/* string to add */

	/* ask for string to insert */
	status =
	    mlreplyt("String to insert<META>: ", tstring, NPAT, metac);
	if (status != TRUE)
		return status;

	if (f == FALSE)
		n = 1;

	if (n < 0)
		n = -n;

	/* insert it */
	while (n-- && (status = linstr(tstring)));
	return status;
}

/*
 * ask for and overwite a string into the current
 * buffer at the current point
 *
 * int f, n;		ignored arguments
 */
int ovstring(int f, int n)
{
	int status;	/* status return code */
	char tstring[NPAT + 1];	/* string to add */

	/* ask for string to insert */
	status =
	    mlreplyt("String to overwrite<META>: ", tstring, NPAT, metac);
	if (status != TRUE)
		return status;

	if (f == FALSE)
		n = 1;

	if (n < 0)
		n = -n;

	/* insert it */
	while (n-- && (status = lover(tstring)));
	return status;
}


/* ----- region.c ----- */
/*	region.c
 *
 *      The routines in this file deal with the region, that magic space
 *      between "." and mark. Some functions are commands. Some functions are
 *      just for internal use.
 *
 *	Modified by Petri Kutvonen
 */
/* system header already included */
/* #include "estruct.h" - amalgamated */
/* #include "edef.h" - amalgamated */
/* #include "efunc.h" - amalgamated */
/* #include "line.h" - amalgamated */

/*
 * Kill the region. Ask "getregion"
 * to figure out the bounds of the region.
 * Move "." to the start, and kill the characters.
 * Bound to "C-W".
 */
int killregion(int f, int n)
{
	int s;
	struct region region;

	if (curbp->b_mode & MDVIEW)	/* don't allow this command if      */
		return rdonly();	/* we are in read only mode     */
	if ((s = getregion(&region)) != TRUE)
		return s;
	if ((lastflag & CFKILL) == 0)	/* This is a kill type  */
		kdelete();	/* command, so do magic */
	thisflag |= CFKILL;	/* kill buffer stuff.   */
	curwp->w_dotp = region.r_linep;
	curwp->w_doto = region.r_offset;
	return ldelete(region.r_size, TRUE);
}

/*
 * Copy all of the characters in the
 * region to the kill buffer. Don't move dot
 * at all. This is a bit like a kill region followed
 * by a yank. Bound to "M-W".
 */
int copyregion(int f, int n)
{
	struct line *linep;
	int loffs;
	int s;
	struct region region;

	if ((s = getregion(&region)) != TRUE)
		return s;
	if ((lastflag & CFKILL) == 0)	/* Kill type command.   */
		kdelete();
	thisflag |= CFKILL;
	linep = region.r_linep;	/* Current line.        */
	loffs = region.r_offset;	/* Current offset.      */
	while (region.r_size--) {
		if (loffs == llength(linep)) {	/* End of line.         */
			if ((s = kinsert('\n')) != TRUE)
				return s;
			linep = lforw(linep);
			loffs = 0;
		} else {	/* Middle of line.      */
			if ((s = kinsert(lgetc(linep, loffs))) != TRUE)
				return s;
			++loffs;
		}
	}
	mlwrite("(region copied)");
	return TRUE;
}

/*
 * Lower case region. Zap all of the upper
 * case characters in the region to lower case. Use
 * the region code to set the limits. Scan the buffer,
 * doing the changes. Call "lchange" to ensure that
 * redisplay is done in all buffers. Bound to
 * "C-X C-L".
 */
int lowerregion(int f, int n)
{
	struct line *linep;
	int loffs;
	int c;
	int s;
	struct region region;

	if (curbp->b_mode & MDVIEW)	/* don't allow this command if      */
		return rdonly();	/* we are in read only mode     */
	if ((s = getregion(&region)) != TRUE)
		return s;
	lchange(WFHARD);
	linep = region.r_linep;
	loffs = region.r_offset;
	while (region.r_size--) {
		if (loffs == llength(linep)) {
			linep = lforw(linep);
			loffs = 0;
		} else {
			c = lgetc(linep, loffs);
			if (c >= 'A' && c <= 'Z')
				lputc(linep, loffs, c + 'a' - 'A');
			++loffs;
		}
	}
	return TRUE;
}

/*
 * Upper case region. Zap all of the lower
 * case characters in the region to upper case. Use
 * the region code to set the limits. Scan the buffer,
 * doing the changes. Call "lchange" to ensure that
 * redisplay is done in all buffers. Bound to
 * "C-X C-L".
 */
int upperregion(int f, int n)
{
	struct line *linep;
	int loffs;
	int c;
	int s;
	struct region region;

	if (curbp->b_mode & MDVIEW)	/* don't allow this command if      */
		return rdonly();	/* we are in read only mode     */
	if ((s = getregion(&region)) != TRUE)
		return s;
	lchange(WFHARD);
	linep = region.r_linep;
	loffs = region.r_offset;
	while (region.r_size--) {
		if (loffs == llength(linep)) {
			linep = lforw(linep);
			loffs = 0;
		} else {
			c = lgetc(linep, loffs);
			if (c >= 'a' && c <= 'z')
				lputc(linep, loffs, c - 'a' + 'A');
			++loffs;
		}
	}
	return TRUE;
}

/*
 * This routine figures out the
 * bounds of the region in the current window, and
 * fills in the fields of the "struct region" structure pointed
 * to by "rp". Because the dot and mark are usually very
 * close together, we scan outward from dot looking for
 * mark. This should save time. Return a standard code.
 * Callers of this routine should be prepared to get
 * an "ABORT" status; we might make this have the
 * conform thing later.
 */
int getregion(struct region *rp)
{
	struct line *flp;
	struct line *blp;
	long fsize;
	long bsize;

	if (curwp->w_markp == NULL) {
		mlwrite("No mark set in this window");
		return FALSE;
	}
	if (curwp->w_dotp == curwp->w_markp) {
		rp->r_linep = curwp->w_dotp;
		if (curwp->w_doto < curwp->w_marko) {
			rp->r_offset = curwp->w_doto;
			rp->r_size =
			    (long) (curwp->w_marko - curwp->w_doto);
		} else {
			rp->r_offset = curwp->w_marko;
			rp->r_size =
			    (long) (curwp->w_doto - curwp->w_marko);
		}
		return TRUE;
	}
	blp = curwp->w_dotp;
	bsize = (long) curwp->w_doto;
	flp = curwp->w_dotp;
	fsize = (long) (llength(flp) - curwp->w_doto + 1);
	while (flp != curbp->b_linep || lback(blp) != curbp->b_linep) {
		if (flp != curbp->b_linep) {
			flp = lforw(flp);
			if (flp == curwp->w_markp) {
				rp->r_linep = curwp->w_dotp;
				rp->r_offset = curwp->w_doto;
				rp->r_size = fsize + curwp->w_marko;
				return TRUE;
			}
			fsize += llength(flp) + 1;
		}
		if (lback(blp) != curbp->b_linep) {
			blp = lback(blp);
			bsize += llength(blp) + 1;
			if (blp == curwp->w_markp) {
				rp->r_linep = blp;
				rp->r_offset = curwp->w_marko;
				rp->r_size = bsize - curwp->w_marko;
				return TRUE;
			}
		}
	}
	mlwrite("Bug: lost mark");
	return FALSE;
}


/* ----- search.c ----- */
/*	search.c
 *
 * The functions in this file implement commands that search in the forward
 * and backward directions.  There are no special characters in the search
 * strings.  Probably should have a regular expression search, or something
 * like that.
 *
 * Aug. 1986 John M. Gamble:
 *	Made forward and reverse search use the same scan routine.
 *
 *	Added a limited number of regular expressions - 'any',
 *	'character class', 'closure', 'beginning of line', and
 *	'end of line'.
 *
 *	Replacement metacharacters will have to wait for a re-write of
 *	the replaces function, and a new variation of ldelete().
 *
 *	For those curious as to my references, i made use of
 *	Kernighan & Plauger's "Software Tools."
 *	I deliberately did not look at any published grep or editor
 *	source (aside from this one) for inspiration.  I did make use of
 *	Allen Hollub's bitmap routines as published in Doctor Dobb's Journal,
 *	June, 1985 and modified them for the limited needs of character class
 *	matching.  Any inefficiences, bugs, stupid coding examples, etc.,
 *	are therefore my own responsibility.
 *
 * April 1987: John M. Gamble
 *	Deleted the "if (n == 0) n = 1;" statements in front of the
 *	search/hunt routines.  Since we now use a do loop, these
 *	checks are unnecessary.  Consolidated common code into the
 *	function delins().  Renamed global mclen matchlen,
 *	and added the globals matchline, matchoff, patmatch, and
 *	mlenold.
 *	This gave us the ability to unreplace regular expression searches,
 *	and to put the matched string into an evironment variable.
 *	SOON TO COME: Meta-replacement characters!
 *
 *	25-apr-87	DML
 *	- cleaned up an unneccessary if/else in forwsearch() and
 *	  backsearch()
 *	- savematch() failed to malloc room for the terminating byte
 *	  of the match string (stomp...stomp...). It does now. Also
 *	  it now returns gracefully if malloc fails
 *
 *	July 1987: John M. Gamble
 *	Set the variables matchlen and matchoff in the 'unreplace'
 *	section of replaces().  The function savematch() would
 *	get confused if you replaced, unreplaced, then replaced
 *	again (serves you right for being so wishy-washy...)
 *
 *	August 1987: John M. Gamble
 *	Put in new function rmcstr() to create the replacement
 *	meta-character array.  Modified delins() so that it knows
 *	whether or not to make use of the array.  And, put in the
 *	appropriate new structures and variables.
 *
 *	Modified by Petri Kutvonen
 */
/* system header already included */
/* #include "estruct.h" - amalgamated */
/* #include "edef.h" - amalgamated */
/* #include "efunc.h" - amalgamated */
/* #include "line.h" - amalgamated */

#if defined(MAGIC)
/*
 * The variables magical and rmagical determine if there
 * were actual metacharacters in the search and replace strings -
 * if not, then we don't have to use the slower MAGIC mode
 * search functions.
 */
static short int magical;
static short int rmagical;
static struct magic mcpat[NPAT]; /* The magic pattern. */
static struct magic tapcm[NPAT]; /* The reversed magic patterni. */
static struct magic_replacement rmcpat[NPAT]; /* The replacement magic array. */
#endif

static int amatch(struct magic *mcptr, int direct, struct line **pcwline, int *pcwoff);
static int readpattern(char *prompt, char *apat, int srch);
static int replaces(int kind, int f, int n);
static int nextch(struct line **pcurline, int *pcuroff, int dir);
static int mcstr(void);
static int rmcstr(void);
static int mceq(int bc, struct magic *mt);
static int cclmake(char **ppatptr, struct magic *mcptr);
static int biteq(int bc, char *cclmap);
static char *clearbits(void);
static void setbit(int bc, char *cclmap);

/*
 * forwsearch -- Search forward.  Get a search string from the user, and
 *	search for the string.  If found, reset the "." to be just after
 *	the match string, and (perhaps) repaint the display.
 *
 * int f, n;			default flag / numeric argument
 */
int forwsearch(int f, int n)
{
	int status = TRUE;

	/* If n is negative, search backwards.
	 * Otherwise proceed by asking for the search string.
	 */
	if (n < 0)
		return backsearch(f, -n);

	/* Ask the user for the text of a pattern.  If the
	 * response is TRUE (responses other than FALSE are
	 * possible), search for the pattern for as long as
	 * n is positive (n == 0 will go through once, which
	 * is just fine).
	 */
	if ((status = readpattern("Search", &pat[0], TRUE)) == TRUE) {
		do {
#if	MAGIC
			if ((magical
			     && curwp->w_bufp->b_mode & MDMAGIC) != 0)
				status =
				    mcscanner(&mcpat[0], FORWARD, PTEND);
			else
#endif
				status = scanner(&pat[0], FORWARD, PTEND);
		} while ((--n > 0) && status);

		/* Save away the match, or complain
		 * if not there.
		 */
		if (status == TRUE)
			savematch();
		else
			mlwrite("Not found");
	}
	return status;
}

/*
 * forwhunt -- Search forward for a previously acquired search string.
 *	If found, reset the "." to be just after the match string,
 *	and (perhaps) repaint the display.
 *
 * int f, n;		default flag / numeric argument
 */
int forwhunt(int f, int n)
{
	int status = TRUE;

	if (n < 0)		/* search backwards */
		return backhunt(f, -n);

	/* Make sure a pattern exists, or that we didn't switch
	 * into MAGIC mode until after we entered the pattern.
	 */
	if (pat[0] == '\0') {
		mlwrite("No pattern set");
		return FALSE;
	}
#if	MAGIC
	if ((curwp->w_bufp->b_mode & MDMAGIC) != 0 &&
	    mcpat[0].mc_type == MCNIL) {
		if (!mcstr())
			return FALSE;
	}
#endif

	/* Search for the pattern for as long as
	 * n is positive (n == 0 will go through once, which
	 * is just fine).
	 */
	do {
#if	MAGIC
		if ((magical && curwp->w_bufp->b_mode & MDMAGIC) != 0)
			status = mcscanner(&mcpat[0], FORWARD, PTEND);
		else
#endif
			status = scanner(&pat[0], FORWARD, PTEND);
	} while ((--n > 0) && status);

	/* Save away the match, or complain
	 * if not there.
	 */
	if (status == TRUE)
		savematch();
	else
		mlwrite("Not found");

	return status;
}

/*
 * backsearch -- Reverse search.  Get a search string from the user, and
 *	search, starting at "." and proceeding toward the front of the buffer.
 *	If found "." is left pointing at the first character of the pattern
 *	(the last character that was matched).
 *
 * int f, n;		default flag / numeric argument
 */
int backsearch(int f, int n)
{
	int status = TRUE;

	/* If n is negative, search forwards.
	 * Otherwise proceed by asking for the search string.
	 */
	if (n < 0)
		return forwsearch(f, -n);

	/* Ask the user for the text of a pattern.  If the
	 * response is TRUE (responses other than FALSE are
	 * possible), search for the pattern for as long as
	 * n is positive (n == 0 will go through once, which
	 * is just fine).
	 */
	if ((status =
	     readpattern("Reverse search", &pat[0], TRUE)) == TRUE) {
		do {
#if	MAGIC
			if ((magical
			     && curwp->w_bufp->b_mode & MDMAGIC) != 0)
				status =
				    mcscanner(&tapcm[0], REVERSE, PTBEG);
			else
#endif
				status = scanner(&tap[0], REVERSE, PTBEG);
		} while ((--n > 0) && status);

		/* Save away the match, or complain
		 * if not there.
		 */
		if (status == TRUE)
			savematch();
		else
			mlwrite("Not found");
	}
	return status;
}

/*
 * backhunt -- Reverse search for a previously acquired search string,
 *	starting at "." and proceeding toward the front of the buffer.
 *	If found "." is left pointing at the first character of the pattern
 *	(the last character that was matched).
 *
 * int f, n;		default flag / numeric argument
 */
int backhunt(int f, int n)
{
	int status = TRUE;

	if (n < 0)
		return forwhunt(f, -n);

	/* Make sure a pattern exists, or that we didn't switch
	 * into MAGIC mode until after we entered the pattern.
	 */
	if (tap[0] == '\0') {
		mlwrite("No pattern set");
		return FALSE;
	}
#if	MAGIC
	if ((curwp->w_bufp->b_mode & MDMAGIC) != 0 &&
	    tapcm[0].mc_type == MCNIL) {
		if (!mcstr())
			return FALSE;
	}
#endif

	/* Go search for it for as long as
	 * n is positive (n == 0 will go through once, which
	 * is just fine).
	 */
	do {
#if	MAGIC
		if ((magical && curwp->w_bufp->b_mode & MDMAGIC) != 0)
			status = mcscanner(&tapcm[0], REVERSE, PTBEG);
		else
#endif
			status = scanner(&tap[0], REVERSE, PTBEG);
	} while ((--n > 0) && status);

	/* Save away the match, or complain
	 * if not there.
	 */
	if (status == TRUE)
		savematch();
	else
		mlwrite("Not found");

	return status;
}

#if	MAGIC
/*
 * mcscanner -- Search for a meta-pattern in either direction.  If found,
 *	reset the "." to be at the start or just after the match string,
 *	and (perhaps) repaint the display.
 *
 * struct magic *mcpatrn;			pointer into pattern
 * int direct;			which way to go.
 * int beg_or_end;		put point at beginning or end of pattern.
 */
int mcscanner(struct magic *mcpatrn, int direct, int beg_or_end)
{
	struct line *curline;		/* current line during scan */
	int curoff;		/* position within current line */

	/* If we are going in reverse, then the 'end' is actually
	 * the beginning of the pattern.  Toggle it.
	 */
	beg_or_end ^= direct;

	/*
	 * Save the old matchlen length, in case it is
	 * very different (closure) from the old length.
	 * This is important for query-replace undo
	 * command.
	 */
	mlenold = matchlen;

	/* Setup local scan pointers to global ".".
	 */
	curline = curwp->w_dotp;
	curoff = curwp->w_doto;

	/* Scan each character until we hit the head link record.
	 */
	while (!boundry(curline, curoff, direct)) {
		/* Save the current position in case we need to
		 * restore it on a match, and initialize matchlen to
		 * zero in case we are doing a search for replacement.
		 */
		matchline = curline;
		matchoff = curoff;
		matchlen = 0;

		if (amatch(mcpatrn, direct, &curline, &curoff)) {
			/* A SUCCESSFULL MATCH!!!
			 * reset the global "." pointers.
			 */
			if (beg_or_end == PTEND) {	/* at end of string */
				curwp->w_dotp = curline;
				curwp->w_doto = curoff;
			} else {	/* at beginning of string */

				curwp->w_dotp = matchline;
				curwp->w_doto = matchoff;
			}

			curwp->w_flag |= WFMOVE;	/* flag that we have moved */
			return TRUE;
		}

		/* Advance the cursor.
		 */
		nextch(&curline, &curoff, direct);
	}

	return FALSE;		/* We could not find a match. */
}

/*
 * amatch -- Search for a meta-pattern in either direction.  Based on the
 *	recursive routine amatch() (for "anchored match") in
 *	Kernighan & Plauger's "Software Tools".
 *
 * struct magic *mcptr;		string to scan for
 * int direct;		which way to go.
 * struct line **pcwline;	current line during scan
 * int *pcwoff;		position within current line
 */
static int amatch(struct magic *mcptr, int direct, struct line **pcwline, int *pcwoff)
{
	int c;		/* character at current position */
	struct line *curline;		/* current line during scan */
	int curoff;		/* position within current line */
	int nchars;

	/* Set up local scan pointers to ".", and get
	 * the current character.  Then loop around
	 * the pattern pointer until success or failure.
	 */
	curline = *pcwline;
	curoff = *pcwoff;

	/* The beginning-of-line and end-of-line metacharacters
	 * do not compare against characters, they compare
	 * against positions.
	 * BOL is guaranteed to be at the start of the pattern
	 * for forward searches, and at the end of the pattern
	 * for reverse searches.  The reverse is true for EOL.
	 * So, for a start, we check for them on entry.
	 */
	if (mcptr->mc_type == BOL) {
		if (curoff != 0)
			return FALSE;
		mcptr++;
	}

	if (mcptr->mc_type == EOL) {
		if (curoff != llength(curline))
			return FALSE;
		mcptr++;
	}

	while (mcptr->mc_type != MCNIL) {
		c = nextch(&curline, &curoff, direct);

		if (mcptr->mc_type & CLOSURE) {
			/* Try to match as many characters as possible
			 * against the current meta-character.  A
			 * newline never matches a closure.
			 */
			nchars = 0;
			while (c != '\n' && mceq(c, mcptr)) {
				c = nextch(&curline, &curoff, direct);
				nchars++;
			}

			/* We are now at the character that made us
			 * fail.  Try to match the rest of the pattern.
			 * Shrink the closure by one for each failure.
			 * Since closure matches *zero* or more occurences
			 * of a pattern, a match may start even if the
			 * previous loop matched no characters.
			 */
			mcptr++;

			for (;;) {
				c = nextch(&curline, &curoff,
					   direct ^ REVERSE);

				if (amatch
				    (mcptr, direct, &curline, &curoff)) {
					matchlen += nchars;
					goto success;
				}

				if (nchars-- == 0)
					return FALSE;
			}
		} else {	/* Not closure. */

			/* The only way we'd get a BOL metacharacter
			 * at this point is at the end of the reversed pattern.
			 * The only way we'd get an EOL metacharacter
			 * here is at the end of a regular pattern.
			 * So if we match one or the other, and are at
			 * the appropriate position, we are guaranteed success
			 * (since the next pattern character has to be MCNIL).
			 * Before we report success, however, we back up by
			 * one character, so as to leave the cursor in the
			 * correct position.  For example, a search for ")$"
			 * will leave the cursor at the end of the line, while
			 * a search for ")<NL>" will leave the cursor at the
			 * beginning of the next line.  This follows the
			 * notion that the meta-character '$' (and likewise
			 * '^') match positions, not characters.
			 */
			if (mcptr->mc_type == BOL) {
				if (curoff == llength(curline)) {
					c = nextch(&curline, &curoff,
						   direct ^ REVERSE);
					goto success;
				} else
					return FALSE;
			}

			if (mcptr->mc_type == EOL) {
				if (curoff == 0) {
					c = nextch(&curline, &curoff,
						   direct ^ REVERSE);
					goto success;
				} else
					return FALSE;
			}

			/* Neither BOL nor EOL, so go through
			 * the meta-character equal function.
			 */
			if (!mceq(c, mcptr))
				return FALSE;
		}

		/* Increment the length counter and
		 * advance the pattern pointer.
		 */
		matchlen++;
		mcptr++;
	}			/* End of mcptr loop. */

	/* A SUCCESSFULL MATCH!!!
	 * Reset the "." pointers.
	 */
      success:
	*pcwline = curline;
	*pcwoff = curoff;

	return TRUE;
}
#endif

/*
 * scanner -- Search for a pattern in either direction.  If found,
 *	reset the "." to be at the start or just after the match string,
 *	and (perhaps) repaint the display.
 *
 * unsigned char *patrn;	string to scan for
 * int direct;			which way to go.
 * int beg_or_end;		put point at beginning or end of pattern.
 */
int scanner(const char *patrn, int direct, int beg_or_end)
{
	int c;		/* character at current position */
	const char *patptr;	/* pointer into pattern */
	struct line *curline;		/* current line during scan */
	int curoff;		/* position within current line */
	struct line *scanline;		/* current line during scanning */
	int scanoff;		/* position in scanned line */

	/* If we are going in reverse, then the 'end' is actually
	 * the beginning of the pattern.  Toggle it.
	 */
	beg_or_end ^= direct;

	/* Set up local pointers to global ".".
	 */
	curline = curwp->w_dotp;
	curoff = curwp->w_doto;

	/* Scan each character until we hit the head link record.
	 */
	while (!boundry(curline, curoff, direct)) {
		/* Save the current position in case we match
		 * the search string at this point.
		 */
		matchline = curline;
		matchoff = curoff;

		/* Get the character resolving newlines, and
		 * test it against first char in pattern.
		 */
		c = nextch(&curline, &curoff, direct);

		if (eq(c, patrn[0])) {	/* if we find it.. */
			/* Setup scanning pointers.
			 */
			scanline = curline;
			scanoff = curoff;
			patptr = &patrn[0];

			/* Scan through the pattern for a match.
			 */
			while (*++patptr != '\0') {
				c = nextch(&scanline, &scanoff, direct);

				if (!eq(c, *patptr))
					goto fail;
			}

			/* A SUCCESSFULL MATCH!!!
			 * reset the global "." pointers
			 */
			if (beg_or_end == PTEND) {	/* at end of string */
				curwp->w_dotp = scanline;
				curwp->w_doto = scanoff;
			} else {	/* at beginning of string */

				curwp->w_dotp = matchline;
				curwp->w_doto = matchoff;
			}

			curwp->w_flag |= WFMOVE;	/* Flag that we have moved. */
			return TRUE;

		}
	      fail:;		/* continue to search */
	}

	return FALSE;		/* We could not find a match */
}

/*
 * eq -- Compare two characters.  The "bc" comes from the buffer, "pc"
 *	from the pattern.  If we are not in EXACT mode, fold out the case.
 */
int eq(unsigned char bc, unsigned char pc)
{
	if ((curwp->w_bufp->b_mode & MDEXACT) == 0) {
		if (islower(bc))
			bc ^= DIFCASE;

		if (islower(pc))
			pc ^= DIFCASE;
	}

	return bc == pc;
}

/*
 * readpattern -- Read a pattern.  Stash it in apat.  If it is the
 *	search string, create the reverse pattern and the magic
 *	pattern, assuming we are in MAGIC mode (and defined that way).
 *	Apat is not updated if the user types in an empty line.  If
 *	the user typed an empty line, and there is no old pattern, it is
 *	an error.  Display the old pattern, in the style of Jeff Lomicka.
 *	There is some do-it-yourself control expansion.  Change to using
 *	<META> to delimit the end-of-pattern to allow <NL>s in the search
 *	string. 
 */
static int readpattern(char *prompt, char *apat, int srch)
{
	int status;
	char tpat[NPAT + 20];

	strcpy(tpat, prompt);	/* copy prompt to output string */
	strcat(tpat, " (");	/* build new prompt string */
	expandp(&apat[0], &tpat[strlen(tpat)], NPAT / 2);	/* add old pattern */
	strcat(tpat, ")<Meta>: ");

	/* Read a pattern.  Either we get one,
	 * or we just get the META charater, and use the previous pattern.
	 * Then, if it's the search string, make a reversed pattern.
	 * *Then*, make the meta-pattern, if we are defined that way.
	 */
	if ((status = mlreplyt(tpat, tpat, NPAT, metac)) == TRUE) {
		strcpy(apat, tpat);
		if (srch) {	/* If we are doing the search string. */
			/* Reverse string copy, and remember
			 * the length for substitution purposes.
			 */
			rvstrcpy(tap, apat);
			mlenold = matchlen = strlen(apat);
		}
#if	MAGIC
		/* Only make the meta-pattern if in magic mode,
		 * since the pattern in question might have an
		 * invalid meta combination.
		 */
		if ((curwp->w_bufp->b_mode & MDMAGIC) == 0) {
			mcclear();
			rmcclear();
		} else
			status = srch ? mcstr() : rmcstr();
#endif
	} else if (status == FALSE && apat[0] != 0)	/* Old one */
		status = TRUE;

	return status;
}

/*
 * savematch -- We found the pattern?  Let's save it away.
 */
void savematch(void)
{
	char *ptr;	/* pointer to last match string */
	int j;
	struct line *curline;		/* line of last match */
	int curoff;		/* offset "      "    */

	/* Free any existing match string, then
	 * attempt to allocate a new one.
	 */
	if (patmatch != NULL)
		free(patmatch);

	ptr = patmatch = malloc(matchlen + 1);

	if (ptr != NULL) {
		curoff = matchoff;
		curline = matchline;

		for (j = 0; j < matchlen; j++)
			*ptr++ = nextch(&curline, &curoff, FORWARD);

		*ptr = '\0';
	}
}

/*
 * rvstrcpy -- Reverse string copy.
 */
void rvstrcpy(char *rvstr, char *str)
{
	int i;

	str += (i = strlen(str));

	while (i-- > 0)
		*rvstr++ = *--str;

	*rvstr = '\0';
}

/*
 * sreplace -- Search and replace.
 *
 * int f;		default flag
 * int n;		# of repetitions wanted
 */
int sreplace(int f, int n)
{
	return replaces(FALSE, f, n);
}

/*
 * qreplace -- search and replace with query.
 *
 * int f;		default flag
 * int n;		# of repetitions wanted
 */
int qreplace(int f, int n)
{
	return replaces(TRUE, f, n);
}

/*
 * replaces -- Search for a string and replace it with another
 *	string.  Query might be enabled (according to kind).
 *
 * int kind;		Query enabled flag
 * int f;		default flag
 * int n;		# of repetitions wanted
 */
static int replaces(int kind, int f, int n)
{
	int status;	/* success flag on pattern inputs */
	int rlength;	/* length of replacement string */
	int numsub;	/* number of substitutions */
	int nummatch;	/* number of found matches */
	int nlflag;		/* last char of search string a <NL>? */
	int nlrepl;		/* was a replace done on the last line? */
	char c;			/* input char for query */
	char tpat[NPAT];	/* temporary to hold search pattern */
	struct line *origline;		/* original "." position */
	int origoff;		/* and offset (for . query option) */
	struct line *lastline;		/* position of last replace and */
	int lastoff;		/* offset (for 'u' query option) */

	if (curbp->b_mode & MDVIEW)	/* don't allow this command if      */
		return rdonly();	/* we are in read only mode     */

	/* Check for negative repetitions.
	 */
	if (f && n < 0)
		return FALSE;

	/* Ask the user for the text of a pattern.
	 */
	if ((status = readpattern((kind ==
				   FALSE ? "Replace" : "Query replace"),
				  &pat[0], TRUE))
	    != TRUE)
		return status;

	/* Ask for the replacement string.
	 */
	if ((status = readpattern("with", &rpat[0], FALSE)) == ABORT)
		return status;

	/* Find the length of the replacement string.
	 */
	rlength = strlen(&rpat[0]);

	/* Set up flags so we can make sure not to do a recursive
	 * replace on the last line.
	 */
	nlflag = (pat[matchlen - 1] == '\n');
	nlrepl = FALSE;

	if (kind) {
		/* Build query replace question string.
		 */
		strcpy(tpat, "Replace '");
		expandp(&pat[0], &tpat[strlen(tpat)], NPAT / 3);
		strcat(tpat, "' with '");
		expandp(&rpat[0], &tpat[strlen(tpat)], NPAT / 3);
		strcat(tpat, "'? ");

		/* Initialize last replaced pointers.
		 */
		lastline = NULL;
		lastoff = 0;
	}

	/* Save original . position, init the number of matches and
	 * substitutions, and scan through the file.
	 */
	origline = curwp->w_dotp;
	origoff = curwp->w_doto;
	numsub = 0;
	nummatch = 0;

	while ((f == FALSE || n > nummatch) &&
	       (nlflag == FALSE || nlrepl == FALSE)) {
		/* Search for the pattern.
		 * If we search with a regular expression,
		 * matchlen is reset to the true length of
		 * the matched string.
		 */
#if	MAGIC
		if ((magical && curwp->w_bufp->b_mode & MDMAGIC) != 0) {
			if (!mcscanner(&mcpat[0], FORWARD, PTBEG))
				break;
		} else
#endif
		if (!scanner(&pat[0], FORWARD, PTBEG))
			break;	/* all done */

		++nummatch;	/* Increment # of matches */

		/* Check if we are on the last line.
		 */
		nlrepl = (lforw(curwp->w_dotp) == curwp->w_bufp->b_linep);

		/* Check for query.
		 */
		if (kind) {
			/* Get the query.
			 */
		      pprompt:mlwrite(&tpat[0], &pat[0],
				&rpat[0]);
		      qprompt:
			update(TRUE);	/* show the proposed place to change */
			c = tgetc();	/* and input */
			mlwrite("");	/* and clear it */

			/* And respond appropriately.
			 */
			switch (c) {
#if	PKCODE
			case 'Y':
#endif
			case 'y':	/* yes, substitute */
			case ' ':
				savematch();
				break;

#if	PKCODE
			case 'N':
#endif
			case 'n':	/* no, onword */
				forwchar(FALSE, 1);
				continue;

			case '!':	/* yes/stop asking */
				kind = FALSE;
				break;

#if	PKCODE
			case 'U':
#endif
			case 'u':	/* undo last and re-prompt */

				/* Restore old position.
				 */
				if (lastline == NULL) {
					/* There is nothing to undo.
					 */
					TTbeep();
					goto pprompt;
				}
				curwp->w_dotp = lastline;
				curwp->w_doto = lastoff;
				lastline = NULL;
				lastoff = 0;

				/* Delete the new string.
				 */
				backchar(FALSE, rlength);
#if	PKCODE
				matchline = curwp->w_dotp;
				matchoff = curwp->w_doto;
#endif
				status = delins(rlength, patmatch, FALSE);
				if (status != TRUE)
					return status;

				/* Record one less substitution,
				 * backup, save our place, and
				 * reprompt.
				 */
				--numsub;
				backchar(FALSE, mlenold);
				matchline = curwp->w_dotp;
				matchoff = curwp->w_doto;
				goto pprompt;

			case '.':	/* abort! and return */
				/* restore old position */
				curwp->w_dotp = origline;
				curwp->w_doto = origoff;
				curwp->w_flag |= WFMOVE;

			case BELL:	/* abort! and stay */
				mlwrite("Aborted!");
				return FALSE;

			default:	/* bitch and beep */
				TTbeep();

			case '?':	/* help me */
				mlwrite
				    ("(Y)es, (N)o, (!)Do rest, (U)ndo last, (^G)Abort, (.)Abort back, (?)Help: ");
				goto qprompt;

			}	/* end of switch */
		}

		/* end of "if kind" */
		/*
		 * Delete the sucker, and insert its
		 * replacement.
		 */
		status = delins(matchlen, &rpat[0], TRUE);
		if (status != TRUE)
			return status;

		/* Save our position, since we may
		 * undo this.
		 */
		if (kind) {
			lastline = curwp->w_dotp;
			lastoff = curwp->w_doto;
		}

		numsub++;	/* increment # of substitutions */
	}

	/* And report the results.
	 */
	mlwrite("%d substitutions", numsub);
	return TRUE;
}

/*
 * delins -- Delete a specified length from the current point
 *	then either insert the string directly, or make use of
 *	replacement meta-array.
 */
int delins(int dlength, char *instr, int use_meta)
{
	int status;
#if	MAGIC
	struct magic_replacement *rmcptr;
#endif

	/* Zap what we gotta,
	 * and insert its replacement.
	 */
	if ((status = ldelete((long) dlength, FALSE)) != TRUE)
		mlwrite("%%ERROR while deleting");
	else
#if	MAGIC
	if ((rmagical && use_meta) &&
		    (curwp->w_bufp->b_mode & MDMAGIC) != 0) {
		rmcptr = &rmcpat[0];
		while (rmcptr->mc_type != MCNIL && status == TRUE) {
			if (rmcptr->mc_type == LITCHAR)
				status = linstr(rmcptr->rstr);
			else
				status = linstr(patmatch);
			rmcptr++;
		}
	} else
#endif
		status = linstr(instr);

	return status;
}

/*
 * expandp -- Expand control key sequences for output.
 *
 * char *srcstr;		string to expand
 * char *deststr;		destination of expanded string
 * int maxlength;		maximum chars in destination
 */
int expandp(char *srcstr, char *deststr, int maxlength)
{
	unsigned char c;	/* current char to translate */

	/* Scan through the string.
	 */
	while ((c = *srcstr++) != 0) {
		if (c == '\n') {	/* it's a newline */
			*deststr++ = '<';
			*deststr++ = 'N';
			*deststr++ = 'L';
			*deststr++ = '>';
			maxlength -= 4;
		}
#if	PKCODE
		else if ((c > 0 && c < 0x20) || c == 0x7f)	/* control character */
#else
		else if (c < 0x20 || c == 0x7f)	/* control character */
#endif
		{
			*deststr++ = '^';
			*deststr++ = c ^ 0x40;
			maxlength -= 2;
		} else if (c == '%') {
			*deststr++ = '%';
			*deststr++ = '%';
			maxlength -= 2;
		} else {	/* any other character */

			*deststr++ = c;
			maxlength--;
		}

		/* check for maxlength */
		if (maxlength < 4) {
			*deststr++ = '$';
			*deststr = '\0';
			return FALSE;
		}
	}
	*deststr = '\0';
	return TRUE;
}

/*
 * boundry -- Return information depending on whether we may search no
 *	further.  Beginning of file and end of file are the obvious
 *	cases, but we may want to add further optional boundry restrictions
 *	in future, a' la VMS EDT.  At the moment, just return TRUE or
 *	FALSE depending on if a boundry is hit (ouch).
 */
int boundry(struct line *curline, int curoff, int dir)
{
	int border;

	if (dir == FORWARD) {
		border = (curoff == llength(curline)) &&
		    (lforw(curline) == curbp->b_linep);
	} else {
		border = (curoff == 0) &&
		    (lback(curline) == curbp->b_linep);
	}
	return border;
}

/*
 * nextch -- retrieve the next/previous character in the buffer,
 *	and advance/retreat the point.
 *	The order in which this is done is significant, and depends
 *	upon the direction of the search.  Forward searches look at
 *	the current character and move, reverse searches move and
 *	look at the character.
 */
static int nextch(struct line **pcurline, int *pcuroff, int dir)
{
	struct line *curline;
	int curoff;
	int c;

	curline = *pcurline;
	curoff = *pcuroff;

	if (dir == FORWARD) {
		if (curoff == llength(curline)) {	/* if at EOL */
			curline = lforw(curline);	/* skip to next line */
			curoff = 0;
			c = '\n';	/* and return a <NL> */
		} else
			c = lgetc(curline, curoff++);	/* get the char */
	} else {		/* Reverse. */

		if (curoff == 0) {
			curline = lback(curline);
			curoff = llength(curline);
			c = '\n';
		} else
			c = lgetc(curline, --curoff);

	}
	*pcurline = curline;
	*pcuroff = curoff;

	return c;
}

#if	MAGIC
/*
 * mcstr -- Set up the 'magic' array.  The closure symbol is taken as
 *	a literal character when (1) it is the first character in the
 *	pattern, and (2) when preceded by a symbol that does not allow
 *	closure, such as a newline, beginning of line symbol, or another
 *	closure symbol.
 *
 *	Coding comment (jmg):  yes, i know i have gotos that are, strictly
 *	speaking, unnecessary.  But right now we are so cramped for
 *	code space that i will grab what i can in order to remain
 *	within the 64K limit.  C compilers actually do very little
 *	in the way of optimizing - they expect you to do that.
 */
static int mcstr(void)
{
	struct magic *mcptr, *rtpcm;
	char *patptr;
	int mj;
	int pchr;
	int status = TRUE;
	int does_closure = FALSE;

	/* If we had metacharacters in the struct magic array previously,
	 * free up any bitmaps that may have been allocated.
	 */
	if (magical)
		mcclear();

	magical = FALSE;
	mj = 0;
	mcptr = &mcpat[0];
	patptr = &pat[0];

	while ((pchr = *patptr) && status) {
		switch (pchr) {
		case MC_CCL:
			status = cclmake(&patptr, mcptr);
			magical = TRUE;
			does_closure = TRUE;
			break;
		case MC_BOL:
			if (mj != 0)
				goto litcase;

			mcptr->mc_type = BOL;
			magical = TRUE;
			does_closure = FALSE;
			break;
		case MC_EOL:
			if (*(patptr + 1) != '\0')
				goto litcase;

			mcptr->mc_type = EOL;
			magical = TRUE;
			does_closure = FALSE;
			break;
		case MC_ANY:
			mcptr->mc_type = ANY;
			magical = TRUE;
			does_closure = TRUE;
			break;
		case MC_CLOSURE:
			/* Does the closure symbol mean closure here?
			 * If so, back up to the previous element
			 * and indicate it is enclosed.
			 */
			if (!does_closure)
				goto litcase;
			mj--;
			mcptr--;
			mcptr->mc_type |= CLOSURE;
			magical = TRUE;
			does_closure = FALSE;
			break;

			/* Note: no break between MC_ESC case and the default.
			 */
		case MC_ESC:
			if (*(patptr + 1) != '\0') {
				pchr = *++patptr;
				magical = TRUE;
			}
		default:
		      litcase:mcptr->mc_type =
			    LITCHAR;
			mcptr->u.lchar = pchr;
			does_closure = (pchr != '\n');
			break;
		}		/* End of switch. */
		mcptr++;
		patptr++;
		mj++;
	}			/* End of while. */

	/* Close off the meta-string.
	 */
	mcptr->mc_type = MCNIL;

	/* Set up the reverse array, if the status is good.  Please note the
	 * structure assignment - your compiler may not like that.
	 * If the status is not good, nil out the meta-pattern.
	 * The only way the status would be bad is from the cclmake()
	 * routine, and the bitmap for that member is guarenteed to be
	 * freed.  So we stomp a MCNIL value there, and call mcclear()
	 * to free any other bitmaps.
	 */
	if (status) {
		rtpcm = &tapcm[0];
		while (--mj >= 0) {
#if	MSC | TURBO | VMS | USG | BSD | V7
			*rtpcm++ = *--mcptr;
#endif
		}
		rtpcm->mc_type = MCNIL;
	} else {
		(--mcptr)->mc_type = MCNIL;
		mcclear();
	}

	return status;
}

/*
 * rmcstr -- Set up the replacement 'magic' array.  Note that if there
 *	are no meta-characters encountered in the replacement string,
 *	the array is never actually created - we will just use the
 *	character array rpat[] as the replacement string.
 */
static int rmcstr(void)
{
	struct magic_replacement *rmcptr;
	char *patptr;
	int status = TRUE;
	int mj;

	patptr = &rpat[0];
	rmcptr = &rmcpat[0];
	mj = 0;
	rmagical = FALSE;

	while (*patptr && status == TRUE) {
		switch (*patptr) {
		case MC_DITTO:

			/* If there were non-magical characters
			 * in the string before reaching this
			 * character, plunk it in the replacement
			 * array before processing the current
			 * meta-character.
			 */
			if (mj != 0) {
				rmcptr->mc_type = LITCHAR;
				if ((rmcptr->rstr =
				     malloc(mj + 1)) == NULL) {
					mlwrite("%%Out of memory");
					status = FALSE;
					break;
				}
				strncpy(rmcptr->rstr, patptr - mj, mj);
				rmcptr++;
				mj = 0;
			}
			rmcptr->mc_type = DITTO;
			rmcptr++;
			rmagical = TRUE;
			break;

		case MC_ESC:
			rmcptr->mc_type = LITCHAR;

			/* We malloc mj plus two here, instead
			 * of one, because we have to count the
			 * current character.
			 */
			if ((rmcptr->rstr = malloc(mj + 2)) == NULL) {
				mlwrite("%%Out of memory");
				status = FALSE;
				break;
			}

			strncpy(rmcptr->rstr, patptr - mj, mj + 1);

			/* If MC_ESC is not the last character
			 * in the string, find out what it is
			 * escaping, and overwrite the last
			 * character with it.
			 */
			if (*(patptr + 1) != '\0')
				*((rmcptr->rstr) + mj) = *++patptr;

			rmcptr++;
			mj = 0;
			rmagical = TRUE;
			break;

		default:
			mj++;
		}
		patptr++;
	}

	if (rmagical && mj > 0) {
		rmcptr->mc_type = LITCHAR;
		if ((rmcptr->rstr = malloc(mj + 1)) == NULL) {
			mlwrite("%%Out of memory.");
			status = FALSE;
		}
		strncpy(rmcptr->rstr, patptr - mj, mj);
		rmcptr++;
	}

	rmcptr->mc_type = MCNIL;
	return status;
}

/*
 * mcclear -- Free up any CCL bitmaps, and MCNIL the struct magic search arrays.
 */
void mcclear(void)
{
	struct magic *mcptr;

	mcptr = &mcpat[0];

	while (mcptr->mc_type != MCNIL) {
		if ((mcptr->mc_type & MASKCL) == CCL ||
		    (mcptr->mc_type & MASKCL) == NCCL)
			free(mcptr->u.cclmap);
		mcptr++;
	}
	mcpat[0].mc_type = tapcm[0].mc_type = MCNIL;
}

/*
 * rmcclear -- Free up any strings, and MCNIL the struct magic_replacement array.
 */
void rmcclear(void)
{
	struct magic_replacement *rmcptr;

	rmcptr = &rmcpat[0];

	while (rmcptr->mc_type != MCNIL) {
		if (rmcptr->mc_type == LITCHAR)
			free(rmcptr->rstr);
		rmcptr++;
	}

	rmcpat[0].mc_type = MCNIL;
}

/*
 * mceq -- meta-character equality with a character.  In Kernighan & Plauger's
 *	Software Tools, this is the function omatch(), but i felt there
 *	were too many functions with the 'match' name already.
 */
static int mceq(int bc, struct magic *mt)
{
	int result;

#if	PKCODE
	bc = bc & 0xFF;
#endif
	switch (mt->mc_type & MASKCL) {
	case LITCHAR:
		result = eq(bc, mt->u.lchar);
		break;

	case ANY:
		result = (bc != '\n');
		break;

	case CCL:
		if (!(result = biteq(bc, mt->u.cclmap))) {
			if ((curwp->w_bufp->b_mode & MDEXACT) == 0 &&
			    (isletter(bc))) {
				result = biteq(CHCASE(bc), mt->u.cclmap);
			}
		}
		break;

	case NCCL:
		result = !biteq(bc, mt->u.cclmap);

		if ((curwp->w_bufp->b_mode & MDEXACT) == 0 &&
		    (isletter(bc))) {
			result &= !biteq(CHCASE(bc), mt->u.cclmap);
		}
		break;

	default:
		mlwrite("mceq: what is %d?", mt->mc_type);
		result = FALSE;
		break;

	}			/* End of switch. */

	return result;
}

extern char *clearbits(void);

/*
 * cclmake -- create the bitmap for the character class.
 *	ppatptr is left pointing to the end-of-character-class character,
 *	so that a loop may automatically increment with safety.
 */
static int cclmake(char **ppatptr, struct magic *mcptr)
{
	char *bmap;
	char *patptr;
	int pchr, ochr;

	if ((bmap = clearbits()) == NULL) {
		mlwrite("%%Out of memory");
		return FALSE;
	}

	mcptr->u.cclmap = bmap;
	patptr = *ppatptr;

	/*
	 * Test the initial character(s) in ccl for
	 * special cases - negate ccl, or an end ccl
	 * character as a first character.  Anything
	 * else gets set in the bitmap.
	 */
	if (*++patptr == MC_NCCL) {
		patptr++;
		mcptr->mc_type = NCCL;
	} else
		mcptr->mc_type = CCL;

	if ((ochr = *patptr) == MC_ECCL) {
		mlwrite("%%No characters in character class");
		return FALSE;
	} else {
		if (ochr == MC_ESC)
			ochr = *++patptr;

		setbit(ochr, bmap);
		patptr++;
	}

	while (ochr != '\0' && (pchr = *patptr) != MC_ECCL) {
		switch (pchr) {
			/* Range character loses its meaning
			 * if it is the last character in
			 * the class.
			 */
		case MC_RCCL:
			if (*(patptr + 1) == MC_ECCL)
				setbit(pchr, bmap);
			else {
				pchr = *++patptr;
				while (++ochr <= pchr)
					setbit(ochr, bmap);
			}
			break;

			/* Note: no break between case MC_ESC and the default.
			 */
		case MC_ESC:
			pchr = *++patptr;
		default:
			setbit(pchr, bmap);
			break;
		}
		patptr++;
		ochr = pchr;
	}

	*ppatptr = patptr;

	if (ochr == '\0') {
		mlwrite("%%Character class not ended");
		free(bmap);
		return FALSE;
	}
	return TRUE;
}

/*
 * biteq -- is the character in the bitmap?
 */
static int biteq(int bc, char *cclmap)
{
#if	PKCODE
	bc = bc & 0xFF;
#endif
	if (bc >= HICHAR)
		return FALSE;

	return (*(cclmap + (bc >> 3)) & BIT(bc & 7)) ? TRUE : FALSE;
}

/*
 * clearbits -- Allocate and zero out a CCL bitmap.
 */
static char *clearbits(void)
{
	char *cclstart;
        char *cclmap;
	int i;

	if ((cclmap = cclstart = (char *)malloc(HIBYTE)) != NULL) {
		for (i = 0; i < HIBYTE; i++)
			*cclmap++ = 0;
	}
	return cclstart;
}

/*
 * setbit -- Set a bit (ON only) in the bitmap.
 */
static void setbit(int bc, char *cclmap)
{
#if	PKCODE
	bc = bc & 0xFF;
#endif
	if (bc < HICHAR)
		*(cclmap + (bc >> 3)) |= BIT(bc & 7);
}
#endif


/* ----- spawn.c ----- */
/*	spaw.c
 *
 *	Various operating system access commands.
 *
 *	<odified by Petri Kutvonen
 */
/* system header already included */
/* system header already included */
/* #include "estruct.h" - amalgamated */
/* #include "edef.h" - amalgamated */
/* #include "efunc.h" - amalgamated */

#if     VMS
#define EFN     0		/* Event flag.          */

#include        <ssdef.h>	/* Random headers.      */
#include        <stsdef.h>
#include        <descrip.h>
#include        <iodef.h>

extern int oldmode[3];		/* In "termio.c"        */
extern int newmode[3];		/* In "termio.c"        */
extern short iochan;		/* In "termio.c"        */
#endif

#if     V7 | USG | BSD
/* system header already included */
#ifdef SIGWINCH
extern int chg_width, chg_height;
extern void sizesignal(int);
#endif
#endif

#if	MSDOS & (MSC | TURBO)
#include	<process.h>
#endif

/*
 * Create a subjob with a copy of the command intrepreter in it. When the
 * command interpreter exits, mark the screen as garbage so that you do a full
 * repaint. Bound to "^X C". The message at the start in VMS puts out a newline.
 * Under some (unknown) condition, you don't get one free when DCL starts up.
 */
int spawncli(int f, int n)
{
#if     V7 | USG | BSD
	char *cp;
#endif

	/* don't allow this command if restricted */
	if (restflag)
		return resterr();

#if     VMS
	movecursor(term.t_nrow, 0);	/* In last line.        */
	mlputs("(Starting DCL)\r\n");
	TTflush();		/* Ignore "ttcol".      */
	sgarbf = TRUE;
	sys(NULL);
	sleep(1);
	mlputs("\r\n(Returning from DCL)\r\n");
	TTflush();
	sleep(1);
	return TRUE;
#endif
#if     MSDOS & (MSC | TURBO)
	movecursor(term.t_nrow, 0);	/* Seek to last line.   */
	TTflush();
	TTkclose();
	shellprog("");
	TTkopen();
	sgarbf = TRUE;
	return TRUE;
#endif
#if     V7 | USG | BSD
	movecursor(term.t_nrow, 0);	/* Seek to last line.   */
	TTflush();
	TTclose();		/* stty to old settings */
	TTkclose();		/* Close "keyboard" */
	if ((cp = getenv("SHELL")) != NULL && *cp != '\0')
		system(cp);
	else
#if	BSD
		system("exec /bin/csh");
#else
		system("exec /bin/sh");
#endif
	sgarbf = TRUE;
	sleep(2);
	TTopen();
	TTkopen();
#ifdef SIGWINCH
/*
 * This fools the update routines to force a full
 * redraw with complete window size checking.
 *		-lbt
 */
	chg_width = term.t_ncol;
	chg_height = term.t_nrow + 1;
	term.t_nrow = term.t_ncol = 0;
#endif
	return TRUE;
#endif
}

#if	BSD | __hpux | SVR4

int bktoshell(int f, int n)
{				/* suspend MicroEMACS and wait to wake up */
	vttidy();
/******************************
	int pid;

	pid = getpid();
	kill(pid,SIGTSTP);
******************************/
	kill(0, SIGTSTP);
	return TRUE;
}

void rtfrmshell(void)
{
	TTopen();
	curwp->w_flag = WFHARD;
	sgarbf = TRUE;
}
#endif

/*
 * Run a one-liner in a subjob. When the command returns, wait for a single
 * character to be typed, then mark the screen as garbage so a full repaint is
 * done. Bound to "C-X !".
 */
int spawn(int f, int n)
{
	int s;
	char line[NLINE];

	/* don't allow this command if restricted */
	if (restflag)
		return resterr();

#if     VMS
	if ((s = mlreply("!", line, NLINE)) != TRUE)
		return s;
	movecursor(term.t_nrow, 0);
	TTflush();
	s = sys(line);		/* Run the command.     */
	if (clexec == FALSE) {
		mlputs("\r\n\n(End)");	/* Pause.               */
		TTflush();
		tgetc();
	}
	sgarbf = TRUE;
	return s;
#endif
#if     MSDOS
	if ((s = mlreply("!", line, NLINE)) != TRUE)
		return s;
	movecursor(term.t_nrow, 0);
	TTkclose();
	shellprog(line);
	TTkopen();
	/* if we are interactive, pause here */
	if (clexec == FALSE) {
		mlputs("\r\n(End)");
		tgetc();
	}
	sgarbf = TRUE;
	return TRUE;
#endif
#if     V7 | USG | BSD
	if ((s = mlreply("!", line, NLINE)) != TRUE)
		return s;
	TTflush();
	TTclose();		/* stty to old modes    */
	TTkclose();
	system(line);
	fflush(stdout);		/* to be sure P.K.      */
	TTopen();

	if (clexec == FALSE) {
		mlputs("(End)");	/* Pause.               */
		TTflush();
		while ((s = tgetc()) != '\r' && s != ' ');
		mlputs("\r\n");
	}
	TTkopen();
	sgarbf = TRUE;
	return TRUE;
#endif
}

/*
 * Run an external program with arguments. When it returns, wait for a single
 * character to be typed, then mark the screen as garbage so a full repaint is
 * done. Bound to "C-X $".
 */

int execprg(int f, int n)
{
	int s;
	char line[NLINE];

	/* don't allow this command if restricted */
	if (restflag)
		return resterr();

#if     VMS
	if ((s = mlreply("!", line, NLINE)) != TRUE)
		return s;
	TTflush();
	s = sys(line);		/* Run the command.     */
	mlputs("\r\n\n(End)");	/* Pause.               */
	TTflush();
	tgetc();
	sgarbf = TRUE;
	return s;
#endif

#if     MSDOS
	if ((s = mlreply("$", line, NLINE)) != TRUE)
		return s;
	movecursor(term.t_nrow, 0);
	TTkclose();
	execprog(line);
	TTkopen();
	/* if we are interactive, pause here */
	if (clexec == FALSE) {
		mlputs("\r\n(End)");
		tgetc();
	}
	sgarbf = TRUE;
	return TRUE;
#endif

#if     V7 | USG | BSD
	if ((s = mlreply("!", line, NLINE)) != TRUE)
		return s;
	TTputc('\n');		/* Already have '\r'    */
	TTflush();
	TTclose();		/* stty to old modes    */
	TTkclose();
	system(line);
	fflush(stdout);		/* to be sure P.K.      */
	TTopen();
	mlputs("(End)");	/* Pause.               */
	TTflush();
	while ((s = tgetc()) != '\r' && s != ' ');
	sgarbf = TRUE;
	return TRUE;
#endif
}

/*
 * Pipe a one line command into a window
 * Bound to ^X @
 */
int pipecmd(int f, int n)
{
	int s;		/* return status from CLI */
	struct window *wp;	/* pointer to new window */
	struct buffer *bp;	/* pointer to buffer to zot */
	char line[NLINE];	/* command line send to shell */
	static char bname[] = "command";

	static char filnam[NSTRING] = "command";

#if     MSDOS
	char *tmp;
	FILE *fp;
	int len;
#endif

	/* don't allow this command if restricted */
	if (restflag)
		return resterr();

#if	MSDOS
	if ((tmp = getenv("TMP")) == NULL
	    && (tmp = getenv("TEMP")) == NULL)
		strcpy(filnam, "command");
	else {
		strcpy(filnam, tmp);
		len = strlen(tmp);
		if (len <= 0 || filnam[len - 1] != '\\'
		    && filnam[len - 1] != '/')
			strcat(filnam, "\\");
		strcat(filnam, "command");
	}
#endif

#if     VMS
	mlwrite("Not available under VMS");
	return FALSE;
#endif

	/* get the command to pipe in */
	if ((s = mlreply("@", line, NLINE)) != TRUE)
		return s;

	/* get rid of the command output buffer if it exists */
	if ((bp = bfind(bname, FALSE, 0)) != FALSE) {
		/* try to make sure we are off screen */
		wp = wheadp;
		while (wp != NULL) {
			if (wp->w_bufp == bp) {
#if	PKCODE
				if (wp == curwp)
					delwind(FALSE, 1);
				else
					onlywind(FALSE, 1);
				break;
#else
				onlywind(FALSE, 1);
				break;
#endif
			}
			wp = wp->w_wndp;
		}
		if (zotbuf(bp) != TRUE)

			return FALSE;
	}
#if     MSDOS
	strcat(line, " >>");
	strcat(line, filnam);
	movecursor(term.t_nrow, 0);
	TTkclose();
	shellprog(line);
	TTkopen();
	sgarbf = TRUE;
	if ((fp = fopen(filnam, "r")) == NULL) {
		s = FALSE;
	} else {
		fclose(fp);
		s = TRUE;
	}
#endif

#if     V7 | USG | BSD
	TTflush();
	TTclose();		/* stty to old modes    */
	TTkclose();
	strcat(line, ">");
	strcat(line, filnam);
	system(line);
	TTopen();
	TTkopen();
	TTflush();
	sgarbf = TRUE;
	s = TRUE;
#endif

	if (s != TRUE)
		return s;

	/* split the current window to make room for the command output */
	if (splitwind(FALSE, 1) == FALSE)
		return FALSE;

	/* and read the stuff in */
	if (getfile(filnam, FALSE) == FALSE)
		return FALSE;

	/* make this window in VIEW mode, update all mode lines */
	curwp->w_bufp->b_mode |= MDVIEW;
	wp = wheadp;
	while (wp != NULL) {
		wp->w_flag |= WFMODE;
		wp = wp->w_wndp;
	}

	/* and get rid of the temporary file */
	unlink(filnam);
	return TRUE;
}

/*
 * filter a buffer through an external DOS program
 * Bound to ^X #
 */
int filter_buffer(int f, int n)
{
	int s;		/* return status from CLI */
	struct buffer *bp;	/* pointer to buffer to zot */
	char line[NLINE];	/* command line send to shell */
	char tmpnam[NFILEN];	/* place to store real file name */
	static char bname1[] = "fltinp";

	static char filnam1[] = "fltinp";
	static char filnam2[] = "fltout";

	/* don't allow this command if restricted */
	if (restflag)
		return resterr();

	if (curbp->b_mode & MDVIEW)	/* don't allow this command if      */
		return rdonly();	/* we are in read only mode     */

#if     VMS
	mlwrite("Not available under VMS");
	return FALSE;
#endif

	/* get the filter name and its args */
	if ((s = mlreply("#", line, NLINE)) != TRUE)
		return s;

	/* setup the proper file names */
	bp = curbp;
	strcpy(tmpnam, bp->b_fname);	/* save the original name */
	strcpy(bp->b_fname, bname1);	/* set it to our new one */

	/* write it out, checking for errors */
	if (writeout(filnam1) != TRUE) {
		mlwrite("(Cannot write filter file)");
		strcpy(bp->b_fname, tmpnam);
		return FALSE;
	}
#if     MSDOS
	strcat(line, " <fltinp >fltout");
	movecursor(term.t_nrow - 1, 0);
	TTkclose();
	shellprog(line);
	TTkopen();
	sgarbf = TRUE;
	s = TRUE;
#endif

#if     V7 | USG | BSD
	TTputc('\n');		/* Already have '\r'    */
	TTflush();
	TTclose();		/* stty to old modes    */
	TTkclose();
	strcat(line, " <fltinp >fltout");
	system(line);
	TTopen();
	TTkopen();
	TTflush();
	sgarbf = TRUE;
	s = TRUE;
#endif

	/* on failure, escape gracefully */
	if (s != TRUE || (readin(filnam2, FALSE) == FALSE)) {
		mlwrite("(Execution failed)");
		strcpy(bp->b_fname, tmpnam);
		unlink(filnam1);
		unlink(filnam2);
		return s;
	}

	/* reset file name */
	strcpy(bp->b_fname, tmpnam);	/* restore name */
	bp->b_flag |= BFCHG;	/* flag it as changed */

	/* and get rid of the temporary file */
	unlink(filnam1);
	unlink(filnam2);
	return TRUE;
}

#if     VMS
/*
 * Run a command. The "cmd" is a pointer to a command string, or NULL if you
 * want to run a copy of DCL in the subjob (this is how the standard routine
 * LIB$SPAWN works. You have to do wierd stuff with the terminal on the way in
 * and the way out, because DCL does not want the channel to be in raw mode.
 */
int sys(char *cmd)
{
	struct dsc$descriptor cdsc;
	struct dsc$descriptor *cdscp;
	long status;
	long substatus;
	long iosb[2];

	status = SYS$QIOW(EFN, iochan, IO$_SETMODE, iosb, 0, 0,
			  oldmode, sizeof(oldmode), 0, 0, 0, 0);
	if (status != SS$_NORMAL || (iosb[0] & 0xFFFF) != SS$_NORMAL)
		return FALSE;
	cdscp = NULL;		/* Assume DCL.          */
	if (cmd != NULL) {	/* Build descriptor.    */
		cdsc.dsc$a_pointer = cmd;
		cdsc.dsc$w_length = strlen(cmd);
		cdsc.dsc$b_dtype = DSC$K_DTYPE_T;
		cdsc.dsc$b_class = DSC$K_CLASS_S;
		cdscp = &cdsc;
	}
	status = LIB$SPAWN(cdscp, 0, 0, 0, 0, 0, &substatus, 0, 0, 0);
	if (status != SS$_NORMAL)
		substatus = status;
	status = SYS$QIOW(EFN, iochan, IO$_SETMODE, iosb, 0, 0,
			  newmode, sizeof(newmode), 0, 0, 0, 0);
	if (status != SS$_NORMAL || (iosb[0] & 0xFFFF) != SS$_NORMAL)
		return FALSE;
	if ((substatus & STS$M_SUCCESS) == 0)	/* Command failed.      */
		return FALSE;
	return TRUE;
}
#endif

#if	MSDOS & (TURBO | MSC)

/*
 * SHELLPROG: Execute a command in a subshell
 *
 * char *cmd;		Incoming command line to execute
 */
int shellprog(char *cmd)
{
	char *shell;		/* Name of system command processor */
	char *p;		/* Temporary pointer */
	char swchar;		/* switch character to use */
	union REGS regs;	/* parameters for dos call */
	char comline[NSTRING];	/* constructed command line */

	/*  detect current switch character and set us up to use it */
	regs.h.ah = 0x37;	/*  get setting data  */
	regs.h.al = 0x00;	/*  get switch character  */
	intdos(&regs, &regs);
	swchar = (char) regs.h.dl;

	/*  get name of system shell  */
	if ((shell = getenv("COMSPEC")) == NULL) {
		return FALSE;	/*  No shell located  */
	}

	/* trim leading whitespace off the command */
	while (*cmd == ' ' || *cmd == '\t')	/*  find out if null command */
		cmd++;

	/**  If the command line is not empty, bring up the shell  **/
	/**  and execute the command.  Otherwise, bring up the     **/
	/**  shell in interactive mode.   **/

	if (*cmd) {
		strcpy(comline, shell);
		strcat(comline, " ");
		comline[strlen(comline) + 1] = 0;
		comline[strlen(comline)] = swchar;
		strcat(comline, "c ");
		strcat(comline, cmd);
		return execprog(comline);
	} else
		return execprog(shell);
}

/*
 * EXECPROG:
 *	A function to execute a named program
 *	with arguments
 *
 * char *cmd;		Incoming command line to execute
 */
int execprog(char *cmd)
{
	char *sp;		/* temporary string pointer */
	char f1[38];		/* FCB1 area (not initialized */
	char f2[38];		/* FCB2 area (not initialized */
	char prog[NSTRING];	/* program filespec */
	char tail[NSTRING];	/* command tail with length byte */
	union REGS regs;	/* parameters for dos call  */
	struct SREGS segreg;	/* segment registers for dis call */
	struct pblock {		/* EXEC parameter block */
		short envptr;	/* 2 byte pointer to environment string */
		char *cline;	/* 4 byte pointer to command line */
		char *fcb1;	/* 4 byte pointer to FCB at PSP+5Ch */
		char *fcb2;	/* 4 byte pointer to FCB at PSP+6Ch */
	} pblock;
	char *flook();

	/* parse the command name from the command line */
	sp = prog;
	while (*cmd && (*cmd != ' ') && (*cmd != '\t'))
		*sp++ = *cmd++;
	*sp = 0;

	/* and parse out the command tail */
	while (*cmd && ((*cmd == ' ') || (*cmd == '\t')))
		++cmd;
	*tail = (char) (strlen(cmd));	/* record the byte length */
	strcpy(&tail[1], cmd);
	strcat(&tail[1], "\r");

	/* look up the program on the path trying various extentions */
	if ((sp = flook(prog, TRUE)) == NULL)
		if ((sp = flook(strcat(prog, ".exe"), TRUE)) == NULL) {
			strcpy(&prog[strlen(prog) - 4], ".com");
			if ((sp = flook(prog, TRUE)) == NULL)
				return FALSE;
		}
	strcpy(prog, sp);

	/* get a pointer to this PSPs environment segment number */
	segread(&segreg);

	/* set up the EXEC parameter block */
	pblock.envptr = 0;	/* make the child inherit the parents env */
	pblock.fcb1 = f1;	/* point to a blank FCB */
	pblock.fcb2 = f2;	/* point to a blank FCB */
	pblock.cline = tail;	/* parameter line pointer */

	/* and make the call */
	regs.h.ah = 0x4b;	/* EXEC Load or Execute a Program */
	regs.h.al = 0x00;	/* load end execute function subcode */
	segreg.ds = ((unsigned long) (prog) >> 16);	/* program name ptr */
	regs.x.dx = (unsigned int) (prog);
	segreg.es = ((unsigned long) (&pblock) >> 16);	/* set up param block ptr */
	regs.x.bx = (unsigned int) (&pblock);
#if	TURBO | MSC
	intdosx(&regs, &regs, &segreg);
	if (regs.x.cflag == 0) {
		regs.h.ah = 0x4d;	/* get child process return code */
		intdos(&regs, &regs);	/* go do it */
		rval = regs.x.ax;	/* save child's return code */
	} else
#if	MSC
		rval = -1;
#else
		rval = -_doserrno;	/* failed child call */
#endif
#endif
	return (rval < 0) ? FALSE : TRUE;
}
#endif


/* ----- tcap.c ----- */
/*	tcap.c
 *
 *	Unix V7 SysV and BS4 Termcap video driver
 *
 *	modified by Petri Kutvonen
 */

/*
 * Defining this to 1 breaks tcapopen() - it doesn't check if the
 * sceen size has changed.
 *	-lbt
 */
#define USE_BROKEN_OPTIMIZATION 0
#define	termdef	1 /* Don't define "term" external. */
/* system header already included */
/* system header already included */
/* system header already included */
/* #include "estruct.h" - amalgamated */
/* #include "edef.h" - amalgamated */
/* #include "efunc.h" - amalgamated */

#if TERMCAP

#if UNIX
/* system header already included */
#endif

#define	MARGIN	8
#define	SCRSIZ	64
#define	NPAUSE	10    /* # times thru update to pause. */
#define BEL     0x07
#define ESC     0x1B

static void tcapkopen(void);
static void tcapkclose(void);
static void tcapmove(int, int);
static void tcapeeol(void);
static void tcapeeop(void);
static void tcapbeep(void);
static void tcaprev(int);
static int tcapcres(char *);
static void tcapscrollregion(int top, int bot);
static void putpad(char *str);

static void tcapopen(void);
#if PKCODE
static void tcapclose(void);
#endif

#if COLOR
static void tcapfcol(void);
static void tcapbcol(void);
#endif
#if SCROLLCODE
static void tcapscroll_reg(int from, int to, int linestoscroll);
static void tcapscroll_delins(int from, int to, int linestoscroll);
#endif

#define TCAPSLEN 315
static char tcapbuf[TCAPSLEN];
static char *UP, PC, *CM, *CE, *CL, *SO, *SE;

#if PKCODE
static char *TI, *TE;
#if USE_BROKEN_OPTIMIZATION
static int term_init_ok = 0;
#endif
#endif

#if SCROLLCODE
static char *CS, *DL, *AL, *SF, *SR;
#endif

struct terminal term = {
	0, /* These four values are set dynamically at open time. */
	0,
	0,
	0,
	MARGIN,
	SCRSIZ,
	NPAUSE,
	tcapopen,
#if	PKCODE
	tcapclose,
#else
	ttclose,
#endif
	tcapkopen,
	tcapkclose,
	ttgetc,
	ttputc,
	ttflush,
	tcapmove,
	tcapeeol,
	tcapeeop,
	tcapbeep,
	tcaprev,
	tcapcres
#if	COLOR
	    , tcapfcol,
	tcapbcol
#endif
#if     SCROLLCODE
	    , NULL		/* set dynamically at open time */
#endif
};

static void tcapopen(void)
{
	char *t, *p;
	char tcbuf[1024];
	char *tv_stype;
	char err_str[72];
	int int_col, int_row;

#if PKCODE && USE_BROKEN_OPTIMIZATION
	if (!term_init_ok) {
#endif
		if ((tv_stype = getenv("TERM")) == NULL) {
			puts("Environment variable TERM not defined!");
			exit(1);
		}

		if ((tgetent(tcbuf, tv_stype)) != 1) {
			sprintf(err_str, "Unknown terminal type %s!",
				tv_stype);
			puts(err_str);
			exit(1);
		}

		/* Get screen size from system, or else from termcap.  */
		getscreensize(&int_col, &int_row);
		term.t_nrow = int_row - 1;
		term.t_ncol = int_col;

		if ((term.t_nrow <= 0)
		    && (term.t_nrow = (short) tgetnum("li") - 1) == -1) {
			puts("termcap entry incomplete (lines)");
			exit(1);
		}

		if ((term.t_ncol <= 0)
		    && (term.t_ncol = (short) tgetnum("co")) == -1) {
			puts("Termcap entry incomplete (columns)");
			exit(1);
		}
#ifdef SIGWINCH
		term.t_mrow = MAXROW;
		term.t_mcol = MAXCOL;
#else
		term.t_mrow = term.t_nrow > MAXROW ? MAXROW : term.t_nrow;
		term.t_mcol = term.t_ncol > MAXCOL ? MAXCOL : term.t_ncol;
#endif
		p = tcapbuf;
		t = tgetstr("pc", &p);
		if (t)
			PC = *t;
		else
			PC = 0;

		CL = tgetstr("cl", &p);
		CM = tgetstr("cm", &p);
		CE = tgetstr("ce", &p);
		UP = tgetstr("up", &p);
		SE = tgetstr("se", &p);
		SO = tgetstr("so", &p);
		if (SO != NULL)
			revexist = TRUE;
#if	PKCODE
		if (tgetnum("sg") > 0) {	/* can reverse be used? P.K. */
			revexist = FALSE;
			SE = NULL;
			SO = NULL;
		}
		TI = tgetstr("ti", &p);	/* terminal init and exit */
		TE = tgetstr("te", &p);
#endif

		if (CL == NULL || CM == NULL || UP == NULL) {
			puts("Incomplete termcap entry\n");
			exit(1);
		}

		if (CE == NULL)	/* will we be able to use clear to EOL? */
			eolexist = FALSE;
#if SCROLLCODE
		CS = tgetstr("cs", &p);
		SF = tgetstr("sf", &p);
		SR = tgetstr("sr", &p);
		DL = tgetstr("dl", &p);
		AL = tgetstr("al", &p);

		if (CS && SR) {
			if (SF == NULL)	/* assume '\n' scrolls forward */
				SF = "\n";
			term.t_scroll = tcapscroll_reg;
		} else if (DL && AL) {
			term.t_scroll = tcapscroll_delins;
		} else {
			term.t_scroll = NULL;
		}
#endif

		if (p >= &tcapbuf[TCAPSLEN]) {
			puts("Terminal description too big!\n");
			exit(1);
		}
#if PKCODE && USE_BROKEN_OPTIMIZATION
		term_init_ok = 1;
	}
#endif
	ttopen();
}

#if	PKCODE
static void tcapclose(void)
{
	putpad(tgoto(CM, 0, term.t_nrow));
	putpad(TE);
	ttflush();
	ttclose();
}
#endif

static void tcapkopen(void)
{
#if	PKCODE
	putpad(TI);
	ttflush();
	ttrow = 999;
	ttcol = 999;
	sgarbf = TRUE;
#endif
	strcpy(sres, "NORMAL");
}

static void tcapkclose(void)
{
#if	PKCODE
	putpad(TE);
	ttflush();
#endif
}

static void tcapmove(int row, int col)
{
	putpad(tgoto(CM, col, row));
}

static void tcapeeol(void)
{
	putpad(CE);
}

static void tcapeeop(void)
{
	putpad(CL);
}

/*
 * Change reverse video status
 *
 * @state: FALSE = normal video, TRUE = reverse video.
 */
static void tcaprev(int state)
{
	if (state) {
		if (SO != NULL)
			putpad(SO);
	} else if (SE != NULL)
		putpad(SE);
}

/* Change screen resolution. */
static int tcapcres(char *res)
{
	return TRUE;
}

#if SCROLLCODE

/* move howmanylines lines starting at from to to */
static void tcapscroll_reg(int from, int to, int howmanylines)
{
	int i;
	if (to == from)
		return;
	if (to < from) {
		tcapscrollregion(to, from + howmanylines - 1);
		tcapmove(from + howmanylines - 1, 0);
		for (i = from - to; i > 0; i--)
			putpad(SF);
	} else {		/* from < to */
		tcapscrollregion(from, to + howmanylines - 1);
		tcapmove(from, 0);
		for (i = to - from; i > 0; i--)
			putpad(SR);
	}
	tcapscrollregion(0, term.t_nrow);
}

/* move howmanylines lines starting at from to to */
static void tcapscroll_delins(int from, int to, int howmanylines)
{
	int i;
	if (to == from)
		return;
	if (to < from) {
		tcapmove(to, 0);
		for (i = from - to; i > 0; i--)
			putpad(DL);
		tcapmove(to + howmanylines, 0);
		for (i = from - to; i > 0; i--)
			putpad(AL);
	} else {
		tcapmove(from + howmanylines, 0);
		for (i = to - from; i > 0; i--)
			putpad(DL);
		tcapmove(from, 0);
		for (i = to - from; i > 0; i--)
			putpad(AL);
	}
}

/* cs is set up just like cm, so we use tgoto... */
static void tcapscrollregion(int top, int bot)
{
	ttputc(PC);
	putpad(tgoto(CS, bot, top));
}

#endif

#if COLOR
/* No colors here, ignore this. */
static void tcapfcol(void)
{
}
/* No colors here, ignore this. */
static void tcapbcol(void)
{
}
#endif

static void tcapbeep(void)
{
	ttputc(BEL);
}

static void putpad(char *str)
{
	tputs(str, 1, ttputc);
}
#endif /* TERMCAP */


/* ----- termio.c ----- */

/*	TERMIO.C
 *
 * The functions in this file negotiate with the operating system for
 * characters, and write characters in a barely buffered fashion on the display.
 * All operating systems.
 *
 *	modified by Petri Kutvonen
 */

#ifndef POSIX
/* system header already included */
/* #include "estruct.h" - amalgamated */
/* #include "edef.h" - amalgamated */

#if     VMS
#include        <stsdef.h>
#include        <ssdef.h>
#include        <descrip.h>
#include        <iodef.h>
#include        <ttdef.h>
#include	<tt2def.h>

#define NIBUF   128		/* Input buffer size            */
#define NOBUF   1024		/* MM says bug buffers win!     */
#define EFN     0		/* Event flag                   */

char obuf[NOBUF];		/* Output buffer                */
int nobuf;			/* # of bytes in above          */
char ibuf[NIBUF];		/* Input buffer                 */
int nibuf;			/* # of bytes in above          */
int ibufi;			/* Read index                   */
int oldmode[3];			/* Old TTY mode bits            */
int newmode[3];			/* New TTY mode bits            */
short iochan;			/* TTY I/O channel              */
#endif

#if     MSDOS & (MSC | TURBO)
union REGS rg;			/* cpu register for use of DOS calls */
int nxtchar = -1;		/* character held from type ahead    */
#endif

#if	USG			/* System V */
/* system header already included */
#include	<termio.h>
/* system header already included */
int kbdflgs;			/* saved keyboard fd flags      */
int kbdpoll;			/* in O_NDELAY mode                     */
int kbdqp;			/* there is a char in kbdq      */
char kbdq;			/* char we've already read      */
struct termio otermio;		/* original terminal characteristics */
struct termio ntermio;		/* charactoristics to use inside */
#if	XONXOFF
#define XXMASK	0016000
#endif
#endif

#if	V7 | BSD
#include        <sgtty.h>	/* for stty/gtty functions */
/* system header already included */
struct sgttyb ostate;		/* saved tty state */
struct sgttyb nstate;		/* values for editor mode */
struct tchars otchars;		/* Saved terminal special character set */
#if	XONXOFF
struct tchars ntchars = { 0xff, 0xff, 0x11, 0x13, 0xff, 0xff };

				/* A lot of nothing and XON/XOFF */
#else
struct tchars ntchars = { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff };

				/* A lot of nothing */
#endif
#if	BSD & PKCODE
struct ltchars oltchars;	/* Saved terminal local special character set */
struct ltchars nltchars = { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff };

				/* A lot of nothing */
#endif

#if BSD
#include <sys/ioctl.h>		/* to get at the typeahead */
extern int rtfrmshell();	/* return from suspended shell */
#define	TBUFSIZ	128
char tobuf[TBUFSIZ];		/* terminal output buffer */
#endif
#endif

#if	__hpux | SVR4
extern int rtfrmshell();	/* return from suspended shell */
#define TBUFSIZ 128
char tobuf[TBUFSIZ];		/* terminal output buffer */
#endif

/*
 * This function is called once to set up the terminal device streams.
 * On VMS, it translates TT until it finds the terminal, then assigns
 * a channel to it and sets it raw. On CPM it is a no-op.
 */
void ttopen(void)
{
#if     VMS
	struct dsc$descriptor idsc;
	struct dsc$descriptor odsc;
	char oname[40];
	int iosb[2];
	int status;

	odsc.dsc$a_pointer = "TT";
	odsc.dsc$w_length = strlen(odsc.dsc$a_pointer);
	odsc.dsc$b_dtype = DSC$K_DTYPE_T;
	odsc.dsc$b_class = DSC$K_CLASS_S;
	idsc.dsc$b_dtype = DSC$K_DTYPE_T;
	idsc.dsc$b_class = DSC$K_CLASS_S;
	do {
		idsc.dsc$a_pointer = odsc.dsc$a_pointer;
		idsc.dsc$w_length = odsc.dsc$w_length;
		odsc.dsc$a_pointer = &oname[0];
		odsc.dsc$w_length = sizeof(oname);
		status = LIB$SYS_TRNLOG(&idsc, &odsc.dsc$w_length, &odsc);
		if (status != SS$_NORMAL && status != SS$_NOTRAN)
			exit(status);
		if (oname[0] == 0x1B) {
			odsc.dsc$a_pointer += 4;
			odsc.dsc$w_length -= 4;
		}
	} while (status == SS$_NORMAL);
	status = SYS$ASSIGN(&odsc, &iochan, 0, 0);
	if (status != SS$_NORMAL)
		exit(status);
	status = SYS$QIOW(EFN, iochan, IO$_SENSEMODE, iosb, 0, 0,
			  oldmode, sizeof(oldmode), 0, 0, 0, 0);
	if (status != SS$_NORMAL || (iosb[0] & 0xFFFF) != SS$_NORMAL)
		exit(status);
	newmode[0] = oldmode[0];
	newmode[1] = oldmode[1] | TT$M_NOECHO;
#if	XONXOFF
#else
	newmode[1] &= ~(TT$M_TTSYNC | TT$M_HOSTSYNC);
#endif
	newmode[2] = oldmode[2] | TT2$M_PASTHRU;
	status = SYS$QIOW(EFN, iochan, IO$_SETMODE, iosb, 0, 0,
			  newmode, sizeof(newmode), 0, 0, 0, 0);
	if (status != SS$_NORMAL || (iosb[0] & 0xFFFF) != SS$_NORMAL)
		exit(status);
	term.t_nrow = (newmode[1] >> 24) - 1;
	term.t_ncol = newmode[0] >> 16;

#endif

#if     MSDOS & (TURBO | (PKCODE & MSC))
	/* kill the CONTROL-break interupt */
	rg.h.ah = 0x33;		/* control-break check dos call */
	rg.h.al = 1;		/* set the current state */
	rg.h.dl = 0;		/* set it OFF */
	intdos(&rg, &rg);	/* go for it! */
#endif

#if	USG
	ioctl(0, TCGETA, &otermio);	/* save old settings */
	ntermio.c_iflag = 0;	/* setup new settings */
#if	XONXOFF
	ntermio.c_iflag = otermio.c_iflag & XXMASK;	/* save XON/XOFF P.K. */
#endif
	ntermio.c_oflag = 0;
	ntermio.c_cflag = otermio.c_cflag;
	ntermio.c_lflag = 0;
	ntermio.c_line = otermio.c_line;
	ntermio.c_cc[VMIN] = 1;
	ntermio.c_cc[VTIME] = 0;
#if	PKCODE
	ioctl(0, TCSETAW, &ntermio);	/* and activate them */
#else
	ioctl(0, TCSETA, &ntermio);	/* and activate them */
#endif
	kbdflgs = fcntl(0, F_GETFL, 0);
	kbdpoll = FALSE;
#endif

#if     V7 | BSD
	gtty(0, &ostate);	/* save old state */
	gtty(0, &nstate);	/* get base of new state */
#if	XONXOFF
	nstate.sg_flags |= (CBREAK | TANDEM);
#else
	nstate.sg_flags |= RAW;
#endif
	nstate.sg_flags &= ~(ECHO | CRMOD);	/* no echo for now... */
	stty(0, &nstate);	/* set mode */
	ioctl(0, TIOCGETC, &otchars);	/* Save old characters */
	ioctl(0, TIOCSETC, &ntchars);	/* Place new character into K */
#if	BSD & PKCODE
	ioctl(0, TIOCGLTC, &oltchars);	/* Save old local characters */
	ioctl(0, TIOCSLTC, &nltchars);	/* New local characters */
#endif
#if	BSD
	/* provide a smaller terminal output buffer so that
	   the type ahead detection works better (more often) */
	setbuffer(stdout, &tobuf[0], TBUFSIZ);
	signal(SIGTSTP, SIG_DFL);	/* set signals so that we can */
	signal(SIGCONT, rtfrmshell);	/* suspend & restart emacs */
#endif
#endif

#if	__hpux | SVR4
	/* provide a smaller terminal output buffer so that
	   the type ahead detection works better (more often) */
	setvbuf(stdout, &tobuf[0], _IOFBF, TBUFSIZ);
	signal(SIGTSTP, SIG_DFL);	/* set signals so that we can */
	signal(SIGCONT, rtfrmshell);	/* suspend & restart emacs */
	TTflush();
#endif				/* __hpux */

	/* on all screens we are not sure of the initial position
	   of the cursor                                        */
	ttrow = 999;
	ttcol = 999;
}

/*
 * This function gets called just before we go back home to the command
 * interpreter. On VMS it puts the terminal back in a reasonable state.
 * Another no-operation on CPM.
 */
void ttclose(void)
{
#if     VMS
	int status;
	int iosb[1];

	ttflush();
	status = SYS$QIOW(EFN, iochan, IO$_SETMODE, iosb, 0, 0,
			  oldmode, sizeof(oldmode), 0, 0, 0, 0);
	if (status != SS$_NORMAL || (iosb[0] & 0xFFFF) != SS$_NORMAL)
		exit(status);
	status = SYS$DASSGN(iochan);
	if (status != SS$_NORMAL)
		exit(status);
#endif
#if     MSDOS & (TURBO | (PKCODE & MSC))
	/* restore the CONTROL-break interupt */
	rg.h.ah = 0x33;		/* control-break check dos call */
	rg.h.al = 1;		/* set the current state */
	rg.h.dl = 1;		/* set it ON */
	intdos(&rg, &rg);	/* go for it! */
#endif

#if	USG
#if	PKCODE
	ioctl(0, TCSETAW, &otermio);	/* restore terminal settings */
#else
	ioctl(0, TCSETA, &otermio);	/* restore terminal settings */
#endif
	fcntl(0, F_SETFL, kbdflgs);
#endif

#if     V7 | BSD
	stty(0, &ostate);
	ioctl(0, TIOCSETC, &otchars);	/* Place old character into K */
#if	BSD & PKCODE
	ioctl(0, TIOCSLTC, &oltchars);	/* Place old local character into K */
#endif
#endif
}

/*
 * Write a character to the display. On VMS, terminal output is buffered, and
 * we just put the characters in the big array, after checking for overflow.
 * On CPM terminal I/O unbuffered, so we just write the byte out. Ditto on
 * MS-DOS (use the very very raw console output routine).
 */
void ttputc(c)
{
#if     VMS
	if (nobuf >= NOBUF)
		ttflush();
	obuf[nobuf++] = c;
#endif

#if	MSDOS & ~IBMPC
	bdos(6, c, 0);
#endif

#if     V7 | USG | BSD
	fputc(c, stdout);
#endif
}

/*
 * Flush terminal buffer. Does real work where the terminal output is buffered
 * up. A no-operation on systems where byte at a time terminal I/O is done.
 */
int ttflush(void)
{
#if     VMS
	int status;
	int iosb[2];

	status = SS$_NORMAL;
	if (nobuf != 0) {
		status =
		    SYS$QIOW(EFN, iochan, IO$_WRITELBLK | IO$M_NOFORMAT,
			     iosb, 0, 0, obuf, nobuf, 0, 0, 0, 0);
		if (status == SS$_NORMAL)
			status = iosb[0] & 0xFFFF;
		nobuf = 0;
	}
	return status;
#endif

#if     MSDOS
#endif

#if     V7 | USG | BSD
/*
 * Add some terminal output success checking, sometimes an orphaned
 * process may be left looping on SunOS 4.1.
 *
 * How to recover here, or is it best just to exit and lose
 * everything?
 *
 * jph, 8-Oct-1993
 */
/* system header already included */
	int status;

	status = fflush(stdout);

	if (status != 0 && errno != EAGAIN) {
		exit(errno);
	}
#endif
}

/*
 * Read a character from the terminal, performing no editing and doing no echo
 * at all. More complex in VMS that almost anyplace else, which figures. Very
 * simple on CPM, because the system can do exactly what you want.
 */
ttgetc()
{
#if     VMS
	int status;
	int iosb[2];
	int term[2];

	while (ibufi >= nibuf) {
		ibufi = 0;
		term[0] = 0;
		term[1] = 0;
		status = SYS$QIOW(EFN, iochan, IO$_READLBLK | IO$M_TIMED,
				  iosb, 0, 0, ibuf, NIBUF, 0, term, 0, 0);
		if (status != SS$_NORMAL)
			exit(status);
		status = iosb[0] & 0xFFFF;
		if (status != SS$_NORMAL && status != SS$_TIMEOUT &&
		    status != SS$_DATAOVERUN)
			exit(status);
		nibuf = (iosb[0] >> 16) + (iosb[1] >> 16);
		if (nibuf == 0) {
			status = SYS$QIOW(EFN, iochan, IO$_READLBLK,
					  iosb, 0, 0, ibuf, 1, 0, term, 0,
					  0);
			if (status != SS$_NORMAL
			    || (status = (iosb[0] & 0xFFFF)) != SS$_NORMAL)
				if (status != SS$_DATAOVERUN)
					exit(status);
			nibuf = (iosb[0] >> 16) + (iosb[1] >> 16);
		}
	}
	return ibuf[ibufi++] & 0xFF;	/* Allow multinational  */
#endif

#if	MSDOS & (MSC | TURBO)
	int c;			/* character read */

	/* if a char already is ready, return it */
	if (nxtchar >= 0) {
		c = nxtchar;
		nxtchar = -1;
		return c;
	}

	/* call the dos to get a char */
	rg.h.ah = 7;		/* dos Direct Console Input call */
	intdos(&rg, &rg);
	c = rg.h.al;		/* grab the char */
	return c & 255;
#endif

#if     V7 | BSD
	return 255 & fgetc(stdin);	/* 8BIT P.K. */
#endif

#if	USG
	if (kbdqp)
		kbdqp = FALSE;
	else {
		if (kbdpoll && fcntl(0, F_SETFL, kbdflgs) < 0)
			return FALSE;
		kbdpoll = FALSE;
		while (read(0, &kbdq, 1) != 1);
	}
	return kbdq & 255;
#endif
}

#if	TYPEAH
/* typahead:	Check to see if any characters are already in the
		keyboard buffer
*/

typahead()
{
#if	MSDOS & (MSC | TURBO)
	if (kbhit() != 0)
		return TRUE;
	else
		return FALSE;
#endif

#if	BSD
	int x;			/* holds # of pending chars */

	return (ioctl(0, FIONREAD, &x) < 0) ? 0 : x;
#endif

#if	PKCODE & VMS
	return ibufi < nibuf;
#endif

#if	USG
	if (!kbdqp) {
		if (!kbdpoll && fcntl(0, F_SETFL, kbdflgs | O_NDELAY) < 0)
			return FALSE;
#if	PKCODE
		kbdpoll = 1;
#endif
		kbdqp = (1 == read(0, &kbdq, 1));
	}
	return kbdqp;
#endif

#if !UNIX & !VMS & !MSDOS
	return FALSE;
#endif
}
#endif

#endif				/* not POSIX */


/* ----- posix.c ----- */
/*	posix.c
 *
 *      The functions in this file negotiate with the operating system for
 *      characters, and write characters in a barely buffered fashion on the
 *      display. All operating systems.
 *
 *	modified by Petri Kutvonen
 *
 *	based on termio.c, with all the old cruft removed, and
 *	fixed for termios rather than the old termio.. Linus Torvalds
 */

#ifdef POSIX
/* system header already included */
/* system header already included */
/* system header already included */
/* system header already included */
/* system header already included */
/* system header already included */
/* #include "estruct.h" - amalgamated */
/* #include "edef.h" - amalgamated */
/* #include "efunc.h" - amalgamated */
/* #include "utf8.h" - amalgamated */

/* Since Mac OS X's termios.h doesn't have the following 2 macros, define them.
 */
#if defined(SYSV) && (defined(_DARWIN_C_SOURCE) || defined(_FREEBSD_C_SOURCE))
#define OLCUC 0000002
#define XCASE 0000004
#endif

static int kbdflgs;			/* saved keyboard fd flags      */
static int kbdpoll;			/* in O_NDELAY mode             */

static struct termios otermios;		/* original terminal characteristics */
static struct termios ntermios;		/* charactoristics to use inside */

#define TBUFSIZ 128
static char tobuf[TBUFSIZ];		/* terminal output buffer */


/*
 * This function is called once to set up the terminal device streams.
 * On VMS, it translates TT until it finds the terminal, then assigns
 * a channel to it and sets it raw. On CPM it is a no-op.
 */
void ttopen(void)
{
	tcgetattr(0, &otermios);	/* save old settings */

	/*
	 * base new settings on old ones - don't change things
	 * we don't know about
	 */
	ntermios = otermios;

	/* raw CR/NL etc input handling, but keep ISTRIP if we're on a 7-bit line */
	ntermios.c_iflag &= ~(IGNBRK | BRKINT | IGNPAR | PARMRK
			      | INPCK | INLCR | IGNCR | ICRNL);

	/* raw CR/NR etc output handling */
	ntermios.c_oflag &=
	    ~(OPOST | ONLCR | OLCUC | OCRNL | ONOCR | ONLRET);

	/* No signal handling, no echo etc */
	ntermios.c_lflag &= ~(ISIG | ICANON | XCASE | ECHO | ECHOE | ECHOK
			      | ECHONL | NOFLSH | TOSTOP | ECHOCTL |
			      ECHOPRT | ECHOKE | FLUSHO | PENDIN | IEXTEN);

	/* one character, no timeout */
	ntermios.c_cc[VMIN] = 1;
	ntermios.c_cc[VTIME] = 0;
	tcsetattr(0, TCSADRAIN, &ntermios);	/* and activate them */

	/*
	 * provide a smaller terminal output buffer so that
	 * the type ahead detection works better (more often)
	 */
	setbuffer(stdout, &tobuf[0], TBUFSIZ);

	kbdflgs = fcntl(0, F_GETFL, 0);
	kbdpoll = FALSE;

	/* on all screens we are not sure of the initial position
	   of the cursor                                        */
	ttrow = 999;
	ttcol = 999;
}

/*
 * This function gets called just before we go back home to the command
 * interpreter. On VMS it puts the terminal back in a reasonable state.
 * Another no-operation on CPM.
 */
void ttclose(void)
{
	tcsetattr(0, TCSADRAIN, &otermios);	/* restore terminal settings */
}

/*
 * Write a character to the display. On VMS, terminal output is buffered, and
 * we just put the characters in the big array, after checking for overflow.
 * On CPM terminal I/O unbuffered, so we just write the byte out. Ditto on
 * MS-DOS (use the very very raw console output routine).
 */
int ttputc(int c)
{
	char utf8[6];
	int bytes;

	bytes = unicode_to_utf8(c, utf8);
	fwrite(utf8, 1, bytes, stdout);
	return 0;
}

/*
 * Flush terminal buffer. Does real work where the terminal output is buffered
 * up. A no-operation on systems where byte at a time terminal I/O is done.
 */
void ttflush(void)
{
/*
 * Add some terminal output success checking, sometimes an orphaned
 * process may be left looping on SunOS 4.1.
 *
 * How to recover here, or is it best just to exit and lose
 * everything?
 *
 * jph, 8-Oct-1993
 * Jani Jaakkola suggested using select after EAGAIN but let's just wait a bit
 *
 */
	int status;

	status = fflush(stdout);
	while (status < 0 && errno == EAGAIN) {
		sleep(1);
		status = fflush(stdout);
	}
	if (status < 0)
		exit(15);
}

/*
 * Read a character from the terminal, performing no editing and doing no echo
 * at all. More complex in VMS that almost anyplace else, which figures. Very
 * simple on CPM, because the system can do exactly what you want.
 */
int ttgetc(void)
{
	static char buffer[32];
	static int pending;
	unicode_t c;
	int count, bytes = 1, expected;

	count = pending;
	if (!count) {
		count = read(0, buffer, sizeof(buffer));
		if (count <= 0)
			return 0;
		pending = count;
	}

	c = (unsigned char) buffer[0];
	if (c >= 32 && c < 128)
		goto done;

	/*
	 * Lazy. We don't bother calculating the exact
	 * expected length. We want at least two characters
	 * for the special character case (ESC+[) and for
	 * the normal short UTF8 sequence that starts with
	 * the 110xxxxx pattern.
	 *
	 * But if we have any of the other patterns, just
	 * try to get more characters. At worst, that will
	 * just result in a barely perceptible 0.1 second
	 * delay for some *very* unusual utf8 character
	 * input.
	 */
	expected = 2;
	if ((c & 0xe0) == 0xe0)
		expected = 6;

	/* Special character - try to fill buffer */
	if (count < expected) {
		int n;
		ntermios.c_cc[VMIN] = 0;
		ntermios.c_cc[VTIME] = 1;		/* A .1 second lag */
		tcsetattr(0, TCSANOW, &ntermios);

		n = read(0, buffer + count, sizeof(buffer) - count);

		/* Undo timeout */
		ntermios.c_cc[VMIN] = 1;
		ntermios.c_cc[VTIME] = 0;
		tcsetattr(0, TCSANOW, &ntermios);

		if (n > 0)
			pending += n;
	}
	if (pending > 1) {
		unsigned char second = buffer[1];

		/* Turn ESC+'[' into CSI */
		if (c == 27 && second == '[') {
			bytes = 2;
			c = 128+27;
			goto done;
		}
	}
	bytes = utf8_to_unicode(buffer, 0, pending, &c);

	/* Hackety hack! Turn no-break space into regular space */
	if (c == 0xa0)
		c = ' ';
done:
	pending -= bytes;
	memmove(buffer, buffer+bytes, pending);
	return c;
}

/* typahead:	Check to see if any characters are already in the
		keyboard buffer
*/

int typahead(void)
{
	int x;			/* holds # of pending chars */

#ifdef FIONREAD
	if (ioctl(0, FIONREAD, &x) < 0)
		x = 0;
#else
	x = 0;
#endif
	return x;
}

#endif				/* POSIX */


/* ----- window.c ----- */
/*	window.c
 *
 *      Window management. Some of the functions are internal, and some are
 *      attached to keys that the user actually types.
 *
 */
/* system header already included */
/* #include "estruct.h" - amalgamated */
/* #include "edef.h" - amalgamated */
/* #include "efunc.h" - amalgamated */
/* #include "line.h" - amalgamated */
/* #include "wrapper.h" - amalgamated */

/*
 * Reposition dot in the current window to line "n". If the argument is
 * positive, it is that line. If it is negative it is that line from the
 * bottom. If it is 0 the window is centered (this is what the standard
 * redisplay code does). With no argument it defaults to 0. Bound to M-!.
 */
int reposition(int f, int n)
{
	if (f == FALSE)		/* default to 0 to center screen */
		n = 0;
	curwp->w_force = n;
	curwp->w_flag |= WFFORCE;
	return TRUE;
}

/*
 * Refresh the screen. With no argument, it just does the refresh. With an
 * argument it recenters "." in the current window. Bound to "C-L".
 */
int redraw(int f, int n)
{
	if (f == FALSE)
		sgarbf = TRUE;
	else {
		curwp->w_force = 0;	/* Center dot. */
		curwp->w_flag |= WFFORCE;
	}

	return TRUE;
}

/*
 * The command make the next window (next => down the screen) the current
 * window. There are no real errors, although the command does nothing if
 * there is only 1 window on the screen. Bound to "C-X C-N".
 *
 * with an argument this command finds the <n>th window from the top
 *
 * int f, n;		default flag and numeric argument
 *
 */
int nextwind(int f, int n)
{
	struct window *wp;
	int nwindows;	/* total number of windows */

	if (f) {

		/* first count the # of windows */
		wp = wheadp;
		nwindows = 1;
		while (wp->w_wndp != NULL) {
			nwindows++;
			wp = wp->w_wndp;
		}

		/* if the argument is negative, it is the nth window
		   from the bottom of the screen                        */
		if (n < 0)
			n = nwindows + n + 1;

		/* if an argument, give them that window from the top */
		if (n > 0 && n <= nwindows) {
			wp = wheadp;
			while (--n)
				wp = wp->w_wndp;
		} else {
			mlwrite("Window number out of range");
			return FALSE;
		}
	} else if ((wp = curwp->w_wndp) == NULL)
		wp = wheadp;
	curwp = wp;
	curbp = wp->w_bufp;
	cknewwindow();
	upmode();
	return TRUE;
}

/*
 * This command makes the previous window (previous => up the screen) the
 * current window. There arn't any errors, although the command does not do a
 * lot if there is 1 window.
 */
int prevwind(int f, int n)
{
	struct window *wp1;
	struct window *wp2;

	/* if we have an argument, we mean the nth window from the bottom */
	if (f)
		return nextwind(f, -n);

	wp1 = wheadp;
	wp2 = curwp;

	if (wp1 == wp2)
		wp2 = NULL;

	while (wp1->w_wndp != wp2)
		wp1 = wp1->w_wndp;

	curwp = wp1;
	curbp = wp1->w_bufp;
	cknewwindow();
	upmode();
	return TRUE;
}

/*
 * This command moves the current window down by "arg" lines. Recompute the
 * top line in the window. The move up and move down code is almost completely
 * the same; most of the work has to do with reframing the window, and picking
 * a new dot. We share the code by having "move down" just be an interface to
 * "move up". Magic. Bound to "C-X C-N".
 */
int mvdnwind(int f, int n)
{
	return mvupwind(f, -n);
}

/*
 * Move the current window up by "arg" lines. Recompute the new top line of
 * the window. Look to see if "." is still on the screen. If it is, you win.
 * If it isn't, then move "." to center it in the new framing of the window
 * (this command does not really move "."; it moves the frame). Bound to
 * "C-X C-P".
 */
int mvupwind(int f, int n)
{
	struct line *lp;
	int i;

	lp = curwp->w_linep;

	if (n < 0) {
		while (n++ && lp != curbp->b_linep)
			lp = lforw(lp);
	} else {
		while (n-- && lback(lp) != curbp->b_linep)
			lp = lback(lp);
	}

	curwp->w_linep = lp;
	curwp->w_flag |= WFHARD;	/* Mode line is OK. */

	for (i = 0; i < curwp->w_ntrows; ++i) {
		if (lp == curwp->w_dotp)
			return TRUE;
		if (lp == curbp->b_linep)
			break;
		lp = lforw(lp);
	}

	lp = curwp->w_linep;
	i = curwp->w_ntrows / 2;

	while (i-- && lp != curbp->b_linep)
		lp = lforw(lp);

	curwp->w_dotp = lp;
	curwp->w_doto = 0;
	return TRUE;
}

/*
 * This command makes the current window the only window on the screen. Bound
 * to "C-X 1". Try to set the framing so that "." does not have to move on the
 * display. Some care has to be taken to keep the values of dot and mark in
 * the buffer structures right if the distruction of a window makes a buffer
 * become undisplayed.
 */
int onlywind(int f, int n)
{
	struct window *wp;
	struct line *lp;
	int i;

	while (wheadp != curwp) {
		wp = wheadp;
		wheadp = wp->w_wndp;
		if (--wp->w_bufp->b_nwnd == 0) {
			wp->w_bufp->b_dotp = wp->w_dotp;
			wp->w_bufp->b_doto = wp->w_doto;
			wp->w_bufp->b_markp = wp->w_markp;
			wp->w_bufp->b_marko = wp->w_marko;
		}
		free((char *) wp);
	}
	while (curwp->w_wndp != NULL) {
		wp = curwp->w_wndp;
		curwp->w_wndp = wp->w_wndp;
		if (--wp->w_bufp->b_nwnd == 0) {
			wp->w_bufp->b_dotp = wp->w_dotp;
			wp->w_bufp->b_doto = wp->w_doto;
			wp->w_bufp->b_markp = wp->w_markp;
			wp->w_bufp->b_marko = wp->w_marko;
		}
		free((char *) wp);
	}
	lp = curwp->w_linep;
	i = curwp->w_toprow;
	while (i != 0 && lback(lp) != curbp->b_linep) {
		--i;
		lp = lback(lp);
	}
	curwp->w_toprow = 0;
	curwp->w_ntrows = term.t_nrow - 1;
	curwp->w_linep = lp;
	curwp->w_flag |= WFMODE | WFHARD;
	return TRUE;
}

/*
 * Delete the current window, placing its space in the window above,
 * or, if it is the top window, the window below. Bound to C-X 0.
 *
 * int f, n;	arguments are ignored for this command
 */
int delwind(int f, int n)
{
	struct window *wp;	/* window to recieve deleted space */
	struct window *lwp;	/* ptr window before curwp */
	int target;	/* target line to search for */

	/* if there is only one window, don't delete it */
	if (wheadp->w_wndp == NULL) {
		mlwrite("Can not delete this window");
		return FALSE;
	}

	/* find window before curwp in linked list */
	wp = wheadp;
	lwp = NULL;
	while (wp != NULL) {
		if (wp == curwp)
			break;
		lwp = wp;
		wp = wp->w_wndp;
	}

	/* find recieving window and give up our space */
	wp = wheadp;
	if (curwp->w_toprow == 0) {
		/* find the next window down */
		target = curwp->w_ntrows + 1;
		while (wp != NULL) {
			if (wp->w_toprow == target)
				break;
			wp = wp->w_wndp;
		}
		if (wp == NULL)
			return FALSE;
		wp->w_toprow = 0;
		wp->w_ntrows += target;
	} else {
		/* find the next window up */
		target = curwp->w_toprow - 1;
		while (wp != NULL) {
			if ((wp->w_toprow + wp->w_ntrows) == target)
				break;
			wp = wp->w_wndp;
		}
		if (wp == NULL)
			return FALSE;
		wp->w_ntrows += 1 + curwp->w_ntrows;
	}

	/* get rid of the current window */
	if (--curwp->w_bufp->b_nwnd == 0) {
		curwp->w_bufp->b_dotp = curwp->w_dotp;
		curwp->w_bufp->b_doto = curwp->w_doto;
		curwp->w_bufp->b_markp = curwp->w_markp;
		curwp->w_bufp->b_marko = curwp->w_marko;
	}
	if (lwp == NULL)
		wheadp = curwp->w_wndp;
	else
		lwp->w_wndp = curwp->w_wndp;
	free((char *) curwp);
	curwp = wp;
	wp->w_flag |= WFHARD;
	curbp = wp->w_bufp;
	cknewwindow();
	upmode();
	return TRUE;
}

/*
 * Split the current window.  A window smaller than 3 lines cannot be
 * split.  An argument of 1 forces the cursor into the upper window, an
 * argument of two forces the cursor to the lower window.  The only
 * other error that is possible is a "malloc" failure allocating the
 * structure for the new window.  Bound to "C-X 2". 
 *
 * int f, n;	default flag and numeric argument
 */
int splitwind(int f, int n)
{
	struct window *wp;
	struct line *lp;
	int ntru;
	int ntrl;
	int ntrd;
	struct window *wp1;
	struct window *wp2;

	if (curwp->w_ntrows < 3) {
		mlwrite("Cannot split a %d line window", curwp->w_ntrows);
		return FALSE;
	}
	wp = xmalloc(sizeof(struct window));
	++curbp->b_nwnd;	/* Displayed twice.     */
	wp->w_bufp = curbp;
	wp->w_dotp = curwp->w_dotp;
	wp->w_doto = curwp->w_doto;
	wp->w_markp = curwp->w_markp;
	wp->w_marko = curwp->w_marko;
	wp->w_flag = 0;
	wp->w_force = 0;
#if	COLOR
	/* set the colors of the new window */
	wp->w_fcolor = gfcolor;
	wp->w_bcolor = gbcolor;
#endif
	ntru = (curwp->w_ntrows - 1) / 2;	/* Upper size           */
	ntrl = (curwp->w_ntrows - 1) - ntru;	/* Lower size           */
	lp = curwp->w_linep;
	ntrd = 0;
	while (lp != curwp->w_dotp) {
		++ntrd;
		lp = lforw(lp);
	}
	lp = curwp->w_linep;
	if (((f == FALSE) && (ntrd <= ntru)) || ((f == TRUE) && (n == 1))) {
		/* Old is upper window. */
		if (ntrd == ntru)	/* Hit mode line.       */
			lp = lforw(lp);
		curwp->w_ntrows = ntru;
		wp->w_wndp = curwp->w_wndp;
		curwp->w_wndp = wp;
		wp->w_toprow = curwp->w_toprow + ntru + 1;
		wp->w_ntrows = ntrl;
	} else {		/* Old is lower window  */
		wp1 = NULL;
		wp2 = wheadp;
		while (wp2 != curwp) {
			wp1 = wp2;
			wp2 = wp2->w_wndp;
		}
		if (wp1 == NULL)
			wheadp = wp;
		else
			wp1->w_wndp = wp;
		wp->w_wndp = curwp;
		wp->w_toprow = curwp->w_toprow;
		wp->w_ntrows = ntru;
		++ntru;		/* Mode line.           */
		curwp->w_toprow += ntru;
		curwp->w_ntrows = ntrl;
		while (ntru--)
			lp = lforw(lp);
	}
	curwp->w_linep = lp;	/* Adjust the top lines */
	wp->w_linep = lp;	/* if necessary.        */
	curwp->w_flag |= WFMODE | WFHARD;
	wp->w_flag |= WFMODE | WFHARD;
	return TRUE;
}

/*
 * Enlarge the current window. Find the window that loses space. Make sure it
 * is big enough. If so, hack the window descriptions, and ask redisplay to do
 * all the hard work. You don't just set "force reframe" because dot would
 * move. Bound to "C-X Z".
 */
int enlargewind(int f, int n)
{
	struct window *adjwp;
	struct line *lp;
	int i;

	if (n < 0)
		return shrinkwind(f, -n);
	if (wheadp->w_wndp == NULL) {
		mlwrite("Only one window");
		return FALSE;
	}
	if ((adjwp = curwp->w_wndp) == NULL) {
		adjwp = wheadp;
		while (adjwp->w_wndp != curwp)
			adjwp = adjwp->w_wndp;
	}
	if (adjwp->w_ntrows <= n) {
		mlwrite("Impossible change");
		return FALSE;
	}
	if (curwp->w_wndp == adjwp) {	/* Shrink below.        */
		lp = adjwp->w_linep;
		for (i = 0; i < n && lp != adjwp->w_bufp->b_linep; ++i)
			lp = lforw(lp);
		adjwp->w_linep = lp;
		adjwp->w_toprow += n;
	} else {		/* Shrink above.        */
		lp = curwp->w_linep;
		for (i = 0; i < n && lback(lp) != curbp->b_linep; ++i)
			lp = lback(lp);
		curwp->w_linep = lp;
		curwp->w_toprow -= n;
	}
	curwp->w_ntrows += n;
	adjwp->w_ntrows -= n;
#if	SCROLLCODE
	curwp->w_flag |= WFMODE | WFHARD | WFINS;
	adjwp->w_flag |= WFMODE | WFHARD | WFKILLS;
#else
	curwp->w_flag |= WFMODE | WFHARD;
	adjwp->w_flag |= WFMODE | WFHARD;
#endif
	return TRUE;
}

/*
 * Shrink the current window. Find the window that gains space. Hack at the
 * window descriptions. Ask the redisplay to do all the hard work. Bound to
 * "C-X C-Z".
 */
int shrinkwind(int f, int n)
{
	struct window *adjwp;
	struct line *lp;
	int i;

	if (n < 0)
		return enlargewind(f, -n);
	if (wheadp->w_wndp == NULL) {
		mlwrite("Only one window");
		return FALSE;
	}
	if ((adjwp = curwp->w_wndp) == NULL) {
		adjwp = wheadp;
		while (adjwp->w_wndp != curwp)
			adjwp = adjwp->w_wndp;
	}
	if (curwp->w_ntrows <= n) {
		mlwrite("Impossible change");
		return FALSE;
	}
	if (curwp->w_wndp == adjwp) {	/* Grow below.          */
		lp = adjwp->w_linep;
		for (i = 0; i < n && lback(lp) != adjwp->w_bufp->b_linep;
		     ++i)
			lp = lback(lp);
		adjwp->w_linep = lp;
		adjwp->w_toprow -= n;
	} else {		/* Grow above.          */
		lp = curwp->w_linep;
		for (i = 0; i < n && lp != curbp->b_linep; ++i)
			lp = lforw(lp);
		curwp->w_linep = lp;
		curwp->w_toprow += n;
	}
	curwp->w_ntrows -= n;
	adjwp->w_ntrows += n;
#if	SCROLLCODE
	curwp->w_flag |= WFMODE | WFHARD | WFKILLS;
	adjwp->w_flag |= WFMODE | WFHARD | WFINS;
#else
	curwp->w_flag |= WFMODE | WFHARD;
	adjwp->w_flag |= WFMODE | WFHARD;
#endif
	return TRUE;
}

/*
 * Resize the current window to the requested size
 *
 * int f, n;		default flag and numeric argument
 */
int resize(int f, int n)
{
	int clines;		/* current # of lines in window */

	/* must have a non-default argument, else ignore call */
	if (f == FALSE)
		return TRUE;

	/* find out what to do */
	clines = curwp->w_ntrows;

	/* already the right size? */
	if (clines == n)
		return TRUE;

	return enlargewind(TRUE, n - clines);
}

/*
 * Pick a window for a pop-up. Split the screen if there is only one window.
 * Pick the uppermost window that isn't the current window. An LRU algorithm
 * might be better. Return a pointer, or NULL on error.
 */
struct window *wpopup(void)
{
	struct window *wp;

	if (wheadp->w_wndp == NULL	/* Only 1 window        */
	    && splitwind(FALSE, 0) == FALSE)	/* and it won't split   */
		return NULL;
	wp = wheadp;		/* Find window to use   */
	while (wp != NULL && wp == curwp)
		wp = wp->w_wndp;
	return wp;
}

int scrnextup(int f, int n)
{				/* scroll the next window up (back) a page */
	nextwind(FALSE, 1);
	backpage(f, n);
	prevwind(FALSE, 1);
	return TRUE;
}

int scrnextdw(int f, int n)
{				/* scroll the next window down (forward) a page */
	nextwind(FALSE, 1);
	forwpage(f, n);
	prevwind(FALSE, 1);
	return TRUE;
}

int savewnd(int f, int n)
{				/* save ptr to current window */
	swindow = curwp;
	return TRUE;
}

int restwnd(int f, int n)
{				/* restore the saved screen */
	struct window *wp;

	/* find the window */
	wp = wheadp;
	while (wp != NULL) {
		if (wp == swindow) {
			curwp = wp;
			curbp = wp->w_bufp;
			upmode();
			return TRUE;
		}
		wp = wp->w_wndp;
	}

	mlwrite("(No such window exists)");
	return FALSE;
}

/*
 * resize the screen, re-writing the screen
 *
 * int f;	default flag
 * int n;	numeric argument
 */
int newsize(int f, int n)
{
	struct window *wp;		/* current window being examined */
	struct window *nextwp;	/* next window to scan */
	struct window *lastwp;	/* last window scanned */
	int lastline;		/* screen line of last line of current window */

	/* if the command defaults, assume the largest */
	if (f == FALSE)
		n = term.t_mrow + 1;

	/* make sure it's in range */
	if (n < 3 || n > term.t_mrow + 1) {
		mlwrite("%%Screen size out of range");
		return FALSE;
	}

	if (term.t_nrow == n - 1)
		return TRUE;
	else if (term.t_nrow < n - 1) {

		/* go to the last window */
		wp = wheadp;
		while (wp->w_wndp != NULL)
			wp = wp->w_wndp;

		/* and enlarge it as needed */
		wp->w_ntrows = n - wp->w_toprow - 2;
		wp->w_flag |= WFHARD | WFMODE;

	} else {

		/* rebuild the window structure */
		nextwp = wheadp;
		wp = NULL;
		lastwp = NULL;
		while (nextwp != NULL) {
			wp = nextwp;
			nextwp = wp->w_wndp;

			/* get rid of it if it is too low */
			if (wp->w_toprow > n - 2) {

				/* save the point/mark if needed */
				if (--wp->w_bufp->b_nwnd == 0) {
					wp->w_bufp->b_dotp = wp->w_dotp;
					wp->w_bufp->b_doto = wp->w_doto;
					wp->w_bufp->b_markp = wp->w_markp;
					wp->w_bufp->b_marko = wp->w_marko;
				}

				/* update curwp and lastwp if needed */
				if (wp == curwp)
					curwp = wheadp;
				curbp = curwp->w_bufp;
				if (lastwp != NULL)
					lastwp->w_wndp = NULL;

				/* free the structure */
				free((char *) wp);
				wp = NULL;

			} else {
				/* need to change this window size? */
				lastline = wp->w_toprow + wp->w_ntrows - 1;
				if (lastline >= n - 2) {
					wp->w_ntrows =
					    n - wp->w_toprow - 2;
					wp->w_flag |= WFHARD | WFMODE;
				}
			}

			lastwp = wp;
		}
	}

	/* screen is garbage */
	term.t_nrow = n - 1;
	sgarbf = TRUE;
	return TRUE;
}

/*
 * resize the screen, re-writing the screen
 *
 * int f;		default flag
 * int n;		numeric argument
 */
int newwidth(int f, int n)
{
	struct window *wp;

	/* if the command defaults, assume the largest */
	if (f == FALSE)
		n = term.t_mcol;

	/* make sure it's in range */
	if (n < 10 || n > term.t_mcol) {
		mlwrite("%%Screen width out of range");
		return FALSE;
	}

	/* otherwise, just re-width it (no big deal) */
	term.t_ncol = n;
	term.t_margin = n / 10;
	term.t_scrsiz = n - (term.t_margin * 2);

	/* florce all windows to redraw */
	wp = wheadp;
	while (wp) {
		wp->w_flag |= WFHARD | WFMOVE | WFMODE;
		wp = wp->w_wndp;
	}
	sgarbf = TRUE;

	return TRUE;
}

int getwpos(void)
{				/* get screen offset of current line in current window */
	int sline;	/* screen line from top of window */
	struct line *lp;	/* scannile line pointer */

	/* search down the line we want */
	lp = curwp->w_linep;
	sline = 1;
	while (lp != curwp->w_dotp) {
		++sline;
		lp = lforw(lp);
	}

	/* and return the value */
	return sline;
}

void cknewwindow(void)
{
	execute(META | SPEC | 'X', FALSE, 1);
}


/* ----- word.c ----- */
/*	word.c
 *
 *      The routines in this file implement commands that work word or a
 *      paragraph at a time.  There are all sorts of word mode commands.  If I
 *      do any sentence mode commands, they are likely to be put in this file.
 *
 *	Modified by Petri Kutvonen
 */
/* system header already included */
/* #include "estruct.h" - amalgamated */
/* #include "edef.h" - amalgamated */
/* #include "efunc.h" - amalgamated */
/* #include "line.h" - amalgamated */

/* Word wrap on n-spaces. Back-over whatever precedes the point on the current
 * line and stop on the first word-break or the beginning of the line. If we
 * reach the beginning of the line, jump back to the end of the word and start
 * a new line.	Otherwise, break the line at the word-break, eat it, and jump
 * back to the end of the word.
 * Returns TRUE on success, FALSE on errors.
 *
 * @f: default flag.
 * @n: numeric argument.
 */
int wrapword(int f, int n)
{
	int cnt;	/* size of word wrapped to next line */
	int c;		/* charector temporary */

	/* backup from the <NL> 1 char */
	if (!backchar(0, 1))
		return FALSE;

	/* back up until we aren't in a word,
	   make sure there is a break in the line */
	cnt = 0;
	while (((c = lgetc(curwp->w_dotp, curwp->w_doto)) != ' ')
	       && (c != '\t')) {
		cnt++;
		if (!backchar(0, 1))
			return FALSE;
		/* if we make it to the beginning, start a new line */
		if (curwp->w_doto == 0) {
			gotoeol(FALSE, 0);
			return lnewline();
		}
	}

	/* delete the forward white space */
	if (!forwdel(0, 1))
		return FALSE;

	/* put in a end of line */
	if (!lnewline())
		return FALSE;

	/* and past the first word */
	while (cnt-- > 0) {
		if (forwchar(FALSE, 1) == FALSE)
			return FALSE;
	}
	return TRUE;
}

/*
 * Move the cursor backward by "n" words. All of the details of motion are
 * performed by the "backchar" and "forwchar" routines. Error if you try to
 * move beyond the buffers.
 */
int backword(int f, int n)
{
	if (n < 0)
		return forwword(f, -n);
	if (backchar(FALSE, 1) == FALSE)
		return FALSE;
	while (n--) {
		while (inword() == FALSE) {
			if (backchar(FALSE, 1) == FALSE)
				return FALSE;
		}
		while (inword() != FALSE) {
			if (backchar(FALSE, 1) == FALSE)
				return FALSE;
		}
	}
	return forwchar(FALSE, 1);
}

/*
 * Move the cursor forward by the specified number of words. All of the motion
 * is done by "forwchar". Error if you try and move beyond the buffer's end.
 */
int forwword(int f, int n)
{
	if (n < 0)
		return backword(f, -n);
	while (n--) {
		while (inword() == TRUE) {
			if (forwchar(FALSE, 1) == FALSE)
				return FALSE;
		}

		while (inword() == FALSE) {
			if (forwchar(FALSE, 1) == FALSE)
				return FALSE;
		}
	}
	return TRUE;
}

/*
 * Move the cursor forward by the specified number of words. As you move,
 * convert any characters to upper case. Error if you try and move beyond the
 * end of the buffer. Bound to "M-U".
 */
int upperword(int f, int n)
{
	int c;

	if (curbp->b_mode & MDVIEW)	/* don't allow this command if      */
		return rdonly();	/* we are in read only mode     */
	if (n < 0)
		return FALSE;
	while (n--) {
		while (inword() == FALSE) {
			if (forwchar(FALSE, 1) == FALSE)
				return FALSE;
		}
		while (inword() != FALSE) {
			c = lgetc(curwp->w_dotp, curwp->w_doto);
#if	PKCODE
			if (islower(c)) {
#else
			if (c >= 'a' && c <= 'z') {
#endif
				c -= 'a' - 'A';
				lputc(curwp->w_dotp, curwp->w_doto, c);
				lchange(WFHARD);
			}
			if (forwchar(FALSE, 1) == FALSE)
				return FALSE;
		}
	}
	return TRUE;
}

/*
 * Move the cursor forward by the specified number of words. As you move
 * convert characters to lower case. Error if you try and move over the end of
 * the buffer. Bound to "M-L".
 */
int lowerword(int f, int n)
{
	int c;

	if (curbp->b_mode & MDVIEW)	/* don't allow this command if      */
		return rdonly();	/* we are in read only mode     */
	if (n < 0)
		return FALSE;
	while (n--) {
		while (inword() == FALSE) {
			if (forwchar(FALSE, 1) == FALSE)
				return FALSE;
		}
		while (inword() != FALSE) {
			c = lgetc(curwp->w_dotp, curwp->w_doto);
#if	PKCODE
			if (isupper(c)) {
#else
			if (c >= 'A' && c <= 'Z') {
#endif
				c += 'a' - 'A';
				lputc(curwp->w_dotp, curwp->w_doto, c);
				lchange(WFHARD);
			}
			if (forwchar(FALSE, 1) == FALSE)
				return FALSE;
		}
	}
	return TRUE;
}

/*
 * Move the cursor forward by the specified number of words. As you move
 * convert the first character of the word to upper case, and subsequent
 * characters to lower case. Error if you try and move past the end of the
 * buffer. Bound to "M-C".
 */
int capword(int f, int n)
{
	int c;

	if (curbp->b_mode & MDVIEW)	/* don't allow this command if      */
		return rdonly();	/* we are in read only mode     */
	if (n < 0)
		return FALSE;
	while (n--) {
		while (inword() == FALSE) {
			if (forwchar(FALSE, 1) == FALSE)
				return FALSE;
		}
		if (inword() != FALSE) {
			c = lgetc(curwp->w_dotp, curwp->w_doto);
#if	PKCODE
			if (islower(c)) {
#else
			if (c >= 'a' && c <= 'z') {
#endif
				c -= 'a' - 'A';
				lputc(curwp->w_dotp, curwp->w_doto, c);
				lchange(WFHARD);
			}
			if (forwchar(FALSE, 1) == FALSE)
				return FALSE;
			while (inword() != FALSE) {
				c = lgetc(curwp->w_dotp, curwp->w_doto);
#if	PKCODE
				if (isupper(c)) {
#else
				if (c >= 'A' && c <= 'Z') {
#endif
					c += 'a' - 'A';
					lputc(curwp->w_dotp, curwp->w_doto,
					      c);
					lchange(WFHARD);
				}
				if (forwchar(FALSE, 1) == FALSE)
					return FALSE;
			}
		}
	}
	return TRUE;
}

/*
 * Kill forward by "n" words. Remember the location of dot. Move forward by
 * the right number of words. Put dot back where it was and issue the kill
 * command for the right number of characters. With a zero argument, just
 * kill one word and no whitespace. Bound to "M-D".
 */
int delfword(int f, int n)
{
	struct line *dotp;	/* original cursor line */
	int doto;	/*      and row */
	int c;		/* temp char */
	long size;		/* # of chars to delete */

	/* don't allow this command if we are in read only mode */
	if (curbp->b_mode & MDVIEW)
		return rdonly();

	/* ignore the command if there is a negative argument */
	if (n < 0)
		return FALSE;

	/* Clear the kill buffer if last command wasn't a kill */
	if ((lastflag & CFKILL) == 0)
		kdelete();
	thisflag |= CFKILL;	/* this command is a kill */

	/* save the current cursor position */
	dotp = curwp->w_dotp;
	doto = curwp->w_doto;

	/* figure out how many characters to give the axe */
	size = 0;

	/* get us into a word.... */
	while (inword() == FALSE) {
		if (forwchar(FALSE, 1) == FALSE)
			return FALSE;
		++size;
	}

	if (n == 0) {
		/* skip one word, no whitespace! */
		while (inword() == TRUE) {
			if (forwchar(FALSE, 1) == FALSE)
				return FALSE;
			++size;
		}
	} else {
		/* skip n words.... */
		while (n--) {

			/* if we are at EOL; skip to the beginning of the next */
			while (curwp->w_doto == llength(curwp->w_dotp)) {
				if (forwchar(FALSE, 1) == FALSE)
					return FALSE;
				++size;
			}

			/* move forward till we are at the end of the word */
			while (inword() == TRUE) {
				if (forwchar(FALSE, 1) == FALSE)
					return FALSE;
				++size;
			}

			/* if there are more words, skip the interword stuff */
			if (n != 0)
				while (inword() == FALSE) {
					if (forwchar(FALSE, 1) == FALSE)
						return FALSE;
					++size;
				}
		}

		/* skip whitespace and newlines */
		while ((curwp->w_doto == llength(curwp->w_dotp)) ||
		       ((c = lgetc(curwp->w_dotp, curwp->w_doto)) == ' ')
		       || (c == '\t')) {
			if (forwchar(FALSE, 1) == FALSE)
				break;
			++size;
		}
	}

	/* restore the original position and delete the words */
	curwp->w_dotp = dotp;
	curwp->w_doto = doto;
	return ldelete(size, TRUE);
}

/*
 * Kill backwards by "n" words. Move backwards by the desired number of words,
 * counting the characters. When dot is finally moved to its resting place,
 * fire off the kill command. Bound to "M-Rubout" and to "M-Backspace".
 */
int delbword(int f, int n)
{
	long size;

	/* don't allow this command if we are in read only mode */
	if (curbp->b_mode & MDVIEW)
		return rdonly();

	/* ignore the command if there is a nonpositive argument */
	if (n <= 0)
		return FALSE;

	/* Clear the kill buffer if last command wasn't a kill */
	if ((lastflag & CFKILL) == 0)
		kdelete();
	thisflag |= CFKILL;	/* this command is a kill */

	if (backchar(FALSE, 1) == FALSE)
		return FALSE;
	size = 0;
	while (n--) {
		while (inword() == FALSE) {
			if (backchar(FALSE, 1) == FALSE)
				return FALSE;
			++size;
		}
		while (inword() != FALSE) {
			++size;
			if (backchar(FALSE, 1) == FALSE)
				goto bckdel;
		}
	}
	if (forwchar(FALSE, 1) == FALSE)
		return FALSE;
      bckdel:return ldelchar(size, TRUE);
}

/*
 * Return TRUE if the character at dot is a character that is considered to be
 * part of a word. The word character list is hard coded. Should be setable.
 */
int inword(void)
{
	int c;

	if (curwp->w_doto == llength(curwp->w_dotp))
		return FALSE;
	c = lgetc(curwp->w_dotp, curwp->w_doto);
#if	PKCODE
	if (isletter(c))
#else
	if (c >= 'a' && c <= 'z')
		return TRUE;
	if (c >= 'A' && c <= 'Z')
#endif
		return TRUE;
	if (c >= '0' && c <= '9')
		return TRUE;
	return FALSE;
}

#if	WORDPRO
/*
 * Fill the current paragraph according to the current
 * fill column
 *
 * f and n - deFault flag and Numeric argument
 */
int fillpara(int f, int n)
{
	unicode_t c;		/* current char during scan    */
	unicode_t wbuf[NSTRING];/* buffer for current word      */
	int wordlen;	/* length of current word       */
	int clength;	/* position on line during fill */
	int i;		/* index during word copy       */
	int newlength;	/* tentative new line length    */
	int eopflag;	/* Are we at the End-Of-Paragraph? */
	int firstflag;	/* first word? (needs no space) */
	struct line *eopline;	/* pointer to line just past EOP */
	int dotflag;	/* was the last char a period?  */

	if (curbp->b_mode & MDVIEW)	/* don't allow this command if      */
		return rdonly();	/* we are in read only mode     */
	if (fillcol == 0) {	/* no fill column set */
		mlwrite("No fill column set");
		return FALSE;
	}
#if	PKCODE
	justflag = FALSE;
#endif

	/* record the pointer to the line just past the EOP */
	gotoeop(FALSE, 1);
	eopline = lforw(curwp->w_dotp);

	/* and back top the beginning of the paragraph */
	gotobop(FALSE, 1);

	/* initialize various info */
	clength = curwp->w_doto;
	if (clength && curwp->w_dotp->l_text[0] == TAB)
		clength = 8;
	wordlen = 0;
	dotflag = FALSE;

	/* scan through lines, filling words */
	firstflag = TRUE;
	eopflag = FALSE;
	while (!eopflag) {
		int bytes = 1;

		/* get the next character in the paragraph */
		if (curwp->w_doto == llength(curwp->w_dotp)) {
			c = ' ';
			if (lforw(curwp->w_dotp) == eopline)
				eopflag = TRUE;
		} else
			bytes = lgetchar(&c);

		/* and then delete it */
		ldelete(bytes, FALSE);

		/* if not a separator, just add it in */
		if (c != ' ' && c != '\t') {
			dotflag = (c == '.');	/* was it a dot */
			if (wordlen < NSTRING - 1)
				wbuf[wordlen++] = c;
		} else if (wordlen) {
			/* at a word break with a word waiting */
			/* calculate tentitive new length with word added */
			newlength = clength + 1 + wordlen;
			if (newlength <= fillcol) {
				/* add word to current line */
				if (!firstflag) {
					linsert(1, ' ');	/* the space */
					++clength;
				}
				firstflag = FALSE;
			} else {
				/* start a new line */
				lnewline();
				clength = 0;
			}

			/* and add the word in in either case */
			for (i = 0; i < wordlen; i++) {
				linsert(1, wbuf[i]);
				++clength;
			}
			if (dotflag) {
				linsert(1, ' ');
				++clength;
			}
			wordlen = 0;
		}
	}
	/* and add a last newline for the end of our new paragraph */
	lnewline();
	return TRUE;
}

#if	PKCODE
/* Fill the current paragraph according to the current
 * fill column and cursor position
 *
 * int f, n;		deFault flag and Numeric argument
 */
int justpara(int f, int n)
{
	unicode_t c;		/* current char durring scan    */
	unicode_t wbuf[NSTRING];/* buffer for current word      */
	int wordlen;	/* length of current word       */
	int clength;	/* position on line during fill */
	int i;		/* index during word copy       */
	int newlength;	/* tentative new line length    */
	int eopflag;	/* Are we at the End-Of-Paragraph? */
	int firstflag;	/* first word? (needs no space) */
	struct line *eopline;	/* pointer to line just past EOP */
	int leftmarg;		/* left marginal */

	if (curbp->b_mode & MDVIEW)	/* don't allow this command if      */
		return rdonly();	/* we are in read only mode     */
	if (fillcol == 0) {	/* no fill column set */
		mlwrite("No fill column set");
		return FALSE;
	}
	justflag = TRUE;
	leftmarg = curwp->w_doto;
	if (leftmarg + 10 > fillcol) {
		leftmarg = 0;
		mlwrite("Column too narrow");
		return FALSE;
	}

	/* record the pointer to the line just past the EOP */
	gotoeop(FALSE, 1);
	eopline = lforw(curwp->w_dotp);

	/* and back top the beginning of the paragraph */
	gotobop(FALSE, 1);

	/* initialize various info */
	if (leftmarg < llength(curwp->w_dotp))
		curwp->w_doto = leftmarg;

	clength = curwp->w_doto;
	if (clength && curwp->w_dotp->l_text[0] == TAB)
		clength = 8;

	wordlen = 0;

	/* scan through lines, filling words */
	firstflag = TRUE;
	eopflag = FALSE;
	while (!eopflag) {
		int bytes = 1;

		/* get the next character in the paragraph */
		if (curwp->w_doto == llength(curwp->w_dotp)) {
			c = ' ';
			if (lforw(curwp->w_dotp) == eopline)
				eopflag = TRUE;
		} else
			bytes = lgetchar(&c);

		/* and then delete it */
		ldelete(bytes, FALSE);

		/* if not a separator, just add it in */
		if (c != ' ' && c != '\t') {
			if (wordlen < NSTRING - 1)
				wbuf[wordlen++] = c;
		} else if (wordlen) {
			/* at a word break with a word waiting */
			/* calculate tentitive new length with word added */
			newlength = clength + 1 + wordlen;
			if (newlength <= fillcol) {
				/* add word to current line */
				if (!firstflag) {
					linsert(1, ' ');	/* the space */
					++clength;
				}
				firstflag = FALSE;
			} else {
				/* start a new line */
				lnewline();
				for (i = 0; i < leftmarg; i++)
					linsert(1, ' ');
				clength = leftmarg;
			}

			/* and add the word in in either case */
			for (i = 0; i < wordlen; i++) {
				linsert(1, wbuf[i]);
				++clength;
			}
			wordlen = 0;
		}
	}
	/* and add a last newline for the end of our new paragraph */
	lnewline();

	forwword(FALSE, 1);
	if (llength(curwp->w_dotp) > leftmarg)
		curwp->w_doto = leftmarg;
	else
		curwp->w_doto = llength(curwp->w_dotp);

	justflag = FALSE;
	return TRUE;
}
#endif

/*
 * delete n paragraphs starting with the current one
 *
 * int f	default flag
 * int n	# of paras to delete
 */
int killpara(int f, int n)
{
	int status;	/* returned status of functions */

	while (n--) {		/* for each paragraph to delete */

		/* mark out the end and beginning of the para to delete */
		gotoeop(FALSE, 1);

		/* set the mark here */
		curwp->w_markp = curwp->w_dotp;
		curwp->w_marko = curwp->w_doto;

		/* go to the beginning of the paragraph */
		gotobop(FALSE, 1);
		curwp->w_doto = 0;	/* force us to the beginning of line */

		/* and delete it */
		if ((status = killregion(FALSE, 1)) != TRUE)
			return status;

		/* and clean up the 2 extra lines */
		ldelete(2L, TRUE);
	}
	return TRUE;
}


/*
 *	wordcount:	count the # of words in the marked region,
 *			along with average word sizes, # of chars, etc,
 *			and report on them.
 *
 * int f, n;		ignored numeric arguments
 */
int wordcount(int f, int n)
{
	struct line *lp;	/* current line to scan */
	int offset;	/* current char to scan */
	long size;		/* size of region left to count */
	int ch;	/* current character to scan */
	int wordflag;	/* are we in a word now? */
	int lastword;	/* were we just in a word? */
	long nwords;		/* total # of words */
	long nchars;		/* total number of chars */
	int nlines;		/* total number of lines in region */
	int avgch;		/* average number of chars/word */
	int status;		/* status return code */
	struct region region;		/* region to look at */

	/* make sure we have a region to count */
	if ((status = getregion(&region)) != TRUE)
		return status;
	lp = region.r_linep;
	offset = region.r_offset;
	size = region.r_size;

	/* count up things */
	lastword = FALSE;
	nchars = 0L;
	nwords = 0L;
	nlines = 0;
	while (size--) {

		/* get the current character */
		if (offset == llength(lp)) {	/* end of line */
			ch = '\n';
			lp = lforw(lp);
			offset = 0;
			++nlines;
		} else {
			ch = lgetc(lp, offset);
			++offset;
		}

		/* and tabulate it */
		wordflag = (
#if	PKCODE
				   (isletter(ch)) ||
#else
				   (ch >= 'a' && ch <= 'z') ||
				   (ch >= 'A' && ch <= 'Z') ||
#endif
				   (ch >= '0' && ch <= '9'));
		if (wordflag == TRUE && lastword == FALSE)
			++nwords;
		lastword = wordflag;
		++nchars;
	}

	/* and report on the info */
	if (nwords > 0L)
		avgch = (int) ((100L * nchars) / nwords);
	else
		avgch = 0;

	mlwrite("Words %D Chars %D Lines %d Avg chars/word %f",
		nwords, nchars, nlines + 1, avgch);
	return TRUE;
}
#endif


/* ----- main.c ----- */
/*
 *	main.c

 *	uEmacs/PK 4.0
 *
 *	Based on:
 *
 *	MicroEMACS 3.9
 *	Written by Dave G. Conroy.
 *	Substantially modified by Daniel M. Lawrence
 *	Modified by Petri Kutvonen
 *
 *	MicroEMACS 3.9 (c) Copyright 1987 by Daniel M. Lawrence
 *
 *	Original statement of copying policy:
 *
 *	MicroEMACS 3.9 can be copied and distributed freely for any
 *	non-commercial purposes. MicroEMACS 3.9 can only be incorporated
 *	into commercial software with the permission of the current author.
 *
 *	No copyright claimed for modifications made by Petri Kutvonen.
 *
 *	This file contains the main driving routine, and some keyboard
 *	processing code.
 *
 * REVISION HISTORY:
 *
 * 1.0  Steve Wilhite, 30-Nov-85
 *
 * 2.0  George Jones, 12-Dec-85
 *
 * 3.0  Daniel Lawrence, 29-Dec-85
 *
 * 3.2-3.6 Daniel Lawrence, Feb...Apr-86
 *
 * 3.7	Daniel Lawrence, 14-May-86
 *
 * 3.8	Daniel Lawrence, 18-Jan-87
 *
 * 3.9	Daniel Lawrence, 16-Jul-87
 *
 * 3.9e	Daniel Lawrence, 16-Nov-87
 *
 * After that versions 3.X and Daniel Lawrence went their own ways.
 * A modified 3.9e/PK was heavily used at the University of Helsinki
 * for several years on different UNIX, VMS, and MSDOS platforms.
 *
 * This modified version is now called eEmacs/PK.
 *
 * 4.0	Petri Kutvonen, 1-Sep-91
 *
 */
/* system header already included */
/* Make global definitions not external. */
#define	maindef

/* #include "estruct.h" - amalgamated */
/* #include "edef.h" - amalgamated */
/* #include "efunc.h" - amalgamated */
/* #include "ebind.h" - amalgamated */
/* #include "version.h" - amalgamated */

/* For MSDOS, increase the default stack space. */
#if MSDOS & TURBO
#if PKCODE
extern unsigned _stklen = 20000;
#else
extern unsigned _stklen = 32766;
#endif
#endif

#if VMS
#include <ssdef.h>
#define GOOD    (SS$_NORMAL)
#endif

#ifndef GOOD
#define GOOD    0
#endif

#if UNIX
/* system header already included */
static void emergencyexit(int);
#ifdef SIGWINCH
extern void sizesignal(int);
#endif
#endif

void usage(int status)
{
  printf("Usage: %s filename\n", PROGRAM_NAME);
  printf("   or: %s [options]\n\n", PROGRAM_NAME);
  fputs("      +          start at the end of file\n", stdout);
  fputs("      +<n>       start at line <n>\n", stdout);
  fputs("      -g[G]<n>   go to line <n>\n", stdout);
  fputs("      --help     display this help and exit\n", stdout);
  fputs("      --version  output version information and exit\n", stdout);

  exit(status);
}

int main(int argc, char **argv)
{
	int c = -1;	/* command character */
	int f;		/* default flag */
	int n;		/* numeric repeat count */
	int mflag;	/* negative flag on repeat */
	struct buffer *bp;	/* temp buffer pointer */
	int firstfile;	/* first file flag */
	int carg;	/* current arg to scan */
	int startflag;	/* startup executed flag */
	struct buffer *firstbp = NULL;	/* ptr to first buffer in cmd line */
	int basec;		/* c stripped of meta character */
	int viewflag;		/* are we starting in view mode? */
	int gotoflag;		/* do we need to goto a line at start? */
	int gline = 0;		/* if so, what line? */
	int searchflag;		/* Do we need to search at start? */
	int saveflag;		/* temp store for lastflag */
	int errflag;		/* C error processing? */
	char bname[NBUFN];	/* buffer name of file to read */
#if	CRYPT
	int cryptflag;		/* encrypting on the way in? */
	char ekey[NPAT];	/* startup encryption key */
#endif
	int newc;

#if	PKCODE & VMS
	(void) umask(-1); /* Use old protection (this is at wrong place). */
#endif

#if	PKCODE & BSD
	sleep(1); /* Time for window manager. */
#endif

#if	UNIX
#ifdef SIGWINCH
	signal(SIGWINCH, sizesignal);
#endif
#endif
	if (argc == 2) {
		if (strcmp(argv[1], "--help") == 0) {
			usage(EXIT_FAILURE);
		}
		if (strcmp(argv[1], "--version") == 0) {
			version();
			exit(EXIT_SUCCESS);
		}
	}

	/* Initialize the editor. */
	vtinit();		/* Display */
	edinit("main");		/* Buffers, windows */
	varinit();		/* user variables */

	viewflag = FALSE;	/* view mode defaults off in command line */
	gotoflag = FALSE;	/* set to off to begin with */
	searchflag = FALSE;	/* set to off to begin with */
	firstfile = TRUE;	/* no file to edit yet */
	startflag = FALSE;	/* startup file not executed yet */
	errflag = FALSE;	/* not doing C error parsing */
#if	CRYPT
	cryptflag = FALSE;	/* no encryption by default */
#endif

	/* Parse the command line */
	for (carg = 1; carg < argc; ++carg) {
		/* Process Switches */
#if	PKCODE
		if (argv[carg][0] == '+') {
			gotoflag = TRUE;
			gline = atoi(&argv[carg][1]);
		} else
#endif
		if (argv[carg][0] == '-') {
			switch (argv[carg][1]) {
				/* Process Startup macroes */
			case 'a':	/* process error file */
			case 'A':
				errflag = TRUE;
				break;
			case 'e':	/* -e for Edit file */
			case 'E':
				viewflag = FALSE;
				break;
			case 'g':	/* -g for initial goto */
			case 'G':
				gotoflag = TRUE;
				gline = atoi(&argv[carg][2]);
				break;
#if	CRYPT
			case 'k':	/* -k<key> for code key */
			case 'K':
				cryptflag = TRUE;
				strcpy(ekey, &argv[carg][2]);
				break;
#endif
#if	PKCODE
			case 'n':	/* -n accept null chars */
			case 'N':
				nullflag = TRUE;
				break;
#endif
			case 'r':	/* -r restrictive use */
			case 'R':
				restflag = TRUE;
				break;
			case 's':	/* -s for initial search string */
			case 'S':
				searchflag = TRUE;
				strncpy(pat, &argv[carg][2], NPAT);
				break;
			case 'v':	/* -v for View File */
			case 'V':
				viewflag = TRUE;
				break;
			default:	/* unknown switch */
				/* ignore this for now */
				break;
			}

		} else if (argv[carg][0] == '@') {

			/* Process Startup macroes */
			if (startup(&argv[carg][1]) == TRUE)
				/* don't execute emacs.rc */
				startflag = TRUE;

		} else {

			/* Process an input file */

			/* set up a buffer for this file */
			makename(bname, argv[carg]);
			unqname(bname);

			/* set this to inactive */
			bp = bfind(bname, TRUE, 0);
			strcpy(bp->b_fname, argv[carg]);
			bp->b_active = FALSE;
			if (firstfile) {
				firstbp = bp;
				firstfile = FALSE;
			}

			/* set the modes appropriatly */
			if (viewflag)
				bp->b_mode |= MDVIEW;
#if	CRYPT
			if (cryptflag) {
				bp->b_mode |= MDCRYPT;
				myencrypt((char *) NULL, 0);
				myencrypt(ekey, strlen(ekey));
				strncpy(bp->b_key, ekey, NPAT);
			}
#endif
		}
	}

#if	UNIX
	signal(SIGHUP, emergencyexit);
	signal(SIGTERM, emergencyexit);
#endif

	/* if we are C error parsing... run it! */
	if (errflag) {
		if (startup("error.cmd") == TRUE)
			startflag = TRUE;
	}

	/* if invoked with no other startup files,
	   run the system startup file here */
	if (startflag == FALSE) {
		startup("");
		startflag = TRUE;
	}
	discmd = TRUE;		/* P.K. */

	/* if there are any files to read, read the first one! */
	bp = bfind("main", FALSE, 0);
	if (firstfile == FALSE && (gflags & GFREAD)) {
		swbuffer(firstbp);
		zotbuf(bp);
	} else
		bp->b_mode |= gmode;

	/* Deal with startup gotos and searches */
	if (gotoflag && searchflag) {
		update(FALSE);
		mlwrite("(Can not search and goto at the same time!)");
	} else if (gotoflag) {
		if (gotoline(TRUE, gline) == FALSE) {
			update(FALSE);
			mlwrite("(Bogus goto argument)");
		}
	} else if (searchflag) {
		if (forwhunt(FALSE, 0) == FALSE)
			update(FALSE);
	}

	/* Setup to process commands. */
	lastflag = 0;  /* Fake last flags. */

      loop:
	/* Execute the "command" macro...normally null. */
	saveflag = lastflag;  /* Preserve lastflag through this. */
	execute(META | SPEC | 'C', FALSE, 1);
	lastflag = saveflag;

#if TYPEAH && PKCODE
	if (typahead()) {
		newc = getcmd();
		update(FALSE);
		do {
			fn_t execfunc;

			if (c == newc && (execfunc = getbind(c)) != NULL
			    && execfunc != insert_newline
			    && execfunc != insert_tab)
				newc = getcmd();
			else
				break;
		} while (typahead());
		c = newc;
	} else {
		update(FALSE);
		c = getcmd();
	}
#else
	/* Fix up the screen    */
	update(FALSE);

	/* get the next command from the keyboard */
	c = getcmd();
#endif
	/* if there is something on the command line, clear it */
	if (mpresf != FALSE) {
		mlerase();
		update(FALSE);
#if	CLRMSG
		if (c == ' ')	/* ITS EMACS does this  */
			goto loop;
#endif
	}
	f = FALSE;
	n = 1;

	/* do META-# processing if needed */

	basec = c & ~META;	/* strip meta char off if there */
	if ((c & META) && ((basec >= '0' && basec <= '9') || basec == '-')) {
		f = TRUE;	/* there is a # arg */
		n = 0;		/* start with a zero default */
		mflag = 1;	/* current minus flag */
		c = basec;	/* strip the META */
		while ((c >= '0' && c <= '9') || (c == '-')) {
			if (c == '-') {
				/* already hit a minus or digit? */
				if ((mflag == -1) || (n != 0))
					break;
				mflag = -1;
			} else {
				n = n * 10 + (c - '0');
			}
			if ((n == 0) && (mflag == -1))	/* lonely - */
				mlwrite("Arg:");
			else
				mlwrite("Arg: %d", n * mflag);

			c = getcmd();	/* get the next key */
		}
		n = n * mflag;	/* figure in the sign */
	}

	/* do ^U repeat argument processing */

	if (c == reptc) {	/* ^U, start argument   */
		f = TRUE;
		n = 4;		/* with argument of 4 */
		mflag = 0;	/* that can be discarded. */
		mlwrite("Arg: 4");
		while (((c = getcmd()) >= '0' && c <= '9') || c == reptc
		       || c == '-') {
			if (c == reptc)
				if ((n > 0) == ((n * 4) > 0))
					n = n * 4;
				else
					n = 1;
			/*
			 * If dash, and start of argument string, set arg.
			 * to -1.  Otherwise, insert it.
			 */
			else if (c == '-') {
				if (mflag)
					break;
				n = 0;
				mflag = -1;
			}
			/*
			 * If first digit entered, replace previous argument
			 * with digit and set sign.  Otherwise, append to arg.
			 */
			else {
				if (!mflag) {
					n = 0;
					mflag = 1;
				}
				n = 10 * n + c - '0';
			}
			mlwrite("Arg: %d",
				(mflag >= 0) ? n : (n ? -n : -1));
		}
		/*
		 * Make arguments preceded by a minus sign negative and change
		 * the special argument "^U -" to an effective "^U -1".
		 */
		if (mflag == -1) {
			if (n == 0)
				n++;
			n = -n;
		}
	}

	/* and execute the command */
	execute(c, f, n);
	goto loop;
}

/*
 * Initialize all of the buffers and windows. The buffer name is passed down
 * as an argument, because the main routine may have been told to read in a
 * file by default, and we want the buffer name to be right.
 */
void edinit(char *bname)
{
	struct buffer *bp;
	struct window *wp;

	bp = bfind(bname, TRUE, 0);	/* First buffer         */
	blistp = bfind("*List*", TRUE, BFINVS);	/* Buffer list buffer   */
	wp = (struct window *)malloc(sizeof(struct window));	/* First window         */
	if (bp == NULL || wp == NULL || blistp == NULL)
		exit(1);
	curbp = bp;		/* Make this current    */
	wheadp = wp;
	curwp = wp;
	wp->w_wndp = NULL;	/* Initialize window    */
	wp->w_bufp = bp;
	bp->b_nwnd = 1;		/* Displayed.           */
	wp->w_linep = bp->b_linep;
	wp->w_dotp = bp->b_linep;
	wp->w_doto = 0;
	wp->w_markp = NULL;
	wp->w_marko = 0;
	wp->w_toprow = 0;
#if	COLOR
	/* initalize colors to global defaults */
	wp->w_fcolor = gfcolor;
	wp->w_bcolor = gbcolor;
#endif
	wp->w_ntrows = term.t_nrow - 1;	/* "-1" for mode line.  */
	wp->w_force = 0;
	wp->w_flag = WFMODE | WFHARD;	/* Full.                */
}

/*
 * This is the general command execution routine. It handles the fake binding
 * of all the keys to "self-insert". It also clears out the "thisflag" word,
 * and arranges to move it to the "lastflag", so that the next command can
 * look at it. Return the status of command.
 */
int execute(int c, int f, int n)
{
	int status;
	fn_t execfunc;

	/* if the keystroke is a bound function...do it */
	execfunc = getbind(c);
	if (execfunc != NULL) {
		thisflag = 0;
		status = (*execfunc) (f, n);
		lastflag = thisflag;
		return status;
	}

	/*
	 * If a space was typed, fill column is defined, the argument is non-
	 * negative, wrap mode is enabled, and we are now past fill column,
	 * and we are not read-only, perform word wrap.
	 */
	if (c == ' ' && (curwp->w_bufp->b_mode & MDWRAP) && fillcol > 0 &&
	    n >= 0 && getccol(FALSE) > fillcol &&
	    (curwp->w_bufp->b_mode & MDVIEW) == FALSE)
		execute(META | SPEC | 'W', FALSE, 1);

#if	PKCODE
	if ((c >= 0x20 && c <= 0x7E)	/* Self inserting.      */
#if	IBMPC
	    || (c >= 0x80 && c <= 0xFE)) {
#else
#if	VMS || BSD || USG	/* 8BIT P.K. */
	    || (c >= 0xA0 && c <= 0x10FFFF)) {
#else
	    ) {
#endif
#endif
#else
	if ((c >= 0x20 && c <= 0xFF)) {	/* Self inserting.      */
#endif
		if (n <= 0) {	/* Fenceposts.          */
			lastflag = 0;
			return n < 0 ? FALSE : TRUE;
		}
		thisflag = 0;	/* For the future.      */

		/* if we are in overwrite mode, not at eol,
		   and next char is not a tab or we are at a tab stop,
		   delete a char forword                        */
		if (curwp->w_bufp->b_mode & MDOVER &&
		    curwp->w_doto < curwp->w_dotp->l_used &&
		    (lgetc(curwp->w_dotp, curwp->w_doto) != '\t' ||
		     (curwp->w_doto) % 8 == 7))
			ldelchar(1, FALSE);

		/* do the appropriate insertion */
		if (c == '}' && (curbp->b_mode & MDCMOD) != 0)
			status = insbrace(n, c);
		else if (c == '#' && (curbp->b_mode & MDCMOD) != 0)
			status = inspound();
		else
			status = linsert(n, c);

#if	CFENCE
		/* check for CMODE fence matching */
		if ((c == '}' || c == ')' || c == ']') &&
		    (curbp->b_mode & MDCMOD) != 0)
			fmatch(c);
#endif

		/* check auto-save mode */
		if (curbp->b_mode & MDASAVE)
			if (--gacount == 0) {
				/* and save the file if needed */
				upscreen(FALSE, 0);
				filesave(FALSE, 0);
				gacount = gasave;
			}

		lastflag = thisflag;
		return status;
	}
	TTbeep();
	mlwrite("(Key not bound)");	/* complain             */
	lastflag = 0;		/* Fake last flags.     */
	return FALSE;
}

/*
 * Fancy quit command, as implemented by Norm. If the any buffer has
 * changed do a write on that buffer and exit emacs, otherwise simply exit.
 */
int quickexit(int f, int n)
{
	struct buffer *bp;	/* scanning pointer to buffers */
	struct buffer *oldcb;	/* original current buffer */
	int status;

	oldcb = curbp;		/* save in case we fail */

	bp = bheadp;
	while (bp != NULL) {
		if ((bp->b_flag & BFCHG) != 0	/* Changed.             */
		    && (bp->b_flag & BFTRUNC) == 0	/* Not truncated P.K.   */
		    && (bp->b_flag & BFINVS) == 0) {	/* Real.                */
			curbp = bp;	/* make that buffer cur */
			mlwrite("(Saving %s)", bp->b_fname);
#if	PKCODE
#else
			mlwrite("\n");
#endif
			if ((status = filesave(f, n)) != TRUE) {
				curbp = oldcb;	/* restore curbp */
				return status;
			}
		}
		bp = bp->b_bufp;	/* on to the next buffer */
	}
	quit(f, n);		/* conditionally quit   */
	return TRUE;
}

static void emergencyexit(int signr)
{
	quickexit(FALSE, 0);
	quit(TRUE, 0);
}

/*
 * Quit command. If an argument, always quit. Otherwise confirm if a buffer
 * has been changed and not written out. Normally bound to "C-X C-C".
 */
int quit(int f, int n)
{
	int s;

	if (f != FALSE		/* Argument forces it.  */
	    || anycb() == FALSE	/* All buffers clean.   */
	    /* User says it's OK.   */
	    || (s =
		mlyesno("Modified buffers exist. Leave anyway")) == TRUE) {
#if	(FILOCK && BSD) || SVR4
		if (lockrel() != TRUE) {
			TTputc('\n');
			TTputc('\r');
			TTclose();
			TTkclose();
			exit(1);
		}
#endif
		vttidy();
		if (f)
			exit(n);
		else
			exit(GOOD);
	}
	mlwrite("");
	return s;
}

/*
 * Begin a keyboard macro.
 * Error if not at the top level in keyboard processing. Set up variables and
 * return.
 */
int ctlxlp(int f, int n)
{
	if (kbdmode != STOP) {
		mlwrite("%%Macro already active");
		return FALSE;
	}
	mlwrite("(Start macro)");
	kbdptr = &kbdm[0];
	kbdend = kbdptr;
	kbdmode = RECORD;
	return TRUE;
}

/*
 * End keyboard macro. Check for the same limit conditions as the above
 * routine. Set up the variables and return to the caller.
 */
int ctlxrp(int f, int n)
{
	if (kbdmode == STOP) {
		mlwrite("%%Macro not active");
		return FALSE;
	}
	if (kbdmode == RECORD) {
		mlwrite("(End macro)");
		kbdmode = STOP;
	}
	return TRUE;
}

/*
 * Execute a macro.
 * The command argument is the number of times to loop. Quit as soon as a
 * command gets an error. Return TRUE if all ok, else FALSE.
 */
int ctlxe(int f, int n)
{
	if (kbdmode != STOP) {
		mlwrite("%%Macro already active");
		return FALSE;
	}
	if (n <= 0)
		return TRUE;
	kbdrep = n;		/* remember how many times to execute */
	kbdmode = PLAY;		/* start us in play mode */
	kbdptr = &kbdm[0];	/*    at the beginning */
	return TRUE;
}

/*
 * Abort.
 * Beep the beeper. Kill off any keyboard macro, etc., that is in progress.
 * Sometimes called as a routine, to do general aborting of stuff.
 */
int ctrlg(int f, int n)
{
	TTbeep();
	kbdmode = STOP;
	mlwrite("(Aborted)");
	return ABORT;
}

/*
 * tell the user that this command is illegal while we are in
 * VIEW (read-only) mode
 */
int rdonly(void)
{
	TTbeep();
	mlwrite("(Key illegal in VIEW mode)");
	return FALSE;
}

int resterr(void)
{
	TTbeep();
	mlwrite("(That command is RESTRICTED)");
	return FALSE;
}

/* user function that does NOTHING */
int nullproc(int f, int n)
{
	return TRUE;
}

/* dummy function for binding to meta prefix */
int metafn(int f, int n)
{
	return TRUE;
}

/* dummy function for binding to control-x prefix */
int cex(int f, int n)
{
	return TRUE;
}

/* dummy function for binding to universal-argument */
int unarg(int f, int n)
{
	return TRUE;
}

/*****		Compiler specific Library functions	****/

#if	RAMSIZE
/*	These routines will allow me to track memory usage by placing
	a layer on top of the standard system malloc() and free() calls.
	with this code defined, the environment variable, $RAM, will
	report on the number of bytes allocated via malloc.

	with SHOWRAM defined, the number is also posted on the
	end of the bottom mode line and is updated whenever it is changed.
*/

#undef	malloc
#undef	free

char *allocate(nbytes)
			    /* allocate nbytes and track */
unsigned nbytes;		/* # of bytes to allocate */

{
	char *mp;		/* ptr returned from malloc */
	char *malloc();

	mp = malloc(nbytes);
	if (mp) {
		envram += nbytes;
#if	RAMSHOW
		dspram();
#endif
	}

	return mp;
}

release(mp)
    /* release malloced memory and track */
char *mp;			/* chunk of RAM to release */

{
	unsigned *lp;		/* ptr to the long containing the block size */

	if (mp) {
		/* update amount of ram currently malloced */
		lp = ((unsigned *) mp) - 1;
		envram -= (long) *lp - 2;
		free(mp);
#if	RAMSHOW
		dspram();
#endif
	}
}

#if	RAMSHOW
dspram()
{				/* display the amount of RAM currently malloced */
	char mbuf[20];
	char *sp;

	TTmove(term.t_nrow - 1, 70);
#if	COLOR
	TTforg(7);
	TTbacg(0);
#endif
	sprintf(mbuf, "[%lu]", envram);
	sp = &mbuf[0];
	while (*sp)
		TTputc(*sp++);
	TTmove(term.t_nrow, 0);
	movecursor(term.t_nrow, 0);
}
#endif
#endif

/*	On some primitave operation systems, and when emacs is used as
	a subprogram to a larger project, emacs needs to de-alloc its
	own used memory
*/

#if	CLEAN

/*
 * cexit()
 *
 * int status;		return status of emacs
 */
int cexit(int status)
{
	struct buffer *bp;	/* buffer list pointer */
	struct window *wp;	/* window list pointer */
	struct window *tp;	/* temporary window pointer */

	/* first clean up the windows */
	wp = wheadp;
	while (wp) {
		tp = wp->w_wndp;
		free(wp);
		wp = tp;
	}
	wheadp = NULL;

	/* then the buffers */
	bp = bheadp;
	while (bp) {
		bp->b_nwnd = 0;
		bp->b_flag = 0;	/* don't say anything about a changed buffer! */
		zotbuf(bp);
		bp = bheadp;
	}

	/* and the kill buffer */
	kdelete();

	/* and the video buffers */
	vtfree();

#undef	exit
	exit(status);
}
#endif


