/******************************************************************************
 File: mkopt.h

 By: David Schwartz

 Date: Apr 1995

 (C) Williams Entertainment

 Mortal Kombat III Options Header
******************************************************************************/

#ifndef __mk_mkopt_h__
#define __mk_mkopt_h__

/*
 * 	DEFINITIONS
 */

/* icons */
#define OPT_IKOMBAT			0		// must match table order in mknuopt
#define OPT_IGAME			1
#define OPT_IKONTROL		2
#define OPT_ISOUND			3
#define OPT_IQUEST1			4
#define OPT_IQUEST2			5
#define OPT_IQUEST3			6
#define OPT_IQUEST4			7

#define OPT_ICON	4
#define OPT_ICON_SECRET	5
#define OPT_ICON_SECRET1	6
#define OPT_ICON_SECRET2	7
#define OPT_ICON_SECRET3	8

#define OPT_CMD_NONE	0		// icons do nothing
#define OPT_CMD_LEFT	1		// icons move left
#define OPT_CMD_RIGHT	2		// icons move right
#define OPT_CMD_EXIT	3		// abort

/* button indexes */
#define OPT_BUT_A			1
#define OPT_BUT_B			2
#define OPT_BUT_L			3
#define OPT_BUT_R			4
#define OPT_BUT_YUP			5
#define OPT_BUT_YDOWN		6
#define OPT_BUT_YLEFT		7
#define OPT_BUT_YRIGHT		8

/* start of screen positions */
#define OPT_TOP_X_L		16
#define OPT_TOP_Y		48
#define OPT_TOP_X_C		244
#define OPT_EXIT_X	160
#define OPT_CC_X_L  152
#define OPT_CC_X1_C  60
#define OPT_CC_X2_C  (SCRRGT-60)

/* option joy control */
#define OPTION_EXIT P1P2_ACTION
#define OPT_P1MASK		(0x0000ffff)
#define OPT_P2MASK		(0xffff0000)

/* option screen index */
#define OPT_SCRN_GAME			0
#define OPT_SCRN_MUSIC			1
#define OPT_SCRN_CONTROLS		2
#define OPT_SCRN_CONTROLS2	3
#define OPT_SCRN_CHEAT1		4
#define OPT_SCRN_CHEAT2		5
#define OPT_SCRN_CHEAT3		6
#define OPT_SCRN_CHEAT4		7

#define OIND_END				0xff

/* valid buttons for SONY PSX */
#define M_TRI			0x0010
#define M_X				0x0040
#define M_CIRCLE	0x0020
#define M_SQUARE	0x0080
#define M_L2			0x0002
#define M_L1			0x0008
#define M_R2			0x0000
#define M_R1			0x0004

#define B_TRI			4
#define B_X       6
#define B_CIRCLE  5
#define B_SQUARE  7
#define B_L1      3
#define B_L2      1
#define B_R1      2
#define B_R2      0

/* opt control lookup values */
#define OCL_HP			0
#define OCL_LP      1
#define OCL_HK      2
#define OCL_LK      3
#define OCL_RUN     4
#define OCL_BLOCK   5
#define OCL_OFF     6

/* list structures for options */
typedef struct optlst
{
//	OBJECT *lobj;				// label object
//	OBJECT *cobj;				// choice object
	WORD oid;					// text id, needed for hiliting
	WORD *var;					// ptr to varible that will store results
	short y;					// line text is located on
	short xlabel;				// x position of label
	short xchoice;				// x posiiton of choices
	char *label_txt;			// ptr to label for options
	char **choicetbl;			// ptr to a list of choices
	FUNC toggle_func;			// toggle function
	WORD index;					// index into choice table
} OPTLIST;

typedef struct optpage
{
	BYTE u0,v0;						// offset within tpage (u0 even)
	BYTE w,h;						// width & height of sprite
} OPTPAGE;

typedef struct optmap
{
	WORD b_index;				// button index value  (hardware bit value)
	WORD *storage;			// variable to store remap
} OPTMAP;

/* color scheme */
#define OPT_NORMAL_COLOR  nuoptextbg_PAL
#define OPT_HILITE_COLOR	YELLOW_p

/* active process for test */
#define OPT_ACTIVE_NONE			0x00
#define OPT_ACTIVE_MUSIC		PID_OPTMUSIC
#define OPT_ACTIVE_SOUND		PID_OPTSOUND

#define OPT_MAX_MUSIC			5							// max # of songs
#define OPT_MAX_SOUND			50						// max # of sfx

/*
 *	RAM
 */
__EXTERN__ WORD option_tpage;
__EXTERN__ WORD opt_active;					// (0=none active, 1=music active, 2=sound active)
__EXTERN__ WORD opt_done;				// flag: option select done

/*
 *	PROTOTYPES
 */
void opt_main(void);
void opt_icon(void);

void option_select(WORD scrnindex);
void option_toggle(void);
void option_exit(void);
void option_center(void);
void option_test_toggle(WORD aflag,WORD max);
void option_mtest(void);
void option_stest(void);
void soundtest_proc(void);
void option_toggle_sound(void);

WORD init_option_table(OPTLIST *otbl,WORD scrn);
OBJECT *get_option_object(short x,short y,WORD lindex);
void opt_disp_num(WORD sndnum,WORD x,WORD y,WORD id);
void opt_pad_setup(OPTMAP *omap, WORD *padmap);
void opt_pad_remap(OPTMAP *omap, WORD *padmap);
void opt_proc(void);
void opt_p2control(void);

/*
 *	MACROS
 */
#define center_opt_obj(_ta8) (_ta8)->oxpos.u.intpos=(_ta8)->oxvel.u.intpos-(_ta8)->header.t_width/2;

/* sony psx hardware joypad */
#define pad_tri			l_hp
#define pad_x				l_lk
#define pad_circle	l_hk
#define pad_square	l_lp
#define pad_r1			l_block
#define pad_r2			l_up
#define pad_l1			l_down
#define pad_l2			l_left

#endif /* __mk_mkopt_h__ */

