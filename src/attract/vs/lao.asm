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

lao_list
	.long	VKLFLESH1A
	.long	VKLFLESH1B
	.long	VKLFLESH1C
	.long	VKLFLESH1D
	.long	VKLFLESH1E
	.long	VKLGREY1A
	.long	VKLGREY1B
	.long	VKLGREY1C
	.long	VKLGREY1D
	.long	VKLGREY1E
	.long	VKLGREY1F
	.long	VKLGREY1G
	.long	VKLPANTS1A
	.long	VKLPANTS1B


VKLFLESH1A
	.long	KLFLESH1A,0
VKLFLESH1B
	.long	KLFLESH1B,0
VKLFLESH1C
	.long	KLFLESH1C,0
VKLFLESH1D
	.long	KLFLESH1D,0
VKLFLESH1E
	.long	KLFLESH1E,0
VKLGREY1A
	.long	KLGREY1A,0
VKLGREY1B
	.long	KLGREY1B,0
VKLGREY1C
	.long	KLGREY1C,0
VKLGREY1D
	.long	KLGREY1D,0
VKLGREY1E
	.long	KLGREY1E,0
VKLGREY1F
	.long	KLGREY1F,0
VKLGREY1G
	.long	KLGREY1G,0
VKLPANTS1A
	.long	KLPANTS1A,0
VKLPANTS1B
	.long	KLPANTS1B,0

	.end
	