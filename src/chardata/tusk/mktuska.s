#include <regdef.h>
#include "mkchar.inc"

	.option	pic0
	.set	noreorder
	.data

atusk_anitab1:
	.word a_skeleton
	
a_skeleton:
	.word SKELETN5
	.word 0
	.word SKELETN9
	.word SKELETN10
	.word SKELETN11
	.word ani_nosleep
	.word SKELETN12
	.word 0
	.word SKELETN13
	.word SKELETN14
	.word SKELETN5
	.word 0
	
SKELETN5:
	.word SKELETN5_SUB, 0
SKELETN5_SUB:
	.word SKELETN5_IMG
	.half 98, 142, 41, -26
	.word HORSE_P
SKELETN9:
	.word SKELETN9_SUB, 0
SKELETN9_SUB:
	.word SKELETN9_IMG
	.half 84, 143, 47, -41
SKELETN10:
	.word SKELETN10_SUB, 0
SKELETN10_SUB:
	.word SKELETN10_IMG
	.half 118, 135, 51, -6
SKELETN11:
	.word SKELETN11_SUB, 0
SKELETN11_SUB:
	.word SKELETN11_IMG
	.half 150, 129, 54, 26
SKELETN12:
	.word SKELETN12_SUB, 0
SKELETN12_SUB:
	.word SKELETN12_IMG
	.half 150, 113, 54, 26
SKELETN13:
	.word SKELETN13_SUB, 0
SKELETN13_SUB:
	.word SKELETN13_IMG
	.half 120, 135, 52, -4
SKELETN14:
	.word SKELETN14_SUB, 0
SKELETN14_SUB:
	.word SKELETN14_IMG
	.half 92, 142, 46, -34
	
	.align 2
#include "mktusk.atta" 
