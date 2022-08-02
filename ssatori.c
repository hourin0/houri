#include <typedefs.h>

#include <lowlevel/vga.h>
#include <lowlevel/io.h>
#include <lowlevel/wait.h>
#include <lowlevel/power.h>


#include <houric/houricio.h>
#include <houric/houristr.h>
#include <houric/hourilib.h>

U0 ssatori_entry() {
	putstr("SSatori Hello World!\n");
	while (1) ;

}
