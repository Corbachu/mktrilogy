/******************************************************************************
 File: u64main.h

 Date: Jan 1996

 (C) Williams Entertainment

 Mortal Kombat III U64 SPECIFIC STUFF
******************************************************************************/

#ifndef __mk_u64main_h__
#define __mk_u64main_h__

/* SONY LIBRARIES */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ultra64.h>
#include "sys_defs.h"
#include "system.h"

/*
 *	TYPES
 */
#define MULTI_ANI_OFF	0			//(1-multi animation texture loads, need to make mods to storm, trash, monk ciode)

typedef unsigned char BYTE;
typedef unsigned short WORD;
typedef unsigned int LONG;
typedef unsigned long ADDRESS;

/* fixed point 16.16 union */
typedef union u_pos {
	long	pos;			/* 16.16 position */
	struct {
#if ENDIAN==1
		short	intpos;		/* integer part */
		short	fracpos;	/* fractional position */
#else
		short	fracpos;	/* fractional position */
		short	intpos;		/* integer part */
#endif
	} u;
} POS;

/* rectangle */
typedef struct {
	short x,y;
	short w,h;
} RECT;

#define setRECT(r,_x,_y,_w,_h) \
	(r)->x = (_x), (r)->y = (_y), (r)->w = (_w), (r)->h = (_h)

/* joy pad info */
typedef union joypad {
	LONG padvalue;			/* pad p2:p1 */
	struct {
#if ENDIAN==1
		WORD p2pad;
		WORD p1pad;
#else
		WORD p1pad;
		WORD p2pad;
#endif
	} u;
} JOYPAD;

/* y:x pos (integer info) */
typedef union u_xytype {
	long yx;					/* y:x position */
	struct {
#if ENDIAN==1
		short	ypos;			/* y position */
		short	xpos;			/* x position */
#else
		short	xpos;			/* x position */
		short	ypos;			/* y position */
#endif
	} u;
} XYTYPE;

/* rgb color info */
typedef struct o_color {
	BYTE red;
	BYTE green;
	BYTE blue;
	WORD rgb;
} COLOR;

/*
 *	DEFINITIONS
 */

//******************************************************************************
//******************************************************************************
//			Ultra 64 Startup Code (Begin)
//******************************************************************************
//******************************************************************************
//========================================================================================
// Public definitions:

#define CRITICAL_DEFS	u32 imask
#define ENTER_CRITICAL	imask = sys_disable_ints()
#define LEAVE_CRITICAL	sys_restore_ints( imask )

#define ZSTAT_FREE			0
#define ZSTAT_OBSYS_REQ		1
#define ZSTAT_OBSYS			2

__EXTERN__ int hang;

//========================================================================================
// Public variables:

/* IMPORTANT: sys_rcp_stack MUST be first here to align on a 16-byte address !!!!!!!! */
__EXTERN__ u64 sys_rcp_stack[SP_DRAM_STACK_SIZE64];
/* IMPORTANT: sys_rcp_stack MUST be first here to align on a 16-byte address !!!!!!!! */

#if SYS_DEBUG	// test values:
	__EXTERN__ char		*tv0, *tv1, *tv2, *tv3, *tv4, *tv5, *tv6, *tv7;
#endif

//extern u32 sys_ovmemptr;		// overlay pointer: points to next free physical byte of DRAM
//extern u32 sys_obmemptr;		// object pointer: points to start of last object loaded
//
//extern u32 sys_zbuf_phys;						// physical start address of zbuffer (aligned on a 64-byte boundary)
//extern u32 sys_fbuf_phys[SYS_NUM_FRAMEBUFS];	// physical start address of frame buffers (aligned on a 64-byte boundary)
//extern u32 sys_dbuf_phys[SYS_NUM_DLBUFS];		// physical start address of display-list buffers (aligned on an 8-byte boundary)
//extern u32 sys_mbuf_phys[SYS_NUM_DLBUFS];		// physical start address of matrix buffers (aligned on an 8-byte boundary)
//extern u32 sys_vbuf_phys[SYS_NUM_DLBUFS];		// physical start address of vertex buffers (aligned on an 8-byte boundary)
//extern u32 sys_pbuf_phys[SYS_NUM_DLBUFS];		// physical start address of viewport buffers (aligned on an 8-byte boundary)
//
//extern u32 sys_heap1_start;		// physical start of heap 1
//extern u32 sys_heap1_end;		// physical end+1 of heap 1
//extern u32 sys_heap2_start;		// physical start of heap 2
//extern u32 sys_heap2_end;		// physical end+1 of heap 2


