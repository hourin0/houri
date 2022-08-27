
UI0 SSHelp() {
	for (UI32 h=0;h<CMDNUM;h++) {
		putstr_attr(cmdlist[h],GREEN,DEF_BG);
		putstr(": ");
		putstr_attr(cmdhelp[h],RED,DEF_BG);
		newline();
	}
}

UI0 SSClear() {
#ifdef FANCY
	init_vga(BLUE);
	sleep(0xAAA);
	init_vga(YELLOW);
	sleep(0xAAA);
#endif
	init_vga(DEF_BG);
}
