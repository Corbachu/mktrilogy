#include <regdef.h>
#include "mkchar.inc"
#include "mkbkgd.inc"

	.set	noreorder

/*
;******************************************************************************
; File: mkmisc.s
;
; By: David Schwartz
;
; Date: Jan 1995
;
; (C) Williams Entertainment
;
; Mortal Kombat III Misc Graphics (Perm Loaded with Code)
;******************************************************************************
*/

	.data
	
/*
;******************************************************************************
;	Noob Projectile (ninjadis.)
;******************************************************************************
*/
	.align 2
	.globl a_ghost_circle
a_ghost_circle:
	.word GHOSTCPLOOP1
	.word GHOSTCPLOOP2
	.word GHOSTCPLOOP3
	.word GHOSTCPLOOP4
	.word ani_jump,a_ghost_circle
	.word 0
	.word GHOSTDISP1
	.word GHOSTDISP2
	.word GHOSTDISP3
	.word 0
	.globl GHOSTCPLOOP1
GHOSTCPLOOP1:
	.word GHOSTCPLOOP1_IMG
	.half 31, 92, -59, -42
	.word NGHOST_P
GHOSTCPLOOP2:
	.word GHOSTCPLOOP2_IMG
	.half 33, 97, -55, -40
GHOSTCPLOOP3:
	.word GHOSTCPLOOP3_IMG
	.half 35, 97, -54, -39
GHOSTCPLOOP4:
	.word GHOSTCPLOOP4_IMG
	.half 36, 86, -59, -40
GHOSTDISP1:
	.word GHOSTDISP1_IMG
	.half 32, 93, -58, -42
	.word NGHOST_P
GHOSTDISP2:
	.word GHOSTDISP2_IMG
	.half 31, 98, -55, -42
GHOSTDISP3:
	.word GHOSTDISP3_IMG
	.half 24, 87, -57, -47
	

	.align 2
	.globl ghost_dict
ghost_dict:	
#include "../common/noobpro/ninjadis.dct"

	.align 2
#include "../common/noobpro/ninjadis.att"
		
/*
;******************************************************************************
;	Various Explosions Graphics (explode.adt)
;******************************************************************************
*/
	.align 2
	.globl a_ground_explode
a_ground_explode:
	.word FLOORXPD1
	.word FLOORXPD3
	.word FLOORXPD5
	.word FLOORXPD7
	.word FLOORXPD9
	.word FLOORXPD11
	.word FLOORXPD13
	.word FLOORXPD19
	.word FLOORXPD21
	.word 0
	
	.align 2
	.globl a_small_explode
a_small_explode:
	.word SMALLXPD1
	.word SMALLXPD2
	.word SMALLXPD3
	.word SMALLXPD4
	.word SMALLXPD5
	.word SMALLXPD6
	.word SMALLXPD7
	.word SMALLXPD8
	.word SMALLXPD9
	.word SMALLXPD10
	.word SMALLXPD11
	.word SMALLXPD12
	.word SMALLXPD13
	.word SMALLXPD14
	.word SMALLXPD15
	.word 0
	
	.globl a_puff
	.globl preload_puff
preload_puff:
a_puff:
	.word PUFF1
	.word PUFF2
	.word PUFF3
	.word PUFF4
	.word PUFF5
	.word 0
	
	.globl a_dave_explode
a_dave_explode:
	.word BIGXPLOD1
	.word BIGXPLOD3
	.word BIGXPLOD5
	.word BIGXPLOD7
	.word BIGXPLOD9
	.word BIGXPLOD11
	.word BIGXPLOD13
	.word BIGXPLOD15
	.word 0
	.word BIGXPLOD15
	.word BIGXPLOD13
	.word BIGXPLOD11
	.word BIGXPLOD9
	.word BIGXPLOD7
	.word BIGXPLOD5
	.word BIGXPLOD3
	.word BIGXPLOD1
	.word 0
	.globl PUFF1
PUFF1:
	.word PUFF1_IMG
	.half 18, 16, 7, 9
	.word PUFF_P
PUFF2:
	.word PUFF2_IMG
	.half 25, 18, 8, 12
PUFF3:
	.word PUFF3_IMG
	.half 30, 24, 11, 15
PUFF4:
	.word PUFF4_IMG
	.half 35, 30, 14, 17
PUFF5:
	.word PUFF5_IMG
	.half 40, 34, 16, 20


BIGXPLOD1:
	.word BIGXPLOD1_SUB, 0
BIGXPLOD1_SUB:
	.word BIGXPLOD1_IMG
	.half 51, 60, 30, 25
	.word XPLODZ_P
BIGXPLOD3:
	.word BIGXPLOD3_SUB, 0
BIGXPLOD3_SUB:
	.word BIGXPLOD3_IMG
	.half 66, 74, 38, 32
BIGXPLOD5:
	.word BIGXPLOD5_SUB, 0
BIGXPLOD5_SUB:
	.word BIGXPLOD5_IMG
	.half 71, 80, 45, 35
BIGXPLOD7:
	.word BIGXPLOD7_SUB, 0
BIGXPLOD7_SUB:
	.word BIGXPLOD7_IMG
	.half 65, 82, 48, 30
BIGXPLOD9:
	.word BIGXPLOD9_SUB, 0
BIGXPLOD9_SUB:
	.word BIGXPLOD9_IMG
	.half 62, 82, 45, 32
BIGXPLOD11:
	.word BIGXPLOD11_SUB, 0
BIGXPLOD11_SUB:
	.word BIGXPLOD11_IMG
	.half 64, 76, 40, 33
BIGXPLOD13:
	.word BIGXPLOD13_SUB, 0
BIGXPLOD13_SUB:
	.word BIGXPLOD13_IMG
	.half 63, 69, 42, 35
BIGXPLOD15:
	.word BIGXPLOD15_SUB, 0
BIGXPLOD15_SUB:
	.word BIGXPLOD15_IMG
	.half 49, 64, 41, 26
	
	
FLOORXPD1:
	.word FLOORXPD1_SUB,0
FLOORXPD1_SUB:
	.word FLOORXPD1_IMG
	.half 77, 76, 37, 73
	.word FXFIRE_P
FLOORXPD3:
	.word FLOORXPD3_SUB,0
FLOORXPD3_SUB:
	.word FLOORXPD3_IMG
	.half 88, 83, 39, 84
FLOORXPD5:
	.word FLOORXPD5_SUB,0
FLOORXPD5_SUB:
	.word FLOORXPD5_IMG
	.half 101, 83, 39, 99
FLOORXPD7:
	.word FLOORXPD7_SUB,0
FLOORXPD7_SUB:
	.word FLOORXPD7_IMG
	.half 115, 88, 41, 112
FLOORXPD9:
	.word FLOORXPD9_SUB,0
FLOORXPD9_SUB:
	.word FLOORXPD9_IMG
	.half 126, 94, 42, 123
FLOORXPD11:
	.word	FLOORXPD11_SUB,0
FLOORXPD11_SUB:
	.word FLOORXPD11_IMG
	.half 133, 99, 44, 131
FLOORXPD13:
	.word	FLOORXPD13_SUB,0
FLOORXPD13_SUB:
	.word FLOORXPD13_IMG
	.half 137, 100, 44, 134
FLOORXPD19:
	.word	FLOORXPD19_SUB,0
FLOORXPD19_SUB:
	.word FLOORXPD19_IMG
	.half 43, 47, 25, 41
FLOORXPD21:
	.word	FLOORXPD21_SUB,0
FLOORXPD21_SUB:
	.word FLOORXPD21_IMG
	.half 19, 27, 8, 16
SMALLXPD1:
	.word SMALLXPD1_IMG
	.half 53, 48, 24, 26
	.word  SMLXPLD_P
SMALLXPD2:
	.word SMALLXPD2_IMG
	.half 58, 54, 26, 28
SMALLXPD3:
	.word SMALLXPD3_IMG
	.half 43, 40, 21, 20
SMALLXPD4:
	.word SMALLXPD4_IMG
	.half 43, 44, 22, 20
SMALLXPD5:
	.word SMALLXPD5_IMG
	.half 43, 40, 22, 20
SMALLXPD6:
	.word SMALLXPD6_IMG
	.half 38, 42, 23, 22
SMALLXPD7:
	.word SMALLXPD7_IMG
	.half 39, 43, 24, 23
SMALLXPD8:
	.word SMALLXPD8_IMG
	.half 40, 45, 26, 24
SMALLXPD9:
	.word SMALLXPD9_IMG
	.half 38, 44, 26, 25
SMALLXPD10:
	.word SMALLXPD10_IMG
	.half 32, 42, 25, 19
SMALLXPD11:
	.word SMALLXPD11_IMG
	.half 32, 31, 13, 19
SMALLXPD12:
	.word SMALLXPD12_IMG
	.half 27, 30, 12, 14
SMALLXPD13:
	.word SMALLXPD13_IMG
	.half 27, 26, 7, 14
SMALLXPD14:
	.word SMALLXPD14_IMG
	.half 24, 24, 6, 13
SMALLXPD15:
	.word SMALLXPD15_IMG
	.half 23, 22, 4, 12

	.align 2
	.globl explode_dict
explode_dict:	
#include "../common/explode/explode.dct"

	.align 2
#include "../common/explode/explode.att"

/*
;******************************************************************************
;	Various Fonts Graphics (fonts.adt)
;******************************************************************************
*/

	.align 2
	.globl preload_fonts
preload_fonts:
	.word SMALLFONT_0
	.word SMALLFONT_1
	.word SMALLFONT_2
	.word SMALLFONT_3
	.word SMALLFONT_4
	.word SMALLFONT_5
	.word SMALLFONT_6
	.word SMALLFONT_7
	.word SMALLFONT_8
	.word SMALLFONT_9
	.word SMALLFONT_A
	.word SMALLFONT_B
	.word SMALLFONT_C
	.word SMALLFONT_D
	.word SMALLFONT_E
	.word SMALLFONT_F
	.word SMALLFONT_G
	.word SMALLFONT_H
	.word SMALLFONT_I
	.word SMALLFONT_J
	.word SMALLFONT_K
	.word SMALLFONT_L
	.word SMALLFONT_M
	.word SMALLFONT_N
	.word SMALLFONT_O
	.word SMALLFONT_P
	.word SMALLFONT_Q
	.word SMALLFONT_R
	.word SMALLFONT_S
	.word SMALLFONT_T
	.word SMALLFONT_U
	.word SMALLFONT_V
	.word SMALLFONT_W
	.word SMALLFONT_X
	.word SMALLFONT_Y
	.word SMALLFONT_Z
	.word register			/* [ */
	.word trademark			/* \ */
	.word copyright			/* ]*/
	.word BIGFONT_0
	.word BIGFONT_1
	.word BIGFONT_2
	.word BIGFONT_3
	.word BIGFONT_4
	.word BIGFONT_5
	.word BIGFONT_6
	.word BIGFONT_7
	.word BIGFONT_8
	.word BIGFONT_9
	.word BIGFONT_COL
	.word BIGFONT_QUE
	.word BIGFONT_A
	.word BIGFONT_B
	.word BIGFONT_C
	.word BIGFONT_D
	.word BIGFONT_E
	.word BIGFONT_F
	.word BIGFONT_G
	.word BIGFONT_H
	.word BIGFONT_I
	.word BIGFONT_J
	.word BIGFONT_K
	.word BIGFONT_L
	.word BIGFONT_M
	.word BIGFONT_N
	.word BIGFONT_O
	.word BIGFONT_P
	.word BIGFONT_Q
	.word BIGFONT_R
	.word BIGFONT_S
	.word BIGFONT_T
	.word BIGFONT_U
	.word BIGFONT_V
	.word BIGFONT_W
	.word BIGFONT_X
	.word BIGFONT_Y
	.word BIGFONT_Z
	.word FONT7N0
	.word FONT7N1
	.word FONT7N2
	.word FONT7N3
	.word FONT7N4
	.word FONT7N5
	.word FONT7N6
	.word FONT7N7
	.word FONT7N8
	.word FONT7N9
	.word FONT7Ncolon
	.word FONT7Nsemicol
	.word FONT7Nless
	.word FONT7Nequal
	.word FONT7Nmore
	.word FONT7Nquest
	.word FONT7Nline
	.word FONT7NA
	.word FONT7NB
	.word FONT7NC
	.word FONT7ND
	.word FONT7NE
	.word FONT7NF
	.word FONT7NG
	.word FONT7NH
	.word FONT7NI
	.word FONT7NJ
	.word FONT7NK
	.word FONT7NL
	.word FONT7NM
	.word FONT7NN
	.word FONT7NO
	.word FONT7NP
	.word FONT7NQ
	.word FONT7NR
	.word FONT7NS
	.word FONT7NT
	.word FONT7NU
	.word FONT7NV
	.word FONT7NW
	.word FONT7NX
	.word FONT7NY
	.word FONT7NZ
	.word 0




	.align 2
	.globl font7_panel_info
