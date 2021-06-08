#include <regdef.h>

	.option	pic0

	.set noreorder
	.data

/*
;******************************************************************************
; File: artanim.s
;
; By: David Schwartz
;
; Date: Jan 1995
;
; (C) Williams Entertainment
;
; Mortal Kombat III Animality Art Textures
;******************************************************************************
*/
	.align 2
	.globl a_animality
a_animality:
	.word ANIMALITY01
	.word ANIMALITY02
	.word ANIMALITY03
	.word ANIMALITY04
	.word ANIMALITY05
	.word ANIMALITY06
	.word ANIMALITY07
	.word ANIMALITY08
	.word ANIMALITY09
	.word ANIMALITY10
	.word ANIMALITY11
	.word ANIMALITY12
	.word 0
	.globl ANIMALITY01
ANIMALITY01:
	.word ANIMALITY01_IMG
	.half 31, 48, -1, -3
	.word ANIMAL_P
ANIMALITY02:
	.word ANIMALITY02_IMG
	.half 34, 85, -1, 0
ANIMALITY03:
	.word ANIMALITY03_IMG
	.half 34, 130, -1, 0
ANIMALITY04:
	.word ANIMALITY04_IMG
	.half 34, 168, -1, 0
ANIMALITY05:
	.word ANIMALITY05_IMG
	.half 35, 199, -1, 0
ANIMALITY06:
	.word ANIMALITY06_IMG
	.half 35, 200, -1, 0
ANIMALITY07:
	.word ANIMALITY07_IMG
	.half 35, 200, -1, 0
ANIMALITY08:
	.word ANIMALITY08_IMG
	.half 35, 200, -1, 0
ANIMALITY09:
	.word ANIMALITY09_IMG
	.half 35, 200, -1, 0
ANIMALITY10:
	.word ANIMALITY10_IMG
	.half 35, 201, 0, 0
ANIMALITY11:
	.word ANIMALITY11_IMG
	.half 35, 201, 0, 0
ANIMALITY12:
	.word ANIMALITY12_IMG
	.half 35, 202, 1, 0
	
	.align 2
#include "animal.att"

	.align 2
	.globl animal_dict
animal_dict:
#include "animal.dct"
