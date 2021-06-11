/******************************************************************************
 File: u64main.c

 Date: Jan 1996

 (C) Williams Entertainment

 Mortal Kombat III U64 SPECIFIC ROUTINES
******************************************************************************/

/* INCLUDES */
#include "u64main.h"
#include "sys_defs.h"

#include "romcopy.h"
#include "gamepad.h"

#include "mkbkgd.h"
#include "mkobj.h"
#include "mkos.h"
#include "mkgame.h"
#include "mkpal.h"
#include "mkmain.h"
#include "mkinit.h"
#include "mkutil.h"
#include "mkjoy.h"
#include "mkguys.h"
#include "mkdma.h"

//******************************************************************************
//******************************************************************************
//			Ultra 64 Startup Code (Begin)
//******************************************************************************
//******************************************************************************
#if SYS_DEBUG
	#define WAIT_FOR_DUBUGGER_TO_START_MAIN_THREAD		0
#else
	#define WAIT_FOR_DUBUGGER_TO_START_MAIN_THREAD		SYS_DEBUG
#endif

extern char _kernelSegmentStart[], _kernelSegmentEnd[];
extern char _initSegmentStart[];

extern u16 cfb[2][BUFFER_WIDTH*BUFFER_HEIGHT];

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

#if 0
static OSThread vid_rdp_thread;
static u64 vid_rdp_stack[ SYS_RDP_STACKSIZE/8 ];
#endif

static OSThread vid_vbi_thread;
static u64 vid_vbi_stack[ SYS_VBI_STACKSIZE/8 ];

//========================================================================================
// Prototypes:

void main( void *arg );
static void idle( void *arg );
void mk3_main(void);

//========================================================================================
// Public functions:

