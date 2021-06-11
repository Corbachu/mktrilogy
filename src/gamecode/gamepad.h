//////////////////////////////////////////////////////////////////////////////////////////
// gamepad.h
//
// Author: David Schwartz
//////////////////////////////////////////////////////////////////////////////////////////
// THIS CODE IS PROPRIETARY PROPERTY OF WILLIAMS ENTERTAINMENT.
//
// The contents of this file may not be disclosed to third
// parties, copied or duplicated in any form, in whole or in part,
// without the prior written permission of Williams Entertainment.
//////////////////////////////////////////////////////////////////////////////////////////


#ifndef GAMEPAD_H
#define GAMEPAD_H

//#include "tool.h"


//========================================================================================
// Public definitions:

struct gamepad {
	u32		b;			// button bits. See BUTTON_* for details

	float	x;			// 0.0=left, 1.0=right
	float	y;			// 0.0=down, 1.0=up
	float	xraw;		// same as x, but without deadzone
	float	yraw;		// same as y, but without deadzone
};


#define BUTTON_START	CONT_START
#define BUTTON_UP		CONT_UP
#define BUTTON_DOWN		CONT_DOWN
#define BUTTON_LEFT		CONT_LEFT
#define BUTTON_RIGHT	CONT_RIGHT
#define BUTTON_L		CONT_L
#define BUTTON_R		CONT_R
#define BUTTON_A		CONT_A
#define BUTTON_B		CONT_B
#define BUTTON_C		CONT_D
#define BUTTON_D		CONT_C
#define BUTTON_E		CONT_F
#define BUTTON_F		CONT_E
#define BUTTON_BOTTOM	CONT_G

#define BUTTON_AUP		0x00010000		// analog "buttons":
#define BUTTON_ADOWN	0x00020000
#define BUTTON_ALEFT	0x00040000
#define BUTTON_ARIGHT	0x00080000

#define BUTTON_R_AUP	0x00100000		// auto-repeat buttons:
#define BUTTON_R_ADOWN	0x00200000
#define BUTTON_R_ALEFT	0x00400000
#define BUTTON_R_ARIGHT	0x00800000

#define BUTTON_SELECT	(BUTTON_START|BUTTON_BOTTOM)
#define BUTTON_ABCDEF	(BUTTON_A|BUTTON_B|BUTTON_C|BUTTON_D|BUTTON_E|BUTTON_F)
#define BUTTON_DIR		(BUTTON_UP|BUTTON_DOWN|BUTTON_RIGHT|BUTTON_LEFT)
#define BUTTON_ADIR		(BUTTON_AUP|BUTTON_ADOWN|BUTTON_ARIGHT|BUTTON_ALEFT)
#define BUTTON_XDIR		(BUTTON_DIR|BUTTON_ADIR)
#define BUTTON_LR		(BUTTON_L|BUTTON_R)
#define BUTTON_OPTIONS	(BUTTON_ABCDEF|BUTTON_LR)
#define BUTTON_ALL		(BUTTON_ABCDEF|BUTTON_DIR|BUTTON_ADIR|BUTTON_LR|BUTTON_BOTTOM|BUTTON_START)
#define BUTTON_XUP		(BUTTON_UP|BUTTON_AUP)
#define BUTTON_XDOWN	(BUTTON_DOWN|BUTTON_ADOWN)
#define BUTTON_XLEFT	(BUTTON_LEFT|BUTTON_ALEFT)
#define BUTTON_XRIGHT	(BUTTON_RIGHT|BUTTON_ARIGHT)

#define BUTTON_R_ADIR	(BUTTON_R_AUP|BUTTON_R_ADOWN|BUTTON_R_ARIGHT|BUTTON_R_ALEFT)
#define BUTTON_R_UDIR	(BUTTON_R_ADIR|BUTTON_DIR)
#define BUTTON_R_UUP	(BUTTON_R_AUP|BUTTON_UP)
#define BUTTON_R_UDOWN	(BUTTON_R_ADOWN|BUTTON_DOWN)
#define BUTTON_R_ULEFT	(BUTTON_R_ALEFT|BUTTON_LEFT)
#define BUTTON_R_URIGHT	(BUTTON_R_ARIGHT|BUTTON_RIGHT)

#define REPEAT_MAP_COUNT	4


#define FRAME_DIVISOR	2			// (1=30fps,2=60fps)

