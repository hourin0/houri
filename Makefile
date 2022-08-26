#view the conf.mk file for configuration
include conf.mk

build: iso-grub houri
	mkdir -p build/
	cp -f houri hourios.iso build/

iso-grub: houri #copy new kernel binary to isodir/ to build ISO
	mkdir -p isodir/boot/grub
	cp -f houri isodir/boot
	cp -f grub.cfg isodir/boot/grub
	grub-mkrescue ${GFLAGS} -o hourios.iso isodir

houri: boot.o kernel.o ssatori.o rsod.o libs #kernel binary
	${LD} ${LFLAGS} -T linker.ld *.o -o houri

boot.o: #boot header
	${AS} ${AFLAGS} boot/boot.${ASMEXT} -o boot.o
kernel.o: #compiles kernel
	${CC} -c ${KERNELPATH}/kernel.c -o kernel.o ${CFLAGS}
ssatori.o: #compiles SSatori (emergency built-in shell)
	${CC} -c ${SSATORIPATH}/ssatori.c -o ssatori.o ${CFLAGS}
rsod.o: #Red Screen of Death Fatal Event handler
	${CC} -c ${KERNELPATH}/rsod.c -o rsod.o ${CFLAGS}

libs: houric.o lowlevel.o system.o
	mkdir -p ./lib
	${LD} -r ${LOWLEVELPATH}/lowlevel.o -o ./lib/liblowlevel.so
	${LD} -r ${HOURICPATH}/*.o -o ./lib/libhouric.so
	${LD} -r ${SYSTEMPATH}/keyboard.o -o ./lib/libkeyboard.so

lowlevel.o:
	${CC} ${CFLAGS} -c -fPIC ${LOWLEVELPATH}/lowlevel.c -o ${LOWLEVELPATH}/lowlevel.o
system.o:
	${CC} ${CFLAGS} -c -fPIC ${SYSTEMPATH}/keyboard.c -o ${SYSTEMPATH}/keyboard.o
houric.o: #TODO: apply GNU Make file pattern to avoid yyp in Vim
	${CC} ${CFLAGS} -c -fPIC ${HOURICPATH}/houricio.c -o ${HOURICPATH}/houricio.o
	${CC} ${CFLAGS} -c -fPIC ${HOURICPATH}/houristr.c -o ${HOURICPATH}/houristr.o
	${CC} ${CFLAGS} -c -fPIC ${HOURICPATH}/hourilib.c -o ${HOURICPATH}/hourilib.o

#for cleaning up. should be self-explainatory
clean-bin:
	rm -f hourios.iso
	rm -f houri
clean-libs:
	rm -f lib/*
clean-obj:
	rm -f ${LOWLEVELPATH}/*.o
	rm -f ${HOURICPATH}/*.o
	rm -f *.o
clean-builds:
	rm -f build/*
clean: clean-bin clean-libs clean-obj

backup: #backup whole directory
	rm -f hourios-src-archive.${PKG}
	${ARCHIVE} -cvf hourios-src-archive.${PKG} ./*
bintar: houri iso-grub #creates archive of ISO and kernel binary
	rm -f hourios-bin-archive.${PKG}
	${ARCHIVE} -cvf hourios-bin-archive.${PKG} hourios.iso houri
