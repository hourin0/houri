
#These are cross-compilers I built. You should build them too if you haven't.
CC:=i686-elf-gcc #use i686-elf-gcc as default cc
AS:=i686-elf-as	 #use i686-elf-as as default as
LD:=i686-elf-ld	#use i686-elf-ld as default ld

LIBS:= -llowlevel -lhouric -lkeyboard

OPT:=-O0	#C optimization method
CFLAGS:=-std=gnu99 -ffreestanding ${OPT} --no-warning -I"./include"	#cc flags
LFLAGS:=-m elf_i386 --verbose -nostdlib -L"./lib" ${LIBS}	#ld flags
AFLAGS:=	#as flags
ASMEXT:=s			#Assembly file extension (s/asm)

COMP:=xz	#disk ISO compression method
GFLAGS:=--compress=${COMP}	#grub-mkrescue flags

ARCHIVE:=tar	#program for making archives
PKG:=tar	#archive compression method


KERNELPATH:=kernel
SSATORIPATH:=ssatori

LOWLEVELPATH:=include/lowlevel
HOURICPATH:=include/houric

SYSTEMPATH:=include/system
FSPATH:=${SYSTEM}/fs

# various other defines for C
FANCY?=FANCY	# various aesthetics for SSatori/Kernel ?
PASSWD?=PASSWD	# will SSatori use password login ?
ENCRYPT?=NONE	# SSatori password encryption: SHA256SUM, other values are treated as NONE
