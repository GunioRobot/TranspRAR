#import "CSStreamHandle.h"

#if !__LP64__
#define _LZMA_UINT32_IS_ULONG
#endif

#define Byte LzmaByte
#import "lzma/Lzma2Dec.h"
#undef Byte

@interface XADLZMA2Handle:CSStreamHandle
{
	CSHandle *parent;
	off_t startoffs;

	CLzma2Dec lzma;

	uint8_t inbuffer[16*1024];
	int bufbytes,bufoffs;
	BOOL seekback;
}

-(id)initWithHandle:(CSHandle *)handle propertyData:(NSData *)propertydata;
-(id)initWithHandle:(CSHandle *)handle length:(off_t)length propertyData:(NSData *)propertydata;
-(void)dealloc;

-(void)setSeekBackAtEOF:(BOOL)seekateof;

-(void)resetStream;
-(int)streamAtMost:(int)num toBuffer:(void *)buffer;

@end
