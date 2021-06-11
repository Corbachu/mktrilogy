/******************************************************************************
 File: mkfile.c

 Date: March 1995

 (C) Williams Entertainment

 Mortal Kombat III File IO
******************************************************************************/

#define SONY_CD_HACK 0                  // needed to deal with SONY sometimes loaded a bad sector at random times, not fix at this time and product needs to ship!!!
#define DRAW_HACK  1 // make dma ints not happen before flushing

/* INCLUDES */
#include "u64main.h"

#include "mkdma.h"
#include "mkbkgd.h"
#include "mkos.h"

//-SONY- #include "psxcdabs.h"

extern LONG system_marker;
extern WORD f_load;
extern WORD p1_bar;
extern WORD p2_bar;
extern WORD g_marker;

#define _BKGDS_BKGDPONG_OVL 0

/******************************************************************************
 Low level File IO Routines
******************************************************************************/

/******************************************************************************
 Function: int module_io_init(void)

 By: David Schwartz

 Date: March 1995

 Parameters: None

 Returns: error code (0=NONE)

 Description:   Init File IO System
******************************************************************************/
int module_io_init(void)
{
#if 0 //-SONY-
#if PC_FILE
   return(PCinit());
#else
	return(0);
#endif
#endif
	return(0);
}

/******************************************************************************
 Function: File_IO_Struct *module_os_open(char *filename)

 By: David Schwartz

 Date: March 1995

 Parameters: filename - full filename of file to open

 Returns: handle to file to access

 Description:   Open the given file in read binary mode
******************************************************************************/
File_IO_Struct *module_os_open(char *filename)
{
#if 0 //-SONY-
#if PC_FILE
	module_int=PCopen(filename,0,0);
	return(&module_int);
#else

#if _CD_ABS_OPEN_ == 0
	char fname[64];

	strcpy(fname,"\\");
	strcat(fname,filename);
	strcat(fname,";1");
	module_int=*psxcd_open(fname);
#else
	module_int=*psxcd_open(filename);
#endif

	return(&module_int);
#endif
#endif
	return(0);
}

/******************************************************************************
 Function: int module_os_read(void *destptr,int readbytes,File_IO_Struct *fileptr)

 By: David Schwartz

 Date: March 1995

 Parameters: destptr - destination to store file input
			 readbytes - # of bytes to read
			 fileptr - handle to correct file

 Returns: error code (0=None)

 Description:   Read in the correct number of bytes from a file and store data
******************************************************************************/
int module_os_read(void *destptr,int readbytes,File_IO_Struct *fileptr)
{
	if (readbytes==0)
		return(0);
#if 0 //-SONY-
#if PC_FILE
	return(PCread(*fileptr,destptr,readbytes));
#else
	return(psxcd_read(destptr,readbytes,fileptr));
#endif
#endif
	return(0);
}

/******************************************************************************
 Function: int module_os_seek(File_IO_Struct *fileptr,int seekpos,int seekmode)

 By: David Schwartz

 Date: March 1995

 Parameters: fileptr - file handle
			 seekpos - seek offset
			 seekmode - (0 - rel to start)
						(1 - rel to current fp)
						(2 - rel to end)

 Returns: error code (0=None)

 Description:   seek to position within a file
******************************************************************************/
int module_os_seek(File_IO_Struct *fileptr,int seekpos,int seekmode)
{
#if 0 //-SONY- 
#if PC_FILE
	return(PClseek(*fileptr,seekpos,seekmode));
#else
	return(psxcd_seek(fileptr,seekpos,seekmode));
#endif
#endif
	return(0);
}

/******************************************************************************
 Function: int module_os_size(File_IO_Struct *fileptr)

 By: David Schwartz

 Date: March 1995

 Parameters: fileptr - file handle

 Returns: error code (0=None)

 Description:   Determine length of file
******************************************************************************/
int module_os_size(File_IO_Struct *fileptr)
{
#if 0 //-SONY-
#if PC_FILE
	int length;
	length=PClseek(*fileptr,0,2);
	PClseek(*fileptr,0,0);  //rewind to start
	return(length);
#else
	return(fileptr->file.size);
#endif
#endif
	return(0);
}

/******************************************************************************
 Function: int module_os_close(File_IO_Struct *fileptr)

 By: David Schwartz

 Date: March 1995

 Parameters: fileptr - file handle

 Returns: error code (0=None)

 Description:   close a file
******************************************************************************/
int module_os_close(File_IO_Struct *fileptr)
{
#if 0 //-SONY-
#if PC_FILE
	return(PCclose(*fileptr));
#else
	psxcd_close(fileptr);
	return(0);
#endif
#endif
	return(0);
}

/******************************************************************************
 Routines used by code to load in files at various times
******************************************************************************/
/* indexed by load_bkgd variable */
BYTE table_o_levels[]=
{
	LVL_SUBWAY_STREET,                      // 0, subway & street
	LVL_SUBWAY_STREET,                      // 1, subway & street
	LVL_CITY,                               // 2, bank
	LVL_CITY,                               // 3, roof
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
	LVL_ARENA,								// 13, sk arena
	LVL_LAIR_ARMORY_TOMB,					// 14, armory
	LVL_FOREST,								// 15, forest
	LVL_TOWER,								// 16, tower
	LVL_MONK,								// 17, floating monk portal
	LVL_LAIR_ARMORY_TOMB,					// 18, goros lair
	LVL_LAIR_ARMORY_TOMB,					// 19, sk tomb
	0,										// 1a, NOT USED
	0,										// 1b, NOT USED
	0,										// 1c, NOT USED
	0,										// 1d, NOT USED
	0,										// 1e, NOT USED
	0,										// 1f, NOT USED
	LVL_BUYIN,                              // 20, buyin module
	LVL_HSCORE,                             // 21, not used
	LVL_LADDER,                             // 22, ladder
	LVL_VERSE,                              // 23, vs screem
	LVL_COIN,                               // 24, coin (NOT USED)
	LVL_FIRE,								// 25, fire sky
	LVL_SOUL,                               // 26, no wall
	LVL_GRADIENT,                           // 27, red color gradient for text messages
	LVL_GRADIENT,                           // 28, green color gradient for text messages
	LVL_GRADIENT,                           // 29, blue color gradient for text messages
	LVL_BUYIN,                              // 2a, mode coin page
	LVL_TITLE,                              // 2b, title screen
	LVL_SELECT,                             // 2c, player select screen
	LVL_TITLE,                              // 2d, legals
	LVL_SKEND,                              // 2e, ending SKDIE1
	LVL_SKEND,                              // 2f,  ending SKDIE2
	LVL_SKEND,                              // 30, ending SKDIEPIT
	LVL_MOCKPIT,                            // 31, mockpit level
	LVL_OPTIONS,                            // 32, dragon logo option bkgd
	LVL_OPTIONS,                            // 33, option coin screen
	LVL_TOURN,								// 34, tournament
};

