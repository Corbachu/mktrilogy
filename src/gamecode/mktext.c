/******************************************************************************
 File: mktext.c

 Date: Jan 1995

 (C) Williams Entertainment

 Mortal Kombat III Text Routines
******************************************************************************/

/* INCLUDES */
#include "u64main.h"

#include "mkbkgd.h"
#include "mkobj.h"
#include "mkos.h"
#include "mkutil.h"
#include "mkani.h"
#include "mkguys.h"
#include "mkmain.h"
#include "mkgame.h"
#include "mkpal.h"
#include "mkdma.h"
#include "mktext.h"

/* local extern info */
extern FNTSETUP pf_15point[];
extern FNTSETUP pf_15point_left[];
extern FNTSETUP pf_15point_soff[];
extern FNTSETUP pf_7point[];
extern FNTSETUP pf_7point_left[];
extern FNTSETUP pf_dave_smallc_soff[];
extern FNTSETUP pf_dave_smallc[];
extern FNTSETUP pf_dave_smalll_soff[];
extern FNTSETUP pf_dave_smallr_soff[];
extern FNTSETUP pf_dave_smallr[];
extern FNTSETUP pf_dave_smalll[];
extern WORD YELLOW_p[];

extern OIMGTBL *font15_panel_info[];
extern OIMGTBL *font7_panel_info[];
extern OIMGTBL *font7N_panel_info[];
OIMGTBL **font_lists[] =
{
	font15_panel_info,				// 15 pt
	font7_panel_info,				// 7 pt
	font7N_panel_info				// 7 Normal pt
};	 


/******************************************************************************
 Function: void p15_centered(char *pa8,short pa9x,short pa9y)

 By: David Schwartz

 Date: Dec 1994

 Parameters: pa8 - ptr to char string
			 pa9x - x pos
			 pa9y - y pos

 Returns: None

 Description:	setup a 15 point font print and print
******************************************************************************/
void p15_centered(char *pa8,short pa9x,short pa9y)
{
	lm_setup(pf_15point);
	fnt_state.fnt_posx=pa9x;
	fnt_state.fnt_posy=pa9y;
	mk_printf(pa8);

	return;
}

void p15_left(char *pa8,short pa9x,short pa9y)
{
	lm_setup(pf_15point_left);
	fnt_state.fnt_posx=pa9x;
	fnt_state.fnt_posy=pa9y;
	mk_printf(pa8);

	return;
}

/******************************************************************************
 Function: void p15_centered_soff(char *pa8,short pa9x,short pa9y)

 By: David Schwartz

 Date: Dec 1994

 Parameters: pa8 - ptr to char string
			 pa9x - x pos
			 pa9y - y pos

 Returns: None

 Description:	setup a 15 point font print and print no shadow
******************************************************************************/
void p15_centered_soff(char *pa8,short pa9x,short pa9y)
{
	lm_setup(pf_15point_soff);
	fnt_state.fnt_posx=pa9x;
	fnt_state.fnt_posy=pa9y;
	mk_printf(pa8);

	return;
}

/******************************************************************************
 Function: void p7_centered(char *pa8,short pa9x,short pa9y)

 By: David Schwartz

 Date: Dec 1994

 Parameters: pa8 - ptr to char string
			 pa9x - x pos
			 pa9y - y pos

 Returns: None

 Description:	setup a 15 point font print and print
******************************************************************************/
void p7_centered(char *pa8,short pa9x,short pa9y)
{
	lm_setup(pf_7point);
	fnt_state.fnt_posx=pa9x;
	fnt_state.fnt_posy=pa9y;
	mk_printf(pa8);

	return;
}

void p7_left(char *pa8,short pa9x,short pa9y)
{
	lm_setup(pf_7point_left);
	fnt_state.fnt_posx=pa9x;
	fnt_state.fnt_posy=pa9y;
	mk_printf(pa8);

	return;
}

/******************************************************************************
 Function: void pds_centered(char *pa8,short pa9x,short pa9y)

 By: David Schwartz

 Date: Mar 1995

 Parameters: pa8 - ptr to char string
			 pa9x - x pos
			 pa9y - y pos

 Returns: None

 Description:	dave small font centered
******************************************************************************/
void pds_centered(char *pa8,short pa9x,short pa9y)
{
	lm_setup(pf_dave_smallc);
	fnt_state.fnt_posx=pa9x;
	fnt_state.fnt_posy=pa9y;
	mk_printf(pa8);

	return;
}

