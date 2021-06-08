;******************************************************************************
; File: mksselvic.s
;
; By: David Schwartz
;
; Date: August 1994
;
; (C) Williams Entertainment
;
; Mortal Kombat III Select Screen Stances & Victories Animation Tables
;******************************************************************************/

	opt c+

select_ovl group
	section	.text_select

	include mkchar.inc

	global kano_panitab1
	global sonya_panitab1
	global jax_panitab1
	global ind_panitab1
	global sz_panitab1
	global swat_panitab1
	global lia_panitab1
	global robo1_panitab1
	global robo2_panitab1
	global lao_panitab1
	global tusk_panitab1
	global sg_panitab1
	global st_panitab1
	global lk_panitab1
	
	global jade_panitab1
	global kit_panitab1
	global mil_panitab1

	global rep_panitab1
	global osz_panitab1
	global scorp_panitab1
	global ermac_panitab1


	xref	GLOW_P
	xref	GRNFLM_P
	xref	GFIRE_P

	CNOP 0,4
	include ..\chars\ermac\pselect\mkermacp.psx
	include ..\chars\ermac\pselect\mkermacp.psi

	CNOP 0,4
	include ..\chars\scorpion\pselect\mkscorpp.psx
	include ..\chars\scorpion\pselect\mkscorpp.psi

	CNOP 0,4
	include ..\chars\oldsz\pselect\mkoszp.psx
	include ..\chars\oldsz\pselect\mkoszp.psi

	CNOP 0,4
	include ..\chars\reptile\pselect\mkrepp.psx
	include ..\chars\reptile\pselect\mkrepp.psi

	CNOP 0,4
	include ..\chars\kitana\pselect\mkkitp.psx
	include ..\chars\kitana\pselect\mkkitp.psi

	CNOP 0,4
	include ..\chars\mileena\pselect\mkmelp.psx
	include ..\chars\mileena\pselect\mkmelp.psi

	CNOP 0,4
	include ..\chars\jade\pselect\mkjadep.psx
	include ..\chars\jade\pselect\mkjadep.psi

	CNOP 0,4
	include ..\chars\sonya\pselect\mksonyap.psx
	include ..\chars\sonya\pselect\mksonyap.psi

	CNOP 0,4
	include ..\chars\kano\pselect\mkkanop.psx
	include ..\chars\kano\pselect\mkkanop.psi

	CNOP 0,4
	include ..\chars\jax\pselect\mkjaxp.psx
	include ..\chars\jax\pselect\mkjaxp.psi

	CNOP 0,4
	include ..\chars\lia\pselect\mkliap.psx
	include ..\chars\lia\pselect\mkliap.psi

	CNOP 0,4
	include ..\chars\lkang\pselect\mklkp.psx
	include ..\chars\lkang\pselect\mklkp.psi

	CNOP 0,4
	include ..\chars\shang\pselect\mkstp.psx
	include ..\chars\shang\pselect\mkstp.psi

	CNOP 0,4
	include ..\chars\indian\pselect\mkindp.psx
	include ..\chars\indian\pselect\mkindp.psi

	CNOP 0,4
	include ..\chars\femgoro\pselect\mksgp.psx
	include ..\chars\femgoro\pselect\mksgp.psi

	CNOP 0,4
	include ..\chars\robo1\pselect\mkrobo1p.psx
	include ..\chars\robo1\pselect\mkrobo1p.psi

	CNOP 0,4
	include ..\chars\robo2\pselect\mkrobo2p.psx
	include ..\chars\robo2\pselect\mkrobo2p.psi

	CNOP 0,4
	include ..\chars\lao\pselect\mklaop.psx
	include ..\chars\lao\pselect\mklaop.psi

	CNOP 0,4
	include ..\chars\subzero\pselect\mkszp.psx
	include ..\chars\subzero\pselect\mkszp.psi

	CNOP 0,4
	include ..\chars\swat\pselect\mkswatp.psx
	include ..\chars\swat\pselect\mkswatp.psi

	CNOP 0,4
	include ..\chars\tusk\pselect\mktuskp.psx
	include ..\chars\tusk\pselect\mktuskp.psi
