#include <typedefs.h>

#include <lowlevel/vga.h>
#include <lowlevel/io.h>
#include <lowlevel/wait.h>
#include <lowlevel/power.h>


#include <houric/houricio.h>
#include <houric/houristr.h>
#include <houric/hourilib.h>

U0 kernel_entry() {
	init_vga(DEF_BG);
	const UI32 waittimer=0xAFFFFFF;
	putstr_attr("Welcome to HouriOS - A free (libre) and open source kernel for x86 systems\n",GREEN,DEF_BG);
	putstr("\tLoading HouriOS kernel: ");
	putstr_attr("OK",GREEN,DEF_BG);
	putchar('\n');
	putstr("\tLoading SSatori: ");
	sleep(waittimer*8);
	putstr_attr("OK",GREEN,DEF_BG);
	putchar('\n');
	ssatori_entry(); //calls SSatori shell

}
