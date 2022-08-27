UI0 SSGetStr(UI8* str) {
	static keypacket key;
	UI32 i=0;
	UI8 ch;
	while (1) {
		getkey(&key);
		ch=keypacketToASCII(&key);
		if (ch=='\n') {
			newline();
			str[i]='\0';
			break;
		}
		else if (ch!=0x00) {
			str[i]=ch;
			i++;
			putchar(ch);
		}
		sleep(0xAAAA);
	}
	return ;
}

#ifdef PASSWD
UI32 SSLogin(UI8 firstTime) {
	newline();
	if (firstTime==1) {
		putstr("Type your username: ");
		SSGetStr(houriuser.username);
		sleep(0xAAFF);
		putstr("Type your password: ");
		SSGetStr(houriuser.passwd);
		strcpy(houriuser.hostname,"localhost");
	}
	if (firstTime==0) {
		UI8 pass[PSWDLENGTH];
		while (1) {
			putstr("Enter password for ");
			putstr(houriuser.username);
			putchar(':');
			SSGetStr(pass);
			if (strcmp(pass,houriuser.passwd)!=0) {
				putstr("\nWrong password. Try again.\n");
			}
			else
				break;
		}
	}
}
UI0 SSLogout() {
	putstr("Logout\n");
}
#endif

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

UI0 SSPrompt() {
#ifdef PASSWD
	putstr_attr(houriuser.username,GREEN,DEF_BG);
	putchar('@');
	putstr_attr(houriuser.hostname,MAGENTA,DEF_BG);
#else
	putstr_attr("@localhost> ",MAGENTA,DEF_BG);
#endif
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
