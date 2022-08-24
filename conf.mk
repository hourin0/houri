
#These are cross-compilers I built. You should build them too if you haven't.
CC:=i686-elf-gcc #use i686-elf-gcc as default cc
AS:=nasm #use nasm as default as
LD:=i686-elf-ld	#use i686-elf-ld as default ld

LIBS:= -llowlevel -lhouric -lkeyboard

OPT:=-O0	#C optimization method
CFLAGS:=-std=gnu99 -ffreestanding ${OPT} --no-warning -I"./include"	#cc flags
LFLAGS:=-m elf_i386 --verbose -nostdlib -L"./lib" ${LIBS}	#ld flags
AFLAGS:=-f elf32		#as flags
ASMEXT:=asm			#Assembly file extension (s/asm)

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
