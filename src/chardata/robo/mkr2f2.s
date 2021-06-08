#include <regdef.h>
#include "mkchar.inc"

	.option	pic0
	.set	noreorder
	.data

robo_anitab1:
	.word a_helecopter
	
#ifdef CUT_FRAME
a_helecopter:
	.word ani_sladd
	.word COPTERHEADA1
	.word COPTERBODY
	
j_copt1:
	.word ani_slani
	.word COPTERHEADA1
	.word COPTERBODY

	.word ani_slani
	.word COPTERHEADA3
	.word COPTERBODY

	.word ani_slani
	.word COPTERHEADA5
	.word COPTERBODY

	.word ani_slani
	.word COPTERHEADA7
	.word COPTERBODY
	.word ani_jump
	.word j_copt1
	.word 0
	
j_copt2:
	.word ani_slani
	.word COPTERHEADB1
	.word COPTERBODY

	.word ani_slani
	.word COPTERHEADB3
	.word COPTERBODY

	.word ani_slani
	.word COPTERHEADB5
	.word COPTERBODY

	.word ani_slani
	.word COPTERHEADB7
	.word COPTERBODY
	.word ani_jump
	.word j_copt2
	.word 0
j_copt3:
	.word ani_slani
	.word COPTERHEADC1
	.word COPTERBODY

	.word ani_slani
	.word COPTERHEADC3
	.word COPTERBODY

	.word ani_slani
	.word COPTERHEADC5
	.word COPTERBODY

	.word ani_slani
	.word COPTERHEADC7
	.word COPTERBODY
	
	.word ani_jump
	.word j_copt3
	.word 0
	
COPTERBODY:
	.word COPTERBODY_SUB, 0
COPTERBODY_SUB:
	.word COPTERBODY_IMG
	.half 122, 55, 30, 0

COPTERHEADA1:
	.word COPTERHEADA1_SUB, 0
COPTERHEADA1_SUB:
	.word COPTERHEADA1_IMG
	.half 23, 38, 17, 0
	.word R2PAL1_P
	
COPTERHEADA3:
	.word COPTERHEADA3_SUB, 0
COPTERHEADA3_SUB:
	.word COPTERHEADA3_IMG
	.half 24, 35, 23, 1
COPTERHEADA5:
	.word COPTERHEADA5_SUB, 0
COPTERHEADA5_SUB:
	.word COPTERHEADA5_IMG
	.half 21, 37, 23, -2
COPTERHEADA7:
	.word COPTERHEADA7_SUB, 0
COPTERHEADA7_SUB:
	.word COPTERHEADA7_IMG
	.half 24, 42, 16, 1
COPTERHEADB1:
	.word COPTERHEADB1_SUB, 0
COPTERHEADB1_SUB:
	.word COPTERHEADB1_IMG
	.half 26, 62, 16, 3
COPTERHEADB3:
	.word COPTERHEADB3_SUB, 0
COPTERHEADB3_SUB:
	.word COPTERHEADB3_IMG
	.half 27, 55, 42, 4
COPTERHEADB5:
	.word COPTERHEADB5_SUB, 0
COPTERHEADB5_SUB:
	.word COPTERHEADB5_IMG
	.half 22, 62, 50, -1
COPTERHEADB7:
	.word COPTERHEADB7_SUB, 0
COPTERHEADB7_SUB:
	.word COPTERHEADB7_IMG
	.half 22, 58, 17, -1
COPTERHEADC1:
	.word COPTERHEADC1_SUB, 0
COPTERHEADC1_SUB:
	.word COPTERHEADC1_IMG
	.half 30, 94, 47, 7
COPTERHEADC3:
	.word COPTERHEADC3_SUB, 0
COPTERHEADC3_SUB:
	.word COPTERHEADC3_IMG
	.half 30, 94, 47, 7
COPTERHEADC5:
	.word COPTERHEADC5_SUB, 0
COPTERHEADC5_SUB:
	.word COPTERHEADC5_IMG
	.half 30, 94, 47, 7
COPTERHEADC7:
	.word COPTERHEADC7_SUB, 0
COPTERHEADC7_SUB:
	.word COPTERHEADC7_IMG
	.half 30, 94, 47, 7
#else
a_helecopter:
j_copt1:
	.word COPTERA1
#ifndef CUT_FRAME
	.word COPTERA2
#endif
	.word COPTERA3
#ifndef CUT_FRAME
	.word COPTERA4
#endif
	.word COPTERA5
#ifndef CUT_FRAME
	.word COPTERA6
#endif
	.word COPTERA7
#ifndef CUT_FRAME
	.word COPTERA8
#endif
	.word ani_jump
	.word j_copt1
	.word 0
j_copt2:
	.word COPTERB1
#ifndef CUT_FRAME
	.word COPTERB2
#endif
	.word COPTERB3
#ifndef CUT_FRAME
	.word COPTERB4
