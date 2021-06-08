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


/* vbi_wait_thread messages */
enum VID_MSG {
	VID_MSG_RSP = 1,
	VID_MSG_RDP,
	VID_MSG_VBI,
	VID_MSG_KICKSTART,
	VID_MSG_PRENMI
};


/* rgb color info */
typedef struct o_color {
	BYTE red;
	BYTE green;
	BYTE blue;
	WORD rgb;
} COLOR;

typedef struct dgpacket {
	void *dp_palptr;			// ptr to palette data
	void *dp_imgptr;			// ptr to bitmap image data
	short dp_x,dp_y;			// screen coordinate of bitmap (can be neg, we will clip)
	WORD dp_w,dp_h;				// original width, height of bitmap
	WORD dp_scx,dp_scy;			// scale factors for X & Y (8.8)
	WORD dp_lclip,dp_rclip;		// clipping values for left and right side of image
	WORD dp_flags;				// flag fields (flips, etc)
} DrawPacket;

__EXTERN__ DrawPacket DrawObj;	// current object to draw 
__EXTERN__ short screen_adj_x;	// x screen adj
__EXTERN__ short screen_adj_y;	// y_screen adj

__EXTERN__ void *tmem_palptr;	// current palette in TMEM
__EXTERN__ void *tmem_imgptr;	// current image in TMEM
//__EXTERN__ volatile short dp_flag;	/* set when RDP is active */
//__EXTERN__ volatile short sp_flag;	/* set when RSP is active */
//__EXTERN__ volatile short draw_flag;	/* set when ready to submit gfx tasklist */

__EXTERN__ ALHeap sys_aheap;

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


/* Graphics Subsystem Stuff */
#define GLIST_LEN	(8*1024)


struct dpipe {
	Gfx		*dbuf;		// pointer to virtual address of display-list buffer
	BYTE	*idcmp_base;				// base address of decomp buffer for this dynamic structure
	u32		gfx_bytes;	// # bytes containing valid Gfx data in dbuf
	volatile u32		idle;		// 1=dpipe is idle
	u32		 frame;		// Detmar
};

struct vpipe {
	unsigned short		*fbuf;		// pointer to virtual address of frame buffer
	volatile u32		free;		// 1=vpipe is free
};

__EXTERN__ volatile int vid_dpipe_free;			// next dlist to be written to by game
__EXTERN__ volatile int vid_dpipe_avail;			// next dlist to be written to by game
__EXTERN__ volatile int vid_dpipe_writing;		// dlist being built by game
__EXTERN__ volatile int vid_dpipe_dataready;	// dlist build and ready, but not given to RSP yet
__EXTERN__ volatile int vid_dpipe_reading;		// dlist being processed by RSP

__EXTERN__ volatile int vid_vpipe_writing;		// fbuf being written to by RDP
__EXTERN__ volatile int vid_vpipe_dataready;	// fbuf ready for screen, but not given to osViSwapBuffer yet
__EXTERN__ volatile int vid_vpipe_committed;	// fbuf given to osViSwapBuffer, but not on screen yet
__EXTERN__ volatile int vid_vpipe_onscreen;		// fbuf on screen

__EXTERN__ volatile int vid_prenmi_flag;		// 0=normal, 1=console reset pressed


__EXTERN__ struct dpipe dpipe[SYS_NUM_DLBUFS];		// initialized by init_sys
__EXTERN__ struct vpipe vpipe[SYS_NUM_FRAMEBUFS];	// initialized by init_sys

__EXTERN__ Gfx *Glp;					// next graphics entry
__EXTERN__ u32 Frame;								// simply increments for each VBI
__EXTERN__ volatile u32 Vid_displaying_frame;		// the 'Frame' currently being handled by the RSP
__EXTERN__ u32 Gframe;								// simply increments for each dlist submitted

/* opt to not have to const change combiner mode */
#define COMBINE_OFF		0x0000
#define COMBINE_ON		0x8000
#define COMBINE_RED		0x4000
#define COMBINE_MASK	0x00ff

__EXTERN__ WORD combine_mode;
//========================================================================================
// Public variables:

/* IMPORTANT: sys_rcp_stack MUST be first here to align on a 16-byte address !!!!!!!! */
extern u64 sys_rcp_stack[SP_DRAM_STACK_SIZE64];
/* IMPORTANT: sys_rcp_stack MUST be first here to align on a 16-byte address !!!!!!!! */

