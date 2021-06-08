#include <regdef.h>
#include "mkchar.inc"

	.option	pic0
	.set	noreorder
	.data

alia_anitab1:
	.word a_wasp

a_wasp:
	.word WASP6
	.word 0
j_wasp:
	.word WASP7
	.word WASP9
	.word ani_jump
	.word j_wasp
	.word 0
j_wasp2:
	.word WASP9
	.word WASP10
	.word WASP11
	.word ani_calla
	.word rsnd_stab
	.word WASP10
	.word ani_jump
	.word j_wasp2

WASP6:
	.word WASP6_SUB, 0
WASP6_SUB:
	.word WASP6_IMG
	.half 105, 116, 42, -12
	.word WASP_P
WASP7:
	.word WASP7_SUB, 0
WASP7_SUB:
	.word WASP7_IMG
	.half 131, 116, 42, 13
WASP9:
	.word WASP9_SUB, 0
WASP9_SUB:
	.word WASP9_IMG
	.half 135, 109, 35, 13
WASP10:
	.word WASP10_SUB, 0
WASP10_SUB:
	.word WASP10_IMG
	.half 122, 111, 43, -6
WASP11:
	.word WASP11_SUB, 0
WASP11_SUB:
	.word WASP11_IMG
	.half 131, 107, 39, 8

	.align 2
#include "mklia.atta" 
