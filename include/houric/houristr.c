#include <typedefs.h>
#include <houric/houristr.h>
//start of houristr
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
UI8 strcmp(const UI8* str1,const UI8* str2) {
	if (strlen(str1)!=strlen(str2))
		return 1;
	else {
		UI32 i;
		for (i=0;i<strlen(str1);i++)
			if (str1[i]!=str2[i])
				return 1;
	}
	return 0;
}
UI0 strrev(UI8* string) {
	UI32 len=strlen(string);
	UI32 i=0,k=len-1;
	UI8 tmp;
	for (;i<k;i++) {
		tmp=string[i];
		string[i]=string[k];
		string[k]=tmp;
		k--;
	}
}

UI8 itoa(const UI32 value,UI8* string, const UI8 base) {
	//libre code moment
	UI32 sum=value;
	UI32 i=0;
	UI32 digit;
	UI32 len=strlen(string);
	if (len==0)
		return -1;
	while (sum&&(i<(len-1))) {
		digit=sum%base;
		if (digit<0xA)
			string[i++]='0'+digit;
		else
			string[i++]='A'+digit-0xA;
		sum/=base;
	}
	string[i]='\0';
	strrev(string);
	return 0;
}
UI32 atoi(const UI8* str,const UI8 base) { //TODO: hex
	int i,n;
	if (base==BIN) {

	}
	else if (base==OCT) {

	}
	else if (base==DEC) { //TODO: does this works?

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
