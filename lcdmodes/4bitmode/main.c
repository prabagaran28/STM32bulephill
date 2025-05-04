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
   GPIOA->crl |=0x11110000;
   GPIOA->crh &=0x00000000;
   GPIOA->crh |= 0x00000111;
    lcd_init4bitmode();
set_cursor4bitmode(0,2);
 send_string4bitmode("WELCOME TO ");
 set_cursor4bitmode(1,3);
 send_string4bitmode("INDIA");
while(1)
{

}
    
}