/******************************************************************************
 Function: int texture_level_load(WORD level)

 By: David Schwartz

 Date: March 1995

 Parameters: level - which texture level to load

 Returns: error code (0=None)

 Description:   loads a texture file in to main memory (p2_heap is the location)
				this area should only be used as temp space as p2_heap holds player 2 textures
				also make sure that what ever is loaded in small enough to fit into p2_heap area
				otherwise problems will occur
******************************************************************************/
/* Format:      filename                                // level # */
#if _CD_ABS_OPEN_ == 0
char *level_texture_filename[]=
{
	"BKGDSART\\ARTSBST.BIN",                   // 0, subway & street
	(char *)NO_FILE,                        // 1, not used
	"BKGDSART\\ARTCITY.BIN",                   // 2, city & bank
	"BKGDSART\\ARTSOUL.BIN",                   // 3, soul & balcony & hidden nowall
	"BKGDSART\\ARTBRIG.BIN",                   // 4, bridge
	"BKGDSART\\ARTBELL.BIN",                   // 5, bell
	"BKGDSART\\ARTTEMP.BIN",                   // 6, temple
	"BKGDSART\\ARTGRAV.BIN",                   // 7, grave
	"BKGDSART\\ARTPIT.BIN",                    // 8, pit
	"BKGDSART\\ARTWATER.BIN",                  // 9, water
	"BKGDSART\\ARTCAVE.BIN",                   // 10, hades/cave
	"BKGDSART\\ARTDESRT.BIN",                  // 11, desert
	"ATTRACT\\ARTBUYIN.BIN",                // 12, buyin
	"BKGDSART\\ARTLOST.BIN",                        // 13, lost mk2
	"BKGDSART\\ARTPORTA.BIN",          		// 14, hidden portal
	"ATTRACT\\ARTHSCOR.BIN",        		// 15, high score background plate
	"ATTRACT\\ARTPSEL.BIN",                 // 16, ladder/player select
	"VS\\ARTVERSE.BIN",             		// 17, vs
	"ATTRACT\\ARTCOIN.BIN",                 // 18, coin (NOT USED)
	"ATTRACT\\ARTFIRE.BIN",                   // 19, fire (ladder part background)
	(char *)NO_FILE,                        // 20, graident (loaded elsewhere)
	"ATTRACT\\ARTTITLE.BIN",                // 21, title screen
	(char *)NO_FILE,                        // 22, not used
	"ATTRACT\\ARTNUOPT.BIN",                  // 23, dragon options logo background
	"ATTRACT\\OPTTEXT.BIN",                 // 24, options text stuff (NOT USED)
	"FXDATA\\CONTROLP.BIN",                  // 25, control panel stuff
	"FXDATA\\FONT.BIN",                      // 26, font data
	"FXDATA\\LOADING.BIN",           		// 27, loading stuff
	"BKGDSART\\ARTSKEND.BIN",  				// 28, skdie endings
	"BKGDSART\\ARTMOCK.BIN",                   // 29, mock pit
	(char *)NO_FILE,                        // 30, dream team, not used
	"BKGDSART\\ARTDEAD.BIN",				// 31, dead pool
	"BKGDSART\\ARTBATT.BIN",				// 32, battle
	"BKGDSART\\ARTARENA.BIN",				// 33, arena
	"BKGDSART\\ARTARMOR.BIN",				// 34, armory
	"BKGDSART\\ARTTREE.BIN",				// 35, forest
	"BKGDSART\\ARTTOWER.BIN",				// 36, tower
	"BKGDSART\\ARTMONK.BIN",				// 37, monk
	(char *)NO_FILE,				// 38, NOT USED
	(char *)NO_FILE,				// 39, NOT USED
	"ATTRACT\\ARTTOURN.BIN",				// 40, tournament
};
#else /* abs sector case */
char *level_texture_filename[]=
{
	(char *)NO_FILE,
};
#endif

