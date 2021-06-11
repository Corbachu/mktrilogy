#include <regdef.h>
#include "mkchar.inc"
#include "mkbkgd.inc"

	.option	pic0

	.set noreorder
	.data

/*
;******************************************************************************
; File: mkverse.s
;
; By: David Schwartz
;
; Date: Feb 1995
;
; (C) Williams Entertainment
;
; Mortal Kombat III Mortal Kombat Versus Module
;******************************************************************************
*/

/*
;*********************************
;**			EXTERNALS			**
;*********************************
*/
	.extern no_scroll		
	.extern dlists_bogus	
/*
	.extern	noob_p			
	.extern	BGSNBLU_P		
	.extern	BGSON1_P		
	.extern	BGSON2_P		
	.extern	BGSON3_P		
	.extern	BGKNBLU_P		
	.extern	BGKANO1_P		
	.extern	BGKANO2_P		
	.extern	BGKANO3_P		
	.extern	VINTAN_P		
	.extern	VINGRY_P		
	.extern	VINBLU_P		
	.extern	VINSKN_P		
	.extern	VJXGRN_P		
	.extern	VJXFLSH_P		
	.extern	VJXPURP_P		
	.extern	VJXGRY_P		
	.extern	VSZGRN_P		
	.extern	VSZBLU_P		
	.extern	VSZSKN_P		
	.extern	VSZGRY_P		
	.extern	VCOPRED_P		
	.extern	VCOPBLU_P		
	.extern	VCOPSKN_P		
	.extern	VCOPGRY_P		
	.extern	VLIABLU_P		
	.extern	VLIASKN_P		
	.extern	VLIAGRY_P		
	.extern	VLIAPRP_P		
	.extern	VRBDRED_P		
	.extern	VRB2GRY_P		
	.extern	VRB2RED_P		
	.extern	VRBDYEL_P		
	.extern	VRB1GRY_P		
	.extern	VRB1YEL_P		
	.extern	VSMOK2_P		
	.extern	VSMOK1_P		
	.extern	VRG3GRY_P		
	.extern	VKLBLU_P		
	.extern	VKLSKIN_P		
	.extern	VKLGRAY_P		
	.extern	VKLTAN_P		
	.extern	VKBBLU_P		
	.extern	VKBSKIN_P		
	.extern	VKBGRAY_P		
	.extern	VKBTAN_P		
	.extern	VSHBLU_P		
	.extern	VSHESKIN_		
	.extern	VSHEGRY_P		
	.extern	VSHRED_P		
	.extern	VLKYEL_P		
	.extern	VLKSKIN_P		
	.extern	VLKGRAY_P		
	.extern	VLKRED_P		
	.extern	VTSRED_P		
	.extern	VTSKIN_P		
	.extern	VTSGRY_P		
	.extern	VTSYEL_P		
	.extern	KTBLUE1_P		
	.extern	KTGRAY_P		
	.extern	KTFLESH_P		
	.extern	KTBLUE1_P		
	.extern	JDGRN1_P		
	.extern	JDGRAY_P		
	.extern	JDFLESH_P		
	.extern	JDGRN1_P		
	.extern	SCYELO2_P		
	.extern	SCGRAY_P		
	.extern	SCFLESH_P		
	.extern	SCYELO1_P		
	.extern	RPRED2_P		
	.extern	RPGRAY_P		
	.extern	RPFLESH_P		
	.extern	RPRED1_P		
	.extern	RPGRN2_P		
	.extern	RPGGRAY_P		
	.extern	RPGFLESH_P		
	.extern	RPGRN1_P		
	.extern	SCBLUE2_P		
	.extern	SCBLUE1_P		
	.extern	RPZGRAY_P		
	.extern	RPZFLESH_P		
	.extern	SCBLUE1_P		
	.extern	SCORPG_P		
	.extern	SCMGRAY_P		
	.extern	SCMFLESH_P		
	.extern	SCORPG_P		
	.extern	MLPURP2_P		
	.extern	MDGRAY_P		
	.extern	MDFLESH_P		
	.extern	MLPURP1_P		
*/
	

/*
;*********************************
;**			PALETTES								**
;*********************************
*/
	.align 2
	/* include palsrc\mkvspal.mas */

/*
;*********************************
;**			ANIMATIONS			**
;*********************************
*/

	.align 2
	.globl vs_anims
vs_anims:

/*

	.globl a_sk_badge_spin
a_sk_badge_spin
	DW VSMKCOIN_01-vs_anims
	DW VSMKCOIN_02-vs_anims
	DW VSMKCOIN_03-vs_anims
	DW VSMKCOIN_04-vs_anims
	DW VSMKCOIN_05-vs_anims
	DW VSMKCOIN_06-vs_anims
	DW VSMKCOIN_07-vs_anims
	DW VSMKCOIN_08-vs_anims
	DW VSMKCOIN_09-vs_anims
	DW ani_jump
	DW a_sk_badge_spin-vs_anims

	.globl sk_ochar_mugs
sk_ochar_mugs
	dw	VSHDKANO
	dw	VSHDSONYA
	dw	VSHDJAX
	dw	VSHDINDIAN
	dw	VSHDSUBZERO
	dw	VSHDSWAT
	dw	VSHDBRIDE
	dw	VSHDKETCHUP
	dw	VSHDMUSTARD
	dw	VSHDLAO
	dw	VSHDTUSKAN
	dw	VSHDSHEGORO
	dw	VSHDSHANG
	dw	VSHDLIUKANG
	dw	VSHDSMOKE
	dw	VSHDKITANA	; f
	dw	VSHDJADE		; 10
	dw	VSHDMILEENA	; 11
	dw	VSHDSCORPION	; 12
	dw	VSHDREPTILE	; 13
	dw	VSHDERMAC		; 14
	dw	VSHDCLASSUB	; 15

	.globl VSMKCOIN_01

	CNOP	0,4
	include ..\attract\treasure\mkmugs.psx
	CNOP	0,4
	include ..\attract\treasure\mkmugs.psi

**************************************************************************
	.align 2
	.globl a_mklight
a_mklight
	DW MKLIGHT1-vs_anims
	DW MKLIGHT2-vs_anims
	DW MKLIGHT3-vs_anims
	DW MKLIGHT4-vs_anims
	DW MKLIGHT5-vs_anims
	DW MKLIGHT6-vs_anims
	DW MKLIGHT7-vs_anims
	DW MKLIGHT8-vs_anims
	DW MKLIGHT9-vs_anims
	DW MKLIGHT10-vs_anims
	DW MKLIGHT11-vs_anims
	DW MKLIGHT12-vs_anims
	DW MKLIGHT13-vs_anims
	DW MKLIGHT14-vs_anims
	DW MKLIGHT15-vs_anims
	DW MKLIGHT16-vs_anims
	DW MKLIGHT17-vs_anims
	DW MKLIGHT18-vs_anims
	DW MKLIGHT19-vs_anims
	DW MKLIGHT20-vs_anims
	DW ani_jump
	DW a_mklight-vs_anims

	.globl MKLIGHT1
MKLIGHT1
	DW MKLIGHT1_IMG-vs_anims
	DH 65, 54, 0, 0
	dw   mKlIGHT_p
MKLIGHT2
	DW MKLIGHT2_IMG-vs_anims
	DH 65, 53, 0, 0
MKLIGHT3
	DW MKLIGHT3_IMG-vs_anims
	DH 65, 54, 0, 0
MKLIGHT4
	DW MKLIGHT4_IMG-vs_anims
	DH 65, 54, 0, 0
MKLIGHT5
	DW MKLIGHT5_IMG-vs_anims
	DH 65, 54, 0, 0
MKLIGHT6
	DW MKLIGHT6_IMG-vs_anims
	DH 65, 53, 0, 0
MKLIGHT7
	DW MKLIGHT7_IMG-vs_anims
	DH 65, 53, 0, 0
MKLIGHT8
	DW MKLIGHT8_IMG-vs_anims
	DH 65, 53, 0, 0
MKLIGHT9
	DW MKLIGHT9_IMG-vs_anims
	DH 65, 54, 0, 0
MKLIGHT10
	DW MKLIGHT10_IMG-vs_anims
	DH 65, 53, 0, 0
MKLIGHT11
	DW MKLIGHT11_IMG-vs_anims
	DH 65, 54, 0, 0
MKLIGHT12
	DW MKLIGHT12_IMG-vs_anims
	DH 65, 53, 0, 0
MKLIGHT13
	DW MKLIGHT13_IMG-vs_anims
	DH 65, 53, 0, 0
MKLIGHT14
	DW MKLIGHT14_IMG-vs_anims
	DH 65, 53, 0, 0
MKLIGHT15
	DW MKLIGHT15_IMG-vs_anims
	DH 65, 53, 0, 0
MKLIGHT16
	DW MKLIGHT16_IMG-vs_anims
	DH 65, 54, 0, 0
MKLIGHT17
	DW MKLIGHT17_IMG-vs_anims
	DH 65, 53, 0, 0
MKLIGHT18
	DW MKLIGHT18_IMG-vs_anims
	DH 65, 54, 0, 0
MKLIGHT19
	DW MKLIGHT19_IMG-vs_anims
	DH 65, 53, 0, 0
MKLIGHT20
	DW MKLIGHT20_IMG-vs_anims
	DH 65, 54, 0, 0


**************************************************************************
	.align 2
	.globl symbol_table
symbol_table
	DW I_DRAGON-vs_anims
	DW I_MK-vs_anims
	DW I_YINYANG-vs_anims
	DW I_THREE-vs_anims
	DW I_QUESTION-vs_anims
	DW I_LIGHTNING-vs_anims
	DW I_GORO-vs_anims
	DW I_RAIDEN-vs_anims
	DW I_SHOKAHN-vs_anims
	DW I_SKULL-vs_anims
	DW I_QUESTION-vs_anims
	DW I_QUESTION-vs_anims

	.globl I_DRAGON
I_DRAGON
	DW I_DRAGON_IMG-vs_anims
	DH 17, 14, 0, 0
	dw   IDRAG_P
I_MK
	DW I_MK_IMG-vs_anims
	DH 17, 14, 0, 0
	dw   IMK_P
I_YINYANG
	DW I_YINYANG_IMG-vs_anims
	DH 17, 14, 0, 0
	dw   IYIN_P
I_THREE
	DW I_THREE_IMG-vs_anims
	DH 17, 14, 0, 0
	dw   ITHREE_P
I_QUESTION
	DW I_QUESTION_IMG-vs_anims
	DH 17, 14, 0, 0
	dw   IQ_P
I_LIGHTNING
	DW I_LIGHTNING_IMG-vs_anims
	DH 17, 14, 0, 0
	dw   ILIGHT_P
I_GORO
	DW I_GORO_IMG-vs_anims
	DH 17, 14, 0, 0
	dw   IGORO_P
I_RAIDEN
	DW I_RAIDEN_IMG-vs_anims
	DH 17, 14, 0, 0
	dw   IRAID_P
I_SHOKAHN
	DW I_SHOKAHN_IMG-vs_anims
	DH 17, 14, 0, 0
	dw   IKAHN_P
I_SKULL
	DW I_SKULL_IMG-vs_anims
	DH 17, 14, 0, 0
	dw   ISKULL_P

	.globl BOX2
BOX2
	DW BOX2_IMG-vs_anims
	DH 118, 18, 0, 0
	dw BOX1_P

**************************************************************************
	.align 2
	.globl a_vs_v
a_vs_v
	DW BURNV1-vs_anims
	DW BURNV2-vs_anims
	DW BURNV3-vs_anims
	DW BURNV4-vs_anims
	DW BURNV5-vs_anims
	DW BURNV6-vs_anims
	DW BURNV7-vs_anims
	DW BURNV8-vs_anims
	DW BURNV9-vs_anims
	DW BURNV10-vs_anims
	DW BURNV11-vs_anims
	DW BURNV12-vs_anims
	DW BURNV13-vs_anims
	DW 0

	.globl BURNS1
BURNS1
	DW BURNS1_IMG-vs_anims
	DH 10, 14, -21, -1
	dw   BURNVS_P
BURNS2
	DW BURNS2_IMG-vs_anims
	DH 10, 16, -21, 1
BURNS3
	DW BURNS3_IMG-vs_anims
	DH 15, 14, -16, -3
BURNS4
	DW BURNS4_IMG-vs_anims
	DH 17, 16, -14, -3
BURNS5
	DW BURNS5_IMG-vs_anims
	DH 20, 20, -11, -3
BURNS6
	DW BURNS6_IMG-vs_anims
	DH 26, 26, -5, -3
BURNS7
	DW BURNS7_IMG-vs_anims
	DH 22, 26, -9, -3
BURNS8
	DW BURNS8_IMG-vs_anims
	DH 22, 26, -9, -3
BURNS9
	DW BURNS9_IMG-vs_anims
	DH 22, 31, -9, -3
BURNS10
	DW BURNS10_IMG-vs_anims
	DH 22, 34, -9, -3
BURNS11
	DW BURNS11_IMG-vs_anims
	DH 22, 38, -9, -3
BURNS12
	DW BURNS12_IMG-vs_anims
	DH 22, 43, -9, -3
BURNS13
	DW BURNS13_IMG-vs_anims
	DH 25, 46, -6, -3
BURNS14
	DW BURNS14_IMG-vs_anims
	DH 28, 48, -3, -3
BURNS15
	DW BURNS15_IMG-vs_anims
	DH 31, 49, 0, -3


**************************************************************************
	.align 2
	.globl a_vs_s
a_vs_s
	DW BURNS1-vs_anims
	DW BURNS2-vs_anims
	DW BURNS3-vs_anims
	DW BURNS4-vs_anims
	DW BURNS5-vs_anims
	DW BURNS6-vs_anims
	DW BURNS7-vs_anims
	DW BURNS8-vs_anims
	DW BURNS9-vs_anims
	DW BURNS10-vs_anims
	DW BURNS11-vs_anims
	DW BURNS12-vs_anims
	DW BURNS13-vs_anims
	DW BURNS14-vs_anims
	DW BURNS15-vs_anims
	DW 0

	.globl BURNV1
BURNV1
	DW BURNV1_IMG-vs_anims
	DH 14, 18, -1, -8
	dw BURNVS_P
BURNV2
	DW BURNV2_IMG-vs_anims
	DH 14, 20, 0, -10
BURNV3
	DW BURNV3_IMG-vs_anims
	DH 12, 25, 0, -10
BURNV4
	DW BURNV4_IMG-vs_anims
	DH 11, 31, -1, -10
BURNV5
	DW BURNV5_IMG-vs_anims
	DH 12, 41, -1, -10
BURNV6
	DW BURNV6_IMG-vs_anims
	DH 14, 39, -3, -10
BURNV7
	DW BURNV7_IMG-vs_anims
	DH 18, 38, -3, -10
BURNV8
	DW BURNV8_IMG-vs_anims
	DH 19, 38, -3, -10
BURNV9
	DW BURNV9_IMG-vs_anims
	DH 22, 38, -3, -10
BURNV10
	DW BURNV10_IMG-vs_anims
	DH 27, 43, -3, -5
BURNV11
	DW BURNV11_IMG-vs_anims
	DH 29, 44, -3, -4
BURNV12
	DW BURNV12_IMG-vs_anims
	DH 30, 48, -3, 0
BURNV13
	DW BURNV13_IMG-vs_anims
	DH 31, 49, -3, 1
**************************************************************************
	.align 2
	.globl battle_digits
battle_digits
	dw	BATTLE0
	dw	BATTLE1
	dw	BATTLE2
	dw	BATTLE3
	dw	BATTLE4
	dw	BATTLE5
	dw	BATTLE6
	dw	BATTLE7
	dw	BATTLE8
	dw	BATTLE9


	.globl BATTLE
BATTLE
	DW BATTLE_IMG-vs_anims
	DH 140, 16, 0, 0
	dw   BATTLE_P

	.globl BATTLE0
BATTLE0
	DW BATTLE0_IMG-vs_anims
	DH 28, 15, 14, -5
	dw   BATTLE_P
BATTLE1
	DW BATTLE1_IMG-vs_anims
	DH 19, 15, 11, -5
BATTLE2
	DW BATTLE2_IMG-vs_anims
	DH 27, 15, 14, -5
BATTLE3
	DW BATTLE3_IMG-vs_anims
	DH 26, 16, 14, -5
BATTLE4
	DW BATTLE4_IMG-vs_anims
	DH 30, 15, 14, -5
BATTLE5
	DW BATTLE5_IMG-vs_anims
	DH 26, 15, 13, -5
BATTLE6
	DW BATTLE6_IMG-vs_anims
	DH 28, 15, 14, -5
BATTLE7
	DW BATTLE7_IMG-vs_anims
	DH 25, 15, 11, -5
BATTLE8
	DW BATTLE8_IMG-vs_anims
	DH 26, 15, 14, -5
BATTLE9
	DW BATTLE9_IMG-vs_anims
	DH 29, 15, 14, -5
*/


/*
;*********************************
;**		 MODULE DATA			**
;*********************************
*/
	.align 2
	/* include ..\attract\vs\steelvs.mod */
#if 0	
	.align 2
	.globl vs_module
vs_module:
	.half	0		 		/* autoerase color */
	.half	0x00				/* initial world y */
	.half	0x00	     			/* ground y */
	.half	0x00				/* initial worldx */
	.half	-0x500 	  			/* scroll left limit */
	.half	0x500	  			/* scroll right limit */

	.word	calla_return
	.word	no_scroll			/* scroll table */
	.word	dlists_bogus
	.word	bakmods

	.word	STEELMODBMOD
	.half	0xfffe,0x07
	.word	0xffffffff
	.word	0				/* no floor here !! */
#endif

