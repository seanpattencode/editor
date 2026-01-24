/*
 * Name:	MicroEMACS
 *		Ultrix-32 system header file.
 * Version:	29
 * Last edit:	05-Feb-86
 * By:		rex::conroy
 *		decvax!decwrl!dec-rhea!dec-rex!conroy
 */
#define	PCC	1			/* "[]" gets an error.		*/
#define	KBLOCK	8192			/* Kill grow.			*/
#define	GOOD	0			/* Good exit status.		*/

/*
 * Macros used by the buffer name making code.
 * Start at the end of the file name, scan to the left
 * until BDC1 (or BDC2, if defined) is reached. The buffer
 * name starts just to the right of that location, and
 * stops at end of string (or at the next BDC3 character,
 * if defined). BDC2 and BDC3 are mainly for VMS.
 */
#define	BDC1	'/'			/* Buffer names.		*/
/*
 * Name:	MicroEMACS
 *		Digital ANSI terminal header file
 * Version:	29
 * Last edit:	05-Feb-86
 * By:		rex::conroy
 *		decvax!decwrl!dec-rhea!dec-rex!conroy
 */
#define	GOSLING	1			/* Compile in fancy display.	*/
#define	MEMMAP	0			/* Not memory mapped video.	*/

/*
 * Yes Bob, it's wrong for you.
 */
#define	NROW	66			/* Rows.			*/
#define	NCOL	132			/* Columns.			*/

/*
 * Special keys, as on the LK201, which is
 * a superset of the VT100. Originally I tried to keep the
 * numbers in LK201 escape sequence code, but it became too much
 * of a pain because of the keycodes greater than 31. 
 * The codes are all just redefinitions for the standard extra
 * key codes. Using the standard names ensures that the
 * LK201 codes land in the right place.
 */
#define	KUP	K01
#define	KDOWN	K02
#define	KLEFT	K03
#define	KRIGHT	K04
#define	KFIND	K05
#define	KINSERT	K06
#define	KREMOVE	K07
#define	KSELECT	K08
#define	KPREV	K09
#define	KNEXT	K0A
#define	KF4	K0B
#define	KF6	K0C
#define	KF7	K0D
#define	KF8	K0E
#define	KF9	K0F
#define	KF10	K10
#define	KF11	K11
#define	KF12	K12
#define	KF13	K13
#define	KF14	K14
#define	KHELP	K15
#define	KDO	K16
#define	KF17	K17
#define	KF18	K18
#define	KF19	K19
#define	KF20	K1A
#define	KPF1	K1B
#define	KPF2	K1C
#define	KPF3	K1D
#define	KPF4	K1E
/*
 * Name:	MicroEMACS
 *		Common header file.
 * Version:	29
 * Last edit:	14-Feb-86
 * By:		rex::conroy
 *		decvax!decwrl!dec-rhea!dec-rex!conroy
 * 
 * This file is the general header file for all parts
 * of the MicroEMACS display editor. It contains all of the
 * general definitions and macros. It also contains some
 * conditional compilation flags. All of the per-system and
 * per-terminal definitions are in special header files.
 * The most common reason to edit this file would be to zap
 * the definition of CVMVAS or BACKUP.
 */
#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>
#include	<dirent.h>
int dirmode;
int sb_top, sb_bot;  /* scrollbar thumb top/bottom rows */

#define	CVMVAS	1			/* C-V, M-V work in pages.	*/
#define	BACKUP	0			/* Make backup file.		*/

/*
 * Table sizes, etc.
 */
#define	NSHASH	31			/* Symbol table hash size.	*/
#define	NFILEN	80			/* Length, file name.		*/
#define	NBUFN	16			/* Length, buffer name.		*/
#define	NLINE	256			/* Length, line.		*/
#define	NKBDM	256			/* Length, keyboard macro.	*/
#define NMSG	512			/* Length, message buffer.	*/
#define	NPAT	80			/* Length, pattern.		*/
#define	HUGE	1000			/* A rather large number.	*/
#define NSRCH	128			/* Undoable search commands.	*/
#define	NXNAME	64			/* Length, extended command.	*/

/*
 * Universal.
 */
#define	FALSE	0			/* False, no, bad, etc.		*/
#define	TRUE	1			/* True, yes, good, etc.	*/
#define	ABORT	2			/* Death, ^G, abort, etc.	*/

/*
 * These flag bits keep track of
 * some aspects of the last command. The CFCPCN
 * flag controls goal column setting. The CFKILL
 * flag controls the clearing versus appending
 * of data in the kill buffer.
 */
#define	CFCPCN	0x0001			/* Last command was C-P, C-N	*/
#define	CFKILL	0x0002			/* Last command was a kill	*/

/*
 * File I/O.
 */
#define	FIOSUC	0			/* Success.			*/
#define	FIOFNF	1			/* File not found.		*/
#define	FIOEOF	2			/* End of file.			*/
#define	FIOERR	3			/* Error.			*/

/*
 * Directory I/O.
 */
#define	DIOSUC	0			/* Success.			*/
#define	DIOEOF	1			/* End of file.			*/
#define	DIOERR	2			/* Error.			*/

/*
 * Display colors.
 */
#define	CNONE	0			/* Unknown color.		*/
#define	CTEXT	1			/* Text color.			*/
#define	CMODE	2			/* Mode line color.		*/

/*
 * Flags for "eread".
 */
#define	EFNEW	0x0001			/* New prompt.			*/
#define	EFAUTO	0x0002			/* Autocompletion enabled.	*/
#define	EFCR	0x0004			/* Echo CR at end; last read.	*/

/*
 * Keys are represented inside using an 11 bit
 * keyboard code. The transformation between the keys on
 * the keyboard and 11 bit code is done by terminal specific
 * code in the "kbd.c" file. The actual character is stored
 * in 8 bits (DEC multinationals work); there is also a control
 * flag KCTRL, a meta flag KMETA, and a control-X flag KCTLX.
 * ASCII control characters are always represented using the
 * KCTRL form. Although the C0 control set is free, it is
 * reserved for C0 controls because it makes the communication
 * between "getkey" and "getkbd" easier. The funny keys get
 * mapped into the C1 control area.
 */
#define	NKEYS	2048			/* 11 bit code.			*/

#define	METACH	0x1B			/* M- prefix,   Control-[, ESC	*/
#define	CTMECH	0x1C			/* C-M- prefix, Control-\	*/
#define	EXITCH	0x1D			/* Exit level,  Control-]	*/
#define	CTRLCH	0x1E			/* C- prefix,	Control-^	*/
#define	HELPCH	0x1F			/* Help key,    Control-_	*/

#define	KCHAR	0x00FF			/* The basic character code.	*/
#define	KCTRL	0x0100			/* Control flag.		*/
#define	KMETA	0x0200			/* Meta flag.			*/
#define	KCTLX	0x0400			/* Control-X flag.		*/

#define	KFIRST	0x0080			/* First special.		*/
#define	KLAST	0x009F			/* Last special.		*/

#define	KRANDOM	0x0080			/* A "no key" code.		*/
#define	K01	0x0081			/* Use these names to define	*/
#define	K02	0x0082			/* the special keys on your	*/
#define	K03	0x0083			/* terminal.			*/
#define	K04	0x0084
#define	K05	0x0085
#define	K06	0x0086
#define	K07	0x0087
#define	K08	0x0088
#define	K09	0x0089
#define	K0A	0x008A
#define	K0B	0x008B
#define	K0C	0x008C
#define	K0D	0x008D
#define	K0E	0x008E
#define	K0F	0x008F
#define	K10	0x0090
#define	K11	0x0091
#define	K12	0x0092
#define	K13	0x0093
#define	K14	0x0094
#define	K15	0x0095
#define	K16	0x0096
#define	K17	0x0097
#define	K18	0x0098
#define	K19	0x0099
#define	K1A	0x009A
#define	K1B	0x009B
#define	K1C	0x009C
#define	K1D	0x009D
#define	K1E	0x009E
#define	K1F	0x009F

/*
 * These flags, and the macros below them,
 * make up a do-it-yourself set of "ctype" macros that
 * understand the DEC multinational set, and let me ask
 * a slightly different set of questions.
 */
#define	_W	0x01			/* Word.			*/
#define	_U	0x02			/* Upper case letter.		*/
#define	_L	0x04			/* Lower case letter.		*/
#define	_C	0x08			/* Control.			*/

#define	ISWORD(c)	((cinfo[(c)]&_W)!=0)
#define	ISCTRL(c)	((cinfo[(c)]&_C)!=0)
#define	ISUPPER(c)	((cinfo[(c)]&_U)!=0)
#define	ISLOWER(c)	((cinfo[(c)]&_L)!=0)
#define	TOUPPER(c)	((c)-0x20)
#define	TOLOWER(c)	((c)+0x20)

/*
 * The symbol table links editing functions
 * to names. Entries in the key map point at the symbol
 * table entry. A reference count is kept, but it is
 * probably next to useless right now. The old type code,
 * which was not being used and probably not right
 * anyway, is all gone.
 */
typedef	struct	SYMBOL {
	struct	SYMBOL *s_symp;		/* Hash chain.			*/
	short	s_nkey;			/* Count of keys bound here.	*/
	char	*s_name;		/* Name.			*/
	int	(*s_funcp)();		/* Function.			*/
}	SYMBOL;

/*
 * There is a window structure allocated for
 * every active display window. The windows are kept in a
 * big list, in top to bottom screen order, with the listhead at
 * "wheadp". Each window contains its own values of dot and mark.
 * The flag field contains some bits that are set by commands
 * to guide redisplay; although this is a bit of a compromise in
 * terms of decoupling, the full blown redisplay is just too
 * expensive to run for every input character. 
 */
typedef	struct	WINDOW {
	struct	WINDOW *w_wndp;		/* Next window			*/
	struct	BUFFER *w_bufp;		/* Buffer displayed in window	*/
	struct	LINE *w_linep;		/* Top line in the window	*/
	struct	LINE *w_dotp;		/* Line containing "."		*/
	short	w_doto;			/* Byte offset for "."		*/
	struct	LINE *w_markp;		/* Line containing "mark"	*/
	short	w_marko;		/* Byte offset for "mark"	*/
	char	w_toprow;		/* Origin 0 top row of window	*/
	char	w_ntrows;		/* # of rows of text in window	*/
	char	w_force;		/* If NZ, forcing row.		*/
	char	w_flag;			/* Flags.			*/
}	WINDOW;

/*
 * Window flags are set by command processors to
 * tell the display system what has happened to the buffer
 * mapped by the window. Setting "WFHARD" is always a safe thing
 * to do, but it may do more work than is necessary. Always try
 * to set the simplest action that achieves the required update.
 * Because commands set bits in the "w_flag", update will see
 * all change flags, and do the most general one.
 */
#define	WFFORCE	0x01			/* Force reframe.		*/
#define	WFMOVE	0x02			/* Movement from line to line.	*/
#define	WFEDIT	0x04			/* Editing within a line.	*/
#define	WFHARD	0x08			/* Better to a full display.	*/
#define	WFMODE	0x10			/* Update mode line.		*/

/*
 * Text is kept in buffers. A buffer header, described
 * below, exists for every buffer in the system. The buffers are
 * kept in a big list, so that commands that search for a buffer by
 * name can find the buffer header. There is a safe store for the
 * dot and mark in the header, but this is only valid if the buffer
 * is not being displayed (that is, if "b_nwnd" is 0). The text for
 * the buffer is kept in a circularly linked list of lines, with
 * a pointer to the header line in "b_linep".
 */
typedef	struct	BUFFER {
	struct	BUFFER *b_bufp;		/* Link to next BUFFER		*/
	struct	LINE *b_dotp;		/* Link to "." LINE structure	*/
	short	b_doto;			/* Offset of "." in above LINE	*/
	struct	LINE *b_markp;		/* The same as the above two,	*/
	short	b_marko;		/* but for the "mark"		*/
	struct	LINE *b_linep;		/* Link to the header LINE	*/
	char	b_nwnd;			/* Count of windows on buffer	*/
	char	b_flag;			/* Flags			*/
	char	b_fname[NFILEN];	/* File name			*/
	char	b_bname[NBUFN];		/* Buffer name			*/
}	BUFFER;

#define	BFCHG	0x01			/* Changed.			*/
#define	BFBAK	0x02			/* Need to make a backup.	*/

/*
 * This structure holds the starting position
 * (as a line/offset pair) and the number of characters in a
 * region of a buffer. This makes passing the specification
 * of a region around a little bit easier.
 * There have been some complaints that the short in this
 * structure is wrong; that a long would be more appropriate.
 * I'll awat more comments from the folks with the little
 * machines; I have a VAX, and everything fits.
 */
typedef	struct	{
	struct	LINE *r_linep;		/* Origin LINE address.		*/
	short	r_offset;		/* Origin LINE offset.		*/
	short	r_size;			/* Length in characters.	*/
}	REGION;

/*
 * All text is kept in circularly linked
 * lists of "LINE" structures. These begin at the
 * header line (which is the blank line beyond the
 * end of the buffer). This line is pointed to by
 * the "BUFFER". Each line contains a the number of
 * bytes in the line (the "used" size), the size
 * of the text array, and the text. The end of line
 * is not stored as a byte; it's implied. Future
 * additions will include update hints, and a
 * list of marks into the line.
 */
typedef	struct	LINE {
	struct	LINE *l_fp;		/* Link to the next line	*/
	struct	LINE *l_bp;		/* Link to the previous line	*/
	short	l_size;			/* Allocated size		*/
	short	l_used;			/* Used size			*/
#if	PCC
	char	l_text[1];		/* A bunch of characters.	*/
#else
	char	l_text[];		/* A bunch of characters.	*/
#endif
}	LINE;

/*
 * The rationale behind these macros is that you
 * could (with some editing, like changing the type of a line
 * link from a "LINE *" to a "REFLINE", and fixing the commands
 * like file reading that break the rules) change the actual
 * storage representation of lines to use something fancy on
 * machines with small address spaces.
 */
#define	lforw(lp)	((lp)->l_fp)
#define	lback(lp)	((lp)->l_bp)
#define	lgetc(lp, n)	((lp)->l_text[(n)]&0xFF)
#define	lputc(lp, n, c)	((lp)->l_text[(n)]=(c))
#define	llength(lp)	((lp)->l_used)

/*
 * Externals.
 */
extern	int	thisflag;
extern	int	lastflag;
extern	int	curgoal;
extern	int	epresf;
extern	int	sgarbf;
extern	WINDOW	*curwp;
extern	BUFFER	*curbp;
extern	WINDOW	*wheadp;
extern	BUFFER	*bheadp;
extern	BUFFER	*blistp;
extern	short	kbdm[];
extern	short	*kbdmip;
extern	short	*kbdmop;
extern	char	pat[];
extern	SYMBOL	*symbol[];
extern	SYMBOL	*binding[];
/* Forward declarations */
BUFFER	*bfind();
BUFFER	*bcreate();
WINDOW	*wpopup();
LINE	*lalloc();
SYMBOL	*symlookup();
extern  int	nrow;
extern  int	ncol;
extern	char	*version[];
extern	int	ttrow;
extern	int	ttcol;
extern	int	tceeol;
extern	int	tcinsl;
extern	int	tcdell;
extern	char	cinfo[];
extern	char	*keystrings[];
extern	int	nmsg;
extern	int	curmsgf;
extern	int	newmsgf;
extern	char	msg[];
/*
 * Name:	MicroEMACS
 *		Character class tables.
 * Version:	29
 * Last edit:	05-Feb-86
 * By:		rex::conroy
 *		decvax!decwrl!dec-rhea!dec-rex!conroy
 *
 * Do it yourself character classification
 * macros, that understand the multinational character set,
 * and let me ask some questions the standard macros (in
 * ctype.h) don't let you ask.
 */

/*
 * This table, indexed by a character drawn
 * from the 256 member character set, is used by my
 * own character type macros to answer questions about the
 * type of a character. It handles the full multinational
 * character set, and lets me ask some questions that the
 * standard "ctype" macros cannot ask.
 */
char	cinfo[256] = {
	_C,		_C,		_C,		_C,	/* 0x0X	*/
	_C,		_C,		_C,		_C,
	_C,		_C,		_C,		_C,
	_C,		_C,		_C,		_C,
	_C,		_C,		_C,		_C,	/* 0x1X	*/
	_C,		_C,		_C,		_C,
	_C,		_C,		_C,		_C,
	_C,		_C,		_C,		_C,
	0,		0,		0,		0,	/* 0x2X	*/
	_W,		0,		0,		_W,
	0,		0,		0,		0,
	0,		0,		0,		0,
	_W,		_W,		_W,		_W,	/* 0x3X	*/
	_W,		_W,		_W,		_W,
	_W,		_W,		0,		0,
	0,		0,		0,		0,
	0,		_U|_W,		_U|_W,		_U|_W,	/* 0x4X	*/
	_U|_W,		_U|_W,		_U|_W,		_U|_W,
	_U|_W,		_U|_W,		_U|_W,		_U|_W,
	_U|_W,		_U|_W,		_U|_W,		_U|_W,
	_U|_W,		_U|_W,		_U|_W,		_U|_W,	/* 0x5X	*/
	_U|_W,		_U|_W,		_U|_W,		_U|_W,
	_U|_W,		_U|_W,		_U|_W,		0,
	0,		0,		0,		_W,
	0,		_L|_W,		_L|_W,		_L|_W,	/* 0x6X	*/
	_L|_W,		_L|_W,		_L|_W,		_L|_W,
	_L|_W,		_L|_W,		_L|_W,		_L|_W,
	_L|_W,		_L|_W,		_L|_W,		_L|_W,
	_L|_W,		_L|_W,		_L|_W,		_L|_W,	/* 0x7X	*/
	_L|_W,		_L|_W,		_L|_W,		_L|_W,
	_L|_W,		_L|_W,		_L|_W,		0,
	0,		0,		0,		_C,
	0,		0,		0,		0,	/* 0x8X	*/
	0,		0,		0,		0,
	0,		0,		0,		0,
	0,		0,		0,		0,
	0,		0,		0,		0,	/* 0x9X	*/
	0,		0,		0,		0,
	0,		0,		0,		0,
	0,		0,		0,		0,
	0,		0,		0,		0,	/* 0xAX	*/
	0,		0,		0,		0,
	0,		0,		0,		0,
	0,		0,		0,		0,
	0,		0,		0,		0,	/* 0xBX	*/
	0,		0,		0,		0,
	0,		0,		0,		0,
	0,		0,		0,		0,
	_U|_W,		_U|_W,		_U|_W,		_U|_W,	/* 0xCX	*/
	_U|_W,		_U|_W,		_U|_W,		_U|_W,
	_U|_W,		_U|_W,		_U|_W,		_U|_W,
	_U|_W,		_U|_W,		_U|_W,		_U|_W,
	0,		_U|_W,		_U|_W,		_U|_W,	/* 0xDX	*/
	_U|_W,		_U|_W,		_U|_W,		_U|_W,
	_U|_W,		_U|_W,		_U|_W,		_U|_W,
	_U|_W,		_U|_W,		0,		_W,
	_L|_W,		_L|_W,		_L|_W,		_L|_W,	/* 0xEX	*/
	_L|_W,		_L|_W,		_L|_W,		_L|_W,
	_L|_W,		_L|_W,		_L|_W,		_L|_W,
	_L|_W,		_L|_W,		_L|_W,		_L|_W,
	0,		_L|_W,		_L|_W,		_L|_W,	/* 0xFX	*/
	_L|_W,		_L|_W,		_L|_W,		_L|_W,
	_L|_W,		_L|_W,		_L|_W,		_L|_W,
	_L|_W,		_L|_W,		0,		0
};
/*
 * Name:	MicroEMACS
 *		Ultrix-32 terminal I/O.
 * Version:	29
 * Last edit:	05-Feb-86
 * By:		rex::conroy
 *		decvax!decwrl!dec-rhea!dec-rex!conroy
 *
 * The functions in this file
 * negotiate with the operating system for
 * keyboard characters, and write characters to
 * the display in a barely buffered fashion.
 */

#include	<termios.h>
#include	<poll.h>

#define	NOBUF	512			/* Output buffer size.		*/

char	obuf[NOBUF];			/* Output buffer.		*/
int	nobuf;
struct	termios	oldtty;			/* POSIX tty settings. */
struct	termios	newtty;
int	nrow;				/* Terminal size, rows.		*/
int	ncol;				/* Terminal size, columns.	*/

/*
 * This function gets called once, to set up
 * the terminal channel. On Ultrix is's tricky, since
 * we want flow control, but we don't want any characters
 * stolen to send signals. Use CBREAK mode, and set all
 * characters but start and stop to 0xFF.
 */
ttopen()
{
	/* Save pos+attr, disable margins, set cursor far away, query pos */
	const char query[] = "\e7\e[r\e[999;999H\e[6n\e[?1006h\e[?1002h";
	struct pollfd fd = { 1, POLLIN, 0 };
	int row, col;

	/* Adjust output channel */
	tcgetattr(1, &oldtty);			/* save old state */
	newtty = oldtty;			/* get base of new state */

#ifdef __sun
	newtty.c_iflag &= ~(IMAXBEL|IGNBRK|BRKINT|PARMRK|ISTRIP|INLCR|IGNCR|ICRNL|IXON);
	newtty.c_oflag &= ~OPOST;
	newtty.c_lflag &= ~(ECHO|ECHONL|ICANON|ISIG|IEXTEN);
	newtty.c_cflag &= ~(CSIZE|PARENB);
	newtty.c_cflag |= CS8;
#else
        cfmakeraw(&newtty);
#endif

	tcsetattr(1, TCSADRAIN, &newtty); tcflush(0, TCIFLUSH);

	/* Query size of terminal by first trying to position cursor */
	if (write(1, query, sizeof(query)) != -1 && poll(&fd, 1, 300) > 0) {
		/* Terminal responds with \e[row;posR */
		if (scanf("\e[%d;%dR", &nrow, &ncol) != 2) {
			nrow = 80;
			ncol = 24;
		}
	}

	if (nrow > NROW)
		nrow = NROW;
	if (ncol > NCOL)
		ncol = NCOL;
}

/*
 * This function gets called just
 * before we go back home to the shell. Put all of
 * the terminal parameters back.
 */
ttclose()
{
	write(1,"\e[?1002l\e[?1006l\e[2J\e[H",23); ttflush();
	tcsetattr(1, TCSADRAIN, &oldtty);
}

/*
 * Write character to the display.
 * Characters are buffered up, to make things
 * a little bit more efficient.
 */
ttputc(c)
{
	if (nobuf >= NOBUF)
		ttflush();
	obuf[nobuf++] = c;
}

/*
 * Flush output.
 */
ttflush()
{
	if (nobuf != 0) {
		write(1, obuf, nobuf);
		nobuf = 0;
	}
}

/*
 * Read character from terminal.
 * All 8 bits are returned, so that you can use
 * a multi-national terminal.
 */
ttgetc()
{
	char	buf[1];

	while (read(0, &buf[0], 1) != 1)
		;
	return (buf[0] & 0xFF);
}
/*
 * Name:	MicroEMACS
 *		Digital ANSI terminal display
 * Version:	29
 * Last edit:	10-Feb-86
 * By:		rex::conroy
 *		decvax!decwrl!dec-rhea!dec-rex!conroy
 *
 * The SCALD display is just an ANSI display, with
 * some special hacks to kludge around the bugs, and
 * to make it a bit more friendly. The support is
 * unquestionably non-optimal. The costs are wrong; in
 * fact, display should be fixed up to understand non
 * linear cost devices like the SCALD. The BackIndex
 * sequence used in the insert line is defective in
 * the display firmware, so we set the cost high to
 * discourage its use. Perhaps the cost should be
 * set to infinity!
 */

#define	SCALD	0			/* Buggy display.		*/

#define	BEL	0x07			/* BEL character.		*/
#define	ESC	0x1B			/* ESC character.		*/
#define	LF	0x0A			/* Line feed.			*/

extern	int	ttrow;
extern	int	ttcol;
extern	int	tttop;
extern	int	ttbot;
extern	int	tthue;

#if	SCALD

int	tceeol	=	3;		/* Costs, SCALDstation.		*/
int	tcinsl	= 	100;
int	tcdell	=	100;

#else

int	tceeol	=	3;		/* Costs, ANSI display.		*/
int	tcinsl	= 	17;
int	tcdell	=	16;

#endif

/*
 * Initialize the terminal when the editor
 * gets started up. This is a no-op on the ANSI
 * display. On the SCALD display, it turns off the
 * half-screen scroll, because this appears to really
 * confuse the scrolling region firmware in the
 * display.
 */
ttinit()
{
#if	SCALD
	ttputc(ESC);			/* Cancel jump interval.	*/
	ttputc('[');
	asciiparm(1);
	ttputc('j');
#endif
}

/*
 * Clean up the terminal, in anticipation of
 * a return to the command interpreter. This is a no-op
 * on the ANSI display. On the SCALD display, it sets the
 * window back to half screen scrolling. Perhaps it should
 * query the display for the increment, and put it
 * back to what it was.
 */
tttidy()
{
#if	SCALD
	ttputc(ESC);			/* Half screen.			*/
	ttputc('[');
	asciiparm(nrow/2);
	ttputc('j');
#endif
}

/*
 * Move the cursor to the specified
 * origin 0 row and column position. Try to
 * optimize out extra moves; redisplay may
 * have left the cursor in the right
 * location last time!
 */
ttmove(row, col)
{
	if (ttrow!=row || ttcol!=col) {
		ttputc(ESC);
		ttputc('[');
		asciiparm(row+1);
		ttputc(';');
		asciiparm(col+1);
		ttputc('H');
		ttrow = row;
		ttcol = col;
	}
}

/*
 * Erase to end of line.
 */
tteeol()
{
	ttputc(ESC);
	ttputc('[');
	ttputc('K');
}

/*
 * Erase to end of page.
 */
tteeop()
{
	ttputc(ESC);
	ttputc('[');
	ttputc('J');
}

/*
 * Make a noise.
 */
ttbeep()
{
	ttputc(BEL);
	ttflush();
}

/*
 * Convert a number to decimal
 * ascii, and write it out. Used to
 * deal with numeric arguments.
 */
asciiparm(n)
register int	n;
{
	register int	q;

	q = n/10;
	if (q != 0)
		asciiparm(q);
	ttputc((n%10) + '0');
}

/*
 * Insert a block of blank lines onto the
 * screen, using a scrolling region that starts at row
 * "row" and extends down to row "bot". Deal with the one
 * line case, which is a little bit special, with special
 * case code. Put all of the back index commands out
 * in a block. The SCALDstation loses the position
 * of the cursor.
 */
ttinsl(row, bot, nchunk)
{
	if (row == bot) {			/* Funny case.		*/
		if (nchunk != 1)
			abort();
		ttmove(row, 0);
		tteeol();
	} else {				/* General case.	*/
		ttwindow(row, bot);
		ttmove(row, 0);
		while (nchunk--) {
			ttputc(ESC);		/* Back index.		*/
			ttputc('M');
		}
#if	SCALD
		ttrow = HUGE;
		ttcol = HUGE;
#endif
	}
}

/*
 * Delete a block of lines, with the uppermost
 * line at row "row", in a screen slice that extends to
 * row "bot". The "nchunk" is the number of lines that have
 * to be deleted. Watch for the pathalogical 1 line case,
 * where the scroll region is *not* the way to do it.
 * The block delete is used by the slightly more
 * optimal display code.
 */
