#include <regdef.h>
#include "mkbkgd.inc"

	.option	pic0
	.set	noreorder
	
/*
;#******************************************************************************
;# File: mkstk.s
;#
;# By: David Schwartz
;#
;# Date: August 1994
;#
;# (C) Williams Entertainment
;#
;# Mortal Kombat III Strike Tables
;#******************************************************************************
*/


/*
;**************************************************************
;* THESE FLAGS MUST MATCH IN (MKUTIL.H)
;**************************************************************
*/
SF_SQUEEZE	=	1	/* flag: squeeze */
SB_SQUEEZE	=	0	/* flag: squeeze */
SF_DUCK		=	2	/* flag: must duck/block to block */

	.data

	.align 2

	.globl strike_tables
strike_tables:
	.word	kano_strikes			/* 0 */
	.word	sonya_strikes			/* 1 */
	.word	jax_strikes				/* 2 */
	.word	indian_strikes			/* 3 */
	.word	jc_strikes				/* 4 */
	.word	swat_strikes			/* 5 */
	.word	lia_strikes				/* 6 */
	.word	robo_strikes			/* 7 */
	.word	robo_strikes			/* 8 */
	.word	lao_strikes				/* 9 */
	.word	tusk_strikes			/* 10 */
	.word	sg_strikes				/* 11 */
	.word	st_strikes				/* 12 */
	.word	lk_strikes				/* 13 */
	.word	robo_strikes			/* 14 */
	.word	fn_strikes	/* 15 - kitana = female ninja */
	.word	fn_strikes	/* 16 - jade = female ninja */
	.word	fn_strikes	/* 17 - mileena = female ninja */

	.word	nj_strikes	/* 18 */
	.word	nj_strikes	/* 19 */
	.word	nj_strikes	/* 20 */
	.word	nj_strikes	/* 21 */
	.word	nj_strikes	/* 22 */
	.word	nj_strikes	/* 23 */

	.word	rd_strikes		   
	.word	sa_strikes		   
	.word	nj_strikes		   

	.word	indian_strikes		   
	.word	nj_strikes		   
	.word	nj_strikes		   

	.word	mot_strikes
	.word	sk_strikes


/*;-u64-
;**************************************************************************
;*											     *
;*  Sword Arms' strike table  								     *
;*											     *
;**************************************************************************/
sa_strikes:
	.word	stk_sahikick	/* 0 */
	.word	stk_salokick	/* 1 */
	.word	stk_sahipunch	/* 2 */
	.word	stk_salopunch	/* 3 */
	.word	stk_sasweepk	/* 4 */
	.word	stk_saduckpunch	/* 5 */
	.word	stk_saduckkickh	/* 6 */
	.word	stk_saduckkickl	/* 7 */
	.word	stk_sauppercut	/* 8 */
	.word	stk_sajumpupp	/* 9 */
	.word	stk_sajumpupk	/* a */
	.word	stk_saflipk	/* b */
	.word	stk_saflipp	/* c */
	.word	stk_saroundh	/* d */
	.word	stk_saknee	/* e */
	.word	stk_saelbow	/* f */
	.word	stk_sazap1	/* 10 */
	.word	stk_sa2ndknee	/* 11 */
	.word	stk_swipe	/* 12 */
	.word	stk_sazap4	/* 13 */
	.word	stk_shred	/* 14 */
	.word	stk_spin	/* 15 */
	.word	stk_spark1	/* 16 */
	.word	stk_spark2	/* 17 */

stk_sahikick:
	.half	0x53		/* x offset of collision box */
	.half	0x0a		/* y offset of collision box */
	.half	0x3c		/* x size of collision box */
	.half	0x23		/* y size of collision box */
	.half	0x0006		/* strike routine */
	.half	0x1805		/* damage */
	.half	SF_SQUEEZE
	.half	0

stk_salokick:
	.half	0x60		/* x offset of collision box */
	.half	0x2a		/* y offset of collision box */
	.half	0x4a		/* x size of collision box */
	.half	0x22		/* y size of collision box */
	.half	0x0106		/* strike routine */
	.half	0x1504		/* damage */
	.half	SF_SQUEEZE
	.half	0

stk_sahipunch:
	.half	0x51		/* x offset of collision box */
	.half	0x10		/* y offset of collision box */
	.half	0x32		/* x size of collision box */
	.half	0x24		/* y size of collision box */
	.half	0x0211		/* strike routine */
	.half	0x0b03		/* damage */
	.half	SF_SQUEEZE
	.half	0

stk_salopunch:
	.half	0x54		/* x offset of collision box */
	.half	0x20		/* y offset of collision box */
	.half	0x38		/* x size of collision box */
	.half	0x18		/* y size of collision box */
	.half	0x0317		/* strike routine */
	.half	0x0802		/* damage */
	.half	SF_SQUEEZE
	.half	0

stk_sasweepk:
	.half	0x63		/* x offset of collision box */
	.half	0x70		/* y offset of collision box */
	.half	0x45		/* x size of collision box */
	.half	0x23		/* y size of collision box */
	.half	0x0403		/* strike routine */
	.half	0x1403		/* damage */
	.half	SF_DUCK
	.half	0

stk_saduckpunch:
	.half	0x4a		/* x offset of collision box */
	.half	0x4d		/* y offset of collision box */
	.half	0x30		/* x size of collision box */
	.half	0x12		/* y size of collision box */
	.half	0x050a		/* strike routine */
	.half	0x0602		/* damage */
	.half	SF_SQUEEZE
	.half	0

stk_saduckkickh:
	.half	0x4d		/* x offset of collision box */
	.half	0x3e		/* y offset of collision box */
	.half	0x45		/* x size of collision box */
	.half	0x32		/* y size of collision box */
	.half	0x060b		/* strike routine */
	.half	0x0c03		/* damage */
	.half	SF_SQUEEZE
	.half	0

stk_saduckkickl:
	.half	0x4d		/* x offset of collision box */
	.half	0x78		/* y offset of collision box */
	.half	0x45		/* x size of collision box */
	.half	0x1b		/* y size of collision box */
	.half	0x070a		/* strike routine */
	.half	0x0602		/* damage */
	.half	SF_SQUEEZE
	.half	0

stk_sauppercut:
	.half	0x4e		/* x offset of collision box */
	.half	-0x08		/* y offset of collision box */
	.half	0x33		/* x size of collision box */
	.half	0x40		/* y size of collision box */
	.half	0x0802		/* strike routine */
	.half	0x2409		/* damage */
	.half	SF_SQUEEZE
	.half	0

stk_sajumpupp:
	.half	0x58		/* x offset of collision box */
	.half	0x14		/* y offset of collision box */
	.half	0x3c		/* x size of collision box */
	.half	0x36		/* y size of collision box */
	.half	0x0b01		/* strike routine */
	.half	0x1005		/* damage */
	.half	SF_SQUEEZE
	.half	0

stk_sajumpupk:
	.half	0x46		/* x offset of collision box */
	.half	0x03		/* y offset of collision box */
	.half	0x40		/* x size of collision box */
	.half	0x32		/* y size of collision box */
	.half	0x0b01		/* strike routine */
	.half	0x1306		/* damage */
	.half	SF_SQUEEZE
	.half	0

stk_saflipk:
	.half	0x60		/* x offset of collision box */
	.half	0x28		/* y offset of collision box */
	.half	0x3e		/* x size of collision box */
	.half	0x1e		/* y size of collision box */
	.half	0x0a01		/* strike routine */
	.half	0x1a07		/* damage */
	.half	SF_SQUEEZE
	.half	0

stk_saflipp:
	.half	0x59		/* x offset of collision box */
	.half	0x24		/* y offset of collision box */
	.half	0x3c		/* x size of collision box */
	.half	0x25		/* y size of collision box */
	.half	0x0b01		/* strike routine */
	.half	0x0d04		/* damage */
	.half	SF_SQUEEZE
	.half	0

stk_saroundh:
	.half	0x60		/* x offset of collision box */
	.half	0x10		/* y offset of collision box */
	.half	0x44		/* x size of collision box */
	.half	0x2c		/* y size of collision box */
	.half	0x0c01		/* strike routine */
	.half	0x1d04		/* damage */
	.half	SF_SQUEEZE
	.half	0

stk_saknee:
	.half	0x39		/* x offset of collision box */
	.half	0x30		/* y offset of collision box */
	.half	0x40		/* x size of collision box */
	.half	0x2b		/* y size of collision box */
	.half	0x0907		/* strike routine */
	.half	0x1203		/* damage */
	.half	SF_SQUEEZE
	.half	0

stk_sa2ndknee:
	.half	0x48		/* x offset of collision box */
	.half	0x10		/* y offset of collision box */
	.half	0x30		/* x size of collision box */
	.half	0x2b		/* y size of collision box */
	.half	0x0907		/* strike routine */
	.half	0x1203		/* damage */
	.half	SF_SQUEEZE
	.half	0

stk_saelbow:
	.half	0x3c		/* x offset of collision box */
	.half	0x0c		/* y offset of collision box */
	.half	0x32		/* x size of collision box */
	.half	0x22		/* y size of collision box */
	.half	0x0907		/* strike routine */
	.half	0x1003		/* damage */
	.half	SF_SQUEEZE
	.half	0

stk_shred:
	.half	0x50		/* x offset of collision box */
	.half	0x0c		/* y offset of collision box */
	.half	0x3c		/* x size of collision box */
	.half	0x4a		/* y size of collision box */
	.half	0x7b1a		/* strike routine */
	.half	0x280A		/* damage */
	.half	SF_SQUEEZE
	.half	0


stk_sazap1:
stk_sazap4:
	.half	0x0a		/* x offset of collision box */
	.half	-0x08		/* y offset of collision box */
	.half	50		/* x size of collision box */
	.half	20		/* y size of collision box */
	.half	0x1b01		/* strike routine */
	.half	0x1805		/* damage */
	.half	SF_SQUEEZE
	.half	0

stk_swipe:
	.half	0x68		/* x offset of collision box */
	.half	0x14		/* y offset of collision box */
	.half	0x46		/* x size of collision box */
	.half	0x18		/* y size of collision box */
	.half	0x7c10		/* strike routine */
	.half	0x1608		/* damage */
	.half	SF_SQUEEZE
	.half	0

stk_spin:
	.half	0x68		/* x offset of collision box */
	.half	0x14		/* y offset of collision box */
	.half	0x46		/* x size of collision box */
	.half	0x18		/* y size of collision box */
	.half	0x7a19		/* strike routine */
	.half	0x1002		/* damage */
	.half	SF_SQUEEZE
	.half	0

stk_spark1:
	.half	0x74		/* x offset of collision box */
	.half	0x1e		/* y offset of collision box */
	.half	0x4a		/* x size of collision box */
	.half	0x12		/* y size of collision box */
	.half	0x7904		/* strike routine */
	.half	0x1806		/* damage */
	.half	SF_SQUEEZE
	.half	0

stk_spark2:
	.half	0x94		/* x offset of collision box */
	.half	0x1e		/* y offset of collision box */
	.half	0x46		/* x size of collision box */
	.half	0x12		/* y size of collision box */
	.half	0x7904		/* strike routine */
	.half	0x1806		/* damage */
	.half	SF_SQUEEZE
	.half	0

/**************************************************************************
*											     *
*  Raiden strike tables									     *
*											     *
**************************************************************************/
rd_strikes:
	.word	stk_rdhikick	/* 0 */
	.word	stk_rdlokick	/* 1 */
	.word	stk_rdhipunch	/* 2 */
	.word	stk_rdlopunch	/* 3 */
	.word	stk_rdsweepk	/* 4 */
	.word	stk_rdduckpunch	/* 5 */
	.word	stk_rdduckkickh	/* 6 */
	.word	stk_rdduckkickl	/* 7 */
	.word	stk_rduppercut	/* 8 */
	.word	stk_rdjumpupp	/* 9 */
	.word	stk_rdjumpupk	/* a */
	.word	stk_rdflipk	/* b */
	.word	stk_rdflipp	/* c */
	.word	stk_rdroundh	/* d */
	.word	stk_rdknee	/* e */
	.word	stk_rdelbow	/* f */
	.word	stk_rdzap1	/* 10 */
	.word	stk_rdzap2	/* 11 */
	.word	stk_rdrzap1	/* 12 */
	.word	stk_rdrzap2	/* 13 */
	.word	stk_dive	/* 14 = raiden dive move */

stk_rdhikick:
	.half	0x58		/* x offset of collision box */
	.half	0x10		/* y offset of collision box */
	.half	0x3c		/* x size of collision box */
	.half	0x23		/* y size of collision box */
	.half	0x0006		/* strike routine */
	.half	0x1805		/* damage */
	.half	SF_SQUEEZE
	.half	0

stk_rdlokick:
	.half	0x63		/* x offset of collision box */
	.half	0x2d		/* y offset of collision box */
	.half	0x4a		/* x size of collision box */
	.half	0x22		/* y size of collision box */
	.half	0x0106		/* strike routine */
	.half	0x1504		/* damage */
	.half	SF_SQUEEZE
	.half	0

stk_rdhipunch:
	.half	0x49		/* x offset of collision box */
	.half	0x14		/* y offset of collision box */
	.half	0x3b		/* x size of collision box */
	.half	0x24		/* y size of collision box */
	.half	0x0211		/* strike routine */
	.half	0x0b03		/* damage */
	.half	SF_SQUEEZE
	.half	0

stk_rdlopunch:
	.half	0x4a		/* x offset of collision box */
	.half	0x21		/* y offset of collision box */
	.half	0x3c		/* x size of collision box */
	.half	0x18		/* y size of collision box */
	.half	0x0317		/* strike routine */
	.half	0x0802		/* damage */
	.half	SF_SQUEEZE
	.half	0

stk_rdsweepk:
	.half	0x67		/* x offset of collision box */
	.half	0x6b		/* y offset of collision box */
	.half	0x4a		/* x size of collision box */
	.half	0x22		/* y size of collision box */
	.half	0x0403		/* strike routine */
	.half	0x1403		/* damage */
	.half	SF_DUCK
	.half	0

stk_rdduckpunch:
	.half	0x46		/* x offset of collision box */
	.half	0x3d		/* y offset of collision box */
	.half	0x30		/* x size of collision box */
	.half	0x1c		/* y size of collision box */
	.half	0x050a		/* strike routine */
	.half	0x0602		/* damage */
	.half	SF_SQUEEZE
	.half	0

stk_rdduckkickh:
	.half	0x58		/* x offset of collision box */
	.half	0x38		/* y offset of collision box */
	.half	0x45		/* x size of collision box */
	.half	0x1b		/* y size of collision box */
	.half	0x060b		/* strike routine */
	.half	0x0c03		/* damage */
	.half	SF_SQUEEZE
	.half	0

stk_rdduckkickl:
	.half	0x5c		/* x offset of collision box */
	.half	0x78		/* y offset of collision box */
	.half	0x45		/* x size of collision box */
	.half	0x1b		/* y size of collision box */
	.half	0x070a		/* strike routine */
	.half	0x0602		/* damage */
	.half	SF_SQUEEZE
	.half	0

stk_rduppercut:
	.half	0x4e		/* x offset of collision box */
	.half	-0x0a		/* y offset of collision box */
	.half	0x36		/* x size of collision box */
	.half	0x42		/* y size of collision box */
	.half	0x0802		/* strike routine */
	.half	0x2409		/* damage */
	.half	SF_SQUEEZE
	.half	0

stk_rdjumpupp:
	.half	0x63		/* x offset of collision box */
	.half	0x08		/* y offset of collision box */
	.half	0x30		/* x size of collision box */
	.half	0x24		/* y size of collision box */
	.half	0x0b01		/* strike routine */
	.half	0x1005		/* damage */
	.half	SF_SQUEEZE
	.half	0

stk_rdjumpupk:
	.half	0x62		/* x offset of collision box */
	.half	0x14		/* y offset of collision box */
	.half	0x40		/* x size of collision box */
	.half	0x25		/* y size of collision box */
	.half	0x0b01		/* strike routine */
	.half	0x1306		/* damage */
	.half	SF_SQUEEZE
	.half	0

stk_rdflipk:
	.half	0x65		/* x offset of collision box */
	.half	0x28		/* y offset of collision box */
	.half	0x40		/* x size of collision box */
	.half	0x27		/* y size of collision box */
	.half	0x0a01		/* strike routine */
	.half	0x1a07		/* damage */
	.half	SF_SQUEEZE
	.half	0

stk_rdflipp:
	.half	0x63		/* x offset of collision box */
	.half	0x08		/* y offset of collision box */
	.half	0x40		/* x size of collision box */
	.half	0x2a		/* y size of collision box */
	.half	0x0b01		/* strike routine */
	.half	0x1005		/* damage */
	.half	SF_SQUEEZE
	.half	0

stk_rdroundh:
	.half	0x50		/* x offset of collision box */
	.half	0x06		/* y offset of collision box */
	.half	0x44		/* x size of collision box */
	.half	0x32		/* y size of collision box */
	.half	0x0c01		/* strike routine */
	.half	0x1d04		/* damage */
	.half	SF_SQUEEZE
	.half	0

stk_rdknee:
	.half	0x3b		/* x offset of collision box */
	.half	0x15		/* y offset of collision box */
	.half	0x30		/* x size of collision box */
	.half	0x38		/* y size of collision box */
	.half	0x0907		/* strike routine */
	.half	0x1203		/* damage */
	.half	SF_SQUEEZE
	.half	0

stk_rdelbow:
	.half	0x39		/* x offset of collision box */
	.half	0x0c		/* y offset of collision box */
	.half	0x40		/* x size of collision box */
	.half	0x24		/* y size of collision box */
	.half	0x0f0f		/* strike routine */
	.half	0x1806		/* damage */
	.half	SF_SQUEEZE
	.half	0

stk_rdzap1:
	.half	0x65		/* x offset of collision box */
	.half	0x24		/* y offset of collision box */
	.half	0x40		/* x size of collision box */
	.half	0x10		/* y size of collision box */
	.half	0x8010		/* strike routine */
	.half	0x1604		/* damage */
	.half	SF_SQUEEZE
	.half	0

stk_rdzap2:
	.half	0x85		/* x offset of collision box */
	.half	0x24		/* y offset of collision box */
	.half	0x3c		/* x size of collision box */
	.half	0x10		/* y size of collision box */
	.half	0x8010		/* strike routine */
	.half	0x1604		/* damage */
	.half	SF_SQUEEZE
	.half	0

