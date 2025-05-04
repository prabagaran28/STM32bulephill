extern unsigned int __start_bss;
extern unsigned int __end_bss;
extern unsigned int __start_data;
extern unsigned int __end_data;
extern unsigned int __end_text;
extern unsigned int main(void);
extern unsigned int __end_stack;
#define IRQ_TOTAL (49)
typedef void (*ptable)(void);
void  reset_handler(void);
__attribute__((used,section(".int")))
 static const ptable irq[IRQ_TOTAL]={
  (ptable)&__end_stack,
    reset_handler,
    
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
