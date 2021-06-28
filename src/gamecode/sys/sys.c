//////////////////////////////////////////////////////////////////////////////////////////
// sys.c - System functions for the Williams Operating System.
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

#include "sys_defs.h"
#include "typedefs.h"

#include "sys.h"
#include "vid.h"
#include "boot.h"
#include "romcopy.h"
#include "ob.h"
#include "sys_overlays.h"



/* IMPORTANT: sys_rcp_stack MUST be first here to align on a 16-byte address !!!!!!!! */
u64 sys_rcp_stack[SP_DRAM_STACK_SIZE64];
/* IMPORTANT: sys_rcp_stack MUST be first here to align on a 16-byte address !!!!!!!! */


//========================================================================================
// Public system variables:

#define		SYS_OVERLAY_TABLE 1
#include	"sys_overlays.h"
#undef		SYS_OVERLAY_TABLE

#if SYS_DEBUG	// test values:
	char	*tv0, *tv1, *tv2, *tv3, *tv4, *tv5, *tv6, *tv7;
#endif

uint32_t sys_ovmemptr;		// overlay pointer: points to next free physical byte of DRAM
uint32_t sys_obmemptr;		// object pointer: points to start of last object loaded

uint32_t sys_zbuf_phys;						// physical start address of zbuffer (aligned on a 64-byte boundary)
uint32_t sys_fbuf_phys[SYS_NUM_FRAMEBUFS];	// physical start address of frame buffers (aligned on a 64-byte boundary)
uint32_t sys_dbuf_phys[SYS_NUM_DLBUFS];		// physical start address of display-list buffers (aligned on an 8-byte boundary)
uint32_t sys_mbuf_phys[SYS_NUM_DLBUFS];		// physical start address of matrix buffers (aligned on an 8-byte boundary)
uint32_t sys_vbuf_phys[SYS_NUM_DLBUFS];		// physical start address of vertex buffers (aligned on an 8-byte boundary)
uint32_t sys_pbuf_phys[SYS_NUM_DLBUFS];		// physical start address of viewport buffers (aligned on an 8-byte boundary)

uint32_t sys_heap1_start;	// physical start of heap 1
uint32_t sys_heap1_end;		// physical end+1 of heap 1
uint32_t sys_heap2_start;	// physical start of heap 2
uint32_t sys_heap2_end;		// physical end+1 of heap 2

OSMesgQueue	sys_msgque_rsp;	// event message queues:
OSMesg		sys_msgbuf_rsp;
OSMesgQueue	sys_msgque_rdp;
OSMesg		sys_msgbuf_rdp;
OSMesgQueue	sys_msgque_vbi;
OSMesg		sys_msgbuf_vbi;
OSMesgQueue	sys_msgque_ser;
OSMesg		sys_msgbuf_ser;
OSMesgQueue	sys_msgque_joy;
OSMesg		sys_msgbuf_joy;
OSMesgQueue	sys_msgque_tmr;
OSMesg		sys_msgbuf_tmr;

OSMesg		sys_DummyMsg;

int sys_zbuf_stat;

unsigned int sys_random_seed;

static void *have_linker_import_these_from_library[] = {
	osCreateViManager,
	osViSetMode,
	osViSetSpecialFeatures,
	osViModeTable,
	osViSetEvent,
	osViBlack,
};


//========================================================================================
// Private variables:

static uint32_t obsys_ovhandle;


//========================================================================================
// Prototypes:

static int get_overlay_vsize( uint32_t index );
static void loadoverlay( uint32_t index );


//========================================================================================
// Public system functions:

//////////////////////////////////////////////////////////////////////////////////////////
// sys_assertion - assert a system error.
//
// Defined only when SYS_DEBUG is non-zero.
//////////////////////////////////////////////////////////////////////////////////////////
#if SYS_DEBUG
	void sys_assertion( int errcode, char *errinfo ) {
		printf(( "*** SYS_ASSERTION ***\n" ));
		printf(( "  '%s'\n", errinfo ));
		
		assert_perror(errcode);
	}
#endif


//////////////////////////////////////////////////////////////////////////////////////////
// sys_loadoverlay - load overlay.
//
// Loads the specified overlay from cartridge ROM into DRAM.
//////////////////////////////////////////////////////////////////////////////////////////
void sys_loadoverlay( uint32_t index ) {
	uint32_t vsize;

	vsize = get_overlay_vsize( index );

	#if SYS_DEBUG
		if( sys_ovmemptr+vsize > sys_obmemptr ) {
			printf(( "*** INSUFFICIENT MEMORY TO LOAD HEAP1 OVERLAY %d ***\n", index ));
			printf(( "    free heap1 memory: %d bytes\n", sys_heap1_end-sys_ovmemptr ));
			printf(( "    required: %d bytes\n", vsize ));
			for(;;);
		}
	#endif

	loadoverlay( index );
	sys_ovmemptr += vsize;

	v3printf(( "    overlay loaded. free heap1 mem=%d bytes\n", sys_heap1_end-sys_ovmemptr ));
}


