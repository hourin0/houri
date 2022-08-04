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

U0 putchar_xy_attr(UI8 ch,UI16 x,UI16 y,const UI8 fg,const UI8 bg) {
	UI16 tmpcursor=cursor;
	goto_xy(x,y);
	putchar_attr(ch,fg,bg);
	cursor=tmpcursor;
}

UI32 putstr_attr(UI8* str,const UI8 fg,const UI8 bg) {
	UI32 i;
	for (i=0;str[i]!='\0';i++)
		putchar_attr(str[i],fg,bg);
	return i;
}

UI32 putstr_xy_attr(UI8* str,UI16 x,UI16 y,const UI8 fg,const UI8 bg) {
	UI16 tmpcursor=cursor;
	goto_xy(x,y);
	UI32 returnvalue=putstr_attr(str,fg,bg);
	cursor=tmpcursor;
	return returnvalue;
}

