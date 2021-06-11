/*
//////////////////////////////////////////////////////////////////////////////////////////
// sys_defs.h
//
// Author: David Schwartz
//
// IMPORTANT: This file is included by the project "spec" file, as well as various c modules.
//            As a result, // style comments cannot be used!
//
//////////////////////////////////////////////////////////////////////////////////////////
// THIS CODE IS PROPRIETARY PROPERTY OF WILLIAMS ENTERTAINMENT.
//
// The contents of this file may not be disclosed to third
// parties, copied or duplicated in any form, in whole or in part,
// without the prior written permission of Williams Entertainment.
//////////////////////////////////////////////////////////////////////////////////////////
*/

#ifndef SYS_DEFS_H
#define SYS_DEFS_H



/*-----------------------------------------------------------------------------------------------------
// Build switches:
*/
 
#define SYS_DEBUG			0		/* 1=turn debugging code on, 0=no debugging code (retail) */
#define SYS_VERBOSE			0		/* 0=quiet, 1=minimum printing, 2=moderate printing, 3=maximum printing */
#define AGRESSOR_ON			1
#define TEXT_QUE			0
#define COLOR64				0		/* set for 64 color demo bs */
#define SYS_OPTSPEED		1		/* 1=optimum speed, 0=optimum accuracy for math functions */
#define SYS_HW_VERSION		2		/* hardware version */

/*-----------------------------------------------------------------------------------------------------
// R4300 CPU definitions:
*/

#define SYS_DMA_ALIGN		3		/* U64 DMA alignment code. All DMA transfer addresses must be aligned */
									/*  on the boundary defined by 2^SYS_DMA_ALIGN. (example: "3" means */
									/*  align on 8-byte (64-bit) DRAM memory boundaries. */

#define SYS_NUM_TLBS		32		/* total number of TLB registers on the R4300 CPU */


/*-----------------------------------------------------------------------------------------------------
// Ultra-64 environmental definitions:
*/

#define SYS_CARTRIDGE_SIZE		12288		/* Cartridge size in kilobytes */
#define SYS_DRAM_MIN			0x000480	/* First usable DRAM address (must be 64-byte aligned) */
#define SYS_DRAM_MIN_K0			0x80000480	/* First KSEG0 DRAM address (must correspond to SYS_DRAM_MIN) */
#define SYS_DRAM_MAX			0xbb7fff	/* Last addressable byte in DRAM */
#define SYS_VTXBUF_SIZE			16			/* Maximum number of vertices that can be loaded into the U64 at once */

#define SYS_GAMEPAD_RETRY		3			/* Retry faulty gamepad requests this many times */
#define SYS_GAMEPAD_USEC		2000		/* Typical response time for osContStartReadData */
#define SYS_PEAK_GAMEPAD_X		80			/* Horizontal analog joystick goes +/- this value */
#define SYS_PEAK_GAMEPAD_Y		80			/* Vertical analog joystick goes +/- this value */
#define SYS_GAMEPAD_CENTER_X	0.5			/* Default gamepad center x */
#define SYS_GAMEPAD_CENTER_Y	0.5			/* Default gamepad center y */
#define SYS_GAMEPAD_THRESH_MIN	0.25		/* Analog minimum threshold for digital conversion to left/down */
#define SYS_GAMEPAD_THRESH_MAX	0.75		/* Analog maximum threshold for digital conversion to right/up */

#define SYS_PRT_SIZE			16			/* size of viewport structures in bytes */
#define SYS_VTX_SIZE			16			/* size of vertex structures in bytes */
#define SYS_MTX_SIZE			64			/* size of matrix structures in bytes */
#define SYS_GFX_SIZE			8			/* size of graphics command structure in bytes */

#define SYS_RSPSEG_VIRTUALSIZE	0x01000000	/* this many bytes per virtual segment */
#define SYS_TEXTURE_COORD_SCALE	0x8000		/* texture coordinate scaling values (.16 format) */


/*-----------------------------------------------------------------------------------------------------
// Game-specific definitions:
*/

#define SYS_NUM_GAMEPADS		2				/* we need 2 gamepads for a 2-player game */
#define SYS_GAMEPAD_DEADZONE	0.1				/* Default gamepad deadzone */
#define SYS_MAX_SLIDERS			50				/* Maximum number of sliders */
#define SYS_MAX_TRIGGERS		100				/* Maximum number of triggers */
#define SYS_RANDOM_SEED			0x789ABCDE		/* Random seed (32-bits) */
#define SYS_NUM_FRAMEBUFS		2				/* Number of frame buffers (2 or 3) */
#define SYS_NUM_DLBUFS			2				/* Number of display-list buffers (2 or 3) */

