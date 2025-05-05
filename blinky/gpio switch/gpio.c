#include "gpio.h"

void gpio_config(gpio_t* port, int num,mode Mode,gpio_mode output)
{
    int number = num;
   
    if(number <8)
    {
   port->crl &= ~(0xf<< num*4);
	 port->crl |= ((Mode << num*4) | (output << (num*4 + 2)));
   
		}
    else{
			num -= 8;
   port->crh &= ~(0xf<< num*4);
	 port->crh |= ((Mode << num*4) | (output << (num*4 +2)));
       
         
    }  
} 

void write_pin(gpio_t* gpiox ,unsigned short int gpio_pin,gpio_state pinstate)
{
     if(pinstate == RESET)
     {
          gpiox->odr &= ~(1 << gpio_pin);
     }
     else
     {
          gpiox->odr |= (1 <<gpio_pin);
     }
}
void gpio_setpin(gpio_t* port,unsigned short int pin)
{
     port->bsrr |= (1 << pin);
}
void gpio_resetpin(gpio_t * port,unsigned short int pin)
{ 
   port->bsrr |= (1 << (pin+ 16));
}
int read_pin(gpio_t * port,unsigned short int pin)
{
    // port->odr =0;
      return ((port->idr >> pin)& 1);
}