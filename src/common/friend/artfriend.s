#include <regdef.h>

	.option	pic0

	.set noreorder

/*
;******************************************************************************
; File: artfriend.s
;
; By: David Schwartz
;
; Date: Jan 1995
;
; (C) Williams Entertainment
;
; Mortal Kombat III friendality Art Textures
;******************************************************************************
*/

	.align 2
	.globl	a_friend
a_friend:
	.word FRIEN01
	.word FRIEN02
	.word FRIEN03
	.word FRIEN04
	.word FRIEN05
	.word FRIEN04
	.word FRIEN03
	.word FRIEN02
	.word FRIEN01
	.word FRIEN02
	.word FRIEN03
	.word FRIEN04
	.word FRIEN05
	.word FRIEN04
	.word FRIEN03
	.word FRIEN02
	.word FRIEN01
	.word FRIEN02
	.word FRIEN03
	.word FRIEN04
	.word FRIEN05
	.word 0
	.globl a_ship
a_ship:
	.word DSHIP01
	.word DSHIP02
	.word DSHIP03
	.word DSHIP04
	.word DSHIP05
	.word DSHIP04
	.word DSHIP03
	.word DSHIP02
	.word DSHIP01
	.word DSHIP02
	.word DSHIP03
	.word DSHIP04
	.word DSHIP05
	.word DSHIP04
	.word DSHIP03
	.word DSHIP02
	.word DSHIP01
	.word DSHIP02
	.word DSHIP03
	.word DSHIP04
	.word DSHIP05
	.word 0
FRIEN01:
	.word FRIEN01_SUB,0
FRIEN01_SUB:
	.word FRIEN1_IMG
	.half 49, 102, 102, 11
	.word FRIEN_P
FRIEN02:
	.word FRIEN02_SUB,0
FRIEN02_SUB:
	.word FRIEN2_IMG
	.half 45, 101, 101, 9
FRIEN03:
	.word FRIEN03_SUB,0
FRIEN03_SUB:
	.word FRIEN3_IMG
	.half 35, 98, 98, 4
FRIEN04:
	.word FRIEN04_SUB,0
FRIEN04_SUB:
	.word FRIEN4_IMG
	.half 26, 95, 96, 0
FRIEN05:
	.word FRIEN05_SUB,0
FRIEN05_SUB:
	.word FRIEN5_IMG
	.half 23, 94, 95, -1
DSHIP01:
	.word DSHIP01_SUB,0
DSHIP01_SUB:
	.word DSHIP1_IMG
	.half 51, 98, 0, 12
	.word DSHIP_P
DSHIP02:
	.word DSHIP02_SUB,0
DSHIP02_SUB:
	.word DSHIP2_IMG
	.half 46, 98, 0, 9
DSHIP03:
	.word DSHIP03_SUB,0
DSHIP03_SUB:
	.word DSHIP3_IMG
	.half 37, 98, 0, 5
DSHIP04:
	.word DSHIP04_SUB,0
DSHIP04_SUB:
	.word DSHIP4_IMG
	.half 26, 98, 0, 0
DSHIP05:
	.word DSHIP05_SUB,0
DSHIP05_SUB:
	.word DSHIP5_IMG
	.half 23, 101, 1, -1

	.align 2
#include "friend.att"

	.align 2
	.globl friend_dict
friend_dict:	
#include "friend.dct"