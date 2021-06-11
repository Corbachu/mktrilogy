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

lia_list
	.long	VLIAFLESH1A
	.long	VLIAFLESH1B
	.long	VLIAFLESH1C
	.long	VLIAFLESH1D
	.long	VLIAFLESH1E
	.long	VLIAGREY1A
	.long	VLIAGREY1B
	.long	VLIAGREY1C
	.long	VLIAPURP1A
	.long	VLIAPURP1B

VLIAFLESH1A
	.long	LIAFLESH1A,0
VLIAFLESH1B
	.long	LIAFLESH1B,0
VLIAFLESH1C
	.long	LIAFLESH1C,0
VLIAFLESH1D
	.long	LIAFLESH1D,0
VLIAFLESH1E
	.long	LIAFLESH1E,0
VLIAGREY1A
	.long	LIAGREY1A,0
VLIAGREY1B
	.long	LIAGREY1B,0
VLIAGREY1C
	.long	LIAGREY1C,0
VLIAPURP1A
	.long	LIAPURP1A,0
VLIAPURP1B
	.long	LIAPURP1B,0

	.end
	