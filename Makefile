#These are cross-compilers I built. You should build them too if you haven't.
CC:=gcc	#use gcc as default cc
AS:=as	#use as as default as
LD:=ld	#use ld as default ld

OPT:=-O2	#C optimization method
CFLAGS:=-m32 -std=gnu99 -ffreestanding ${OPT} --no-warning -I"./include"	#cc flags
LFLAGS:=-m elf_i386 --verbose -nostdlib #ld flags
AFLAGS:=--32	#as flags

COMP:=xz	#disk ISO compression method
GFLAGS:=--compress=${COMP}	#grub-mkrescue flags

ARCHIVE:=tar	#program for making archives
PKG:=tar	#archive compression method


iso-grub: houri #copy new kernel binary to isodir/ to build ISO
	mkdir -p isodir/boot/grub
	cp -f houri isodir/boot
	cp grub.cfg isodir/boot/grub
	grub-mkrescue ${GFLAGS} -o hourios.iso isodir

houri: boot.o kernel.o #kernel binary
	${LD} ${LFLAGS} -T linker.ld *.o -o houri

boot.o: #boot header
	${AS} ${AFLAGS} boot.s -o boot.o
kernel.o: #compiles kernel
	${CC} -c kernel.c -o kernel.o ${CFLAGS}

#for cleaning up. should be self-explainatory
clean-bin:
	rm -f hourios.iso
	rm -f houri
clean-obj:
	rm -f *.o
clean: clean-bin clean-libs clean-obj

backup: #backup whole directory
	rm -f hourios-src-archive.${PKG}
	${ARCHIVE} -cvf hourios-src-archive.${PKG} ./*
bintar: houri iso-grub #creates archive of ISO and kernel binary
	rm -f hourios-bin-archive.${PKG}
	${ARCHIVE} -cvf hourios-bin-archive.${PKG} hourios.iso houri
