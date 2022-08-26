/* HouriOS Fatal Event handler
 * Called after kernel in boot.s
 * Used in emergency events such as kernel panic
 * Also used to test rand(), srand() and itoa()
 */

#include <typedefs.h>

#include <lowlevel/vga.h>

#include <houric/houricio.h>
#include <houric/houristr.h>

UI0 rsod_main() {
	#define DEF_BG RED
	#define DEF_FG YELLOW
	init_screen(DEF_BG);
	for (UI16 i=0;i<LINE_SIZE;i++)
		putchar_attr(' ',DEF_FG,DEF_FG);
	putstr("\n\n\tFATAL: Kernel exitted with code ");
	putstr_attr("<SYSCODE HERE>\n",DEF_BG,DEF_FG);
	putstr("\n\tIf you believe this is HouriOS' fault, please file a bug report to the git\n repo at");
	putstr_attr(" https://github.com/randomCharacterArray/houri",CYAN,DEF_BG);
	putstr(".\n\tOtherwise reboot and don't do the same dumb mistake twice.\n");
	goto_xy(0,24);
	for (UI16 i=0;i<LINE_SIZE;i++)
		putchar_attr(' ',DEF_FG,DEF_FG);
	srand(69);
	while (1) {
		putchar_xy_attr(rand()%(127-35)+35,
			LINE_SIZE-1,24,
			DEF_BG,DEF_FG);
		putchar_xy_attr(rand()%(127-35)+35,
			LINE_SIZE-2,24,
			DEF_BG,DEF_FG);
		putchar_xy_attr(rand()%(127-35)+35,
			LINE_SIZE-3,24,
			DEF_BG,DEF_FG);
	}
	while (1);
}
