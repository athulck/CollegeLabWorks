
GPPPARAMS = -m32 -fno-use-cxa-atexit -nostdlib -fno-builtin -fno-rtti -fno-exceptions -fno-leading-underscore
ASPARAMS = --32
LDPARAMS = -melf_i386
object_files = loader.o kernel.o

%.o: %.cpp
	g++ $(GPPPARAMS) -o $@ -c $<

%.o: %.s
	as $(ASPARAMS) -o $@ $<

ginger_kernel.bin: linker.ld $(object_files)
	ld $(LDPARAMS) -T $< -o $@ $(object_files)

install: ginger_kernel.bin
	sudo cp $< /boot/ginger_kernel.bin
