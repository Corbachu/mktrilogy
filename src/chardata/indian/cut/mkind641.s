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
	.extern INBLU_P
	.extern INYEL_P
	.extern GRNFLM_P
	.extern GFIRE_p
	.extern ZAP_P
	.extern LIGHTNG_P

	.align 2
#include "mkind64.att2" 