font7_panel_info:
	.word SMALLFONT_EXC
	.word SMALLFONT_QUE
	.word FONT7Napost
	.word FONT7Napost
	.word SMALLFONT_PERC
	.word FONT7Napost
	.word FONT7Napost
	.word SMALLFONT_PR1
	.word SMALLFONT_PR2
	.word FONT7Napost
	.word FONT7Napost
	.word SMALLFONT_COM
	.word SMALLFONT_MIN
	.word SMALLFONT_PER
	.word SMALLFONT_SLA
	.word SMALLFONT_0
	.word SMALLFONT_1
	.word SMALLFONT_2
	.word SMALLFONT_3
	.word SMALLFONT_4
	.word SMALLFONT_5
	.word SMALLFONT_6
	.word SMALLFONT_7
	.word SMALLFONT_8
	.word SMALLFONT_9
	.word SMALLFONT_COL
	.word SMALLFONT_COL
	.word SMALLFONT_COL
	.word SMALLFONT_COL
	.word SMALLFONT_COL
	.word FONT7Nquest
	.word SMALLFONT_COL
	.word SMALLFONT_A
	.word SMALLFONT_B
	.word SMALLFONT_C
	.word SMALLFONT_D
	.word SMALLFONT_E
	.word SMALLFONT_F
	.word SMALLFONT_G
	.word SMALLFONT_H
	.word SMALLFONT_I
	.word SMALLFONT_J
	.word SMALLFONT_K
	.word SMALLFONT_L
	.word SMALLFONT_M
	.word SMALLFONT_N
	.word SMALLFONT_O
	.word SMALLFONT_P
	.word SMALLFONT_Q
	.word SMALLFONT_R
	.word SMALLFONT_S
	.word SMALLFONT_T
	.word SMALLFONT_U
	.word SMALLFONT_V
	.word SMALLFONT_W
	.word SMALLFONT_X
	.word SMALLFONT_Y
	.word SMALLFONT_Z
	.word register			/* [ */
	.word trademark			/* \ */
	.word copyright			/* ]*/
	
	.align 2
	.globl font15_panel_info
font15_panel_info:	 
	.word BIGFONT_EXC
	.word FONT7Napost
	.word FONT7Napost
	.word FONT7Napost
	.word BIGFONT_PERC
	.word FONT7Napost
	.word FONT7Napost
	.word BIGFONT_PR1
	.word BIGFONT_PR2
	.word FONT7Napost
	.word FONT7Napost
	.word BIGFONT_COM
	.word BIGFONT_MIN
	.word BIGFONT_PER
	.word BIGFONT_SLA
	.word BIGFONT_0
	.word BIGFONT_1
	.word BIGFONT_2
	.word BIGFONT_3
	.word BIGFONT_4
	.word BIGFONT_5
	.word BIGFONT_6
	.word BIGFONT_7
	.word BIGFONT_8
	.word BIGFONT_9
	.word BIGFONT_COL
	.word BIGFONT_COL
	.word BIGFONT_COL
	.word BIGFONT_COL
	.word BIGFONT_COL
	.word BIGFONT_QUE
	.word BIGFONT_QUE
	.word BIGFONT_A
	.word BIGFONT_B
	.word BIGFONT_C
	.word BIGFONT_D
	.word BIGFONT_E
	.word BIGFONT_F
	.word BIGFONT_G
	.word BIGFONT_H
	.word BIGFONT_I
	.word BIGFONT_J
	.word BIGFONT_K
	.word BIGFONT_L
	.word BIGFONT_M
	.word BIGFONT_N
	.word BIGFONT_O
	.word BIGFONT_P
	.word BIGFONT_Q
	.word BIGFONT_R
	.word BIGFONT_S
	.word BIGFONT_T
	.word BIGFONT_U
	.word BIGFONT_V
	.word BIGFONT_W
	.word BIGFONT_X
	.word BIGFONT_Y
	.word BIGFONT_Z
	.word register			/* [ */
	.word trademark			/* \ */
	.word copyright			/* ]*/
	
	.align 2
	.globl font7N_panel_info
font7N_panel_info:
	.word FONT7Nexcla
	.word FONT7Nquote
	.word FONT7Npound
	.word FONT7Ndoll
	.word FONT7Npercen
	.word FONT7Nand
	.word FONT7Napost
	.word FONT7Nparenl
	.word FONT7Nparenr
	.word FONT7Nast
	.word FONT7Nplus
	.word FONT7Ncomma
	.word FONT7Ndash
	.word FONT7Nperiod
	.word FONT7Nforsp
	.word FONT7N0
	.word FONT7N1
	.word FONT7N2
	.word FONT7N3
	.word FONT7N4
	.word FONT7N5
	.word FONT7N6
	.word FONT7N7
	.word FONT7N8
	.word FONT7N9
	.word FONT7Ncolon
	.word FONT7Nsemicol
	.word FONT7Nless
	.word FONT7Nequal
	.word FONT7Nmore
	.word FONT7Nquest
	.word FONT7Nline
	.word FONT7NA
	.word FONT7NB
	.word FONT7NC
	.word FONT7ND
	.word FONT7NE
	.word FONT7NF
	.word FONT7NG
	.word FONT7NH
	.word FONT7NI
	.word FONT7NJ
	.word FONT7NK
	.word FONT7NL
	.word FONT7NM
	.word FONT7NN
	.word FONT7NO
	.word FONT7NP
	.word FONT7NQ
	.word FONT7NR
	.word FONT7NS
	.word FONT7NT
	.word FONT7NU
	.word FONT7NV
	.word FONT7NW
	.word FONT7NX
	.word FONT7NY
	.word FONT7NZ
	.word register			/* [ */
	.word trademark			/* \ */
	.word copyright			/* ]*/
	.word FONT7Nexcla



	.globl FONT7Nexcla
FONT7Nexcla:
	.word FONT7excla_IMG
	.half 7, 2, 0, 0
	.globl FONT7Nquote
FONT7Nquote:
	.word FONT7quote_IMG
	.half 3, 5, 0, 0
	.globl FONT7Npound
FONT7Npound:
	.word FONT7pound_IMG
	.half 7, 8, 0, 0
	.globl FONT7Ndoll
FONT7Ndoll:
	.word FONT7doll_IMG
	.half 8, 5, 0, 1
	.globl FONT7Npercen
FONT7Npercen:
	.word FONT7percen_IMG
	.half 7, 9, 0, 0
	.globl FONT7Nand
FONT7Nand:
	.word FONT7and_IMG
	.half 7, 6, 0, 0
	.globl FONT7Napost
FONT7Napost:
	.word FONT7apost_IMG
	.half 3, 2, 0, 1
	.globl FONT7Nparenl
FONT7Nparenl:
	.word FONT7parenl_IMG
	.half 9, 2, 0, 1
	.globl FONT7Nparenr
FONT7Nparenr:
	.word FONT7parenr_IMG
	.half 9, 2, 0, 1
	.globl FONT7Nast
FONT7Nast:
	.word FONT7ast_IMG
	.half 7, 6, 1, 0
	.globl FONT7Nplus
FONT7Nplus:
	.word FONT7plus_IMG
	.half 5, 5, 0, -1
	.globl FONT7Ncomma
FONT7Ncomma:
	.word FONT7comma_IMG
	.half 3, 2, 0, -5
	.globl FONT7Ndash
FONT7Ndash:
	.word FONT7dash_IMG
	.half 2, 4, 0, -3
	.globl FONT7Nperiod
FONT7Nperiod:
	.word FONT7period_IMG
	.half 2, 2, 0, -5
	.globl FONT7Nforsp
FONT7Nforsp:
	.word FONT7forsp_IMG
	.half 7, 4, 0, 0
	.globl FONT7N0
FONT7N0:
	.word FONT70_IMG
	.half 7, 5, 0, 0
	.globl FONT7N1
FONT7N1:
	.word FONT71_IMG
	.half 7, 3, 0, 0
	.globl FONT7N2
FONT7N2:
	.word FONT72_IMG
	.half 7, 5, 0, 0
	.globl FONT7N3
FONT7N3:
	.word FONT73_IMG
	.half 7, 5, 0, 0
	.globl FONT7N4
FONT7N4:
	.word FONT74_IMG
	.half 7, 5, 0, 0
	.globl FONT7N5
FONT7N5:
	.word FONT75_IMG
	.half 7, 5, 0, 0
	.globl FONT7N6
FONT7N6:
	.word FONT76_IMG
	.half 7, 5, 0, 0
	.globl FONT7N7
FONT7N7:
	.word FONT77_IMG
	.half 7, 5, 0, 0
	.globl FONT7N8
FONT7N8:
	.word FONT78_IMG
	.half 7, 5, 0, 0
	.globl FONT7N9
FONT7N9:
	.word FONT79_IMG
	.half 7, 5, 0, 0
	.globl FONT7Ncolon
FONT7Ncolon:
	.word FONT7colon_IMG
	.half 5, 2, 0, -1
	.globl FONT7Nsemicol
FONT7Nsemicol:
	.word FONT7semicol_IMG
	.half 7, 2, 0, 0
	.globl FONT7Nless
FONT7Nless:
	.word FONT7less_IMG
	.half 6, 3, 0, 0
	.globl FONT7Nequal
FONT7Nequal:
	.word FONT7equal_IMG
	.half 4, 4, 0, -2
	.globl FONT7Nmore
FONT7Nmore:
	.word FONT7more_IMG
	.half 6, 3, 0, 0
	.globl FONT7Nquest
FONT7Nquest:
	.word FONT7quest_IMG
	.half 7, 5, 0, 0
	.globl FONT7Nline
FONT7Nline:
	.word FONT7line_IMG
	.half 2, 5, 0, -4
	.globl FONT7NA
FONT7NA:
	.word FONT7A_IMG
	.half 7, 5, 0, 0
	.globl FONT7NB
FONT7NB:
	.word FONT7B_IMG
	.half 7, 5, 0, 0
	.globl FONT7NC
FONT7NC:
	.word FONT7C_IMG
	.half 7, 5, 0, 0
	.globl FONT7ND
FONT7ND:
	.word FONT7D_IMG
	.half 7, 5, 0, 0
	.globl FONT7NE
FONT7NE:
	.word FONT7E_IMG
	.half 7, 5, 0, 0
	.globl FONT7NF
FONT7NF:
	.word FONT7F_IMG
	.half 7, 5, 0, 0
	.globl FONT7NG
FONT7NG:
	.word FONT7G_IMG
	.half 7, 5, 0, 0
	.globl FONT7NH
FONT7NH:
	.word FONT7H_IMG
	.half 7, 5, 0, 0
	.globl FONT7NI
FONT7NI:
	.word FONT7I_IMG
	.half 7, 2, 0, 0
	.globl FONT7NJ
FONT7NJ:
	.word FONT7J_IMG
	.half 7, 5, 0, 0
	.globl FONT7NK
FONT7NK:
	.word FONT7K_IMG
	.half 7, 5, 0, 0
	.globl FONT7NL
FONT7NL:
	.word FONT7L_IMG
	.half 7, 4, 0, 0
	.globl FONT7NM
FONT7NM:
	.word FONT7M_IMG
	.half 7, 8, 0, 0
	.globl FONT7NN
FONT7NN:
	.word FONT7N_IMG
	.half 7, 6, 0, 0
	.globl FONT7NO
FONT7NO:
	.word FONT7O_IMG
	.half 7, 6, 0, 0
	.globl FONT7NP
FONT7NP:
	.word FONT7P_IMG
	.half 7, 5, 0, 0
	.globl FONT7NQ
FONT7NQ:
	.word FONT7Q_IMG
	.half 9, 6, 0, 0
	.globl FONT7NR
FONT7NR:
	.word FONT7R_IMG
	.half 7, 5, 0, 0
	.globl FONT7NS
