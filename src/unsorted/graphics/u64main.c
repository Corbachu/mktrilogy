/******************************************************************************
 File: u64main.c

 Date: Jan 1996

 (C) Williams Entertainment

 Mortal Kombat III U64 SPECIFIC ROUTINES
******************************************************************************/

#define VID_TRACK_EVENTS	0

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
#include "bench.h"
#include "inflate.h"

#include "wessapi.h"	// audio stuff...
#include "seqload.h"
#include "soundhw.h"
#include "sound.h"
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
extern OSTask	vid_rsptask;

//========================================================================================
// Public variables:

u64 boot_stack[ SYS_BOOT_STACKSIZE/8 ];


//========================================================================================
// Private variables:

static int n64settings[SNDHW_TAG_MAX*2] = {
	SNDHW_TAG_DRIVER_ID,		N64_ID,
	SNDHW_TAG_SOUND_EFFECTS,	1,
	SNDHW_TAG_MUSIC,			1,
	SNDHW_TAG_DRUMS,			1,
	SNDHW_TAG_END,				0
};

static int *settings_list[2] = {
	n64settings,
	0
};

static OSThread	idle_thread;
static u64		idle_stack[ SYS_IDLE_STACKSIZE/8 ];

#if SYS_DEBUG
static OSThread	rmon_thread;
static u64		rmon_stack[ RMON_STACKSIZE/8 ];
#endif

static OSThread	main_thread;
static u64		main_stack[ SYS_MAIN_STACKSIZE/8 ];

static OSMesg		msgbuf_Pi[ SYS_MSGBUF_SIZE_PI ];
static OSMesgQueue	msgque_Pi;

static OSThread vid_vbi_thread;
static u64 vid_vbi_stack[ SYS_VBI_STACKSIZE/8 ];


OSTask *vid_next_atask;		// audio task to be started on next VBI
OSTask *vid_atask_ready;		// audio task ready for submission
OSTask *vid_rsp_atask;		// audio task being processed by RSP
volatile short gfx_yielded;	// 1=gfx task yeild request has been sent to rsp
short vid_rsp_atask_submitted;	// 1=audio task has been submitted to RSP
short vid_prenmi_flag;				// 1=nmi about to happen dont submit anything

//========================================================================================
// Prototypes:

void main( void *arg );
static void idle( void *arg );
void mk3_main(short);
void init_audio(void);

void rsp_event(void);
void rdp_event(void);
void vbi_event(void);
void prenmi_event(void);
static void kickstart_event( void );

//========================================================================================
// Public functions:
static int debug_flag=0;
int mk_dbug=0;

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
    char *ap;
    u32 *argp;
    u32 argbuf[16];
	

//----------------------------------------------------------------------------------------
// Re-initialize U64 operating system...

	osInitialize();


//----------------------------------------------------------------------------------------
// Parse Any Arguments
    argp = (u32 *)RAMROM_APP_WRITE_ADDR;
    for (i=0; i<sizeof(argbuf)/4; i++, argp++) {
	osPiRawReadIo((u32)argp, &argbuf[i]); /* Assume no DMA */
    }
    /* Parse the options */
    ap = (char *)argbuf;
    while (*ap != '\0') {
	while (*ap == ' ')
	    ap++;
	if ( *ap == '-' && *(ap+1) == 'd') {
	    debug_flag = 1;
	    ap += 2;
	} else if ( *ap == '-' && *(ap+1) == 'm') {
	    mk_dbug = 1;
	    ap += 2;
	} else if ( *ap == '-' && *(ap+1) == 'r') {
	    //rdp_DRAM_io = 1;
	    ap += 2;
	} else if ( *ap == '-' && *(ap+1) == '1') {
	    //use_chrome1D = 1;
	    ap += 2;
	} else if ( *ap == '-' && *(ap+1) == '2') {
	    //use_chrome1D = 0;
	    ap += 2;
	}
    }

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
	if (debug_flag==0)
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

	printf(("MORTAL KOMBAT TRILOGY (U64) LIVES!\n"));
	
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
	init_hardware_system();

