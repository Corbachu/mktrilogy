#include <regdef.h>

	.option	pic0

	.set noreorder

/*
;******************************************************************************
; File: artbrutal.s
;
; By: David Schwartz
;
; Date: Jan 1995
;
; (C) Williams Entertainment
;
; Mortal Kombat III Fight Art Textures
;******************************************************************************
*/

	.align 2
/*
;******************************************************************************
;	Spinning Fight Intro Graphics (fight.adt)
;******************************************************************************
*/
	.extern	BRUTAL_P
	
	.globl a_brutality
a_brutality:
	.word BRU_B
	.word BRU_R
	.word BRU_U
	.word BRU_T
	.word BRU_A
	.word BRU_L
	.word BRU_I
	.word BRU_T2
	.word BRU_Y
BRU_B:
	.word BRU_B_IMG
	.half 41, 27, 0, 0
	.word BRUTAL_P
BRU_R:
	.word BRU_R_IMG
	.half 41, 26, 28, 0
	.word BRUTAL_P
BRU_U:
	.word BRU_U_IMG
	.half 41, 26, 55, 0
	.word BRUTAL_P
BRU_T:
	.word BRU_T_IMG
	.half 41, 23, 82, 0
	.word BRUTAL_P
BRU_A:
	.word BRU_A_IMG
	.half 41, 28, 105, 0
	.word BRUTAL_P
BRU_L:
	.word BRU_L_IMG
	.half 41, 22, 134, 0
	.word BRUTAL_P
BRU_I:
	.word BRU_I_IMG
	.half 41, 14, 157, 0
	.word BRUTAL_P
BRU_T2:
	.word BRU_T2_IMG
	.half 41, 23, 172, 0
	.word BRUTAL_P
BRU_Y:
	.word BRU_Y_IMG
	.half 41, 26, 196, 0
	.word BRUTAL_P

	.align 2
#include "brutalit.att"

	.align 2
	.globl brutal_dict	
brutal_dict:
#include "brutalit.dct"

