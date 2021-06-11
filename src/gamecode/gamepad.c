//////////////////////////////////////////////////////////////////////////////////////////
// gamepad.c - Game controller functions.
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

#include "gamepad.h"
#include "sys.h"
//#include "tool.h"



//========================================================================================
// Public variables:

OSThread gamepad_thread;
u64 gamepad_stack[ SYS_GAMEPAD_STACKSIZE/8 ];
OSThread gamepad_timer_thread;
u64 gamepad_timer_stack[ SYS_GTIMER_STACKSIZE/8 ];

#define MAXCONTROLLERS GLFW_JOYSTICK_LAST

OSContStatus	gamepad_status[ MAXCONTROLLERS ];
OSContPad		gamepad_data[ MAXCONTROLLERS ];
u8				gamepad_bit_pattern;	// one bit for each controller
int				gamepad_count;			// number of game controllers
int				gamepad_index[ SYS_NUM_GAMEPADS ];
int				gamepad_system_busy;
float			gamepad_deadzone[ SYS_NUM_GAMEPADS ];
float			gamepad_center[ SYS_NUM_GAMEPADS ][2];	// 2 is for x/y: 0=x, 1=y

int				gamepad_rescan_count;

struct gamepad	pad[ SYS_NUM_GAMEPADS + TOOL_ENABLED ];

OSTimer	gamepad_timer[2];
OSTime	gamepad_vbi_to_start_delay;
OSTime	gamepad_vbi_red_start_time;
OSTime	gamepad_vbi_green_start_time;


//========================================================================================
// Private variables:

static struct dynamic_gamepad_data {
	volatile u32		button;
	volatile s32		stick_x;
	volatile s32		stick_y;
	volatile int		ready_flag;
} fresh_data[ SYS_NUM_GAMEPADS ];

static int gamepad_next_count;
static int gamepad_next_index[ SYS_NUM_GAMEPADS ];

static int retry_count;
static u32 latch1[ SYS_NUM_GAMEPADS + TOOL_ENABLED ];
static u32 latch2[ SYS_NUM_GAMEPADS + TOOL_ENABLED ];

static int repeat_count[SYS_NUM_GAMEPADS];


//========================================================================================
// Prototypes:

static void parse_rescan_data( void );
static void parse_controller_data( void );
static void update_time( void );


//========================================================================================
// Public functions:

//////////////////////////////////////////////////////////////////////////////////////////
// gamepad_click - Returns the latched button state.
//
// The value returned is the latched state of the buttons and has the same bit configuration
// as pad[].b. The bits parameter indicates which latched bits are to be cleared.
//////////////////////////////////////////////////////////////////////////////////////////
int gamepad_click( int player, u32 bits ) {
	u32 i;

	latch2[player] &= ~( bits & latch1[player] );
	i = latch1[player];
	latch1[player] &= ~bits;

	return( i );
}


//////////////////////////////////////////////////////////////////////////////////////////
// gamepad_update - updates gamepad_count and gamepad_index[] based on the values in
//                  gamepad_status.
//////////////////////////////////////////////////////////////////////////////////////////
void gamepad_update( void ) {
	CRITICAL_DEFS;
	int i;

	ENTER_CRITICAL;
		gamepad_next_count = 0;
		for( i=0; i<MAXCONTROLLERS; i++ ) {
			if( gamepad_status[i].errno == 0 ) {
				gamepad_next_index[ gamepad_next_count++ ] = i;
				if( gamepad_next_count == SYS_NUM_GAMEPADS ) break;
			}
		}
	LEAVE_CRITICAL;
}


