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

static UI16 CurY() {	// TODO: does it work ?
	UI32 tmp=cursor;
	UI32 n=0;
	while ((tmp-LINE_SIZE)>=0) {
		n++;
		tmp-=LINE_SIZE;
	}
	return n;
}

UI0 SSOnce(U0);
UI0 SSPrompt(U0);
UI0 SSScroll(U0);
UI8* SSGetHost(U0);
UI8* SSGetString(U0);
UI32 SSCheckCommand(const UI8* cmd);

UI0 SSOnce(U0) {
	putstr_attr("OK\n",GREEN,DEF_BG);
	putstr_attr("\n\nSSatori Hello World!\n",MAGENTA,YELLOW);
	putstr("Novice user press C-h for a list of built-in commands\n");
	putstr("Press C-m for a list of defined key shortcuts\n");
}

UI0 SSPrompt(U0) {
	newline();
	putstr_attr("@localhost> ",MAGENTA,DEF_BG);
}

UI32 ssatori_entry() {
	SSOnce();
	keypacket key;
	UI8 hexstr[10];
	SSPrompt();
	newline();
	const oldCursor=cursor;
	while (1) {
		getkey(&key);
		putstr("  Character you type from keyboard will be here: \0");
		putchar_attr(keypacketToASCII(&key),RED,DEF_BG);
		cursor=oldCursor;
	}
	return 0xFF;
}
