//////////////////////////////////////////////////////////////////////////////////////////
// kloop.c - Main loop code for the Williams Operating System.
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

#include "kloop.h"
#include "sys.h"
#include "vid.h"
#include "mtx.h"
#include "gutil.h"
#include "gamepad.h"
#include "slider.h"
#include "text.h"
#include "camera.h"
#include "bench.h"
#include "gdefaults.h"
#include "profile.h"
#include "tool.h"
#include "cusapad.h"

#include "cusa.h"			// for debugging...
#include "screen.h"


#define KLOOP_FCOUNT	0


//========================================================================================
// Public variables:

void	(*Control_func)(int);			// game loop control function pointer
int		Control_parm;					// parameter passed to the function
int		Control_overlay;				// the overlay id the control function is located in
int		prior_overlay;					// used to determine when Control_overlay has been changed
int		Pause;							// 1=game is paused


//========================================================================================
// Private variables:


//========================================================================================
// Public functions:

//////////////////////////////////////////////////////////////////////////////////////////
// kloop_main - main system loop. Never returns. Called by kstart.
//////////////////////////////////////////////////////////////////////////////////////////
void kloop_main( void ) {
int i, x, y;
#if KLOOP_FCOUNT
	struct text_descriptor *td_fcount;
#endif

#if BENCH
	bench_reset_all();
#endif

#if KLOOP_FCOUNT
	td_fcount = text_print_num( FONT_DIG_ONTOP, Gframe+1, 8, ' ', TEXT_JUSTIFY_RIGHT );
	srt_init( &td_fcount->srt, S16_VIEW_RIGHT, S16_VIEW_BOTTOM + SCREEN(12), 0, 1 );
#endif

#if PROFILE
	profile_start();
#endif

	for(;;) {

//----------------------------------------------------------------------------------------
// do these things until a Gfx display-list buffer is available...

#if BENCH
		bench_start( BENCHSW_CPU_IDLE );
#endif
		do {
			if( !Pause ) sys_random();
			callback_work();

			if( Control_overlay != prior_overlay ) {
				vid_sync();
				if( prior_overlay != KLOOP_OVLOAD_NONE ) sys_unloadoverlay( prior_overlay );

				Control_overlay &= (~KLOOP_FORCE_OVLOAD_BIT);
				prior_overlay = Control_overlay;

				if( Control_overlay != KLOOP_OVLOAD_NONE ) {
					sys_loadoverlay( Control_overlay );
				}
			}

		} while( vid_get_dbuf() );

#if BENCH
		bench_stop( BENCHSW_CPU_IDLE );
		bench_start( BENCHSW_CPU_WORKING );
#endif

//----------------------------------------------------------------------------------------
// initialize graphics stuff...

#if TOOL_ENABLED
		tool_work();
#endif

		gamepad_work();		// update gamepad state variables
		cusapad_work();		// update cusapad structure

		// IMPORTANT: This **MUST** be the first Gfx command in every Gfx list
		//            The video system (vid.c) overwrites this with the correct
		//            gSPSegment() command that properly describes the location
		//            of the frame buffer.
		gSPSegment( Glp++, SYS_RSPSEG_FBUF, 0 );

		gSPSegment( Glp++, SYS_RSPSEG_PHYSICAL, 0 );
		gSPSegment( Glp++, SYS_RSPSEG_K0, SYS_MEMMAP_KERNEL );
		gSPSegment( Glp++, SYS_RSPSEG_PAL, 0 );

		gSPDisplayList( Glp++, osVirtualToPhysical(gutil_gfxinit) );
		gutil_init_zbuf();		// NOTE: sets up frame buffer

//----------------------------------------------------------------------------------------
// call control function...

		Control_func( Control_parm );

#if KLOOP_FCOUNT
	text_reprint_num( td_fcount, Gframe+1, 8, ' ', 0 );
#endif

//----------------------------------------------------------------------------------------
// display text...

		if( !Pause ) text_work();

//----------------------------------------------------------------------------------------
// process Gfx display-list...

		gDPFullSync( Glp++ );
		gSPEndDisplayList( Glp++ );
		vid_process_gfx();

//----------------------------------------------------------------------------------------
// handle sliders...

		if( !Pause ) slider_work();

#if BENCH
//----------------------------------------------------------------------------------------
// print benchmarks...

		bench_print();
#endif

//----------------------------------------------------------------------------------------
// repeat loop...

#if BENCH
		bench_stop( BENCHSW_CPU_WORKING );
#endif
	}
}


//////////////////////////////////////////////////////////////////////////////////////////
// kloop_idle_control_func - called when no control function handler has been
//                           specified. Used internally by system. Should not be called.
//////////////////////////////////////////////////////////////////////////////////////////
void kloop_idle_control_func( int parm ) {
	return;
}
