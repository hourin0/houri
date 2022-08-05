#ifndef STRING_H
#define STRING_H

UI8 isalpha(UI8 ch);
UI8 uppercase_char(UI8 ch);
UI8 lowercase_char(UI8 ch);
U0 uppercase_str(UI8* str);
U0 lowercase_str(UI8* str);
UI32 strlen(const UI8* str);
UI8* strcpy(UI8* dest,const UI8* src);
UI8* strcat(UI8* dest,const UI8* src);
UI8 strcmp(const UI8* str1,const UI8* str2);
UI0  strrev(UI8* string);

enum {
	BIN=2,
	OCT=8,
	DEC=10,
	HEX=16
};
UI8 itoa(const UI32 value,UI8* string,const UI8 base);
UI32 atoi(const UI8* str,const UI8 base);


#endif
