//////////////////////////////////////////////////////////////////////////////////////////
// init_sys.c - initialization code for kernel.
//
// Author: Steve Ranck
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

#include "init_sys.h"
#include "sys.h"
#include "romcopy.h"
#include "vid.h"
#include "gfx_ybuf.h"
#include "mtx.h"
#include "kloop.h"
#include "gamepad.h"
#include "slider.h"
#include "timer.h"
#include "gutil.h"
#include "text.h"
#include "cusa.h"
#include "ob.h"
#include "ob_ids.h"
#include "sys_overlays.h"
#include "attract.h"
#include "race.h"
#include "garage.h"
#include "host.h"
#include "tool.h"
#include "cusapad.h"
#include "logo.h"
#include "cartool.h"
#include "hot.h"
#include "hud.h"
#include "mon.h"
#include "sound.h"

#include "wessapi.h"	// audio stuff...
#include "seqload.h"
#include "soundhw.h"
#include "cusan64.h"
#include "sound.h"

#include "prez.h"		// for debugging only
#include "sky.h"		// for debugging only
#include "press.h"		// for debugging only


extern char _wess_wmdSegmentRomStart[], _wess_wmdSegmentRomEnd[];
extern char _wess_datSegmentRomStart[], _wess_datSegmentRomEnd[];


int make_a_bss_segment;		// dummy variable to cause compiler to create bss segment


//========================================================================================
// Private definitions:

#if 1
#define UCODE_TEXT_START	(u64 *)gspFast3D_fifoTextStart
#define UCODE_DATA_START	(u64 *)gspFast3D_fifoDataStart
#else
#define UCODE_TEXT_START	(u64 *)gspF3DNoN_fifoTextStart
#define UCODE_DATA_START	(u64 *)gspF3DNoN_fifoDataStart
#endif

#define MSC2S( m, s, c ) ((float)(m)*60.0 + (float)(s) + (float)(c)/100.0)

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


//========================================================================================
// Private variables:

static struct init_hot { char *initials; float time; } init_hot[10] = {
	"SER", MSC2S( 2,  1, 0 ),		// Steve Erwin Ranck
	"GGN", MSC2S( 2,  2, 0 ),		// Greg George Newton
	"DP\0", MSC2S( 2,  3, 0 ),		// Detmar Peterke
	"SSP", MSC2S( 2,  4, 0 ),		// Scott S. Patterson
	"OH\0", MSC2S( 2,  6, 0 ),		// Orpheus Hanley
	"BDJ", MSC2S( 2,  8, 0 ),		// Brian David Johnson
	"SJK", MSC2S( 2, 10, 0 ),		// Steve J. Kramer
	"DAW", MSC2S( 2, 12, 0 ),		// Dave Allen Wagner
	"MCG", MSC2S( 2, 14, 0 ),		// Mark Charles Guidarelli
	"CAC", MSC2S( 2, 16, 0 ),		// Command And Conquer
};


//========================================================================================
// Prototypes:

static void init_audio( void );


//========================================================================================
// Public functions:

