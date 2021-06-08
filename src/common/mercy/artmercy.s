#include <regdef.h>

	.option	pic0

	.set noreorder
	.data

/*
;******************************************************************************
; File: artmercy.s
;
; By: David Schwartz
;
; Date: Jan 1995
;
; (C) Williams Entertainment
;
; Mortal Kombat III Mercy Art Textures
;******************************************************************************
*/

/*
;******************************************************************************
;	Mercy Graphics (mercy.adt)
;******************************************************************************
*/
	.align 2
	.globl a_mercy
a_mercy:
	.word MERCY_01
	.word MERCY_02
	.word MERCY_03
	.word MERCY_04
	.word MERCY_05
	.word MERCY_06
	.word MERCY_07
	.word MERCY_08
	.word MERCY_09
	.word 0
	.word MERCY_10
	.word MERCY_11
	.word MERCY_12
	.word MERCY_11
	.word MERCY_10
	.word MERCY_11
	.word MERCY_12
	.word MERCY_11
	.word MERCY_10
	.word 0
	.word MERCY_13
	.word 0
	.globl MERCY_01
MERCY_01:
	.word MERCY_01_IMG
	.half 45, 68, 34, 0
	.word	MERCY_P
MERCY_02:
	.word MERCY_02_IMG
	.half 80, 75, 38, 0
MERCY_03:
	.word MERCY_03_IMG
	.half 90, 78, 40, 0
MERCY_04:
	.word MERCY_04_IMG
	.half 102, 82, 42, 0
MERCY_05:
	.word MERCY_05_IMG
	.half 94, 86, 44, -19
MERCY_06:
	.word MERCY_06_IMG
	.half 78, 93, 47, -40
MERCY_07:
	.word MERCY_07_IMG
	.half 64, 101, 51, -59
MERCY_08:
	.word MERCY_08_IMG
	.half 48, 110, 56, -79
MERCY_09:
	.word MERCY_09_IMG
	.half 39, 118, 60, -91
MERCY_10:
	.word MERCY_10_IMG
	.half 61, 126, 64, -83
	.word	MRFLASH_P
MERCY_11:
	.word MERCY_11_IMG
	.half 165, 182, 89, -31
	.word	MRFLASH_P
MERCY_12:
	.word MERCY_12_IMG
	.half 116, 129, 64, -55
	.word	MRFLASH_P
MERCY_13:
	.word MERCY_13_IMG
	.half 34, 126, 64, -98
	.word	MERCY_P
	
	.align 2
#include "mercy.att"

	
	.align 2
	.globl mercy_dict
mercy_dict:	
#include "mercy.dct"