#if 0	//SYS_DEBUG	// test values:
	__EXTERN__ char		*tv0, *tv1, *tv2, *tv3, *tv4, *tv5, *tv6, *tv7;
#endif
__EXTERN__ int hang;

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
__EXTERN__  OSMesg		sys_msgbuf_vbi[SYS_MSGBUF_SIZE_VID];

/* Serial/Gamepad */
#define SYS_MSGBUF_SIZE_SER	5
__EXTERN__  OSMesgQueue	sys_msgque_ser;
__EXTERN__  OSMesg		sys_msgbuf_ser[SYS_MSGBUF_SIZE_SER];

#define SYS_MSGBUF_SIZE_JOY	5
__EXTERN__  OSMesgQueue	sys_msgque_joy;
__EXTERN__  OSMesg		sys_msgbuf_joy[SYS_MSGBUF_SIZE_JOY];

/* Timer */
#define SYS_MSGBUF_SIZE_TMR	5
__EXTERN__  OSMesgQueue	sys_msgque_tmr;
__EXTERN__  OSMesg		sys_msgbuf_tmr[SYS_MSGBUF_SIZE_TMR];

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


void kickstart(void);
void start_rsp( OSTask *task );

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

/* VRAM Memory Allocation */
#define BUFFER_WIDTH 320						/* width of display buffer */
#define BUFFER_HEIGHT 240						/* height of display buffer */

#define FLOOR_Y 84					/* # of pixels per floor in height */
#define FLOOR_X 960					/* # of pixels per floor scan line */

/* screen sizing information */
#define SCRTOP 0
#define SCRBOT (BUFFER_HEIGHT-1)
#define SCRLFT 0
#define SCRRGT (BUFFER_WIDTH-1)

#define SCRNSTX SCRLFT
#define SCRNSTY SCRTOP
#define SCRNENDX SCRRGT
#define SCRNENDY SCRBOT
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
#if 0
	ADDRESS	c_fs0;
	ADDRESS	c_fs1;
	ADDRESS	c_fs2;
	ADDRESS	c_fs3;
	ADDRESS	c_fs4;
	ADDRESS	c_fs5;
#endif
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
#if 0
	ADDRESS	c_fs0;
	ADDRESS	c_fs1;
	ADDRESS	c_fs2;
	ADDRESS	c_fs3;
	ADDRESS	c_fs4;
	ADDRESS	c_fs5;
#endif
	long long c_stack[STKSIZE/8]; 	/* stack space for the processor MUST BE DOUBLEWORD aligned */
} CONTEXT;

/*
 *	RAM
 */
__EXTERN__ WORD pad1_map_tbl[MAP_TBL_ENTRIES];			// remap table for joystick 1
__EXTERN__ WORD pad2_map_tbl[MAP_TBL_ENTRIES];			// remap table for joystick 2
__EXTERN__ WORD game_map_tbl[MAP_TBL_ENTRIES];			// table for non fight modes

/* texture pool area */
#define TEXTURE_POOL_SIZE	(304*1024-9000)

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
#define DECOMP_BUFFER_SIZE	(1024*225)			/* # of bytes in image decomp buffer */
__EXTERN__ Gfx glist[2][GLIST_LEN];

__EXTERN__ long long image_dcomp_buffer[2][DECOMP_BUFFER_SIZE/sizeof(long long)];	// decomp buffer for image data
__EXTERN__ LONG *idcomp_base;						// base address of current used decomp buffer
__EXTERN__ LONG *idcomp_ptr;						// decomp buffer ptr to next free area

/* Player Heap Area */
#define PLAYER_HEAP_SIZE	(460000*2)
extern long long player_heap[];	//-NOTE- align  __attribute__ ((aligned(4)));
#define p1_heap (&player_heap[0])
#define p2_heap (&player_heap[(PLAYER_HEAP_SIZE/sizeof(long long))/2])

/*
 *	PROTOTYPES
 */

/* system routines */
void init_hardware_system(void);
void mk_vblank_int(void);

/* decompress routines */
BYTE *uncompress_image(BYTE *src,BYTE *dict);
void unsonyRLE(BYTE *, BYTE **);
void expand_simpleRLE(BYTE *, BYTE **);
void unbetterSimpleRLE(BYTE *src, BYTE **dst);
void dict_uncompress_32(BYTE *src, BYTE **dst, BYTE *dict);
void dict_uncompress_64(BYTE *src, BYTE **dst, BYTE *dict);

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

