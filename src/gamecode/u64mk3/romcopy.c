//////////////////////////////////////////////////////////////////////////////////////////
// romcopy.c - ROM copy functions for the Williams Operating System.
//
// Author: David Schwartz
//////////////////////////////////////////////////////////////////////////////////////////
// THIS CODE IS PROPRIETARY PROPERTY OF WILLIAMS ENTERTAINMENT.
//
// The contents of this file may not be disclosed to third
// parties, copied or duplicated in any form, in whole or in part,
// without the prior written permission of Williams Entertainment.
//////////////////////////////////////////////////////////////////////////////////////////


#include <ultra64.h>

#include "u64main.h"
#include "sys_defs.h"
//#include "typedefs.h"

#include "mkbkgd.h"
#include "mkobj.h"
#include "mkos.h"
#include "romcopy.h"
#include "sys.h"
#include "callback.h"



//========================================================================================
// Private variables:

static struct queue rc_queue_normal;
static struct queue rc_queue_audio;

static struct romcopy *rc_current;


//========================================================================================
// Public variables:

OSThread romcopy_thread;
u64 romcopy_stack[ SYS_ROMCOPY_STACKSIZE/8 ];

OSMesgQueue	romcopy_msgque;
OSMesg		romcopy_msgbuf;
OSIoMesg	romcopy_msgblk;


//========================================================================================
// Prototypes:

static void romcopy_start( struct romcopy *romcopy );

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
#define MAX_XFER	(24*1024L)
#define ROMCOPYLIST	32
struct romcopy romcopy_list[ROMCOPYLIST];
void romcopy_sync( u32 romstart, void *vstart, s32 numbytes, int flags ) 
{
	static struct romcopy romcopy;
	struct romcopy *romcopy_ptr;
	int rc_size;
	
	romcopy.romstart = romstart;
	romcopy.vstart = vstart;
	romcopy.numbytes = numbytes;
	romcopy.flags = flags;
	romcopy.callback.callback = 0;
	romcopy_ptr=romcopy_list;
	
	do
	{
		rc_size=(romcopy.numbytes>MAX_XFER) ? MAX_XFER : romcopy.numbytes;
		
		romcopy_ptr->romstart = romcopy.romstart;
		romcopy_ptr->vstart = romcopy.vstart;
		romcopy_ptr->numbytes = rc_size;
		romcopy_ptr->flags = romcopy.flags;
		romcopy_ptr->callback.callback = 0;
		romcopy_async( romcopy_ptr );
		
		romcopy.numbytes-=rc_size;
		
		if (romcopy.numbytes!=0) 
		{
			romcopy_ptr++;
			romcopy.romstart=(BYTE *)romcopy.romstart+rc_size;
			romcopy.vstart=(BYTE *)romcopy.vstart+rc_size;
#if SYS_DEBUG
			if (romcopy_ptr==&romcopy_list[ROMCOPYLIST]) 
			{
				printf(("ROM COPY SYNC ERROR: RAN OUT QUEUE SPACE\n"));
			}
#endif			
		}
		else break;
	}
	while(1);
	
	while( !(romcopy_ptr->flags & RCFLAG_COMPLETE) );		// wait until last copy has finished
}


//////////////////////////////////////////////////////////////////////////////////////////
// romcopy_async - asynchronously DMA copies between cartridge and DRAM. (non-blocking)
//
// Returns immediately. Use the flags field or the callback function to determine when
// the transfer has completed. If callback is 0, no callback is made. Returns romcopy.
//////////////////////////////////////////////////////////////////////////////////////////
struct romcopy *romcopy_async( struct romcopy *romcopy ) {
	CRITICAL_DEFS;
	struct queue *qp;

	qp = (romcopy->flags & RCFLAG_AUDIO) ? &rc_queue_audio : &rc_queue_normal;
	romcopy->flags &= ~RCFLAG_COMPLETE;

	ENTER_CRITICAL;

	if( rc_current ) {
		if( romcopy->flags & RCFLAG_JAM ) {
			queue_add_head( qp, (struct qlink *)romcopy );
		} else {
			queue_add_tail( qp, (struct qlink *)romcopy );
		}
		LEAVE_CRITICAL;
	} else {
		LEAVE_CRITICAL;
		romcopy_start( romcopy );
	}

	return( romcopy );
}


//////////////////////////////////////////////////////////////////////////////////////////
// romcopy_wait_thread - An independent thread used in conjunction with
//                       romcopy_start. Must be started only by kstart.
//
// IMPORTANT: This function is internally called and managed by the kernel. It should
//            not be called.
//////////////////////////////////////////////////////////////////////////////////////////
void romcopy_wait_thread( void *arg ) {
	for(;;) {
		osRecvMesg( &romcopy_msgque, &sys_DummyMsg, OS_MESG_BLOCK );

		rc_current->flags |= RCFLAG_COMPLETE;
		callback_add( &rc_current->callback );

		if( rc_queue_audio.head ) {
			romcopy_start( (struct romcopy *)queue_remove_head( &rc_queue_audio ) );
		} else {
			if( rc_queue_normal.head ) {
				romcopy_start( (struct romcopy *)queue_remove_head( &rc_queue_normal ) );
			} else {
				rc_current = 0;
			}
		}
	}
}


//========================================================================================
// Private functions:

//////////////////////////////////////////////////////////////////////////////////////////
// romcopy_start - parses the romcopy packet, flushes the specified caches, and sends the
//                 request to the PI manager. romcopy_start simply returns if a null
//                 pointer is passed in.
//////////////////////////////////////////////////////////////////////////////////////////
static void romcopy_start( struct romcopy *romcopy ) 
{
	if( rc_current = romcopy ) {
		if( romcopy->flags & RCFLAG_RAM2CART ) {
			if( romcopy->flags & RCFLAG_FLUSHDATA ) osWritebackDCache( romcopy->vstart, romcopy->numbytes );
		} else {
			if( romcopy->flags & RCFLAG_FLUSHDATA )
			{
			  osWritebackDCacheAll();
			  osInvalDCache( romcopy->vstart, romcopy->numbytes );		
			  
			} 
			if( romcopy->flags & RCFLAG_FLUSHCODE ) osInvalICache( romcopy->vstart, romcopy->numbytes );
		}

		if (vid_prenmi_flag) return;
		
		osPiStartDma(
			&romcopy_msgblk,
			OS_MESG_PRI_NORMAL,
			(romcopy->flags & RCFLAG_RAM2CART) ? OS_WRITE : OS_READ,
			romcopy->romstart,
			romcopy->vstart,
			romcopy->numbytes,
			&romcopy_msgque
		);
	}
}
