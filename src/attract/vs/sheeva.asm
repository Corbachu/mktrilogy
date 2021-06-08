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

sheeva_list
	.long	VSHFLESH1A
	.long	VSHFLESH1B
	.long	VSHFLESH1C
	.long	VSHFLESH1D
	.long	VSHFLESH1E
	.long	VSHFLESH1F
	.long	VSHFLESH1G
	.long	VSHFLESH1H
	.long	VSHFLESH1I
	.long	VSHGREY1A
	.long	VSHGREY1B
	.long	VSHGREY1C
	.long	VSHGREY1D
	.long	VSHGREY1E
	.long	VSHGREY1F
	.long	VSHGREY1G
	.long	VSHRED1A
	.long	VSHRED1B
	.long	VSHRED1C
	.long	VSHRED1D


VSHFLESH1A
	.long	SHFLESH1A,0
VSHFLESH1B
	.long	SHFLESH1B,0
VSHFLESH1C
	.long	SHFLESH1C,0
VSHFLESH1D
	.long	SHFLESH1D,0
VSHFLESH1E
	.long	SHFLESH1E,0
VSHFLESH1F
	.long	SHFLESH1F,0
VSHFLESH1G
	.long	SHFLESH1G,0
VSHFLESH1H
	.long	SHFLESH1H,0
VSHFLESH1I
	.long	SHFLESH1I,0
VSHGREY1A
	.long	SHGREY1A,0
VSHGREY1B
	.long	SHGREY1B,0
VSHGREY1C
	.long	SHGREY1C,0
VSHGREY1D
	.long	SHGREY1D,0
VSHGREY1E
	.long	SHGREY1E,0
VSHGREY1F
	.long	SHGREY1F,0
VSHGREY1G
	.long	SHGREY1G,0
VSHRED1A
	.long	SHRED1A,0
VSHRED1B
	.long	SHRED1B,0
VSHRED1C
	.long	SHRED1C,0
VSHRED1D
	.long	SHRED1D,0

	.end
	