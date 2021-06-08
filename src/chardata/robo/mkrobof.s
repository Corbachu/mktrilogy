#include <regdef.h>
#include "mkchar.inc"

	.option	pic0
	.set	noreorder
	.data

robo_anitab1:
	.word a_robo1_friend
	.word a_dinger
	.word a_robo2_friend
	.word a_smoke_friend
	
a_robo1_friend:
#ifndef CUT_FRAME
	.word RBHAMMER2
#endif
	.word RBHAMMER3
	.word RBHAMMER4
	.word RBHAMMER5
	.word RBHAMMER6
	.word 0
a_dinger:
	.word RBDINGER1
	.word RBDINGER2
#ifndef CUT_FRAME
	.word RBDINGER3
#endif
	.word RBDINGER4
#ifndef CUT_FRAME
	.word RBDINGER5
#endif
	.word RBDINGER6
#ifndef CUT_FRAME
	.word RBDINGER7
#endif
	.word RBDINGER8
	.word RBDINGER8
	.word RBDINGER8
	.word RBDINGER8
	.word 0
	.word RBDINGER13
#ifndef CUT_FRAME
	.word RBDINGER14
#endif
	.word RBDINGER15
	.word 0
a_robo2_friend:
	.word RBCHACHA1
#ifndef CUT_FRAME
	.word RBCHACHA2
#endif
	.word RBCHACHA3
#ifndef CUT_FRAME
	.word RBCHACHA4
#endif
	.word RBCHACHA5
#ifndef CUT_FRAME
	.word RBCHACHA4
#endif
	.word RBCHACHA3
#ifndef CUT_FRAME
	.word RBCHACHA2
#endif
	.word ani_jump
	.word a_robo2_friend
a_smoke_friend:
	.word ani_sladd
#ifdef CUT_FRAME
	.word HORN2
#else
	.word HORN1
#endif
	.word ani_slani_sleep
#ifdef CUT_FRAME
	.word HORN2
#else
	.word HORN1
#endif
	.word ani_slani_sleep
	.word HORN2
	.word ani_slani_sleep
	.word HORN3
	.word 0
	.word ani_slani_sleep
#ifdef CUT_FRAME
	.word HORN3
#else
	.word HORN4
#endif
	.word ani_slani_sleep
	.word HORN5
	.word ani_slani_sleep
#ifdef CUT_FRAME
	.word HORN3
#else
	.word HORN4
#endif
	.word ani_slani_sleep
	.word HORN5
	.word ani_slani_sleep
#ifdef CUT_FRAME
	.word HORN3
#else
	.word HORN4
#endif
	.word ani_slani_sleep
	.word HORN5
	.word ani_slani_sleep
#ifdef CUT_FRAME
	.word HORN3
#else
	.word HORN4
#endif
	.word ani_slani_sleep
	.word HORN5
	.word ani_slani_sleep
#ifdef CUT_FRAME
	.word HORN3
#else
	.word HORN4
#endif
	.word ani_slani_sleep
	.word HORN5
	.word ani_slani_sleep
	.word HORN3
	.word 0
	.word ani_slani_sleep
	.word HORN2
	.word ani_slani_sleep
#ifdef CUT_FRAME
	.word HORN2
#else
	.word HORN1
#endif
	.word 0
	
#ifndef CUT_FRAME
HORN1:
	.word HORN1_SUB, 0
HORN1_SUB:
	.word HORN1_IMG
	.half 21, 12, -5, -28
	.word BIGHORN_P
#endif
HORN2:
	.word HORN2_SUB, 0
HORN2_SUB:
	.word HORN2_IMG
	.half 21, 33, -5, -28
#ifdef CUT_FRAME
	.word BIGHORN_P
#endif
HORN3:
	.word HORN3_SUB, 0
HORN3_SUB:
	.word HORN3_IMG
	.half 61, 77, -5, -8
#ifndef CUT_FRAME
HORN4:
	.word HORN4_SUB, 0
HORN4_SUB:
	.word HORN4_IMG
	.half 62, 78, -5, -8
#endif
HORN5:
	.word HORN5_SUB, 0
HORN5_SUB:
	.word HORN5_IMG
	.half 62, 79, -4, -8