/******************************************************************************
 Function: void pds_centered_soff(char *pa8,short pa9x,short pa9y)

 By: David Schwartz

 Date: Mar 1995

 Parameters: pa8 - ptr to char string
			 pa9x - x pos
			 pa9y - y pos

 Returns: None

 Description:	dave small font centered, no shadow
******************************************************************************/
void pds_centered_soff(char *pa8,short pa9x,short pa9y)
{
	lm_setup(pf_dave_smallc_soff);
	fnt_state.fnt_posx=pa9x;
	fnt_state.fnt_posy=pa9y;
	mk_printf(pa8);

	return;
}
void pds_left_soff(char *pa8,short pa9x,short pa9y)
{
	lm_setup(pf_dave_smalll_soff);
	fnt_state.fnt_posx=pa9x;
	fnt_state.fnt_posy=pa9y;
	mk_printf(pa8);

	return;
}

void pds_right_soff(char *pa8,short pa9x,short pa9y)
{
	lm_setup(pf_dave_smallr_soff);
	fnt_state.fnt_posx=pa9x;
	fnt_state.fnt_posy=pa9y;
	mk_printf(pa8);

	return;
}

/******************************************************************************
 Function: void pds_left(char *pa8,short pa9x,short pa9y)

 By: David Schwartz

 Date: Mar 1995

 Parameters: pa8 - ptr to char string
			 pa9x - x pos
			 pa9y - y pos

 Returns: None

 Description:	dave small font left
******************************************************************************/
void pds_left(char *pa8,short pa9x,short pa9y)
{
	lm_setup(pf_dave_smalll);
	fnt_state.fnt_posx=pa9x;
	fnt_state.fnt_posy=pa9y;
	mk_printf(pa8);

	return;
}

/******************************************************************************
 Function: void pds_right(char *pa8,short pa9x,short pa9y)

 By: David Schwartz

 Date: Mar 1995

 Parameters: pa8 - ptr to char string
			 pa9x - x pos
			 pa9y - y pos

 Returns: None

 Description:	dave small font right justify
******************************************************************************/
void pds_right(char *pa8,short pa9x,short pa9y)
{
	lm_setup(pf_dave_smallr);
	fnt_state.fnt_posx=pa9x;
	fnt_state.fnt_posy=pa9y;
	mk_printf(pa8);

	return;
}

/******************************************************************************
 Function: void lm_printf(FNTSETUP *fnt_info)

 By: David Schwartz

 Date: Jan 1995

 Parameters: fnt_info - data to init fnt_state, print string follows

 Returns: None

 Description:	setup the fnt state and print out the string
******************************************************************************/
void lm_printf(FNTSETUP *fnt_info)
{
	lm_setup(fnt_info);
	fnt_info++;					// move to string

	/* convert info */
	mk_printf((char *)fnt_info);

	return;
}

/******************************************************************************
 Function: void lm_printf_p1(FNTSETUP *fnt_info,WORD parm1)

 By: David Schwartz

 Date: Jan 1995

 Parameters: fnt_info - data to init fnt_state, print string follows
			 p1 - parameter 1

 Returns: None

 Description:	setup the fnt state and print out the string has 1 parameter to stick into the string
******************************************************************************/
void lm_printf_p1(FNTSETUP *fnt_info,WORD parm1)
{
	lm_setup(fnt_info);
	fnt_info++;					// move to string

	/* convert info */
	sprintf(fnt_buffer,(char *)fnt_info,parm1);

	stringer();

	return;
}

void pds_centered_p1(char *pa8,short pa9x,short pa9y,WORD parm1)
{
	lm_setup(pf_dave_smallc);
	fnt_state.fnt_posx=pa9x;
	fnt_state.fnt_posy=pa9y;
	/* convert info */
	sprintf(fnt_buffer,pa8,parm1);

	stringer();


	return;
}

void p7_left_p1(char *pa8,short pa9x,short pa9y,WORD parm1)
{
	lm_setup(pf_7point_left);
	fnt_state.fnt_posx=pa9x;
	fnt_state.fnt_posy=pa9y;
	/* convert info */
	sprintf(fnt_buffer,pa8,parm1);

	stringer();

	return;
}



