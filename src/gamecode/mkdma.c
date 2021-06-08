/******************************************************************************
 File: mkdma.c

 Date: March 1995

 (C) Williams Entertainment

 Mortal Kombat III DMA IO
******************************************************************************/

/* INCLUDES */
#include "u64main.h"
#include "romcopy.h"

#include "mkdma.h"
#include "mkbkgd.h"
#include "mkos.h"
#include "mkgame.h"

/******************************************************************************
 Low Level Overlay load System Routines
******************************************************************************/
extern WORD f_white;

//////////////////////////////////////////////////////////////////////////////////////////
// sys_aligned_memfill - fills the specified virtual memory range with the specified
//                       value. This is an integer-aligned memory fill operation.
//////////////////////////////////////////////////////////////////////////////////////////
void sys_aligned_memfill( int *memstart, int numints, int val ) 
{
	int i;

	for( i=0; i<numints; i++ ) 
		memstart[i] = val;
	
	return;
}


//////////////////////////////////////////////////////////////////////////////////////////
// sys_aligned_memclear - zeros the specified virtual memory range. This is an integer-
//                        aligned operation.
//////////////////////////////////////////////////////////////////////////////////////////
void sys_aligned_memclear( int *memstart, int numints ) 
{
	sys_aligned_memfill( memstart, numints, 0 );
	return;
}

/******************************************************************************
 Function: void loadoverlay(LONG index)

 By: David Schwartz
 	 David Schwartz (modified)

 Date: Feb 1996

 Parameters: overlay index

 Returns: error code (0=None)

 Description:   load an overlay from rom to ram
******************************************************************************/

/* overlay array must match enums in mkdma.h header file */
static struct sys_ovdirentry sys_ovdir[]=
{
	SYS_OVENTRY(city),
	SYS_OVENTRY(armor),
	SYS_OVENTRY(battle),
	SYS_OVENTRY(bell),
	SYS_OVENTRY(bridge),
	SYS_OVENTRY(cave),
	SYS_OVENTRY(kung2),
	SYS_OVENTRY(kung5),
	SYS_OVENTRY(dead),
	SYS_OVENTRY(desert),
	SYS_OVENTRY(grave),
	SYS_OVENTRY(hport),
	SYS_OVENTRY(lost),
	SYS_OVENTRY(mk2pit),
	SYS_OVENTRY(monk),
	SYS_OVENTRY(pit),
	SYS_OVENTRY(sbst),
	SYS_OVENTRY(soul),
	SYS_OVENTRY(temple),
	SYS_OVENTRY(tower),
	SYS_OVENTRY(tree),
	SYS_OVENTRY(water),
	SYS_OVENTRY(buyin),
	SYS_OVENTRY(select),
	SYS_OVENTRY(grad),
//	SYS_OVENTRY(option),
	SYS_OVENTRY(title),
	SYS_OVENTRY(title),
	SYS_OVENTRY(vsplay),
	SYS_OVENTRY(steel),
	SYS_OCENTRY(ponggame),
	SYS_OCENTRY(markgame),
	SYS_OCENTRY(stormdata),
};

void loadoverlay( LONG index ) 
{
	u32 vstart, romstart, romsize, bss_start, bss_size;

	//v3printf(( "  >loading overlay #%d...\n", index ));

	romstart = sys_ovdir[index].romstart;
	romsize = sys_ovdir[index].romend-romstart;
	vstart = sys_ovdir[index].vstart;
	bss_start = sys_ovdir[index].bss_start;
	bss_size = sys_ovdir[index].bss_end - sys_ovdir[index].bss_start;

	/* load from rom to ram */
	//v3printf(( "    reading from ROM 0x%08x-0x%08x to virt 0x%08x-0x%08x (%d bytes)\n", romstart, romstart+romsize-1, vstart, vstart+romsize-1, romsize ));
	romcopy_sync( romstart, (void *)vstart, romsize, RCFLAG_FLUSHCODE | RCFLAG_FLUSHDATA );

	/* clear BSS section */
	//v3printf(( "    clearing BSS area 0x%08x - 0x%08x (%d bytes)\n", bss_start, bss_start+bss_size-1, bss_size ));
	sys_aligned_memclear( (int *)bss_start, bss_size>>2 );

	return;
}

void loadtexture(u32 romstart,u32 romsize,u32 vstart) 
{
	//v3printf(( "  >texture overlay...\n"));
	
	/* load from rom to ram */
 	//v3printf(( "    reading from ROM 0x%08x-0x%08x to virt 0x%08x-0x%08x (%d bytes)\n", romstart, romstart+romsize-1, vstart, vstart+romsize-1, romsize ));
	
	romcopy_sync( romstart, (void *)vstart, romsize, RCFLAG_FLUSHCODE | RCFLAG_FLUSHDATA );
	
	return;
}

