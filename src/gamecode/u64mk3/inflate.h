#define INFLATE_NO_ERR					0
#define INFLATE_MEM_ALLOC_ERR			1
#define INFLATE_INCOMPLETE_TABLE_ERR	2
#define INFLATE_BAD_STORED_SIZE_ERR		3
#define INFLATE_BAD_LENGTH_ERR			4
#define INFLATE_INVALID_BLOCK_ERR		5
#define INFLATE_TOO_MANY_CODES			6
#define INFLATE_LOOKUP_ERR				7
#define INFLATE_DYNAMIC_TABLE_ERR		8
#define INFLATE_PARTIAL_DONE			9

typedef unsigned char uchar;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned long ulong;

int inflate(uchar *mem_src, uchar **dst, uchar *memory_pool, ulong pool_size);
int inflate_cart(uchar *cart_src, uchar **dst, uchar *memory_pool, ulong pool_size);
int inflate_cart_partial(uchar *cart_src, uchar **dst, ulong inflate_count, uchar *memory_pool, ulong pool_size);

