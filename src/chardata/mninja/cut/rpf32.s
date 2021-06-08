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
	.word RPHITUNG3
	.word RPHITUNG5
	.word RPHITUNG7
	.word RPHITUNG9
	.word RPHITUNG11
	.word 0
	.word RPHITUNG9
	.word RPHITUNG7
	.word RPHITUNG5
	.word RPHITUNG3
	.word RPHITUNG1
	.word 0
a_med_tongue:
	.word RPMEDTUNG1
	.word RPMEDTUNG3
	.word RPMEDTUNG5
	.word RPMEDTUNG7
	.word RPMEDTUNG9
	.word RPMEDTUNG11
	.word 0
	.word RPMEDTUNG9
	.word RPMEDTUNG7
	.word RPMEDTUNG5
	.word RPMEDTUNG3
	.word RPMEDTUNG1
	.word 0
a_lo_tongue:
	.word RPLOTUNG1
	.word RPLOTUNG3
	.word RPLOTUNG5
	.word RPLOTUNG7
	.word RPLOTUNG9
	.word RPLOTUNG11
	.word 0
	.word RPLOTUNG9
	.word RPLOTUNG7
	.word RPLOTUNG5
	.word RPLOTUNG3
	.word RPLOTUNG1
	.word 0
a_reptile_chomp_head:
	.word RPCHOMP1
	.word RPCHOMP3
	.word 0
	.word RPCHOMP5
	.word RPCHOMP7
	.word RPCHOMP9
	.word RPCHOMP11
	.word RPCHOMP13
	.word RPCHOMP1
	.word 0

RPHITUNG1:
	.word RPHITUNG1_IMG
	.half 4, 21, -25, -3
	.word TUNG_P
RPHITUNG3:
	.word RPHITUNG3_IMG
	.half 7, 35, -24, -1
RPHITUNG5:
	.word RPHITUNG5_IMG
	.half 9, 64, -24, 0
RPHITUNG7:
	.word RPHITUNG7_IMG
	.half 9, 94, -24, -1
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
RPMEDTUNG3:
	.word RPMEDTUNG3_IMG
	.half 11, 34, -23, -2
RPMEDTUNG5:
	.word RPMEDTUNG5_IMG
	.half 15, 62, -24, -2
RPMEDTUNG7:
	.word RPMEDTUNG7_IMG
	.half 21, 93, -24, -2
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
RPLOTUNG3:
	.word RPLOTUNG3_IMG
	.half 12, 34, -24, -2
RPLOTUNG5:
	.word RPLOTUNG5_IMG
	.half 16, 62, -24, -2
RPLOTUNG7:
	.word RPLOTUNG7_IMG
	.half 32, 90, -24, -2
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
RPCHOMP3:
	.word RPCHOMP3_IMG
	.half 20, 14, -17, 2
RPCHOMP5:
	.word RPCHOMP5_IMG
	.half 54, 17, -16, 21
RPCHOMP7:
	.word RPCHOMP7_IMG
	.half 80, 39, -15, 37
RPCHOMP9:
	.word RPCHOMP9_IMG
	.half 49, 80, -11, 23
RPCHOMP11:
	.word RPCHOMP11_IMG
	.half 30, 75, -13, 11
RPCHOMP13:
	.word RPCHOMP13_IMG
	.half 20, 38, -16, 2
	
	.align 2
#include "mknjrpf1.att" 
