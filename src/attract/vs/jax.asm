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

jax_list
	.long	VJXFLESH1A
	.long	VJXPURP1A
	.long	VJXPURP1B
	.long	VJXGRY1A
	.long	VJXGRY1B
	.long	VJXGRY1C


VJXFLESH1A	
	.long	JXFLESH1A,0
VJXPURP1A	
	.long	JXPURP1A,0
VJXPURP1B	
	.long	JXPURP1B,0
VJXGRY1A	
	.long	JXGRY1A,0
VJXGRY1B	
	.long	JXGRY1B,0
VJXGRY1C
	.long	JXGRY1C,0


	.end
	