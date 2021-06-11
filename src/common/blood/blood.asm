ÿ
blood_anims
	.long	a_face_blood
	.long	a_decap_spray
	.long	a_skinny_blood
	.long	a_bigger
	.long	a_drip
	.long	a_drip_splat
	.long	a_rotate_12
	.long	a_goro_arm
	.long	a_skull
	.long	a_rib_cage
	.long	a_bone
	.long	a_limb
	.long	a_leg2
	.long	a_leg
	.long	a_arm2
	.long	a_arm_land
	.long	a_arm
	.long	a_pork
	.long 	a_blood_explode
	.long	a_misc_blood
	
	
a_misc_blood
	.long	BIGBLD1
	.long	STAB1
	.long	0
	
;Fatality Blood

;****************************************************************
a_blood_explode
	.long	BLDXPD1
	.long	BLDXPD2
	.long	BLDXPD3
	.long	BLDXPD4
	.long	BLDXPD5
	.long	BLDXPD6
	.long	BLDXPD7
	.long	BLDXPD8
	.long	BLDXPD9
	.long	BLDXPD10
	.long	BLDXPD11
	.long	BLDXPD12
	.long	BLDXPD13
	.long	0

BLDXPD1
	.long	BLDXPD1A,BLDXPD1B,0
BLDXPD2
	.long	BLDXPD2A,BLDXPD2B,0
BLDXPD3
	.long	BLDXPD3A,BLDXPD3B,0
BLDXPD4
	.long	BLDXPD4A,BLDXPD4B,0
BLDXPD5
	.long	BLDXPD5A,BLDXPD5B,0
BLDXPD6
	.long	BLDXPD6A,BLDXPD6B,0
BLDXPD7
	.long	BLDXPD7A,BLDXPD7B,0
BLDXPD8
	.long	BLDXPD8A,BLDXPD8B,0
BLDXPD9
	.long	BLDXPD9A,BLDXPD9B,0
BLDXPD10
	.long	BLDXPD10A,BLDXPD10B,0
BLDXPD11
	.long	BLDXPD11A,BLDXPD11B,0
BLDXPD12
	.long	BLDXPD12A,BLDXPD12B,0
BLDXPD13
	.long	BLDXPD13A,BLDXPD13B,0

;****************************************************************
a_pork
	.long	PORK01
	.long	PORK02
	.long	PORK03
	.long	PORK04
	.long	PORK05
	.long	PORK06
	.long	PORK07
	.long	PORK08
	.long	PORK09
	.long	PORK10
	.long	PORK11
	.long	PORK12
	.long	ani_jump,a_pork

;****************************************************************
a_arm
	.long	ARM01
	.long	ARM02
	.long	ARM03
	.long	ARM04
	.long	ARM05
	.long	ARM06
	.long	ARM07
	.long	ARM08
	.long	ARM09
	.long	ARM10
	.long	ARM11
	.long	ARM12
	.long	ani_jump,a_arm,0

;****************************************************************
a_arm_land
	.long	ARM13
	.long	ARM14
	.long	ARM15
	.long	ARM16
	.long	ARM17
	.long	ARM18
	.long	ARM19
	.long	0

;****************************************************************
a_arm2
	.long	ARM_B01
	.long	ARM_B02
	.long	ARM_B03
	.long	ARM_B04
	.long	ARM_B05
	.long	ARM_B06
	.long	ARM_B07
	.long	ARM_B08
	.long	ARM_B09
	.long	ARM_B10
	.long	ARM_B11
	.long	ARM_B12
	.long	ani_jump,a_arm2
	.long	0

;****************************************************************
a_leg
	.long	LEG01
	.long	LEG02
	.long	LEG03
	.long	LEG04
	.long	LEG05
	.long	LEG06
	.long	LEG07
	.long	LEG08
	.long	LEG09
	.long	LEG10
	.long	LEG11
	.long	LEG12
	.long	ani_jump,a_leg

