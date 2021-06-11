#include <regdef.h>
#include "mkchar.inc"

	.option	pic0
	.set	noreorder
	.data
asz_anitab1:
	.word a_sz_polar
	
a_sz_polar:
	.word POLAR1
	.word POLAR3
	.word POLAR4
	.word POLAR5
	.word POLAR6
	.word 0
	.word POLAR8
	.word POLAR10
	.word POLAR11
	.word 0
	.word POLAR12
	.word ani_adjustxy
	.half 0
	.half 8
	.word POLAR13
	.word ani_adjustxy
	.half 0
	.half 8
j_polar:
	.word POLAR15
	.word POLAR16
	.word POLAR17
	.word ani_jump
	.word j_polar
	
POLAR1:
	.word POLAR1_SUB, 0
POLAR1_SUB:
	.word POLAR1_IMG
	.half 109, 45, 14, -6
	.word POLAR_P
POLAR3:
	.word POLAR3_SUB, 0
POLAR3_SUB:
	.word POLAR3_IMG
	.half 105, 53, 22, -13
POLAR4:
	.word POLAR4_SUB, 0
POLAR4_SUB:
	.word POLAR4_IMG
	.half 94, 59, 29, -25
POLAR5:
	.word POLAR5_SUB, 0
POLAR5_SUB:
	.word POLAR5_IMG
	.half 82, 78, 37, -36
POLAR6:
	.word POLAR6_SUB, 0
POLAR6_SUB:
	.word POLAR6_IMG
	.half 69, 100, 45, -50
POLAR8:
	.word POLAR8_SUB, 0
POLAR8_SUB:
	.word POLAR8_IMG
	.half 112, 71, 40, -7
POLAR10:
	.word POLAR10_SUB, 0
POLAR10_SUB:
	.word POLAR10_IMG
	.half 131, 63, 37, 11
POLAR11:
	.word POLAR11_SUB, 0
POLAR11_SUB:
	.word POLAR11_IMG
	.half 132, 60, 31, 11
POLAR12:
	.word POLAR12_SUB, 0
POLAR12_SUB:
	.word POLAR12_IMG
	.half 133, 68, 30, 14
POLAR13:
	.word POLAR13_SUB, 0
POLAR13_SUB:
	.word POLAR13_IMG
	.half 134, 86, 41, 15
POLAR15:
	.word POLAR15_SUB, 0
POLAR15_SUB:
	.word POLAR15_IMG
	.half 98, 82, 43, -20
POLAR16:
	.word POLAR16_SUB, 0
POLAR16_SUB:
	.word POLAR16_IMG
	.half 83, 85, 51, -36
POLAR17:
	.word POLAR17_SUB, 0
POLAR17_SUB:
	.word POLAR17_IMG
	.half 80, 90, 54, -40
	
	.align 2
#include "mksz.atta" 
