/******************************************************************************
 File: mkdma.h

 By: David Schwartz

 Date: Feb 1996

 (C) Williams Entertainment

 Mortal Kombat III DMA Header
******************************************************************************/

#ifndef __mk_mkdma_h__
#define __mk_mkdma_h__

/*
 * 	DEFINITIONS
 */


//================================================================================================
/* U64 overlay system */
struct sys_ovdirentry {	// overlay directory entry:
	u32	romstart;		// overlay's start address in ROM
	u32	romend;			// overlay's end address in ROM (one byte past end)
	u32	vstart;			// overlay's start virtual address
	u32	vend;			// overlay's end virtual address
	u32	bss_start;		// overlay's bss start virtual address
	u32	bss_end;		// overlay's bss end virtual address
};

//================================================================================================
// Append to this enum:

enum {							// overlay id definitions
	SYS_CITY_OVL,
	SYS_ARMOR_OVL,
	SYS_BATTLE_OVL,
	SYS_BELL_OVL,
	SYS_BRIDGE_OVL,
	SYS_CAVE_OVL,
	SYS_KUNGFU2_OVL,
	SYS_KUNGFU5_OVL,
	SYS_DEAD_OVL,
	SYS_DESERT_OVL,
	SYS_GRAVE_OVL,
	SYS_HPORT_OVL,
	SYS_LOST_OVL,
	SYS_MK2PIT_OVL,
	SYS_MONK_OVL,
	SYS_PIT_OVL,
	SYS_SBST_OVL,
	SYS_SOUL_OVL,
	SYS_TEMPLE_OVL,
	SYS_TOWER_OVL,
	SYS_TREE_OVL,
	SYS_WATER_OVL,
	SYS_BUYIN_OVL,
	SYS_SELECT_OVL,
	SYS_GRAD_OVL,
	SYS_OPTION_OVL,
	SYS_TITLE_OVL,
	SYS_VSPLAY_OVL,
	SYS_STEEL_OVL,
	SYS_PONG_OVL,
	SYS_MARK_OVL,
	SYS_STORM_OVL,
	SYS_NUM_OVERLAYS			// always leave this in the last enum position
};

#define NULL_OVERLAY	0xffff			// indicates no overlay to load for level
//================================================================================================
/* special -ality overlay loads must match special_character_textures */
enum 
{ 
	SPEC_IND_FRIEND,
	SPEC_IND_ANIMAL,
	SPEC_R1_ANIMAL,
	SPEC_R3_ANIMAL,
	SPEC_R1F1_FATAL,
	SPEC_R1F2_FATAL,
	SPEC_R2F1_FATAL,
	SPEC_R2F2_FATAL,
	SPEC_R3F1_FATAL,
	SPEC_R3F2_FATAL,
	SPEC_NJ_ANIMAL,
	SPEC_NJ_FRIEND,
	SPEC_NJ_SCF1,
	SPEC_ROBO_FRIEND,
	SPEC_R2_ANIMAL,
	SPEC_FN_FRIEND,
	SPEC_FN_MLF1,
	SPEC_IND_F2,
	SPEC_LIA_ANIMAL,
	SPEC_NJ_RPF1,
	SPEC_NJ_RPF2,
	SPEC_ST_ANIMAL,
	SPEC_TUSK_ANIMAL,
	SPEC_TUSK_F2,
	SPEC_NJ_SCF2,

	SPEC_NUM_FATALS			// always leave last
};

//================================================================================================

#define SYS_OVEXTERN( name )											\
	extern char _##name##SegmentRomStart[], _##name##SegmentRomEnd[];	\
	extern char _##name##SegmentStart[], _##name##SegmentEnd[];			\
	extern char _##name##SegmentBssStart[], _##name##SegmentBssEnd[];	\
	extern char _##name##SegmentTextStart[], _##name##SegmentTextEnd[];	\
	extern char _##name##SegmentDataStart[], _##name##SegmentDataEnd[]

#define SYS_OTEXTERN( name )											\
	extern char _##name##SegmentRomStart[], _##name##SegmentRomEnd[]	

