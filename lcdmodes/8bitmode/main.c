#include "rcc.h"
#include "gpio.h"
#include "init.h"
#include "systick.h"
#include "lcd.h"
int main()
{
    init();
    
 systickInit();

 RCC->apb2enr |= RCC_APREB2ENR_IOPA_EN_MASK ;
 GPIOA->crl &=0x00000000;
   GPIOA->crl |=0x11111111;
   GPIOA->crh &=0x00000000;
   GPIOA->crh |= 0x00000111;
lcd_init();
 
 send_string("WELCOME TO YOU");
 set_cursor(1,3);
 delay_milli(100);
 send_string("YOUTUBE");

while(1)
{

}
    
}