/******************************************************************************
 Routines used by code to load in files at various times
******************************************************************************/
/* indexed by load_bkgd variable */
BYTE table_o_levels[]=
{
	LVL_SUBWAY_STREET,                      // 0, subway & street
	LVL_SUBWAY_STREET,                      // 1, subway & street
	LVL_KUNG2, 								// 2, kungfu 2 (monks)
	LVL_KUNG5,								// 3, kungfu 5 (pit 1)
	LVL_SOUL,                               // 4, tower
	LVL_BRIDGE,                             // 5, bridge
	LVL_SOUL,                               // 6, soul
	LVL_BELL,                               // 7, bell
	LVL_TEMPLE,                             // 8, temple
	LVL_GRAVE,                              // 9, grave
	LVL_PIT,                                // a, pit/throne
	LVL_WATER,								// b, water
	LVL_HADES_CAVE,							// c, hades
	LVL_HADES_CAVE,							// d, cave
	LVL_DESERT,								// e, desert
	LVL_LOST,								// f, lost mk2
	LVL_PORTAL,                             // 10, portal module
	LVL_DEADPOOL,							// 11, deadpool
	LVL_BATTLE,								// 12, battle arena
	LVL_CITY,								// 13, sk arena
	LVL_LAIR_ARMORY_TOMB,					// 14, armory
	LVL_FOREST,								// 15, forest
	LVL_TOWER,								// 16, tower
	LVL_MONK,								// 17, floating monk portal
	LVL_LAIR_ARMORY_TOMB,					// 18, goros lair
	LVL_LAIR_ARMORY_TOMB,					// 19, sk tomb
	LVL_MK2PIT,								// 1a, mk2 pit
	LVL_MK2PIT,								// 1b, mk2 pit star
	LVL_KUNG5,								// 1c, NOT USED
	0,										// 1d, NOT USED
	0,										// 1e, NOT USED
	0,										// 1f, NOT USED
	LVL_BUYIN,                              // 20, buyin module
	LVL_HSCORE,                             // 21, high score background plate (LVL_SELECT)
	LVL_LADDER,                             // 22, ladder (LVL_SELECT)
	LVL_VERSE,                              // 23, vs screen 
	0,
	LVL_FIRE,								// 25, fire sky (LVL_SELECT)
	LVL_SOUL,                               // 26, no wall
	LVL_GRADIENT,                           // 27, red color gradient for text messages
	LVL_GRADIENT,                           // 28, green color gradient for text messages
	LVL_GRADIENT,                           // 29, blue color gradient for text messages
	LVL_BUYIN,                              // 2a, mode coin page
	LVL_TITLE,                              // 2b, title screen
	LVL_SELECT,                             // 2c, player select screen
	LVL_TITLE,                              // 2d, legals
	LVL_SKEND,                              // 2e, ending SKDIE1 (NOT USED)
	LVL_SKEND,                              // 2f,  ending SKDIE2 (NOT USED)
	LVL_SKEND,                              // 30, ending SKDIEPIT (NOT USED)
	LVL_MOCKPIT,                            // 31, mockpit level (NOT USED)
	LVL_OPTIONS,                            // 32, dragon logo option bkgd
	LVL_OPTIONS,                            // 33, option coin screen
	LVL_TOURN,								// 34, tournament 
	LVL_FIRE,								// 35, fire sky (LVL_SELECT)
};

//******************************************************************************
//******************************************************************************
// 			TEXTURE LOADER
//******************************************************************************
//******************************************************************************

/******************************************************************************
 Function: int texture_level_load(WORD level)

 By: David Schwartz

 Date: March 1995

 Parameters: level - which texture level to load

 Returns: error code (0=None)

 Description:   This routine will load all textures for a level into memory.  The routine
				loads the data from the cartridge into the uncompress buffer.  It then decompresses
				the memory to the next available location in the texture pool.  See the 
				u64main.h for the layout for the segments.
******************************************************************************/
/* level texture load tables */
/* terminate list with length field 0 */
SEGL dummy_seg[]=
{
	{0,0},			// background textures
#if MULTI_ANI_OFF	
	{0,0},			// background unique textures anims1 (if any)
	{0,0},			// background unique textures anims2 (if any)
#endif	
};

SEGL city_seg[]= 
{	
	SYS_OTENTRY(city),		// background textures
#if MULTI_ANI_OFF	
	{0,0},			// background unique textures anims1 (if any)
	{0,0},			// background unique textures anims2 (if any)
#endif	
};

SEGL armory_seg[]= 
{	
	SYS_OTENTRY(armor),		// background textures
#if MULTI_ANI_OFF	
	{0,0},			// background unique textures anims1 (if any)
	{0,0},			// background unique textures anims2 (if any)
#endif	
};

