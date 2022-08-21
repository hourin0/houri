#pragma once
#define EXT2_FS

#include <typedefs.h>

enum {	// filesystem state
	CLEAN = 1,
	ERROR = 2
};

enum {	// what to do in case of errors
	IGNORE = 1,
	REMOUNT = 2,
	PANIC = 3
};

enum {	// OS ID
	LINUX = 0,
	HURD = 1,
	MASIX = 2,
	FREEBSD = 3,
	OTHER = 4
};



struct Inode {


};

struct Superblock {
	UI32 totalInode;
	UI32 totalBlock;
	UI32 suBlock;		// blocks reserved for superuser
	UI32 totalUnallocBlock;
	UI32 totalUnallocInode;
	UI32 blockNumber;	// block number of Superblock
	UI32 blockSize;
	UI32 fragSize;
	UI32 groupBlockNum;	// number of blocks in each group
	UI32 groupFragNum;	// number of fragments in each group
	UI32 groupInodeNum;	// number of inodes in each group
	UI32 lastMount;
	UI32 lastWritten;
	UI16 timeMounted;	// times mounted since last consistency check
	UI16 allowdMount;	// number of mounts allowed before cons. check
	UI16 signature;		// =0xEF53 (Ext2 signature)
	UI16 state;
	UI16 error;
	UI16 minorVersion;	// minor portion of version
	UI32 timeLastCheck;	// time since last consistency check
	UI32 timeForceCheck;	// time between forced checks
	UI32 id;		// OS ID
	UI32 majorVersion;	// major portion of version
	UI16 suBlockUID;	// user ID allowed to use superuser block
	UI16 suBlockGID;	// group ID allowed to use superuser block
} attribute((__packed__));

struct BlockGroupDesc {
	UI32 blockBitmapAddress;
	UI32 inodeBitmapAddress;
	UI32 inodeTabAddress;		// starting block address of inode table
	UI16 unallocBlockNum;		// number of unallocated blocks in group
	UI16 unallocInodeNum;		// number of unallocated inodes in group
	UI16 dirNum;			// number of directories in group
	// padding to 31st byte
} attribute((__packed__));

struct Inode {
	UI16 type;	// type and permission
	UI16 userID;
	UI32 size;	// size in bytes
	UI32 lastAccess;	// last accessed time
	UI32 lastModified;	// last modification time
	UI32 timeDeleted;	// time of deletion
	UI16 groupID;
	UI16 hardlinksNum;	// count of hardlinks to this inode
	UI32 sectorsNum;	// count of disk sectors used by this inode
	UI32 flags;
	UI32 OSSpecificVal;
	UI32 directBlockPointer[11];
	UI32 singlyIndirectBlockPointer;
	UI32 doublyIndirectBlockPointer;
	UI32 triplyIndirectBlockPointer;
	UI32 genNum;		// generation number
	UI32 reserved[2];	// reserved if Ext2 version 0
	UI32 fragmentAddress;	// block address of fragment
	UI32 OSSpecificVal2;
} attribute((__packed__));

 
