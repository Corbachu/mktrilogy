//////////////////////////////////////////////////////////////////////////////////////////
// vid.c - Video system functions for the Williams Operating System.
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

#include "vid.h"
#include "sys.h"
#include "gamepad.h"
#include "mtx.h"
#include "bench.h"
#include "tool.h"

#include "wessapi.h"


#define VID_TRACK_EVENTS	0


//========================================================================================
// Public variables:

// IMPORTANT: vid_rsptask must be the first variable defined in vid.c, so that
//            it will be aligned on a 16-byte boundary.
OSTask vid_rsptask;					// RSP task list structure

volatile int vid_dpipe_avail;		// number of idle dlists available
volatile int vid_dpipe_writing;		// dlist being built by game
volatile int vid_dpipe_dataready;	// dlist build and ready, but not given to RSP yet
volatile int vid_dpipe_reading;		// dlist being processed by RSP

volatile int vid_vpipe_writing;		// fbuf being written to by RDP
volatile int vid_vpipe_dataready;	// fbuf ready for screen, but not given to osViSwapBuffer yet
volatile int vid_vpipe_committed;	// fbuf given to osViSwapBuffer, but not on screen yet
volatile int vid_vpipe_onscreen;	// fbuf on screen

volatile int vid_prenmi_flag;		// 0=normal, 1=console reset pressed


#if SYS_TURBO
gtGfx *Tlp;								// current turbo Gfx display-list pointer
#endif
Gfx *Glp;								// current Gfx display-list pointer
Mtx *Mlp;								// current Mtx list pointer
Vtx *Vlp;								// current Vtx list pointer
Vp  *Plp;								// current Vp list pointer
u32 Frame;								// simply increments for each VBI
volatile u32 Vid_displaying_frame;		// the 'Frame' currently being handled by the RSP
u32 Gframe;								// simply increments for each dlist submitted

#if BENCHBUF
int benchbuf_newmax;
int Glp_max;
int Mlp_max;
int Vlp_max;
int Plp_max;
#endif

struct dpipe dpipe[SYS_NUM_DLBUFS];		// initialized by init_sys
struct vpipe vpipe[SYS_NUM_FRAMEBUFS];	// initialized by init_sys

OSThread vid_thread;
u64 vid_stack[ SYS_VID_STACKSIZE/8 ];


//========================================================================================
// Private variables:

static volatile int gfx_yielded;	// 1=gfx task yield request has been sent to RSP
static OSTask *vid_next_atask;		// audio task to be started on next VBI
static OSTask *vid_atask_ready;		// audio task ready for submission
static OSTask *vid_rsp_atask;		// audio task being processed by RSP
static int vid_rsp_atask_submitted;	// 1=audio task has been submitted to RSP

//========================================================================================
// Prototypes:

static void rsp_event( void );
static void rdp_event( void );
static void vbi_event( void );
static void kickstart_event( void );
static void prenmi_event( void );
static void kickstart( void );
static void start_rsp( OSTask *task );
static void init_rsp_packet( int dindex );


//========================================================================================
// Public functions:

//////////////////////////////////////////////////////////////////////////////////////////
// vid_get_dbuf - get an available display-list buffer.
//
// Sets up Glp, Mlp, Vlp, and Plp pointing to empty buffers. vid_dpipe_writing is also set
// up to index into the allocated dpipe buffer. If successful, 0 is returned. If no buffers
// are free, 1 is returned.
//////////////////////////////////////////////////////////////////////////////////////////
int vid_get_dbuf( void ) {
	CRITICAL_DEFS;
	int i;

	ENTER_CRITICAL;
	if( vid_dpipe_avail ) {
		vid_dpipe_avail--;
		LEAVE_CRITICAL;

		for( i=0; i<SYS_NUM_DLBUFS; i++ ) {
			if( dpipe[i].idle ) {
				dpipe[i].idle = 0;
				Glp = dpipe[i].dbuf;
				Mlp = dpipe[i].mbuf+1;
				Vlp = dpipe[i].vbuf;
				Plp = dpipe[i].pbuf;
	
				dpipe[i].zbuf = 0;
				dpipe[i].frame = Frame;
				vid_dpipe_writing = i;
				return( 0 );
			}
		}
	}
	LEAVE_CRITICAL;

	return( 1 );
}


