#pragma once

I32 SSControl(const keypacket* key) {
	UI8 chget=keycodeToASCII(key->keycode);
	if (isCtrl(key->mod)==1) {
		if (chget=='m')
			SSMenu();
		else if (chget=='c') {
			newline();
			for (UI32 k=0;k<=255;k++)
				cmd[k]=0x00;
			SSPrompt();
		}
	}

	if (isMeta(key->mod)==1) {
		if (key->keycode==KEY_F4)
			return -1;
	}
}
