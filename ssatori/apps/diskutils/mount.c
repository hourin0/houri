#include "diskutils"
#include <typedefs.h>

int mount(part partition,const UI8* path) {
	if (!partition)
		return -1;
	if (!path) {
		// TODO: default mount point at /mnt
	}

}
