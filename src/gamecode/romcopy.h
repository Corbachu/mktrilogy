//////////////////////////////////////////////////////////////////////////////////////////
// romcopy.h
//
// Author: David Schwartz
//////////////////////////////////////////////////////////////////////////////////////////
// THIS CODE IS PROPRIETARY PROPERTY OF WILLIAMS ENTERTAINMENT.
//
// The contents of this file may not be disclosed to third
// parties, copied or duplicated in any form, in whole or in part,
// without the prior written permission of Williams Entertainment.
//////////////////////////////////////////////////////////////////////////////////////////

#ifndef ROMCOPY_H
#define ROMCOPY_H 1

#include "queue.h"
#include "callback.h"


//========================================================================================
// Public definitions:

struct romcopy {
	struct callback	callback;			// private: queue & callback pointers
	u32				romstart;			// rom start address (2-byte boundary)
	void			*vstart;			// dram virtual start address (8-byte boundary)
	s32				numbytes;			// transfer size (2-byte boundary)
	volatile u32	flags;				// see RCFLAG_* for details
	int				user;				// general-purpose user field
};

#define RCFLAG_RAM2CART		0x0001	// transfer from DRAM to cartridge
#define RCFLAG_FLUSHDATA	0x0002	// flush or invalidate the CPU data cache
#define RCFLAG_FLUSHCODE	0x0004	// flush or invalidate the CPU instruction cache
#define RCFLAG_AUDIO		0x0008	// audio rom copy request (higher priority)
#define RCFLAG_JAM			0x0010	// jam request to front of queue
#define RCFLAG_COMPLETE		0x8000	// set by system when transfer has completed


//========================================================================================
// Public variables:

extern OSThread romcopy_thread;
extern u64 romcopy_stack[ SYS_ROMCOPY_STACKSIZE/8 ];

extern OSMesgQueue	romcopy_msgque;
extern OSMesg		romcopy_msgbuf;
extern OSIoMesg		romcopy_msgblk;


//========================================================================================
// Public system functions:

//////////////////////////////////////////////////////////////////////////////////////////
// romcopy_sync - synchronously DMA copies between cartridge ROM and DRAM. (blocking)
//
// Returns when complete. romstart is the starting cartridge ROM address. vstart is
// the starting DRAM virtual address. numbytes is the number of bytes in the transfer.
// flags may contain one or more RCFLAG_* bit set for various alterations.
//
// NOTE: romstart must be aligned on an even address. vstart must be aligned on an
//       8-byte boundary. numbytes should be even.
//////////////////////////////////////////////////////////////////////////////////////////
extern void romcopy_sync( u32 romstart, void *vstart, s32 numbytes, int flags );


//////////////////////////////////////////////////////////////////////////////////////////
// romcopy_async - asynchronously DMA copies between cartridge and DRAM. (non-blocking)
//
// Returns immediately. Use the flags field or the callback function to determine when
// the transfer has completed. If callback is 0, no callback is made. Returns romcopy.
//////////////////////////////////////////////////////////////////////////////////////////
extern struct romcopy *romcopy_async( struct romcopy *romcopy );


//////////////////////////////////////////////////////////////////////////////////////////
// romcopy_wait_thread - An independent thread used in conjunction with
//                       romcopy_start. Must be started only by kstart.
//
// IMPORTANT: This function is internally called and managed by the kernel. It should
//            not be called.
//////////////////////////////////////////////////////////////////////////////////////////
extern void romcopy_wait_thread( void *arg );



#endif
