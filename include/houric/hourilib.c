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

static UI32 next=1;
UI32 rand(U0) {
	next=next*1103515245+12345;
	return (next/65536)%32768;
}
UI0 srand(UI32 seed) {
	next=seed;
}
