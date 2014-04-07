robix
=====

A Operation System written in C++11. In order to compile it, a cross platform elf64 compiler is needed.

The build process:

 - Create a build folder somewhere
 - link kernel/makefile into this folder
 - create a folder 'iso' in the build folder
 - create a folder 'boot' in the iso folder
 - run 'make' in the build folder

The command 'make run' runs the kernel on qemu.

You need to have grub-mkreskue and qemu installed to use the given makefile. Another option is to edit the
makefile to use your prefered emulator.

Features:

 - boots
