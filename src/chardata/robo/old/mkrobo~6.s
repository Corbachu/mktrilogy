#include <regdef.h>
#include "mkchar.inc"

	.option	pic0
	.set	noreorder
	.data

robo_anitab1:
	.word a_flame_on
	
a_flame_on:
	.word RBFLAMEON1
	.word RBFLAMEON2
	.word RBFLAMEON3
	.word RBFLAMEON3
	.word RBFLAMEON3
	.word ani_sound
	.word 0x1f
	.word ani_sladd
	.word RFIRE1
	.word ani_slani_sleep
	.word RFIRE1
	.word ani_slani_sleep
	.word RFIRE2
	.word ani_slani_sleep
	.word RFIRE3
	.word ani_slani_sleep
	.word RFIRE4
	.word ani_slani_sleep
	.word RFIRE5
	.word ani_slani_sleep
	.word RFIRE6
	.word 0
	.word RBFLAMEON2
	.word RBFLAMEON1
	.word 0
	
RBFLAMEON1:
	.word RBFLAMEON1_SUB, 0
RBFLAMEON1_SUB:
	.word RBFLAMEON1_IMG
	.half 111, 52, 20, -11
RBFLAMEON2:
	.word RBFLAMEON2_SUB, 0
RBFLAMEON2_SUB:
	.word RBFLAMEON2_IMG
	.half 105, 51, 22, -16
RBFLAMEON3:
	.word RBFLAMEON3_SUB, 0
RBFLAMEON3_SUB:
	.word RBFLAMEON3_IMG
	.half 94, 65, 21, -27
	
RFIRE1:
	.word RFIRE1_SUB, 0
RFIRE1_SUB:
	.word RFIRE1_IMG
	.half 9, 30, -40, -34
	.word SKELFIR_P
RFIRE2:
	.word RFIRE2_SUB, 0
RFIRE2_SUB:
	.word RFIRE2_IMG
	.half 12, 44, -40, -31
RFIRE3:
	.word RFIRE3_SUB, 0
RFIRE3_SUB:
	.word RFIRE3_IMG
	.half 15, 64, -40, -29
RFIRE4:
	.word RFIRE4_SUB, 0
RFIRE4_SUB:
	.word RFIRE4_IMG
	.half 18, 87, -40, -26
RFIRE5:
	.word RFIRE5_SUB, 0
RFIRE5_SUB:
	.word RFIRE5_IMG
	.half 24, 138, -40, -20
RFIRE6:
	.word RFIRE6_SUB, 0
RFIRE6_SUB:
	.word RFIRE6_IMG
	.half 46, 122, -64, -11

	.align 2
#include "mkrobo1f2.att" 