SEGL battle_seg[]= 
{	
	SYS_OTENTRY(battle),		// background textures
#if MULTI_ANI_OFF	
	{0,0},			// background unique textures anims1 (if any)
	{0,0},			// background unique textures anims2 (if any)
#endif	
};

SEGL bell_seg[]= 
{	
	SYS_OTENTRY(bell),		// background textures
#if MULTI_ANI_OFF	
	{0,0},			// background unique textures anims1 (if any)
	{0,0},			// background unique textures anims2 (if any)
#endif	
};

SEGL bridge_seg[]= 
{	
	SYS_OTENTRY(bridge),		// background textures
#if MULTI_ANI_OFF	
	{0,0},			// background unique textures anims1 (if any)
	{0,0},			// background unique textures anims2 (if any)
#endif	
};

SEGL cave_seg[]= 
{	
	SYS_OTENTRY(cave),		// background textures
#if MULTI_ANI_OFF	
	{0,0},			// background unique textures anims1 (if any)
	{0,0},			// background unique textures anims2 (if any)
#endif	
};

SEGL dead_seg[]= 
{	
	SYS_OTENTRY(dead),		// background textures
#if MULTI_ANI_OFF	
	{0,0},			// background unique textures anims1 (if any)
	{0,0},			// background unique textures anims2 (if any)
#endif	
};

SEGL desert_seg[]= 
{	
	SYS_OTENTRY(desert),		// background textures
#if MULTI_ANI_OFF	
	{0,0},			// background unique textures anims1 (if any)
	{0,0},			// background unique textures anims2 (if any)
#endif	
};

SEGL grave_seg[]= 
{	
	SYS_OTENTRY(grave),		// background textures
#if MULTI_ANI_OFF	
	{0,0},			// background unique textures anims1 (if any)
	{0,0},			// background unique textures anims2 (if any)
#endif	
};

SEGL hport_seg[]= 
{	
	SYS_OTENTRY(hport),		// background textures
#if MULTI_ANI_OFF	
	{0,0},			// background unique textures anims1 (if any)
	{0,0},			// background unique textures anims2 (if any)
#endif	
};

SEGL lost_seg[]= 
{	
	SYS_OTENTRY(lost),		// background textures
#if MULTI_ANI_OFF	
	{0,0},			// background unique textures anims1 (if any)
	{0,0},			// background unique textures anims2 (if any)
#endif	
};

SEGL mk2pit_seg[]= 
{	
	SYS_OTENTRY(mk2pit),		// background textures
#if MULTI_ANI_OFF	
	{0,0},			// background unique textures anims1 (if any)
	{0,0},			// background unique textures anims2 (if any)
#endif	
};

SEGL monk_seg[]= 
{	
	SYS_OTENTRY(monk),		// background textures
#if MULTI_ANI_OFF	
	{0,0},			// background unique textures anims1 (if any)
	{0,0},			// background unique textures anims2 (if any)
#endif	
};

SEGL pit_seg[]= 
{	
	SYS_OTENTRY(pit),		// background textures
#if MULTI_ANI_OFF	
	{0,0},			// background unique textures anims1 (if any)
	{0,0},			// background unique textures anims2 (if any)
#endif	
};

SEGL sbst_seg[]= 
{	
	SYS_OTENTRY(sbst),		// background textures
#if MULTI_ANI_OFF	
	{0,0},			// background unique textures anims1 (if any)
	{0,0},			// background unique textures anims2 (if any)
#endif	
};

SEGL soul_seg[]= 
{	
	SYS_OTENTRY(soul),		// background textures
#if MULTI_ANI_OFF	
	{0,0},			// background unique textures anims1 (if any)
	{0,0},			// background unique textures anims2 (if any)
#endif	
};

SEGL temple_seg[]= 
{	
	SYS_OTENTRY(temple),		// background textures
#if MULTI_ANI_OFF	
	{0,0},			// background unique textures anims1 (if any)
	{0,0},			// background unique textures anims2 (if any)
#endif	
};

SEGL tower_seg[]= 
{	
	SYS_OTENTRY(tower),		// background textures
#if MULTI_ANI_OFF	
	{0,0},			// background unique textures anims1 (if any)
	{0,0},			// background unique textures anims2 (if any)
#endif	
};

SEGL tree_seg[]= 
{	
	SYS_OTENTRY(tree),		// background textures
#if MULTI_ANI_OFF	
	{0,0},			// background unique textures anims1 (if any)
	{0,0},			// background unique textures anims2 (if any)
#endif	
};

SEGL water_seg[]= 
{	
	SYS_OTENTRY(water),		// background textures
#if MULTI_ANI_OFF	
	{0,0},			// background unique textures anims1 (if any)
	{0,0},			// background unique textures anims2 (if any)
#endif	
};

SEGL kung2_seg[]= 
{	
	SYS_OTENTRY(kung2),		// background textures
#if MULTI_ANI_OFF	
	{0,0},			// background unique textures anims1 (if any)
	{0,0},			// background unique textures anims2 (if any)
#endif	
};