FONT7NS:
	.word FONT7S_IMG
	.half 7, 5, 0, 0
	.globl FONT7NT
FONT7NT:
	.word FONT7T_IMG
	.half 7, 5, 0, 0
	.globl FONT7NU
FONT7NU:
	.word FONT7U_IMG
	.half 7, 5, 0, 0
	.globl FONT7NV
FONT7NV:
	.word FONT7V_IMG
	.half 7, 6, 0, 0
	.globl FONT7NW
FONT7NW:
	.word FONT7W_IMG
	.half 7, 9, 0, 0
	.globl FONT7NX
FONT7NX:
	.word FONT7X_IMG
	.half 7, 6, 0, 0
	.globl FONT7NY
FONT7NY:
	.word FONT7Y_IMG
	.half 7, 5, 0, 0
	.globl FONT7NZ
FONT7NZ:
	.word FONT7Z_IMG
	.half 7, 5, 0, 0
	
	.globl SMALLFONT_0
SMALLFONT_0:
	.word SMALLFONT_0_IMG
	.half 9, 8, 0, 0
	.globl SMALLFONT_1
SMALLFONT_1:
	.word SMALLFONT_1_IMG
	.half 9, 6, 0, 0
	.globl SMALLFONT_2
SMALLFONT_2:
	.word SMALLFONT_2_IMG
	.half 9, 8, 0, 0
	.globl SMALLFONT_3
SMALLFONT_3:
	.word SMALLFONT_3_IMG
	.half 9, 8, 0, 0
	.globl SMALLFONT_4
SMALLFONT_4:
	.word SMALLFONT_4_IMG
	.half 9, 7, 0, 0
	.globl SMALLFONT_5
SMALLFONT_5:
	.word SMALLFONT_5_IMG
	.half 9, 7, 0, 0
	.globl SMALLFONT_6
SMALLFONT_6:
	.word SMALLFONT_6_IMG
	.half 9, 8, 0, 0
	.globl SMALLFONT_7
SMALLFONT_7:
	.word SMALLFONT_7_IMG
	.half 9, 8, 0, 0
	.globl SMALLFONT_8
SMALLFONT_8:
	.word SMALLFONT_8_IMG
	.half 10, 8, 0, 0
	.globl SMALLFONT_9
SMALLFONT_9:
	.word SMALLFONT_9_IMG
	.half 9, 7, 0, 0
	.globl SMALLFONT_A
SMALLFONT_A:
	.word SMALLFONT_A_IMG
	.half 10, 9, 0, 0
	.globl SMALLFONT_B
SMALLFONT_B:
	.word SMALLFONT_B_IMG
	.half 9, 9, 0, 0
	.globl SMALLFONT_C
SMALLFONT_C:
	.word SMALLFONT_C_IMG
	.half 9, 6, 0, 0
	.globl SMALLFONT_D
SMALLFONT_D:
	.word SMALLFONT_D_IMG
	.half 9, 9, 0, 0
	.globl SMALLFONT_E
SMALLFONT_E:
	.word SMALLFONT_E_IMG
	.half 9, 8, 0, 0
	.globl SMALLFONT_F
SMALLFONT_F:
	.word SMALLFONT_F_IMG
	.half 10, 8, 0, 0
	.globl SMALLFONT_G
SMALLFONT_G:
	.word SMALLFONT_G_IMG
	.half 9, 8, 0, 0
	.globl SMALLFONT_H
SMALLFONT_H:
	.word SMALLFONT_H_IMG
	.half 10, 10, 0, 0
	.globl SMALLFONT_I
SMALLFONT_I:
	.word SMALLFONT_I_IMG
	.half 9, 6, 0, 0
	.globl SMALLFONT_J
SMALLFONT_J:
	.word SMALLFONT_J_IMG
	.half 11, 7, 0, 0
	.globl SMALLFONT_K
SMALLFONT_K:
	.word SMALLFONT_K_IMG
	.half 9, 10, 0, 0
	.globl SMALLFONT_L
SMALLFONT_L:
	.word SMALLFONT_L_IMG
	.half 9, 6, 0, 0
	.globl SMALLFONT_M
SMALLFONT_M:
	.word SMALLFONT_M_IMG
	.half 9, 10, 0, 0
	.globl SMALLFONT_N
SMALLFONT_N:
	.word SMALLFONT_N_IMG
	.half 9, 10, 0, 0
	.globl SMALLFONT_O
SMALLFONT_O:
	.word SMALLFONT_O_IMG
	.half 9, 8, 0, 0
	.globl SMALLFONT_P
SMALLFONT_P:
	.word SMALLFONT_P_IMG
	.half 9, 9, 0, 0
	.globl SMALLFONT_Q
SMALLFONT_Q:
	.word SMALLFONT_Q_IMG
	.half 9, 9, 0, 1
	.globl SMALLFONT_R
SMALLFONT_R:
	.word SMALLFONT_R_IMG
	.half 10, 10, 0, 0
	.globl SMALLFONT_S
SMALLFONT_S:
	.word SMALLFONT_S_IMG
	.half 9, 7, 0, 0
	.globl SMALLFONT_T
SMALLFONT_T:
	.word SMALLFONT_T_IMG
	.half 9, 7, 0, 0
	.globl SMALLFONT_U
SMALLFONT_U:
	.word SMALLFONT_U_IMG
	.half 9, 8, 0, 0
	.globl SMALLFONT_V
SMALLFONT_V:
	.word SMALLFONT_V_IMG
	.half 9, 8, 0, 0
	.globl SMALLFONT_W
SMALLFONT_W:
	.word SMALLFONT_W_IMG
	.half 9, 11, 0, 0
	.globl SMALLFONT_X
SMALLFONT_X:
	.word SMALLFONT_X_IMG
	.half 9, 10, 0, 0
	.globl SMALLFONT_Y
SMALLFONT_Y:
	.word SMALLFONT_Y_IMG
	.half 10, 8, 0, 0
	.globl SMALLFONT_Z
SMALLFONT_Z:
	.word SMALLFONT_Z_IMG
	.half 9, 9, 0, 0
	.globl SMALLFONT_PER
SMALLFONT_PER:
	.word SMALLFONT_PER_IMG
	.half 3, 3, 0, -5
	.globl SMALLFONT_COL
SMALLFONT_COL:
	.word SMALLFONT_COL_IMG
	.half 7, 5, 0, -1
	.globl SMALLFONT_COM
SMALLFONT_COM:
	.word SMALLFONT_COM_IMG
	.half 4, 4, 0, -4
	.globl SMALLFONT_EXC
SMALLFONT_EXC:
	.word SMALLFONT_EXC_IMG
	.half 9, 6, 0, 0
	.globl SMALLFONT_MIN
SMALLFONT_MIN:
	.word SMALLFONT_MIN_IMG
	.half 3, 5, 0, -2
	.globl SMALLFONT_PERC
SMALLFONT_PERC:
	.word SMALLFONT_PERC_IMG
	.half 9, 10, 0, 0
	.globl SMALLFONT_PR1
SMALLFONT_PR1:
	.word SMALLFONT_PR1_IMG
	.half 10, 7, 0, 0
	.globl SMALLFONT_PR2
SMALLFONT_PR2:
	.word SMALLFONT_PR2_IMG
	.half 10, 7, 0, 0
	.globl SMALLFONT_QUE
SMALLFONT_QUE:
	.word SMALLFONT_QUE_IMG
	.half 9, 6, 0, 0
	.globl SMALLFONT_SLA
SMALLFONT_SLA:
	.word SMALLFONT_SLA_IMG
	.half 11, 9, 0, 0
	.globl MEDFONT_0
MEDFONT_0:
	.word MEDFONT_0_IMG
	.half 10, 10, 0, 0
	.globl MEDFONT_1
MEDFONT_1:
	.word MEDFONT_1_IMG
	.half 10, 6, 0, 0
	.globl MEDFONT_2
MEDFONT_2:
	.word MEDFONT_2_IMG
	.half 10, 10, 0, 0
	.globl MEDFONT_3
MEDFONT_3:
	.word MEDFONT_3_IMG
	.half 10, 9, 0, 0
	.globl MEDFONT_4
MEDFONT_4:
	.word MEDFONT_4_IMG
	.half 10, 9, 0, 0
	.globl MEDFONT_5
MEDFONT_5:
	.word MEDFONT_5_IMG
	.half 10, 9, 0, 0
	.globl MEDFONT_6
MEDFONT_6:
	.word MEDFONT_6_IMG
	.half 10, 8, 0, 0
	.globl MEDFONT_7
MEDFONT_7:
	.word MEDFONT_7_IMG
	.half 10, 9, 0, 0
	.globl MEDFONT_8
MEDFONT_8:
	.word MEDFONT_8_IMG
	.half 10, 10, 0, 0
	.globl MEDFONT_9
MEDFONT_9:
	.word MEDFONT_9_IMG
	.half 10, 9, 0, 0
	.globl MEDFONT_A
MEDFONT_A:
	.word MEDFONT_A_IMG
	.half 12, 11, 0, 0
	.globl MEDFONT_B
MEDFONT_B:
	.word MEDFONT_B_IMG
	.half 10, 10, 0, 0
	.globl MEDFONT_C
MEDFONT_C:
	.word MEDFONT_C_IMG
	.half 10, 8, 0, 0
	.globl MEDFONT_D
MEDFONT_D:
	.word MEDFONT_D_IMG
	.half 10, 11, 0, 0
	.globl MEDFONT_E
MEDFONT_E:
	.word MEDFONT_E_IMG
	.half 10, 10, 0, 0
	.globl MEDFONT_F
MEDFONT_F:
	.word MEDFONT_F_IMG
	.half 12, 10, 0, 0
	.globl MEDFONT_G
MEDFONT_G:
	.word MEDFONT_G_IMG
	.half 10, 10, 0, 0
	.globl MEDFONT_H
MEDFONT_H:
	.word MEDFONT_H_IMG
	.half 12, 12, 0, 0
	.globl MEDFONT_I
MEDFONT_I:
	.word MEDFONT_I_IMG
	.half 10, 6, 0, 0
	.globl MEDFONT_J
MEDFONT_J:
	.word MEDFONT_J_IMG
	.half 13, 9, 0, 0
	.globl MEDFONT_K
MEDFONT_K:
	.word MEDFONT_K_IMG
	.half 10, 11, 0, 0
	.globl MEDFONT_L
MEDFONT_L:
	.word MEDFONT_L_IMG
	.half 10, 7, 0, 0
	.globl MEDFONT_M
MEDFONT_M:
	.word MEDFONT_M_IMG
	.half 10, 12, 0, 0
	.globl MEDFONT_N
MEDFONT_N:
	.word MEDFONT_N_IMG
	.half 10, 11, 0, 0
	.globl MEDFONT_O
MEDFONT_O:
	.word MEDFONT_O_IMG
	.half 10, 10, 0, 0
	.globl MEDFONT_P
MEDFONT_P:
	.word MEDFONT_P_IMG
	.half 10, 10, 0, 0
	.globl MEDFONT_Q
MEDFONT_Q:
	.word MEDFONT_Q_IMG
	.half 10, 10, 0, 0
	.globl MEDFONT_R
MEDFONT_R:
	.word MEDFONT_R_IMG
	.half 12, 10, 0, 0
	.globl MEDFONT_S
MEDFONT_S:
	.word MEDFONT_S_IMG
	.half 10, 9, 0, 0
	.globl MEDFONT_T
MEDFONT_T:
	.word MEDFONT_T_IMG
	.half 10, 9, 0, 0
	.globl MEDFONT_U
MEDFONT_U:
	.word MEDFONT_U_IMG
	.half 10, 10, 0, 0
	.globl MEDFONT_V
MEDFONT_V:
	.word MEDFONT_V_IMG
	.half 10, 10, 0, 0
	.globl MEDFONT_W
MEDFONT_W:
	.word MEDFONT_W_IMG
	.half 10, 14, 0, 0
	.globl MEDFONT_X
MEDFONT_X:
	.word MEDFONT_X_IMG
	.half 10, 11, 0, 0
	.globl MEDFONT_Y
MEDFONT_Y:
	.word MEDFONT_Y_IMG
	.half 12, 9, 0, 0
	.globl MEDFONT_Z
MEDFONT_Z:
	.word MEDFONT_Z_IMG
	.half 10, 10, 0, 0
	.globl MEDFONT_PER
MEDFONT_PER:
	.word MEDFONT_PER_IMG
	.half 3, 3, 0, -7
	.globl MEDFONT_COL
