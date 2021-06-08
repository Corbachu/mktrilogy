**************************************************************************
*											     *
*  mk3 - kentart.asm										*
*											     *
**************************************************************************

	.FILE	'kentart.ASM'
	.WIDTH	132
	.OPTION	B,D,L,T
	.MNOLIST

	.text

kentart_anims
	.long 	a_expld
	.long	a_ship
	.long	a_enemy

a_expld
	.long	expld1
	.long	expld2
	.long	expld3
	.long	expld4
	.long	expld5
	.long	expld6
	.long	expld7
	.long	expld8

	.long	0

a_ship
	.long	ship1
	.long	ship2
	.long	ship3
	.long	ship4

	.long	0

a_enemy
	.long enemy1
	.long enemy2
	.long enemy3
	.long enemy4
	.long enemy5
	.long enemy6
	.long enemy7
	.long enemy8
	.long enemy9
	.long enemy10

	.long	0


	.end