//----------------------------------------------------------------------------------------
// Jump to main loop...
	mk3_main(mk_dbug);				// can return only in DEBUG mode

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
	game_map_tbl[0]=pad1_map_tbl[0]=pad2_map_tbl[0]=0x0004;				//r1,run
	game_map_tbl[1]=pad1_map_tbl[1]=pad2_map_tbl[1]=0x0008;				//l1,block
	game_map_tbl[2]=pad1_map_tbl[2]=pad2_map_tbl[2]=0x0008;			//r2,run
	game_map_tbl[3]=pad1_map_tbl[3]=pad2_map_tbl[3]=0x0004;			//l2,block

	game_map_tbl[4]=pad1_map_tbl[4]=pad2_map_tbl[4]=0x0010;			//triangle, hk
	game_map_tbl[5]=pad1_map_tbl[5]=pad2_map_tbl[5]=0x0020;			//circle, lk
	game_map_tbl[6]=pad1_map_tbl[6]=pad2_map_tbl[6]=0x0040;			//x, lp
	game_map_tbl[7]=pad1_map_tbl[7]=pad2_map_tbl[7]=0x0080;			//square, hp
	
	game_map_tbl[8]=pad1_map_tbl[8]=pad2_map_tbl[8]=0x0100;			//coll box, (SELECT BUTTON)
	game_map_tbl[9]=pad1_map_tbl[9]=pad2_map_tbl[9]=0;				// unused
	game_map_tbl[10]=pad1_map_tbl[10]=pad2_map_tbl[10]=0;			// unused
	game_map_tbl[11]=pad1_map_tbl[11]=pad2_map_tbl[11]=0x0800;		//start

	game_map_tbl[12]=pad1_map_tbl[12]=pad2_map_tbl[12]=0x1000;		//up
	game_map_tbl[13]=pad1_map_tbl[13]=pad2_map_tbl[13]=0x2000;		//right
	game_map_tbl[14]=pad1_map_tbl[14]=pad2_map_tbl[14]=0x4000;		//down
	game_map_tbl[15]=pad1_map_tbl[15]=pad2_map_tbl[15]=0x8000;		//left

//----------------------------------------------------------------------------------------
// Create and start the Vi manager and init the video mode...

	osCreateViManager( OS_PRIORITY_VIMGR );
	osViSetMode( &osViModeTable[SYS_VIDEO_MODE] );	
	osViSetSpecialFeatures(OS_VI_GAMMA_OFF);	//-DHS-