//////////////////////////////////////////////////////////////////////////////////////////
// init_sys - initialize kernel data and u64 hardware stuff.
//////////////////////////////////////////////////////////////////////////////////////////
void init_sys( void ) {
	int i, j;
	u16 *rpm_pal;
	unsigned int rpm_shell;

//----------------------------------------------------------------------------------------
// Initialize vpipe structures...

	for( i=0; i<SYS_NUM_DLBUFS; i++ ) {
		dpipe[i].dbuf = (Gfx *)OS_PHYSICAL_TO_K0( sys_dbuf_phys[i] );
		dpipe[i].mbuf = (Mtx *)OS_PHYSICAL_TO_K0( sys_mbuf_phys[i] );
		dpipe[i].vbuf = (Vtx *)OS_PHYSICAL_TO_K0( sys_vbuf_phys[i] );
		dpipe[i].pbuf = (Vp *)OS_PHYSICAL_TO_K0( sys_pbuf_phys[i] );
		dpipe[i].idle = 1;
	}
	for( i=0; i<SYS_NUM_FRAMEBUFS; i++ ) {
		vpipe[i].fbuf = (unsigned short *)OS_PHYSICAL_TO_K1( sys_fbuf_phys[i] );
		vpipe[i].free = 1;
	}

	vid_rsptask.t.type = M_GFXTASK;
	vid_rsptask.t.ucode_boot = (u64 *)rspbootTextStart;
	vid_rsptask.t.ucode_boot_size = (int)rspbootTextEnd - (int)rspbootTextStart;
	vid_rsptask.t.ucode = UCODE_TEXT_START;
	vid_rsptask.t.ucode_size = SP_UCODE_SIZE;
	vid_rsptask.t.ucode_data = UCODE_DATA_START;
	vid_rsptask.t.ucode_data_size = SP_UCODE_DATA_SIZE;
	vid_rsptask.t.dram_stack = sys_rcp_stack;
	vid_rsptask.t.dram_stack_size = SP_DRAM_STACK_SIZE8;
	vid_rsptask.t.output_buff = OS_PHYSICAL_TO_K0( sys_cbuf_phys );
	vid_rsptask.t.output_buff_size = (u64 *)( (u32)OS_PHYSICAL_TO_K0( sys_cbuf_phys ) + (u32)SYS_CBUF_SIZE );
	vid_rsptask.t.yield_data_ptr = gfx_ybuf;
	vid_rsptask.t.yield_data_size = OS_YIELD_DATA_SIZE;

	vid_dpipe_avail = 1;
	vid_dpipe_writing = -1;
	vid_dpipe_dataready = -1;
	vid_dpipe_reading = -1;

	vid_vpipe_writing = -1;
	vid_vpipe_dataready = -1;
	vid_vpipe_committed = -1;
	vid_vpipe_onscreen = -1;

//----------------------------------------------------------------------------------------
// Create and start the Vi manager and init the video mode...

	osCreateViManager( OS_PRIORITY_VIMGR );
	osViSetMode( &osViModeTable[SYS_VIDEO_MODE] );
	osViSetSpecialFeatures( OS_VI_GAMMA_OFF );
	osViBlack(1);

//----------------------------------------------------------------------------------------
// Initialize gamepad...

#if 1
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
#endif

//----------------------------------------------------------------------------------------
// Setup message queues and event triggering...

	osCreateMesgQueue( &sys_msgque_joy, &sys_msgbuf_joy, 1 );
	osSetEventMesg( OS_EVENT_SI, &sys_msgque_joy, 0 );

	osCreateMesgQueue( &sys_msgque_tmr, &sys_msgbuf_tmr, 1 );
	osCreateMesgQueue( &sys_msgque_vid, sys_msgbuf_vid, SYS_MSGBUF_SIZE_VID );

	osSetEventMesg( OS_EVENT_PRENMI, &sys_msgque_vid, (OSMesg)VID_MSG_PRENMI );
	osSetEventMesg( OS_EVENT_SP, &sys_msgque_vid, (OSMesg)VID_MSG_RSP );
	osSetEventMesg( OS_EVENT_DP, &sys_msgque_vid, (OSMesg)VID_MSG_RDP );
	osViSetEvent( &sys_msgque_vid, (OSMesg)VID_MSG_VBI, 1 );	// last parm: 2 indicates 30 FPS (1=60)

//----------------------------------------------------------------------------------------
// Create and start video thread...

	osCreateThread(
		&vid_thread,
		SYS_THREAD_ID_VID,
		vid_wait_thread,
		(void *)0,
		vid_stack + SYS_VID_STACKSIZE/8,
		SYS_VID_THREAD_PRIORITY
	);
	osStartThread( &vid_thread );		// will return immediately

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

	vpipe[0].free = 0;
	for( i=0; i<SYS_NUM_FRAMEBUFS; i++ ) {
		sys_aligned_memclear( (int *)vpipe[i].fbuf, SYS_FBUF_SIZE / sizeof(int) );
	}
	vid_vpipe_committed = 0;
	osViSwapBuffer( vpipe[0].fbuf );
	vid_sync();
	osViBlack(0);

//----------------------------------------------------------------------------------------
// Convert pre-calculated matrices into RSP format...

	mtx_rsp_fixup( &Mtx_cam_identity,   &Mtx_cam_identity + 1 );
	mtx_rsp_fixup( &Mtx_knocked_flat,   &Mtx_knocked_flat + 1 );
	mtx_rsp_fixup( &Mtx_ortho1,   		&Mtx_ortho1 + 1 );
	mtx_rsp_fixup( &Mtx_ortho2,   		&Mtx_ortho2 + 1 );
	mtx_rsp_fixup( &Mtx_persp1,   		&Mtx_persp1 + 1 );
	mtx_rsp_fixup( &Mtx_persp2,   		&Mtx_persp2 + 1 );
	mtx_rsp_fixup( &Mtx_perspmap, 		&Mtx_perspmap + 1 );

//----------------------------------------------------------------------------------------
// Set random seed...

	sys_random_seed = SYS_RANDOM_SEED;

//----------------------------------------------------------------------------------------
// Initialize sliders, flashers, and text...

	slider_system_init();
	timer_flasher_init();
	text_system_init();

//----------------------------------------------------------------------------------------
// Load global objects...

	sys_openobsys_z();
	text_palloc = ob_load( OBID_FONT_PAL );								// font palette
	ob_loadgroup_phys( OBID_FONT_GROUP, (u32 *)text_rlaloc );			// font textures
	ob_loadgroup_phys( OBID_REDNUM_GROUP, (u32 *)text_redloc );			// red number objects
	sys_closeobsys_z();

	car_load_primary_cars();
	car_load_additional_cars();

//----------------------------------------------------------------------------------------
// Read in RPM palette gradient...

	sys_openobsys_z();
	rpm_shell = ob_shell();

	rpm_pal = (u16 *)OS_PHYSICAL_TO_K0( ob_load( OBID_HUD_RPMS_TGA_PAL ) );
	for( i=0; i<HUD_RPM_GRADIENT_STEPS; i++ ) {
		cusa_hud_rpm_gradient[i] = rpm_pal[ i+HUD_RPM_FIRST_PALETTE_ENTRY ];
	}
	for( i=0; i<4; i++ ) {
		cusa_hud_gear_colors[i] = rpm_pal[ i+HUD_GEAR_FIRST_PALETTE_ENTRY ];
	}

	ob_freeshell( rpm_shell );
	sys_closeobsys_z();

//----------------------------------------------------------------------------------------
// Initialize general game data...

	cusa_init();

	Difficulty = 2;
	Metric = 0;
	Volume[0] = 0.95;
	Volume[1] = 0.95;
	TwoPlayerSplitSounds = 1;	// player 1's sounds on left channel, player 2's sounds on right channel

	Racers_switch = 1;
	Traffic_switch = 1;
	cusa_update_racers_and_traffic();

	prior_overlay = CUSA_OVLOAD_NONE;
	cusa_init_player( 0 );
	cusapad_init( 0, 0 );
	cusapad_init( 1, 0 );

	for( i=0; i<TRACK_COUNT+1; i++ ) {
		for( j=0; j<10; j++ ) {
			hot_times[i][j].initials[0] = init_hot[j].initials[0];
			hot_times[i][j].initials[1] = init_hot[j].initials[1];
			hot_times[i][j].initials[2] = init_hot[j].initials[2];
			hot_times[i][j].time = init_hot[j].time + (float)i/100.0;
		}
	}
	for( j=0; j<10; j++ ) {
		hot_times[TRACK_USA][j].time = init_hot[j].time * 14.0 + (float)TRACK_USA/100.0;
	}

	for( i=0; i<TRACK_COUNT; i++ ) {
		for( j=0; j<CUSA_MAX_CHECKPOINTS; j++ ) {
			cusa_checkpoint_split_csecs[i][j] = -1;
		}
	}

#if TOOL_ENABLED
	tool_init();
#endif

//----------------------------------------------------------------------------------------
// Initialize sound system...

	init_audio();
	sound_reset();
	wess_master_mus_vol_set( Volume[0] * 127 );
	wess_master_sfx_vol_set( Volume[1] * 127 );

//----------------------------------------------------------------------------------------
// Initialize crash monitor system...

#if MON_ENABLED
	mon_init();
#endif

//----------------------------------------------------------------------------------------
// Set up initial main loop handler function...

	prior_overlay = KLOOP_OVLOAD_NONE;
#if 0
	Control_func = kloop_idle_control_func;
	Control_parm = 0;
	Control_overlay = KLOOP_OVLOAD_NONE;
#endif
#ifdef STEVE
	#if CARTOOL_ENABLED
		Control_func = cartool_init;
		Control_parm = 0;
		Control_overlay = KLOOP_OVLOAD_NONE;
	#else
		Control_func = logo_init;
		Control_parm = 1;
		Control_overlay = KLOOP_FORCE_OVLOAD( SYS_OVID_WRAPPERS );
	#endif
#endif
#ifdef DETMAR
		Control_func = logo_init;
		Control_parm = 1;
		Control_overlay = KLOOP_FORCE_OVLOAD( SYS_OVID_WRAPPERS );
#endif

//Control_func = prez_start;
//Control_func = sky_test;
}


