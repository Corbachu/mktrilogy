#include <regdef.h>
#include "mkchar.inc"

	.option	pic0
	.set	noreorder
	.data

aind_anitab1:
	.word	a_indiam_wolf
	
a_indiam_wolf:
	.word WOLF1
	.word WOLF3
	.word WOLF5
	.word WOLF6
	.word 0
	.word WOLF11
	.word WOLF12
	.word WOLF13
	.word 0
	.word WOLF14
j_wolf:
	.word WOLF15
	.word WOLF18
	.word ani_jump
	.word j_wolf
	.word 0
	.word WOLF20
	.word 0
	
WOLF1:
	.word WOLF1_SUB, 0
WOLF1_SUB:
	.word WOLF1_IMG
	.half 106, 52, 21, -10
	.word WOLF_P
WOLF3:
	.word WOLF3_SUB, 0
WOLF3_SUB:
	.word WOLF3_IMG
	.half 105, 50, 20, -15
WOLF5:
	.word WOLF5_SUB, 0
WOLF5_SUB:
	.word WOLF5_IMG
	.half 84, 49, 14, -36
WOLF6:
	.word WOLF6_SUB, 0
WOLF6_SUB:
	.word WOLF6_IMG
	.half 72, 63, 18, -51
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
#include "mkinda64.att" 
