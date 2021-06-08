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


/* TUSK */
	.align 2
	.globl tusk_pieces
tusk_pieces:	
	.half	0x5c,0x35+19,0x128,0x35+19
	.word VKBFLESH1A,0
	.word VKBFLESH1B,0
	.word VKBFLESH1C,0
	.word VKBFLESH1D,0
	.word VKBFLESH1E,0
	.word VKBGRVEST1A,0
	.word VKBGRVEST1B,0
	.word VKBGRVEST1C,0
	.word VKBGRVEST1D,0
	.word VKBGRVEST1E,0
	.word VKBPANTS1A,VKBBLU_P
	.word VKBPANTS1B,VKBBLU_P
	.word 0
	
VKBFLESH1A:
	.word KBFLESH1A
	.word 0
VKBFLESH1B:
	.word KBFLESH1B
	.word 0
VKBFLESH1C:
	.word KBFLESH1C
	.word 0
VKBFLESH1D:
	.word KBFLESH1D
	.word 0
VKBFLESH1E:
	.word KBFLESH1E
	.word 0
VKBGRVEST1A:
	.word KBGRVEST1A
	.word 0
VKBGRVEST1B:
	.word KBGRVEST1B
	.word 0
VKBGRVEST1C:
	.word KBGRVEST1C
	.word 0
VKBGRVEST1D:
	.word KBGRVEST1D
	.word 0
VKBGRVEST1E:
	.word KBGRVEST1E
	.word 0
VKBPANTS1A:
	.word KBPANTS1A
	.word 0
VKBPANTS1B:
	.word KBPANTS1B
	.word 0
	
	
	
KBFLESH1A:
	.word 0x00000000
        .half 62, 26, 77, -64
	.word VKBSKIN_P
KBFLESH1B:
	.word 0x000003A0
        .half 15, 26, -8, -11
	.word VKBSKIN_P
KBFLESH1C:
	.word 0x00000410
	.half 13, 6, -29, -70
	.word VKBSKIN_P
KBFLESH1D:
	.word 0x00000460
	.half 83, 47, 19, -43
	.word VKBSKIN_P
KBFLESH1E:
	.word 0x00000930
	.half 51, 41, -45, -85
	.word VKBSKIN_P
KBGRVEST1A:
	.word 0x00000C84
	.half 31, 21, -68, -58
	.word VKBGRAY_P
KBGRVEST1B:
	.word 0x00000DDC
	.half 140, 44, 70, -39
	.word VKBGRAY_P
KBGRVEST1C:
	.word 0x000019B8
	.half 169, 38, 8, -10
	.word VKBGRAY_P
KBGRVEST1D:
	.word 0x000027A4
	.half 152, 18, 26, -27
	.word VKBGRAY_P
KBGRVEST1E:
	.word 0x00002E4C
	.half 122, 33, -29, -15
	.word VKBGRAY_P
KBPANTS1A:
	.word 0x000033AC
        .half 11, 19, 71, -168
	.word VKBTAN_P
KBPANTS1B:
	.word 0x00003420
        .half 27, 30, 40, -152
	.word VKBTAN_P

	.align 2
	.globl tusk_dict
tusk_dict:	
#include "tusk.dct"