#define SYS_MAX_PRT				20				/* Maximum number of dynamic viewports */
#define SYS_MAX_VTX				1500			/* Maximum number of dynamic vertices */
#define SYS_MAX_MTX				1000			/* Maximum number of matrices */
#define SYS_MAX_GFX				8192			/* Maximum number of GFX commands */
#define SYS_ABUF_SIZE			( 128 * 1024 )	/* Audio buffer size (bytes) */

#define SYS_VIDEO_MODE		OS_VI_NTSC_LPN1		/* must be OS_VI_NTSC_* from os.h */
#define SYS_SCALE			0.2					/* Master artwork/world scale factor */
#define SYS_FRAMES_PER_SEC	60					/* Game loop runs at this rate */

#define SYS_OUTER_HRES		320		/* Horizontal screen resolution (must be even) */
#define SYS_OUTER_VRES		240		/* Vertical screen resolution (must be even) */
#define SYS_SCREEN_DEPTH	2		/* Bytes per pixel */
#define SYS_NEAR_CLIP		1		/* Near clipping plane */
#define SYS_FAR_CLIP		65500	/* Far clipping plane */


/*-----------------------------------------------------------------------------------------------------
// Memory map definitions:
*/

#define SYS_FBUF_SIZE		(SYS_OUTER_HRES*SYS_OUTER_VRES*SYS_SCREEN_DEPTH)	/* Frame buf size (bytes) */
#define SYS_ZBUF_SIZE		SYS_FBUF_SIZE										/* Z-buffer size (bytes) */
#define SYS_DBUF_SIZE		( SYS_MAX_GFX * SYS_GFX_SIZE )						/* Display-list buffer size (bytes) */
#define SYS_MBUF_SIZE		( SYS_MAX_MTX * SYS_MTX_SIZE )						/* Matrix buffer size (bytes) */
#define SYS_VBUF_SIZE		( SYS_MAX_VTX * SYS_VTX_SIZE )						/* Vertex buffer size (bytes) */
#define SYS_PBUF_SIZE		( SYS_MAX_PRT * SYS_PRT_SIZE )						/* Viewport buffer size (bytes) */

#define SYS_MEMMAP_LIMIT		(SYS_DRAM_MAX+1)						/* byte after highest RAM */
#define SYS_MEMMAP_AUDIOBUFS	ALIGN_DOWN( SYS_MEMMAP_LIMIT-SYS_ABUF_SIZE, 8 )

#if SYS_NUM_DLBUFS==3
#define SYS_MEMMAP_DBUF3		ALIGN_DOWN( SYS_MEMMAP_AUDIOBUFS-SYS_DBUF_SIZE, 8 )
#define SYS_MEMMAP_DBUF2		ALIGN_DOWN( SYS_MEMMAP_DBUF3-SYS_DBUF_SIZE, 8 )
#else
#define SYS_MEMMAP_DBUF2		ALIGN_DOWN( SYS_MEMMAP_AUDIOBUFS-SYS_DBUF_SIZE, 8 )
#endif
#define SYS_MEMMAP_DBUF1		ALIGN_DOWN( SYS_MEMMAP_DBUF2-SYS_DBUF_SIZE, 8 )

#if SYS_NUM_DLBUFS==3
#define SYS_MEMMAP_MBUF3		ALIGN_DOWN( SYS_MEMMAP_DBUF1-SYS_MBUF_SIZE, 8 )
#define SYS_MEMMAP_MBUF2		ALIGN_DOWN( SYS_MEMMAP_MBUF3-SYS_MBUF_SIZE, 8 )
#else
#define SYS_MEMMAP_MBUF2		ALIGN_DOWN( SYS_MEMMAP_DBUF1-SYS_MBUF_SIZE, 8 )
#endif
#define SYS_MEMMAP_MBUF1		ALIGN_DOWN( SYS_MEMMAP_MBUF2-SYS_MBUF_SIZE, 8 )

#if SYS_NUM_DLBUFS==3
#define SYS_MEMMAP_VBUF3		ALIGN_DOWN( SYS_MEMMAP_MBUF1-SYS_VBUF_SIZE, 8 )
#define SYS_MEMMAP_VBUF2		ALIGN_DOWN( SYS_MEMMAP_VBUF3-SYS_VBUF_SIZE, 8 )
#else
#define SYS_MEMMAP_VBUF2		ALIGN_DOWN( SYS_MEMMAP_MBUF1-SYS_VBUF_SIZE, 8 )
#endif
#define SYS_MEMMAP_VBUF1		ALIGN_DOWN( SYS_MEMMAP_VBUF2-SYS_VBUF_SIZE, 8 )