MEDFONT_COL:
	.word MEDFONT_COL_IMG
	.half 8, 5, 0, -1
	.globl MEDFONT_COM
MEDFONT_COM:
	.word MEDFONT_COM_IMG
	.half 4, 5, 0, -7
	.globl MEDFONT_EXC
MEDFONT_EXC:
	.word MEDFONT_EXC_IMG
	.half 10, 6, 0, 0
	.globl MEDFONT_MIN
MEDFONT_MIN:
	.word MEDFONT_MIN_IMG
	.half 3, 6, -1, -2
	.globl MEDFONT_PERC
MEDFONT_PERC:
	.word MEDFONT_PERC_IMG
	.half 12, 13, 0, 0
	.globl MEDFONT_PR1
MEDFONT_PR1:
	.word MEDFONT_PR1_IMG
	.half 13, 9, 0, 0
	.globl MEDFONT_PR2
MEDFONT_PR2:
	.word MEDFONT_PR2_IMG
	.half 13, 9, 0, 0
	.globl MEDFONT_QUE
MEDFONT_QUE:
	.word MEDFONT_QUE_IMG
	.half 10, 8, 0, 0
	.globl MEDFONT_SLA
MEDFONT_SLA:
	.word MEDFONT_SLA_IMG
	.half 13, 10, 0, 1
	.globl BIGFONT_0
BIGFONT_0:
	.word BIGFONT_0_IMG
	.half 13, 13, 0, 0
	.globl BIGFONT_1
BIGFONT_1:
	.word BIGFONT_1_IMG
	.half 13, 8, 0, 0
	.globl BIGFONT_2
BIGFONT_2:
	.word BIGFONT_2_IMG
	.half 13, 12, 0, 0
	.globl BIGFONT_3
BIGFONT_3:
	.word BIGFONT_3_IMG
	.half 13, 11, 0, 0
	.globl BIGFONT_4
BIGFONT_4:
	.word BIGFONT_4_IMG
	.half 13, 11, 0, 0
	.globl BIGFONT_5
BIGFONT_5:
	.word BIGFONT_5_IMG
	.half 13, 10, 0, 0
	.globl BIGFONT_6
BIGFONT_6:
	.word BIGFONT_6_IMG
	.half 14, 10, 0, 0
	.globl BIGFONT_7
BIGFONT_7:
	.word BIGFONT_7_IMG
	.half 13, 12, 0, 0
	.globl BIGFONT_8
BIGFONT_8:
	.word BIGFONT_8_IMG
	.half 14, 12, 0, 0
	.globl BIGFONT_9
BIGFONT_9:
	.word BIGFONT_9_IMG
	.half 14, 11, 0, 0
	.globl BIGFONT_A
BIGFONT_A:
	.word BIGFONT_A_IMG
	.half 14, 14, 0, 0
	.globl BIGFONT_B
BIGFONT_B:
	.word BIGFONT_B_IMG
	.half 13, 14, 0, 0
	.globl BIGFONT_C
BIGFONT_C:
	.word BIGFONT_C_IMG
	.half 13, 10, 0, 0
	.globl BIGFONT_D
BIGFONT_D:
	.word BIGFONT_D_IMG
	.half 13, 13, 1, 0
	.globl BIGFONT_E
BIGFONT_E:
	.word BIGFONT_E_IMG
	.half 13, 13, 0, 0
	.globl BIGFONT_F
BIGFONT_F:
	.word BIGFONT_F_IMG
	.half 15, 12, 0, 0
	.globl BIGFONT_G
BIGFONT_G:
	.word BIGFONT_G_IMG
	.half 13, 12, 0, 0
	.globl BIGFONT_H
BIGFONT_H:
	.word BIGFONT_H_IMG
	.half 14, 15, 0, 0
	.globl BIGFONT_I
BIGFONT_I:
	.word BIGFONT_I_IMG
	.half 13, 9, 0, 0
	.globl BIGFONT_J
BIGFONT_J:
	.word BIGFONT_J_IMG
	.half 16, 11, 0, 0
	.globl BIGFONT_K
BIGFONT_K:
	.word BIGFONT_K_IMG
	.half 13, 14, 0, 0
	.globl BIGFONT_L
BIGFONT_L:
	.word BIGFONT_L_IMG
	.half 13, 10, 2, 0
	.globl BIGFONT_M
BIGFONT_M:
	.word BIGFONT_M_IMG
	.half 13, 16, 0, 0
	.globl BIGFONT_N
BIGFONT_N:
	.word BIGFONT_N_IMG
	.half 13, 14, 1, 0
	.globl BIGFONT_O
BIGFONT_O:
	.word BIGFONT_O_IMG
	.half 13, 13, 0, 0
	.globl BIGFONT_P
BIGFONT_P:
	.word BIGFONT_P_IMG
	.half 13, 13, 0, 0
	.globl BIGFONT_Q
BIGFONT_Q:
	.word BIGFONT_Q_IMG
	.half 14, 12, 0, 0
	.globl BIGFONT_R
BIGFONT_R:
	.word BIGFONT_R_IMG
	.half 14, 14, 0, 0
	.globl BIGFONT_S
BIGFONT_S:
	.word BIGFONT_S_IMG
	.half 13, 10, 0, 0
	.globl BIGFONT_T
BIGFONT_T:
	.word BIGFONT_T_IMG
	.half 13, 11, -1, 0
	.globl BIGFONT_U
BIGFONT_U:
	.word BIGFONT_U_IMG
	.half 13, 14, 0, 0
	.globl BIGFONT_V
BIGFONT_V:
	.word BIGFONT_V_IMG
	.half 13, 12, 0, 0
	.globl BIGFONT_W
BIGFONT_W:
	.word BIGFONT_W_IMG
	.half 13, 18, 0, 0
	.globl BIGFONT_X
BIGFONT_X:
	.word BIGFONT_X_IMG
	.half 13, 15, 1, 0
	.globl BIGFONT_Y
BIGFONT_Y:
	.word BIGFONT_Y_IMG
	.half 14, 12, 0, 0
	.globl BIGFONT_Z
BIGFONT_Z:
	.word BIGFONT_Z_IMG
	.half 13, 14, 1, 0
	.globl BIGFONT_PER
BIGFONT_PER:
	.word BIGFONT_PER_IMG
	.half 4, 5, 0, -8
	.globl BIGFONT_COL
BIGFONT_COL:
	.word BIGFONT_COL_IMG
	.half 10, 6, 0, -1
	.globl BIGFONT_COM
BIGFONT_COM:
	.word BIGFONT_COM_IMG
	.half 5, 6, 0, -8
	.globl BIGFONT_EXC
BIGFONT_EXC:
	.word BIGFONT_EXC_IMG
	.half 13, 8, 0, 0
	.globl BIGFONT_MIN
BIGFONT_MIN:
	.word BIGFONT_MIN_IMG
	.half 4, 7, 0, -5
	.globl BIGFONT_PERC
BIGFONT_PERC:
	.word BIGFONT_PERC_IMG
	.half 13, 15, 0, 0
	.globl BIGFONT_PR1
BIGFONT_PR1:
	.word BIGFONT_PR1_IMG
	.half 16, 11, 0, 0
	.globl BIGFONT_PR2
BIGFONT_PR2:														 
	.word BIGFONT_PR2_IMG
	.half 16, 11, 0, 0
	.globl BIGFONT_QUE
BIGFONT_QUE:
	.word BIGFONT_QUE_IMG
	.half 13, 10, 0, 0
	.globl BIGFONT_SLA
BIGFONT_SLA:
	.word BIGFONT_SLA_IMG
	.half 16, 14, 0, 0

trademark:
	.word trademark_IMG
	.half 4, 9, 0, 0
copyright:
	.word copyright_IMG
	.half 9, 8, 0, 0
register:
	.word register_IMG
	.half 9, 8, 0, 0
 
	.align 2
#include "../common/fonts/mkfont.att"

	.align 2 
	.globl font_dict
font_dict:
#include "../common/fonts/mkfont.dct"

/*
;******************************************************************************
;	Various Blood Graphics (blood.adt)
;******************************************************************************
*/
	.align 2
	.globl preload_blood
preload_blood:
	.word ARM01
	.word ARM02
	.word ARM03
	.word ARM04
	.word ARM05
	.word ARM06
	.word ARM07
	.word ARM08
	.word ARM09
	.word ARM10
	.word ARM11
	.word ARM12
	.word ARM13
	.word ARM14
	.word ARM15
	.word ARM16
	.word ARM17
	.word ARM18
	.word ARM19
	.word ARM_B01
	.word ARM_B02
	.word ARM_B03
	.word ARM_B04
	.word ARM_B05
	.word ARM_B06
	.word ARM_B07
	.word ARM_B08
	.word ARM_B09
	.word ARM_B10
	.word ARM_B11
	.word ARM_B12
	.word LEG01
	.word LEG02
	.word LEG03
	.word LEG04
	.word LEG05
	.word LEG06
	.word LEG07
	.word LEG08
	.word LEG09
	.word LEG10
	.word LEG11
	.word LEG12
	.word LEG_B01
	.word LEG_B02
	.word LEG_B03
	.word LEG_B04
	.word LEG_B05
	.word LEG_B06
	.word LEG_B07
	.word LEG_B08
	.word LEG_B09
	.word LEG_B10
	.word LEG_B11
	.word LEG_B12
	.word XLIMB01
	.word XLIMB02
	.word XLIMB03
	.word XLIMB04
	.word XLIMB05
	.word XLIMB06
	.word XLIMB07
	.word XLIMB08
	.word XLIMB09
	.word XLIMB10
	.word XLIMB11
	.word XLIMB12
	.word BONE01
	.word BONE02
	.word BONE03
	.word BONE04
	.word BONE05
	.word BONE06
	.word BONE07
	.word BONE08
	.word BONE09
	.word BONE10
	.word BONE11
	.word BONE12
	.word CAGE01
	.word CAGE02
	.word CAGE03
	.word CAGE04
	.word CAGE05
	.word CAGE06
	.word CAGE07
	.word CAGE08
	.word CAGE09
	.word CAGE10
	.word CAGE11
	.word CAGE12
	.word SKULL01
	.word SKULL02
	.word SKULL03
	.word SKULL04
	.word SKULL05
	.word SKULL06
	.word SKULL07
	.word SKULL08
	.word SKULL09
	.word SKULL10
	.word SKULL11
	.word SKULL12
	.word SPLAT1
	.word SPLAT2
	.word SPLAT3
	.word SPLAT4
	.word SPLAT5
	.word SPLAT6
	.word SPLAT7
	.word SPRAY1
	.word SPRAY2
	.word SPRAY3
	.word SPRAY4
	.word SPRAY5
	.word SPRAY6
	.word SPRAY8
	.word SPRAY9
	.word SPRAY10
	.word SPRAY11
	.word SPRAY12
	.word SPRAY13
	.word BIGGERBLUD1
	.word BIGGERBLUD1
	.word BIGGERBLUD2
	.word BIGGERBLUD2
	.word BIGGERBLUD3
	.word BIGGERBLUD4
	.word BIGGERBLUD5
	.word BIGGERBLUD6
	.word DRIP1
	.word DRIP2
	.word DRIP3
	.word DRIP4
	.word DRIP5
	.word DRIP6
	.word DRIP7
	.word bludglob1
	.word bludglob2
	.word bludglob3
	.word bludglob4
	.word bludglob5
	.word bludglob6
	.word bludglob7
	.word bludglob8
	.word bludglob9
	.word bludglob10
	.word bludglob11
	.word bludglob12
	.word 0


	.extern	SMDRIP_P
	
	.align 2
	.globl a_blood_explode
a_blood_explode:
	.word BLDXPD1
	.word BLDXPD2
	.word BLDXPD3
	.word BLDXPD4
	.word BLDXPD5
	.word BLDXPD6
	.word BLDXPD7
	.word BLDXPD8
	.word BLDXPD9
	.word BLDXPD10
	.word BLDXPD11
	.word BLDXPD12
	.word BLDXPD13
	.word 0
	
	.globl a_pork
a_pork:
	.word PORK01
	.word PORK02
	.word PORK03
	.word PORK04
	.word PORK05
	.word PORK06
	.word PORK07
	.word PORK08
	.word PORK09
	.word PORK10
	.word PORK11
	.word PORK12
	.word ani_jump
	.word a_pork
	
	.globl a_arm
