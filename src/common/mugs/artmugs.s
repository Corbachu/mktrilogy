#include <regdef.h>
#include "mkchar.inc"

	.option	pic0

	.set noreorder
	.data

/*
;******************************************************************************
; File: artfight.s
;
; By: David Schwartz
;
; Date: Jan 1995
;
; (C) Williams Entertainment
;
; Mortal Kombat III Fight Art Textures
;******************************************************************************
*/

	.align 2
#include "mugpal.mas"
	
/*
;******************************************************************************
;	mugs shots and spinning dragon coin
;******************************************************************************
*/
	.align 2
	.globl a_badge_spin
a_badge_spin:
	.word MKCOIN_01
	.word MKCOIN_02
	.word MKCOIN_03
	.word MKCOIN_04
	.word MKCOIN_05
	.word MKCOIN_06
	.word MKCOIN_07
	.word MKCOIN_08
	.word MKCOIN_09
	.word ani_jump
	.word a_badge_spin
	.globl MKCOIN_01
MKCOIN_01:
	.word MKCOIN_01_IMG
	.half 33, 35, 0, 0
	.word MKCOIN_P
MKCOIN_02:
	.word MKCOIN_02_IMG
	.half 33, 34, 0, 0
MKCOIN_03:
	.word MKCOIN_03_IMG
	.half 33, 30, 0, 0
MKCOIN_04:
	.word MKCOIN_04_IMG
	.half 33, 23, -3, 0
MKCOIN_05:
	.word MKCOIN_05_IMG
	.half 33, 14, -9, 0
MKCOIN_06:
	.word MKCOIN_06_IMG
	.half 33, 10, -12, 0
MKCOIN_07:
	.word MKCOIN_07_IMG
	.half 33, 21, -8, 0
MKCOIN_08:
	.word MKCOIN_08_IMG
	.half 33, 30, -3, 0
MKCOIN_09:
	.word MKCOIN_09_IMG
	.half 33, 34, -1, 0

	.align 2
	.globl ochar_order_mugs
ochar_order_mugs:
	.word HDKANO
	.word HDSONYA
	.word HDJAX
	.word HDINDIAN
	.word HDCAGE
	.word HDSWAT
	.word HDBRIDE
	.word HDKETCHUP
	.word HDMUSTARD
	.word HDLAO
	.word HDTUSKAN
	.word HDSHEGORO
	.word HDSHANG
	.word HDLIUKANG
	.word HDSMOKE
	.word HDKITANA
	.word HDJADE
	.word HDMILEENA
	.word HDSCORPION
	.word HDREPTILE
	.word HDERMAC
	.word HDCLASSUB
	.word HDOSM
	.word HDNOOB
	.word HDRAYDEN
	.word HDBARAKA
	.word HDRAIN
	.word HDKAMEL
	.word MUG_QUESTION
	.word MUG_QUESTION
	.word HDMOTARO
	.word HDSHAO
	.word ENDUR_GOLD
	.word ENDUR_MAG
	.word ENDUR_GREEN
	.word ENDUR_BLUE
	.word ENDUR_GOLD
	.word ENDUR_MAG
	.word ENDUR_GREEN
	.word ENDUR_BLUE
	.word ENDUR_GOLD
	.word ENDUR_MAG
	.word ENDUR_GREEN
	.word ENDUR_BLUE
	.word ENDUR_GOLD
	.word ENDUR_MAG
	.word ENDUR_GREEN
	.word ENDUR_BLUE
	.word ENDUR_RED
	.word ENDUR_RED
	.word ENDUR_RED
	.word ENDUR_RED
	.word ENDUR_RED
	.word ENDUR_RED
	.word ENDUR_RED
	.word ENDUR_RED
	.word ENDUR_RED
	.word ENDUR_RED
	.word ENDUR_RED
	.word ENDUR_RED
	.word ENDUR_RED
	.word ENDUR_RED
	.word ENDUR_RED
	.word ENDUR_RED
	.word ENDUR_RED
	.word ENDUR_RED
	.word ENDUR_RED
	.word ENDUR_RED
	.word ENDUR_RED
	.word ENDUR_RED
	.word ENDUR_RED
	.word ENDUR_RED
	.word ENDUR_RED
	.word ENDUR_RED
	.word ENDUR_RED

	.globl HDBARAKA
HDBARAKA:
	.word HDBARAKA_IMG
	.half 45, 34, 0, 0
	.word HDSA_P
	.globl HDRAYDEN
HDRAYDEN:
	.word HDRAYDEN_IMG
	.half 45, 34, 0, 0
	.word HDRAYDEN_P
	.globl HDRAIN
HDRAIN:
	.word HDRAIN_IMG
	.half 45, 34, 0, 0
	.word HDRAIN_P
	.globl HDNOOB
HDNOOB:
	.word HDNOOB_IMG
	.half 45, 34, 0, 0
	.word HDNOOB_P
	
	.globl HDKANO
HDKANO:
	.word HDKANO_IMG
	.half 45, 34, 0, 0
	.word HDKANO_P
	.globl HDSONYA
HDSONYA:
	.word HDSONYA_IMG
	.half 45, 34, 0, 0
	.word HDSOYN_P
	.globl HDJAX
