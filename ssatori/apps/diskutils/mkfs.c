#include "diskutils.h"

int mkfs(part partition,Filesystem fs) {
	if (!partition)	// partition not found
		return -1;
	if (fs<UNFORMATTED||fs>FAT32) // filesystem not supported
		return -2;
	
}
