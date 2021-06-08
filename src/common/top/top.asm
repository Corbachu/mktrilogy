**************************************************************************
*											     *
*  mktop					*
*											     *
**************************************************************************

	.FILE	'mktop.ASM'
	.WIDTH	132
	.OPTION	B,D,L,T
	.MNOLIST

	.text
top_anims
	.long	a_top
	.long	a_topout

a_top
	.long	TOP1
	.long	TOP2
	.long	TOP3
	.long	TOP4
	.long	TOP5
	.long	TOP6
	.long	0

a_topout
	.long	TOPOUT1
	.long	TOPOUT2
	.long	TOPOUT3
	.long	TOPOUT4
	.long	TOPOUT5
	.long	TOPOUT6
	.long	TOPOUT7
	.long	0


	.end
