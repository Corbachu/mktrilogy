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

sz_list
	.long	VSZBLUE1A
	.long	VSZBLUE1B
	.long	VSZBLUE1C
	.long	VSZBLUE1D
	.long	VSZFLESH1A
	.long	VSZFLESH1B
	.long	VSZFLESH1C
	.long	VSZFLESH1D
	.long	VSZFLESH1E
	.long	VSZFLESH1F
	.long	VSZFLESH1G
	.long	VSZFLESH1H
	.long	VSZGREY1A
	.long	VSZGREY1B
	.long	VSZGREY1C
	.long	VSZGREY1D
	.long	VSZGREY1E
	.long	VSZGREY1F
	.long	VSZGREY1G



VSZBLUE1A
	.long	SZBLUE1A,0
VSZBLUE1B
	.long	SZBLUE1B,0
VSZBLUE1C
	.long	SZBLUE1C,0
VSZBLUE1D
	.long	SZBLUE1D,0
VSZFLESH1A
	.long	SZFLESH1A,0
VSZFLESH1B
	.long	SZFLESH1B,0
VSZFLESH1C
	.long	SZFLESH1C,0
VSZFLESH1D
	.long	SZFLESH1D,0
VSZFLESH1E
	.long	SZFLESH1E,0
VSZFLESH1F
	.long	SZFLESH1F,0
VSZFLESH1G
	.long	SZFLESH1G,0
VSZFLESH1H
	.long	SZFLESH1H,0
VSZGREY1A
	.long	SZGREY1A,0
VSZGREY1B
	.long	SZGREY1B,0
VSZGREY1C
	.long	SZGREY1C,0
VSZGREY1D
	.long	SZGREY1D,0
VSZGREY1E
	.long	SZGREY1E,0
VSZGREY1F
	.long	SZGREY1F,0
VSZGREY1G
	.long	SZGREY1G,0

	.end
	