//////////////////////////////////////////////////////////////////////////////////////////
// kstart_entry - kernel entry called by the U64 bootstrap loader upon power-up.
//
// Performs the following:
//     1) initializes the U64 operating system,
//     3) creates and starts the idle thread
//////////////////////////////////////////////////////////////////////////////////////////
void kstart_entry( void ) 
{
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
static void idle( void *arg ) 
{

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
void main( void *arg ) 
{
	u32 ovhandle;
#if PROFILE
	u32 pre_profile_heap2_end;
#endif

	printf(("MORTAL KOMBAT TRILOGY (U64) LIVES!\n"));
	
/*
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

*/

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

//	sys_loadoverlay( SYS_OVID_INIT );
	init_hardware_system();
//	sys_unloadoverlay( SYS_OVID_INIT );

//----------------------------------------------------------------------------------------
// DEBUG ONLY: Print more startup info...

#if 0	// SYS_DEBUG
	printf(( "  free memory after resident objects loaded: %d bytes\n", sys_getfreemem() ));
	printf(( "\n" ));
#endif

//----------------------------------------------------------------------------------------
// Jump to main loop...

	mk3_main();				// can return only in DEBUG mode

//----------------------------------------------------------------------------------------
// DEBUG ONLY: Exit from executable...

#if SYS_DEBUG
	osSetThreadPri( 0, 0 );		// lower current thread's priority to zero
	osExit();
#endif
}

/******************************************************************************
 Function: void init_hardware_system(void)

 By: David Schwartz

 Date: Aug 9, 1994

 Parameters: None

 Returns: None

 Description:	VBLANK ROUTINE
******************************************************************************/
void init_hardware_system(void)
{
	int i, j;

	/* init joy remap stuff */
	game_map_tbl[0]=pad1_map_tbl[0]=pad2_map_tbl[0]=0x0004;			//r1,block
	game_map_tbl[1]=pad1_map_tbl[1]=pad2_map_tbl[1]=0x0004;			//l1,block
	game_map_tbl[2]=pad1_map_tbl[2]=pad2_map_tbl[2]=0x0008;			//r2,run
	game_map_tbl[3]=pad1_map_tbl[3]=pad2_map_tbl[3]=0x0008;			//l2,run

	game_map_tbl[4]=pad1_map_tbl[4]=pad2_map_tbl[4]=0x0020;			//triangle, hk
	game_map_tbl[5]=pad1_map_tbl[5]=pad2_map_tbl[5]=0x0040;			//circle, lk
	game_map_tbl[6]=pad1_map_tbl[6]=pad2_map_tbl[6]=0x0080;			//x, lp
	game_map_tbl[7]=pad1_map_tbl[7]=pad2_map_tbl[7]=0x0010;			//square, hp

	game_map_tbl[8]=pad1_map_tbl[8]=pad2_map_tbl[8]=0x0100;			//coll box, (SELECT BUTTON)
	game_map_tbl[9]=pad1_map_tbl[9]=pad2_map_tbl[9]=0x0200;			//run, needed for sony box controllers
	game_map_tbl[10]=pad1_map_tbl[10]=pad2_map_tbl[10]=0x0400;		//block, needed for sony box controllers
	game_map_tbl[11]=pad1_map_tbl[11]=pad2_map_tbl[11]=0x0800;		//start

	game_map_tbl[12]=pad1_map_tbl[12]=pad2_map_tbl[12]=0x1000;		//up
	game_map_tbl[13]=pad1_map_tbl[13]=pad2_map_tbl[13]=0x2000;		//right
	game_map_tbl[14]=pad1_map_tbl[14]=pad2_map_tbl[14]=0x4000;		//down
	game_map_tbl[15]=pad1_map_tbl[15]=pad2_map_tbl[15]=0x8000;		//left

//----------------------------------------------------------------------------------------
// Create and start the Vi manager and init the video mode...

	osCreateViManager( OS_PRIORITY_VIMGR );
	osViSetMode( &osViModeTable[SYS_VIDEO_MODE] );	//-DHS- setup correctly (possible set to point sampled)
	DISPLAY_OFF;

//----------------------------------------------------------------------------------------
// Clear Frame Buffers  & Setup Double Buffer System
	for( i=0; i<SYS_NUM_FRAMEBUFS; i++ ) 
	{
		sys_aligned_memclear( (int *)cfb[i], (BUFFER_WIDTH*BUFFER_HEIGHT)/ sizeof(int) );
	}
	
	osViSwapBuffer( cfb[0] );
#if 0	
	dbl_buffer[0].frame_done=dbl_buffer[1].frame_done=DBL_FRAME_READY;		// clear frame done flag
	dbl_buffer_ptr=&dbl_buffer[0];								// set buffer ptr
#endif
//----------------------------------------------------------------------------------------
// Initialize gamepad...

	gamepad_rescan_count = GAMEPAD_RESCAN_COUNT_INIT;
	gamepad_vbi_to_start_delay = GAMEPAD_TIMER_DELAY_MAX;

	osCreateMesgQueue( &sys_msgque_ser, &sys_msgbuf_ser, 1 );
	osSetEventMesg( OS_EVENT_SI, &sys_msgque_ser, 0 );
	for( j=0; j<SYS_GAMEPAD_RETRY; j++ ) {
		osContInit( &sys_msgque_ser, &gamepad_bit_pattern, gamepad_status );
		for( i=0; i<MAXCONTROLLERS; i++ ) {
			if( gamepad_status[i].errno == CONT_OVERRUN_ERROR ) break;
		}
		if( i==MAXCONTROLLERS ) break;
	}

	gamepad_update();

	for( i=0; i<SYS_NUM_GAMEPADS; i++ ) {
		gamepad_center[i][0] = SYS_GAMEPAD_CENTER_X;
		gamepad_center[i][1] = SYS_GAMEPAD_CENTER_Y;
		gamepad_deadzone[i] = SYS_GAMEPAD_DEADZONE;
	}

//----------------------------------------------------------------------------------------
// Setup message queues and event triggering...

#if 0
	/* RSP queue */
	osCreateMesgQueue( &sys_msgque_rsp, &sys_msgbuf_rsp, 1 );
	osSetEventMesg( OS_EVENT_SP, &sys_msgque_rsp, 0 );

	/* RDP queue */
	osCreateMesgQueue( &sys_msgque_rdp, &sys_msgbuf_rdp, 1 );
	osSetEventMesg( OS_EVENT_DP, &sys_msgque_rdp, 0 );
#endif

	/* Serial/Joy queue */
	osCreateMesgQueue( &sys_msgque_joy, &sys_msgbuf_joy, 1 );
	osSetEventMesg( OS_EVENT_SI, &sys_msgque_joy, 0 );

	/* VBI queue */
	osCreateMesgQueue( &sys_msgque_vbi, &sys_msgbuf_vbi, 1 );
	osViSetEvent( &sys_msgque_vbi, 0, 1 );			// 2 indicates 30 FPS (1=60)
//	osSetEventMesg( OS_EVENT_DP, &sys_msgque_vbi, 0 );	// set to recieve RDP events
//	osSetEventMesg( OS_EVENT_SP, &sys_msgque_vbi, 0 );	// set to recieve RSP events

	/* Timer queue */
	osCreateMesgQueue( &sys_msgque_tmr, &sys_msgbuf_tmr, 1 );

//----------------------------------------------------------------------------------------
// Create and start video vbi thread...

	osCreateThread(
		&vid_vbi_thread,
		SYS_THREAD_ID_VBI,
		vid_vbi_wait_thread,
		(void *)0,
		vid_vbi_stack + SYS_VBI_STACKSIZE/8,
		SYS_VBI_THREAD_PRIORITY
	);
	osStartThread( &vid_vbi_thread );		// will return immediately

//----------------------------------------------------------------------------------------
// Create and start RSP wait thread...

#if 0
	osCreateThread(
		&rsp_thread,
		SYS_THREAD_ID_RSP,
		rsp_wait_thread,
		(void *)0,
		rsp_stack + SYS_RSP_STACKSIZE/8,
		SYS_RSP_THREAD_PRIORITY
	);
	osStartThread( &rsp_thread );			// will return immediately
#endif	

//----------------------------------------------------------------------------------------
// Create and start RDP wait thread...

#if 0
	osCreateThread(
		&vid_rdp_thread,
		SYS_THREAD_ID_RDP,
		vid_rdp_wait_thread,												   
		(void *)0,
		vid_rdp_stack + SYS_RDP_STACKSIZE/8,
		SYS_RDP_THREAD_PRIORITY
	);
	osStartThread( &vid_rdp_thread );		// will return immediately
#endif

//----------------------------------------------------------------------------------------
// Create and start gamepad wait thread...
#if 1
	osCreateThread(
		&gamepad_thread,
		SYS_THREAD_ID_GAMEPAD,
		gamepad_wait_thread,
		(void *)0,
		gamepad_stack + SYS_GAMEPAD_STACKSIZE/8,
		SYS_GAMEPAD_THREAD_PRIORITY
	);
	osStartThread( &gamepad_thread );		// will return immediately
#endif

//----------------------------------------------------------------------------------------
// Create and start timer wait thread...
#if 1
	osCreateThread(
		&gamepad_timer_thread,
		SYS_THREAD_ID_GTIMER,
		gamepad_timer_wait_thread,
		(void *)0,
		gamepad_timer_stack + SYS_GTIMER_STACKSIZE/8,
		SYS_GTIMER_THREAD_PRIORITY
	);
	osStartThread( &gamepad_timer_thread );	// will return immediately
#endif

//----------------------------------------------------------------------------------------
// Initialize video buffers...

#if 0	//-SONY-
	vpipe[0].free = 0;
	for( i=0; i<SYS_NUM_FRAMEBUFS; i++ ) {
		sys_aligned_memclear( (int *)vpipe[i].fbuf, SYS_FBUF_SIZE / sizeof(int) );
	}
	vid_vpipe_committed = 0;
	osViSwapBuffer( vpipe[0].fbuf );
	vid_sync();
	osViBlack(0);
#endif	

	return;
}

//******************************************************************************
//******************************************************************************
//			Ultra 64 Startup Code (End)
//******************************************************************************
//******************************************************************************






/*
 * MODULE PROTOTYPES
 */
static void stack_switch_bits(LONG,WORD);

/******************************************************************************
 Function: void mk_vblank_int(void)

 By: David Schwartz

 Date: Aug 9, 1994

 Parameters: None

 Returns: None

 Description:	VBLANK ROUTINE
				1) vblank bookeeping
				2) stack various switch processes based on joy input
				3) screen drawing and switching stuff
				4) coin handling processing (MIGHT BE ARCADE SPECIFIC ONLY)
******************************************************************************/

//////////////////////////////////////////////////////////////////////////////////////////
// vid_vbi_wait_thread - An independent thread used to catch vertical retraces.
//
// IMPORTANT: This function is internally called and managed by the kernel. It should
//            not be called.
//////////////////////////////////////////////////////////////////////////////////////////
void vid_vbi_wait_thread( void *arg ) 
{
	int vbi_msg;
	
	for(;;) 
	{
//		osRecvMesg( &sys_msgque_vbi,(OSMesg *)&vbi_msg, OS_MESG_BLOCK );
		osRecvMesg( &sys_msgque_vbi,&sys_DummyMsg, OS_MESG_BLOCK );
		
		mk_vblank_int();			// service intrupt
		gamepad_fps_vbi();			// controller setup
#if 0		
		continue;
		
		switch (vbi_msg)
		{
			case OS_EVENT_DP:				// end of display processing
				dbl_buffer_ptr->frame_done=DBL_FRAME_READY;		// signal drawning is finished
				osViSwapBuffer((dbl_buffer_ptr==&dbl_buffer[0]) ? cfb[0]:cfb[1]);	// tell vblank to swap buffers
				break;
			case OS_EVENT_SP:				// end of signal processing
				break;
			case OS_EVENT_VI:
				mk_vblank_int();			// service intrupt
				gamepad_fps_vbi();			// controller setup
				break;
		}
#endif
		
	}
}

//******************************************************************************
//******************************************************************************
// RDP Service Routine

//******************************************************************************
//******************************************************************************
// RSP Service Routine

//******************************************************************************
//******************************************************************************
// VBI Service Routine
static WORD irq_tick;
extern volatile short or1;
void mk_vblank_int(void)
{
	JOYPAD swprev1,swprev2;
	JOYPAD sw0,swstate;

	/* vblank book keeping */
	irq_timer++;
	if ( f_pause<PAUSE_OFF )
		irq_tick++;
	tick=(irq_tick*55)/60;
	
	/* switch scan routines */
	//-SONY- swcurr.padvalue=PadRead(SONY_PAD_ID);		/* read current joystick (P2:P1) */
	swcurr.padvalue=0;		//-DHS should already be set up by timer intrupt
	or1+=(swcurr.u.p1pad+swcurr.u.p2pad);

	/* remap input to correct values */
	if ( gstate==GS_FIGHTING || gstate==GS_ROUND_INTRO)
	{
		swcurr.u.p1pad=joy_remap(swcurr.u.p1pad,pad1_map_tbl);
		swcurr.u.p2pad=joy_remap(swcurr.u.p2pad,pad2_map_tbl);
	}
	else
	{
		swcurr.u.p1pad=joy_remap(swcurr.u.p1pad,game_map_tbl);
		swcurr.u.p2pad=joy_remap(swcurr.u.p2pad,game_map_tbl);
	}

	/* save switch values */
	swprev1.padvalue=swtemp1.padvalue;					/* retrieve last joystick (P2:P1) */
	swprev2.padvalue=swtemp2.padvalue;					/* retrieve last last joystick (P2:P1) */

	swtemp2.padvalue=swtemp1.padvalue;					/* update last last joystick */
	swtemp1.padvalue=swcurr.padvalue;						/* update last joystick */

	if ((sw0.padvalue=swcurr.padvalue ^ swprev1.padvalue)) 			/* bits that changed */
	{
		/* closed switch tests */
		if ((swstate.padvalue=sw0.padvalue & swcurr.padvalue))		/* bits that changed and just closed */
		{
		 	swstate.padvalue &= ~(swprev1.padvalue | swprev2.padvalue);   	/* only pass if last 2 stats --> open, open */
		 	stack_switch_bits(swstate.padvalue,SW_STACK_CLOSE_OFFSET);
		}

		/* open switch tests */
		swstate.padvalue = ~swcurr.padvalue & swprev1.padvalue;		/* bits that changed and just opened */
		stack_switch_bits(swstate.padvalue,SW_STACK_OPEN_OFFSET);
	}

	//-NOTE- routines that belong here gravity & scroll are with mkos.c

	/* handle coin processing */

	return;
}

/******************************************************************************
 Function: void stack_switch_bits(LONG swstate,WORD swoffset)

 By: David Schwartz

 Date: Aug 9, 1994

 Parameters: swstate = bits to add to switch state
			 swoffset = base offset into table

 Returns: None

 Description:	This routine will add an entry to the switch stack for each
				bit set in the swstate.  These switches are then retrieved in the
				exec(main) loop and joystick processes are setup.
******************************************************************************/
void stack_switch_bits(LONG swstate,WORD swoffset)
{
	LONG sw0;
	WORD i=0;

	while (swstate)
	{
		if ((sw0=swstate & 1))			/* is lowest bit set, if so add to switch stack */
		{
			if (swstack>=&swstmn[SWSTCK_SIZE])	/* check if we have gone past end of stack */
				return;

			*swstack=i+swoffset;		/* push switch number onto stack (0-31)+OFFSET */
			swstack++;
		}

		i++;							/* next bit position */

		swstate=(0xfffffffe & swstate)>>1;	/* remove bit and shift next bit down */
	}

	return;
}

/******************************************************************************
 Function: WORD joy_remap(WORD input,WORD *tbl)

 By: David Schwartz

 Date: Jan 1995

 Parameters: input - input bit pattern from joystick
			 tbl - convert table lookup maps input to output

 Returns: remapped joystick buttons

 Description:	This routine will remap the joystick values, based on the user selctions
******************************************************************************/
WORD joy_remap(WORD input,WORD *tbl)
{
	short i;
	WORD output=0;

	for (i=0;i<MAP_TBL_ENTRIES;i++)
	{
		if (input & 1)
		{
			/* bit set, remap */
			output|=*(tbl+i);		// map table entry contains correct bit to set in output
		}

		input>>=1;					// shift down next bit
	}

	return(output);
}

//******************************************************************************
//******************************************************************************
//		UNCOMPRESS ROUTINES
//******************************************************************************
//******************************************************************************

/******************************************************************************
 Function: BYTE *uncompress_image(BYTE *src)

 By: David Schwartz

 Date: Jan 1995

 Parameters: src - src address compressed image

			 Each image has a 32 bit header:
				bits [31..24] = compression type (0=None, 1=64 RLE, 2=256 RLE)
				bits [23..0] = # of bytes in src compress data + 4 bytes for header

 Returns: dest - dest decompression buffer area

 Description:	This routine will uncompress data via the correct routine.  The results
				will be dumped to the current decompress buffer
******************************************************************************/
BYTE *uncompress_image(BYTE *src)
{
	BYTE *dest;
	BYTE *start;
	WORD i;
	LONG before;
	LONG after;
	
	after=*( (LONG *)src);
	*(((BYTE*)&before)+3)=*(((BYTE*)&after)+0);
	*(((BYTE*)&before)+2)=*(((BYTE*)&after)+1);
	*(((BYTE*)&before)+1)=*(((BYTE*)&after)+2);
	*(((BYTE*)&before)+0)=*(((BYTE*)&after)+3);
	
	*( (LONG *)src)=before;

	switch (((*( (LONG *)src)) >>24)&0x3f)
	{
		case 0:		// no compression
			start=src+sizeof(LONG);
			break;
		case 1:		// 64 color comp
			start=dest=(BYTE *)idcomp_ptr;
			unsonyRLE(src,&dest);
			idcomp_ptr=(LONG *)(((LONG)(dest+3)) & (~3));
   			break;
		case 2:		// 256 color comp
			start=dest=(BYTE *)idcomp_ptr;
			expand_simpleRLE(src,&dest);
			idcomp_ptr=(LONG *)(((LONG)(dest+3)) & (~3));
			break;
		case 3:
			start=dest=(BYTE *)idcomp_ptr;
			unbetterSimpleRLE(src,&dest);
			idcomp_ptr=(LONG *)(((LONG)(dest+3)) & (~3));
			break;
	}

	*( (LONG *)src)=after;

	return(start);
}

/******************************************************************************
 Function: void unsonyRLE(BYTE *src, BYTE **dst)

 By: David Schwartz

 Date: Jan 1995

 Parameters: src - src address compressed image
			 dest - ptr to dest decompression buffer area

 Returns: None

 Description:	This routine will uncompression a src image into a decomp buffer (256 color)
******************************************************************************/
void expand_simpleRLE(BYTE *src, BYTE **dst)
{
	int i;
	signed char *s, *d, ch;
	long srcBytes;

	s = (signed char *)src + sizeof(long);
	d = (signed char *)(*dst);
	srcBytes = (*(long *)src & 0x00FFFFFF) - sizeof(long);
	while (srcBytes > 0)
		if ((i = *s++) < 0)
		{               					/* if < 0 then zero based count */
			ch = *s++;                      /* byte to be repeated */
			for (srcBytes -= 2; i <= 0; i++)
				*d++ = ch;
		}
		else
			for (srcBytes -= i + 2; i >= 0; i--)
				*d++ = *s++;                /* zero based bytes of data */

	*dst=(BYTE *)d;
}  /* expand_simpleRLE */

/******************************************************************************
 Function: void unsonyRLE(BYTE *src, BYTE **dst)

 By: David Schwartz

 Date: Jan 1995

 Parameters: src - src address compressed image
			 dest - ptr to dest decompression buffer area

 Returns: None

 Description:	This routine will uncompression a src image into a decomp buffer (64 color)
******************************************************************************/
void unsonyRLE(BYTE *src, BYTE **dst)
{
	short someshort;
	long Lrunlen;
	int complete, partial;
	BYTE *packdata, *packlen;
	WORD *buffer;

#if 0 //-SONY-
	static void *table[32] = {&&case2, &&case4, &&case6, &&case8, &&case10, &&case12,
							  &&case14, &&case16, &&case18, &&case20, &&case22, &&case24,
							  &&case26, &&case28, &&case30, &&case32, &&case34, &&case36,
							  &&case38, &&case40, &&case42, &&case44, &&case46, &&case48,
							  &&case50, &&case52, &&case54, &&case56, &&case58, &&case60,
							  &&case62, &&case64};
#endif

	packdata = src;
	packlen = packdata + (*((long*)packdata) & 0x00FFFFFF);
	buffer = (WORD *)(*dst);

	for (packdata += 4; packdata < packlen; ) {
		someshort = *(((WORD *)packdata)++);

		if (someshort & 0x8000) {
			Lrunlen = someshort & 0x01FF;
			someshort &= 0x7E00;
			someshort = (someshort >> 1) | (someshort >> 9);
			complete = Lrunlen >> 6;
			partial = Lrunlen & 63;

			if (!partial) {
				partial = 64;
				complete--;
			}

#if 0	//-SONY-
			goto *table[(partial >> 1) - 1];

			case64:	*(((WORD *)buffer)++) = someshort;
			case62:	*(((WORD *)buffer)++) = someshort;
			case60:	*(((WORD *)buffer)++) = someshort;
			case58:	*(((WORD *)buffer)++) = someshort;
			case56:	*(((WORD *)buffer)++) = someshort;
			case54:	*(((WORD *)buffer)++) = someshort;
			case52:	*(((WORD *)buffer)++) = someshort;
			case50:	*(((WORD *)buffer)++) = someshort;
			case48:	*(((WORD *)buffer)++) = someshort;
			case46:	*(((WORD *)buffer)++) = someshort;
			case44:	*(((WORD *)buffer)++) = someshort;
			case42:	*(((WORD *)buffer)++) = someshort;
			case40:	*(((WORD *)buffer)++) = someshort;
			case38:	*(((WORD *)buffer)++) = someshort;
			case36:	*(((WORD *)buffer)++) = someshort;
			case34:	*(((WORD *)buffer)++) = someshort;
			case32:	*(((WORD *)buffer)++) = someshort;
			case30:	*(((WORD *)buffer)++) = someshort;
			case28:	*(((WORD *)buffer)++) = someshort;
			case26:	*(((WORD *)buffer)++) = someshort;
			case24:	*(((WORD *)buffer)++) = someshort;
			case22:	*(((WORD *)buffer)++) = someshort;
			case20:	*(((WORD *)buffer)++) = someshort;
			case18:	*(((WORD *)buffer)++) = someshort;
			case16:	*(((WORD *)buffer)++) = someshort;
			case14:	*(((WORD *)buffer)++) = someshort;
			case12:	*(((WORD *)buffer)++) = someshort;
			case10:	*(((WORD *)buffer)++) = someshort;
			case8:	*(((WORD *)buffer)++) = someshort;
			case6:	*(((WORD *)buffer)++) = someshort;
			case4:	*(((WORD *)buffer)++) = someshort;
			case2:	*(((WORD *)buffer)++) = someshort;

			if (complete--)
				goto case64;
#endif

		}
		else *(((WORD *)buffer)++) = someshort;
	}

	*dst=(BYTE *)buffer;
}  /* unsonyRLE */

/******************************************************************************
 Function: void unbetterSimpleRLE(BYTE *src, BYTE **dst)

 By: David Schwartz

 Date: Jan 1995

 Parameters: src - src address compressed image
			 dest - ptr to dest decompression buffer area

 Returns: None

 Description:	This routine will uncompression a src image into a decomp buffer (64 color)
******************************************************************************/

#define NEXTBYTE(var)   \
switch (state++) {      \
	case 0:                                     \
		c1 = *src++;                            \
		c2 = *src++;                            \
		c3 = *src++;                            \
		var = c1 >> 2;                          \
		break;                                  \
	case 1:                                     \
		var = (c2 >> 4) | ((c1 << 4) & 0x30);   \
		break;                                  \
	case 2:                                     \
		var = ((c2 << 2) & 0x3C) | (c3 >> 6);   \
		break;                                  \
	case 3:                                     \
		var = c3 & 0x3F;                        \
		state = 0;                              \
		break;                                  \
}

void unbetterSimpleRLE(BYTE *src, BYTE **dst)
{
	int i, state;
	BYTE ch, c1, c2, c3;
	long srcBytes;
	BYTE *buffer;

	srcBytes = (*(long *)src & 0x00FFFFFF) - (sizeof(long));
	srcBytes = srcBytes + (srcBytes / 3) - (src[3] >> 6);
	src += sizeof(long);
	buffer = *dst;
	state = 0;
	while (srcBytes > 0)
	{
		NEXTBYTE(i);
		if (i < 32)
		{                       			/* if < 32 then zero based count */
			NEXTBYTE(ch);                   /* byte to be repeated */
			for (srcBytes -= 2; i >= 0; i--)
				*buffer++ = ch;
		}
		else
		{
			i -= 32;
			for (srcBytes -= i + 2; i >= 0; i--)
				NEXTBYTE(*buffer++);           /* zero based bytes of data */
		}
	}

	*dst=buffer;
}  /* unbetterSimpleRLE */


//******************************************************************************
//******************************************************************************
//		MISC ROUTINES
//******************************************************************************
//******************************************************************************
void *sys_memset(void *dst,BYTE fill,int count) 
{
	BYTE *ptr=(BYTE *)dst;
	
	while (count-->0)
		*ptr++=fill;
	
	return(dst);	
	
}

//-DHS- check if needed or remove at some point
/******************************************************************************
 Function: void load_perm_art(void)

 By: David Schwartz

 Date: April 1995

 Parameters: None

 Returns: None

 Description:	load in text fonts and control panel art (perm) only need to do once
******************************************************************************/
void load_perm_art(void)
{

	/* load control panel graphics */
	//-SONY-texture_level_load(LVL_CONTROL,SYNC_LOAD);
	//-SONY-control_floor_tpage=LOADTPAGE((ADDRESS *)p2_heap,TEXTURE_MODE,0,CP_TEXT_X,CP_TEXT_Y,256,256);		// 0 trans for score bar
	//-SONY-DrawSync(0);

	/* load loading message graphics */
	//-SONY-texture_level_load(LVL_LOADING,SYNC_LOAD);
	//-SONY-load_tpage=LOADTPAGE((ADDRESS *)p2_heap,TEXTURE_MODE,0,LOADING_BASE_X,LOADING_BASE_Y,256,70);		// 0 trans for score bar
	//-SONY-DrawSync(0);

	/* load text graphics */
	//-SONY-setup_text_fonts();

	return;
}

/******************************************************************************
 Function: void ermac(WORD error)

 By: David Schwartz

 Date: Aug 9, 1994

 Parameters: error #

 Returns: None

 Description:	Report to terminal an error an lock

 System Errors:
  1 = 1 player state has 2 players active (THIS IS NOT GOOD)
  2 = winner_status bad (JOY)
  3 = exobj_er (MKUTIL)
  4 = exprc_er (MKUTIL)
  5 = object_setup could not get an object (mkutil)
  6 = decomp buffer outage
  7 =
  8 = swpal ran out of pals
  9 = rgbstuff could not find a pal
 10 = rgbstuff could not find a pal
 11 = color cycler could not find a pal
 12 = scroll error
 13 = reached code that was not expected to execute (mkutil, frame_a9)
 14 = delobj, cant find object to delete (mkobj)
 15 = alloc_vram_perm, cant alloc cache entry for perm image (mkutil.c)
 16 = no more process left to allocate, (mkos.c)
******************************************************************************/
void ermac(WORD error)
{
	int wait=0;

#if 0
	switch (error)
	{
		case 1:
			CPRT("1 player state has 2 players active (THIS IS NOT GOOD)");
			break;
		case 2:
			CPRT("winner_status bad (MKJOY)");
			break;
		case 3:
			CPRT("exobj_er (MKUTIL)");
			break;
		case 4:
			CPRT("exprc_er (MKUTIL)");
			break;
		case 5:
			CPRT("object_setup could not get an object (mkutil)");
			break;
		case 6:
			CPRT("ran out of image decomp buffer, (mksony.c)");
			break;
		case 7:
			break;
		case 8:
			CPRT("swpal ran out of pals");
			break;
		case 9:
			CPRT(" rgbstuff could not find a pal");
			break;
		case 10:
			CPRT("rgbstuff could not find a pal");
			break;
		case 11:
			CPRT("color cycler could not find a pal");
			break;
		case 12:
			CPRT("scroll error");
			break;
		case 13:
			CPRT("frame_a9 code wasn't to be executed (mkutil)");
			break;
		case 14:
			CPRT("delobj, object could not be found (mkobj)");
			break;
		case 15:
			CPRT("alloc_vram_perm, can't alloca vram cache entry (mkutil.c)");
			break;
		case 16:
			CPRT("process_create, no more process left to allocate (mkos.c)");
			break;
		default:
			CPRT("UNKNOWN ERROR");
	}
#endif

	while(wait==0)
		POLLING;
	return;
}


/* This function is to place the u64 joystick data into the same format as the sony
	This is the lazy way of doing things, but heck, it makes life easier.
	
	David
*/
static WORD u64_sony_map_tbl[]= 
//	SONY VALUE		U64 VALUE
{
	0,				// Remap nothing
	MASK_JHIK,		// Button_F
	MASK_JLOP,		// Button_C
	MASK_JHIP,		// Button_D
	MASK_JLOK,		// Button_E
	MASK_JRUN,		// Button_A
	MASK_JBLOCK,	// Button_B
	0,				// None
	0,				// None
	MASK_JRIGHT,	// Button_Right
	MASK_JLEFT,		// Button_Left
	MASK_JDOWN,		// Button_Down
	MASK_JUP,		// Button_Up
	MASK_START,		// Button_Start,
	MASK_SELECT,	// Button_G(Z)
	MASK_JBLOCK,		// Button_L
	MASK_JRUN,		// Button_R
	MASK_JUP,		// Button_Up
	MASK_JDOWN,		// Button_Down
	MASK_JLEFT,		// Button_Left
	MASK_JRIGHT,	// Button_Right
};
void map_u64_to_sony(void) 
{
	int i=0;
	int bit;
	LONG u64_button;
	WORD *swpad;
	
	swcurr.padvalue=0;
	
	while (i<gamepad_count && i<2)
	{
		bit=0;
		u64_button=(LONG)(pad[i].b);
		swpad=(i==0)?(WORD *)&swcurr.u.p1pad : (WORD *)&swcurr.u.p2pad;
		*swpad=0;
		while (++bit<=sizeof(u64_sony_map_tbl)/sizeof(u64_sony_map_tbl[0]))
		{
			if (u64_button & 1)
				*swpad|=u64_sony_map_tbl[bit];		// perform remap
			
			u64_button>>=1;				// next bit	
		}
		
		i++;
	}
	
	return;
}


static long ecs_imask;
void EnterCriticalSection(void) 
{
	ecs_imask=sys_disable_ints();
	return;
}

void ExitCriticalSection(void) 
{
	sys_restore_ints(ecs_imask);
	return;
}