SEGL kung5_seg[]= 
{	
	SYS_OTENTRY(kung5),		// background textures
#if MULTI_ANI_OFF	
	{0,0},			// background unique textures anims1 (if any)
	{0,0},			// background unique textures anims2 (if any)
#endif	
};


SEGL buyin_seg[]= 
{	
	SYS_OTENTRY(buyin),		// background textures
#if MULTI_ANI_OFF	
	{0,0},			// background unique textures anims1 (if any)
	{0,0},			// background unique textures anims2 (if any)
#endif	
};

SEGL select_seg[]= 
{	
	SYS_OTENTRY(select),		// background textures
#if MULTI_ANI_OFF	
	{0,0},			// background unique textures anims1 (if any)
	{0,0},			// background unique textures anims2 (if any)
#endif	
};

SEGL grad_seg[]= 
{	
	SYS_OTENTRY(grad),		// background textures
#if MULTI_ANI_OFF	
	{0,0},			// background unique textures anims1 (if any)
	{0,0},			// background unique textures anims2 (if any)
#endif	
};

#if 0
SEGL option_seg[]= 
{	
	SYS_OTENTRY(option),		// background textures
#if MULTI_ANI_OFF	
	{0,0},			// background unique textures anims1 (if any)
	{0,0},			// background unique textures anims2 (if any)
#endif	
};
#endif

SEGL title_seg[]= 
{	
	SYS_OTENTRY(title),		// background textures
#if MULTI_ANI_OFF	
	{0,0},			// background unique textures anims1 (if any)
	{0,0},			// background unique textures anims2 (if any)
#endif	
};

SEGL steel_seg[]= 
{	
	SYS_OTENTRY(steel),		// background textures
#if MULTI_ANI_OFF	
	{0,0},			// background unique textures anims1 (if any)
	{0,0},			// background unique textures anims2 (if any)
#endif	
};


/* Format:      overlay texture segment data                                // level # */
SEGL *level_texture_ptrs[]=
{
	sbst_seg,               // 0, subway & street
	mk2pit_seg,               // 1, mk2 pit 
   	NULL,					// 2, not used
	soul_seg,               // 3, soul & balcony & hidden nowall
	bridge_seg,               // 4, bridge
	bell_seg,               // 5, bell
	temple_seg,               // 6, temple
	grave_seg,               // 7, grave
	pit_seg,               // 8, pit
	water_seg,               // 9, water
	cave_seg,               // 10, hades/cave
	desert_seg,               // 11, desert
	buyin_seg,               // 12, buyin
	lost_seg,               // 13, lost mk2
	hport_seg,          		// 14, hidden portal
	NULL,        		// 15, high score background plate (NOT USED U64, part of LVL_VERSE)
	NULL,               // 16, (NOT USED U64, part of LVL_SELECT)
	steel_seg,           // 17, vs 
	NULL,               // 18, coin (NOT USED U64, part of LVL_SELECT)
	NULL,               // 19, fire (NOT USED U64, part of LVL_SELECT)
	grad_seg,           // 20, graident 
	title_seg,               // 21, title screen
	select_seg,               // 22, ladder/player select/high score/vs/tourn/fire
	NULL,//	option_seg,               // 23, options logo background
	NULL,               // 24, options text stuff (NOT USED U64)
	NULL,               // 25, control panel stuff (NOT USED U64)
	NULL,               // 26, font data (NOT USED U64)
	NULL,           	// 27, loading stuff (NOT USED U64)
	NULL,  				// 28, skdie endings  (NOT USED U64)
	NULL,               // 29, mock pit (NOT USED U64)
	NULL,               // 30, dream team (NOT USED U64)
	dead_seg,				// 31, dead pool
	battle_seg,				// 32, battle
	city_seg,				// 33, city roof
	armory_seg,				// 34, armory
	tree_seg,				// 35, forest
	tower_seg,				// 36, tower
	monk_seg,				// 37, monk
	NULL,				// 38, NOT USED
	NULL,				// 39, NOT USED
	NULL,
	kung2_seg,				// 41 kung fu 2
	kung5_seg,				// 42 kung fu 5
};

void texture_pool_init(void) 
{
	int i;
	
	/* clear texture ptrs */
	for (i=0;i<TEXT_POOL_MAX;i++)
		texture_base_ptrs[i]=NULL;

	/* initialize texture ptr */
	bkgd_texture_ptr=(BYTE *)bkgd_texture_pool;

	return;
}