a_arm:
	.word ARM01
	.word ARM02
	.word ARM03
	.word ARM04
	.word ARM05
	.word ARM06
	.word ARM07
	.word ARM08
	.word ARM09
	.word ARM10
	.word ARM11
	.word ARM12
	.word ani_jump
	.word a_arm
	
	.globl a_arm_land
a_arm_land:
	.word ARM13
	.word ARM14
	.word ARM15
	.word ARM16
	.word ARM17
	.word ARM18
	.word ARM19
	
	.globl a_arm2
a_arm2:
	.word ARM_B01
	.word ARM_B02
	.word ARM_B03
	.word ARM_B04
	.word ARM_B05
	.word ARM_B06
	.word ARM_B07
	.word ARM_B08
	.word ARM_B09
	.word ARM_B10
	.word ARM_B11
	.word ARM_B12
	.word ani_jump
	.word a_arm2
	
	.globl a_leg
a_leg:
	.word LEG01
	.word LEG02
	.word LEG03
	.word LEG04
	.word LEG05
	.word LEG06
	.word LEG07
	.word LEG08
	.word LEG09
	.word LEG10
	.word LEG11
	.word LEG12
	.word ani_jump
	.word a_leg
	
	.globl a_leg2
a_leg2:
	.word LEG_B01
	.word LEG_B02
	.word LEG_B03
	.word LEG_B04
	.word LEG_B05
	.word LEG_B06
	.word LEG_B07
	.word LEG_B08
	.word LEG_B09
	.word LEG_B10
	.word LEG_B11
	.word LEG_B12
	.word ani_jump
	.word a_leg2
	
	.globl a_limb
a_limb:
	.word XLIMB01
	.word XLIMB02
	.word XLIMB03
	.word XLIMB04
	.word XLIMB05
	.word XLIMB06
	.word XLIMB07
	.word XLIMB08
	.word XLIMB09
	.word XLIMB10
	.word XLIMB11
	.word XLIMB12
	.word ani_jump
	.word a_limb
	
	.globl a_bone
a_bone:
	.word BONE01
	.word BONE02
	.word BONE03
	.word BONE04
	.word BONE05
	.word BONE06
	.word BONE07
	.word BONE08
	.word BONE09
	.word BONE10
	.word BONE11
	.word BONE12
	.word ani_jump
	.word a_bone
	
	.globl a_rib_cage
a_rib_cage:
	.word CAGE01
	.word CAGE02
	.word CAGE03
	.word CAGE04
	.word CAGE05
	.word CAGE06
	.word CAGE07
	.word CAGE08
	.word CAGE09
	.word CAGE10
	.word CAGE11
	.word CAGE12
	.word ani_jump
	.word a_rib_cage
	
	.globl a_skull
a_skull:
	.word SKULL01
	.word SKULL02
	.word SKULL03
	.word SKULL04
	.word SKULL05
	.word SKULL06
	.word SKULL07
	.word SKULL08
	.word SKULL09
	.word SKULL10
	.word SKULL11
	.word SKULL12
	.word ani_jump
	.word a_skull
	
	.globl a_goro_arm
a_goro_arm:
	.word GOROARM02
	.word GOROARM03
	.word GOROARM04
	.word GOROARM05
	.word GOROARM06
	.word GOROARM07
	.word GOROARM08
	.word GOROARM09
	.word GOROARM10
	.word GOROARM11
	.word GOROARM12
	.word ani_jump
	.word a_goro_arm
	
	.globl a_face_blood
	.globl preload_face_blood
preload_face_blood:
a_face_blood:
	.word SPLAT1
	.word SPLAT2
	.word SPLAT3
	.word SPLAT4
	.word SPLAT5
	.word SPLAT6
	.word SPLAT7
	.word 0
	
	.globl preload_decap_spray
	.globl a_decap_spray
a_decap_spray:
preload_decap_spray:
	.word SPRAY1
	.word SPRAY2
	.word SPRAY3
	.word SPRAY4
	.word SPRAY5
	.word SPRAY6
	.word SPRAY8
	.word SPRAY9
	.word SPRAY10
	.word SPRAY11
	.word SPRAY12
	.word SPRAY13
	.word 0
	
	.globl a_skinny_blood
a_skinny_blood:
	.word SMDRIP1
	.word SMDRIP2
	.word SMDRIP3
	.word 0
	.word SMDRIP4
	.word SMDRIP5
	.word SMDRIP6
	.word SMDRIP7
	.word 0
	.word SMDRIP8
	.word SMDRIP9
	.word 0
	
	.globl a_bigger
	.globl preload_bigger
a_bigger:
preload_bigger:
	.word BIGGERBLUD1
	.word BIGGERBLUD1
	.word BIGGERBLUD2
	.word BIGGERBLUD2
	.word BIGGERBLUD3
	.word BIGGERBLUD4
	.word BIGGERBLUD5
	.word BIGGERBLUD6
	.word 0
	
	.globl a_drip
	.globl preload_drip
a_drip:
preload_drip:
	.word DRIP1
	.word DRIP2
	.word DRIP3
	.word DRIP4
	.word 0
	
	.globl a_drip_splat
	.globl preload_drip_splat
a_drip_splat:
preload_drip_splat:
	.word DRIP5
	.word DRIP6
	.word DRIP7
	.word 0
	
	.globl a_rotate_12
	.globl preload_rotate_12
a_rotate_12:
preload_rotate_12:
	.word bludglob1
	.word bludglob2
	.word bludglob3
	.globl a_rotate_standard
a_rotate_standard:
	.word bludglob4
	.word bludglob5
	.globl a_rotate_9
a_rotate_9:
	.word bludglob6
	.word bludglob7
	.word bludglob8
	.globl a_rotate_7
a_rotate_7:
	.word bludglob9
	.word bludglob10
	.word bludglob11
	.word bludglob12
	.word 0
	.globl BIGBLD1
BIGBLD1:
	.word BIGBLD1_IMG
	.half 9, 14, 5, -22
	.word BLOOD_P
	.globl STAB1
STAB1:
	.word STAB1_IMG
	.half 9, 6, 0, 5
	.word BLOOD_P
SPLAT1:
	.word SPLAT1_IMG
	.half 9, 7, 0, 6
SPLAT2:
	.word SPLAT2_IMG
	.half 15, 15, 0, 13
SPLAT3:
	.word SPLAT3_IMG
	.half 27, 25, 1, 20
SPLAT4:
	.word SPLAT4_IMG
	.half 39, 26, -3, 29
SPLAT5:
	.word SPLAT5_IMG
	.half 45, 37, -1, 36
SPLAT6:
	.word SPLAT6_IMG
	.half 51, 39, -5, 37
SPLAT7:
	.word SPLAT7_IMG
	.half 43, 29, -12, 27
SPRAY1:
	.word SPRAY1_IMG
	.half 10, 9, -3, 12
SPRAY2:
	.word SPRAY2_IMG
	.half 20, 19, -4, 23
SPRAY3:
	.word SPRAY3_IMG
	.half 27, 25, -4, 30
SPRAY4:
	.word SPRAY4_IMG
	.half 40, 38, -4, 42
SPRAY5:
	.word SPRAY5_IMG
	.half 57, 52, -4, 54
SPRAY6:
	.word SPRAY6_IMG
	.half 70, 63, -4, 60
SPRAY8:
	.word SPRAY8_IMG
	.half 89, 90, -5, 60
SPRAY9:
	.word SPRAY9_IMG
	.half 64, 66, -6, 57
SPRAY10:
	.word SPRAY10_IMG
	.half 54, 76, -9, 52
SPRAY11:
	.word SPRAY11_IMG
	.half 51, 70, -9, 44
SPRAY12:
	.word SPRAY12_IMG
	.half 47, 54, -17, 37
SPRAY13:
	.word SPRAY13_IMG
	.half 38, 52, -23, 27
SMDRIP1:
	.word SMDRIP1_IMG
	.half 5, 2, 1, 0
	.word SMDRIP_P
SMDRIP2:
	.word SMDRIP2_IMG
	.half 9, 2, 1, 0
SMDRIP3:
	.word SMDRIP3_IMG
	.half 13, 2, 1, 0
SMDRIP4:
	.word SMDRIP4_IMG
	.half 13, 2, 1, -2
SMDRIP5:
	.word SMDRIP5_IMG
	.half 13, 2, 1, -13
SMDRIP6:
	.word SMDRIP6_IMG
	.half 13, 2, 1, -25
SMDRIP7:
	.word SMDRIP7_IMG
	.half 13, 2, 1, -36
SMDRIP8:
	.word SMDRIP8_IMG
	.half 10, 7, 4, -47
SMDRIP9:
	.word SMDRIP9_IMG
	.half 4, 14, 7, -54
BIGGERBLUD1:
	.word BIGGERBLUD1_IMG
	.half 12, 21, 11, -20
BIGGERBLUD2:
	.word BIGGERBLUD2_IMG
	.half 20, 22, 18, -17
BIGGERBLUD3:
	.word BIGGERBLUD3_IMG
	.half 24, 16, 22, -14
BIGGERBLUD4:
	.word BIGGERBLUD4_IMG
	.half 27, 20, 30, -12
BIGGERBLUD5:
	.word BIGGERBLUD5_IMG
	.half 25, 18, 36, -13
BIGGERBLUD6:
	.word BIGGERBLUD6_IMG
	.half 22, 18, 42, -14
DRIP1:
	.word DRIP1_IMG
	.half 12, 18, 0, 11
DRIP2:
	.word DRIP2_IMG
	.half 17, 11, 0, 17
DRIP3:
	.word DRIP3_IMG
	.half 20, 8, 2, 20
DRIP4:
	.word DRIP4_IMG
	.half 23, 6, 2, 22
DRIP5:
	.word DRIP5_IMG
	.half 11, 18, 8, 9
DRIP6:
	.word DRIP6_IMG
	.half 11, 24, 12, 8
DRIP7:
	.word DRIP7_IMG
	.half 9, 28, 14, 5
bludglob1:
	.word bludglob1_IMG
	.half 18, 6, 0, 0
bludglob2:
	.word bludglob2_IMG
	.half 20, 7, 0, 0
bludglob3:
	.word bludglob3_IMG
	.half 17, 10, 0, 0
bludglob4:
	.word bludglob4_IMG
	.half 16, 14, 0, 0
bludglob5:
	.word bludglob5_IMG
	.half 12, 19, 0, 0
bludglob6:
	.word bludglob6_IMG
	.half 7, 21, 0, 0
bludglob7:
	.word bludglob7_IMG
	.half 9, 21, 0, 3
bludglob8:
	.word bludglob8_IMG
	.half 12, 19, 0, 6
bludglob9:
	.word bludglob9_IMG
	.half 15, 15, 0, 9
bludglob10:
	.word bludglob10_IMG
	.half 17, 11, 0, 10
bludglob11:
	.word bludglob11_IMG
	.half 20, 8, 0, 14
bludglob12:
	.word bludglob12_IMG
	.half 23, 6, 0, 15
GOROARM02:
	.word GOROARM02_IMG
	.half 22, 23, 13, 7
	.word	GBODY_P
GOROARM03:
	.word GOROARM03_IMG
	.half 10, 26, 15, 2
GOROARM04:
	.word GOROARM04_IMG
	.half 15, 24, 15, 4
GOROARM05:
	.word GOROARM05_IMG
	.half 27, 18, 13, 11
GOROARM06:
	.word GOROARM06_IMG
	.half 34, 10, 7, 16
GOROARM07:
	.word GOROARM07_IMG
	.half 32, 18, 11, 18
GOROARM08:
	.word GOROARM08_IMG
	.half 23, 30, 15, 14
GOROARM09:
	.word GOROARM09_IMG
	.half 8, 31, 15, 3
GOROARM10:
	.word GOROARM10_IMG
	.half 22, 27, 13, 10
GOROARM11:
	.word GOROARM11_IMG
	.half 35, 19, 8, 15
GOROARM12:
	.word GOROARM12_IMG
	.half 37, 10, 4, 15
	.globl SKULL01
SKULL01:
	.word SKULL01_IMG
	.half 14, 15, 8, 8
	.word	BONE_P
SKULL02:
	.word SKULL02_IMG
	.half 14, 17, 9, 8
SKULL03:
	.word SKULL03_IMG
	.half 14, 16, 8, 7
