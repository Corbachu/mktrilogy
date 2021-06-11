;U64 Explosions and Smoke Animations (explode_atxt)

explode_anims
	.long	a_puff
	.long	a_dave_explode
	.long	a_ground_explode
	.long 	a_small_explode
	
a_small_explode
	.long	SMALLXPD1
	.long	SMALLXPD2
	.long	SMALLXPD3
	.long	SMALLXPD4
	.long	SMALLXPD5
	.long	SMALLXPD6
	.long	SMALLXPD7
	.long	SMALLXPD8
	.long	SMALLXPD9
	.long	SMALLXPD10
	.long	SMALLXPD11
	.long	SMALLXPD12
	.long	SMALLXPD13
	.long	SMALLXPD14
	.long	SMALLXPD15
	.long	0
	
a_ground_explode
	.long FLOORXPD1
	.long FLOORXPD3
	.long FLOORXPD5
	.long FLOORXPD7
	.long FLOORXPD9
	.long FLOORXPD11
	.long FLOORXPD13
	.long FLOORXPD19
	.long FLOORXPD21
	.long 0

a_puff
	.long	PUFF1
	.long	PUFF2
	.long	PUFF3
	.long	PUFF4
	.long	PUFF5
	.long	0

a_dave_explode
	.long	BIGXPLOD1
;	.long	BIGXPLOD2
	.long	BIGXPLOD3
;	.long	BIGXPLOD4
	.long	BIGXPLOD5
;	.long	BIGXPLOD6
	.long	BIGXPLOD7
;	.long	BIGXPLOD8
	.long	BIGXPLOD9
;	.long	BIGXPLOD10
	.long	BIGXPLOD11
;	.long	BIGXPLOD12
	.long	BIGXPLOD13
;	.long	BIGXPLOD14
	.long	BIGXPLOD15
;	.long	BIGXPLOD16
	.long	0

;	.long	BIGXPLOD16
	.long	BIGXPLOD15
;	.long	BIGXPLOD14
	.long	BIGXPLOD13
;	.long	BIGXPLOD12
	.long	BIGXPLOD11
;	.long	BIGXPLOD10
	.long	BIGXPLOD9
;	.long	BIGXPLOD8
	.long	BIGXPLOD7
;	.long	BIGXPLOD6
	.long	BIGXPLOD5
;	.long	BIGXPLOD4
	.long	BIGXPLOD3
;	.long	BIGXPLOD2
	.long	BIGXPLOD1
	.long	0

BIGXPLOD1
	.long	BIGXPLOD1A,0
BIGXPLOD2
	.long	BIGXPLOD2A,0
BIGXPLOD3
	.long	BIGXPLOD3A,0
BIGXPLOD4
	.long	BIGXPLOD4A,0
BIGXPLOD5
	.long	BIGXPLOD5A,0
BIGXPLOD6
	.long	BIGXPLOD6A,0
BIGXPLOD7
	.long	BIGXPLOD7A,0
BIGXPLOD8
	.long	BIGXPLOD8A,0
BIGXPLOD9
	.long	BIGXPLOD9A,0
BIGXPLOD10
	.long	BIGXPLOD10A,BIGXPLOD10B,0
BIGXPLOD11
	.long	BIGXPLOD11A,BIGXPLOD11B,0
BIGXPLOD12
	.long	BIGXPLOD12A,BIGXPLOD12B,0
BIGXPLOD13
	.long	BIGXPLOD13A,BIGXPLOD13B,0
BIGXPLOD14
	.long	BIGXPLOD14A,BIGXPLOD14B,0
BIGXPLOD15
	.long	BIGXPLOD15A,BIGXPLOD15B,0
BIGXPLOD16
	.long	BIGXPLOD16A,BIGXPLOD16B,0

	.end
