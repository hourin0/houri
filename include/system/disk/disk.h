#include <typedefs.h>

typedef enum {
	NONE,
	EXT2
} Filesystem;

typedef UI0* Disk;
typedef UI0* Part;

UI8 mount(Part dev);
UI8 unmount(Part dev);

UI8 ismounted(Part dev);
UI0 format(Part dev, Filesystem fs);