//////////////////////////////////////////////////////////////////////////////////////////
// gamepad_work - Updates the gamepad values. Used internally by the kernel. Should not
//                be called.
//////////////////////////////////////////////////////////////////////////////////////////
void gamepad_work( void ) {
	CRITICAL_DEFS;
	u32 button[SYS_NUM_GAMEPADS];
	s32 stick_xy[SYS_NUM_GAMEPADS][2], newdata[SYS_NUM_GAMEPADS];
	float xy[SYS_NUM_GAMEPADS][2], rxy[SYS_NUM_GAMEPADS][2], center, deadzone, delta;
	int i, j, k;
	u32 b;
	static peak[2] = { SYS_PEAK_GAMEPAD_X, SYS_PEAK_GAMEPAD_Y };

	static struct repeat_map {
		u32	unrepeated_b;
		u32	repeated_b;
	} repeat_map[REPEAT_MAP_COUNT] = {
		BUTTON_AUP, BUTTON_R_AUP,
		BUTTON_ADOWN, BUTTON_R_ADOWN,
		BUTTON_ALEFT, BUTTON_R_ALEFT,
		BUTTON_ARIGHT, BUTTON_R_ARIGHT,
	};

	ENTER_CRITICAL;
		gamepad_count = gamepad_next_count;
		for( i=0; i<SYS_NUM_GAMEPADS; i++ ) gamepad_index[i] = gamepad_next_index[i];

		for( i=0; i<gamepad_count; i++ ) {
			if( fresh_data[i].ready_flag ) {
				button[i] = fresh_data[i].button;
				stick_xy[i][0] = fresh_data[i].stick_x;
				stick_xy[i][1] = fresh_data[i].stick_y;
				fresh_data[i].ready_flag = 0;
				newdata[i] = 1;
			} else {
				newdata[i] = 0;
			}
		}
	LEAVE_CRITICAL;

	for( i=0; i<gamepad_count; i++ ) {
		if( newdata[i] ) {
			deadzone = gamepad_deadzone[i];
			for( j=0; j<2; j++ ) {
				if( stick_xy[i][j] < -peak[j] ) {
					stick_xy[i][j] = -peak[j];
				} else {
					if( stick_xy[i][j] > peak[j] ) stick_xy[i][j] = peak[j];
				}
				rxy[i][j]= (float)(stick_xy[i][j] + peak[j]) / (float)(peak[j]<<1);

				center = gamepad_center[i][j];
				delta = center-deadzone;

				if( rxy[i][j] < delta ) {
					xy[i][j] = 0.5 * rxy[i][j] / delta;
				} else {
					if( rxy[i][j] > center+deadzone ) {
						xy[i][j] = 0.5 + 0.5 * (rxy[i][j]-(1-delta)) / delta;
					} else {
						xy[i][j] = 0.5;
					}
				}
			}

			if( rxy[i][0] <= SYS_GAMEPAD_THRESH_MIN ) {
				button[i] |= BUTTON_ALEFT;
			} else {
				if( rxy[i][0] >= SYS_GAMEPAD_THRESH_MAX ) button[i] |= BUTTON_ARIGHT;
			}
			if( rxy[i][1] <= SYS_GAMEPAD_THRESH_MIN ) {
				button[i] |= BUTTON_ADOWN;
			} else {
				if( rxy[i][1] >= SYS_GAMEPAD_THRESH_MAX ) button[i] |= BUTTON_AUP;
			}
		}
	}

	for( k=0; k<gamepad_count; k++ ) {
		if( newdata[k] ) {
			button[k] &= ~BUTTON_R_ADIR;
			for( i=0; i<REPEAT_MAP_COUNT; i++ ) {
				if( button[k] & repeat_map[i].unrepeated_b ) button[k] |= repeat_map[i].repeated_b;
			}

			if( button[k] & BUTTON_R_ADIR ) {
				if( repeat_count[k] ) {
					if( !--repeat_count[k] ) {
						repeat_count[k] = GAMEPAD_REPEAT_COUNT;
					} else {
						button[k] &= ~BUTTON_R_ADIR;
					}
				} else {
					repeat_count[k] = GAMEPAD_REPEAT_DELAY;
				}
			} else {
				repeat_count[k] = 0;
			}
		}
	}

#if TOOL_ENABLED
	if( newdata[0] ) {
		if( (button[0] & (BUTTON_L|BUTTON_R)) == (BUTTON_L|BUTTON_R) ) {
			if( button[0] & (BUTTON_START|0x0080) ) {
				button[0] &= ~(BUTTON_L|BUTTON_R|BUTTON_START|0x0080);
				tool_latch = 1;
			} else {
				if( tool_latch ) {
					tool_latch = 0;
					tool_on = !tool_on;
					if( tool_on ) {
						tool_mode = 0;
						latch1[2] = latch2[2] = 0;
						vprintf(( "tool on (A:pause B:box C:mag D:alpha E:crop F:camadj)\n" ));
					} else {
						vprintf(( "tool off\n" ));
					}
				}
			}
		}
	}

	ENTER_CRITICAL;
		for( i=0; i<gamepad_count; i++ ) {
			j = ( !i && tool_on ) ? 2 : i;
			if( newdata[i] ) {
				pad[j].x = xy[i][0];
				pad[j].y = xy[i][1];
				pad[j].xraw = rxy[i][0];
				pad[j].yraw = rxy[i][1];
				pad[j].b = button[i];
				latch1[j] |= latch2[j] & button[i];
				latch2[j] |= ~button[i];
			}
		}
	LEAVE_CRITICAL;
#else
	ENTER_CRITICAL;
		for( i=0; i<gamepad_count; i++ ) {
			if( newdata[i] ) {
				pad[i].x = xy[i][0];
				pad[i].y = xy[i][1];
				pad[i].xraw = rxy[i][0];
				pad[i].yraw = rxy[i][1];
				pad[i].b = button[i];
				latch1[i] |= latch2[i] & button[i];
				latch2[i] |= ~button[i];
			}
		}
	LEAVE_CRITICAL;
#endif
}