SKULL04:
	.word SKULL04_IMG
	.half 15, 14, 6, 8
SKULL05:
	.word SKULL05_IMG
	.half 17, 14, 6, 9
SKULL06:
	.word SKULL06_IMG
	.half 16, 15, 8, 8
SKULL07:
	.word SKULL07_IMG
	.half 13, 15, 9, 4
SKULL08:
	.word SKULL08_IMG
	.half 14, 17, 9, 5
SKULL09:
	.word SKULL09_IMG
	.half 14, 16, 9, 7
SKULL10:
	.word SKULL10_IMG
	.half 15, 14, 9, 7
SKULL11:
	.word SKULL11_IMG
	.half 17, 14, 9, 8
SKULL12:
	.word SKULL12_IMG
	.half 16, 15, 8, 8
	.globl	CAGE01
CAGE01:
	.word CAGE01_IMG
	.half 21, 21, 12, 8
	.word	CAGE_P
CAGE02:
	.word CAGE02_IMG
	.half 20, 23, 14, 7
CAGE03:
	.word CAGE03_IMG
	.half 17, 23, 14, 8
CAGE04:
	.word CAGE04_IMG
	.half 20, 22, 13, 9
CAGE05:
	.word CAGE05_IMG
	.half 21, 19, 11, 9
CAGE06:
	.word CAGE06_IMG
	.half 20, 19, 9, 11
CAGE07:
	.word CAGE07_IMG
	.half 21, 23, 11, 12
CAGE08:
	.word CAGE08_IMG
	.half 19, 24, 11, 10
CAGE09:
	.word CAGE09_IMG
	.half 17, 22, 10, 8
CAGE10:
	.word CAGE10_IMG
	.half 20, 22, 10, 10
CAGE11:
	.word CAGE11_IMG
	.half 21, 18, 9, 10
CAGE12:
	.word CAGE12_IMG
	.half 21, 18, 10, 9
	.globl BONE01
BONE01:
	.word BONE01_IMG
	.half 21, 8, 5, 12
	.word BONE_P
BONE02:
	.word BONE02_IMG
	.half 14, 11, 5, 8
BONE03:
	.word BONE03_IMG
	.half 5, 19, 9, 3
BONE04:
	.word BONE04_IMG
	.half 15, 23, 11, 8
BONE05:
	.word BONE05_IMG
	.half 22, 22, 10, 11
BONE06:
	.word BONE06_IMG
	.half 23, 17, 8, 12
BONE07:
	.word BONE07_IMG
	.half 21, 9, 4, 11
BONE08:
	.word BONE08_IMG
	.half 13, 11, 6, 7
BONE09:
	.word BONE09_IMG
	.half 6, 18, 9, 3
BONE10:
	.word BONE10_IMG
	.half 15, 22, 11, 8
BONE11:
	.word BONE11_IMG
	.half 22, 22, 11, 11
BONE12:
	.word BONE12_IMG
	.half 25, 17, 9, 13
XLIMB01:
	.word XLIMB01_IMG
	.half 23, 25, 12, 9
	.word   BODY_P
XLIMB02:
	.word XLIMB02_IMG
	.half 15, 31, 16, 7
XLIMB03:
	.word XLIMB03_IMG
	.half 9, 30, 16, 3
XLIMB04:
	.word XLIMB04_IMG
	.half 16, 24, 14, 8
XLIMB05:
	.word XLIMB05_IMG
	.half 21, 13, 8, 10
XLIMB06:
	.word XLIMB06_IMG
	.half 24, 16, 9, 11
XLIMB07:
	.word XLIMB07_IMG
	.half 20, 26, 14, 9
XLIMB08:
	.word XLIMB08_IMG
	.half 13, 32, 17, 5
XLIMB09:
	.word XLIMB09_IMG
	.half 10, 31, 17, 4
XLIMB10:
	.word XLIMB10_IMG
	.half 18, 25, 14, 7
XLIMB11:
	.word XLIMB11_IMG
	.half 24, 14, 7, 10
XLIMB12:
	.word XLIMB12_IMG
	.half 26, 15, 8, 11
LEG_B01:
	.word LEG_B01_IMG
	.half 31, 18, 9, 15
	.word   BODY_P
LEG_B02:
	.word LEG_B02_IMG
	.half 33, 14, 10, 14
LEG_B03:
	.word LEG_B03_IMG
	.half 29, 22, 13, 11
LEG_B04:
	.word LEG_B04_IMG
	.half 20, 30, 17, 6
LEG_B05:
	.word LEG_B05_IMG
	.half 14, 31, 18, 8
LEG_B06:
	.word LEG_B06_IMG
	.half 23, 26, 17, 11
LEG_B07:
	.word LEG_B07_IMG
	.half 28, 18, 13, 13
LEG_B08:
	.word LEG_B08_IMG
	.half 31, 16, 9, 15
LEG_B09:
	.word LEG_B09_IMG
	.half 28, 24, 14, 15
LEG_B10:
	.word LEG_B10_IMG
	.half 19, 28, 16, 12
LEG_B11:
	.word LEG_B11_IMG
	.half 15, 31, 16, 7
LEG_B12:
	.word LEG_B12_IMG
	.half 23, 27, 13, 11
	.globl LEG01
LEG01:
	.word LEG01_IMG
	.half 29, 15, 7, 11
	.word   BODY_P
LEG02:
	.word LEG02_IMG
	.half 30, 19, 9, 11
LEG03:
	.word LEG03_IMG
	.half 31, 21, 10, 11
LEG04:
	.word LEG04_IMG
	.half 32, 19, 10, 12
LEG05:
	.word LEG05_IMG
	.half 32, 19, 10, 12
LEG06:
	.word LEG06_IMG
	.half 32, 14, 7, 12
LEG07:
	.word LEG07_IMG
	.half 33, 14, 8, 13
LEG08:
	.word LEG08_IMG
	.half 31, 18, 11, 12
LEG09:
	.word LEG09_IMG
	.half 31, 20, 11, 12
LEG10:
	.word LEG10_IMG
	.half 31, 20, 12, 12
LEG11:
	.word LEG11_IMG
	.half 29, 19, 11, 11
LEG12:
	.word LEG12_IMG
	.half 29, 14, 8, 11
	.globl ARM_B01
ARM_B01:
	.word ARM_B01_IMG
	.half 25, 13, 6, 14
	.word   BODY_P
ARM_B02:
	.word ARM_B02_IMG
	.half 18, 23, 11, 10
ARM_B03:
	.word ARM_B03_IMG
	.half 10, 28, 15, 6
ARM_B04:
	.word ARM_B04_IMG
	.half 12, 26, 15, 6
ARM_B05:
	.word ARM_B05_IMG
	.half 23, 20, 13, 9
ARM_B06:
	.word ARM_B06_IMG
	.half 29, 11, 8, 11
ARM_B07:
	.word ARM_B07_IMG
	.half 27, 14, 6, 9
ARM_B08:
	.word ARM_B08_IMG
	.half 19, 26, 10, 6
ARM_B09:
	.word ARM_B09_IMG
	.half 10, 30, 11, 3
ARM_B10:
	.word ARM_B10_IMG
	.half 12, 26, 10, 5
ARM_B11:
	.word ARM_B11_IMG
	.half 21, 19, 7, 11
ARM_B12:
	.word ARM_B12_IMG
	.half 26, 10, 4, 14
ARM13:
	.word ARM13_IMG
	.half 19, 18, 11, 4
ARM14:
	.word ARM14_IMG
	.half 17, 11, 6, -1
ARM15:
	.word ARM15_IMG
	.half 15, 14, 6, -6
ARM16:
	.word ARM16_IMG
	.half 12, 23, 10, -11
ARM17:
	.word ARM17_IMG
	.half 8, 28, 11, -14
ARM18:
	.word ARM18_IMG
	.half 9, 35, 13, -15
ARM19:
	.word ARM19_IMG
	.half 9, 34, 13, -14
ARM01:
	.word ARM01_IMG
	.half 22, 18, 10, 11
	.word   BODY_P
ARM02:
	.word ARM02_IMG
	.half 21, 11, 6, 10
ARM03:
	.word ARM03_IMG
	.half 23, 11, 6, 11
ARM04:
	.word ARM04_IMG
	.half 24, 19, 8, 11
ARM05:
	.word ARM05_IMG
	.half 26, 23, 9, 11
ARM06:
	.word ARM06_IMG
	.half 26, 22, 7, 11
ARM07:
	.word ARM07_IMG
	.half 25, 18, 6, 11
ARM08:
	.word ARM08_IMG
	.half 23, 10, 4, 11
ARM09:
	.word ARM09_IMG
	.half 22, 11, 4, 11
ARM10:
	.word ARM10_IMG
	.half 22, 18, 8, 11
ARM11:
	.word ARM11_IMG
	.half 22, 22, 11, 11
ARM12:
	.word ARM12_IMG
	.half 22, 21, 12, 11
	.globl PORK01
PORK01:
	.word PORK01_IMG
	.half 20, 14, 7, 9
	.word PORK_P
PORK02:
	.word PORK02_IMG
	.half 13, 16, 8, 6
PORK03:
	.word PORK03_IMG
	.half 6, 15, 8, 3
PORK04:
	.word PORK04_IMG
	.half 14, 12, 6, 7
PORK05:
	.word PORK05_IMG
	.half 20, 8, 5, 10
PORK06:
	.word PORK06_IMG
	.half 21, 10, 6, 12
PORK07:
	.word PORK07_IMG
	.half 20, 14, 8, 11
PORK08:
	.word PORK08_IMG
	.half 13, 16, 10, 7
PORK09:
	.word PORK09_IMG
	.half 7, 15, 10, 3
PORK10:
	.word PORK10_IMG
	.half 14, 12, 7, 6
PORK11:
	.word PORK11_IMG
	.half 20, 6, 4, 9
PORK12:
	.word PORK12_IMG
	.half 22, 9, 6, 9
BLDXPD1:
	.word BLDXPD1_SUB, 0
BLDXPD1_SUB:
	.word BLDXPD1_IMG
	.half 40, 45, 22, 20
	.word BLDXPD_P
BLDXPD2:
	.word BLDXPD2_SUB, 0
BLDXPD2_SUB:
	.word BLDXPD2_IMG
	.half 49, 56, 28, 25
BLDXPD3:
	.word BLDXPD3_SUB, 0
BLDXPD3_SUB:
	.word BLDXPD3_IMG
	.half 59, 67, 34, 29
BLDXPD4:
	.word BLDXPD4_SUB, 0
BLDXPD4_SUB:
	.word BLDXPD4_IMG
	.half 66, 77, 38, 33
BLDXPD5:
	.word BLDXPD5_SUB, 0
BLDXPD5_SUB:
	.word BLDXPD5_IMG
	.half 77, 85, 42, 37
BLDXPD6:
	.word BLDXPD6_SUB, 0
BLDXPD6_SUB:
	.word BLDXPD6_IMG
	.half 86, 96, 48, 41
BLDXPD7:
	.word BLDXPD7_SUB, 0
BLDXPD7_SUB:
	.word BLDXPD7_IMG
	.half 97, 107, 54, 47
BLDXPD8:
	.word BLDXPD8_SUB, 0
BLDXPD8_SUB:
	.word BLDXPD8_IMG
	.half 106, 118, 59, 51
BLDXPD9:
	.word BLDXPD9_SUB, 0
BLDXPD9_SUB:
	.word BLDXPD9_IMG
	.half 116, 130, 65, 55
BLDXPD10:
	.word BLDXPD10_SUB, 0
BLDXPD10_SUB:
	.word BLDXPD10_IMG
	.half 127, 144, 72, 61
BLDXPD11:
	.word BLDXPD11_SUB, 0
BLDXPD11_SUB:
	.word BLDXPD11_IMG
	.half 139, 162, 81, 68
BLDXPD12:
	.word BLDXPD12_SUB, 0
BLDXPD12_SUB:
	.word BLDXPD12_IMG
	.half 143, 182, 91, 69
BLDXPD13:
	.word BLDXPD13_SUB, 0
BLDXPD13_SUB:
	.word BLDXPD13_IMG
	.half 150, 157, 78, 77
 
	.align 2
	.globl blood_dict
blood_dict:
#include "../common/blood/blood.dct"
 
	.align 2
#include "../common/blood/blood.att"

/*
;******************************************************************************
;	Various Rock Graphics (rocks.adt)
;******************************************************************************
*/

	.align 2
	.globl preload_rocks
