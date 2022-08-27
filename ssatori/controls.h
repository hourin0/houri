#pragma once

I32 SSControl(const keypacket* key) {
	UI8 tmpstr[255];
	UI8 chget=keycodeToASCII(key->keycode);
	if (isCtrl(key->mod)==1) {
		if (chget=='m')	// print control menu
			SSMenu();
		else if (chget=='c') {	// cancel command
			newline();
			for (UI32 k=0;k<=255;k++)
				cmd[k]=0x00;
			SSPrompt();
		}
		else if (chget=='l') {	// clear screen
			newline();
			SSClear();
			SSPrompt();
			for (UI32 h=0;cmd[h]!=0x00;h++)
				putchar(cmd[h]);
		}
		else if (chget=='x') {
		#ifdef PASSWD
			SSLogout();
		#else
			putstr_attr("\nUser functions not enabled in this HouriOS install.\n",RED,DEF_BG);
			SSPrompt();
		#endif
		}
		else if (chget=='t') {
			putstr("\nType a string: ");
			SSGetStr(tmpstr);
			putstr("You typed: "); 
			putstr(tmpstr);
			newline();
			SSPrompt();
		}
	}

	if (isMeta(key->mod)==1) {
		if (key->keycode==KEY_F4)
			return -1;
	}
}