#endif
	.word COPTERB5
#ifndef CUT_FRAME
	.word COPTERB6
#endif
	.word COPTERB7
#ifndef CUT_FRAME
	.word COPTERB8
#endif
	.word ani_jump
	.word j_copt2
	.word 0
j_copt3:
	.word COPTERC1
#ifndef CUT_FRAME
	.word COPTERC2
#endif
	.word COPTERC3
#ifndef CUT_FRAME
	.word COPTERC4
#endif
	.word COPTERC5
#ifndef CUT_FRAME
	.word COPTERC6
#endif
	.word COPTERC7
#ifndef CUT_FRAME
	.word COPTERC8
#endif
	.word ani_jump
	.word j_copt3
	.word 0
	
COPTERA1:
	.word COPTERA1_SUB, 0
COPTERA1_SUB:
	.word COPTERA1_IMG
	.half 122, 55, 30, 0
COPTERA3:
	.word COPTERA3_SUB, 0
COPTERA3_SUB:
	.word COPTERA3_IMG
	.half 123, 55, 30, 2
COPTERA5:
	.word COPTERA5_SUB, 0
COPTERA5_SUB:
	.word COPTERA5_IMG
	.half 120, 55, 30, -1
COPTERA7:
	.word COPTERA7_SUB, 0
COPTERA7_SUB:
	.word COPTERA7_IMG
	.half 123, 56, 30, 2
COPTERB1:
	.word COPTERB1_SUB, 0
COPTERB1_SUB:
	.word COPTERB1_IMG
	.half 125, 76, 30, 3
COPTERB3:
	.word COPTERB3_SUB, 0
COPTERB3_SUB:
	.word COPTERB3_IMG
	.half 126, 67, 42, 4
COPTERB5:
	.word COPTERB5_SUB, 0
COPTERB5_SUB:
	.word COPTERB5_IMG
	.half 121, 75, 50, 0
COPTERB7:
	.word COPTERB7_SUB, 0
COPTERB7_SUB:
	.word COPTERB7_IMG
	.half 121, 71, 30, 0
COPTERC1:
	.word COPTERC1_SUB, 0
COPTERC1_SUB:
	.word COPTERC1_IMG
	.half 128, 94, 47, 7
COPTERC3:
	.word COPTERC3_SUB, 0
COPTERC3_SUB:
	.word COPTERC3_IMG
	.half 128, 94, 47, 7
COPTERC5:
	.word COPTERC5_SUB, 0
COPTERC5_SUB:
	.word COPTERC5_IMG
	.half 128, 94, 47, 7
COPTERC7:
	.word COPTERC7_SUB, 0
COPTERC7_SUB:
	.word COPTERC7_IMG
	.half 128, 94, 47, 7

#ifndef CUT_FRAME
COPTERA2:
	.word COPTERA2_SUB, 0
COPTERA2_SUB:
	.word COPTERA2_IMG
	.half 122, 55, 30, 1
COPTERA4:
	.word COPTERA4_SUB, 0
COPTERA4_SUB:
	.word COPTERA4_IMG
	.half 122, 55, 30, 0
COPTERA6:
	.word COPTERA6_SUB, 0
COPTERA6_SUB:
	.word COPTERA6_IMG
	.half 122, 55, 30, 0
COPTERA8:
	.word COPTERA8_SUB, 0
COPTERA8_SUB:
	.word COPTERA8_IMG
	.half 122, 55, 30, 1
COPTERB2:
	.word COPTERB2_SUB, 0
COPTERB2_SUB:
	.word COPTERB2_IMG
	.half 126, 55, 30, 4
COPTERB4:
	.word COPTERB4_SUB, 0
COPTERB4_SUB:
	.word COPTERB4_IMG
	.half 123, 73, 47, 2
COPTERB6:
	.word COPTERB6_SUB, 0
COPTERB6_SUB:
	.word COPTERB6_IMG
	.half 121, 64, 36, 0
COPTERB8:
	.word COPTERB8_SUB, 0
COPTERB8_SUB:
	.word COPTERB8_IMG
	.half 122, 74, 30, 1
COPTERC2:
	.word COPTERC2_SUB, 0
COPTERC2_SUB:
	.word COPTERC2_IMG
	.half 128, 94, 47, 7
COPTERC4:
	.word COPTERC4_SUB, 0
COPTERC4_SUB:
	.word COPTERC4_IMG
	.half 128, 94, 47, 7
COPTERC6:
	.word COPTERC6_SUB, 0
COPTERC6_SUB:
	.word COPTERC6_IMG
	.half 128, 94, 47, 7
COPTERC8:
	.word COPTERC8_SUB, 0
COPTERC8_SUB:
	.word COPTERC8_IMG
	.half 128, 94, 47, 7
#endif
#endif
	
	.align 2
#include "mkr2f2.att" 
