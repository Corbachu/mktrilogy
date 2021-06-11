**************************************************************************
*											     *
*  mk3 - VS Stuff
*											     *
**************************************************************************
	.FILE	'mkst.asm'
	.WIDTH	132
	.OPTION	B,D,L,T
	.MNOLIST

	.include mainequ.asm
	.include imgtbl.glo
	.include sysequ.asm
	.include shang.tbl
	.text

robot_list
;cyrax
	.long	VRB1GOLD1A
	.long	VRB1GOLD1B
	.long	VRB1GOLD1C
	.long	VRB1GOLD1D
	.long	VRB1GOLD1E
	.long	VRB1GREY1A
	.long	VRB1GREY1B
	.long	VRB1GREY1C
	.long	VRB1GREY1D
	.long	VRB1GREY1E
	.long	VRB1GREY1F
	.long	VRB1GREY1G

;sektor
	.long	VRB2GREY1A
	.long	VRB2GREY1B
	.long	VRB2GREY1C
	.long	VRB2GREY1D
	.long	VRB2GREY1E
	.long	VRB2GREY1F
	.long	VRB2RED1A
	.long	VRB2RED1B
	.long	VRB2RED1C
	.long	VRB2RED1D
	.long	VRB2RED1E
	.long	VRB2RED1F
	.long	VRB2RED1G

;smoke (CYRAX)



;Robot 1 Pieces
VRB1GOLD1A
	.long	RB1GOLD1A,0
VRB1GOLD1B
	.long	RB1GOLD1B,0
VRB1GOLD1C
	.long	RB1GOLD1C,0
VRB1GOLD1D
	.long	RB1GOLD1D,0
VRB1GOLD1E
	.long	RB1GOLD1E,0
VRB1GREY1A
	.long	RB1GREY1A,0
VRB1GREY1B
	.long	RB1GREY1B,0
VRB1GREY1C
	.long	RB1GREY1C,0
VRB1GREY1D
	.long	RB1GREY1D,0
VRB1GREY1E
	.long	RB1GREY1E,0
VRB1GREY1F
	.long	RB1GREY1F,0
VRB1GREY1G
	.long	RB1GREY1G,0

;Robot 2 Pieces
VRB2GREY1A
	.long	RB2GREY1A,0
VRB2GREY1B
	.long	RB2GREY1B,0
VRB2GREY1C
	.long	RB2GREY1C,0
VRB2GREY1D
	.long	RB2GREY1D,0
VRB2GREY1E
	.long	RB2GREY1E,0
VRB2GREY1F
	.long	RB2GREY1F,0
VRB2RED1A
	.long	RB2RED1A,0
VRB2RED1B
	.long	RB2RED1B,0
VRB2RED1C
	.long	RB2RED1C,0
VRB2RED1D
	.long	RB2RED1D,0
VRB2RED1E
	.long	RB2RED1E,0
VRB2RED1F
	.long	RB2RED1F,0
VRB2RED1G
	.long	RB2RED1G,0

	.end
