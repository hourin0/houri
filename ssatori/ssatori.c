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
UI32 SSCheckCommand();

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

I32 SSControl(const keypacket* key) {
	if (isCtrl(key->mod)==1)
		if (keycodeToASCII(key->keycode)=='m')
			SSMenu();
	if (isMeta(key->mod)==1)
		if (key->keycode==KEY_F4)
			return -1;
}

UI0 SSCommandNotFound() {
	putstr_attr("SSatori: ",RED,DEF_BG);
	putstr_attr(cmd,MAGENTA,DEF_BG);
	putstr_attr(": Command not found\n",RED,DEF_BG);
}

UI32 SSCheckCommand() {
	if (cmd[0]==0x00)
		return 0;
	if (strcmp(cmd,"ping")==0) {
		putstr("pong\n");
	}
	else if (strcmp(cmd,"clear")==0) {
	#ifdef FANCY
		init_vga(BLUE);
		sleep(0xAAA);
		init_vga(YELLOW);
		sleep(0xAAA);
	#endif
		init_vga(DEF_BG);
	}
	else
		SSCommandNotFound();

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
