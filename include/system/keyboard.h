#pragma once
#include <typedefs.h>

#define KEY_1 0x02
#define KEY_2 0x03
#define KEY_3 0x04
#define KEY_4 0x05
#define KEY_5 0x06
#define KEY_6 0x07
#define KEY_7 0x08
#define KEY_8 0x09
#define KEY_9 0x0A
#define KEY_0 0x0B

#define KEY_Q 0x10
#define KEY_W 0x11
#define KEY_E 0x12
#define KEY_R 0x13
#define KEY_T 0x14
#define KEY_Y 0x15
#define KEY_U 0x16
#define KEY_I 0x17
#define KEY_O 0x18
#define KEY_P 0x19

#define KEY_A 0x1E
#define KEY_S 0x1F
#define KEY_D 0x20
#define KEY_F 0x21
#define KEY_G 0x22
#define KEY_H 0x23
#define KEY_J 0x24
#define KEY_K 0x25
#define KEY_L 0x26

#define KEY_Z 0x2C
#define KEY_X 0x2D
#define KEY_C 0x2E
#define KEY_V 0x2F
#define KEY_B 0x30
#define KEY_N 0x31
#define KEY_M 0x32

#define KEY_BACKSPACE 0x0E
#define KEY_DELETE 0x53
#define KEY_RETURN 0x1C
#define KEY_ESC 0x01

#define KEY_LSHIFT 0x2A
#define KEY_RSHIFT 0x36

#define KBINPORT 0x60
#define KBOUTPORT 0x64

struct keypacket {
	UI8 keycode;
	UI8 mod;
/*
	UI8 mod explaination:
	byte:	0 0 0 0 0 0 0 0
	number:	7 6 5 4 3 2 1 0
		bit 0: right shift
		bit 7: left shift
		bit 1: right control
		bit 6: left control
		bit 2: right meta
		bit 5: left meta
		bit 3: right super
		bit 4: left super
*/
} __attribute__((packed)) ;
typedef struct keypacket keypacket;

UI0 getkey(keypacket* key);
UI8 keycodeToASCII(const UI8 key);
UI8 isShift(const UI8 mod);
UI8 isCtrl(const UI8 mod);
UI8 isMeta(const UI8 mod);
UI8 isSuper(const UI8 mod);
UI8 keypacketToASCII(const keypacket* key);
