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

int mkfs(part partition,Filesystem fs);
int mount(part partition,const UI8* path);	// path ?
int unmount(part partition);
int fdisk(disk device);

