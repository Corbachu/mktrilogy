#include <regdef.h>
#include "mkchar.inc"

	.option	pic0

	.set noreorder
	.data

	.globl a_sb_skeleton_burn
	.globl a_robo_skeleton_burn

a_sb_skeleton_burn:
	.word SBFIRE1
	.word SBFIRE2
a_robo_skeleton_burn:
	.word SKELFIRE1
	.word SKELFIRE2
/*	.word SKELFIRE3*/
	.word SKELFIRE4
	.word SKELFIRE6
	.word 0
	.word SKELFIRE8
	.word SKELFIRE10
	.word SKELFIRE12
	.word 0
	.word SKELFIRE14
	.word SKELFIRE15
	.word SKELFIRE16
	.word 0
	.word ani_sound
	.word 0x21
	.word SKELFIRE18
	.word SKELFIRE19
	.word SKELFIRE20
	.word SKELFIRE23
	.word SKELFIRE24
	.word 0

SBFIRE1:
	.word SBFIRE1_SUB,0
SBFIRE1_SUB:
	.word SBFRE1_IMG
	.half 46, 32, 26, -20
	.word SKELFIR_P

SBFIRE2:
	.word SBFIRE2_SUB,0
SBFIRE2_SUB:
	.word SBFRE2_IMG
	.half 65, 42, 33, -12

SKELFIRE1:
	.word SKELFIRE1_SUB,0
SKELFIRE1_SUB:
	.word SKELFIRE1_IMG
	.half 93, 70, 35, -4
	.word SKELFIR_P
SKELFIRE2:
	.word SKELFIRE2_SUB,0
SKELFIRE2_SUB:
	.word SKELFIRE2_IMG
	.half 108, 77, 32, -1
	.word SKELFIR_P
/*	
SKELFIRE3:
	.word SKELFIRE3_SUB,0
SKELFIRE3_SUB:
	.word SKELFIRE3_IMG
	.half 127, 93, 37, 4
*/	
SKELFIRE4:
	.word SKELFIRE4_SUB,0
SKELFIRE4_SUB:
	.word SKELFIRE4_IMG
	.half 133, 104, 42, 5
SKELFIRE6:
	.word SKELFIRE6_SUB,0
SKELFIRE6_SUB:
	.word SKELFIRE6_IMG
	.half 144, 117, 44, 13
SKELFIRE8:
	.word SKELFIRE8_SUB,0
SKELFIRE8_SUB:
	.word SKELFIRE8_IMG
	.half 150, 68, 30, 28
SKELFIRE10:
	.word SKELFIRE10_SUB,0
SKELFIRE10_SUB:
	.word SKELFIRE10_IMG
	.half 149, 74, 30, 27
SKELFIRE12:
	.word SKELFIRE12_SUB,0
SKELFIRE12_SUB:
	.word SKELFIRE12_IMG
	.half 151, 74, 30, 29
SKELFIRE14:
	.word SKELFIRE14_SUB,0
SKELFIRE14_SUB:
	.word SKELFIRE14_IMG
	.half 142, 69, 30, 20
SKELFIRE15:
	.word SKELFIRE15_SUB,0
SKELFIRE15_SUB:
	.word SKELFIRE15_IMG
	.half 145, 69, 30, 22
SKELFIRE16:
	.word SKELFIRE16_SUB,0
SKELFIRE16_SUB:
	.word SKELFIRE16_IMG
	.half 111, 63, 30, -11
SKELFIRE18:
	.word SKELFIRE18_SUB,0
SKELFIRE18_SUB:
	.word SKELFIRE18_IMG
	.half 79, 63, 27, -44
SKELFIRE19:
	.word SKELFIRE19_SUB,0
SKELFIRE19_SUB:
	.word SKELFIRE19_IMG
	.half 58, 65, 31, -69
SKELFIRE20:
	.word SKELFIRE20_SUB,0
SKELFIRE20_SUB:
	.word SKELFIRE20_IMG
	.half 48, 76, 33, -83
SKELFIRE23:
	.word SKELFIRE23_SUB,0
SKELFIRE23_SUB:
	.word SKELFIRE23_IMG
	.half 48, 106, 41, -92
SKELFIRE24:
	.word SKELFIRE24_SUB,0
SKELFIRE24_SUB:
	.word SKELFIRE24_IMG
	.half 47, 104, 39, -93

	.align 2
#include "../../common/skelfire/skelfire.att"

	.align 2
	.globl skelfire_dict
skelfire_dict:
#include "../../common/skelfire/skelfire.dct"
