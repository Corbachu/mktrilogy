//////////////////////////////////////////////////////////////////////////////////////////
// gutil.c - General purpose graphic functions.
//
// Author: David Schwartz
//////////////////////////////////////////////////////////////////////////////////////////
// THIS CODE IS PROPRIETARY PROPERTY OF WILLIAMS ENTERTAINMENT.
//
// The contents of this file may not be disclosed to third
// parties, copied or duplicated in any form, in whole or in part,
// without the prior written permission of Williams Entertainment.
//////////////////////////////////////////////////////////////////////////////////////////
#define SCIS	0

#include <ultra64.h>

#include "u64main.h"

#include "sys_defs.h"

#include "sys.h"
#include "gutil.h"
#include "gdefaults.h"
#include "gamepad.h"
#include "mkfade.h"
#include "mkbkgd.h"
#include "mkobj.h"

/* gutil_defs */
#define GUTIL_SMOKEBOX_COLOR		20		// smaller number means darker black
#define GUTIL_SMOKEBOX_ALPHA		150		// smaller number means more transparent

// The following macros expand to gSPSetOtherMode commands, shadowed in the RSP:
//
// gDPPipelineMode
// gDPSetCycleType
// gDPSetTexturePersp
// gDPSetTextureDetail
// gDPSetTextureLOD
// gDPSetTextureLUT
// gDPSetTextureFilter
// gDPSetTextureConvert
// gDPSetCombineKey
// gDPSetColorDither
// gDPSetAlphaDither
// gDPSetAlphaCompare
// gDPSetDepthSource
// gDPSetRenderMode

//========================================================================================
// Public data:

Gfx gutil_gfxinit[] = {
	gsDPPipeSync(),
	gsDPSetCycleType_default,
	gsDPPipelineMode_default,
	gsDPSetTextureLOD_default,
	gsDPSetTextureLUT_default,
	gsDPSetTextureDetail_default,		// is this needed???
	gsDPSetTexturePersp_default,
	gsDPSetTextureFilter_default,
	gsDPSetTextureConvert_default,
	gsDPSetCombineMode_default,
	gsDPSetCombineKey_default,

	gsDPSetAlphaCompare_default,
	gsDPSetAlphaDither_default,

	gsDPSetRenderMode_default,
	gsDPSetColorDither_default,
	gsDPSetDepthSource_default,
	gsDPSetBlendColor_default,
	gsDPSetPrimColor_default,

	gsSPSegment( SYS_RSPSEG_PHYSICAL, 0 ),
	gsSPClearGeometryMode( G_ZBUFFER | G_SHADE | G_SHADING_SMOOTH | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD ),
	gsSPSetGeometryMode( G_SHADE | G_SHADING_SMOOTH ),
	gsSPTexture_default,
	gsSPPerspNormalize_default,
    gsDPPipeSync(),

	gsSPEndDisplayList(),
};

WORD gmode;

//========================================================================================
// Private data:


//========================================================================================
// Public functions:

//////////////////////////////////////////////////////////////////////////////////////////
// gutil_clear_screen - clears the entire screen to the specified RGBA color. color is
//                      in GPACK_RGBA5551 format (see gbi.h). player is the player number
//                      of the portion of the screen to clear. If player is -1, a full
//                      screen clear is forced, regardless of the player mode.
//////////////////////////////////////////////////////////////////////////////////////////
void gutil_clear_screen(unsigned short color,unsigned short start,unsigned short lines ) 
{
	gDPPipeSync( Glp++ );
	gDPSetCycleType( Glp++, G_CYC_FILL );
	gDPSetRenderMode( Glp++, G_RM_NOOP,G_RM_NOOP);
	gDPSetFillColor( Glp++, color<<16 | color );
	gDPSetScissor( Glp++, GUTIL_DPSetScissorMode, 0,0,BUFFER_WIDTH-1,BUFFER_HEIGHT-1 );
	gDPFillRectangle( Glp++, 0, start, BUFFER_WIDTH-1,start+lines-1 );
	gDPPipeSync( Glp++ );
	gDPSetRenderMode_default( Glp++ );
	gDPSetCycleType_default( Glp++ );

	gmode=GUTIL_DPSetCycleType;		// set current mode
	combine_mode=COMBINE_OFF;
		
	return;	
	
}

