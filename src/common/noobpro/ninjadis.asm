**************************************************************************
*											     *
*  mk3 - disapate					*
*											     *
**************************************************************************

	.FILE	'mk3disapate.ASM'
	.WIDTH	132
	.OPTION	B,D,L,T
	.MNOLIST

	.text
disapate_anims
	.long	a_noob

a_noob
	.long	GHOSTCPLOOP1
	.long	GHOSTCPLOOP2
	.long	GHOSTCPLOOP3
	.long	GHOSTCPLOOP4
	.long	GHOSTDISP1
	.long	GHOSTDISP2
	.long	GHOSTDISP3
	.long	0



	.end
