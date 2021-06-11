//////////////////////////////////////////////////////////////////////////////////////////
// kstart.c - Kernel entry code for the Williams Operating System.
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

#include "kstart.h"
#include "boot.h"
#include "sys.h"
#include "romcopy.h"
#include "kloop.h"
#include "init_sys.h"
#include "sys_overlays.h"
#include "profile.h"
#include "zbuf.h"


#if SYS_DEBUG
	#define WAIT_FOR_DUBUGGER_TO_START_MAIN_THREAD		0
#else
	#define WAIT_FOR_DUBUGGER_TO_START_MAIN_THREAD		SYS_DEBUG
#endif


extern char _kernelSegmentStart[], _kernelSegmentEnd[];
extern char _initSegmentStart[];


//========================================================================================
// Public variables:

u64 boot_stack[ SYS_BOOT_STACKSIZE/8 ];


//========================================================================================
// Private variables:

static OSThread	idle_thread;
static u64		idle_stack[ SYS_IDLE_STACKSIZE/8 ];

static OSThread	rmon_thread;
static u64		rmon_stack[ RMON_STACKSIZE/8 ];

static OSThread	main_thread;
static u64		main_stack[ SYS_MAIN_STACKSIZE/8 ];

static OSMesg		msgbuf_Pi[ SYS_MSGBUF_SIZE_PI ];
static OSMesgQueue	msgque_Pi;


//========================================================================================
// Prototypes:

void main( void *arg );
static void idle( void *arg );


//========================================================================================
// Public functions:

//////////////////////////////////////////////////////////////////////////////////////////
// kstart_entry - kernel entry called by the U64 bootstrap loader upon power-up.
//
// Performs the following:
//     1) initializes the U64 operating system,
//     3) creates and starts the idle thread
//////////////////////////////////////////////////////////////////////////////////////////
void kstart_entry( void ) {
	int i;

//----------------------------------------------------------------------------------------
// Re-initialize U64 operating system...

	osInitialize();

//----------------------------------------------------------------------------------------
// Create and start idle thread...

	osCreateThread(
		&idle_thread,
		SYS_THREAD_ID_IDLE,
		idle,
		0,
		idle_stack + SYS_IDLE_STACKSIZE/8,
		0
	);

	osStartThread( &idle_thread );
}


//////////////////////////////////////////////////////////////////////////////////////////
// idle - idle thread created and started by kstart_entry.
//
// Always begins with these:
//     1) creates and starts the Vi manager and inits the video mode,
//     2) initializes the Pi manager.
//
// If SYS_DEBUG, performs these next:
//     1) creates and starts the rmon thread,
//     2) creates the main thread,
//     3) sleeps until the debugger starts the main thread manually.
//
// If !SYS_DUBUG, performs these next:
//     1) creates and starts the main thread.
//
//////////////////////////////////////////////////////////////////////////////////////////
static void idle( void *arg ) {

//----------------------------------------------------------------------------------------
// Create and start the Pi manager...

	osCreatePiManager( (OSPri)OS_PRIORITY_PIMGR, &msgque_Pi, msgbuf_Pi, SYS_MSGBUF_SIZE_PI );

//----------------------------------------------------------------------------------------
// DEBUG ONLY: Create and start rmon thread...

#if SYS_DEBUG
	osCreateThread(
		&rmon_thread,
		SYS_THREAD_ID_RMON,
		rmonMain,
		(void *)0,
		rmon_stack + RMON_STACKSIZE/8,
		OS_PRIORITY_RMON
	);

	osStartThread( &rmon_thread );
#endif

//----------------------------------------------------------------------------------------
// Create main thread...

	osCreateThread(
		&main_thread,
		SYS_THREAD_ID_MAIN,
		main,
		0,
		main_stack + SYS_MAIN_STACKSIZE/8,
		SYS_MAIN_THREAD_PRIORITY
	);

//----------------------------------------------------------------------------------------
// RETAIL ONLY: Start main thread...

#if !WAIT_FOR_DUBUGGER_TO_START_MAIN_THREAD
	osStartThread( &main_thread );
#endif

//----------------------------------------------------------------------------------------
// Idle loop...

	for(;;);
}


