#include"gpio.h"
#include"init.h"
#include "rcc.h"

int main()
{
 init();
periperal_clock_enable(gpioa);
periperal_clock_enable(gpiob);
gpio_config(GPIOA,1,INPIUT_MODE,INPUT_PULL);
 gpio_config(GPIOB,1,OUTPUT_MAX_50MHX,OUTPUT_PUSH_PULL);


     while(1)

     {  if(read_pin(GPIOA,1) ==1)
          {
               gpio_setpin(GPIOB,1);
          }
          else      
          {
               gpio_resetpin(GPIOB,1);
          }
             
     }
}