//////////////////////////////////////////////////////////////////////////////////////////
// callback.h
//
// Author: David Schwartz
//////////////////////////////////////////////////////////////////////////////////////////
// THIS CODE IS PROPRIETARY PROPERTY OF WILLIAMS ENTERTAINMENT.
//
// The contents of this file may not be disclosed to third
// parties, copied or duplicated in any form, in whole or in part,
// without the prior written permission of Williams Entertainment.
//////////////////////////////////////////////////////////////////////////////////////////

#ifndef CALLBACK_H
#define CALLBACK_H 1

#include "queue.h"


//========================================================================================
// Public definitions:

struct callback {
	struct qlink	qlink;		// private: queue pointers
	void (*callback)(void *);	// callback function pointer (0=none)
};



//========================================================================================
// Public functions:

//////////////////////////////////////////////////////////////////////////////////////////
// callback_add - add a callback function to queue.
//
// May be called at any time, including from within ISRs. If callback is zero, this
// function simply returns.
//////////////////////////////////////////////////////////////////////////////////////////
extern void callback_add( struct callback *callback );


//////////////////////////////////////////////////////////////////////////////////////////
// callback_work - handles callbacks. Should be called only by the main game loop.
//////////////////////////////////////////////////////////////////////////////////////////
extern void callback_work( void );


#endif