preload_rocks:
	.word SMALL01
	.word SMALL02
	.word SMALL03
	.word SMALL04
	.word SMALL05
	.word SMALL06
	.word SMALL07
	.word SMALL08
	.word SMALL09
	.word SMALL10
	.word SMALL11
	.word SMALL12
	.word MEDIUM01
	.word MEDIUM02
	.word MEDIUM03
	.word MEDIUM04
	.word MEDIUM05
	.word MEDIUM06
	.word MEDIUM07
	.word MEDIUM08
	.word MEDIUM09
	.word MEDIUM10
	.word MEDIUM11
	.word MEDIUM12
	.word LARGE01
	.word LARGE02
	.word LARGE03
	.word LARGE04
	.word LARGE05
	.word LARGE06
	.word LARGE07
	.word LARGE08
	.word LARGE09
	.word LARGE10
	.word LARGE11
	.word LARGE12
	.word XPLODE01
	.word XPLODE02
	.word XPLODE03
	.word XPLODE04
	.word XPLODE05
	.word XPLODE06
	.word XPLODE07
	.word XPLODE08
	.word XPLODE09
	.word XPLODE10
	.word XPLODE11
	.word XPLODE12
	.word 0

	.align 2
	.globl a_small_rock
a_small_rock:
	.word SMALL01
	.word SMALL02
	.word SMALL03
	.word SMALL04
	.word SMALL05
	.word SMALL06
	.globl a_small_rock2
a_small_rock2:
	.word SMALL07
	.word SMALL08
	.word SMALL09
	.word SMALL10
	.word SMALL11
	.word SMALL12
	.word ani_jump
	.word a_small_rock
	.globl a_med_rock
a_med_rock:
	.word MEDIUM01
	.word MEDIUM02
	.word MEDIUM03
	.word MEDIUM04
	.word MEDIUM05
	.word MEDIUM06
	.word MEDIUM07
	.word MEDIUM08
	.word MEDIUM09
	.word MEDIUM10
	.word MEDIUM11
	.word MEDIUM12
	.word ani_jump
	.word a_med_rock
	.globl a_large_rock
a_large_rock:
	.word LARGE01
	.word LARGE02
	.word LARGE03
	.word LARGE04
	.word LARGE05
	.word LARGE06
	.word LARGE07
	.word LARGE08
	.word LARGE09
	.word LARGE10
	.word LARGE11
	.word LARGE12
	.word ani_jump
	.word a_large_rock
	.globl a_crumple
a_crumple:
	.word XPLODE01
	.word XPLODE02
	.word XPLODE03
	.word XPLODE04
	.word XPLODE05
	.word XPLODE06
	.word XPLODE07
	.word XPLODE08
	.word XPLODE09
	.word XPLODE10
	.word XPLODE11
	.word XPLODE12
	.word 0
	.globl SMALL01
SMALL01:
	.word SMALL01_IMG
	.half 12, 9, 5, 6
	.word SMALL_p
SMALL02:
	.word SMALL02_IMG
	.half 12, 7, 4, 6
SMALL03:
	.word SMALL03_IMG
	.half 12, 8, 4, 6
SMALL04:
	.word SMALL04_IMG
	.half 11, 10, 5, 6
SMALL05:
	.word SMALL05_IMG
	.half 12, 10, 5, 6
SMALL06:
	.word SMALL06_IMG
	.half 11, 10, 5, 5
SMALL07:
	.word SMALL07_IMG
	.half 10, 11, 6, 5
SMALL08:
	.word SMALL08_IMG
	.half 13, 12, 6, 7
SMALL09:
	.word SMALL09_IMG
	.half 12, 11, 6, 6
SMALL10:
	.word SMALL10_IMG
	.half 13, 10, 6, 6
SMALL11:
	.word SMALL11_IMG
	.half 13, 9, 5, 6
SMALL12:
	.word SMALL12_IMG
	.half 13, 9, 5, 6
	.globl MEDIUM01
MEDIUM01:
	.word MEDIUM01_IMG
	.half 17, 16, 8, 9
	.word MEDIUM_p
MEDIUM02:
	.word MEDIUM02_IMG
	.half 17, 15, 8, 9
MEDIUM03:
	.word MEDIUM03_IMG
	.half 15, 16, 9, 6
MEDIUM04:
	.word MEDIUM04_IMG
	.half 17, 17, 9, 7
MEDIUM05:
	.word MEDIUM05_IMG
	.half 19, 17, 9, 9
MEDIUM06:
	.word MEDIUM06_IMG
	.half 19, 17, 9, 9
MEDIUM07:
	.word MEDIUM07_IMG
	.half 18, 17, 10, 9
MEDIUM08:
	.word MEDIUM08_IMG
	.half 15, 17, 10, 7
MEDIUM09:
	.word MEDIUM09_IMG
	.half 15, 17, 10, 8
MEDIUM10:
	.word MEDIUM10_IMG
	.half 17, 17, 9, 9
MEDIUM11:
	.word MEDIUM11_IMG
	.half 18, 16, 8, 9
MEDIUM12:
	.word MEDIUM12_IMG
	.half 18, 15, 8, 9
	.globl LARGE01
LARGE01:
	.word LARGE01_IMG
	.half 31, 42, 24, 17
	.word MEDIUM_p
LARGE02:
	.word LARGE02_IMG
	.half 30, 46, 25, 16
LARGE03:
	.word LARGE03_IMG
	.half 30, 40, 20, 16
LARGE04:
	.word LARGE04_IMG
	.half 30, 41, 18, 16
LARGE05:
	.word LARGE05_IMG
	.half 30, 34, 13, 16
LARGE06:
	.word LARGE06_IMG
	.half 29, 26, 9, 16
LARGE07:
	.word LARGE07_IMG
	.half 29, 38, 16, 16
LARGE08:
	.word LARGE08_IMG
	.half 29, 45, 22, 16
LARGE09:
	.word LARGE09_IMG
	.half 29, 42, 22, 16
LARGE10:
	.word LARGE10_IMG
	.half 29, 40, 23, 16
LARGE11:
	.word LARGE11_IMG
	.half 30, 38, 25, 17
LARGE12:
	.word LARGE12_IMG
	.half 30, 30, 22, 17
	.globl XPLODE01
XPLODE01:
	.word XPLODE01_IMG
	.half 10, 7, 3, 9
	.word SMALL_p
XPLODE02:
	.word XPLODE02_IMG
	.half 9, 9, 4, 10
XPLODE03:
	.word XPLODE03_IMG
	.half 10, 14, 6, 12
XPLODE04:
	.word XPLODE04_IMG
	.half 11, 20, 9, 12
XPLODE05:
	.word XPLODE05_IMG
	.half 10, 26, 11, 9
XPLODE06:
	.word XPLODE06_IMG
	.half 9, 31, 14, 7
XPLODE07:
	.word XPLODE07_IMG
	.half 8, 35, 15, 5
XPLODE08:
	.word XPLODE08_IMG
	.half 8, 38, 16, 5
XPLODE09:
	.word XPLODE09_IMG
	.half 8, 40, 17, 5
XPLODE10:
	.word XPLODE10_IMG
	.half 7, 42, 18, 4
XPLODE11:
	.word XPLODE11_IMG
	.half 3, 43, 18, 1
XPLODE12:
	.word XPLODE12_IMG
	.half 3, 45, 19, 1
	.globl STBREAK1
STBREAK1:
	.word STBREAK1_IMG
	.half 54, 74, 0, 0
	.word STBREAK_P
	.globl STBREAK2
STBREAK2:
	.word STBREAK2_IMG
	.half 54, 90, -73, 0
	.word STBREAK_P
	.globl STBREAK3
STBREAK3:
	.word STBREAK3_IMG
	.half 54, 81, 0, 0
	.word STBREAK_P
	
	.align 2
	.globl rock_dict
rock_dict:
#include "../common/rocks/rocks.dct"

	.align 2
#include "../common/rocks/rocks.att"

  
/*
;******************************************************************************
;	Various Control Panel Graphics (control.adt)
;******************************************************************************
*/
	.align 2
	.globl name_anim_imgs
name_anim_imgs:
	.word N_KANO
	.word N_SONYA
	.word N_JAX
	.word N_NIGHTWOLF
	.word N_CAGE
	.word N_STRYKER
	.word N_SINDEL
	.word N_SEKTOR
	.word N_CYRAX
	.word N_KUNGLAO
	.word N_KABAL
	.word N_SHEEVA
	.word N_SHANGTSUNG
	.word N_LIUKANG
	.word N_SMOKE
	.word N_KITANA
	.word N_JADE
	.word N_MILEENA
	.word N_SCORPION
	.word N_REPTILE
	.word N_ERMAC
	.word N_SUBZERO
	.word N_SMOKE
	.word N_NOOBSAIBOT
	.word N_RAYDEN
	.word N_BARAKA
	.word N_RAIN
  	.word N_KAMELEON
	.word N_SCORPION
  	.word N_REPTILE
	.word N_MOTARO
	.word N_SHAOKAHN
	
	.align 2
	.globl control_panel_info
	.globl control_panel_info1
	.globl preload_control_panel
control_panel_info:
	.word	0
control_panel_info1:
preload_control_panel:
	.word	MEDAL1
	.word	PWRBAR_LA
	.word	PWRBAR_LB
	.word	PUSHSTART
	.word	PUSHSTART
/*
	.globl 	score_nums_tbl
score_nums_tbl:
*/
	.word X_SHADNUM0
	.word X_SHADNUM1
	.word X_SHADNUM2
	.word X_SHADNUM3
	.word X_SHADNUM4
	.word X_SHADNUM5
	.word X_SHADNUM6
	.word X_SHADNUM7
	.word X_SHADNUM8
	.word X_SHADNUM9
	.word X_SHADWINS
/*
	.globl clock_nums
clock_nums:
*/
	.word COUNTDOWN_0
	.word COUNTDOWN_1
	.word COUNTDOWN_2
	.word COUNTDOWN_3
	.word COUNTDOWN_4
	.word COUNTDOWN_5
	.word COUNTDOWN_6
	.word COUNTDOWN_7
	.word COUNTDOWN_8
	.word COUNTDOWN_9
	.word	0
	.word	0
	
	.globl VOLUME
VOLUME:
	.word volume_IMG
	.half 14, 96, 0, 0
	.word SCORE_P
	
	.globl DANGER
DANGER:
	.word DANGER_IMG
	.half 8, 31, 0, 0
	.word WHITE_p
	.globl TOASTY
TOASTY:
	.word TOASTY_IMG
	.half 85, 78, 82, 0
	.word LOADING_P
	.globl damage_s
damage_s:
	.word damage_s_IMG
	.half 10, 65, 0, 0
	.word WHITE_p
	.globl hits_s
hits_s:
	.word hits_s_IMG
	.half 10, 26, 0, 0
	.word WHITE_p
N_BARAKA:
  .word N_BARAKA_IMG
  .half 7, 39, 0, 0
N_RAYDEN:
  .word N_RAYDEN_IMG
  .half 7, 38, 0, 0
N_RAIN:
  .word N_RAIN_IMG
  .half 7, 23, 0, 0
N_KANO:
	.word N_KANO_IMG
	.half 7, 26, 0, 0
N_SONYA:
	.word N_SONYA_IMG
	.half 7, 30, 0, 0
N_JAX:
	.word N_JAX_IMG
	.half 7, 19, 0, 0
N_NIGHTWOLF:
	.word N_NIGHTWOLF_IMG
	.half 7, 53, 0, 0
N_SUBZERO:
	.word N_SUBZERO_IMG
	.half 7, 44, 0, 0
N_STRYKER:
	.word N_STRYKER_IMG
	.half 7, 41, 0, 0
N_SINDEL:
	.word N_SINDEL_IMG
	.half 7, 31, 0, 0
N_SEKTOR:
	.word N_SEKTOR_IMG
	.half 7, 36, 0, 0
N_CYRAX:
	.word N_CYRAX_IMG
	.half 7, 32, 0, 0
N_KUNGLAO:
	.word N_KUNGLAO_IMG
	.half 7, 48, 0, 0
N_KABAL:
	.word N_KABAL_IMG
	.half 7, 30, 0, 0
N_SHEEVA:
	.word N_SHEEVA_IMG
	.half 7, 34, 0, 0
N_SHANGTSUNG:
	.word N_SHANGTSUNG_IMG
	.half 7, 66, 0, 0
