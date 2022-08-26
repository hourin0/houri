#pragma once
#define STDIO_H

#include <lowlevel/vga.h>

#define DEF_FG BLACK
#define DEF_BG WHITE

U0 init_screen(UI8 color);
U0 goto_xy(UI16 x,UI16 y);

U0 putchar_attr(UI8 ch,const UI8 fg,const UI8 bg);
U0 putchar(UI8 ch);

U0 putchar_xy_attr(UI8 ch,UI16 x,UI16 y,const UI8 fg,const UI8 bg);
U0 putchar_xy(UI8 ch,UI16 x,UI16 y);

UI32 putstr_attr(UI8* str,const UI8 fg,const UI8 bg);
UI32 putstr(UI8* str);

UI32 putstr_xy_attr(UI8* str,UI16 x,UI16 y,const UI8 fg,const UI8 bg);
UI32 putstr_xy(UI8* str,UI16 x,UI16 y);


