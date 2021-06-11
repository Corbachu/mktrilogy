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

tusk_list
	.long	VKBFLESH1A
	.long	VKBFLESH1B
	.long	VKBFLESH1C
	.long	VKBFLESH1D
	.long	VKBFLESH1E
	.long	VKBGRVEST1A
	.long	VKBGRVEST1B
	.long	VKBGRVEST1C
	.long	VKBGRVEST1D
	.long	VKBGRVEST1E
	.long	VKBPANTS1A
	.long	VKBPANTS1B

VKBFLESH1A
	.long	KBFLESH1A,0
VKBFLESH1B
	.long	KBFLESH1B,0
VKBFLESH1C
	.long	KBFLESH1C,0
VKBFLESH1D
	.long	KBFLESH1D,0
VKBFLESH1E
	.long	KBFLESH1E,0
VKBGRVEST1A
	.long	KBGRVEST1A,0
VKBGRVEST1B
	.long	KBGRVEST1B,0
VKBGRVEST1C
	.long	KBGRVEST1C,0
VKBGRVEST1D
	.long	KBGRVEST1D,0
VKBGRVEST1E
	.long	KBGRVEST1E,0
VKBPANTS1A
	.long	KBPANTS1A,0
VKBPANTS1B
	.long	KBPANTS1B,0


	.end
