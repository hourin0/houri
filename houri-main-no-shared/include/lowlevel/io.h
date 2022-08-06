#pragma once
UI8 in_byte(UI16 port);
U0 out_byte(UI16 port,UI8 data);

UI8 in_byte(UI16 port) {
	UI8 returnval;
	__asm__ volatile ("inb %1,%0" : "=a"(returnval) : "d"(port));
	return returnval;
}
U0 out_byte(UI16 port,UI8 data) {
	__asm__ volatile ("outb %0,%1" : "=a"(data) : "d"(port));
}
