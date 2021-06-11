/******************************************************************************
 File: mkfile.h

 By: David Schwartz

 Date: March 1995

 (C) Williams Entertainment

 Mortal Kombat III file Header
******************************************************************************/

#ifndef __mk_mkfile_h__
#define __mk_mkfile_h__

//-SONY- #include "psxcd.h"

/*
 * 	DEFINITIONS
 */
#define CD_FILE	_CD_VERSION_
#define PC_FILE	(CD_FILE^1)

#if _CD_VERSION_ == 1
typedef PsxCd_File File_IO_Struct;
#else
typedef int File_IO_Struct;
#endif

typedef struct ovl
{
	char **ovl_addr;
	char *ovl_file;
} OVL;

/* character data type */
#define CHAR_BABY   0
#define CHAR_NORMAL	1
#define CHAR_ANIMAL 2
#define CHAR_FRIEND 3
#define CHAR_FATAL1  4
#define CHAR_FATAL2  5
#define CHAR_VS  6

/* special character loads */
#define NO_FILE							0xffff					// EQUIVALENT TO NULL
#define CHAR_SPECIAL_1			0xfff1					// KANO SKEL REACH
#define CHAR_SPECIAL_2			0xfff2					// LIA SKIN RIP
#define CHAR_SPECIAL_3			0xfff3					// KABAL INFLATE
#define CHAR_SPECIAL_4			0xfff4					// SHEEVA SKIN RIP
#define CHAR_SPECIAL_5			0xfff5					// SHANG FLOAT
#define CHAR_SPECIAL_6			0xfff6					// SMOKE ARM BOMB
#define CHAR_SPECIAL_7			0xfff7

/* load types */
#define SYNC_LOAD	0x0000			// normal sync load
#define ASYNC_LOAD 	0x0001			// async load
#define FATAL_LOAD	0x0002			// load at dest-length addr

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

/* special end of figght fxs load */
#define FX_FATAL_LOAD 0
#define FX_ANIMAL_LOAD 1
#define FX_FRIEND_LOAD 2
#define FX_BABY_LOAD 3

/* level textures & code file index */
#define LVL_NONE			0xff
#define LVL_SUBWAY_STREET	0
#define LVL_UNUSED1			1
#define LVL_BANK			2
#define LVL_CITY			2
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
#define LVL_HSCORE			15
#define LVL_LADDER			16
#define LVL_VERSE			17
#define LVL_COIN			18
#define LVL_FIRE			19
#define LVL_GRADIENT		20
#define LVL_TITLE			21
#define LVL_SELECT			LVL_LADDER
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
#define LVL_ARENA			33
#define LVL_ARMORY			34
#define LVL_LAIR_ARMORY_TOMB	LVL_ARMORY
#define LVL_FOREST			35
#define LVL_TOWER			36
#define LVL_MONK			37
#define LVL_LIAR			38		
#define LVL_TOMB			39
#define LVL_TOURN			40


/*
 *	RAM
 */
__EXTERN__ File_IO_Struct module_int;

__EXTERN__ BYTE load_level;				// current level in load_addr area
__EXTERN__ BYTE load_pal;				// current img palette overlay loaded (0-NTSC, 1-RGB)

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

int texture_level_load(WORD level,WORD sync);
int character_texture_load(WORD pchar,WORD type,void *dest,WORD sync);
int async_overlay_load(WORD overnum);
int generic_overlay_load(WORD overnum);
BYTE *special_fx_load(WORD fxtype);
int level_overlay_load(WORD level);
void file_load_message(WORD);



/*
 *	MACROS
 */

#endif /* __mk_mkfile_h__ */
