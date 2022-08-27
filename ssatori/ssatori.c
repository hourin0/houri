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

#ifdef PASSWD	// user functions will be enabled if PASSWD is defined
#define NAMELENGTH 20	// username and hostname length
#define PSWDLENGTH 50	// password length
struct user {
	UI8 username[NAMELENGTH];	// is this really needed ?
	UI8 hostname[NAMELENGTH];
	UI8 passwd[50];
	#ifdef SHA256SUM	// enable password encryption ?
		UI8 passwdHash[67];
	#endif
} __attribute__((packed));
typedef struct user user;
user houriuser;
#endif

static UI16 CurY() {	// TODO: does it work ?
	UI32 tmp=cursor;
	UI32 n=0;
	while ((tmp-LINE_SIZE)>=0) {
		n++;
		tmp-=LINE_SIZE;
	}
	return n;
}

UI0 SSGetStr(UI8* str);
UI32 SSLogin(UI8 firstTime);
UI0 SSLogout();
UI0 SSPrompt(U0);
UI0 SSScroll(U0);
UI0 SSMenu(U0);
UI8* SSGetHost(U0);
UI0 SSCommandNotFound();
UI32 SSCheckCommand();
I32 SSControl(const keypacket* key);

UI0 SSHelp();
UI0 SSClear();

#include "commands.h"
#include "funcs.h"
#include "controls.h"
UI32 ssatori_entry() {
	SSLogin(1);
	SSOnce();
	keypacket key;
	UI8 hexstr[10];
	UI32 i=0;
	newline();
	SSPrompt();
	while (SSControl(&key)!=-1) {	// we can't use SSGetStr() here because have to get ctrl keys
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