int texture_level_load(WORD level,WORD sync)
{
	File_IO_Struct *pfile;
	int length;

	if (level_texture_filename[level]!=(char *)NO_FILE )
	{
		/* retrieve file bin data */
		pfile=module_os_open(level_texture_filename[level]);
		length=module_os_size(pfile);

		if ( sync & ASYNC_LOAD )
		{
#if _CD_VERSION_
#if SONY_CD_HACK
			psxcd_async_read(p2_heap,(length>5*2048)?5*2048:length,pfile);
			while ( psxcd_async_on() )
				process_sleep(1);
			pfile=module_os_open(level_texture_filename[level]);
#endif
			psxcd_async_read(p2_heap,length,pfile);
			return(0);
#else
#if SONY_CD_HACK
			module_os_read(p2_heap,(length>5*2048)?5*2048:length,pfile);
			pfile=module_os_open(level_texture_filename[level]);
#endif
			module_os_read(p2_heap,length,pfile);
#endif
		}
		else
		{
#if SONY_CD_HACK
			module_os_read(p2_heap,(length>5*2048)?5*2048:length,pfile);
			pfile=module_os_open(level_texture_filename[level]);
#endif
			module_os_read(p2_heap,length,pfile);
		}

		module_os_close(pfile);
		return(0);
	}
	else return(-1);

}

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
#if _CD_ABS_OPEN_==0 /* CDSEARCHFILE CASE */
char *char_texture_filename[][7]=
{
	{"KANO\\KANOB.BIN","KANO\\KANO.BIN","KANO\\KANOA.BIN","KANO\\KANOS.BIN","KANO\\KANOF.BIN",(char *)CHAR_SPECIAL_1,"VS\\VSKANO.BIN"},
	{"SONYA\\SONYAB.BIN","SONYA\\SONYA.BIN","SONYA\\SONYAA.BIN","SONYA\\SONYAS.BIN","SONYA\\SONYAF.BIN","SONYA\\SONYAF1.BIN","VS\\VSSONYA.BIN"},
	{"JAX\\JAXB.BIN","JAX\\JAX.BIN","JAX\\JAXA.BIN","JAX\\JAXS.BIN","JAX\\JAXF.BIN","JAX\\JAXF1.BIN","VS\\VSJAX.BIN"},
	{"INDIAN\\INDB.BIN","INDIAN\\IND.BIN","INDIAN\\INDA.BIN","INDIAN\\INDS.BIN","INDIAN\\INDF.BIN","INDIAN\\INDF1.BIN","VS\\VSINDIAN.BIN"},
	{"SUBZERO\\SUBZEROB.BIN","SUBZERO\\SUBZERO.BIN","SUBZERO\\SUBZEROA.BIN","SUBZERO\\SUBZEROS.BIN","SUBZERO\\SUBZEROF.BIN","SUBZERO\\SUBZERF1.BIN","VS\\VSSZ.BIN"},
	{"SWAT\\SWATB.BIN","SWAT\\SWAT.BIN","SWAT\\SWATA.BIN","SWAT\\SWATS.BIN","SWAT\\SWATF.BIN","SWAT\\SWATF1.BIN","VS\\VSSWAT.BIN"},
	{"LIA\\LIAB.BIN","LIA\\LIA.BIN","LIA\\LIAA.BIN","LIA\\LIAS.BIN",(char *)CHAR_SPECIAL_2,"LIA\\LIAF1.BIN","VS\\VSLIA.BIN"},
	{"ROBO1\\ROBO1B.BIN","ROBO1\\ROBO1.BIN","ROBO1\\ROBO1A.BIN","ROBO1\\ROBO1S.BIN","ROBO1\\ROBO1F.BIN","ROBO1\\ROBO1F1.BIN","VS\\VSROBO1.BIN"},
	{"ROBO2\\ROBO2B.BIN","ROBO2\\ROBO2.BIN","ROBO2\\ROBO2A.BIN","ROBO2\\ROBO2S.BIN","ROBO2\\ROBO2F.BIN","ROBO2\\ROBO2F1.BIN","VS\\VSROBO2.BIN"},
	{"LAO\\LAOB.BIN","LAO\\LAO.BIN","LAO\\LAOA.BIN","LAO\\LAOS.BIN","LAO\\LAOF.BIN","LAO\\LAOF1.BIN","VS\\VSLAO.BIN"},
	{"TUSK\\TUSKB.BIN","TUSK\\TUSK.BIN","TUSK\\TUSKA.BIN","TUSK\\TUSKS.BIN","TUSK\\TUSKF.BIN","TUSK\\TUSKF1.BIN","VS\\VSTUSK.BIN"},
	{"SHEEVA\\SHEEVAB.BIN","SHEEVA\\SHEEVA.BIN","SHEEVA\\SHEEVAA.BIN","SHEEVA\\SHEEVAS.BIN","SHEEVA\\SHEEVAF.BIN",(char *)CHAR_SPECIAL_4,"VS\\VSSG.BIN"},
	{"SHANG\\SHANGB.BIN","SHANG\\SHANG.BIN","SHANG\\SHANGA.BIN","SHANG\\SHANGS.BIN","SHANG\\SHANGF.BIN","SHANG\\SHANGF1.BIN","VS\\VSST.BIN"},
	{"LKANG\\LKANGB.BIN","LKANG\\LKANG.BIN","LKANG\\LKANGA.BIN","LKANG\\LKANGS.BIN","LKANG\\LKANGF.BIN","LKANG\\LKANGF1.BIN","VS\\VSLKANG.BIN"},
	{"ROBO3\\ROBO3B.BIN","ROBO3\\ROBO3.BIN","ROBO3\\ROBO3A.BIN","ROBO3\\ROBO3S.BIN","ROBO3\\ROBO3F.BIN",(char *)CHAR_SPECIAL_6,"VS\\VSROBO3.BIN"},

	{"KITANA\\KITANAB.BIN","KITANA\\KITANA.BIN","KITANA\\KITANAA.BIN","KITANA\\KITANAS.BIN","KITANA\\KITANAF.BIN","KITANA\\KITANAF1.BIN","VS\\VSKITANA.BIN"},
	{"JADE\\JADEB.BIN","JADE\\JADE.BIN","JADE\\JADEA.BIN","JADE\\JADES.BIN","JADE\\JADEF.BIN",(char *)NO_FILE,"VS\\VSJADE.BIN"},
	{"MILEENA\\MILEENAB.BIN","MILEENA\\MILEENA.BIN","MILEENA\\MILEENAA.BIN","MILEENA\\MILEENAS.BIN","MILEENA\\MILEENAF.BIN","MILEENA\\MILEENF1.BIN","VS\\VSMILEEN.BIN"},
	{"SCORPION\\SCORPB.BIN","SCORPION\\SCORPION.BIN","SCORPION\\SCORPA.BIN","SCORPION\\SCORPS.BIN","SCORPION\\SCORPF.BIN","SCORPION\\SCORPF1.BIN","VS\\VSSCORP.BIN"},
	{"REPTILE\\REPTILEB.BIN","REPTILE\\REPTILE.BIN","REPTILE\\REPTILEA.BIN","REPTILE\\REPTILES.BIN","REPTILE\\REPTILEF.BIN","REPTILE\\REPTILF1.BIN","VS\\VSREP.BIN"},
	{"ERMAC\\ERMACB.BIN","ERMAC\\ERMAC.BIN","ERMAC\\ERMACA.BIN","ERMAC\\ERMACS.BIN","ERMAC\\ERMACF.BIN","ERMAC\\ERMACF1.BIN","VS\\VSERMAC.BIN"},
	{"OLDSZ\\OLDSZB.BIN","OLDSZ\\OLDSZ.BIN","OLDSZ\\OLDSZA.BIN","OLDSZ\\OLDSZS.BIN",(char *)NO_FILE,"OLDSZ\\OLDSZF1.BIN","VS\\VSOLDSZ.BIN"},
	{"SCORPION\\SCORPB.BIN","SCORPION\\SCORPION.BIN","SCORPION\\SCORPA.BIN","SCORPION\\SCORPS.BIN",(char *)NO_FILE,(char *)NO_FILE,"VS\\VSOLDSMK.BIN"},		// same as scorpion (oldsmoke) (normal moves)
	{"SCORPION\\SCORPB.BIN","SCORPION\\SCORPION.BIN","SCORPION\\SCORPA.BIN","SCORPION\\SCORPS.BIN","SCORPION\\SCORPF.BIN","SCORPION\\SCORPF1.BIN","VS\\VSNOOB.BIN"},

	{(char *)NO_FILE,"MOTARO\\MOTARO.BIN",(char *)NO_FILE,(char *)NO_FILE,(char *)NO_FILE,(char *)NO_FILE},
	{(char *)NO_FILE,"SHAOKAHN\\SHAO.BIN",(char *)NO_FILE,"SHAOKAHN\\SHAOF.BIN",(char *)NO_FILE,(char *)NO_FILE},
};

