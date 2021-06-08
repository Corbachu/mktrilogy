#include <regdef.h>

	.option	pic0

	.set noreorder
	.data

/*
;******************************************************************************
; File: artverse.s
;
; By: David Schwartz
;
; Date: Jan 1995
;
; (C) Williams Entertainment
;
; Mortal Kombat III Verse Art Textures
;******************************************************************************
*/

/* SWAT */
	.align 2
	.globl swat_pieces
swat_pieces:
	.half	0x63,0x25+29,0x125,0x25+29
	.word VCOPBLUE1A,VCOPRED_P
	.word VCOPBLUE1B,VCOPRED_P
	.word VCOPBLUE1C,VCOPRED_P
	.word VCOPFLESH1A,0
	.word VCOPFLESH1B,0
	.word VCOPFLESH1C,0
	.word VCOPFLESH1D,0
	.word VCOPGREY1A,0
	.word VCOPGREY1B,0
	.word VCOPGREY1C,0
	.word VCOPGREY1D,0
	.word	0
	
VCOPBLUE1A:
	.word COPBLUE1A
	.word 0
VCOPBLUE1B:
	.word COPBLUE1B
	.word 0
VCOPBLUE1C:
	.word COPBLUE1C
	.word 0
VCOPFLESH1A:
	.word COPFLESH1A
	.word 0
VCOPFLESH1B:
	.word COPFLESH1B
	.word 0
VCOPFLESH1C:
	.word COPFLESH1C
	.word 0
VCOPFLESH1D:
	.word COPFLESH1D
	.word 0
VCOPGREY1A:
	.word COPGREY1A
	.word 0
VCOPGREY1B:
	.word COPGREY1B
	.word 0
VCOPGREY1C:
	.word COPGREY1C
	.word 0
VCOPGREY1D:
	.word COPGREY1D
	.word 0
	
	
COPBLUE1A:
	.word 0x00000000
	.half 72, 96, 48, -66
	.word VCOPBLU_P
COPBLUE1B:
	.word 0x00000D3C
	.half 9, 10, 42, -150
	.word VCOPBLU_P
COPBLUE1C:
	.word 0x00000D8C
        .half 14, 20, 69, -170
	.word VCOPBLU_P
COPFLESH1A:
	.word 0x00000E5C
	.half 39, 44, -1, -31
	.word VCOPSKN_P
COPFLESH1B:
	.word 0x000012CC
	.half 35, 55, 69, -97
	.word VCOPSKN_P
COPFLESH1C:
	.word 0x00001598
	.half 16, 11, 10, -127
	.word VCOPSKN_P
COPFLESH1D:
	.word 0x000015E4
	.half 60, 40, -34, -111
	.word VCOPSKN_P
COPGREY1A:
	.word 0x00001880
        .half 33, 50, 6, -13
	.word VCOPGRY_P
COPGREY1B:
	.word 0x00001AF4
	.half 134, 77, 75, -50
	.word VCOPGRY_P
COPGREY1C:
	.word 0x00002810
	.half 31, 21, -53, -139
	.word VCOPGRY_P
COPGREY1D:
	.word 0x000028D8
	.half 133, 46, -1, -51
	.word VCOPGRY_P

	.align 2
	.globl swat_dict
swat_dict:
#include "swat.dct"

