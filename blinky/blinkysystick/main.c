#include"gpio.h"
#include"init.h"
#include "rcc.h"
#include "systick.h"
int main()
{
 init();// external 8mhz to 72mhz 
 systickInit();
periperal_clock_enable(gpiob);
 gpio_config(GPIOB,1,OUTPUT_MAX_50MHX,OUTPUT_PUSH_PULL);


     while(1)

     {  
               gpio_setpin(GPIOB,1);
               delay_milli(1000);
               gpio_resetpin(GPIOB,1);
               delay_milli(1000);
}
}