int texture_level_load(WORD level,WORD sync)
{
	SEGL *seg;
	BYTE **tptr;
	int l;
	WORD *decomp_ptr;

	texture_pool_init();

	if ((seg=level_texture_ptrs[level])!=NULL) 
	{
		decomp_ptr=(WORD *)idcomp_ptr;			// save current compress ptr
		
		tptr=texture_base_ptrs;

		for (l=0;l<TEXT_POOL_MAX-1;l++)
		{
			if (seg->segl_end!=0) 
			{
				/* load data from cartridge to uncompress buffer */
				loadtexture(seg->segl_start,seg->segl_end-seg->segl_start,(LONG)player_heap);

#if 0				
				if (f_error) 
				{
					printf(("TEXTURE LOAD\n"));
					validate_process();
				}
#endif				

				/* update base ptrs */
				*tptr++=bkgd_texture_ptr;			// store start of texture memory for heap calcs

				/* decompress from buffer to texture pool area */
				idcomp_ptr=(LONG *)bkgd_texture_ptr;
	
				uncompress_image((BYTE *)player_heap,NULL);
				
#if 0//SYS_DEBUG
				if (((ADDRESS)idcomp_ptr-(ADDRESS)bkgd_texture_pool)>TEXTURE_POOL_SIZE)
					printf(("OVERALLOCATED BKGD TEXTURE POOL\n"));
				
				printf(("BKGD TEXTURE ALLOC SIZE %d\n",(ADDRESS)idcomp_ptr-(ADDRESS)bkgd_texture_pool));
#endif

#if 0
				if (f_error) 
				{
					printf(("TEXTURE DECOMP\n"));
					validate_process();
				}
#endif				

				bkgd_texture_ptr=(BYTE *)idcomp_ptr;		// update background decomp ptr

				/* next segment load */
				seg++;				
			  
			}
			else
			{
			 	*tptr++=bkgd_texture_ptr;
			}
		}
	
		*tptr++=bkgd_texture_ptr;		// set last entry (THIS SHOULD BE THE FLOORS)
		(WORD *)idcomp_ptr=decomp_ptr;			// restore current compress ptr
	}
	return(0);
}

//******************************************************************************
//******************************************************************************
// 			GENERIC OVERLAY LOADER
//******************************************************************************
//******************************************************************************

/******************************************************************************
 Function: int level_overlay_load(WORD level)

 By: David Schwartz

 Date: March 1995

 Parameters: level - level number to load

 Returns: error code (0=None)

 Description:   load specified background level code overlay to correct area
******************************************************************************/
/* overlay loader index for code			<--- level # */
WORD level_overlay_table[]=
{
	SYS_SBST_OVL,		// ovl 00 - SUBWAY & STREET
	SYS_MK2PIT_OVL,		// ovl 01 - UNUSED
	NULL_OVERLAY,		// ovl 02 - NOT USED
	SYS_SOUL_OVL,		// ovl 03 - SOUL & BALCONY & HIDDEN NOWALL
	SYS_BRIDGE_OVL,		// ovl 04 - BRIDGE
	SYS_BELL_OVL,		// ovl 05 - BELL
	SYS_TEMPLE_OVL,		// ovl 06 - TEMPLE
	SYS_GRAVE_OVL,		// ovl 07 - GRAVE
	SYS_PIT_OVL,		// ovl 08 - PIT
	SYS_WATER_OVL,		// ovl 09 - WATER
	SYS_CAVE_OVL,		// ovl 10 - HADES & CAVE
	SYS_DESERT_OVL,		// ovl 11 - DESERT
	SYS_BUYIN_OVL,		// ovl 12 - BUYIN SCREEN
	SYS_LOST_OVL,		// ovl 13 - LOST MK2
	SYS_HPORT_OVL,		// ovl 14 - hidden portal level
	NULL_OVERLAY,		// ovl 15 - High SCore (LVL_SELECT U64)
	NULL_OVERLAY,		// ovl 16 - SELECT/LADDER (LVL_SELECT U64)
	SYS_STEEL_OVL,		// ovl 17 - VERSE SCREEN (BACKGROUND) 
	NULL_OVERLAY,		// ovl 18 - COIN (NOT USED)
	NULL_OVERLAY,		// ovl 19 - FIRE PORTAL (LVL_SELECT U64)
	SYS_GRAD_OVL,		// ovl 20 - gradients
	SYS_TITLE_OVL,		// ovl 21 - Title
	SYS_SELECT_OVL,		// ovl 22 - ladder/player select/vs/high score/tourn/fire
	NULL_OVERLAY,		//SYS_OPTION_OVL,		// ovl 23 - NONE, options
	NULL_OVERLAY,		//SYS_OPTION_OVL,		// ovl 24 - NONE, opttext
	NULL_OVERLAY,		// ovl 25 - NONE, control
	NULL_OVERLAY,		// ovl 26 - NONE, fonts
	NULL_OVERLAY,		// ovl 27 - NONE, loading
	NULL_OVERLAY,		// ovl 28 - skdie endings
	NULL_OVERLAY,		// ovl 20 - MOCK PIT
	NULL_OVERLAY,		// ovl 30 - DREAM TEAM
	SYS_DEAD_OVL,		// 31, dead pool
	SYS_BATTLE_OVL,		// 32, battle
	SYS_CITY_OVL,		// 33, arena
	SYS_ARMOR_OVL,		// 34, armory
	SYS_TREE_OVL,		// 35, forest
	SYS_TOWER_OVL,		// 36, tower
	SYS_MONK_OVL,		// 37, monk
	NULL_OVERLAY,		// 38, NOT USED
	NULL_OVERLAY,		// 39, NOT USED
	NULL_OVERLAY,		// 40, tournament 
	SYS_KUNGFU2_OVL,	// 41, kung 2
	SYS_KUNGFU5_OVL,	// 42, kung 5
};