#if SYS_NUM_DLBUFS==3
#define SYS_MEMMAP_PBUF3		ALIGN_DOWN( SYS_MEMMAP_VBUF1-SYS_PBUF_SIZE, 8 )
#define SYS_MEMMAP_PBUF2		ALIGN_DOWN( SYS_MEMMAP_PBUF3-SYS_PBUF_SIZE, 8 )
#else
#define SYS_MEMMAP_PBUF2		ALIGN_DOWN( SYS_MEMMAP_VBUF1-SYS_PBUF_SIZE, 8 )
#endif
#define SYS_MEMMAP_PBUF1		ALIGN_DOWN( SYS_MEMMAP_PBUF2-SYS_PBUF_SIZE, 8 )

#define SYS_MEMMAP_HEAP2_END	SYS_MEMMAP_PBUF1		/* byte after heap 2's end */

#define SYS_MEMMAP_KERNEL		0x00001000				/* physical start of kernel */
#define SYS_MEMMAP_KERNEL_K0	0x80001000				/* virtual start of kernel */

#define SYS_MEMMAP_ZBUF			SYS_DRAM_MIN			/* physical start of zbuffer */
#define SYS_MEMMAP_ZBUF_K0		SYS_DRAM_MIN_K0			/* virtual start of zbuffer */


/*-----------------------------------------------------------------------------------------------------
// TLB and segment definitions:
*/

#define SYS_RSPSEG_PHYSICAL		0
#define SYS_RSPSEG_K0			1
#define SYS_RSPSEG_FBUF			2		/* used by the video system */
#define SYS_RSPSEG_PAL			3		/* palette index segment (normally 0) */

#define SYS_FBUF_SEGMENTED_ADDR	( SYS_RSPSEG_FBUF * SYS_RSPSEG_VIRTUALSIZE )


/*-----------------------------------------------------------------------------------------------------
// Thread definitions:
*/

#define SYS_THREAD_ID_RMON			0		/* debugger thread IDs */
#define SYS_THREAD_ID_IDLE			1
#define SYS_THREAD_ID_MAIN			2
#define SYS_THREAD_ID_ROMCOPY		3
#define SYS_THREAD_ID_VBI			4
#define SYS_THREAD_ID_RSP			5
#define SYS_THREAD_ID_RDP			6
#define SYS_THREAD_ID_GAMEPAD		7
#define SYS_THREAD_ID_GTIMER		8

#define SYS_MAIN_THREAD_PRIORITY	10
#define SYS_ROMCOPY_THREAD_PRIORITY	50
#define SYS_GAMEPAD_THREAD_PRIORITY	70
#define SYS_RDP_THREAD_PRIORITY		75
#define SYS_RSP_THREAD_PRIORITY		80		/* RSP's priority MUST be greater than RDP's */
#define SYS_GTIMER_THREAD_PRIORITY	85
#define SYS_VBI_THREAD_PRIORITY		90

#define SYS_BOOT_STACKSIZE			256		/* stack sizes are in bytes */
#define SYS_IDLE_STACKSIZE			384
#define SYS_MAIN_STACKSIZE			2048
#define SYS_ROMCOPY_STACKSIZE		2048
#define SYS_VBI_STACKSIZE			3072
#define SYS_GAMEPAD_STACKSIZE		1024
#define SYS_GTIMER_STACKSIZE		1024


/*-----------------------------------------------------------------------------------------------------
// Message queue definitions:
*/

#define SYS_MSGBUF_SIZE_PI		400
#define SYS_MSGBUF_SIZE_VID		32


/*-----------------------------------------------------------------------------------------------------
// Debugging definitions:
//
// The following macros generate code only when SYS_DEBUG is set.
//
//    printf    - always prints
//    vprintf   - prints if SYS_VERBOSE is 1, 2, or 3
//    v23printf - prints if SYS_VERBOSE is either 2 or 3
//    v3printf  - prints if SYS_VERBOSE is 3 only
*/

#if SYS_DEBUG==1
  #define printf(args) rmonPrintf args

  #if SYS_VERBOSE==0
    #define vprintf(args)
    #define v23printf(args)
    #define v3printf(args)
  #else
    #if SYS_VERBOSE==1
      #define vprintf(args) rmonPrintf args
      #define v23printf(args)
      #define v3printf(args)
    #else
      #if SYS_VERBOSE==2
        #define vprintf(args) rmonPrintf args
        #define v23printf(args) rmonPrintf args
        #define v3printf(args)
      #else
        #define vprintf(args) rmonPrintf args
        #define v23printf(args) rmonPrintf args
        #define v3printf(args) rmonPrintf args
      #endif
    #endif
  #endif
#else
  #define printf(args)
  #define vprintf(args)
  #define v23printf(args)
  #define v3printf(args)
#endif


#endif
