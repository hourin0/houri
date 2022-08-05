#view the conf.mk file for configuration
include conf.mk

iso-grub: houri #copy new kernel binary to isodir/ to build ISO
	mkdir -p isodir/boot/grub
	cp -f houri isodir/boot
	cp -f grub.cfg isodir/boot/grub
	grub-mkrescue ${GFLAGS} -o hourios.iso isodir

houri: boot.o kernel.o ssatori.o rsod.o libs #kernel binary
	${LD} ${LFLAGS} -T linker.ld *.o -o houri

boot.o: #boot header
	${AS} ${AFLAGS} boot.s -o boot.o
kernel.o: #compiles kernel
	${CC} -c kernel.c -o kernel.o ${CFLAGS}
ssatori.o: #compiles SSatori (emergency built-in shell)
	${CC} -c ssatori.c -o ssatori.o ${CFLAGS}
rsod.o: #Red Screen of Death Fatal Event handler
	${CC} -c rsod.c -o rsod.o ${CFLAGS}

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
	rm -f include/houric/*.o
	rm -f *.o
clean: clean-bin clean-libs clean-obj

backup: #backup whole directory
	rm -f hourios-src-archive.${PKG}
	${ARCHIVE} -cvf hourios-src-archive.${PKG} ./*
bintar: houri iso-grub #creates archive of ISO and kernel binary
	rm -f hourios-bin-archive.${PKG}
	${ARCHIVE} -cvf hourios-bin-archive.${PKG} hourios.iso houri
