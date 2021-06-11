/******************************************************************************
 File: mkpal.h

 By: David Schwartz

 Date: August 1994

 (C) Williams Entertainment

 Mortal Kombat III pal Header 
******************************************************************************/

#ifndef __mk_mkpal_h__
#define __mk_mkpal_h__

/* 
 * 	DEFINITIONS
 */
#define NUM_F_PALS 47	//128								/* # of foreground palettes */
#define NUM_B_PALS 47	//128								/* # of background palettes */
#define NUM_PALS	(NUM_F_PALS+NUM_B_PALS)			/* # of dynamic allocated palettes */


#define PALQ_MAX_ENTRY NUM_PALS							/* # of entries in palette transfer queue */

#define UNKNOWN_PAL 0xffff						// returned value if cant find palette (findpal)
#define END_STUFF 0x0000						// ending flptr stuff, (0000 should never be a color used */

typedef struct p_palqent {
	WORD index;										/* dest index into buffer */
	WORD count;										/* # of entries */
	ADDRESS *csrc;									/* src address of clut */
} PALQENT;

typedef struct p_palinfo {
	WORD *palid;										/* palette id (unique identifier palette data) */
	short palcnt;									/* palette allocation count (# of objs using pal) */
	WORD paltime;									/* @tick value when this palette was deleted */
} PALINFO;

/* 
 *	RAM 
 */
__EXTERN__ PALQENT paltrans_queue[PALQ_MAX_ENTRY];	/* transfer queue */
__EXTERN__ PALQENT *paltrans_start;					/* start ptr in transfer que */
__EXTERN__ PALQENT *paltrans_end;					/* end ptr in transfer que */

__EXTERN__ PALINFO palram[NUM_PALS];
__EXTERN__ u64 pal_buffer[(2*NUM_PALS*256)/sizeof(u64)];	// storage area to keep active palettes (need to do this way in order to color cycle and stuff)

#if DEBUG
__EXTERN__ WORD usefpcnt;							/* # of fore pals being used */
__EXTERN__ WORD usebpcnt;							/* # of back pals being used */
#endif

/*
 *	PROTOTYPES 
 */
void init_paltrans_queue(void);
WORD findpal(WORD*);
void clear_pal(void);
void clear_fore_pal(void);
void clear_back_pal(void);
WORD get_fore_pal(WORD *);
WORD get_back_pal(WORD *);
void free_pal(WORD);
void copy_pal(OBJECT *obj,WORD palid);
void color_cycle(WORD *pal,WORD dir);

//-SONY_IGNORE- void palset_xfer(WORD,WORD,WORD *);
void palset_xfer(WORD,WORD *);

//-SONY_IGNORE- void unget_pal(WORD);
//-SONY_IGNORE- void blow_pal(WORD*);

void transfer_palettes(void);

/* perm pals located in imgpal.s, if add update mkchar.inc */
extern WORD bpal_black_P[];
extern WORD bpal_red_P[];
extern WORD bpal_white_P[];
extern WORD bpal_flash1_P[];
extern WORD bpal_flash2_P[];
extern WORD bpal_flash3_P[];
extern WORD bpal_flash4_P[];
extern WORD bpal_flash5_P[];
extern WORD SCORE_P[];
extern WORD BLOOD_P[];
extern WORD OIL_P[];
extern WORD SHEEBL_P[];
extern WORD WHITE_p[];

/*
 *	MACROS
 */
#define fpalram palram
#define bpalram (palram+NUM_F_PALS)

#define get_back_pal get_fore_pal

#define delpal(p)	free_pal(p->opal)

#define cycle_forward(_pa0) color_cycle(_pa0,0)
#define cycle_backward(_pa0) color_cycle(_pa0,1)

#endif /* __mk_mkpal_h__ */


