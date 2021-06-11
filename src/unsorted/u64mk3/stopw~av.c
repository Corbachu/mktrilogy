//////////////////////////////////////////////////////////////////////////////////////////
// stopwatch.c - System stopwatch functions.
//
// Author: David Schwartz
//////////////////////////////////////////////////////////////////////////////////////////
// THIS CODE IS PROPRIETARY PROPERTY OF WILLIAMS ENTERTAINMENT.
//
// The contents of this file may not be disclosed to third
// parties, copied or duplicated in any form, in whole or in part,
// without the prior written permission of Williams Entertainment.
//////////////////////////////////////////////////////////////////////////////////////////


#include "u64main.h"
#include "sys_defs.h"

#include "sys.h"
#include "stopwatch.h"




//========================================================================================
// Prototypes:

static void clear_sw( struct stopwatch *sw );


//========================================================================================
// Public functions:

//////////////////////////////////////////////////////////////////////////////////////////
// stopwatch_reset - resets the specified stopwatch to zero.
//////////////////////////////////////////////////////////////////////////////////////////
void stopwatch_reset( struct stopwatch *sw ) {
	CRITICAL_DEFS;

	ENTER_CRITICAL;
		if( sw->flags & STOPW_STARTED ) {
			sw->flags |= STOPW_NEED2RESET;
		} else {
			clear_sw( sw );
		}
	LEAVE_CRITICAL;
}


//////////////////////////////////////////////////////////////////////////////////////////
// stopwatch_start - starts the specified stopwatch.
//////////////////////////////////////////////////////////////////////////////////////////
void stopwatch_start( struct stopwatch *sw ) {
	CRITICAL_DEFS;

	ENTER_CRITICAL;
		sw->start_ticks = osGetTime();
		if( sw->flags & STOPW_STARTED ) sw->pause_ticks = 0;
		sw->flags |= STOPW_STARTED;
	LEAVE_CRITICAL;
}


//////////////////////////////////////////////////////////////////////////////////////////
// stopwatch_stop - stops the stopwatch and adds the delta time since it was started.
//////////////////////////////////////////////////////////////////////////////////////////
void stopwatch_stop( struct stopwatch *sw ) {
	CRITICAL_DEFS;

	ENTER_CRITICAL;
		if( sw->flags & STOPW_NEED2RESET ) clear_sw( sw );

		if( sw->flags & STOPW_STARTED ) {
			sw->total_ticks += osGetTime() - sw->start_ticks + sw->pause_ticks;
			sw->pause_ticks = 0;
			sw->num_samples++;
			sw->flags &= ~STOPW_STARTED;
		}
	LEAVE_CRITICAL;
}


//////////////////////////////////////////////////////////////////////////////////////////
// stopwatch_pause - pauses the stopwatch. stopwatch_resume must be called next.
//////////////////////////////////////////////////////////////////////////////////////////
void stopwatch_pause( struct stopwatch *sw ) {
	CRITICAL_DEFS;

	ENTER_CRITICAL;
		if( sw->flags & STOPW_STARTED ) {
			sw->pause_ticks += osGetTime() - sw->start_ticks;
		}
	LEAVE_CRITICAL;
}


//////////////////////////////////////////////////////////////////////////////////////////
// stopwatch_resume - resumes a paused stopwatch.
//////////////////////////////////////////////////////////////////////////////////////////
void stopwatch_resume( struct stopwatch *sw ) {
	CRITICAL_DEFS;

	ENTER_CRITICAL;
		sw->start_ticks = osGetTime();
	LEAVE_CRITICAL;
}


//////////////////////////////////////////////////////////////////////////////////////////
// stopwatch_val - returns the specified stopwatch's time in seconds (or 0 if none).
//////////////////////////////////////////////////////////////////////////////////////////
double stopwatch_val( struct stopwatch *sw ) {
	CRITICAL_DEFS;
	OSTime total;
	u32 samples;
	double v;

	ENTER_CRITICAL;
		total = sw->total_ticks;
		samples = sw->num_samples;
	LEAVE_CRITICAL;

	v = (double)0.0;
	if( samples ) {
		v = OS_CYCLES_TO_NSEC( (double)total / (double)samples ) / (double)1000000000.0;
	}

	return( v );
}


//========================================================================================
// Private functions:

static void clear_sw( struct stopwatch *sw ) {
	sw->total_ticks = 0;
	sw->pause_ticks = 0;
	sw->num_samples = 0;
	sw->flags &= ~STOPW_NEED2RESET;
}