stk_rdrzap1:
	.half	0x65		/* x offset of collision box */
	.half	0x24		/* y offset of collision box */
	.half	0x40		/* x size of collision box */
	.half	0x10		/* y size of collision box */
	.half	0x8110		/* strike routine */
	.half	0x1604		/* damage */
	.half	SF_SQUEEZE
	.half	0

stk_rdrzap2:
	.half	0x85		/* x offset of collision box */
	.half	0x24		/* y offset of collision box */
	.half	0x3c		/* x size of collision box */
	.half	0x10		/* y size of collision box */
	.half	0x8110		/* strike routine */
	.half	0x1604		/* damage */
	.half	SF_SQUEEZE
	.half	0

stk_dive:
	.half	0x50		/* x offset of collision box */
	.half	0x2d		/* y offset of collision box */
	.half	0x5a		/* x size of collision box */
	.half	0x18		/* y size of collision box */
	.half	0x7f00		/* strike routine */
	.half	0x1e07		/* damage */
	.half	SF_SQUEEZE
	.half	0


/*-u64- */

	.align 2
sk_strikes:
	.word	stk_sk_punch		/* 0 - punch */
	.word	stk_sk_kick		/* 1 - kick */
	.word	stk_sk_hammer		/* 2 - hammah time ! */
	.word	stk_sk_charge		/* 3 - charge */
	.word	stk_sk_zap		/* 4 - zap */
	.word	stk_sk_air_charge	/* 5 - air charge */
	.word	0					/*6 */
	.word	0					/*7 */
	.word	stk_sk_uppercut		/*8 - uppercut */

	.align 2
stk_sk_uppercut:
	.half	0x4d		/* x offset of collision box */
	.half	0xffed		/* y offset of collision box */
	.half	0x3a		/* x size of collision box */
	.half	0x4a		/* y size of collision box */
	.half	0x0802		/* strike routine */
	.half	0x2409		/* damage */
	.half	SF_SQUEEZE
	.half	0

	.align 2
stk_sk_punch:
	.half	0x53		/* x offset of collision box */
	.half	0x12		/* y offset of collision box */
	.half	0x46		/* x size of collision box */
	.half	0x75		/* y size of collision box */
	.half	0x6215		/* strike routine */
	.half	0x2206		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_sk_kick:
	.half	0x6d		/* x offset of collision box */
	.half	0x20		/* y offset of collision box */
	.half	0x4e		/* x size of collision box */
	.half	0x3d		/* y size of collision box */
	.half	0x6215		/* strike routine */
	.half	0x2706		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_sk_hammer:
	.half	0x86		/* x offset of collision box */
	.half	0x20		/* y offset of collision box */
	.half	0x77		/* x size of collision box */
	.half	0x39		/* y size of collision box */
	.half	0x6315		/* strike routine */
	.half	0x2706		/* damage */
	.half	SF_SQUEEZE

/*************************************************** */
	.align 2
nj_strikes:
	.word	stk_nj_hikick			/* 0 */
	.word	stk_nj_lokick			/* 1 */
	.word	stk_nj_hi_punch   		/* 2 */
	.word	stk_nj_lo_punch   		/* 3 */
	.word	stk_nj_sweep			/* 4 */
	.word	stk_nj_duck_punch		/* 5 */
	.word	stk_nj_duck_kickh		/* 6 */
	.word	stk_nj_duck_kickl		/* 7 */
	.word	stk_nj_uppercut   		/* 8 	 */
	.word	stk_nj_jump_punch		/* 9 */
	.word	stk_nj_jump_kick		/* a */
	.word	stk_nj_flip_kick		/* d */
	.word	stk_nj_flip_punch		/* c */
	.word	stk_nj_roundh			/* d */
	.word	stk_nj_knee			/* e */
	.word	stk_nj_elbow			/* f */
	.word	stk_nj_slide			/* 10 */
	.word	stk_nj_orb			/* 11 */
	.word	stk_nj_spit			/* 12 */
	.word	stk_sz_forward_zap		/* 13 */
	.word	stk_scorp_spear			/* 14 */
	.word	stk_reptile_dash   		/* 15 */
	.word	stk_reptile_dash2   		/* 16 */
	.word	stk_scorp_tele			/* 17 */
	.word	stk_floor_ice			/* 18 */
	.word	stk_ermac_zap			/* 19 */
	.word	stk_ermac_slam			/* 1a */
	.word	stk_noob_zap			/* 1b -u64- */
	.word	stk_rain_bolt			/* 1c -u64- */
	.word	stk_rain_zap			/* 1d -u64- */
	.word	stk_osz_zap			/* 1e */
	.word	stk_rain_roundh			/* 1f */
	.word 	stk_noob_slam			/* 20 */

	.align 2
stk_sz_forward_zap:
	.half	0x82		/* x offset of collision box */
	.half	0xfff5		/* y offset of collision box */
	.half	0x3e		/* x size of collision box */
	.half	0x06		/* y size of collision box */
	.half	0x2c05		/* strike routine */
	.half	0x0000		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_rain_roundh:
	.half	0x5b		/* x offset of collision box */
	.half	0x00		/* y offset of collision box */
	.half	0x46		/* x size of collision box */
	.half	0x36		/* y size of collision box */
	.half	0x8c01		/* strike routine */
	.half	0x0e04		/* damage */
	.half	SF_SQUEEZE
	.half	0


	.align 2
stk_osz_zap:
	.half	0x17		/* x offset of collision box */
	.half	0x3f		/* y offset of collision box */
	.half	0x30		/* x size of collision box */
	.half	0x7e		/* y size of collision box */
	.half	0x2c05		/* strike routine */
	.half	0x0000		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_nj_hikick:
	.half	0x60		/* x offset of collision box */
	.half	0x04		/* y offset of collision box */
	.half	0x41		/* x size of collision box */
	.half	0x2c		/* y size of collision box */
	.half	0x0006		/* strike routine */
	.half	0x1805		/* damage */
	.half	SF_SQUEEZE
 	.half	0

	.align 2
stk_nj_lokick:
	.half	0x6d		/* x offset of collision box */
	.half	0x2a		/* y offset of collision box */
	.half	0x4a		/* x size of collision box */
	.half	0x13		/* y size of collision box */
	.half	0x0106		/* strike routine */
	.half	0x1504		/* damage */
	.half	SF_SQUEEZE
 	.half	0

	.align 2
stk_nj_hi_punch:
	.half	0x4d		/* x offset of collision box */
	.half	0x01		/* y offset of collision box */
	.half	0x35		/* x size of collision box */
	.half	0x21		/* y size of collision box */
	.half	0x0211		/* strike routine */
	.half	0x0b03		/* damage */
 	.half	SF_SQUEEZE
 	.half	0

	.align 2
stk_nj_lo_punch:
	.half	0x54		/* x offset of collision box */
	.half	0x1f		/* y offset of collision box */
	.half	0x3d		/* x size of collision box */
	.half	0x14		/* y size of collision box */
	.half	0x0317		/* strike routine */
	.half	0x0802		/* damage */
	.half	SF_SQUEEZE
 	.half	0

	.align 2
stk_nj_sweep:
	.half	0x67		/* x offset of collision box */
	.half	0x6b		/* y offset of collision box */
	.half	0x51		/* x size of collision box */
	.half	0x1b		/* y size of collision box */
	.half	0x0403		/* strike routine */
	.half	0x1403		/* damage */
	.half	SF_DUCK
 	.half	0

	.align 2
stk_noob_slam:
	.half	0x65		/* x offset of collision box */
	.half	0x20-3		/* y offset of collision box */
	.half	0x3f		/* x size of collision box */
	.half	0x10		/* y size of collision box */
	.half	0x0400		/* strike routine */
	.half	0x0003		/* damage */
	.half	0
 	.half	0

	.align 2
stk_nj_duck_punch:
	.half	0x4d		/* x offset of collision box */
	.half	0x36		/* y offset of collision box */
	.half	0x36		/* x size of collision box */
	.half	0x12		/* y size of collision box */
	.half	0x050a		/* strike routine */
	.half	0x0602		/* damage */
	.half	SF_SQUEEZE
 	.half	0

	.align 2
stk_nj_duck_kickh:
	.half	0x48		/* x offset of collision box */
	.half	0x3b		/* y offset of collision box */
	.half	0x41		/* x size of collision box */
	.half	0x1e		/* y size of collision box */
	.half	0x060b		/* strike routine */
	.half	0x0c03		/* damage */
	.half	SF_SQUEEZE
 	.half	0

	.align 2
stk_nj_duck_kickl:
	.half	0x57		/* x offset of collision box */
	.half	0x69		/* y offset of collision box */
	.half	0x44		/* x size of collision box */
	.half	0x16		/* y size of collision box */
	.half	0x070a		/* strike routine */
	.half	0x0602		/* damage */
	.half	SF_SQUEEZE
 	.half	0

	.align 2
stk_nj_uppercut:
	.half	0x4d		/* x offset of collision box */
	.half	0xffed		/* y offset of collision box */
	.half	0x3a		/* x size of collision box */
	.half	0x4a		/* y size of collision box */
	.half	0x0802		/* strike routine */
	.half	0x2409		/* damage */
	.half	SF_SQUEEZE
	.half	0

	.align 2
stk_nj_jump_punch:
	.half	0x4e		/* x offset of collision box */
	.half	0x17		/* y offset of collision box */
	.half	0x3a		/* x size of collision box */
	.half	0x2e		/* y size of collision box */
	.half	0x0b01		/* strike routine */
	.half	0x1005		/* damage */
	.half	SF_SQUEEZE
	.half	0

	.align 2
stk_nj_jump_kick:
	.half	0x4e		/* x offset of collision box */
	.half	0x02		/* y offset of collision box */
	.half	0x42		/* x size of collision box */
	.half	0x3b		/* y size of collision box */
	.half	0x0b01		/* strike routine */
	.half	0x1306		/* damage */
	.half	SF_SQUEEZE
	.half	0

	.align 2
stk_nj_flip_kick:
	.half	0x42		/* x offset of collision box */
	.half	0x23		/* y offset of collision box */
	.half	0x2e		/* x size of collision box */
	.half	0x26		/* y size of collision box */
	.half	0x0a01		/* strike routine */
	.half	0x1a07		/* damage */
	.half	SF_SQUEEZE
	.half	0

	.align 2
stk_nj_flip_punch:
	.half	0x4e		/* x offset of collision box */
	.half	0x17		/* y offset of collision box */
	.half	0x3a		/* x size of collision box */
	.half	0x2e		/* y size of collision box */
	.half	0x0b01		/* strike routine */
	.half	0x1005		/* damage */
	.half	SF_SQUEEZE
	.half	0

	.align 2
stk_nj_roundh:
	.half	0x5b		/* x offset of collision box */
	.half	0x00		/* y offset of collision box */
	.half	0x46		/* x size of collision box */
	.half	0x36		/* y size of collision box */
	.half	0x0c01		/* strike routine */
	.half	0x1d04		/* damage */
	.half	SF_SQUEEZE
	.half	0

	.align 2
stk_nj_knee:
	.half	0x4a		/* x offset of collision box */
	.half	0x21		/* y offset of collision box */
	.half	0x31		/* x size of collision box */
	.half	0x34		/* y size of collision box */
	.half	0x0907		/* strike routine */
	.half	0x1203		/* damage */
	.half	SF_SQUEEZE
	.half	0

	.align 2
stk_nj_elbow:
	.half	0x59		/* x offset of collision box */
	.half	0x0f		/* y offset of collision box */
	.half	0x3c		/* x size of collision box */
	.half	0x2c		/* y size of collision box */
	.half	0x4c07		/* strike routine */
	.half	0x1003		/* damage */
	.half	SF_SQUEEZE
	.half	0

	.align 2
stk_nj_orb:
	.half	0x63		/* x offset of collision box */
	.half	0x2c		/* y offset of collision box */
	.half	0x2f		/* x size of collision box */
	.half	0x3d		/* y size of collision box */
	.half	0x7101		/* strike routine */
	.half	0x1202		/* damage */
	.half	SF_SQUEEZE
	.half	0

	.align 2
stk_nj_slide:
	.half	0x38		/* x offset of collision box */
	.half	0x59		/* y offset of collision box */
	.half	0x47		/* x size of collision box */
	.half	0x2a		/* y size of collision box */
	.half	0x2d00		/* strike routine */
	.half	0x0d03		/* damage */
	.half	SF_SQUEEZE
	.half	0

	.align 2
stk_nj_spit:
	.half	0xc1		/* x offset of collision box */
	.half	0x1b		/* y offset of collision box */
	.half	0x40		/* x size of collision box */
	.half	0x0c		/* y size of collision box */
	.half	0x7201		/* strike routine */
	.half	0x0f04		/* damage */
	.half	SF_SQUEEZE
	.half	0

	.align 2
stk_scorp_tele:
	.half	0x4c		/* x offset of collision box */
	.half	0x11		/* y offset of collision box */
	.half	0x36		/* x size of collision box */
	.half	0x2a		/* y size of collision box */
	.half	0x7300		/* strike routine */
	.half	0x0f04		/* damage */
	.half	SF_SQUEEZE
	.half	0

	.align 2
stk_scorp_spear:
	.half	0x54		/* x offset of collision box */
	.half	0x19		/* y offset of collision box */
	.half	0x35		/* x size of collision box */
	.half	0x11		/* y size of collision box */
	.half	0x7500		/* strike routine */
	.half	0x0802		/* damage */
	.half	SF_SQUEEZE
	.half	0

	.align 2
stk_reptile_dash:
	.half	0x2b		/* x offset of collision box */
	.half	0x09		/* y offset of collision box */
	.half	0x22		/* x size of collision box */
	.half	0x6e		/* y size of collision box */
	.half	0x7400		/* strike routine */
	.half	0x0000
	.half	SF_SQUEEZE
	.half	0

	.align 2
stk_reptile_dash2:
	.half	0x44		/* x offset of collision box */
	.half	0x0b		/* y offset of collision box */
	.half	0x27		/* x size of collision box */
	.half	0x3c		/* y size of collision box */
	.half	0x2400		/* strike routine */
	.half	0x0d03		/* damage */
	.half	SF_SQUEEZE
	.half	0

	.align 2
stk_floor_ice:
	.half	0x9a		/* x offset of collision box */
	.half	0x76		/* y offset of collision box */
	.half	0x4e		/* x size of collision box */
	.half	0x11		/* y size of collision box */
	.half	0x7616		/* strike routine */
	.half	0x0000		/* damage */
	.half	SF_SQUEEZE
	.half	0

	.align 2
stk_ermac_zap:
	.half	0x6d		/* x offset of collision box */
	.half	0x3a		/* y offset of collision box */
	.half	0x22		/* x size of collision box */
	.half	0x09		/* y size of collision box */
	.half	0x7701		/* strike routine */
	.half	0x1403		/* damage */
	.half	SF_SQUEEZE
	.half	0

	.align 2
stk_ermac_slam:
	.half	0xce
	.half	0x24
	.half	0x6a
	.half	0x5a
	.half	0x7801		/* strike routine */
	.half	0x0000		/* damage */
	.half	SF_SQUEEZE
	.half	0


	.align 2
stk_rain_zap:
	.half	0xb1		/* x offset of collision box */
	.half	0x32		/* y offset of collision box */
	.half	0x26		/* x size of collision box */
	.half	0x12		/* y size of collision box */
	.half	0x8b01		/* strike routine */
	.half	0x1403		/* damage */
	.half	SF_SQUEEZE
	.half	0

	.align 2
stk_rain_bolt:
	.half	0x68
	.half	0x88
	.half	0x30
	.half	0x60
	.half	0x8a01		/* strike routine */
	.half	0x0903		/* damage */
	.half	SF_SQUEEZE
	.half	0


	.align 2
stk_noob_zap:
	.half	0xae		/* x offset of collision box */
	.half	0x3a		/* y offset of collision box */
	.half	0x27		/* x size of collision box */
	.half	0x12		/* y size of collision box */
	.half	0x8504		/* strike routine */
	.half	0x0502		/* damage */
	.half	SF_SQUEEZE
	.half	0


/****************************************************** */

fn_strikes:
	.word	stk_fn_hikick			/* 0 */
	.word	stk_fn_lokick			/* 1 */
	.word	stk_fn_hi_punch   		/* 2 */
	.word	stk_fn_lo_punch   		/* 3 */
	.word	stk_fn_sweep			/* 4 */
	.word	stk_fn_duck_punch		/* 5 */
	.word	stk_fn_duck_kickh		/* 6 */
	.word	stk_fn_duck_kickl		/* 7 */
	.word	stk_fn_uppercut   		/* 8 	 */
	.word	stk_fn_jump_punch		/* 9 */
	.word	stk_fn_jump_kick		/* a */
	.word	stk_fn_flip_kick		/* d */
	.word	stk_fn_flip_punch		/* c */
	.word	stk_fn_roundh			/* d */
	.word	stk_fn_knee			/* e */
	.word	stk_kit_elbow			/* f */
	.word	stk_jade_prop			/* 10 */
	.word	stk_kit_square			/* 11 */
	.word	stk_fan_lift			/* 12 */
	.word	stk_fn_fan			/* 13 */
	.word	stk_boomerang			/* 14 */
	.word	stk_mileena_tele		/* 15 */
	.word	stk_mileena_roll		/* 16 */
	.word	stk_mileena_zap			/* 17 */

	.align 2
stk_fn_hikick:
	.half	0x62		/* x offset of collision box */
	.half	0x17		/* y offset of collision box */
	.half	0x41		/* x size of collision box */
	.half	0x16		/* y size of collision box */
	.half	0x0006		/* strike routine */
	.half	0x1805		/* damage */
	.half	SF_SQUEEZE
	.half	0

	.align 2
stk_fn_lokick:
	.half	0x67		/* x offset of collision box */
	.half	0x32		/* y offset of collision box */
	.half	0x44		/* x size of collision box */
	.half	0x08		/* y size of collision box */
	.half	0x0106		/* strike routine */
	.half	0x1504		/* damage */
	.half	SF_SQUEEZE
	.half	0

	.align 2
stk_fn_hi_punch:
	.half	0x48		/* x offset of collision box */
	.half	0x0a		/* y offset of collision box */
	.half	0x32		/* x size of collision box */
	.half	0x1d		/* y size of collision box */
	.half	0x0211		/* strike routine */
	.half	0x0b03		/* damage */
 	.half	SF_SQUEEZE
	.half	0

	.align 2
