#include <regdef.h>
#include "mkchar.inc"

	.option	pic0
	.set	noreorder
	.data

anj_anitab1:
	.word a_tony_flame
	
a_tony_flame:
	.word SCORPFIRE1
	.word SCORPFIRE2
	.word SCORPFIRE3
	.word 0
	.word SCORPFIRE4
	.word SCORPFIRE5
	.word SCORPFIRE6
	.word 0
	.word SCORPFIRE7
	.word SCORPFIRE8
	.word SCORPFIRE9
	.word SCORPFIRE10
	.word SCORPFIRE11
	.word SCORPFIRE12
	.word SCORPFIRE13
	.word 0

SCORPFIRE1:
	.word SCORPFIRE1_IMG
	.half 13, 9, -25, -8
	.word   SCFIRE_P
SCORPFIRE2:
	.word SCORPFIRE2_IMG
	.half 23, 18, -25, -8
SCORPFIRE3:
	.word SCORPFIRE3_IMG
	.half 54, 50, -35, -14
SCORPFIRE4:
	.word SCORPFIRE4_IMG
	.half 61, 65, -47, -32
SCORPFIRE5:
	.word SCORPFIRE4_IMG
	.half 61, 65, -73, -56
SCORPFIRE6:
	.word SCORPFIRE6_IMG
	.half 53, 71, -125, -77
SCORPFIRE7:
	.word SCORPFIRE7_IMG
	.half 79, 37, -130, -52
SCORPFIRE8:
	.word SCORPFIRE8_IMG
	.half 122, 49, -118, -8
SCORPFIRE9:
	.word SCORPFIRE9_IMG
	.half 139, 48, -119, 7
SCORPFIRE10:
	.word SCORPFIRE10_IMG
	.half 142, 48, -119, 9
SCORPFIRE11:
	.word SCORPFIRE11_IMG
	.half 142, 53, -114, 9
SCORPFIRE12:
	.word SCORPFIRE12_IMG
	.half 108, 54, -113, 9
SCORPFIRE13:
	.word SCORPFIRE13_IMG
	.half 71, 53, -114, 8

	.align 2
#include "mknjscf2.att" 