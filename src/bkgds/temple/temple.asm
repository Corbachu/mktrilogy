;U64 Temple background anaimations (temple_atxt)

temple_anims
	.long	a_tflame
	.long	a_candle_flame
	.long	a_kandle
	
a_kandle
	.long	KANDLE1
	.long	0
	
	.globl a_tflame
a_tflame
	.long SKTORCH1
	.long SKTORCH2
	.long SKTORCH3
	.long SKTORCH4
	.long SKTORCH5
	.long SKTORCH6
	.long ani_jump
	.long a_tflame

	.globl a_candle_flame
a_candle_flame
	.long wik1
	.long wik2
	.long wik3
	.long wik4
	.long ani_jump
	.long a_candle_flame

	
	.end