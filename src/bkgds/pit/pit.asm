;U64 Pit Background Animations
pit_anims
	.long a_saw
	.long a_wall

a_saw
;	.long SAW1-pit_anims
	.long SAW2-pit_anims
;	.long SAW3-pit_anims
	.long SAW4-pit_anims
;	.long SAW5-pit_anims
	.long SAW6-pit_anims
	.long 0
	
a_wall
	.long	THRONEWALL
	.long	0
	
	
	.end