//////////////////////////////////////////////////////////////////////////////////////////
// main - kernel main thread called by kstart.
//
// Performs the following:
//   1) initializes the system memory map
//	 2) prints startup info,
//   3) loads and executes the kernel initialization overlay,
//   4) unloads the kernel initialization overlay and jumps to cusa_main
//
// If SYS_DEBUG, performs these next:
//   1) lowers the main thread's priority to zero,
//   2) pauses the U64 operating system,
//   3) exits
//////////////////////////////////////////////////////////////////////////////////////////
void main( void *arg ) {
	u32 ovhandle;
#if PROFILE
	u32 pre_profile_heap2_end;
#endif

//----------------------------------------------------------------------------------------
// Initialize the system memory map...

	sys_zbuf_phys = OS_K0_TO_PHYSICAL( zbuf );
	sys_fbuf_phys[0] = ALIGN_UP( SYS_MEMMAP_KERNEL + ((u32)_kernelSegmentEnd - (u32)_kernelSegmentStart), 64 );
	sys_fbuf_phys[1] = ALIGN_UP( sys_fbuf_phys[0] + SYS_FBUF_SIZE, 64 );
#if SYS_NUM_FRAMEBUFS==3
	sys_fbuf_phys[2] = ALIGN_UP( sys_fbuf_phys[1] + SYS_FBUF_SIZE, 64 );
#endif
	sys_dbuf_phys[0] = SYS_MEMMAP_DBUF1;
	sys_dbuf_phys[1] = SYS_MEMMAP_DBUF2;
#if SYS_NUM_DLBUFS==3
	sys_dbuf_phys[2] = SYS_MEMMAP_DBUF3;
#endif
	sys_mbuf_phys[0] = SYS_MEMMAP_MBUF1;
	sys_mbuf_phys[1] = SYS_MEMMAP_MBUF2;
#if SYS_NUM_DLBUFS==3
	sys_mbuf_phys[2] = SYS_MEMMAP_MBUF3;
#endif
	sys_vbuf_phys[0] = SYS_MEMMAP_VBUF1;
	sys_vbuf_phys[1] = SYS_MEMMAP_VBUF2;
#if SYS_NUM_DLBUFS==3
	sys_vbuf_phys[2] = SYS_MEMMAP_VBUF3;
#endif
	sys_pbuf_phys[0] = SYS_MEMMAP_PBUF1;
	sys_pbuf_phys[1] = SYS_MEMMAP_PBUF2;
#if SYS_NUM_DLBUFS==3
	sys_pbuf_phys[2] = SYS_MEMMAP_PBUF3;
#endif

	sys_heap1_start = OS_K0_TO_PHYSICAL( _initSegmentStart );
	sys_heap1_end = SYS_MEMMAP_KERNEL;
#if SYS_NUM_FRAMEBUFS==3
	sys_heap2_start = sys_fbuf_phys[2] + SYS_FBUF_SIZE;
#else
	sys_heap2_start = sys_fbuf_phys[1] + SYS_FBUF_SIZE;
#endif
	sys_heap2_end = SYS_MEMMAP_HEAP2_END;

#if PROFILE
	pre_profile_heap2_end = sys_heap2_end;
	profile_init();
#endif

	sys_ovmemptr = sys_heap1_start;
	sys_obmemptr = ALIGN_DOWN( sys_heap2_end, 8 );

//----------------------------------------------------------------------------------------
// DEBUG ONLY: Print startup info...

#if SYS_DEBUG
	printf(( "\n\n=== CUSA DEBUGGING ENVIRONMENT ===\n\n" ));
	printf(( "  SYS_DEBUG           = %d\n", SYS_DEBUG ));
	printf(( "  SYS_VERBOSE         = %d\n", SYS_VERBOSE ));
	printf(( "  SYS_OPTSPEED        = %d\n", SYS_OPTSPEED ));
	printf(( "\n" ));
	printf(( "   reserved: 0x%08x - 0x%08x (%7d)\n", 0, SYS_DRAM_MIN-1, SYS_DRAM_MIN ));
	printf(( "       zbuf: 0x%08x - 0x%08x (%7d)\n", sys_zbuf_phys, sys_heap1_start-1, sys_heap1_start-sys_zbuf_phys ));
	printf(( "      heap1: 0x%08x - 0x%08x (%7d) [free]\n", sys_heap1_start, sys_heap1_end-1, sys_heap1_end-sys_heap1_start ));
	printf(( "     kernel: 0x%08x - 0x%08x (%7d)\n", SYS_MEMMAP_KERNEL, (SYS_MEMMAP_KERNEL + ((u32)_kernelSegmentEnd - (u32)_kernelSegmentStart))-1, ((u32)_kernelSegmentEnd - (u32)_kernelSegmentStart) ));
	printf(( "      fbuf1: 0x%08x - 0x%08x (%7d)\n", sys_fbuf_phys[0], sys_fbuf_phys[1]-1, sys_fbuf_phys[1]-sys_fbuf_phys[0] ));
#if SYS_NUM_FRAMEBUFS==3
	printf(( "      fbuf2: 0x%08x - 0x%08x (%7d)\n", sys_fbuf_phys[1], sys_fbuf_phys[2]-1, sys_fbuf_phys[2]-sys_fbuf_phys[1] ));
	printf(( "      fbuf3: 0x%08x - 0x%08x (%7d)\n", sys_fbuf_phys[2], sys_heap2_start-1, sys_heap2_start-sys_fbuf_phys[2] ));
#else
	printf(( "      fbuf2: 0x%08x - 0x%08x (%7d)\n", sys_fbuf_phys[1], sys_heap2_start-1, sys_heap2_start-sys_fbuf_phys[1] ));
#endif
	printf(( "      heap2: 0x%08x - 0x%08x (%7d) [free]\n", sys_heap2_start, sys_heap2_end-1, sys_heap2_end-sys_heap2_start ));
#if PROFILE
	printf(( "   profiler: 0x%08x - 0x%08x (%7d) [debug only]\n", sys_heap2_end, pre_profile_heap2_end-1, pre_profile_heap2_end-sys_heap2_end ));
#endif
	printf(( "      pbuf1: 0x%08x - 0x%08x (%7d)\n", SYS_MEMMAP_PBUF1, SYS_MEMMAP_PBUF1+SYS_PBUF_SIZE-1, SYS_PBUF_SIZE ));
	printf(( "      pbuf2: 0x%08x - 0x%08x (%7d)\n", SYS_MEMMAP_PBUF2, SYS_MEMMAP_PBUF2+SYS_PBUF_SIZE-1, SYS_PBUF_SIZE ));
#if SYS_NUM_DLBUFS==3
	printf(( "      pbuf3: 0x%08x - 0x%08x (%7d)\n", SYS_MEMMAP_PBUF3, SYS_MEMMAP_PBUF3+SYS_PBUF_SIZE-1, SYS_PBUF_SIZE ));
#endif
	printf(( "      vbuf1: 0x%08x - 0x%08x (%7d)\n", SYS_MEMMAP_VBUF1, SYS_MEMMAP_VBUF1+SYS_VBUF_SIZE-1, SYS_VBUF_SIZE ));
	printf(( "      vbuf2: 0x%08x - 0x%08x (%7d)\n", SYS_MEMMAP_VBUF2, SYS_MEMMAP_VBUF2+SYS_VBUF_SIZE-1, SYS_VBUF_SIZE ));
#if SYS_NUM_DLBUFS==3
	printf(( "      vbuf3: 0x%08x - 0x%08x (%7d)\n", SYS_MEMMAP_VBUF3, SYS_MEMMAP_VBUF3+SYS_VBUF_SIZE-1, SYS_VBUF_SIZE ));
#endif
	printf(( "      mbuf1: 0x%08x - 0x%08x (%7d)\n", SYS_MEMMAP_MBUF1, SYS_MEMMAP_MBUF1+SYS_MBUF_SIZE-1, SYS_MBUF_SIZE ));
	printf(( "      mbuf2: 0x%08x - 0x%08x (%7d)\n", SYS_MEMMAP_MBUF2, SYS_MEMMAP_MBUF2+SYS_MBUF_SIZE-1, SYS_MBUF_SIZE ));
#if SYS_NUM_DLBUFS==3
	printf(( "      mbuf3: 0x%08x - 0x%08x (%7d)\n", SYS_MEMMAP_MBUF3, SYS_MEMMAP_MBUF3+SYS_MBUF_SIZE-1, SYS_MBUF_SIZE ));
#endif
	printf(( "      dbuf1: 0x%08x - 0x%08x (%7d)\n", SYS_MEMMAP_DBUF1, SYS_MEMMAP_DBUF1+SYS_DBUF_SIZE-1, SYS_DBUF_SIZE ));
	printf(( "      dbuf2: 0x%08x - 0x%08x (%7d)\n", SYS_MEMMAP_DBUF2, SYS_MEMMAP_DBUF2+SYS_DBUF_SIZE-1, SYS_DBUF_SIZE ));
#if SYS_NUM_DLBUFS==3
	printf(( "      dbuf3: 0x%08x - 0x%08x (%7d)\n", SYS_MEMMAP_DBUF3, SYS_MEMMAP_DBUF3+SYS_DBUF_SIZE-1, SYS_DBUF_SIZE ));
#endif
	printf(( "      abufs: 0x%08x - 0x%08x (%7d)\n", SYS_MEMMAP_AUDIOBUFS, SYS_MEMMAP_LIMIT-1, SYS_MEMMAP_LIMIT-SYS_MEMMAP_AUDIOBUFS ));
	printf(( "\n" ));
	printf(( "  total free memory: %d bytes\n", sys_getfreemem() ));
#endif

//----------------------------------------------------------------------------------------
// Create and start romcopy thread...

	osCreateMesgQueue( &romcopy_msgque, &romcopy_msgbuf, 1 );

	osCreateThread(
		&romcopy_thread,
		SYS_THREAD_ID_ROMCOPY,
		romcopy_wait_thread,
		(void *)0,
		romcopy_stack + SYS_ROMCOPY_STACKSIZE/8,
		SYS_ROMCOPY_THREAD_PRIORITY
	);
	osStartThread( &romcopy_thread );		// will return immediately

//----------------------------------------------------------------------------------------
// Initialize kernel...

	sys_loadoverlay( SYS_OVID_INIT );
	init_sys();
	sys_unloadoverlay( SYS_OVID_INIT );

//----------------------------------------------------------------------------------------
// DEBUG ONLY: Print more startup info...

#if SYS_DEBUG
	printf(( "  free memory after resident objects loaded: %d bytes\n", sys_getfreemem() ));
	printf(( "\n" ));
#endif

//----------------------------------------------------------------------------------------
// Jump to main loop...

	kloop_main();				// can return only in DEBUG mode

//----------------------------------------------------------------------------------------
// DEBUG ONLY: Exit from executable...

#if SYS_DEBUG
	osSetThreadPri( 0, 0 );		// lower current thread's priority to zero
	osExit();
#endif
}