N_LIUKANG:
	.word N_LIUKANG_IMG
	.half 7, 43, 0, 0
N_SMOKE:
	.word N_SMOKE_IMG
	.half 7, 32, 0, 0
N_KITANA:
	.word N_KITANA_IMG
	.half 7, 34, 0, 0
N_JADE:
	.word N_JADE_IMG
	.half 7, 26, 0, 0
N_MILEENA:
	.word N_MILEENA_IMG
	.half 7, 40, 0, 0
N_SCORPION:
	.word N_SCORPION_IMG
	.half 7, 47, 0, 0
N_REPTILE:
	.word N_REPTILE_IMG
	.half 7, 36, 0, 0
N_ERMAC:
	.word N_ERMAC_IMG
	.half 7, 33, 0, 0
N_NOOBSAIBOT:
	.word N_NOOBSAIBOT_IMG
	.half 7, 62, 0, 0
N_MOTARO:
	.word N_MOTARO_IMG
	.half 7, 39, 0, 0
N_SHAOKAHN:
	.word N_SHAOKAHN_IMG
	.half 7, 54, 0, 0
N_CAGE:
	.word N_JOHNNY_IMG
	.half 7, 68, 0, 0
N_KAMELEON:
	.word N_KHAMELEON_IMG
	.half 7, 60, 0, 0
	.globl PWRBAR_LA
PWRBAR_LA:
	.word PWRBAR_LA_IMG
	.half 13, 134, 0, 0
	.globl PWRBAR_LB
PWRBAR_LB:
	.word PWRBAR_LB_IMG
	.half 13, 134, 0, 0
COUNTDOWN_0:
	.word COUNTDOWN_0_IMG
	.half 14, 10, 0, 0
COUNTDOWN_1:
	.word COUNTDOWN_1_IMG
	.half 14, 7, 0, 0
COUNTDOWN_2:
	.word COUNTDOWN_2_IMG
	.half 14, 10, 0, 0
COUNTDOWN_3:
	.word COUNTDOWN_3_IMG
	.half 14, 10, 0, 0
COUNTDOWN_4:
	.word COUNTDOWN_4_IMG
	.half 14, 10, 0, 0
COUNTDOWN_5:
	.word COUNTDOWN_5_IMG
	.half 14, 10, 0, 0
COUNTDOWN_6:
	.word COUNTDOWN_6_IMG
	.half 14, 10, 0, 0
COUNTDOWN_7:
	.word COUNTDOWN_7_IMG
	.half 14, 10, 0, 0
COUNTDOWN_8:
	.word COUNTDOWN_8_IMG
	.half 14, 10, 0, 0
COUNTDOWN_9:
	.word COUNTDOWN_9_IMG
	.half 14, 10, 0, 0
X_SHADNUM0:
	.word X_SHADNUM0_IMG
	.half 11, 10, 0, 0
X_SHADNUM1:
	.word X_SHADNUM1_IMG
	.half 10, 6, 0, 0
X_SHADNUM2:
	.word X_SHADNUM2_IMG
	.half 10, 10, 0, 0
X_SHADNUM3:
	.word X_SHADNUM3_IMG
	.half 10, 9, 0, 0
X_SHADNUM4:
	.word X_SHADNUM4_IMG
	.half 10, 9, 0, 0
X_SHADNUM5:
	.word X_SHADNUM5_IMG
	.half 10, 9, 0, 0
X_SHADNUM6:
	.word X_SHADNUM6_IMG
	.half 11, 9, 0, 0
X_SHADNUM7:
	.word X_SHADNUM7_IMG
	.half 10, 10, 0, 0
X_SHADNUM8:
	.word X_SHADNUM8_IMG
	.half 11, 9, 0, 0
X_SHADNUM9:
	.word X_SHADNUM9_IMG
	.half 10, 9, 0, 0
	.globl PUSHSTART
PUSHSTART:
	.word PUSHSTART_IMG
	.half 12, 74, 0, 0
	.globl X_SHADWINS
X_SHADWINS:
	.word X_SHADWINS_IMG
	.half 10, 34, 36, 2
MEDAL1:
	.word MEDAL1_IMG
	.half 11, 10, 0, 0
	
	.align 2
	.globl a_agressor
	.globl preload_agressor
preload_agressor:
a_agressor:
	.word AGRESSOR1
	.word AGRESSOR2
	.word AGRESSOR3
	.word AGRESSOR5
	.word AGRESSOR7
	.word AGRESSOR8
	.word 0
	
	.align 2
	.globl AGRESSOR1
AGRESSOR1:
	.word AGGRESSOR1_IMG
	.half 15, 81,  -10, -5
	.word SCORE_P

	.align 2
	.globl AGRESSOR2
AGRESSOR2:
	.word AGGRESSOR2_IMG
	.half 26, 102,  0, 0

	.align 2
	.globl AGRESSOR3
AGRESSOR3:
	.word AGGRESSOR3_IMG
	.half 26, 102,  1, 1

	.align 2
	.globl AGRESSOR5
AGRESSOR5:
	.word AGGRESSOR5_IMG
	.half 26, 102,  0, 0

	.align 2
	.globl AGRESSOR7
AGRESSOR7:
	.word AGGRESSOR7_IMG
	.half 26, 102,  1, 0

	.align 2
	.globl AGRESSOR8
AGRESSOR8:
	.word AGGRESSOR8_IMG
	.half 26, 102,  0, 0

	.align 2
	.globl control_dict
control_dict:
#include "../common/control/control.dct"
			 	  
	.align 2
#include "../common/control/control.att"

/*
;******************************************************************************
;	Various Monk Graphics (monk.adt)
;******************************************************************************
*/
	.align 2
	.globl preload_monk
preload_monk:
	.word monk1
	.word monk3
	.word monk5
	.word monk7
	.word monktorso
	.word 0

	.align 2
	.globl a_bg_monk
a_bg_monk:
	.word monk1
	.word monk3
	.word monk5
	.word monk7
	.word ani_jump
	.word a_bg_monk
	
	.globl monk1
monk1:
	.word monk1_IMG
	.half 37, 38, 11, 0
	.word MONKPAL_p
monk3:
	.word monk3_IMG
	.half 38, 34, 11, 0
monk5:
	.word monk5_IMG
	.half 37, 34, 10, 0
monk7:
	.word monk7_IMG
	.half 37, 37, 10, 0
	.globl monktorso
monktorso:
	.word monktorso_IMG
	.half 37, 32, 18, 34
	.word MONKPAL_p

	.align 2
	.globl monk_dict
monk_dict:
#include "../common/monk/monk.dct"

	.align 2
#include "../common/monk/monk.att"

/*
;******************************************************************************
;	Various Trash Graphics (trash.adt)
;******************************************************************************
*/
	.align 2
	.globl preload_trash
preload_trash:
	.word PAPER1
	.word PAPER2
	.word PAPER3
	.word PAPER4
	.word PAPER5
	.word PAPER6
	.word PAPER7
	.word PAPER8
	.word PAPER9
	.word LGSHEET1
	.word LGSHEET2
	.word LGSHEET3
	.word LGSHEET4
	.word LGSHEET5
	.word LGSHEET6
	.word LGSHEET7
	.word LGSHEET8
	.word LGSHEET9
	.word SMSHEET1
	.word SMSHEET2
	.word SMSHEET3
	.word SMSHEET4
	.word SMSHEET5
	.word SMSHEET6
	.word SMSHEET7
	.word SMSHEET8
	.word SMSHEET9
	.word LEAF1
	.word LEAF2
	.word LEAF3
	.word LEAF4
	.word LEAF5
	.word LEAF6
	.word LEAF7
	.word LEAF8
	.word 0
	

	.align 2
	.globl a_paper1
a_paper1:
	.word PAPER1
	.word PAPER2
	.word PAPER3
	.word PAPER4
	.word PAPER5
	.word PAPER6
	.word PAPER7
	.word PAPER8
	.word PAPER9
	.word 0
	.globl a_big_paper
a_big_paper:
	.word LGSHEET1
	.word LGSHEET2
	.word LGSHEET3
	.word LGSHEET4
	.word LGSHEET5
	.word LGSHEET6
	.word LGSHEET7
	.word LGSHEET8
	.word LGSHEET9
	.word ani_jump
	.word a_big_paper
	.globl a_lil_paper
a_lil_paper:
	.word SMSHEET1
	.word SMSHEET2
	.word SMSHEET3
	.word SMSHEET4
	.word SMSHEET5
	.word SMSHEET6
	.word SMSHEET7
	.word SMSHEET8
	.word SMSHEET9
	.word ani_jump
	.word a_lil_paper
	.globl a_leaf
a_leaf:
	.word LEAF1
	.word LEAF2
	.word LEAF3
	.word LEAF4
	.word LEAF5
	.word LEAF6
	.word LEAF7
	.word LEAF8
	.word ani_jump
	.word a_leaf
	.globl PAPER1
PAPER1:
	.word PAPER1_IMG
	.half 12, 18, 8, 11
	.word PAPER_P
PAPER2:
	.word PAPER2_IMG
	.half 12, 18, 7, 11
PAPER3:
	.word PAPER3_IMG
	.half 12, 18, 7, 11
PAPER4:
	.word PAPER4_IMG
	.half 11, 18, 7, 10
PAPER5:
	.word PAPER5_IMG
	.half 10, 18, 7, 9
PAPER6:
	.word PAPER6_IMG
	.half 10, 19, 7, 9
PAPER7:
	.word PAPER7_IMG
	.half 12, 20, 7, 11
PAPER8:
	.word PAPER8_IMG
	.half 14, 19, 9, 14
PAPER9:
	.word PAPER9_IMG
	.half 15, 20, 10, 14
	.globl LGSHEET1
LGSHEET1:
	.word LGSHEET1_IMG
	.half 17, 9, 4, 8
	.word PAPER_P
LGSHEET2:
	.word LGSHEET2_IMG
	.half 12, 12, 3, 4
LGSHEET3:
	.word LGSHEET3_IMG
	.half 11, 14, 2, 3
LGSHEET4:
	.word LGSHEET4_IMG
	.half 13, 11, 2, 3
LGSHEET5:
	.word LGSHEET5_IMG
	.half 14, 5, 0, 4
LGSHEET6:
	.word LGSHEET6_IMG
	.half 13, 11, 5, 3
LGSHEET7:
	.word LGSHEET7_IMG
	.half 14, 14, 6, 3
LGSHEET8:
	.word LGSHEET8_IMG
	.half 14, 11, 3, 4
LGSHEET9:
	.word LGSHEET9_IMG
	.half 14, 9, 3, 6
	.globl SMSHEET1
SMSHEET1:
	.word SMSHEET1_IMG
	.half 14, 7, 3, 7
	.word PAPER_P
SMSHEET2:
	.word SMSHEET2_IMG
	.half 9, 8, 2, 4
SMSHEET3:
	.word SMSHEET3_IMG
	.half 9, 10, 2, 3
SMSHEET4:
	.word SMSHEET4_IMG
	.half 10, 8, 0, 3
SMSHEET5:
	.word SMSHEET5_IMG
	.half 11, 3, 0, 4
SMSHEET6:
	.word SMSHEET6_IMG
	.half 9, 9, 4, 3
SMSHEET7:
	.word SMSHEET7_IMG
	.half 11, 10, 6, 4
SMSHEET8:
	.word SMSHEET8_IMG
	.half 11, 9, 4, 5
SMSHEET9:
	.word SMSHEET9_IMG
	.half 10, 6, 4, 5
	.globl LEAF1
LEAF1:
	.word LEAF1_IMG
	.half 3, 5, 3, 1
	.word PAPER_P
LEAF2:
	.word LEAF2_IMG
	.half 3, 3, 2, 2
LEAF3:
	.word LEAF3_IMG
	.half 3, 3, 1, 2
LEAF4:
	.word LEAF4_IMG
	.half 3, 4, 1, 1
LEAF5:
	.word LEAF5_IMG
	.half 4, 2, 0, 2
LEAF6:
	.word LEAF6_IMG
	.half 3, 2, 0, 0
LEAF7:
	.word LEAF7_IMG
	.half 1, 3, 2, -1
LEAF8:
	.word LEAF8_IMG
	.half 1, 3, 2, 0

	.align 2
	.globl trash_dict
trash_dict:
#include "../common/trash/trash.dct"

	.align 2
#include "../common/trash/trash.att"



