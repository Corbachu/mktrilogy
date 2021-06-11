#include <regdef.h>

	.option	pic0

	.set noreorder

/*
;******************************************************************************
; File: artfinhim.s
;
; By: David Schwartz
;
; Date: Jan 1995
;
; (C) Williams Entertainment
;
; Mortal Kombat III finhimality Art Textures
;******************************************************************************
*/

/*
;******************************************************************************
;	Spinning Finish Him Graphics  (finhim.adt)
;******************************************************************************
*/
	.align 2
	.globl a_finhim_out
a_finhim_out:
	.word FINHIM1
	.word FINHIM3
	.word FINHIM5
	.word FINHIM7
	.word FINHIM9
	.word FINHIM11
	.word FINHIM13
	.word FINHIM15
	.word FINHIM17
	.word 0
	.globl FINHIM1
FINHIM1:
	.word FINHIM1_IMG
	.half 35, 222, 0, -61
	.word MKFIGHT_P
FINHIM3:
	.word FINHIM3_IMG
	.half 121, 188, -16, -16
FINHIM5:
	.word FINHIM5_IMG
	.half 154, 125, -47, 0
FINHIM7:
	.word FINHIM7_IMG
	.half 152, 81, -70, 0
FINHIM9:
	.word FINHIM9_IMG
	.half 125, 84, -68, -14
FINHIM11:
	.word FINHIM11_IMG
	.half 81, 76, -72, -35
FINHIM13:
	.word FINHIM13_IMG
	.half 46, 60, -80, -54
FINHIM15:
	.word FINHIM15_IMG
	.half 30, 35, -93, -61
FINHIM17:
	.word FINHIM17_IMG
	.half 7, 6, -107, -73

	.align 2
#include "finhim.att"

	.align 2
	.globl finhim_dict
finhim_dict:
#include "finhim.dct"