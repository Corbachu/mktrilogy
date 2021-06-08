;******************************************************************************
; File: mkmarkdt.s
;
; By: David Schwartz
;
; Date: Jan 1995
;
; (C) Williams Entertainment
;
; Mortal Kombat III Hidden Game Textures
;******************************************************************************/

	opt c+
;
;
l27 group
	section	.bkgddata_l27

	include mkchar.inc

	CNOP 0,4
star_p
	dw	5
	dh	$0000,$7c00,$7c00,$7c00,$7c00

	CNOP 0, 4
enemyp
	DW 15
	DH $0000, $5400, $6108, $6A29, $0012, $1CFF, $5ADF, $03FF, $294A, $4631
	DH $6318, $7FFF, $0160, $1626, $4B72

	CNOP 0, 4
expldp3
	DW 15
	DH $0000, $002A, $048E, $1153, $2218, $2EDA, $3B5D, $4BFF, $001D, $04DD
	DH $0D9D, $163E, $1EDE, $277F, $2FFF

	CNOP 0, 4
shipp1
	DW 15
	DH $0000, $5400, $7CE4, $7FB4, $7FFF, $04F8, $0010, $56B5, $318C, $7D4A
	DH $6ECE, $4A52, $295F, $6B5A, $2BFF

	CNOP 0, 4
OSTR_P
	DW 10
	DH $0000, $2DF5, $0088, $0D0C, $7DE0, $2861, $5820, $7B9A, $1000, $0339

	public on

	CNOP 0,4
hidden_anims

expld1
	DW expld1_IMG-hidden_anims
	DH 12, 11, 0, 0
	dw   expldp3
expld2
	DW expld2_IMG-hidden_anims
	DH 16, 21, 0, 0
	dw   expldp3
expld3
	DW expld3_IMG-hidden_anims
	DH 16, 21, 0, 0
	dw   expldp3
expld4
	DW expld4_IMG-hidden_anims
	DH 16, 21, 0, 0
	dw   expldp3
expld5
	DW expld5_IMG-hidden_anims
	DH 16, 20, 0, 0
	dw   expldp3
expld6
	DW expld6_IMG-hidden_anims
	DH 10, 10, 0, 0
	dw   expldp3
expld7
	DW expld7_IMG-hidden_anims
	DH 11, 11, 0, 0
	dw   expldp3
expld8
	DW expld8_IMG-hidden_anims
	DH 11, 11, 0, 0
ship1
	DW ship1_IMG-hidden_anims
	DH 14, 21, 0, 0
	dw   shipp1
ship2
	DW ship2_IMG-hidden_anims
	DH 14, 21, 0, 0
	dw   shipp1
ship3
	DW ship3_IMG-hidden_anims
	DH 15, 15, 0, 0
	dw   shipp1
ship4
	DW ship4_IMG-hidden_anims
	DH 15, 15, 0, 0
	dw   shipp1
enemy1
	DW enemy1_IMG-hidden_anims
	DH 11, 11, 0, 0
	dw   enemyp
enemy2
	DW enemy2_IMG-hidden_anims
	DH 11, 11, 0, 0
	dw   enemyp
enemy3
	DW enemy3_IMG-hidden_anims
	DH 11, 11, 0, 0
	dw   enemyp
enemy4
	DW enemy4_IMG-hidden_anims
	DH 8, 11, 0, 0
	dw   enemyp
enemy5
	DW enemy5_IMG-hidden_anims
	DH 11, 11, 0, 0
	dw   enemyp
enemy6
	DW enemy6_IMG-hidden_anims
	DH 11, 8, 0, 0
	dw   enemyp
enemy7
	DW enemy7_IMG-hidden_anims
	DH 11, 11, 0, 0
	dw   enemyp
enemy8
	DW enemy8_IMG-hidden_anims
	DH 11, 11, 0, 0
	dw   enemyp
enemy9
	DW enemy9_IMG-hidden_anims
	DH 11, 11, 0, 0
	dw   enemyp
enemy10
	DW enemy10_IMG-hidden_anims
	DH 11, 8, 0, 0
	dw   enemyp
star
	dw star_IMG-hidden_anims
	Dh 1,1,0,0
	DW star_p

	CNOP 0,4
star_IMG
	db	0,0,0,0,1,1,1,1

	public off

	CNOP 0,4
	include ..\attract\arcade\arcade.psi
