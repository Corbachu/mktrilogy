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

swat_list
	.long	VCOPBLUE1A
	.long	VCOPBLUE1B
	.long	VCOPBLUE1C
	.long	VCOPFLESH1A
	.long	VCOPFLESH1B
	.long	VCOPFLESH1C
	.long	VCOPFLESH1D
	.long	VCOPGREY1A
	.long	VCOPGREY1B
	.long	VCOPGREY1C
	.long	VCOPGREY1D

VCOPBLUE1A
	.long	COPBLUE1A,0
VCOPBLUE1B
	.long	COPBLUE1B,0
VCOPBLUE1C
	.long	COPBLUE1C,0
VCOPFLESH1A
	.long	COPFLESH1A,0
VCOPFLESH1B
	.long	COPFLESH1B,0
VCOPFLESH1C
	.long	COPFLESH1C,0
VCOPFLESH1D
	.long	COPFLESH1D,0
VCOPGREY1A
	.long	COPGREY1A,0
VCOPGREY1B
	.long	COPGREY1B,0
VCOPGREY1C
	.long	COPGREY1C,0
VCOPGREY1D
	.long	COPGREY1D,0


	.end
	