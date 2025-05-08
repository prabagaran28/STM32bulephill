#include"gpio.h"
#include"rcc.h"
#include"init.h"
#include"lcd.h"
#include"systick.h"
int main()
{
init();
systickInit(0);
    periperal_clock_enable(gpioa);
    gpio_config(GPIOA,0,OUTPUT_MAX_10HMZ,OUTPUT_PUSH_PULL);
    gpio_config(GPIOA,1,OUTPUT_MAX_10HMZ,OUTPUT_PUSH_PULL);
    gpio_config(GPIOA,2,OUTPUT_MAX_10HMZ,OUTPUT_PUSH_PULL);
    gpio_config(GPIOA,3,OUTPUT_MAX_10HMZ,OUTPUT_PUSH_PULL);
    gpio_config(GPIOA,4,OUTPUT_MAX_10HMZ,OUTPUT_PUSH_PULL);
    gpio_config(GPIOA,5,OUTPUT_MAX_10HMZ,OUTPUT_PUSH_PULL);
    gpio_config(GPIOA,6,OUTPUT_MAX_10HMZ,OUTPUT_PUSH_PULL);
    gpio_config(GPIOA,7,OUTPUT_MAX_10HMZ,OUTPUT_PUSH_PULL);
    gpio_config(GPIOA,8,OUTPUT_MAX_10HMZ,OUTPUT_PUSH_PULL);
    gpio_config(GPIOA,9,OUTPUT_MAX_10HMZ,OUTPUT_PUSH_PULL);
    gpio_config(GPIOA,10,OUTPUT_MAX_10HMZ,OUTPUT_PUSH_PULL);
    lcd_init();
    set_cursor(0,0);
    send_str("WELCOME TO YOU");
    set_cursor(1,0);
    send_str("YOUTUBE");
    while(1)
    {

    }
}