#ifndef STDLIB_H
#define STDLIB_H

U0 memcpy(U0* dest,const U0* src,UI32 len);
U0 memset(U0* dest,I32 val,UI32 len);

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

#endif
