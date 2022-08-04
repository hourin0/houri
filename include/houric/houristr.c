#include <typedefs.h>
//start of houristr
enum {
	BIN=2,
	OCT=8,
	DEC=10,
	HEX=16
};
static const UI8* hex_digits="0123456789ABCDEF";
static const UI8* dec_digits="0123456789";
UI8 isalpha(UI8 ch) {
	if (ch>=65&&ch<=122)
		return 1;
	else
		return 0;
}
UI8 uppercase_char(UI8 ch) {
	return (ch-32);
}
UI8 lowercase_char(UI8 ch) {
	return (ch+32);
}
U0 uppercase_str(UI8* str) {
	for (UI32 i=0;str[i]!='\0';i++)
		if (isalpha(str[i])&&str[i]>90)
			str[i]=uppercase_char(str[i]);
}
U0 lowercase_str(UI8* str) {
	for (UI32 i=0;str[i]!='\0';i++)
		if (isalpha(str[i])&&str[i]<=90)
			str[i]=lowercase_char(str[i]);
}
UI32 strlen(const UI8* str) {
	UI32 i;
	for (i=0;str[i]!='\0';i++)
		;
	return i;
}
UI8* strcpy(UI8* dest,const UI8* src) {
	memcpy(dest,src,strlen(src)+1);
}
UI8* strcat(UI8* dest,const UI8* src) {
	strcpy(dest+strlen(dest),src);
	return dest;
}

UI8* itoa(const UI32 i,const UI8 base) { //TODO: finish asap
	if (base==BIN) {

	}
	else if (base==OCT) {

	}
	else if (base==DEC) {

	}
	else if (base==HEX) {
	}
	else {
		#ifdef ERRNO_H
		errno=ERR_UNK_BASE;
		#endif
		return 0;	
	}
}
UI32 atoi(const UI8* str,const UI8 base) { //TODO: hex
	int i,n;
	if (base==BIN) {

	}
	else if (base==OCT) {

	}
	else if (base==DEC) { //TODO: does this works?
		n=0;
		for (i=0;str[i]>='0'&&str[i]<='9';++i)
			n=10*n+(str[i]-'0');
	}
	else if (base==HEX) {

	}
	else {
		#ifdef ERRNO_H
		errno=ERR_UNK_BASE;
		#endif
		return 0;
	}
	return n;
}
