#include <regdef.h>
#include "mkchar.inc"

	.option	pic0
	.set	noreorder
	.data

atusk_anitab1:
	.word a_tube
	
a_tube:
	.word TRTUBE1
	.word TRTUBE2
	.word TRTUBE3
	.word TRTUBE4
	.word TRTUBE5
	.word TRTUBE6
	.word 0
	.word TRTUBE7
	.word TRTUBE8
	.word TRTUBE9
	.word TRTUBE10
	.word TRTUBE11
	.word TRTUBE12
	.word TRTUBE13
	.word 0
	.word TRTUBE14
	.word TRTUBE15
	.word 0
	
TRTUBE1:
	.word TRTUBE1_SUB, 0
TRTUBE1_SUB:
	.word TRTUBE1_IMG
	.half 115, 57, 18, -7
TRTUBE2:
	.word TRTUBE2_SUB, 0
TRTUBE2_SUB:
	.word TRTUBE2_IMG
	.half 115, 45, 17, -6
TRTUBE3:
	.word TRTUBE3_SUB, 0
TRTUBE3_SUB:
	.word TRTUBE3_IMG
	.half 113, 57, 16, -8
TRTUBE4:
	.word TRTUBE4_SUB, 0
TRTUBE4_SUB:
	.word TRTUBE4_IMG
	.half 115, 111, 17, -6
TRTUBE5:
	.word TRTUBE5_SUB, 0
TRTUBE5_SUB:
	.word TRTUBE5_IMG
	.half 115, 151, 17, -6
TRTUBE6:
	.word TRTUBE6_SUB, 0
TRTUBE6_SUB:
	.word TRTUBE6_IMG
	.half 115, 172, 17, -6
TRTUBE7:
	.word TRTUBE7_SUB, 0
TRTUBE7_SUB:
	.word TRTUBE7_IMG
	.half 115, 177, 17, -6
TRTUBE8:
	.word TRTUBE8_SUB, 0
TRTUBE8_SUB:
	.word TRTUBE8_IMG
	.half 115, 177, 17, -6
TRTUBE9:
	.word TRTUBE9_SUB, 0
TRTUBE9_SUB:
	.word TRTUBE9_IMG
	.half 115, 177, 17, -6
TRTUBE10:
	.word TRTUBE10_SUB, 0
TRTUBE10_SUB:
	.word TRTUBE10_IMG
	.half 115, 177, 17, -6
TRTUBE11:
	.word TRTUBE11_SUB, 0
TRTUBE11_SUB:
	.word TRTUBE11_IMG
	.half 115, 177, 17, -6
TRTUBE12:
	.word TRTUBE12_SUB, 0
TRTUBE12_SUB:
	.word TRTUBE12_IMG
	.half 115, 177, 17, -6
TRTUBE13:
	.word TRTUBE13_SUB, 0
TRTUBE13_SUB:
	.word TRTUBE13_IMG
	.half 115, 177, 17, -6
TRTUBE14:
	.word TRTUBE14_SUB, 0
TRTUBE14_SUB:
	.word TRTUBE14_IMG
	.half 115, 103, 17, -6
TRTUBE15:
	.word TRTUBE15_SUB, 0
TRTUBE15_SUB:
	.word TRTUBE15_IMG
	.half 115, 46, 14, -6
	
	.align 2
#include "mktuskf2.att" 