;****************************************************************
a_leg2
	.long	LEG_B01
	.long	LEG_B02
	.long	LEG_B03
	.long	LEG_B04
	.long	LEG_B05
	.long	LEG_B06
	.long	LEG_B07
	.long	LEG_B08
	.long	LEG_B09
	.long	LEG_B10
	.long	LEG_B11
	.long	LEG_B12
	.long	ani_jump,a_leg2
	.long	0

;****************************************************************
a_limb
	.long	XLIMB01
	.long	XLIMB02
	.long	XLIMB03
	.long	XLIMB04
	.long	XLIMB05
	.long	XLIMB06
	.long	XLIMB07
	.long	XLIMB08
	.long	XLIMB09
	.long	XLIMB10
	.long	XLIMB11
	.long	XLIMB12
	.long	ani_jump,a_limb
	.long	0

;****************************************************************
a_bone
	.long	BONE01
	.long	BONE02
	.long	BONE03
	.long	BONE04
	.long	BONE05
	.long	BONE06
	.long	BONE07
	.long	BONE08
	.long	BONE09
	.long	BONE10
	.long	BONE11
	.long	BONE12
;	.long	0,ani_jump,a_bone
	.long	ani_jump,a_bone

;****************************************************************
a_rib_cage
	.long	CAGE01
	.long	CAGE02
	.long	CAGE03
	.long	CAGE04
	.long	CAGE05
	.long	CAGE06
	.long	CAGE07
	.long	CAGE08
	.long	CAGE09
	.long	CAGE10
	.long	CAGE11
	.long	CAGE12
	.long	ani_jump,a_rib_cage

;****************************************************************
a_skull
	.long	SKULL01
	.long	SKULL02
	.long	SKULL03
	.long	SKULL04
	.long	SKULL05
	.long	SKULL06
	.long	SKULL07
	.long	SKULL08
	.long	SKULL09
	.long	SKULL10
	.long	SKULL11
	.long	SKULL12
	.long	ani_jump,a_skull

;****************************************************************
a_goro_arm
	.long	GOROARM02
	.long	GOROARM03
	.long	GOROARM04
	.long	GOROARM05
	.long	GOROARM06
	.long	GOROARM07
	.long	GOROARM08
	.long	GOROARM09
	.long	GOROARM10
	.long	GOROARM11
	.long	GOROARM12
	.long	ani_jump
	.long	a_goro_arm


;Normal Blood
a_face_blood
	.long SPLAT1
	.long SPLAT2
	.long SPLAT3
	.long SPLAT4
	.long SPLAT5
	.long SPLAT6
	.long SPLAT7
	.long 0

a_decap_spray
	.long SPRAY1
	.long SPRAY2
	.long SPRAY3
	.long SPRAY4
	.long SPRAY5
	.long SPRAY6
;	.long SPRAY7
	.long SPRAY8
	.long SPRAY9
	.long SPRAY10
	.long SPRAY11
	.long SPRAY12
	.long SPRAY13
	.long 0

a_skinny_blood
	.long SMDRIP1
	.long SMDRIP2
	.long SMDRIP3
	.long 0
	.long SMDRIP4
	.long SMDRIP5
	.long SMDRIP6
	.long SMDRIP7
	.long 0
	.long SMDRIP8
	.long SMDRIP9
	.long 0

a_bigger
	.long BIGGERBLUD1
	.long BIGGERBLUD1
	.long BIGGERBLUD2
	.long BIGGERBLUD2
	.long BIGGERBLUD3
	.long BIGGERBLUD4
	.long BIGGERBLUD5
	.long BIGGERBLUD6
	.long 0

a_drip
	.long DRIP1
	.long DRIP2
	.long DRIP3
	.long DRIP4
	.long 0

a_drip_splat
	.long DRIP5
	.long DRIP6
	.long DRIP7
	.long 0

a_rotate_12
	.long bludglob1
	.long bludglob2
	.long bludglob3
a_rotate_standard
	.long bludglob4
	.long bludglob5
a_rotate_9
	.long bludglob6
	.long bludglob7
	.long bludglob8
a_rotate_7
	.long bludglob9
	.long bludglob10
	.long bludglob11
	.long bludglob12
	.long 0




	.end