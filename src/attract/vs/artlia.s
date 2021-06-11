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

/* LIA */
	.align 2
	.globl lia_pieces
lia_pieces:
	.half	0x5d,0x35+26,0x12a,0x35+26
	.word VLIAFLESH1A,0
	.word VLIAFLESH1B,0
	.word VLIAFLESH1C,0
	.word VLIAFLESH1D,0
	.word VLIAFLESH1E,0
	.word VLIAGREY1A,0
	.word VLIAGREY1B,0
	.word VLIAGREY1C,0
	.word VLIAPURP1A,VLIABLU_P
	.word VLIAPURP1B,VLIABLU_P
	.word 0
VLIAFLESH1A:
	.word LIAFLESH1A
	.word 0
VLIAFLESH1B:
	.word LIAFLESH1B
	.word 0
VLIAFLESH1C:
	.word LIAFLESH1C
	.word 0
VLIAFLESH1D:
	.word LIAFLESH1D
	.word 0
VLIAFLESH1E:
	.word LIAFLESH1E
	.word 0
VLIAGREY1A:
	.word LIAGREY1A
	.word 0
VLIAGREY1B:
	.word LIAGREY1B
	.word 0
VLIAGREY1C:
	.word LIAGREY1C
	.word 0
VLIAPURP1A:
	.word LIAPURP1A
	.word 0
VLIAPURP1B:
	.word LIAPURP1B
	.word 0
	
	
LIAFLESH1A:
	.word 0x00000000
	.half 53, 33, 67, -79
	.word VLIASKN_P
LIAFLESH1B:
	.word 0x00000278
	.half 72, 25, 34, -61
	.word VLIASKN_P
LIAFLESH1C:
	.word 0x00000528
	.half 26, 26, -60, -55
	.word VLIASKN_P
LIAFLESH1D:
	.word 0x00000668
	.half 51, 35, -27, -81
	.word VLIASKN_P
LIAFLESH1E:
	.word 0x00000944
	.half 115, 35, 10, -36
	.word VLIASKN_P
LIAGREY1A:
	.word 0x00000F98
        .half 166, 66, 59, -7
	.word VLIAGRY_P
LIAGREY1B:
	.word 0x00001C2C
        .half 39, 25, -49, -74
	.word VLIAGRY_P
LIAGREY1C:
	.word 0x00001D88
        .half 166, 26, -6, -7
	.word VLIAGRY_P
LIAPURP1A:
	.word 0x00002380
	.half 42, 15, 38, -95
	.word VLIAPRP_P
LIAPURP1B:
	.word 0x00002474
        .half 77, 33, 8, -96
	.word VLIAPRP_P

	.align 2
	.globl lia_dict
lia_dict:
#include "lia.dct"

