#include <regdef.h>
#include "mkchar.inc"

	.option	pic0
	.set	noreorder
	.data

robo_anitab1:
	.word a_bull
	
a_bull:
	.word BULL6
	.word 0
j_bull:
	.word BULL7
	.word BULL8
	.word BULL9
	.word BULL10
	.word BULL11
	.word BULL12
	.word BULL13
	.word ani_jump
	.word j_bull
	
BULL6:
	.word BULL6_SUB, 0
BULL6_SUB:
	.word BULL6_IMG
	.half 88, 156, 55, -30
	.word BULL_P
BULL7:
	.word BULL7_SUB, 0
BULL7_SUB:
	.word BULL7_IMG
	.half 94, 173, 67, -27
BULL8:
	.word BULL8_SUB, 0
BULL8_SUB:
	.word BULL8_IMG
	.half 91, 162, 66, -31
BULL9:
	.word BULL9_SUB, 0
BULL9_SUB:
	.word BULL9_IMG
	.half 88, 168, 78, -33
BULL10:
	.word BULL10_SUB, 0
BULL10_SUB:
	.word BULL10_IMG
	.half 92, 170, 78, -30
BULL11:
	.word BULL11_SUB, 0
BULL11_SUB:
	.word BULL11_IMG
	.half 86, 173, 82, -35
BULL12:
	.word BULL12_SUB, 0
BULL12_SUB:
	.word BULL12_IMG
	.half 86, 171, 76, -35
BULL13:
	.word BULL13_SUB, 0
BULL13_SUB:
	.word BULL13_IMG
	.half 88, 166, 68, -33

	.align 2
#include "mkrobo3.atta" 
