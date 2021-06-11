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
	.word RPHITUNG2
	.word RPHITUNG3
	.word RPHITUNG4
	.word RPHITUNG5
	.word RPHITUNG6
	.word RPHITUNG7
	.word RPHITUNG8
	.word RPHITUNG9
	.word RPHITUNG10
	.word RPHITUNG11
	.word 0
	.word RPHITUNG10
	.word RPHITUNG9
	.word RPHITUNG8
	.word RPHITUNG7
	.word RPHITUNG6
	.word RPHITUNG5
	.word RPHITUNG4
	.word RPHITUNG3
	.word RPHITUNG2
	.word RPHITUNG1
	.word 0
a_med_tongue:
	.word RPMEDTUNG1
	.word RPMEDTUNG2
	.word RPMEDTUNG3
	.word RPMEDTUNG4
	.word RPMEDTUNG5
	.word RPMEDTUNG6
	.word RPMEDTUNG7
	.word RPMEDTUNG8
	.word RPMEDTUNG9
	.word RPMEDTUNG10
	.word RPMEDTUNG11
	.word 0
	.word RPMEDTUNG10
	.word RPMEDTUNG9
	.word RPMEDTUNG8
	.word RPMEDTUNG7
	.word RPMEDTUNG6
	.word RPMEDTUNG5
	.word RPMEDTUNG4
	.word RPMEDTUNG3
	.word RPMEDTUNG2
	.word RPMEDTUNG1
	.word 0
a_lo_tongue:
	.word RPLOTUNG1
	.word RPLOTUNG2
	.word RPLOTUNG3
	.word RPLOTUNG4
	.word RPLOTUNG5
	.word RPLOTUNG6
	.word RPLOTUNG7
	.word RPLOTUNG8
	.word RPLOTUNG9
	.word RPLOTUNG10
	.word RPLOTUNG11
	.word 0
	.word RPLOTUNG10
	.word RPLOTUNG9
	.word RPLOTUNG8
	.word RPLOTUNG7
	.word RPLOTUNG6
	.word RPLOTUNG5
	.word RPLOTUNG4
	.word RPLOTUNG3
	.word RPLOTUNG2
	.word RPLOTUNG1
	.word 0
a_reptile_chomp_head:
	.word RPCHOMP1
	.word RPCHOMP2
	.word RPCHOMP3
	.word RPCHOMP4
	.word 0
	.word RPCHOMP5
	.word RPCHOMP6
	.word RPCHOMP7
	.word RPCHOMP8
	.word RPCHOMP9
	.word RPCHOMP10
	.word RPCHOMP11
	.word RPCHOMP12
	.word RPCHOMP13
	.word RPCHOMP14
	.word RPCHOMP1
	.word 0

RPHITUNG1:
	.word RPHITUNG1_IMG
	.half 4, 21, -25, -3
	.word TUNG_P
RPHITUNG2:
	.word RPHITUNG2_IMG
	.half 6, 29, -24, -2
RPHITUNG3:
	.word RPHITUNG3_IMG
	.half 7, 35, -24, -1
RPHITUNG4:
	.word RPHITUNG4_IMG
	.half 9, 45, -24, 0
RPHITUNG5:
	.word RPHITUNG5_IMG
	.half 9, 64, -24, 0
RPHITUNG6:
	.word RPHITUNG6_IMG
	.half 9, 82, -24, 0
RPHITUNG7:
	.word RPHITUNG7_IMG
	.half 9, 94, -24, -1
RPHITUNG8:
	.word RPHITUNG8_IMG
	.half 10, 110, -24, 0
RPHITUNG9:
	.word RPHITUNG9_IMG
	.half 9, 131, -24, 0
RPHITUNG10:
	.word RPHITUNG10_IMG
	.half 12, 149, -24, 0
RPHITUNG11:
	.word RPHITUNG11_IMG
	.half 14, 155, -24, 1
RPMEDTUNG1:
	.word RPMEDTUNG1_IMG
	.half 6, 19, -24, -2
	.word TUNG_P
