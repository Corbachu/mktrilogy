//////////////////////////////////////////////////////////////////////////////////////////
// bench.c - System benchmarking functions.
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
//#include "typedefs.h"

#include "sys.h"
#include "bench.h"
#include "stopwatch.h"

#if BENCH
//========================================================================================
// Public variables:

struct stopwatch benchsw[BENCHSW_MAX];
float bench_displayed_frames;
float bench_total_dlists;
int bench_online;


//========================================================================================
// Private variables:

#if BENCHGFX
static u32 segbase[ 16 ];

enum GFXCNT {
	GFXCNT_SAMPLES,
	GFXCNT_MTX_STACK_DEPTH_M,
	GFXCNT_MTX_STACK_DEPTH_P,
	GFXCNT_MTX_STACK_DEPTH_MAX_M,
	GFXCNT_MTX_STACK_DEPTH_MAX_P,
	GFXCNT_MTX_M,
	GFXCNT_MTX_P,
	GFXCNT_GFX_STACK_DEPTH,
	GFXCNT_GFX_STACK_DEPTH_MAX,
	GFXCNT_DISPLAY_LIST,
	GFXCNT_BRANCH_LIST,
	GFXCNT_TRI,
	GFXCNT_VTX_LOADS,
	GFXCNT_VTX_TOTAL,

	NUM_GFXCNTS
};

static int gfx_count[ NUM_GFXCNTS ];

enum GFXCMD {
	GFXCMD_MTX,
	GFXCMD_TRI,
	GFXCMD_CDL,
	GFXCMD_BDL,
	GFXCMD_POP,
	GFXCMD_EDL,
	GFXCMD_SEG,
	GFXCMD_VTX,

	NUM_GFXCMDS
};

static struct gfx_stat {
	unsigned int	w0_mask;		// word 0 mask
	unsigned int	w1_mask;		// word 1 mask
	unsigned int	w0;				// word 0
	unsigned int	w1;				// word 1
} gfx_stat[ NUM_GFXCMDS ] = {
	0xff000000, 0x00000000, (G_MTX<<24), 0,						// gSPMatrix
	0xff000000, 0x00000000, (G_TRI1<<24), 0,					// gSP1Triangle
	0xffff0000, 0x00000000, (G_DL<<24) + (G_DL_PUSH), 0,		// gSPDisplayList
	0xffff0000, 0x00000000, (G_DL<<24) + (G_DL_NOPUSH), 0,		// gSPBranchList
	0xff000000, 0x00000000, (G_POPMTX<<24), 0,					// gSPPopMatrix
	0xff000000, 0x00000000, (G_ENDDL<<24), 0,					// gSPEndDisplayList
	0xff000000, 0x00000000, (G_SEGMENT<<24), 0,					// gSPSegment
	0xff000000, 0x00000000, (G_VTX<<24), 0,						// gSPVertex
};
#endif


//========================================================================================
// Prototypes:

#if BENCHGFX
static void walk_gfx( Gfx *g );
static int find_interesting_gfx_command( Gfx *g );
static void *seg_to_k1( u32 seg );
#endif


//========================================================================================
// Public functions:

//////////////////////////////////////////////////////////////////////////////////////////
// bench_reset - resets the specified benchmark time to zero.
//////////////////////////////////////////////////////////////////////////////////////////
void bench_reset( int bench ) {
	stopwatch_reset( &benchsw[bench] );
}


//////////////////////////////////////////////////////////////////////////////////////////
// bench_reset_all - resets all benchmark times to zero.
//////////////////////////////////////////////////////////////////////////////////////////
void bench_reset_all( void ) {
	int i;

	for( i=0; i<BENCHSW_MAX; i++ ) {
		stopwatch_reset( &benchsw[i] );
	}
}


//////////////////////////////////////////////////////////////////////////////////////////
// bench_start - starts the specified benchmark time.
//////////////////////////////////////////////////////////////////////////////////////////
void bench_start( int bench ) {
	stopwatch_start( &benchsw[bench] );
}