char *char_sg_rip[]=
{
	"SHEEVA\\SGF1KN.BIN","SHEEVA\\SGF1SN.BIN","SHEEVA\\SGF1JX.BIN","SHEEVA\\SGF1IN.BIN","SHEEVA\\SGF1SZ.BIN",
	"SHEEVA\\SGF1SW.BIN","SHEEVA\\SGF1LI.BIN","SHEEVA\\SGF1RB.BIN","SHEEVA\\SGF1RB.BIN","SHEEVA\\SGF1KL.BIN",
	"SHEEVA\\SGF1TS.BIN","SHEEVA\\SGF1SG.BIN","SHEEVA\\SGF1ST.BIN","SHEEVA\\SGF1LK.BIN","SHEEVA\\SGF1RB.BIN",
	"SHEEVA\\SGF1FN.BIN","SHEEVA\\SGF1FN.BIN","SHEEVA\\SGF1FN.BIN",
	"SHEEVA\\SGF1NJ.BIN","SHEEVA\\SGF1NJ.BIN","SHEEVA\\SGF1NJ.BIN",
	"SHEEVA\\SGF1NJ.BIN","SHEEVA\\SGF1NJ.BIN","SHEEVA\\SGF1NJ.BIN",
};

char *char_kano_skel[]=
{
	"KANO\\KANOF1KN.BIN","KANO\\KANOF1SN.BIN","KANO\\KANOF1JX.BIN","KANO\\KANOF1IN.BIN","KANO\\KANOF1SZ.BIN",
	"KANO\\KANOF1SW.BIN","KANO\\KANOF1LI.BIN","KANO\\KANOF1RB.BIN","KANO\\KANOF1RB.BIN","KANO\\KANOF1KL.BIN",
	"KANO\\KANOF1TS.BIN","KANO\\KANOF1SG.BIN","KANO\\KANOF1ST.BIN","KANO\\KANOF1LK.BIN","KANO\\KANOF1RB.BIN",
	"KANO\\KANOF1FN.BIN","KANO\\KANOF1FN.BIN","KANO\\KANOF1FN.BIN",
	"KANO\\KANOF1NJ.BIN","KANO\\KANOF1NJ.BIN","KANO\\KANOF1NJ.BIN",
	"KANO\\KANOF1NJ.BIN","KANO\\KANOF1NJ.BIN","KANO\\KANOF1NJ.BIN",
};

char *char_smoke_bomb[]=
{
	"ROBO3\\RB3F1KN.BIN","ROBO3\\RB3F1SN.BIN","ROBO3\\RB3F1JX.BIN","ROBO3\\RB3F1IN.BIN","ROBO3\\RB3F1SZ.BIN",
	"ROBO3\\RB3F1SW.BIN","ROBO3\\RB3F1LI.BIN","ROBO3\\RB3F1RB.BIN","ROBO3\\RB3F1RB.BIN","ROBO3\\RB3F1KL.BIN",
	"ROBO3\\RB3F1TS.BIN","ROBO3\\RB3F1SG.BIN","ROBO3\\RB3F1ST.BIN","ROBO3\\RB3F1LK.BIN","ROBO3\\RB3F1RB.BIN"
	"ROBO3\\RB3F1FN.BIN","ROBO3\\RB3F1FN.BIN","ROBO3\\RB3F1FN.BIN",
	"ROBO3\\RB3F1NJ.BIN","ROBO3\\RB3F1NJ.BIN","ROBO3\\RB3F1NJ.BIN",
	"ROBO3\\RB3F1NJ.BIN","ROBO3\\RB3F1NJ.BIN","ROBO3\\RB3F1NJ.BIN",
};

