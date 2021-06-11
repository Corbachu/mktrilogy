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

ind_list
	.long	VINGRY1A
	.long	VINGRY1B
	.long	VINGRY1C
	.long	VINGRY1D
	.long	VINGRY1E
	.long	VINBLU1A
	.long	VINBLU1B
	.long	VINBLU1C
	.long	VINBLU1D
	.long	VINSKIN1A
	.long	VINSKIN1B
	.long	VINSKIN1C
	.long	VINSKIN1D
	.long	VINSKIN1E
	.long	VINSKIN1F
	.long	VINSKIN1G


VINGRY1A	
	.long	INGRY1A,0
VINGRY1B	
	.long	INGRY1B,0
VINGRY1C	
	.long	INGRY1C,0
VINGRY1D	
	.long	INGRY1D,0
VINGRY1E	
	.long	INGRY1E,0
VINBLU1A	
	.long	INBLU1A,0
VINBLU1B	
	.long	INBLU1B,0
VINBLU1C	
	.long	INBLU1C,0
VINBLU1D	
	.long	INBLU1D,0
VINSKIN1A	
	.long	INSKIN1A,0
VINSKIN1B	
	.long	INSKIN1B,0
VINSKIN1C	
	.long	INSKIN1C,0
VINSKIN1D	
	.long	INSKIN1D,0
VINSKIN1E	
	.long	INSKIN1E,0
VINSKIN1F	
	.long	INSKIN1F,0
VINSKIN1G	
	.long	INSKIN1G,0

	.end
	