/******************************************************************************
 Function: void printf_p1(char *msg,WORD parm1)

 By: David Schwartz

 Date: Jan 1995

 Parameters: msg - message text
			 p1 - parameter 1

 Returns: None

 Description:	print out the string has 1 parameter to stick into the string
******************************************************************************/
void printf_p1(char *msg,WORD parm1)
{
	/* convert info */
	sprintf(fnt_buffer,msg,parm1);
	stringer();

	return;
}

/******************************************************************************
 Function: void printf_s1(char *msg,char *parm1)

 By: David Schwartz

 Date: Jan 1995

 Parameters: msg - message text
			 p1 - parameter 1 (string)

 Returns: None

 Description:	print out the string has 1 parameter to stick into the string
******************************************************************************/
void printf_s1(char *msg,char *parm1)
{
	/* convert info */
	sprintf(fnt_buffer,msg,parm1);
	stringer();

	return;
}


/******************************************************************************
 Function: void mk_printf(char *cptr)

 By: David Schwartz

 Date: Jan 1995

 Parameters: cptr - text to print

 Returns: None

 Description:	print out the string
******************************************************************************/
void mk_printf(char *cptr)
{
	memcpy(fnt_buffer,cptr,strlen(cptr)+1);
	((char *)current_proc->pa8)=fnt_buffer;

	stringer();

	return;
}

