/*
	CPU view of the Frame Buffer memory.
	(Linker aligns file to 16 bytes)
*/
#include "u64main.h"
 
long long player_heap[PLAYER_HEAP_SIZE/sizeof(long long)];
