#pragma once

// TODO: implement structs for partition and block devices
typedef void* part;
typedef void* disk;

typedef enum {
	UNFORMATTED,
	EXT2,
	EXT3,
	EXT4,
	FAT32
} Filesystem;

// TODO: which one ?
UI8 isPartMounted(part partition);	// is partition mounted ?
UI32 mkfs(part partition,Filesystem fs);
UI32 mount(part partition,const UI8* path);	// path ?
UI32 unmount(part partition);
UI32 fdisk(disk device);