stk_fn_lo_punch:
	.half	0x51		/* x offset of collision box */
	.half	0x28		/* y offset of collision box */
	.half	0x44		/* x size of collision box */
	.half	0x12		/* y size of collision box */
	.half	0x0317		/* strike routine */
	.half	0x0802		/* damage */
	.half	SF_SQUEEZE
	.half	0

	.align 2
stk_fn_sweep:
	.half	0x66		/* x offset of collision box */
	.half	0x6c		/* y offset of collision box */
	.half	0x4e		/* x size of collision box */
	.half	0x18		/* y size of collision box */
	.half	0x0403		/* strike routine */
	.half	0x1403		/* damage */
	.half	SF_DUCK
	.half	0

	.align 2
stk_fn_duck_punch:
	.half	0x44		/* x offset of collision box */
	.half	0x44		/* y offset of collision box */
	.half	0x33		/* x size of collision box */
	.half	0x12		/* y size of collision box */
	.half	0x050a		/* strike routine */
	.half	0x0602		/* damage */
	.half	SF_SQUEEZE
	.half	0

	.align 2
stk_fn_duck_kickh:
	.half	0x3d		/* x offset of collision box */
	.half	0x37		/* y offset of collision box */
	.half	0x41		/* x size of collision box */
	.half	0x25		/* y size of collision box */
	.half	0x060b		/* strike routine */
	.half	0x0c03		/* damage */
	.half	SF_SQUEEZE
	.half	0

	.align 2
stk_fn_duck_kickl:
	.half	0x58		/* x offset of collision box */
	.half	0x68		/* y offset of collision box */
	.half	0x44		/* x size of collision box */
	.half	0x1b		/* y size of collision box */
	.half	0x070a		/* strike routine */
	.half	0x0602		/* damage */
	.half	SF_SQUEEZE
	.half	0

	.align 2
stk_fn_uppercut:
	.half	0x4f		/* x offset of collision box */
	.half	0xfff6		/* y offset of collision box */
	.half	0x3a		/* x size of collision box */
	.half	0x45		/* y size of collision box */
	.half	0x0802		/* strike routine */
	.half	0x2409		/* damage */
	.half	SF_SQUEEZE
	.half	0

	.align 2
stk_fn_jump_punch:
	.half	0x42		/* x offset of collision box */
	.half	0x17		/* y offset of collision box */
	.half	0x33		/* x size of collision box */
	.half	0x28		/* y size of collision box */
	.half	0x0b01		/* strike routine */
	.half	0x1005		/* damage */
	.half	SF_SQUEEZE
	.half	0

	.align 2
stk_fn_jump_kick:
	.half	0x43		/* x offset of collision box */
	.half	0xfffd		/* y offset of collision box */
	.half	0x40		/* x size of collision box */
	.half	0x39		/* y size of collision box */
	.half	0x0b01		/* strike routine */
	.half	0x1306		/* damage */
	.half	SF_SQUEEZE
	.half	0

	.align 2
stk_fn_flip_kick:
	.half	0x45		/* x offset of collision box */
	.half	0x2a		/* y offset of collision box */
	.half	0x3a		/* x size of collision box */
	.half	0x23		/* y size of collision box */
	.half	0x0a01		/* strike routine */
	.half	0x1a07		/* damage */
	.half	SF_SQUEEZE
	.half	0

	.align 2
stk_fn_flip_punch:
	.half	0x42		/* x offset of collision box */
	.half	0x17		/* y offset of collision box */
	.half	0x33		/* x size of collision box */
	.half	0x28		/* y size of collision box */
	.half	0x0b01		/* strike routine */
	.half	0x1005		/* damage */
	.half	SF_SQUEEZE
	.half	0

	.align 2
stk_fn_roundh:
	.half	0x56		/* x offset of collision box */
	.half	0x09		/* y offset of collision box */
	.half	0x46		/* x size of collision box */
	.half	0x30		/* y size of collision box */
	.half	0x0c01		/* strike routine */
	.half	0x1d04		/* damage */
	.half	SF_SQUEEZE
	.half	0

	.align 2
stk_fn_knee:
	.half	0x55		/* x offset of collision box */
	.half	0x21		/* y offset of collision box */
	.half	0x3e		/* x size of collision box */
	.half	0x3f		/* y size of collision box */
	.half	0x0907		/* strike routine */
	.half	0x1203		/* damage */
	.half	SF_SQUEEZE
	.half	0

	.align 2
stk_kit_elbow:
	.half	0x4d		/* x offset of collision box */
	.half	0x0c		/* y offset of collision box */
	.half	0x3b		/* x size of collision box */
	.half	0x32		/* y size of collision box */
	.half	0x4c07		/* strike routine */
	.half	0x1003		/* damage */
	.half	SF_SQUEEZE
	.half	0

	.align 2
stk_fn_fan:
	.half	0x17		/* x offset of collision box */
	.half	0x0e		/* y offset of collision box */
	.half	0x2a		/* x size of collision box */
	.half	0x0f		/* y size of collision box */
	.half	0x6600		/* strike routine */
	.half	0x1603		/* damage */
	.half	SF_SQUEEZE
	.half	0

	.align 2
stk_fan_lift:
	.half	0x62		/* x offset of collision box */
	.half	0xffd3		/* y offset of collision box */
	.half	0x50		/* x size of collision box */
	.half	0x54		/* y size of collision box */
	.half	0x6701		/* strike routine */
	.half	0x0000		/* damage */
	.half	SF_SQUEEZE
	.half	0

	.align 2
stk_kit_square:
	.half	0x4b		/* x offset of collision box */
	.half	0x0d		/* y offset of collision box */
	.half	0x43		/* x size of collision box */
	.half	0x2d		/* y size of collision box */
	.half	0x1d00		/* strike routine */
	.half	0x1b08		/* damage */
	.half	SF_SQUEEZE
	.half	0

	.align 2
stk_boomerang:
	.half	0x17		/* x offset of collision box */
	.half	0xffef		/* y offset of collision box */
	.half	0x27		/* x size of collision box */
	.half	0x22		/* y size of collision box */
	.half	0x6800		/* strike routine */
	.half	0x1403		/* damage */
	.half	SF_SQUEEZE
	.half	0

	.align 2
stk_jade_prop:
	.half	0x61		/* x offset of collision box */
	.half	0x28		/* y offset of collision box */
	.half	0x5b		/* x size of collision box */
	.half	0x14		/* y size of collision box */
	.half	0x6901		/* strike routine */
	.half	0x1303		/* damage */
	.half	SF_SQUEEZE
	.half	0

	.align 2
stk_mileena_tele:
	.half	0x34		/* x offset of collision box */
	.half	0x21		/* y offset of collision box */
	.half	0x2b		/* x size of collision box */
	.half	0x23		/* y size of collision box */
	.half	0x6a00		/* strike routine */
	.half	0x1803		/* damage */
	.half	SF_SQUEEZE
	.half	0

	.align 2
stk_mileena_roll:
	.half	0x21		/* x offset of collision box */
	.half	0x0c		/* y offset of collision box */
	.half	0x3c		/* x size of collision box */
	.half	0x2a		/* y size of collision box */
	.half	0x6b00		/* strike routine */
	.half	0x1003		/* damage */
	.half	0
	.half	0

	.align 2
stk_mileena_zap:
	.half	0x2d		/* x offset of collision box */
	.half	0xfff8		/* y offset of collision box */
	.half	0x47		/* x size of collision box */
	.half	0x19		/* y size of collision box */
	.half	0x6c00		/* strike routine */
	.half	0x1002		/* damage */
	.half	SF_SQUEEZE
	.half	0

/************************************ */

	.align 2
stk_sk_charge:
	.half	0x40		/* x offset of collision box */
	.half	0x11		/* y offset of collision box */
	.half	0x42		/* x size of collision box */
	.half	0x90		/* y size of collision box */
	.half	0x6415		/* strike routine */
	.half	0x2005		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_sk_zap:
	.half	0x78		/* x offset of collision box */
	.half	0x29		/* y offset of collision box */
	.half	0x34		/* x size of collision box */
	.half	0x31		/* y size of collision box */
	.half	0x6415		/* strike routine */
	.half	0x2306		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_sk_air_charge:
	.half	0x4d		/* x offset of collision box */
	.half	0x17		/* y offset of collision box */
	.half	0x46		/* x size of collision box */
	.half	0x4a		/* y size of collision box */
	.half	0x6515		/* strike routine */
	.half	0x2005		/* damage */
	.half	SF_SQUEEZE

/**************************************************************************
*											     *
*   Motaro Strikes									     *
*											     *
**************************************************************************/
	.align 2
mot_strikes:
	.word	stk_mot_punch		/* 0 */
	.word	stk_mot_kick
	.word	stk_mot_sweep
	.word	stk_mot_zap
	.word	stk_dummy
	.word	stk_dummy
	.word	stk_dummy


	.align 2
stk_mot_punch:
	.half	0x6b		/* x offset of collision box */
	.half	0x12		/* y offset of collision box */
	.half	0x5f		/* x size of collision box */
	.half	0x75		/* y size of collision box */
	.half	0x6015		/* strike routine */
	.half	0x2809		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_mot_kick:
	.half	0x0b		/* x offset of collision box */
	.half	0x23		/* y offset of collision box */
	.half	0x72		/* x size of collision box */
	.half	0x64		/* y size of collision box */
	.half	0x6115		/* strike routine */
	.half	0x300d		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_mot_sweep:
	.half	0xe3		/* x offset of collision box */
	.half	0x6e		/* y offset of collision box */
	.half	0xbd		/* x size of collision box */
	.half	0x34		/* y size of collision box */
	.half	0x0403		/* strike routine */
	.half	0x2007		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_mot_zap:
	.half	0x0d		/* x offset of collision box */
	.half	0xfff2		/* y offset of collision box */
	.half	0x19		/* x size of collision box */
	.half	0x1c		/* y size of collision box */
	.half	0x6015		/* strike routine */
	.half	0x2005		/* damage */
	.half	SF_SQUEEZE

/**************************************************************************
*											     *
*   Liu Kang strikes 									     *
*											     *
**************************************************************************/
	.align 2
lk_strikes:
	.word	stk_lk_hikick			/* 0 */
	.word	stk_lk_lokick			/* 1 */
	.word	stk_lk_hi_punch   		/* 2 */
	.word	stk_lk_lo_punch   		/* 3 */
	.word	stk_lk_sweep			/* 4 */
	.word	stk_lk_duck_punch		/* 5 */
	.word	stk_lk_duck_kickh		/* 6 */
	.word	stk_lk_duck_kickl		/* 7 */
	.word	stk_lk_uppercut   		/* 8 */
	.word	stk_lk_jump_punch		/* 9 */
	.word	stk_lk_jump_kick		/* a */
	.word	stk_lk_flip_kick		/* d */
	.word	stk_lk_flip_punch		/* c */
	.word	stk_lk_roundh			/* d */
	.word	stk_lk_knee			/* e */
	.word	stk_lk_elbow			/* f */
	.word	stk_dummy			/* 10 */
	.word	stk_lk_zap			/* 11 */
	.word	stk_lk_bike			/* 12 */
	.word	stk_super_kang			/* 13 */
	.word	stk_lk_sbike			/* 14 */
	.word	stk_dummy			/* */
	.word	stk_dummy			/* */
	.word	stk_dummy			/* */

	.align 2
stk_lk_hikick:
	.half	0x4e		/* x offset of collision box */
	.half	0x0e		/* y offset of collision box */
	.half	0x4e		/* x size of collision box */
	.half	0x2a		/* y size of collision box */
	.half	0x0006		/* strike routine */
	.half	0x1805		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_lk_lokick:
	.half	0x5f		/* x offset of collision box */
	.half	0x30		/* y offset of collision box */
	.half	0x4f		/* x size of collision box */
	.half	0x0f		/* y size of collision box */
	.half	0x0106		/* strike routine */
	.half	0x1504		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_lk_hi_punch:
	.half	0x48		/* x offset of collision box */
	.half	0x09		/* y offset of collision box */
	.half	0x35		/* x size of collision box */
	.half	0x1d		/* y size of collision box */
	.half	0x0211		/* strike routine */
	.half	0x0b03		/* damage */
 	.half	SF_SQUEEZE

	.align 2
stk_lk_lo_punch:
	.half	0x54		/* x offset of collision box */
	.half	0x20		/* y offset of collision box */
	.half	0x41		/* x size of collision box */
	.half	0x15		/* y size of collision box */
	.half	0x0317		/* strike routine */
	.half	0x0802		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_lk_sweep:
	.half	0x6a		/* x offset of collision box */
	.half	0x6c		/* y offset of collision box */
	.half	0x4a		/* x size of collision box */
	.half	0x19		/* y size of collision box */
	.half	0x0403		/* strike routine */
	.half	0x1403		/* damage */
	.half	SF_DUCK

	.align 2
stk_lk_duck_punch:
	.half	0x4d		/* x offset of collision box */
	.half	0x49		/* y offset of collision box */
	.half	0x3b		/* x size of collision box */
	.half	0x10		/* y size of collision box */
	.half	0x050a		/* strike routine */
	.half	0x0602		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_lk_duck_kickh:
	.half	0x50		/* x offset of collision box */
	.half	0x37		/* y offset of collision box */
	.half	0x40		/* x size of collision box */
	.half	0x21		/* y size of collision box */
	.half	0x060b		/* strike routine */
	.half	0x0c03		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_lk_duck_kickl:
	.half	0x51		/* x offset of collision box */
	.half	0x6d		/* y offset of collision box */
	.half	0x3c		/* x size of collision box */
	.half	0x18		/* y size of collision box */
	.half	0x070a		/* strike routine */
	.half	0x0602		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_lk_uppercut:
	.half	0x46		/* x offset of collision box */
	.half	0xfff6		/* y offset of collision box */
	.half	0x37		/* x size of collision box */
	.half	0x43		/* y size of collision box */
	.half	0x0802		/* strike routine */
	.half	0x2409		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_lk_jump_punch:
	.half	0x55		/* x offset of collision box */
	.half	0x05		/* y offset of collision box */
	.half	0x3a		/* x size of collision box */
	.half	0x28		/* y size of collision box */
	.half	0x0b01		/* strike routine */
	.half	0x1005		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_lk_jump_kick:
	.half	0x3d		/* x offset of collision box */
	.half	0xfffa		/* y offset of collision box */
	.half	0x36		/* x size of collision box */
	.half	0x34		/* y size of collision box */
	.half	0x0b01		/* strike routine */
	.half	0x1306		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_lk_flip_kick:
	.half	0x57		/* x offset of collision box */
	.half	0x10		/* y offset of collision box */
	.half	0x3f		/* x size of collision box */
	.half	0x2c		/* y size of collision box */
	.half	0x0a01		/* strike routine */
	.half	0x1a07		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_lk_flip_punch:
	.half	0x55		/* x offset of collision box */
	.half	0x05		/* y offset of collision box */
	.half	0x3a		/* x size of collision box */
	.half	0x28		/* y size of collision box */
	.half	0x0b01		/* strike routine */
	.half	0x0d04		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_lk_roundh:
	.half	0x6b		/* x offset of collision box */
	.half	0x05		/* y offset of collision box */
	.half	0x53		/* x size of collision box */
	.half	0x34		/* y size of collision box */
	.half	0x0c01		/* strike routine */
	.half	0x1d04		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_lk_knee:
	.half	0x47		/* x offset of collision box */
	.half	0x21		/* y offset of collision box */
	.half	0x33		/* x size of collision box */
	.half	0x3d		/* y size of collision box */
	.half	0x0907		/* strike routine */
	.half	0x1203		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_lk_elbow:
	.half	0x40		/* x offset of collision box */
	.half	0x0c		/* y offset of collision box */
	.half	0x2e		/* x size of collision box */
	.half	0x32		/* y size of collision box */
	.half	0x0907		/* strike routine */
	.half	0x1003		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_lk_zap:
	.half	0xd0		/* x offset of collision box */
	.half	0x10		/* y offset of collision box */
	.half	0x51		/* x size of collision box */
	.half	0x14		/* y size of collision box */
	.half	0x5501		/* strike routine */
	.half	0x1603		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_lk_bike:
	.half	0x42		/* x offset of collision box */
	.half	0x10		/* y offset of collision box */
	.half	0x41		/* x size of collision box */
	.half	0x2a		/* y size of collision box */
	.half	0x5600		/* strike routine */
	.half	0x1402		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_lk_sbike:
	.half	0x42		/* x offset of collision box */
	.half	0x10		/* y offset of collision box */
	.half	0x41		/* x size of collision box */
	.half	0x2a		/* y size of collision box */
	.half	0x5600		/* strike routine */
	.half	0x1001		/* damage */
	.half	SF_SQUEEZE


	.align 2
stk_super_kang:
	.half	0x63		/* x offset of collision box */
	.half	0x21		/* y offset of collision box */
	.half	0x4b		/* x size of collision box */
	.half	0x1c		/* y size of collision box */
	.half	0x5700		/* strike routine */
	.half	0x1704		/* damage */
	.half	SF_SQUEEZE

/**************************************************************************
*											     *
*   Shang Tsung strikes 									     *
*											     *
**************************************************************************/
	.align 2
st_strikes:
	.word	stk_st_hikick			/* 0 */
	.word	stk_st_lokick			/* 1 */
	.word	stk_st_hi_punch   		/* 2 */
	.word	stk_st_lo_punch   		/* 3 */
	.word	stk_st_sweep			/* 4 */
	.word	stk_st_duck_punch		/* 5 */
	.word	stk_st_duck_kickh		/* 6 */
	.word	stk_st_duck_kickl		/* 7 */
	.word	stk_st_uppercut   		/* 8 */
	.word	stk_st_jump_punch		/* 9 */
	.word	stk_st_jump_kick		/* a */
	.word	stk_st_flip_kick		/* d */
	.word	stk_st_flip_punch		/* c */
	.word	stk_st_roundh			/* d */
	.word	stk_st_knee			/* e */
	.word	stk_st_elbow			/* f */
	.word	stk_dummy			/* 10 */
	.word	stk_st_zap			/* 11 */
	.word	stk_summon			/* 12 */
	.word	stk_dummy			/* 13 */
	.word	stk_dummy			/* 14 */
	.word	stk_dummy			/* */
	.word	stk_dummy			/* */
	.word	stk_dummy			/* */


	.align 2
