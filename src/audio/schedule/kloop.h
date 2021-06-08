//////////////////////////////////////////////////////////////////////////////////////////
// kloop.h
//
// Author: Steve Ranck
//////////////////////////////////////////////////////////////////////////////////////////
// THIS CODE IS PROPRIETARY PROPERTY OF WILLIAMS ENTERTAINMENT.
//
// The contents of this file may not be disclosed to third
// parties, copied or duplicated in any form, in whole or in part,
// without the prior written permission of Williams Entertainment.
//////////////////////////////////////////////////////////////////////////////////////////

#ifndef KLOOP_H
#define KLOOP_H 1



//========================================================================================
// Public definitions:

#define KLOOP_FORCE_OVLOAD_BIT		0x8000

#define KLOOP_OVLOAD_NONE			0x7FFF
#define KLOOP_FORCE_OVLOAD( ovid )	((ovid) | KLOOP_FORCE_OVLOAD_BIT)


//========================================================================================
// Public variables:

extern void	(*Control_func)(int);			// game loop control function pointer
extern int		Control_parm;				// parameter passed to the function
extern int		Control_overlay;			// the overlay id the control function is located in
extern int		prior_overlay;				// used to determine when Control_overlay has been changed
extern int		Pause;						// 1=game is paused


//========================================================================================
// Public functions:

//////////////////////////////////////////////////////////////////////////////////////////
// kloop_main - main system loop. Never returns. Called by kstart.
//////////////////////////////////////////////////////////////////////////////////////////
extern void kloop_main( void );


//////////////////////////////////////////////////////////////////////////////////////////
// kloop_idle_control_func - called when no control function handler has been
//                           specified. Used internally by system. Should not be called.
//////////////////////////////////////////////////////////////////////////////////////////
extern void kloop_idle_control_func( int parm );


#endif