ttdell(row, bot, nchunk)
{
	if (row == bot) {			/* Funny case.		*/
		if (nchunk != 1)
			abort();
		ttmove(row, 0);
		tteeol();
	} else {				/* General case.	*/
		ttwindow(row, bot);
		ttmove(bot, 0);
		while (nchunk--)
			ttputc(LF);
#if	SCALD
		ttrow = HUGE;
		ttcol = HUGE;
#endif
	}
}

/*
 * This routine sets the scrolling window
 * on the display to go from line "top" to line
 * "bot" (origin 0, inclusive). The caller checks
 * for the pathalogical 1 line scroll window that
 * doesn't work right, and avoids it. The "ttrow"
 * and "ttcol" variables are set to a crazy value
 * to ensure that the next call to "ttmove" does
 * not turn into a no-op (the window adjustment
 * moves the cursor).
 */
ttwindow(top, bot)
{
	if (tttop!=top || ttbot!=bot) {
		ttputc(ESC);
		ttputc('[');
		asciiparm(top+1);
		ttputc(';');
		asciiparm(bot+1);
		ttputc('r');
		ttrow = HUGE;			/* Unknown.		*/
		ttcol = HUGE;
		tttop = top;			/* Remember region.	*/
		ttbot = bot;
	}
}

/*
 * Switch to full screen scroll. This is
 * used by "spawn.c" just before is suspends the
 * editor, and by "display.c" when it is getting ready
 * to exit. This function gets to full screen scroll
 * by sending a DECSTBM with default parameters, but
 * I think that this is wrong. The SRM seems to say
 * that the default for Pb is 24, not the size of the
 * screen, which seems really dumb. Do I really have
 * to read the size of the screen as in "ttresize"
 * to do this right?
 */
ttnowindow()
{
	ttputc(ESC);
	ttputc('[');
	ttputc(';');
	ttputc('r');
	ttrow = HUGE;				/* Unknown.		*/
	ttcol = HUGE;
	tttop = HUGE;				/* No scroll region.	*/
	ttbot = HUGE;
}

/*
 * Set the current writing color to the
 * specified color. Watch for color changes that are
 * not going to do anything (the color is already right)
 * and don't send anything to the display.
 * The rainbow version does this in putline.s on a
 * line by line basis, so don't bother sending
 * out the color shift.
 */
ttcolor(color)
register int	color;
{
	if (color != tthue) {
/*
if	!RAINBOW
*/
		if (color == CTEXT) {		/* Normal video.	*/
			ttputc(ESC);
			ttputc('[');
			ttputc('m');
		} else if (color == CMODE) {	/* Reverse video.	*/
			ttputc(ESC);
			ttputc('[');
			ttputc('7');
			ttputc('m');
		}
/*
endif
*/
		tthue = color;			/* Save the color.	*/
	}
}

/*
 * This routine is called by the
 * "refresh the screen" command to try and resize
 * the display. The new size, which must be deadstopped
 * to not exceed the NROW and NCOL limits, it stored
 * back into "nrow" and "ncol". Display can always deal
 * with a screen NROW by NCOL. Look in "window.c" to
 * see how the caller deals with a change.
 */
ttresize()
{
	register int	c;
	register int	newnrow;
	register int	newncol;

	ttputc(ESC);				/* Off the end of the	*/
	ttputc('[');				/* world. The terminal	*/
	asciiparm(HUGE);			/* will chop it.	*/
	ttputc(';');
	asciiparm(HUGE);
	ttputc('H');
	ttrow = HUGE;				/* Unknown.		*/
	ttcol = HUGE;
	ttputc(ESC);				/* Report position.	*/
	ttputc('[');
	ttputc('6');
	ttputc('n');
	ttflush();
	if (ttgetc()!=ESC || ttgetc()!='[')
		return;
	newnrow = 0;
	while ((c=ttgetc())>='0' && c<='9')
		newnrow = 10*newnrow + c - '0';
	if (c != ';')
		return;
	newncol = 0;
	while ((c=ttgetc())>='0' && c<='9')
		newncol = 10*newncol + c - '0';
	if (c != 'R')
		return;
	if (newnrow < 1)			/* Check limits.	*/
		newnrow = 1;
	else if (newnrow > NROW)
		newnrow = NROW;
	if (newncol < 1)
		newncol = 1;
	else if (newncol > NCOL)
		newncol = NCOL;
	nrow = newnrow;
	ncol = newncol;
}
/*
 * Name:	MicroEMACS
 * 		Digital ANSI terminal keyboard.
 *		Assumes LK201, which is OK on the VT100.
 * Version:	29
 * Last edit:	05-Feb-86
 * By:		rex::conroy
 *		decvax!decwrl!dec-rhea!dec-rex!conroy
 */

#define	ESC	0x1B			/* Escape, arrows et al.	*/
#define	AGRAVE	0x60			/* LK201 kludge.		*/

/*
 * The special keys on an LK201 send back
 * escape sequences of the general form <ESC>[nnn~, where
 * nnn is a key code number. This table is indexed by the
 * nnn code to get the key code, which is used in the
 * binding table. The F4 key, and the F6 through F14 keys
 * have key codes. Also F17 through F20. Think of
 * help and do as special.
 */
short	lk201map[] = {
	KRANDOM,	KFIND,		KINSERT,	KREMOVE,
	KSELECT,	KPREV,		KNEXT,		KRANDOM,
	KRANDOM,	KRANDOM,	KRANDOM,	KRANDOM,
	KRANDOM,	KRANDOM,	KF4,		KRANDOM,
	KRANDOM,	KF6,		KF7,		KF8,
	KF9,		KF10,		KRANDOM,	KF11,
	KF12,		KF13,		KF14,		KRANDOM,
	KHELP,		KDO,		KRANDOM,	KF17,
	KF18,		KF19,		KF20
};

/*
 * Names for the keys with basic keycode
 * between KFIRST and KLAST (inclusive). This is used by
 * the key name routine in "kbd.c".
 */
char	*keystrings[] = {
	NULL,		"Up",		"Down",		"Left",
	"Right",	"Find",		"Insert",	"Remove",
	"Select",	"Previous",	"Next",		"F4",
	"F6",		"F7",		"F8",		"F9",
	"F10",		"F11",		"F12",		"F13",
	"F14",		"Help",		"Do",		"F17",
	"F18",		"F19",		"F20",		"PF1",
	"PF2",		"PF3",		"PF4",		NULL
};

/*
 * Read in a key, doing the low level mapping
 * of ASCII code to 11 bit code. This level deals with
 * mapping the special keys into their spots in the C1
 * control area. The C0 controls go right through, and
 * get remapped by "getkey".
 */
getkbd()
{
	register int	c;
	register int	n;
loop:
	c = ttgetc();
	if (c == AGRAVE)			/* On LK201, grave is	*/
		c = METACH;			/* also META.		*/
	if (c == ESC) {
		c = ttgetc();
		if (c == '[') {
			c = ttgetc();
			if (c == '<') { /* SGR mouse: \e[<btn;x;yM or m */
				int b=0,x=0,y=0,ch,row; LINE *lp;
				while((ch=ttgetc())!=';') b=b*10+ch-'0';
				while((ch=ttgetc())!=';') x=x*10+ch-'0';
				while((ch=ttgetc())!='M'&&ch!='m') y=y*10+ch-'0';
				if(b>=64&&b<128){b&1?forwline(0,4,0):backline(0,4,0);update();goto loop;}
				x--; y--; row=y-curwp->w_toprow;
				if(x>=(b&32?ncol/2:ncol-2)&&y>0&&row>=0&&row<curwp->w_ntrows){int t=0,g;LINE*p;
					for(p=lforw(curbp->b_linep);p!=curbp->b_linep;p=lforw(p))t++;
					g=row*t/curwp->w_ntrows;for(p=lforw(curbp->b_linep);g>0&&p!=curbp->b_linep;g--)p=lforw(p);
					curwp->w_linep=curwp->w_dotp=p;curwp->w_doto=0;curwp->w_flag|=WFHARD;update();goto loop;}
				if(b&32)goto loop;
				if(y==0&&x>=ncol-3&&ch=='M'){quit(0,0,0);goto loop;}
				if(row>=0 && row<curwp->w_ntrows) {
					for(lp=curwp->w_linep;row>0&&lp!=curbp->b_linep;row--)lp=lforw(lp);
					curwp->w_dotp=lp;{int i,c;for(i=c=0;i<llength(lp)&&c<x;c=lgetc(lp,i++)==9?(c|7)+1:c+1);curwp->w_doto=i;}
					if(ch=='M'){if(b>=128&&!(b&32)){backdir();}else if(!(b&3)&&!(b&32)){if(dirmode){char f[256];int i,n=llength(lp);
						for(i=0;i<n;i++)f[i]=lgetc(lp,i);f[n]=0;
						if(n&&f[n-1]=='/')filldir(f);else{dirmode=0;readin(f);}}
					else{curwp->w_markp=lp;curwp->w_marko=curwp->w_doto;}}}
					curwp->w_flag|=WFMOVE; update();
				}
				goto loop;
			}
			if (c == 'A')
				return (KUP);
			if (c == 'B')
				return (KDOWN);
			if (c == 'C')
				return (KRIGHT);
			if (c == 'D')
				return (KLEFT);
			if (c>='0' && c<='9') {	/* LK201 functions.	*/
				n = 0;
				do {
					n = 10*n + c - '0';
					c = ttgetc();
				} while (c>='0' && c<='9');
				if (c=='~' && n<=34) {
					c = lk201map[n];
					if (c != KRANDOM)
						return (c);
					goto loop;
				}
			}
			goto loop;
		}
		if (c == 'O') {	
			c = ttgetc();
			if (c == 'A')
				return (KUP);
			if (c == 'B')
				return (KDOWN);
			if (c == 'C')
				return (KRIGHT);
			if (c == 'D')
				return (KLEFT);
			if (c == 'P')
				return (KPF1);
			if (c == 'Q')
				return (KPF2);
			if (c == 'R')
				return (KPF3);
			if (c == 'S')
				return (KPF4);
			goto loop;
		}
		if (ISLOWER(c) != FALSE)	/* Copy the standard	*/
			c = TOUPPER(c);		/* META code.		*/
		if (c>=0x00 && c<=0x1F)
			c = KCTRL | (c+'@');
		return (KMETA | c);
	}
	return (c);
}

/*
 * Terminal specific keymap initialization.
 * Attach the special keys to the appropriate built
 * in functions. Bind all of the assigned graphics in the
 * DEC supplimental character set to "ins-self".
 * As is the case of all the keymap routines, errors
 * are very fatal.
 */
ttykeymapinit()
{
	register SYMBOL	*sp;
	register int	i;

	keydup(KFIND,	"search-again");
	keydup(KHELP,	"help");
	keydup(KINSERT, "yank");
	keydup(KREMOVE, "kill-region");
	keydup(KSELECT, "set-mark");
	keydup(KPREV,	"back-page");
	keydup(KNEXT,	"forw-page");
	keydup(KDO,	"execute-macro");
	keydup(KF17,	"back-window");
	keydup(KF18,	"forw-window");
	keydup(KF19,	"enlarge-window");
	keydup(KF20,	"shrink-window");
	keydup(KUP,	"back-line");
	keydup(KDOWN,	"forw-line");
	keydup(KRIGHT,	"forw-char");
	keydup(KLEFT,	"back-char");

	/*
	 * Bind all GR positions that correspond
	 * to assigned characters in the Digital multinational
	 * character set to "ins-self". These characters may
	 * be used just like any other character.
	 */

	if ((sp=symlookup("ins-self")) == NULL)
		abort();
	for (i=0xA0; i<0xFF; ++i) {
		if (i!=0xA4 && i!=0xA6 && i!=0xAC && i!=0xAD && i!=0xAE
		&&  i!=0xAF && i!=0xB4 && i!=0xB8 && i!=0xBE && i!=0xF0
		&&  i!=0xFE && i!=0xA0) {
			if (binding[i] != NULL)
				abort();
			binding[i] = sp;
			++sp->s_nkey;
		}
	}
}
/*
 * Name:	MicroEMACS
 *		Echo line reading and writing.
 * Version:	29
 * Last edit:	14-Feb-86
 * By:		rex::conroy
 *		decvax!decwrl!dec-rhea!dec-rex!conroy
 *
 * Common routines for reading
 * and writing characters in the echo line area
 * of the display screen. Used by the entire
 * known universe.
 */
#include    <stdarg.h>      /* Diviation from original sources - va_* macros */
int	epresf	= FALSE;		/* Stuff in echo line flag.	*/
int	nmsg	= 0;			/* Size of occupied msg. area.	*/
int	curmsgf	= FALSE;		/* Current alert state.		*/
int	newmsgf	= FALSE;		/* New alert state.		*/

char	msg[NMSG];			/* Random message storage.	*/

/*
 * Send a string to the message system.
 * Add a free newline to the end of the message string.
 * Return TRUE if it fits, and FALSE if it does not.
 * Perhaps the message buffer should know how to get
 * larger, just like the kill buffer?
 */
writemsg(sp)
register char	*sp;
{
	register int	c;

	if (nmsg+strlen(sp)+1 > NMSG)		/* "+1" for the "\n".	*/
		return (FALSE);
	while ((c = *sp++) != '\0')
		msg[nmsg++] = c;
	msg[nmsg++] = '\n';
	newmsgf = TRUE;				/* Update mode line.	*/
	return (TRUE);
}

/*
 * Read messages. The message lines are
 * displayed, one line at a time, in the message line.
 * A special sub-mode is entered, in which the keys have
 * the following meanings:
 *	^P	Go backward 1 line.
 *	BS	Go backward 1 line.
 *	^N	Go forward 1 line. Quit if at the end.
 *	SP	Go forward 1 line. Quit if at the end.
 *	CR	Go forward 1 line. Quit if at the end.
 *	^G	Abort, leave old text.
 *	^C	Quit, delete anything already read.
 * Return TRUE if you left this mode in a reasonable
 * way (not ^G), and ABORT if you quit the mode with a
 * ^G.
 */
readmsg()
{
	register int	c;
	register int	i;
	register int	j;

	if (nmsg == 0)				/* Duck out if none.	*/
		return (TRUE);
	newmsgf = FALSE;			/* Kill alert, and do	*/
	update();				/* a redisplay.		*/
	ttcolor(CTEXT);
	i = 0;
	while (i < nmsg) {
		ttmove(nrow-1, 0);		/* Display 1 line.	*/
		while (i<nmsg && (c=msg[i++])!='\n')
			eputc(c);
		tteeol();
		ttmove(nrow-1, 0);		/* Looks nice.		*/
		ttflush();
		for (;;) {			/* Editing loop.	*/
			c = ttgetc();
			switch (c) {
			case 0x0E:		/* ^N			*/
			case 0x20:		/* SP			*/
			case 0x0D:		/* CR			*/
				break;

			case 0x10:		/* ^P			*/
			case 0x08:		/* BS			*/
				do {
					--i;
				} while (i!=0 && msg[i-1]!='\n');
				if (i != 0) {
					do {	/* Back up 1 line.	*/
						--i;
					} while (i!=0 && msg[i-1]!='\n');
				}
				break;

			case 0x03:		/* ^C			*/
				j = 0;		/* Eat what we read.	*/
				while (i < nmsg)
					msg[j++] = msg[i++];
				nmsg = j;
				eerase();
				return (TRUE);

			case 0x07:		/* ^G			*/
				ttbeep();
				eerase();
				return (ABORT);

			default:		/* Loop on the rest.	*/
				continue;
			}
			break;
		}
	}
	nmsg = 0;				/* Flow off the end.	*/
	eerase();
	return (TRUE);
}

/*
 * Erase the echo line.
 */
eerase()
{
	ttcolor(CTEXT);
	ttmove(nrow-1, 0);
	tteeol();
	ttflush();
	epresf = FALSE;
}

/* Deviation from original sources: Prototype needed for eread OR 
 * eread can be moved before ereply - this intrudes less on the original 
 * sources
 */
int ereply(char* fp, char* buf, int nbuf, ...);

/*
 * Ask "yes" or "no" question.
 * Return ABORT if the user answers the question
 * with the abort ("^G") character. Return FALSE
 * for "no" and TRUE for "yes". No formatting
 * services are available.
 */
eyesno(sp)
char	*sp;
{
	register int	s;
	char		buf[64];

	for (;;) {
		s = ereply("%s [y/n]? ", buf, sizeof(buf), sp);
		if (s == ABORT)
			return (ABORT);
		if (s != FALSE) {
			if (buf[0]=='y' || buf[0]=='Y')
				return (TRUE);
			if (buf[0]=='n' || buf[0]=='N')
				return (FALSE);
		}
	}
}

/*
 * Write out a prompt, and read back a
 * reply. The prompt is now written out with full "eprintf"
 * formatting, although the arguments are in a rather strange
 * place. This is always a new message, there is no auto
 * completion, and the return is echoed as such.
 * 
 * Deviation from original source: K&R function declaration 
 * not allowed when using variadic function parameters.
 */
int ereply(char* fp, char* buf, int nbuf, ...)
{    
    va_list ap;
    int result;
    va_start(ap, nbuf);
	result = eread(fp, buf, nbuf, EFNEW|EFCR, ap);
    va_end(ap);
    return result;
}

/*
 * This is the general "read input from the
 * echo line" routine. The basic idea is that the prompt
 * string "prompt" is written to the echo line, and a one
 * line reply is read back into the supplied "buf" (with
 * maximum length "len"). The "flag" contains EFNEW (a
 * new prompt), an EFAUTO (autocomplete), or EFCR (echo
 * the carriage return as CR).
 */
eread(fp, buf, nbuf, flag, ap)
char	*fp;
char	*buf;
va_list ap; /* Deviation from original source - now using va_* for portability */
{
	register int	cpos;
	register SYMBOL	*sp1;
	register SYMBOL	*sp2;
	register int	i;
	register int	c;
	register int	h;
	register int	nhits;
	register int	nxtra;
	register int	bxtra;

	cpos = 0;
	if (kbdmop != NULL) {			/* In a macro.		*/
		while ((c = *kbdmop++) != '\0')
			buf[cpos++] = c;
		buf[cpos] = '\0';
		goto done;
	}
	if ((flag&EFNEW)!=0 || ttrow!=nrow-1) {
		ttcolor(CTEXT);
		ttmove(nrow-1, 0);
		epresf = TRUE;
	} else
		eputc(' ');
	eformat(fp, ap);
	tteeol();
	ttflush();
	for (;;) {
		c = ttgetc();
		if (c==' ' && (flag&EFAUTO)!=0) {
			nhits = 0;
			nxtra = HUGE;
			for (h=0; h<NSHASH; ++h) {
				sp1 = symbol[h];
				while (sp1 != NULL) {
					for (i=0; i<cpos; ++i) {
						if (buf[i] != sp1->s_name[i])
							break;
					}
					if (i == cpos) {
						if (nhits == 0)
							sp2 = sp1;
						++nhits;
						bxtra = getxtra(sp1, sp2, cpos);
						if (bxtra < nxtra)
							nxtra = bxtra;
					}
					sp1 = sp1->s_symp;
				}
			}
			if (nhits == 0)		/* No completion.	*/
				continue;
			for (i=0; i<nxtra && cpos<nbuf-1; ++i) {
				c = sp2->s_name[cpos];
				buf[cpos++] = c;
				eputc(c);
			}
			ttflush();
			if (nhits != 1)		/* Fake a CR if there	*/
				continue;	/* is 1 choice.		*/
			c = 0x0D;
		}
		switch (c) {
		case 0x0D:			/* Return, done.	*/
			buf[cpos] = '\0';
			if (kbdmip != NULL) {
				if (kbdmip+cpos+1 > &kbdm[NKBDM-3]) {
					(void) ctrlg(FALSE, 0, KRANDOM);
					ttflush();
					return (ABORT);
				}
				for (i=0; i<cpos; ++i)
					*kbdmip++ = buf[i];
				*kbdmip++ = '\0';
			}
			if ((flag&EFCR) != 0) {
				ttputc(0x0D);
				ttflush();
			}
			goto done;

		case 0x07:			/* Bell, abort.		*/
			eputc(0x07);
			(void) ctrlg(FALSE, 0, KRANDOM);
			ttflush();
			return (ABORT);

		case 0x7F:			/* Rubout, erase.	*/
		case 0x08:			/* Backspace, erase.	*/
			if (cpos != 0) {
				ttputc('\b');
				ttputc(' ');
				ttputc('\b');
				--ttcol;
				if (ISCTRL(buf[--cpos]) != FALSE) {
					ttputc('\b');
					ttputc(' ');
					ttputc('\b');
					--ttcol;
				}
				ttflush();
			}
			break;

		case 0x15:			/* C-U, kill line.	*/
			while (cpos != 0) {
				ttputc('\b');
				ttputc(' ');
				ttputc('\b');
				--ttcol;
				if (ISCTRL(buf[--cpos]) != FALSE) {
					ttputc('\b');
					ttputc(' ');
					ttputc('\b');
					--ttcol;
				}
			}
			ttflush();
			break;

		default:			/* All the rest.	*/
			if (cpos < nbuf-1) {
				buf[cpos++] = c;
				eputc(c);
				ttflush();
			}
		}
	}
done:
	if (buf[0] == '\0')
		return (FALSE);
	return (TRUE);
}

/*
 * The "sp1" and "sp2" point to extended command
 * symbol table entries. The "cpos" is a horizontal position
 * in the name. Return the longest block of characters that can
 * be autocompleted at this point. Sometimes the two symbols
 * are the same, but this is normal.
 */
getxtra(sp1, sp2, cpos)
register SYMBOL	*sp1;
register SYMBOL	*sp2;
{
	register int	i;

	i = cpos;
	for (;;) {
		if (sp1->s_name[i] != sp2->s_name[i])
			break;
		if (sp1->s_name[i] == '\0')
			break;
		++i;
	}
	return (i - cpos);
}

/*
 * Special "printf" for the echo line.
 * Each call to "eprintf" starts a new line in the
 * echo area, and ends with an erase to end of the
 * echo line. The formatting is done by a call
 * to the standard formatting routine.
 */
void eprintf(char* fp, ...)
{
	va_list ap;
	va_start(ap, fp);
	ttcolor(CTEXT);
	ttmove(nrow-1, 0);
	eformat(fp, ap);
	tteeol();
	ttflush();
	epresf = TRUE;
	va_end(ap);
}

/*
 * Printf style formatting. This is
 * called by both "eprintf" and "ereply", to provide
 * formatting services to their clients. The move to the
 * start of the echo line, and the erase to the end of
 * the echo line, is done by the caller.
 */
eformat(fp, ap)
register char	*fp;
va_list	ap;
{
	register int	c;

	while ((c = *fp++) != '\0') {
		if (c != '%')
			eputc(c);
		else {
			c = *fp++;
			switch (c) {
			case 'd':
				eputi(va_arg(ap, int), 10);
				break;

			case 'o':
				eputi(va_arg(ap, int),  8);
				break;

			case 's':
				eputs(va_arg(ap, char*));
				break;

			default:
				eputc(c);
			}
		}
	}
}

/*
 * Put integer, in radix "r".
 */
eputi(i, r)
register int	i;
register int	r;
{
	register int	q;

	if ((q=i/r) != 0)
		eputi(q, r);
	eputc(i%r+'0');
}

/*
 * Put string.
 */
eputs(s)
register char	*s;
{
	register int	c;

	while ((c = *s++) != '\0')
		eputc(c);
}

/*
 * Put character. Watch for
 * control characters, and for the line
 * getting too long.
 */
eputc(c)
register int	c;
{
	if (ttcol < ncol) {
		if (ISCTRL(c) != FALSE) {
			eputc('^');
			c ^= 0x40;
		}
		ttputc(c);
		++ttcol;
	}
}
/*
 * Name:	MicroEMACS
 *		Text line handling.
 * Version:	29
 * Last edit:	14-Feb-86
 * By:		rex::conroy, vox::ellison
 *		decvax!decwrl!dec-rhea!dec-rex!conroy
 *				   ...!dec-vox!ellison
 *
 * The functions in this file
 * are a general set of line management
 * utilities. They are the only routines that
 * touch the text. They also touch the buffer
 * and window structures, to make sure that the
 * necessary updating gets done. There are routines
 * in this file that handle the kill buffer too.
 * It isn't here for any good reason.
 *
 * Note that this code only updates the dot and
 * mark values in the window list. Since all the code
 * acts on the current window, the buffer that we
 * are editing must be being displayed, which means
 * that "b_nwnd" is non zero, which means that the
 * dot and mark values in the buffer headers are
 * nonsense.
 */

#define	NBLOCK	16			/* Line block chunk size	*/

#ifndef	KBLOCK
#define	KBLOCK	256			/* Kill buffer block size.	*/
#endif

char	*kbufp	= NULL;			/* Kill buffer data.		*/
int	kused	= 0;			/* # of bytes used in KB.	*/
int	ksize	= 0;			/* # of bytes allocated in KB.	*/

/*
 * This routine allocates a block
 * of memory large enough to hold a LINE
 * containing "used" characters. The block is
 * always rounded up a bit. Return a pointer
 * to the new block, or NULL if there isn't
 * any memory left. Print a message in the
 * message line if no space.
 */
LINE	*
lalloc(used)
register int	used;
{
	register LINE	*lp;
	register int	size;

	size = (used+NBLOCK-1) & ~(NBLOCK-1);
	if (size == 0)				/* Assume that an empty	*/
		size = NBLOCK;			/* line is for type-in.	*/
	if ((lp=(LINE *)malloc(sizeof(LINE)+size)) == NULL) {
		eprintf("Cannot allocate %d bytes", size);
		return (NULL);
	}
	lp->l_size = size;
	lp->l_used = used;
	return (lp);
}

/*
 * Delete line "lp". Fix all of the
 * links that might point at it (they are
 * moved to offset 0 of the next line.
 * Unlink the line from whatever buffer it
 * might be in. Release the memory. The
 * buffers are updated too; the magic conditions
 * described in the above comments don't hold
 * here.
 */