#define SYS_EXTERN( name )	\
	SYS_OVEXTERN( name##cod##); \
	SYS_OTEXTERN( name##txt##) 

#define SYS_CEXTERN( name )	\
	SYS_OVEXTERN( name); \
	SYS_OTEXTERN( name) 

//================================================================================================
// Append to this list (CREATE EXTERNALS):
SYS_EXTERN(city);
SYS_EXTERN(armor);
SYS_EXTERN(battle);
SYS_EXTERN(bell);
SYS_EXTERN(bridge);
SYS_EXTERN(cave);
SYS_EXTERN(dead);
SYS_EXTERN(desert);
SYS_EXTERN(grave);
SYS_EXTERN(hport);
SYS_EXTERN(lost);
SYS_EXTERN(mk2pit);
SYS_EXTERN(monk);
SYS_EXTERN(pit);
SYS_EXTERN(sbst);
SYS_EXTERN(soul);
SYS_EXTERN(temple);
SYS_EXTERN(tower);
SYS_EXTERN(tree);
SYS_EXTERN(water);
SYS_EXTERN(kung2);
SYS_EXTERN(kung5);
SYS_EXTERN(buyin);
SYS_EXTERN(select);
SYS_EXTERN(steel);
SYS_CEXTERN(ponggame);
SYS_CEXTERN(markgame);
SYS_CEXTERN(stormdata);
SYS_EXTERN(grad);
SYS_EXTERN(option);
SYS_EXTERN(title);
SYS_EXTERN(vsplay);

SYS_OTEXTERN(fninjaziptxt);
SYS_OTEXTERN(indianziptxt);
SYS_OTEXTERN(jaxziptxt);
SYS_OTEXTERN(kanoziptxt);
SYS_OTEXTERN(laoziptxt);
SYS_OTEXTERN(liaziptxt);
SYS_OTEXTERN(lkziptxt);
SYS_OTEXTERN(mninjaziptxt);
SYS_OTEXTERN(roboziptxt);
SYS_OTEXTERN(shangziptxt);
SYS_OTEXTERN(sheevaziptxt);
SYS_OTEXTERN(sonyaziptxt);
SYS_OTEXTERN(swatziptxt);
SYS_OTEXTERN(jcziptxt);
SYS_OTEXTERN(tuskziptxt);
SYS_OTEXTERN(nuguysziptxt);


SYS_OTEXTERN(sonyatxt);
SYS_OTEXTERN(sonyadct);
SYS_OTEXTERN(roboftxt);
SYS_OTEXTERN(robo2atxt);
SYS_OTEXTERN(robo3atxt);
SYS_OTEXTERN(robo1atxt);
SYS_OTEXTERN(robo1f1txt);
SYS_OTEXTERN(robo1f2txt);
SYS_OTEXTERN(robo2f1txt);
SYS_OTEXTERN(robo2f2txt);
SYS_OTEXTERN(robo3f1txt);
SYS_OTEXTERN(robo3f2txt);
SYS_OTEXTERN(robotxt);
SYS_OTEXTERN(robodct);
SYS_OTEXTERN(tusktxt);
SYS_OTEXTERN(tuskatxt);
SYS_OTEXTERN(tuskf2txt);
SYS_OTEXTERN(tuskdct);
SYS_OTEXTERN(jcagetxt);
SYS_OTEXTERN(jcagedct);
SYS_OTEXTERN(swattxt);
SYS_OTEXTERN(swatdct);
SYS_OTEXTERN(sheevatxt);
SYS_OTEXTERN(sheevadct);
SYS_OTEXTERN(fntxt);
SYS_OTEXTERN(fnmlf1txt);
SYS_OTEXTERN(fnatxt);
SYS_OTEXTERN(fnftxt);
SYS_OTEXTERN(fndct);
SYS_OTEXTERN(nj64txt);
SYS_OTEXTERN(nj64dct);
SYS_OTEXTERN(njtxt);
SYS_OTEXTERN(njatxt);
SYS_OTEXTERN(njftxt);
SYS_OTEXTERN(njscf1txt);
SYS_OTEXTERN(njscf2txt);
SYS_OTEXTERN(njrpf1txt);
SYS_OTEXTERN(njrpf2txt);
SYS_OTEXTERN(njdct);
SYS_OTEXTERN(lktxt);
SYS_OTEXTERN(lkdct);
SYS_OTEXTERN(laotxt);
SYS_OTEXTERN(laodct);
SYS_OTEXTERN(liatxt);
SYS_OTEXTERN(liaatxt);
SYS_OTEXTERN(liadct);
SYS_OTEXTERN(kanotxt);
SYS_OTEXTERN(kanodct);
SYS_OTEXTERN(jaxtxt);
SYS_OTEXTERN(jaxdct);
SYS_OTEXTERN(indian64txt);
SYS_OTEXTERN(indian64dct);
SYS_OTEXTERN(indiantxt);
SYS_OTEXTERN(indiandct);
SYS_OTEXTERN(indianatxt);
SYS_OTEXTERN(indianftxt);
SYS_OTEXTERN(indianf2txt);
SYS_OTEXTERN(satxt);
SYS_OTEXTERN(sadct);
SYS_OTEXTERN(mottxt);
SYS_OTEXTERN(motdct);
SYS_OTEXTERN(sttxt);
SYS_OTEXTERN(statxt);
SYS_OTEXTERN(stdct);
SYS_OTEXTERN(sktxt);
SYS_OTEXTERN(sksziptxt);
SYS_OTEXTERN(motsziptxt);
SYS_OTEXTERN(skdct);
SYS_OTEXTERN(rdtxt);
SYS_OTEXTERN(rddct);

//================================================================================================
#define SYS_OVENTRY( name ) {	\
	(u32)_##name##codSegmentRomStart,		\
	(u32)_##name##codSegmentRomEnd,		\
	(u32)_##name##codSegmentStart,			\
	(u32)_##name##codSegmentEnd,			\
	(u32)_##name##codSegmentBssStart,		\
	(u32)_##name##codSegmentBssEnd			\
}

#define SYS_OVTENTRY( name ) {	\
	(u32)_##name##txtSegmentRomStart,		\
	(u32)_##name##txtSegmentRomEnd,		\
	(u32)_##name##txtSegmentStart,			\
	(u32)_##name##txtSegmentEnd,			\
}

