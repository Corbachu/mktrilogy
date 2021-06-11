/*
	CPU view of the Frame Buffer memory.
	(Linker aligns file to 16 bytes)
*/
#include "u64main.h"

u16 cfb[2][BUFFER_WIDTH*BUFFER_HEIGHT];