lfree(lp)
register LINE	*lp;
{
	register BUFFER	*bp;
	register WINDOW	*wp;

	wp = wheadp;
	while (wp != NULL) {
		if (wp->w_linep == lp)
			wp->w_linep = lp->l_fp;
		if (wp->w_dotp  == lp) {
			wp->w_dotp  = lp->l_fp;
			wp->w_doto  = 0;
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
			if (bp->b_dotp  == lp) {
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
 * This routine gets called when
 * a character is changed in place in the
 * current buffer. It updates all of the required
 * flags in the buffer and window system. The flag
 * used is passed as an argument; if the buffer is being
 * displayed in more than 1 window we change EDIT to
 * HARD. Set MODE if the mode line needs to be
 * updated (the "*" has to be set).
 */
lchange(flag)
register int	flag;
{
	register WINDOW	*wp;

	if (curbp->b_nwnd != 1)			/* Ensure hard.		*/
		flag = WFHARD;
	if ((curbp->b_flag&BFCHG) == 0) {	/* First change, so 	*/
		flag |= WFMODE;			/* update mode lines.	*/
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
 * Insert "n" copies of the character "c"
 * at the current location of dot. In the easy case
 * all that happens is the text is stored in the line.
 * In the hard case, the line has to be reallocated.
 * When the window list is updated, take special
 * care; I screwed it up once. You always update dot
 * in the current window. You update mark, and a
 * dot in another window, if it is greater than
 * the place where you did the insert. Return TRUE
 * if all is well, and FALSE on errors.
 */
linsert(n, c)
{
	register char	*cp1;
	register char	*cp2;
	register LINE	*lp1;
	register LINE	*lp2;
	register LINE	*lp3;
	register int	doto;
	register int	i;
	register WINDOW	*wp;

	lchange(WFEDIT);
	lp1 = curwp->w_dotp;			/* Current line		*/
	if (lp1 == curbp->b_linep) {		/* At the end: special	*/
		if (curwp->w_doto != 0) {
			eprintf("bug: linsert");
			return (FALSE);
		}
		if ((lp2=lalloc(n)) == NULL)	/* Allocate new line	*/
			return (FALSE);
		lp3 = lp1->l_bp;		/* Previous line	*/
		lp3->l_fp = lp2;		/* Link in		*/
		lp2->l_fp = lp1;
		lp1->l_bp = lp2;
		lp2->l_bp = lp3;
		for (i=0; i<n; ++i)
			lp2->l_text[i] = c;
		curwp->w_dotp = lp2;
		curwp->w_doto = n;
		return (TRUE);
	}
	doto = curwp->w_doto;			/* Save for later.	*/
	if (lp1->l_used+n > lp1->l_size) {	/* Hard: reallocate	*/
		if ((lp2=lalloc(lp1->l_used+n)) == NULL)
			return (FALSE);
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
	} else {				/* Easy: in place	*/
		lp2 = lp1;			/* Pretend new line	*/
		lp2->l_used += n;
		cp2 = &lp1->l_text[lp1->l_used];
		cp1 = cp2-n;
		while (cp1 != &lp1->l_text[doto])
			*--cp2 = *--cp1;
	}
	for (i=0; i<n; ++i)			/* Add the characters	*/
		lp2->l_text[doto+i] = c;
	wp = wheadp;				/* Update windows	*/
	while (wp != NULL) {
		if (wp->w_linep == lp1)
			wp->w_linep = lp2;
		if (wp->w_dotp == lp1) {
			wp->w_dotp = lp2;
			if (wp==curwp || wp->w_doto>doto)
				wp->w_doto += n;
		}
		if (wp->w_markp == lp1) {
			wp->w_markp = lp2;
			if (wp->w_marko > doto)
				wp->w_marko += n;
		}
		wp = wp->w_wndp;
	}
	return (TRUE);
}

/*
 * Insert a newline into the buffer
 * at the current location of dot in the current
 * window. The funny ass-backwards way it does things
 * is not a botch; it just makes the last line in
 * the file not a special case. Return TRUE if everything
 * works out and FALSE on error (memory allocation
 * failure). The update of dot and mark is a bit
 * easier then in the above case, because the split
 * forces more updating.
 */
lnewline()
{
	register char	*cp1;
	register char	*cp2;
	register LINE	*lp1;
	register LINE	*lp2;
	register int	doto;
	register WINDOW	*wp;

	lchange(WFHARD);
	lp1  = curwp->w_dotp;			/* Get the address and	*/
	doto = curwp->w_doto;			/* offset of "."	*/
	if ((lp2=lalloc(doto)) == NULL)		/* New first half line	*/
		return (FALSE);
	cp1 = &lp1->l_text[0];			/* Shuffle text around	*/
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
	wp = wheadp;				/* Windows		*/
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
	return (TRUE);
}

/*
 * This function deletes "n" bytes,
 * starting at dot. It understands how do deal
 * with end of lines, etc. It returns TRUE if all
 * of the characters were deleted, and FALSE if
 * they were not (because dot ran into the end of
 * the buffer. The "kflag" is TRUE if the text
 * should be put in the kill buffer.
 */
ldelete(n, kflag)
{
	register char	*cp1;
	register char	*cp2;
	register LINE	*dotp;
	register int	doto;
	register int	chunk;
	register WINDOW	*wp;

	while (n != 0) {
		dotp = curwp->w_dotp;
		doto = curwp->w_doto;
		if (dotp == curbp->b_linep)	/* Hit end of buffer.	*/
			return (FALSE);
		chunk = dotp->l_used-doto;	/* Size of chunk.	*/
		if (chunk > n)
			chunk = n;
		if (chunk == 0) {		/* End of line, merge.	*/
			lchange(WFHARD);
			if (ldelnewline() == FALSE
			|| (kflag!=FALSE && kinsert('\n')==FALSE))
				return (FALSE);
			--n;
			continue;
		}
		lchange(WFEDIT);
		cp1 = &dotp->l_text[doto];	/* Scrunch text.	*/
		cp2 = cp1 + chunk;
		if (kflag != FALSE) {		/* Kill?		*/
			while (cp1 != cp2) {
				if (kinsert(*cp1) == FALSE)
					return (FALSE);
				++cp1;
			}
			cp1 = &dotp->l_text[doto];
		}
		while (cp2 != &dotp->l_text[dotp->l_used])
			*cp1++ = *cp2++;
		dotp->l_used -= chunk;
		wp = wheadp;			/* Fix windows		*/
		while (wp != NULL) {
			if (wp->w_dotp==dotp && wp->w_doto>=doto) {
				wp->w_doto -= chunk;
				if (wp->w_doto < doto)
					wp->w_doto = doto;
			}	
			if (wp->w_markp==dotp && wp->w_marko>=doto) {
				wp->w_marko -= chunk;
				if (wp->w_marko < doto)
					wp->w_marko = doto;
			}
			wp = wp->w_wndp;
		}
		n -= chunk;
	}
	return (TRUE);
}

/*
 * Delete a newline. Join the current line
 * with the next line. If the next line is the magic
 * header line always return TRUE; merging the last line
 * with the header line can be thought of as always being a
 * successful operation, even if nothing is done, and this makes
 * the kill buffer work "right". Easy cases can be done by
 * shuffling data around. Hard cases require that lines be moved
 * about in memory. Return FALSE on error and TRUE if all
 * looks ok. Called by "ldelete" only.
 */
ldelnewline()
{
	register char	*cp1;
	register char	*cp2;
	register LINE	*lp1;
	register LINE	*lp2;
	register LINE	*lp3;
	register WINDOW	*wp;

	lp1 = curwp->w_dotp;
	lp2 = lp1->l_fp;
	if (lp2 == curbp->b_linep) {		/* At the buffer end.	*/
		if (lp1->l_used == 0)		/* Blank line.		*/
			lfree(lp1);
		return (TRUE);
	}
	if (lp2->l_used <= lp1->l_size-lp1->l_used) {
		cp1 = &lp1->l_text[lp1->l_used];
		cp2 = &lp2->l_text[0];
		while (cp2 != &lp2->l_text[lp2->l_used])
			*cp1++ = *cp2++;
		wp = wheadp;
		while (wp != NULL) {
			if (wp->w_linep == lp2)
				wp->w_linep = lp1;
			if (wp->w_dotp == lp2) {
				wp->w_dotp  = lp1;
				wp->w_doto += lp1->l_used;
			}
			if (wp->w_markp == lp2) {
				wp->w_markp  = lp1;
				wp->w_marko += lp1->l_used;
			}
			wp = wp->w_wndp;
		}		
		lp1->l_used += lp2->l_used;
		lp1->l_fp = lp2->l_fp;
		lp2->l_fp->l_bp = lp1;
		free((char *) lp2);
		return (TRUE);
	}
	if ((lp3=lalloc(lp1->l_used+lp2->l_used)) == NULL)
		return (FALSE);
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
		if (wp->w_linep==lp1 || wp->w_linep==lp2)
			wp->w_linep = lp3;
		if (wp->w_dotp == lp1)
			wp->w_dotp  = lp3;
		else if (wp->w_dotp == lp2) {
			wp->w_dotp  = lp3;
			wp->w_doto += lp1->l_used;
		}
		if (wp->w_markp == lp1)
			wp->w_markp  = lp3;
		else if (wp->w_markp == lp2) {
			wp->w_markp  = lp3;
			wp->w_marko += lp1->l_used;
		}
		wp = wp->w_wndp;
	}
	free((char *) lp1);
	free((char *) lp2);
	return (TRUE);
}

/*
 * Replace plen characters before dot with argument string.
 * Control-J characters in st are interpreted as newlines.
 * There is a casehack disable flag (normally it likes to match
 * case of replacement to what was there).
 */
lreplace(plen, st, f)
register int	plen;			/* length to remove		*/
char		*st;			/* replacement string		*/
int		f;			/* case hack disable		*/
{
	register int	rlen;		/* replacement length		*/
	register int	rtype;		/* capitalization 		*/
	register int	c;		/* used for random characters	*/
	register int	doto;		/* offset into line		*/

	/*
	 * Find the capitalization of the word that was found.
	 * f says use exact case of replacement string (same thing that
	 * happens with lowercase found), so bypass check.
	 */
	backchar(TRUE, plen, KRANDOM);
	rtype = _L;
	c = lgetc(curwp->w_dotp, curwp->w_doto);
	if (ISUPPER(c)!=FALSE  &&  f==FALSE) {
		rtype = _U|_L;
		if (curwp->w_doto+1 < llength(curwp->w_dotp)) {
			c = lgetc(curwp->w_dotp, curwp->w_doto+1);
			if (ISUPPER(c) != FALSE) {
				rtype = _U;
			}
		}
	}

	/*
	 * make the string lengths match (either pad the line
	 * so that it will fit, or scrunch out the excess).
	 * be careful with dot's offset.
	 */
	rlen = strlen(st);
	doto = curwp->w_doto;
	if (plen > rlen)
		ldelete(plen-rlen, FALSE);
	else if (plen < rlen) {
		if (linsert(rlen-plen, ' ') == FALSE)
			return (FALSE);
	}
	curwp->w_doto = doto;

	/*
	 * do the replacement:  If was capital, then place first 
	 * char as if upper, and subsequent chars as if lower.  
	 * If inserting upper, check replacement for case.
	 */
	while ((c = *st++&0xff) != '\0') {
		if ((rtype&_U)!=0  &&  ISLOWER(c)!=0)
			c = TOUPPER(c);
		if (rtype == (_U|_L))
			rtype = _L;
		if (c == '\n') {
			if (curwp->w_doto == llength(curwp->w_dotp))
				forwchar(FALSE, 1, KRANDOM);
			else {
				ldelete(1, FALSE);
				lnewline();
			}
		} else if (curwp->w_dotp == curbp->b_linep) {
			linsert(1, c);
		} else if (curwp->w_doto == llength(curwp->w_dotp)) {
			ldelete(1, FALSE);
			linsert(1, c);
		} else
			lputc(curwp->w_dotp, curwp->w_doto++, c);
	}
	lchange(WFHARD);
	return (TRUE);
}

/*
 * Delete all of the text
 * saved in the kill buffer. Called by commands
 * when a new kill context is being created. The kill
 * buffer array is released, just in case the buffer has
 * grown to immense size. No errors.
 */
kdelete()
{
	if (kbufp != NULL) {
		free((char *) kbufp);
		kbufp = NULL;
		kused = 0;
		ksize = 0;
	}
}

/*
 * Insert a character to the kill buffer,
 * enlarging the buffer if there isn't any room. Always
 * grow the buffer in chunks, on the assumption that if you
 * put something in the kill buffer you are going to put
 * more stuff there too later. Return TRUE if all is
 * well, and FALSE on errors. Print a message on
 * errors.
 */
kinsert(c)
{
	register char	*nbufp;
	register int	i;

	if (kused == ksize) {
		if ((nbufp=malloc(ksize+KBLOCK)) == NULL) {
			eprintf("Too many kills");
			return (FALSE);
		}
		for (i=0; i<ksize; ++i)
			nbufp[i] = kbufp[i];
		if (kbufp != NULL)
			free((char *) kbufp);
		kbufp  = nbufp;
		ksize += KBLOCK;
	}
	kbufp[kused++] = c;
	return (TRUE);
}

/*
 * This function gets characters from
 * the kill buffer. If the character index "n" is
 * off the end, it returns "-1". This lets the caller
 * just scan along until it gets a "-1" back.
 */
kremove(n)
{
	if (n >= kused)
		return (-1);
	return (kbufp[n] & 0xFF);
}
/*
 * Name:	MicroEMACS
 *		Symbol table stuff.
 * Version:	29
 * Last edit:	05-Feb-86
 * By:		rex::conroy
 *		decvax!decwrl!dec-rhea!dec-rex!conroy
 *
 * Symbol tables, and keymap setup.
 * The terminal specific parts of building the
 * keymap has been moved to a better place.
 */

#define	DIRLIST	0			/* Disarmed!			*/

/*
 * Defined by "main.c".
 */
extern	int	ctrlg();		/* Abort out of things		*/
extern	int	quit();			/* Quit				*/
extern	int	ctlxlp();		/* Begin macro			*/
extern	int	ctlxrp();		/* End macro			*/
extern	int	ctlxe();		/* Execute macro		*/
extern	int	jeffexit();		/* Jeff Lomicka style exit.	*/
extern  int	showversion();		/* Show version numbers, etc.	*/

/*
 * Defined by "search.c".
 */
extern	int	forwsearch();		/* Search forward		*/
extern	int	backsearch();		/* Search backwards		*/
extern  int	searchagain();		/* Repeat last search command	*/
extern  int	forwisearch();		/* Incremental search forward	*/
extern  int	backisearch();		/* Incremental search backwards	*/
extern  int	queryrepl();		/* Query replace		*/

/*
 * Defined by "basic.c".
 */
extern	int	gotobol();		/* Move to start of line	*/
extern	int	backchar();		/* Move backward by characters	*/
extern	int	gotoeol();		/* Move to end of line		*/
extern	int	forwchar();		/* Move forward by characters	*/
extern	int	gotobob();		/* Move to start of buffer	*/
extern	int	gotoeob();		/* Move to end of buffer	*/
extern	int	forwline();		/* Move forward by lines	*/
extern	int	backline();		/* Move backward by lines	*/
extern	int	forwpage();		/* Move forward by pages	*/
extern	int	backpage();		/* Move backward by pages	*/
extern	int	setmark();		/* Set mark			*/
extern	int	swapmark();		/* Swap "." and mark		*/
extern	int	gotoline();		/* Go to a specified line.	*/

/*
 * Defined by "buffer.c".
 */
extern	int	listbuffers();		/* Display list of buffers	*/
extern	int	usebuffer();		/* Switch a window to a buffer	*/
extern	int	killbuffer();		/* Make a buffer go away.	*/

#if	DIRLIST
/*
 * Defined by "dirlist.c".
 */
extern	int	dirlist();		/* Directory list.		*/
#endif

/*
 * Defined by "display.c".
 */
extern  int	readmsg();		/* Read next line of message.	*/

/*
 * Defined by "file.c".
 */
extern	int	fileread();		/* Get a file, read only	*/
extern	int	filevisit();		/* Get a file, read write	*/
extern	int	filewrite();		/* Write a file			*/
extern	int	filesave();		/* Save current file		*/
extern	int	filename();		/* Adjust file name		*/

/*
 * Defined by "random.c".
 */
extern	int	selfinsert();		/* Insert character		*/
extern	int	showcpos();		/* Show the cursor position	*/
extern	int	twiddle();		/* Twiddle characters		*/
extern	int	quote();		/* Insert literal		*/
extern	int	openline();		/* Open up a blank line		*/
extern	int	newline();		/* Insert CR-LF			*/
extern	int	deblank();		/* Delete blank lines		*/
extern	int	indent();		/* Insert CR-LF, then indent	*/
extern	int	forwdel();		/* Forward delete		*/
extern	int	backdel();		/* Backward delete		*/
extern	int	killline();		/* Kill forward			*/
extern	int	yank();			/* Yank back from killbuffer.	*/

/*
 * Defined by "region.c".
 */
extern	int	killregion();		/* Kill region.			*/
extern	int	copyregion();		/* Copy region to kill buffer.	*/
extern	int	lowerregion();		/* Lower case region.		*/
extern	int	upperregion();		/* Upper case region.		*/

/*
 * Defined by "spawn.c".
 */
extern	int	spawncli();		/* Run CLI in a subjob.		*/

/*
 * Defined by "window.c".
 */
extern	int	reposition();		/* Reposition window		*/
extern	int	refresh();		/* Refresh the screen		*/
extern	int	nextwind();		/* Move to the next window	*/
extern  int	prevwind();		/* Move to the previous window	*/
extern	int	mvdnwind();		/* Move window down		*/
extern	int	mvupwind();		/* Move window up		*/
extern	int	onlywind();		/* Make current window only one	*/
extern	int	splitwind();		/* Split current window		*/
extern	int	enlargewind();		/* Enlarge display window.	*/
extern	int	shrinkwind();		/* Shrink window.		*/

/*
 * Defined by "word.c".
 */
extern	int	backword();		/* Backup by words		*/
extern	int	forwword();		/* Advance by words		*/
extern	int	upperword();		/* Upper case word.		*/
extern	int	lowerword();		/* Lower case word.		*/
extern	int	capword();		/* Initial capitalize word.	*/
extern	int	delfword();		/* Delete forward word.		*/
extern	int	delbword();		/* Delete backward word.	*/

/*
 * Defined by "extend.c".
 */
extern	int	extend();		/* Extended commands.		*/
extern	int	help();			/* Help key.			*/
extern	int	bindtokey();		/* Modify key bindings.		*/
extern	int	wallchart();		/* Make wall chart.		*/
int	backdir();

typedef	struct	{
	short	k_key;			/* Key to bind.			*/
	int	(*k_funcp)();		/* Function.			*/
	char	*k_name;		/* Function name string.	*/
}	KEY;

/*
 * Default key binding table. VSCode-style shortcuts.
 * Ctrl+C=Copy, Ctrl+V=Paste, Ctrl+X=Cut, Ctrl+S=Save, etc.
 */
KEY	key[] = {
	KCTRL|'A',	gotobol,	"goto-bol",
	KCTRL|'B',	backdir,	"back-dir",
	KCTRL|'C',	copyregion,	"copy-region",
	KCTRL|'D',	forwdel,	"forw-del-char",
	KCTRL|'E',	gotoeol,	"goto-eol",
	KCTRL|'F',	forwisearch,	"forw-i-search",
	KCTRL|'G',	gotoline,	"goto-line",
	KCTRL|'H',	queryrepl,	"query-replace",
	KCTRL|'I',	selfinsert,	"ins-self",
	KCTRL|'J',	indent,		"ins-nl-and-indent",
	KCTRL|'K',	killline,	"kill-line",
	KCTRL|'L',	refresh,	"refresh",
	KCTRL|'M',	newline,	"ins-nl",
	KCTRL|'N',	forwline,	"forw-line",
	KCTRL|'O',	filevisit,	"file-visit",
	KCTRL|'P',	backline,	"back-line",
	KCTRL|'Q',	quit,		"quit",
	KCTRL|'R',	backisearch,	"back-i-search",
	KCTRL|'S',	filesave,	"file-save",
	KCTRL|'V',	yank,		"yank",
	KCTRL|'W',	quit,		"quit",
	KCTRL|'X',	killregion,	"kill-region",
	KCTRL|'Z',	jeffexit,	"jeff-exit",
	KCTRL|'\\',	splitwind,	"split-window",
	KCTRL|'@',	setmark,	"set-mark",
	-1,		backchar,	"back-char",
	-1,		forwchar,	"forw-char",
	-1,		ctrlg,		"abort",
	-1,		backdel,	"back-del-char",
	-1,		openline,	"ins-nl-and-backup",
	-1,		quote,		"quote",
	-1,		twiddle,	"twiddle",
	-1,		forwpage,	"forw-page",
	-1,		backpage,	"back-page",
	-1,		listbuffers,	"display-buffers",
	-1,		filename,	"set-file-name",
	-1,		lowerregion,	"lower-region",
	-1,		upperregion,	"upper-region",
	-1,		fileread,	"file-read",
	-1,		filewrite,	"file-write",
	-1,		swapmark,	"swap-dot-and-mark",
	-1,		showcpos,	"display-position",
	-1,		ctlxlp,		"start-macro",
	-1,		ctlxrp,		"end-macro",
	-1,		onlywind,	"only-window",
	-1,		usebuffer,	"use-buffer",
	-1,		ctlxe,		"execute-macro",
	-1,		nextwind,	"forw-window",
	-1,		prevwind,	"back-window",
	-1,		enlargewind,	"enlarge-window",
	-1,		shrinkwind,	"shrink-window",
	-1,		mvdnwind,	"down-window",
	-1,		mvupwind,	"up-window",
	-1,		deblank,	"del-blank-lines",
	-1,		delbword,	"back-del-word",
	-1,		delfword,	"forw-del-word",
	-1,		readmsg,	"display-message",
	-1,		showversion,	"display-version",
	-1,		reposition,	"reposition-window",
	-1,		gotoeob,	"goto-eob",
	-1,		gotobob,	"goto-bob",
	-1,		backword,	"back-word",
	-1,		forwword,	"forw-word",
	-1,		capword,	"cap-word",
	-1,		lowerword,	"lower-word",
	-1,		upperword,	"upper-word",
	-1,		backsearch,	"back-search",
	-1,		forwsearch,	"forw-search",
	-1,		extend,		"extended-command",
	-1,		searchagain,	"search-again",
	-1,		spawncli,	"spawn-cli",
	-1,		help,		"help",
	-1,		wallchart,	"display-bindings",
	-1,		bindtokey,	"bind-to-key"
};

#define	NKEY	(sizeof(key) / sizeof(key[0]))

/*
 * Symbol table lookup.
 * Return a pointer to the SYMBOL node, or NULL if
 * the symbol is not found.
 */
SYMBOL	*
symlookup(cp)
register char	*cp;
{
	register SYMBOL	*sp;

	sp = symbol[symhash(cp)];
	while (sp != NULL) {
		if (strcmp(cp, sp->s_name) == 0)
			return (sp);
		sp = sp->s_symp;
	}
	return (NULL);
}

/*
 * Take a string, and compute the symbol table
 * bucket number. This is done by adding all of the characters
 * together, and taking the sum mod NSHASH. The string probably
 * should not contain any GR characters; if it does the "*cp"
 * may get a nagative number on some machines, and the "%"
 * will return a negative number!
 */
symhash(cp)
register char	*cp;
{
	register int	c;
	register int	n;

	n = 0;
	while ((c = *cp++) != 0)
		n += c;
	return (n % NSHASH);
}

/*
 * Build initial keymap. VSCode-style bindings.
 */
keymapinit()
{
	register SYMBOL	*sp;
	register KEY	*kp;
	register int	i;

	for (i=0; i<NKEYS; ++i)
		binding[i] = NULL;
	for (kp = &key[0]; kp < &key[NKEY]; ++kp)
		keyadd(kp->k_key, kp->k_funcp, kp->k_name);
	keydup(0x7F,		"back-del-char");
	keydup(KCTRL|'[',	"abort");
	if ((sp=symlookup("ins-self")) == NULL)
		abort();
	for (i=0x20; i<0x7F; ++i) {
		if (binding[i] != NULL)
			abort();
		binding[i] = sp;
		++sp->s_nkey;
	}
	ttykeymapinit();
}

/*
 * Create a new builtin function "name"
 * with function "funcp". If the "new" is a real
 * key, bind it as a side effect. All errors
 * are fatal.
 */
keyadd(new, funcp, name)
int	(*funcp)();
char	*name;
{
	register SYMBOL	*sp;
	register int	hash;

	if ((sp=(SYMBOL *)malloc(sizeof(SYMBOL))) == NULL)
		abort();
	hash = symhash(name);
	sp->s_symp = symbol[hash];
	symbol[hash] = sp;
	sp->s_nkey = 0;
	sp->s_name = name;
	sp->s_funcp = funcp;
	if (new >= 0) {				/* Bind this key.	*/
		if (binding[new] != NULL)
			abort();
		binding[new] = sp;
		++sp->s_nkey;
	}
}

/*
 * Bind key "new" to the existing
 * routine "name". If the name cannot be found,
 * or the key is already bound, abort.
 */
keydup(new, name)
register int	new;
char		*name;
{
	register SYMBOL	*sp;

	if (binding[new]!=NULL || (sp=symlookup(name))==NULL)
		abort();
	binding[new] = sp;
	++sp->s_nkey;
}
/*
 * Name:	MicroEMACS
 *		Buffer handling.
 * Version:	30
 * Last edit:	17-Feb-86
 * By:		rex::conroy
 *		decvax!decwrl!dec-rhea!dec-rex!conroy
 */

/*
 * Attach a buffer to a window. The
 * values of dot and mark come from the buffer
 * if the use count is 0. Otherwise, they come
 * from some other window.
 */
usebuffer(f, n, k)
{
	register BUFFER	*bp;
	register WINDOW	*wp;
	register int	s;
	char		bufn[NBUFN];

	if ((s=ereply("Use buffer: ", bufn, NBUFN)) != TRUE)
		return (s);
	if ((bp=bfind(bufn, TRUE)) == NULL)
		return (FALSE);
	if (--curbp->b_nwnd == 0) {		/* Last use.		*/
		curbp->b_dotp  = curwp->w_dotp;
		curbp->b_doto  = curwp->w_doto;
		curbp->b_markp = curwp->w_markp;
		curbp->b_marko = curwp->w_marko;
	}
	curbp = bp;				/* Switch.		*/
	curwp->w_bufp  = bp;
	curwp->w_linep = bp->b_linep;		/* For macros, ignored.	*/
	curwp->w_flag |= WFMODE|WFFORCE|WFHARD;	/* Quite nasty.		*/
	if (bp->b_nwnd++ == 0) {		/* First use.		*/
		curwp->w_dotp  = bp->b_dotp;
		curwp->w_doto  = bp->b_doto;
		curwp->w_markp = bp->b_markp;
		curwp->w_marko = bp->b_marko;
		return (TRUE);
	}
	wp = wheadp;				/* Look for old.	*/
	while (wp != NULL) {
		if (wp!=curwp && wp->w_bufp==bp) {
			curwp->w_dotp  = wp->w_dotp;
			curwp->w_doto  = wp->w_doto;
			curwp->w_markp = wp->w_markp;
			curwp->w_marko = wp->w_marko;
			break;
		}
		wp = wp->w_wndp;
	}
	return (TRUE);
}

/*
 * Dispose of a buffer, by name.
 * Ask for the name. Look it up (don't get too
 * upset if it isn't there at all!). Get quite upset
 * if the buffer is being displayed. Clear the buffer (ask
 * if the buffer has been changed). Then free the header
 * line and the buffer header. Bound to "C-X K".
 */
killbuffer(f, n, k)
{
	register BUFFER	*bp;
	register BUFFER	*bp1;
	register BUFFER	*bp2;
	register int	s;
	char		bufn[NBUFN];

	if ((s=ereply("Kill buffer: ", bufn, NBUFN)) != TRUE)
		return (s);
	if ((bp=bfind(bufn, FALSE)) == NULL)	/* Easy if unknown.	*/
		return (TRUE);
	if (bp->b_nwnd != 0) {			/* Error if on screen.	*/
		eprintf("Buffer is being displayed");
		return (FALSE);
	}
	if ((s=bclear(bp)) != TRUE)		/* Blow text away.	*/
		return (s);
	free((char *) bp->b_linep);		/* Release header line.	*/
	bp1 = NULL;				/* Find the header.	*/
	bp2 = bheadp;
	while (bp2 != bp) {
		bp1 = bp2;
		bp2 = bp2->b_bufp;
	}
	bp2 = bp2->b_bufp;			/* Next one in chain.	*/
	if (bp1 == NULL)			/* Unlink it.		*/
		bheadp = bp2;
	else
		bp1->b_bufp = bp2;
	free((char *) bp);			/* Release buffer block	*/
	return (TRUE);
}

/*
 * Display the buffer list. This is done
 * in two parts. The "makelist" routine figures out
 * the text, and puts it in the buffer whoses header is
 * pointed to by the external "blistp". The "popblist"
 * then pops the data onto the screen. Bound to
 * "C-X C-B".
 */
listbuffers(f, n, k)
{
	register int	s;

	if ((s=makelist()) != TRUE)
		return (s);
	return (popblist());
}

/*
 * Pop the special buffer whose
 * buffer header is pointed to by the external
 * variable "blistp" onto the screen. This is used
 * by the "listbuffers" routine (above) and by
 * some other packages. Returns a status.
 */
popblist()
{
	register WINDOW	*wp;
	register BUFFER	*bp;

	if (blistp->b_nwnd == 0) {		/* Not on screen yet.	*/
		if ((wp=wpopup()) == NULL)
			return (FALSE);
		bp = wp->w_bufp;
		if (--bp->b_nwnd == 0) {
			bp->b_dotp  = wp->w_dotp;
			bp->b_doto  = wp->w_doto;
			bp->b_markp = wp->w_markp;
			bp->b_marko = wp->w_marko;
		}
		wp->w_bufp  = blistp;
		++blistp->b_nwnd;
	}
	wp = wheadp;
	while (wp != NULL) {
		if (wp->w_bufp == blistp) {
			wp->w_linep = lforw(blistp->b_linep);
			wp->w_dotp  = lforw(blistp->b_linep);
			wp->w_doto  = 0;
			wp->w_markp = NULL;
			wp->w_marko = 0;
			wp->w_flag |= WFMODE|WFHARD;
		}
		wp = wp->w_wndp;
	}
	return (TRUE);
}

/*
 * This routine rebuilds the
 * text in the special secret buffer
 * that holds the buffer list. It is called
 * by the list buffers command. Return TRUE
 * if everything works. Return FALSE if there
 * is an error (if there is no memory).
 */
makelist()
{
	register char	*cp1;
	register char	*cp2;
	register int	c;
	register BUFFER	*bp;
	register LINE	*lp;
	register int	nbytes;
	register int	s;
	char		b[6+1];
	char		line[128];

	blistp->b_flag &= ~BFCHG;		/* Blow away old.	*/
	if ((s=bclear(blistp)) != TRUE)
		return (s);
	strcpy(blistp->b_fname, "");
	if (addline("C   Size Buffer           File") == FALSE
	||  addline("-   ---- ------           ----") == FALSE)
		return (FALSE);
	bp = bheadp;				/* For all buffers	*/
	while (bp != NULL) {
		cp1 = &line[0];			/* Start at left edge	*/
		if ((bp->b_flag&BFCHG) != 0)	/* "*" if changed	*/
			*cp1++ = '*';
		else
			*cp1++ = ' ';
		*cp1++ = ' ';			/* Gap.			*/
		nbytes = 0;			/* Count bytes in buf.	*/
		lp = lforw(bp->b_linep);
		while (lp != bp->b_linep) {
			nbytes += llength(lp)+1;
			lp = lforw(lp);
		}
		itoa_(b, 6, nbytes);		/* 6 digit buffer size.	*/
		cp2 = &b[0];
		while ((c = *cp2++) != 0)
			*cp1++ = c;
		*cp1++ = ' ';			/* Gap.			*/
		cp2 = &bp->b_bname[0];		/* Buffer name		*/
		while ((c = *cp2++) != 0)
			*cp1++ = c;
		cp2 = &bp->b_fname[0];		/* File name		*/
		if (*cp2 != 0) {
			while (cp1 < &line[1+1+6+1+NBUFN+1])
				*cp1++ = ' ';		
			while ((c = *cp2++) != 0) {
				if (cp1 < &line[128-1])
					*cp1++ = c;
			}
		}
		*cp1 = 0;			/* Add to the buffer.	*/
		if (addline(line) == FALSE)
			return (FALSE);
		bp = bp->b_bufp;
	}
	return (TRUE);				/* All done		*/
}

/*
 * Used above.
 */
itoa_(buf, width, num)
register char	buf[];
register int	width;
register int	num;
{
	buf[width] = 0;				/* End of string.	*/
	while (num >= 10) {			/* Conditional digits.	*/
		buf[--width] = (num%10) + '0';
		num /= 10;
	}
	buf[--width] = num + '0';		/* Always 1 digit.	*/
	while (width != 0)			/* Pad with blanks.	*/
		buf[--width] = ' ';
}

/*
 * The argument "text" points to
 * a string. Append this line to the
 * buffer list buffer. Handcraft the EOL
 * on the end. Return TRUE if it worked and
 * FALSE if you ran out of room.
 */
addline(text)
char	*text;
{
	register LINE	*lp;
	register int	i;
	register int	ntext;

	ntext = strlen(text);
	if ((lp=lalloc(ntext)) == NULL)
		return (FALSE);
	for (i=0; i<ntext; ++i)
		lputc(lp, i, text[i]);
	blistp->b_linep->l_bp->l_fp = lp;	/* Hook onto the end	*/
	lp->l_bp = blistp->b_linep->l_bp;
	blistp->b_linep->l_bp = lp;
	lp->l_fp = blistp->b_linep;
	if (blistp->b_dotp == blistp->b_linep)	/* If "." is at the end	*/
		blistp->b_dotp = lp;		/* move it to new line	*/
	return (TRUE);
}

/*
 * Look through the list of
 * buffers. Return TRUE if there
 * are any changed buffers. Special buffers
 * like the buffer list buffer don't count, as
 * they are not in the list. Return FALSE if
 * there are no changed buffers.
 */
anycb()
{
	register BUFFER	*bp;

	bp = bheadp;
	while (bp != NULL) {
		if ((bp->b_flag&BFCHG) != 0)
			return (TRUE);
		bp = bp->b_bufp;
	}
	return (FALSE);
}

/*
 * Search for a buffer, by name.
 * If not found, and the "cflag" is TRUE,
 * create a buffer and put it in the list of
 * all buffers. Return pointer to the BUFFER
 * block for the buffer.
 */
BUFFER	*
bfind(bname, cflag)
register char	*bname;
{
	register BUFFER	*bp;

	bp = bheadp;
	while (bp != NULL) {
		if (strcmp(bname, bp->b_bname) == 0)
			return (bp);
		bp = bp->b_bufp;
	}
	if (cflag!=FALSE && (bp=bcreate(bname))!=NULL) {
		bp->b_bufp = bheadp;
		bheadp = bp;
	}
	return (bp);
}

/*
 * Create a buffer, by name.
 * Return a pointer to the BUFFER header
 * block, or NULL if the buffer cannot
 * be created. The BUFFER is not put in the
 * list of all buffers; this is called by
 * "edinit" to create the buffer list
 * buffer.
 */
BUFFER	*
bcreate(bname)
register char	*bname;
{
	register BUFFER	*bp;
	register LINE	*lp;

	if ((bp=(BUFFER *)malloc(sizeof(BUFFER))) == NULL)
		return (NULL);
	if ((lp=lalloc(0)) == NULL) {
		free((char *) bp);
		return (NULL);
	}
	bp->b_bufp  = NULL;
	bp->b_dotp  = lp;
	bp->b_doto  = 0;
	bp->b_markp = NULL;
	bp->b_marko = 0;
	bp->b_flag  = 0;
	bp->b_nwnd  = 0;
	bp->b_linep = lp;
	strcpy(bp->b_fname, "");
	strcpy(bp->b_bname, bname);
	lp->l_fp = lp;
	lp->l_bp = lp;
	return (bp);
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
bclear(bp)
register BUFFER	*bp;
{
	register LINE	*lp;
	register int	s;
	
	if ((bp->b_flag&BFCHG) != 0		/* Changed.		*/
	&& (s=eyesno("Discard changes")) != TRUE)
		return (s);
	bp->b_flag  &= ~BFCHG;			/* Not changed		*/
	while ((lp=lforw(bp->b_linep)) != bp->b_linep)
		lfree(lp);
	bp->b_dotp  = bp->b_linep;		/* Fix "."		*/
	bp->b_doto  = 0;
	bp->b_markp = NULL;			/* Invalidate "mark"	*/
	bp->b_marko = 0;
	return (TRUE);
}
/*
 * Name:	MicroEMACS
 *		Window handling.
 * Version:	29
 * Last edit:	10-Feb-86
 * By:		rex::conroy
 *		decvax!decwrl!dec-rhea!dec-rex!conroy
 */

/*
 * Reposition dot in the current
 * window to line "n". If the argument is
 * positive, it is that line. If it is negative it
 * is that line from the bottom. If it is 0 the window
 * is centered (this is what the standard redisplay code
 * does). With no argument it defaults to 1.
 * Because of the default, it works like in
 * Gosling.
 */
reposition(f, n, k)
{
	curwp->w_force = n;
	curwp->w_flag |= WFFORCE;
	return (TRUE);
}

/*
 * Refresh the display. A call is made to the
 * "ttresize" entry in the terminal handler, which tries
 * to reset "nrow" and "ncol". They will, however, never
 * be set outside of the NROW or NCOL range. If the display
 * changed size, arrange that everything is redone, then
 * call "update" to fix the display. We do this so the
 * new size can be displayed. In the normal case the
 * call to "update" in "main.c" refreshes the screen,
 * and all of the windows need not be recomputed.
 * Note that when you get to the "display unusable"
 * message, the screen will be messed up. If you make
 * the window bigger again, and send another command,
 * everything will get fixed!
 */
refresh(f, n, k)
{
	register WINDOW	*wp;
	register int	oldnrow;
	register int	oldncol;

	oldnrow = nrow;
	oldncol = ncol;
	ttresize();
	if (nrow!=oldnrow || ncol!=oldncol) {
		wp = wheadp;			/* Find last.		*/
		while (wp->w_wndp != NULL)
			wp = wp->w_wndp;
		if (nrow < wp->w_toprow+3) {	/* Check if too small.	*/
			eprintf("Display unusable");
			return (FALSE);
		}		
		wp->w_ntrows = nrow-wp->w_toprow-2;
		wp = wheadp;			/* Redraw all.		*/
		while (wp != NULL) {
			wp->w_flag |= WFMODE|WFHARD;
			wp = wp->w_wndp;
		}
		sgarbf = TRUE;
		update();
		eprintf("[New size %d by %d]", nrow, ncol);
	} else
		sgarbf = TRUE;
	return (TRUE);
}

/*
 * The command make the next
 * window (next => down the screen)
 * the current window. There are no real
 * errors, although the command does
 * nothing if there is only 1 window on
 * the screen.
 */
nextwind(f, n, k)
{
	register WINDOW	*wp;

	if ((wp=curwp->w_wndp) == NULL)
		wp = wheadp;
	curwp = wp;
	curbp = wp->w_bufp;
	return (TRUE);
}

/*
 * This command makes the previous
 * window (previous => up the screen) the
 * current window. There arn't any errors,
 * although the command does not do a lot
 * if there is 1 window.
 */
prevwind(f, n, k)
{
	register WINDOW	*wp1;
	register WINDOW	*wp2;

	wp1 = wheadp;
	wp2 = curwp;
	if (wp1 == wp2)
		wp2 = NULL;
	while (wp1->w_wndp != wp2)
		wp1 = wp1->w_wndp;
	curwp = wp1;
	curbp = wp1->w_bufp;
	return (TRUE);
}

/*
 * This command moves the current
 * window down by "arg" lines. Recompute
 * the top line in the window. The move up and
 * move down code is almost completely the same;
 * most of the work has to do with reframing the
 * window, and picking a new dot. We share the
 * code by having "move down" just be an interface
 * to "move up".
 */
mvdnwind(f, n, k)
register int	n;
{
	return (mvupwind(f, -n, KRANDOM));
}

/*
 * Move the current window up by "arg"
 * lines. Recompute the new top line of the window.
 * Look to see if "." is still on the screen. If it is,
 * you win. If it isn't, then move "." to center it
 * in the new framing of the window (this command does
 * not really move "."; it moves the frame).
 */
mvupwind(f, n, k)
register int	n;
{
	register LINE	*lp;
	register int	i;

	lp = curwp->w_linep;
	if (n < 0) {
		while (n++ && lp!=curbp->b_linep)
			lp = lforw(lp);
	} else {
		while (n-- && lback(lp)!=curbp->b_linep)
			lp = lback(lp);
	}
	curwp->w_linep = lp;
	curwp->w_flag |= WFHARD;		/* Mode line is OK.	*/
	for (i=0; i<curwp->w_ntrows; ++i) {
		if (lp == curwp->w_dotp)
			return (TRUE);
		if (lp == curbp->b_linep)
			break;
		lp = lforw(lp);
	}
	lp = curwp->w_linep;
	i  = curwp->w_ntrows/2;
	while (i-- && lp!=curbp->b_linep)
		lp = lforw(lp);
	curwp->w_dotp  = lp;
	curwp->w_doto  = 0;
	return (TRUE);
}

/*
 * This command makes the current
 * window the only window on the screen.
 * Try to set the framing
 * so that "." does not have to move on
 * the display. Some care has to be taken
 * to keep the values of dot and mark
 * in the buffer structures right if the
 * distruction of a window makes a buffer
 * become undisplayed.
 */
onlywind(f, n, k)
{
	register WINDOW	*wp;
	register LINE	*lp;
	register int	i;

	while (wheadp != curwp) {
		wp = wheadp;
		wheadp = wp->w_wndp;
		if (--wp->w_bufp->b_nwnd == 0) {
			wp->w_bufp->b_dotp  = wp->w_dotp;
			wp->w_bufp->b_doto  = wp->w_doto;
			wp->w_bufp->b_markp = wp->w_markp;
			wp->w_bufp->b_marko = wp->w_marko;
		}
		free((char *) wp);
	}
	while (curwp->w_wndp != NULL) {
		wp = curwp->w_wndp;
		curwp->w_wndp = wp->w_wndp;
		if (--wp->w_bufp->b_nwnd == 0) {
			wp->w_bufp->b_dotp  = wp->w_dotp;
			wp->w_bufp->b_doto  = wp->w_doto;
			wp->w_bufp->b_markp = wp->w_markp;
			wp->w_bufp->b_marko = wp->w_marko;
		}
		free((char *) wp);
	}
	lp = curwp->w_linep;
	i  = curwp->w_toprow;
	while (i!=0 && lback(lp)!=curbp->b_linep) {
		--i;
		lp = lback(lp);
	}
	curwp->w_toprow = 0;
	curwp->w_ntrows = nrow-2;		/* 2 = mode, echo.	*/
	curwp->w_linep  = lp;
	curwp->w_flag  |= WFMODE|WFHARD;
	return (TRUE);
}

/*
 * Split the current window. A window
 * smaller than 3 lines cannot be split.
 * The only other error that is possible is
 * a "malloc" failure allocating the structure
 * for the new window.
 */
splitwind(f, n, k)
{
	register WINDOW	*wp;
	register LINE	*lp;
	register int	ntru;
	register int	ntrl;
	register int	ntrd;
	register WINDOW	*wp1;
	register WINDOW	*wp2;

	if (curwp->w_ntrows < 3) {
		eprintf("Cannot split a %d line window", curwp->w_ntrows);
		return (FALSE);
	}
	if ((wp = (WINDOW *) malloc(sizeof(WINDOW))) == NULL) {
		eprintf("Cannot allocate WINDOW block");
		return (FALSE);
	}
	++curbp->b_nwnd;			/* Displayed twice.	*/
	wp->w_bufp  = curbp;
	wp->w_dotp  = curwp->w_dotp;
	wp->w_doto  = curwp->w_doto;
	wp->w_markp = curwp->w_markp;
	wp->w_marko = curwp->w_marko;
	wp->w_flag  = 0;
	wp->w_force = 0;
	ntru = (curwp->w_ntrows-1) / 2;		/* Upper size		*/
	ntrl = (curwp->w_ntrows-1) - ntru;	/* Lower size		*/
	lp = curwp->w_linep;
	ntrd = 0;
	while (lp != curwp->w_dotp) {
		++ntrd;
		lp = lforw(lp);
	}
	lp = curwp->w_linep;
	if (ntrd <= ntru) {			/* Old is upper window.	*/
		if (ntrd == ntru)		/* Hit mode line.	*/
			lp = lforw(lp);
		curwp->w_ntrows = ntru;
		wp->w_wndp = curwp->w_wndp;
		curwp->w_wndp = wp;
		wp->w_toprow = curwp->w_toprow+ntru+1;
		wp->w_ntrows = ntrl;
	} else {				/* Old is lower window	*/
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
		wp->w_wndp   = curwp;
		wp->w_toprow = curwp->w_toprow;
		wp->w_ntrows = ntru;
		++ntru;				/* Mode line.		*/
		curwp->w_toprow += ntru;
		curwp->w_ntrows  = ntrl;
		while (ntru--)
			lp = lforw(lp);
	}
	curwp->w_linep = lp;			/* Adjust the top lines	*/
	wp->w_linep = lp;			/* if necessary.	*/
	curwp->w_flag |= WFMODE|WFHARD;
	wp->w_flag |= WFMODE|WFHARD;
	return (TRUE);
}

/*
 * Enlarge the current window.
 * Find the window that loses space. Make
 * sure it is big enough. If so, hack the window
 * descriptions, and ask redisplay to do all the
 * hard work. You don't just set "force reframe"
 * because dot would move.
 */
enlargewind(f, n, k)
{
	register WINDOW	*adjwp;
	register LINE	*lp;
	register int	i;

	if (n < 0)
		return (shrinkwind(f, -n, KRANDOM));
	if (wheadp->w_wndp == NULL) {
		eprintf("Only one window");
		return (FALSE);
	}
	if ((adjwp=curwp->w_wndp) == NULL) {
		adjwp = wheadp;
		while (adjwp->w_wndp != curwp)
			adjwp = adjwp->w_wndp;
	}
	if (adjwp->w_ntrows <= n) {
		eprintf("Impossible change");
		return (FALSE);
	}
	if (curwp->w_wndp == adjwp) {		/* Shrink below.	*/
		lp = adjwp->w_linep;
		for (i=0; i<n && lp!=adjwp->w_bufp->b_linep; ++i)
			lp = lforw(lp);
		adjwp->w_linep  = lp;
		adjwp->w_toprow += n;
	} else {				/* Shrink above.	*/
		lp = curwp->w_linep;
		for (i=0; i<n && lback(lp)!=curbp->b_linep; ++i)
			lp = lback(lp);
		curwp->w_linep  = lp;
		curwp->w_toprow -= n;
	}
	curwp->w_ntrows += n;
	adjwp->w_ntrows -= n;
	curwp->w_flag |= WFMODE|WFHARD;
	adjwp->w_flag |= WFMODE|WFHARD;
	return (TRUE);
}

/*
 * Shrink the current window.
 * Find the window that gains space. Hack at
 * the window descriptions. Ask the redisplay to
 * do all the hard work.
 */
shrinkwind(f, n, k)
{
	register WINDOW	*adjwp;
	register LINE	*lp;
	register int	i;

	if (n < 0)
		return (enlargewind(f, -n, KRANDOM));
	if (wheadp->w_wndp == NULL) {
		eprintf("Only one window");
		return (FALSE);
	}
	if ((adjwp=curwp->w_wndp) == NULL) {
		adjwp = wheadp;
		while (adjwp->w_wndp != curwp)
			adjwp = adjwp->w_wndp;
	}
	if (curwp->w_ntrows <= n) {
		eprintf("Impossible change");
		return (FALSE);
	}
	if (curwp->w_wndp == adjwp) {		/* Grow below.		*/
		lp = adjwp->w_linep;
		for (i=0; i<n && lback(lp)!=adjwp->w_bufp->b_linep; ++i)
			lp = lback(lp);
		adjwp->w_linep  = lp;
		adjwp->w_toprow -= n;
	} else {				/* Grow above.		*/
		lp = curwp->w_linep;
		for (i=0; i<n && lp!=curbp->b_linep; ++i)
			lp = lforw(lp);
		curwp->w_linep  = lp;
		curwp->w_toprow += n;
	}
	curwp->w_ntrows -= n;
	adjwp->w_ntrows += n;
	curwp->w_flag |= WFMODE|WFHARD;
	adjwp->w_flag |= WFMODE|WFHARD;
	return (TRUE);
}

/*
 * Pick a window for a pop-up.
 * Split the screen if there is only
 * one window. Pick the uppermost window that
 * isn't the current window. An LRU algorithm
 * might be better. Return a pointer, or
 * NULL on error.
 */
WINDOW	*
wpopup()
{
	register WINDOW	*wp;

	if (wheadp->w_wndp == NULL
	&& splitwind(FALSE, 0, KRANDOM) == FALSE)
		return (NULL);
	wp = wheadp;				/* Find window to use	*/
	while (wp!=NULL && wp==curwp)
		wp = wp->w_wndp;
	return (wp);
}
/*
 * Name:	MicroEMACS
 * 		File commands.
 * Version:	29
 * Last edit:	05-Feb-86
 * By:		rex::conroy
 *		decvax!decwrl!dec-rhea!dec-rex!conroy
 */

/*
 * Read a file into the current
 * buffer. This is really easy; all you do it
 * find the name of the file, and call the standard
 * "read a file into the current buffer" code.
 */
fileread(f, n, k)
{
	register int	s;
	char		fname[NFILEN];

	if ((s=ereply("Read file: ", fname, NFILEN)) != TRUE)
		return (s);
	adjustcase(fname);
	return (readin(fname));
}

/*
 * Select a file for editing.
 * Look around to see if you can find the
 * fine in another buffer; if you can find it
 * just switch to the buffer. If you cannot find
 * the file, create a new buffer, read in the
 * text, and switch to the new buffer.
 */
filevisit(f, n, k)
{
	register BUFFER	*bp;
	register WINDOW	*wp;
	register LINE	*lp;
	register int	i;
	register int	s;
	char		bname[NBUFN];
	char		fname[NFILEN];

	if ((s=ereply("Visit file: ", fname, NFILEN)) != TRUE)
		return (s);
	adjustcase(fname);
	for (bp=bheadp; bp!=NULL; bp=bp->b_bufp) {
		if (strcmp(bp->b_fname, fname) == 0) {
			if (--curbp->b_nwnd == 0) {
				curbp->b_dotp  = curwp->w_dotp;
				curbp->b_doto  = curwp->w_doto;
				curbp->b_markp = curwp->w_markp;
				curbp->b_marko = curwp->w_marko;
			}
			curbp = bp;
			curwp->w_bufp  = bp;
			if (bp->b_nwnd++ == 0) {
				curwp->w_dotp  = bp->b_dotp;
				curwp->w_doto  = bp->b_doto;
				curwp->w_markp = bp->b_markp;
				curwp->w_marko = bp->b_marko;
			} else {
				wp = wheadp;
				while (wp != NULL) {
					if (wp!=curwp && wp->w_bufp==bp) {
						curwp->w_dotp  = wp->w_dotp;
						curwp->w_doto  = wp->w_doto;
						curwp->w_markp = wp->w_markp;
						curwp->w_marko = wp->w_marko;
						break;
					}
					wp = wp->w_wndp;
				}
			}
			lp = curwp->w_dotp;
			i = curwp->w_ntrows/2;
			while (i-- && lback(lp)!=curbp->b_linep)
				lp = lback(lp);
			curwp->w_linep = lp;
			curwp->w_flag |= WFMODE|WFHARD;
			if (kbdmop == NULL)
				eprintf("[Old buffer]");
			return (TRUE);
		}
	}
	makename(bname, fname);			/* New buffer name.	*/
	while ((bp=bfind(bname, FALSE)) != NULL) {
		s = ereply("Buffer name: ", bname, NBUFN);
		if (s == ABORT)			/* ^G to just quit	*/
			return (s);
		if (s == FALSE) {		/* CR to clobber it	*/
			makename(bname, fname);
			break;
		}
	}
	if (bp==NULL && (bp=bfind(bname, TRUE))==NULL) {
		eprintf("Cannot create buffer");
		return (FALSE);
	}
	if (--curbp->b_nwnd == 0) {		/* Undisplay.		*/
		curbp->b_dotp = curwp->w_dotp;
		curbp->b_doto = curwp->w_doto;
		curbp->b_markp = curwp->w_markp;
		curbp->b_marko = curwp->w_marko;
	}
	curbp = bp;				/* Switch to it.	*/
	curwp->w_bufp = bp;
	curbp->b_nwnd++;
	return (readin(fname));			/* Read it in.		*/
}

/*
 * Read the file "fname" into the current buffer.
 * Make all of the text in the buffer go away, after checking
 * for unsaved changes. This is called by the "read" command, the
 * "visit" command, and the mainline (for "uemacs file"). If the
 * BACKUP conditional is set, then this routine also does the read
 * end of backup processing. The BFBAK flag, if set in a buffer,
 * says that a backup should be taken. It is set when a file is
 * read in, but not on a new file (you don't need to make a backup
 * copy of nothing). Return a standard status. Print a summary
 * (lines read, error message) out as well.
 */
readin(fname)
char	fname[];
{
	register LINE	*lp1;
	register LINE	*lp2;
	register int	i;
	register WINDOW	*wp;
	register BUFFER	*bp;
	register int	s;
	register int	nbytes;
	register int	nline;
	char		line[NLINE];

	bp = curbp;				/* Cheap.		*/
	if ((s=bclear(bp)) != TRUE)		/* Might be old.	*/
		return (s);
#if	BACKUP
	bp->b_flag &= ~(BFCHG|BFBAK);		/* No change, backup.	*/
#else
	bp->b_flag &= ~BFCHG;			/* No change.		*/
#endif
	strcpy(bp->b_fname, fname);
	if ((s=ffropen(fname)) == FIOERR) 	/* Hard file open.	*/
		goto out;
	if (s == FIOFNF) {			/* File not found.	*/
		if (kbdmop == NULL)
			eprintf("[New file]");
		goto out;
	}
	nline = 0;
	while ((s=ffgetline(line, NLINE)) == FIOSUC) {
		nbytes = strlen(line);
		if ((lp1=lalloc(nbytes)) == NULL) {
			s = FIOERR;		/* Keep message on the	*/
			break;			/* display.		*/
		}
		lp2 = lback(curbp->b_linep);
		lp2->l_fp = lp1;
		lp1->l_fp = curbp->b_linep;
		lp1->l_bp = lp2;
		curbp->b_linep->l_bp = lp1;
		for (i=0; i<nbytes; ++i)
			lputc(lp1, i, line[i]);
		++nline;
	}
	ffclose();				/* Ignore errors.	*/
	if (s==FIOEOF && kbdmop==NULL) {	/* Don't zap an error.	*/
		if (nline == 1)
			eprintf("[Read 1 line]");
		else
			eprintf("[Read %d lines]", nline);
	}
#if	BACKUP
	curbp->b_flag |= BFBAK;			/* Need a backup.	*/
#endif
out:
	for (wp=wheadp; wp!=NULL; wp=wp->w_wndp) {
		if (wp->w_bufp == curbp) {
			wp->w_linep = lforw(curbp->b_linep);
			wp->w_dotp  = lforw(curbp->b_linep);
			wp->w_doto  = 0;
			wp->w_markp = NULL;
			wp->w_marko = 0;
			wp->w_flag |= WFMODE|WFHARD;
		}
	}
	if (s == FIOERR)			/* False if error.	*/
		return (FALSE);
	return (TRUE);
}

filldir(p)char*p;{DIR*d;struct dirent*e;LINE*l;int n;char s[256];
if(!(d=opendir(p)))return;bclear(curbp);chdir(p);getcwd(curbp->b_fname,NFILEN);
while((e=readdir(d))){if(e->d_name[0]=='.'&&!e->d_name[1])continue;
n=sprintf(s,"%s%s",e->d_name,e->d_type==DT_DIR?"/":"");if((l=lalloc(n))){
l->l_bp=lback(curbp->b_linep);l->l_bp->l_fp=l;l->l_fp=curbp->b_linep;
curbp->b_linep->l_bp=l;while(n--)lputc(l,n,s[n]);}}closedir(d);dirmode=1;
curwp->w_linep=curwp->w_dotp=lforw(curbp->b_linep);curwp->w_doto=0;curwp->w_flag|=WFHARD;}
backdir(){if(dirmode){filldir("..");}else{char d[80],*p;strcpy(d,curbp->b_fname);p=strrchr(d,'/');if(p)*p=0;else*d=0;filldir(*d?d:".");}return TRUE;}

/*
 * Take a file name, and from it
 * fabricate a buffer name. This routine knows
 * about the syntax of file names on the target system.
 * BDC1		left scan delimiter.
 * BDC2		optional second left scan delimiter.
 * BDC3		optional right scan delimiter.
 */
makename(bname, fname)
char	bname[];
char	fname[];
{
	register char	*cp1;
	register char	*cp2;

	cp1 = &fname[0];
	while (*cp1 != 0)
		++cp1;
#ifdef	BDC2
	while (cp1!=&fname[0] && cp1[-1]!=BDC1 && cp1[-1]!=BDC2)
		--cp1;
#else
	while (cp1!=&fname[0] && cp1[-1]!=BDC1)
		--cp1;
#endif
	cp2 = &bname[0];
#ifdef	BDC3
	while (cp2!=&bname[NBUFN-1] && *cp1!=0 && *cp1!=BDC3)
		*cp2++ = *cp1++;
#else
	while (cp2!=&bname[NBUFN-1] && *cp1!=0)
		*cp2++ = *cp1++;
#endif
	*cp2 = 0;
}

/*
 * Ask for a file name, and write the
 * contents of the current buffer to that file.
 * Update the remembered file name and clear the
 * buffer changed flag. This handling of file names
 * is different from the earlier versions, and
 * is more compatable with Gosling EMACS than
 * with ITS EMACS.
 */
filewrite(f, n, k)
{
	register WINDOW	*wp;
	register int	s;
	char		fname[NFILEN];

	if ((s=ereply("Write file: ", fname, NFILEN)) != TRUE)
		return (s);
	adjustcase(fname);
	if ((s=writeout(fname)) == TRUE) {
		strcpy(curbp->b_fname, fname);
		curbp->b_flag &= ~BFCHG;
		wp = wheadp;			/* Update mode lines.	*/
		while (wp != NULL) {
			if (wp->w_bufp == curbp)
				wp->w_flag |= WFMODE;
			wp = wp->w_wndp;
		}
	}
#if	BACKUP
	curbp->b_flag &= ~BFBAK;		/* No backup.		*/
#endif
	return (s);
}

/*
 * Save the contents of the current buffer back into
 * its associated file. Do nothing if there have been no changes
 * (is this a bug, or a feature). Error if there is no remembered
 * file name. If this is the first write since the read or visit,
 * then a backup copy of the file is made.
 */
filesave(f, n, k)
{
	register WINDOW	*wp;
	register int	s;

	if ((curbp->b_flag&BFCHG) == 0)		/* Return, no changes.	*/
		return (TRUE);
	if (curbp->b_fname[0] == 0) {		/* Must have a name.	*/
		eprintf("No file name");
		return (FALSE);
	}
#if	BACKUP
	if ((curbp->b_flag&BFBAK) != 0) {
		s = fbackupfile(curbp->b_fname);
		if (s == ABORT)			/* Hard error.		*/
			return (s);
		if (s == FALSE			/* Softer error.	*/
		&& (s=eyesno("Backup error, save anyway")) != TRUE)
			return (s);
	}
#endif
	if ((s=writeout(curbp->b_fname)) == TRUE) {
		curbp->b_flag &= ~BFCHG;
		wp = wheadp;			/* Update mode lines.	*/
		while (wp != NULL) {
			if (wp->w_bufp == curbp)
				wp->w_flag |= WFMODE;
			wp = wp->w_wndp;
		}
	}
#if	BACKUP
	curbp->b_flag &= ~BFBAK;		/* No backup.		*/
#endif
	return (s);
}

/*
 * This function performs the details of file
 * writing. Uses the file management routines in the
 * "fileio.c" package. The number of lines written is
 * displayed. Sadly, it looks inside a LINE; provide
 * a macro for this. Most of the grief is error
 * checking of some sort.
 */
writeout(fn)
char	*fn;
{
	register int	s;
	register LINE	*lp;
	register int	nline;

	if ((s=ffwopen(fn)) != FIOSUC)		/* Open writes message.	*/
		return (FALSE);
	lp = lforw(curbp->b_linep);		/* First line.		*/
	nline = 0;				/* Number of lines.	*/
	while (lp != curbp->b_linep) {
		if ((s=ffputline(&lp->l_text[0], llength(lp))) != FIOSUC)
			break;
		++nline;
		lp = lforw(lp);
	}
	if (s == FIOSUC) {			/* No write error.	*/
		s = ffclose();
		if (s==FIOSUC && kbdmop==NULL) {
			if (nline == 1)
				eprintf("[Wrote 1 line]");
			else
				eprintf("[Wrote %d lines]", nline);
		}
	} else					/* Ignore close error	*/
		ffclose();			/* if a write error.	*/
	if (s != FIOSUC)			/* Some sort of error.	*/
		return (FALSE);
	return (TRUE);
}

/*
 * The command allows the user
 * to modify the file name associated with
 * the current buffer. It is like the "f" command
 * in UNIX "ed". The operation is simple; just zap
 * the name in the BUFFER structure, and mark the windows
 * as needing an update. You can type a blank line at the
 * prompt if you wish.
 */
filename(f, n, k)
{
	register WINDOW	*wp;
	register int	s;
	char	 	fname[NFILEN];

	if ((s=ereply("Name: ", fname, NFILEN)) == ABORT)
		return (s);
	adjustcase(fname);
	strcpy(curbp->b_fname, fname);		/* Fix name.		*/
	wp = wheadp;				/* Update mode lines.	*/
	while (wp != NULL) {
		if (wp->w_bufp == curbp)
			wp->w_flag |= WFMODE;
		wp = wp->w_wndp;
	}
#if	BACKUP
	curbp->b_flag &= ~BFBAK;		/* No backup.		*/
#endif
	return (TRUE);
}
/*
 * Name:	MicroEMACS
 *		Assorted commands.
 * Version:	29
 * Last edit:	10-Feb-86
 * By:		rex::conroy
 *		decvax!decwrl!dec-rhea!dec-rex!conroy
 *
 * The file contains the command
 * processors for a large assortment of unrelated
 * commands. The only thing they have in common is
 * that they are all command processors.
 */

/*
 * Display a bunch of useful information about
 * the current location of dot. The character under the
 * cursor (in octal), the current line, row, and column, and
 * approximate position of the cursor in the file (as a percentage)
 * is displayed. The column position assumes an infinite position
 * display; it does not truncate just because the screen does.
 * This is normally bound to "C-X =".
 */
showcpos(f, n, k)
{
	register LINE	*clp;
	register int	cbo;
	register int	nchar;
	register int	cchar;
	register int	nline;
	register int	cline;
	register int	cbyte;
	register int	ratio;
	register int	row;
	register int	col;
	register int	i;
	register int	c;

	clp = lforw(curbp->b_linep);		/* Collect the data.	*/
	cbo = 0;
	nchar = 0;
	nline = 1;				/* Origin 1.		*/
	for (;;) {
		if (clp == curwp->w_dotp) {
			cline = nline;
			if (cbo == curwp->w_doto) {
				cchar = nchar;
				if (cbo == llength(clp))
					cbyte = '\n';
				else
					cbyte = lgetc(clp, cbo);
			}
		}
		if (cbo == llength(clp)) {
			if (clp == curbp->b_linep)
				break;
			clp = lforw(clp);
			cbo = 0;
			++nline;		/* Count a line.	*/
		} else
			++cbo;
		++nchar;			/* Count a character.	*/
	}
	row = curwp->w_toprow;			/* Determine row.	*/
	clp = curwp->w_linep;
	while (clp!=curbp->b_linep && clp!=curwp->w_dotp) {
		++row;
		clp = lforw(clp);
	}
	++row;					/* Convert to origin 1.	*/
	col = 0;				/* Determine column.	*/
	for (i=0; i<curwp->w_doto; ++i) {
		c = lgetc(curwp->w_dotp, i);
		if (c == '\t')
			col |= 0x07;
		else if (ISCTRL(c) != FALSE)
			++col;
		++col;
	}
	++col;					/* Convert to origin 1.	*/
	ratio = 0;				/* Ratio before dot.	*/
	if (nchar != 0) {
		ratio = (100L*cchar) / nchar;
		if (ratio==0 && cchar!=0)	/* Allow 0% only at the	*/
			ratio = 1;		/* start of the file.	*/
	}
	eprintf("[CH:0%o Line:%d Row:%d Col:%d %d%% of %d]",
		cbyte, cline, row, col, ratio, nchar);
	return (TRUE);
}

/*
 * Twiddle the two characters on either side of
 * dot. If dot is at the end of the line twiddle the
 * two characters before it. Return with an error if dot
 * is at the beginning of line; it seems to be a bit
 * pointless to make this work. This fixes up a very
 * common typo with a single stroke. Normally bound
 * to "C-T". This always works within a line, so
 * "WFEDIT" is good enough.
 */
twiddle(f, n, k)
{
	register LINE	*dotp;
	register int	doto;
	register int	cl;
	register int	cr;

	dotp = curwp->w_dotp;
	doto = curwp->w_doto;
	if (doto==llength(dotp) && --doto<0)
		return (FALSE);
	cr = lgetc(dotp, doto);
	if (--doto < 0)
		return (FALSE);
	cl = lgetc(dotp, doto);
	lputc(dotp, doto+0, cr);
	lputc(dotp, doto+1, cl);
	lchange(WFEDIT);
	return (TRUE);
}

/*
 * Quote the next character, and
 * insert it into the buffer. All the characters
 * are taken literally, with the exception of the newline,
 * which always has its line splitting meaning. The character
 * is always read, even if it is inserted 0 times, for
 * regularity.
 */
quote(f, n, k)
{
	register int	s;
	register int	c;

	if (kbdmop != NULL)
		c = *kbdmop++;
	else {
		c = ttgetc();
		if (kbdmip != NULL) {
			if (kbdmip > &kbdm[NKBDM-4]) {
				ctrlg(FALSE, 0, KRANDOM);
				return (ABORT);
			}
			*kbdmip++ = c;
		}
	}
	if (n < 0)
		return (FALSE);
	if (n == 0)
		return (TRUE);
	if (c == '\n') {
		do {
			s = lnewline();
		} while (s==TRUE && --n);
		return (s);
	}
	return (linsert(n, c));
}

/*
 * Ordinary text characters are bound to this function,
 * which inserts them into the buffer. Characters marked as control
 * characters (using the CTRL flag) may be remapped to their ASCII
 * equivalent. This makes TAB (C-I) work right, and also makes the
 * world look reasonable if a control character is bound to this
 * this routine by hand. Any META or CTLX flags on the character
 * are discarded. This is the only routine that actually looks
 * the the "k" argument.
 */
selfinsert(f, n, k)
{
	register int	c;

	if (dirmode)
		return (TRUE);
	if (n < 0)
		return (FALSE);
	if (n == 0)
		return (TRUE);
	c = k & KCHAR;
	if ((k&KCTRL)!=0 && c>='@' && c<='_')	/* ASCII-ify.		*/
		c -= '@';
	return (linsert(n, c));
}

/*
 * Open up some blank space. The basic plan
 * is to insert a bunch of newlines, and then back
 * up over them. Everything is done by the subcommand
 * procerssors. They even handle the looping. Normally
 * this is bound to "C-O".
 */
openline(f, n, k)
{
	register int	i;
	register int	s;

	if (n < 0)
		return (FALSE);
	if (n == 0)
		return (TRUE);
	i = n;					/* Insert newlines.	*/
	do {
		s = lnewline();
	} while (s==TRUE && --i);
	if (s == TRUE)				/* Then back up overtop	*/
		s = backchar(f, n, KRANDOM);	/* of them all.		*/
	return (s);
}

/*
 * Insert a newline.
 * If you are at the end of the line and the
 * next line is a blank line, just move into the
 * blank line. This makes "C-O" and "C-X C-O" work
 * nicely, and reduces the ammount of screen
 * update that has to be done. This would not be
 * as critical if screen update were a lot
 * more efficient.
 */
newline(f, n, k)
{
	register LINE	*lp;
	register int	s;
	if(dirmode){lp=curwp->w_dotp;char f[256];int i,n=llength(lp);for(i=0;i<n;i++)f[i]=lgetc(lp,i);f[n]=0;if(n&&f[n-1]=='/')filldir(f);else{dirmode=0;readin(f);}return TRUE;}
	if (n < 0)
		return (FALSE);
	while (n--) {
		lp = curwp->w_dotp;
		if (llength(lp) == curwp->w_doto
		&& lp != curbp->b_linep
		&& llength(lforw(lp)) == 0) {
			if ((s=forwchar(FALSE, 1, KRANDOM)) != TRUE)
				return (s);
		} else if ((s=lnewline()) != TRUE)
			return (s);
	}
	return (TRUE);
}

/*
 * Delete blank lines around dot.
 * What this command does depends if dot is
 * sitting on a blank line. If dot is sitting on a
 * blank line, this command deletes all the blank lines
 * above and below the current line. If it is sitting
 * on a non blank line then it deletes all of the
 * blank lines after the line. Normally this command
 * is bound to "C-X C-O". Any argument is ignored.
 */
deblank(f, n, k)
{
	register LINE	*lp1;
	register LINE	*lp2;
	register int	nld;

	lp1 = curwp->w_dotp;
	while (llength(lp1)==0 && (lp2=lback(lp1))!=curbp->b_linep)
		lp1 = lp2;
	lp2 = lp1;
	nld = 0;
	while ((lp2=lforw(lp2))!=curbp->b_linep && llength(lp2)==0)
		++nld;
	if (nld == 0)
		return (TRUE);
	curwp->w_dotp = lforw(lp1);
	curwp->w_doto = 0;
	return (ldelete(nld, FALSE));
}

/*
 * Insert a newline, then enough
 * tabs and spaces to duplicate the indentation
 * of the previous line. Assumes tabs are every eight
 * characters. Quite simple. Figure out the indentation
 * of the current line. Insert a newline by calling
 * the standard routine. Insert the indentation by
 * inserting the right number of tabs and spaces.
 * Return TRUE if all ok. Return FALSE if one
 * of the subcomands failed. Normally bound
 * to "C-J".
 */
indent(f, n, k)
{
	register int	nicol;
	register int	c;
	register int	i;

	if (n < 0)
		return (FALSE);
	while (n--) {
		nicol = 0;
		for (i=0; i<llength(curwp->w_dotp); ++i) {
			c = lgetc(curwp->w_dotp, i);
			if (c!=' ' && c!='\t')
				break;
			if (c == '\t')
				nicol |= 0x07;
			++nicol;
		}
		if (lnewline() == FALSE
		|| ((i=nicol/8)!=0 && linsert(i, '\t')==FALSE)
		|| ((i=nicol%8)!=0 && linsert(i,  ' ')==FALSE))
			return (FALSE);
	}
	return (TRUE);
}

/*
 * Delete forward. This is real
 * easy, because the basic delete routine does
 * all of the work. Watches for negative arguments,
 * and does the right thing. If any argument is
 * present, it kills rather than deletes, to prevent
 * loss of text if typed with a big argument.
 * Normally bound to "C-D".
 */
forwdel(f, n, k)
{
	if (n < 0)
		return (backdel(f, -n, KRANDOM));
	if (f != FALSE) {			/* Really a kill.	*/
		if ((lastflag&CFKILL) == 0)
			kdelete();
		thisflag |= CFKILL;
	}
	return (ldelete(n, f));
}

/*
 * Delete backwards. This is quite easy too,
 * because it's all done with other functions. Just
 * move the cursor back, and delete forwards.
 * Like delete forward, this actually does a kill
 * if presented with an argument.
 */
backdel(f, n, k)
{
	register int	s;

	if (n < 0)
		return (forwdel(f, -n, KRANDOM));
	if (f != FALSE) {			/* Really a kill.	*/
		if ((lastflag&CFKILL) == 0)
			kdelete();
		thisflag |= CFKILL;
	}
	if ((s=backchar(f, n, KRANDOM)) == TRUE)
		s = ldelete(n, f);
	return (s);
}

/*
 * Kill line. If called without an argument,
 * it kills from dot to the end of the line, unless it
 * is at the end of the line, when it kills the newline.
 * If called with an argument of 0, it kills from the
 * start of the line to dot. If called with a positive
 * argument, it kills from dot forward over that number
 * of newlines. If called with a negative argument it
 * kills any text before dot on the current line,
 * then it kills back abs(arg) lines.
 */
killline(f, n, k)
{
	register int	chunk;
	register LINE	*nextp;

	if ((lastflag&CFKILL) == 0)		/* Clear kill buffer if	*/
		kdelete();			/* last wasn't a kill.	*/
	thisflag |= CFKILL;
	if (f == FALSE) {
		chunk = llength(curwp->w_dotp)-curwp->w_doto;
		if (chunk == 0)
			chunk = 1;
	} else if (n > 0) {
		chunk = llength(curwp->w_dotp)-curwp->w_doto+1;
		nextp = lforw(curwp->w_dotp);
		while (--n) {
			if (nextp == curbp->b_linep)
				return (FALSE);
			chunk += llength(nextp)+1;
			nextp = lforw(nextp);
		}
	} else {				/* n <= 0		*/
		chunk = curwp->w_doto;
		curwp->w_doto = 0;
		while (n++) {
			if (lback(curwp->w_dotp) == curbp->b_linep)
				break;
			curwp->w_dotp = lback(curwp->w_dotp);
			curwp->w_flag |= WFMOVE;
			chunk += llength(curwp->w_dotp)+1;
		}
	}
	return (ldelete(chunk, TRUE));
}

/*
 * Yank text back from the kill buffer. This
 * is really easy. All of the work is done by the
 * standard insert routines. All you do is run the loop,
 * and check for errors. The blank
 * lines are inserted with a call to "newline"
 * instead of a call to "lnewline" so that the magic
 * stuff that happens when you type a carriage
 * return also happens when a carriage return is
 * yanked back from the kill buffer.
 * An attempt has been made to fix the cosmetic bug
 * associated with a yank when dot is on the top line of
 * the window (nothing moves, because all of the new
 * text landed off screen).
 */
yank(f, n, k)
{
	register int	c;
	register int	i;
	register LINE	*lp;
	register int	nline;

	if (n < 0)
		return (FALSE);
	nline = 0;				/* Newline counting.	*/
	while (n--) {
		i = 0;
		while ((c=kremove(i)) >= 0) {
			if (c == '\n') {
				if (newline(FALSE, 1, KRANDOM) == FALSE)
					return (FALSE);
				++nline;
			} else {
				if (linsert(1, c) == FALSE)
					return (FALSE);
			}
			++i;
		}
	}
	lp = curwp->w_linep;			/* Cosmetic adjustment	*/
	if (curwp->w_dotp == lp) {		/* if offscreen insert.	*/
		while (nline-- && lback(lp)!=curbp->b_linep)
			lp = lback(lp);
		curwp->w_linep = lp;		/* Adjust framing.	*/
		curwp->w_flag |= WFHARD;
	}
	return (TRUE);
}
/*
 * Name:	MicroEMACS
 *		Word mode commands.
 * Version:	29
 * Last edit:	05-Feb-86
 * By:		rex::conroy
 *		decvax!decwrl!dec-rhea!dec-rex!conroy
 *
 * The routines in this file
 * implement commands that work word at
 * a time. There are all sorts of word mode
 * commands. If I do any sentence and/or paragraph
 * mode commands, they are likely to be put in
 * this file.
 */

/*
 * Move the cursor backward by
 * "n" words. All of the details of motion
 * are performed by the "backchar" and "forwchar"
 * routines. Error if you try to move beyond
 * the buffers.
 */
backword(f, n, k)
{
	if (n < 0)
		return (forwword(f, -n, KRANDOM));
	if (backchar(FALSE, 1, KRANDOM) == FALSE)
		return (FALSE);
	while (n--) {
		while (inword() == FALSE) {
			if (backchar(FALSE, 1, KRANDOM) == FALSE)
				return (FALSE);
		}
		while (inword() != FALSE) {
			if (backchar(FALSE, 1, KRANDOM) == FALSE)
				return (FALSE);
		}
	}
	return (forwchar(FALSE, 1, KRANDOM));
}

/*
 * Move the cursor forward by
 * the specified number of words. All of the
 * motion is done by "forwchar". Error if you
 * try and move beyond the buffer's end.
 */
forwword(f, n, k)
{
	if (n < 0)
		return (backword(f, -n, KRANDOM));
	while (n--) {
		while (inword() == FALSE) {
			if (forwchar(FALSE, 1, KRANDOM) == FALSE)
				return (FALSE);
		}
		while (inword() != FALSE) {
			if (forwchar(FALSE, 1, KRANDOM) == FALSE)
				return (FALSE);
		}
	}
	return (TRUE);
}

/*
 * Move the cursor forward by
 * the specified number of words. As you move,
 * convert any characters to upper case. Error
 * if you try and move beyond the end of the
 * buffer.
 */
upperword(f, n, k)
{
	register int	c;

	if (n < 0)
		return (FALSE);
	while (n--) {
		while (inword() == FALSE) {
			if (forwchar(FALSE, 1, KRANDOM) == FALSE)
				return (FALSE);
		}
		while (inword() != FALSE) {
			c = lgetc(curwp->w_dotp, curwp->w_doto);
			if (ISLOWER(c) != FALSE) {
				c = TOUPPER(c);
				lputc(curwp->w_dotp, curwp->w_doto, c);
				lchange(WFHARD);
			}
			if (forwchar(FALSE, 1, KRANDOM) == FALSE)
				return (FALSE);
		}
	}
	return (TRUE);
}

/*
 * Move the cursor forward by
 * the specified number of words. As you move
 * convert characters to lower case. Error if you
 * try and move over the end of the buffer.
 */
lowerword(f, n, k)
{
	register int	c;

	if (n < 0)
		return (FALSE);
	while (n--) {
		while (inword() == FALSE) {
			if (forwchar(FALSE, 1, KRANDOM) == FALSE)
				return (FALSE);
		}
		while (inword() != FALSE) {
			c = lgetc(curwp->w_dotp, curwp->w_doto);
			if (ISUPPER(c) != FALSE) {
				c = TOLOWER(c);
				lputc(curwp->w_dotp, curwp->w_doto, c);
				lchange(WFHARD);
			}
			if (forwchar(FALSE, 1, KRANDOM) == FALSE)
				return (FALSE);
		}
	}
	return (TRUE);
}

/*
 * Move the cursor forward by
 * the specified number of words. As you move
 * convert the first character of the word to upper
 * case, and subsequent characters to lower case. Error
 * if you try and move past the end of the buffer.
 */
capword(f, n, k)
{
	register int	c;

	if (n < 0)
		return (FALSE);
	while (n--) {
		while (inword() == FALSE) {
			if (forwchar(FALSE, 1, KRANDOM) == FALSE)
				return (FALSE);
		}
		if (inword() != FALSE) {
			c = lgetc(curwp->w_dotp, curwp->w_doto);
			if (ISLOWER(c) != FALSE) {
				c = TOUPPER(c);
				lputc(curwp->w_dotp, curwp->w_doto, c);
				lchange(WFHARD);
			}
			if (forwchar(FALSE, 1, KRANDOM) == FALSE)
				return (FALSE);
			while (inword() != FALSE) {
				c = lgetc(curwp->w_dotp, curwp->w_doto);
				if (ISUPPER(c) != FALSE) {
					c = TOLOWER(c);
					lputc(curwp->w_dotp, curwp->w_doto, c);
					lchange(WFHARD);
				}
				if (forwchar(FALSE, 1, KRANDOM) == FALSE)
					return (FALSE);
			}
		}
	}
	return (TRUE);
}

/*
 * Kill forward by "n" words. The rules for final
 * status are now different. It is not considered an error
 * to delete fewer words than you asked. This lets you say
 * "kill lots of words" and have the command stop in a reasonable
 * way when it hits the end of the buffer. Normally this is
 */
delfword(f, n, k)
{
	register int	size;
	register LINE	*dotp;
	register int	doto;

	if (n < 0)
		return (FALSE);
	if ((lastflag&CFKILL) == 0)		/* Purge kill buffer.	*/
		kdelete();
	thisflag |= CFKILL;
	dotp = curwp->w_dotp;
	doto = curwp->w_doto;
	size = 0;
	while (n--) {
		while (inword() == FALSE) {
			if (forwchar(FALSE, 1, KRANDOM) == FALSE)
				goto out;	/* Hit end of buffer.	*/
			++size;
		}
		while (inword() != FALSE) {
			if (forwchar(FALSE, 1, KRANDOM) == FALSE)
				goto out;	/* Hit end of buffer.	*/
			++size;
		}
	}
out:
	curwp->w_dotp = dotp;
	curwp->w_doto = doto;
	return (ldelete(size, TRUE));
}

/*
 * Kill backwards by "n" words. The rules
 * for success and failure are now different, to prevent
 * strange behavior at the start of the buffer. The command
 * only fails if something goes wrong with the actual delete
 * of the characters. It is successful even if no characters
 * are deleted, or if you say delete 5 words, and there are
 * only 4 words left. I considered making the first call
 * to "backchar" special, but decided that that would just
 * be wierd. Normally this is bound to "M-Rubout" and
 * to "M-Backspace".
 */
delbword(f, n, k)
{
	register int	size;

	if (n < 0)
		return (FALSE);
	if ((lastflag&CFKILL) == 0)		/* Purge kill buffer.	*/
		kdelete();
	thisflag |= CFKILL;
	if (backchar(FALSE, 1, KRANDOM) == FALSE)
		return (TRUE);			/* Hit buffer start.	*/
	size = 1;				/* One deleted.		*/
	while (n--) {
		while (inword() == FALSE) {
			if (backchar(FALSE, 1, KRANDOM) == FALSE)
				goto out;	/* Hit buffer start.	*/
			++size;
		}
		while (inword() != FALSE) {
			if (backchar(FALSE, 1, KRANDOM) == FALSE)
				goto out;	/* Hit buffer start.	*/
			++size;
		}
	}
	if (forwchar(FALSE, 1, KRANDOM) == FALSE)
		return (FALSE);
	--size;					/* Undo assumed delete.	*/
out:
	return (ldelete(size, TRUE));
}

/*
 * Return TRUE if the character at dot
 * is a character that is considered to be
 * part of a word. The word character list is hard
 * coded. Should be setable.
 */
inword()
{
	if (curwp->w_doto == llength(curwp->w_dotp))
		return (FALSE);
	if (ISWORD(lgetc(curwp->w_dotp, curwp->w_doto)) != FALSE)
		return (TRUE);
	return (FALSE);
}
/*
 * Name:	MicroEMACS
 *		Region based commands.
 * Version:	29
 * Last edit:	12-Feb-86
 * By:		rex::conroy
 *		decvax!decwrl!dec-rhea!dec-rex!conroy
 * What:	Region operations.
 *
 * The routines in this file
 * deal with the region, that magic space
 * between "." and mark. Some functions are
 * commands. Some functions are just for
 * internal use.
 */

/*
 * Kill the region. Ask "getregion"
 * to figure out the bounds of the region.
 * Move "." to the start, and kill the characters.
 */
killregion(f, n, k)
{
	register int	s;
	REGION		region;

	if ((s=getregion(&region)) != TRUE)
		return (s);
	if ((lastflag&CFKILL) == 0)		/* This is a kill type	*/
		kdelete();			/* command, so do magic	*/
	thisflag |= CFKILL;			/* kill buffer stuff.	*/
	curwp->w_dotp = region.r_linep;
	curwp->w_doto = region.r_offset;
	return (ldelete(region.r_size, TRUE));
}

/*
 * Copy all of the characters in the
 * region to the kill buffer. Don't move dot
 * at all. This is a bit like a kill region followed
 * by a yank.
 */
copyregion(f, n, k)
{
	register LINE	*linep;
	register int	loffs;
	register int	s;
	REGION		region;

	if ((s=getregion(&region)) != TRUE)
		return (s);
	if ((lastflag&CFKILL) == 0)		/* Kill type command.	*/
		kdelete();
	thisflag |= CFKILL;
	linep = region.r_linep;			/* Current line.	*/
	loffs = region.r_offset;		/* Current offset.	*/
	while (region.r_size--) {
		if (loffs == llength(linep)) {	/* End of line.		*/
			if ((s=kinsert('\n')) != TRUE)
				return (s);
			linep = lforw(linep);
			loffs = 0;
		} else {			/* Middle of line.	*/
			if ((s=kinsert(lgetc(linep, loffs))) != TRUE)
				return (s);
			++loffs;
		}
	}
	return (TRUE);
}

/*
 * Lower case region. Zap all of the upper
 * case characters in the region to lower case. Use
 * the region code to set the limits. Scan the buffer,
 * doing the changes. Call "lchange" to ensure that
 * redisplay is done in all buffers. 
 */
lowerregion(f, n, k)
{
	register LINE	*linep;
	register int	loffs;
	register int	c;
	register int	s;
	REGION		region;

	if ((s=getregion(&region)) != TRUE)
		return (s);
	lchange(WFHARD);
	linep = region.r_linep;
	loffs = region.r_offset;
	while (region.r_size--) {
		if (loffs == llength(linep)) {
			linep = lforw(linep);
			loffs = 0;
		} else {
			c = lgetc(linep, loffs);
			if (ISUPPER(c) != FALSE)
				lputc(linep, loffs, TOLOWER(c));
			++loffs;
		}
	}
	return (TRUE);
}

/*
 * Upper case region. Zap all of the lower
 * case characters in the region to upper case. Use
 * the region code to set the limits. Scan the buffer,
 * doing the changes. Call "lchange" to ensure that
 * redisplay is done in all buffers. 
 */
upperregion(f, n, k)
{
	register LINE	*linep;
	register int	loffs;
	register int	c;
	register int	s;
	REGION		region;

	if ((s=getregion(&region)) != TRUE)
		return (s);
	lchange(WFHARD);
	linep = region.r_linep;
	loffs = region.r_offset;
	while (region.r_size--) {
		if (loffs == llength(linep)) {
			linep = lforw(linep);
			loffs = 0;
		} else {
			c = lgetc(linep, loffs);
			if (ISLOWER(c) != FALSE)
				lputc(linep, loffs, TOUPPER(c));
			++loffs;
		}
	}
	return (TRUE);
}

/*
 * This routine figures out the bound of the region
 * in the current window, and stores the results into the fields
 * of the REGION structure. Dot and mark are usually close together,
 * but I don't know the order, so I scan outward from dot, in both
 * directions, looking for mark. The size is kept in a long. At the
 * end, after the size is figured out, it is assigned to the size
 * field of the region structure. If this assignment loses any bits,
 * then we print an error. This is "type independent" overflow
 * checking. All of the callers of this routine should be ready to
 * get an ABORT status, because I might add a "if regions is big,
 * ask before clobberring" flag.
 */
getregion(rp)
register REGION	*rp;
{
	register LINE	*flp;
	register LINE	*blp;
	register long	fsize;			/* Long now.		*/
	register long	bsize;

	if (curwp->w_markp == NULL) {
		eprintf("No mark in this window");
		return (FALSE);
	}
	if (curwp->w_dotp == curwp->w_markp) {	/* "r_size" always ok.	*/
		rp->r_linep = curwp->w_dotp;
		if (curwp->w_doto < curwp->w_marko) {
			rp->r_offset = curwp->w_doto;
			rp->r_size = curwp->w_marko-curwp->w_doto;
		} else {
			rp->r_offset = curwp->w_marko;
			rp->r_size = curwp->w_doto-curwp->w_marko;
		}
		return (TRUE);
	}
	blp = curwp->w_dotp;			/* Get region size.	*/
	flp = curwp->w_dotp;
	bsize = curwp->w_doto;
	fsize = llength(flp)-curwp->w_doto+1;
	while (flp!=curbp->b_linep || lback(blp)!=curbp->b_linep) {
		if (flp != curbp->b_linep) {
			flp = lforw(flp);
			if (flp == curwp->w_markp) {
				rp->r_linep = curwp->w_dotp;
				rp->r_offset = curwp->w_doto;
				return (setsize(rp, fsize+curwp->w_marko));
			}
			fsize += llength(flp)+1;
		}
		if (lback(blp) != curbp->b_linep) {
			blp = lback(blp);
			bsize += llength(blp)+1;
			if (blp == curwp->w_markp) {
				rp->r_linep = blp;
				rp->r_offset = curwp->w_marko;
				return (setsize(rp, bsize-curwp->w_marko));
			}
		}
	}
	eprintf("Bug: lost mark");		/* Gak!			*/
	return (FALSE);
}

/*
 * Set size, and check for overflow.
 */
setsize(rp, size)
register REGION	*rp;
register long	size;
{
	rp->r_size = size;
	if (rp->r_size != size) {
		eprintf("Region is too large");
		return (FALSE);
	}
	return (TRUE);
}
/*
 * Name:	MicroEMACS
 *		Basic cursor motion commands.
 * Version:	29
 * Last edit:	05-Feb-86
 * By:		rex::conroy
 *		decvax!decwrl!dec-rhea!dec-rex!conroy
 *
 * The routines in this file are the basic
 * command functions for moving the cursor around on
 * the screen, setting mark, and swapping dot with
 * mark. Only moves between lines, which might make the
 * current buffer framing bad, are hard.
 */

/*
 * Go to beginning of line.
 */
gotobol(f, n, k)
{
	curwp->w_doto  = 0;
	return (TRUE);
}

/*
 * Move cursor backwards. Do the
 * right thing if the count is less than
 * 0. Error if you try to move back from
 * the beginning of the buffer.
 */
backchar(f, n, k)
register int	n;
{
	register LINE	*lp;

	if (n < 0)
		return (forwchar(f, -n, KRANDOM));
	while (n--) {
		if (curwp->w_doto == 0) {
			if ((lp=lback(curwp->w_dotp)) == curbp->b_linep)
				return (FALSE);
			curwp->w_dotp  = lp;
			curwp->w_doto  = llength(lp);
			curwp->w_flag |= WFMOVE;
		} else
			curwp->w_doto--;
	}
	return (TRUE);
}

/*
 * Go to end of line.
 */
gotoeol(f, n, k)
{
	curwp->w_doto  = llength(curwp->w_dotp);
	return (TRUE);
}

/*
 * Move cursor forwards. Do the
 * right thing if the count is less than
 * 0. Error if you try to move forward
 * from the end of the buffer.
 */
forwchar(f, n, k)
register int	n;
{
	if (n < 0)
		return (backchar(f, -n, KRANDOM));
	while (n--) {
		if (curwp->w_doto == llength(curwp->w_dotp)) {
			if (curwp->w_dotp == curbp->b_linep)
				return (FALSE);
			curwp->w_dotp  = lforw(curwp->w_dotp);
			curwp->w_doto  = 0;
			curwp->w_flag |= WFMOVE;
		} else
			curwp->w_doto++;
	}
	return (TRUE);
}

/*
 * Go to the beginning of the
 * buffer. Setting WFHARD is conservative,
 * but almost always the case.
 */
gotobob(f, n, k)
{
	curwp->w_dotp  = lforw(curbp->b_linep);
	curwp->w_doto  = 0;
	curwp->w_flag |= WFHARD;
	return (TRUE);
}

/*
 * Go to the end of the buffer.
 * Setting WFHARD is conservative, but
 * almost always the case.
 */
gotoeob(f, n, k)
{
	curwp->w_dotp  = curbp->b_linep;
	curwp->w_doto  = 0;
	curwp->w_flag |= WFHARD;
	return (TRUE);
}

/*
 * Move forward by full lines.
 * If the number of lines to move is less
 * than zero, call the backward line function to
 * actually do it. The last command controls how
 * the goal column is set.
 */
forwline(f, n, k)
{
	register LINE	*dlp;

	if (n < 0)
		return (backline(f, -n, KRANDOM));
	if ((lastflag&CFCPCN) == 0)		/* Fix goal.		*/
		setgoal();
	thisflag |= CFCPCN;
	dlp = curwp->w_dotp;
	while (n-- && dlp!=curbp->b_linep)
		dlp = lforw(dlp);
	curwp->w_dotp  = dlp;
	curwp->w_doto  = getgoal(dlp);
	curwp->w_flag |= WFMOVE;
	return (TRUE);
}

/*
 * This function is like "forwline", but
 * goes backwards. The scheme is exactly the same.
 * Check for arguments that are less than zero and
 * call your alternate. Figure out the new line and
 * call "movedot" to perform the motion.
 */
backline(f, n, k)
{
	register LINE	*dlp;

	if (n < 0)
		return (forwline(f, -n, KRANDOM));
	if ((lastflag&CFCPCN) == 0)		/* Fix goal.		*/
		setgoal();
	thisflag |= CFCPCN;
	dlp = curwp->w_dotp;
	while (n-- && lback(dlp)!=curbp->b_linep)
		dlp = lback(dlp);
	curwp->w_dotp  = dlp;
	curwp->w_doto  = getgoal(dlp);
	curwp->w_flag |= WFMOVE;
	return (TRUE);
}

/*
 * Set the current goal column,
 * which is saved in the external variable "curgoal",
 * to the current cursor column. The column is never off
 * the edge of the screen; it's more like display then
 * show position.
 */
setgoal()
{
	register int	c;
	register int	i;

	curgoal = 0;				/* Get the position.	*/
	for (i=0; i<curwp->w_doto; ++i) {
		c = lgetc(curwp->w_dotp, i);
		if (c == '\t')
			curgoal |= 0x07;
		else if (ISCTRL(c) != FALSE)
			++curgoal;
		++curgoal;
	}
	if (curgoal >= ncol)			/* Chop to tty width.	*/
		curgoal = ncol-1;
}

/*
 * This routine looks at a line (pointed
 * to by the LINE pointer "dlp") and the current
 * vertical motion goal column (set by the "setgoal"
 * routine above) and returns the best offset to use
 * when a vertical motion is made into the line.
 */
getgoal(dlp)
register LINE	*dlp;
{
	register int	c;
	register int	col;
	register int	newcol;
	register int	dbo;

	col = 0;
	dbo = 0;
	while (dbo != llength(dlp)) {
		c = lgetc(dlp, dbo);
		newcol = col;
		if (c == '\t')
			newcol |= 0x07;
		else if (ISCTRL(c) != FALSE)
			++newcol;
		++newcol;
		if (newcol > curgoal)
			break;
		col = newcol;
		++dbo;
	}
	return (dbo);
}

/*
 * Scroll forward by a specified number
 * of lines, or by a full page if no argument.
 * The "2" is the window overlap (this is the default
 * value from ITS EMACS). Because the top line in
 * the window is zapped, we have to do a hard
 * update and get it back.
 */
forwpage(f, n, k)
register int	n;
{
	register LINE	*lp;

	if (f == FALSE) {
		n = curwp->w_ntrows - 2;	/* Default scroll.	*/
		if (n <= 0)			/* Forget the overlap	*/
			n = 1;			/* if tiny window.	*/
	} else if (n < 0)
		return (backpage(f, -n, KRANDOM));
#if	CVMVAS
	else					/* Convert from pages	*/
		n *= curwp->w_ntrows;		/* to lines.		*/
#endif
	lp = curwp->w_linep;
	while (n-- && lp!=curbp->b_linep)
		lp = lforw(lp);
	curwp->w_linep = lp;
	curwp->w_dotp  = lp;
	curwp->w_doto  = 0;
	curwp->w_flag |= WFHARD;
	return (TRUE);
}

/*
 * This command is like "forwpage",
 * but it goes backwards. The "2", like above,
 * is the overlap between the two windows. The
 * value is from the ITS EMACS manual. The
 * hard update is done because the top line in
 * the window is zapped.
 */
backpage(f, n, k)
register int	n;
{
	register LINE	*lp;

	if (f == FALSE) {
		n = curwp->w_ntrows - 2;	/* Default scroll.	*/
		if (n <= 0)			/* Don't blow up if the	*/
			n = 1;			/* window is tiny.	*/
	} else if (n < 0)
		return (forwpage(f, -n, KRANDOM));
#if	CVMVAS
	else					/* Convert from pages	*/
		n *= curwp->w_ntrows;		/* to lines.		*/
#endif
	lp = curwp->w_linep;
	while (n-- && lback(lp)!=curbp->b_linep)
		lp = lback(lp);
	curwp->w_linep = lp;
	curwp->w_dotp  = lp;
	curwp->w_doto  = 0;
	curwp->w_flag |= WFHARD;
	return (TRUE);
}

/*
 * Set the mark in the current window
 * to the value of dot. A message is written to
 * the echo line unless we are running in a keyboard
 * macro, when it would be silly.
 */
setmark(f, n, k)
{
	curwp->w_markp = curwp->w_dotp;
	curwp->w_marko = curwp->w_doto;
	if (kbdmop == NULL)
		eprintf("[Mark set]");
	return (TRUE);
}

/*
 * Swap the values of "dot" and "mark" in
 * the current window. This is pretty easy, because
 * all of the hard work gets done by the standard routine
 * that moves the mark about. The only possible
 * error is "no mark".
 */
swapmark(f, n, k)
{
	register LINE	*odotp;
	register int	odoto;

	if (curwp->w_markp == NULL) {
		eprintf("No mark in this window");
		return (FALSE);
	}
	odotp = curwp->w_dotp;
	odoto = curwp->w_doto;
	curwp->w_dotp  = curwp->w_markp;
	curwp->w_doto  = curwp->w_marko;
	curwp->w_markp = odotp;
	curwp->w_marko = odoto;
	curwp->w_flag |= WFMOVE;
	return (TRUE);
}

/*
 * Go to a specific line, mostly for
 * looking up errors in C programs, which give the
 * error a line number. If an argument is present, then
 * it is the line number, else prompt for a line number
 * to use.
 */
gotoline(f, n, k)
register int	n;
{
	register LINE	*clp;
	register int	s;
	char		buf[32];

	if (f == FALSE) {
		if ((s=ereply("Goto line: ", buf, sizeof(buf))) != TRUE)
			return (s);
		n = atoi(buf);
	}
	if (n <= 0) {
		eprintf("Bad line");
		return (FALSE);
	}
	clp = lforw(curbp->b_linep);		/* "clp" is first line	*/
	while (n != 1) {
		if (clp == curbp->b_linep) {
			eprintf("Line number too large");
			return (FALSE);
		}
		clp = lforw(clp);
		--n;
	}
	curwp->w_dotp = clp;
	curwp->w_doto = 0;
	curwp->w_flag |= WFMOVE;
	return (TRUE);
}
/*
 * Name:	MicroEMACS
 * 		Search commands.
 * Version:	30
 * Last edit:	14-Feb-86
 * By:		rex::conroy, rex::ellison
 *		decvax!decwrl!dec-rhea!dec-rex!conroy
 *		                   ...!dec-vox!ellison
 *
 * The functions in this file implement the
 * search commands (both plain and incremental searches
 * are supported) and the query-replace command.
 *
 * The plain old search code is part of the original
 * MicroEMACS "distribution". The incremental search code,
 * and the query-replace code, is by Rich Ellison.
 */

#define CCHR(x)		((x)-'@')

#define SRCH_BEGIN	(0)			/* Search sub-codes.	*/
#define	SRCH_FORW	(-1)
#define SRCH_BACK	(-2)
#define SRCH_PREV	(-3)
#define SRCH_NEXT	(-4)
#define SRCH_NOPR	(-5)
#define SRCH_ACCM	(-6)

typedef struct  {
	int	s_code;
	LINE	*s_dotp;
	int	s_doto;
}	SRCHCOM;

static	SRCHCOM	cmds[NSRCH];
static	int	cip;

int	srch_lastdir = SRCH_NOPR;		/* Last search flags.	*/

/*
 * Search forward.
 * Get a search string from the user, and search for it,
 * starting at ".". If found, "." gets moved to just after the
 * matched characters, and display does all the hard stuff.
 * If not found, it just prints a message.
 */
forwsearch(f, n, k)
{
	register int	s;

	if ((s=readpattern("Search")) != TRUE)
		return (s);
	if (forwsrch() == FALSE) {
		eprintf("Not found");
		return (FALSE);
	}
	srch_lastdir = SRCH_FORW;
	return (TRUE);
}

/*
 * Reverse search.
 * Get a search string from the  user, and search, starting at "."
 * and proceeding toward the front of the buffer. If found "." is left
 * pointing at the first character of the pattern [the last character that
 * was matched].
 */
backsearch(f, n, k)
{
	register int	s;

	if ((s=readpattern("Reverse search")) != TRUE)
		return (s);
	if (backsrch() == FALSE) {
		eprintf("Not found");
		return (FALSE);
	}
	srch_lastdir = SRCH_BACK;
	return (TRUE);
}

/* 
 * Search again, using the same search string
 * and direction as the last search command. The direction
 * has been saved in "srch_lastdir", so you know which way
 * to go.
 */
searchagain(f, n, k)
{
	if (srch_lastdir == SRCH_FORW) {
		if (forwsrch() == FALSE) {
			eprintf("Not found");
			return (FALSE);
		}
		return (TRUE);
	}
	if (srch_lastdir == SRCH_BACK) {
		if (backsrch() == FALSE) {
			eprintf("Not found");
			return (FALSE);
		}
		return (TRUE);
	}
	eprintf("No last search");
	return (FALSE);
}

/*
 * Use incremental searching, initially in the forward direction.
 * isearch ignores any explicit arguments.
 */
forwisearch(f, n, k)
{
	return (isearch(SRCH_FORW));
}

/*
 * Use incremental searching, initially in the reverse direction.
 * isearch ignores any explicit arguments.
 */
backisearch(f, n, k)
{
	return (isearch(SRCH_BACK));
}

/*
 * Incremental Search.
 *	dir is used as the initial direction to search.
 *	^N	find next occurance  (if first thing typed reuse old string).
 *	^P	find prev occurance  (if first thing typed reuse old string).
 *	^S	switch direction to forward, find next
 *	^R	switch direction to reverse, find prev
 *	^Q	quote next character (allows searching for ^N etc.)
 *	<ESC>	exit from Isearch.
 *	<DEL>	undoes last character typed. (tricky job to do this correctly).
 *	else	accumulate into search string
 */
isearch(dir)
{
	register int	c;
	register LINE	*clp;
	register int	cbo;
	register int	success;
	int		pptr;

	for (cip=0; cip<NSRCH; cip++)
		cmds[cip].s_code = SRCH_NOPR;
	cip = 0;
	pptr = -1;
	clp = curwp->w_dotp;
	cbo = curwp->w_doto;
	is_lpush();
	is_cpush(SRCH_BEGIN);
	success = TRUE;
	is_prompt(dir, TRUE, success);
	for (;;) {
		update();
		switch (c = ttgetc()) {
		case CCHR('M'):
		case METACH:
			srch_lastdir = dir;
			eprintf("[Done]");
			return (TRUE);

		case CCHR('G'):
			curwp->w_dotp = clp;
			curwp->w_doto = cbo;
			curwp->w_flag |= WFMOVE;
			srch_lastdir = dir;
			ctrlg(FALSE, 0, KRANDOM);
			return (FALSE);

		case CCHR('S'):
		case CCHR('F'):
			if (dir == SRCH_BACK) {
				dir = SRCH_FORW;
				is_lpush();
				is_cpush(SRCH_FORW);
				success = TRUE;
			}
			/* Drop through to find next. */
		case CCHR('N'):
			if (success==FALSE && dir==SRCH_FORW)
				break;
			is_lpush();
			forwchar(FALSE, 1, KRANDOM);
			if (is_find(SRCH_NEXT) != FALSE) {
				is_cpush(SRCH_NEXT);
				pptr = strlen(pat);
			} else {
				backchar(FALSE, 1, KRANDOM);
				ttbeep();
				success = FALSE;
			}
			is_prompt(dir, FALSE, success);
			break;

		case CCHR('R'):
		case CCHR('B'):
			if (dir == SRCH_FORW) {
				dir = SRCH_BACK;
				is_lpush();
				is_cpush(SRCH_BACK);
				success = TRUE;
			}
			/* Drop through to find previous. */
		case CCHR('P'):
			if (success==FALSE && dir==SRCH_BACK)
				break;
			is_lpush();
			backchar(FALSE, 1, KRANDOM);
			if (is_find(SRCH_PREV) != FALSE) {
				is_cpush(SRCH_PREV);
				pptr = strlen(pat);
			} else {
				forwchar(FALSE, 1, KRANDOM);
				ttbeep();
				success = FALSE;
			}
			is_prompt(dir,FALSE,success);
			break;

		case 0x7F:
			if (is_undo(&pptr, &dir) != TRUE)
				return (ABORT);
			if (is_peek() != SRCH_ACCM)
				success = TRUE;
			is_prompt(dir, FALSE, success);
			break;

		case CCHR('^'):
		case CCHR('Q'):
			c = ttgetc();
		case CCHR('U'):
		case CCHR('X'):
		case CCHR('J'):
			goto  addchar;

		default:
			if (ISCTRL(c) != FALSE) {
				c += '@';
				c |= KCTRL;
				success = execute(c, FALSE, 1);
				curwp->w_flag |= WFMOVE;
				return (success);
			}				
		addchar:
			if (pptr == -1)
				pptr = 0;
			if (pptr == 0)
				success = TRUE;
			pat[pptr++] = c;
			if (pptr == NPAT) {
				eprintf("Pattern too long");
				ctrlg(FALSE, 0, KRANDOM);
				return (ABORT);
			}
			pat[pptr] = '\0';
			is_lpush();
			if (success != FALSE) {
				if (is_find(dir) != FALSE)
					is_cpush(c);
				else {
					success = FALSE;
					ttbeep();
					is_cpush(SRCH_ACCM);
				}
			} else
				is_cpush(SRCH_ACCM);
			is_prompt(dir, FALSE, success);
		}
	}
}

is_cpush(cmd)
register int	cmd;
{
	if (++cip >= NSRCH)
		cip = 0;
	cmds[cip].s_code = cmd;
}

is_lpush()
{
	register int	ctp;

	ctp = cip+1;
	if (ctp >= NSRCH)
		ctp = 0;
	cmds[ctp].s_code = SRCH_NOPR;
	cmds[ctp].s_doto = curwp->w_doto;
	cmds[ctp].s_dotp = curwp->w_dotp;
}

is_pop()
{
	if (cmds[cip].s_code != SRCH_NOPR) {
		curwp->w_doto  = cmds[cip].s_doto; 
		curwp->w_dotp  = cmds[cip].s_dotp;
		curwp->w_flag |= WFMOVE;
		cmds[cip].s_code = SRCH_NOPR;
	}
	if (--cip <= 0)
		cip = NSRCH-1;
}

is_peek()	
{
	if (cip == 0)
		return (cmds[NSRCH-1].s_code);
	else
		return (cmds[cip-1].s_code);
}

is_undo(pptr, dir)
register int	*pptr;
register int	*dir;
{
	switch (cmds[cip].s_code) {
	case SRCH_NOPR:
	case SRCH_BEGIN:
	case SRCH_NEXT:
	case SRCH_PREV:
		break;

	case SRCH_FORW:
		*dir = SRCH_BACK;
		break;

	case SRCH_BACK:
		*dir = SRCH_FORW;
		break;

	case SRCH_ACCM:
	default:
		*pptr -= 1;
		if (*pptr < 0)
			*pptr = 0;
		pat[*pptr] = '\0';
		break;
	}
	is_pop();
	return (TRUE);
}

is_find(dir)
register int	dir;
{
	register int	plen;

	plen = strlen(pat);
	if (plen != 0) {
		if (dir==SRCH_FORW || dir==SRCH_NEXT) {
			backchar(FALSE, plen, KRANDOM);
			if (forwsrch() == FALSE) {
				forwchar(FALSE, plen, KRANDOM);
				return (FALSE);
			}
			return (TRUE);
		}
		if (dir==SRCH_BACK || dir==SRCH_PREV) {
			forwchar(FALSE, plen, KRANDOM);
			if (backsrch() == FALSE) {
				backchar(FALSE, plen, KRANDOM);
				return (FALSE);
			}
			return (TRUE);
		}
		eprintf("bad call to is_find");
		ctrlg(FALSE, 0, KRANDOM);
		return (FALSE);
	}
	return (FALSE);
}

/*
 * If called with "dir" not one of SRCH_FORW
 * or SRCH_BACK, this routine used to print an error
 * message. It also used to return TRUE or FALSE,
 * depending on if it liked the "dir". However, none
 * of the callers looked at the status, so I just
 * made the checking vanish.
 */
is_prompt(dir, flag, success)
{
	if (dir == SRCH_FORW) {
		if (success != FALSE)
			is_dspl("i-search forward", flag);
		else
			is_dspl("failing i-search forward", flag);
	} else if (dir == SRCH_BACK) {
		if (success != FALSE)
			is_dspl("i-search backward", flag);
		else
			is_dspl("failing i-search backward", flag);
	}
}

/*
 * Prompt writing routine for the incremental search. 
 * The "prompt" is just a string. The "flag" determines
 * if a "[ ]" or ":" embelishment is used.
 */
is_dspl(prompt, flag)
char	*prompt;
{
	if (flag != FALSE)
		eprintf("%s [%s]", prompt, pat);
	else
		eprintf("%s: %s", prompt, pat);
}

/*
 * Query Replace.
 *	Replace strings selectively.  Does a search and replace operation.
 *	A space or a comma replaces the string, a period replaces and quits,
 *	an n doesn't replace, a C-G quits.
 */
queryrepl(f, n, k)
{
	register int	s;
	char		news[NPAT];	/* replacement string		*/
	register int	kludge;		/* Watch for saved line move	*/
	LINE		*clp;		/* saved line pointer		*/
	int		cbo;		/* offset into the saved line	*/
	int		rcnt = 0;	/* Replacements made so far	*/
	int		plen;		/* length of found string	*/

	if ((s=readpattern("Old string")) != TRUE)
		return (s);
	if ((s=ereply("New string: ",news, NPAT)) == ABORT)
		return (s);
	if (s == FALSE)
		news[0] = '\0';
	eprintf("Query Replace:  [%s] -> [%s]", pat, news);
	plen = strlen(pat);

	/*
	 * Search forward repeatedly, checking each time whether to insert
	 * or not.  The "!" case makes the check always true, so it gets put
	 * into a tighter loop for efficiency.
	 *
	 * If we change the line that is the remembered value of dot, then
	 * it is possible for the remembered value to move.  This causes great
	 * pain when trying to return to the non-existant line.
	 *
	 * possible fixes:
	 * 1) put a single, relocated marker in the WINDOW structure, handled
	 *    like mark.  The problem now becomes a what if two are needed...
	 * 2) link markers into a list that gets updated (auto structures for
	 *    the nodes)
	 * 3) Expand the mark into a stack of marks and add pushmark, popmark.
	 */

	clp = curwp->w_dotp;		/* save the return location	*/
	cbo = curwp->w_doto;
	while (forwsrch() == TRUE) {
	retry:
		update();
		switch (ttgetc()) {
		case ' ':
		case ',':
			kludge = (curwp->w_dotp == clp);
			if (lreplace(plen, news, f) == FALSE)
				return (FALSE);
			rcnt++;
			if (kludge != FALSE)
				clp = curwp->w_dotp;
			break;

		case '.':
			kludge = (curwp->w_dotp == clp);
			if (lreplace(plen, news, f) == FALSE)
				return (FALSE);
			rcnt++;
			if (kludge != FALSE)
				clp = curwp->w_dotp;
			goto stopsearch;

		case CCHR('G'):
			ctrlg(FALSE, 0, KRANDOM);
			goto stopsearch;

		case '!':
			do {
				kludge = (curwp->w_dotp == clp);
				if (lreplace(plen, news, f) == FALSE)
					return (FALSE);
				rcnt++;
				if (kludge != FALSE)
					clp = curwp->w_dotp;
			} while (forwsrch() == TRUE);
			goto stopsearch;

		case 'n':
			break;

		default:
eprintf("<SP>[,] replace, [.] rep-end, [n] don't, [!] repl rest [C-G] quit");
			goto retry;
		}
	}
stopsearch:
	curwp->w_dotp = clp;
	curwp->w_doto = cbo;
	curwp->w_flag |= WFHARD;
	update();
	if (rcnt == 0)
		eprintf("[No replacements done]");
	else if (rcnt == 1)
		eprintf("[1 replacement done]");
	else
		eprintf("[%d replacements done]", rcnt);
	return (TRUE);
}

/*
 * This routine does the real work of a
 * forward search. The pattern is sitting in the external
 * variable "pat". If found, dot is updated, the window system
 * is notified of the change, and TRUE is returned. If the
 * string isn't found, FALSE is returned.
 */
forwsrch()
{
	register LINE	*clp;
	register int	cbo;
	register LINE	*tlp;
	register int	tbo;
	register char	*pp;
	register int	c;

	clp = curwp->w_dotp;
	cbo = curwp->w_doto;
	while (clp != curbp->b_linep) {
		if (cbo == llength(clp)) {
			clp = lforw(clp);
			cbo = 0;
			c = '\n';
		} else
			c = lgetc(clp, cbo++);
		if (eq(c, pat[0]) != FALSE) {
			tlp = clp;
			tbo = cbo;
			pp  = &pat[1];
			while (*pp != 0) {
				if (tlp == curbp->b_linep)
					goto fail;
				if (tbo == llength(tlp)) {
					tlp = lforw(tlp);
					if (tlp == curbp->b_linep)
						goto fail;
					tbo = 0;
					c = '\n';
				} else
					c = lgetc(tlp, tbo++);
				if (eq(c, *pp++) == FALSE)
					goto fail;
			}
			curwp->w_dotp  = tlp;
			curwp->w_doto  = tbo;
			curwp->w_flag |= WFMOVE;
			return (TRUE);
		}
	fail:	;
	}
	return (FALSE);
}

/*
 * This routine does the real work of a
 * backward search. The pattern is sitting in the external
 * variable "pat". If found, dot is updated, the window system
 * is notified of the change, and TRUE is returned. If the
 * string isn't found, FALSE is returned.
 */
backsrch()
{
	register LINE	*clp;
	register int	cbo;
	register LINE	*tlp;
	register int	tbo;
	register int	c;
	register char	*epp;
	register char	*pp;

	for (epp = &pat[0]; epp[1] != 0; ++epp)
		;
	clp = curwp->w_dotp;
	cbo = curwp->w_doto;
	for (;;) {
		if (cbo == 0) {
			clp = lback(clp);
			if (clp == curbp->b_linep)
				return (FALSE);
			cbo = llength(clp)+1;
		}
		if (--cbo == llength(clp))
			c = '\n';
		else
			c = lgetc(clp,cbo);
		if (eq(c, *epp) != FALSE) {
			tlp = clp;
			tbo = cbo;
			pp  = epp;
			while (pp != &pat[0]) {
				if (tbo == 0) {
					tlp = lback(tlp);
					if (tlp == curbp->b_linep)
						goto fail;
					tbo = llength(tlp)+1;
				}
				if (--tbo == llength(tlp))
					c = '\n';
				else
					c = lgetc(tlp,tbo);
				if (eq(c, *--pp) == FALSE)
					goto fail;
			}
			curwp->w_dotp  = tlp;
			curwp->w_doto  = tbo;
			curwp->w_flag |= WFMOVE;
			return (TRUE);
		}
	fail:	;
	}
}

/*
 * Compare two characters.
 * The "bc" comes from the buffer.
 * It has its case folded out. The
 * "pc" is from the pattern.
 */
eq(bc, pc)
{
	register int	ibc;
	register int	ipc;

	ibc = bc & 0xFF;
	ipc = pc & 0xFF;
	if (ISLOWER(ibc) != FALSE)
		ibc = TOUPPER(ibc);
	if (ISLOWER(ipc) != FALSE)
		ipc = TOUPPER(ipc);
	if (ibc == ipc)
		return (TRUE);
	return (FALSE);
}

/*
 * Read a pattern.
 * Stash it in the external variable "pat". The "pat" is
 * not updated if the user types in an empty line. If the user typed
 * an empty line, and there is no old pattern, it is an error.
 * Display the old pattern, in the style of Jeff Lomicka. There is
 * some do-it-yourself control expansion.
 */
readpattern(prompt)
char	*prompt;
{
	register int	s;
	char		tpat[NPAT];

	s = ereply("%s [%s]: ", tpat, NPAT, prompt, pat);
	if (s == TRUE)				/* Specified		*/
		strcpy(pat, tpat);
	else if (s==FALSE && pat[0]!=0)		/* CR, but old one	*/
		s = TRUE;
	return (s);
}
/*
 * Name:	MicroEMACS
 *		Terminal independent keyboard handling.
 * Version:	29
 * Last edit:	05-Feb-86
 * By:		rex::conroy
 *		decvax!decwrl!dec-rhea!dec-rex!conroy
 */

/*
 * Read in a key, doing the terminal
 * independent prefix handling. The terminal specific
 * "getkbd" routine gets the first swing, and may return
 * one of the special codes used by the special keys
 * on the keyboard. The "getkbd" routine returns the
 * C0 controls as received; this routine moves them to
 * the right spot in 11 bit code.
 */
getkey()
{
	register int	c;

	c = getkbd();
	if (c == METACH)			/* M-			*/
		c = KMETA | getctl();
	else if (c == CTRLCH)			/* C-			*/
		c = KCTRL | getctl();
	else if (c == CTMECH)			/* C-M-			*/
		c = KCTRL | KMETA | getctl();
	else if (c>=0x00 && c<=0x1F)		/* Relocate control.	*/
		c = KCTRL | (c+'@');
	if (c == (KCTRL|'X'))			/* C-X			*/
		c = KCTLX | getctl();
	return (c);
}

/*
 * Used above.
 */
getctl()
{
	register int	c;

	c = ttgetc();
	if (ISLOWER(c) != FALSE)
		c = TOUPPER(c);
	if (c>=0x00 && c<=0x1F)			/* Relocate control.	*/
		c = KCTRL | (c+'@');
	return (c);
}

/*
 * Transform a key code into a name,
 * using a table for the special keys and combination
 * of some hard code and some general processing for
 * the rest. None of this code is terminal specific any
 * more. This makes adding keys easier.
 */
keyname(cp, k)
register char	*cp;
register int	k;
{
	register char	*np;
	char		nbuf[3];

	static	char	hex[] = {
		'0',	'1',	'2',	'3',
		'4',	'5',	'6',	'7',
		'8',	'9',	'A',	'B',
		'C',	'D',	'E',	'F'
	};

	if ((k&KCTLX) != 0) {			/* C-X prefix.		*/
		*cp++ = 'C';
		*cp++ = '-';
		*cp++ = 'X';
		*cp++ = ' ';
		k &= ~KCTLX;
	}
	if ((k&KCHAR)>=KFIRST && (k&KCHAR)<=KLAST) {
		if ((np=keystrings[(k&KCHAR)-KFIRST]) != NULL) {
			if ((k&KCTRL) != 0) {
				*cp++ = 'C';
				*cp++ = '-';
			}
			if ((k&KMETA) != 0) {
				*cp++ = 'M';
				*cp++ = '-';
			}
			strcpy(cp, np);
			return;
		}
	}
	if ((k&~KMETA) == (KCTRL|'I'))		/* Some specials.	*/
		np = "Tab";
	else if ((k&~KMETA) == (KCTRL|'M'))
		np = "Return";
	else if ((k&~KMETA) == (KCTRL|'H'))
		np = "Backspace";
	else if ((k&~KMETA) == ' ')
		np = "Space";
	else if ((k&~KMETA) == 0x7F)
		np = "Rubout";
	else {
		if ((k&KCTRL) != 0) {		/* Add C- mark.		*/
			*cp++ = 'C';
			*cp++ = '-';
		}
		np = &nbuf[0];
		if (((k&KCHAR)>=0x20 && (k&KCHAR)<=0x7E)
		||  ((k&KCHAR)>=0xA0 && (k&KCHAR)<=0xFE)) {
			nbuf[0] = k&KCHAR;	/* Graphic.		*/
			nbuf[1] = 0;
		} else {			/* Non graphic.		*/
			nbuf[0] = hex[(k>>4)&0x0F];
			nbuf[1] = hex[k&0x0F];
			nbuf[2] = 0;
		}
	}
	if ((k&KMETA) != 0) {			/* Add M- mark.		*/
		*cp++ = 'M';
		*cp++ = '-';
	}
	strcpy(cp, np);
}
/*
 * Name:	MicroEMACS
 *		Extended (M-X) commands.
 * Version:	29
 * Last edit:	14-Feb-86
 * By:		rex::conroy
 *		decvax!decwrl!dec-rhea!dec-rex!conroy
 */

/*
 * This function modifies the keyboard
 * binding table, by adjusting the entries in the
 * big "bindings" array. Most of the grief deals with the
 * prompting for additional arguments. This code does not
 * work right if there is a keyboard macro floating around.
 * Should be fixed.
 */
bindtokey(f, n, k)
{
	register int	s;
	register char	*cp;
	register SYMBOL	*sp;
	register int	c;
	char		xname[NXNAME];

	if (kbdmip!=NULL || kbdmop!=NULL) {
		eprintf("Not now");
		return (FALSE);
	}
	if ((s=eread("Function: ", xname, NXNAME, EFAUTO, NULL)) != TRUE)
		return (s);
	if ((sp=symlookup(xname)) == NULL) {
		eprintf("Unknown function for binding");
		return (FALSE);
	}
	eputc(' ');
	eputc('K');
	eputc('e');
	eputc('y');
	eputc(':');
	eputc(' ');
	ttflush();
	c = getkey();				/* Read key.		*/
	keyname(xname, c);			/* Display keyname.	*/
	eputs(xname);
	ttflush();
	if (binding[c] != NULL)			/* Unbind old, and	*/
		--binding[c]->s_nkey;
	binding[c] = sp;			/* rebind new.		*/
	++sp->s_nkey;
	return (TRUE);
}
 
/*
 * Extended command. Call the message line
 * routine to read in the command name and apply autocompletion
 * to it. When it comes back, look the name up in the symbol table
 * and run the command if it is found and has the right type.
 * Print an error if there is anything wrong.
 */
extend(f, n, k)
{
	register SYMBOL	*sp;
	register int	s;
	char		xname[NXNAME];

	if ((s=eread(": ", xname, NXNAME, EFNEW|EFAUTO, NULL)) != TRUE)
		return (s);
	if ((sp=symlookup(xname)) != NULL)
		return ((*sp->s_funcp)(f, n, KRANDOM));
	eprintf("Unknown extended command");
	return (ABORT);
}

/*
 * Read a key from the keyboard, and look it
 * up in the binding table. Display the name of the function
 * currently bound to the key. Say that the key is not bound
 * if it is indeed not bound, or if the type is not a
 * "builtin". This is a bit of overkill, because this is the
 * only kind of function there is.
 */
help(f, n, k)
{
	register SYMBOL	*sp;
	register int	c;
	char		b[20];

	c = getkey();
	keyname(b, c);
	if ((sp=binding[c]) == NULL)
		eprintf("[%s is unbound]", b);
	else
		eprintf("[%s is bound to %s]", b, sp->s_name);
	return (TRUE);
}

/*
 * This function creates a table, listing all
 * of the command keys and their current bindings, and stores
 * the table in the standard pop-op buffer (the one used by the
 * directory list command, the buffer list command, etc.). This
 * lets MicroEMACS produce it's own wall chart. The bindings to
 * "ins-self" are only displayed if there is an argument.
 */
wallchart(f, n, k)
{
	register int	s;
	register int	key;
	register SYMBOL	*sp;
	register char	*cp1;
	register char	*cp2;
	char		buf[64];

	if ((s=bclear(blistp)) != TRUE)		/* Clear it out.	*/
		return (s);
	(void) strcpy(blistp->b_fname, "");
	for (key=0; key<NKEYS; ++key) {		/* For all keys.	*/
		sp = binding[key];
		if (sp != NULL
		&& (f!=FALSE || strcmp(sp->s_name, "ins-self")!=0)) {
			keyname(buf, key);
			cp1 = &buf[0];		/* Find end.		*/
			while (*cp1 != 0)
				++cp1;
			while (cp1 < &buf[16])	/* Goto column 16.	*/
				*cp1++ = ' ';				
			cp2 = sp->s_name;	/* Add function name.	*/
			while (*cp1++ = *cp2++)
				;
			if (addline(buf) == FALSE)
				return (FALSE);
		}
	}
	return (popblist());
}
/*
 * Name:	MicroEMACS
 *		Gosling style redisplay.
 * Version:	30
 * Last edit:	10-Feb-86
 * By:		rex::conroy
 *		decvax!decwrl!dec-rhea!dec-rex!conroy
 *
 * The functions in this file handle redisplay. The
 * redisplay system knows almost nothing about the editing
 * process; the editing functions do, however, set some
 * hints to eliminate a lot of the grinding. There is more
 * that can be done; the "vtputc" interface is a real
 * pig. Two conditional compilation flags; the GOSLING
 * flag enables dynamic programming redisplay, using the
 * algorithm published by Jim Gosling in SIGOA. The MEMMAP
 * changes things around for memory mapped video. With
 * both off, the terminal is a VT52.
 */

/*
 * You can change these back to the types
 * implied by the name if you get tight for space. If you
 * make both of them "int" you get better code on the VAX.
 * They do nothing if this is not Gosling redisplay, except
 * for change the size of a structure that isn't used.
 * A bit of a cheat.
 */
#define	XCHAR	int
#define	XSHORT	int

/*
 * A video structure always holds
 * an array of characters whose length is equal to
 * the longest line possible. Only some of this is
 * used if "ncol" isn't the same as "NCOL".
 */
typedef	struct	{
	short	v_hash;			/* Hash code, for compares.	*/
	short	v_flag;			/* Flag word.			*/
	short	v_color;		/* Color of the line.		*/
	XSHORT	v_cost;			/* Cost of display.		*/
	char	v_text[NCOL];		/* The actual characters.	*/
}	VIDEO;

#define	VFCHG	0x0001			/* Changed.			*/
#define	VFHBAD	0x0002			/* Hash and cost are bad.	*/

/*
 * SCORE structures hold the optimal
 * trace trajectory, and the cost of redisplay, when
 * the dynamic programming redisplay code is used.
 * If no fancy redisplay, this isn't used. The trace index
 * fields can be "char", and the score a "short", but
 * this makes the code worse on the VAX.
 */
typedef	struct	{
	XCHAR	s_itrace;		/* "i" index for track back.	*/
	XCHAR	s_jtrace;		/* "j" index for trace back.	*/
	XSHORT	s_cost;			/* Display cost.		*/
}	SCORE;

int	sgarbf	= TRUE;			/* TRUE if screen is garbage.	*/
int	vtrow	= 0;			/* Virtual cursor row.		*/
int	vtcol	= 0;			/* Virtual cursor column.	*/
int	tthue	= CNONE;		/* Current color.		*/
int	ttrow	= HUGE;			/* Physical cursor row.		*/
int	ttcol	= HUGE;			/* Physical cursor column.	*/
int	tttop	= HUGE;			/* Top of scroll region.	*/
int	ttbot	= HUGE;			/* Bottom of scroll region.	*/

VIDEO	*vscreen[NROW-1];		/* Edge vector, virtual.	*/
VIDEO	*pscreen[NROW-1];		/* Edge vector, physical.	*/
VIDEO	video[2*(NROW-1)];		/* Actual screen data.		*/
VIDEO	blanks;				/* Blank line image.		*/

#if	GOSLING
/*
 * This matrix is written as an array because
 * we do funny things in the "setscores" routine, which
 * is very compute intensive, to make the subscripts go away.
 * It would be "SCORE	score[NROW][NROW]" in old speak.
 * Look at "setscores" to understand what is up.
 */
SCORE	score[NROW*NROW];
#endif

/*
 * Initialize the data structures used
 * by the display code. The edge vectors used
 * to access the screens are set up. The operating
 * system's terminal I/O channel is set up. Fill the
 * "blanks" array with ASCII blanks. The rest is done
 * at compile time. The original window is marked
 * as needing full update, and the physical screen
 * is marked as garbage, so all the right stuff happens
 * on the first call to redisplay.
 */
vtinit()
{
	register VIDEO	*vp;
	register int	i;

	ttopen();
	ttinit();
	vp = &video[0];
	for (i=0; i<NROW-1; ++i) {
		vscreen[i] = vp;
		++vp;
		pscreen[i] = vp;
		++vp;
	}
	blanks.v_color = CTEXT;
	for (i=0; i<NCOL; ++i)
		blanks.v_text[i] = ' ';
}

/*
 * Tidy up the virtual display system
 * in anticipation of a return back to the host
 * operating system. Right now all we do is position
 * the cursor to the last line, erase the line, and
 * close the terminal channel.
 */
vttidy()
{
	ttcolor(CTEXT);
	ttnowindow();				/* No scroll window.	*/
	ttmove(nrow-1, 0);			/* Echo line.		*/
	tteeol();
	tttidy();
	ttflush();
	ttclose();
}

/*
 * Move the virtual cursor to an origin
 * 0 spot on the virtual display screen. I could
 * store the column as a character pointer to the spot
 * on the line, which would make "vtputc" a little bit
 * more efficient. No checking for errors.
 */
vtmove(row, col)
{
	vtrow = row;
	vtcol = col;
}

/*
 * Write a character to the virtual display,
 * dealing with long lines and the display of unprintable
 * things like control characters. Also expand tabs every 8
 * columns. This code only puts printing characters into 
 * the virtual display image. Special care must be taken when
 * expanding tabs. On a screen whose width is not a multiple
 * of 8, it is possible for the virtual cursor to hit the
 * right margin before the next tab stop is reached. This
 * makes the tab code loop if you are not careful.
 * Three guesses how we found this.
 */
vtputc(c)
register int	c;
{
	register VIDEO	*vp;

	vp = vscreen[vtrow];
	if (vtcol >= ncol)
		vp->v_text[ncol-1] = '$';
	else if (c == '\t') {
		do {
			vtputc(' ');
		} while (vtcol<ncol && (vtcol&0x07)!=0);
	} else if (ISCTRL(c) != FALSE) {
		vtputc('^');
		vtputc(c ^ 0x40);
	} else
		vp->v_text[vtcol++] = c;		
}

/*
 * Erase from the end of the
 * software cursor to the end of the
 * line on which the software cursor is
 * located. The display routines will decide
 * if a hardware erase to end of line command
 * should be used to display this.
 */
vteeol()
{
	register VIDEO	*vp;

	vp = vscreen[vtrow];
	while (vtcol < ncol)
		vp->v_text[vtcol++] = ' ';
	if(vtrow==0){vp->v_text[ncol-3]='[';vp->v_text[ncol-2]='X';vp->v_text[ncol-1]=']';}
	else if(vtrow>=curwp->w_toprow&&vtrow<curwp->w_toprow+curwp->w_ntrows)
		vp->v_text[ncol-1]=(vtrow>=sb_top&&vtrow<=sb_bot)?'#':'.';
}

/*
 * Make sure that the display is
 * right. This is a three part process. First,
 * scan through all of the windows looking for dirty
 * ones. Check the framing, and refresh the screen.
 * Second, make sure that "currow" and "curcol" are
 * correct for the current window. Third, make the
 * virtual and physical screens the same.
 */
update()
{
	register LINE	*lp;
	register WINDOW	*wp;
	register VIDEO	*vp1;
	register VIDEO	*vp2;
	register int	i;
	register int	j;
	register int	c;
	register int	hflag;
	register int	currow;
	register int	curcol;
	register int	offs;
	register int	size;

	if (curmsgf!=FALSE || newmsgf!=FALSE) {
		wp = wheadp;
		while (wp != NULL) {
			wp->w_flag |= WFMODE;	/* Must do mode lines.	*/
			wp = wp->w_wndp;
		}
	}
	curmsgf = newmsgf;			/* Sync. up right now.	*/
	hflag = FALSE;				/* Not hard.		*/
	{int t=0,a=0,h;LINE*p;for(p=lforw(curbp->b_linep);p!=curbp->b_linep;p=lforw(p)){if(p==curwp->w_linep)a=t;t++;}
	h=curwp->w_ntrows;if(t<h)t=h;sb_top=curwp->w_toprow+a*h/t;sb_bot=sb_top+h*h/t;if(sb_bot>sb_top+h-1)sb_bot=sb_top+h-1;if(sb_bot<sb_top)sb_bot=sb_top;}
	wp = wheadp;
	while (wp != NULL) {
		if (wp->w_flag != 0) {		/* Need update.		*/
			if ((wp->w_flag&WFFORCE) == 0) {
				lp = wp->w_linep;
				for (i=0; i<wp->w_ntrows; ++i) {
					if (lp == wp->w_dotp)
						goto out;
					if (lp == wp->w_bufp->b_linep)
						break;
					lp = lforw(lp);
				}
			}
			i = wp->w_force;	/* Reframe this one.	*/
			if (i > 0) {
				--i;
				if (i >= wp->w_ntrows)
					i = wp->w_ntrows-1;
			} else if (i < 0) {
				i += wp->w_ntrows;
				if (i < 0)
					i = 0;
			} else
				i = wp->w_ntrows/2;
			lp = wp->w_dotp;
			while (i!=0 && lback(lp)!=wp->w_bufp->b_linep) {
				--i;
				lp = lback(lp);
			}
			wp->w_linep = lp;
			wp->w_flag |= WFHARD;	/* Force full.		*/
		out:
			lp = wp->w_linep;	/* Try reduced update.	*/
			i  = wp->w_toprow;
			if ((wp->w_flag&~WFMODE) == WFEDIT) {
				while (lp != wp->w_dotp) {
					++i;
					lp = lforw(lp);
				}
				vscreen[i]->v_color = CTEXT;
				vscreen[i]->v_flag |= (VFCHG|VFHBAD);
				vtmove(i, 0);
				for (j=0; j<llength(lp); ++j)
					vtputc(lgetc(lp, j));
				vteeol();
			} else if ((wp->w_flag&(WFEDIT|WFHARD)) != 0) {
				hflag = TRUE;
				while (i < wp->w_toprow+wp->w_ntrows) {
					vscreen[i]->v_color = CTEXT;
					vscreen[i]->v_flag |= (VFCHG|VFHBAD);
					vtmove(i, 0);
					if (lp != wp->w_bufp->b_linep) {
						for (j=0; j<llength(lp); ++j)
							vtputc(lgetc(lp, j));
						lp = lforw(lp);
					}
					vteeol();
					++i;
				}
			}
			if ((wp->w_flag&WFMODE) != 0)
				modeline(wp);
			wp->w_flag  = 0;
			wp->w_force = 0;
		}		
		wp = wp->w_wndp;
	}
	lp = curwp->w_linep;			/* Cursor location.	*/
	currow = curwp->w_toprow;
	while (lp != curwp->w_dotp) {
		++currow;
		lp = lforw(lp);
	}
	curcol = 0;
	i = 0;
	while (i < curwp->w_doto) {
		c = lgetc(lp, i++);
		if (c == '\t')
			curcol |= 0x07;
		else if (ISCTRL(c) != FALSE)
			++curcol;
		++curcol;
	}
	if (curcol >= ncol)			/* Long line.		*/
		curcol = ncol-1;
	if (sgarbf != FALSE) {			/* Screen is garbage.	*/
		sgarbf = FALSE;			/* Erase-page clears	*/
		epresf = FALSE;			/* the message area.	*/
		tttop  = HUGE;			/* Forget where you set	*/
		ttbot  = HUGE;			/* scroll region.	*/
		tthue  = CNONE;			/* Color unknown.	*/
		ttmove(0, 0);
		tteeop();
		for (i=0; i<nrow-1; ++i) {
			uline(i, vscreen[i], &blanks);
			ucopy(vscreen[i], pscreen[i]);
		}
		ttmove(currow, curcol);
		ttflush();
		return;
	}
#if	GOSLING
	if (hflag != FALSE) {			/* Hard update?		*/
		for (i=0; i<nrow-1; ++i) {	/* Compute hash data.	*/
			hash(vscreen[i]);
			hash(pscreen[i]);
		}
		offs = 0;			/* Get top match.	*/
		while (offs != nrow-1) {
			vp1 = vscreen[offs];
			vp2 = pscreen[offs];
			if (vp1->v_color != vp2->v_color
			||  vp1->v_hash  != vp2->v_hash)
				break;
			uline(offs, vp1, vp2);
			ucopy(vp1, vp2);
			++offs;
		}
		if (offs == nrow-1) {		/* Might get it all.	*/
			ttmove(currow, curcol);
			ttflush();
			return;
		}
		size = nrow-1;			/* Get bottom match.	*/
		while (size != offs) {
			vp1 = vscreen[size-1];
			vp2 = pscreen[size-1];
			if (vp1->v_color != vp2->v_color
			||  vp1->v_hash  != vp2->v_hash)
				break;
			uline(size-1, vp1, vp2);
			ucopy(vp1, vp2);
			--size;
		}
		if ((size -= offs) == 0)	/* Get screen size.	*/
			abort();
		setscores(offs, size);		/* Do hard update.	*/
		traceback(offs, size, size, size);
		for (i=0; i<size; ++i)
			ucopy(vscreen[offs+i], pscreen[offs+i]);
		ttmove(currow, curcol);
		ttflush();
		return;			
	}
#endif
	for (i=0; i<nrow-1; ++i) {		/* Easy update.		*/
		vp1 = vscreen[i];
		vp2 = pscreen[i];
		if ((vp1->v_flag&VFCHG) != 0) {
			uline(i, vp1, vp2);
			ucopy(vp1, vp2);
		}
	}
	ttmove(currow, curcol);
	ttflush();
}

/*
 * Update a saved copy of a line,
 * kept in a VIDEO structure. The "vvp" is
 * the one in the "vscreen". The "pvp" is the one
 * in the "pscreen". This is called to make the
 * virtual and physical screens the same when
 * display has done an update.
 */
ucopy(vvp, pvp)
register VIDEO	*vvp;
register VIDEO	*pvp;
{
	register int	i;

	vvp->v_flag &= ~VFCHG;			/* Changes done.	*/
	pvp->v_flag  = vvp->v_flag;		/* Update model.	*/
	pvp->v_hash  = vvp->v_hash;
	pvp->v_cost  = vvp->v_cost;
	pvp->v_color = vvp->v_color;
	for (i=0; i<ncol; ++i)
		pvp->v_text[i] = vvp->v_text[i];
}

/*
 * Update a single line. This routine only
 * uses basic functionality (no insert and delete character,
 * but erase to end of line). The "vvp" points at the VIDEO
 * structure for the line on the virtual screen, and the "pvp"
 * is the same for the physical screen. Avoid erase to end of
 * line when updating CMODE color lines, because of the way that
 * reverse video works on most terminals.
 */
uline(row, vvp, pvp)
VIDEO	*vvp;
VIDEO	*pvp;
{
#if	MEMMAP
	putline(row+1, 1, &vvp->v_text[0]);
#else
	register char	*cp1;
	register char	*cp2;
	register char	*cp3;
	register char	*cp4;
	register char	*cp5;
	register int	nbflag;

	if (vvp->v_color != pvp->v_color) {	/* Wrong color, do a	*/
		ttmove(row, 0);			/* full redraw.		*/
		ttcolor(vvp->v_color);
		cp1 = &vvp->v_text[0];
		cp2 = &vvp->v_text[ncol];
		while (cp1 != cp2) {
			ttputc(*cp1++);
			++ttcol;
		}
		return;
	}
	cp1 = &vvp->v_text[0];			/* Compute left match.	*/
	cp2 = &pvp->v_text[0];
	while (cp1!=&vvp->v_text[ncol] && cp1[0]==cp2[0]) {
		++cp1;
		++cp2;
	}
	if (cp1 == &vvp->v_text[ncol])		/* All equal.		*/
		return;
	nbflag = FALSE;
	cp3 = &vvp->v_text[ncol];		/* Compute right match.	*/
	cp4 = &pvp->v_text[ncol];
	while (cp3[-1] == cp4[-1]) {
		--cp3;
		--cp4;
		if (cp3[0] != ' ')		/* Note non-blanks in	*/
			nbflag = TRUE;		/* the right match.	*/
	}
	cp5 = cp3;				/* Is erase good?	*/
	if (nbflag==FALSE && vvp->v_color==CTEXT) {
		while (cp5!=cp1 && cp5[-1]==' ')
			--cp5;
		/* Alcyon hack */
		if ((int)(cp3-cp5) <= tceeol)
			cp5 = cp3;
	}
	/* Alcyon hack */
	ttmove(row, (int)(cp1-&vvp->v_text[0]));
	ttcolor(vvp->v_color);
	while (cp1 != cp5) {
		ttputc(*cp1++);
		++ttcol;
	}
	if (cp5 != cp3)				/* Do erase.		*/
		tteeol();
#endif
}

/*
 * Redisplay the mode line for
 * the window pointed to by the "wp".
 * This is the only routine that has any idea
 * of how the modeline is formatted. You can
 * change the modeline format by hacking at
 * this routine. Called by "update" any time
 * there is a dirty window.
 */
modeline(wp)
register WINDOW	*wp;
{
	register char	*cp;
	register int	c;
	register int	n;
	register BUFFER	*bp;

	n = wp->w_toprow+wp->w_ntrows;		/* Location.		*/
	vscreen[n]->v_color = CMODE;		/* Mode line color.	*/
	vscreen[n]->v_flag |= (VFCHG|VFHBAD);	/* Recompute, display.	*/
	vtmove(n, 0);				/* Seek to right line.	*/
	bp = wp->w_bufp;
	if ((bp->b_flag&BFCHG) != 0)		/* "*" if changed.	*/
		vtputc('*');
	else
		vtputc(' ');
	n  = 1;
	cp = "MicroEMACS";			/* Buffer name.		*/
	while ((c = *cp++) != 0) {
		vtputc(c);
		++n;
	}
	if (bp->b_bname[0] != 0) {
		vtputc(' ');
		++n;
		cp = &bp->b_bname[0];
		while ((c = *cp++) != 0) {
			vtputc(c);
			++n;
		}
	}
	if (bp->b_fname[0] != 0) {		/* File name.		*/
		vtputc(' ');
		++n;
		cp = "File:";
		while ((c = *cp++) != 0) {
			vtputc(c);
			++n;
		}
		cp = &bp->b_fname[0];
		while ((c = *cp++) != 0) {
			vtputc(c);
			++n;
		}
	}
	if (curmsgf != FALSE			/* Message alert.	*/
	&& wp->w_wndp == NULL) {
		while (n < ncol-5-1) {
			vtputc(' ');
			++n;
		}
		cp = "[Msg]";			/* Sizeof("[Msg]") = 5.	*/
		while ((c = *cp++) != 0) {
			vtputc(c);
			++n;
		}
	}
	while (n < ncol) {			/* Pad out.		*/
		vtputc(' ');
		++n;
	}
}

#if	GOSLING
/*
 * Compute the hash code for
 * the line pointed to by the "vp". Recompute
 * it if necessary. Also set the approximate redisplay
 * cost. The validity of the hash code is marked by
 * a flag bit. The cost understand the advantages
 * of erase to end of line. Tuned for the VAX
 * by Bob McNamara; better than it used to be on
 * just about any machine.
 */
hash(vp)
register VIDEO	*vp;
{
	register int	i;
	register int	n;
	register char	*s;
 
	if ((vp->v_flag&VFHBAD) != 0) {		/* Hash bad.		*/
		s = &vp->v_text[ncol-1];
		for (i=ncol; i!=0; --i, --s)
			if (*s != ' ')
				break;
		n = ncol-i;			/* Erase cheaper?	*/
		if (n > tceeol)
			n = tceeol;
		vp->v_cost = i+n;		/* Bytes + blanks.	*/
		for (n=0; i!=0; --i, --s)
			n = (n<<5) + n + *s;
		vp->v_hash = n;			/* Hash code.		*/
		vp->v_flag &= ~VFHBAD;		/* Flag as all done.	*/
	}
}

/*
 * Compute the Insert-Delete
 * cost matrix. The dynamic programming algorithm
 * described by James Gosling is used. This code assumes
 * that the line above the echo line is the last line involved
 * in the scroll region. This is easy to arrange on the VT100
 * because of the scrolling region. The "offs" is the origin 0
 * offset of the first row in the virtual/physical screen that
 * is being updated; the "size" is the length of the chunk of
 * screen being updated. For a full screen update, use offs=0
 * and size=nrow-1.
 *
 * Older versions of this code implemented the score matrix by
 * a two dimensional array of SCORE nodes. This put all kinds of
 * multiply instructions in the code! This version is written to
 * use a linear array and pointers, and contains no multiplication
 * at all. The code has been carefully looked at on the VAX, with
 * only marginal checking on other machines for efficiency. In
 * fact, this has been tuned twice! Bob McNamara tuned it even
 * more for the VAX, which is a big issue for him because of
 * the 66 line X displays.
 *
 * On some machines, replacing the "for (i=1; i<=size; ++i)" with
 * i = 1; do { } while (++i <=size)" will make the code quite a
 * bit better; but it looks ugly.
 */
setscores(offs, size)
{
	register SCORE	*sp;
	register int	tempcost;
	register int	bestcost;
	register int	j;
	register int	i;
	register VIDEO	**vp;
	register VIDEO	**pp;
	register SCORE	*sp1;
	register VIDEO	**vbase;
	register VIDEO	**pbase;
 
	vbase = &vscreen[offs-1];		/* By hand CSE's.	*/
	pbase = &pscreen[offs-1];
	score[0].s_itrace = 0;			/* [0, 0]		*/
	score[0].s_jtrace = 0;
	score[0].s_cost   = 0;
	sp = &score[1];				/* Row 0, inserts.	*/
	tempcost = 0;
	vp = &vbase[1];
	for (j=1; j<=size; ++j) {
		sp->s_itrace = 0;
		sp->s_jtrace = j-1;
		tempcost += tcinsl;
		tempcost += (*vp)->v_cost;
		sp->s_cost = tempcost;
		++vp;
		++sp;
	}
	sp = &score[NROW];			/* Column 0, deletes.	*/
	tempcost = 0;
	for (i=1; i<=size; ++i) {
		sp->s_itrace = i-1;
		sp->s_jtrace = 0;
		tempcost  += tcdell;
		sp->s_cost = tempcost;
		sp += NROW;
	}
	sp1 = &score[NROW+1];			/* [1, 1].		*/
	pp = &pbase[1];
	for (i=1; i<=size; ++i) {
		sp = sp1;
		vp = &vbase[1];
		for (j=1; j<=size; ++j) {
			sp->s_itrace = i-1;
			sp->s_jtrace = j;
			bestcost = (sp-NROW)->s_cost;
			if (j != size)		/* Cd(A[i])=0 @ Dis.	*/
				bestcost += tcdell;
			tempcost = (sp-1)->s_cost;
			tempcost += (*vp)->v_cost;
			if (i != size)		/* Ci(B[j])=0 @ Dsj.	*/
				tempcost += tcinsl;
			if (tempcost < bestcost) {
				sp->s_itrace = i;
				sp->s_jtrace = j-1;
				bestcost = tempcost;
			}
			tempcost = (sp-NROW-1)->s_cost;
			if ((*pp)->v_color != (*vp)->v_color
			||  (*pp)->v_hash  != (*vp)->v_hash)
				tempcost += (*vp)->v_cost;
			if (tempcost < bestcost) {
				sp->s_itrace = i-1;
				sp->s_jtrace = j-1;
				bestcost = tempcost;
			}
			sp->s_cost = bestcost;
			++sp;			/* Next column.		*/
			++vp;
		}
		++pp;
		sp1 += NROW;			/* Next row.		*/
	}
}

/*
 * Trace back through the dynamic programming cost
 * matrix, and update the screen using an optimal sequence
 * of redraws, insert lines, and delete lines. The "offs" is
 * the origin 0 offset of the chunk of the screen we are about to
 * update. The "i" and "j" are always started in the lower right
 * corner of the matrix, and imply the size of the screen.
 * A full screen traceback is called with offs=0 and i=j=nrow-1.
 * There is some do-it-yourself double subscripting here,
 * which is acceptable because this routine is much less compute
 * intensive then the code that builds the score matrix!
 */
traceback(offs, size, i, j)
{
	register int	itrace;
	register int	jtrace;
	register int	k;
	register int	ninsl;
	register int	ndraw;
	register int	ndell;

	if (i==0 && j==0)			/* End of update.	*/
		return;
	itrace = score[(NROW*i) + j].s_itrace;
	jtrace = score[(NROW*i) + j].s_jtrace;
	if (itrace == i) {			/* [i, j-1]		*/
		ninsl = 0;			/* Collect inserts.	*/
		if (i != size)
			ninsl = 1;
		ndraw = 1;
		while (itrace!=0 || jtrace!=0) {
			if (score[(NROW*itrace) + jtrace].s_itrace != itrace)
				break;
			jtrace = score[(NROW*itrace) + jtrace].s_jtrace;
			if (i != size)
				++ninsl;
			++ndraw;
		}
		traceback(offs, size, itrace, jtrace);
		if (ninsl != 0) {
			ttcolor(CTEXT);
			ttinsl(offs+j-ninsl, offs+size-1, ninsl);
		}
		do {				/* B[j], A[j] blank.	*/
			k = offs+j-ndraw;
			uline(k, vscreen[k], &blanks);
		} while (--ndraw);
		return;
	}
	if (jtrace == j) {			/* [i-1, j]		*/
		ndell = 0;			/* Collect deletes.	*/
		if (j != size)
			ndell = 1;
		while (itrace!=0 || jtrace!=0) {
			if (score[(NROW*itrace) + jtrace].s_jtrace != jtrace)
				break;
			itrace = score[(NROW*itrace) + jtrace].s_itrace;
			if (j != size)
				++ndell;
		}
		if (ndell != 0) {
			ttcolor(CTEXT);
			ttdell(offs+i-ndell, offs+size-1, ndell);
		}
		traceback(offs, size, itrace, jtrace);
		return;
	}
	traceback(offs, size, itrace, jtrace);
	k = offs+j-1;
	uline(k, vscreen[k], pscreen[offs+i-1]);
}
#endif
/*
 * Name:	MicroEMACS
 * 		Ultrix-32 file I/O.
 * Version:	29
 * Last edit:	05-Feb-86
 * By:		rex::conroy
 *		decvax!decwrl!dec-rhea!dec-rex!conroy
 */

static	FILE	*ffp;

/*
 * Open a file for reading.
 */
ffropen(fn)
char	*fn;
{
	if ((ffp=fopen(fn, "r")) == NULL)
		return (FIOFNF);
	return (FIOSUC);
}

/*
 * Open a file for writing.
 * Return TRUE if all is well, and
 * FALSE on error (cannot create).
 */
ffwopen(fn)
char	*fn;
{
	if ((ffp=fopen(fn, "w")) == NULL) {
		eprintf("Cannot open file for writing");
		return (FIOERR);
	}
	return (FIOSUC);
}

/*
 * Close a file.
 * Should look at the status.
 */
ffclose()
{
	fclose(ffp);
	return (FIOSUC);
}

/*
 * Write a line to the already
 * opened file. The "buf" points to the
 * buffer, and the "nbuf" is its length, less
 * the free newline. Return the status.
 * Check only at the newline.
 */
ffputline(buf, nbuf)
register char	buf[];
{
	register int	i;

	for (i=0; i<nbuf; ++i)
		putc(buf[i]&0xFF, ffp);
	putc('\n', ffp);
	if (ferror(ffp) != FALSE) {
		eprintf("Write I/O error");
		return (FIOERR);
	}
	return (FIOSUC);
}

/*
 * Read a line from a file, and store the bytes
 * in the supplied buffer. Stop on end of file or end of
 * line. Don't get upset by files that don't have an end of
 * line on the last line; this seem to be common on CP/M-86 and
 * MS-DOS (the suspected culprit is VAX/VMS kermit, but this
 * has not been confirmed. If this is sufficiently researched
 * it may be possible to pull this kludge). Delete any CR
 * followed by an LF. This is mainly for runoff documents,
 * both on VMS and on Ultrix (they get copied over from
 * VMS systems with DECnet).
 */
ffgetline(buf, nbuf)
register char	buf[];
{
	register int	c;
	register int	i;

	i = 0;
	for (;;) {
		c = getc(ffp);
		if (c == '\r') {		/* Delete any non-stray	*/
			c = getc(ffp);		/* carriage returns.	*/
			if (c != '\n') {
				if (i < nbuf-1)
					buf[i++] = '\r';
			}
		}
		if (c==EOF || c=='\n')		/* End of line.		*/
			break;
		if (i < nbuf-1)
			buf[i++] = c;
	}
	if (c == EOF) {				/* End of file.		*/
		if (ferror(ffp) != FALSE) {
			eprintf("File read error");
			return (FIOERR);
		}
		if (i == 0)			/* Don't get upset if	*/
			return (FIOEOF);	/* no newline at EOF.	*/
	}
	buf[i] = 0;
	return (FIOSUC);
}

/*
 * Rename the file "fname" into a backup
 * copy. On Unix the backup has the same name as the
 * original file, with a "~" on the end; this seems to
 * be newest of the new-speak. The error handling is
 * all in "file.c". The "unlink" is perhaps not the
 * right thing here; I don't care that much as
 * I don't enable backups myself.
 */
fbackupfile(fname)
char	*fname;
{
	register char	*nname;

	if ((nname=malloc(strlen(fname)+1+1)) == NULL)
		return (ABORT);
	(void) strcpy(nname, fname);
	(void) strcat(nname, "~");
	(void) unlink(nname);			/* Ignore errors.	*/
	if (rename(fname, nname) < 0) {
		free(nname);
		return (FALSE);
	}
	free(nname);
	return (TRUE);
}

/*
 * The string "fn" is a file name.
 * Perform any required case adjustments. All sustems
 * we deal with so far have case insensitive file systems.
 * We zap everything to lower case. The problem we are trying
 * to solve is getting 2 buffers holding the same file if
 * you visit one of them with the "caps lock" key down.
 * On UNIX file names are dual case, so we leave
 * everything alone.
 */
adjustcase(fn)
register char	*fn;
{
#if	0
	register int	c;

	while ((c = *fn) != 0) {
		if (c>='A' && c<='Z')
			*fn = c + 'a' - 'A';
		++fn;
	}
#endif
}
/*
 * Name:	MicroEMACS
 *		Spawn CLI; stop if C shell.
 * Version:	29
 * Last edit:	10-Feb-86
 * By:		rex::conroy
 *		decvax!decwrl!dec-rhea!dec-rex!conroy
 *
 * Spawn. New version, which
 * interracts with the job control stuff
 * in the 4.X BSD C shell.
 */

#include	<signal.h>

char	*shellp	= NULL;			/* Saved "SHELL" name.		*/


extern	char	*getenv();

/*
 * This code does a one of 2 different
 * things, depending on what version of the shell
 * you are using. If you are using the C shell, which
 * implies that you are using job control, then MicroEMACS
 * moves the cursor to a nice place and sends itself a
 * stop signal. If you are using the Bourne shell it runs
 * a subshell using fork/exec. Bound to "C-C", and used
 * as a subcommand by "C-Z".
 */
spawncli(f, n, k)
{
	register int	pid;
	register int	wpid;
	register int	(*oqsig)();
	register int	(*oisig)();
	int		status;

	if (shellp == NULL) {
		shellp = getenv("SHELL");
		if (shellp == NULL)
			shellp = getenv("shell");
		if (shellp == NULL)
			shellp = "/bin/sh";	/* Safer.		*/
	}
	ttcolor(CTEXT);
	ttnowindow();
	if (strcmp(shellp, "/bin/csh") == 0) {
		if (epresf != FALSE) {
			ttmove(nrow-1, 0);
			tteeol();
			epresf = FALSE;
		}				/* Csh types a "\n"	*/
		ttmove(nrow-2, 0);		/* before "Stopped".	*/
	} else {
		ttmove(nrow-1, 0);
		if (epresf != FALSE) {
			tteeol();
			epresf = FALSE;
		}
	}
	ttflush();
	ttclose();
	if (strcmp(shellp, "/bin/csh") == 0)	/* C shell.		*/
		kill(0, SIGTSTP);
	else {					/* Bourne shell.	*/
		oqsig = signal(SIGQUIT, SIG_IGN);
		oisig = signal(SIGINT,  SIG_IGN);
		if ((pid=fork()) < 0) {
			signal(SIGQUIT, oqsig);
			signal(SIGINT,  oisig);
			eprintf("Failed to create process");
			return (FALSE);
		}
		if (pid == 0) {
			execl(shellp, "sh", "-i", NULL);
			_exit(0);		/* Should do better!	*/
		}
		while ((wpid=wait(&status))>=0 && wpid!=pid)
			;
		signal(SIGQUIT, oqsig);
		signal(SIGINT,  oisig);
	}
	sgarbf = TRUE;				/* Force repaint.	*/
	ttopen();
	return (TRUE);
}
/*
 * Name:	MicroEMACS
 *		Version stamp.
 * Version:	30
 * Last edit:	14-Feb-86
 * By:		rex::conroy
 *		decvax!decwrl!dec-rhea!dec-rex!conroy
 *
 * This file contains the string(s)
 * that get written out by the show version command.
 * Rich had it generated by a command file. I do
 * it manually, until I can figure out a way to get
 * the MicroEMACS version number generated in a
 * reasonable (automatic) manner. Perhaps a program
 * that reads "things2do.txt".
 */
#ifdef HAVE_CONFIG_H
#include	"config.h"
#else
#define PACKAGE_VERSION "30"
#endif

char	*version[] = {
	"MicroEMACS version " PACKAGE_VERSION,
	"Source from REX::USER$A:[CONROY.HACKING.MINIEMACS]",
	NULL
}; 
/*
 * Name:	MicroEMACS
 *		Mainline, macro commands.
 * Version:	29
 * Last edit:	05-Feb-86
 * By:		rex::conroy
 *		decvax!decwrl!dec-rhea!dec-rex!conroy
 */

int	thisflag;			/* Flags, this command		*/
int	lastflag;			/* Flags, last command		*/
int	curgoal;			/* Goal column			*/
BUFFER	*curbp;				/* Current buffer		*/
WINDOW	*curwp;				/* Current window		*/
BUFFER	*bheadp;			/* BUFFER listhead		*/
WINDOW	*wheadp;			/* WINDOW listhead		*/
BUFFER	*blistp;			/* Buffer list BUFFER		*/
short	kbdm[NKBDM] = { KCTLX | ')' };	/* Macro			*/
short	*kbdmip;			/* Input  for above		*/
short	*kbdmop;			/* Output for above		*/
char	pat[NPAT];			/* Pattern			*/
SYMBOL	*symbol[NSHASH];		/* Symbol table listhead.	*/
SYMBOL	*binding[NKEYS];		/* Key bindings.		*/

main(argc, argv)
char	*argv[];
{
	register int	c;
	register int	f;
	register int	n;
	register int	mflag;
	char		bname[NBUFN];

	strcpy(bname, "main");			/* Get buffer name.	*/
	if (argc > 1)
		makename(bname, argv[1]);
	vtinit();				/* Virtual terminal.	*/
	edinit(bname);				/* Buffers, windows.	*/
	keymapinit();				/* Symbols, bindings.	*/
	if (argc > 1) { update(); readin(argv[1]); } else filldir(".");
	lastflag = 0;				/* Fake last flags.	*/
loop:
	update();				/* Fix up the screen.	*/
	c = getkey();
	if (epresf != FALSE) {
		eerase();
		update();
	}
	f = FALSE;
	n = 1;
	if (c == (KCTRL|'U')) {			/* ^U, start argument.	*/
		f = TRUE;
		n = 4;
		while ((c=getkey()) == (KCTRL|'U'))
			n *= 4;
		if ((c>='0' && c<='9') || c=='-') {
			if (c == '-') {
				n = 0;
				mflag = TRUE;
			} else {
				n = c - '0';
				mflag = FALSE;
			}
			while ((c=getkey())>='0' && c<='9')
				n = 10*n + c - '0';
			if (mflag != FALSE)
				n = -n;
		}
	}
	if (kbdmip != NULL) {			/* Save macro strokes.	*/
		if (c!=(KCTLX|')') && kbdmip>&kbdm[NKBDM-6]) {
			ctrlg(FALSE, 0, KRANDOM);
			goto loop;
		}
		if (f != FALSE) {
			*kbdmip++ = (KCTRL|'U');
			*kbdmip++ = n;
		}
		*kbdmip++ = c;
	}
	execute(c, f, n);			/* Do it.		*/
	goto loop;
}

/*
 * Command execution. Look up the binding in the the
 * binding array, and do what it says. Return a very bad status
 * if there is no binding, or if the symbol has a type that
 * is not usable (there is no way to get this into a symbol table
 * entry now). Also fiddle with the flags.
 */
execute(c, f, n)
{
	register SYMBOL	*sp;
	register int	status;

	if ((sp=binding[c]) != NULL) {
		thisflag = 0;
		status = (*sp->s_funcp)(f, n, c);
		lastflag = thisflag;
		return (status);
	}
	lastflag = 0;
	return (ABORT);
}

/*
 * Initialize all of the buffers
 * and windows. The buffer name is passed down as
 * an argument, because the main routine may have been
 * told to read in a file by default, and we want the
 * buffer name to be right.
 */
edinit(bname)
char	bname[];
{
	register BUFFER	*bp;
	register WINDOW	*wp;

	bp = bfind(bname, TRUE);		/* Text buffer.		*/
	blistp = bcreate("");			/* Special list buffer.	*/
	wp = (WINDOW *) malloc(sizeof(WINDOW));	/* Initial window.	*/
	if (bp==NULL || wp==NULL || blistp==NULL)
		abort();
	curbp  = bp;				/* Current ones.	*/
	wheadp = wp;
	curwp  = wp;
	wp->w_wndp  = NULL;			/* Initialize window.	*/
	wp->w_bufp  = bp;
	bp->b_nwnd  = 1;			/* Displayed.		*/
	wp->w_linep = bp->b_linep;
	wp->w_dotp  = bp->b_linep;
	wp->w_doto  = 0;
	wp->w_markp = NULL;
	wp->w_marko = 0;
	wp->w_toprow = 0;
	wp->w_ntrows = nrow-2;			/* 2 = mode, echo.	*/
	wp->w_force = 0;
	wp->w_flag  = WFMODE|WFHARD;		/* Full.		*/
}
	
/*
 * Fancy quit command, as implemented
 * by Jeff. If the current buffer has changed
 * do a write current buffer. Otherwise run a command
 * interpreter in a subjob. Two of these will get you
 * out. Bound to "C-Z".
 */
jeffexit(f, n, k)
{
	if ((curbp->b_flag&BFCHG) != 0)		/* Changed.		*/
		return (filesave(f, n, KRANDOM));
	return (spawncli(f, n, KRANDOM));	/* Suspend.		*/
}

/*
 * Quit command. If an argument, always
 * quit. Otherwise confirm if a buffer has been
 * changed and not written out. Normally bound
 * to "C-X C-C".
 */
quit(f, n, k)
{
	register int	s;

	if (f != FALSE				/* Argument forces it.	*/
	|| anycb() == FALSE			/* All buffers clean.	*/
	|| (s=eyesno("Quit")) == TRUE) {	/* User says it's OK.	*/
		vttidy();
		exit(GOOD);
	}
	return (s);
}

/*
 * Begin a keyboard macro.
 * Error if not at the top level
 * in keyboard processing. Set up
 * variables and return.
 */
ctlxlp(f, n, k)
{
	if (kbdmip!=NULL || kbdmop!=NULL) {
		eprintf("Not now");
		return (FALSE);
	}
	eprintf("[Start macro]");
	kbdmip = &kbdm[0];
	return (TRUE);
}

/*
 * End keyboard macro. Check for
 * the same limit conditions as the
 * above routine. Set up the variables
 * and return to the caller.
 */
ctlxrp(f, n, k)
{
	if (kbdmip == NULL) {
		eprintf("Not now");
		return (FALSE);
	}
	eprintf("[End macro]");
	kbdmip = NULL;
	return (TRUE);
}

/*
 * Execute a macro.
 * The command argument is the
 * number of times to loop. Quit as
 * soon as a command gets an error.
 * Return TRUE if all ok, else
 * FALSE.
 */
ctlxe(f, n, k)
{
	register int	c;
	register int	af;
	register int	an;
	register int	s;

	if (kbdmip!=NULL || kbdmop!=NULL) {
		eprintf("Not now");
		return (FALSE);
	}
	if (n <= 0) 
		return (TRUE);
	do {
		kbdmop = &kbdm[0];
		do {
			af = FALSE;
			an = 1;
			if ((c = *kbdmop++) == (KCTRL|'U')) {
				af = TRUE;
				an = *kbdmop++;
				c  = *kbdmop++;
			}
			s = TRUE;
		} while (c!=(KCTLX|')') && (s=execute(c, af, an))==TRUE);
		kbdmop = NULL;
	} while (s==TRUE && --n);
	return (s);
}

/*
 * Abort.
 * Beep the beeper.
 * Kill off any keyboard macro,
 * etc., that is in progress.
 * Sometimes called as a routine,
 * to do general aborting of
 * stuff.
 */
ctrlg(f, n, k)
{
	ttbeep();
	if (kbdmip != NULL) {
		kbdm[0] = (KCTLX|')');
		kbdmip  = NULL;
	}
	return (ABORT);
}

/*
 * Display the version. All this does
 * is copy the text in the external "version" array into
 * the message system, and call the message reading code.
 * Don't call display if there is an argument.
 */
showversion(f, n, k)
{
	register char	**cpp;
	register char	*cp;

	cpp = &version[0];
	while ((cp = *cpp++) != NULL) {
		if (writemsg(cp) == FALSE)
			return (FALSE);
	}
	if (f != FALSE)				/* No display if arg.	*/
		return (TRUE);
	return (readmsg());
}
