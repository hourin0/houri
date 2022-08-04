#pragma once
#ifndef STDIO_H
#define STDIO_H

#define DEF_FG BLACK
#define DEF_BG WHITE

U0 init_screen(UI8 color);
U0 goto_xy(UI16 x,UI16 y);

U0 putchar_attr(UI8 ch,const UI8 fg,const UI8 bg);
U0 putchar_xy_attr(UI8 ch,UI16 x,UI16 y,const UI8 fg,const UI8 bg);

UI32 putstr_attr(UI8* str,const UI8 fg,const UI8 bg);
UI32 putstr_xy_attr(UI8* str,UI16 x,UI16 y,const UI8 fg,const UI8 bg);

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

#endif