/*

	.align 2
	include ..\attract\vs\mkbgvs.psi
********************************************************************** 
vs_c0 group
	section	.vs_0

;	include palsrc\vssonya.mas

	.globl sonya_pieces
sonya_pieces
	.half	0x5e,0x4f,0x12d,0x4f
	.word bgsonya1a-sonya_pieces,0
	.word bgsonya1b-sonya_pieces,0
	.word bgsonya1c-sonya_pieces,0
	.word bgsonya1d-sonya_pieces,0
	.word bgsonya1e-sonya_pieces,0
	.word bgsonya1f-sonya_pieces,0
	.word bgsonya2a-sonya_pieces,BGSNBLU_P
	.word bgsonya2b-sonya_pieces,BGSNBLU_P
	.word bgsonya2c-sonya_pieces,BGSNBLU_P
	.word bgsonya2d-sonya_pieces,BGSNBLU_P
	.word bgsonya3a-sonya_pieces,0
	.word bgsonya3b-sonya_pieces,0
	.word bgsonya3c-sonya_pieces,0
	.word bgsonya3d-sonya_pieces,0
	.word bgsonya3e-sonya_pieces,0
	.word bgsonya3f-sonya_pieces,0
	.word bgsonya3g-sonya_pieces,0
	.word 0

bgsonya1a
	.word	BGSONYA1A-sonya_pieces,0
bgsonya1b
	.word	BGSONYA1B-sonya_pieces,0
bgsonya1c
	.word	BGSONYA1C-sonya_pieces,0
bgsonya1d
	.word	BGSONYA1D-sonya_pieces,0
bgsonya1e
	.word	BGSONYA1E-sonya_pieces,0
bgsonya1f
	.word	BGSONYA1F-sonya_pieces,0
bgsonya2a
	.word	BGSONYA2A-sonya_pieces,0
bgsonya2b
	.word	BGSONYA2B-sonya_pieces,0
bgsonya2c
	.word	BGSONYA2C-sonya_pieces,0
bgsonya2d
	.word	BGSONYA2D-sonya_pieces,0
bgsonya3a
	.word	BGSONYA3A-sonya_pieces,0
bgsonya3b
	.word	BGSONYA3B-sonya_pieces,0
bgsonya3c
	.word	BGSONYA3C-sonya_pieces,0
bgsonya3d
	.word	BGSONYA3D-sonya_pieces,0
bgsonya3e
	.word	BGSONYA3E-sonya_pieces,0
bgsonya3f
	.word	BGSONYA3F-sonya_pieces,0
bgsonya3g
	.word	BGSONYA3G-sonya_pieces,0

BGSONYA1A
	.word	BGSONYA1A_SUB-sonya_pieces,0
BGSONYA1A_SUB
	.word BGSONYA1A_IMG-sonya_pieces
	.half 64, 104, 75, -5
	.word   BGSON1_P
BGSONYA1B
	.word	BGSONYA1B_SUB-sonya_pieces,0
BGSONYA1B_SUB
	.word BGSONYA1B_IMG-sonya_pieces
	.half 26, 70, 11, -2
	.word   BGSON1_P
BGSONYA1C
	.word	BGSONYA1C_SUB-sonya_pieces,0
BGSONYA1C_SUB
	.word BGSONYA1C_IMG-sonya_pieces
	.half 20, 53, -13, -9
	.word   BGSON1_P
BGSONYA1D
	.word	BGSONYA1D_SUB-sonya_pieces,0
BGSONYA1D_SUB
	.word BGSONYA1D_IMG-sonya_pieces
	.half 53, 31, 37, -124
	.word   BGSON1_P
BGSONYA1E
	.word	BGSONYA1E_SUB-sonya_pieces,0
BGSONYA1E_SUB
	.word BGSONYA1E_IMG-sonya_pieces
	.half 34, 59, -16, -73
	.word   BGSON1_P
BGSONYA1F
	.word	BGSONYA1F_SUB-sonya_pieces,0
BGSONYA1F_SUB
	.word BGSONYA1F_IMG-sonya_pieces
	.half 36, 39, -49, -93
	.word   BGSON1_P
BGSONYA2A
	.word	BGSONYA2A_SUB-sonya_pieces,0
BGSONYA2A_SUB
	.word BGSONYA2A_IMG-sonya_pieces
	.half 6, 3, 51, -78
	.word   BGSON2_P
BGSONYA2B
	.word	BGSONYA2B_SUB-sonya_pieces,0
BGSONYA2B_SUB
	.word BGSONYA2B_IMG-sonya_pieces
	.half 30, 37, 61, -136
	.word   BGSON2_P
BGSONYA2C
	.word	BGSONYA2C_SUB-sonya_pieces,0
BGSONYA2C_SUB
	.word BGSONYA2C_IMG-sonya_pieces
	.half 34, 64, 22, -64
	.word   BGSON2_P
BGSONYA2D
	.word	BGSONYA2D_SUB-sonya_pieces,0
BGSONYA2D_SUB
	.word BGSONYA2D_IMG-sonya_pieces
	.half 18, 59, -11, -70
	.word   BGSON2_P
BGSONYA3A
	.word	BGSONYA3A_SUB-sonya_pieces,0
BGSONYA3A_SUB
	.word BGSONYA3A_IMG-sonya_pieces
	.half 7, 32, 34, -92
	.word   BGSON3_P
BGSONYA3B
	.word	BGSONYA3B_SUB-sonya_pieces,0
BGSONYA3B_SUB
	.word BGSONYA3B_IMG-sonya_pieces
	.half 20, 70, 30, -57
	.word   BGSON3_P
BGSONYA3C
	.word	BGSONYA3C_SUB-sonya_pieces,0
BGSONYA3C_SUB
	.word BGSONYA3C_IMG-sonya_pieces
	.half 38, 36, 43, -137
	.word   BGSON3_P
BGSONYA3D
	.word	BGSONYA3D_SUB-sonya_pieces,0
BGSONYA3D_SUB
	.word BGSONYA3D_IMG-sonya_pieces
	.half 10, 21, 5, -151
	.word   BGSON3_P
BGSONYA3E
	.word	BGSONYA3E_SUB-sonya_pieces,0
BGSONYA3E_SUB
	.word BGSONYA3E_IMG-sonya_pieces
	.half 16, 84, 10, -29
	.word   BGSON3_P
BGSONYA3F
	.word	BGSONYA3F_SUB-sonya_pieces,0
BGSONYA3F_SUB
	.word BGSONYA3F_IMG-sonya_pieces
	.half 37, 91, -5, -24
	.word   BGSON3_P
BGSONYA3G
	.word	BGSONYA3G_SUB-sonya_pieces,0
BGSONYA3G_SUB
	.word BGSONYA3G_IMG-sonya_pieces
	.half 15, 26, -72, -85
	.word   BGSON3_P

	.align 2
	include ..\attract\vs\vssonya.psi

;**********************************************************************
vs_c1 group
	section	.vs_1

;	include palsrc\vskano.mas

	.globl kano_pieces
kano_pieces
	.half	0x5e,0x4e,0x12d,0x4e
	.word bgkano1a-kano_pieces,0
	.word bgkano1b-kano_pieces,0
	.word bgkano1c-kano_pieces,0
	.word bgkano1d-kano_pieces,0
	.word bgkano2a-kano_pieces,BGKNBLU_P
	.word bgkano2b-kano_pieces,BGKNBLU_P
	.word bgkano2c-kano_pieces,BGKNBLU_P
	.word bgkano2d-kano_pieces,BGKNBLU_P
	.word bgkano2e-kano_pieces,BGKNBLU_P
	.word bgkano3a-kano_pieces,0
	.word bgkano3b-kano_pieces,0
	.word bgkano3c-kano_pieces,0
	.word bgkano3d-kano_pieces,0
	.word bgkano4a-kano_pieces,0
	.word 0

bgkano1a
	.word	BGKANO1A-kano_pieces,0
bgkano1b
	.word	BGKANO1B-kano_pieces,0
bgkano1c
	.word	BGKANO1C-kano_pieces,0
bgkano1d
	.word	BGKANO1D-kano_pieces,0
bgkano2a
	.word	BGKANO2A-kano_pieces,0
bgkano2b
	.word	BGKANO2B-kano_pieces,0
bgkano2c
	.word	BGKANO2C-kano_pieces,0
bgkano2d
	.word	BGKANO2D-kano_pieces,0
bgkano2e
	.word	BGKANO2E-kano_pieces,0
bgkano3a
	.word	BGKANO3A-kano_pieces,0
bgkano3b
	.word	BGKANO3B-kano_pieces,0
bgkano3c
	.word	BGKANO3C-kano_pieces,0
bgkano3d
	.word	BGKANO3D-kano_pieces,0
bgkano4a
	.word	BGKANO4A-kano_pieces,0


BGKANO1A
	.word	BGKANO1A_SUB-kano_pieces,0
BGKANO1A_SUB
	.word BGKANO1A_IMG-kano_pieces
	.half 45, 67, 66, -35
	.word   BGKANO1_P
BGKANO1B
	.word	BGKANO1B_SUB-kano_pieces,0
BGKANO1B_SUB
	.word BGKANO1B_IMG-kano_pieces
	.half 43, 82, -2, -7
	.word   BGKANO1_P
BGKANO1C
	.word	BGKANO1C_SUB-kano_pieces,0
BGKANO1C_SUB
	.word BGKANO1C_IMG-kano_pieces
	.half 12, 60, -45, -9
	.word   BGKANO1_P
BGKANO1D
	.word	BGKANO1D_SUB-kano_pieces,0
BGKANO1D_SUB
	.word BGKANO1D_IMG-kano_pieces
	.half 38, 65, -31, -93
	.word   BGKANO1_P
BGKANO2A
	.word	BGKANO2A_SUB-kano_pieces,0
BGKANO2A_SUB
	.word BGKANO2A_IMG-kano_pieces
	.half 28, 44, 70, -55
	.word   BGKANO2_P
BGKANO2B
	.word	BGKANO2B_SUB-kano_pieces,0
BGKANO2B_SUB
	.word BGKANO2B_IMG-kano_pieces
	.half 22, 67, 24, -30
	.word   BGKANO2_P
BGKANO2C
	.word	BGKANO2C_SUB-kano_pieces,0
BGKANO2C_SUB
	.word BGKANO2C_IMG-kano_pieces
	.half 2, 9, -1, -79
	.word   BGKANO2_P
BGKANO2D
	.word	BGKANO2D_SUB-kano_pieces,0
BGKANO2D_SUB
	.word BGKANO2D_IMG-kano_pieces
	.half 16, 37, 68, -137
	.word   BGKANO2_P
BGKANO2E
	.word	BGKANO2E_SUB-kano_pieces,0
BGKANO2E_SUB
	.word BGKANO2E_IMG-kano_pieces
	.half 78, 93, 3, -81
	.word   BGKANO2_P
BGKANO3A
	.word	BGKANO3A_SUB-kano_pieces,0
BGKANO3A_SUB
	.word BGKANO3A_IMG-kano_pieces
	.half 25, 36, 68, -59
	.word   BGKANO3_P
BGKANO3B
	.word	BGKANO3B_SUB-kano_pieces,0
BGKANO3B_SUB
	.word BGKANO3B_IMG-kano_pieces
	.half 77, 137, 64, -37
	.word   BGKANO3_P
BGKANO3C
	.word	BGKANO3C_SUB-kano_pieces,0
BGKANO3C_SUB
	.word BGKANO3C_IMG-kano_pieces
	.half 28, 36, -44, -114
	.word   BGKANO3_P
BGKANO3D
	.word	BGKANO3D_SUB-kano_pieces,0
BGKANO3D_SUB
	.word BGKANO3D_IMG-kano_pieces
	.half 46, 117, -12, -23
	.word   BGKANO3_P
BGKANO4A
	.word	BGKANO4A_SUB-kano_pieces,0
BGKANO4A_SUB
	.word BGKANO4A_IMG-kano_pieces
	.half 63, 72, 10, -39
	.word   BGKANO4_P

	.align 2
	include ..\attract\vs\vskano.psi

;**********************************************************************
vs_c2 group
	section	.vs_2

	;include palsrc\vsind.mas

	.globl ind_pieces
ind_pieces
	.half	0x63,0x25+19+10,0x125,0x25+19+10
	.word ingry1a-ind_pieces,0
	.word ingry1b-ind_pieces,0
	.word ingry1c-ind_pieces,0
	.word ingry1d-ind_pieces,0
	.word ingry1e-ind_pieces,0
	.word inblu1a-ind_pieces,VINTAN_P
	.word inblu1b-ind_pieces,VINTAN_P
	.word inblu1c-ind_pieces,VINTAN_P
	.word inblu1d-ind_pieces,VINTAN_P
	.word inskin1a-ind_pieces,0
	.word inskin1b-ind_pieces,0
	.word inskin1c-ind_pieces,0
	.word inskin1d-ind_pieces,0
	.word inskin1e-ind_pieces,0
	.word inskin1f-ind_pieces,0
	.word inskin1g-ind_pieces,0
	.word 0

ingry1a
	.word	INGRY1A-ind_pieces,0
ingry1b
	.word	INGRY1B-ind_pieces,0
ingry1c
	.word	INGRY1C-ind_pieces,0
ingry1d
	.word	INGRY1D-ind_pieces,0
ingry1e
	.word	INGRY1E-ind_pieces,0
inblu1a
	.word	INBLU1A-ind_pieces,0
inblu1b
	.word	INBLU1B-ind_pieces,0
inblu1c
	.word	INBLU1C-ind_pieces,0
inblu1d
	.word	INBLU1D-ind_pieces,0
inskin1a
	.word	INSKIN1A-ind_pieces,0
inskin1b
	.word	INSKIN1B-ind_pieces,0
inskin1c
	.word	INSKIN1C-ind_pieces,0
inskin1d
	.word	INSKIN1D-ind_pieces,0
inskin1e
	.word	INSKIN1E-ind_pieces,0
inskin1f
	.word	INSKIN1F-ind_pieces,0
inskin1g
	.word	INSKIN1G-ind_pieces,0

INGRY1A
	.word	INGRY1A_SUB-ind_pieces,0
INGRY1A_SUB
	.word INGRY1A_IMG-ind_pieces
	.half 21, 24, -62, -121
	.word   VINGRY_P
INGRY1B
	.word	INGRY1B_SUB-ind_pieces,0
INGRY1B_SUB
	.word INGRY1B_IMG-ind_pieces
	.half 23, 81, 72, -103
	.word   VINGRY_P
INGRY1C
	.word	INGRY1C_SUB-ind_pieces,0
INGRY1C_SUB
	.word INGRY1C_IMG-ind_pieces
	.half 41, 95, 49, -48
	.word   VINGRY_P
INGRY1D
	.word	INGRY1D_SUB-ind_pieces,0
INGRY1D_SUB
	.word INGRY1D_IMG-ind_pieces
	.half 19, 105, -25, -16
	.word   VINGRY_P
INGRY1E
	.word	INGRY1E_SUB-ind_pieces,0
INGRY1E_SUB
	.word INGRY1E_IMG-ind_pieces
	.half 64, 159, 38, -15
	.word   VINGRY_P
INBLU1A
	.word	INBLU1A_SUB-ind_pieces,0
INBLU1A_SUB
	.word INBLU1A_IMG-ind_pieces
	.half 21, 23, 64, -76
	.word   VINBLU_P
INBLU1B
	.word	INBLU1B_SUB-ind_pieces,0
INBLU1B_SUB
	.word INBLU1B_IMG-ind_pieces
	.half 38, 68, -2, -33
	.word   VINBLU_P
INBLU1C
	.word	INBLU1C_SUB-ind_pieces,0
INBLU1C_SUB
	.word INBLU1C_IMG-ind_pieces
	.half 22, 26, -19, -120
	.word   VINBLU_P
INBLU1D
	.word	INBLU1D_SUB-ind_pieces,0
INBLU1D_SUB
	.word INBLU1D_IMG-ind_pieces
	.half 64, 13, 56, -171
	.word   VINBLU_P
INSKIN1A
	.word	INSKIN1A_SUB-ind_pieces,0
INSKIN1A_SUB
	.word INSKIN1A_IMG-ind_pieces
	.half 34, 77, 88, -69
	.word   VINSKN_P
INSKIN1B
	.word	INSKIN1B_SUB-ind_pieces,0
INSKIN1B_SUB
	.word INSKIN1B_IMG-ind_pieces
	.half 33, 116, 58, -60
	.word   VINSKN_P
INSKIN1C
	.word	INSKIN1C_SUB-ind_pieces,0
INSKIN1C_SUB
	.word INSKIN1C_IMG-ind_pieces
	.half 28, 41, -12, -42
	.word   VINSKN_P
INSKIN1D
	.word	INSKIN1D_SUB-ind_pieces,0
INSKIN1D_SUB
	.word INSKIN1D_IMG-ind_pieces
	.half 18, 31, -67, -98
	.word   VINSKN_P
INSKIN1E
	.word	INSKIN1E_SUB-ind_pieces,0
INSKIN1E_SUB
	.word INSKIN1E_IMG-ind_pieces
	.half 14, 24, -25, -99
	.word   VINSKN_P
INSKIN1F
	.word	INSKIN1F_SUB-ind_pieces,0
INSKIN1F_SUB
	.word INSKIN1F_IMG-ind_pieces
	.half 54, 48, -19, -126
	.word   VINSKN_P
INSKIN1G
	.word	INSKIN1G_SUB-ind_pieces,0
INSKIN1G_SUB
	.word INSKIN1G_IMG-ind_pieces
	.half 44, 89, 26, -69
	.word   VINSKN_P

	.align 2
	include ..\attract\vs\vsindian.psi

;**********************************************************************
vs_c3 group
	section	.vs_3

	;include palsrc\vsjax.mas

	.globl jax_pieces
jax_pieces
	.half	0x63,0x20+35,0x125,0x20+35
	.word jxflesh1a-jax_pieces,0
	.word jxpurp1a-jax_pieces,VJXGRN_P
	.word jxpurp1b-jax_pieces,VJXGRN_P
	.word jxgry1a-jax_pieces,0
	.word jxgry1b-jax_pieces,0
	.word jxgry1c-jax_pieces,0
	.word 0

jxflesh1a
	.word	JXFLESH1A-jax_pieces,0
jxpurp1a
	.word	JXPURP1A-jax_pieces,0
jxpurp1b
	.word	JXPURP1B-jax_pieces,0
jxgry1a
	.word	JXGRY1A-jax_pieces,0
jxgry1b
	.word	JXGRY1B-jax_pieces,0
jxgry1c
	.word	JXGRY1C-jax_pieces,0

JXFLESH1A
	.word	JXFLESH1A_SUB-jax_pieces,0
JXFLESH1A_SUB
	.word JXFLESH1A_IMG-jax_pieces
	.half 88, 158, 44, -13
	.word   VJXFLSH_P
JXPURP1A
	.word	JXPURP1A_SUB-jax_pieces,0
JXPURP1A_SUB
	.word JXPURP1A_IMG-jax_pieces
	.half 27, 15, 57, -168
	.word   VJXPURP_P
JXPURP1B
	.word	JXPURP1B_SUB-jax_pieces,0
JXPURP1B_SUB
	.word JXPURP1B_IMG-jax_pieces
	.half 6, 6, -16, -178
	.word   VJXPURP_P
JXGRY1A
	.word	JXGRY1A_SUB-jax_pieces,0
JXGRY1A_SUB
	.word JXGRY1A_IMG-jax_pieces
	.half 77, 96, 84, -50
	.word   VJXGRY_P
JXGRY1B
	.word	JXGRY1B_SUB-jax_pieces,0
JXGRY1B_SUB
	.word JXGRY1B_IMG-jax_pieces
	.half 72, 31, 50, -153
	.word   VJXGRY_P
JXGRY1C
	.word	JXGRY1C_SUB-jax_pieces,0
JXGRY1C_SUB
	.word JXGRY1C_IMG-jax_pieces
	.half 34, 106, -32, -77
	.word   VJXGRY_P

	.align 2
	include ..\attract\vs\vsjax.psi

;**********************************************************************
vs_c4 group
	section	.vs_4

	;include palsrc\vssz.mas

	.globl sz_pieces
sz_pieces
	.half	0x63,0x2d+29,0x125,0x2d+29
	.word szblue1a-sz_pieces,VSZGRN_P
	.word szblue1b-sz_pieces,VSZGRN_P
	.word szblue1c-sz_pieces,VSZGRN_P
	.word szblue1d-sz_pieces,VSZGRN_P
	.word szflesh1a-sz_pieces,0
	.word szflesh1b-sz_pieces,0
	.word szflesh1c-sz_pieces,0
	.word szflesh1d-sz_pieces,0
	.word szflesh1e-sz_pieces,0
	.word szflesh1f-sz_pieces,0
	.word szflesh1g-sz_pieces,0
	.word szflesh1h-sz_pieces,0
	.word szgrey1a-sz_pieces,0
	.word szgrey1b-sz_pieces,0
	.word szgrey1c-sz_pieces,0
	.word szgrey1d-sz_pieces,0
	.word szgrey1e-sz_pieces,0
	.word szgrey1f-sz_pieces,0
	.word szgrey1g-sz_pieces,0
	.word 0

szblue1a
	.word	SZBLUE1A-sz_pieces,0
szblue1b
	.word	SZBLUE1B-sz_pieces,0
szblue1c
	.word	SZBLUE1C-sz_pieces,0
szblue1d
	.word	SZBLUE1D-sz_pieces,0
szflesh1a
	.word	SZFLESH1A-sz_pieces,0
szflesh1b
	.word	SZFLESH1B-sz_pieces,0
szflesh1c
	.word	SZFLESH1C-sz_pieces,0
szflesh1d
	.word	SZFLESH1D-sz_pieces,0
szflesh1e
	.word	SZFLESH1E-sz_pieces,0
szflesh1f
	.word	SZFLESH1F-sz_pieces,0
szflesh1g
	.word	SZFLESH1G-sz_pieces,0
szflesh1h
	.word	SZFLESH1H-sz_pieces,0
szgrey1a
	.word	SZGREY1A-sz_pieces,0
szgrey1b
	.word	SZGREY1B-sz_pieces,0
szgrey1c
	.word	SZGREY1C-sz_pieces,0
szgrey1d
	.word	SZGREY1D-sz_pieces,0
szgrey1e
	.word	SZGREY1E-sz_pieces,0
szgrey1f
	.word	SZGREY1F-sz_pieces,0
szgrey1g
	.word	SZGREY1G-sz_pieces,0

SZBLUE1A
	.word	SZBLUE1A_SUB-sz_pieces,0
SZBLUE1A_SUB
	.word SZBLUE1A_IMG-sz_pieces
	.half 30, 22, 60, -155
	.word   VSZBLU_P
SZBLUE1B
	.word	SZBLUE1B_SUB-sz_pieces,0
SZBLUE1B_SUB
	.word SZBLUE1B_IMG-sz_pieces
	.half 50, 104, 52, -45
	.word   VSZBLU_P
SZBLUE1C
	.word	SZBLUE1C_SUB-sz_pieces,0
SZBLUE1C_SUB
	.word SZBLUE1C_IMG-sz_pieces
	.half 8, 40, 2, -47
	.word   VSZBLU_P
SZBLUE1D
	.word	SZBLUE1D_SUB-sz_pieces,0
SZBLUE1D_SUB
	.word SZBLUE1D_IMG-sz_pieces
	.half 36, 65, 2, -80
	.word   VSZBLU_P
SZFLESH1A
	.word	SZFLESH1A_SUB-sz_pieces,0
SZFLESH1A_SUB
	.word SZFLESH1A_IMG-sz_pieces
	.half 31, 21, 36, -9
	.word   VSZSKN_P
SZFLESH1B
	.word	SZFLESH1B_SUB-sz_pieces,0
SZFLESH1B_SUB
	.word SZFLESH1B_IMG-sz_pieces
	.half 28, 28, 34, -120
	.word   VSZSKN_P
SZFLESH1C
	.word	SZFLESH1C_SUB-sz_pieces,0
SZFLESH1C_SUB
	.word SZFLESH1C_IMG-sz_pieces
	.half 75, 116, 88, -12
	.word   VSZSKN_P
SZFLESH1D
	.word	SZFLESH1D_SUB-sz_pieces,0
SZFLESH1D_SUB
	.word SZFLESH1D_IMG-sz_pieces
	.half 2, 13, 13, -45
	.word   VSZSKN_P
SZFLESH1E
	.word	SZFLESH1E_SUB-sz_pieces,0
SZFLESH1E_SUB
	.word SZFLESH1E_IMG-sz_pieces
	.half 15, 32, -62, -121
	.word   VSZSKN_P
SZFLESH1F
	.word	SZFLESH1F_SUB-sz_pieces,0
SZFLESH1F_SUB
	.word SZFLESH1F_IMG-sz_pieces
	.half 33, 87, 11, -38
	.word   VSZSKN_P
SZFLESH1G
	.word	SZFLESH1G_SUB-sz_pieces,0
SZFLESH1G_SUB
	.word SZFLESH1G_IMG-sz_pieces
	.half 45, 78, -13, -99
	.word   VSZSKN_P
SZFLESH1H
	.word	SZFLESH1H_SUB-sz_pieces,0
SZFLESH1H_SUB
	.word SZFLESH1H_IMG-sz_pieces
	.half 29, 54, -21, -29
	.word   VSZSKN_P
SZGREY1A
	.word	SZGREY1A_SUB-sz_pieces,0
SZGREY1A_SUB
	.word SZGREY1A_IMG-sz_pieces
	.half 51, 34, 83, -11
	.word   VSZGRY_P
SZGREY1B
	.word	SZGREY1B_SUB-sz_pieces,0
SZGREY1B_SUB
	.word SZGREY1B_IMG-sz_pieces
	.half 38, 60, 94, -117
	.word   VSZGRY_P
SZGREY1C
	.word	SZGREY1C_SUB-sz_pieces,0
SZGREY1C_SUB
	.word SZGREY1C_IMG-sz_pieces
	.half 54, 131, 56, -47
	.word   VSZGRY_P
SZGREY1D
	.word	SZGREY1D_SUB-sz_pieces,0
SZGREY1D_SUB
	.word SZGREY1D_IMG-sz_pieces
	.half 46, 51, -3, -13
	.word   VSZGRY_P
SZGREY1E
	.word	SZGREY1E_SUB-sz_pieces,0
SZGREY1E_SUB
	.word SZGREY1E_IMG-sz_pieces
	.half 6, 20, 2, -67
	.word   VSZGRY_P
SZGREY1F
	.word	SZGREY1F_SUB-sz_pieces,0
SZGREY1F_SUB
	.word SZGREY1F_IMG-sz_pieces
	.half 36, 61, 2, -83
	.word   VSZGRY_P
SZGREY1G
	.word	SZGREY1G_SUB-sz_pieces,0
SZGREY1G_SUB
	.word SZGREY1G_IMG-sz_pieces
	.half 46, 36, -23, -142
	.word   VSZGRY_P

	.align 2
	include ..\attract\vs\vssz.psi

;**********************************************************************
vs_c5 group
	section	.vs_5

	;include palsrc\vsswat.mas

	.globl swat_pieces
swat_pieces
	.half	0x63,0x25+29,0x125,0x25+29
	.word copblue1a-swat_pieces,VCOPRED_P
	.word copblue1b-swat_pieces,VCOPRED_P
	.word copblue1c-swat_pieces,VCOPRED_P
	.word copflesh1a-swat_pieces,0
	.word copflesh1b-swat_pieces,0
	.word copflesh1c-swat_pieces,0
	.word copflesh1d-swat_pieces,0
	.word copgrey1a-swat_pieces,0
	.word copgrey1b-swat_pieces,0
	.word copgrey1c-swat_pieces,0
	.word copgrey1d-swat_pieces,0
	.word 0

copblue1a
	.word	COPBLUE1A-swat_pieces,0
copblue1b
	.word	COPBLUE1B-swat_pieces,0
copblue1c
	.word	COPBLUE1C-swat_pieces,0
copflesh1a
	.word	COPFLESH1A-swat_pieces,0
copflesh1b
	.word	COPFLESH1B-swat_pieces,0
copflesh1c
	.word	COPFLESH1C-swat_pieces,0
copflesh1d
	.word	COPFLESH1D-swat_pieces,0
copgrey1a
	.word	COPGREY1A-swat_pieces,0
copgrey1b
	.word	COPGREY1B-swat_pieces,0
copgrey1c
	.word	COPGREY1C-swat_pieces,0
copgrey1d
	.word	COPGREY1D-swat_pieces,0

COPBLUE1A
	.word	COPBLUE1A_SUB-swat_pieces,0
COPBLUE1A_SUB
	.word COPBLUE1A_IMG-swat_pieces
	.half 96, 72, 48, -66
	.word   VCOPBLU_P
COPBLUE1B
	.word	COPBLUE1B_SUB-swat_pieces,0
COPBLUE1B_SUB
	.word COPBLUE1B_IMG-swat_pieces
	.half 10, 9, 42, -150
	.word   VCOPBLU_P
COPBLUE1C
	.word	COPBLUE1C_SUB-swat_pieces,0
COPBLUE1C_SUB
	.word COPBLUE1C_IMG-swat_pieces
	.half 20, 14, 69, -171
	.word   VCOPBLU_P
COPFLESH1A
	.word	COPFLESH1A_SUB-swat_pieces,0
COPFLESH1A_SUB
	.word COPFLESH1A_IMG-swat_pieces
	.half 44, 39, -1, -31
	.word   VCOPSKN_P
COPFLESH1B
	.word	COPFLESH1B_SUB-swat_pieces,0
	.word   VCOPSKN_P
COPFLESH1B_SUB
	.word COPFLESH1B_IMG-swat_pieces
	.half 55, 35, 69, -97
	.word   VCOPSKN_P
COPFLESH1C
	.word	COPFLESH1C_SUB-swat_pieces,0
COPFLESH1C_SUB
	.word COPFLESH1C_IMG-swat_pieces
	.half 11, 16, 10, -127
	.word   VCOPSKN_P
COPFLESH1D
	.word	COPFLESH1D_SUB-swat_pieces,0
COPFLESH1D_SUB
	.word COPFLESH1D_IMG-swat_pieces
	.half 40, 60, -34, -111
	.word   VCOPSKN_P
COPGREY1A
	.word	COPGREY1A_SUB-swat_pieces,0
COPGREY1A_SUB
	.word COPGREY1A_IMG-swat_pieces
	.half 50, 33, 4, -13
	.word   VCOPGRY_P
COPGREY1B
	.word	COPGREY1B_SUB-swat_pieces,0
COPGREY1B_SUB
	.word COPGREY1B_IMG-swat_pieces
	.half 77, 134, 75, -50
	.word   VCOPGRY_P
COPGREY1C
	.word	COPGREY1C_SUB-swat_pieces,0
COPGREY1C_SUB
	.word COPGREY1C_IMG-swat_pieces
	.half 21, 31, -53, -139
	.word   VCOPGRY_P
COPGREY1D
	.word	COPGREY1D_SUB-swat_pieces,0
COPGREY1D_SUB
	.word COPGREY1D_IMG-swat_pieces
	.half 46, 133, -1, -51
	.word   VCOPGRY_P

	.align 2
	include ..\attract\vs\vsswat.psi

;**********************************************************************
vs_c6 group
	section	.vs_6

	;include palsrc\vslia.mas

	.globl lia_pieces
lia_pieces
	.half	0x5d,0x35+26,0x12a,0x35+26
	.word liaflesh1a-lia_pieces,0
	.word liaflesh1b-lia_pieces,0
	.word liaflesh1c-lia_pieces,0
	.word liaflesh1d-lia_pieces,0
	.word liaflesh1e-lia_pieces,0
	.word liagrey1a-lia_pieces,0
	.word liagrey1b-lia_pieces,0
	.word liagrey1c-lia_pieces,0
	.word liapurp1a-lia_pieces,VLIABLU_P
	.word liapurp1b-lia_pieces,VLIABLU_P
	.word 0

liaflesh1a
	.word	LIAFLESH1A-lia_pieces,0
liaflesh1b
	.word	LIAFLESH1B-lia_pieces,0
liaflesh1c
	.word	LIAFLESH1C-lia_pieces,0
liaflesh1d
	.word	LIAFLESH1D-lia_pieces,0
liaflesh1e
	.word	LIAFLESH1E-lia_pieces,0
liagrey1a
	.word	LIAGREY1A-lia_pieces,0
liagrey1b
	.word	LIAGREY1B-lia_pieces,0
liagrey1c
	.word	LIAGREY1C-lia_pieces,0
liapurp1a
	.word	LIAPURP1A-lia_pieces,0
liapurp1b
	.word	LIAPURP1B-lia_pieces,0

LIAFLESH1A
	.word	LIAFLESH1A_SUB-lia_pieces,0
LIAFLESH1A_SUB
	.word LIAFLESH1A_IMG-lia_pieces
	.half 33, 53, 67, -79
	.word   VLIASKN_P
LIAFLESH1B
	.word	LIAFLESH1B_SUB-lia_pieces,0
LIAFLESH1B_SUB
	.word LIAFLESH1B_IMG-lia_pieces
	.half 25, 72, 34, -61
	.word   VLIASKN_P
LIAFLESH1C
	.word	LIAFLESH1C_SUB-lia_pieces,0
LIAFLESH1C_SUB
	.word LIAFLESH1C_IMG-lia_pieces
	.half 26, 26, -60, -55
	.word   VLIASKN_P
LIAFLESH1D
	.word	LIAFLESH1D_SUB-lia_pieces,0
LIAFLESH1D_SUB
	.word LIAFLESH1D_IMG-lia_pieces
	.half 35, 51, -27, -81
	.word   VLIASKN_P
LIAFLESH1E
	.word	LIAFLESH1E_SUB-lia_pieces,0
LIAFLESH1E_SUB
	.word LIAFLESH1E_IMG-lia_pieces
	.half 35, 115, 10, -36
	.word   VLIASKN_P
LIAGREY1A
	.word	LIAGREY1A_SUB-lia_pieces,0
LIAGREY1A_SUB
	.word LIAGREY1A_IMG-lia_pieces
	.half 66, 166, 59, -8
	.word   VLIAGRY_P
LIAGREY1B
	.word	LIAGREY1B_SUB-lia_pieces,0
LIAGREY1B_SUB
	.word LIAGREY1B_IMG-lia_pieces
	.half 25, 39, -49, -75
	.word   VLIAGRY_P
LIAGREY1C
	.word	LIAGREY1C_SUB-lia_pieces,0
LIAGREY1C_SUB
	.word LIAGREY1C_IMG-lia_pieces
	.half 26, 166, -5, -8
	.word   VLIAGRY_P
LIAPURP1A
	.word	LIAPURP1A_SUB-lia_pieces,0
LIAPURP1A_SUB
	.word LIAPURP1A_IMG-lia_pieces
	.half 15, 42, 38, -95
	.word   VLIAPRP_P
LIAPURP1B
	.word	LIAPURP1B_SUB-lia_pieces,0
LIAPURP1B_SUB
	.word LIAPURP1B_IMG-lia_pieces
	.half 33, 77, 7, -97
	.word   VLIAPRP_P

	.align 2
	include ..\attract\vs\vslia.psi

;**********************************************************************
vs_c7 group
	section	.vs_7

	;include palsrc\vsrobo1.mas

	.globl robo1_pieces
robo1_pieces
	.half	0x55,0x35+0x1e,0x130,0x35+0x1e
	.word rb2grey1a-robo1_pieces,0
	.word rb2grey1b-robo1_pieces,0
	.word rb2grey1c-robo1_pieces,0
	.word rb2grey1d-robo1_pieces,0
	.word rb2grey1e-robo1_pieces,0
	.word rb2grey1f-robo1_pieces,0
	.word rb2red1a-robo1_pieces,VRBDRED_P
	.word rb2red1b-robo1_pieces,VRBDRED_P
	.word rb2red1c-robo1_pieces,VRBDRED_P
	.word rb2red1d-robo1_pieces,VRBDRED_P
	.word rb2red1e-robo1_pieces,VRBDRED_P
	.word rb2red1f-robo1_pieces,VRBDRED_P
	.word rb2red1g-robo1_pieces,VRBDRED_P
	.word 0

rb2grey1a
	.word	RB2GREY1A-robo1_pieces,0
rb2grey1b
	.word	RB2GREY1B-robo1_pieces,0
rb2grey1c
	.word	RB2GREY1C-robo1_pieces,0
rb2grey1d
	.word	RB2GREY1D-robo1_pieces,0
rb2grey1e
	.word	RB2GREY1E-robo1_pieces,0
rb2grey1f
	.word	RB2GREY1F-robo1_pieces,0
rb2red1a
	.word	RB2RED1A-robo1_pieces,0
rb2red1b
	.word	RB2RED1B-robo1_pieces,0
rb2red1c
	.word	RB2RED1C-robo1_pieces,0
rb2red1d
	.word	RB2RED1D-robo1_pieces,0
rb2red1e
	.word	RB2RED1E-robo1_pieces,0
rb2red1f
	.word	RB2RED1F-robo1_pieces,0
rb2red1g
	.word	RB2RED1G-robo1_pieces,0

RB2GREY1A
	.word	RB2GREY1A_SUB-robo1_pieces,0
RB2GREY1A_SUB
	.word RB2GREY1A_IMG-robo1_pieces
	.half 37, 43, 4, -133
	.word   VRB2GRY_P
RB2GREY1B
	.word	RB2GREY1B_SUB-robo1_pieces,0
RB2GREY1B_SUB
	.word RB2GREY1B_IMG-robo1_pieces
	.half 50, 66, 59, -50
	.word   VRB2GRY_P
RB2GREY1C
	.word	RB2GREY1C_SUB-robo1_pieces,0
RB2GREY1C_SUB
	.word RB2GREY1C_IMG-robo1_pieces
	.half 50, 60, 54, -116
	.word   VRB2GRY_P
RB2GREY1D
	.word	RB2GREY1D_SUB-robo1_pieces,0
RB2GREY1D_SUB
	.word RB2GREY1D_IMG-robo1_pieces
	.half 22, 52, -56, -70
	.word   VRB2GRY_P
RB2GREY1E
	.word	RB2GREY1E_SUB-robo1_pieces,0
RB2GREY1E_SUB
	.word RB2GREY1E_IMG-robo1_pieces
	.half 38, 51, -16, -84
	.word   VRB2GRY_P
RB2GREY1F
	.word	RB2GREY1F_SUB-robo1_pieces,0
RB2GREY1F_SUB
	.word RB2GREY1F_IMG-robo1_pieces
	.half 51, 82, 9, -7
	.word   VRB2GRY_P
RB2RED1A
	.word	RB2RED1A_SUB-robo1_pieces,0
RB2RED1A_SUB
	.word RB2RED1A_IMG-robo1_pieces
	.half 54, 36, 82, -38
	.word   VRB2RED_P
RB2RED1B
	.word	RB2RED1B_SUB-robo1_pieces,0
RB2RED1B_SUB
	.word RB2RED1B_IMG-robo1_pieces
	.half 12, 13, 42, -156
	.word   VRB2RED_P
RB2RED1C
	.word	RB2RED1C_SUB-robo1_pieces,0
RB2RED1C_SUB
	.word RB2RED1C_IMG-robo1_pieces
	.half 50, 101, 40, -41
	.word   VRB2RED_P
RB2RED1D
	.word	RB2RED1D_SUB-robo1_pieces,0
RB2RED1D_SUB
	.word RB2RED1D_IMG-robo1_pieces
	.half 10, 5, -9, -151
	.word   VRB2RED_P
RB2RED1E
	.word	RB2RED1E_SUB-robo1_pieces,0
RB2RED1E_SUB
	.word RB2RED1E_IMG-robo1_pieces
	.half 24, 21, 21, -155
	.word   VRB2RED_P
RB2RED1F
	.word	RB2RED1F_SUB-robo1_pieces,0
RB2RED1F_SUB
	.word RB2RED1F_IMG-robo1_pieces
	.half 19, 111, -9, -25
	.word   VRB2RED_P
RB2RED1G
	.word	RB2RED1G_SUB-robo1_pieces,0
RB2RED1G_SUB
	.word RB2RED1G_IMG-robo1_pieces
	.half 46, 103, -28, -42
	.word   VRB2RED_P

	.align 2
	include ..\attract\vs\vsrobo1.psi
;**********************************************************************
vs_c8 group
	section	.vs_8

	;include palsrc\vsrobo2.mas

	.globl robo2_pieces
robo2_pieces
	.half	0x5c,0x35+0x1f,0x128,0x35+0x1f
	.word rb1gold1a-robo2_pieces,VRBDYEL_P
	.word rb1gold1b-robo2_pieces,VRBDYEL_P
	.word rb1gold1c-robo2_pieces,VRBDYEL_P
	.word rb1gold1d-robo2_pieces,VRBDYEL_P
	.word rb1gold1e-robo2_pieces,VRBDYEL_P
	.word rb1grey1a-robo2_pieces,0
	.word rb1grey1b-robo2_pieces,0
	.word rb1grey1c-robo2_pieces,0
	.word rb1grey1d-robo2_pieces,0
	.word rb1grey1e-robo2_pieces,0
	.word rb1grey1f-robo2_pieces,0
	.word rb1grey1g-robo2_pieces,0
	.word 0

rb1gold1a
	.word	RB1GOLD1A-robo2_pieces,0
rb1gold1b
	.word	RB1GOLD1B-robo2_pieces,0
rb1gold1c
	.word	RB1GOLD1C-robo2_pieces,0
rb1gold1d
	.word	RB1GOLD1D-robo2_pieces,0
rb1gold1e
	.word	RB1GOLD1E-robo2_pieces,0

rb1grey1a
	.word	RB1GREY1A-robo2_pieces,0
rb1grey1b
	.word	RB1GREY1B-robo2_pieces,0
rb1grey1c
	.word	RB1GREY1C-robo2_pieces,0
rb1grey1d
	.word	RB1GREY1D-robo2_pieces,0
rb1grey1e
	.word	RB1GREY1E-robo2_pieces,0
rb1grey1f
	.word	RB1GREY1F-robo2_pieces,0
rb1grey1g
	.word	RB1GREY1G-robo2_pieces,0

RB1GREY1A
	.word	RB1GREY1A_SUB-robo2_pieces,0
RB1GREY1A_SUB
	.word RB1GREY1A_IMG-robo2_pieces
	.half 54, 43, 56, -1
	.word   VRB1GRY_P
RB1GREY1B
	.word	RB1GREY1B_SUB-robo2_pieces,0
RB1GREY1B_SUB
	.word RB1GREY1B_IMG-robo2_pieces
	.half 22, 27, 66, -47
	.word   VRB1GRY_P
RB1GREY1C
	.word	RB1GREY1C_SUB-robo2_pieces,0
RB1GREY1C_SUB
	.word RB1GREY1C_IMG-robo2_pieces
	.half 54, 125, 59, -44
	.word   VRB1GRY_P
RB1GREY1D
	.word	RB1GREY1D_SUB-robo2_pieces,0
RB1GREY1D_SUB
	.word RB1GREY1D_IMG-robo2_pieces
	.half 23, 27, 5, -142
	.word   VRB1GRY_P
RB1GREY1E
	.word	RB1GREY1E_SUB-robo2_pieces,0
RB1GREY1E_SUB
	.word RB1GREY1E_IMG-robo2_pieces
	.half 54, 82, -4, -1
	.word   VRB1GRY_P
RB1GREY1F
	.word	RB1GREY1F_SUB-robo2_pieces,0
RB1GREY1F_SUB
	.word RB1GREY1F_IMG-robo2_pieces
	.half 25, 41, -22, -87
	.word   VRB1GRY_P
RB1GREY1G
	.word	RB1GREY1G_SUB-robo2_pieces,0
RB1GREY1G_SUB
	.word RB1GREY1G_IMG-robo2_pieces
	.half 67, 65, -29, -88
	.word   VRB1GRY_P
RB1GOLD1A
	.word	RB1GOLD1A_SUB-robo2_pieces,0
RB1GOLD1A_SUB
	.word RB1GOLD1A_IMG-robo2_pieces
	.half 29, 48, 78, -25
	.word   VRB1YEL_P
RB1GOLD1B
	.word	RB1GOLD1B_SUB-robo2_pieces,0
RB1GOLD1B_SUB
	.word RB1GOLD1B_IMG-robo2_pieces
	.half 27, 33, 50, -42
	.word   VRB1YEL_P
RB1GOLD1C
	.word	RB1GOLD1C_SUB-robo2_pieces,0
RB1GOLD1C_SUB
	.word RB1GOLD1C_IMG-robo2_pieces
	.half 62, 16, 45, -153
	.word   VRB1YEL_P
RB1GOLD1D
	.word	RB1GOLD1D_SUB-robo2_pieces,0
RB1GOLD1D_SUB
	.word RB1GOLD1D_IMG-robo2_pieces
	.half 66, 111, 38, -36
	.word   VRB1YEL_P
RB1GOLD1E
	.word	RB1GOLD1E_SUB-robo2_pieces,0
RB1GOLD1E_SUB
	.word RB1GOLD1E_IMG-robo2_pieces
	.half 46, 139, -27, -23
	.word   VRB1YEL_P

	.align 2
	include ..\attract\vs\vsrobo2.psi

;**********************************************************************
vs_c14 group
	section	.vs_14

	;include palsrc\vsrobo3.mas

	.globl smoke_pieces
smoke_pieces
	.half	0x5c,0x35+0x1f,0x128,0x35+0x1f
	.word sm1gold1a-smoke_pieces,VSMOK2_P
	.word sm1gold1b-smoke_pieces,VSMOK2_P
	.word sm1gold1c-smoke_pieces,VSMOK2_P
	.word sm1gold1d-smoke_pieces,VSMOK2_P
	.word sm1gold1e-smoke_pieces,VSMOK2_P
	.word rb3grey1a-smoke_pieces,0
	.word rb3grey1b-smoke_pieces,0
	.word rb3grey1c-smoke_pieces,0
	.word rb3grey1d-smoke_pieces,0
	.word rb3grey1e-smoke_pieces,0
	.word rb3grey1f-smoke_pieces,0
	.word rb3grey1g-smoke_pieces,0
	.word 0

sm1gold1a
	.word	SM1GOLD1A-smoke_pieces,0
sm1gold1b
	.word	SM1GOLD1B-smoke_pieces,0
sm1gold1c
	.word	SM1GOLD1C-smoke_pieces,0
sm1gold1d
	.word	SM1GOLD1D-smoke_pieces,0
sm1gold1e
	.word	SM1GOLD1E-smoke_pieces,0
rb3grey1a
	.word	RB3GREY1A-smoke_pieces,0
rb3grey1b
	.word	RB3GREY1B-smoke_pieces,0
rb3grey1c
	.word	RB3GREY1C-smoke_pieces,0
rb3grey1d
	.word	RB3GREY1D-smoke_pieces,0
rb3grey1e
	.word	RB3GREY1E-smoke_pieces,0
rb3grey1f
	.word	RB3GREY1F-smoke_pieces,0
rb3grey1g
	.word	RB3GREY1G-smoke_pieces,0

SM1GOLD1A
	.word	SM1GOLD1A_SUB-smoke_pieces,0
SM1GOLD1A_SUB
	.word RB3GOLD1A_IMG-smoke_pieces
	.half 29, 48, 78, -25
	.word   VSMOK1_P
SM1GOLD1B
	.word	SM1GOLD1B_SUB-smoke_pieces,0
SM1GOLD1B_SUB
	.word RB3GOLD1B_IMG-smoke_pieces
	.half 27, 33, 50, -42
	.word   VSMOK1_P
SM1GOLD1C
	.word	SM1GOLD1C_SUB-smoke_pieces,0
SM1GOLD1C_SUB
	.word RB3GOLD1C_IMG-smoke_pieces
	.half 62, 16, 45, -153
	.word   VSMOK1_P
SM1GOLD1D
	.word	SM1GOLD1D_SUB-smoke_pieces,0
SM1GOLD1D_SUB
	.word RB3GOLD1D_IMG-smoke_pieces
	.half 66, 111, 38, -36
	.word   VSMOK1_P
SM1GOLD1E
	.word	SM1GOLD1E_SUB-smoke_pieces,0
SM1GOLD1E_SUB
	.word RB3GOLD1E_IMG-smoke_pieces
	.half 46, 139, -27, -23
	.word   VSMOK1_P

RB3GREY1A
	.word	RB3GREY1A_SUB-smoke_pieces,0
RB3GREY1A_SUB
	.word RB3GREY1A_IMG-smoke_pieces
	.half 54, 43, 56, -1
	.word   VRG3GRY_P
RB3GREY1B
	.word	RB3GREY1B_SUB-smoke_pieces,0
RB3GREY1B_SUB
	.word RB3GREY1B_IMG-smoke_pieces
	.half 22, 27, 66, -47
	.word   VRG3GRY_P
RB3GREY1C
	.word	RB3GREY1C_SUB-smoke_pieces,0
RB3GREY1C_SUB
	.word RB3GREY1C_IMG-smoke_pieces
	.half 54, 125, 59, -44
	.word   VRG3GRY_P
RB3GREY1D
	.word	RB3GREY1D_SUB-smoke_pieces,0
RB3GREY1D_SUB
	.word RB3GREY1D_IMG-smoke_pieces
	.half 23, 27, 5, -142
	.word   VRG3GRY_P
RB3GREY1E
	.word	RB3GREY1E_SUB-smoke_pieces,0
RB3GREY1E_SUB
	.word RB3GREY1E_IMG-smoke_pieces
	.half 54, 82, -4, -1
	.word   VRG3GRY_P
RB3GREY1F
	.word	RB3GREY1F_SUB-smoke_pieces,0
RB3GREY1F_SUB
	.word RB3GREY1F_IMG-smoke_pieces
	.half 25, 41, -22, -87
	.word   VRG3GRY_P
RB3GREY1G
	.word	RB3GREY1G_SUB-smoke_pieces,0
RB3GREY1G_SUB
	.word RB3GREY1G_IMG-smoke_pieces
	.half 67, 65, -29, -88
	.word   VRG3GRY_P

	.align 2
	include ..\attract\vs\vsrobo3.psi

;**********************************************************************
vs_c9 group
	section	.vs_9

;	include palsrc\vslao.mas

	.globl lao_pieces
lao_pieces
	.half	0x5c,0x35+15,0x128,0x35+15
	.word klflesh1a-lao_pieces,0
	.word klflesh1b-lao_pieces,0
	.word klflesh1c-lao_pieces,0
	.word klflesh1d-lao_pieces,0
	.word klflesh1e-lao_pieces,0
	.word klgrey1a-lao_pieces,0
	.word klgrey1b-lao_pieces,0
	.word klgrey1c-lao_pieces,0
	.word klgrey1d-lao_pieces,0
	.word klgrey1e-lao_pieces,0
	.word klgrey1f-lao_pieces,0
	.word klgrey1g-lao_pieces,0
	.word klpants1a-lao_pieces,VKLBLU_P
	.word klpants1b-lao_pieces,VKLBLU_P
	.word 0

klflesh1a
	.word	KLFLESH1A-lao_pieces,0

klflesh1b
	.word	KLFLESH1B-lao_pieces,0

klflesh1c
	.word	KLFLESH1C-lao_pieces,0

klflesh1d
	.word	KLFLESH1D-lao_pieces,0

klflesh1e
	.word	KLFLESH1E-lao_pieces,0

klgrey1a
	.word	KLGREY1A-lao_pieces,0

klgrey1b
	.word	KLGREY1B-lao_pieces,0

klgrey1c
	.word	KLGREY1C-lao_pieces,0

klgrey1d
	.word	KLGREY1D-lao_pieces,0

klgrey1e
	.word	KLGREY1E-lao_pieces,0

klgrey1f
	.word	KLGREY1F-lao_pieces,0

klgrey1g
	.word	KLGREY1G-lao_pieces,0

klpants1a
	.word	KLPANTS1A-lao_pieces,0

klpants1b
	.word	KLPANTS1B-lao_pieces,0


KLFLESH1A
	.word	KLFLESH1A_SUB-lao_pieces,0
KLFLESH1A_SUB
	.word KLFLESH1A_IMG-lao_pieces
	.half 66, 46, 84, -26
	.word VKLSKIN_P
KLFLESH1B
	.word	KLFLESH1B_SUB-lao_pieces,0
KLFLESH1B_SUB
	.word KLFLESH1B_IMG-lao_pieces
	.half 10, 87, 42, -72
	.word VKLSKIN_P
KLFLESH1C
	.word	KLFLESH1C_SUB-lao_pieces,0
KLFLESH1C_SUB
	.word KLFLESH1C_IMG-lao_pieces
	.half 51, 134, 31, -25
	.word VKLSKIN_P
KLFLESH1D
	.word	KLFLESH1D_SUB-lao_pieces,0
KLFLESH1D_SUB
	.word KLFLESH1D_IMG-lao_pieces
	.half 39, 116, -19, -25
	.word VKLSKIN_P
KLFLESH1E
	.word	KLFLESH1E_SUB-lao_pieces,0
KLFLESH1E_SUB
	.word KLFLESH1E_IMG-lao_pieces
	.half 33, 70, -58, -72
	.word VKLSKIN_P
KLGREY1A
	.word	KLGREY1A_SUB-lao_pieces,0
KLGREY1A_SUB
	.word KLGREY1A_IMG-lao_pieces
	.half 26, 20, 70, -27
	.word VKLGRAY_P
KLGREY1B
	.word	KLGREY1B_SUB-lao_pieces,0
KLGREY1B_SUB
	.word KLGREY1B_IMG-lao_pieces
	.half 47, 137, 42, -6
	.word VKLGRAY_P
KLGREY1C
	.word	KLGREY1C_SUB-lao_pieces,0
KLGREY1C_SUB
	.word KLGREY1C_IMG-lao_pieces
	.half 22, 34, -61, -94
	.word VKLGRAY_P
KLGREY1D
	.word	KLGREY1D_SUB-lao_pieces,0
KLGREY1D_SUB
	.word KLGREY1D_IMG-lao_pieces
	.half 27, 31, 0, -151
	.word VKLGRAY_P
KLGREY1E
	.word	KLGREY1E_SUB-lao_pieces,0
KLGREY1E_SUB
	.word KLGREY1E_IMG-lao_pieces
	.half 59, 83, -4, -1
	.word VKLGRAY_P
KLGREY1F
	.word	KLGREY1F_SUB-lao_pieces,0
KLGREY1F_SUB
	.word KLGREY1F_IMG-lao_pieces
	.half 18, 28, -4, -114
	.word VKLGRAY_P
KLGREY1G
	.word	KLGREY1G_SUB-lao_pieces,0
KLGREY1G_SUB
	.word KLGREY1G_IMG-lao_pieces
	.half 46, 40, 51, -143
	.word VKLGRAY_P
KLPANTS1A
	.word	KLPANTS1A_SUB-lao_pieces,0
KLPANTS1A_SUB
	.word KLPANTS1A_IMG-lao_pieces
	.half 9, 18, 37, -165
	.word VKLTAN_P
KLPANTS1B
	.word	KLPANTS1B_SUB-lao_pieces,0
KLPANTS1B_SUB
	.word KLPANTS1B_IMG-lao_pieces
	.half 32, 25, 6, -158
	.word VKLTAN_P

	.align 2
	include ..\attract\vs\vslao.psi

;**********************************************************************
vs_c10 group
	section	.vs_10

	;include palsrc\vstusk.mas

	.globl tusk_pieces
tusk_pieces
	.half	0x5c,0x35+19,0x128,0x35+19
	.word kbflesh1a-tusk_pieces,0
	.word kbflesh1b-tusk_pieces,0
	.word kbflesh1c-tusk_pieces,0
	.word kbflesh1d-tusk_pieces,0
	.word kbflesh1e-tusk_pieces,0
	.word kbgrvest1a-tusk_pieces,0
	.word kbgrvest1b-tusk_pieces,0
	.word kbgrvest1c-tusk_pieces,0
	.word kbgrvest1d-tusk_pieces,0
	.word kbgrvest1e-tusk_pieces,0
	.word kbpants1a-tusk_pieces,VKBBLU_P
	.word kbpants1b-tusk_pieces,VKBBLU_P
	.word 0

kbflesh1a
	.word	KBFLESH1A-tusk_pieces,0
kbflesh1b
	.word	KBFLESH1B-tusk_pieces,0
kbflesh1c
	.word	KBFLESH1C-tusk_pieces,0
kbflesh1d
	.word	KBFLESH1D-tusk_pieces,0
kbflesh1e
	.word	KBFLESH1E-tusk_pieces,0
kbgrvest1a
	.word	KBGRVEST1A-tusk_pieces,0
kbgrvest1b
	.word	KBGRVEST1B-tusk_pieces,0
kbgrvest1c
	.word	KBGRVEST1C-tusk_pieces,0
kbgrvest1d
	.word	KBGRVEST1D-tusk_pieces,0
kbgrvest1e
	.word	KBGRVEST1E-tusk_pieces,0
kbpants1a
	.word	KBPANTS1A-tusk_pieces,0
kbpants1b
	.word	KBPANTS1B-tusk_pieces,0

KBFLESH1A
	.word	KBFLESH1A_SUB-tusk_pieces,0
KBFLESH1A_SUB
	.word KBFLESH1A_IMG-tusk_pieces
	.half 26, 62, 78, -64
	.word   VKBSKIN_P
KBFLESH1B
	.word	KBFLESH1B_SUB-tusk_pieces,0
KBFLESH1B_SUB
	.word KBFLESH1B_IMG-tusk_pieces
	.half 26, 15, -7, -11
	.word   VKBSKIN_P
KBFLESH1C
	.word	KBFLESH1C_SUB-tusk_pieces,0
KBFLESH1C_SUB
	.word KBFLESH1C_IMG-tusk_pieces
	.half 6, 13, -29, -70
	.word   VKBSKIN_P
KBFLESH1D
	.word	KBFLESH1D_SUB-tusk_pieces,0
KBFLESH1D_SUB
	.word KBFLESH1D_IMG-tusk_pieces
	.half 47, 83, 19, -43
	.word   VKBSKIN_P
KBFLESH1E
	.word	KBFLESH1E_SUB-tusk_pieces,0
KBFLESH1E_SUB
	.word KBFLESH1E_IMG-tusk_pieces
	.half 41, 51, -45, -85
	.word   VKBSKIN_P
KBGRVEST1A
	.word	KBGRVEST1A_SUB-tusk_pieces,0
KBGRVEST1A_SUB
	.word KBGRVEST1A_IMG-tusk_pieces
	.half 21, 31, -68, -58
	.word   VKBGRAY_P
KBGRVEST1B
	.word	KBGRVEST1B_SUB-tusk_pieces,0
KBGRVEST1B_SUB
	.word KBGRVEST1B_IMG-tusk_pieces
	.half 44, 140, 70, -39
	.word   VKBGRAY_P
KBGRVEST1C
	.word	KBGRVEST1C_SUB-tusk_pieces,0
KBGRVEST1C_SUB
	.word KBGRVEST1C_IMG-tusk_pieces
	.half 38, 169, 8, -10
	.word   VKBGRAY_P
KBGRVEST1D
	.word	KBGRVEST1D_SUB-tusk_pieces,0
KBGRVEST1D_SUB
	.word KBGRVEST1D_IMG-tusk_pieces
	.half 18, 152, 26, -27
	.word   VKBGRAY_P
KBGRVEST1E
	.word	KBGRVEST1E_SUB-tusk_pieces,0
KBGRVEST1E_SUB
	.word KBGRVEST1E_IMG-tusk_pieces
	.half 33, 122, -29, -15
	.word   VKBGRAY_P
KBPANTS1A
	.word	KBPANTS1A_SUB-tusk_pieces,0
KBPANTS1A_SUB
	.word KBPANTS1A_IMG-tusk_pieces
	.half 19, 11, 72, -168
	.word   VKBTAN_P
KBPANTS1B
	.word	KBPANTS1B_SUB-tusk_pieces,0
KBPANTS1B_SUB
	.word KBPANTS1B_IMG-tusk_pieces
	.half 30, 27, 41, -152
	.word   VKBTAN_P

	.align 2
	include ..\attract\vs\vstusk.psi

;**********************************************************************
vs_c11 group
	section	.vs_11

	;include palsrc\vssg.mas

	.globl sg_pieces
sg_pieces
	.half	0x5c,0x33+18,0x128,0x33+18
	.word shflesh1a-sg_pieces,0
	.word shflesh1b-sg_pieces,0
	.word shflesh1c-sg_pieces,0
	.word shflesh1d-sg_pieces,0
	.word shflesh1e-sg_pieces,0
	.word shflesh1f-sg_pieces,0
	.word shflesh1g-sg_pieces,0
	.word shflesh1h-sg_pieces,0
	.word shflesh1i-sg_pieces,0
	.word shgrey1a-sg_pieces,0
	.word shgrey1b-sg_pieces,0
	.word shgrey1c-sg_pieces,0
	.word shgrey1d-sg_pieces,0
	.word shgrey1e-sg_pieces,0
	.word shgrey1f-sg_pieces,0
	.word shgrey1g-sg_pieces,0
	.word shred1a-sg_pieces,VSHBLU_P
	.word shred1b-sg_pieces,VSHBLU_P
	.word shred1c-sg_pieces,VSHBLU_P
	.word shred1d-sg_pieces,VSHBLU_P
	.word	0

shflesh1a
	.word	SHFLESH1A-sg_pieces,0
shflesh1b
	.word	SHFLESH1B-sg_pieces,0
shflesh1c
	.word	SHFLESH1C-sg_pieces,0
shflesh1d
	.word	SHFLESH1D-sg_pieces,0
shflesh1e
	.word	SHFLESH1E-sg_pieces,0
shflesh1f
	.word	SHFLESH1F-sg_pieces,0
shflesh1g
	.word	SHFLESH1G-sg_pieces,0
shflesh1h
	.word	SHFLESH1H-sg_pieces,0
shflesh1i
	.word	SHFLESH1I-sg_pieces,0
shgrey1a
	.word	SHGREY1A-sg_pieces,0
shgrey1b
	.word	SHGREY1B-sg_pieces,0
shgrey1c
	.word	SHGREY1C-sg_pieces,0
shgrey1d
	.word	SHGREY1D-sg_pieces,0
shgrey1e
	.word	SHGREY1E-sg_pieces,0
shgrey1f
	.word	SHGREY1F-sg_pieces,0
shgrey1g
	.word	SHGREY1G-sg_pieces,0
shred1a
	.word	SHRED1A-sg_pieces,0
shred1b
	.word	SHRED1B-sg_pieces,0
shred1c
	.word	SHRED1C-sg_pieces,0
shred1d
	.word	SHRED1D-sg_pieces,0

SHFLESH1A
	.word	SHFLESH1A_SUB-sg_pieces,0
SHFLESH1A_SUB
	.word SHFLESH1A_IMG-sg_pieces
	.half 17, 27, 21, -155
	.word   VSHESKIN_
SHFLESH1B
	.word	SHFLESH1B_SUB-sg_pieces,0
SHFLESH1B_SUB
	.word SHFLESH1B_IMG-sg_pieces
	.half 41, 43, 71, -139
	.word   VSHESKIN_
SHFLESH1C
	.word	SHFLESH1C_SUB-sg_pieces,0
SHFLESH1C_SUB
	.word SHFLESH1C_IMG-sg_pieces
	.half 41, 65, -5, -13
	.word   VSHESKIN_
SHFLESH1D
	.word	SHFLESH1D_SUB-sg_pieces,0
SHFLESH1D_SUB
	.word SHFLESH1D_IMG-sg_pieces
	.half 21, 41, 64, -8
	.word   VSHESKIN_
SHFLESH1E
	.word	SHFLESH1E_SUB-sg_pieces,0
SHFLESH1E_SUB
	.word SHFLESH1E_IMG-sg_pieces
	.half 62, 85, 82, -62
	.word   VSHESKIN_
SHFLESH1F
	.word	SHFLESH1F_SUB-sg_pieces,0
SHFLESH1F_SUB
	.word SHFLESH1F_IMG-sg_pieces
	.half 40, 96, -3, -77
	.word   VSHESKIN_
SHFLESH1G
	.word	SHFLESH1G_SUB-sg_pieces,0
SHFLESH1G_SUB
	.word SHFLESH1G_IMG-sg_pieces
	.half 40, 85, -43, -93
	.word   VSHESKIN_
SHFLESH1H
	.word	SHFLESH1H_SUB-sg_pieces,0
SHFLESH1H_SUB
	.word SHFLESH1H_IMG-sg_pieces
	.half 38, 88, 43, -15
	.word   VSHESKIN_
SHFLESH1I
	.word	SHFLESH1I_SUB-sg_pieces,0
SHFLESH1I_SUB
	.word SHFLESH1I_IMG-sg_pieces
	.half 26, 105, 21, -44
	.word   VSHESKIN_
SHGREY1A
	.word	SHGREY1A_SUB-sg_pieces,0
SHGREY1A_SUB
	.word SHGREY1A_IMG-sg_pieces
	.half 18, 20, 54, -10
	.word   VSHEGRY_P
SHGREY1B
	.word	SHGREY1B_SUB-sg_pieces,0
SHGREY1B_SUB
	.word SHGREY1B_IMG-sg_pieces
	.half 21, 20, 82, -72
	.word   VSHEGRY_P
SHGREY1C
	.word	SHGREY1C_SUB-sg_pieces,0
SHGREY1C_SUB
	.word SHGREY1C_IMG-sg_pieces
	.half 10, 14, 37, -59
	.word   VSHEGRY_P
SHGREY1D
	.word	SHGREY1D_SUB-sg_pieces,0
SHGREY1D_SUB
	.word SHGREY1D_IMG-sg_pieces
	.half 58, 57, 17, 2
	.word   VSHEGRY_P
SHGREY1E
	.word	SHGREY1E_SUB-sg_pieces,0
SHGREY1E_SUB
	.word SHGREY1E_IMG-sg_pieces
	.half 38, 23, 48, -134
	.word   VSHEGRY_P
SHGREY1F
	.word	SHGREY1F_SUB-sg_pieces,0
SHGREY1F_SUB
	.word SHGREY1F_IMG-sg_pieces
	.half 18, 17, -31, -161
	.word   VSHEGRY_P
SHGREY1G
	.word	SHGREY1G_SUB-sg_pieces,0
SHGREY1G_SUB
	.word SHGREY1G_IMG-sg_pieces
	.half 14, 27, -69, -121
	.word   VSHEGRY_P
SHRED1A
	.word	SHRED1A_SUB-sg_pieces,0
SHRED1A_SUB
	.word SHRED1A_IMG-sg_pieces
	.half 18, 32, 32, -150
	.word   VSHRED_P
SHRED1B
	.word	SHRED1B_SUB-sg_pieces,0
SHRED1B_SUB
	.word SHRED1B_IMG-sg_pieces
	.half 26, 61, -5, -76
	.word   VSHRED_P
SHRED1C
	.word	SHRED1C_SUB-sg_pieces,0
SHRED1C_SUB
	.word SHRED1C_IMG-sg_pieces
	.half 22, 21, 16, -135
	.word   VSHRED_P
SHRED1D
	.word	SHRED1D_SUB-sg_pieces,0
SHRED1D_SUB
	.word SHRED1D_IMG-sg_pieces
	.half 44, 94, 30, -52
	.word   VSHRED_P

	.align 2
	include ..\attract\vs\vssg.psi

;**********************************************************************
vs_c12 group
	section	.vs_12

	;include palsrc\vslk.mas

	.globl lk_pieces
lk_pieces
	.half	0x60,0x35+31,0x12c,0x35+31
	.word lkflesh1a-lk_pieces,0
	.word lkflesh1b-lk_pieces,0
	.word lkflesh1c-lk_pieces,0
	.word lkflesh1d-lk_pieces,0
	.word lkflesh1e-lk_pieces,0
	.word lkgrey1a-lk_pieces,0
	.word lkgrey1b-lk_pieces,0
	.word lkgrey1c-lk_pieces,0
	.word lkgrey1d-lk_pieces,0
	.word lkgrey1e-lk_pieces,0
	.word lkred1a-lk_pieces,VLKYEL_P
	.word lkred1b-lk_pieces,VLKYEL_P
	.word lkred1c-lk_pieces,VLKYEL_P
	.word 0

lkflesh1a
	.word	LKFLESH1A-lk_pieces,0
lkflesh1b
	.word	LKFLESH1B-lk_pieces,0
lkflesh1c
	.word	LKFLESH1C-lk_pieces,0
lkflesh1d
	.word	LKFLESH1D-lk_pieces,0
lkflesh1e
	.word	LKFLESH1E-lk_pieces,0
lkgrey1a
	.word	LKGREY1A-lk_pieces,0
lkgrey1b
	.word	LKGREY1B-lk_pieces,0
lkgrey1c
	.word	LKGREY1C-lk_pieces,0
lkgrey1d
	.word	LKGREY1D-lk_pieces,0
lkgrey1e
	.word	LKGREY1E-lk_pieces,0
lkred1a
	.word	LKRED1A-lk_pieces,0
lkred1b
	.word	LKRED1B-lk_pieces,0
lkred1c
	.word	LKRED1C-lk_pieces,0

LKFLESH1A
	.word	LKFLESH1A_SUB-lk_pieces,0
LKFLESH1A_SUB
	.word LKFLESH1A_IMG-lk_pieces
	.half 28, 73, 73, -66
	.word   VLKSKIN_P
LKFLESH1B
	.word	LKFLESH1B_SUB-lk_pieces,0
LKFLESH1B_SUB
	.word LKFLESH1B_IMG-lk_pieces
	.half 35, 98, 45, -57
	.word   VLKSKIN_P
LKFLESH1C
	.word	LKFLESH1C_SUB-lk_pieces,0
LKFLESH1C_SUB
	.word LKFLESH1C_IMG-lk_pieces
	.half 15, 26, -65, -79
	.word   VLKSKIN_P
LKFLESH1D
	.word	LKFLESH1D_SUB-lk_pieces,0
LKFLESH1D_SUB
	.word LKFLESH1D_IMG-lk_pieces
	.half 38, 78, -28, -76
	.word   VLKSKIN_P
LKFLESH1E
	.word	LKFLESH1E_SUB-lk_pieces,0
LKFLESH1E_SUB
	.word LKFLESH1E_IMG-lk_pieces
	.half 38, 124, 10, -28
	.word   VLKSKIN_P
LKGREY1A
	.word	LKGREY1A_SUB-lk_pieces,0
LKGREY1A_SUB
	.word LKGREY1A_IMG-lk_pieces
	.half 28, 80, 18, 0
	.word   VLKGRAY_P
LKGREY1B
	.word	LKGREY1B_SUB-lk_pieces,0
LKGREY1B_SUB
	.word LKGREY1B_IMG-lk_pieces
	.half 18, 67, -9, 0
	.word   VLKGRAY_P
LKGREY1C
	.word	LKGREY1C_SUB-lk_pieces,0
LKGREY1C_SUB
	.word LKGREY1C_IMG-lk_pieces
	.half 22, 36, -54, -98
	.word   VLKGRAY_P
LKGREY1D
	.word	LKGREY1D_SUB-lk_pieces,0
LKGREY1D_SUB
	.word LKGREY1D_IMG-lk_pieces
	.half 51, 48, 56, -121
	.word   VLKGRAY_P
LKGREY1E
	.word	LKGREY1E_SUB-lk_pieces,0
LKGREY1E_SUB
	.word LKGREY1E_IMG-lk_pieces
	.half 11, 18, 5, -152
	.word   VLKGRAY_P
LKRED1A
	.word	LKRED1A_SUB-lk_pieces,0
LKRED1A_SUB
	.word LKRED1A_IMG-lk_pieces
	.half 53, 56, 24, -19
	.word   VLKRED_P
LKRED1B
	.word	LKRED1B_SUB-lk_pieces,0
LKRED1B_SUB
	.word LKRED1B_IMG-lk_pieces
	.half 17, 27, 58, -143
	.word   VLKRED_P
LKRED1C
	.word	LKRED1C_SUB-lk_pieces,0
LKRED1C_SUB
	.word LKRED1C_IMG-lk_pieces
	.half 51, 23, 38, -147
	.word   VLKRED_P

	.align 2
	include ..\attract\vs\vslkang.psi
;**********************************************************************
vs_c13 group
	section	.vs_13

	;include palsrc\vsst.mas

	.globl st_pieces
st_pieces
	.half	0x58,0x35+30,0x135,0x35+30
TSFLESH1
	.word tsflesh1a-st_pieces,0
	.word tsflesh1b-st_pieces,0
	.word tsflesh1c-st_pieces,0
	.word tsflesh1d-st_pieces,0
	.word tsflesh1e-st_pieces,0
	.word tsgrey1a-st_pieces,0
	.word tsgrey1b-st_pieces,0
	.word tsgrey1c-st_pieces,0
	.word tsgrey1d-st_pieces,0
	.word tsgrey1e-st_pieces,0
	.word tspant1a-st_pieces,VTSRED_P
	.word tspant1b-st_pieces,VTSRED_P
	.word 0

tsflesh1a
	.word	TSFLESH1A-st_pieces,0
tsflesh1b
	.word	TSFLESH1B-st_pieces,0
tsflesh1c
	.word	TSFLESH1C-st_pieces,0
tsflesh1d
	.word	TSFLESH1D-st_pieces,0
tsflesh1e
	.word	TSFLESH1E-st_pieces,0
tsgrey1a
	.word	TSGREY1A-st_pieces,0
tsgrey1b
	.word	TSGREY1B-st_pieces,0
tsgrey1c
	.word	TSGREY1C-st_pieces,0
tsgrey1d
	.word	TSGREY1D-st_pieces,0
tsgrey1e
	.word	TSGREY1E-st_pieces,0
tspant1a
	.word	TSPANT1A-st_pieces,0
tspant1b
	.word	TSPANT1B-st_pieces,0

TSFLESH1A
	.word	TSFLESH1A_SUB-st_pieces,0
TSFLESH1A_SUB
	.word TSFLESH1A_IMG-st_pieces
	.half 18, 49, 13, -93
	.word   VTSKIN_P
TSFLESH1B
	.word	TSFLESH1B_SUB-st_pieces,0
TSFLESH1B_SUB
	.word TSFLESH1B_IMG-st_pieces
	.half 63, 142, 64, -7
	.word   VTSKIN_P
TSFLESH1C
	.word	TSFLESH1C_SUB-st_pieces,0
TSFLESH1C_SUB
	.word TSFLESH1C_IMG-st_pieces
	.half 6, 14, -4, -94
	.word   VTSKIN_P
TSFLESH1D
	.word	TSFLESH1D_SUB-st_pieces,0
TSFLESH1D_SUB
	.word TSFLESH1D_IMG-st_pieces
	.half 31, 105, -3, -47
	.word   VTSKIN_P
TSFLESH1E
	.word	TSFLESH1E_SUB-st_pieces,0
TSFLESH1E_SUB
	.word TSFLESH1E_IMG-st_pieces
	.half 59, 119, -34, -51
	.word   VTSKIN_P
TSGREY1A
	.word	TSGREY1A_SUB-st_pieces,0
TSGREY1A_SUB
	.word TSGREY1A_IMG-st_pieces
	.half 18, 18, 44, -5
	.word   VTSGRY_P
TSGREY1B
	.word	TSGREY1B_SUB-st_pieces,0
TSGREY1B_SUB
	.word TSGREY1B_IMG-st_pieces
	.half 18, 24, -60, -124
	.word   VTSGRY_P
TSGREY1C
	.word	TSGREY1C_SUB-st_pieces,0
TSGREY1C_SUB
	.word TSGREY1C_IMG-st_pieces
	.half 60, 147, 43, -23
	.word   VTSGRY_P
TSGREY1D
	.word	TSGREY1D_SUB-st_pieces,0
TSGREY1D_SUB
	.word TSGREY1D_IMG-st_pieces
	.half 42, 105, -16, -16
	.word   VTSGRY_P
TSGREY1E
	.word	TSGREY1E_SUB-st_pieces,0
TSGREY1E_SUB
	.word TSGREY1E_IMG-st_pieces
	.half 10, 19, -16, -149
	.word   VTSGRY_P
TSPANT1A
	.word	TSPANT1A_SUB-st_pieces,0
TSPANT1A_SUB
	.word TSPANT1A_IMG-st_pieces
	.half 18, 15, 39, -155
	.word   VTSYEL_P
TSPANT1B
	.word	TSPANT1B_SUB-st_pieces,0
TSPANT1B_SUB
	.word TSPANT1B_IMG-st_pieces
	.half 17, 13, -13, -157
	.word   VTSYEL_P

	.align 2
	include ..\attract\vs\vsst.psi

;**********************************************************************
vs_c15 group
	section	.vs_15

	;include palsrc\vskit.mas

	.globl kitana_pieces
kitana_pieces
	.half	0x5d,0x3d+30,0x135,0x3d+30
	.word 	kitgray1a-kitana_pieces,0
	.word 	kitgray1b-kitana_pieces,0
	.word 	kitgray1c-kitana_pieces,0
	.word 	kitflesh1a-kitana_pieces,0
	.word 	kitflesh1b-kitana_pieces,0
	.word 	kitflesh1c-kitana_pieces,0
	.word 	kitflesh1d-kitana_pieces,0
	.word 	kitflesh1e-kitana_pieces,0
	.word 	kitflesh1f-kitana_pieces,0
	.word 	kitflesh1g-kitana_pieces,0
	.word 	kitblue1a-kitana_pieces,KTBLUE1_P
	.word 	kitblue1b-kitana_pieces,KTBLUE1_P
	.word 	kitblue1c-kitana_pieces,KTBLUE1_P
	.word 	kitblue1d-kitana_pieces,KTBLUE1_P
	.word 	kitblue1e-kitana_pieces,KTBLUE1_P
	.word	0


kitgray1a
	.word	KITGRAY1A-kitana_pieces,0

kitgray1b
	.word	KITGRAY1B-kitana_pieces,0

kitgray1c
	.word	KITGRAY1C-kitana_pieces,0

kitflesh1a
	.word	KITFLESH1A-kitana_pieces,0

kitflesh1b
	.word	KITFLESH1B-kitana_pieces,0

kitflesh1c
	.word	KITFLESH1C-kitana_pieces,0

kitflesh1d
	.word	KITFLESH1D-kitana_pieces,0

kitflesh1e
	.word	KITFLESH1E-kitana_pieces,0

kitflesh1f
	.word	KITFLESH1F-kitana_pieces,0

kitflesh1g
	.word	KITFLESH1G-kitana_pieces,0

kitblue1a
	.word	KITBLUE1A-kitana_pieces,0

kitblue1b
	.word	KITBLUE1B-kitana_pieces,0

kitblue1c
	.word	KITBLUE1C-kitana_pieces,0

kitblue1d
	.word	KITBLUE1D-kitana_pieces,0

kitblue1e
	.word	KITBLUE1E-kitana_pieces,0


KITGRAY1A
	.word	KITGRAY1A_SUB-kitana_pieces,0
KITGRAY1A_SUB
	.word KITGRAY1A_IMG-kitana_pieces
	.half 86, 141, 92, -22
	.word   KTGRAY_P
KITGRAY1B
	.word	KITGRAY1B_SUB-kitana_pieces,0
KITGRAY1B_SUB
	.word KITGRAY1B_IMG-kitana_pieces
	.half 15, 139, 6, -24
	.word   KTGRAY_P
KITGRAY1C
	.word	KITGRAY1C_SUB-kitana_pieces,0
KITGRAY1C_SUB
	.word KITGRAY1C_IMG-kitana_pieces
	.half 42, 164, -9, 0
	.word   KTGRAY_P
KITFLESH1A
	.word	KITFLESH1A_SUB-kitana_pieces,0
KITFLESH1A_SUB
	.word KITFLESH1A_IMG-kitana_pieces
	.half 18, 20, 55, -25
	.word   KTFLESH_P
KITFLESH1B
	.word	KITFLESH1B_SUB-kitana_pieces,0
KITFLESH1B_SUB
	.word KITFLESH1B_IMG-kitana_pieces
	.half 22, 23, 37, -22
	.word   KTFLESH_P
KITFLESH1C
	.word	KITFLESH1C_SUB-kitana_pieces,0
KITFLESH1C_SUB
	.word KITFLESH1C_IMG-kitana_pieces
	.half 26, 22, 12, -33
	.word   KTFLESH_P
KITFLESH1D
	.word	KITFLESH1D_SUB-kitana_pieces,0
KITFLESH1D_SUB
	.word KITFLESH1D_IMG-kitana_pieces
	.half 26, 26, 36, -137
	.word   KTFLESH_P
KITFLESH1E
	.word	KITFLESH1E_SUB-kitana_pieces,0
KITFLESH1E_SUB
	.word KITFLESH1E_IMG-kitana_pieces
	.half 27, 71, -25, -65
	.word   KTFLESH_P
KITFLESH1F
	.word	KITFLESH1F_SUB-kitana_pieces,0
KITFLESH1F_SUB
	.word KITFLESH1F_IMG-kitana_pieces
	.half 34, 50, -18, -9
	.word   KTFLESH_P
KITFLESH1G
	.word	KITFLESH1G_SUB-kitana_pieces,0
KITFLESH1G_SUB
	.word KITFLESH1G_IMG-kitana_pieces
	.half 26, 89, -3, -74
	.word   KTFLESH_P
KITBLUE1A
	.word	KITBLUE1A_SUB-kitana_pieces,0
KITBLUE1A_SUB
	.word KITBLUE1A_IMG-kitana_pieces
	.half 39, 9, 28, -19
	.word   KTBLUE1_P
KITBLUE1B
	.word	KITBLUE1B_SUB-kitana_pieces,0
KITBLUE1B_SUB
	.word KITBLUE1B_IMG-kitana_pieces
	.half 33, 51, 22, -93
	.word   KTBLUE1_P
KITBLUE1C
	.word	KITBLUE1C_SUB-kitana_pieces,0
KITBLUE1C_SUB
	.word KITBLUE1C_IMG-kitana_pieces
	.half 7, 8, -8, -53
	.word   KTBLUE1_P
KITBLUE1D
	.word	KITBLUE1D_SUB-kitana_pieces,0
KITBLUE1D_SUB
	.word KITBLUE1D_IMG-kitana_pieces
	.half 11, 47, -26, -61
	.word   KTBLUE1_P
KITBLUE1E
	.word	KITBLUE1E_SUB-kitana_pieces,0
KITBLUE1E_SUB
	.word KITBLUE1E_IMG-kitana_pieces
	.half 33, 24, -18, -35
	.word   KTBLUE1_P


	.align 2
	include ..\attract\vs\vskit.psi

;**********************************************************************
vs_c16 group
	section	.vs_16

	;include palsrc\vsjade.mas

	.globl jade_pieces
jade_pieces
	.half	0x5d,0x3d+30,0x135,0x3d+30
	.word jadfgray1a-jade_pieces,0
	.word jadfgray1b-jade_pieces,0
	.word jadfgray1c-jade_pieces,0
	.word jadfgray1d-jade_pieces,0
	.word jadfgray1e-jade_pieces,0
	.word jadfgray1f-jade_pieces,0
	.word jadfgray1g-jade_pieces,0
	.word jadflesh1a-jade_pieces,0
	.word jadflesh1b-jade_pieces,0
	.word jadflesh1c-jade_pieces,0
	.word jadflesh1d-jade_pieces,0
	.word jadflesh1e-jade_pieces,0
	.word jadflesh1f-jade_pieces,0
	.word jadflesh1g-jade_pieces,0
	.word jadflesh1h-jade_pieces,0
	.word jadflesh1i-jade_pieces,0
	.word jadgreen1a-jade_pieces,JDGRN1_P
	.word jadgreen1b-jade_pieces,JDGRN1_P
	.word jadgreen1c-jade_pieces,JDGRN1_P
	.word jadgreen1d-jade_pieces,JDGRN1_P
	.word jadgreen1e-jade_pieces,JDGRN1_P
	.word jadgreen1f-jade_pieces,JDGRN1_P
	.word 0

jadfgray1a
	.word JADFGRAY1A-jade_pieces,0

jadfgray1b
	.word JADFGRAY1B-jade_pieces,0

jadfgray1c
	.word JADFGRAY1C-jade_pieces,0

jadfgray1d
	.word JADFGRAY1D-jade_pieces,0

jadfgray1e
	.word JADFGRAY1E-jade_pieces,0

jadfgray1f
	.word JADFGRAY1F-jade_pieces,0

jadfgray1g
	.word JADFGRAY1G-jade_pieces,0

jadflesh1a
	.word JADFLESH1A-jade_pieces,0

jadflesh1b
	.word JADFLESH1B-jade_pieces,0

jadflesh1c
	.word JADFLESH1C-jade_pieces,0

jadflesh1d
	.word JADFLESH1D-jade_pieces,0

jadflesh1e
	.word JADFLESH1E-jade_pieces,0

jadflesh1f
	.word JADFLESH1F-jade_pieces,0

jadflesh1g
	.word JADFLESH1G-jade_pieces,0

jadflesh1h
	.word JADFLESH1H-jade_pieces,0

jadflesh1i
	.word JADFLESH1I-jade_pieces,0

jadgreen1a
	.word JADGREEN1A-jade_pieces,0

jadgreen1b
	.word JADGREEN1B-jade_pieces,0

jadgreen1c
	.word JADGREEN1C-jade_pieces,0

jadgreen1d
	.word JADGREEN1D-jade_pieces,0

jadgreen1e
	.word JADGREEN1E-jade_pieces,0

jadgreen1f
	.word JADGREEN1F-jade_pieces,0

JADFGRAY1A
	.word	JADFGRAY1A_SUB-jade_pieces,0
JADFGRAY1A_SUB
	.word JADFGRAY1A_IMG-jade_pieces
	.half 61, 34, 60, -19
	.word   JDGRAY_P
JADFGRAY1B
	.word	JADFGRAY1B_SUB-jade_pieces,0
JADFGRAY1B_SUB
	.word JADFGRAY1B_IMG-jade_pieces
	.half 27, 54, 36, -110
	.word   JDGRAY_P
JADFGRAY1C
	.word	JADFGRAY1C_SUB-jade_pieces,0
JADFGRAY1C_SUB
	.word JADFGRAY1C_IMG-jade_pieces
	.half 22, 94, 9, -71
	.word   JDGRAY_P
JADFGRAY1D
	.word	JADFGRAY1D_SUB-jade_pieces,0
JADFGRAY1D_SUB
	.word JADFGRAY1D_IMG-jade_pieces
	.half 18, 17, -32, -105
	.word   JDGRAY_P
JADFGRAY1E
	.word	JADFGRAY1E_SUB-jade_pieces,0
JADFGRAY1E_SUB
	.word JADFGRAY1E_IMG-jade_pieces
	.half 35, 54, -49, -97
	.word   JDGRAY_P
JADFGRAY1F
	.word	JADFGRAY1F_SUB-jade_pieces,0
JADFGRAY1F_SUB
	.word JADFGRAY1F_IMG-jade_pieces
	.half 15, 3, -28, -28
	.word   JDGRAY_P
JADFGRAY1G
	.word	JADFGRAY1G_SUB-jade_pieces,0
JADFGRAY1G_SUB
	.word JADFGRAY1G_IMG-jade_pieces
	.half 41, 146, -2, 0
	.word   JDGRAY_P
JADFLESH1A
	.word	JADFLESH1A_SUB-jade_pieces,0
JADFLESH1A_SUB
	.word JADFLESH1A_IMG-jade_pieces
	.half 15, 22, 68, -22
	.word   JDFLESH_P
JADFLESH1B
	.word	JADFLESH1B_SUB-jade_pieces,0
JADFLESH1B_SUB
	.word JADFLESH1B_IMG-jade_pieces
	.half 22, 31, 53, -19
	.word   JDFLESH_P
JADFLESH1C
	.word	JADFLESH1C_SUB-jade_pieces,0
JADFLESH1C_SUB
	.word JADFLESH1C_IMG-jade_pieces
	.half 32, 40, 25, -35
	.word   JDFLESH_P
JADFLESH1D
	.word	JADFLESH1D_SUB-jade_pieces,0
JADFLESH1D_SUB
	.word JADFLESH1D_IMG-jade_pieces
	.half 30, 32, 47, -132
	.word   JDFLESH_P
JADFLESH1E
	.word	JADFLESH1E_SUB-jade_pieces,0
JADFLESH1E_SUB
	.word JADFLESH1E_IMG-jade_pieces
	.half 11, 20, -2, -145
	.word   JDFLESH_P
JADFLESH1F
	.word	JADFLESH1F_SUB-jade_pieces,0
JADFLESH1F_SUB
	.word JADFLESH1F_IMG-jade_pieces
	.half 34, 45, -9, -10
	.word   JDFLESH_P
JADFLESH1G
	.word	JADFLESH1G_SUB-jade_pieces,0
JADFLESH1G_SUB
	.word JADFLESH1G_IMG-jade_pieces
	.half 19, 44, -27, -65
	.word   JDFLESH_P
JADFLESH1H
	.word	JADFLESH1H_SUB-jade_pieces,0
JADFLESH1H_SUB
	.word JADFLESH1H_IMG-jade_pieces
	.half 26, 32, -35, -119
	.word   JDFLESH_P
JADFLESH1I
	.word	JADFLESH1I_SUB-jade_pieces,0
JADFLESH1I_SUB
	.word JADFLESH1I_IMG-jade_pieces
	.half 23, 64, 1, -69
	.word   JDFLESH_P
JADGREEN1A
	.word	JADGREEN1A_SUB-jade_pieces,0
JADGREEN1A_SUB
	.word JADGREEN1A_IMG-jade_pieces
	.half 39, 7, 45, -17
	.word   JDGRN1_P
JADGREEN1B
	.word	JADGREEN1B_SUB-jade_pieces,0
JADGREEN1B_SUB
	.word JADGREEN1B_IMG-jade_pieces
	.half 32, 26, -12, -30
	.word   JDGRN1_P
JADGREEN1C
	.word	JADGREEN1C_SUB-jade_pieces,0
JADGREEN1C_SUB
	.word JADGREEN1C_IMG-jade_pieces
	.half 7, 15, -59, -122
	.word   JDGRN1_P
JADGREEN1D
	.word	JADGREEN1D_SUB-jade_pieces,0
JADGREEN1D_SUB
	.word JADGREEN1D_IMG-jade_pieces
	.half 25, 65, -10, -70
	.word   JDGRN1_P
JADGREEN1E
	.word	JADGREEN1E_SUB-jade_pieces,0
JADGREEN1E_SUB
	.word JADGREEN1E_IMG-jade_pieces
	.half 9, 11, -1, -132
	.word   JDGRN1_P
JADGREEN1F
	.word	JADGREEN1F_SUB-jade_pieces,0
JADGREEN1F_SUB
	.word JADGREEN1F_IMG-jade_pieces
	.half 39, 85, 28, -54
	.word   JDGRN1_P


	.align 2
	include ..\attract\vs\vsjade.psi

;**********************************************************************
vs_c17 group
	section	.vs_17

	;include palsrc\vsscorp.mas

	.globl scorpion_pieces
scorpion_pieces
	.half 0x5d,0x3d+25,0x135,0x3d+25
	.word scorpgray1a-scorpion_pieces,0
	.word scorpgray1b-scorpion_pieces,0
	.word scorpgray1c-scorpion_pieces,0
	.word scorpgray1d-scorpion_pieces,0
	.word scorpgray1e-scorpion_pieces,0
	.word scorpgray1f-scorpion_pieces,0
	.word scorpgray1g-scorpion_pieces,0
	.word scorpgray1h-scorpion_pieces,0
	.word scorpflesh1a-scorpion_pieces,0
	.word scorpflesh1b-scorpion_pieces,0
	.word scorpflesh1c-scorpion_pieces,0
	.word scorpflesh1d-scorpion_pieces,0
	.word scorpflesh1e-scorpion_pieces,0
	.word scorpyelo1a-scorpion_pieces,SCYELO2_P
	.word scorpyelo1b-scorpion_pieces,SCYELO2_P
	.word scorpyelo1c-scorpion_pieces,SCYELO2_P
	.word scorpyelo1d-scorpion_pieces,SCYELO2_P
	.word scorpyelo1e-scorpion_pieces,SCYELO2_P
	.word 0

scorpgray1a
	.word SCORPGRAY1A-scorpion_pieces,0

scorpgray1b
	.word SCORPGRAY1B-scorpion_pieces,0

scorpgray1c
	.word SCORPGRAY1C-scorpion_pieces,0

scorpgray1d
	.word SCORPGRAY1D-scorpion_pieces,0

scorpgray1e
	.word SCORPGRAY1E-scorpion_pieces,0

scorpgray1f
	.word SCORPGRAY1F-scorpion_pieces,0

scorpgray1g
	.word SCORPGRAY1G-scorpion_pieces,0

scorpgray1h
	.word SCORPGRAY1H-scorpion_pieces,0

scorpflesh1a
	.word SCORPFLESH1A-scorpion_pieces,0

scorpflesh1b
	.word SCORPFLESH1B-scorpion_pieces,0

scorpflesh1c
	.word SCORPFLESH1C-scorpion_pieces,0

scorpflesh1d
	.word SCORPFLESH1D-scorpion_pieces,0

scorpflesh1e
	.word SCORPFLESH1E-scorpion_pieces,0

scorpyelo1a
	.word SCORPYELO1A-scorpion_pieces,0

scorpyelo1b
	.word SCORPYELO1B-scorpion_pieces,0

scorpyelo1c
	.word SCORPYELO1C-scorpion_pieces,0

scorpyelo1d
	.word SCORPYELO1D-scorpion_pieces,0

scorpyelo1e
	.word SCORPYELO1E-scorpion_pieces,0



SCORPGRAY1A
	.word	SCORPGRAY1A_SUB-scorpion_pieces,0
SCORPGRAY1A_SUB
	.word SCORPGRAY1A_IMG-scorpion_pieces
	.half 22, 44, 65, -57
	.word   SCGRAY_P
SCORPGRAY1B
	.word	SCORPGRAY1B_SUB-scorpion_pieces,0
SCORPGRAY1B_SUB
	.word SCORPGRAY1B_IMG-scorpion_pieces
	.half 27, 48, 46, -119
	.word   SCGRAY_P
SCORPGRAY1C
	.word	SCORPGRAY1C_SUB-scorpion_pieces,0
SCORPGRAY1C_SUB
	.word SCORPGRAY1C_IMG-scorpion_pieces
	.half 30, 67, -58, -75
	.word   SCGRAY_P
SCORPGRAY1D
	.word	SCORPGRAY1D_SUB-scorpion_pieces,0
SCORPGRAY1D_SUB
	.word SCORPGRAY1D_IMG-scorpion_pieces
	.half 6, 24, -52, -117
	.word   SCGRAY_P
SCORPGRAY1E
	.word	SCORPGRAY1E_SUB-scorpion_pieces,0
SCORPGRAY1E_SUB
	.word SCORPGRAY1E_IMG-scorpion_pieces
	.half 30, 94, -37, 0
	.word   SCGRAY_P
SCORPGRAY1F
	.word	SCORPGRAY1F_SUB-scorpion_pieces,0
SCORPGRAY1F_SUB
	.word SCORPGRAY1F_IMG-scorpion_pieces
	.half 50, 123, 30, -14
	.word   SCGRAY_P
SCORPGRAY1G
	.word	SCORPGRAY1G_SUB-scorpion_pieces,0
SCORPGRAY1G_SUB
	.word SCORPGRAY1G_IMG-scorpion_pieces
	.half 20, 128, -20, 0
	.word   SCGRAY_P
SCORPGRAY1H
	.word	SCORPGRAY1H_SUB-scorpion_pieces,0
SCORPGRAY1H_SUB
	.word SCORPGRAY1H_IMG-scorpion_pieces
	.half 34, 30, 2, -138
	.word   SCGRAY_P
SCORPFLESH1A
	.word	SCORPFLESH1A_SUB-scorpion_pieces,0
SCORPFLESH1A_SUB
	.word SCORPFLESH1A_IMG-scorpion_pieces
	.half 39, 50, 64, -24
	.word   SCFLESH_P
SCORPFLESH1B
	.word	SCORPFLESH1B_SUB-scorpion_pieces,0
SCORPFLESH1B_SUB
	.word SCORPFLESH1B_IMG-scorpion_pieces
	.half 16, 24, 37, -95
	.word   SCFLESH_P
SCORPFLESH1C
	.word	SCORPFLESH1C_SUB-scorpion_pieces,0
SCORPFLESH1C_SUB
	.word SCORPFLESH1C_IMG-scorpion_pieces
	.half 25, 18, -30, -25
	.word   SCFLESH_P
SCORPFLESH1D
	.word	SCORPFLESH1D_SUB-scorpion_pieces,0
SCORPFLESH1D_SUB
	.word SCORPFLESH1D_IMG-scorpion_pieces
	.half 17, 26, -71, -69
	.word   SCFLESH_P
SCORPFLESH1E
	.word	SCORPFLESH1E_SUB-scorpion_pieces,0
SCORPFLESH1E_SUB
	.word SCORPFLESH1E_IMG-scorpion_pieces
	.half 29, 60, -37, -77
	.word   SCFLESH_P
SCORPYELO1A
	.word	SCORPYELO1A_SUB-scorpion_pieces,0
SCORPYELO1A_SUB
	.word SCORPYELO1A_IMG-scorpion_pieces
	.half 22, 51, -65, -79
	.word   SCYELO1_P
SCORPYELO1B
	.word	SCORPYELO1B_SUB-scorpion_pieces,0
SCORPYELO1B_SUB
	.word SCORPYELO1B_IMG-scorpion_pieces
	.half 10, 20, -55, -112
	.word   SCYELO1_P
SCORPYELO1C
	.word	SCORPYELO1C_SUB-scorpion_pieces,0
SCORPYELO1C_SUB
	.word SCORPYELO1C_IMG-scorpion_pieces
	.half 26, 51, 63, -64
	.word   SCYELO1_P
SCORPYELO1D
	.word	SCORPYELO1D_SUB-scorpion_pieces,0
SCORPYELO1D_SUB
	.word SCORPYELO1D_IMG-scorpion_pieces
	.half 66, 127, -4, -30
	.word   SCYELO1_P
SCORPYELO1E
	.word	SCORPYELO1E_SUB-scorpion_pieces,0
SCORPYELO1E_SUB
	.word SCORPYELO1E_IMG-scorpion_pieces
	.half 47, 162, 38, -6
	.word   SCYELO1_P


	.align 2
	include ..\attract\vs\vsscorp.psi

;**********************************************************************
vs_c18 group
	section	.vs_18

	;include palsrc\vsermac.mas

	.globl ermac_pieces
ermac_pieces
	.half	0x5d,0x30+29,0x135,0x30+29
	.word ermacgray1a-ermac_pieces,0
	.word ermacgray1b-ermac_pieces,0
	.word ermacgray1c-ermac_pieces,0
	.word ermacgray1d-ermac_pieces,0
	.word ermacflesh1a-ermac_pieces,0
	.word ermacflesh1b-ermac_pieces,0
	.word ermacflesh1c-ermac_pieces,0
	.word ermacflesh1d-ermac_pieces,0
	.word ermacred1a-ermac_pieces,RPRED2_P
	.word ermacgreen1b-ermac_pieces,RPRED2_P
	.word ermacgreen1c-ermac_pieces,RPRED2_P
	.word ermacgreen1d-ermac_pieces,RPRED2_P
	.word ermacgreen1e-ermac_pieces,RPRED2_P
	.word 0

ermacgray1a
	.word ERMACGRAY1A-ermac_pieces,0

ermacgray1b
	.word ERMACGRAY1B-ermac_pieces,0

ermacgray1c
	.word ERMACGRAY1C-ermac_pieces,0

ermacgray1d
	.word ERMACGRAY1D-ermac_pieces,0

ermacflesh1a
	.word ERMACFLESH1A-ermac_pieces,0

ermacflesh1b
	.word ERMACFLESH1B-ermac_pieces,0

ermacflesh1c
	.word ERMACFLESH1C-ermac_pieces,0

ermacflesh1d
	.word ERMACFLESH1D-ermac_pieces,0

ermacred1a
	.word ERMACRED1A-ermac_pieces,0

ermacgreen1b
	.word ERMACGREEN1B-ermac_pieces,0

ermacgreen1c
	.word ERMACGREEN1C-ermac_pieces,0

ermacgreen1d
	.word ERMACGREEN1D-ermac_pieces,0

ermacgreen1e
	.word ERMACGREEN1E-ermac_pieces,0


ERMACGRAY1A
	.word	ERMACGRAY1A_SUB-ermac_pieces,0
ERMACGRAY1A_SUB
	.word ERMACGRAY1A_IMG-ermac_pieces
	.half 60, 37, 74, 0
	.word   RPGRAY_P
ERMACGRAY1B
	.word	ERMACGRAY1B_SUB-ermac_pieces,0
ERMACGRAY1B_SUB
	.word ERMACGRAY1B_IMG-ermac_pieces
	.half 46, 116, 40, -54
	.word   RPGRAY_P
ERMACGRAY1C
	.word	ERMACGRAY1C_SUB-ermac_pieces,0
ERMACGRAY1C_SUB
	.word ERMACGRAY1C_IMG-ermac_pieces
	.half 34, 68, -54, -94
	.word   RPGRAY_P
ERMACGRAY1D
	.word	ERMACGRAY1D_SUB-ermac_pieces,0
ERMACGRAY1D_SUB
	.word ERMACGRAY1D_IMG-ermac_pieces
	.half 42, 147, -5, -23
	.word   RPGRAY_P
ERMACFLESH1A
	.word	ERMACFLESH1A_SUB-ermac_pieces,0
ERMACFLESH1A_SUB
	.word ERMACFLESH1A_IMG-ermac_pieces
	.half 77, 75, 74, -5
	.word   RPFLESH_P
ERMACFLESH1B
	.word	ERMACFLESH1B_SUB-ermac_pieces,0
ERMACFLESH1B_SUB
	.word ERMACFLESH1B_IMG-ermac_pieces
	.half 27, 18, -20, -50
	.word   RPFLESH_P
ERMACFLESH1C
	.word	ERMACFLESH1C_SUB-ermac_pieces,0
ERMACFLESH1C_SUB
	.word ERMACFLESH1C_IMG-ermac_pieces
	.half 39, 71, -38, -93
	.word   RPFLESH_P
ERMACFLESH1D
	.word	ERMACFLESH1D_SUB-ermac_pieces,0
ERMACFLESH1D_SUB
	.word ERMACFLESH1D_IMG-ermac_pieces
	.half 21, 26, -77, -93
	.word   RPFLESH_P
ERMACRED1A
	.word	ERMACRED1A_SUB-ermac_pieces,0
ERMACRED1A_SUB
	.word ERMACGREEN1A_IMG-ermac_pieces
	.half 38, 36, 68, 0
	.word	RPRED1_P
ERMACGREEN1B
	.word	ERMACGREEN1B_SUB-ermac_pieces,0
ERMACGREEN1B_SUB
	.word ERMACGREEN1B_IMG-ermac_pieces
	.half 18, 22, 30, 0
	.word	RPRED1_P
ERMACGREEN1C
	.word	ERMACGREEN1C_SUB-ermac_pieces,0
ERMACGREEN1C_SUB
	.word ERMACGREEN1C_IMG-ermac_pieces
	.half 38, 142, 40, -33
	.word	RPRED1_P
ERMACGREEN1D
	.word	ERMACGREEN1D_SUB-ermac_pieces,0
ERMACGREEN1D_SUB
	.word ERMACGREEN1D_IMG-ermac_pieces
	.half 28, 43, -57, -107
	.word	RPRED1_P
ERMACGREEN1E
	.word	ERMACGREEN1E_SUB-ermac_pieces,0
ERMACGREEN1E_SUB
	.word ERMACGREEN1E_IMG-ermac_pieces
	.half 67, 128, 2, -47
	.word	RPRED1_P


	.align 2
	include ..\attract\vs\vsermac.psi

;**********************************************************************
vs_c19 group
	section	.vs_19

	;include palsrc\vsrep.mas
	.globl reptile_pieces
reptile_pieces
	.half	0x5d,0x30+29,0x135,0x30+29
	.word repgray1a-reptile_pieces,0
	.word repgray1b-reptile_pieces,0
	.word repgray1c-reptile_pieces,0
	.word repgray1d-reptile_pieces,0
	.word repflesh1a-reptile_pieces,0
	.word repflesh1b-reptile_pieces,0
	.word repflesh1c-reptile_pieces,0
	.word repflesh1d-reptile_pieces,0
	.word repred1a-reptile_pieces,RPGRN2_P
	.word repgreen1b-reptile_pieces,RPGRN2_P
	.word repgreen1c-reptile_pieces,RPGRN2_P
	.word repgreen1d-reptile_pieces,RPGRN2_P
	.word repgreen1e-reptile_pieces,RPGRN2_P
	.word 0

repgray1a
	.word REPGRAY1A-reptile_pieces,0

repgray1b
	.word REPGRAY1B-reptile_pieces,0

repgray1c
	.word REPGRAY1C-reptile_pieces,0

repgray1d
	.word REPGRAY1D-reptile_pieces,0

repflesh1a
	.word REPFLESH1A-reptile_pieces,0

repflesh1b
	.word REPFLESH1B-reptile_pieces,0

repflesh1c
	.word REPFLESH1C-reptile_pieces,0

repflesh1d
	.word REPFLESH1D-reptile_pieces,0

repred1a
	.word REPRED1A-reptile_pieces,RPGRN2_P

repgreen1b
	.word REPGREEN1B-reptile_pieces,RPGRN2_P

repgreen1c
	.word REPGREEN1C-reptile_pieces,RPGRN2_P

repgreen1d
	.word REPGREEN1D-reptile_pieces,RPGRN2_P

repgreen1e
	.word REPGREEN1E-reptile_pieces,RPGRN2_P


REPGRAY1A
	.word	REPGRAY1A_SUB-reptile_pieces,0
REPGRAY1A_SUB
	.word REPGRAY1A_IMG-reptile_pieces
	.half 60, 37, 74, 0
	.word   RPGGRAY_P
REPGRAY1B
	.word	REPGRAY1B_SUB-reptile_pieces,0
REPGRAY1B_SUB
	.word REPGRAY1B_IMG-reptile_pieces
	.half 46, 116, 40, -54
	.word   RPGGRAY_P
REPGRAY1C
	.word	REPGRAY1C_SUB-reptile_pieces,0
REPGRAY1C_SUB
	.word REPGRAY1C_IMG-reptile_pieces
	.half 34, 68, -54, -94
	.word   RPGGRAY_P
REPGRAY1D
	.word	REPGRAY1D_SUB-reptile_pieces,0
REPGRAY1D_SUB
	.word REPGRAY1D_IMG-reptile_pieces
	.half 42, 147, -5, -23
	.word   RPGGRAY_P
REPFLESH1A
	.word	REPFLESH1A_SUB-reptile_pieces,0
REPFLESH1A_SUB
	.word REPFLESH1A_IMG-reptile_pieces
	.half 77, 75, 74, -5
	.word   RPGFLESH_P
REPFLESH1B
	.word	REPFLESH1B_SUB-reptile_pieces,0
REPFLESH1B_SUB
	.word REPFLESH1B_IMG-reptile_pieces
	.half 27, 18, -20, -50
	.word   RPGFLESH_P
REPFLESH1C
	.word	REPFLESH1C_SUB-reptile_pieces,0
REPFLESH1C_SUB
	.word REPFLESH1C_IMG-reptile_pieces
	.half 39, 71, -38, -93
	.word   RPGFLESH_P
REPFLESH1D
	.word	REPFLESH1D_SUB-reptile_pieces,0
REPFLESH1D_SUB
	.word REPFLESH1D_IMG-reptile_pieces
	.half 21, 26, -77, -93
	.word   RPGFLESH_P
REPRED1A
	.word	REPRED1A_SUB-reptile_pieces,0
REPRED1A_SUB
	.word REPGREEN1A_IMG-reptile_pieces
	.half 38, 36, 68, 0
	.word   RPGRN1_P
REPGREEN1B
	.word	REPGREEN1B_SUB-reptile_pieces,0
REPGREEN1B_SUB
	.word REPGREEN1B_IMG-reptile_pieces
	.half 18, 22, 30, 0
	.word   RPGRN1_P
REPGREEN1C
	.word	REPGREEN1C_SUB-reptile_pieces,0
REPGREEN1C_SUB
	.word REPGREEN1C_IMG-reptile_pieces
	.half 38, 142, 40, -33
	.word   RPGRN1_P
REPGREEN1D
	.word	REPGREEN1D_SUB-reptile_pieces,0
REPGREEN1D_SUB
	.word REPGREEN1D_IMG-reptile_pieces
	.half 28, 43, -57, -107
	.word   RPGRN1_P
REPGREEN1E
	.word	REPGREEN1E_SUB-reptile_pieces,0
REPGREEN1E_SUB
	.word REPGREEN1E_IMG-reptile_pieces
	.half 67, 128, 2, -47
	.word   RPGRN1_P


	.align 2
	include ..\attract\vs\vsrep.psi

;**********************************************************************
vs_c20 group
	section	.vs_20

	;include palsrc\vsosz.mas

	.globl oldsz_pieces
oldsz_pieces
	.half	0x5d,0x30+29,0x135,0x30+29
	.word oszgray1a-oldsz_pieces,0
	.word oszgray1b-oldsz_pieces,0
	.word oszgray1c-oldsz_pieces,0
	.word oszgray1d-oldsz_pieces,0
	.word oszflesh1a-oldsz_pieces,0
	.word oszflesh1b-oldsz_pieces,0
	.word oszflesh1c-oldsz_pieces,0
	.word oszflesh1d-oldsz_pieces,0
	.word oszblu1a-oldsz_pieces,SCBLUE2_P
	.word oszgreen1b-oldsz_pieces,SCBLUE2_P
	.word oszgreen1c-oldsz_pieces,SCBLUE2_P
	.word oszgreen1d-oldsz_pieces,SCBLUE2_P
	.word oszgreen1e-oldsz_pieces,SCBLUE2_P
	.word 0

oszgray1a
	.word OSZGRAY1A-oldsz_pieces,0

oszgray1b
	.word OSZGRAY1B-oldsz_pieces,0

oszgray1c
	.word OSZGRAY1C-oldsz_pieces,0

oszgray1d
	.word OSZGRAY1D-oldsz_pieces,0

oszflesh1a
	.word OSZFLESH1A-oldsz_pieces,0

oszflesh1b
	.word OSZFLESH1B-oldsz_pieces,0

oszflesh1c
	.word OSZFLESH1C-oldsz_pieces,0

oszflesh1d
	.word OSZFLESH1D-oldsz_pieces,0

oszblu1a
	.word OSZBLU1A-oldsz_pieces,0

oszgreen1b
	.word OSZGREEN1B-oldsz_pieces,0

oszgreen1c
	.word OSZGREEN1C-oldsz_pieces,0

oszgreen1d
	.word OSZGREEN1D-oldsz_pieces,0

oszgreen1e
	.word OSZGREEN1E-oldsz_pieces,0


OSZBLU1A
	.word	OSZBLU1A_SUB-oldsz_pieces,0
OSZBLU1A_SUB
	.word OSZGREEN1A_IMG-oldsz_pieces
	.half 38, 36, 68, 0
	.word	SCBLUE1_P
OSZGRAY1A
	.word	OSZGRAY1A_SUB-oldsz_pieces,0
OSZGRAY1A_SUB
	.word OSZGRAY1A_IMG-oldsz_pieces
	.half 60, 37, 74, 0
	.word   RPZGRAY_P
OSZGRAY1B
	.word	OSZGRAY1B_SUB-oldsz_pieces,0
OSZGRAY1B_SUB
	.word OSZGRAY1B_IMG-oldsz_pieces
	.half 46, 116, 40, -54
	.word   RPZGRAY_P
OSZGRAY1C
	.word	OSZGRAY1C_SUB-oldsz_pieces,0
OSZGRAY1C_SUB
	.word OSZGRAY1C_IMG-oldsz_pieces
	.half 34, 68, -54, -94
	.word   RPZGRAY_P
OSZGRAY1D
	.word	OSZGRAY1D_SUB-oldsz_pieces,0
OSZGRAY1D_SUB
	.word OSZGRAY1D_IMG-oldsz_pieces
	.half 42, 147, -5, -23
	.word   RPZGRAY_P
OSZFLESH1A
	.word	OSZFLESH1A_SUB-oldsz_pieces,0
OSZFLESH1A_SUB
	.word OSZFLESH1A_IMG-oldsz_pieces
	.half 77, 75, 74, -5
	.word   RPZFLESH_P
OSZFLESH1B
	.word	OSZFLESH1B_SUB-oldsz_pieces,0
OSZFLESH1B_SUB
	.word OSZFLESH1B_IMG-oldsz_pieces
	.half 27, 18, -20, -50
	.word   RPZFLESH_P
OSZFLESH1C
	.word	OSZFLESH1C_SUB-oldsz_pieces,0
OSZFLESH1C_SUB
	.word OSZFLESH1C_IMG-oldsz_pieces
	.half 39, 71, -38, -93
	.word   RPZFLESH_P
OSZFLESH1D
	.word	OSZFLESH1D_SUB-oldsz_pieces,0
OSZFLESH1D_SUB
	.word OSZFLESH1D_IMG-oldsz_pieces
	.half 21, 26, -77, -93
	.word   RPZFLESH_P
OSZGREEN1B
	.word	OSZGREEN1B_SUB-oldsz_pieces,0
OSZGREEN1B_SUB
	.word OSZGREEN1B_IMG-oldsz_pieces
	.half 18, 22, 30, 0
	.word	SCBLUE1_P
OSZGREEN1C
	.word	OSZGREEN1C_SUB-oldsz_pieces,0
OSZGREEN1C_SUB
	.word OSZGREEN1C_IMG-oldsz_pieces
	.half 38, 142, 40, -33
	.word	SCBLUE1_P
OSZGREEN1D
	.word	OSZGREEN1D_SUB-oldsz_pieces,0
OSZGREEN1D_SUB
	.word OSZGREEN1D_IMG-oldsz_pieces
	.half 28, 43, -57, -107
	.word	SCBLUE1_P
OSZGREEN1E
	.word	OSZGREEN1E_SUB-oldsz_pieces,0
OSZGREEN1E_SUB
	.word OSZGREEN1E_IMG-oldsz_pieces
	.half 67, 128, 2, -47
	.word	SCBLUE1_P


	.align 2
	include ..\attract\vs\vsosz.psi


;**********************************************************************
vs_c21 group
	section	.vs_21

	;include palsrc\vsosm.mas

	.globl oldsmoke_pieces
oldsmoke_pieces
	.half	0x5d,0x3d+25,0x135,0x3d+25
	.word oldsmokegray1a-oldsmoke_pieces,0
	.word oldsmokegray1b-oldsmoke_pieces,0
	.word oldsmokegray1c-oldsmoke_pieces,0
	.word oldsmokegray1d-oldsmoke_pieces,0
	.word oldsmokegray1e-oldsmoke_pieces,0
	.word oldsmokegray1f-oldsmoke_pieces,0
	.word oldsmokegray1g-oldsmoke_pieces,0
	.word oldsmokegray1h-oldsmoke_pieces,0
	.word oldsmokeflesh1a-oldsmoke_pieces,0
	.word oldsmokeflesh1b-oldsmoke_pieces,0
	.word oldsmokeflesh1c-oldsmoke_pieces,0
	.word oldsmokeflesh1d-oldsmoke_pieces,0
	.word oldsmokeflesh1e-oldsmoke_pieces,0
	.word oldsmokeyelo1a-oldsmoke_pieces,SCORPG_P
	.word oldsmokeyelo1b-oldsmoke_pieces,SCORPG_P
	.word oldsmokeyelo1c-oldsmoke_pieces,SCORPG_P
	.word oldsmokeyelo1d-oldsmoke_pieces,SCORPG_P
	.word oldsmokeyelo1e-oldsmoke_pieces,SCORPG_P
	.word	0

oldsmokegray1a
	.word OLDSMOKEGRAY1A-oldsmoke_pieces,0

oldsmokegray1b
	.word OLDSMOKEGRAY1B-oldsmoke_pieces,0

oldsmokegray1c
	.word OLDSMOKEGRAY1C-oldsmoke_pieces,0

oldsmokegray1d
	.word OLDSMOKEGRAY1D-oldsmoke_pieces,0

oldsmokegray1e
	.word OLDSMOKEGRAY1E-oldsmoke_pieces,0

oldsmokegray1f
	.word OLDSMOKEGRAY1F-oldsmoke_pieces,0

oldsmokegray1g
	.word OLDSMOKEGRAY1G-oldsmoke_pieces,0

oldsmokegray1h
	.word OLDSMOKEGRAY1H-oldsmoke_pieces,0

oldsmokeflesh1a
	.word OLDSMOKEFLESH1A-oldsmoke_pieces,0

oldsmokeflesh1b
	.word OLDSMOKEFLESH1B-oldsmoke_pieces,0

oldsmokeflesh1c
	.word OLDSMOKEFLESH1C-oldsmoke_pieces,0

oldsmokeflesh1d
	.word OLDSMOKEFLESH1D-oldsmoke_pieces,0

oldsmokeflesh1e
	.word OLDSMOKEFLESH1E-oldsmoke_pieces,0

oldsmokeyelo1a
	.word OLDSMOKEYELO1A-oldsmoke_pieces,0

oldsmokeyelo1b
	.word OLDSMOKEYELO1B-oldsmoke_pieces,0

oldsmokeyelo1c
	.word OLDSMOKEYELO1C-oldsmoke_pieces,0

oldsmokeyelo1d
	.word OLDSMOKEYELO1D-oldsmoke_pieces,0

oldsmokeyelo1e
	.word OLDSMOKEYELO1E-oldsmoke_pieces,0


OLDSMOKEGRAY1A
	.word	OLDSMOKEGRAY1A_SUB-oldsmoke_pieces,0
OLDSMOKEGRAY1A_SUB
	.word OLDSMOKEGRAY1A_IMG-oldsmoke_pieces
	.half 22, 44, 65, -57
	.word   SCMGRAY_P
OLDSMOKEGRAY1B
	.word	OLDSMOKEGRAY1B_SUB-oldsmoke_pieces,0
OLDSMOKEGRAY1B_SUB
	.word OLDSMOKEGRAY1B_IMG-oldsmoke_pieces
	.half 27, 48, 46, -119
	.word   SCMGRAY_P
OLDSMOKEGRAY1C
	.word	OLDSMOKEGRAY1C_SUB-oldsmoke_pieces,0
OLDSMOKEGRAY1C_SUB
	.word OLDSMOKEGRAY1C_IMG-oldsmoke_pieces
	.half 30, 67, -58, -75
	.word   SCMGRAY_P
OLDSMOKEGRAY1D
	.word	OLDSMOKEGRAY1D_SUB-oldsmoke_pieces,0
OLDSMOKEGRAY1D_SUB
	.word OLDSMOKEGRAY1D_IMG-oldsmoke_pieces
	.half 6, 24, -52, -117
	.word   SCMGRAY_P
OLDSMOKEGRAY1E
	.word	OLDSMOKEGRAY1E_SUB-oldsmoke_pieces,0
OLDSMOKEGRAY1E_SUB
	.word OLDSMOKEGRAY1E_IMG-oldsmoke_pieces
	.half 30, 94, -37, 0
	.word   SCMGRAY_P
OLDSMOKEGRAY1F
	.word	OLDSMOKEGRAY1F_SUB-oldsmoke_pieces,0
OLDSMOKEGRAY1F_SUB
	.word OLDSMOKEGRAY1F_IMG-oldsmoke_pieces
	.half 50, 123, 30, -14
	.word   SCMGRAY_P
OLDSMOKEGRAY1G
	.word	OLDSMOKEGRAY1G_SUB-oldsmoke_pieces,0
OLDSMOKEGRAY1G_SUB
	.word OLDSMOKEGRAY1G_IMG-oldsmoke_pieces
	.half 20, 128, -20, 0
	.word   SCMGRAY_P
OLDSMOKEGRAY1H
	.word	OLDSMOKEGRAY1H_SUB-oldsmoke_pieces,0
OLDSMOKEGRAY1H_SUB
	.word OLDSMOKEGRAY1H_IMG-oldsmoke_pieces
	.half 34, 30, 2, -138
	.word   SCMGRAY_P
OLDSMOKEFLESH1A
	.word	OLDSMOKEFLESH1A_SUB-oldsmoke_pieces,0
OLDSMOKEFLESH1A_SUB
	.word OLDSMOKEFLESH1A_IMG-oldsmoke_pieces
	.half 39, 50, 64, -24
	.word   SCMFLESH_P
OLDSMOKEFLESH1B
	.word	OLDSMOKEFLESH1B_SUB-oldsmoke_pieces,0
OLDSMOKEFLESH1B_SUB
	.word OLDSMOKEFLESH1B_IMG-oldsmoke_pieces
	.half 16, 24, 37, -95
	.word   SCMFLESH_P
OLDSMOKEFLESH1C
	.word	OLDSMOKEFLESH1C_SUB-oldsmoke_pieces,0
OLDSMOKEFLESH1C_SUB
	.word OLDSMOKEFLESH1C_IMG-oldsmoke_pieces
	.half 25, 18, -30, -25
	.word   SCMFLESH_P
OLDSMOKEFLESH1D
	.word	OLDSMOKEFLESH1D_SUB-oldsmoke_pieces,0
OLDSMOKEFLESH1D_SUB
	.word OLDSMOKEFLESH1D_IMG-oldsmoke_pieces
	.half 17, 26, -71, -69
	.word   SCMFLESH_P
OLDSMOKEFLESH1E
	.word	OLDSMOKEFLESH1E_SUB-oldsmoke_pieces,0
OLDSMOKEFLESH1E_SUB
	.word OLDSMOKEFLESH1E_IMG-oldsmoke_pieces
	.half 29, 60, -37, -77
	.word   SCMFLESH_P
OLDSMOKEYELO1A
	.word	OLDSMOKEYELO1A_SUB-oldsmoke_pieces,0
OLDSMOKEYELO1A_SUB
	.word OLDSMOKEYELO1A_IMG-oldsmoke_pieces
	.half 22, 51, -65, -79
	.word   SCORPG_P
OLDSMOKEYELO1B
	.word	OLDSMOKEYELO1B_SUB-oldsmoke_pieces,0
OLDSMOKEYELO1B_SUB
	.word OLDSMOKEYELO1B_IMG-oldsmoke_pieces
	.half 10, 20, -55, -112
	.word   SCORPG_P
OLDSMOKEYELO1C
	.word	OLDSMOKEYELO1C_SUB-oldsmoke_pieces,0
OLDSMOKEYELO1C_SUB
	.word OLDSMOKEYELO1C_IMG-oldsmoke_pieces
	.half 26, 51, 63, -64
	.word   SCORPG_P
OLDSMOKEYELO1D
	.word	OLDSMOKEYELO1D_SUB-oldsmoke_pieces,0
OLDSMOKEYELO1D_SUB
	.word OLDSMOKEYELO1D_IMG-oldsmoke_pieces
	.half 66, 127, -4, -30
	.word   SCORPG_P
OLDSMOKEYELO1E
	.word	OLDSMOKEYELO1E_SUB-oldsmoke_pieces,0
OLDSMOKEYELO1E_SUB
	.word OLDSMOKEYELO1E_IMG-oldsmoke_pieces
	.half 47, 162, 38, -6
	.word   SCORPG_P


	.align 2
	include ..\attract\vs\vsosmk.psi

;**********************************************************************
vs_c22 group
	section	.vs_22

	;include palsrc\vsmil.mas

	.globl mileena_pieces
mileena_pieces
	.half	0x5d,0x3d+29,0x135,0x3d+29
	.word milfgray1a-mileena_pieces,0
	.word milfgray1b-mileena_pieces,0
	.word milfgray1c-mileena_pieces,0
	.word milfgray1d-mileena_pieces,0
	.word milfgray1e-mileena_pieces,0
	.word milfgray1f-mileena_pieces,0
	.word milfgray1g-mileena_pieces,0
	.word milflesh1a-mileena_pieces,0
	.word milflesh1b-mileena_pieces,0
	.word milflesh1c-mileena_pieces,0
	.word milflesh1d-mileena_pieces,0
	.word milflesh1e-mileena_pieces,0
	.word milflesh1f-mileena_pieces,0
	.word milflesh1g-mileena_pieces,0
	.word milflesh1h-mileena_pieces,0
	.word milflesh1i-mileena_pieces,0
	.word milpurp1a-mileena_pieces,MLPURP2_P
	.word milgreen1b-mileena_pieces,MLPURP2_P
	.word milgreen1c-mileena_pieces,MLPURP2_P
	.word milgreen1d-mileena_pieces,MLPURP2_P
	.word milgreen1e-mileena_pieces,MLPURP2_P
	.word milgreen1f-mileena_pieces,MLPURP2_P
	.word 0

milfgray1a
	.word MILFGRAY1A-mileena_pieces,0

milfgray1b
	.word MILFGRAY1B-mileena_pieces,0

milfgray1c
	.word MILFGRAY1C-mileena_pieces,0

milfgray1d
	.word MILFGRAY1D-mileena_pieces,0

milfgray1e
	.word MILFGRAY1E-mileena_pieces,0

milfgray1f
	.word MILFGRAY1F-mileena_pieces,0

milfgray1g
	.word MILFGRAY1G-mileena_pieces,0

milflesh1a
	.word MILFLESH1A-mileena_pieces,0

milflesh1b
	.word MILFLESH1B-mileena_pieces,0

milflesh1c
	.word MILFLESH1C-mileena_pieces,0

milflesh1d
	.word MILFLESH1D-mileena_pieces,0

milflesh1e
	.word MILFLESH1E-mileena_pieces,0

milflesh1f
	.word MILFLESH1F-mileena_pieces,0

milflesh1g
	.word MILFLESH1G-mileena_pieces,0

milflesh1h
	.word MILFLESH1H-mileena_pieces,0

milflesh1i
	.word MILFLESH1I-mileena_pieces,0

milpurp1a
	.word MILGREEN1A-mileena_pieces,0

milgreen1b
	.word MILGREEN1B-mileena_pieces,0

milgreen1c
	.word MILGREEN1C-mileena_pieces,0

milgreen1d
	.word MILGREEN1D-mileena_pieces,0

milgreen1e
	.word MILGREEN1E-mileena_pieces,0

milgreen1f
	.word MILGREEN1F-mileena_pieces,0

MILFGRAY1A
	.word	MILFGRAY1A_SUB-mileena_pieces,0
MILFGRAY1A_SUB
	.word MILFGRAY1A_IMG-mileena_pieces
	.half 61, 34, 60, -19
	.word   MDGRAY_P
MILFGRAY1B
	.word	MILFGRAY1B_SUB-mileena_pieces,0
MILFGRAY1B_SUB
	.word MILFGRAY1B_IMG-mileena_pieces
	.half 27, 54, 36, -110
	.word   MDGRAY_P
MILFGRAY1C
	.word	MILFGRAY1C_SUB-mileena_pieces,0
MILFGRAY1C_SUB
	.word MILFGRAY1C_IMG-mileena_pieces
	.half 22, 94, 9, -71
	.word   MDGRAY_P
MILFGRAY1D
	.word	MILFGRAY1D_SUB-mileena_pieces,0
MILFGRAY1D_SUB
	.word MILFGRAY1D_IMG-mileena_pieces
	.half 18, 17, -32, -105
	.word   MDGRAY_P
MILFGRAY1E
	.word	MILFGRAY1E_SUB-mileena_pieces,0
MILFGRAY1E_SUB
	.word MILFGRAY1E_IMG-mileena_pieces
	.half 35, 54, -49, -97
	.word   MDGRAY_P
MILFGRAY1F
	.word	MILFGRAY1F_SUB-mileena_pieces,0
MILFGRAY1F_SUB
	.word MILFGRAY1F_IMG-mileena_pieces
	.half 15, 3, -28, -28
	.word   MDGRAY_P
MILFGRAY1G
	.word	MILFGRAY1G_SUB-mileena_pieces,0
MILFGRAY1G_SUB
	.word MILFGRAY1G_IMG-mileena_pieces
	.half 41, 146, -2, 0
	.word   MDGRAY_P
MILFLESH1A
	.word	MILFLESH1A_SUB-mileena_pieces,0
MILFLESH1A_SUB
	.word MILFLESH1A_IMG-mileena_pieces
	.half 15, 22, 68, -22
	.word   MDFLESH_P
MILFLESH1B
	.word	MILFLESH1B_SUB-mileena_pieces,0
MILFLESH1B_SUB
	.word MILFLESH1B_IMG-mileena_pieces
	.half 22, 31, 53, -19
	.word   MDFLESH_P
MILFLESH1C
	.word	MILFLESH1C_SUB-mileena_pieces,0
MILFLESH1C_SUB
	.word MILFLESH1C_IMG-mileena_pieces
	.half 32, 40, 25, -35
	.word   MDFLESH_P
MILFLESH1D
	.word	MILFLESH1D_SUB-mileena_pieces,0
MILFLESH1D_SUB
	.word MILFLESH1D_IMG-mileena_pieces
	.half 30, 32, 47, -132
	.word   MDFLESH_P
MILFLESH1E
	.word	MILFLESH1E_SUB-mileena_pieces,0
MILFLESH1E_SUB
	.word MILFLESH1E_IMG-mileena_pieces
	.half 11, 20, -2, -145
	.word   MDFLESH_P
MILFLESH1F
	.word	MILFLESH1F_SUB-mileena_pieces,0
MILFLESH1F_SUB
	.word MILFLESH1F_IMG-mileena_pieces
	.half 34, 45, -9, -10
	.word   MDFLESH_P
MILFLESH1G
	.word	MILFLESH1G_SUB-mileena_pieces,0
MILFLESH1G_SUB
	.word MILFLESH1G_IMG-mileena_pieces
	.half 19, 44, -27, -65
	.word   MDFLESH_P
MILFLESH1H
	.word	MILFLESH1H_SUB-mileena_pieces,0
MILFLESH1H_SUB
	.word MILFLESH1H_IMG-mileena_pieces
	.half 26, 32, -35, -119
	.word   MDFLESH_P
MILFLESH1I
	.word	MILFLESH1I_SUB-mileena_pieces,0
MILFLESH1I_SUB
	.word MILFLESH1I_IMG-mileena_pieces
	.half 23, 64, 1, -69
	.word   MDFLESH_P
MILGREEN1A
	.word	MILGREEN1A_SUB-mileena_pieces,0
MILGREEN1A_SUB
	.word MILGREEN1A_IMG-mileena_pieces
	.half 39, 7, 45, -17
	.word   MLPURP1_P
MILGREEN1B
	.word	MILGREEN1B_SUB-mileena_pieces,0
MILGREEN1B_SUB
	.word MILGREEN1B_IMG-mileena_pieces
	.half 32, 26, -12, -30
	.word   MLPURP1_P
MILGREEN1C
	.word	MILGREEN1C_SUB-mileena_pieces,0
MILGREEN1C_SUB
	.word MILGREEN1C_IMG-mileena_pieces
	.half 7, 15, -59, -122
	.word   MLPURP1_P
MILGREEN1D
	.word	MILGREEN1D_SUB-mileena_pieces,0
MILGREEN1D_SUB
	.word MILGREEN1D_IMG-mileena_pieces
	.half 25, 65, -10, -70
	.word   MLPURP1_P
MILGREEN1E
	.word	MILGREEN1E_SUB-mileena_pieces,0
MILGREEN1E_SUB
	.word MILGREEN1E_IMG-mileena_pieces
	.half 9, 11, -1, -132
	.word   MLPURP1_P
MILGREEN1F
	.word	MILGREEN1F_SUB-mileena_pieces,0
MILGREEN1F_SUB
	.word MILGREEN1F_IMG-mileena_pieces
	.half 39, 85, 28, -54
	.word   MLPURP1_P

	.align 2
	include ..\attract\vs\vsmil.psi

;**********************************************************************
vs_c23 group
	section	.vs_23

	.globl noob_pieces
noob_pieces
	.half	0x5d,0x3d+25,0x135,0x3d+25
	.word noobgray1a-noob_pieces,0
	.word noobgray1b-noob_pieces,0
	.word noobgray1c-noob_pieces,0
	.word noobgray1d-noob_pieces,0
	.word noobgray1e-noob_pieces,0
	.word noobgray1f-noob_pieces,0
	.word noobgray1g-noob_pieces,0
	.word noobgray1h-noob_pieces,0
	.word noobflesh1a-noob_pieces,0
	.word noobflesh1b-noob_pieces,0
	.word noobflesh1c-noob_pieces,0
	.word noobflesh1d-noob_pieces,0
	.word noobflesh1e-noob_pieces,0
	.word noobyelo1a-noob_pieces,noob_p
	.word noobyelo1b-noob_pieces,noob_p
	.word noobyelo1c-noob_pieces,noob_p
	.word noobyelo1d-noob_pieces,noob_p
	.word noobyelo1e-noob_pieces,noob_p
	.word	0

noobgray1a
	.word NOOBGRAY1A-noob_pieces,0

noobgray1b
	.word NOOBGRAY1B-noob_pieces,0

noobgray1c
	.word NOOBGRAY1C-noob_pieces,0

noobgray1d
	.word NOOBGRAY1D-noob_pieces,0

noobgray1e
	.word NOOBGRAY1E-noob_pieces,0

noobgray1f
	.word NOOBGRAY1F-noob_pieces,0

noobgray1g
	.word NOOBGRAY1G-noob_pieces,0

noobgray1h
	.word NOOBGRAY1H-noob_pieces,0

noobflesh1a
	.word NOOBFLESH1A-noob_pieces,0

noobflesh1b
	.word NOOBFLESH1B-noob_pieces,0

noobflesh1c
	.word NOOBFLESH1C-noob_pieces,0

noobflesh1d
	.word NOOBFLESH1D-noob_pieces,0

noobflesh1e
	.word NOOBFLESH1E-noob_pieces,0

noobyelo1a
	.word NOOBYELO1A-noob_pieces,0

noobyelo1b
	.word NOOBYELO1B-noob_pieces,0

noobyelo1c
	.word NOOBYELO1C-noob_pieces,0

noobyelo1d
	.word NOOBYELO1D-noob_pieces,0

noobyelo1e
	.word NOOBYELO1E-noob_pieces,0


NOOBGRAY1A
	.word	NOOBGRAY1A_SUB-noob_pieces,0
NOOBGRAY1A_SUB
	.word NOOBGRAY1A_IMG-noob_pieces
	.half 22, 44, 65, -57
	.word   noob_p
NOOBGRAY1B
	.word	NOOBGRAY1B_SUB-noob_pieces,0
NOOBGRAY1B_SUB
	.word NOOBGRAY1B_IMG-noob_pieces
	.half 27, 48, 46, -119
	.word   noob_p
NOOBGRAY1C
	.word	NOOBGRAY1C_SUB-noob_pieces,0
NOOBGRAY1C_SUB
	.word NOOBGRAY1C_IMG-noob_pieces
	.half 30, 67, -58, -75
	.word   noob_p
NOOBGRAY1D
	.word	NOOBGRAY1D_SUB-noob_pieces,0
NOOBGRAY1D_SUB
	.word NOOBGRAY1D_IMG-noob_pieces
	.half 6, 24, -52, -117
	.word   noob_p
NOOBGRAY1E
	.word	NOOBGRAY1E_SUB-noob_pieces,0
NOOBGRAY1E_SUB
	.word NOOBGRAY1E_IMG-noob_pieces
	.half 30, 94, -37, 0
	.word   noob_p
NOOBGRAY1F
	.word	NOOBGRAY1F_SUB-noob_pieces,0
NOOBGRAY1F_SUB
	.word NOOBGRAY1F_IMG-noob_pieces
	.half 50, 123, 30, -14
	.word   noob_p
NOOBGRAY1G
	.word	NOOBGRAY1G_SUB-noob_pieces,0
NOOBGRAY1G_SUB
	.word NOOBGRAY1G_IMG-noob_pieces
	.half 20, 128, -20, 0
	.word   noob_p
NOOBGRAY1H
	.word	NOOBGRAY1H_SUB-noob_pieces,0
NOOBGRAY1H_SUB
	.word NOOBGRAY1H_IMG-noob_pieces
	.half 34, 30, 2, -138
	.word   noob_p
NOOBFLESH1A
	.word	NOOBFLESH1A_SUB-noob_pieces,0
NOOBFLESH1A_SUB
	.word NOOBFLESH1A_IMG-noob_pieces
	.half 39, 50, 64, -24
	.word   noob_p
NOOBFLESH1B
	.word	NOOBFLESH1B_SUB-noob_pieces,0
NOOBFLESH1B_SUB
	.word NOOBFLESH1B_IMG-noob_pieces
	.half 16, 24, 37, -95
	.word   noob_p
NOOBFLESH1C
	.word	NOOBFLESH1C_SUB-noob_pieces,0
NOOBFLESH1C_SUB
	.word NOOBFLESH1C_IMG-noob_pieces
	.half 25, 18, -30, -25
	.word   noob_p
NOOBFLESH1D
	.word	NOOBFLESH1D_SUB-noob_pieces,0
NOOBFLESH1D_SUB
	.word NOOBFLESH1D_IMG-noob_pieces
	.half 17, 26, -71, -69
	.word   noob_p
NOOBFLESH1E
	.word	NOOBFLESH1E_SUB-noob_pieces,0
NOOBFLESH1E_SUB
	.word NOOBFLESH1E_IMG-noob_pieces
	.half 29, 60, -37, -77
	.word   noob_p
NOOBYELO1A
	.word	NOOBYELO1A_SUB-noob_pieces,0
NOOBYELO1A_SUB
	.word NOOBYELO1A_IMG-noob_pieces
	.half 22, 51, -65, -79
	.word   noob_p
NOOBYELO1B
	.word	NOOBYELO1B_SUB-noob_pieces,0
NOOBYELO1B_SUB
	.word NOOBYELO1B_IMG-noob_pieces
	.half 10, 20, -55, -112
	.word   noob_p
NOOBYELO1C
	.word	NOOBYELO1C_SUB-noob_pieces,0
NOOBYELO1C_SUB
	.word NOOBYELO1C_IMG-noob_pieces
	.half 26, 51, 63, -64
	.word   noob_p
NOOBYELO1D
	.word	NOOBYELO1D_SUB-noob_pieces,0
NOOBYELO1D_SUB
	.word NOOBYELO1D_IMG-noob_pieces
	.half 66, 127, -4, -30
	.word   noob_p
NOOBYELO1E
	.word	NOOBYELO1E_SUB-noob_pieces,0
NOOBYELO1E_SUB
	.word NOOBYELO1E_IMG-noob_pieces
	.half 47, 162, 38, -6
	.word   noob_p

	.align 2
	include ..\attract\vs\vsnoob.psi

*/