extern unsigned int __start_bss;
extern unsigned int __end_bss;
extern unsigned int __start_data;
extern unsigned int __end_data;
extern unsigned int __end_text;
extern unsigned int main(void);
extern unsigned int __end_stack;
#define IRQ_TOTAL (49)
void default_handler(void);
__attribute__((weak,alias("default_handler"))) void systick_handler(void);
typedef void (*ptable)(void);
void  reset_handler(void);
__attribute__((used,section(".int")))
 static const ptable irq[IRQ_TOTAL]={
  (ptable)&__end_stack,
    reset_handler,
    0,                              /* 0x08 NMI           */
	0,                              /* 0x0C HardFaullt    */
	0,                              /* 0x10 MemManage     */
	0,                              /* 0x14 BusFault      */
	0,                              /* 0x18 UsageFault    */
	0,                              /* 0x1C Reserved      */
	0,                              /* 0x20 Reserved      */
	0,                              /* 0x24 Reserved      */
	0,                              /* 0x28 Reserved      */
	0,                              /* 0x2C SVCall        */
	0,                              /* 0x30 Debug Monitor */
	0,                              /* 0x34 Reserved      */
	0,                              /* 0x38 PendSV        */
	 systick_handler, 
 };


 void reset_handler()
 {
    unsigned int *Dptr = &__start_data;
    unsigned int*Sptr = &__end_text;
    for(;Dptr<&__end_data;)
    {
             *Dptr++ = *Sptr++; 
    }
     Dptr = &__start_bss;
    for(;Dptr<&__end_bss;)
    {
             *Dptr++ =0;
    }
    main();

 }
void default_handler()
{
   while(1)
   {

   }
}