/* Graphics Subsystem Stuff */
#define GLIST_LEN	16*1024

typedef struct dyn
{ 
  Gfx glist[GLIST_LEN];			// graphics list
  volatile WORD	frame_done;				// set if no frame is rendering using this buffer
} DYNAMIC;

#define DBL_FRAME_READY	  0		// Ready to Draw a frame
#define DBL_FRAME_DRAW	  1		// Frame being drawn

__EXTERN__ DYNAMIC dbl_buffer[2];		// double buffer system
__EXTERN__ DYNAMIC *dbl_buffer_ptr;		// ptr to current buffer


#if 0
/* RSP */
__EXTERN__  OSMesgQueue	sys_msgque_rsp;	// event message queues:
__EXTERN__  OSMesg		sys_msgbuf_rsp;

/* RDP */
__EXTERN__  OSMesgQueue	sys_msgque_rdp;
__EXTERN__  OSMesg		sys_msgbuf_rdp;
#endif

/* VBI */
__EXTERN__  OSMesgQueue	sys_msgque_vbi;
__EXTERN__  OSMesg		sys_msgbuf_vbi;

/* Serial/Gamepad */
__EXTERN__  OSMesgQueue	sys_msgque_ser;
__EXTERN__  OSMesg		sys_msgbuf_ser;

__EXTERN__  OSMesgQueue	sys_msgque_joy;
__EXTERN__  OSMesg		sys_msgbuf_joy;

/* Timer */
__EXTERN__  OSMesgQueue	sys_msgque_tmr;
__EXTERN__  OSMesg		sys_msgbuf_tmr;

__EXTERN__  OSMesg		sys_DummyMsg;

//========================================================================================
// Public system functions:

//////////////////////////////////////////////////////////////////////////////////////////
// sys_assertion - assert a system error.
//
// Defined only when SYS_DEBUG is non-zero.
//////////////////////////////////////////////////////////////////////////////////////////
#if SYS_DEBUG
	extern void sys_assertion( int errcode, char *errinfo );
#endif


//////////////////////////////////////////////////////////////////////////////////////////
// sys_disable_ints - disables R4300 CPU interrupts, returning the prior state.  This is
//                    an assembly function.
//////////////////////////////////////////////////////////////////////////////////////////
extern u32 sys_disable_ints( void );


//////////////////////////////////////////////////////////////////////////////////////////
// sys_restore_ints - restores R4300 CPU interrupts to their prior state (passed as the
//                    parameter). This is an assembly function.
//////////////////////////////////////////////////////////////////////////////////////////
extern void sys_restore_ints( u32 prior_state );

//////////////////////////////////////////////////////////////////////////////////////////
// vid_vbi_wait_thread - An independent thread used to catch vertical retraces.
//
// IMPORTANT: This function is internally called and managed by the kernel. It should
//            not be called.
//////////////////////////////////////////////////////////////////////////////////////////
extern void vid_vbi_wait_thread( void *arg );

//******************************************************************************
//******************************************************************************
//			Ultra 64 Startup Code (End)
//******************************************************************************
//******************************************************************************





#define MAP_TBL_ENTRIES 16				/* 16 bits for each pad */

#define SCORE_RAM_CNT	22				/* # of sprites needed for the control panel */
//-SONY- #define SONY_GRAPH_DEBUG 0
//-SONY- #define SONY_HBLANK 0
//-SONY- #define OTSIZE	250								/* size of ording table */
//-SONY- #define OBJPRIM_SIZE 220						/* # of drawing primitives per buffer */
//-SONY- #define BOXPRIM_SIZE 10							/* number of box prim to draw */
//-SONY- #define TEXTURE_MODE 1							/* 0=4 bit, 1=8bit, 2=15 bit */
//-SONY- #define TRANS_RATE 0							/* semi transperency rate */
//-SONY- #define SHADE_TEX 0								/* shading */