stk_st_hikick:
	.half	0x55		/* x offset of collision box */
	.half	0xfffb		/* y offset of collision box */
	.half	0x49		/* x size of collision box */
	.half	0x31		/* y size of collision box */
	.half	0x0006		/* strike routine */
	.half	0x1805		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_st_lokick:
	.half	0x6a		/* x offset of collision box */
	.half	0x27		/* y offset of collision box */
	.half	0x53		/* x size of collision box */
	.half	0x14		/* y size of collision box */
	.half	0x0106		/* strike routine */
	.half	0x1504		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_st_hi_punch:
	.half	0x54		/* x offset of collision box */
	.half	0x03		/* y offset of collision box */
	.half	0x3e		/* x size of collision box */
	.half	0x1d		/* y size of collision box */
	.half	0x0211		/* strike routine */
	.half	0x0b03		/* damage */
 	.half	SF_SQUEEZE

	.align 2
stk_st_lo_punch:
	.half	0x53		/* x offset of collision box */
	.half	0x18		/* y offset of collision box */
	.half	0x39		/* x size of collision box */
	.half	0x1b		/* y size of collision box */
	.half	0x0317		/* strike routine */
	.half	0x0802		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_st_sweep:
	.half	0x60		/* x offset of collision box */
	.half	0x67		/* y offset of collision box */
	.half	0x52		/* x size of collision box */
	.half	0x1a		/* y size of collision box */
	.half	0x0403		/* strike routine */
	.half	0x1403		/* damage */
	.half	SF_DUCK

	.align 2
stk_st_duck_punch:
	.half	0x4d		/* x offset of collision box */
	.half	0x37		/* y offset of collision box */
	.half	0x39		/* x size of collision box */
	.half	0x10		/* y size of collision box */
	.half	0x050a		/* strike routine */
	.half	0x0602		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_st_duck_kickh:
	.half	0x59		/* x offset of collision box */
	.half	0x3c		/* y offset of collision box */
	.half	0x40		/* x size of collision box */
	.half	0x1c		/* y size of collision box */
	.half	0x060b		/* strike routine */
	.half	0x0c03		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_st_duck_kickl:
	.half	0x5a		/* x offset of collision box */
	.half	0x69		/* y offset of collision box */
	.half	0x44		/* x size of collision box */
	.half	0x15		/* y size of collision box */
	.half	0x070a		/* strike routine */
	.half	0x0602		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_st_uppercut:
	.half	0x55		/* x offset of collision box */
	.half	0xfff2		/* y offset of collision box */
	.half	0x3d		/* x size of collision box */
	.half	0x40		/* y size of collision box */
	.half	0x0802		/* strike routine */
	.half	0x2409		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_st_jump_punch:
	.half	0x57		/* x offset of collision box */
	.half	0x09		/* y offset of collision box */
	.half	0x3e		/* x size of collision box */
	.half	0x28		/* y size of collision box */
	.half	0x0b01		/* strike routine */
	.half	0x1005		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_st_jump_kick:
	.half	0x5d		/* x offset of collision box */
	.half	0xfff5		/* y offset of collision box */
	.half	0x4e		/* x size of collision box */
	.half	0x2d		/* y size of collision box */
	.half	0x0b01		/* strike routine */
	.half	0x1306		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_st_flip_kick:
	.half	0x57		/* x offset of collision box */
	.half	0x17		/* y offset of collision box */
	.half	0x3a		/* x size of collision box */
	.half	0x2c		/* y size of collision box */
	.half	0x0a01		/* strike routine */
	.half	0x1a07		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_st_flip_punch:
	.half	0x57		/* x offset of collision box */
	.half	0x09		/* y offset of collision box */
	.half	0x3e		/* x size of collision box */
	.half	0x28		/* y size of collision box */
	.half	0x0b01		/* strike routine */
	.half	0x1005		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_st_roundh:
	.half	0x65		/* x offset of collision box */
	.half	0xfff6		/* y offset of collision box */
	.half	0x49		/* x size of collision box */
	.half	0x37		/* y size of collision box */
	.half	0x0c01		/* strike routine */
	.half	0x1d04		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_st_knee:
	.half	0x4a		/* x offset of collision box */
	.half	0x21		/* y offset of collision box */
	.half	0x36		/* x size of collision box */
	.half	0x3d		/* y size of collision box */
	.half	0x0907		/* strike routine */
	.half	0x1203		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_st_elbow:
	.half	0x47		/* x offset of collision box */
	.half	0xfffe		/* y offset of collision box */
	.half	0x32		/* x size of collision box */
	.half	0x30		/* y size of collision box */
	.half	0x0907		/* strike routine */
	.half	0x1003		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_st_zap:
	.half	0x9a		/* x offset of collision box	    */
	.half	0x15		/* y offset of collision box */
	.half	0x4e		/* x size of collision box */
	.half	0x16		/* y size of collision box */
	.half	0x5101		/* strike routine */
	.half	0x0d02		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_summon:
	.half	0x14		/* x offset of collision box */
	.half	0xff9b		/* y offset of collision box */
	.half	0x27		/* x size of collision box */
	.half	0x5d		/* y size of collision box */
	.half	0x5001		/* strike routine */
	.half	0x0803		/* damage */
	.half	SF_SQUEEZE

/**************************************************************************
*											     *
*   She Goro strikes    									     *
*											     *
**************************************************************************/
	.align 2
sg_strikes:
	.word	stk_sg_hikick			/* 0 */
	.word	stk_sg_lokick			/* 1 */
	.word	stk_sg_hi_punch   		/* 2 */
	.word	stk_sg_lo_punch   		/* 3 */
	.word	stk_sg_sweep			/* 4 */
	.word	stk_sg_duck_punch		/* 5 */
	.word	stk_sg_duck_kickh		/* 6 */
	.word	stk_sg_duck_kickl		/* 7 */
	.word	stk_sg_uppercut   		/* 8 */
	.word	stk_sg_jump_punch		/* 9 */
	.word	stk_sg_jump_kick		/* a */
	.word	stk_sg_flip_kick		/* d */
	.word	stk_sg_flip_punch		/* c */
	.word	stk_sg_roundh			/* d */
	.word	stk_sg_knee			/* e */
	.word	stk_sg_elbow			/* f */
	.word	stk_dummy			/* 10 */
	.word	stk_sg_zap			/* 11 */
	.word	stk_pounce			/* 12 */
	.word	stk_boss_pounce			/* 13 */
	.word	stk_dummy			/* 14 */
	.word	stk_dummy			/* */
	.word	stk_dummy			/* */
	.word	stk_dummy			/* */


	.align 2
stk_sg_hikick:
	.half	0x65		/* x offset of collision box */
	.half	0x16		/* y offset of collision box */
	.half	0x50		/* x size of collision box */
	.half	0x2a		/* y size of collision box */
	.half	0x0006		/* strike routine */
	.half	0x1805		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_sg_lokick:
	.half	0x6b		/* x offset of collision box */
	.half	0x31		/* y offset of collision box */
	.half	0x53		/* x size of collision box */
	.half	0x14		/* y size of collision box */
	.half	0x0106		/* strike routine */
	.half	0x1504		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_sg_hi_punch:
	.half	0x52		/* x offset of collision box */
	.half	0x12		/* y offset of collision box */
	.half	0x3e		/* x size of collision box */
	.half	0x1a		/* y size of collision box */
	.half	0x0211		/* strike routine */
	.half	0x0b03		/* damage */
 	.half	SF_SQUEEZE

	.align 2
stk_sg_lo_punch:
	.half	0x4a		/* x offset of collision box */
	.half	0x2b		/* y offset of collision box */
	.half	0x39		/* x size of collision box */
	.half	0x1e		/* y size of collision box */
	.half	0x0317		/* strike routine */
	.half	0x0802		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_sg_sweep:
	.half	0x63		/* x offset of collision box */
	.half	0x73		/* y offset of collision box */
	.half	0x52		/* x size of collision box */
	.half	0x21		/* y size of collision box */
	.half	0x0403		/* strike routine */
	.half	0x1403		/* damage */
	.half	SF_DUCK

	.align 2
stk_sg_duck_punch:
	.half	0x56		/* x offset of collision box */
	.half	0x4a		/* y offset of collision box */
	.half	0x47		/* x size of collision box */
	.half	0x13		/* y size of collision box */
	.half	0x050a		/* strike routine */
	.half	0x0602		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_sg_duck_kickh:
	.half	0x5d		/* x offset of collision box */
	.half	0x3d		/* y offset of collision box */
	.half	0x46		/* x size of collision box */
	.half	0x2f		/* y size of collision box */
	.half	0x060b		/* strike routine */
	.half	0x0c03		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_sg_duck_kickl:
	.half	0x60		/* x offset of collision box */
	.half	0x7a		/* y offset of collision box */
	.half	0x4e		/* x size of collision box */
	.half	0x20		/* y size of collision box */
	.half	0x070a		/* strike routine */
	.half	0x0602		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_sg_uppercut:
	.half	0x56		/* x offset of collision box */
	.half	0xfff0		/* y offset of collision box */
	.half	0x4b		/* x size of collision box */
	.half	0x53		/* y size of collision box */
	.half	0x0802		/* strike routine */
	.half	0x2409		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_sg_jump_punch:
	.half	0x49		/* x offset of collision box */
	.half	0x0a		/* y offset of collision box */
	.half	0x3d		/* x size of collision box */
	.half	0x2f		/* y size of collision box */
	.half	0x0b01		/* strike routine */
	.half	0x1005		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_sg_jump_kick:
	.half	0x5a		/* x offset of collision box */
	.half	0x15		/* y offset of collision box */
	.half	0x4e		/* x size of collision box */
	.half	0x2c		/* y size of collision box */
	.half	0x0b01		/* strike routine */
	.half	0x1306		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_sg_flip_kick:
	.half	0x4f		/* x offset of collision box */
	.half	0x28		/* y offset of collision box */
	.half	0x49		/* x size of collision box */
	.half	0x34		/* y size of collision box */
	.half	0x0a01		/* strike routine */
	.half	0x1a07		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_sg_flip_punch:
	.half	0x49		/* x offset of collision box */
	.half	0x0a		/* y offset of collision box */
	.half	0x3d		/* x size of collision box */
	.half	0x2f		/* y size of collision box */
	.half	0x0b01		/* strike routine */
	.half	0x1005		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_sg_roundh:
	.half	0x77		/* x offset of collision box */
	.half	0x03		/* y offset of collision box */
	.half	0x51		/* x size of collision box */
	.half	0x38		/* y size of collision box */
	.half	0x0c01		/* strike routine */
	.half	0x1d04		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_sg_knee:
	.half	0x51		/* x offset of collision box */
	.half	0x21		/* y offset of collision box */
	.half	0x3c		/* x size of collision box */
	.half	0x4a		/* y size of collision box */
	.half	0x0907		/* strike routine */
	.half	0x1203		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_sg_elbow:
	.half	0x4b		/* x offset of collision box */
	.half	0x18		/* y offset of collision box */
	.half	0x32		/* x size of collision box */
	.half	0x30		/* y size of collision box */
	.half	0x0907		/* strike routine */
	.half	0x1003		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_sg_zap:
	.half	0x01		/* x offset of collision box */
	.half	0xffed		/* y offset of collision box */
	.half	0x30		/* x size of collision box */
	.half	0x26		/* y size of collision box */
	.half	0x5c01		/* strike routine */
	.half	0x1a03		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_pounce:
	.half	0x23		/* x offset of collision box */
	.half	0x26		/* y offset of collision box */
	.half	0x32		/* x size of collision box */
	.half	0x4b		/* y size of collision box */
	.half	0x5b0e		/* strike routine (unblockable) */
	.half	0x2020		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_boss_pounce:
	.half	0x23		/* x offset of collision box */
	.half	0x26		/* y offset of collision box */
	.half	0x32		/* x size of collision box */
	.half	0x4b		/* y size of collision box */
	.half	0x5b01		/* strike routine (unblockable) */
	.half	0x2020		/* damage */
	.half	SF_SQUEEZE

/**************************************************************************
*											     *
*   Tusk strikes    									     *
*											     *
**************************************************************************/
	.align 2
tusk_strikes:
	.word	stk_tusk_hikick			/* 0 */
	.word	stk_tusk_lokick			/* 1 */
	.word	stk_tusk_hi_punch   		/* 2 */
	.word	stk_tusk_lo_punch   		/* 3 */
	.word	stk_tusk_sweep			/* 4 */
	.word	stk_tusk_duck_punch		/* 5 */
	.word	stk_tusk_duck_kickh		/* 6 */
	.word	stk_tusk_duck_kickl		/* 7 */
	.word	stk_tusk_uppercut   		/* 8 */
	.word	stk_tusk_jump_punch		/* 9 */
	.word	stk_tusk_jump_kick		/* a */
	.word	stk_tusk_flip_kick		/* d */
	.word	stk_tusk_flip_punch		/* c */
	.word	stk_tusk_roundh			/* d */
	.word	stk_tusk_knee			/* e */
	.word	stk_tusk_elbow			/* f */
	.word	stk_dummy			/* 10 */
	.word	stk_tusk_zap			/* 11 */
	.word	stk_tusk_blur			/* 12 */
	.word	stk_tusk_saw			/* 13 */
	.word	stk_dummy			/* 14 */
	.word	stk_dummy			/* */
	.word	stk_dummy			/* */
	.word	stk_dummy			/* */

	.align 2
stk_tusk_hikick:
	.half	0x58		/* x offset of collision box */
	.half	0x15		/* y offset of collision box */
	.half	0x50		/* x size of collision box */
	.half	0x2a		/* y size of collision box */
	.half	0x0006		/* strike routine */
	.half	0x1805		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_tusk_lokick:
	.half	0x63		/* x offset of collision box */
	.half	0x31		/* y offset of collision box */
	.half	0x4c		/* x size of collision box */
	.half	0x14		/* y size of collision box */
	.half	0x0106		/* strike routine */
	.half	0x1504		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_tusk_hi_punch:
	.half	0x54		/* x offset of collision box */
	.half	0x11		/* y offset of collision box */
	.half	0x34		/* x size of collision box */
	.half	0x21		/* y size of collision box */
	.half	0x0211		/* strike routine */
	.half	0x0b03		/* damage */
 	.half	SF_SQUEEZE

	.align 2
stk_tusk_lo_punch:
	.half	0x5f		/* x offset of collision box */
	.half	0x28		/* y offset of collision box */
	.half	0x3f		/* x size of collision box */
	.half	0x15		/* y size of collision box */
	.half	0x0317		/* strike routine */
	.half	0x0802		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_tusk_sweep:
	.half	0x68		/* x offset of collision box */
	.half	0x70		/* y offset of collision box */
	.half	0x4e		/* x size of collision box */
	.half	0x1c		/* y size of collision box */
	.half	0x0403		/* strike routine */
	.half	0x1403		/* damage */
	.half	SF_DUCK

	.align 2
stk_tusk_duck_punch:
	.half	0x51		/* x offset of collision box */
	.half	0x50		/* y offset of collision box */
	.half	0x3d		/* x size of collision box */
	.half	0x0e		/* y size of collision box */
	.half	0x050a		/* strike routine */
	.half	0x0602		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_tusk_duck_kickh:
	.half	0x51		/* x offset of collision box */
	.half	0x45		/* y offset of collision box */
	.half	0x40		/* x size of collision box */
	.half	0x1a		/* y size of collision box */
	.half	0x060b		/* strike routine */
	.half	0x0c03		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_tusk_duck_kickl:
	.half	0x56		/* x offset of collision box */
	.half	0x74		/* y offset of collision box */
	.half	0x43		/* x size of collision box */
	.half	0x1a		/* y size of collision box */
	.half	0x070a		/* strike routine */
	.half	0x0602		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_tusk_uppercut:
	.half	0x47		/* x offset of collision box */
	.half	0x00		/* y offset of collision box */
	.half	0x40		/* x size of collision box */
	.half	0x43		/* y size of collision box */
	.half	0x0802		/* strike routine */
	.half	0x2409		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_tusk_jump_punch:
	.half	0x56		/* x offset of collision box */
	.half	0x1c		/* y offset of collision box */
	.half	0x34		/* x size of collision box */
	.half	0x29		/* y size of collision box */
	.half	0x0b01		/* strike routine */
	.half	0x1005		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_tusk_jump_kick:
	.half	0x51		/* x offset of collision box */
	.half	0x20		/* y offset of collision box */
	.half	0x42		/* x size of collision box */
	.half	0x24		/* y size of collision box */
	.half	0x0b01		/* strike routine */
	.half	0x1306		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_tusk_flip_kick:
	.half	0x5a		/* x offset of collision box */
	.half	0x2b		/* y offset of collision box */
	.half	0x3e		/* x size of collision box */
	.half	0x2d		/* y size of collision box */
	.half	0x0a01		/* strike routine */
	.half	0x1a07		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_tusk_flip_punch:
	.half	0x56		/* x offset of collision box */
	.half	0x1c		/* y offset of collision box */
	.half	0x34		/* x size of collision box */
	.half	0x29		/* y size of collision box */
	.half	0x0b01		/* strike routine */
	.half	0x1005		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_tusk_roundh:
	.half	0x65		/* x offset of collision box */
	.half	0x15		/* y offset of collision box */
	.half	0x4d		/* x size of collision box */
	.half	0x30		/* y size of collision box */
	.half	0x0c01		/* strike routine */
	.half	0x1d04		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_tusk_knee:
	.half	0x4a		/* x offset of collision box */
	.half	0x3a		/* y offset of collision box */
	.half	0x31		/* x size of collision box */
	.half	0x32		/* y size of collision box */
	.half	0x0907		/* strike routine */
	.half	0x1203		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_tusk_elbow:
	.half	0x47		/* x offset of collision box */
	.half	0x2c		/* y offset of collision box */
	.half	0x3b		/* x size of collision box */
	.half	0x22		/* y size of collision box */
	.half	0x4c07		/* strike routine */
	.half	0x1003		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_tusk_zap:
	.half	0x31		/* x offset of collision box */
	.half	0xffef		/* y offset of collision box */
	.half	0x2a		/* x size of collision box */
	.half	0x19		/* y size of collision box */
	.half	0x4a01		/* strike routine */
	.half	0x1703		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_tusk_blur:
	.half	0x21		/* x offset of collision box */
	.half	0x10		/* y offset of collision box */
	.half	0x35		/* x size of collision box */
	.half	0x7e		/* y size of collision box */
	.half	0x4b00		/* strike routine */
	.half	0x0000		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_tusk_saw:
	.half	0x14		/* x offset of collision box */
	.half	0xffd4		/* y offset of collision box */
	.half	0x22		/* x size of collision box */
	.half	0x2b		/* y size of collision box */
	.half	0x4d00		/* strike routine */
	.half	0x1202		/* damage */
	.half	SF_SQUEEZE