//////////////////////////////////////////////////////////////////////////////////////////
// bench_stop - stops the benchmark and adds the delta time since it was started.
//////////////////////////////////////////////////////////////////////////////////////////
void bench_stop( int bench ) {
	stopwatch_stop( &benchsw[bench] );
}


//////////////////////////////////////////////////////////////////////////////////////////
// bench_val - returns the specified benchmark time in seconds (or 0 if none).
//////////////////////////////////////////////////////////////////////////////////////////
double bench_val( int bench ) {
	return( stopwatch_val( &benchsw[bench] ) );
}


#if BENCHGFX
//////////////////////////////////////////////////////////////////////////////////////////
// bench_reset_gfx - resets the gfx benchmark counters.
//////////////////////////////////////////////////////////////////////////////////////////
void bench_reset_gfx( void ) {
	int i;

	for( i=0; i<NUM_GFXCNTS; i++ ) gfx_count[i] = 0;
}


//////////////////////////////////////////////////////////////////////////////////////////
// bench_gfx - walks the specified gfx list and collects statistics.
//
// g must be a KSEG0 address.
//////////////////////////////////////////////////////////////////////////////////////////
void bench_gfx( Gfx *g ) {
	int i;

	gfx_count[GFXCNT_SAMPLES]++;
	walk_gfx( OS_PHYSICAL_TO_K1( OS_K0_TO_PHYSICAL(g) ) );
}


static void walk_gfx( Gfx *g ) {
	int i, p;

	for(;;) {
		i = find_interesting_gfx_command( g );
		switch( i ) {
			case GFXCMD_SEG:
				segbase[ g->words.w1 >> 24 ] = g->words.w1 & 0x00ffffff;
				break;
			case GFXCMD_CDL:
				gfx_count[GFXCNT_DISPLAY_LIST]++;
				if( ++gfx_count[GFXCNT_GFX_STACK_DEPTH] > gfx_count[GFXCNT_GFX_STACK_DEPTH_MAX] ) {
					gfx_count[GFXCNT_GFX_STACK_DEPTH_MAX] = gfx_count[GFXCNT_GFX_STACK_DEPTH];
				}
			case GFXCMD_BDL:
				gfx_count[GFXCNT_BRANCH_LIST]++;
				walk_gfx( seg_to_k1( (u32)g->words.w1 ) );
				break;
			case GFXCMD_EDL:
				gfx_count[GFXCNT_GFX_STACK_DEPTH]--;
				return;
			case GFXCMD_MTX:
				if( (g->words.w0>>16)&G_MTX_PUSH ) {
					p = (g->words.w0>>16)&G_MTX_PROJECTION ? 1 : 0;
					gfx_count[GFXCNT_MTX_M+p]++;
					if( ++gfx_count[GFXCNT_MTX_STACK_DEPTH_M+p] > gfx_count[GFXCNT_MTX_STACK_DEPTH_MAX_M+p] ) {
						gfx_count[GFXCNT_MTX_STACK_DEPTH_MAX_M+p] = gfx_count[GFXCNT_MTX_STACK_DEPTH_M+p];
					}
				}
				break;
			case GFXCMD_POP:
				p = (g->words.w0>>16)&G_MTX_PROJECTION ? 1 : 0;
				gfx_count[GFXCNT_MTX_STACK_DEPTH_M+p]--;
				break;
			case GFXCMD_TRI:
				gfx_count[GFXCNT_TRI]++;
				break;
			case GFXCMD_VTX:
				gfx_count[GFXCNT_VTX_LOADS]++;
				gfx_count[GFXCNT_VTX_TOTAL] += (int)( (g->words.w0>>20)&0xf ) + 1;
				break;
		};

		g++;
	}
}