//////////////////////////////////////////////////////////////////////////////////////////
// vid_process_gfx - process the current display-list and display it.
//
// Returns immediately.
//////////////////////////////////////////////////////////////////////////////////////////
void vid_process_gfx( void ) {
	CRITICAL_DEFS;
	int i;
	u32 gc, mc, vc, pc;

	Gframe++;

#if BENCH
	bench_total_dlists++;
#endif
#if BENCHGFX
	bench_gfx( dpipe[vid_dpipe_writing].dbuf );
#endif

	gc = (u32)Glp - (u32)dpipe[vid_dpipe_writing].dbuf;
	mc = (u32)Mlp - (u32)dpipe[vid_dpipe_writing].mbuf;
	vc = (u32)Vlp - (u32)dpipe[vid_dpipe_writing].vbuf;
	pc = (u32)Plp - (u32)dpipe[vid_dpipe_writing].pbuf;

#if BENCHBUF
	if( gc > Glp_max ) { benchbuf_newmax = 1; Glp_max = gc; }
	if( mc > Mlp_max ) { benchbuf_newmax = 1; Mlp_max = mc; }
	if( vc > Vlp_max ) { benchbuf_newmax = 1; Vlp_max = vc; }
	if( pc > Plp_max ) { benchbuf_newmax = 1; Plp_max = pc; }
#endif
#if SYS_DEBUG
	if( gc > SYS_DBUF_SIZE ) {
		printf(( " <<<< WARNING: Display-list buffer overflow >>>>\n" ));
		printf(( "               buffer size: %d bytes\n", SYS_DBUF_SIZE ));
		printf(( "               Gfx size:    %d bytes\n", gc ));
	}
	if( mc > SYS_MBUF_SIZE ) {
		printf(( " <<<< WARNING: Matrix-list buffer overflow >>>>\n" ));
		printf(( "               buffer size: %d bytes\n", SYS_MBUF_SIZE ));
		printf(( "               Mtx size:    %d bytes\n", mc ));
	}
	if( vc > SYS_VBUF_SIZE ) {
		printf(( " <<<< WARNING: Vertex-list buffer overflow >>>>\n" ));
		printf(( "               buffer size: %d bytes\n", SYS_VBUF_SIZE ));
		printf(( "               Vtx size:    %d bytes\n", vc ));
	}
	if( pc > SYS_PBUF_SIZE ) {
		printf(( " <<<< WARNING: Viewport-list buffer overflow >>>>\n" ));
		printf(( "               buffer size: %d bytes\n", SYS_PBUF_SIZE ));
		printf(( "               Vp size:    %d bytes\n", pc ));
	}
#endif
#define TIME_FIXUP 0
{
#if TIME_FIXUP
CRITICAL_DEFS;
static int cnt, mcnt;
OSTime start;
static float delta, mdelta;
ENTER_CRITICAL;
cnt = ((int)Mlp - (int)(dpipe[vid_dpipe_writing].mbuf+1)) / sizeof( Mtx );
start = osGetTime();
#endif
	mtx_rsp_fixup_s( dpipe[vid_dpipe_writing].mbuf+1, Mlp );
#if TIME_FIXUP
delta = (float)OS_CYCLES_TO_USEC(osGetTime() - start) / 1000.0;
LEAVE_CRITICAL;
if( delta > mdelta ) { mcnt = cnt; mdelta = delta; }
if( delta > 1.0 ) printf(( "#=%d, time=%f  max(#=%d, time=%f)\n", cnt, delta, mcnt, mdelta ));
#endif
}
	dpipe[vid_dpipe_writing].gfx_bytes = gc;
	dpipe[vid_dpipe_writing].mtx_bytes = mc;
	dpipe[vid_dpipe_writing].vtx_bytes = vc;
	dpipe[vid_dpipe_writing].prt_bytes = pc;

	ENTER_CRITICAL;
	if( vid_dpipe_dataready >= 0 ) {			// replace dlist with the one ready for RSP processing...
		init_rsp_packet( vid_dpipe_writing );
		dpipe[vid_dpipe_dataready].idle = 1;
		vid_dpipe_dataready = vid_dpipe_writing;
		vid_dpipe_writing = -1;
		Vid_displaying_frame = dpipe[vid_dpipe_dataready].frame;
		LEAVE_CRITICAL;
	} else {									// submit new dlist...
		vid_dpipe_dataready = vid_dpipe_writing;
		vid_dpipe_writing = -1;
		LEAVE_CRITICAL;
		kickstart();
	}
}


//////////////////////////////////////////////////////////////////////////////////////////
// vid_sync - returns when all submitted display lists have been displayed. Returns
//            the vpipe index of the on-screen display list.
//////////////////////////////////////////////////////////////////////////////////////////
int vid_sync( void ) {
	while( vid_dpipe_dataready >= 0
		|| vid_dpipe_reading >= 0
		|| vid_vpipe_writing >= 0
		|| vid_vpipe_dataready >= 0
		|| vid_vpipe_committed >= 0
	);

	return( vid_vpipe_onscreen );
}


