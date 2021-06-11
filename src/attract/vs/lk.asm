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

lk_list
	.long	VLKFLESH1A
	.long	VLKFLESH1B
	.long	VLKFLESH1C
	.long	VLKFLESH1D
	.long	VLKFLESH1E
	.long	VLKGREY1A
	.long	VLKGREY1B
	.long	VLKGREY1C
	.long	VLKGREY1D
	.long	VLKGREY1E
	.long	VLKRED1A
	.long	VLKRED1B
	.long	VLKRED1C

VLKFLESH1A
	.long	LKFLESH1A,0
VLKFLESH1B
	.long	LKFLESH1B,0
VLKFLESH1C
	.long	LKFLESH1C,0
VLKFLESH1D
	.long	LKFLESH1D,0
VLKFLESH1E
	.long	LKFLESH1E,0
VLKGREY1A
	.long	LKGREY1A,0
VLKGREY1B
	.long	LKGREY1B,0
VLKGREY1C
	.long	LKGREY1C,0
VLKGREY1D
	.long	LKGREY1D,0
VLKGREY1E
	.long	LKGREY1E,0
VLKRED1A
	.long	LKRED1A,0
VLKRED1B
	.long	LKRED1B,0
VLKRED1C
	.long	LKRED1C,0

	.end
	