//////////////////////////////////////////////////////////////////////////////////////////
// gdefaults.h
//
// Author: David Schwartz
//////////////////////////////////////////////////////////////////////////////////////////
// THIS CODE IS PROPRIETARY PROPERTY OF WILLIAMS ENTERTAINMENT.
//
// The contents of this file may not be disclosed to third
// parties, copied or duplicated in any form, in whole or in part,
// without the prior written permission of Williams Entertainment.
//////////////////////////////////////////////////////////////////////////////////////////

#ifndef GDEFAULTS_H
#define GDEFAULTS_H 1



//========================================================================================
// Public definitions:

#define GUTIL_PERSPNORMALIZE_FACTOR		62


#define GUTIL_DPSetCycleType		G_CYC_1CYCLE			// G_CYC_1CYCLE, G_CYC_2CYCLE, G_CYC_COPY, G_CYC_FILL

#define GUTIL_DPPipelineMode		G_PM_NPRIMITIVE			// G_PM_NPRIMITIVE=faster, G_PM_1PRIMITIVE=no artifacts

#define GUTIL_DPSetTextureLOD		G_TL_TILE				// G_TL_TILE, G_TL_LOD

#define GUTIL_DPSetTextureLUT		G_TT_RGBA16				// G_TT_NONE, G_TT_RGBA16, G_TT_IA16

#define GUTIL_DPSetTextureDetail	G_TD_CLAMP				// G_TD_CLAMP, G_TD_SHARPEN, G_TD_DETAIL

#define GUTIL_DPSetTexturePersp		G_TP_NONE				// G_TP_NONE, G_TP_PERSP

#define GUTIL_DPSetTextureFilter	G_TF_POINT				// G_TF_POINT, G_TF_AVERAGE, G_TF_BILERP

#define GUTIL_DPSetTextureConvert	G_TC_FILT				// G_TC_CONV, G_TC_FILTCONV, G_TC_FILT

#define GUTIL_DPSetCombineMode1		G_CC_DECALRGBA
#define GUTIL_DPSetCombineMode2		G_CC_DECALRGBA
#define GUTIL_DPSetCombineKey		G_CK_NONE

#define GUTIL_DPSetAlphaCompare		G_AC_NONE				// G_AC_NONE, G_AC_THRESHOLD, G_AC_DITHER
#define GUTIL_DPSetAlphaDither		G_AD_DISABLE//G_AD_NOISE				// G_AD_PATTERN, G_AD_NOTPATTERN, G_AD_NOISE, G_AD_DISABLE

#define GUTIL_DPSetRenderMode1		G_RM_XLU_SURF
#define GUTIL_DPSetRenderMode2		G_RM_XLU_SURF2

#define GUTIL_DPSetColorDither		G_CD_DISABLE			// G_CD_MAGICSQ, G_CD_BAYER, G_CD_NOISE, G_CD_ENABLE, G_CD_DISABLE

#define GUTIL_DPSetDepthSource		G_ZS_PIXEL				// G_ZS_PIXEL, G_ZS_PRIM

#define GUTIL_DPSetPrimColor1		0						// m parameter for LOD
#define GUTIL_DPSetPrimColor2		0						// l parameter for LOD
#define GUTIL_DPSetPrimColor3		256						// red 256
#define GUTIL_DPSetPrimColor4		256					// green
#define GUTIL_DPSetPrimColor5		256						// blue
#define GUTIL_DPSetPrimColor6		256						// alpha

#define GUTIL_SPPerspNormalize		GUTIL_PERSPNORMALIZE_FACTOR		

#define GUTIL_SPTexture1			SYS_TEXTURE_COORD_SCALE
#define GUTIL_SPTexture2			SYS_TEXTURE_COORD_SCALE
#define GUTIL_SPTexture3			0
#define GUTIL_SPTexture4			G_TX_RENDERTILE
#define GUTIL_SPTexture5			G_ON

#define GUTIL_DPSetBlendColor1		0
#define GUTIL_DPSetBlendColor2		0
#define GUTIL_DPSetBlendColor3		0
#define GUTIL_DPSetBlendColor4		1

#define GUTIL_DPSetScissorMode		G_SC_NON_INTERLACE		// G_SC_NON_INTERLACE, G_SC_ODD_INTERLACE, G_SC_EVEN_INTERLACE

/* all 3 ClipRatio defaults must be changed simultaneously */
#define GUTIL_SPClipRatio					FRUSTRATIO_3
#define gSPClipRatio_default( pkt )			gSPClipRatio( pkt, FRUSTRATIO_3 )
#define gsSPClipRatio_default				gsSPClipRatio( FRUSTRATIO_3 )

