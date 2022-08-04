U0 kb_reset();
U0 triplefault_reset();
U0 reboot_routine();

U0 kb_reset() {
	UI8 tmp=0x02;
	while (tmp&0x02)
		tmp=in_byte(0x64);
	out_byte(0x60,0xFE);
}
U0 triplefault_reset() {
	__asm__ volatile("jmp $0xFFFF,$0");
}
U0 reboot_routine() {
	kb_reset(); //first do reboot via reset pin on keyboard
	
	triplefault_reset();	//triplefault as last choice
}
