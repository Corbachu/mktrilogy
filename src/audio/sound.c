//////////////////////////////////////////////////////////////////////////////////////////
// sound.c - Sound functions on top of wess.
//
// Author: Steve Ranck
//////////////////////////////////////////////////////////////////////////////////////////
// THIS CODE IS PROPRIETARY PROPERTY OF WILLIAMS ENTERTAINMENT.
//
// The contents of this file may not be disclosed to third
// parties, copied or duplicated in any form, in whole or in part,
// without the prior written permission of Williams Entertainment.
//////////////////////////////////////////////////////////////////////////////////////////

#include <ultra64.h>

#include "sys_defs.h"

#include "sys.h"
#include "sound.h"
#include "mktril.h"
#include "wessapi.h"
#include "seqload.h"



//========================================================================================
// Private data:

static TriggerPlayAttr sound_attr;
static volatile int music_seq_playing;		// -1 = none
static volatile int music_seq_waiting;		// -1 = none


//========================================================================================
// Public functions:

//////////////////////////////////////////////////////////////////////////////////////////
// sound_reset - resets the sound system. All sound is stopped.
//////////////////////////////////////////////////////////////////////////////////////////
void sound_reset( void ) {
	CRITICAL_DEFS;

	ENTER_CRITICAL;
		music_seq_playing = -1;
		music_seq_waiting = -1;
	LEAVE_CRITICAL;
}


//////////////////////////////////////////////////////////////////////////////////////////
// sound_player - plays a sound for the specified player. If Players is 0 then the
//                player parameter is ignored and both left and right channels are used
//                to play the sound. If Players is 1 then the player parameter determines
//                which channel to play the sound (0: left, 1:right).
//
//                If TwoPlayerSplitSounds is 0 or player is -1 then Players is ignored
//                and all sounds are played on both left and right channels.
//////////////////////////////////////////////////////////////////////////////////////////
void sound_player( int seq_num, int player ) {
	sound_player_vol( seq_num, player, 1.0 );
}



//////////////////////////////////////////////////////////////////////////////////////////
// sound_player_vol - same as sound_player, but adds volume control (0.0=min, 1.0=max).
//////////////////////////////////////////////////////////////////////////////////////////
void sound_player_vol( int seq_num, int player, float vol ) {
	unsigned long seq_type;

	sound_attr.mask = TRIGGER_VOLUME | TRIGGER_PAN;
	sound_attr.volume = vol*127;

	if( !Players || !TwoPlayerSplitSounds || player==-1 ) {
		seq_type = 2;
		sound_attr.pan = 64;			// 64=center
	} else {
		seq_type = player;
		sound_attr.pan = player*127;	// 0=left, 127=right
	}

	seq_type |= ((seq_num&0xffff) << 16);

	wess_seq_trigger_type_special( seq_num, seq_type, &sound_attr );
}



//////////////////////////////////////////////////////////////////////////////////////////
// sound_status - returns the status of the specified sound. Status codes are the same
//                as wess_seq_status. Note that player may be -1 to indicate both channels.
//                See sound_player for more info.
//////////////////////////////////////////////////////////////////////////////////////////
int sound_status( int seq_num, int player ) {
	unsigned long seq_type;

	if( !Players || !TwoPlayerSplitSounds || player==-1 ) {
		seq_type = 2;
	} else {
		seq_type = player;
	}

	seq_type |= ((seq_num&0xffff) << 16);

	return( wess_seq_type_status( seq_type ) );
}


//////////////////////////////////////////////////////////////////////////////////////////
// sound_stop_player - stops the specified sound. Use this to stop sounds started with
//                     sound_player. Note that player may be -1 to indicate both channels.
//                     See sound_player for more info.
//////////////////////////////////////////////////////////////////////////////////////////
void sound_stop_player( int seq_num, int player ) {
	unsigned long seq_type;

	if( !Players || !TwoPlayerSplitSounds || player==-1 ) {
		seq_type = 2;
	} else {
		seq_type = player;
	}

	seq_type |= ((seq_num&0xffff) << 16);

	wess_seq_stoptype( seq_type );
}


//////////////////////////////////////////////////////////////////////////////////////////
// sound_stop_all - stops the specified sound playing on all channels (left, right, or
//                  both.
//////////////////////////////////////////////////////////////////////////////////////////
void sound_stop_all( int seq_num ) {
	unsigned long seq_type;

	seq_type = ((seq_num&0xffff) << 16);

	wess_seq_stoptype( seq_type | 0 );
	wess_seq_stoptype( seq_type | 1 );
	wess_seq_stoptype( seq_type | 2 );
}


//////////////////////////////////////////////////////////////////////////////////////////
// sound_music_work - called by game loop to handle synchronization of music sequences.
//////////////////////////////////////////////////////////////////////////////////////////
void sound_music_work( void ) {
#if SYS_DEBUG
	int seq_size;
#endif

	if( music_seq_waiting >= 0 ) {
		if( music_seq_playing<0 || (wess_seq_status( music_seq_playing ) != SEQUENCE_PLAYING) ) {
			if( 1 /*music_seq_waiting != music_seq_playing*/ ) {
				if( music_seq_playing >= 0 ) wess_seq_free( music_seq_playing );
#if SYS_DEBUG
				if( (seq_size=wess_seq_sizeof(music_seq_waiting)) > SOUND_MUSIC_SEQ_BUFFER_SIZE ) {
					printf(( " <<<< WARNING: music seqload buffer overflow >>>>\n" ));
					printf(( "               buffer size: %d bytes\n", SOUND_MUSIC_SEQ_BUFFER_SIZE ));
					printf(( "               seq %d size: %d bytes\n", music_seq_waiting, seq_size ));
				}
#endif
				wess_seq_load( music_seq_waiting, sys_music_buf );
			}
			wess_seq_trigger( music_seq_waiting );
			music_seq_playing = music_seq_waiting;
			music_seq_waiting = -1;
		}
	}
}


//////////////////////////////////////////////////////////////////////////////////////////
// sound_music_start - starts a music sequence playing as soon as possible. If another
//                     sequence is currently playing, that sequence is stopped first.
//////////////////////////////////////////////////////////////////////////////////////////
void sound_music_start( int seq_num ) {
	music_seq_waiting = -1;
	if( music_seq_playing >= 0 ) wess_seq_stop( music_seq_playing );
	music_seq_waiting = seq_num;
}


//////////////////////////////////////////////////////////////////////////////////////////
// sound_music_stop - stops the current music sequence from playing.
//////////////////////////////////////////////////////////////////////////////////////////
void sound_music_stop( void ) {
	music_seq_waiting = -1;
	if( music_seq_playing >= 0 ) wess_seq_stop( music_seq_playing );
}
