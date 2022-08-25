# houri
A free (libre) and open source OS/kernel for x86 systems.
## Building crosscompilers
HouriOS is a x86 Operating System, thus your x86-64 compiler won't work.
Unless you are running a x86 system, you should follow the instructions at [OSDev Wiki](https://wiki.osdev.org/GCC_Cross-Compiler)
## Build Instruction
Required dependency: gcc and ld for i686-elf, make are required for building the kernel. You might need GRUB if you want to build a bootable ISO.\
HouriOS should work with any virtual machines, however I have only tested it on QEMU.
### Building kernel
```
make hourios
```
### Building ISO with GRUB
```
make grub-iso
```
You can call `make grub-iso` directly to build houriclib, hourios and iso. Sometimes you might need `clean`
