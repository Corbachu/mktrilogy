#include <regdef.h>
#include "mkchar.inc"

	.option	pic0
	.set	noreorder
	.data

anj_anitab1:
	.word a_hi_tongue
	.word a_med_tongue
	.word a_lo_tongue
	.word a_reptile_chomp_head

a_hi_tongue:
	.word RPHITUNG1
	.word RPHITUNG9
	.word RPHITUNG11
	.word 0
	.word RPHITUNG9
	.word RPHITUNG1
	.word 0
a_med_tongue:
	.word RPMEDTUNG1
	.word RPMEDTUNG9
	.word RPMEDTUNG11
	.word 0
	.word RPMEDTUNG9
	.word RPMEDTUNG1
	.word 0
a_lo_tongue:
	.word RPLOTUNG1
	.word RPLOTUNG9
	.word RPLOTUNG11
	.word 0
	.word RPLOTUNG9
	.word RPLOTUNG1
	.word 0
a_reptile_chomp_head:
	.word RPCHOMP1
	.word 0
	.word RPCHOMP7
	.word RPCHOMP11
	.word RPCHOMP13
	.word RPCHOMP1
	.word 0

RPHITUNG1:
	.word RPHITUNG1_IMG
	.half 4, 21, -25, -3
	.word TUNG_P
RPHITUNG9:
	.word RPHITUNG9_IMG
	.half 9, 131, -24, 0
RPHITUNG11:
	.word RPHITUNG11_IMG
	.half 14, 155, -24, 1
RPMEDTUNG1:
	.word RPMEDTUNG1_IMG
	.half 6, 19, -24, -2
	.word TUNG_P
RPMEDTUNG9:
	.word RPMEDTUNG9_IMG
	.half 29, 129, -24, -2
RPMEDTUNG11:
	.word RPMEDTUNG11_IMG
	.half 31, 154, -24, -2
RPLOTUNG1:
	.word RPLOTUNG1_IMG
	.half 7, 19, -24, -3
	.word TUNG_P
RPLOTUNG9:
	.word RPLOTUNG9_IMG
	.half 40, 126, -24, -2
RPLOTUNG11:
	.word RPLOTUNG11_IMG
	.half 55, 148, -25, -2
RPCHOMP1:
	.word RPCHOMP1_IMG
	.half 19, 16, -17, 1
	.word REPHEAD_P
RPCHOMP7:
	.word RPCHOMP7_IMG
	.half 80, 39, -15, 37
RPCHOMP11:
	.word RPCHOMP11_IMG
	.half 30, 75, -13, 11
RPCHOMP13:
	.word RPCHOMP13_IMG
	.half 20, 38, -16, 2
	
	.align 2
#include "mknjrpf1.att" 