//////////////////////////////////////////////////////////////////////////////////////////
// gutil_draw_line - draw a line on the screen (good for timing)
// 
//////////////////////////////////////////////////////////////////////////////////////////
void gutil_draw_line(WORD line,LONG color) 
{
	WORD LineDepth=0;
	
//	LineDepth=line/BUFFER_HEIGHT;
	gDPPipeSync(Glp++);
	gDPSetCycleType(Glp++, G_CYC_FILL);
//	gDPSetRenderMode(Glp++, G_RM_OPA_SURF, G_RM_OPA_SURF2);
	gDPSetRenderMode( Glp++, G_RM_NOOP,G_RM_NOOP);
	gDPSetFillColor(Glp++, (GPACK_RGBA5551((color>>16)&0xff,(color>>8)&0xff,color&0xff,1)<<16)
	 | GPACK_RGBA5551((color>>16)&0xff,(color>>8)&0xff,color&0xff,1));
	gDPFillRectangle(Glp++, 0, line%240, BUFFER_WIDTH-1, (line%240)+LineDepth);
	gDPPipeSync( Glp++ );
	gDPSetRenderMode_default( Glp++ );
	gDPSetCycleType_default( Glp++ );
	
	return;	
}

//////////////////////////////////////////////////////////////////////////////////////////
// gutil_draw_box - draw a box on the screen
// x,y - top left hand corner of box
// w,h - width & height of box
// color - RGBA color of box 
//////////////////////////////////////////////////////////////////////////////////////////
void gutil_draw_box(short x,short y,WORD w,WORD h,WORD color) 
{
	short xc,yc;
	
	/* adjust object onto screen */
	x+=screen_adj_x;
	y+=screen_adj_y;
	
	xc=(x<0) ? -x:0;
	yc=(y<0) ? -x:0;
	
	color=xcolor(color,master_fade);
	
	gDPPipeSync(Glp++);
	gDPSetCycleType(Glp++, G_CYC_FILL);
	gDPSetRenderMode( Glp++, G_RM_NOOP,G_RM_NOOP);
	gDPSetFillColor(Glp++, (color<<16)|color);
	gDPFillRectangle(Glp++, x+xc, y+yc, (x+w-1+xc), (y+h-1+yc));
	gDPPipeSync( Glp++ );
	gDPSetRenderMode_default( Glp++ );
	gDPSetCycleType_default( Glp++ );

	return;	
}

