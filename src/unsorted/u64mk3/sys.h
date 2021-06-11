//////////////////////////////////////////////////////////////////////////////////////////
// sys.h
//
// Author: David Schwartz
//////////////////////////////////////////////////////////////////////////////////////////
// THIS CODE IS PROPRIETARY PROPERTY OF WILLIAMS ENTERTAINMENT.
//
// The contents of this file may not be disclosed to third
// parties, copied or duplicated in any form, in whole or in part,
// without the prior written permission of Williams Entertainment.
//////////////////////////////////////////////////////////////////////////////////////////

#ifndef SYS_H
#define SYS_H 1


//========================================================================================
// Public definitions:

#define CRITICAL_DEFS	u32 imask
#define ENTER_CRITICAL	imask = sys_disable_ints()
#define LEAVE_CRITICAL	sys_restore_ints( imask )

#define ZSTAT_FREE			0
#define ZSTAT_OBSYS_REQ		1
#define ZSTAT_OBSYS			2

extern int hang;

//========================================================================================
// Public variables:

/* IMPORTANT: sys_rcp_stack MUST be first here to align on a 16-byte address !!!!!!!! */
extern u64 sys_rcp_stack[SP_DRAM_STACK_SIZE64];
/* IMPORTANT: sys_rcp_stack MUST be first here to align on a 16-byte address !!!!!!!! */

#if SYS_DEBUG	// test values:
	extern char		*tv0, *tv1, *tv2, *tv3, *tv4, *tv5, *tv6, *tv7;
#endif

extern u32 sys_ovmemptr;		// overlay pointer: points to next free physical byte of DRAM
extern u32 sys_obmemptr;		// object pointer: points to start of last object loaded

extern u32 sys_zbuf_phys;						// physical start address of zbuffer (aligned on a 64-byte boundary)
extern u32 sys_fbuf_phys[SYS_NUM_FRAMEBUFS];	// physical start address of frame buffers (aligned on a 64-byte boundary)
extern u32 sys_dbuf_phys[SYS_NUM_DLBUFS];		// physical start address of display-list buffers (aligned on an 8-byte boundary)
extern u32 sys_mbuf_phys[SYS_NUM_DLBUFS];		// physical start address of matrix buffers (aligned on an 8-byte boundary)
extern u32 sys_vbuf_phys[SYS_NUM_DLBUFS];		// physical start address of vertex buffers (aligned on an 8-byte boundary)
extern u32 sys_pbuf_phys[SYS_NUM_DLBUFS];		// physical start address of viewport buffers (aligned on an 8-byte boundary)

extern u32 sys_heap1_start;		// physical start of heap 1
extern u32 sys_heap1_end;		// physical end+1 of heap 1
extern u32 sys_heap2_start;		// physical start of heap 2
extern u32 sys_heap2_end;		// physical end+1 of heap 2

#if 0
extern OSMesgQueue	sys_msgque_rsp;	// event message queues:
extern OSMesg		sys_msgbuf_rsp;
extern OSMesgQueue	sys_msgque_rdp;
extern OSMesg		sys_msgbuf_rdp;
extern OSMesgQueue	sys_msgque_vbi;
extern OSMesg		sys_msgbuf_vbi[SYS_MSGBUG_SIZE_VID];
extern OSMesgQueue	sys_msgque_ser;
extern OSMesg		sys_msgbuf_ser[SYS_MSGBUF_SIZE_SER];
extern OSMesgQueue	sys_msgque_joy;
extern OSMesg		sys_msgbuf_joy[SYS_MSGBUF_SIZE_JOY];
extern OSMesgQueue	sys_msgque_tmr;
extern OSMesg		sys_msgbuf_tmr[SYS_MSGBUF_SIZE_TMR];
#endif

extern OSMesg		sys_DummyMsg;

extern int sys_zbuf_stat;

extern unsigned int sys_random_seed;


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
// sys_loadoverlay - load overlay.
//
// Loads the specified overlay from cartridge ROM into DRAM. Returns 1 if insufficient
// memory, or 0 if successful.
//////////////////////////////////////////////////////////////////////////////////////////
extern void sys_loadoverlay( unsigned int index );


