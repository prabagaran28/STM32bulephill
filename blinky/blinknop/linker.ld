
MEMORY 
{
    flash(rx): ORIGIN = 0x08000000, LENGTH = 32k
    ram(rwx): ORIGIN = 0x20000000, LENGTH =  10k
}

__end_stack = ORIGIN(ram) + LENGTH(ram);

SECTIONS 
{
    .text :
    {
        boot.o(.int) 
        *(.text)
         . = ALIGN(4);
         __end_text = ABSOLUTE(.);
    }>flash 

    .data :
    {
        . = ALIGN(4);
        __start_data = ABSOLUTE(.);
        *(.data)
        . = ALIGN(4);
        __end_data = ABSOLUTE(.);

    }>ram AT>flash 

    .bss :
    {     . = ALIGN(4);
        __start_bss = ABSOLUTE(.);
        *(.bss)
        . = ALIGN(4);
        __end_bss = ABSOLUTE(.);

    }>ram
}