static short delay=0;
void gamepad_info(void) 
{
	int i;
	
	delay++;
	if (delay>30)
		delay=0;
		
	printf (("GAMEPAD COUNT:%d\n",gamepad_count));
	
	if (gamepad_count==0)
		return;
	
	for( i=0; i<gamepad_count; i++ ) 
	{
		printf(("Joy:%d\t\Buttons:%x\n",i,pad[i].b));
	}
	

	return;	
}

//////////////////////////////////////////////////////////////////////////////////////////
// gamepad_fps_vbi - Called from the vbi thread and in phase with the game loop's vbi,
//                     this function starts a count-down timer which will trigger just
//                     before the next game loop vbi. When the timer triggers,
//                     gamepad_timer_thread is woken and starts DMAing the gamepad data
//                     into memory. The data should be ready just before the beginning
//                     of the next Xfps vbi.
//
// IMPORTANT: This function is internally called and managed by the kernel. It should
//            not be directly called.
//////////////////////////////////////////////////////////////////////////////////////////
volatile int timer_flag=0;
void gamepad_fps_vbi( void ) {
	CRITICAL_DEFS;
	OSTime time;

	ENTER_CRITICAL;
		time = osGetTime();

		if( gamepad_vbi_green_start_time ) 
		{
			time -= gamepad_vbi_green_start_time;
			if( time > GAMEPAD_GREEN_THRESHOLD ) 
			{
				time -= GAMEPAD_GREEN_SLACK;
				if( gamepad_vbi_to_start_delay+time > GAMEPAD_TIMER_DELAY_MAX ) 
				{
					gamepad_vbi_to_start_delay = GAMEPAD_TIMER_DELAY_MAX;
				} 
				else 
				{
					gamepad_vbi_to_start_delay += time;
				}
			}
		} 
		else 
		{
			if( gamepad_system_busy && !gamepad_vbi_red_start_time ) 
			{
				gamepad_vbi_red_start_time = osGetTime();
			}
		}
	LEAVE_CRITICAL;

	timer_flag++;
	osSetTimer( &gamepad_timer[timer_flag & 1], gamepad_vbi_to_start_delay, 0, &sys_msgque_tmr, 0 );
//osSendMesg(&sys_msgque_tmr,0,0);
}