/* VRAM Memory Allocation */
#define BUFFER_WIDTH 320						/* width of display buffer */
#define BUFFER_HEIGHT 240						/* height of display buffer */

//-SONY- #define BUF0_X_COORD 0							/* draw buffer 0 x coordinate */
//-SONY- #define BUF0_Y_COORD 0							/* draw buffer 0 y coordinate */
//-SONY- #define BUF1_X_COORD BUFFER_WIDTH				/* draw buffer 1 x coordinate */
//-SONY- #define BUF1_Y_COORD 0							/* draw buffer 1 y coordinate */
//-SONY- #define BACK_TEXTURE_BASE_X 384					/* base x coord of backgrounds */
//-SONY- #define BACK_TEXTURE_BASE_Y 256					/* base y coord of backgrounds */
//-SONY- #define CP_TEXT_X	640							/* control panel texture page start x */
//-SONY- #define CP_TEXT_Y	0							/* control panel texture page start y */
//-SONY- #define OPT_TEXT_X	896							/* option texture page x coord */
//-SONY- #define OPT_TEXT_Y	256							/* option texture page y coord */
//-SONY- #define CLUT_BASE_PAL_X	0						/* base vram CLUT X addr */
//-SONY- #define CLUT_BASE_PAL_Y 240						/* base vram CLUT Y addr */

#define FLOOR_Y 84					/* # of pixels per floor in height */
#define FLOOR_X 960					/* # of pixels per floor scan line */

/* floor goes below control panel stuff, cp art cannot exceed 68 lines */
/* floors cannont go below line 239 */
//-SONY- #define FLR_L_BASE_X	CP_TEXT_X		//640+128
//-SONY- #define FLR_L_BASE_Y	68			//(255-FLOOR_Y)

//-SONY- #define FLR_R_BASE_X	CP_TEXT_X				//(640+128+128)
//-SONY- #define FLR_R_BASE_Y	FLR_L_BASE_Y+FLOOR_Y	//(255-FLOOR_Y)

//-SONY- #define PLYR_1_BASE_X	640+128+1
//-SONY- #define PLYR_1_BASE_Y	0

//-SONY- #define PLYR_2_BASE_X	(640+128+128)+1
//-SONY- #define PLYR_2_BASE_Y	0

//-SONY- #define FONT_15_BASE_X	(640+128)		/* 15 point font vram start x local */
//-SONY- #define FONT_15_BASE_Y	(170)					/* 15 point font vram start y local */

//-SONY- #define LOADING_BASE_X	(640+128+128)		/* loading vram start x local */
//-SONY- #define LOADING_BASE_Y	(170)						/* loading vram start y local */

//-SONY- #define FRAME_WIDTH 1023
//-SONY- #define FRAME_HEIGHT 512

/* screen sizing information */
#define SCRTOP 0
#define SCRBOT (BUFFER_HEIGHT-1)
#define SCRLFT 0
#define SCRRGT (BUFFER_WIDTH-1)

#define SCRNSTX SCRLFT
#define SCRNSTY SCRTOP
#define SCRNENDX SCRRGT
#define SCRNENDY SCRBOT

/* draw buffer primitive */
//-SONY- typedef struct {
//-SONY- 	DRAWENV	draw;					/* draw environment */
//-SONY- 	DISPENV disp;					/* display environment */
//-SONY- 	u_long ot[OTSIZE];				/* ordering table */
//-SONY- 	u_long *ot_ptr;					/* ordering table ptr */
//-SONY- 	POLY_FT4 obj_prim[OBJPRIM_SIZE];	/* drawing primitives */
//-SONY- 	POLY_FT4 *curr_prim;
//-SONY- 	BLK_FILL clear;
//-SONY- 	LONG primcnt;
//-SONY- 
//-SONY- 	DR_MODE	dm_score;						/* needed to change tpage during draw */
//-SONY- 	SPRT cp[SCORE_RAM_CNT];
//-SONY- 
//-SONY- 	DR_MODE dm_floor;						/* change tpage for floor */
//-SONY- 	SPRT floor[2];							/* floor left/right buffers */
//-SONY- 
//-SONY- 	DR_MODE dm_test;						/* change tpage for floor */
//-SONY- 
//-SONY- 	POLY_F4	box_prim[BOXPRIM_SIZE];	/* used to draw box primitives */
//-SONY- 	POLY_F4 *box_ptr;
//-SONY- 
//-SONY- #if DEBUG_GRID
//-SONY- 	LINE_F2 lines[22];
//-SONY- #endif
//-SONY- } DB;

