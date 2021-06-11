#include <regdef.h>

	.option	pic0

	.set noreorder

/*
;******************************************************************************
; File: artfight.s
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
	.extern	MKFIGHT_P
	
	.globl a_fight_out
a_fight_out:
	.word FINFITE1
	.word FINFITE3
	.word FINFITE5
	.word FINFITE7
	.word FINFITE9
	.word FINFITE11
	.word FINFITE13
	.word FINFITE15
	.word FINFITE17
	.word 0
	.globl FINFITE1
FINFITE1:
	.word FINFITE1_IMG
	.half 39, 136, 0, -32
	.word MKFIGHT_P
FINFITE3:
	.word FINFITE3_IMG
	.half 83, 122, -6, -8
FINFITE5:
	.word FINFITE5_IMG
	.half 100, 87, -24, 0
FINFITE7:
	.word FINFITE7_IMG
	.half 94, 54, -41, -2
FINFITE9:
	.word FINFITE9_IMG
	.half 77, 54, -41, -11
FINFITE11:
	.word FINFITE11_IMG
	.half 54, 49, -43, -22
FINFITE13:
	.word FINFITE13_IMG
	.half 29, 38, -49, -35
FINFITE15:
	.word FINFITE15_IMG
	.half 19, 22, -57, -40
FINFITE17:
	.word FINFITE17_IMG
	.half 5, 5, -66, -46

	.align 2
#include "fight.att"

	.align 2
	.globl fight_dict	
fight_dict:
#include "fight.dct"

