
#define VGA_ADDRESS 0xB8000
#define BUFFER_SIZE 2200
#define LINE_SIZE 80
#define NULL 0
typedef unsigned char UI8;
typedef char I8;
typedef unsigned short UI16;
typedef short I16;
typedef unsigned int UI32;
typedef int I32;
typedef void U0,UI0,I0;

volatile UI16* vga_buffer;
volatile UI16 cursor;
volatile UI16 linechar;
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

UI8 in_byte(UI16 port) {
	UI8 returnval;
	__asm__("inb %1,%0" : "=a"(returnval) : "d"(port));
	return returnval;
}
U0 out_byte(UI16 port,UI8 data) {
	__asm__("outb %0,%1" : "=a"(data) : "d"(port));
}

U0 kb_reset() {
	UI8 tmp=0x02;
	while (tmp&0x02)
		tmp=in_byte(0x64);
	out_byte(0x60,0xFE);
}
U0 triplefault_reset() {
}
U0 reboot_routine() {
	kb_reset(); //first do reboot via reset pin on keyboard
	
	triplefault_reset();	//triplefault as last choice
}

U0 wait_for_io(UI32 timer) {
	while (timer>0) {
		__asm__ volatile("nop");
		timer--;
	}
}
U0 sleep(UI32 time) {
	wait_for_io(time);
}