/* context switch storage */
typedef struct mc_reg {
	ADDRESS c_wakeup;				/* ptr to next code to execute */
	ADDRESS c_stackptr;				/* stack ptr */
	ADDRESS c_frameptr;				/* frame ptr */
	ADDRESS c_globalptr;			/* global ptr */
	ADDRESS c_s0;					/* s0 reg */
	ADDRESS c_s1;					/* s1 reg */
	ADDRESS c_s2;					/* s2 reg */
	ADDRESS c_s3;					/* s3 reg */
	ADDRESS c_s4;					/* s4 reg */
	ADDRESS c_s5;					/* s5 reg */
	ADDRESS c_s6;					/* s6 reg */
	ADDRESS c_s7;					/* s7 reg */
	ADDRESS	c_fs0;
	ADDRESS	c_fs1;
	ADDRESS	c_fs2;
	ADDRESS	c_fs3;
	ADDRESS	c_fs4;
	ADDRESS	c_fs5;
} MCONTEXT;

typedef struct c_reg {
	ADDRESS c_wakeup;				/* ptr to next code to execute */
	ADDRESS c_stackptr;				/* stack ptr */
	ADDRESS c_frameptr;				/* frame ptr */
	ADDRESS c_globalptr;			/* global ptr */
	ADDRESS c_s0;					/* s0 reg */
	ADDRESS c_s1;					/* s1 reg */
	ADDRESS c_s2;					/* s2 reg */
	ADDRESS c_s3;					/* s3 reg */
	ADDRESS c_s4;					/* s4 reg */
	ADDRESS c_s5;					/* s5 reg */
	ADDRESS c_s6;					/* s6 reg */
	ADDRESS c_s7;					/* s7 reg */
	ADDRESS	c_fs0;
	ADDRESS	c_fs1;
	ADDRESS	c_fs2;
	ADDRESS	c_fs3;
	ADDRESS	c_fs4;
	ADDRESS	c_fs5;

	long long c_stack[STKSIZE/8]; 	/* stack space for the processor MUST BE DOUBLEWORD aligned */
} CONTEXT;

/*
 *	RAM
 */
//-SONY- __EXTERN__ DB db[2];						/* double buffer environment */
//-SONY- __EXTERN__ DB *cdb;							/* current draw buffer */
//-SONY- __EXTERN__ WORD	bkgd_base_tpage;			/* base texture page for backgrounds */
//-SONY- __EXTERN__ WORD control_floor_tpage;		/* tpage info for control panel texture page & floors */
//-SONY- __EXTERN__ WORD load_tpage;				/* loading message tpage */

//-SONY- __EXTERN__ u_long vbEvent;					/* event # for vblank routine */

__EXTERN__ WORD pad1_map_tbl[MAP_TBL_ENTRIES];			// remap table for joystick 1
__EXTERN__ WORD pad2_map_tbl[MAP_TBL_ENTRIES];			// remap table for joystick 2
__EXTERN__ WORD game_map_tbl[MAP_TBL_ENTRIES];			// table for non fight modes

/* texture pool area */
#define TEXTURE_POOL_SIZE	(FLOOR_X*FLOOR_Y+400*1024)

__EXTERN__ long long bkgd_texture_pool[TEXTURE_POOL_SIZE/sizeof(long long)];

__EXTERN__ BYTE *bkgd_texture_ptr;				/// ptr to next available texture space

#if MULTI_ANI_OFF
#define TEXT_POOL_BKGD		0		// main background textures for level
#define TEXT_POOL_ANIM1		1		// background animations for level
#define TEXT_POOL_ANIM2		2		// background animations for level
#define TEXT_POOL_FLOOR		3		// background floor texture area (this should always be last)
#define TEXT_POOL_MAX		4		// max # of texture pools
#else
#define TEXT_POOL_BKGD		0		// main background textures for level
#define TEXT_POOL_FLOOR		1		// background floor texture area (this should always be last)
#define TEXT_POOL_MAX		2		// max # of texture pools
#endif