static int find_interesting_gfx_command( Gfx *g ) {
	int i;

	for(;;) {
		for( i=0; i<NUM_GFXCMDS; i++ ) {
			if( ((g->words.w0 & gfx_stat[i].w0_mask) == gfx_stat[i].w0) && ((g->words.w1 & gfx_stat[i].w1_mask) == gfx_stat[i].w1) ) {
				return( i );
			}
		}
		g++;
	}
}


static void *seg_to_k1( u32 seg ) {
	return( OS_PHYSICAL_TO_K1( segbase[ seg>>24 ] + (seg&0x00ffffff) ) );
}
#endif


//////////////////////////////////////////////////////////////////////////////////////////
// bench_print - prints the benchmark results every BENCH_PRINT_SECS seconds.
//////////////////////////////////////////////////////////////////////////////////////////
void bench_print( void ) {
	CRITICAL_DEFS;
	static bench_countdown = BENCH_TICKS_TO_ONLINE-1;
	double rsp_idle, rsp_gfx, rsp_aud;
	double rdp_idle, rdp_gfx;
	double cpu_idle, cpu_wrk;
	float fps;
#if BENCHGFX
	int tri, mtxm, mtxp, gsamples;
#endif

	if( !bench_countdown-- ) {
		bench_countdown = BENCH_PRINT_TICKS-1;

		if( bench_online ) {
			rsp_idle = bench_val(BENCHSW_RSP_IDLE)*(double)1000.0;
			rsp_gfx = bench_val(BENCHSW_RSP_WORKING_GFX)*(double)1000.0;
			rsp_aud = bench_val(BENCHSW_RSP_WORKING_AUD)*(double)1000.0;
			rdp_idle = bench_val(BENCHSW_RDP_IDLE)*(double)1000.0;
			rdp_gfx = bench_val(BENCHSW_RDP_WORKING)*(double)1000.0;
			cpu_idle = bench_val(BENCHSW_CPU_IDLE)*(double)1000.0;
			cpu_wrk = bench_val(BENCHSW_CPU_WORKING)*(double)1000.0;

			if( bench_total_dlists ) {
				ENTER_CRITICAL;
					fps = bench_displayed_frames / bench_total_dlists * 60.0;
				LEAVE_CRITICAL;
			} else {
				fps = 0.0;
			}

			vprintf(( "%4.1ffps  RSP(%6.2fi, %6.2fg, %6.2fa)  RDP(%6.2fi, %6.2fg)  CPU(%6.2fi, %6.2fw) \n",
//			vprintf(( "FPS=%4.1f,  RSP: idle=%8.2f gfx=%8.2f aud=%8.2f,  RDP: idle=%8.2f gfx=%8.2f,  CPU: idle=%8.2f wrk=%8.2f\n",
				(double)fps,
				rsp_idle,
				rsp_gfx,
				rsp_aud,
				rdp_idle,
				rdp_gfx,
				cpu_idle,
				cpu_wrk
			));


#if BENCHGFX
			gsamples = gfx_count[GFXCNT_SAMPLES];
			if( gsamples ) {
				tri = gfx_count[GFXCNT_TRI]/gsamples;
				mtxm = gfx_count[GFXCNT_MTX_M]/gsamples;
				mtxp = gfx_count[GFXCNT_MTX_P]/gsamples;
			} else {
				tri = 0;
				mtxm = 0;
				mtxp = 0;
			}

			vprintf(( "TRI=%d, MTX-M=%d, MTX-P=%d\n",
				tri,
				mtxm,
				mtxp
			));
#endif

			ENTER_CRITICAL;
				bench_reset_all();
#if BENCHGFX
				bench_reset_gfx();
#endif
				bench_total_dlists = 0;
				bench_displayed_frames = 0;
			LEAVE_CRITICAL;
		} else {
			bench_reset_all();
#if BENCHGFX
			bench_reset_gfx();
#endif
			bench_total_dlists = 0;
			bench_displayed_frames = 0;
			bench_online = 1;
		}
	}
}


#endif