/**************************************************************************
*											     *
*   Kung Lao strikes    									     *
*											     *
**************************************************************************/
	.align 2
lao_strikes:
	.word	stk_lao_hikick			/* 0 */
	.word	stk_lao_lokick			/* 1 */
	.word	stk_lao_hi_punch   		/* 2 */
	.word	stk_lao_lo_punch   		/* 3 */
	.word	stk_lao_sweep			/* 4 */
	.word	stk_lao_duck_punch		/* 5 */
	.word	stk_lao_duck_kickh		/* 6 */
	.word	stk_lao_duck_kickl		/* 7 */
	.word	stk_lao_uppercut   		/* 8 */
	.word	stk_lao_jump_punch		/* 9 */
	.word	stk_lao_jump_kick		/* a */
	.word	stk_lao_flip_kick		/* d */
	.word	stk_lao_flip_punch		/* c */
	.word	stk_lao_roundh			/* d */
	.word	stk_lao_knee			/* e */
	.word	stk_lao_elbow			/* f */
	.word	stk_dummy			/* 10 */
	.word	stk_lao_zap			/* 11 */
	.word	stk_lao_angle			/* 12 */
	.word	stk_lao_spin			/* 13 */
	.word	stk_dummy			/* 14 */
	.word	stk_dummy			/* */
	.word	stk_dummy			/* */
	.word	stk_dummy			/* */

	.align 2
stk_lao_hikick:
	.half	0x55		/* x offset of collision box */
	.half	0x06		/* y offset of collision box */
	.half	0x40		/* x size of collision box */
	.half	0x2e		/* y size of collision box */
	.half	0x0006		/* strike routine */
	.half	0x1805		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_lao_lokick:
	.half	0x64		/* x offset of collision box */
	.half	0x25		/* y offset of collision box */
	.half	0x4c		/* x size of collision box */
	.half	0x14		/* y size of collision box */
	.half	0x0106		/* strike routine */
	.half	0x1504		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_lao_hi_punch:
	.half	0x4a		/* x offset of collision box */
	.half	0x03		/* y offset of collision box */
	.half	0x37		/* x size of collision box */
	.half	0x23		/* y size of collision box */
	.half	0x0211		/* strike routine */
	.half	0x0b03		/* damage */
 	.half	SF_SQUEEZE

	.align 2
stk_lao_lo_punch:
	.half	0x51		/* x offset of collision box */
	.half	0x1b		/* y offset of collision box */
	.half	0x33		/* x size of collision box */
	.half	0x1c		/* y size of collision box */
	.half	0x0317		/* strike routine */
	.half	0x0802		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_lao_sweep:
	.half	0x6e		/* x offset of collision box */
	.half	0x69		/* y offset of collision box */
	.half	0x4c		/* x size of collision box */
	.half	0x18		/* y size of collision box */
	.half	0x0403		/* strike routine */
	.half	0x1403		/* damage */
	.half	SF_DUCK

	.align 2
stk_lao_duck_punch:
	.half	0x4a		/* x offset of collision box */
	.half	0x39		/* y offset of collision box */
	.half	0x3b		/* x size of collision box */
	.half	0x13		/* y size of collision box */
	.half	0x050a		/* strike routine */
	.half	0x0602		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_lao_duck_kickh:
	.half	0x4b		/* x offset of collision box */
	.half	0x39		/* y offset of collision box */
	.half	0x46		/* x size of collision box */
	.half	0x31		/* y size of collision box */
	.half	0x060b		/* strike routine */
	.half	0x0c03		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_lao_duck_kickl:
	.half	0x57		/* x offset of collision box */
	.half	0x69		/* y offset of collision box */
	.half	0x43		/* x size of collision box */
	.half	0x1a		/* y size of collision box */
	.half	0x070a		/* strike routine */
	.half	0x0602		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_lao_uppercut:
	.half	0x3a		/* x offset of collision box */
	.half	0xffef		/* y offset of collision box */
	.half	0x34		/* x size of collision box */
	.half	0x46		/* y size of collision box */
	.half	0x0802		/* strike routine */
	.half	0x2409		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_lao_jump_punch:
	.half	0x68		/* x offset of collision box */
	.half	0x15		/* y offset of collision box */
	.half	0x39		/* x size of collision box */
	.half	0x2e		/* y size of collision box */
	.half	0x0b01		/* strike routine */
	.half	0x1005		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_lao_jump_kick:
	.half	0x52		/* x offset of collision box */
	.half	0x0c		/* y offset of collision box */
	.half	0x39		/* x size of collision box */
	.half	0x3b		/* y size of collision box */
	.half	0x0b01		/* strike routine */
	.half	0x1306		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_lao_flip_kick:
	.half	0x4c		/* x offset of collision box */
	.half	0x2d		/* y offset of collision box */
	.half	0x2c		/* x size of collision box */
	.half	0x1d		/* y size of collision box */
	.half	0x0a01		/* strike routine */
	.half	0x1a07		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_lao_flip_punch:
	.half	0x67		/* x offset of collision box */
	.half	0x19		/* y offset of collision box */
	.half	0x39		/* x size of collision box */
	.half	0x2d		/* y size of collision box */
	.half	0x0b01		/* strike routine */
	.half	0x1005		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_lao_roundh:
	.half	0x61		/* x offset of collision box */
	.half	0x07		/* y offset of collision box */
	.half	0x45		/* x size of collision box */
	.half	0x31		/* y size of collision box */
	.half	0x0c01		/* strike routine */
	.half	0x1d04		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_lao_knee:
	.half	0x40		/* x offset of collision box */
	.half	0x21		/* y offset of collision box */
	.half	0x3a		/* x size of collision box */
	.half	0x30		/* y size of collision box */
	.half	0x0907		/* strike routine */
	.half	0x1203		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_lao_elbow:
	.half	0x3d		/* x offset of collision box */
	.half	0x0c		/* y offset of collision box */
	.half	0x30		/* x size of collision box */
	.half	0x24		/* y size of collision box */
	.half	0x0907		/* strike routine */
	.half	0x1003		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_lao_zap:
	.half	0x54		/* x offset of collision box */
	.half	0x24		/* y offset of collision box */
	.half	0x2a		/* x size of collision box */
	.half	0x29		/* y size of collision box */
	.half	0x4504		/* strike routine */
	.half	0x1402		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_lao_angle:
	.half	0x56		/* x offset of collision box */
	.half	0x34		/* y offset of collision box */
	.half	0x2d		/* x size of collision box */
	.half	0x09		/* y size of collision box */
	.half	0x4600		/* strike routine */
	.half	0x0f02		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_lao_spin:
	.half	0x37		/* x offset of collision box */
	.half	0xfff9		/* y offset of collision box */
	.half	0x63		/* x size of collision box */
	.half	0x52		/* y size of collision box */
	.half	0x4701		/* strike routine */
	.half	0x1603		/* damage */
	.half	SF_SQUEEZE

/**************************************************************************
*											     *
*   Robo strikes    									     *
*											     *
**************************************************************************/
	.align 2
robo_strikes:
	.word	stk_ro_hikick			/* 0 */
	.word	stk_ro_lokick			/* 1 */
	.word	stk_ro_hi_punch			/* 2 */
	.word	stk_ro_lo_punch			/* 3 */
	.word	stk_ro_sweep			/* 4 */
	.word	stk_ro_duck_punch		/* 5 */
	.word	stk_ro_duck_kickh		/* 6 */
	.word	stk_ro_duck_kickl		/* 7 */
	.word	stk_ro_uppercut			/* 8 */
	.word	stk_ro_jump_punch		/* 9 */
	.word	stk_ro_jump_kick		/* a */
	.word	stk_ro_flip_kick		/* d */
	.word	stk_ro_flip_punch		/* c */
	.word	stk_ro_roundh			/* d */
	.word	stk_ro_knee			/* e */
	.word	stk_ro_elbow			/* f */
	.word	stk_dummy			/* 10 */
	.word	stk_ro_net			/* 11 */
	.word	stk_ro_zap			/* 12 */
	.word	stk_ro_tele			/* 13 */
	.word	stk_smoke_spear			/* 14 */
	.word	stk_ro_bomb			/* 15 */

	.align 2
stk_ro_hikick:
	.half	0x5f		/* x offset of collision box */
	.half	0x0d		/* y offset of collision box */
	.half	0x47		/* x size of collision box */
	.half	0x34		/* y size of collision box */
	.half	0x0006		/* strike routine */
	.half	0x1805		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_ro_lokick:
	.half	0x6a		/* x offset of collision box */
	.half	0x30		/* y offset of collision box */
	.half	0x47		/* x size of collision box */
	.half	0x10		/* y size of collision box */
	.half	0x0106		/* strike routine */
	.half	0x1504		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_ro_hi_punch:
	.half	0x4b		/* x offset of collision box */
	.half	0x0e		/* y offset of collision box */
	.half	0x36		/* x size of collision box */
	.half	0x21		/* y size of collision box */
	.half	0x0211		/* strike routine */
	.half	0x0b03		/* damage */
 	.half	SF_SQUEEZE

	.align 2
stk_ro_lo_punch:
	.half	0x46		/* x offset of collision box */
	.half	0x23		/* y offset of collision box */
	.half	0x3a		/* x size of collision box */
	.half	0x1f		/* y size of collision box */
	.half	0x0317		/* strike routine */
	.half	0x0802		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_ro_sweep:
	.half	0x6a		/* x offset of collision box */
	.half	0x6b		/* y offset of collision box */
	.half	0x4f		/* x size of collision box */
	.half	0x21		/* y size of collision box */
	.half	0x0403		/* strike routine */
	.half	0x1403		/* damage */
	.half	SF_DUCK

	.align 2
stk_ro_duck_punch:
	.half	0x44		/* x offset of collision box */
	.half	0x3f		/* y offset of collision box */
	.half	0x37		/* x size of collision box */
	.half	0x13		/* y size of collision box */
	.half	0x050a		/* strike routine */
	.half	0x0602		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_ro_duck_kickh:
	.half	0x48		/* x offset of collision box */
	.half	0x3a		/* y offset of collision box */
	.half	0x3d		/* x size of collision box */
	.half	0x38		/* y size of collision box */
	.half	0x060b		/* strike routine */
	.half	0x0c03		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_ro_duck_kickl:
	.half	0x60		/* x offset of collision box */
	.half	0x70		/* y offset of collision box */
	.half	0x40		/* x size of collision box */
	.half	0x17		/* y size of collision box */
	.half	0x070a		/* strike routine */
	.half	0x0602		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_ro_uppercut:
	.half	0x3c		/* x offset of collision box */
	.half	0xfffa		/* y offset of collision box */
	.half	0x38		/* x size of collision box */
	.half	0x4a		/* y size of collision box */
	.half	0x0802		/* strike routine */
	.half	0x2409		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_ro_jump_punch:
	.half	0x4b		/* x offset of collision box */
	.half	0x11		/* y offset of collision box */
	.half	0x32		/* x size of collision box */
	.half	0x31		/* y size of collision box */
	.half	0x0b01		/* strike routine */
	.half	0x1005		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_ro_jump_kick:
	.half	0x4b		/* x offset of collision box */
	.half	0xfff6		/* y offset of collision box */
	.half	0x45		/* x size of collision box */
	.half	0x49		/* y size of collision box */
	.half	0x0b01		/* strike routine */
	.half	0x1306		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_ro_flip_kick:
	.half	0x50		/* x offset of collision box */
	.half	0x2d		/* y offset of collision box */
	.half	0x3a		/* x size of collision box */
	.half	0x23		/* y size of collision box */
	.half	0x0a01		/* strike routine */
	.half	0x1a07		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_ro_flip_punch:
	.half	0x4b		/* x offset of collision box */
	.half	0x11		/* y offset of collision box */
	.half	0x32		/* x size of collision box */
	.half	0x31		/* y size of collision box */
	.half	0x0b01		/* strike routine */
	.half	0x1005		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_ro_roundh:
	.half	0x68		/* x offset of collision box */
	.half	0x09		/* y offset of collision box */
	.half	0x4a		/* x size of collision box */
	.half	0x33		/* y size of collision box */
	.half	0x0c01		/* strike routine */
	.half	0x1d04		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_ro_knee:
	.half	0x47		/* x offset of collision box */
	.half	0x2c		/* y offset of collision box */
	.half	0x30		/* x size of collision box */
	.half	0x3f		/* y size of collision box */
	.half	0x0907		/* strike routine */
	.half	0x1203		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_ro_elbow:
	.half	0x3d		/* x offset of collision box */
	.half	0x09		/* y offset of collision box */
	.half	0x33		/* x size of collision box */
	.half	0x36		/* y size of collision box */
	.half	0x0907		/* strike routine */
	.half	0x1003		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_ro_zap:
	.half	0x10		/* x offset of collision box */
	.half	0xfff1		/* y offset of collision box */
	.half	0x23		/* x size of collision box */
	.half	0x1f		/* y size of collision box */
	.half	0x3b04		/* strike routine */
	.half	0x1402		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_ro_net:
	.half	0x27		/* x offset of collision box */
	.half	0xffe7		/* y offset of collision box */
	.half	0x29		/* x size of collision box */
	.half	0x39		/* y size of collision box */
	.half	0x3c00		/* strike routine */
	.half	0x0000		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_ro_tele:
	.half	0x49		/* x offset of collision box */
	.half	0xfff7		/* y offset of collision box */
	.half	0x49		/* x size of collision box */
	.half	0x57		/* y size of collision box */
	.half	0x3d00		/* strike routine */
	.half	0x1002		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_ro_bomb:
	.half	0x2f		/* x offset of collision box */
	.half	0xffb8		/* y offset of collision box */
	.half	0x53		/* x size of collision box */
	.half	0x57		/* y size of collision box */
	.half	0x3e09		/* strike routine */
	.half	0x1212		/* damage */
	.half	0

	.align 2
stk_smoke_spear:
	.half	0x30		/* x offset of collision box */
	.half	0x27		/* y offset of collision box */
	.half	0x3d		/* x size of collision box */
	.half	0x10		/* y size of collision box */
	.half	0x3f00		/* strike routine */
	.half	0x0802		/* damage */
	.half	SF_SQUEEZE

/**************************************************************************
*											     *
*   Lia guy strikes    									     *
*											     *
**************************************************************************/
	.align 2
lia_strikes:
	.word	stk_li_hikick			/* 0 */
	.word	stk_li_lokick			/* 1 */
	.word	stk_li_hi_punch			/* 2 */
	.word	stk_li_lo_punch			/* 3 */
	.word	stk_li_sweep			/* 4 */
	.word	stk_li_duck_punch		/* 5 */
	.word	stk_li_duck_kickh		/* 6 */
	.word	stk_li_duck_kickl		/* 7 */
	.word	stk_li_uppercut			/* 8 */
	.word	stk_li_jump_punch		/* 9 */
	.word	stk_li_jump_kick		/* a */
	.word	stk_li_flip_kick		/* d */
	.word	stk_li_flip_punch		/* c */
	.word	stk_li_roundh			/* d */
	.word	stk_li_knee			/* e */
	.word	stk_li_elbow			/* f */
	.word	stk_dummy			/* 10 */
	.word	stk_li_scream			/* 11 */
	.word	stk_li_angle_zap 		/* 12 */
	.word	stk_li_angle_zap2 		/* 13 */
	.word	stk_li_angle_zap3 		/* 14 */
	.word	stk_li_forward			/* 15 */

	.align 2
stk_li_hikick:
	.half	0x59		/* x offset of collision box */
	.half	0x0b		/* y offset of collision box */
	.half	0x47		/* x size of collision box */
	.half	0x2d		/* y size of collision box */
	.half	0x0006		/* strike routine */
	.half	0x1805		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_li_lokick:
	.half	0x5f		/* x offset of collision box */
	.half	0x2f		/* y offset of collision box */
	.half	0x42		/* x size of collision box */
	.half	0x0f		/* y size of collision box */
	.half	0x0106		/* strike routine */
	.half	0x1504		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_li_hi_punch:
	.half	0x54		/* x offset of collision box */
	.half	0x10		/* y offset of collision box */
	.half	0x2f		/* x size of collision box */
	.half	0x23		/* y size of collision box */
	.half	0x0211		/* strike routine */
	.half	0x0b03		/* damage */
 	.half	SF_SQUEEZE

	.align 2
stk_li_lo_punch:
	.half	0x54		/* x offset of collision box */
	.half	0x26		/* y offset of collision box */
	.half	0x33		/* x size of collision box */
	.half	0x16		/* y size of collision box */
	.half	0x0317		/* strike routine */
	.half	0x0802		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_li_sweep:
	.half	0x6b		/* x offset of collision box */
	.half	0x66		/* y offset of collision box */
	.half	0x4c		/* x size of collision box */
	.half	0x21		/* y size of collision box */
	.half	0x0403		/* strike routine */
	.half	0x1403		/* damage */
	.half	SF_DUCK

	.align 2
stk_li_duck_punch:
	.half	0x4d		/* x offset of collision box */
	.half	0x49		/* y offset of collision box */
	.half	0x37		/* x size of collision box */
	.half	0x13		/* y size of collision box */
	.half	0x050a		/* strike routine */
	.half	0x0602		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_li_duck_kickh:
	.half	0x59		/* x offset of collision box */
	.half	0x40		/* y offset of collision box */
	.half	0x47		/* x size of collision box */
	.half	0x2c		/* y size of collision box */
	.half	0x060b		/* strike routine */
	.half	0x0c03		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_li_duck_kickl:
	.half	0x59		/* x offset of collision box */
	.half	0x72		/* y offset of collision box */
	.half	0x3a		/* x size of collision box */
	.half	0x18		/* y size of collision box */
	.half	0x070a		/* strike routine */
	.half	0x0602		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_li_uppercut:
	.half	0x4a		/* x offset of collision box */
	.half	0xfff3		/* y offset of collision box */
	.half	0x34		/* x size of collision box */
	.half	0x47		/* y size of collision box */
	.half	0x0802		/* strike routine */
	.half	0x2409		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_li_jump_punch:
	.half	0x55		/* x offset of collision box */
	.half	0x06		/* y offset of collision box */
	.half	0x2f		/* x size of collision box */
	.half	0x2b		/* y size of collision box */
	.half	0x0b01		/* strike routine */
	.half	0x1005		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_li_jump_kick:
	.half	0x4f		/* x offset of collision box */
	.half	0xfff8		/* y offset of collision box */
	.half	0x3a		/* x size of collision box */
	.half	0x48		/* y size of collision box */
	.half	0x0b01		/* strike routine */
	.half	0x1306		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_li_flip_kick:
	.half	0x59		/* x offset of collision box */
	.half	0x1a		/* y offset of collision box */
	.half	0x3a		/* x size of collision box */
	.half	0x33		/* y size of collision box */
	.half	0x0a01		/* strike routine */
	.half	0x1a07		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_li_flip_punch:
	.half	0x56		/* x offset of collision box */
	.half	0x0c		/* y offset of collision box */
	.half	0x35		/* x size of collision box */
	.half	0x2a		/* y size of collision box */
	.half	0x0b01		/* strike routine */
	.half	0x1005		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_li_roundh:
	.half	0x4a		/* x offset of collision box */
	.half	0x01		/* y offset of collision box */
	.half	0x3f		/* x size of collision box */
	.half	0x39		/* y size of collision box */
	.half	0x0c01		/* strike routine */
	.half	0x1d04		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_li_knee:
	.half	0x51		/* x offset of collision box */
	.half	0x22		/* y offset of collision box */
	.half	0x2f		/* x size of collision box */
	.half	0x3a		/* y size of collision box */
	.half	0x0907		/* strike routine */
	.half	0x1203		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_li_elbow:
	.half	0x4c		/* x offset of collision box */
	.half	0x10		/* y offset of collision box */
	.half	0x2d		/* x size of collision box */
	.half	0x2c		/* y size of collision box */