#define SYS_OTENTRY( name ) { \
	(u32)_##name##txtSegmentRomStart,		\
	(u32)_##name##txtSegmentRomEnd		\
}

#define SYS_OCENTRY( name ) {	\
	(u32)_##name##SegmentRomStart,		\
	(u32)_##name##SegmentRomEnd,		\
	(u32)_##name##SegmentStart,			\
	(u32)_##name##SegmentEnd,			\
	(u32)_##name##SegmentBssStart,		\
	(u32)_##name##SegmentBssEnd			\
}


#define SYS_ODENTRY( name ) { \
	(u32)_##name##dctSegmentRomStart,		\
	(u32)_##name##dctSegmentRomEnd		\
}

//================================================================================================
/* special end of figght fxs load */
#define FX_FATAL_LOAD 0
#define FX_ANIMAL_LOAD 1
#define FX_FRIEND_LOAD 2
#define FX_BABY_LOAD 3
#define FX_FIGHT_LOAD 4
#define FX_FINHIM_LOAD 5
#define FX_FINHER_LOAD 6
#define FX_MERCY_LOAD  7
#define FX_MUGS_LOAD	8
#define FX_TOP_LOAD	9
#define FX_SKEL_LOAD	10
#define FX_RIPS_LOAD	11
#define FX_LOGO_LOAD	12
#define FX_BRUTAL_LOAD	13
#define FX_SKDIE_LOAD	14

#define FX_NO_LOAD	0xff

SYS_OVEXTERN(brutaltxt);
SYS_OVEXTERN(fataltxt);
SYS_OVEXTERN(animaltxt);
SYS_OVEXTERN(friendtxt);
SYS_OVEXTERN(babytxt);
SYS_OVEXTERN(fighttxt);
SYS_OVEXTERN(finhimtxt);
SYS_OVEXTERN(finhertxt);
SYS_OVEXTERN(mercytxt);
SYS_OVEXTERN(mugstxt);
SYS_OVEXTERN(skdietxt);
SYS_OVEXTERN(toptxt);
SYS_OVEXTERN(skeltxt);
SYS_OVEXTERN(ripstxt);
SYS_OVEXTERN(logotxt);

__EXTERN__ WORD f_top_load;		// set if top art is loaded
__EXTERN__ WORD f_skel_load;	// set if skeleton art loaded
__EXTERN__ WORD f_rips_load;	// set if rips skel art loaded

//================================================================================================
/* level textures & code file index */
#define LVL_NONE			0xff
#define LVL_SUBWAY_STREET	0
#define LVL_MK2PIT			1
#define LVL_BALCONY			3
#define LVL_SOUL			3
#define LVL_BRIDGE			4
#define LVL_BELL			5
#define LVL_TEMPLE			6
#define LVL_GRAVE			7
#define LVL_PIT				8
#define LVL_WATER			9
#define LVL_HADES_CAVE		10
#define LVL_DESERT			11
#define LVL_BUYIN			12
#define LVL_LOST			13
#define LVL_PORTAL 			14
#define LVL_HSCORE			LVL_VERSE
#define LVL_LADDER			LVL_SELECT
#define LVL_VERSE			17
#define LVL_COIN			18
#define LVL_FIRE			LVL_SELECT
#define LVL_GRADIENT		20
#define LVL_TITLE			21
#define LVL_SELECT			22
#define LVL_OPTIONS			23
#define LVL_OPTTEXT			24
#define LVL_CONTROL			25
#define LVL_FONTS			26
#define LVL_LOADING			27
#define LVL_SKEND			28
#define LVL_MOCKPIT			29
#define LVL_DTEAM			30
#define LVL_DEADPOOL		31
#define LVL_BATTLE			32
#define LVL_CITY			33
#define LVL_ARMORY			34
#define LVL_LAIR_ARMORY_TOMB	LVL_ARMORY
#define LVL_FOREST			35
#define LVL_TOWER			36
#define LVL_MONK			37
#define LVL_LIAR			38		
#define LVL_TOMB			39
#define LVL_TOURN			40
#define LVL_KUNG2			41
#define LVL_KUNG5			42