//////////////////////////////////////////////////////////////////////////////////////////
// vid_wait_thread - This is the main thread that handles RSP/RDP/VBI interrupt events.
//
// IMPORTANT: This function is internally called and managed by the kernel. It should
//            not be called.
//////////////////////////////////////////////////////////////////////////////////////////
void vid_wait_thread( void *arg ) {
	int msg;

	for(;;) {
		osRecvMesg( &sys_msgque_vid, (OSMesg *)&msg, OS_MESG_BLOCK );	// wait for event

		switch( msg ) {
			case VID_MSG_RSP:
				rsp_event();
				break;
			case VID_MSG_RDP:
#if VID_TRACK_EVENTS
				printf(( "rdp\n" ));
#endif
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
				break;
		}
	}
}


//========================================================================================
// Private functions:

//////////////////////////////////////////////////////////////////////////////////////////
// rsp_event - RSP interrupt handler. Will not be interrupted by VBI nor RDP interrupts.
//////////////////////////////////////////////////////////////////////////////////////////
static void rsp_event( void ) {
#if BENCH
	bench_start( BENCHSW_RSP_IDLE );
#endif

	if( vid_rsp_atask ) {
		if( vid_rsp_atask_submitted ) {
#if VID_TRACK_EVENTS
			printf(( "rsp a\n" ));
#endif
#if BENCH
			bench_stop( BENCHSW_RSP_WORKING_AUD );
#endif
			vid_rsp_atask = 0;
			kickstart();
		} else {
#if VID_TRACK_EVENTS
			printf(( "rsp gy\n" ));
#endif
#if BENCH
			bench_stop( BENCHSW_RSP_WORKING_GFX );
#endif
			if( !osSpTaskYielded( &vid_rsptask ) ) {
#if VID_TRACK_EVENTS
				printf(( "no y\n" ));
#endif
				gfx_yielded = 0;
				dpipe[vid_dpipe_reading].idle = 1;
				vid_dpipe_reading = -1;
			}
#if VID_TRACK_EVENTS
			printf(( "start a2\n" ));
#endif
			start_rsp( vid_rsp_atask );
			vid_rsp_atask_submitted = 1;
		}
	} else {
#if VID_TRACK_EVENTS
		printf(( "rsp g\n" ));
#endif
#if BENCH
		bench_stop( BENCHSW_RSP_WORKING_GFX );
#endif
		dpipe[vid_dpipe_reading].idle = 1;
		vid_dpipe_reading = -1;
		kickstart();
	}
}


//////////////////////////////////////////////////////////////////////////////////////////
// rdp_event - RDP interrupt handler. Will not be interrupted by VBI nor RSP interrupts.
//////////////////////////////////////////////////////////////////////////////////////////
static void rdp_event( void ) {
	int i;

#if BENCH
	bench_start( BENCHSW_RDP_IDLE );
	bench_stop( BENCHSW_RDP_WORKING );
#endif

#if TOOL_ENABLED
	tool_box_draw( sys_fbuf_phys[vid_vpipe_writing] );
#endif

	i = vid_vpipe_writing;
	vid_vpipe_writing = -1;

	if( vid_vpipe_committed >= 0 ) {
		vid_vpipe_dataready = i;
	} else {
		vid_vpipe_committed = i;
		osViSwapBuffer( vpipe[i].fbuf );
	}

	kickstart();
}


//////////////////////////////////////////////////////////////////////////////////////////
// vbi_event - VBI handler. Will not be interrupted by RSP nor RDP interrupts.
//////////////////////////////////////////////////////////////////////////////////////////
static void vbi_event( void ) {
	OSTask *t;
	int frame_on_screen, current_fbuf;
	int i;

	Frame++;

	if( vid_next_atask ) {
		vid_atask_ready = vid_next_atask;
		vid_next_atask = 0;
		kickstart_event();	// kickstart now
	}

	current_fbuf = (int)osViGetCurrentFramebuffer();
#if SYS_NUM_FRAMEBUFS == 3
	if( current_fbuf == (int)vpipe[0].fbuf ) {
		frame_on_screen = 0;
	} else {
		if( current_fbuf == (int)vpipe[1].fbuf ) {
			frame_on_screen = 1;
		} else {
			if( current_fbuf == (int)vpipe[2].fbuf ) {
				frame_on_screen = 2;
			} else {
				frame_on_screen = -1;
			}
		}
	}
#else
	frame_on_screen = (current_fbuf == (int)vpipe[1].fbuf);
#endif

	if( frame_on_screen != vid_vpipe_onscreen ) {
		if( vid_vpipe_onscreen >= 0 ) vpipe[vid_vpipe_onscreen].free = 1;
		vid_vpipe_onscreen = frame_on_screen;

		if( vid_vpipe_dataready >= 0 ) {
			vid_vpipe_committed = vid_vpipe_dataready;
			vid_vpipe_dataready = -1;
			osViSwapBuffer( vpipe[vid_vpipe_committed].fbuf );
		} else {
			vid_vpipe_committed = -1;
		}

		kickstart();

#if BENCH
		bench_displayed_frames++;
#endif
	}

	if( Frame&1 ) {
		if( ++vid_dpipe_avail > 3 ) vid_dpipe_avail=3;
		gamepad_30fps_vbi();

#if SYS_AUDIO_WORKFREQ==30
		if( !vid_prenmi_flag ) vid_next_atask = wess_work();
#endif
	}
#if SYS_AUDIO_WORKFREQ==60
	if( !vid_prenmi_flag ) vid_next_atask = wess_work();
#endif
}


