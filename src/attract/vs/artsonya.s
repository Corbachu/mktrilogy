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

/* SONYA */
	.align 2
	.globl sonya_pieces
sonya_pieces:
	.half	0x5e,0x4f,0x12d,0x4f
	.word VBGSONYA1A,0
	.word VBGSONYA1B,0
	.word VBGSONYA1C,0
	.word VBGSONYA1D,0
	.word VBGSONYA1E,0
	.word VBGSONYA1F,0
	.word VBGSONYA2A,BGSNBLU_P
	.word VBGSONYA2B,BGSNBLU_P
	.word VBGSONYA2C,BGSNBLU_P
	.word VBGSONYA2D,BGSNBLU_P
	.word VBGSONYA3A,0
	.word VBGSONYA3B,0
	.word VBGSONYA3C,0
	.word VBGSONYA3D,0
	.word VBGSONYA3E,0
	.word VBGSONYA3F,0
	.word VBGSONYA3G,0
	.word	0
	
VBGSONYA1A:
	.word BGSONYA1A
	.word 0
VBGSONYA1B:
	.word BGSONYA1B
	.word 0
VBGSONYA1C:
	.word BGSONYA1C
	.word 0
VBGSONYA1D:
	.word BGSONYA1D
	.word 0
VBGSONYA1E:
	.word BGSONYA1E
	.word 0
VBGSONYA1F:
	.word BGSONYA1F
	.word 0
VBGSONYA2A:
	.word BGSONYA2A
	.word 0
VBGSONYA2B:
	.word BGSONYA2B
	.word 0
VBGSONYA2C:
	.word BGSONYA2C
	.word 0
VBGSONYA2D:
	.word BGSONYA2D
	.word 0
VBGSONYA3A:
	.word BGSONYA3A
	.word 0
VBGSONYA3B:
	.word BGSONYA3B
	.word 0
VBGSONYA3C:
	.word BGSONYA3C
	.word 0
VBGSONYA3D:
	.word BGSONYA3D
	.word 0
VBGSONYA3E:
	.word BGSONYA3E
	.word 0
VBGSONYA3F:
	.word BGSONYA3F
	.word 0
VBGSONYA3G:
	.word BGSONYA3G
	.word 0

BGSONYA1A:
	.word 0x00000000
	.half 104, 64, 75, -5
	.word BGSON1_P
BGSONYA1B:
	.word 0x0000059C
	.half 70, 26, 11, -2
	.word BGSON1_P
BGSONYA1C:
	.word 0x00000AE8
	.half 53, 20, -13, -9
	.word BGSON1_P
BGSONYA1D:
	.word 0x00000D34
	.half 31, 53, 37, -124
	.word BGSON1_P
BGSONYA1E:
	.word 0x0000105C
	.half 59, 34, -16, -73
	.word BGSON1_P
BGSONYA1F:
	.word 0x000012EC
        .half 39, 36, -50, -93
	.word BGSON1_P
BGSONYA2A:
	.word 0x0000147C
	.half 3, 6, 51, -78
	.word BGSON2_P
BGSONYA2B:
	.word 0x00001490
	.half 37, 30, 61, -136
	.word BGSON2_P
BGSONYA2C:
	.word 0x0000164C
	.half 64, 34, 22, -64
	.word BGSON2_P
BGSONYA2D:
	.word 0x00001894
	.half 59, 18, -11, -70
	.word BGSON2_P
BGSONYA3A:
	.word 0x00001A80
	.half 32, 7, 34, -92
	.word BGSON3_P
BGSONYA3B:
	.word 0x00001B30
	.half 70, 20, 30, -57
	.word BGSON3_P
BGSONYA3C:
	.word 0x00001DDC
        .half 36, 38, 44, -137
	.word BGSON3_P
BGSONYA3D:
	.word 0x0000200C
        .half 21, 10, 6, -152
	.word BGSON3_P
BGSONYA3E:
	.word 0x00002098
	.half 84, 16, 10, -29
	.word BGSON3_P
BGSONYA3F:
	.word 0x00002260
	.half 91, 37, -5, -24
	.word BGSON3_P
BGSONYA3G:
	.word 0x00002504
	.half 26, 15, -72, -85
	.word BGSON3_P

	.align 2
	.globl sonya_dict
sonya_dict:
#include "sonya.dct"