/*	.half	0x0907		; strike routine */
	.half	0x4c07		/* strike routine */

	.half	0x1003		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_li_angle_zap:
	.half	0x53		/* x offset of collision box */
	.half	0x30		/* y offset of collision box */
	.half	0x25		/* x size of collision box */
	.half	0x25		/* y size of collision box */
	.half	0x3704		/* strike routine */
	.half	0x1402		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_li_scream:
	.half	0x9a		/* x offset of collision box */
	.half	0x08		/* y offset of collision box */
	.half	0x6a		/* x size of collision box */
	.half	0x42		/* y size of collision box */
	.half	0x3608		/* strike routine */
	.half	0x0000		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_li_angle_zap2:
	.half	0x7d		/* x offset of collision box */
	.half	0x51		/* y offset of collision box */
	.half	0x2a		/* x size of collision box */
	.half	0x2c		/* y size of collision box */
	.half	0x3704		/* strike routine */
	.half	0x1402		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_li_angle_zap3:
	.half	0x85		/* x offset of collision box */
	.half	0x5b		/* y offset of collision box */
	.half	0x2f		/* x size of collision box */
	.half	0x2b		/* y size of collision box */
	.half	0x3704		/* strike routine */
	.half	0x1402		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_li_forward:
	.half	0x72		/* x offset of collision box */
	.half	0x09		/* y offset of collision box */
	.half	0x2d		/* x size of collision box */
	.half	0x11		/* y size of collision box */
	.half	0x3704		/* strike routine */
	.half	0x1402		/* damage */
	.half	SF_SQUEEZE

/**************************************************************************
*											     *
*   Swat guy strikes    									     *
*											     *
**************************************************************************/
	.align 2
swat_strikes:
	.word	stk_sw_hikick			/* 0 */
	.word	stk_sw_lokick			/* 1 */
	.word	stk_sw_hi_punch			/* 2 */
	.word	stk_sw_lo_punch			/* 3 */
	.word	stk_sw_sweep			/* 4 */
	.word	stk_sw_duck_punch		/* 5 */
	.word	stk_sw_duck_kickh		/* 6 */
	.word	stk_sw_duck_kickl		/* 7 */
	.word	stk_sw_uppercut			/* 8 */
	.word	stk_sw_jump_punch		/* 9 */
	.word	stk_sw_jump_kick		/* a */
	.word	stk_sw_flip_kick		/* d */
	.word	stk_sw_flip_punch		/* c */
	.word	stk_sw_roundh			/* d */
	.word	stk_sw_knee			/* e */
	.word	stk_sw_elbow			/* f */
	.word	stk_sw_bomb			/* 10 */
	.word	stk_dummy			/* 11 */
	.word	stk_sw_zap			/* 12 */
	.word	stk_sw_prezap1			/* 13 */
	.word	stk_sw_prezap2			/* 14 */
	.word	stk_sw_zoom			/* 15 */
	.word	stk_sw_diag_zap2		/* 16 */
	.word	stk_sw_stick_sweep		/* 17 */
	.word	stk_swat_gun			/* 18 */

	.align 2
stk_sw_hikick:
	.half	0x5f		/* x offset of collision box */
	.half	0x0d		/* y offset of collision box */
	.half	0x51		/* x size of collision box */
	.half	0x2c		/* y size of collision box */
	.half	0x0006		/* strike routine */
	.half	0x1805		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_sw_lokick:
	.half	0x67		/* x offset of collision box */
	.half	0x31		/* y offset of collision box */
	.half	0x4e		/* x size of collision box */
	.half	0x10		/* y size of collision box */
	.half	0x0106		/* strike routine */
	.half	0x1504		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_sw_hi_punch:
	.half	0x58		/* x offset of collision box */
	.half	0x0d		/* y offset of collision box */
	.half	0x35  		/* x size of collision box */
	.half	0x24  		/* y size of collision box */
	.half	0x0211		/* strike routine */
	.half	0x0b03		/* damage */
 	.half	SF_SQUEEZE

	.align 2
stk_sw_lo_punch:
	.half	0x50		/* x offset of collision box */
	.half	0x20		/* y offset of collision box */
	.half	0x37		/* x size of collision box */
	.half	0x14		/* y size of collision box */
	.half	0x0317		/* strike routine */
	.half	0x0802		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_sw_sweep:
	.half	0x6d		/* x offset of collision box */
	.half	0x66		/* y offset of collision box */
	.half	0x4b		/* x size of collision box */
	.half	0x24		/* y size of collision box */
	.half	0x0403		/* strike routine */
	.half	0x1403		/* damage */
	.half	SF_DUCK

	.align 2
stk_sw_duck_punch:
	.half	0x4d		/* x offset of collision box */
	.half	0x46		/* y offset of collision box */
	.half	0x37		/* x size of collision box */
	.half	0x13		/* y size of collision box */
	.half	0x050a		/* strike routine */
	.half	0x0602		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_sw_duck_kickh:
	.half	0x51		/* x offset of collision box */
	.half	0x3a		/* y offset of collision box */
	.half	0x3f		/* x size of collision box */
	.half	0x31		/* y size of collision box */
	.half	0x060b		/* strike routine */
	.half	0x0c03		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_sw_duck_kickl:
	.half	0x5d		/* x offset of collision box */
	.half	0x6f		/* y offset of collision box */
	.half	0x46		/* x size of collision box */
	.half	0x1f		/* y size of collision box */
	.half	0x070a		/* strike routine */
	.half	0x0602		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_sw_uppercut:
	.half	0x4e		/* x offset of collision box */
	.half	0xfff6		/* y offset of collision box */
	.half	0x3a		/* x size of collision box */
	.half	0x4d		/* y size of collision box */
	.half	0x0802		/* strike routine */
	.half	0x2409		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_sw_jump_punch:
	.half	0x5a		/* x offset of collision box */
	.half	0x11		/* y offset of collision box */
	.half	0x3d		/* x size of collision box */
	.half	0x2c		/* y size of collision box */
	.half	0x0b01		/* strike routine */
	.half	0x1005		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_sw_jump_kick:
	.half	0x4e		/* x offset of collision box */
	.half	0x02		/* y offset of collision box */
	.half	0x3c		/* x size of collision box */
	.half	0x48		/* y size of collision box */
	.half	0x0b01		/* strike routine */
	.half	0x1306		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_sw_flip_kick:
	.half	0x56		/* x offset of collision box */
	.half	0x29		/* y offset of collision box */
	.half	0x34		/* x size of collision box */
	.half	0x23		/* y size of collision box */
	.half	0x0a01		/* strike routine */
	.half	0x1a07		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_sw_flip_punch:
	.half	0x5a		/* x offset of collision box */
	.half	0x11		/* y offset of collision box */
	.half	0x3d		/* x size of collision box */
	.half	0x2c		/* y size of collision box */
	.half	0x0b01		/* strike routine */
	.half	0x1005		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_sw_roundh:
	.half	0x6d		/* x offset of collision box */
	.half	0xfff7		/* y offset of collision box */
	.half	0x48		/* x size of collision box */
	.half	0x3b		/* y size of collision box */
	.half	0x0c01		/* strike routine */
	.half	0x1d04		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_sw_knee:
	.half	0x4e		/* x offset of collision box */
	.half	0x27		/* y offset of collision box */
	.half	0x33		/* x size of collision box */
	.half	0x36		/* y size of collision box */
	.half	0x0907		/* strike routine */
	.half	0x1203		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_sw_elbow:
	.half	0x41		/* x offset of collision box */
	.half	0x0d		/* y offset of collision box */
	.half	0x2c		/* x size of collision box */
	.half	0x28		/* y size of collision box */
	.half	0x0907		/* strike routine */
	.half	0x1003		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_sw_zap:
	.half	0xe9		/* x offset of collision box */
	.half	0x2b		/* y offset of collision box */
	.half	0x3f		/* x size of collision box */
	.half	0x13		/* y size of collision box */
	.half	0x3004		/* strike routine */
	.half	0x1402		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_sw_prezap1:
	.half	0x87		/* x offset of collision box */
	.half	0x2b		/* y offset of collision box */
	.half	0x3a		/* x size of collision box */
	.half	0x13		/* y size of collision box */
	.half	0x3004		/* strike routine */
	.half	0x1402		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_sw_prezap2:
	.half	0xad		/* x offset of collision box */
	.half	0x2b		/* y offset of collision box */
	.half	0x5b		/* x size of collision box */
	.half	0x13		/* y size of collision box */
	.half	0x3004		/* strike routine */
	.half	0x1402		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_sw_diag_zap1:
	.half	0x5f		/* x offset of collision box */
	.half	0xffe4		/* y offset of collision box */
	.half	0x2b		/* x size of collision box */
	.half	0x30		/* y size of collision box */
	.half	0x3000		/* strike routine */
	.half	0x1402		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_sw_diag_zap2:
	.half	0x8c		/* x offset of collision box */
	.half	0xffbc		/* y offset of collision box */
	.half	0x2b		/* x size of collision box */
	.half	0x30		/* y size of collision box */
	.half	0x3000		/* strike routine */
	.half	0x1402		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_sw_bomb:
	.half	0x17		/* x offset of collision box */
	.half	0xffed		/* y offset of collision box */
	.half	0x2d		/* x size of collision box */
	.half	0x25		/* y size of collision box */
	.half	0x3104		/* strike routine */
	.half	0x1504		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_sw_zoom:
	.half	0xfff2		/* x offset of collision box */
	.half	0x1c		/* y offset of collision box */
	.half	0x28		/* x size of collision box */
	.half	0x24		/* y size of collision box */
	.half	0x3200		/* strike routine */
	.half	0x0000		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_sw_stick_sweep:
	.half	0x83		/* x offset of collision box */
	.half	0x64		/* y offset of collision box */
	.half	0x74		/* x size of collision box */
	.half	0x04		/* y size of collision box */
	.half	0x3303		/* strike routine */
	.half	0x1a04		/* damage */
	.half	SF_DUCK

	.align 2
stk_swat_gun:
	.half	0xb7		/* x offset of collision box */
	.half	0x33		/* y offset of collision box */
	.half	0x93		/* x size of collision box */
	.half	0x2e		/* y size of collision box */
	.half	0x3401		/* strike routine */
	.half	0x1404		/* damage */
	.half	SF_SQUEEZE
	.half	0

/**************************************************************************
*											     *
*   subzero strikes    									     *
*											     *
**************************************************************************/
	.align 2
jc_strikes:
	.word	stk_jc_hikick			/* 0 */
	.word	stk_jc_lokick			/* 1 */
	.word	stk_jc_hi_punch			/* 2 */
	.word	stk_jc_lo_punch			/* 3 */
	.word	stk_jc_sweep			/* 4 */
	.word	stk_jc_duck_punch		/* 5 */
	.word	stk_jc_duck_kickh		/* 6 */
	.word	stk_jc_duck_kickl		/* 7 */
	.word	stk_jc_uppercut			/* 8 */
	.word	stk_jc_jump_punch		/* 9 */
	.word	stk_jc_jump_kick		/* a */
	.word	stk_jc_flip_kick		/* d */
	.word	stk_jc_flip_punch		/* c */
	.word	stk_jc_roundh			/* d */
	.word	stk_jc_knee			/* e */
	.word	stk_jc_elbow			/* f */
	.word	stk_jc_shadow		/* 10, 11 */
	.word	stk_jc_shoruken		/* 11, 12 */
	.word	stk_jc_zap1			/* 12, 10 */
	.word	stk_jc_zap4			/* 13, 13 */
	.word	stk_jc_shadowr			/* 14 */
	.word	stk_dummy			/* 15 */
	.word	stk_dummy			/* 16 */
	.word	stk_dummy			/* 17 */


	.align 2
stk_jc_zap1:
stk_jc_zap2:
stk_jc_zap3:
stk_jc_zap4:
	.half	0x0a-8
	.half	-0x08+6
	.half	30
	.half	20+3
	.half	0x8f00	   
	.half	0x1505
	.half	SF_SQUEEZE

	.align 2
stk_jc_shadow:
	.half	0x67+30
	.half	0x2e	   
	.half	0x57
	.half	0x10	   
	.half	0x9101
	.half	0x1807	   
	.half	SF_SQUEEZE

	.align 2
stk_jc_shadowr:
	.half	0x67+30
	.half	0x2e	   
	.half	0x57
	.half	0x10	   
	.half	0x9101
	.half	0x0c03	   
	.half	SF_SQUEEZE

	.align 2
stk_jc_shoruken:
	.half	0x60-6
	.half	12-5
	.half	0x30-4
	.half	0x3c
	.half	0x9000 
	.half	0x1d06	
	.half	SF_SQUEEZE


	.align 2
stk_jc_hikick:
	.half	0x68+22		/* x offset of collision box */
	.half	0x0a+16		/* y offset of collision box */
	.half	0x4e+16		/* x size of collision box */
	.half	0x28		/* y size of collision box */
	.half	0x0006		/* strike routine */
	.half	0x1805		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_jc_lokick:
	.half	0x6f+26		/* x offset of collision box */
	.half	0x2e+3		/* y offset of collision box */
	.half	0x4d+18		/* x size of collision box */
	.half	0x0f+3+2		/* y size of collision box */
	.half	0x0106		/* strike routine */
	.half	0x1504		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_jc_hi_punch:
	.half	0x52-14		/* x offset of collision box */
	.half	0x06+10		/* y offset of collision box */
	.half	0x32		/* x size of collision box */
	.half	0x20		/* y size of collision box */
	.half	0x0211		/* strike routine */
	.half	0x0b03		/* damage */
 	.half	SF_SQUEEZE

	.align 2
stk_jc_lo_punch:
	.half	0x57-10		/* x offset of collision box */
	.half	0x1c+4		/* y offset of collision box */
	.half	0x3c		/* x size of collision box */
	.half	0x16		/* y size of collision box */
	.half	0x0317		/* strike routine */
	.half	0x0802		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_jc_sweep:
	.half	0x65+5-16		/* x offset of collision box */
	.half	0x67+7		/* y offset of collision box */
	.half	0x52+2		/* x size of collision box */
	.half	0x1f-3+5		/* y size of collision box */
	.half	0x0403		/* strike routine */
	.half	0x1403		/* damage */
	.half	SF_DUCK

	.align 2
stk_jc_duck_punch:
	.half	0x42		/* x offset of collision box */
	.half	0x42		/* y offset of collision box */
	.half	0x31		/* x size of collision box */
	.half	0xc		/* y size of collision box */
	.half	0x050a		/* strike routine */
	.half	0x0602		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_jc_duck_kickh:
	.half	0x4c		/* x offset of collision box */
	.half	0x35+16		/* y offset of collision box */
	.half	0x40		/* x size of collision box */
	.half	0x31-16		/* y size of collision box */
	.half	0x060b		/* strike routine */
	.half	0x0c03		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_jc_duck_kickl:
	.half	0x5e-5		/* x offset of collision box */
	.half	0x60+7		/* y offset of collision box */
	.half	0x46-9+5		/* x size of collision box */
	.half	0x24		/* y size of collision box */
	.half	0x070a		/* strike routine */
	.half	0x0602		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_jc_uppercut:
	.half	0x51-19		/* x offset of collision box */
	.half	0xffee+10		/* y offset of collision box */
	.half	0x3a		/* x size of collision box */
	.half	0x48		/* y size of collision box */
	.half	0x0802		/* strike routine */
	.half	0x2409		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_jc_jump_punch:
	.half	0x60-14		/* x offset of collision box */
	.half	38		/* y offset of collision box */
	.half	0x28		/* x size of collision box */
	.half	0x2c-2		/* y size of collision box */
	.half	0x0b01		/* strike routine */
	.half	0x1005		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_jc_jump_kick:
	.half	0x60-24	/* x offset of collision box */
	.half	-0x11+48		/* y offset of collision box */
	.half	0x4c-10+8		/* x size of collision box */
	.half	0x42-20		/* y size of collision box */
	.half	0x0b01		/* strike routine */
	.half	0x1306		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_jc_flip_kick:
	.half	0x64-16		/* x offset of collision box */
	.half	0x1a+18		/* y offset of collision box */
	.half	0x41		/* x size of collision box */
	.half	0x29		/* y size of collision box */
	.half	0x0a01		/* strike routine */
	.half	0x1a07		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_jc_flip_punch:
	.half	0x60-11		/* x offset of collision box */
	.half	22+20		/* y offset of collision box */
	.half	0x2a		/* x size of collision box */
	.half	0x2a-4		/* y size of collision box */
	.half	0x0b01		/* strike routine */
	.half	0x1005		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_jc_roundh:
	.half	0x5a+32-18		/* x offset of collision box */
	.half	0x00+12		/* y offset of collision box */
	.half	0x48+4		/* x size of collision box */
	.half	0x36-4		/* y size of collision box */
	.half	0x0c01		/* strike routine */
	.half	0x1d04		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_jc_knee:
	.half	0x55		/* x offset of collision box */
	.half	0x20		/* y offset of collision box */
	.half	0x32-16		/* x size of collision box */
	.half	0x35		/* y size of collision box */
	.half	0x0907		/* strike routine */
	.half	0x1203		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_jc_elbow:
	.half	0x3e		/* x offset of collision box */
	.half	0x09		/* y offset of collision box */
	.half	0x2b		/* x size of collision box */
	.half	0x24		/* y size of collision box */
	.half	0x0907		/* strike routine */
	.half	0x1003		/* damage */
	.half	SF_SQUEEZE