/******************************************************************************
 Function: void stringer(void)

 By: David Schwartz

 Date: Jan 1995

 Parameters: fnt_state - init state information
			 fnt_buffer - set to text to print
			 current_proc->pa8 - ptr to fnt_buffer

			str_flags - insert:justify
			bit 17 = set the "no_scroll" bit in oflags2
			bit 16 = 1 insert on obj list
			bit 15 = 1 shadow the characters that get kicked out

			justify =  0 left justify
					   1 center justify
					   2 right justify

 Returns: None

 Description:	read fnt_buffer and create an object lists of text to display
******************************************************************************/
extern BYTE font_dict[];
void stringer(void)
{
	LONG str_flags;
	short b2;				// emul b2 register
	XYTYPE initpos;		// a3
	char cur_char;
	OBJECT *obj,*tobj;			// current object
	char *strptr;
	OIMGTBL *fptr;

	/* setup correct flag state */
	switch (fnt_state.fnt_routine)
	{
		case STRCNRMOS:
			str_flags=0x18001;
			break;
		case STRCNRMOS_SCR:
			str_flags=0x18001|STR_SCROLL;
			break;
		case STRLNRMOS_SCR:
			str_flags=0x18000|STR_SCROLL;
			break;
		case STRRNRMOS_SCR:
			str_flags=0x18002|STR_SCROLL;
			break;
		case STRCNRMO_SCR:
			str_flags=0x10001|STR_SCROLL;
			break;
		case STRLNRMO_SCR:
			str_flags=0x10002|STR_SCROLL;
			break;
		case STRRNRMO_SCR:
			str_flags=0x10000|STR_SCROLL;
			break;
	}

	string_underline=0;			// clear shadowing and underling flag
	(char *)current_proc->pa8=fnt_buffer;			// set to start of string to display

	string_shadow=(str_flags & STR_SHADOW) ? 1:0;

	/* stringer_noshad */
	spacing();

	initpos.u.xpos=fnt_state.fnt_posx;
	initpos.u.ypos=fnt_state.fnt_posy;

	justify(str_flags & STR_JUSTIFY);

	/* stringr2 */
	while (((short)*((char *)current_proc->pa8))!=0)
	{
		cur_char=*((char *)current_proc->pa8);
		((char *)(current_proc->pa8))++;					// next char
		b0=0;					// not a space, yet

		if (cur_char<' ')
		{
			/* control character */
			switch ((short)cur_char)
			{
				case NEW_XY:
					fnt_state.fnt_posx=(short)(*((char *)(current_proc->pa8)));
					((char *)(current_proc->pa8))++;					// next char
					fnt_state.fnt_posy=(short)(*((char *)(current_proc->pa8)));
					((char *)(current_proc->pa8))++;					// next char
					break;
				case NEW_SPACING:
					fnt_state.fnt_spacing=(WORD)(*((char *)(current_proc->pa8)));
					((char *)(current_proc->pa8))++;					// next char
					break;
				case ASCII_CR:
					fnt_state.fnt_posx=initpos.u.xpos;			// get back to where we started
					fnt_state.fnt_posy=initpos.u.ypos+fnt_spacing.u.ypos;	// move down 1 line
					initpos.u.xpos=fnt_state.fnt_posx;		// store position
					initpos.u.ypos=fnt_state.fnt_posy;
					justify(str_flags & STR_JUSTIFY);
					break;
				case ADD_DYDX:
					fnt_state.fnt_posx+=((short)(*((char *)(current_proc->pa8))));		// add delta x
					((char *)(current_proc->pa8))++;					// next char
					fnt_state.fnt_posy+=((short)(*((char *)(current_proc->pa8))));			// add delta y
					((char *)(current_proc->pa8))++;					// next char
					break;
			}
		}
		else
		{
			if (cur_char==' ')
			{
				/* spacing info setup */
				b2=fnt_state.fnt_posx;
				fnt_state.fnt_posx+=(fnt_spacing.u.xpos+fnt_state.fnt_spacing);

				if (string_underline==0)
					goto SKIP_DRAW;

				b0=b2;
				b2=fnt_state.fnt_posx;		// swap locations
				fnt_state.fnt_posx=b0;

				b0=1;
				cur_char='a';

				goto SKIP_DRAW;
			}

			/* strnchar, legal character draw time */
			fptr=*(font_lists[fnt_state.fnt_num]+(WORD)cur_char-0x21);

#if TEXT_QUE
			if (text_draw==1) 
			{
				if (fptr!=NULL)
				{
					tque_ptr->t_letter=fptr;
					tque_ptr->t_x=fnt_state.fnt_posx-fptr->anixoff;
					tque_ptr->t_y=fnt_state.fnt_posy-fptr->aniyoff;
					tque_ptr++;
				}
				
				if (tque_ptr>&text_queue[TQUE_MAX-1])
				{
					printf(("TEXT QUEUE OVERFLOW \n"));
					while (1);
				}
			}
			else
#endif
			{
				if ((obj=get_object())!=NULL)
				{
					obj->oflags2=0;

					if (str_flags & STR_SCROLL)
						obj->oflags2|=M_NOSCROLL;		// set no scroll bit

					obj->osag=fptr;
					obj->oimg=(LONG)fptr;	//-u64-
					obj->oheap=0;			//-u64-
					obj->odict=font_dict;
					
					obj->oxvel.pos=0;			// clear out position & vel info
					obj->oyvel.pos=0;
					obj->oxpos.pos=0;
					obj->oypos.pos=0;

					obj->oid=OID_TEXT;				// stuff findable ID
					obj->opal=get_fore_pal(fnt_state.fnt_pal);
					obj->ozval=1;

					obj->oxpos.u.intpos=fnt_state.fnt_posx-fptr->anixoff;		// eliminated anim point stuff
					obj->oypos.u.intpos=fnt_state.fnt_posy-fptr->aniyoff;

					strptr=(char *)current_proc->pa8;				//-u64-
					current_proc->pa8=obj;							//-u64-
					animate(SINGLE_ANI0,fptr,obj->oflags);			//-u64-
					(char *)current_proc->pa8=strptr;						//-u64-

					if (b0==0)
						insert_object(obj,&objlst2);

					/* check for underlining */
					/* check for shadowing */
					if (string_shadow!=0 && text_draw!=1)
					{
						tobj=obj;
						if ((obj=get_object())!=NULL)
						{
							copy_obj(tobj,obj);
							
							if (fnt_state.fnt_num==FONT_15)
							{
								obj->oxpos.u.intpos+=1;
								obj->oypos.u.intpos+=1;
							}
							else
							{
								obj->oxpos.u.intpos+=1;
								obj->oypos.u.intpos+=1;
							}
							obj->ozval=0;				// normal letters in front of shadows

							obj->opal=get_fore_pal(bpal_black_P);		// shadow is done in black

							insert_object(obj,&objlst2);
						}
					}
				}
			}

			/* strngdun */
			if (b0==0)
			{
				/* if characters is one need special spacing routine */
				if (cur_char=='1')
					fptr++;
				
				if (fptr==NULL)	
					printf(("NULL CHARACTER %d\n",cur_char));

				fnt_state.fnt_posx+=(fnt_state.fnt_spacing+fptr->size.u.xpos);	// pass character size and font spacing
			}
			else
			{
				fnt_state.fnt_posx=b2;
			}

			/* strng_bypass_1 */
			if (fnt_state.fnt_sleep!=0)
				process_sleep(fnt_state.fnt_sleep);
		}

SKIP_DRAW:
		;
  	}

	/* stringrx */
	return;
}

