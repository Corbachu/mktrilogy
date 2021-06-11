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

/* ROBO */
	.align 2
	.globl robo1_pieces
robo1_pieces:
	.half	0x55,0x35+0x1e,0x130,0x35+0x1e
	.word VRB2GREY1A,0
	.word VRB2GREY1B,0
	.word VRB2GREY1C,0
	.word VRB2GREY1D,0
	.word VRB2GREY1E,0
	.word VRB2GREY1F,0
	.word VRB2RED1A,VRBDRED_P
	.word VRB2RED1B,VRBDRED_P
	.word VRB2RED1C,VRBDRED_P
	.word VRB2RED1D,VRBDRED_P
	.word VRB2RED1E,VRBDRED_P
	.word VRB2RED1F,VRBDRED_P
	.word VRB2RED1G,VRBDRED_P
	.word 0

	.globl robo2_pieces
robo2_pieces:
	.half	0x5c,0x35+0x1f,0x128,0x35+0x1f
	.word VRB1GOLD1A,VRBDYEL_P
	.word VRB1GOLD1B,VRBDYEL_P
	.word VRB1GOLD1C,VRBDYEL_P
	.word VRB1GOLD1D,VRBDYEL_P
	.word VRB1GOLD1E,VRBDYEL_P
	.word VRB1GREY1A,0
	.word VRB1GREY1B,0
	.word VRB1GREY1C,0
	.word VRB1GREY1D,0
	.word VRB1GREY1E,0
	.word VRB1GREY1F,0
	.word VRB1GREY1G,0
	.word 0
	
	.globl smoke_pieces
smoke_pieces:
	.half	0x5c,0x35+0x1f,0x128,0x35+0x1f
	.word VSM1GOLD1A,VSMOK2_P
	.word VSM1GOLD1B,VSMOK2_P
	.word VSM1GOLD1C,VSMOK2_P
	.word VSM1GOLD1D,VSMOK2_P
	.word VSM1GOLD1E,VSMOK2_P
	.word VRB1GREY1A,0
	.word VRB1GREY1B,0
	.word VRB1GREY1C,0
	.word VRB1GREY1D,0
	.word VRB1GREY1E,0
	.word VRB1GREY1F,0
	.word VRB1GREY1G,0
	.word 0
	
VRB1GOLD1A:
	.word RB1GOLD1A
	.word 0
VRB1GOLD1B:
	.word RB1GOLD1B
	.word 0
VRB1GOLD1C:
	.word RB1GOLD1C
	.word 0
VRB1GOLD1D:
	.word RB1GOLD1D
	.word 0
VRB1GOLD1E:
	.word RB1GOLD1E
	.word 0
VSM1GOLD1A:
	.word SM1GOLD1A
	.word 0
VSM1GOLD1B:
	.word SM1GOLD1B
	.word 0
VSM1GOLD1C:
	.word SM1GOLD1C
	.word 0
VSM1GOLD1D:
	.word SM1GOLD1D
	.word 0
VSM1GOLD1E:
	.word SM1GOLD1E
	.word 0
	
VRB1GREY1A:
	.word RB1GREY1A
	.word 0
VRB1GREY1B:
	.word RB1GREY1B
	.word 0
VRB1GREY1C:
	.word RB1GREY1C
	.word 0
VRB1GREY1D:
	.word RB1GREY1D
	.word 0
VRB1GREY1E:
	.word RB1GREY1E
	.word 0
VRB1GREY1F:
	.word RB1GREY1F
	.word 0
VRB1GREY1G:
	.word RB1GREY1G
	.word 0
VRB2GREY1A:
	.word RB2GREY1A
	.word 0
VRB2GREY1B:
	.word RB2GREY1B
	.word 0
VRB2GREY1C:
	.word RB2GREY1C
	.word 0
VRB2GREY1D:
	.word RB2GREY1D
	.word 0
VRB2GREY1E:
	.word RB2GREY1E
	.word 0
VRB2GREY1F:
	.word RB2GREY1F
	.word 0
VRB2RED1A:
	.word RB2RED1A
	.word 0
VRB2RED1B:
	.word RB2RED1B
	.word 0