//////////////////////////////////////////////////////////////////////////////////////////
// sys_unloadoverlay - unload overlay.
//
// Unloads the overlay specified by the given overlay handle. All code segments
// that have been loaded after the overlay specified in this call must have already
// been unloaded.
//////////////////////////////////////////////////////////////////////////////////////////
extern void sys_unloadoverlay( unsigned int index );


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
extern u32 sys_alloc_heap1( u32 bytes, u32 align_mask );


//////////////////////////////////////////////////////////////////////////////////////////
// sys_openobsys_z - open the object system for use, loading it into the z-buffer.
//                   Returns the next available object shell.
//////////////////////////////////////////////////////////////////////////////////////////
extern u32 sys_openobsys_z( void );


//////////////////////////////////////////////////////////////////////////////////////////
// sys_closeobsys_z - close the object system from use (located in z-buffer).
//
// Once closed, none of the object system (ob_*) calls can be used. See sys_openobsys
// for more information.
//////////////////////////////////////////////////////////////////////////////////////////
extern void sys_closeobsys_z( void );


//////////////////////////////////////////////////////////////////////////////////////////
// sys_getfreemem - return amount of free memory.
//
// The value returned is the number of unused bytes between data object memory and overlay
// memory.
//////////////////////////////////////////////////////////////////////////////////////////
extern u32 sys_getfreemem( void );


//////////////////////////////////////////////////////////////////////////////////////////
// sys_strcpy - copy a zero-terminated string to another. Copies the zero-terminator, too.
//
// Returns a pointer to the destination string.
//////////////////////////////////////////////////////////////////////////////////////////
extern char *sys_strcpy( char *ds, char *ss );


//////////////////////////////////////////////////////////////////////////////////////////
// sys_strcat - concatinates ss to ds.
//
// Returns a pointer to the destination string.
//////////////////////////////////////////////////////////////////////////////////////////
extern char *sys_strcat( char *ds, char *ss );


//////////////////////////////////////////////////////////////////////////////////////////
// sys_aligned_memfill - fills the specified virtual memory range with the specified
//                       value. This is an integer-aligned memory fill operation.
//////////////////////////////////////////////////////////////////////////////////////////
extern void sys_aligned_memfill( int *memstart, int numints, int val );


//////////////////////////////////////////////////////////////////////////////////////////
// sys_aligned_memclear - zeros the specified virtual memory range. This is an integer-
//                        aligned operation.
//////////////////////////////////////////////////////////////////////////////////////////
extern void sys_aligned_memclear( int *memstart, int numints );


//////////////////////////////////////////////////////////////////////////////////////////
// sys_int_blockcopy - copy a block of int-aligned integers to a non-overlapping destination.
//
// Returns a pointer to the destination buffer.
//////////////////////////////////////////////////////////////////////////////////////////
extern int *sys_int_blockcopy( int *dest, int *source, int num_ints );


//////////////////////////////////////////////////////////////////////////////////////////
// sys_random - returns a random unsigned integer.
//////////////////////////////////////////////////////////////////////////////////////////
extern unsigned int sys_random( void );


/************************************************************************/
/* sys_random_choice - returns an int in the range 0<=r<choices.        */
/* 'choices' must be <= 0xffff						*/
/************************************************************************/
int sys_random_choice(int c);

//////////////////////////////////////////////////////////////////////////////////////////
// sys_randomf - returns a random float in the range 0<=r<1.
//////////////////////////////////////////////////////////////////////////////////////////
extern float sys_randomf( void );


//////////////////////////////////////////////////////////////////////////////////////////
// sys_random_range - returns a random integer whose range is from min to max, inclusive.
//////////////////////////////////////////////////////////////////////////////////////////
extern int sys_random_range( int min, int max );


//////////////////////////////////////////////////////////////////////////////////////////
// sys_random_chance - returns true based on probability of chance. If chance_of_success
//                     is zero, always returns false. If 1.0, always returns true.
//////////////////////////////////////////////////////////////////////////////////////////
extern int sys_random_chance( float chance_of_success );


//////////////////////////////////////////////////////////////////////////////////////////
// sys_log2 - returns the log (base-2) of n, or zero if n is zero.
//////////////////////////////////////////////////////////////////////////////////////////
extern int sys_log2( unsigned int n );



#endif
