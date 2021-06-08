#include <regdef.h>
#include "mkchar.inc"

	.option	pic0
	.set	noreorder
	.data

robo_anitab1:
	.word a_helecopter
	
a_helecopter:
j_copt1:
	.word COPTERA1
	.word COPTERA2
	.word COPTERA3
	.word COPTERA4
	.word COPTERA5
	.word COPTERA6
	.word COPTERA7
	.word COPTERA8
	.word ani_jump
	.word j_copt1
	.word 0
j_copt2:
	.word COPTERB1
	.word COPTERB2
	.word COPTERB3
	.word COPTERB4
	.word COPTERB5
	.word COPTERB6
	.word COPTERB7
	.word COPTERB8
	.word ani_jump
	.word j_copt2
	.word 0
j_copt3:
	.word COPTERC1
	.word COPTERC2
	.word COPTERC3
	.word COPTERC4
	.word COPTERC5
	.word COPTERC6
	.word COPTERC7
	.word COPTERC8
	.word ani_jump
	.word j_copt3
	.word 0
	
COPTERA1:
	.word COPTERA1_SUB, 0
COPTERA1_SUB:
	.word COPTERA1_IMG
	.half 122, 55, 30, 0
COPTERA2:
	.word COPTERA2_SUB, 0
COPTERA2_SUB:
	.word COPTERA2_IMG
	.half 122, 55, 30, 1
COPTERA3:
	.word COPTERA3_SUB, 0
COPTERA3_SUB:
	.word COPTERA3_IMG
	.half 123, 55, 30, 2
COPTERA4:
	.word COPTERA4_SUB, 0
COPTERA4_SUB:
	.word COPTERA4_IMG
	.half 122, 55, 30, 0
COPTERA5:
	.word COPTERA5_SUB, 0
COPTERA5_SUB:
	.word COPTERA5_IMG
	.half 120, 55, 30, -1
COPTERA6:
	.word COPTERA6_SUB, 0
COPTERA6_SUB:
	.word COPTERA6_IMG
	.half 122, 55, 30, 0
COPTERA7:
	.word COPTERA7_SUB, 0
COPTERA7_SUB:
	.word COPTERA7_IMG
	.half 123, 56, 30, 2
COPTERA8:
	.word COPTERA8_SUB, 0
COPTERA8_SUB:
	.word COPTERA8_IMG
	.half 122, 55, 30, 1
COPTERB1:
	.word COPTERB1_SUB, 0
COPTERB1_SUB:
	.word COPTERB1_IMG
	.half 125, 76, 30, 3
COPTERB2:
	.word COPTERB2_SUB, 0
COPTERB2_SUB:
	.word COPTERB2_IMG
	.half 126, 55, 30, 4
COPTERB3:
	.word COPTERB3_SUB, 0
COPTERB3_SUB:
	.word COPTERB3_IMG
	.half 126, 67, 42, 4
COPTERB4:
	.word COPTERB4_SUB, 0
COPTERB4_SUB:
	.word COPTERB4_IMG
	.half 123, 73, 47, 2
COPTERB5:
	.word COPTERB5_SUB, 0
COPTERB5_SUB:
	.word COPTERB5_IMG
	.half 121, 75, 50, 0
COPTERB6:
	.word COPTERB6_SUB, 0
COPTERB6_SUB:
	.word COPTERB6_IMG
	.half 121, 64, 36, 0
COPTERB7:
	.word COPTERB7_SUB, 0
COPTERB7_SUB:
	.word COPTERB7_IMG
	.half 121, 71, 30, 0
COPTERB8:
	.word COPTERB8_SUB, 0
COPTERB8_SUB:
	.word COPTERB8_IMG
	.half 122, 74, 30, 1
COPTERC1:
	.word COPTERC1_SUB, 0
COPTERC1_SUB:
	.word COPTERC1_IMG
	.half 128, 94, 47, 7
COPTERC2:
	.word COPTERC2_SUB, 0
COPTERC2_SUB:
	.word COPTERC2_IMG
	.half 128, 94, 47, 7
COPTERC3:
	.word COPTERC3_SUB, 0
COPTERC3_SUB:
	.word COPTERC3_IMG
	.half 128, 94, 47, 7
COPTERC4:
	.word COPTERC4_SUB, 0
COPTERC4_SUB:
	.word COPTERC4_IMG
	.half 128, 94, 47, 7
COPTERC5:
	.word COPTERC5_SUB, 0
COPTERC5_SUB:
	.word COPTERC5_IMG
	.half 128, 94, 47, 7
COPTERC6:
	.word COPTERC6_SUB, 0
COPTERC6_SUB:
	.word COPTERC6_IMG
	.half 128, 94, 47, 7
COPTERC7:
	.word COPTERC7_SUB, 0
COPTERC7_SUB:
	.word COPTERC7_IMG
	.half 128, 94, 47, 7
COPTERC8:
	.word COPTERC8_SUB, 0
COPTERC8_SUB:
	.word COPTERC8_IMG
	.half 128, 94, 47, 7
	
	.align 2
#include "mkrobo2f2.att" 