char *char_lia_rip[]=
{
	"LIA\\LIAFKN.BIN","LIA\\LIAFSN.BIN","LIA\\LIAFJX.BIN","LIA\\LIAFIN.BIN","LIA\\LIAFSZ.BIN",
	"LIA\\LIAFSW.BIN","LIA\\LIAFLI.BIN","LIA\\LIAFRB.BIN","LIA\\LIAFRB.BIN","LIA\\LIAFKL.BIN",
	"LIA\\LIAFTS.BIN","LIA\\LIAFSG.BIN","LIA\\LIAFST.BIN","LIA\\LIAFLK.BIN","LIA\\LIAFRB.BIN"
	"LIA\\LIAFFN.BIN","LIA\\LIAFFN.BIN","LIA\\LIAFFN.BIN",
	"LIA\\LIAFNJ.BIN","LIA\\LIAFNJ.BIN","LIA\\LIAFNJ.BIN",
	"LIA\\LIAFNJ.BIN","LIA\\LIAFNJ.BIN","LIA\\LIAFNJ.BIN",
};
#else /* ABS SECTOR CASE */
char *char_texture_filename[][7]=
{
	{(char *)_KANO_KANOB_BIN,(char *)_KANO_KANO_BIN,(char *)_KANO_KANOA_BIN,(char *)_KANO_KANOS_BIN,(char *)_KANO_KANOF_BIN,(char *)CHAR_SPECIAL_1,(char *)_VS_VSKANO_BIN},
	{(char *)_SONYA_SONYAB_BIN,(char *)_SONYA_SONYA_BIN,(char *)_SONYA_SONYAA_BIN,(char *)_SONYA_SONYAS_BIN,(char *)_SONYA_SONYAF_BIN,(char *)_SONYA_SONYAF1_BIN,(char *)_VS_VSSONYA_BIN},
	{(char *)_JAX_JAXB_BIN,(char *)_JAX_JAX_BIN,(char *)_JAX_JAXA_BIN,(char *)_JAX_JAXS_BIN,(char *)_JAX_JAXF_BIN,(char *)_JAX_JAXF1_BIN,(char *)_VS_VSJAX_BIN},
	{(char *)_INDIAN_INDB_BIN,(char *)_INDIAN_IND_BIN,(char *)_INDIAN_INDA_BIN,(char *)_INDIAN_INDS_BIN,(char *)_INDIAN_INDF_BIN,(char *)_INDIAN_INDF1_BIN,(char *)_VS_VSINDIAN_BIN},
	{(char *)_SUBZERO_SUBZEROB_BIN,(char *)_SUBZERO_SUBZERO_BIN,(char *)_SUBZERO_SUBZEROA_BIN,(char *)_SUBZERO_SUBZEROS_BIN,(char *)_SUBZERO_SUBZEROF_BIN,(char *)_SUBZERO_SUBZERF1_BIN,(char *)_VS_VSSZ_BIN},
	{(char *)_SWAT_SWATB_BIN,(char *)_SWAT_SWAT_BIN,(char *)_SWAT_SWATA_BIN,(char *)_SWAT_SWATS_BIN,(char *)_SWAT_SWATF_BIN,(char *)_SWAT_SWATF1_BIN,(char *)_VS_VSSWAT_BIN},
	{(char *)_LIA_LIAB_BIN,(char *)_LIA_LIA_BIN,(char *)_LIA_LIAA_BIN,(char *)_LIA_LIAS_BIN,(char *)CHAR_SPECIAL_2,(char *)_LIA_LIAF1_BIN,(char *)_VS_VSLIA_BIN},
	{(char *)_ROBO1_ROBO1B_BIN,(char *)_ROBO1_ROBO1_BIN,(char *)_ROBO1_ROBO1A_BIN,(char *)_ROBO1_ROBO1S_BIN,(char *)_ROBO1_ROBO1F_BIN,(char *)_ROBO1_ROBO1F1_BIN,(char *)_VS_VSROBO1_BIN},
	{(char *)_ROBO2_ROBO2B_BIN,(char *)_ROBO2_ROBO2_BIN,(char *)_ROBO2_ROBO2A_BIN,(char *)_ROBO2_ROBO2S_BIN,(char *)_ROBO2_ROBO2F_BIN,(char *)_ROBO2_ROBO2F1_BIN,(char *)_VS_VSROBO2_BIN},
	{(char *)_LAO_LAOB_BIN,(char *)_LAO_LAO_BIN,(char *)_LAO_LAOA_BIN,(char *)_LAO_LAOS_BIN,(char *)_LAO_LAOF_BIN,(char *)_LAO_LAOF1_BIN,(char *)_VS_VSLAO_BIN},
	{(char *)_TUSK_TUSKB_BIN,(char *)_TUSK_TUSK_BIN,(char *)_TUSK_TUSKA_BIN,(char *)_TUSK_TUSKS_BIN,(char *)_TUSK_TUSKF_BIN,(char *)_TUSK_TUSKF1_BIN,(char *)_VS_VSTUSK_BIN},
	{(char *)_SHEEVA_SHEEVAB_BIN,(char *)_SHEEVA_SHEEVA_BIN,(char *)_SHEEVA_SHEEVAA_BIN,(char *)_SHEEVA_SHEEVAS_BIN,(char *)_SHEEVA_SHEEVAF_BIN,(char *)CHAR_SPECIAL_4,(char *)_VS_VSSG_BIN},
	{(char *)_SHANG_SHANGB_BIN,(char *)_SHANG_SHANG_BIN,(char *)_SHANG_SHANGA_BIN,(char *)_SHANG_SHANGS_BIN,(char *)_SHANG_SHANGF_BIN,(char *)_SHANG_SHANGF1_BIN,(char *)_VS_VSST_BIN},
	{(char *)_LKANG_LKANGB_BIN,(char *)_LKANG_LKANG_BIN,(char *)_LKANG_LKANGA_BIN,(char *)_LKANG_LKANGS_BIN,(char *)_LKANG_LKANGF_BIN,(char *)_LKANG_LKANGF1_BIN,(char *)_VS_VSLKANG_BIN},
	{(char *)_ROBO3_ROBO3B_BIN,(char *)_ROBO3_ROBO3_BIN,(char *)_ROBO3_ROBO3A_BIN,(char *)_ROBO3_ROBO3S_BIN,(char *)_ROBO3_ROBO3F_BIN,(char *)CHAR_SPECIAL_6,(char *)_VS_VSROBO3_BIN},
	{(char *)NO_FILE,(char *)_MOTARO_MOTARO_BIN,(char *)NO_FILE,(char *)NO_FILE,(char *)NO_FILE,(char *)NO_FILE},
	{(char *)NO_FILE,(char *)_SHAOKAHN_SHAO_BIN,(char *)NO_FILE,(char *)_SHAOKAHN_SHAOF_BIN,(char *)NO_FILE,(char *)NO_FILE},
	{(char *)NO_FILE,(char *)_KANO_KANO_BIN,(char *)NO_FILE,(char *)NO_FILE,(char *)NO_FILE,(char *)NO_FILE}
};

