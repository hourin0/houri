#include "diskutils"
#include <typedefs.h>

UI32 mount(part partition,const UI8* path) {
	if (!partition)
		return -1;
	if (!path) {
		// TODO: default mount point at /mnt
	}

}

UI32 unmount(part partition) {
	if (!isPartMounted(partition))	// not mounted ?
		return -1;
}