HDJAX:
	.word HDJAX_IMG
	.half 45, 34, 0, 0
	.word HDJAX_P
	.globl HDINDIAN
HDINDIAN:
	.word HDINDIAN_IMG
	.half 45, 34, 0, 0
	.word HDINDY_P
	.globl HDCAGE
HDCAGE:
	.word CAGESEL_IMG
	.half 45, 34, 0, 0
	.word HDCAGE_P
	.globl HDSWAT
HDSWAT:
	.word HDSWAT_IMG
	.half 45, 34, 0, 0
	.word HDSWAT_P
	.globl HDBRIDE
HDBRIDE:
	.word HDBRIDE_IMG
	.half 45, 34, 0, 0
	.word HDBRDE_P
	.globl HDKETCHUP
HDKETCHUP:
	.word HDKETCHUP_IMG
	.half 45, 34, 0, 0
	.word HDKETC_P
	.globl HDMUSTARD
HDMUSTARD:
	.word HDMUSTARD_IMG
	.half 45, 34, 0, 0
	.word HDMUST_P
	.globl HDLAO
HDLAO:
	.word HDLAO_IMG
	.half 45, 34, 0, 0
	.word HDLAO_P
	.globl HDTUSKAN
HDTUSKAN:
	.word HDTUSKAN_IMG
	.half 45, 34, 0, 0
	.word HDSAND_P
	.globl HDSHEGORO
HDSHEGORO:
	.word HDSHEGORO_IMG
	.half 45, 34, 0, 0
	.word HDGORO_P
	.globl HDSHANG
HDSHANG:
	.word HDSHANG_IMG
	.half 45, 34, 0, 0
	.word HDSHAG_P
	.globl HDLIUKANG
HDLIUKANG:
	.word HDLIUKANG_IMG
	.half 45, 34, 0, 0
	.word HDKANG_P
	.globl HDSMOKE
HDSMOKE:	   
	.word HDSMOKE_IMG
	.half 45, 34, 0, 0
	.word HDSMOK_P
	.globl HDKITANA
HDKITANA:
	.word HDKITANA_IMG
	.half 45, 34, 0, 0
	.word HDKITANA_P
	.globl HDJADE
HDJADE:
	.word HDJADE_IMG
	.half 45, 34, 0, 0
	.word HDJADEBO_P
	.globl HDMILEENA
HDMILEENA:
	.word HDMILEENA_IMG
	.half 45, 34, 0, 0
	.word HDMILEENA_P
	.globl BOX_01
BOX_01:
	.word BOX_01_IMG
	.half 45, 34, 0, 0
	.word	selbOX_p
	.globl HDSCORPION
HDSCORPION:
	.word HDSCORPION_IMG
	.half 45, 34, 0, 0
	.word HDSCORPIO_P
	.globl HDREPTILE
HDREPTILE:
	.word HDREPTILE_IMG
	.half 45, 34, 0, 0
	.word HDREPTILE_P
	.globl HDERMAC
HDERMAC:
	.word HDERMAC_IMG
	.half 45, 34, 0, 0
	.word HDERMACB_P
	.globl HDCLASSUB
HDCLASSUB:
	.word HDCLASSUB_IMG
	.half 45, 34, 0, 0
	.word HDCLASSUB_P
	
	.globl HDKAMEL
HDKAMEL:
	.word HDKITANA_IMG
	.half 45, 34, 0, 0
	.word HDKAMEL_P
	
	.globl HDOSM
HDOSM:
	.word HDCLASSUB_IMG
	.half 45, 34, 0, 0
	.word HDOSM_P
	
	.globl MUG_QUESTION
MUG_QUESTION:
	.word QUESTION_IMG
	.half 45, 34, 0, 0
	.word REDQ_P
	.globl HDMOTARO
HDMOTARO:
	.word HDMOTARO_IMG
	.half 45, 34, 0, 0
	.word HDMOTA_P
	.globl HDSHAO
HDSHAO:
	.word HDSHAO_IMG
	.half 45, 34, 0, 0
	.word HDSHAO_P

	.globl ENDUR_RED
	.globl ENDUR_GOLD
	.globl ENDUR_MAG
	.globl ENDUR_GREEN
	.globl ENDUR_BLUE
ENDUR_RED:
	.word ENDUR_RED_IMG
	.half 45, 34, 0, 0
	.word ENDUR_RED_P

ENDUR_BLUE:
	.word ENDUR_RED_IMG
	.half 45, 34, 0, 0
	.word ENDUR_BLUE_P

ENDUR_GREEN:
	.word ENDUR_RED_IMG
	.half 45, 34, 0, 0
	.word ENDUR_GREEN_P
	
ENDUR_MAG:
	.word ENDUR_RED_IMG
	.half 45, 34, 0, 0
	.word ENDUR_MAG_P
	
ENDUR_GOLD:
	.word ENDUR_RED_IMG
	.half 45, 34, 0, 0
	.word ENDUR_GOLD_P

	.align 2
	.globl sdragon_dict
sdragon_dict:	
#include "../../common/dragon/sdragon.dct"
	.align 2
#include "../../common/dragon/sdragon.att"

	.align 2
#include "../../common/mugs/mugs.att"
