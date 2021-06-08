#include <regdef.h>
#include "mkchar.inc"

	.option	pic0
	.set	noreorder
	.data

robo_anitab1:
	.word a_arm_bomb
	.word a_smbomb
	
a_arm_bomb:
	.word RBSHOLDER1
	.word ani_sladd
	.word ARM1
	.word ani_slani_sleep
	.word ARM1
	.word ani_slani_sleep
	.word ARM2
	.word ani_slani_sleep
	.word ARM3
	.word ani_slani_sleep
	.word ARM4
#ifndef CUT_FRAME
	.word ani_slani_sleep
	.word ARM5
#endif
	.word ani_slani_sleep
	.word ARM6
	.word 0
#ifndef CUT_FRAME
	.word ani_slani_sleep
	.word ARM7
#endif
	.word ani_slani_sleep
	.word ARM8
	.word ani_slani_sleep
	.word ARM9
	.word ani_slani_sleep
	.word ARM10
	.word ani_slani_sleep
	.word ARM11
	.word 0
	
a_smbomb:
	.word SMBOMB1A
	.word 0
	
RBSHOLDER1:
	.word RBSHOLDER1_SUB, 0
RBSHOLDER1_SUB:
	.word RBSHOLDER1_COPY_IMG
	.half 114, 54, 23, -6
	.word RBARM_P
	
ARM1:
	.word ARM1_SUB, 0
ARM1_SUB:
	.word ARM1_IMG
	.half 29, 28, 6, 0
	.word RBARM_P
ARM2:
	.word ARM2_SUB, 0
ARM2_SUB:
	.word ARM2_IMG
	.half 40, 57, 6, 10
ARM3:
	.word ARM3_SUB, 0
ARM3_SUB:
	.word ARM3_IMG
	.half 57, 94, 6, 27
ARM4:
	.word ARM4_SUB, 0
ARM4_SUB:
	.word ARM4_IMG
	.half 60, 118, 6, 30
#ifndef CUT_FRAME
ARM5:
	.word ARM5_SUB, 0
ARM5_SUB:
	.word ARM5_IMG
	.half 62, 118, 6, 32
#endif
ARM6:
	.word ARM6_SUB, 0
ARM6_SUB:
	.word ARM6_IMG
	.half 65, 118, 6, 36
#ifndef CUT_FRAME
ARM7:
	.word ARM7_SUB, 0
ARM7_SUB:
	.word ARM7_IMG
	.half 52, 108, 6, 22
#endif
ARM8:
	.word ARM8_SUB, 0
ARM8_SUB:
	.word ARM8_IMG
	.half 46, 114, 6, 16
ARM9:
	.word ARM9_SUB, 0
ARM9_SUB:
	.word ARM9_IMG
	.half 45, 90, 6, 15
ARM10:
	.word ARM10_SUB, 0
ARM10_SUB:
	.word ARM10_IMG
	.half 27, 53, 6, -2
ARM11:
	.word ARM11_SUB, 0
ARM11_SUB:
	.word ARM11_IMG
	.half 15, 24, 6, -13
	
SMBOMB1A:
	.word SMBOMB1A_IMG
	.half 27, 15, -99, -4
	.word RBARM_P

	.align 2
#include "mkr3f2.att" 
