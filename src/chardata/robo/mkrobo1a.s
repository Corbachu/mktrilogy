#include <regdef.h>
#include "mkchar.inc"

	.option	pic0
	.set	noreorder
	.data

robo_anitab1:
	.word a_bat
	
a_bat:
#ifdef CUT_FRAME
	.word BAT11
#else
	.word BAT6
#endif
	.word 0
#ifdef CUT_FRAME
	.word BAT12
#else
	.word BAT7
#endif
j_bat:
#ifdef CUT_FRAME
	.word BAT13
#else
	.word BAT8
#endif
	.word BAT9
	.word BAT10
	.word BAT11
	.word BAT12
	.word BAT13
	.word ani_jump
	.word j_bat
	.word 0
	
#ifndef CUT_FRAME
BAT6:
	.word BAT6_SUB, 0
BAT6_SUB:
	.word BAT6_IMG
	.half 101, 146, 81, 17
	.word BAT_P
BAT7:
	.word BAT7_SUB, 0
BAT7_SUB:
	.word BAT7_IMG
	.half 54, 177, 67, -33
BAT8:
	.word BAT8_SUB, 0
BAT8_SUB:
	.word BAT8_IMG
	.half 73, 118, 26, -34
#endif
BAT9:
	.word BAT9_SUB, 0
BAT9_SUB:
	.word BAT9_IMG
	.half 76, 114, 29, -19
BAT10:
	.word BAT10_SUB, 0
BAT10_SUB:
	.word BAT10_IMG
	.half 82, 102, 38, -1
BAT11:
	.word BAT11_SUB, 0
BAT11_SUB:
	.word BAT11_IMG
	.half 106, 146, 82, 17
#ifdef CUT_FRAME
	.word BAT_P
#endif
BAT12:
	.word BAT12_SUB, 0
BAT12_SUB:
	.word BAT12_IMG
	.half 60, 177, 67, -33
BAT13:
	.word BAT13_SUB, 0
BAT13_SUB:
	.word BAT13_IMG
	.half 73, 118, 25, -34
	
	.align 2
#include "mkrobo1a.att" 
