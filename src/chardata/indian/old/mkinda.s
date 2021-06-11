#include <regdef.h>
#include "mkchar.inc"

	.option	pic0
	.set	noreorder
	.data

aind_anitab1:
	.word	a_indiam_wolf
	
a_indiam_wolf:
	.word WOLF6
	.word 0
	.word WOLF11
	.word WOLF12
	.word WOLF13
	.word 0
	.word WOLF14
j_wolf:
	.word WOLF15
	.word WOLF16
	.word WOLF18
	.word ani_jump
	.word j_wolf
	.word 0
	.word WOLF20
	.word 0
	
WOLF6:
	.word WOLF6_SUB, 0
WOLF6_SUB:
	.word WOLF6_IMG
	.half 72, 63, 18, -51
	.word WOLF_P
WOLF11:
	.word WOLF11_SUB, 0
WOLF11_SUB:
	.word WOLF11_IMG
	.half 73, 103, 40, -46
WOLF12:
	.word WOLF12_SUB, 0
WOLF12_SUB:
	.word WOLF12_IMG
	.half 69, 104, 36, -17
WOLF13:
	.word WOLF13_SUB, 0
WOLF13_SUB:
	.word WOLF13_IMG
	.half 65, 78, 38, -8
WOLF14:
	.word WOLF14_SUB, 0
WOLF14_SUB:
	.word WOLF14_IMG
	.half 52, 85, 42, -36
WOLF15:
	.word WOLF15_SUB, 0
WOLF15_SUB:
	.word WOLF15_IMG
	.half 57, 82, 34, -69
WOLF16:
	.word WOLF16_SUB, 0
WOLF16_SUB:
	.word WOLF16_IMG
	.half 55, 83, 30, -70
WOLF18:
	.word WOLF18_SUB, 0
WOLF18_SUB:
	.word WOLF18_IMG
	.half 59, 76, 27, -68
WOLF20:
	.word WOLF20_SUB, 0
WOLF20_SUB:
	.word WOLF20_IMG
	.half 72, 66, 17, -53

	.align 2
#include "mkind.atta" 