//----------------------------------------------------------------------------------------
// Clear Frame Buffers  & Setup Double Buffer System
	for( i=0; i<SYS_NUM_FRAMEBUFS; i++ ) 
	{
		sys_aligned_memclear( (int *)cfb[i], (BUFFER_WIDTH*BUFFER_HEIGHT)/ sizeof(int) );
	}
	
	osViSwapBuffer( cfb[0] );
	
	DISPLAY_OFF;
	
	/* setup dbl buffer system */
	dbl_buffer[0].frame_done=dbl_buffer[1].frame_done=DBL_FRAME_READY;		// clear frame done flag
	dbl_buffer_ptr=&dbl_buffer[0];								// set buffer ptr
	Glp=dbl_buffer_ptr->glist;									// set initial grpahics list ptr
	tmem_palptr=tmem_imgptr=NULL;								// no initial graphics or palettes 
	dbl_buffer[0].idcmp_base=(BYTE*)image_dcomp_buffer[0];			// setup base decomp buffers
	dbl_buffer[1].idcmp_base=(BYTE*)image_dcomp_buffer[1];
	dbl_buffer[0].draw_ptr=cfb[0];			// buffer 0 draws to frame 0
	dbl_buffer[0].disp_ptr=cfb[1];			// buffer 0 displays frame 1
	dbl_buffer[1].draw_ptr=cfb[1];			// buffer 1 draws to frame 1
	dbl_buffer[1].disp_ptr=cfb[0];			// buffer 1 displays frame 0
	(BYTE*)idcomp_ptr=dbl_buffer_ptr->idcmp_base;
	
	init_vram_cache();

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
	/* Serial/Joy queue */
	osCreateMesgQueue( &sys_msgque_joy, &sys_msgbuf_joy, 1 );
	osSetEventMesg( OS_EVENT_SI, &sys_msgque_joy, 0 );

	/* VBI queue */
	osCreateMesgQueue( &sys_msgque_vbi, sys_msgbuf_vbi, SYS_MSGBUF_SIZE_VID );
	osSetEventMesg( OS_EVENT_PRENMI, &sys_msgque_vbi, (OSMesg)VID_MSG_PRENMI );
	osSetEventMesg( OS_EVENT_SP, &sys_msgque_vbi, (OSMesg)VID_MSG_RSP );
	osSetEventMesg( OS_EVENT_DP, &sys_msgque_vbi, (OSMesg)VID_MSG_RDP );
	osViSetEvent( &sys_msgque_vbi, (OSMesg)VID_MSG_VBI, 1 );	// last parm: 2 indicates 30 FPS (1=60)
	
	sp_flag=dp_flag=-1;
	draw_flag=0;	

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
// Create and start gamepad wait thread...
	osCreateThread(
		&gamepad_thread,
		SYS_THREAD_ID_GAMEPAD,
		gamepad_wait_thread,
		(void *)0,
		gamepad_stack + SYS_GAMEPAD_STACKSIZE/8,
		SYS_GAMEPAD_THREAD_PRIORITY
	);
	osStartThread( &gamepad_thread );		// will return immediately

//----------------------------------------------------------------------------------------
// Create and start timer wait thread...
	osCreateThread(
		&gamepad_timer_thread,
		SYS_THREAD_ID_GTIMER,
		gamepad_timer_wait_thread,
		(void *)0,
		gamepad_timer_stack + SYS_GTIMER_STACKSIZE/8,
		SYS_GTIMER_THREAD_PRIORITY
	);
	osStartThread( &gamepad_timer_thread );	// will return immediately

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


#if ENABLE_AUDIO
//----------------------------------------------------------------------------------------
// Initialize sound system...

	init_audio();
	sound_reset();
	wess_master_mus_vol_set( 127 );
	wess_master_sfx_vol_set( 127 );
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
		osRecvMesg( &sys_msgque_vbi,(OSMesg *)&vbi_msg, OS_MESG_BLOCK );		// wait for event

		switch (vbi_msg)
		{
			case VID_MSG_RSP:				// end of signal processing
				rsp_event();
				break;
			case VID_MSG_RDP:				// end of display processing
				rdp_event();
				break;
			case VID_MSG_VBI:
				vbi_event();
				break;
			case VID_MSG_KICKSTART:
				kickstart_event();
				break;
			case VID_MSG_PRENMI:
				prenmi_event();
				break;
			default:
				printf(("VBI_MSG %d",vbi_msg));
				break;
		}
	}
}