int level_overlay_load(WORD level)
{
	/* make sure we have a valid level */
	if (level>=sizeof(level_overlay_table)/sizeof(level_overlay_table[0]))
		return(-1);

	/* make sure there is something to load */
	if ( level_overlay_table[level]==NULL_OVERLAY )
		return(0);

	/* load up the data */
	loadoverlay(level_overlay_table[level]);	

	return(0);
}
//******************************************************************************
//******************************************************************************
// 			CHARACTER ANIMATION AND TEXTURE LOADER
//******************************************************************************
//******************************************************************************

/******************************************************************************
 Function: int character_texture_load(WORD pchar,WORD type,void *dest,WORD sync)

 By: David Schwartz

 Date: March 1995

 Parameters: pchar - which character to load
						 type - character data type
								0 - normal
								1 - animality
								2 - friendship & babality
								3 - fatality
			 dest - ptr to where file data should be loaded
			 sync = bit 0 - off=synchronous on=asyncrounous
					bit 1 - off=load at dest on=load at dest-length


 Returns: error code (0=None)

 Description:   loads a characters texture file in to memory, this routine handles all types of character
				loads based on tables.  The are multiple files because of memory/speed issues.  Since the CD
				is dog slow we want all file loads to be as small as possible.  So various files are subdivided
				and special cased loaded.
******************************************************************************/
/* Format:      filename                // char # */
SEGL character_textures[]=
{
	SYS_OTENTRY(kano),			// kano
	SYS_OTENTRY(sonya),			// sonya
	SYS_OTENTRY(jax),			// jax
	SYS_OTENTRY(indian),			// indian
	SYS_OTENTRY(jcage),			// jcage
	SYS_OTENTRY(swat),			// swat
	
	SYS_OTENTRY(lia),			// lia
	SYS_OTENTRY(robo),			// robo1
	SYS_OTENTRY(robo),			// robo2
	SYS_OTENTRY(lao),			// lao
	SYS_OTENTRY(tusk),			// tusk
	
	SYS_OTENTRY(sheeva),			// sg
	SYS_OTENTRY(st),			// st
	SYS_OTENTRY(lk),			// lk
	SYS_OTENTRY(robo),			// smoke
	SYS_OTENTRY(fn),			// kitana
	
	SYS_OTENTRY(fn),			// jade
	SYS_OTENTRY(fn),			// mileena
	SYS_OTENTRY(nj),			// scorp
	SYS_OTENTRY(nj),			// reptile
	SYS_OTENTRY(nj),			// ermac
	
	SYS_OTENTRY(nj),			// oldsz
	SYS_OTENTRY(nj),			// oldsmoke
	SYS_OTENTRY(nj),			// noob
	SYS_OTENTRY(rd),			// rayden
	SYS_OTENTRY(sa),			// sword arm
	SYS_OTENTRY(nj),			// rain
	SYS_OTENTRY(fn),			// kamel
	SYS_OTENTRY(nj),			// ?
	SYS_OTENTRY(nj),			// ?
	SYS_OTENTRY(mot),			// motaro
	SYS_OTENTRY(sk),			// sk
};

SEGL character_dict[]=
{
	SYS_ODENTRY(kano),			// kano
	SYS_ODENTRY(sonya),			// sonya
	SYS_ODENTRY(jax),			// jax
	SYS_ODENTRY(indian),			// indian
	SYS_ODENTRY(jcage),			// jcage
	SYS_ODENTRY(swat),			// swat
	
	SYS_ODENTRY(lia),			// lia
	SYS_ODENTRY(robo),			// robo1
	SYS_ODENTRY(robo),			// robo2
	SYS_ODENTRY(lao),			// lao
	SYS_ODENTRY(tusk),			// tusk
	
	SYS_ODENTRY(sheeva),			// sg
	SYS_ODENTRY(st),			// st
	SYS_ODENTRY(lk),			// lk
	SYS_ODENTRY(robo),			// smoke
	SYS_ODENTRY(fn),			// kitana
	
	SYS_ODENTRY(fn),			// jade
	SYS_ODENTRY(fn),			// mileena
	SYS_ODENTRY(nj),			// scorp
	SYS_ODENTRY(nj),			// reptile
	SYS_ODENTRY(nj),			// ermac
	
	SYS_ODENTRY(nj),			// oldsz
	SYS_ODENTRY(nj),			// oldsmoke
	SYS_ODENTRY(nj),			// noob
	SYS_ODENTRY(rd),			// rayden
	SYS_ODENTRY(sa),			// baraka
	SYS_ODENTRY(nj),			// rain
	SYS_ODENTRY(fn),			// kamel
	SYS_ODENTRY(nj),			// noob
	SYS_ODENTRY(nj),			// noob
	SYS_ODENTRY(mot),			// mODaro
	SYS_ODENTRY(sk),			// sk
};