//////////////////////////////////////////////////////////////////////////////////////////
// gamepad_timer_wait_thread - An independent thread used to trigger gamepad data reads.
//
// IMPORTANT: This function is internally called and managed by the kernel. It should
//            not be called.
//////////////////////////////////////////////////////////////////////////////////////////
void gamepad_timer_wait_thread( void *arg ) {
	CRITICAL_DEFS;
	int i, g, retry;

	for(;;) {
		osRecvMesg( &sys_msgque_tmr, 0, OS_MESG_BLOCK );

		if( !gamepad_system_busy ) {
			gamepad_system_busy = 1;

			gamepad_vbi_red_start_time = 0;
			gamepad_vbi_green_start_time = 0;

			osContStartReadData( &sys_msgque_joy );
		}
	}
}


//////////////////////////////////////////////////////////////////////////////////////////
// gamepad_wait_thread - An independent thread used to read the gamepad state.
//
// IMPORTANT: This function is internally called and managed by the kernel. It should
//            not be called.
//////////////////////////////////////////////////////////////////////////////////////////
void gamepad_wait_thread( void *arg ) {
	for(;;) {
		osRecvMesg( &sys_msgque_joy, 0, OS_MESG_BLOCK );

		if( !gamepad_rescan_count ) {
			parse_rescan_data();
		} else {
			parse_controller_data();
		}
	}
}


static void parse_rescan_data( void ) {
	int i, retry;

	retry = 0;

	osContGetQuery( gamepad_status );

	for( i=0; i<MAXCONTROLLERS; i++ ) {
		if( gamepad_status[i].errno == CONT_OVERRUN_ERROR ) {
			retry = 1;
			break;
		}
	}

	if( retry ) {
		if( --retry_count ) {
			if( retry_count < 0 ) retry_count = SYS_GAMEPAD_RETRY;
			osContStartQuery( &sys_msgque_joy );
		} else {
			retry = 0;
		}
	}

	if( !retry ) {
		gamepad_rescan_count = GAMEPAD_RESCAN_COUNT_INIT;
		gamepad_system_busy = 0;
		gamepad_update();
	}
}


static void parse_controller_data( void ) {
	CRITICAL_DEFS;
	int i, g, retry;

	retry = 0;

	osContGetReadData( gamepad_data );

	for( i=0; i<gamepad_count; i++ ) {
		g = gamepad_index[i];

		if( gamepad_data[g].errno ) {
			if( gamepad_data[g].errno == CONT_NO_RESPONSE_ERROR ) {
				ENTER_CRITICAL;
					fresh_data[i].button = 0;
					fresh_data[i].stick_x = 0;
					fresh_data[i].stick_y = 0;
					fresh_data[i].ready_flag = 1;
				LEAVE_CRITICAL;
			}
			retry++;
		} else {
			ENTER_CRITICAL;
				fresh_data[i].button = gamepad_data[g].button;
				fresh_data[i].stick_x = gamepad_data[g].stick_x;
				fresh_data[i].stick_y = gamepad_data[g].stick_y;
				fresh_data[i].ready_flag = 1;
			LEAVE_CRITICAL;
		}
	}

	if( retry ) {
		if( --retry_count ) {
			if( retry_count < 0 ) retry_count = SYS_GAMEPAD_RETRY;
			osContStartReadData( &sys_msgque_joy );
		} else {
			retry = 0;
		}
	} else {
		update_time();
	}

	if( !retry ) {
		retry_count = 0;

		if( !--gamepad_rescan_count ) {
			osContStartQuery( &sys_msgque_joy );
		} else {
			gamepad_system_busy = 0;
		}
	}
}


static void update_time( void ) {
	CRITICAL_DEFS;
	OSTime time;

	ENTER_CRITICAL;
		time = osGetTime();

		if( gamepad_vbi_red_start_time ) {
			time -= (gamepad_vbi_red_start_time - GAMEPAD_GREEN_SLACK);
			if( gamepad_vbi_to_start_delay-time < GAMEPAD_TIMER_DELAY_MIN ) {
				gamepad_vbi_to_start_delay = GAMEPAD_TIMER_DELAY_MIN;
			} else {
				gamepad_vbi_to_start_delay -= time;
			}
		} else {
			gamepad_vbi_green_start_time = time;
		}
	LEAVE_CRITICAL;
}