#define GAMEPAD_GREEN_THRESHOLD_US		(4000/FRAME_DIVISOR)
#define GAMEPAD_GREEN_SLACK_US			(2000/FRAME_DIVISOR)
#define GAMEPAD_TIMER_DELAY_MIN_US		(10000/FRAME_DIVISOR)
#define GAMEPAD_TIMER_DELAY_MAX_US		( (1000000/SYS_FRAMES_PER_SEC)-SYS_GAMEPAD_USEC-GAMEPAD_GREEN_SLACK_US )

#define GAMEPAD_GREEN_THRESHOLD			OS_USEC_TO_CYCLES( GAMEPAD_GREEN_THRESHOLD_US )
#define GAMEPAD_GREEN_SLACK				OS_USEC_TO_CYCLES( GAMEPAD_GREEN_SLACK_US )
#define GAMEPAD_TIMER_DELAY_MIN			OS_USEC_TO_CYCLES( GAMEPAD_TIMER_DELAY_MIN_US )
#define GAMEPAD_TIMER_DELAY_MAX			OS_USEC_TO_CYCLES( GAMEPAD_TIMER_DELAY_MAX_US )

#define GAMEPAD_RESCAN_COUNT_INIT		60

#define GAMEPAD_REPEAT_DELAY			12
#define GAMEPAD_REPEAT_COUNT			8


//========================================================================================
// Public variables:

extern OSThread gamepad_thread;
extern u64 gamepad_stack[ SYS_GAMEPAD_STACKSIZE/8 ];
extern OSThread gamepad_timer_thread;
extern u64 gamepad_timer_stack[ SYS_GTIMER_STACKSIZE/8 ];

extern OSContStatus		gamepad_status[ MAXCONTROLLERS ];
extern OSContPad		gamepad_data[ MAXCONTROLLERS ];
extern u8				gamepad_bit_pattern;	// one bit for each controller
extern int				gamepad_count;			// number of game controllers
extern int				gamepad_index[ SYS_NUM_GAMEPADS ];
extern int				gamepad_system_busy;
extern float			gamepad_deadzone[ SYS_NUM_GAMEPADS ];
extern float			gamepad_center[ SYS_NUM_GAMEPADS ][2];	// 2 is for x/y: 0=x, 1=y

extern int				gamepad_rescan_count;

extern struct gamepad	pad[ SYS_NUM_GAMEPADS + TOOL_ENABLED ];

extern OSTimer	gamepad_timer[2];
extern OSTime	gamepad_vbi_to_start_delay;
extern OSTime	gamepad_vbi_red_start_time;
extern OSTime	gamepad_vbi_green_start_time;


//========================================================================================
// Public functions:

//////////////////////////////////////////////////////////////////////////////////////////
// gamepad_click - Returns the latched button state.
//
// The value returned is the latched state of the buttons and has the same bit configuration
// as pad[].b. The bits parameter indicates which latched bits are to be cleared.
//////////////////////////////////////////////////////////////////////////////////////////
extern int gamepad_click( int player, u32 bits );


//////////////////////////////////////////////////////////////////////////////////////////
// gamepad_update - updates gamepad_count and gamepad_index[] based on the values in
//                  gamepad_status.
//////////////////////////////////////////////////////////////////////////////////////////
extern void gamepad_update( void );


//////////////////////////////////////////////////////////////////////////////////////////
// gamepad_work - Updates the gamepad values. Used internally by the kernel. Should not
//                be called.
//////////////////////////////////////////////////////////////////////////////////////////
extern void gamepad_work( void );


//////////////////////////////////////////////////////////////////////////////////////////
// gamepad_fps_vbi - Called from the vbi thread and in phase with the game loop's vbi,
//                     this function starts a count-down timer which will trigger just
//                     before the next game loop vbi. When the timer triggers,
//                     gamepad_timer_thread is woken and starts DMAing the gamepad data
//                     into memory. The data should be ready just before the beginning
//                     of the next fps vbi.
//
// IMPORTANT: This function is internally called and managed by the kernel. It should
//            not be directly called.
//////////////////////////////////////////////////////////////////////////////////////////
extern void gamepad_fps_vbi( void );


//////////////////////////////////////////////////////////////////////////////////////////
// gamepad_timer_wait_thread - An independent thread used to trigger gamepad data reads.
//
// IMPORTANT: This function is internally called and managed by the kernel. It should
//            not be called.
//////////////////////////////////////////////////////////////////////////////////////////
extern void gamepad_timer_wait_thread( void *arg );


//////////////////////////////////////////////////////////////////////////////////////////
// gamepad_wait_thread - An independent thread used to read the gamepad state.
//
// IMPORTANT: This function is internally called and managed by the kernel. It should
//            not be called.
//////////////////////////////////////////////////////////////////////////////////////////
extern void gamepad_wait_thread( void *arg );


#endif
