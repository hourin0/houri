#These are cross-compilers I built. You should build them too if you haven't.
CC:=i686-elf-gcc#use i686-elf-gcc as default cc
AS:=i686-elf-as	#use i686-elf-as as default as
LD:=i686-elf-ld	#use i686-elf-ld as default ld

OPT:=-O2	#C optimization method
CFLAGS:=-std=gnu99 -ffreestanding ${OPT} --no-warning -I"./include"	#cc flags
LFLAGS:=-m elf_i386 --verbose -nostdlib -L"./lib" -llowlevel -lhouric	#ld flags
AFLAGS:=			#as flags

COMP:=xz	#disk ISO compression method
GFLAGS:=--compress=${COMP}	#grub-mkrescue flags

ARCHIVE:=tar	#program for making archives
PKG:=tar	#archive compression method


iso-grub: houri #copy new kernel binary to isodir/ to build ISO
	mkdir -p isodir/boot/grub
	cp -f houri isodir/boot
	cp grub.cfg isodir/boot/grub
	grub-mkrescue ${GFLAGS} -o hourios.iso isodir

houri: boot.o kernel.o ssatori.o libs #kernel binary
	${LD} ${LFLAGS} -T linker.ld *.o -o houri

boot.o: #boot header
	${AS} ${AFLAGS} boot.s -o boot.o

kernel.o: #compiles kernel
	${CC} -c kernel.c -o kernel.o ${CFLAGS}

ssatori.o: #compiles SSatori (emergency built-in shell)
	${CC} -c ssatori.c -o ssatori.o ${CFLAGS}

libs: houric.o lowlevel.o #compiles shared library. requires a i686-elf compiler and linker
	mkdir -p ./lib
	${LD} -r include/lowlevel/lowlevel.o -o ./lib/liblowlevel.so
	${LD} -r include/houric/*.o -o ./lib/libhouric.so

lowlevel.o:
	${CC} ${CFLAGS} -c -fPIC include/lowlevel/lowlevel.c -o include/lowlevel/lowlevel.o
houric.o: #TODO: apply GNU Make file pattern to avoid yyp in Vim
	${CC} ${CFLAGS} -c -fPIC include/houric/houricio.c -o include/houric/houricio.o
	${CC} ${CFLAGS} -c -fPIC include/houric/houristr.c -o include/houric/houristr.o
	${CC} ${CFLAGS} -c -fPIC include/houric/hourilib.c -o include/houric/hourilib.o

#for cleaning up. should be self-explainatory
clean-bin:
	rm -f hourios.iso
	rm -f houri
clean-libs:
	rm -f lib/*
clean-obj:
	rm -f include/lowlevel/*.o
	rm -f include/lowlevel/*.o
	rm -f *.o
clean: clean-bin clean-libs clean-obj

backup: #backup whole directory
	rm -f hourios-src-archive.${PKG}
	${ARCHIVE} -cvf hourios-src-archive.${PKG} ./*
bintar: houri iso-grub #creates archive of ISO and kernel binary
	rm -f hourios-bin-archive.${PKG}
	${ARCHIVE} -cvf hourios-bin-archive.${PKG} hourios.iso houri