/**************************************************************************
*											     *
*   indian strikes    									     *
*											     *
**************************************************************************/
	.align 2
indian_strikes:
	.word	stk_ind_hikick			/* 0 */
	.word	stk_ind_lokick			/* 1 */
	.word	stk_ind_hi_punch		/* 2 */
	.word	stk_ind_lo_punch		/* 3 */
	.word	stk_ind_sweep			/* 4 */
	.word	stk_ind_duck_punch		/* 5 */
	.word	stk_ind_duck_kickh		/* 6 */
	.word	stk_ind_duck_kickl		/* 7 */
	.word	stk_ind_uppercut		/* 8 */
	.word	stk_ind_jump_punch		/* 9 */
	.word	stk_ind_jump_kick		/* a */
	.word	stk_ind_flip_kick		/* d */
	.word	stk_ind_flip_punch		/* c */
	.word	stk_ind_roundh			/* d */
	.word	stk_ind_knee			/* e */
	.word	stk_ind_elbow			/* f */
	.word	stk_dummy			/* 10 */
	.word	stk_ind_charge			/* 11 */
	.word	stk_ind_zap			/* 12 */
	.word	stk_axe_horz			/* 13 */
	.word	stk_dummy			/* 14 */
	.word	stk_axe_up			/* 15 */
	.word	stk_ind_charge_fast			/* 16 */
	.word	stk_dummy			/* 17 */


	.align 2
stk_ind_hikick:
	.half	0x64		/* x offset of collision box */
	.half	0x07		/* y offset of collision box */
	.half	0x53		/* x size of collision box */
	.half	0x2f		/* y size of collision box */
	.half	0x0006		/* strike routine */
	.half	0x1805		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_ind_lokick:
	.half	0x6a		/* x offset of collision box */
	.half	0x2e		/* y offset of collision box */
	.half	0x4d		/* x size of collision box */
	.half	0x13		/* y size of collision box */
	.half	0x0106		/* strike routine */
	.half	0x1504		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_ind_hi_punch:
	.half	0x4b		/* x offset of collision box */
	.half	0x0b		/* y offset of collision box */
	.half	0x35		/* x size of collision box */
	.half	0x25		/* y size of collision box */
	.half	0x0211		/* strike routine */
	.half	0x0b03		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_ind_lo_punch:
	.half	0x45+4		/* x offset of collision box */
	.half	0x1f		/* y offset of collision box */
	.half	0x37		/* x size of collision box */
	.half	0x1a		/* y size of collision box */
	.half	0x0317		/* strike routine */
	.half	0x0802		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_ind_sweep:
	.half	0x6d+4		/* x offset of collision box */
	.half	0x68		/* y offset of collision box */
	.half	0x49		/* x size of collision box */
	.half	0x21		/* y size of collision box */
	.half	0x0403		/* strike routine */
	.half	0x1403		/* damage */
	.half	SF_DUCK

	.align 2
stk_ind_duck_punch:
	.half	0x45+4		/* x offset of collision box */
	.half	0x41		/* y offset of collision box */
	.half	0x37		/* x size of collision box */
	.half	0x1d		/* y size of collision box */
	.half	0x050a		/* strike routine */
	.half	0x0602		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_ind_duck_kickh:
	.half	0x3b+4		/* x offset of collision box */
	.half	0x33		/* y offset of collision box */
	.half	0x3a		/* x size of collision box */
	.half	0x3c		/* y size of collision box */
	.half	0x060b		/* strike routine */
	.half	0x0c03		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_ind_duck_kickl:
	.half	0x5e+4		/* x offset of collision box */
	.half	0x66		/* y offset of collision box */
	.half	0x46		/* x size of collision box */
	.half	0x20		/* y size of collision box */
	.half	0x070a		/* strike routine */
	.half	0x0602		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_ind_uppercut:
	.half	0x3e		/* x offset of collision box */
	.half	0xfff3		/* y offset of collision box */
	.half	0x31		/* x size of collision box */
	.half	0x4b		/* y size of collision box */
	.half	0x0802		/* strike routine */
	.half	0x2409		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_ind_jump_punch:
	.half	0x4d		/* x offset of collision box */
	.half	0x19		/* y offset of collision box */
	.half	0x31		/* x size of collision box */
	.half	0x2b		/* y size of collision box */
	.half	0x0b01		/* strike routine */
	.half	0x1005		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_ind_jump_kick:
	.half	0x52+4		/* x offset of collision box */
	.half	0x04		/* y offset of collision box */
	.half	0x46		/* x size of collision box */
	.half	0x47		/* y size of collision box */
	.half	0x0b01		/* strike routine */
	.half	0x1306		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_ind_flip_kick:
	.half	0x52+4		/* x offset of collision box */
	.half	0x1b		/* y offset of collision box */
	.half	0x3c		/* x size of collision box */
	.half	0x37		/* y size of collision box */
	.half	0x0a01		/* strike routine */
	.half	0x1a07		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_ind_flip_punch:
	.half	0x49+4		/* x offset of collision box */
	.half	0x19		/* y offset of collision box */
	.half	0x31		/* x size of collision box */
	.half	0x34		/* y size of collision box */
	.half	0x0b01		/* strike routine */
	.half	0x1005		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_ind_roundh:
	.half	0x53		/* x offset of collision box */
	.half	0x0a		/* y offset of collision box */
	.half	0x40		/* x size of collision box */
	.half	0x34		/* y size of collision box */
	.half	0x0c01		/* strike routine */
	.half	0x1d04		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_ind_knee:
	.half	0x45		/* x offset of collision box */
	.half	0x3a		/* y offset of collision box */
	.half	0x44		/* x size of collision box */
	.half	0x35		/* y size of collision box */
	.half	0x0907		/* strike routine */
	.half	0x1203		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_ind_elbow:
	.half	0x43		/* x offset of collision box */
	.half	0x14		/* y offset of collision box */
	.half	0x2b		/* x size of collision box */
	.half	0x16		/* y size of collision box */
	.half	0x0907		/* strike routine */
	.half	0x1003		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_ind_zap:
	.half	0x74		/* x offset of collision box */
	.half	0x24		/* y offset of collision box */
	.half	0x4c		/* x size of collision box */
	.half	0x12		/* y size of collision box */
	.half	0x2805		/* strike routine */
	.half	0x1003		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_ind_charge:
	.half	0x38		/* x offset of collision box */
	.half	0x10		/* y offset of collision box */
	.half	0x3a		/* x size of collision box */
	.half	0x28		/* y size of collision box */
	.half	0x2901		/* strike routine */
	.half	0x1804		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_ind_charge_fast:
	.half	0x38		/* x offset of collision box */
	.half	0x10		/* y offset of collision box */
	.half	0x3a		/* x size of collision box */
	.half	0x28		/* y size of collision box */
	.half	0x2901		/* strike routine */
	.half	0x0c02		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_axe_horz:
	.half	0x5d		/* x offset of collision box */
	.half	0x22		/* y offset of collision box */
	.half	0x47		/* x size of collision box */
	.half	0x16		/* y size of collision box */
	.half	0x2a01		/* strike routine */
	.half	0x1504		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_axe_up:
	.half	0x58		/* x offset of collision box */
	.half	0xfffe		/* y offset of collision box */
	.half	0x49		/* x size of collision box */
	.half	0x3e		/* y size of collision box */
	.half	0x2b01		/* strike routine */
	.half	0x1203		/* damage */
	.half	SF_SQUEEZE

/**************************************************************************
*											     *
*   jax strikes    									     *
*											     *
**************************************************************************/
	.align 2
jax_strikes:
	.word	stk_jax_hikick			/* 0 */
	.word	stk_jax_lokick			/* 1 */
	.word	stk_jax_hi_punch		/* 2 */
	.word	stk_jax_lo_punch		/* 3 */
	.word	stk_jax_sweep			/* 4 */
	.word	stk_jax_duck_punch		/* 5 */
	.word	stk_jax_duck_kickh		/* 6 */
	.word	stk_jax_duck_kickl		/* 7 */
	.word	stk_jax_uppercut		/* 8 */
	.word	stk_jax_jump_punch		/* 9 */
	.word	stk_jax_jump_kick		/* a */
	.word	stk_jax_flip_kick		/* d */
	.word	stk_jax_flip_punch		/* c */
	.word	stk_jax_roundh			/* d */
	.word	stk_jax_knee			/* e */
	.word	stk_jax_elbow			/* f */
	.word	stk_jax_dash			/* 10 */
	.word	stk_dummy			/* 11 */
	.word	stk_jax_zap			/* 12 */
	.word	stk_jax_prezap			/* 13 */
	.word	stk_noogy			/* 14 */

	.align 2
stk_jax_hikick:
	.half	0x5f		/* x offset of collision box */
	.half	0x1e		/* y offset of collision box */
	.half	0x51		/* x size of collision box */
	.half	0x2e		/* y size of collision box */
	.half	0x0006		/* strike routine */
	.half	0x1805		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_jax_lokick:
	.half	0x69		/* x offset of collision box */
	.half	0x39		/* y offset of collision box */
	.half	0x49		/* x size of collision box */
	.half	0x14		/* y size of collision box */
	.half	0x0106		/* strike routine */
	.half	0x1504		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_jax_hi_punch:
	.half	0x50		/* x offset of collision box */
	.half	0x1a		/* y offset of collision box */
	.half	0x3e		/* x size of collision box */
	.half	0x20		/* y size of collision box */
	.half	0x0211		/* strike routine */
	.half	0x0b03		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_jax_lo_punch:
	.half	0x4e		/* x offset of collision box */
	.half	0x2d		/* y offset of collision box */
	.half	0x3e		/* x size of collision box */
	.half	0x1d		/* y size of collision box */
	.half	0x0317		/* strike routine */
	.half	0x0802		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_jax_sweep:
	.half	0x65		/* x offset of collision box */
	.half	0x7a		/* y offset of collision box */
	.half	0x49		/* x size of collision box */
	.half	0x1f		/* y size of collision box */
	.half	0x0403		/* strike routine */
	.half	0x1403		/* damage */
	.half	SF_DUCK

	.align 2
stk_jax_duck_punch:
	.half	0x51		/* x offset of collision box */
	.half	0x48		/* y offset of collision box */
	.half	0x37		/* x size of collision box */
	.half	0x1d		/* y size of collision box */
	.half	0x050a		/* strike routine */
	.half	0x0602		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_jax_duck_kickh:
	.half	0x3c		/* x offset of collision box */
	.half	0x55		/* y offset of collision box */
	.half	0x3a		/* x size of collision box */
	.half	0x42		/* y size of collision box */
	.half	0x060b		/* strike routine */
	.half	0x0c03		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_jax_duck_kickl:
	.half	0x63		/* x offset of collision box */
	.half	0x78		/* y offset of collision box */
	.half	0x46		/* x size of collision box */
	.half	0x20		/* y size of collision box */
	.half	0x070a		/* strike routine */
	.half	0x0602		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_jax_uppercut:
	.half	0x4b		/* x offset of collision box */
	.half	0xfff8		/* y offset of collision box */
	.half	0x31		/* x size of collision box */
	.half	0x4c		/* y size of collision box */
	.half	0x0802		/* strike routine */
	.half	0x2409		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_jax_jump_punch:
	.half	0x58		/* x offset of collision box */
	.half	0x12		/* y offset of collision box */
	.half	0x33		/* x size of collision box */
	.half	0x39		/* y size of collision box */
	.half	0x0b01		/* strike routine */
	.half	0x1005		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_jax_jump_kick:
	.half	0x47		/* x offset of collision box */
	.half	0x0f		/* y offset of collision box */
	.half	0x39		/* x size of collision box */
	.half	0x47		/* y size of collision box */
	.half	0x0b01		/* strike routine */
	.half	0x1306		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_jax_flip_kick:
	.half	0x58		/* x offset of collision box */
	.half	0x31		/* y offset of collision box */
	.half	0x42		/* x size of collision box */
	.half	0x29		/* y size of collision box */
	.half	0x0a01		/* strike routine */
	.half	0x1a07		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_jax_flip_punch:
	.half	0x47		/* x offset of collision box */
	.half	0x0f		/* y offset of collision box */
	.half	0x39		/* x size of collision box */
	.half	0x47		/* y size of collision box */
	.half	0x0b01		/* strike routine */
	.half	0x1005		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_jax_roundh:
	.half	0x53		/* x offset of collision box */
	.half	0x09		/* y offset of collision box */
	.half	0x37		/* x size of collision box */
	.half	0x36		/* y size of collision box */
	.half	0x0c01		/* strike routine */
	.half	0x1d04		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_jax_knee:
	.half	0x52		/* x offset of collision box */
	.half	0x2e		/* y offset of collision box */
	.half	0x30		/* x size of collision box */
	.half	0x37		/* y size of collision box */
	.half	0x0907		/* strike routine */
	.half	0x1203		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_jax_elbow:
	.half	0x41		/* x offset of collision box */
	.half	0x13		/* y offset of collision box */
	.half	0x36		/* x size of collision box */
	.half	0x29		/* y size of collision box */
	.half	0x0907		/* strike routine */
	.half	0x1003		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_jax_zap:
	.half	0x73		/* x offset of collision box */
	.half	0x36		/* y offset of collision box */
	.half	0x5c		/* x size of collision box */
	.half	0x10		/* y size of collision box */
	.half	0x2304		/* strike routine */
	.half	0x1003		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_jax_prezap:
	.half	0x4f		/* x offset of collision box */
	.half	0x2f		/* y offset of collision box */
	.half	0x4a		/* x size of collision box */
	.half	0x1a		/* y size of collision box */
	.half	0x2304		/* strike routine */
	.half	0x1003		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_noogy:
	.half	0x60 		/* x offset of collision box */
	.half	0x0c		/* y offset of collision box */
	.half	0x36		/* x size of collision box */
	.half	0x28		/* y size of collision box */
	.half	0x0d00		/* strike routine */
	.half	0x0000		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_jax_dash:
	.half	0x5d		/* x offset of collision box */
	.half	0x24		/* y offset of collision box */
	.half	0x44		/* x size of collision box */
	.half	0x16		/* y size of collision box */
	.half	0x2401		/* strike routine */
	.half	0x1603		/* damage */
	.half	SF_SQUEEZE

/**************************************************************************
*											     *
*   Sonya strikes    									     *
*											     *
**************************************************************************/
	.align 2
sonya_strikes:
	.word	stk_sonya_hikick		/* 0 */
	.word	stk_sonya_lokick		/* 1 */
	.word	stk_sonya_hi_punch		/* 2 */
	.word	stk_sonya_lo_punch		/* 3 */
	.word	stk_sonya_sweep			/* 4 */
	.word	stk_sonya_duck_punch		/* 5 */
	.word	stk_sonya_duck_kickh		/* 6 */
	.word	stk_sonya_duck_kickl		/* 7 */
	.word	stk_sonya_uppercut		/* 8 */
	.word	stk_sonya_jump_punch		/* 9 */
	.word	stk_sonya_jump_kick		/* a */
	.word	stk_sonya_flip_kick		/* d */
	.word	stk_sonya_flip_punch		/* c */
	.word	stk_sonya_roundh		/* d */
	.word	stk_sonya_knee			/* e */
	.word	stk_sonya_elbow			/* f */
	.word	stk_sonya_leg			/* 10 */
	.word	stk_sonya_square		/* 11 */
	.word	stk_sonya_zap			/* 12 */
	.word	stk_sonya_prezap		/* 13 */
	.word	stk_sonya_bike			/* 14 */

/* 1. new stk table entry */
/* 2. set hit/block offsets */
/* 3. set hit/block damage */

	.align 2
stk_sonya_hikick:
	.half	0x4b+8		/* x offset of collision box */
	.half	0x0f		/* y offset of collision box */
	.half	0x44		/* x size of collision box */
	.half	0x2e		/* y size of collision box */
	.half	0x0006		/* strike routine */
	.half	0x1805		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_sonya_lokick:
	.half	0x52+8		/* x offset of collision box */
	.half	0x30		/* y offset of collision box */
	.half	0x49		/* x size of collision box */
	.half	0x1f		/* y size of collision box */
	.half	0x0106		/* strike routine */
	.half	0x1504		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_sonya_duck_punch:
	.half	0x39+8		/* x offset of collision box */
	.half	0x40		/* y offset of collision box */
	.half	0x33		/* x size of collision box */
	.half	0x22		/* y size of collision box */
	.half	0x050a		/* strike routine */
	.half	0x0602		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_sonya_duck_kickh:
	.half	0x47+8		/* x offset of collision box */
	.half	0x33		/* y offset of collision box */
	.half	0x37		/* x size of collision box */
	.half	0x3e		/* y size of collision box */
	.half	0x060b		/* strike routine */
	.half	0x0c03		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_sonya_duck_kickl:
	.half	0x62+8		/* x offset of collision box */
	.half	0x6d		/* y offset of collision box */
	.half	0x46		/* x size of collision box */
	.half	0x1e		/* y size of collision box */
	.half	0x070a		/* strike routine */
	.half	0x0602		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_sonya_uppercut:
	.half	0x4e		/* x offset of collision box */
	.half	0xfff9		/* y offset of collision box */
	.half	0x31		/* x size of collision box */
	.half	0x43		/* y size of collision box */
	.half	0x0802		/* strike routine */
	.half	0x2409		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_sonya_elbow:
	.half	0x3d+8		/* x offset of collision box */
	.half	0x13		/* y offset of collision box */
	.half	0x29		/* x size of collision box */
	.half	0x27		/* y size of collision box */
	.half	0x0907		/* strike routine */
	.half	0x1003		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_sonya_knee:
	.half	0x40+8		/* x offset of collision box */
	.half	0x2e		/* y offset of collision box */
	.half	0x2b		/* x size of collision box */
	.half	0x37		/* y size of collision box */
	.half	0x0907		/* strike routine */
	.half	0x1203		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_sonya_roundh:
	.half	0x48+8		/* x offset of collision box */
	.half	0x0d		/* y offset of collision box */
	.half	0x37		/* x size of collision box */
	.half	0x10		/* y size of collision box */
	.half	0x0c01		/* strike routine */
	.half	0x1d04		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_sonya_sweep:
	.half	0x5d+8		/* x offset of collision box */
	.half	0x6e		/* y offset of collision box */
	.half	0x49		/* x size of collision box */
	.half	0x1b		/* y size of collision box */
	.half	0x0403		/* strike routine */
	.half	0x1403		/* damage */
	.half	SF_DUCK

	.align 2
