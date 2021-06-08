#include <regdef.h>
#include "mkchar.inc"

	.option	pic0
	.set	noreorder
	.data

ast_anitab1:
	.word a_snake
	
a_snake:
	.word SNAKE6
	.word 0
	.word SNAKE8
	.word SNAKE9
	.word SNAKE10
	.word SNAKE11
	.word 0
	.word SNAKE12
	.word SNAKE13
	.word SNAKE8
	.word SNAKE6
	.word 0

SNAKE6:
	.word SNAKE6_SUB, 0
SNAKE6_SUB:
	.word SNAKE6_IMG
	.half 129, 103, 45, 13
	.word SNAKE_P
SNAKE8:
	.word SNAKE8_SUB, 0
SNAKE8_SUB:
	.word SNAKE8_IMG
	.half 137, 135, 45, 20
SNAKE9:
	.word SNAKE9_SUB, 0
SNAKE9_SUB:
	.word SNAKE9_IMG
	.half 136, 165, 45, 20
SNAKE10:
	.word SNAKE10_SUB, 0
SNAKE10_SUB:
	.word SNAKE10_IMG
	.half 132, 180, 45, 15
SNAKE11:
	.word SNAKE11_SUB, 0
SNAKE11_SUB:
	.word SNAKE11_IMG
	.half 144, 180, 45, 16
SNAKE12:
	.word SNAKE12_SUB, 0
SNAKE12_SUB:
	.word SNAKE12_IMG
	.half 137, 157, 44, 20
SNAKE13:
	.word SNAKE13_SUB, 0
SNAKE13_SUB:
	.word SNAKE13_IMG
	.half 137, 135, 45, 20

	.align 2
#include "mkst.atta" 
