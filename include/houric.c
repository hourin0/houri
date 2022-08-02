//view end of file for list of line index
#include <typedefs.h>

//start of houricio
#define DEF_FG BLACK
#define DEF_BG WHITE
extern volatile UI16* vga_buffer;
extern volatile UI16 cursor;
extern volatile UI16 linechar;

U0 init_screen(UI8 color) {
	if (vga_buffer==NULL)
		init_vga(color);
	clear_vga_buffer(color);
	cursor=0;
	linechar=0;
}
U0 goto_xy(UI16 x,UI16 y) {
	cursor=LINE_SIZE*y+x;
}

U0 putchar_attr(UI8 ch,const UI8 fg,const UI8 bg) {
	if (ch=='\n') {
		cursor=cursor+LINE_SIZE-linechar;
		linechar=0;
	}
	else if (ch=='\t') {
		cursor+=4;
		linechar+=4;
	}
	else {
		if (linechar==LINE_SIZE) {
			cursor=cursor+LINE_SIZE-linechar;
			linechar=0;
		}
		vga_buffer[cursor]=vga_entry(ch,fg,bg);
		linechar++;
		cursor++;
	}
}
#define putchar(ch) putchar_attr(ch,DEF_FG,DEF_BG)

U0 putchar_xy_attr(UI8 ch,UI16 x,UI16 y,const UI8 fg,const UI8 bg) {
	UI16 tmpcursor=cursor;
	goto_xy(x,y);
	putchar_attr(ch,fg,bg);
	cursor=tmpcursor;
}
#define putchar_xy(ch,x,y) putchar_xy_attr(ch,x,y,DEF_FG,DEF_BG)

UI32 putstr_attr(UI8* str,const UI8 fg,const UI8 bg) {
	UI32 i;
	for (i=0;str[i]!='\0';i++)
		putchar_attr(str[i],fg,bg);
	return i;
}
#define putstr(str) putstr_attr(str,DEF_FG,DEF_BG)

UI32 putstr_xy_attr(UI8* str,UI16 x,UI16 y,const UI8 fg,const UI8 bg) {
	UI16 tmpcursor=cursor;
	goto_xy(x,y);
	UI32 returnvalue=putstr_attr(str,fg,bg);
	cursor=tmpcursor;
	return returnvalue;
}
#define putstr_xy(str,x,y) putstr_xy_attr(str,x,y,DEF_FG,DEF_BG)

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
		#ifdef ERRNO_H
		errno=ERR_UNK_BASE;
		#endif
		return 0;
	}
	else {
		
	}
}
UI32 atoi(const UI8* str,const UI8 base) { //TODO: hex
	int i,n;
	if (base==BIN) {

	}
	else if (base==OCT) {

	}
	else if (base==DEC) {
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
/*	Line number index:
	houricio: 4
	hourilib: 65
	houristr:
	hourerr:
*/
