#include <typedefs.h>
//start of hourilib
U0 memcpy(U0* dest,const U0* src,UI32 len) {
	UI8* d=dest;
	const UI8* s=src;
	while (len--)
		*d++=*s++;
}
U0 memset(U0* dest,I32 val,UI32 len) {
	UI8* ptr=dest;
	while ((len--)>0)
		*ptr++=val;
}

/*	Line number index:
	houricio: 4
	hourilib: 68
	houristr: 81
	hourerr:
*/
