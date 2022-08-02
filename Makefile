CC:=i686-elf-gcc
AS:=i686-elf-as
LD:=i686-elf-ld
OPT:=-O2
COMP:=xz
CFLAGS:=-std=gnu99 -ffreestanding ${OPT} --no-warning -I"./include"
LFLAGS:=-m elf_i386 --verbose -nostdlib -L"./lib" -llowlevel -lhouric
AFLAGS:=
GFLAGS:=--compress=${COMP}

iso: hourios
	mkdir -p isodir/boot/grub
	cp -f hourios isodir/boot
	cp grub.cfg isodir/boot/grub
	grub-mkrescue ${GFLAGS} -o hourios.iso isodir

hourios: boot.o kernel.o ssatori.o houriclib 
	${LD} ${LFLAGS} -T linker.ld *.o -o hourios 

boot.o:
	${AS} ${AFLAGS} boot.s -o boot.o

kernel.o:
	${CC} -c kernel.c -o kernel.o ${CFLAGS}

ssatori.o:
	${CC} -c ssatori.c -o ssatori.o ${CFLAGS}

houriclib:
	mkdir -p ./lib
	${CC} ${CFLAGS} -c -fPIC ./include/lowlevel.c -o ./include/lowlevel.o
	${LD} -r ./include/lowlevel.o -o ./lib/liblowlevel.so
	${CC} ${CFLAGS} -c -fPIC ./include/houric.c -o ./include/houric.o
	${LD} -r ./include/houric.o -o ./lib/libhouric.so

clean:
	rm -f hourios.iso
	rm -f hourios
	rm -f lib/*
	rm -f include/*.o
	rm -f *.o

backup:
	rm -f kernel.tar
	tar -cvf kernel.tar ./*
