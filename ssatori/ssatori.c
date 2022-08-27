#include <typedefs.h>

#include <lowlevel/vga.h>
#include <lowlevel/io.h>
#include <lowlevel/wait.h>
#include <lowlevel/power.h>

#include <system/keyboard.h>

#include <houric/houricio.h>
#include <houric/houristr.h>
#include <houric/hourilib.h>

#define newline() putchar('\n');
#define CurX() linechar

static UI8 cmd[255];
static UI8 chget;

static UI16 CurY() {	// TODO: does it work ?
	UI32 tmp=cursor;
	UI32 n=0;
	while ((tmp-LINE_SIZE)>=0) {
		n++;
		tmp-=LINE_SIZE;
	}
	return n;
}


UI0 SSPrompt(U0);
UI0 SSScroll(U0);
UI0 SSMenu(U0);
UI8* SSGetHost(U0);
UI0 SSCommandNotFound();
UI32 SSCheckCommand();
I32 SSControl(const keypacket* key);

#include "commands.h"
#include "controls.h"

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

UI32 ssatori_entry() {
	SSOnce();
	keypacket key;
	UI8 hexstr[10];
	UI32 i=0;
	newline();
	SSPrompt();
	while (SSControl(&key)!=-1) {
		getkey(&key);
		chget=keypacketToASCII(&key);
		if (chget=='\n') {
			newline();
			SSCheckCommand();
			for (UI32 k=0;k<=255;k++)	// clear cmd string
				cmd[k]=0x00;
			SSPrompt();
			i=0;	// reset cmd string index
		}
		else if (chget!=0x00) {
			cmd[i]=chget;
			i++;
			putchar(chget);
		}
		sleep(0xAAAA);
	}
	return 0xFF;
}