//////////////////////////////////////////////////////////////////////////////////////////
// kickstart_event - handles kickstart messages.
//////////////////////////////////////////////////////////////////////////////////////////
static void kickstart_event( void ) {
	int i;

	if( vid_rsp_atask ) return;		// exit if the RSP is working on an audio task

	if( vid_atask_ready ) {
//if( vid_dpipe_reading >= 0 ) return;
		vid_rsp_atask = vid_atask_ready;
		vid_atask_ready = 0;

		if( vid_dpipe_reading >= 0 ) {
			gfx_yielded = 1;
			vid_rsp_atask_submitted = 0;
#if VID_TRACK_EVENTS
			printf(( "yield g\n" ));
#endif
			osSpTaskYield();
		} else {
			vid_rsp_atask_submitted = 1;
#if VID_TRACK_EVENTS
			printf(( "start a1\n" ));
#endif
			start_rsp( vid_rsp_atask );
		}
	} else {
		if( gfx_yielded ) {
			gfx_yielded = 0;
#if VID_TRACK_EVENTS
			printf(( "start yg\n" ));
#endif
			start_rsp( &vid_rsptask );
		} else {
			if( vid_vpipe_writing<0 && vid_dpipe_reading<0 && vid_dpipe_dataready>=0 ) {
				for( i=0; i<SYS_NUM_FRAMEBUFS; i++ ) {
					if( vpipe[i].free ) {
						vpipe[i].free = 0;
						vid_dpipe_reading = vid_dpipe_dataready;
						vid_vpipe_writing = i;
						vid_dpipe_dataready = -1;

						vid_rsptask.t.flags = 0;
						/* LATEST RELNOTES SAY TO REMOVE THIS FOR FIFO UCODE:
						//   vid_rsptask.t.flags = OS_TASK_DP_WAIT;
						*/
						init_rsp_packet( vid_dpipe_reading );

#if VID_TRACK_EVENTS
						printf(( "start g\n" ));
#endif
#if BENCH
						bench_stop( BENCHSW_RDP_IDLE );
						bench_start( BENCHSW_RDP_WORKING );
#endif
						start_rsp( &vid_rsptask );
						break;
					}
				}
			}
		}
	}
}


//////////////////////////////////////////////////////////////////////////////////////////
// prenmi_event - handles the pre-NMI event.
//////////////////////////////////////////////////////////////////////////////////////////
static void prenmi_event( void ) {
	vid_prenmi_flag = 1;
//	wess_seq_stopall();
}


//////////////////////////////////////////////////////////////////////////////////////////
// kickstart - checks whether an audio or gfx task can be given to the RSP and, if so,
//             does it. This should be called whenever there's a possibility that the RSP
//             (for audio/gfx) or the RDP (gfx) has become idle.
//////////////////////////////////////////////////////////////////////////////////////////
static void kickstart( void ) {
	osSendMesg( &sys_msgque_vid, (OSMesg)VID_MSG_KICKSTART, OS_MESG_BLOCK );	// should never block
}


//////////////////////////////////////////////////////////////////////////////////////////
// start_rsp - flushes the data cache, and sends the task structure to the RSP.
//////////////////////////////////////////////////////////////////////////////////////////
static void start_rsp( OSTask *task ) {
	osWritebackDCacheAll();

	if( vid_prenmi_flag ) return;

#if BENCH
	bench_stop( BENCHSW_RSP_IDLE );

	if( task->t.type == M_GFXTASK ) {
		bench_start( BENCHSW_RSP_WORKING_GFX );
	} else {
		bench_start( BENCHSW_RSP_WORKING_AUD );
	}
#endif

	osSpTaskStart( task );
}


static void init_rsp_packet( int dindex ) {
	gSPSegment( dpipe[dindex].dbuf, SYS_RSPSEG_FBUF, sys_fbuf_phys[vid_vpipe_writing] );
	vid_rsptask.t.data_ptr = (u64 *)dpipe[dindex].dbuf;
	vid_rsptask.t.data_size = dpipe[dindex].gfx_bytes;
}