VRB2RED1C:
	.word RB2RED1C
	.word 0
VRB2RED1D:
	.word RB2RED1D
	.word 0
VRB2RED1E:
	.word RB2RED1E
	.word 0
VRB2RED1F:
	.word RB2RED1F
	.word 0
VRB2RED1G:
	.word RB2RED1G
	.word 0
	
	
SM1GOLD1A:
	.word 0x00000000
	.half 48, 29, 78, -25
	.word   VSMOK1_P
SM1GOLD1B:
	.word 0x000002E0
	.half 33, 27, 50, -42
	.word   VSMOK1_P
SM1GOLD1C:
	.word 0x00000444
	.half 16, 62, 45, -153
	.word   VSMOK1_P
SM1GOLD1D:
	.word 0x000005B4
	.half 111, 66, 38, -36
	.word   VSMOK1_P
SM1GOLD1E:
	.word 0x000012E4
	.half 139, 46, -27, -23
	.word   VSMOK1_P
	
RB1GOLD1A:
	.word 0x00000000
	.half 48, 29, 78, -25
	.word   VRB1YEL_P
RB1GOLD1B:
	.word 0x000002E0
	.half 33, 27, 50, -42
	.word   VRB1YEL_P
RB1GOLD1C:
	.word 0x00000444
	.half 16, 62, 45, -153
	.word   VRB1YEL_P
RB1GOLD1D:
	.word 0x000005B4
	.half 111, 66, 38, -36
	.word   VRB1YEL_P
RB1GOLD1E:
	.word 0x000012E4
	.half 139, 46, -27, -23
	.word   VRB1YEL_P
	
RB1GREY1A:
	.word 0x00001B10
	.half 43, 54, 56, -1
	.word   VRB1GRY_P
RB1GREY1B:
	.word 0x00001D94
        .half 27, 22, 66, -48
	.word   VRB1GRY_P
RB1GREY1C:
	.word 0x00001E30
	.half 125, 54, 59, -44
	.word   VRB1GRY_P
RB1GREY1D:
	.word 0x00002670
	.half 27, 23, 5, -142
	.word   VRB1GRY_P
RB1GREY1E:
	.word 0x000027CC
	.half 82, 54, -4, -1
	.word   VRB1GRY_P
RB1GREY1F:
	.word 0x00002E40
        .half 41, 25, -22, -88
	.word   VRB1GRY_P
RB1GREY1G:
	.word 0x00002F58
        .half 65, 67, -29, -89
	.word   VRB1GRY_P
RB2GREY1A:
	.word 0x00003260
	.half 43, 37, 4, -133
	.word   VRB2GRY_P
RB2GREY1B:
	.word 0x000034AC
        .half 66, 50, 58, -50
	.word   VRB2GRY_P
RB2GREY1C:
	.word 0x000038A0
	.half 60, 50, 54, -116
	.word   VRB2GRY_P
RB2GREY1D:
	.word 0x00003D54
        .half 52, 22, -57, -71
	.word   VRB2GRY_P
RB2GREY1E:
	.word 0x00003F40
        .half 51, 38, -18, -84
	.word   VRB2GRY_P
RB2GREY1F:
	.word 0x00004150
        .half 82, 51, 8, -7
	.word   VRB2GRY_P
RB2RED1A:
	.word 0x00004768
	.half 36, 54, 82, -38
	.word   VRB2RED_P
RB2RED1B:
	.word 0x00004B5C
	.half 13, 12, 42, -156
	.word   VRB2RED_P
RB2RED1C:
	.word 0x00004BC4
        .half 101, 50, 39, -41
	.word   VRB2RED_P
RB2RED1D:
	.word 0x000054D8
	.half 5, 10, -9, -151
	.word   VRB2RED_P
RB2RED1E:
	.word 0x00005504
	.half 21, 24, 21, -155
	.word   VRB2RED_P
RB2RED1F:
	.word 0x00005628
        .half 111, 19, -11, -25
	.word   VRB2RED_P
RB2RED1G:
	.word 0x00005A78
        .half 103, 46, -30, -42
	.word   VRB2RED_P


	.align 2
	.globl robo_dict
robo_dict:
#include "robo.dct"

