/******************************************************************************
 File: mkbug.h

 By: David Schwartz

 Date: August 1994

 (C) Williams Entertainment

 Mortal Kombat III Debugging
******************************************************************************/

#ifndef __mk_mkbug_h__
#define __mk_mkbug_h__

/* 
 * 	DEFINITIONS
 */


/* 
 *	RAM 
 */

/*
 *	PROTOTYPES 
 */
void debug_grid(void);
void profiler(void);
void draw_collision_box(XYTYPE *,XYTYPE *,WORD);

void throw_debug(WORD pa0);
void slam_debug_init(void); 
void print_slam_data(void); 


/*
 *	MACROS
 */
#define air_slam_debug() throw_debug(0)
#define double_mframew_debug() throw_debug(0)
#define body_slam_debug() throw_debug(1)

#endif /* __mk_mkbug_h__ */