char *char_sg_rip[]=
{
	(char *)_SHEEVA_SGF1KN_BIN,(char *)_SHEEVA_SGF1SN_BIN,(char *)_SHEEVA_SGF1JX_BIN,(char *)_SHEEVA_SGF1IN_BIN,(char *)_SHEEVA_SGF1SZ_BIN,
	(char *)_SHEEVA_SGF1SW_BIN,(char *)_SHEEVA_SGF1LI_BIN,(char *)_SHEEVA_SGF1RB_BIN,(char *)_SHEEVA_SGF1RB_BIN,(char *)_SHEEVA_SGF1KL_BIN,
	(char *)_SHEEVA_SGF1TS_BIN,(char *)_SHEEVA_SGF1SG_BIN,(char *)_SHEEVA_SGF1ST_BIN,(char *)_SHEEVA_SGF1LK_BIN,(char *)_SHEEVA_SGF1RB_BIN
};

char *char_kano_skel[]=
{
	(char *)_KANO_KANOF1KN_BIN,(char *)_KANO_KANOF1SN_BIN,(char *)_KANO_KANOF1JX_BIN,(char *)_KANO_KANOF1IN_BIN,(char *)_KANO_KANOF1SZ_BIN,
	(char *)_KANO_KANOF1SW_BIN,(char *)_KANO_KANOF1LI_BIN,(char *)_KANO_KANOF1RB_BIN,(char *)_KANO_KANOF1RB_BIN,(char *)_KANO_KANOF1KL_BIN,
	(char *)_KANO_KANOF1TS_BIN,(char *)_KANO_KANOF1SG_BIN,(char *)_KANO_KANOF1ST_BIN,(char *)_KANO_KANOF1LK_BIN,(char *)_KANO_KANOF1RB_BIN
};

char *char_smoke_bomb[]=
{
	(char *)_ROBO3_RB3F1KN_BIN,(char *)_ROBO3_RB3F1SN_BIN,(char *)_ROBO3_RB3F1JX_BIN,(char *)_ROBO3_RB3F1IN_BIN,(char *)_ROBO3_RB3F1SZ_BIN,
	(char *)_ROBO3_RB3F1SW_BIN,(char *)_ROBO3_RB3F1LI_BIN,(char *)_ROBO3_RB3F1RB_BIN,(char *)_ROBO3_RB3F1RB_BIN,(char *)_ROBO3_RB3F1KL_BIN,
	(char *)_ROBO3_RB3F1TS_BIN,(char *)_ROBO3_RB3F1SG_BIN,(char *)_ROBO3_RB3F1ST_BIN,(char *)_ROBO3_RB3F1LK_BIN,(char *)_ROBO3_RB3F1RB_BIN
};

char *char_lia_rip[]=
{
	(char *)_LIA_LIAFKN_BIN,(char *)_LIA_LIAFSN_BIN,(char *)_LIA_LIAFJX_BIN,(char *)_LIA_LIAFIN_BIN,(char *)_LIA_LIAFSZ_BIN,
	(char *)_LIA_LIAFSW_BIN,(char *)_LIA_LIAFLI_BIN,(char *)_LIA_LIAFRB_BIN,(char *)_LIA_LIAFRB_BIN,(char *)_LIA_LIAFKL_BIN,
	(char *)_LIA_LIAFTS_BIN,(char *)_LIA_LIAFSG_BIN,(char *)_LIA_LIAFST_BIN,(char *)_LIA_LIAFLK_BIN,(char *)_LIA_LIAFRB_BIN
};

