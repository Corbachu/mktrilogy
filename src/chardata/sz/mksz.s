#include <regdef.h>
#include "mkchar.inc"

	.option	pic0
	.set	noreorder
	.data

/*
;******************************************************************************
; File: mksonya.s
;
; By: David Schwartz
;
; Date: August 1994
;
; (C) Williams Entertainment
;
; Mortal Kombat III Sonya Animation Tables
;******************************************************************************
*/

	.extern SZBLU_P
	.extern SZBLUGR_P
	.extern ICE_P
	.extern SZICE_P
	.extern FRZBLST_P
	.extern ICO13P
	.extern ICEBLOW_P

	.align 2
#include "mksz.atd"
#include "mksz.att1" 