/******************************************************************************
 Function: void spacing(void)

 By: David Schwartz

 Date: Jan 1995

 Parameters: None

 Returns: fnt_spacing - sets variables with correct spacing

 Description:	set the spacing for the current font
******************************************************************************/
void spacing(void)
{
	OIMGTBL *fptr;

	if (fnt_state.fnt_num==FONT_15)
	{
		fnt_spacing.u.xpos=SCX(0x0a);
		fnt_spacing.u.ypos=SCY(0x13);
	}
	else
	{
		fptr=*font_lists[fnt_state.fnt_num];			// get pointer to font info

		fptr+='H'-0x21;				// USE 'H' for space and newline stuff

		/* x sizing = (x size of 'H')/2 */
		fnt_spacing.u.xpos=(fptr->size.u.xpos)>>1;

		/* x sizing = 3*(y size of 'H')/2 */
		fnt_spacing.u.ypos=(fptr->size.u.ypos)+((fptr->size.u.ypos)>>1);
	}

	return;
}

/******************************************************************************
 Function: void justify(WORD jindex)

 By: David Schwartz

 Date: Jan 1995

 Parameters: jindex - which justify setting to use
			0 - left
			1 - center
			2 - right

			fnt_buffer - string to justify
			fnt_state.fnt_posx - x pos of string
			fnt_state.fnt_posy - y pos of string

 Returns: fnt_state.fnt_posx - justified x pos
		  fnt_state.fnt_posy - justified y pos

 Description:	justify the string position
******************************************************************************/
void justify(WORD jindex)
{
	switch (jindex)
	{
		case 1:	// center justify
			fnt_state.fnt_posx=fnt_state.fnt_posx-strnglen()/2;
			break;
		case 2: // right justify
			fnt_state.fnt_posx=fnt_state.fnt_posx-strnglen();
			break;
	}

	return;
}

/*number of argument bytes for control character (1-1f) */
BYTE control_tab[] =
{
	2,2,2,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
};

/******************************************************************************
 Function: short strnglen(void)

 By: David Schwartz

 Date: Jan 1995

 Parameters: fnt_buffer - string to display


 Returns: pixel length of string

 Description:	return length of string (pixels)
******************************************************************************/
extern WORD f_white;
short strnglen(void)
{
	char *fptr;
	short fontsize=0;
	OIMGTBL *fntptr;

	/* x sizing = (x size of 'H')/2 */
	fntptr=*(font_lists[fnt_state.fnt_num]+(WORD)'H'-0x21);
	(fntptr->size.u.xpos)>>1;

	fptr=((char *)current_proc->pa8);

	while (*fptr!=0 && *fptr!=ASCII_CR)
	{
		if (*fptr<0x20)
		{
			fptr+=control_tab[(WORD)*fptr];		// skip past control command args
		}
		else
		{
			/* process character */
			if (*fptr==' ')
				fontsize+=fnt_spacing.u.xpos;
			else
			{
				if (*fptr=='1')
				{
					fntptr=*(font_lists[fnt_state.fnt_num]+(WORD)'2'-0x21);
					fontsize+=fntptr->size.u.xpos;
				}
				else 
				{
					fntptr=*(font_lists[fnt_state.fnt_num]+(WORD)(*fptr)-0x21);
					fontsize+=fntptr->size.u.xpos;
				}
			}

			fontsize+=fnt_state.fnt_spacing;		// add in space between chars
		}
		fptr++;					// next char
	}
	return(fontsize);
}

/******************************************************************************
 Function: void copy_obj(OBJECT *src,OBJECT *dest)

 By: David Schwartz

 Date: Jan 1995

 Parameters: src - object to copy
			 dest - object to store info


 Returns: None

 Description:	copy's the src obj into the dest obj, without copying the links
******************************************************************************/
void copy_obj(OBJECT *src,OBJECT *dest)
{
	memcpy(&(dest->ograv),&(src->ograv),sizeof(OBJECT)-sizeof(OBJECT *)-sizeof(void*)-sizeof(PROCESS *));
	
	dest->oplink=0;
	
	alloc_vram_mem_update(dest->ovcache);		// update vram cache if needed
	
	return;
}
