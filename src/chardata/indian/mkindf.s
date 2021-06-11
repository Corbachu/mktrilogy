#include <regdef.h>
#include "mkchar.inc"

	.option	pic0
	.set	noreorder
	.data

aind_anitab1:
	.word a_ind_friend

a_ind_friend:
#ifndef CUT_FRAME
	.word INFRIENDSHIP1
	.word INFRIENDSHIP2
	.word INFRIENDSHIP3
	.word INFRIENDSHIP4
	.word ani_sladd
	.word AXE01
#endif
	.word INFRIENDSHIP5
	.word ani_sladd
	.word AXE02
	.word INFRIENDSHIP6
	.word ani_slani
	.word AXE03
j_juggle:
	.word INFRIENDSHIP7
	.word ani_slani
	.word AXE04
	.word INFRIENDSHIP8
	.word ani_slani
	.word AXE05
	.word INFRIENDSHIP9
	.word ani_slani
	.word AXE06
	.word INFRIENDSHIP10
	.word ani_slani
	.word AXE07
	.word INFRIENDSHIP11
	.word ani_slani
	.word AXE08
	.word INFRIENDSHIP12
	.word ani_slani
	.word AXE09
	.word INFRIENDSHIP13
	.word ani_slani
	.word AXE10
	.word ani_jump
	.word j_juggle
	.word 0

#ifndef CUT_FRAME
INFRIENDSHIP1:
	.word INFRIENDSHIP1_SUB, 0
INFRIENDSHIP1_SUB:
	.word INFRIENDSHIP1_IMG
	.half 108, 78, 33, -9
INFRIENDSHIP2:
	.word INFRIENDSHIP2_SUB, 0
INFRIENDSHIP2_SUB:
	.word INFRIENDSHIP2_IMG
	.half 129, 44, 17, 12
INFRIENDSHIP3:
	.word INFRIENDSHIP3_SUB, 0
INFRIENDSHIP3_SUB:
	.word INFRIENDSHIP3_IMG
	.half 105, 42, 15, -12
INFRIENDSHIP4:
	.word INFRIENDSHIP4_SUB, 0
INFRIENDSHIP4_SUB:
	.word INFRIENDSHIP4_IMG
	.half 116, 54, 22, -1
#endif
INFRIENDSHIP5:
	.word INFRIENDSHIP5_SUB, 0
INFRIENDSHIP5_SUB:
	.word INFRIENDSHIP5_IMG
	.half 106, 81, 37, -11
INFRIENDSHIP6:
	.word INFRIENDSHIP6_SUB, 0
INFRIENDSHIP6_SUB:
	.word INFRIENDSHIP6_IMG
	.half 104, 68, 29, -13
INFRIENDSHIP7:
	.word INFRIENDSHIP7_SUB, 0
INFRIENDSHIP7_SUB:
	.word INFRIENDSHIP7_IMG
	.half 108, 42, 16, -9
INFRIENDSHIP8:
	.word INFRIENDSHIP8_SUB, 0
INFRIENDSHIP8_SUB:
	.word INFRIENDSHIP8_IMG
	.half 111, 42, 15, -6
INFRIENDSHIP9:
	.word INFRIENDSHIP9_SUB, 0
INFRIENDSHIP9_SUB:
	.word INFRIENDSHIP9_IMG
	.half 112, 42, 15, -5
INFRIENDSHIP10:
	.word INFRIENDSHIP10_SUB, 0
INFRIENDSHIP10_SUB:
	.word INFRIENDSHIP10_IMG
	.half 111, 43, 17, -6
INFRIENDSHIP11:
	.word INFRIENDSHIP11_SUB, 0
INFRIENDSHIP11_SUB:
	.word INFRIENDSHIP11_IMG
	.half 110, 44, 18, -7
INFRIENDSHIP12:
	.word INFRIENDSHIP12_SUB, 0
INFRIENDSHIP12_SUB:
	.word INFRIENDSHIP12_IMG
	.half 112, 42, 16, -5
INFRIENDSHIP13:
	.word INFRIENDSHIP13_SUB, 0
INFRIENDSHIP13_SUB:
	.word INFRIENDSHIP13_IMG
	.half 111, 42, 16, -6

#ifndef CUT_FRAME
AXE01:
	.word AXE01_SUB, 0
AXE01_SUB:
	.word axe01_IMG
	.half 14, 49, 18, 0
	.word AXE_P
#endif
AXE02:
	.word AXE02_SUB, 0
AXE02_SUB:
	.word axe02_IMG
	.half 14, 121, 55, -23
	.word FRAXE_P
AXE03:
	.word AXE03_SUB, 0
AXE03_SUB:
	.word axe03_IMG
	.half 27, 107, 49, -35
AXE04:
	.word AXE04_SUB, 0
AXE04_SUB:
	.word axe04_IMG
	.half 102, 60, 28, 36
AXE05:
	.word AXE05_SUB, 0
AXE05_SUB:
	.word axe05_IMG
	.half 88, 56, 27, 44
AXE06:
	.word AXE06_SUB, 0
AXE06_SUB:
	.word axe06_IMG
	.half 102, 56, 27, 48
AXE07:
	.word AXE07_SUB, 0
AXE07_SUB:
	.word axe07_IMG
	.half 113, 58, 30, 36
AXE08:
	.word AXE08_SUB, 0
AXE08_SUB:
	.word axe08_IMG
	.half 107, 61, 35, 39
AXE09:
	.word AXE09_SUB, 0
AXE09_SUB:
	.word axe09_IMG
	.half 85, 57, 30, 43
AXE10:
	.word AXE10_SUB, 0
AXE10_SUB:
	.word axe10_IMG
	.half 96, 52, 28, 48

	.align 2
#include "mkind.attf" 