#ifndef CUT_FRAME
RBHAMMER2:
	.word RBHAMMER2_SUB, 0
RBHAMMER2_SUB:
	.word RBHAMMER2_IMG
	.half 114, 58, 36, -8
#endif
RBHAMMER3:
	.word RBHAMMER3_SUB, 0
RBHAMMER3_SUB:
	.word RBHAMMER3_IMG
	.half 121, 68, 42, -1
RBHAMMER4:
	.word RBHAMMER4_SUB, 0
RBHAMMER4_SUB:
	.word RBHAMMER4_IMG
	.half 141, 46, 12, 19
RBHAMMER5:
	.word RBHAMMER5_SUB, 0
RBHAMMER5_SUB:
	.word RBHAMMER5_IMG
	.half 120, 78, 13, -2
RBHAMMER6:
	.word RBHAMMER6_SUB, 0
RBHAMMER6_SUB:
	.word RBHAMMER6_IMG
	.half 82, 90, 12, -40
RBDINGER1:
	.word RBDINGER1_SUB, 0
RBDINGER1_SUB:
	.word RBDINGER1_IMG
	.half 23, 43, -57, -105
	.word RBHAMM_P
RBDINGER2:
	.word RBDINGER2_SUB, 0
RBDINGER2_SUB:
	.word RBDINGER2_IMG
	.half 27, 36, -62, -98
#ifndef CUT_FRAME
RBDINGER3:
	.word RBDINGER3_SUB, 0
RBDINGER3_SUB:
	.word RBDINGER3_IMG
	.half 55, 33, -62, -68
#endif
RBDINGER4:
	.word RBDINGER4_SUB, 0
RBDINGER4_SUB:
	.word RBDINGER4_IMG
	.half 88, 34, -62, -35
#ifndef CUT_FRAME
RBDINGER5:
	.word RBDINGER5_SUB, 0
RBDINGER5_SUB:
	.word RBDINGER5_IMG
	.half 116, 34, -62, -8
#endif
RBDINGER6:
	.word RBDINGER6_SUB, 0
RBDINGER6_SUB:
	.word RBDINGER6_IMG
	.half 155, 34, -62, 31
#ifndef CUT_FRAME
RBDINGER7:
	.word RBDINGER7_SUB, 0
RBDINGER7_SUB:
	.word RBDINGER7_IMG
	.half 159, 31, -62, 35
#endif
RBDINGER8:
	.word RBDINGER8_SUB, 0
RBDINGER8_SUB:
	.word RBDINGER8_IMG
	.half 158, 30, -62, 34
RBDINGER13:
	.word RBDINGER13_SUB, 0
RBDINGER13_SUB:
	.word RBDINGER13_IMG
	.half 158, 30, -62, 34
#ifndef CUT_FRAME
RBDINGER14:
	.word RBDINGER14_SUB, 0
RBDINGER14_SUB:
	.word RBDINGER14_IMG
	.half 159, 30, -62, 35
#endif
RBDINGER15:
	.word RBDINGER15_SUB, 0
RBDINGER15_SUB:
	.word RBDINGER15_IMG
	.half 158, 30, -62, 34
RBCHACHA1:
	.word RBCHACHA1_SUB, 0
RBCHACHA1_SUB:
	.word RBCHACHA1_IMG
	.half 88, 46, 20, -32
#ifndef CUT_FRAME
RBCHACHA2:
	.word RBCHACHA2_SUB, 0
RBCHACHA2_SUB:
	.word RBCHACHA2_IMG
	.half 89, 42, 15, -31
#endif
RBCHACHA3:
	.word RBCHACHA3_SUB, 0
RBCHACHA3_SUB:
	.word RBCHACHA3_IMG
	.half 89, 39, 14, -30
#ifndef CUT_FRAME
RBCHACHA4:
	.word RBCHACHA4_SUB, 0
RBCHACHA4_SUB:
	.word RBCHACHA4_IMG
	.half 88, 42, 16, -32
#endif
RBCHACHA5:
	.word RBCHACHA5_SUB, 0
RBCHACHA5_SUB:
	.word RBCHACHA5_IMG
	.half 86, 43, 16, -35
	

	.align 2
#include "mkrobof.att" 
