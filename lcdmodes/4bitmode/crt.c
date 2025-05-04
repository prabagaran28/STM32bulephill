extern int main(void);
extern unsigned int __estack;
extern unsigned int __sdata;
extern unsigned int __edata;
extern unsigned int __etext;
extern unsigned int __sbss;
extern unsigned int __ebss;
void Reset_Handler(void);
void nmi_Handler(void);
void Hard_Handler(void);
void copy_to_data(void);
void fill_bss(void);
#define TOTAL_VECTOR (59U)
typedef void (*fptr_t)(void);
#define WEEK __attribute__((weak,alias("default_handler")))

WEEK void memmange_handler(void);
WEEK void busfault_handler(void);
WEEK void usagefault_handler(void);
WEEK void svcall_handler(void);
WEEK void debugmonitor_handler(void);
WEEK void pendsv_handler(void);
WEEK void systick_handler(void);
__attribute((used,section(".ivt")))
fptr_t tables[TOTAL_VECTOR]= {
    (fptr_t)&__estack,
    Reset_Handler,
    nmi_Handler,
    Hard_Handler,
    memmange_handler,
    busfault_handler,
    usagefault_handler,
    0,
    0,
    0,
    0,
    svcall_handler,
    debugmonitor_handler,
    0,
    pendsv_handler,
    systick_handler
};

void Reset_Handler()
{
    copy_to_data();
    fill_bss();
     main();
}
void nmi_Handler()
{
    while(1);
}
void Hard_Handler()
{
    while(1);
}

void fill_bss()
{ unsigned int *ptr_bss = &__sbss;
    while(ptr_bss < &__ebss)
    {
           *ptr_bss++ = 0;
    }
}
void copy_to_data()
{
    unsigned int *src_ptr = &__etext;
    unsigned int *dsc_ptr = &__sdata;
    while( dsc_ptr< &__edata)
    {
        *dsc_ptr++ = *src_ptr++ ;
    }
}
void default_handler(void)
{
 while(1);
}