//******************************************************************************
//******************************************************************************
// RSP Service Routine
void rsp_event(void) 
{
#if BENCH			
	bench_start(BENCHSW_RSP_IDLE);
#endif				

	if (vid_prenmi_flag) return;
	
	if( vid_rsp_atask ) 
	{
#if VID_TRACK_EVENTS	
		printf(("AUDIO RSP\n"));	
#endif
		/* RSP Audio Completed */
		if( vid_rsp_atask_submitted ) 
		{
#if VID_TRACK_EVENTS
			printf(( "rsp a\n" ));
#endif
		
#if BENCH
			bench_stop( BENCHSW_RSP_WORKING_AUD );
#endif
			vid_rsp_atask = 0;
			kickstart();
		} 
		else 
		{
			/* Gfx Yielded */
#if VID_TRACK_EVENTS
			printf(( "rsp graphics yield\n" ));
#endif

#if BENCH
			bench_stop( BENCHSW_RSP_WORKING_GFX );
#endif
			if( !osSpTaskYielded( &vid_rsptask ) ) 
			{
#if VID_TRACK_EVENTS
				printf(( "no yield\n" ));
#endif
				gfx_yielded = 0;
				sp_flag = -1;
			}
			
#if VID_TRACK_EVENTS
			printf(( "start a2\n" ));
			
			if (vid_rsp_atask==0)
				printf(("INVALID AUD\n"));
			
#endif
			start_rsp( vid_rsp_atask );
			vid_rsp_atask_submitted = 1;
		}
	} 
	else 
	{
		/* Gfx Completed */
#if VID_TRACK_EVENTS
		printf(( "rsp g\n" ));
#endif

#if BENCH
		bench_stop( BENCHSW_RSP_WORKING_GFX );
#endif
		sp_flag = -1;
		kickstart();
	}
}

//******************************************************************************
//******************************************************************************
// RDP Service Routine
//******************************************************************************
void rdp_event(void) 
{
	int i;
	
#if BENCH			
	bench_stop(BENCHSW_RDP_WORKING);
	bench_start(BENCHSW_RDP_IDLE);
#endif				

#if VID_TRACK_EVENTS
	printf(("rdp\n"));
#endif
	dp_flag=-1;
	
	/* Register to Swap Draw and Display Buffers */				
	if (!noflip)
		osViSwapBuffer(dbl_buffer_ptr->disp_ptr);
					
	kickstart();
}

//******************************************************************************
// VBI Service Routine
static WORD irq_tick;

void vbi_event(void) 
{
	/* vblank book keeping */
	irq_timer++;
	if ( f_pause<PAUSE_OFF ) 
		irq_tick++;
		
	tick=(irq_tick*55)/60;

	/* audio task release */
	if( vid_next_atask ) 
	{
		vid_atask_ready = vid_next_atask;
		vid_next_atask = 0;
		kickstart_event();	// kickstart now
	}

	kickstart();
	
	gamepad_fps_vbi();			// controller setup
	
#if ENABLE_AUDIO	
	/* next audio function task */
	if (vid_prenmi_flag) 
		return;
//	else vid_next_atask=wess_work();
#endif

	return;
}


