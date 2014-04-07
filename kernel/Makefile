ISO := os.iso
OUTPUT := kernel.sys
KERNEL_ROOT := /home/robin/os/robix/kernel
KERNEL_BOOT := $(KERNEL_ROOT)/boot

OBJS := boot.o main.o ostream.o

COMPILER := /home/robin/os/x86_64-elf-4.8.1/bin/x86_64-elf-g++
LINKER := /home/robin/os/x86_64-elf-4.8.1/bin/x86_64-elf-ld

FLAGS := -ffreestanding -mcmodel=large -mno-red-zone -mno-mmx -mno-sse -mno-sse2 -mno-sse3 -mno-3dnow
EXTRAFLAGS := -O2 -Wall -Wextra -fno-exceptions -fno-rtti -nostdlib -lgcc -std=c++11

.SUFFIX = .asm

all:	$(ISO)

$(ISO):	$(OUTPUT)
	cp $(KERNEL_ROOT)/grub iso/boot -R
	cp $(OUTPUT) iso/boot
	grub-mkrescue -o $@ iso
	cp $@ iso

$(OUTPUT): $(OBJS) $(KERNEL_BOOT)/linker.ld
	$(COMPILER) $(FLAGS) $(EXTRAFLAGS) -z max-page-size=0x1000 -T$(KERNEL_BOOT)/linker.ld -o $@ $(OBJS)

boot.o: $(KERNEL_BOOT)/boot.asm
	nasm -felf64 $(KERNEL_BOOT)/boot.asm -o boot.o

main.o: $(KERNEL_ROOT)/main.cpp
	$(COMPILER) $(FLAGS) $(EXTRAFLAGS) -c $(KERNEL_ROOT)/main.cpp -o main.o

ostream.o: $(KERNEL_ROOT)/util/ostream.cpp
	$(COMPILER) $(FLAGS) $(EXTRAFLAGS) -c $(KERNEL_ROOT)/util/ostream.cpp -o ostream.o

clean:
	@rm -f $(OBJS) $(OUTPUT)

run:
	qemu-system-x86_64 -cdrom iso/os.iso
