#include "systick.h" 
void systickInit()
{
    SYSTICK->ctrl = 0 ;
    SYSTICK->load = 0x00ffffff;
    SYSTICK->val = 0;
    SYSTICK->ctrl =SYTICK_ENABLE;
}
//8421
//0111
void delay_ms()
{
        SYSTICK->load=72000-1;
        SYSTICK->val=0;
        while((SYSTICK->ctrl & 0x00010000)==0);
    
}
void delay_milli(unsigned int l)
{
    for(; l>0;l--)
    {
        delay_ms();
    }
}


void Delayus()
{
    SYSTICK->load = 72;
    SYSTICK->val = 0;
    while((SYSTICK->ctrl & 0x00010000)==0);
}
void delay_micro(unsigned int t)
{

for(;t>0;t--)
{
    Delayus();
}

}

