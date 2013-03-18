# Lua OS

A mix of OSKit and Lua.

## Requirements
   
* gcc 4.5+
* scons
* qemu

    # for ubuntu
    $ sudo apt-get install scons
    
## Setup

    $ git clone http://github.com/mischief/los
    $ cd los

Run scons

    $ scons
    scons: Reading SConscript files ...
    scons: done reading SConscript files.
    scons: Building targets ...
    scons: building associated VariantDir targets: .build
    as       .build/src/crt/x86/multiboot.o
    src/crt/x86/multiboot.S: Assembler messages:
    src/crt/x86/multiboot.S:33: Error: invalid instruction suffix for `push'
    src/crt/x86/multiboot.S:36: Error: operand type mismatch for `push'
    src/crt/x86/multiboot.S:37: Error: operand type mismatch for `push'
    scons: *** [.build/src/crt/x86/multiboot.o] Error 1
    scons: building terminated because of errors.

Ack! Cross compiling failed. Update build parameters

    $ emacs -nw scache.conf # or vim or whatever editor of your choice

    # FROM:
    AR = 'ar'
    RANLIB = 'ranlib'
    CC = 'gcc' # <--
    CXX = 'g++'
    AS = 'as' # <--
    LINK = '$SMARTLINK' # <--
    CFLAGS = ' -Wall -nostdinc -ffreestanding -std=gnu99 -pipe'
    CXXFLAGS = ' -Wall  -nostdlib -fno-builtin -nostartfiles -nodefaultlibs -fno-exceptions -fno-rtti -fno-stack-protector'
    ASFLAGS = ' -Wall -nostdlib -ffreestanding'

    # TO:
    AR = 'ar'
    RANLIB = 'ranlib'
    CC = 'gcc -m32' # <--
    CXX = 'g++'
    AS = 'as --32' # <--
    LINK = 'ld -m elf_i386' # <--
    CFLAGS = ' -Wall -nostdinc -ffreestanding -std=gnu99 -pipe'
    CXXFLAGS = ' -Wall  -nostdlib -fno-builtin -nostartfiles -nodefaultlibs -fno-exceptions -fno-rtti -fno-stack-protector'
    ASFLAGS = ' -Wall -nostdlib -ffreestanding'
    verbose = True
    
Try again

    # Tips:
    # If you get an error, you can do: scons -c to clean
    # To run a parallel build: scons -j _ (where _ is # of cores, e.g. 1, 2, 4)

    $ scons
    scons: Reading SConscript files ...
    scons: done reading SConscript files.
    scons: Building targets ...
    scons: building associated VariantDir targets: .build
    Copy("kernel", ".build/kernels/hello")
    scons: done building targets.

Mount the disk image to the floppy disk -- Check this file first
before proceeding! Also, if anyone knows how to a modify floppy disks
in userspace without calling mount (which requires root)

    $ ./scripts/update_linux.sh
    Mounting floppy...
    [sudo] password for mek: 
    Copying kernels...
    Unmounting floppy...

Run qemu to emulate and run the image

    qemu-system-i386 -fda ./los.img


If, after GRUB, you see a stream of non-stop text, you've encountered an error. This happens if debug settings not included with scons (if optimization level of gcc is set to anything > 0)

    $ scons debug=true optimization=0 # verbose=False (optional)
    $ ./scripts/update_linux.sh
    $ qemu-system-i386 -fda ./los.img

Prefer interacting with los from your custom terminal instead of through qemu?

    qemu-system-i386 -serial stdio -fda ./los.img
