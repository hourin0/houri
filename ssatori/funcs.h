#ifdef PASSWD
UI32 SSLogin(UI8 firstTime,user* u) {
	if (firstTime==1) {
		putstr("Type your username: ");
		putstr("Type your password: ");
	}
	if (firstTime==0) {

	}
}
UI0 SSLogout() {
	
}
#endif

UI0 SSGetStr(UI8* str,keypacket* key) {
	UI32 i=0;
	UI8 chget;
	while (1) {
		getkey(key);
		chget=keypacketToASCII(key);
		if (chget=='\n') {
			newline();
			str[i]='\0';
			break;
		}
		else if (chget!=0x00) {
			str[i]=chget;
			i++;
			putchar(chget);
		}
		sleep(0xAAAA);
	}
}
UI0 SSMenu(U0) {
	#define MENUENTRY(x) putstr_attr(x,RED,YELLOW)
	newline();
	MENUENTRY("C-m");
	putstr(": Prints this menu");
	newline();
}

UI0 SSOnce(U0) {
	putstr_attr("OK\n",GREEN,DEF_BG);
	putstr_attr("\n\nSSatori Hello World!\n",MAGENTA,YELLOW);
	putstr("Novice user press C-h for a list of built-in commands\n");
	putstr("Press C-m for a list of defined key shortcuts\n");
	putstr("M-F4 to exit\n");
}

UI0 SSPrompt(U0) {
	putstr_attr("@localhost> ",MAGENTA,DEF_BG);
}

UI0 SSScroll() {
	// TODO: scroll
}


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