void gutil_draw_xlu_box(short x,short y,WORD w,WORD h,WORD color,WORD xlu) 
{
	short xc,yc;
	
	
	/* adjust object onto screen */
	x+=screen_adj_x;
	y+=screen_adj_y;
	
	xc=(x<0) ? -x:0;
	yc=(y<0) ? -x:0;

	color=xcolor(color,master_fade);
	
	gDPPipeSync(Glp++);
	/* adjust for 8 bit rgba values */
  	gDPSetPrimColor( Glp++, 0, 0, (color & 0xf800)>>8, (color & 0x07c0)>>3, (color & 0x003e)<<2, xlu );
  	gDPSetCombineMode( Glp++, G_CC_PRIMITIVE, G_CC_PRIMITIVE );
	gDPSetRenderMode(Glp++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
	gDPFillRectangle(Glp++, x+xc, y+yc, (xc+x+w), (yc+y+h));
	gDPPipeSync( Glp++ );
	gDPSetRenderMode_default( Glp++ );
	gDPSetCombineMode_default( Glp++ );
	gDPSetPrimColor_default( Glp++ );
	combine_mode=COMBINE_OFF;
	
	return;	
}


#define MAX_DRAW_WIDTH	96
#define MAX_DRAW_HEIGHT	18

//////////////////////////////////////////////////////////////////////////////////////////
// gutil_draw_object - draws an object onto the screen
//  global variable DrawObj contains all information needed to setup a draw
// OBJECT CANNOT BE GREATER THEN 256 pixels wide
//////////////////////////////////////////////////////////////////////////////////////////
void draw_obj_XY(void) 
{
	WORD srcwidth;
	int i,j;
	int xp,yp;
	int dw,dh;
	int s,t;
	int dwx,dhy;		// scale height and width of rectangle

//**************************************************************************	
//		TILE BITMAP
//**************************************************************************	
	srcwidth=(DrawObj.dp_w +3) & (~3);			// get 4 byte aligned width
		
	j=0;
	yp=DrawObj.dp_y;
	
	/* traverse rows */
	while (j<DrawObj.dp_h)
	{
		/* start column reset */
		xp=DrawObj.dp_x;

		/* compute amount left to draw in height of bitmap */
		dh=DrawObj.dp_h-j;
		
		/* clamp bitmap tile height to constant */
		if (dh>MAX_DRAW_HEIGHT)
			dh=MAX_DRAW_HEIGHT;
		/* compute rectangle tile height */
		if (DrawObj.dp_scy==0x0100)
			dhy=dh;
		else dhy=(dh<<8)/DrawObj.dp_scy;

		i=DrawObj.dp_lclip;	
		/* traverse columns */
		while (i<srcwidth-DrawObj.dp_rclip)
		{
			/* compute amount left to draw in row of bitmap */
			dw=srcwidth-DrawObj.dp_rclip-i;
			
			/* clamp bitmap tile width to constant */
			if (dw>MAX_DRAW_WIDTH)
				dw=MAX_DRAW_WIDTH;
			
			/* compute rectangle tile width */	
			if (DrawObj.dp_scx==0x0100)
				dwx=dw;
			else dwx=(dw<<8)/DrawObj.dp_scx;
			
			if ((xp+dwx)>=0 && (yp+dhy)>=0 && xp<BUFFER_WIDTH && yp<BUFFER_HEIGHT)
			{
				/* load a tile from the bitmap */
				gDPLoadTextureTile(Glp++,DrawObj.dp_imgptr,G_IM_FMT_CI,G_IM_SIZ_8b,
									srcwidth,DrawObj.dp_h, 
									i,j,i+dw,j+dh, 
									0,		
									G_TX_NOMIRROR,G_TX_NOMIRROR,G_TX_NOMASK,G_TX_NOMASK,G_TX_NOLOD,G_TX_NOLOD);
			
				/* draw the tile */
#if SCIS
				s=t=0;
#else				
				s=(xp>=0)?0:-xp;			// compute TLX scissor (cant have neg x,y pos)
				t=(yp>=0)?0:-yp;			// compute TLY scissor
#endif
	
				if (DrawObj.dp_scx!=0x0100)
					s=(s<<8)/DrawObj.dp_scx;
				if (DrawObj.dp_scy!=0x0100)
					t=(t<<8)/DrawObj.dp_scy;
				
#if SCIS				
				gSPScisTextureRectangle(Glp++,
									(xp+s)<<2,(yp+t)<<2,
									(xp+dwx)<<2,(yp+dhy)<<2,
									G_TX_RENDERTILE,(i+s)<<5,(j+t)<<5,(DrawObj.dp_scx<<2),(DrawObj.dp_scy<<2));
#else
				gSPTextureRectangle(Glp++,
									(xp+s)<<2,(yp+t)<<2,
									(xp+dwx)<<2,(yp+dhy)<<2,
									G_TX_RENDERTILE,(i+s)<<5,(j+t)<<5,(DrawObj.dp_scx<<2),(DrawObj.dp_scy<<2));
#endif
			}
												
		   	i+=dw;				// next tile start col position
		   	xp+=dwx;				// next tile xpos
		}

		j+=dh;					// next tile start row position
		yp+=dhy;				// next tile ypos
	}

	return;
}

void draw_obj_XFlipY(void) 
{
	WORD srcwidth;
	int i,j;
	int xp,yp;
	int dw,dh;
	int s,t;
	int dwx,dhy;
	
//**************************************************************************	
//		TILE BITMAP XFLIP
//**************************************************************************	
	srcwidth=(DrawObj.dp_w +3) & (~3);			// get 4 byte aligned width
	
	j=0;
	yp=DrawObj.dp_y;
	
	/* traverse rows */
	while (j<DrawObj.dp_h)
	{
		/* start column reset */
		if (DrawObj.dp_scx==0x0100)
			xp=DrawObj.dp_x+DrawObj.dp_w;		// normal width
		else xp=DrawObj.dp_x+(DrawObj.dp_w<<8)/DrawObj.dp_scx;		// scaled width

		/* compute amount left to draw in height of bitmap */
		dh=DrawObj.dp_h-j;
		
		/* clamp tile height to constant */
		if (dh>MAX_DRAW_HEIGHT)
			dh=MAX_DRAW_HEIGHT;
		
		/* compute rectange tile height */
		if (DrawObj.dp_scy==0x0100)	
			dhy=dh;
		else dhy=(dh<<8)/DrawObj.dp_scy;

		i=DrawObj.dp_lclip;	
		/* traverse columns */
		while (i<srcwidth-DrawObj.dp_rclip)
		{
			/* compute amount left to draw in row of bitmap */
			dw=srcwidth-DrawObj.dp_rclip-i;
			
			/* clamp tile width to constant */
			if (dw>MAX_DRAW_WIDTH)
				dw=MAX_DRAW_WIDTH;

			/* compute rectangle tile width */
			if (DrawObj.dp_scx==0x0100)
				dwx=dw;
			else dwx=(dw<<8)/DrawObj.dp_scx;
			
			if (xp>=0 && (yp+dhy)>=0 && (xp-dwx)<BUFFER_WIDTH && yp<BUFFER_HEIGHT)	
			{
				/* load a tile from the bitmap */
				gDPLoadTextureTile(Glp++,DrawObj.dp_imgptr,G_IM_FMT_CI,G_IM_SIZ_8b,
									srcwidth,DrawObj.dp_h, 
									i,j,i+dw,j+dh, 
									0,		
									G_TX_NOMIRROR,G_TX_NOMIRROR,G_TX_NOMASK,G_TX_NOMASK,G_TX_NOLOD,G_TX_NOLOD);
			
				/* draw the tile */
				xp-=dwx;				// next tile xpos
#if SCIS
				s=t=0;
#else
				s=(xp>=0)?0:-xp;			// compute TLX scissor (cant have neg x,y pos)
				t=(yp>=0)?0:-yp;			// compute TLY scissor
#endif
				
				if (DrawObj.dp_scx!=0x0100)
					s=(s<<8)/DrawObj.dp_scx;
				if (DrawObj.dp_scy!=0x0100)
					t=(t<<8)/DrawObj.dp_scy;
				
#if SCIS				
				gSPScisTextureRectangle(Glp++,
									(xp+s)<<2,(yp+t)<<2,
									(xp+dwx)<<2,(yp+dhy)<<2,
									G_TX_RENDERTILE,(i+dw-s-1)<<5,(j+t)<<5,(-(DrawObj.dp_scx<<2)) & 0xffff,(DrawObj.dp_scy)<<2);
#else
				gSPTextureRectangle(Glp++,
									(xp+s)<<2,(yp+t)<<2,
									(xp+dwx)<<2,(yp+dhy)<<2,
									G_TX_RENDERTILE,(i+dw-s-1)<<5,(j+t)<<5,(-(DrawObj.dp_scx<<2)) & 0xffff,(DrawObj.dp_scy)<<2);
#endif									
			}
			else
			{
				xp-=dwx;
			}
											
			i+=dw;				// next tile start col position
		}

		j+=dh;					// next tile start row position
		yp+=dhy;					// next tile ypos
	}
	
	return;
	
}

void draw_obj_XYFlip(void) 
{
	WORD srcwidth;
	int i,j;
	int xp,yp;
	int dw,dh;
	int s,t;
	int dwx,dhy;		// scale height and width of rectangle

//**************************************************************************	
//		TILE BITMAP YFLIP
//**************************************************************************	
	srcwidth=(DrawObj.dp_w +3) & (~3);			// get 4 byte aligned width
		
	j=0;
	
	/* calc starting position for rectangles */
	if (DrawObj.dp_scy==0x0100)
		yp=DrawObj.dp_y+DrawObj.dp_h;
	else yp=DrawObj.dp_y+(DrawObj.dp_h<<8)/DrawObj.dp_scy;
	
	/* traverse rows */
	while (j<DrawObj.dp_h)
	{
		/* start column reset */
		xp=DrawObj.dp_x;

		/* compute amount left to draw in height of bitmap */
		dh=DrawObj.dp_h-j;
		
		/* clamp bitmap tile height to constant */
		if (dh>MAX_DRAW_HEIGHT)
			dh=MAX_DRAW_HEIGHT;
			
		/* compute rectangle tile height */
		if (DrawObj.dp_scy==0x0100)
			dhy=dh;
		else dhy=(dh<<8)/DrawObj.dp_scy;

		/* compute start position */
		yp-=dhy;

		i=DrawObj.dp_lclip;	
		/* traverse columns */
		while (i<srcwidth-DrawObj.dp_rclip)
		{
			/* compute amount left to draw in row of bitmap */
			dw=srcwidth-DrawObj.dp_rclip-i;
			
			/* clamp bitmap tile width to constant */
			if (dw>MAX_DRAW_WIDTH)
				dw=MAX_DRAW_WIDTH;
			
			/* compute rectangle tile width */	
			if (DrawObj.dp_scx==0x0100)
				dwx=dw;
			else dwx=(dw<<8)/DrawObj.dp_scx;
			
			if ((xp+dwx)>=0 && (yp+dhy)>=0 && xp<BUFFER_WIDTH && yp<BUFFER_HEIGHT)
			{
				/* load a tile from the bitmap */
				gDPLoadTextureTile(Glp++,DrawObj.dp_imgptr,G_IM_FMT_CI,G_IM_SIZ_8b,
									srcwidth,DrawObj.dp_h, 
									i,j,i+dw,j+dh, 
									0,		
									G_TX_NOMIRROR,G_TX_NOMIRROR,G_TX_NOMASK,G_TX_NOMASK,G_TX_NOLOD,G_TX_NOLOD);
			
				/* draw the tile */
#if SCIS
				s=t=0;
#else
				s=(xp>=0)?0:-xp;			// compute TLX scissor (cant have neg x,y pos)
				t=(yp>=0)?0:-yp;			// compute TLY scissor
#endif				
				
				if (DrawObj.dp_scx!=0x0100)
					s=(s<<8)/DrawObj.dp_scx;
				if (DrawObj.dp_scy!=0x0100)
					t=(t<<8)/DrawObj.dp_scy;
				
#if SCIS				
				gSPScisTextureRectangle(Glp++,
									(xp+s)<<2,(yp+t)<<2,
									(xp+dwx)<<2,(yp+dhy)<<2,
									G_TX_RENDERTILE,(i+s)<<5,(j+dh-t-1)<<5,(DrawObj.dp_scx<<2),(-(DrawObj.dp_scy<<2)) & 0xffff);
#else
				gSPTextureRectangle(Glp++,
									(xp+s)<<2,(yp+t)<<2,
									(xp+dwx)<<2,(yp+dhy)<<2,
									G_TX_RENDERTILE,(i+s)<<5,(j+dh-t-1)<<5,(DrawObj.dp_scx<<2),(-(DrawObj.dp_scy<<2)) & 0xffff);
#endif									
			};
												
		   	i+=dw;				// next tile start col position
		   	xp+=dwx;				// next tile xpos
		}

		j+=dh;					// next tile start row position
	}

	return;
}

void draw_obj_XFlipYFlip(void) 
{
	WORD srcwidth;
	int i,j;
	int xp,yp;
	int dw,dh;
	int s,t;
	int dwx,dhy;		// scale height and width of rectangle

//**************************************************************************	
//		TILE BITMAP XFLIP & YFLIP
//**************************************************************************	
	srcwidth=(DrawObj.dp_w +3) & (~3);			// get 4 byte aligned width
		
	j=0;
	
	/* calc starting position for rectangles */
	if (DrawObj.dp_scy==0x0100)
		yp=DrawObj.dp_y+DrawObj.dp_h;
	else yp=DrawObj.dp_y+(DrawObj.dp_h<<8)/DrawObj.dp_scy;
	
	/* traverse rows */
	while (j<DrawObj.dp_h)
	{
		/* start column reset */
		if (DrawObj.dp_scx==0x0100)
			xp=DrawObj.dp_x+DrawObj.dp_w;
		else xp=DrawObj.dp_x+(DrawObj.dp_w<<8)/DrawObj.dp_scx;

		/* compute amount left to draw in height of bitmap */
		dh=DrawObj.dp_h-j;
		
		/* clamp bitmap tile height to constant */
		if (dh>MAX_DRAW_HEIGHT)
			dh=MAX_DRAW_HEIGHT;
			
		/* compute rectangle tile height */
		if (DrawObj.dp_scy==0x0100)
			dhy=dh;
		else dhy=(dh<<8)/DrawObj.dp_scy;

		/* compute start position */
		yp-=dhy;

		i=DrawObj.dp_lclip;	
		/* traverse columns */
		while (i<srcwidth-DrawObj.dp_rclip)
		{
			/* compute amount left to draw in row of bitmap */
			dw=srcwidth-DrawObj.dp_rclip-i;
			
			/* clamp bitmap tile width to constant */
			if (dw>MAX_DRAW_WIDTH)
				dw=MAX_DRAW_WIDTH;
			
			/* compute rectangle tile width */	
			if (DrawObj.dp_scx==0x0100)
				dwx=dw;
			else dwx=(dw<<8)/DrawObj.dp_scx;
			
			if (xp>=0 && (yp+dhy)>=0 && (xp-dwx)<BUFFER_WIDTH && yp<BUFFER_HEIGHT)
			{
				/* load a tile from the bitmap */
				gDPLoadTextureTile(Glp++,DrawObj.dp_imgptr,G_IM_FMT_CI,G_IM_SIZ_8b,
									srcwidth,DrawObj.dp_h, 
									i,j,i+dw,j+dh, 
									0,		
									G_TX_NOMIRROR,G_TX_NOMIRROR,G_TX_NOMASK,G_TX_NOMASK,G_TX_NOLOD,G_TX_NOLOD);
			
				/* draw the tile */
				xp-=dwx;

#if SCIS
				s=t=0;
#else				
				s=(xp>=0)?0:-xp;			// compute TLX scissor (cant have neg x,y pos)
				t=(yp>=0)?0:-yp;			// compute TLY scissor
#endif				
				
				if (DrawObj.dp_scx!=0x0100)
					s=(s<<8)/DrawObj.dp_scx;
				if (DrawObj.dp_scy!=0x0100)
					t=(t<<8)/DrawObj.dp_scy;
				
#if SCIS
				gSPScisTextureRectangle(Glp++,
									(xp+s)<<2,(yp+t)<<2,
									(xp+dwx)<<2,(yp+dhy)<<2,
									G_TX_RENDERTILE,(i+dw-s-1)<<5,(j+dh-t-1)<<5,(-(DrawObj.dp_scx<<2)) & 0xffff,(-(DrawObj.dp_scy<<2)) & 0xffff);
#else				
				gSPTextureRectangle(Glp++,
									(xp+s)<<2,(yp+t)<<2,
									(xp+dwx)<<2,(yp+dhy)<<2,
									G_TX_RENDERTILE,(i+dw-s-1)<<5,(j+dh-t-1)<<5,(-(DrawObj.dp_scx<<2)) & 0xffff,(-(DrawObj.dp_scy<<2)) & 0xffff);
#endif									
			}
			else
			{
				xp-=dwx;
			}
												
		   	i+=dw;				// next tile start col position
		}

		j+=dh;					// next tile start row position
	}

	return;
}

void gutil_draw_object(void) 
{
//**************************************************************************
//			PALETTE LOADER	
//**************************************************************************	
	/* Determine if palette needs to be loaded */
	if (tmem_palptr!=DrawObj.dp_palptr) 
	{
		/* need a different palette */
		tmem_palptr=DrawObj.dp_palptr;			// record palette in TMEM
		gDPLoadTLUT_pal256(Glp++,tmem_palptr);	// load in the palette
	}

	/* Determine if has xlu factor*/
	if (DrawObj.dp_flags & M_XLU_ON) 
	{
		if (DrawObj.dp_flags & M_RED_TINT)
		{
			if (!(combine_mode & COMBINE_RED))
			{
				gDPPipeSync( Glp++ );
				gDPSetCombineMode( Glp++, G_CC_MODULATERGBDECALA_PRIM, G_CC_MODULATERGBDECALA_PRIM);
			
				/* determine if we red bias */
		 		gDPSetPrimColor( Glp++, 0, 0, 255, 32, 32, 255);
		 		combine_mode=COMBINE_RED;					
		 	}
		}
		else
		{
			/* only need to set if combine mode is different then what we need */
			if (!((combine_mode & COMBINE_ON) && (combine_mode & COMBINE_MASK)==((DrawObj.dp_flags & M_XLU_VALUE)>>M_XLU_SHIFT)))
			{
				gDPPipeSync( Glp++ );
				gDPSetCombineMode( Glp++, G_CC_MODULATERGBDECALA_PRIM, G_CC_MODULATERGBDECALA_PRIM);
				
				/* determine if we red bias */
			 	gDPSetPrimColor( Glp++, 0, 0, 255, 255, 255, ((DrawObj.dp_flags & M_XLU_VALUE)>>M_XLU_SHIFT));	
				combine_mode=COMBINE_ON|((DrawObj.dp_flags & M_XLU_VALUE)>>M_XLU_SHIFT);	// tell world what cmb mode we are in
			}
		}
	}
	else
	{
		if (combine_mode & (COMBINE_ON|COMBINE_RED)) 
		{
			/* reset combiner */
			gDPPipeSync( Glp++ );
			gDPSetCombineMode_default( Glp++ );
			gDPSetPrimColor_default( Glp++ );
			combine_mode=COMBINE_OFF;
		}
	}

	/* adjust object onto screen */
	DrawObj.dp_x+=screen_adj_x;
	DrawObj.dp_y+=screen_adj_y;
	
	switch (((DrawObj.dp_flags & (M_FLIPH+M_FLIPV))>>4) & 0x03)
	{
		case 0:
			draw_obj_XY();
			break;
		case 1:
			draw_obj_XFlipY();
			break;
		case 2:
			draw_obj_XYFlip();
			break;
		case 3:
			draw_obj_XFlipYFlip();
			break;
	}

	return;
}