static void init_audio( void ) {
	u8 *audioHeapEnd;
    int wmdlength;
    WessConfig wess_config;
	WessTweakAttr wess_tweak;
    int loaded;
    int modulesize;
    int seqsize;
    char *moduleptr;
    char *seqptr;
	u32 old_ovmemptr;
	void *tempram;

	wess_set_error_callback( sound_wess_error_handler );

    alHeapInit( &sys_aheap, OS_PHYSICAL_TO_K0( SYS_MEMMAP_AUDIOBUFS ), SYS_ABUF_SIZE );

	wess_config.audioframerate = SYS_AUDIO_WORKFREQ;
    wess_config.outputsamplerate = 22050;
    wess_config.maxACMDSize = 3072;
    wess_config.heap_ptr = &sys_aheap;

	wess_tweak.mask = TWEAK_DMA_BUFFERS | TWEAK_DMA_MESSAGES;
	wess_tweak.dma_buffers = 32;	// see wessapi.h for defaults
	wess_tweak.dma_messages = 64;

	wess_set_tweaks( &wess_tweak );
    wess_init( &wess_config );

	// now we load the .wmd image into a temporary ram space

    wmdlength = _wess_wmdSegmentRomEnd - _wess_wmdSegmentRomStart;
	old_ovmemptr = sys_ovmemptr;
	tempram = OS_PHYSICAL_TO_K0( sys_alloc_heap1( wmdlength, 8 ) );
    wess_rom_copy( _wess_wmdSegmentRomStart, tempram, wmdlength );

    wess_dat_location(_wess_datSegmentRomStart);

    modulesize = wess_size_module( tempram, settings_list );
    moduleptr = alHeapAlloc( &sys_aheap, 1, modulesize );
    loaded = wess_load_module( tempram, moduleptr, modulesize, settings_list );
	sys_ovmemptr = old_ovmemptr;	// deallocates ram

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
}