__EXTERN__ BYTE *texture_base_ptrs[TEXT_POOL_MAX];		// ptrs to start of each texture type

#define bkgd_base_addr (texture_base_ptrs[TEXT_POOL_BKGD])
#define floor_bitmap_addr (texture_base_ptrs[TEXT_POOL_FLOOR])

#if MULTI_ANI_OFF	
#define anim1_base_addr (texture_base_ptrs[TEXT_POOL_ANIM1])
#define anim2_base_addr (texture_base_ptrs[TEXT_POOL_ANIM2])
#endif	


/* image decomp buffer area */
#define DECOMP_BUFFER_SIZE	(1024*100)			/* # of bytes in image decomp buffer */

__EXTERN__ long long image_dcomp_buffer[DECOMP_BUFFER_SIZE/sizeof(long long)];	// decomp buffer for image data
__EXTERN__ LONG *idcomp_base;						// base address of current used decomp buffer
__EXTERN__ LONG *idcomp_ptr;						// decomp buffer ptr to next free area

/* Player Heap Area */
#define PLAYER_HEAP_SIZE	(510000*2)
extern long long player_heap[];	//-NOTE- align  __attribute__ ((aligned(4)));
#define p1_heap (&player_heap[0])
#define p2_heap (&player_heap[PLAYER_HEAP_SIZE/2])

/*
 *	PROTOTYPES
 */

/* system routines */
void init_hardware_system(void);
void mk_vblank_int(void);

/* decompress routines */
BYTE *uncompress_image(BYTE *src);
void unsonyRLE(BYTE *, BYTE **);
void expand_simpleRLE(BYTE *, BYTE **);
void unbetterSimpleRLE(BYTE *src, BYTE **dst);

/* joystick routines */
WORD joy_remap(WORD,WORD *);

/* misc */
void load_perm_art(void);
void ermac(WORD);
void *sys_memset(void *dst,BYTE fill,int count);

/*
 *	MACROS
 */
/* yes & no answers */
#define q_yes return(SYSTEM_CARRY_SET)
#define q_no return(SYSTEM_CARRY_CLR)

#define SET_BLUE(rgb)  ((rgb) & (0x1f<<10))
#define SET_GREEN(rgb)  ((rgb) & (0x1f<<5))
#define SET_RED(rgb)  ((rgb) & 0x1f)

#define GET_BLUE(rgb)  (((rgb) & 0x7c00)>>10)
#define GET_GREEN(rgb)  (((rgb) & 0x3e0)>>5)
#define GET_RED(rgb)  ((rgb) & 0x1f)

#define SET_RGB(r,g,b) (32*32*(b)+32*(g)+(r))

#define DISPLAY_OFF	displayon=0,osViBlack(1)
#define DISPLAY_ON displayon=1,osViBlack(0)

#define GET_BYTE(b) *((BYTE*)b)
#define GET_WORD(w) *((WORD*)w)
#define GET_LONG(l) *((LONG*)l)

#define COMPUTE_ADDR(_base,_offset) ((BYTE *)(_base)+(LONG)(_offset))

//-SONY- u_short DLoadTpage(u_long *pix, int tp, int abr, int x, int y, int w, int h);
//-SONY- int DLoadImage(RECT *rect, u_long *p);

#if DEBUG==0
#define LOADTPAGE(_pix, _tp, _abr, _x, _y, _w, _h) \
	LoadTPage(_pix, _tp, _abr, _x, _y, _w, _h);

#define LOADIMAGE(_rect,_p) \
	LoadImage(_rect,_p)

#else

#define LOADTPAGE(_pix, _tp, _abr, _x, _y, _w, _h) \
		DLoadTPage(_pix, _tp, _abr, _x, _y, _w, _h);

#define LOADIMAGE(_rect,_p) \
	DLoadImage(_rect,_p)

#endif

#endif 	/* __mk_u64main_h__ */

