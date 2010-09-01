OUTPUT_FORMAT(elf32-i386)
ENTRY(_start)
SECTIONS
{
    .text 0x100000 :
    {
        *(.rodata*)
        *(.rdata*)
        code = .; _code = .;
        *(.text)
        . = ALIGN(4096);
    }

    .data :
    {
        data = .; _data = .;
        *(.data)
        *(.rodata)
        . = ALIGN(4096);
    }

    .bss :
    {
        bss = .; _bss = .;
        *(.bss)
        . = ALIGN(4096);
    }

    end = .; _end = .;
}
