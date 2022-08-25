#include <system/keyboard.h>
#include <houric/houristr.h>

UI8 keycodeToASCII(const UI8 key) {	// convert key scancodes to ASCII (table 1)
	switch (key) {
		case KEY_A:
			return 'a'; break;
		case KEY_B:
			return 'b'; break;
		case KEY_C:
			return 'c'; break;
		case KEY_D:
			return 'd'; break;
		case KEY_E:
			return 'e'; break;
		case KEY_F:
			return 'f'; break;
		case KEY_G:
			return 'g'; break;
		case KEY_H:
			return 'h'; break;
		case KEY_I:
			return 'i'; break;
		case KEY_J:
			return 'j'; break;
		case KEY_K:
			return 'k'; break;
		case KEY_L:
			return 'l'; break;
		case KEY_M:
			return 'm'; break;
		case KEY_N:
			return 'n'; break;
		case KEY_O:
			return 'o'; break;
		case KEY_P:
			return 'p'; break;
		case KEY_Q:
			return 'q'; break;
		case KEY_R:
			return 'r'; break;
		case KEY_S:
			return 's'; break;
		case KEY_T:
			return 't'; break;
		case KEY_U:
			return 'u'; break;
		case KEY_V:
			return 'v'; break;
		case KEY_W:
			return 'w'; break;
		case KEY_X:
			return 'x'; break;
		case KEY_Y:
			return 'y'; break;
		case KEY_Z:
			return 'z'; break;
		default:
			return 0x00; break;

	}
}

UI0 getkey(keypacket* key) {	// get keypacket from keyboard and perform modifier bits set/clear
	key->keycode=in_byte(KBINPORT);

	switch (key->keycode) {	// handle modifiers
		case KEY_LSHIFT:
			key->mod|=1<<7; break;
		case KEY_RSHIFT:
			key->mod|=1<<0; break;
		case KEY_LSHIFT+0x80:
			key->mod&=~(1<<7); break;
		case KEY_RSHIFT+0x80:
			key->mod&=~(1<<0); break;
		case KEY_LCTRL:
			key->mod|=1<<6; break;
		case KEY_LMETA:
			key->mod|=1<<5; break;
		// TODO: RCTRL and LMETA
		default:
			break;
		// TODO: is Caps Lock necessary to waste 1 extra bit for ?
	}
}

UI8 isShift(const UI8 mod) {
	return ((mod&(1<<0))||(mod&(1<<7)));
}

UI8 isCtrl(const UI8 mod) {
	return ((mod&(1<<1))||(mod&(1<<6)));
}

UI8 isMeta(const UI8 mod) { 
	return ((mod&(1<<2))||(mod&(1<<5)));
}

UI8 isSuper(const UI8 mod) { // NOTE: i didn't implemented Super key yet
	return ((mod&(1<<3))||(mod&(1<<4)));
}

UI8 keypacketToASCII(const keypacket* key) {	// change keycode to ASCII then modify the ASCII based on UI8 mod
	UI8 tmp=keycodeToASCII(key->keycode);
	if (isShift(key->mod)==1) {
		if (isalpha(tmp)&&tmp>90)	// uppercase if character is lowercase
			return uppercase_char(tmp);
		else if (tmp>=48&&tmp<=57)	// alternative chars if character is number
			;
		else				// default case
			;
	}
	return tmp;
}
