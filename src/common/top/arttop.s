#include <regdef.h>
#include "mkchar.inc"

	.option	pic0

	.set noreorder
	.data

	.globl a_top
a_top:
	.word ani_swpal
	.word TOP1
	.word TOP3
	.word TOP5
	.word ani_jump
	.word a_top
	.word 0
a_topout:
	.word TOPOUT1
	.word TOPOUT2
	.word TOPOUT3
	.word TOPOUT4
	.word TOPOUT5
	.word TOPOUT6
	.word TOPOUT7
	.word 0
TOP1:
	.word TOP1_SUB,0
TOP1_SUB:
	.word TOP1_IMG
	.half 110, 56, 28, 0
	.word FLESH_P
TOP3:
	.word TOP3_SUB,0
TOP3_SUB:
	.word TOP3_IMG
	.half 110, 56, 29, 0
TOP5:
	.word TOP5_SUB,0
TOP5_SUB:
	.word TOP5_IMG
	.half 110, 56, 29, 0
TOPOUT1:
	.word TOPOUT1_SUB,0
TOPOUT1_SUB:
	.word TOPOUT1_IMG
	.half 104, 54, 29, -8
TOPOUT2:
	.word TOPOUT2_SUB,0
TOPOUT2_SUB:
	.word TOPOUT2_IMG
	.half 86, 55, 29, -25
TOPOUT3:
	.word TOPOUT3_SUB,0
TOPOUT3_SUB:
	.word TOPOUT3_IMG
	.half 76, 54, 28, -36
TOPOUT4:
	.word TOPOUT4_SUB,0
TOPOUT4_SUB:
	.word TOPOUT4_IMG
	.half 65, 56, 30, -46
TOPOUT5:
	.word TOPOUT5_SUB,0
TOPOUT5_SUB:
	.word TOPOUT5_IMG
	.half 54, 56, 31, -59
TOPOUT6:
	.word TOPOUT6_SUB,0
TOPOUT6_SUB:
	.word TOPOUT6_IMG
	.half 48, 51, 29, -71
TOPOUT7:
	.word TOPOUT7_SUB,0
TOPOUT7_SUB:
	.word TOPOUT7_IMG
	.half 17, 47, 26, -101

	.align 2
#include "../../common/top/top.att"

	.align 2
	.globl top_dict
top_dict:
#include "../../common/top/top.dct"
