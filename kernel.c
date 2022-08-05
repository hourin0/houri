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
	putstr_attr("Welcome to HouriOS - A free (libre) and open source\
 kernel for x86 systems\n",GREEN,DEF_BG);
	putstr("\tLoading HouriOS kernel: ");
	putstr_attr("OK\n",GREEN,DEF_BG);
	putstr("\tLoading SSatori: ");
	ssatori_entry(); //calls SSatori shell
	putstr_attr("\n\nFATAL: SSatori exitted\n ",RED,DEF_BG);
	sleep(0xAFFFFFF*3);
}