#endif
int character_texture_load(WORD pchar,WORD type,void *dest,WORD sync)
{
	File_IO_Struct *pfile;
	int length;

	/* pick correct case */
	switch ((LONG)char_texture_filename[pchar][type])
	{
		case NO_FILE:
			return(0);
		case CHAR_SPECIAL_1:                    // KANO SKEL RIP
			pfile=module_os_open(char_kano_skel[(current_proc->pdata.p_otherguy)->ochar]);
			break;
		case CHAR_SPECIAL_2:                    // LIA SKIN RIP
			pfile=module_os_open(char_lia_rip[(current_proc->pdata.p_otherguy)->ochar]);
			break;
		case CHAR_SPECIAL_4:                    // SHEEVA RIP
			pfile=module_os_open(char_sg_rip[(current_proc->pdata.p_otherguy)->ochar]);
			break;
		case CHAR_SPECIAL_6:                    // SMOKE BOMB
			pfile=module_os_open(char_smoke_bomb[(current_proc->pdata.p_otherguy)->ochar]);
			break;
		default:                // NORMAL LOAD
			pfile=module_os_open(char_texture_filename[pchar][type]);
			break;
	}

	length=module_os_size(pfile);

#if 0 //-SONY-
	if ( sync & FATAL_LOAD)
	{
		/* set correct dest ptr */
		((BYTE *)dest)-=length;                                                 // set dest ptr back length
		dest-=((LONG)dest & 0x3);                                               // make sure we are LONG aligned
		finish_heap_ptr=dest;                                                   // set finish to correct position
	}
#endif

	if ( sync & ASYNC_LOAD )
	{
#if _CD_VERSION_
		psxcd_async_read(dest,length,pfile);
		return(0);
#else
		module_os_read(dest,length,pfile);
#endif
	}
	else module_os_read(dest,length,pfile);

	module_os_close(pfile);

	return(0);
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
#if _CD_ABS_OPEN_ == 0 /* searchfile case */
char *texture_fx[]=
{
	"FXDATA\\FATAL.BIN",
	"FXDATA\\ANIMAL.BIN",
	"FXDATA\\FRIEND.BIN",
	"FXDATA\\BABY.BIN"
};
#else  /* ABS SECTOR CASE */
char *texture_fx[]=
{
	(char *)_FXDATA_FATAL_BIN,
	(char *)_FXDATA_ANIMAL_BIN,
	(char *)_FXDATA_FRIEND_BIN,
	(char *)_FXDATA_BABY_BIN
};
#endif

BYTE *special_fx_load(WORD fxtype)
{
	File_IO_Struct *pfile;
	int length;
	BYTE *dest;

	/* retrieve file bin data */
	pfile=module_os_open(texture_fx[fxtype]);
	length=module_os_size(pfile);
	/* place art at end of loser buffer */
	if ((LONG *)finish_heap_ptr>=(LONG *)p2_heap)
	{
		/* player 1 lost, stick at end of his heap */
		dest=(BYTE*)p2_heap-length;                            // place at end of p1 heap minus size of data to load
	}
	else
	{
		/* player 2 lost, stick at end of his heap */
		dest=((BYTE*)&player_heap[PLAYER_HEAP_SIZE/sizeof(long long)])-length;                             // place at end of heap minus size of data
	}

	dest-=((LONG)dest & 0x3);                                               // make sure we are LONG aligned

	/* load up art */
#if _CD_VERSION_
	psxcd_async_read(dest,length,pfile);

	while (psxcd_async_on())                                        // allow other processes to run during load
	{
		process_sleep(1);
	}

#else
	module_os_read(dest,length,pfile);
#endif

	module_os_close(pfile);

	return(dest);
}

/******************************************************************************
 Function: int generic_overlay_load(WORD overnum)

 By: David Schwartz

 Date: March 1995

 Parameters: overnum - which overlay number to load

 Returns: error code (0=None)

 Description:   load specified overlay to correct area
******************************************************************************/
extern char *pheap_loadaddr;
extern char *level_loadaddr;
#if _CD_ABS_OPEN_==0 /* CD SEARCHFILE CASE */
OVL goverlay_table[]=
{
	{&pheap_loadaddr,"OVERLAY\\MKSELVIC.BIN"},                      // ovl 0 - select screen character stances & victories
	{&pheap_loadaddr,"ATTRACT\\MKNUOPT.BIN"},                      // ovl 1 - options graphics
	{&level_loadaddr,"BKGDSOVL\\BKGDMARK.OVL"},                         // ovl 2 - 'space invaders'
	{&level_loadaddr,"BKGDSOVL\\BKGDPONG.OVL"},                         // ovl 3 - 'pong'
	{&pheap_loadaddr,"OVERLAY\\END1.BIN"},                      // ovl 4 - some cast members
	{&pheap_loadaddr,"OVERLAY\\END2.BIN"},                      // ovl 5 - some cast members
	{&pheap_loadaddr,"OVERLAY\\END3.BIN"},                      // ovl 6 - some cast members
	{&pheap_loadaddr,"OVERLAY\\END4.BIN"},                      // ovl 7 - some cast members
	{&pheap_loadaddr,"OVERLAY\\END5.BIN"},                      // ovl 8 - some cast members
	{&pheap_loadaddr,"OVERLAY\\END6.BIN"},                      // ovl 9 - some cast members
};
#else
OVL goverlay_table[]=
{
	{&pheap_loadaddr,(char *)_OVERLAY_MKSELVIC_BIN},                        // ovl 0 - select screen character stances & victories
	{&pheap_loadaddr,(char *)_ATTRACT_MKOPTION_BIN},                        // ovl 1 - options graphics
	{&level_loadaddr,(char *)_BKGDS_BKGDMARK_OVL},                           // ovl 2 - 'space invaders'
	{&level_loadaddr,(char *)_BKGDS_BKGDPONG_OVL}                           // ovl 2 - 'space invaders'
};
#endif
int generic_overlay_load(WORD overnum)
{
	File_IO_Struct *pfile;
	int length;

	/* retrieve file data */
	pfile=module_os_open(goverlay_table[overnum].ovl_file);

#if 0 //-SONY- 
	/* flush for overlays, cache coherency */
	psxcd_stop();
	while ( psxcd_waiting_for_pause() ); //POLLING;
	CdFlush();

#if DRAW_HACK
	DrawSync(0);
#endif

	EnterCriticalSection();
	FlushCache();
	ExitCriticalSection();
#endif
	length=module_os_size(pfile);
#if SONY_CD_HACK
	module_os_read(*goverlay_table[overnum].ovl_addr,(length>5*2048)?5*2048:length,pfile);                  // for sony error that reads bad 1st sector once in blue moon
	pfile=module_os_open(goverlay_table[overnum].ovl_file);
#endif
	module_os_read(*goverlay_table[overnum].ovl_addr,length,pfile);
	module_os_close(pfile);

	return(0);
}

int async_overlay_load(WORD overnum)
{
	int length;
	/* retrieve file data */
	module_os_open(goverlay_table[overnum].ovl_file);
	length=module_os_size(&module_int);
#if _CD_VERSION_
	psxcd_async_read(*goverlay_table[overnum].ovl_addr,length,&module_int);         // start async read
#else
	module_os_read(*goverlay_table[overnum].ovl_addr,length,&module_int);           // start async read
#endif
	return(0);
}

/******************************************************************************
 Function: int level_overlay_load(WORD level)

 By: David Schwartz

 Date: March 1995

 Parameters: level - level number to load

 Returns: error code (0=None)

 Description:   load specified background level code overlay to correct area
******************************************************************************/
#if _CD_ABS_OPEN_ == 0 /* SEARCHFILE CASE */
char *level_overlay_table[]=
{
	"BKGDSOVL\\BKGDSBST.OVL",                  // ovl 00 - SUBWAY & STREET
	(char *)NO_FILE,                        // ovl 01 - UNUSED
	"BKGDSOVL\\BKGDCITY.OVL",                  // ovl 02 - CITY & BANK
	"BKGDSOVL\\BKGDSOUL.OVL",                  // ovl 03 - SOUL & BALCONY & HIDDEN NOWALL
	"BKGDSOVL\\BKGDBRIG.OVL",                  // ovl 04 - BRIDGE
	"BKGDSOVL\\BKGDBELL.OVL",                  // ovl 05 - BELL
	"BKGDSOVL\\BKGDTEMP.OVL",                  // ovl 06 - TEMPLE
	"BKGDSOVL\\BKGDGRAV.OVL",                  // ovl 07 - GRAVE
	"BKGDSOVL\\BKGDPIT.OVL",                   // ovl 08 - PIT
	"BKGDSOVL\\BKGDWATR.OVL",                        // ovl 09 - WATER
	"BKGDSOVL\\BKGDCAVE.OVL",                        // ovl 10 - HADES & CAVE
	"BKGDSOVL\\BKGDESRT.OVL",                        // ovl 11 - DESERT
	"ATTRACT\\MKBUYDT.OVL",                 // ovl 12 - BUYIN SCREEN
	"BKGDSOVL\\BKGDLOST.OVL",                        // ovl 13 - LOST MK2
	"BKGDSOVL\\BKGDPORT.OVL",                  // ovl 14 - hidden portal level
	"ATTRACT\\MKHSCORE.OVL",                // ovl 15 - High SCore
	"ATTRACT\\MKPSEL.OVL",                  // ovl 16 - SELECT/LADDER
	"VS\\MKVERSE.OVL",                      // ovl 13 - VERSE SCREEN (BACKGROUND)
	(char*)NO_FILE,                  // ovl 18 - COIN (NOT USED)
	"ATTRACT\\MKFIRE.OVL",                        // ovl 19 - FIRE PORTAL
	"ATTRACT\\MKGRAD.OVL",                  // ovl 20 - gradients
	"ATTRACT\\MKTITLE.OVL",                 // ovl 21 - Title
	(char *)NO_FILE,                        // ovl 22 - not use
	(char *)NO_FILE,                        // ovl 23 - NONE, options
	(char *)NO_FILE,                        // ovl 24 - NONE, opttext
	(char *)NO_FILE,                        // ovl 25 - NONE, control
	(char *)NO_FILE,                        // ovl 26 - NONE, fonts
	(char *)NO_FILE,                        // ovl 27 - NONE, loading
	"BKGDSOVL\\BKGDSKEN.OVL",                  // ovl 28 - skdie endings
	"BKGDSOVL\\BKGDMOCK.OVL",                  // ovl 20 - MOCK PIT
	"ATTRACT\\MKDTEAM.OVL",                 // ovl 30 - DREAM TEAM
	"BKGDSOVL\\MKDEAD.OVL",				// 31, dead pool
	"BKGDSOVL\\MKBATTLE.OVL",			// 32, battle
	"BKGDSOVL\\MKARENA.OVL",			// 33, arena
	"BKGDSOVL\\MKARMOR.OVL",			// 34, armory
	"BKGDSOVL\\MKTREE.OVL",				// 35, forest
	"BKGDSOVL\\MKTOWER.OVL",			// 36, tower
	"BKGDSOVL\\MKMONK.OVL",				// 37, monk
	(char *)NO_FILE,				// 38, NOT USED
	(char *)NO_FILE,				// 39, NOT USED
	"ATTRACT\\MKTOURN.OVL",				// 40, tournament
};
#else /* ABS SECTOR CASE */
char *level_overlay_table[]=
{
	(char *)NO_FILE,
};
#endif

int level_overlay_load(WORD level)
{
	File_IO_Struct *pfile;
	int length;

	/* make sure we have a valid level */
	length=sizeof(level_overlay_table)/sizeof(level_overlay_table[0]);
	if (level>=sizeof(level_overlay_table)/sizeof(level_overlay_table[0]))
		return(-1);

	/* make sure there is something to load */
	if ( level_overlay_table[level]==(char *)NO_FILE )
		return(0);

	/* retrieve file ovl data */
#if 0 //-SONY- 

	/* flush for overlays, cache coherency */
	psxcd_stop();
	while ( psxcd_waiting_for_pause() ) ;
  CdFlush();

#if DRAW_HACK
	DrawSync(0);
#endif


	EnterCriticalSection();
	FlushCache();
	ExitCriticalSection();
#endif

	pfile=module_os_open(level_overlay_table[level]);
	length=module_os_size(pfile);

#if SONY_CD_HACK
	module_os_read(level_loadaddr,(length>5*2048)?5*2048:length,pfile);
	pfile=module_os_open(level_overlay_table[level]);
#endif
	module_os_read(level_loadaddr,length,pfile);

	module_os_close(pfile);

	return(0);
}

extern WORD displayon;
extern WORD LOADING_P[];
void file_load_message(WORD load_num)
{
	if (system_marker==SYSTEM_INIT_MARKER)
	{
		f_load=load_num;
#if VS_OFF
		clr_scrn();
		DISPLAY_ON;
#endif
		//-SONY- get_fore_pal(LOADING_P);
		process_sleep(2);
	}

	return;
}
