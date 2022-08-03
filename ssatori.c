#include <typedefs.h>

#include <lowlevel/vga.h>
#include <lowlevel/io.h>
#include <lowlevel/wait.h>
#include <lowlevel/power.h>

#include <houric/houricio.h>
#include <houric/houristr.h>
#include <houric/hourilib.h>

#define newline() putchar('\n');

U0 ssatori_entry() {
	putstr_attr("OK\n",GREEN,DEF_BG);
	putstr("\n\nSSatori Hello World!\n");
	putstr("Novice user press C-h for a list of built-in commands\n");
	putstr_attr("@localhost> ",MAGENTA,DEF_BG);

}
