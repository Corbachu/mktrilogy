#include <regdef.h>
#include "mkchar.inc"

	.option	pic0
	.set	noreorder
	.data

anj_anitab1:
	.word a_icespike
	
a_icespike:	
	.word ICSPIKE1
	.word ICSPIKE2
	.word ICSPIKE3
	.word ICSPIKE4
	.word ICSPIKE5
	.word ICSPIKE6
	.word ICSPIKE7
	.word ICSPIKE8
	.word ICSPIKE9
	.word ICSPIKE10
	.word 0
	
ICSPIKE1:
	.word ICSPIKE1_SUB, 0
ICSPIKE1_SUB:
	.word ICSPIKE1_IMG
	.half 21, 19, -9, -36
	.word	ICE_P
ICSPIKE2:
	.word ICSPIKE2_SUB, 0
ICSPIKE2_SUB:
	.word ICSPIKE2_IMG
	.half 44, 39, -4, -29
ICSPIKE3:
	.word ICSPIKE3_SUB, 0
ICSPIKE3_SUB:
	.word ICSPIKE3_IMG
	.half 70, 64, 0, -25
ICSPIKE4:
	.word ICSPIKE4_SUB, 0
ICSPIKE4_SUB:
	.word ICSPIKE4_IMG
	.half 82, 98, -4, -29
ICSPIKE5:
	.word ICSPIKE5_SUB, 0
ICSPIKE5_SUB:
	.word ICSPIKE5_IMG
	.half 73, 102, -9, -37
ICSPIKE6:
	.word ICSPIKE6_SUB, 0
ICSPIKE6_SUB:
	.word ICSPIKE6_IMG
	.half 68, 102, -17, -44
ICSPIKE7:
	.word ICSPIKE7_SUB, 0
ICSPIKE7_SUB:
	.word ICSPIKE7_IMG
	.half 59, 92, -30, -54
ICSPIKE8:
	.word ICSPIKE8_SUB, 0
ICSPIKE8_SUB:
	.word ICSPIKE8_IMG
	.half 79, 79, -45, -35
ICSPIKE9:
	.word ICSPIKE9_SUB, 0
ICSPIKE9_SUB:
	.word ICSPIKE9_IMG
	.half 99, 69, -58, -16
ICSPIKE10:
	.word ICSPIKE10_SUB, 0
ICSPIKE10_SUB:
	.word ICSPIKE10_IMG
	.half 110, 42, -80, -7
	
	.align 2
#include "mknjszf2.att" 