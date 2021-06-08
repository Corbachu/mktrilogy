#include <regdef.h>
#include "mkchar.inc"

	.option	pic0
	.set	noreorder
	.data

anj_anitab1:
	.word a_monkey
	.word a_frog
	.word a_pengo
	.word a_egg

a_monkey:
	.word MONKEY2
	.word MONKEY3
	.word MONKEY4
	.word ani_jump
	.word a_monkey

a_frog:
	.word FROG1
	.word FROG1
	.word FROG1
	.word 0
	.word FROG4
	.word FROG6
	.word FROG7
	.word 0
	.word FROG8
	.word FROG7
	.word FROG6
	.word FROG4
	.word FROG1
	.word FROG1
	.word FROG1
	.word 0
a_pengo:
	.word PENGO1
	.word PENGO2
	.word PENGO3
	.word ani_jump
	.word a_pengo
a_egg:
	.word EGG1
	.word EGG2
	.word EGG1
	.word EGG2
	.word EGG1
	.word EGG2
	.word EGG1
	.word EGG2
	.word EGG1
	.word EGG2
	.word EGG1
	.word EGG2
	.word 0

FROG1:
	.word FROG1_IMG
	.half 9, 14, -10, -36
	.word FROG_P
FROG4:
	.word FROG4_IMG
	.half 17, 14, -10, -26
FROG6:
	.word FROG6_IMG
	.half 43, 29, -10, 17
FROG7:
	.word FROG7_IMG
	.half 71, 42, -3, 49
FROG8:
	.word FROG8_IMG
	.half 109, 41, 0, 70
PENGO1:
	.word PENGO1_IMG
	.half 35, 18, 6, -2
	.word PENGO_P
PENGO2:
	.word PENGO2_IMG
	.half 35, 15, 4, -2
PENGO3:
	.word PENGO3_IMG
	.half 35, 17, 2, -2
EGG1:
	.word EGG1_IMG
	.half 13, 10, 1, -19
	.word PENGO_P
EGG2:
	.word EGG2_IMG
	.half 16, 10, 1, -16

MONKEY2:
	.word MONKEY2_IMG
	.half 59, 32, 12, 0
	.word MONKY_P
MONKEY3:
	.word MONKEY3_IMG
	.half 58, 22, 10, 0
MONKEY4:
	.word MONKEY4_IMG
	.half 59, 28, 12, 0

	.align 2
#include "mknj.atta" 