#define gSPTexture_default( pkt )			gSPTexture( pkt, GUTIL_SPTexture1, GUTIL_SPTexture2, GUTIL_SPTexture3, GUTIL_SPTexture4, GUTIL_SPTexture5 )
#define gSPPerspNormalize_default( pkt )	gSPPerspNormalize( pkt, GUTIL_SPPerspNormalize )
#define gDPSetCycleType_default( pkt )		gDPSetCycleType( pkt, GUTIL_DPSetCycleType )
#define gDPPipelineMode_default( pkt )		gDPPipelineMode( pkt, GUTIL_DPPipelineMode )
#define gDPSetTextureLOD_default( pkt )		gDPSetTextureLOD( pkt, GUTIL_DPSetTextureLOD )
#define gDPSetTextureLUT_default( pkt )		gDPSetTextureLUT( pkt, GUTIL_DPSetTextureLUT )
#define gDPSetTextureDetail_default( pkt )	gDPSetTextureDetail( pkt, GUTIL_DPSetTextureDetail )
#define gDPSetTexturePersp_default( pkt )	gDPSetTexturePersp( pkt, GUTIL_DPSetTexturePersp )
#define gDPSetTextureFilter_default( pkt )	gDPSetTextureFilter( pkt, GUTIL_DPSetTextureFilter )
#define gDPSetTextureConvert_default( pkt )	gDPSetTextureConvert( pkt, GUTIL_DPSetTextureConvert )
#define gDPSetCombineMode_default( pkt )	gDPSetCombineMode( pkt, GUTIL_DPSetCombineMode1, GUTIL_DPSetCombineMode2 )
#define gDPSetCombineKey_default( pkt )		gDPSetCombineKey( pkt, GUTIL_DPSetCombineKey )
#define gDPSetAlphaCompare_default( pkt )	gDPSetAlphaCompare( pkt, GUTIL_DPSetAlphaCompare )
#define gDPSetAlphaDither_default( pkt )	gDPSetAlphaDither( pkt, GUTIL_DPSetAlphaDither )
#define gDPSetRenderMode_default( pkt )		gDPSetRenderMode( pkt, GUTIL_DPSetRenderMode1, GUTIL_DPSetRenderMode2 )
#define gDPSetColorDither_default( pkt )	gDPSetColorDither( pkt, GUTIL_DPSetColorDither )
#define gDPSetDepthSource_default( pkt )	gDPSetDepthSource( pkt, GUTIL_DPSetDepthSource )
#define gDPSetBlendColor_default( pkt )		gDPSetBlendColor( pkt, GUTIL_DPSetBlendColor1, GUTIL_DPSetBlendColor2, GUTIL_DPSetBlendColor3, GUTIL_DPSetBlendColor4 )
#define gDPSetPrimColor_default( pkt )		gDPSetPrimColor( pkt, GUTIL_DPSetPrimColor1, GUTIL_DPSetPrimColor2, GUTIL_DPSetPrimColor3, GUTIL_DPSetPrimColor4, GUTIL_DPSetPrimColor5, GUTIL_DPSetPrimColor6 )

#define gsSPTexture_default					gsSPTexture( GUTIL_SPTexture1, GUTIL_SPTexture2, GUTIL_SPTexture3, GUTIL_SPTexture4, GUTIL_SPTexture5 )
#define gsSPPerspNormalize_default			gsSPPerspNormalize( GUTIL_SPPerspNormalize )
#define gsDPSetCycleType_default			gsDPSetCycleType( GUTIL_DPSetCycleType )
#define gsDPPipelineMode_default			gsDPPipelineMode( GUTIL_DPPipelineMode )
#define gsDPSetTextureLOD_default			gsDPSetTextureLOD( GUTIL_DPSetTextureLOD )
#define gsDPSetTextureLUT_default			gsDPSetTextureLUT( GUTIL_DPSetTextureLUT )
#define gsDPSetTextureDetail_default		gsDPSetTextureDetail( GUTIL_DPSetTextureDetail )
#define gsDPSetTexturePersp_default			gsDPSetTexturePersp( GUTIL_DPSetTexturePersp )
#define gsDPSetTextureFilter_default		gsDPSetTextureFilter( GUTIL_DPSetTextureFilter )
#define gsDPSetTextureConvert_default		gsDPSetTextureConvert( GUTIL_DPSetTextureConvert )
#define gsDPSetCombineMode_default			gsDPSetCombineMode( GUTIL_DPSetCombineMode1, GUTIL_DPSetCombineMode2 )
#define gsDPSetCombineKey_default			gsDPSetCombineKey( GUTIL_DPSetCombineKey )
#define gsDPSetAlphaCompare_default			gsDPSetAlphaCompare( GUTIL_DPSetAlphaCompare )
#define gsDPSetAlphaDither_default			gsDPSetAlphaDither( GUTIL_DPSetAlphaDither )
#define gsDPSetRenderMode_default			gsDPSetRenderMode( GUTIL_DPSetRenderMode1, GUTIL_DPSetRenderMode2 )
#define gsDPSetColorDither_default			gsDPSetColorDither( GUTIL_DPSetColorDither )
#define gsDPSetDepthSource_default			gsDPSetDepthSource( GUTIL_DPSetDepthSource )
#define gsDPSetBlendColor_default			gsDPSetBlendColor( GUTIL_DPSetBlendColor1, GUTIL_DPSetBlendColor2, GUTIL_DPSetBlendColor3, GUTIL_DPSetBlendColor4 )
#define gsDPSetPrimColor_default			gsDPSetPrimColor( GUTIL_DPSetPrimColor1, GUTIL_DPSetPrimColor2, GUTIL_DPSetPrimColor3, GUTIL_DPSetPrimColor4, GUTIL_DPSetPrimColor5, GUTIL_DPSetPrimColor6 )


#endif
