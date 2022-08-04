#pragma once
UI16 vga_entry(UI8 ch,UI8 fore_color,UI8 back_color) {
	UI16 ax=0;
	UI8 ah=0,al=0;
	ah=back_color;
	ah<<=4;
	ah|=fore_color;
	ax=ah;
	ax<<=8;
	al=ch;
	ax|=al;
	
	return ax;
}
U0 clear_vga_buffer(UI8 color) {
	for (UI16 i=0;i<BUFFER_SIZE;i++)
		vga_buffer[i]=vga_entry(NULL,color,color);
}
U0 init_vga(UI8 color) {
	vga_buffer=(UI16*)VGA_ADDRESS;
	clear_vga_buffer(color);
	cursor=0;
}
