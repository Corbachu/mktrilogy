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

/* SHANG */
	.align 2
	.globl shang_pieces
shang_pieces:
	.half	0x58,0x35+30,0x135,0x35+30
	.word VTSFLESH1A,0
	.word VTSFLESH1B,0
	.word VTSFLESH1C,0
	.word VTSFLESH1D,0
	.word VTSFLESH1E,0
	.word VTSGREY1A,0
	.word VTSGREY1B,0
	.word VTSGREY1C,0
	.word VTSGREY1D,0
	.word VTSGREY1E,0
	.word VTSPANT1A,VTSRED_P
	.word VTSPANT1B,VTSRED_P
	.word	0
VTSFLESH1A:
	.word TSFLESH1A
	.word 0
VTSFLESH1B:
	.word TSFLESH1B
	.word 0
VTSFLESH1C:
	.word TSFLESH1C
	.word 0
VTSFLESH1D:
	.word TSFLESH1D
	.word 0
VTSFLESH1E:
	.word TSFLESH1E
	.word 0
VTSGREY1A:
	.word TSGREY1A
	.word 0
VTSGREY1B:
	.word TSGREY1B
	.word 0
VTSGREY1C:
	.word TSGREY1C
	.word 0
VTSGREY1D:
	.word TSGREY1D
	.word 0
VTSGREY1E:
	.word TSGREY1E
	.word 0
VTSPANT1A:
	.word TSPANT1A
	.word 0
VTSPANT1B:
	.word TSPANT1B
	.word 0
	
	
TSFLESH1A:
	.word 0x00000000
        .half 49, 18, 12, -93
	.word VTSKIN_P
TSFLESH1B:
	.word 0x00000180
	.half 142, 63, 64, -7
	.word VTSKIN_P
TSFLESH1C:
	.word 0x00000CB8
	.half 14, 6, -4, -94
	.word VTSKIN_P
TSFLESH1D:
	.word 0x00000D08
	.half 105, 31, -3, -47
	.word VTSKIN_P
TSFLESH1E:
	.word 0x0000137C
	.half 119, 59, -34, -51
	.word VTSKIN_P
TSGREY1A:
	.word 0x00001BC0
	.half 18, 18, 44, -5
	.word VTSGRY_P
TSGREY1B:
	.word 0x00001C70
	.half 24, 18, -60, -124
	.word VTSGRY_P
TSGREY1C:
	.word 0x00001D24
        .half 147, 60, 44, -22
	.word VTSGRY_P
TSGREY1D:
	.word 0x0000276C
        .half 105, 42, -15, -16
	.word VTSGRY_P
TSGREY1E:
	.word 0x00002D58
	.half 19, 10, -16, -149
	.word VTSGRY_P
TSPANT1A:
	.word 0x00002DC0
        .half 15, 18, 40, -154
	.word VTSYEL_P
TSPANT1B:
	.word 0x00002E40
        .half 13, 17, -12, -156
	.word VTSYEL_P
	
	.align 2
	.globl shang_dict
shang_dict:
#include "shang.dct"

