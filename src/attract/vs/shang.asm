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

shang_list
	.long	VTSFLESH1A
	.long	VTSFLESH1B
	.long	VTSFLESH1C
	.long	VTSFLESH1D
	.long	VTSFLESH1E
	.long	VTSGREY1A
	.long	VTSGREY1B
	.long	VTSGREY1C
	.long	VTSGREY1D
	.long	VTSGREY1E
	.long	VTSPANT1A
	.long	VTSPANT1B


VTSFLESH1A
	.long	TSFLESH1A,0
VTSFLESH1B
	.long	TSFLESH1B,0
VTSFLESH1C
	.long	TSFLESH1C,0
VTSFLESH1D
	.long	TSFLESH1D,0
VTSFLESH1E
	.long	TSFLESH1E,0
VTSGREY1A
	.long	TSGREY1A,0
VTSGREY1B
	.long	TSGREY1B,0
VTSGREY1C
	.long	TSGREY1C,0
VTSGREY1D
	.long	TSGREY1D,0
VTSGREY1E
	.long	TSGREY1E,0
VTSPANT1A
	.long	TSPANT1A,0
VTSPANT1B
	.long	TSPANT1B,0

	.end