//////////////////////////////////////////////////////////////////////////////////////////
// sys_unloadoverlay - unload overlay.
//
// Unloads the overlay specified by the given overlay handle. All code segments
// that have been loaded after the overlay specified in this call must have already
// been unloaded.
//////////////////////////////////////////////////////////////////////////////////////////
void sys_unloadoverlay( uint32_t index ) {
	v3printf(( "  >unloading heap1 overlay %d...\n", index ));
	sys_ovmemptr -= get_overlay_vsize( index );
	v3printf(( "    overlay unloaded. free mem=%d bytes\n", sys_heap1_end-sys_ovmemptr ));
}


//////////////////////////////////////////////////////////////////////////////////////////
// sys_alloc_heap1 - allocates a block of memory from heap 1 and adjusts sys_ovmemptr.
//
// align_mask must be a power of 2 and indicates how the block of memory should be
// aligned. If there is sufficient memory, the starting location of the block is
// returned. Otherwise, 0 is returned.
//
// The caller of this function must be responsible for reading sys_ovmemptr prior to
// calling this function and restoring it when the block of memory is no longer needed.
//////////////////////////////////////////////////////////////////////////////////////////
uint32_t sys_alloc_heap1( uint32_t bytes, uint32_t align_mask ) {
	uint32_t start;

	start = ALIGN_UP( sys_ovmemptr, align_mask );
	if( bytes > (sys_heap1_end - start) ) return( 0 );

	sys_ovmemptr = ALIGN_UP( start+bytes, 4 );
	return( start );
}


//////////////////////////////////////////////////////////////////////////////////////////
// sys_openobsys_z - open the object system for use, loading it into the z-buffer.
//                   Returns the next available object shell.
//////////////////////////////////////////////////////////////////////////////////////////
uint32_t sys_openobsys_z( void ) {
	CRITICAL_DEFS;
	int i;

	for(;;) {
		ENTER_CRITICAL;
		if( vid_dpipe_dataready>=0 && dpipe[vid_dpipe_dataready].zbuf
			|| vid_dpipe_queued2rsp>=0 && dpipe[vid_dpipe_queued2rsp].zbuf
			|| vid_dpipe_reading>=0 && dpipe[vid_dpipe_reading].zbuf
		) {
			sys_zbuf_stat = ZSTAT_OBSYS_REQ;
			LEAVE_CRITICAL;
			for( i=0; i<200; i++ );			// leave ints enabled a bit
		} else {
			sys_zbuf_stat = ZSTAT_OBSYS;
			LEAVE_CRITICAL;
			break;
		}
	}

	loadoverlay( SYS_OVID_OBSYS );
	return( sys_obmemptr );
}


//////////////////////////////////////////////////////////////////////////////////////////
// sys_closeobsys_z - close the object system from use (located in z-buffer).
//
// Once closed, none of the object system (ob_*) calls can be used. See sys_openobsys_z
// for more information.
//////////////////////////////////////////////////////////////////////////////////////////
void sys_closeobsys_z( void ) {
	sys_zbuf_stat = ZSTAT_FREE;
}


//////////////////////////////////////////////////////////////////////////////////////////
// sys_getfreemem - return amount of free memory.
//
// The value returned is the number of unused bytes between data object memory and overlay
// memory.
//////////////////////////////////////////////////////////////////////////////////////////
uint32_t sys_getfreemem( void ) {
	if( sys_obmemptr < sys_heap2_start ) {
		return( sys_obmemptr - sys_ovmemptr );
	}

	return( (sys_heap1_end - sys_ovmemptr) + (sys_obmemptr - sys_heap2_start) );
}


//////////////////////////////////////////////////////////////////////////////////////////
// sys_strcpy - copy a zero-terminated string to another. Copies the zero-terminator, too.
//
// Returns a pointer to the destination string.
//////////////////////////////////////////////////////////////////////////////////////////
#define sys_strcpy strcpy

//////////////////////////////////////////////////////////////////////////////////////////
// sys_strcat - concatinates ss to ds.
//
// Returns a pointer to the destination string.
//////////////////////////////////////////////////////////////////////////////////////////
#define sys_strcat strcat