stk_sonya_flip_kick:
	.half	0x41+8		/* x offset of collision box */
	.half	0x23		/* y offset of collision box */
	.half	0x42		/* x size of collision box */
	.half	0x22		/* y size of collision box */
	.half	0x0a01		/* strike routine */
	.half	0x1a07		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_sonya_flip_punch:
	.half	0x3e+8		/* x offset of collision box */
	.half	0x10		/* y offset of collision box */
	.half	0x31		/* x size of collision box */
	.half	0x31		/* y size of collision box */
	.half	0x0b01		/* strike routine */
	.half	0x1005		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_sonya_jump_punch:
	.half	0x3e+8		/* x offset of collision box */
	.half	0x10		/* y offset of collision box */
	.half	0x31		/* x size of collision box */
	.half	0x31		/* y size of collision box */
	.half	0x0b01		/* strike routine */
	.half	0x1005		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_sonya_jump_kick:
	.half	0x3e+8		/* x offset of collision box */
	.half	0x15		/* y offset of collision box */
	.half	0x39		/* x size of collision box */
	.half	0x3f		/* y size of collision box */
	.half	0x0b01		/* strike routine */
	.half	0x1306		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_sonya_hi_punch:
	.half	0x41		/* x offset of collision box */
	.half	0x12		/* y offset of collision box */
	.half	0x35		/* x size of collision box */
	.half	0x1e		/* y size of collision box */
	.half	0x0211		/* strike routine */
	.half	0x0b03		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_sonya_lo_punch:
	.half	0x48		/* x offset of collision box */
	.half	0x28		/* y offset of collision box */
	.half	0x37		/* x size of collision box */
	.half	0x13		/* y size of collision box */
	.half	0x0317		/* strike routine */
	.half	0x0802		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_sonya_leg:
	.half	0x6b+8		/* x offset of collision box */
	.half	0x22		/* y offset of collision box */
	.half	0x48		/* x size of collision box */
	.half	0x4d		/* y size of collision box */
	.half	0x0d00		/* strike routine */
	.half	0x0000		/* damage */
	.half	SF_DUCK

	.align 2
stk_sonya_square:
	.half	0x46		/* x offset of collision box */
	.half	0x0f		/* y offset of collision box */
	.half	0x3a		/* x size of collision box */
	.half	0x34		/* y size of collision box */
	.half	0x1d00		/* strike routine */
	.half	0x1b08		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_sonya_zap:
	.half	0x6c		/* x offset of collision box */
	.half	0x23		/* y offset of collision box */
	.half	0x24		/* x size of collision box */
	.half	0x0b		/* y size of collision box */
	.half	0x1e04		/* strike routine */
	.half	0x1303		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_sonya_prezap:
	.half	0x4d		/* x offset of collision box */
	.half	0x23		/* y offset of collision box */
	.half	0x2f		/* x size of collision box */
	.half	0x1b		/* y size of collision box */
	.half	0x1e04		/* strike routine */
	.half	0x1303		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_sonya_bike:
	.half	0x36		/* x offset of collision box */
	.half	0x03		/* y offset of collision box */
	.half	0x39		/* x size of collision box */
	.half	0x35		/* y size of collision box */
	.half	0x0d01		/* strike routine */
	.half	0x1603		/* damage */
	.half	SF_SQUEEZE

/**************************************************************************
*											     *
*   Kano strikes										     *
*											     *
**************************************************************************/
	.align 2
kano_strikes:
	.word	stk_kano_hikick		/* 0 */
	.word	stk_kano_lokick		/* 1 */
	.word	stk_kano_hi_punch	/* 2 */
	.word	stk_kano_lo_punch	/* 3 */
	.word	stk_kano_sweep		/* 4 */
	.word	stk_kano_duck_punch	/* 5 */
	.word	stk_kano_duck_kickh	/* 6 */
	.word	stk_kano_duck_kickl	/* 7 */
	.word	stk_kano_uppercut	/* 8 */
	.word	stk_kano_jump_punch	/* 9 */
	.word	stk_kano_jump_kick	/* a */
	.word	stk_kano_flip_kick	/* d */
	.word	stk_kano_flip_punch	/* c */
	.word	stk_kano_roundh		/* d */
	.word	stk_kano_knee		/* e */
	.word	stk_kano_elbow		/* f */
	.word	stk_kano_shake		/*10 */
	.word	0			/*11 */
	.word	stk_kano_swipe		/*12 */
	.word	stk_kano_roll		/*13 - kano ball roll */
	.word	stk_kano_prezap		/*14 */
	.word	stk_kano_zap		/*15 */

/* 1. new stk table entry */
/* 2. set hit/block offsets */
/* 3. set hit/block damage */

	.align 2
stk_kano_hikick:
	.half	0x59		/* x offset of collision box */
	.half	0x0d		/* y offset of collision box */
	.half	0x40		/* x size of collision box */
	.half	0x29		/* y size of collision box */
	.half	0x0006		/* strike routine */
	.half	0x1805		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_kano_lokick:
	.half	0x6d		/* x offset of collision box */
	.half	0x2a		/* y offset of collision box */
	.half	0x49		/* x size of collision box */
	.half	0x12		/* y size of collision box */
	.half	0x0106		/* strike routine */
	.half	0x1504		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_kano_duck_punch:
	.half	0x56		/* x offset of collision box */
	.half	0x44		/* y offset of collision box */
	.half	0x3a		/* x size of collision box */
	.half	0x15		/* y size of collision box */
	.half	0x050a		/* strike routine */
	.half	0x0602		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_kano_duck_kickh:
	.half	0x3a		/* x offset of collision box */
	.half	0x34		/* y offset of collision box */
	.half	0x37		/* x size of collision box */
	.half	0x39		/* y size of collision box */
	.half	0x060b		/* strike routine */
	.half	0x0c03		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_kano_duck_kickl:
	.half	0x5c		/* x offset of collision box */
	.half	0x6d		/* y offset of collision box */
	.half	0x46		/* x size of collision box */
	.half	0x20		/* y size of collision box */
	.half	0x070a		/* strike routine */
	.half	0x0602		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_kano_uppercut:
	.half	0x4d		/* x offset of collision box */
	.half	0xfff7		/* y offset of collision box */
	.half	0x35		/* x size of collision box */
	.half	0x46		/* y size of collision box */
	.half	0x0802		/* strike routine */
	.half	0x2409		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_kano_elbow:
	.half	0x41		/* x offset of collision box */
	.half	0x04		/* y offset of collision box */
	.half	0x29		/* x size of collision box */
	.half	0x2d		/* y size of collision box */
	.half	0x0907		/* strike routine */
	.half	0x1003		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_kano_knee:
	.half	0x53		/* x offset of collision box */
	.half	0x26		/* y offset of collision box */
	.half	0x37		/* x size of collision box */
	.half	0x38		/* y size of collision box */
	.half	0x0907		/* strike routine */
	.half	0x1203		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_kano_roundh:
	.half	0x59		/* x offset of collision box */
	.half	0x06		/* y offset of collision box */
	.half	0x37		/* x size of collision box */
	.half	0x36		/* y size of collision box */
	.half	0x0c01		/* strike routine */
	.half	0x1d04		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_kano_sweep:
	.half	0x6c		/* x offset of collision box */
	.half	0x6d		/* y offset of collision box */
	.half	0x4f		/* x size of collision box */
	.half	0x22		/* y size of collision box */
	.half	0x0403		/* strike routine */
	.half	0x1403		/* damage */
	.half	SF_DUCK

	.align 2
stk_kano_flip_kick:
	.half	0x57		/* x offset of collision box */
	.half	0x2e		/* y offset of collision box */
	.half	0x42		/* x size of collision box */
	.half	0x24		/* y size of collision box */
	.half	0x0a01		/* strike routine */
	.half	0x1a07		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_kano_flip_punch:
	.half	0x4d		/* x offset of collision box */
	.half	0x1f		/* y offset of collision box */
	.half	0x3f		/* x size of collision box */
	.half	0x24		/* y size of collision box */
	.half	0x0b01		/* strike routine */
	.half	0x1005		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_kano_jump_punch:
	.half	0x4d		/* x offset of collision box */
	.half	0x1f		/* y offset of collision box */
	.half	0x3f		/* x size of collision box */
	.half	0x24		/* y size of collision box */
	.half	0x0b01		/* strike routine */
	.half	0x1005		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_kano_jump_kick:
	.half	0x55		/* x offset of collision box */
	.half	0x24		/* y offset of collision box */
	.half	0x48		/* x size of collision box */
	.half	0x1a		/* y size of collision box */
	.half	0x0b01		/* strike routine */
	.half	0x1306		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_kano_hi_punch:
	.half	0x49		/* x offset of collision box */
	.half	0x0e		/* y offset of collision box */
	.half	0x35		/* x size of collision box */
	.half	0x22		/* y size of collision box */
	.half	0x0211		/* strike routine */
	.half	0x0b03		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_kano_lo_punch:
	.half	0x4f		/* x offset of collision box */
	.half	0x1d		/* y offset of collision box */
	.half	0x3f		/* x size of collision box */
	.half	0x1d		/* y size of collision box */
	.half	0x0317		/* strike routine */
	.half	0x0802		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_kano_swipe:
	.half	0x6d		/* x offset of collision box */
	.half	0x14		/* y offset of collision box */
	.half	0x4b		/* x size of collision box */
	.half	0x43		/* y size of collision box */
	.half	0x1c01		/* strike routine */
	.half	0x1a03		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_kano_roll:
	.half	0x39		/* x offset of collision box */
	.half	0x0e		/* y offset of collision box */
	.half	0x48		/* x size of collision box */
	.half	0x1f		/* y size of collision box */
	.half	0x1a00		/* strike routine */
	.half	0x1805		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_kano_zap:
	.half	0x1c		/* x offset of collision box */
	.half	0xfff5		/* y offset of collision box */
	.half	0x2c		/* x size of collision box */
	.half	0x21		/* y size of collision box */
	.half	0x1b04		/* strike routine */
	.half	0x1303		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_kano_prezap:
	.half	0x6b		/* x offset of collision box */
	.half	0x04		/* y offset of collision box */
	.half	0x4a		/* x size of collision box */
	.half	0x1e		/* y size of collision box */
	.half	0x1704		/* strike routine */
	.half	0x1303		/* damage */
	.half	SF_SQUEEZE

	.align 2
stk_kano_shake:
	.half	0x65		/* x offset of collision box */
	.half	0x20		/* y offset of collision box */
	.half	0x3f		/* x size of collision box */
	.half	0x11		/* y size of collision box */
	.half	0x0d00		/* strike routine */
	.half	0x0000		/* damage */
	.half	SF_SQUEEZE

/************************************************************************** */
/************************************************************************** */
	.align 2
	.globl combo_strike_table
combo_strike_table:
	.word	stk_combo0	/* 0 */
	.word	stk_combo1	/* 1 */
	.word	stk_combo2	/* 2 */
	.word	stk_combo3	/* 3 */
	.word	stk_combo4  	/* 4 */
	.word	stk_combo_upcut  	/* 5 */
	.word	stk_combo_klang	/* 6 */
	.word	stk_combo1_stab	/* 7 */
	.word	stk_combo2_stab	/* 8 */
	.word	stk_combo6  	/* 9 */

	.word	stk_combo0		/* a - not used */
	.word	stk_combo1_weak		/* b - not used */
	.word	stk_combo1_stabw	/* c */
	.word	stk_combo_upcutw	/* d - upcut weak */
	.word	stk_combo0		/* e - not used */
	.word	stk_combo0		/* f - not used */

	.word	stk_hard_combo0	/* 10 */
	.word	stk_hard_combo1	/* 11 */
	.word	stk_hard_combo2	/* 12 */
	.word	stk_combo3	/* 13 */
	.word	stk_combo4  	/* 14 */
	.word	stk_combo_upcut  	/* 15 */



combo_damage	=	0x0701
hard_damage		=	0x0a01
weak_damage		=	0x0301

	.align 2
stk_combo0:
	.half	0x51   		/* x offset of collision box */
	.half	0x0    		/* y offset of collision box */
	.half	0x43   		/* x size of collision box */
	.half	0x85   		/* y size of collision box */
	.half	0x100f 		/* strike routine */
	.half	combo_damage	/* damage */
 	.half	0

	.align 2
stk_hard_combo0:
	.half	0x51   		/* x offset of collision box */
	.half	0x0    		/* y offset of collision box */
	.half	0x43   		/* x size of collision box */
	.half	0x85   		/* y size of collision box */
	.half	0x100f 		/* strike routine */
	.half	hard_damage	/* damage */
 	.half	0

	.align 2
stk_combo1:
	.half	0x51   		/* x offset of collision box */
	.half	0x0    		/* y offset of collision box */
	.half	0x43   		/* x size of collision box */
	.half	0x85   		/* y size of collision box */
	.half	0x110f 		/* strike routine */
	.half	combo_damage	/* damage */
 	.half	0
	
	.align 2
stk_combo1_weak:
	.half	0x51   		/* x offset of collision box */
	.half	0x0    		/* y offset of collision box */
	.half	0x43   		/* x size of collision box */
	.half	0x85   		/* y size of collision box */
	.half	0x110f 		/* strike routine */
	.half	weak_damage	/* damage */
 	.half	0
	.half	0

	.align 2
stk_hard_combo1:
	.half	0x51   		/* x offset of collision box */
	.half	0x0    		/* y offset of collision box */
	.half	0x43   		/* x size of collision box */
	.half	0x85   		/* y size of collision box */
	.half	0x110f 		/* strike routine */
	.half	hard_damage	/* damage */
 	.half	0

	.align 2
stk_combo1_stabw:
	.half	0x51   		/* x offset of collision box */
	.half	0x0    		/* y offset of collision box */
	.half	0x43   		/* x size of collision box */
	.half	0x85   		/* y size of collision box */
	.half	0x0f0f 		/* strike routine */
	.half	weak_damage	/* damage */
 	.half	0
	.half	0

	.align 2
stk_combo1_stab:
	.half	0x51   		/* x offset of collision box */
	.half	0x0    		/* y offset of collision box */
	.half	0x43   		/* x size of collision box */
	.half	0x85   		/* y size of collision box */
	.half	0x0f0f 		/* strike routine */
	.half	hard_damage	/* damage */
 	.half	0

	.align 2
stk_combo2:
	.half	0x51   		/* x offset of collision box */
	.half	0x0    		/* y offset of collision box */
	.half	0x43   		/* x size of collision box */
	.half	0x85   		/* y size of collision box */
	.half	0x1212 		/* strike routine */
	.half	combo_damage	/* damage */
 	.half	0

	.align 2
stk_hard_combo2:
	.half	0x51   		/* x offset of collision box */
	.half	0x0    		/* y offset of collision box */
	.half	0x43   		/* x size of collision box */
	.half	0x85   		/* y size of collision box */
	.half	0x1212 		/* strike routine */
	.half	hard_damage	/* damage */
 	.half	0

	.align 2
stk_combo2_stab:
	.half	0x51   		/* x offset of collision box */
	.half	0x0    		/* y offset of collision box */
	.half	0x43   		/* x size of collision box */
	.half	0x85   		/* y size of collision box */
	.half	0x0e12 		/* strike routine */
	.half	combo_damage	/* damage */
 	.half	0

	.align 2
stk_combo3:
	.half	0x51   		/* x offset of collision box */
	.half	0x0    		/* y offset of collision box */
	.half	0x43   		/* x size of collision box */
	.half	0x85   		/* y size of collision box */
	.half	0x1312 		/* strike routine */
	.half	combo_damage	/* damage */
 	.half	0

	.align 2
stk_combo4:
	.half	0x51   		/* x offset of collision box */
	.half	0x0    		/* y offset of collision box */
	.half	0x43   		/* x size of collision box */
	.half	0x85   		/* y size of collision box */
	.half	0x1412 		/* strike routine */
	.half	combo_damage	/* damage */
 	.half	0
	
	.align 2
stk_combo_upcut:
	.half	0x51   		/* x offset of collision box */
	.half	0x0    		/* y offset of collision box */
	.half	0x43   		/* x size of collision box */
	.half	0x85   		/* y size of collision box */
	.half	0x1512 		/* strike routine */
	.half	combo_damage	/* damage */
 	.half	0
 	.half	0

	.align 2
stk_combo_upcutw:
	.half	0x51   		/* x offset of collision box */
	.half	0x0    		/* y offset of collision box */
	.half	0x43   		/* x size of collision box */
	.half	0x85   		/* y size of collision box */
	.half	0x1512 		/* strike routine */
	.half	weak_damage	/* damage */
 	.half	0

	.align 2
stk_combo6:
	.half	0x51   		/* x offset of collision box */
	.half	0x0    		/* y offset of collision box */
	.half	0x43   		/* x size of collision box */
	.half	0x85   		/* y size of collision box */
	.half	0x1712 		/* strike routine */
	.half	combo_damage	/* damage */
 	.half	0


	.align 2
stk_combo_klang:
	.half	0x51   		/* x offset of collision box */
	.half	0x0    		/* y offset of collision box */
	.half	0x43   		/* x size of collision box */
	.half	0x85   		/* y size of collision box */
	.half	0x160f 		/* strike routine */
	.half	combo_damage	/* damage */
 	.half	0

	.align 2
stk_combo_axeup:
	.half	0x5a		/* x offset of collision box */
	.half	-0x02		/* y offset of collision box */
	.half	0x36		/* x size of collision box */
	.half	0x5c		/* y size of collision box */
	.half	0x2b01		/* strike routine */
	.half	0x1804		/* damage */
	.half	SF_SQUEEZE

/************************************************************************** */

	.align 2
stk_dummy:
	.half	10		/* x offset of collision box */
	.half	10		/* y offset of collision box */
	.half	10		/* x size of collision box */
	.half	10		/* y size of collision box */
	.half	0x0000		/* strike routine */
	.half	0x0000		/* damage */
	.half	SF_SQUEEZE

	.align 2
dummy_strikes:
	.word	stk_dummy
	.word	stk_dummy
	.word	stk_dummy
	.word	stk_dummy
	.word	stk_dummy
	.word	stk_dummy
	.word	stk_dummy
	.word	stk_dummy
	.word	stk_dummy
	.word	stk_dummy
	.word	stk_dummy
	.word	stk_dummy
