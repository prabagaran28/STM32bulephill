#include"gpio.h"
#include"rcc.h"
#include"init.h"
void delay(void);
int main()
{
     init();
     periperal_clock_enable(gpiob);

gpio_config(GPIOB,1,OUTPUT_MAX_50MHX,OUTPUT_PUSH_PULL);

     while(1)
     {
          gpio_setpin(GPIOB,1);
          delay();
          gpio_resetpin(GPIOB,1);
          delay();
     }

}
void delay()
{
     for(int i=0;i<500000;i++)
     {
          __asm("nop");
     }
}