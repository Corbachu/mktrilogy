#include <regdef.h>
#include "mkchar.inc"

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
 	.extern NUSTORM_P		

/*
;******************************************************************************
;	Various Storm Graphics (storm.adt)
;******************************************************************************
*/
	.globl STORM03
	.globl STORM05
	.globl STORM07
	.globl STORM09
	.globl STORM11

	.align 2
	.globl a_storm
a_storm:
	.word STORM01
	.word STORM03
	.word STORM05
	.word STORM07
	.word STORM09
	.word STORM11
	.word ani_jump
	.word a_storm
	.globl STORM01
STORM01:
	.word STORM01_IMG
	.half 52, 165, -15, -9
	.word NUSTORM_P
STORM03:
	.word STORM03_IMG
	.half 61, 151, -15, -4
	.word NUSTORM_P
STORM05:
	.word STORM05_IMG
	.half 54, 173, -9, -9
	.word NUSTORM_P
STORM07:
	.word STORM07_IMG
	.half 51, 162, -6, -8
	.word NUSTORM_P
STORM09:
	.word STORM09_IMG
	.half 65, 155, -20, 0
	.word NUSTORM_P
STORM11:
	.word STORM11_IMG
	.half 55, 177, -14, -5
	.word NUSTORM_P

	.align 2
	.globl storm_dict
storm_dict:
#include "../common/storm/storm.dct"

	.align 2
#include "../common/storm/storm.att"