//================================================================================================
typedef struct ovl
{
	char **ovl_addr;
	char *ovl_file;
} OVL;

/* segment load structure */
typedef struct 
{ 
	u32 segl_start;
	u32 segl_end;
} SEGL;

typedef int File_IO_Struct;


//================================================================================================
/* character data type */
#define CHAR_NORMAL	0
#define CHAR_SELECT 1
#define CHAR_INTRO	2
#define CHAR_SHANG	3
#define CHAR_ENDING 4

#define BUCKET_COUNT	8
#define BUCKET_SIZE	((PLAYER_HEAP_SIZE/BUCKET_COUNT) & 0xfffffc00)

#define END_BUCKET_COUNT	20
#define END_BUCKET_SIZE		((PLAYER_HEAP_SIZE/END_BUCKET_COUNT) & 0xfffffc00)

#define INTRO_BUCKET_SIZE	100000


#define CHAR_BABY   0
#define CHAR_ANIMAL 2
#define CHAR_FRIEND 3
#define CHAR_FATAL1  4
#define CHAR_FATAL2  5
#define CHAR_VS  6


//================================================================================================
/* special character loads */
#define NO_FILE					0xffff					// EQUIVALENT TO NULL
#define CHAR_SPECIAL_1			0xfff1					// KANO SKEL REACH
#define CHAR_SPECIAL_2			0xfff2					// LIA SKIN RIP
#define CHAR_SPECIAL_3			0xfff3					// KABAL INFLATE
#define CHAR_SPECIAL_4			0xfff4					// SHEEVA SKIN RIP
#define CHAR_SPECIAL_5			0xfff5					// SHANG FLOAT
#define CHAR_SPECIAL_6			0xfff6					// SMOKE ARM BOMB
#define CHAR_SPECIAL_7			0xfff7

//================================================================================================
/* load types */
#define SYNC_LOAD	0x0000			// normal sync load
#define ASYNC_LOAD 	0x0001			// async load
#define FATAL_LOAD	0x0002			// load at dest-length addr

//================================================================================================
/* generic overlay indexs, overlays for various stuff */
#define OVL_SELECT	0x00					// select screen fighter data
#define OVL_OPTIONS 0x01					// option screen data
#define OVL_SINVADE	0x02					// hidden game overlay
#define OVL_SPONG	0x03					// hidden game pong overlay
/* if changes update mkchar.inc */
#define OVL_END1	0x04					// kano, sonya, kabal
#define OVL_END2	0x05					// jax, swat, lk
#define OVL_END3	0x06					// ind, robos
#define OVL_END4	0x07					// sz, st, male ninjas
#define OVL_END5	0x08					// female ninjas
#define OVL_END6	0x09					// sindel, sk, lao
//================================================================================================

/*
 *	RAM
 */
__EXTERN__ BYTE load_level;				// current level in load_addr area
__EXTERN__ BYTE spec_fx;				// set to current special overlay loaded (-1) means who cares

__EXTERN__ void *finish_heap_ptr;		// ptr for finishing heap info
__EXTERN__ void *player_heap_ptr;		// remember what my heap ptr was before fatality
/*
 *	PROTOTYPES
 */
int module_io_init(void);
File_IO_Struct *module_os_open(char *filename);
int module_os_read(void *destptr,int readbytes,File_IO_Struct *fileptr);
int module_os_seek(File_IO_Struct *fileptr,int seekpos,int seekmode);
int module_os_size(File_IO_Struct *fileptr);
int module_os_close(File_IO_Struct *fileptr);

void sys_aligned_memfill( int *memstart, int numints, int val );
void sys_aligned_memclear( int *memstart, int numints );
void loadoverlay( LONG index );


void texture_pool_init(void);
int texture_level_load(WORD level,WORD sync);
int character_ziptexture_load(WORD pchar,void *dest);
int character_texture_load(WORD pchar,WORD type,void *dest,WORD sync);
void *special_character_texture_load(WORD special,WORD player);
int async_overlay_load(WORD overnum);
int generic_overlay_load(WORD overnum);
BYTE *special_fx_load(WORD fxtype);
int level_overlay_load(WORD level);

/*
 *	MACROS
 */

#endif /* __mk_mkdma_h__ */
