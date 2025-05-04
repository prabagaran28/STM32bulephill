MEMORY
{
    flash(xr) : ORIGIN = 0x08000000, LENGTH = 32k
    ram(xrw)  : ORIGIN = 0x20000000, LENGTH = 10k
}

__estack = ORIGIN(ram) + LENGTH(ram);
SECTIONS
{
    .text :
    {
         KEEP(*(.ivt))
        *(.text)
        __etext = . ;
    }>flash
  .data :
  {
     __sdata = . ;
       *(.data)
       __edata = .;
  }>ram AT >flash
    .bss :
    {
        __sbss = . ;
        *(.bss)
        __ebss = . ;
    }>ram

}