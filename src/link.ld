ENTRY(_start)
SECTIONS
{
    . = 0x100000;
    .text ALIGN(4096) :
    {
        *(.text)
        *(.gnu.linkonce.t*)
    }
    
    .rodata ALIGN(4096) :
    {
        *(.rodata*)
        *(.gnu.linkonce.r*)
    }

    .data ALIGN(4096) :
    {
      start_ctors = .;
      *(.ctor*)
      end_ctors = .;
      
      start_dtors = .;
      *(.dtor*)
      end_dtors = .;
    
      /*  data = .; _data = .; */
        *(.data)
        *(.gnu.linkonce.d*)
    }

    .bss ALIGN(4096) :
    {
        *(.COMMON*)
       /* bss = .; _bss = .; */
        *(.bss)
        *(.gnu.linkonce.b*)
    }

    end = .; _end = .;
    
    /DISCARD/ :
    {
        *(.comment)
      /**(.eh_frame) /* You should discard this unless you're implementing runtime support for C++ exceptions. */
    }
}
