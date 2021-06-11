//////////////////////////////////////////////////////////////////////////////////////////
// vid.h
//
// Author: Steve Ranck
//////////////////////////////////////////////////////////////////////////////////////////
// THIS CODE IS PROPRIETARY PROPERTY OF WILLIAMS ENTERTAINMENT.
//
// The contents of this file may not be disclosed to third
// parties, copied or duplicated in any form, in whole or in part,
// without the prior written permission of Williams Entertainment.
//////////////////////////////////////////////////////////////////////////////////////////

#ifndef VID_H
#define VID_H 1

#include "bench.h"


//========================================================================================
// Public definitions:

enum VID_MSG {
	VID_MSG_RSP = 1,
	VID_MSG_RDP,
	VID_MSG_VBI,
	VID_MSG_KICKSTART,
	VID_MSG_PRENMI
};


struct dpipe {
	Gfx					*dbuf;		// pointer to virtual address of display-list buffer
	Mtx					*mbuf;		// pointer to virtual address of matrix buffer
	Vtx					*vbuf;		// pointer to virtual address of vertex buffer
	Vp					*pbuf;		// pointer to virtual address of viewport buffer
	u32					gfx_bytes;	// # bytes containing valid Gfx data in dbuf
	u32					mtx_bytes;	// # bytes containing valid Mtx data in mbuf
	u32					vtx_bytes;	// # bytes containing valid Vtx data in vbuf
	u32					prt_bytes;	// # bytes containing valid Vp data in pbuf
	volatile u32		idle;		// 1=dpipe is idle
	volatile u32		zbuf;		// 1=uses z-buffer
	u32					frame;		// Detmar
};

struct vpipe {
	unsigned short		*fbuf;		// pointer to virtual address of frame buffer
	volatile u32		free;		// 1=vpipe is free
};


//========================================================================================
// Public variables:

// IMPORTANT: vid_rsptask must be the first variable defined in vid.c, so that
//            it will be aligned on a 16-byte boundary.
extern OSTask vid_rsptask;					// RSP task list structure

extern volatile int vid_dpipe_avail;		// number of idle dlists available
extern volatile int vid_dpipe_writing;		// dlist being built by game
extern volatile int vid_dpipe_dataready;	// dlist build and ready, but not given to RSP yet
extern volatile int vid_dpipe_reading;		// dlist being processed by RSP

extern volatile int vid_vpipe_writing;		// fbuf being written to by RDP
extern volatile int vid_vpipe_dataready;	// fbuf ready for screen, but not given to osViSwapBuffer yet
extern volatile int vid_vpipe_committed;	// fbuf given to osViSwapBuffer, but not on screen yet
extern volatile int vid_vpipe_onscreen;		// fbuf on screen

extern volatile int vid_prenmi_flag;		// 0=normal, 1=console reset pressed

#if SYS_TURBO
extern gtGfx *Tlp;								// current turbo Gfx display-list pointer
#endif
extern Gfx *Glp;								// current Gfx display-list pointer
extern Mtx *Mlp;								// current Mtx list pointer
extern Vtx *Vlp;								// current Vtx list pointer
extern Vp  *Plp;								// current Vp list pointer
extern u32 Frame;								// simply increments for each VBI
extern volatile u32 Vid_displaying_frame;		// the 'Frame' currently being handled by the RSP
extern u32 Gframe;								// simply increments for each dlist submitted

#if BENCHBUF
extern int benchbuf_newmax;
extern int Glp_max;
extern int Mlp_max;
extern int Vlp_max;
extern int Plp_max;
#endif

extern struct dpipe dpipe[SYS_NUM_DLBUFS];		// initialized by init_sys
extern struct vpipe vpipe[SYS_NUM_FRAMEBUFS];	// initialized by init_sys

extern OSThread vid_thread;
extern u64 vid_stack[ SYS_VID_STACKSIZE/8 ];


//========================================================================================
// Public functions:

//////////////////////////////////////////////////////////////////////////////////////////
// vid_get_dbuf - get an available display-list buffer.
//
// Sets up Glp and Mlp pointing to empty buffers. Vid is also set up to index into the
// allocated vpipe buffer. If successful, 0 is returned. If no buffers are free, 1 is
// returned.
//////////////////////////////////////////////////////////////////////////////////////////
extern int vid_get_dbuf( void );


//////////////////////////////////////////////////////////////////////////////////////////
// vid_process_gfx - process the current display-list and display it.
//
// Returns immediately.
//////////////////////////////////////////////////////////////////////////////////////////
extern void vid_process_gfx( void );


//////////////////////////////////////////////////////////////////////////////////////////
// vid_sync - returns when all submitted display lists have been displayed. Returns
//            the vpipe index of the on-screen display list.
//////////////////////////////////////////////////////////////////////////////////////////
extern int vid_sync( void );


//////////////////////////////////////////////////////////////////////////////////////////
// vid_wait_thread - This is the main thread that handles RSP/RDP/VBI interrupt events.
//
// IMPORTANT: This function is internally called and managed by the kernel. It should
//            not be called.
//////////////////////////////////////////////////////////////////////////////////////////
extern void vid_wait_thread( void *arg );



#endif
