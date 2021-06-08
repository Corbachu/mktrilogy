//////////////////////////////////////////////////////////////////////////////////////////
// callback.c - callback functions for the Williams Operating System.
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

#include "callback.h"
#include "queue.h"
#include "sys.h"



//========================================================================================
// Private variables:

static struct queue cb_queue_callback;


//========================================================================================
// Public functions:

//////////////////////////////////////////////////////////////////////////////////////////
// callback_add - add a callback function to queue.
//
// May be called at any time, including from within ISRs. If callback is zero, this
// function simply returns.
//////////////////////////////////////////////////////////////////////////////////////////
void callback_add( struct callback *callback ) {
	if( callback->callback ) {
		queue_add_tail( &cb_queue_callback, (struct qlink *)callback );
	}
}


//////////////////////////////////////////////////////////////////////////////////////////
// callback_work - handles callbacks. Should be called only by the main game loop.
//////////////////////////////////////////////////////////////////////////////////////////
void callback_work( void ) {
	struct callback *cb;

	while( cb = (struct callback *)queue_remove_head( &cb_queue_callback ) ) {
		(cb->callback)( cb );
	}
}
