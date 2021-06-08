/*
 *  sndtask.c by Scott Patterson
 */

/*
 *  This code sets up the Audio task scheduling
 *
 *  The sound system is initilized with the wess_init function
 *
 *  Here is how the audio integration works :
 *
 *  At the top of the retrace, the scheduler yeilds any currently
 *  processing graphics task if there is a audio task ready to submit.
 *
 *  The scheduler next notifies the graphics and audio tasks that they
 *  should start building RSP task lists for the next retrace.
 *
 *  The audio thread is at a higher priority and wess_work is called
 *  next, this calculates the RSP task list for the next frame and makes
 *  DMA requests that need to be recieved before the next frame.
 *
 *  When wess_work returns, the audio task for the next retrace is sent
 *  to the scheduler.  Audio cpu work for this frame is done at this point.
 *
 *  As soon as the audio RSP task finishes, graphics RSP calculations can
 *  be started or resumed.
 *
 *
 *  Lets watch the audio system start up after initialization :
 *
 *  frame N  :
 *                No DAC output yet        (for frame N)
 *                No audio task to submit  (for frame N+1)
 *                Cartridge to DRAM DMA's  (for frame N+2) ------>|
 *                Audio task list building (for frame N+2) ------>|
 *  frame N+1:                                                    |
 *                No DAC output yet        (for frame N+1)        |
 *                Audio task submission    (for frame N+2) ------>|
 *                Cartridge to DRAM DMA's  (for frame N+3)        |
 *                Audio task list building (for frame N+3)        |
 *                                                                |
 *  frame N+2:                                                    |
 *                DAC output               (for frame N+2) <------|
 *                Audio task submission    (for frame N+3)
 *                Cartridge to DRAM DMA's  (for frame N+4)
 *                Audio task list building (for frame N+4)
 *  frame N+i:
 *                DAC output               (for frame N+i)
 *                Audio task submission    (for frame N+i+1)
 *                Cartridge to DRAM DMA's  (for frame N+i+2)
 *                Audio task list building (for frame N+i+2)
 */

#include <ultra64.h>
#include "../wess/wessapi.h"
#include "../wess/seqload.h"
#include "../markg/inflate/inflate.h"

#define DECOMP_SIZE 120000
char decomp_mem[DECOMP_SIZE];

/*
    Audio globals
*/

#define AUDIO_HEAP_SIZE         800000

static u8   audioHeap[AUDIO_HEAP_SIZE];

static u8       *audioHeapEnd;
static ALHeap   hp;

extern char _wess_wmdSegmentRomStart[], _wess_wmdSegmentRomEnd[];
extern char _wess_wsdSegmentRomStart[], _wess_wsdSegmentRomEnd[];
extern char _wess_wddSegmentRomStart[], _wess_wddSegmentRomEnd[];

static master_status_structure *pms = 0;

void startsound(int sound)
{
    wess_seq_trigger(sound);
}

void stopallsound(void)
{
    wess_seq_stopall();
}

void pauseallsound(void)
{
    wess_seq_pauseall( YesMute, REMEMBER_MUSIC | REMEMBER_SNDFX );
}

void restartallsound(void)
{
    wess_seq_restartall( YesVoiceRestart );
}

int mydecomp( unsigned char decomp_type,
	      char          *fileref,
	      unsigned long file_offset,
	      char          *ramdest,
	      unsigned long uncompressed_size )
{
    if(inflate_cart((char *)((unsigned long)fileref + file_offset),
		    ramdest,
		    decomp_mem,
		    DECOMP_SIZE))
    {
	return(-1);
    }
}

void initAudio(OSPri priority, int num_fields)
{
    int i,wmdlength;
    WessConfig wessconfig;
    WessTweakAttr wesstweek;
    int loaded;
    int modulesize;
    int seqtblsize;
    int seqsize;
    char *moduleptr;
    char *seqtblptr;
    char *seqptr;

    wess_get_tweaks(&wesstweek);

    wesstweek.mask = TWEAK_DMA_BUFFERS | TWEAK_DMA_MESSAGES | TWEAK_DMA_BUFFER_LENGTH | TWEAK_UPDATES | TWEAK_FRAME_LAG;
    wesstweek.dma_buffers += 8;
    wesstweek.dma_messages += 32;
    wesstweek.updates += 24;

    wess_set_tweaks(&wesstweek);
   
    alHeapInit(&hp, audioHeap, sizeof(audioHeap));    

    wessconfig.audioframerate = (num_fields==2)?30:60;
    wessconfig.outputsamplerate = 22050; /*22050;*/
    wessconfig.maxACMDSize = 3 * 1024;
    wessconfig.heap_ptr = &hp;
    wessconfig.wdd_location = _wess_wddSegmentRomStart;
    wessconfig.reverb_id = WESS_REVERB_BIGROOM;
    wessconfig.revtbl_ptr = 0;

    wess_init(&wessconfig);

    wess_set_decomp_callback(mydecomp);
    
    modulesize = wess_size_module(_wess_wmdSegmentRomStart);
    moduleptr = alHeapAlloc(&hp, 1, modulesize);

    //this call may result in decompression callbacks
    loaded  = wess_load_module(_wess_wmdSegmentRomStart,moduleptr,modulesize);

    seqtblsize = wess_seq_loader_sizeof(wess_get_master_status(),_wess_wsdSegmentRomStart);
    seqtblptr = alHeapAlloc(&hp, 1, seqtblsize);

    //this call may result in decompression callbacks
    wess_seq_loader_init(wess_get_master_status(),_wess_wsdSegmentRomStart,NoOpenSeqHandle,seqtblptr,seqtblsize);

    pms = wess_get_master_status();

    seqsize = wess_seq_range_sizeof(0,wess_seq_loader_count());
    seqptr = alHeapAlloc(&hp, 1, seqsize);

    //this call may result in decompression callbacks
    wess_seq_range_load(0,wess_seq_loader_count(),seqptr);

    /*
        alHeapAlloc is used one last time to see how much of the heap has been used.

        alHeapAlloc seems to allocate a minimum of 16 bytes.
    */
    audioHeapEnd = alHeapAlloc(&hp,1,4);
    audioHeapEnd += 16;
    
    //sprintf(statusbuf,"LOAD: %d RAMSIZE: %d",loaded,(unsigned long)audioHeapEnd - (unsigned long)audioHeap);
    //sprintf(statusbuf,"LOAD: %d %d %d %d",loaded,modulesize,seqtblsize,seqsize);


    /*
        SET UP FOR AUDIO THREAD
		wess_work() must be called at audio frame rate
    */

}



