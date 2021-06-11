#include <regdef.h>
#include "mkchar.inc"

	.option	pic0
	.set	noreorder
	.data

aind_anitab1:
	.word a_ind_friend
	.word a_mkgame

a_ind_friend:
	.word ani_swpal
	.word RNBEAMUP3
	.word RNBEAMUP5
	.word RNBEAMUP7
	.word ani_swpal
	.word RNVICTORY1
	.word RNVICTORY2
	.word RNVICTORY3
	.word RNVICTORY5
	.word RNVICTORY6
	.word RNVICTORY7
	.word 0
a_mkgame:
	.word MK2GAME
	.word 0

RNBEAMUP3:
	.word RNBEAMUP3_SUB, 0
RNBEAMUP3_SUB:
	.word RNBEAMUP3_IMG
	.half 57, 50, 19, -67
	.word ELEC_P
RNBEAMUP5:
	.word RNBEAMUP5_SUB, 0
RNBEAMUP5_SUB:
	.word RNBEAMUP5_IMG
	.half 88, 52, 22, -36
RNBEAMUP7:
	.word RNBEAMUP7_SUB, 0
RNBEAMUP7_SUB:
	.word RNBEAMUP7_IMG
	.half 122, 54, 20, -2
RNVICTORY1:
	.word RNVICTORY1_SUB, 0
RNVICTORY1_SUB:
	.word RNVICTORY1_IMG
	.half 105, 86, 37, -19
	.word RADBLU_P
RNVICTORY2:
	.word RNVICTORY2_SUB, 0
RNVICTORY2_SUB:
	.word RNVICTORY2_IMG
	.half 85, 80, 41, -38
RNVICTORY3:
	.word RNVICTORY3_SUB, 0
RNVICTORY3_SUB:
	.word RNVICTORY3_IMG
	.half 72, 48, 21, -51
RNVICTORY5:
	.word RNVICTORY5_SUB, 0
RNVICTORY5_SUB:
	.word RNVICTORY5_IMG
	.half 105, 50, 22, -19
RNVICTORY6:
	.word RNVICTORY6_SUB, 0
RNVICTORY6_SUB:
	.word RNVICTORY6_IMG
	.half 123, 61, 27, 0
RNVICTORY7:
	.word RNVICTORY7_SUB, 0
RNVICTORY7_SUB:
	.word RNVICTORY7_IMG
	.half 133, 79, 38, 9
MK2GAME:
	.word MK2GAME_IMG
	.half 167, 94, 0, 0
	.word MK2GAME_P

	.align 2
#include "mkindf64.att" 