//////////////////////////////////////////////////////////////////////////////////////////
// sys_aligned_memfill - fills the specified virtual memory range with the specified
//                       value. This is an integer-aligned memory fill operation.
//////////////////////////////////////////////////////////////////////////////////////////
void sys_aligned_memfill( int *memstart, int numints, int val ) {
	int i;

	for( i=0; i<numints; i++ ) memstart[i] = val;
}


//////////////////////////////////////////////////////////////////////////////////////////
// sys_aligned_memclear - zeros the specified virtual memory range. This is an integer-
//                        aligned operation.
//////////////////////////////////////////////////////////////////////////////////////////
void sys_aligned_memclear( int *memstart, int numints ) {
	sys_aligned_memfill( memstart, numints, 0 );
}


//////////////////////////////////////////////////////////////////////////////////////////
// sys_int_blockcopy - copy a block of int-aligned integers to a non-overlapping destination.
//
// Returns a pointer to the destination buffer.
//////////////////////////////////////////////////////////////////////////////////////////
int *sys_int_blockcopy( int *dest, int *source, int num_ints ) {
	int i;

	for( i=0; i<num_ints; i++ ) dest[i] = source[i];
	return( dest );
}


//////////////////////////////////////////////////////////////////////////////////////////
// sys_random - returns a random unsigned integer.
//////////////////////////////////////////////////////////////////////////////////////////
void sys_random_init( void ) {
	srandom(SYS_RANDOM_SEED);
}

#define sys_random random

//	return( rand_r( = sys_random_seed*5 + 1 );


//////////////////////////////////////////////////////////////////////////////////////////
// sys_randomf - returns a random float in the range 0<=r<1.
//////////////////////////////////////////////////////////////////////////////////////////
float sys_randomf( void ) {
	float r;

	r = sys_random() >> 12;
	return( r/(float)0x00100000 );
}


/************************************************************************/
/* sys_random_choice - returns an int in the range 0<=r<choices.        */
/* 'choices' must be <= 0xffff						*/
/************************************************************************/
uint16_t sys_random_choice(uint16_t c) {

    return((sys_random()&0xffff)*c>>16);
}


//////////////////////////////////////////////////////////////////////////////////////////
// sys_random_range - returns a random integer whose range is from min to max, inclusive.
//////////////////////////////////////////////////////////////////////////////////////////
int sys_random_range( int min, int max ) {
	float range;
	int i;

	range = max-min+1;
	i = sys_randomf()*range;

	return( i + min );
}


//////////////////////////////////////////////////////////////////////////////////////////
// sys_random_chance - returns true based on probability of chance. If chance_of_success
//                     is zero, always returns false. If 1.0, always returns true.
//////////////////////////////////////////////////////////////////////////////////////////
int sys_random_chance( float chance_of_success ) {
	return( sys_randomf() < chance_of_success );
}


//////////////////////////////////////////////////////////////////////////////////////////
// sys_log2 - returns the log (base-2) of n, or zero if n is zero.
//////////////////////////////////////////////////////////////////////////////////////////
int sys_log2( uint32_t n ) {
	int i = 0;

	while( n>>1 ) i++;
	return( i );
}


//========================================================================================
// Private functions:

//////////////////////////////////////////////////////////////////////////////////////////
// get_overlay_vsize - returns the virtual size of the specified overlay.
//////////////////////////////////////////////////////////////////////////////////////////
static int get_overlay_vsize( uint32_t index ) {
	return( sys_ovdir[index].vend - sys_ovdir[index].vstart );
}


//////////////////////////////////////////////////////////////////////////////////////////
// loadoverlay - unconditionally loads the specified overlay.
//////////////////////////////////////////////////////////////////////////////////////////
static void loadoverlay( uint32_t index ) {
	uint32_t vstart, romstart, romsize, bss_start, bss_size;

	v3printf(( "  >loading overlay #%d...\n", index ));

	romstart = sys_ovdir[index].romstart;
	romsize = sys_ovdir[index].romend-romstart;
	vstart = sys_ovdir[index].vstart;
	bss_start = sys_ovdir[index].bss_start;
	bss_size = sys_ovdir[index].bss_end - sys_ovdir[index].bss_start;

	v3printf(( "    reading from ROM 0x%08x-0x%08x to virt 0x%08x-0x%08x (%d bytes)\n", romstart, romstart+romsize-1, vstart, vstart+romsize-1, romsize ));
	romcopy_sync( romstart, (void *)vstart, romsize, RCFLAG_FLUSHCODE | RCFLAG_FLUSHDATA );

	v3printf(( "    clearing BSS area 0x%08x - 0x%08x (%d bytes)\n", bss_start, bss_start+bss_size-1, bss_size ));
	sys_aligned_memclear( (int *)bss_start, bss_size>>2 );
}


