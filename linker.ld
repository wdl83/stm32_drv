MEMORY
{
    FLASH (rx)  : ORIGIN = 0x08000000, LENGTH = 64K
    SRAM  (rwx) : ORIGIN = 0x20000000, LENGTH = 20K
}

SECTIONS
{
    .text :
    {
        PROVIDE(_text_begin = .);
        KEEP(*(.isr_vector_table))
        *(.text*)
        *(.rodata)
        . = ALIGN(4);
        PROVIDE(_text_end = .);
    } > FLASH
    .data :
    {
        PROVIDE(_data_begin = .);
        *(.data*)
        . = ALIGN(4);
        PROVIDE(_data_end = .);
    } > SRAM AT > FLASH
    .bss :
    {
        PROVIDE(_bss_begin = .);
        *(.bss*)
        . = ALIGN(4);
        PROVIDE(_bss_end = . + SIZEOF(.bss));
    } > SRAM
}

PROVIDE(_text_size = SIZEOF(.text));
PROVIDE(_data_size = SIZEOF(.data));
PROVIDE(_bss_size = SIZEOF(.bss));
PROVIDE(_stack_end = 0x20005000);
