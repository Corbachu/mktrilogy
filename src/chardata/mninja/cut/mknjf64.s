#include <regdef.h>
#include "mkchar.inc"

	.option	pic0
	.set	noreorder
	.data

anj_anitab1:
	.word a_snake_in_da_box
	.word a_crank_box
	.word a_snowbox
	.word a_skull_in_da_box

a_snake_in_da_box:
	.word RPSNAKEBOX1A
	.word RPSNAKEBOX3A
	.word RPSNAKEBOX5A
	.word RPSNAKEBOX5A
	.word RPSNAKEBOX5A
	.word RPSNAKEBOX5A
	.word RPSNAKEBOX5A
	.word RPSNAKEBOX5A
	.word 0
a_crank_box:
	.word SCJACKBOX2
	.word SCJACKBOX5
	.word SCJACKBOX5
	.word SCJACKBOX5
	.word SCJACKBOX5
	.word SCJACKBOX8
	.word SCJACKBOX9
	.word 0
a_snowbox:
	.word SNOWBOX1
	.word SNOWBOX3
	.word SNOWBOX7
	.word 0
a_skull_in_da_box:
	.word SCSKULLBOX1A
	.word SCSKULLBOX3A
	.word SCSKULLBOX13A
	.word 0
	
SCJACKBOX2:
	.word SCJACKBOX2_SUB, 0
SCJACKBOX2_SUB:
	.word SCJACKBOX2_IMG
	.half 108, 44, 18, -4
SCJACKBOX5:
	.word SCJACKBOX5_SUB, 0
SCJACKBOX5_SUB:
	.word SCJACKBOX5_IMG
	.half 112, 46, 22, -1
SCJACKBOX8:
	.word SCJACKBOX8_SUB, 0
SCJACKBOX8_SUB:
	.word SCJACKBOX8_IMG
	.half 112, 45, 20, -1
SCJACKBOX9:
	.word SCJACKBOX9_SUB, 0
SCJACKBOX9_SUB:
	.word SCJACKBOX9_IMG
	.half 112, 47, 20, -1
RPSNAKEBOX1A:
	.word RPSNAKEBOX1A_IMG
	.half 15, 18, 10, -19
	.word JBOX3_P
RPSNAKEBOX3A:
	.word RPSNAKEBOX3A_IMG
	.half 48, 30, 22, 13
RPSNAKEBOX5A:
	.word RPSNAKEBOX5A_IMG
	.half 61, 36, 26, 26
SNOWBOX1:
	.word SNOWBOX1_IMG
	.half 25, 26, 18, -15
	.word	JBOX2_P
SNOWBOX3:
	.word SNOWBOX3_IMG
	.half 65, 51, 29, 14
SNOWBOX7:
	.word SNOWBOX7_IMG
	.half 62, 34, 25, 27
SCSKULLBOX1A:
	.word SCSKULLBOX1A_IMG
	.half 21, 21, 13, -13
	.word JBOX1_P
SCSKULLBOX3A:
	.word SCSKULLBOX3A_IMG
	.half 54, 34, 19, 14
SCSKULLBOX13A:
	.word SCSKULLBOX13A_IMG
	.half 60, 26, 21, 26

	.align 2
#include "mknj.attf" 