//////////////////////////////////////////////////////////////////////////////////////////
// kickstart_event - handles kickstart messages.
//////////////////////////////////////////////////////////////////////////////////////////
static void kickstart_event( void ) 
{
	int i;

	if( vid_rsp_atask ) return;		// exit if the RSP is working on an audio task

	/* is there an audio task */
	if( vid_atask_ready ) 
	{
//		if (sp_flag>=0)	return;
			
#if VID_TRACK_EVENTS
		printf(("AUDIO KICK\n"));	
#endif
		vid_rsp_atask = vid_atask_ready;
		vid_atask_ready = 0;

		/* check if RSP doing the GFX */
		if( sp_flag >= 0 ) 
		{
			gfx_yielded = 1;
			vid_rsp_atask_submitted = 0;

			osSpTaskYield();
#if VID_TRACK_EVENTS
			printf(( "yield g\n" ));
#endif
		}
		else 
		{
			/* start new audio task */
			vid_rsp_atask_submitted = 1;
#if VID_TRACK_EVENTS
			printf(( "start a1\n" ));
#endif
			start_rsp( vid_rsp_atask );
		}
	} 
	else 
	{
		/* resume a yield gfx task */
		if( gfx_yielded ) 
		{
			gfx_yielded = 0;
#if VID_TRACK_EVENTS
			printf(( "start yg\n" ));
#endif
			start_rsp( &vid_rsptask );
		}
		else 
		{
			/* start new gfx task */
			if( sp_flag<0 && dp_flag<0 && draw_flag!=0 ) 
			{

				dp_flag=draw_flag;
				draw_flag=0;
				sp_flag=1;
#if VID_TRACK_EVENTS
				printf(( "start g\n" ));
#endif
				start_rsp( &vid_rsptask );
			}
		}
	}
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
//////////////////////////////////////////////////////////////////////////////////////////
// prenmi_event - handles the pre-NMI event.
//////////////////////////////////////////////////////////////////////////////////////////
void prenmi_event( void ) 
{
	vid_prenmi_flag=1;
//	wess_master_fade( 0, SYS_PRENMI_FADE_MSECS );
}


//////////////////////////////////////////////////////////////////////////////////////////
// kickstart - checks whether an audio or gfx task can be given to the RSP and, if so,
//             does it. This should be called whenever there's a possibility that the RSP
//             (for audio/gfx) or the RDP (gfx) has become idle.
//////////////////////////////////////////////////////////////////////////////////////////
void kickstart( void ) 
{
#if VID_TRACK_EVENTS
			printf(( "kickstart\n" ));
#endif
	osSendMesg( &sys_msgque_vbi, (OSMesg)VID_MSG_KICKSTART, OS_MESG_BLOCK );	// should never block
}

//////////////////////////////////////////////////////////////////////////////////////////
// start_rsp - flushes the data cache, and sends the task structure to the RSP.
//////////////////////////////////////////////////////////////////////////////////////////
void start_rsp( OSTask *task ) 
{
	osWritebackDCacheAll();

#if BENCH
	bench_stop( BENCHSW_RSP_IDLE );

	if( task->t.type == M_GFXTASK ) {
		bench_stop( BENCHSW_RDP_IDLE );
		bench_start( BENCHSW_RSP_WORKING_GFX );
		bench_start( BENCHSW_RDP_WORKING );
	} else {
		bench_start( BENCHSW_RSP_WORKING_AUD );
	}
#endif

	osSpTaskStart( task );
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
 			 dict - ptr to dictionary (if used)

			 Each image has a 32 bit header:
				bits [31..24] = compression type (0=None, 1=64 RLE, 2=256 RLE)
				bits [23..0] = # of bytes in src compress data + 4 bytes for header

 Returns: dest - dest decompression buffer area

 Description:	This routine will uncompress data via the correct routine.  The results
				will be dumped to the current decompress buffer
******************************************************************************/
extern WORD f_white;
BYTE *uncompress_image(BYTE *src,BYTE *dict)
{
	BYTE *dest;
	BYTE *start;
	BYTE *startt;
	WORD i;
	LONG before; 
	LONG after;

/* swap endian format until tool is fixed -DHS- */

	switch (((*( (LONG *)src)) >>24)&0x3f)
	{
		case 0:		// no compression
			start=src+sizeof(LONG);		// skip header block
			break;
		case 1:		// 64 color comp
			start=dest=(BYTE *)idcomp_ptr;
			unsonyRLE(src,&dest);
			idcomp_ptr=(LONG *)(((LONG)(dest+7)) & (~7));		// 8 byte align for u64
   			break;
		case 2:		// 256 color comp
			start=dest=(BYTE *)idcomp_ptr;
			expand_simpleRLE(src,&dest);
			idcomp_ptr=(LONG *)(((LONG)(dest+7)) & (~7));		// 8 byte align for u64
			break;
		case 3:		// better 64 color comp
			start=dest=(BYTE *)idcomp_ptr;
			unbetterSimpleRLE(src,&dest);
			idcomp_ptr=(LONG *)(((LONG)(dest+7)) & (~7));		// 8 byte align for u64
			break;
		case 7:		// 64 color dictionary compression
			start=dest=(BYTE *)idcomp_ptr;		
			dict_uncompress_64(src,&dest,dict);
			idcomp_ptr=(LONG *)(((LONG)(dest+7)) & (~7));		// 8 byte align for u64
			break;
		case 8:		// 32 color dictionary compression
			start=dest=(BYTE *)idcomp_ptr;
			dict_uncompress_32(src,&dest,dict);
			idcomp_ptr=(LONG *)(((LONG)(dest+7)) & (~7));		// 8 byte align for u64
			break;
		case 9:		// background zip files
			start=dest=(BYTE *)idcomp_ptr;
			after=inflate(src,&dest,(BYTE *)&player_heap[((PLAYER_HEAP_SIZE-300*1024)/sizeof(long long))],300*1024);
			idcomp_ptr=(LONG *)(((LONG)(dest+7)) & (~7));		// 8 byte align for u64
			break;
			
	}
/* swap endian format until tool is fixed -DHS- */

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

	packdata = src;
	packlen = packdata + (*((long*)packdata) & 0x00FFFFFF);
	buffer = (WORD *)(*dst);

	for (packdata += 4; packdata < packlen; ) 
	{
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
			
			switch ((partial >> 1) - 1)
			{
CASE64:			
				case 64:	
					*(((WORD *)buffer)++) = someshort;
				case 62:
					*(((WORD *)buffer)++) = someshort;
				case 60:
					*(((WORD *)buffer)++) = someshort;
				case 58:
					*(((WORD *)buffer)++) = someshort;
				case 56:
					*(((WORD *)buffer)++) = someshort;
				case 54:
					*(((WORD *)buffer)++) = someshort;
				case 52:
					*(((WORD *)buffer)++) = someshort;
				case 50:
					*(((WORD *)buffer)++) = someshort;
				case 48:
					*(((WORD *)buffer)++) = someshort;
				case 46:
					*(((WORD *)buffer)++) = someshort;
				case 44:
					*(((WORD *)buffer)++) = someshort;
				case 42:
					*(((WORD *)buffer)++) = someshort;
				case 40:
					*(((WORD *)buffer)++) = someshort;
				case 38:
					*(((WORD *)buffer)++) = someshort;
				case 36:
					*(((WORD *)buffer)++) = someshort;
				case 34:
					*(((WORD *)buffer)++) = someshort;
				case 32:
					*(((WORD *)buffer)++) = someshort;
				case 30:
					*(((WORD *)buffer)++) = someshort;
				case 28:
					*(((WORD *)buffer)++) = someshort;
				case 26:
					*(((WORD *)buffer)++) = someshort;
				case 24:
					*(((WORD *)buffer)++) = someshort;
				case 22:
					*(((WORD *)buffer)++) = someshort;
				case 20:
					*(((WORD *)buffer)++) = someshort;
				case 18:
					*(((WORD *)buffer)++) = someshort;
				case 16:
					*(((WORD *)buffer)++) = someshort;
				case 14:
					*(((WORD *)buffer)++) = someshort;
				case 12:
					*(((WORD *)buffer)++) = someshort;
				case 10:
					*(((WORD *)buffer)++) = someshort;
				case 8:	
					*(((WORD *)buffer)++) = someshort;
				case 6:	
					*(((WORD *)buffer)++) = someshort;
				case 4:	
					*(((WORD *)buffer)++) = someshort;
				case 2:	
					*(((WORD *)buffer)++) = someshort;
			}
			
			if (complete--)
				goto CASE64;
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
	srcBytes = srcBytes + (srcBytes / 3) - (src[0] >> 6);
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

/* compressor type 7 */
void dict_uncompress_64(BYTE *src, BYTE **dst, BYTE *dict)
{
	long src_bytes;
	int sw;
	BYTE ch;
	BYTE *buffer;

	src_bytes = (*(long *)src & 0x00FFFFFF) - (sizeof(long));
	src += sizeof(long);
	buffer=*dst;
	while (src_bytes-- > 0) {
		ch = *src++;
		sw = ch >> 6;
		ch &= 0x3F;
		switch (sw) {
		case 1:
			*buffer++ = ch;
			/* fall thru */
		case 0:
			*buffer++ = ch;
			break;
		case 2: {
			BYTE *dict_ptr;
			
			dict_ptr = dict + ((ch & 0x3F) << 1);
			*buffer++ = *dict_ptr++;
			*buffer++ = *dict_ptr;
		}
			break;
		case 3: {
			int cnt;
			
			for (cnt = *src++, src_bytes--; cnt > 0; cnt--)
				*buffer++ = ch;
		}
			break;
		}
	}
	
	*dst=buffer;
}  /* dict_uncompress_64 */

/* compressor type 8 */
void dict_uncompress_32(BYTE *src, BYTE **dst, BYTE *dict)
{
	long src_bytes;
	BYTE ch;
	BYTE *buffer;

	src_bytes = (*(long *)src & 0x00FFFFFF) - (sizeof(long));
	src += sizeof(long);
	buffer=*dst;
	while (src_bytes-- > 0) {
		ch = *src++;
		if (ch & 0x80) {
			BYTE *dict_ptr;
			
			dict_ptr = dict + ((ch & 0x7F) << 1);
			*buffer++ = *dict_ptr++;
			*buffer++ = *dict_ptr;
		} else {
			int sw;
			
			sw = ch >> 5;
			ch &= 0x1F;
			switch (sw) {
			case 3: {
				int cnt;
				
				for (cnt = *src++, src_bytes--; cnt > 0; cnt--)
					*buffer++ = ch;
			}
				break;
			case 2: {
				int cnt;
				
				for (cnt = ch + 3; cnt > 0; cnt--)
					*buffer++ = 0;
			}
				break;
			case 1:
				*buffer++ = ch;
				/* fall thru */
			case 0:
				*buffer++ = ch;
				break;
			}
		}
	}
	
	*dst=buffer;
}  /* dict_uncompress_32 */

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

#if 1
	switch (error)
	{
		case 1:
			printf(("1 player state has 2 players active (THIS IS NOT GOOD)\n"));
			break;
		case 2:
			printf(("winner_status bad (MKJOY)\n"));
			break;
		case 3:
			printf(("exobj_er (MKUTIL)\n"));
			break;
		case 4:
			printf(("exprc_er (MKUTIL)\n"));
			break;
		case 5:
			printf(("object_setup could not get an object (mkutil)\n"));
			break;
		case 6:
			printf(("ran out of image decomp buffer, (mksony.c)\n"));
			break;
		case 7:
			break;
		case 8:
			printf(("swpal ran out of pals\n"));
			break;
		case 9:
			printf((" rgbstuff could not find a pal\n"));
			break;
		case 10:
			printf(("rgbstuff could not find a pal\n"));
			break;
		case 11:
			printf(("color cycler could not find a pal\n"));
			break;
		case 12:
			printf(("scroll error\n"));
			break;
		case 13:
			printf(("frame_a9 code wasn't to be executed (mkutil)\n"));
			break;
		case 14:
			printf(("delobj, object could not be found (mkobj)\n"));
			break;
		case 15:
			printf(("alloc_vram_perm, can't alloca vram cache entry (mkutil.c)\n"));
			break;
		case 16:
			printf(("process_create, no more process left to allocate (mkos.c)\n"));
			break;
		default:
			printf(("UNKNOWN ERROR\n"));
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
#define MASK_JBLOCK1		0x0002
#define MASK_JRUN1			0x0001
static WORD u64_sony_map_tbl[]= 
//	SONY VALUE		U64 VALUE
{
	0,				// Remap nothing	0
	MASK_JLOK,		// Button_F			1
	MASK_JHIP,		// Button_C			2
	MASK_JLOP,		// Button_D			3
	MASK_JHIK,		// Button_E			4
	MASK_JRUN,		// Button_A			5
	MASK_JBLOCK,	// Button_B			6
	0,				// None				7
	0,				// None				8
	MASK_JRIGHT,	// Button_Right		9
	MASK_JLEFT,		// Button_Left		10
	MASK_JDOWN,		// Button_Down		11
	MASK_JUP,		// Button_Up		12
	MASK_START,		// Button_Start,	13
	MASK_SELECT,	// Button_G(Z)		14
	MASK_JBLOCK1,	// Button_L			15
	MASK_JRUN1,		// Button_R			16
	MASK_JUP,		// Button_Up		17
	MASK_JDOWN,		// Button_Down		18
	MASK_JLEFT,		// Button_Left		19
	MASK_JRIGHT,	// Button_Right		20
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
		u64_button=pad[i].b & 0xfffff;
		swpad=(i==0)?(WORD *)&swcurr.u.p1pad : (WORD *)&swcurr.u.p2pad;
		*swpad=0;
		
		bit=1;
		while (u64_button)
		{
			if (u64_button & 1)
			{
				*swpad|=u64_sony_map_tbl[bit];		// perform remap
			
			}
			
			u64_button>>=1;				// next bit	
			bit++;
		}
		
		i++;
	}
	
	return;
}


extern char _wess_wmdSegmentRomStart[], _wess_wmdSegmentRomEnd[];
extern char _wess_datSegmentRomStart[], _wess_datSegmentRomEnd[];


#if ENABLE_AUDIO
#define AUDIO_HEAP_SIZE	(300*1024)
u64 audio_heap[AUDIO_HEAP_SIZE/sizeof(u64)];

void init_audio( void ) {
	u8 *audioHeapEnd;
    int wmdlength;
    WessConfig wess_config;
    int loaded;
    int modulesize;
    int seqsize;
    char *moduleptr;
    char *seqptr;
	u32 old_ovmemptr;
	void *tempram;

    alHeapInit( &sys_aheap, (BYTE *)audio_heap, AUDIO_HEAP_SIZE );    

    wess_config.audioframerate = 60;
    wess_config.outputsamplerate = 22050;
    wess_config.maxACMDSize=2048;

    wess_config.heap_ptr = &sys_aheap;

    wess_init( &wess_config );

	// now we load the .wmd image into a temporary ram space

    wmdlength = _wess_wmdSegmentRomEnd - _wess_wmdSegmentRomStart;
//	old_ovmemptr = sys_ovmemptr;
//	tempram = OS_PHYSICAL_TO_K0( sys_alloc_heap1( wmdlength, 8 ) );
	tempram=image_dcomp_buffer;
    wess_rom_copy( _wess_wmdSegmentRomStart, tempram, wmdlength );

    wess_dat_location(_wess_datSegmentRomStart);

    modulesize = wess_size_module( tempram, settings_list );
    moduleptr = alHeapAlloc( &sys_aheap, 1, modulesize );
    loaded = wess_load_module( tempram, moduleptr, modulesize, settings_list );
//	sys_ovmemptr = old_ovmemptr;	// deallocates ram

    wess_seq_loader_init(wess_get_master_status(),_wess_wmdSegmentRomStart,NoOpenSeqHandle);

    seqsize = wess_seq_range_sizeof(0,SOUND_FIRST_MUSIC_SEQ_NUM);
    seqptr = alHeapAlloc(&sys_aheap, 1, seqsize);
    seqsize = wess_seq_range_load(0,SOUND_FIRST_MUSIC_SEQ_NUM,seqptr);
	sys_music_buf = alHeapAlloc(&sys_aheap, 1, SOUND_MUSIC_SEQ_BUFFER_SIZE);
    /*
        alHeapAlloc is used one last time to see how much of the heap has been used.

        alHeapAlloc seems to allocate a minimum of 16 bytes.
    */
    audioHeapEnd = alHeapAlloc(&sys_aheap,1,4);
    audioHeapEnd += 16;
	
//printf(("MUSIC BUFFER SIZE %x\n",(ADDRESS)audioHeapEnd-(ADDRESS)audio_heap));
	
}
#endif


