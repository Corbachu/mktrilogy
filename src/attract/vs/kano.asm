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

kano_list
	.long	VBGKANO1A
	.long	VBGKANO1B
	.long	VBGKANO1C
	.long	VBGKANO1D
	.long	VBGKANO2A
	.long	VBGKANO2B
	.long	VBGKANO2C
	.long	VBGKANO2D
	.long	VBGKANO2E
	.long	VBGKANO3A
	.long	VBGKANO3B
	.long	VBGKANO3C
	.long	VBGKANO3D
	.long	VBGKANO4A
VBGKANO1A
	.long	BGKANO1A,0
VBGKANO1B	
	.long	BGKANO1B,0
VBGKANO1C	
	.long	BGKANO1C,0
VBGKANO1D	
	.long	BGKANO1D,0
VBGKANO2A
	.long	BGKANO2A,0
VBGKANO2B
	.long	BGKANO2B,0
VBGKANO2C
	.long	BGKANO2C,0
VBGKANO2D
	.long	BGKANO2D,0
VBGKANO2E
	.long	BGKANO2E,0
VBGKANO3A	
	.long	BGKANO3A,0
VBGKANO3B	
	.long	BGKANO3B,0
VBGKANO3C	
	.long	BGKANO3C,0
VBGKANO3D
	.long	BGKANO3D,0
VBGKANO4A
	.long	BGKANO4A,0




	.end
	
	