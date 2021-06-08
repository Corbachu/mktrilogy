;******************************************************************************
; File: mkhscore.s
;
; By: David Schwartz
;
; Date: Feb 1995
;
; (C) Williams Entertainment
;
; Mortal Kombat III Mortal Kombat High Score Module
;******************************************************************************/

	opt c+

l25 group
	section	.bkgddata_l25

	include mkchar.inc
	include mkbkgd.inc

;*********************************
;**			EXTERNALS			**
;*********************************
	xref no_scroll
	xref dlists_bogus

;*********************************
;**			PALETTES								**
;*********************************
	CNOP 0,4
	include palsrc\mkvspal.mas

;*********************************
;**			ANIMATIONS			**
;*********************************
	CNOP 0,4

;*********************************
;**		 MODULE DATA			**
;*********************************
	CNOP 0,4
	include ..\attract\vs\steelvs.mod

	CNOP 0,4
	global hscore_module
hscore_module
	dh	0		 		; autoerase color
	dh	$00				; initial world y
	dh	$00	     			; ground y
	dh	$00				; initial worldx
	dh	-$500 	  			; scroll left limit
	dh	$500	  			; scroll right limit

	dw	calla_return
	dw	no_scroll			; scroll table
	dw	dlists_bogus
	dw	bakmods

	dw	STEELMODBMOD
	dh	$fffe,$07
	dw	$ffffffff
	dw	0				; no floor here !!
