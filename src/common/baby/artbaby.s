#include <regdef.h>

	.option	pic0

	.set noreorder

/*
;******************************************************************************
; File: artbaby.s
;
; By: David Schwartz
;
; Date: Jan 1995
;
; (C) Williams Entertainment
;
; Mortal Kombat III babyality Art Textures
;******************************************************************************
*/

	.align 2
	.globl a_baby_text
a_baby_text:
	.word BABALITY1
	.word BABALITY2
	.word BABALITY3
	.word BABALITY4
	.word BABALITY5
	.word BABALITY6
	.word BABALITY7
	.word BABALITY8
	.word 0
BABALITY1:
	.word BABALITY1_IMG
	.half 29, 33, 0, 0
	.word	BABYB_P
BABALITY2:
	.word BABALITY2_IMG
	.half 29, 31, 0, 0
	.word	BABYA_P
BABALITY3:
	.word BABALITY3_IMG
	.half 29, 29, 0, 0
	.word	BABYB_P
BABALITY4:
	.word BABALITY4_IMG
	.half 29, 27, 0, 0
	.word	BABYA_P
BABALITY5:		
	.word BABALITY5_IMG
	.half 29, 28, 0, 0
	.word	BABYL_P
BABALITY6:
	.word BABALITY6_IMG
	.half 30, 30, 0, 0
	.word	BABYI_P
BABALITY7:
	.word BABALITY7_IMG
	.half 29, 32, 0, 0
	.word	BABYT_P
BABALITY8:
	.word BABALITY8_IMG
	.half 29, 34, 0, 0
	.word	BABYY_P
	
	.align 2
#include "baby.att"

	.align 2
	.globl baby_dict
baby_dict:
#include "baby.dct"
