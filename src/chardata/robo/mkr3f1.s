#include <regdef.h>
#include "mkchar.inc"

	.option	pic0
	.set	noreorder
	.data

robo_anitab1:
	.word a_earth
	
a_earth:
	.word EARTH1
	.word ani_swpal
	.word EARTH2
	.word 0
	
EARTH1:
	.word EARTH1_SUB, 0
EARTH1_SUB:
	.word EARTH1_IMG
	.half 46, 47, 23, 23
	.word EARTH01P
EARTH2:
	.word EARTH2_SUB, 0
EARTH2_SUB:
	.word EARTH2_IMG
	.half 133, 138, 70, 69
	.word EARTH02P
		
	.align 2
#include "mkr3f1.att" 
