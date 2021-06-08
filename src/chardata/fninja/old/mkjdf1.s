#include <regdef.h>
#include "mkchar.inc"

	.option	pic0
	.set	noreorder
	.data
 
fn_anitab1:
	.word a_rod_shaker

a_rod_shaker:
	.word JDSTAFFSHAKE1
	.word JDSTAFFSHAKE2
	.word JDSTAFFSHAKE3
	.word JDSTAFFSHAKE4
	.word 0
j_shake:
	.word JDSTAFFSHAKE5
	.word ani_calla
	.word rsnd_whoosh
	.word JDSTAFFSHAKE6
	.word JDSTAFFSHAKE7
	.word JDSTAFFSHAKE6
	.word ani_jump
	.word j_shake
	.word 0
	.word ani_calla
	.word use_shakbod_pal
j_bod:
	.word SHAKBOD1
	.word SHAKBOD6
	.word SHAKBOD4
	.word SHAKBOD6
	.word ani_jump
	.word j_bod

JDSTAFFSHAKE1:
	.word JDSTAFFSHAKE1_SUB, 0
JDSTAFFSHAKE1_SUB:
	.word JDSTAFFSHAKE1_IMG
	.half 109, 93, 43, -4
JDSTAFFSHAKE2:
	.word JDSTAFFSHAKE2_SUB, 0
JDSTAFFSHAKE2_SUB:
	.word JDSTAFFSHAKE2_IMG
	.half 110, 79, 58, -4
JDSTAFFSHAKE3:
	.word JDSTAFFSHAKE3_SUB, 0
JDSTAFFSHAKE3_SUB:
	.word JDSTAFFSHAKE3_IMG
	.half 125, 78, 60, 10
JDSTAFFSHAKE4:
	.word JDSTAFFSHAKE4_SUB, 0
JDSTAFFSHAKE4_SUB:
	.word JDSTAFFSHAKE4_IMG
	.half 110, 94, 29, -4
JDSTAFFSHAKE5:
	.word JDSTAFFSHAKE5_SUB, 0
JDSTAFFSHAKE5_SUB:
	.word JDSTAFFSHAKE5_IMG
	.half 108, 118, 20, -6
JDSTAFFSHAKE6:
	.word JDSTAFFSHAKE6_SUB, 0
JDSTAFFSHAKE6_SUB:
	.word JDSTAFFSHAKE6_IMG
	.half 109, 125, 19, -5
JDSTAFFSHAKE7:
	.word JDSTAFFSHAKE7_SUB, 0
JDSTAFFSHAKE7_SUB:
	.word JDSTAFFSHAKE7_IMG
	.half 109, 116, 19, -5
SHAKBOD1:
	.word SHAKBOD1_SUB, 0
SHAKBOD1_SUB:
	.word SHAKBOD1_IMG 
	.half 105, 70, -68, 11
SHAKBOD6:
	.word SHAKBOD6_SUB, 0
SHAKBOD6_SUB:
	.word SHAKBOD6_IMG 
	.half 124, 65, -60, 1
SHAKBOD4:
	.word SHAKBOD4_SUB, 0
SHAKBOD4_SUB:
	.word SHAKBOD4_IMG 
	.half 88, 94, -16, -44

	.align 2
#include "mkjdf1.att" 
