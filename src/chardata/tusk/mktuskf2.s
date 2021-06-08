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
	
#ifdef CUT_FRAME
	.word ani_sladd
	.word TUBE4
	.word TRTUBESTANCE
	.word ani_slani_sleep
	.word TUBE5
	.word ani_slani_sleep
	.word TUBE6
	.word 0

	.word ani_slani_sleep
	.word TUBE7
	.word ani_slani_sleep
	.word TUBE8
	.word ani_slani_sleep
	.word TUBE9
	.word ani_slani_sleep
	.word TUBE10
	.word ani_slani_sleep
	.word TUBE11
	.word ani_slani_sleep
	.word TUBE12
	.word ani_slani
	.word TUBE13
	.word TRTUBESTANCE
	.word 0

	.word ani_slani_sleep
	.word TUBE14
	.word ani_slani
	.word TUBE15
	.word TRTUBESTANCE
	.word 0
	
#else
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
#endif
	
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
#ifdef CUT_FRAME
TRTUBESTANCE:
	.word TRTUBESTANCE_SUB, 0
TRTUBESTANCE_SUB:
	.word TRTUBESTANCE_IMG
	.half 115, 45, 17, -6
	.word   TSKTAN_P

TUBE4:
	.word TUBE4_SUB, 0
TUBE4_SUB:
	.word TUBE4_IMG
	.half 27, 75, -19, -23
	.word   TSKTAN_P
TUBE5:
	.word TUBE5_SUB, 0
TUBE5_SUB:
	.word TUBE5_IMG
	.half 29, 115, -19, -21
TUBE6:
	.word TUBE6_SUB, 0
TUBE6_SUB:
	.word TUBE6_IMG
	.half 10, 136, -19, -40
TUBE7:
	.word TUBE7_SUB, 0
TUBE7_SUB:
	.word TUBE7_IMG
	.half 8, 141, -19, -43
TUBE8:
	.word TUBE8_SUB, 0
TUBE8_SUB:
	.word TUBE8_IMG
	.half 13, 141, -19, -41
TUBE9:
	.word TUBE9_SUB, 0
TUBE9_SUB:
	.word TUBE9_IMG
	.half 13, 141, -19, -41
TUBE10:
	.word TUBE10_SUB, 0
TUBE10_SUB:
	.word TUBE10_IMG
	.half 13, 141, -19, -41
TUBE11:
	.word TUBE11_SUB, 0
TUBE11_SUB:
	.word TUBE11_IMG
	.half 13, 141, -19, -41
TUBE12:
	.word TUBE12_SUB, 0
TUBE12_SUB:
	.word TUBE12_IMG
	.half 13, 141, -19, -41
TUBE13:
	.word TUBE13_SUB, 0
TUBE13_SUB:
	.word TUBE13_IMG
	.half 14, 141, -19, -41
TUBE14:
	.word TUBE14_SUB, 0
TUBE14_SUB:
	.word TUBE14_IMG
	.half 9, 67, -19, -42
TUBE15:
	.word TUBE15_SUB, 0
TUBE15_SUB:
	.word TUBE15_IMG
	.half 8, 13, -19, -42
#else
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
#endif
	
	.align 2
#include "mktuskf2.att" 