SEGL character_vs[]= 
{
	SYS_OTENTRY(kanozip),			// kano
	SYS_OTENTRY(sonyazip),			// sonya
	SYS_OTENTRY(jaxzip),			// jax
	SYS_OTENTRY(indianzip),			// indian
	SYS_OTENTRY(jczip),			// jcage
	SYS_OTENTRY(swatzip),			// swat
	SYS_OTENTRY(liazip),			// lia
	SYS_OTENTRY(robozip),			// robots
	SYS_OTENTRY(laozip),			// lao
	SYS_OTENTRY(tuskzip),			// tusk
	SYS_OTENTRY(sheevazip),			// sg
	SYS_OTENTRY(shangzip),			// st
	SYS_OTENTRY(lkzip),			// lk
	SYS_OTENTRY(fninjazip),			// kitana
	SYS_OTENTRY(mninjazip),			// scorp
	SYS_OTENTRY(nuguyszip),			// rayden
};

int character_ziptexture_load(WORD pchar,void *dest)
{
	SEGL *seg;
	int after;
	
	/* load the character zip data */
	seg=&character_vs[pchar];
	after=inflate_cart(seg->segl_start,&dest,(BYTE *)dpipe[vid_dpipe_writing].idcmp_base,90*1024);
	return(0);
}

SEGL character_zip[]= 
{
	SYS_OTENTRY(motszip),			// kano
	SYS_OTENTRY(skszip),			// kano
};

int character_texture_load(WORD pchar,WORD type,void *dest,WORD sync)
{
	SEGL *seg;
	LONG length;
	WORD after;
	
	/* load the dictionary */
	seg=&character_dict[pchar];
	loadtexture(seg->segl_start,seg->segl_end-seg->segl_start,(LONG)dest);
	
	/* load the character data */
	seg=&character_textures[pchar];
	length=seg->segl_end-seg->segl_start;

	switch (type)
	{
		case CHAR_NORMAL:
			length=seg->segl_end-seg->segl_start;
			break;
		case CHAR_SELECT:
			if (length>BUCKET_SIZE)
				length=BUCKET_SIZE;
			break;
		case CHAR_ENDING:
			if (length>END_BUCKET_SIZE)
				length=END_BUCKET_SIZE;
			break;
		case CHAR_SHANG:
			length=50*1024;
			break;
		default:
			if (length>INTRO_BUCKET_SIZE)
				length=INTRO_BUCKET_SIZE;
			break;
	};

	(BYTE *)dest=(BYTE*)dest+256;
	loadtexture(seg->segl_start,length,(LONG)dest);

#if 1
	if (pchar==FT_SK || pchar==FT_MOTARO) 
	{
//		printf(("SK LENGTH %x\n",length));
		(BYTE *)dest=(BYTE*)dest+length;
//		printf(("DEST TEXT %x\n",dest));
		seg=&character_zip[pchar-FT_MOTARO];
		
		if (type!=CHAR_NORMAL)
		{
			if (pchar==FT_MOTARO)
				after=inflate_cart_partial(seg->segl_start,&dest,94*1024,(BYTE *)dpipe[vid_dpipe_writing].idcmp_base+120*1024,90*1024);
			else after=inflate_cart_partial(seg->segl_start,&dest,30*1024,(BYTE *)dpipe[vid_dpipe_writing].idcmp_base+120*1024,90*1024);
		}
		else after=inflate_cart(seg->segl_start,&dest,(BYTE *)dpipe[vid_dpipe_writing].idcmp_base,90*1024);
//		printf(("AFTER=%d\n",after));
	}
#endif

	/* load in top art for kabal */
	if (pchar==FT_TUSK && f_top_load==0 && gstate!=GS_PSEL && gstate!=GS_POST_PSEL)
		special_fx_load(FX_TOP_LOAD);
	
	return(0);
}


