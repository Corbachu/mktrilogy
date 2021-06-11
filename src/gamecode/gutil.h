//////////////////////////////////////////////////////////////////////////////////////////
// gutil.h
//
// Author: David Schwartz
//////////////////////////////////////////////////////////////////////////////////////////
// THIS CODE IS PROPRIETARY PROPERTY OF WILLIAMS ENTERTAINMENT.
//
// The contents of this file may not be disclosed to third
// parties, copied or duplicated in any form, in whole or in part,
// without the prior written permission of Williams Entertainment.
//////////////////////////////////////////////////////////////////////////////////////////

#ifndef GUTIL_H
#define GUTIL_H 1



//========================================================================================
// Public definitions:

/* modulate environment color with primitive color */
#define G_CC_ENV_MODULATE_PRIM	ENVIRONMENT, 0, PRIMITIVE, 0, ENVIRONMENT, 0, PRIMITIVE, 0

/* same as G_RM_AA_ZB_XLU_SURF, but with z-buffer updating */
#define	RM_AA_ZBUPDATE_XLU_SURF(clk)					\
	AA_EN | Z_CMP | Z_UPD | IM_RD | CVG_DST_WRAP | CLR_ON_CVG |	\
	FORCE_BL | ZMODE_XLU |					\
	GBL_c##clk(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA)
#define	G_RM_AA_ZBUPDATE_XLU_SURF	RM_AA_ZBUPDATE_XLU_SURF(1)
#define	G_RM_AA_ZBUPDATE_XLU_SURF2	RM_AA_ZBUPDATE_XLU_SURF(2)

#define TMEM_TEXTURE_SIZE	2048

//========================================================================================
// Public data:

//extern short gutil_screenshift_x;			// global x screen shift (pixels)
//extern short gutil_screenshift_y;			// global y screen shift (pixels)

extern Gfx gutil_gfxinit[];
//extern Vtx gutil_box_vtx[4];
//extern Vtx gutil_cbox_vtx[4];


//========================================================================================
// Public functions:

//////////////////////////////////////////////////////////////////////////////////////////
// gutil_clear_screen - clears the entire screen to the specified RGBA color. color is
//                      in GPACK_RGBA5551 format (see gbi.h). player is the player number
//                      of the portion of the screen to clear. If player is -1, a full
//                      screen clear is forced, regardless of the player mode.
//////////////////////////////////////////////////////////////////////////////////////////
void gutil_clear_screen(unsigned short color,unsigned short start,unsigned short lines ) ;


//////////////////////////////////////////////////////////////////////////////////////////
// gutil_init_zbuf - initializes the zbuffer. Note that gDPSetColorImage is changed.
//////////////////////////////////////////////////////////////////////////////////////////
extern void gutil_init_zbuf( void );


//////////////////////////////////////////////////////////////////////////////////////////
// gutil_clear_2player_gap - clears the region between the player 1 and player 2 view
//                           screens. The caller must first test Players to make sure
//                           the game is operating in 2-player mode; this function
//                           performs no checks.
//////////////////////////////////////////////////////////////////////////////////////////
extern void gutil_clear_2player_gap( void );

void gutil_draw_line(WORD line,LONG color);
void gutil_draw_box(short x,short y,WORD w,WORD h,WORD color);
void gutil_draw_xlu_box(short x,short y,WORD w,WORD h,WORD color,WORD xlu);

//////////////////////////////////////////////////////////////////////////////////////////
// gutil_set_viewport - sets the specified RDP viewport.
//
//					    IMPORTANT: no gDPPipeSync is inserted into the pipeline.
//////////////////////////////////////////////////////////////////////////////////////////
extern void gutil_set_viewport( Vp *vp, short dx, short dy );


//////////////////////////////////////////////////////////////////////////////////////////
// gutil_set_scissor - sets up the RDP scissoring box for the specified player.
//                     If player is -1, full-screen (single player) is forced.
//////////////////////////////////////////////////////////////////////////////////////////
extern void gutil_set_scissor( int player );


//////////////////////////////////////////////////////////////////////////////////////////
// gutil_box - displays a box of the given pixel dimensions (h, v) at the given screen
//             x,y coordinate (16.16 format). x,y are upper-left corner of box. r, g, b,
//             and a are the 8-bit red, green, blue, and alpha color of the box.
//
// IMPORTANT: There is a known bug with this function. The box is displayed one line
//            lower than specified. I don't want to fix this in Cruis'n because too
//            much work would be involved in adjusting all the wrappers that use
//            gutil_box and gutil_smokebox.
//////////////////////////////////////////////////////////////////////////////////////////
extern void gutil_box( int h, int v, int x, int y, u32 r, u32 g, u32 b, u32 a );


//////////////////////////////////////////////////////////////////////////////////////////
// gutil_smokebox - displays a smokebox of the given pixel dimensions (h, v) at the given
//                  screen x,y coordinate (16.16 format). x,y are upper-left corner of box.
//
// IMPORTANT: Read note on gutil_box function for bug info.
//////////////////////////////////////////////////////////////////////////////////////////
extern void gutil_smokebox( int h, int v, int x, int y );


//////////////////////////////////////////////////////////////////////////////////////////
// gutil_color_vertices - changes the color of the specified vertices to the specified
//                        color. vp is a pointer to the first vertex and numv is the
//                        number of contiguous vertices to color.
//////////////////////////////////////////////////////////////////////////////////////////
extern void gutil_color_vertices( Vtx *vp, int numv, int r, int g, int b );


//////////////////////////////////////////////////////////////////////////////////////////
// gutil_light_vertices - changes the intensity of the specified vertices to the specified
//                        shade of gray. vp is a pointer to the first vertex and numv is
//                        the number of contiguous vertices to color.
//////////////////////////////////////////////////////////////////////////////////////////
extern void gutil_light_vertices( Vtx *vp, int numv, int intensity );


//////////////////////////////////////////////////////////////////////////////////////////
// gutil_draw_xlated - builds and pushes a matrix for the specified translation and pushes
//                     it on the graphics pipeline. The specified display list is then
//                     executed and the matrix is popped.
//////////////////////////////////////////////////////////////////////////////////////////
extern void gutil_draw_xlated( Gfx *dlist, int x, int y, int z, int scale );


///////////////////////////////////////////////////////////////////////////////
// gutil_draw_yrot_xlated
//	builds and pushes a matrix for the specified y-rotation and translation
//	and pushes it on the graphics pipeline.  The specified display list is
//	then executed and the matrix is popped.
///////////////////////////////////////////////////////////////////////////////
extern void gutil_draw_yrot_xlated( Gfx *dlist, int turn, int x, int y, int z);


//////////////////////////////////////////////////////////////////////////////////////////
// gutil_copy_fbuf - Inserts Gfx commands that use the RDP to copy the specified
//                   320x240 frame buffer to the specified destination location.
//////////////////////////////////////////////////////////////////////////////////////////
extern void gutil_copy_fbuf( u32 destbuf, u32 srcbuf );


//////////////////////////////////////////////////////////////////////////////////////////
// gutil_display_vbox - displays the rotating viewbox that exposes the track. angle is
//                      the CCW angle of the box.
//////////////////////////////////////////////////////////////////////////////////////////
extern void gutil_display_vbox( int angle );


#endif
