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

sonya_list
	.long	VBGSONYA1A
	.long	VBGSONYA1B
	.long	VBGSONYA1C
	.long	VBGSONYA1D
	.long	VBGSONYA1E
	.long	VBGSONYA1F
	.long	VBGSONYA2A
	.long	VBGSONYA2B
	.long	VBGSONYA2C
	.long	VBGSONYA2D
	.long	VBGSONYA3A
	.long	VBGSONYA3B
	.long	VBGSONYA3C
	.long	VBGSONYA3D
	.long	VBGSONYA3E
	.long	VBGSONYA3F
	.long	VBGSONYA3G

VBGSONYA1A	
	.long	BGSONYA1A,0
VBGSONYA1B	
	.long	BGSONYA1B,0
VBGSONYA1C	
	.long	BGSONYA1C,0
VBGSONYA1D	
	.long	BGSONYA1D,0
VBGSONYA1E	
	.long	BGSONYA1E,0
VBGSONYA1F
	.long	BGSONYA1F,0
VBGSONYA2A	
	.long	BGSONYA2A,0
VBGSONYA2B	
	.long	BGSONYA2B,0
VBGSONYA2C	
	.long	BGSONYA2C,0
VBGSONYA2D
	.long	BGSONYA2D,0
VBGSONYA3A	
	.long	BGSONYA3A,0
VBGSONYA3B	
	.long	BGSONYA3B,0
VBGSONYA3C	
	.long	BGSONYA3C,0
VBGSONYA3D	
	.long	BGSONYA3D,0
VBGSONYA3E	
	.long	BGSONYA3E,0
VBGSONYA3F	
	.long	BGSONYA3F,0
VBGSONYA3G
	.long	BGSONYA3G,0

	.end
	