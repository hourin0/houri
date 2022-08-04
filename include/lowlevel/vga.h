#pragma once
#define VGA_H
#define VGA_ADDRESS 0xB8000
#define BUFFER_SIZE 2200
#define LINE_SIZE 80
UI16 vga_entry(UI8 ch,UI8 fg,UI8 bg);
U0 clear_vga_buffer(UI8 color);
U0 init_vga(UI8	color);

extern volatile UI16* vga_buffer;
extern volatile UI16 cursor;
extern volatile UI16 linechar;

enum vga_color {
	BLACK,
	BLUE,
	GREEN,
	CYAN,
	RED,
	MAGENTA,
	BROWN,
	GREY,
	DARK_GREY,
	BRIGHT_BLUE,
	BRIGHT_GREEN,
	BRIGHT_CYAN,
	BRIGHT_RED,
	BRIGHT_MAGENTA,
	YELLOW,
	WHITE
};