SEGL special_character_textures[]=
{
	SYS_OTENTRY(indianf),
	SYS_OTENTRY(indiana),			
	SYS_OTENTRY(robo1a),			
	SYS_OTENTRY(robo3a),			
	SYS_OTENTRY(robo1f1),			
	SYS_OTENTRY(robo1f2),			
	SYS_OTENTRY(robo2f1),			
	SYS_OTENTRY(robo2f2),			
	SYS_OTENTRY(robo3f1),			
	SYS_OTENTRY(robo3f2),			
	SYS_OTENTRY(nja),			
	SYS_OTENTRY(njf),
	SYS_OTENTRY(njscf1),
	SYS_OTENTRY(robof),			
	SYS_OTENTRY(robo2a),
	
	SYS_OTENTRY(fnf),
	SYS_OTENTRY(fnmlf1),
	SYS_OTENTRY(indianf2),
	SYS_OTENTRY(liaa),
	SYS_OTENTRY(njrpf1),
	SYS_OTENTRY(njrpf2),
	SYS_OTENTRY(sta),
	SYS_OTENTRY(tuska),
	SYS_OTENTRY(tuskf2),
	SYS_OTENTRY(njscf2),
};

void *special_character_texture_load(WORD special,WORD player)
{
	SEGL *seg;
	int length;
	void *heap;
	BYTE *dest;
	
	/* compute length of data to load */
	seg=&special_character_textures[special];
	length=seg->segl_end-seg->segl_start;
	
	/* calulate correct heap start local */
	switch (player)
	{
		case 0:		// player 1, so stick at player 2 heap bottom
			dest=(BYTE *)p1_heap;
			break;
		case 1:		// player 2, so stick at player 1 heap bottom
			dest=(BYTE *)p2_heap;
			break;
	}
	
	dest+=(PLAYER_HEAP_SIZE/2)-length;		// get enough room to store data
	dest-=((LONG)dest & 0x7);				// 8 byte align data

	/* load the character data */
	loadtexture(seg->segl_start,length,(LONG)dest);

	return(dest);
}

/******************************************************************************
 Function: int special_fx_load(WORD fxtype)

 By: David Schwartz

 Date: June 1995

 Parameters: fxtype - which effect to load

 Returns: error code (0=None)

 Description:   loads end of fight fxs graphic
******************************************************************************/
/* Format:      filename                // fx # */
static struct sys_ovdirentry sys_fxdir[]=
{
	SYS_OVTENTRY(fatal),
	SYS_OVTENTRY(animal),
	SYS_OVTENTRY(friend),
	SYS_OVTENTRY(baby),
	SYS_OVTENTRY(fight),
	SYS_OVTENTRY(finhim),
	SYS_OVTENTRY(finher),
	SYS_OVTENTRY(mercy),
	SYS_OVTENTRY(mugs),
	SYS_OVTENTRY(top),
	SYS_OVTENTRY(skel),
	SYS_OVTENTRY(rips),
	SYS_OVTENTRY(logo),
	SYS_OVTENTRY(brutal),
	SYS_OVTENTRY(skdie),
};

// do not call unless spec fx is cleared
BYTE *special_fx_load(WORD fxtype)
{
	u32 vstart, romstart, romsize;

	//v3printf(( "  >FX loading overlay #%d...\n", fxtype ));

	/* track what is loaded in special area */
	switch (fxtype)
	{
		case FX_TOP_LOAD:
			f_top_load=1;
			break;
		case FX_SKEL_LOAD:
			if (spec_fx==FX_MERCY_LOAD)
			{
				/* kill mercy graphics process */
				process_kill_class(PID_MERCY,0xffff);
				
				/* reset loading fx */
				spec_fx=FX_NO_LOAD;
			}
			f_skel_load=1;
			f_top_load=0;
			break;
		case FX_RIPS_LOAD:
			if (spec_fx==FX_MERCY_LOAD)
			{
				/* kill mercy graphics process */
				process_kill_class(PID_MERCY,0xffff);
				
				/* reset loading fx */
				spec_fx=FX_NO_LOAD;
			}
			f_rips_load=1;
			f_top_load=0;
			break;
		case FX_SKDIE_LOAD:
		case FX_MUGS_LOAD:
		case FX_LOGO_LOAD:
			/* wipes out top data */
			f_top_load=0;
		case FX_MERCY_LOAD:
			/* wipes out skel data */
			f_skel_load=0;
			f_rips_load=0;
		default:
			spec_fx=fxtype;
			break;
	}
	
	romstart = sys_fxdir[fxtype].romstart;
	romsize = sys_fxdir[fxtype].romend-romstart;
	vstart = sys_fxdir[fxtype].vstart;

	/* load from rom to ram */
	//v3printf(( "    FX reading from ROM 0x%08x-0x%08x to virt 0x%08x-0x%08x (%d bytes)\n", romstart, romstart+romsize-1, vstart, vstart+romsize-1, romsize ));
	romcopy_sync( romstart, (void *)vstart, romsize, RCFLAG_FLUSHCODE | RCFLAG_FLUSHDATA );

	return(NULL);	
}




