#pragma once
#define STDIO_H

#include <lowlevel/vga.h>

#define DEF_FG BLACK
#define DEF_BG WHITE

U0 init_screen(UI8 color);
U0 goto_xy(UI16 x,UI16 y);

U0 putchar_attr(UI8 ch,const UI8 fg,const UI8 bg);
#define putchar(ch) putchar_attr(ch,DEF_FG,DEF_BG)

U0 putchar_xy_attr(UI8 ch,UI16 x,UI16 y,const UI8 fg,const UI8 bg);
#define putchar_xy(ch,x,y) putchar_xy_attr(ch,x,y,DEF_FG,DEF_BG);

UI32 putstr_attr(UI8* str,const UI8 fg,const UI8 bg);
#define putstr(str) putstr_attr(str,DEF_FG,DEF_BG);

UI32 putstr_xy_attr(UI8* str,UI16 x,UI16 y,const UI8 fg,const UI8 bg);
#define putstr_xy(str,x,y) putstr_xy_attr(str,x,y,DEF_FG,DEF_BG);


