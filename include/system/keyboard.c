#include <system/keyboard.h>

UI8 keycodeToASCII(const UI8 key) {
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
