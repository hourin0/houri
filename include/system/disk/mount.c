#include <typedefs.h>
#include <system/disk/disk.h>

UI8 mount(Part dev) {
	if (!dev)
		return 1;
	else if (ismounted(dev)==1)
		return 2;
	// TODO: mounting here
	return 0;
}
