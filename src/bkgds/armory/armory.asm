;U64 armory/lair/tomb anims (armor_atxt)
armory_anims
;Tomb
	.long	a_medbat
	.long	a_smallbat
	.long	a_spikes
;Armory
	.long	a_lava


;Armory
a_lava
	.long LAVA1
	.long LAVA2
	.long LAVA3
	.long LAVA4
	.long LAVA5
	.long LAVA6
	.long LAVA7
	.long LAVA8
	.long LAVA9
	.long LAVA10
	.long LAVA11
	.long LAVA12
	.long 0

;Tomb
a_spikes
	.long	spikes
	.long	0
	.long	spikeroof2
	.long	0
		
a_medbat
	.long	MEDBAT1
	.long	MEDBAT2
	.long	MEDBAT3
	.long	MEDBAT4
	.long	MEDBAT5
	.long	MEDBAT6
	.long	MEDBAT7
	.long	MEDBAT8
	.long	ani_jump,a_medbat

	global a_smallbat
a_smallbat
	.long	SMBAT1
	.long	SMBAT2
	.long	SMBAT3
	.long	SMBAT4
	.long	SMBAT5
	.long	SMBAT6
	.long	SMBAT7
	.long	SMBAT8
	.long	ani_jump,a_smallbat


	.end
	