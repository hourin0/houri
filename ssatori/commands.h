

UI0 SSCommandNotFound() {
	putstr_attr("SSatori: ",RED,DEF_BG);
	putstr_attr(cmd,MAGENTA,DEF_BG);
	putstr_attr(": Command not found\n",RED,DEF_BG);
}

UI32 SSCheckCommand() {
	if (cmd[0]==0x00)
		return 0;

	if (!strcmp(cmd,"ping")) {
		putstr("pong\n");
	}

	else if (!strcmp(cmd,"clear")) {
	#ifdef FANCY
		init_vga(BLUE);
		sleep(0xAAA);
		init_vga(YELLOW);
		sleep(0xAAA);
	#endif
		init_vga(DEF_BG);
	}

	else if (!strcmp(cmd,"scroll")) {
		SSScroll();
	}

	else
		SSCommandNotFound();

}

