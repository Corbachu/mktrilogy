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

/* JAX */
	.align 2
	.globl jax_pieces
jax_pieces:
	.half	0x63,0x20+35,0x125,0x20+35
	.word VJXFLESH1A,0
	.word VJXPURP1A,VJXGRN_P
	.word VJXPURP1B,VJXGRN_P
	.word VJXGRY1A,0
	.word VJXGRY1B,0
	.word VJXGRY1C,0
	.word	0
	
VJXFLESH1A:
	.word JXFLESH1A
	.word 0
VJXPURP1A:
	.word JXPURP1A
	.word 0
VJXPURP1B:
	.word JXPURP1B
	.word 0
VJXGRY1A:
	.word JXGRY1A
	.word 0
VJXGRY1B:
	.word JXGRY1B
	.word 0
VJXGRY1C:
	.word JXGRY1C
	.word 0
	
	
JXFLESH1A:
	.word 0x00000000
	.half 158, 88, 44, -13
	.word	VJXFLSH_P
JXPURP1A:
	.word 0x000018CC
        .half 20, 28, 56, -168
	.word VJXPURP_P
JXPURP1B:
	.word 0x000019B8
        .half 10, 7, -16, -177
	.word VJXPURP_P
JXGRY1A:
	.word 0x000019E0
	.half 96, 77, 84, -50
	.word	VJXGRY_P
JXGRY1B:
	.word 0x0000246C
        .half 35, 72, 49, -152
	.word	VJXGRY_P
JXGRY1C:
	.word 0x000027D4
	.half 106, 34, -32, -77
	.word	VJXGRY_P
	
	.align 2
	.globl jax_dict
jax_dict:
#include "jax.dct"