RPMEDTUNG2:
	.word RPMEDTUNG2_IMG
	.half 9, 27, -24, -2
RPMEDTUNG3:
	.word RPMEDTUNG3_IMG
	.half 11, 34, -23, -2
RPMEDTUNG4:
	.word RPMEDTUNG4_IMG
	.half 11, 45, -23, -2
RPMEDTUNG5:
	.word RPMEDTUNG5_IMG
	.half 15, 62, -24, -2
RPMEDTUNG6:
	.word RPMEDTUNG6_IMG
	.half 21, 78, -24, -2
RPMEDTUNG7:
	.word RPMEDTUNG7_IMG
	.half 21, 93, -24, -2
RPMEDTUNG8:
	.word RPMEDTUNG8_IMG
	.half 26, 107, -24, -2
RPMEDTUNG9:
	.word RPMEDTUNG9_IMG
	.half 29, 129, -24, -2
RPMEDTUNG10:
	.word RPMEDTUNG10_IMG
	.half 29, 146, -24, -2
RPMEDTUNG11:
	.word RPMEDTUNG11_IMG
	.half 31, 154, -24, -2
RPLOTUNG1:
	.word RPLOTUNG1_IMG
	.half 7, 19, -24, -3
	.word TUNG_P
RPLOTUNG2:
	.word RPLOTUNG2_IMG
	.half 11, 25, -24, -2
RPLOTUNG3:
	.word RPLOTUNG3_IMG
	.half 12, 34, -24, -2
RPLOTUNG4:
	.word RPLOTUNG4_IMG
	.half 14, 44, -24, -2
RPLOTUNG5:
	.word RPLOTUNG5_IMG
	.half 16, 62, -24, -2
RPLOTUNG6:
	.word RPLOTUNG6_IMG
	.half 28, 77, -24, -2
RPLOTUNG7:
	.word RPLOTUNG7_IMG
	.half 32, 90, -24, -2
RPLOTUNG8:
	.word RPLOTUNG8_IMG
	.half 34, 106, -24, -2
RPLOTUNG9:
	.word RPLOTUNG9_IMG
	.half 40, 126, -24, -2
RPLOTUNG10:
	.word RPLOTUNG10_IMG
	.half 52, 140, -25, -2
RPLOTUNG11:
	.word RPLOTUNG11_IMG
	.half 55, 148, -25, -2
RPCHOMP1:
	.word RPCHOMP1_IMG
	.half 19, 16, -17, 1
	.word REPHEAD_P
RPCHOMP2:
	.word RPCHOMP2_IMG
	.half 20, 14, -17, 2
RPCHOMP3:
	.word RPCHOMP3_IMG
	.half 20, 14, -17, 2
RPCHOMP4:
	.word RPCHOMP4_IMG
	.half 28, 16, -16, 9
RPCHOMP5:
	.word RPCHOMP5_IMG
	.half 54, 17, -16, 21
RPCHOMP6:
	.word RPCHOMP6_IMG
	.half 78, 25, -16, 37
RPCHOMP7:
	.word RPCHOMP7_IMG
	.half 80, 39, -15, 37
RPCHOMP8:
	.word RPCHOMP8_IMG
	.half 71, 68, -11, 32
RPCHOMP9:
	.word RPCHOMP9_IMG
	.half 49, 80, -11, 23
RPCHOMP10:
	.word RPCHOMP10_IMG
	.half 35, 78, -13, 16
RPCHOMP11:
	.word RPCHOMP11_IMG
	.half 30, 75, -13, 11
RPCHOMP12:
	.word RPCHOMP12_IMG
	.half 23, 56, -15, 4
RPCHOMP13:
	.word RPCHOMP13_IMG
	.half 20, 38, -16, 2
RPCHOMP14:
	.word RPCHOMP14_IMG
	.half 20, 25, -14, 1
	
	.align 2
#include "mknjrpf1.att" 
