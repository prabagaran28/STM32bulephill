#include "rcc.h"
#include "gpio.h"
#include "init.h"
#include "systick.h"
#include "lcd.h"
int main()
{

   //char customChar[8] = { 0x00, 0x04,0x02,0x1F,0x02,0x04,0x00, 0x00};
   //char customChar1[8] = { 0x04,0x04,0x1F,0x04,0x04,0x00,0x00,0x1F };
   //char customChar2[8] = {0x04,0x1B,0x11,0x11,0x11,0x11,0x11,0x1F};
char customChar1[8] = {0x00, 0x00, 0x0A, 0x00, 0x11, 0x0E, 0x00, 0x00};  // smiley
char customChar2[8] = {0x0E, 0x0E, 0x04, 0x0E, 0x15, 0x04, 0x0A, 0x0A};  // Robo
char customChar3[8] = {0x08, 0x0C, 0x0E, 0x0F, 0x0E, 0x0C, 0x08, 0x00};  // arrow
char customChar4[8] = {0x00, 0x04, 0x0E, 0x0E, 0x0E, 0x1F, 0x04, 0x00};  // bell
char customChar5[8] = {0x00, 0x00, 0x0A, 0x15, 0x11, 0x0E, 0x04, 0x00};  // Heart
char customChar6[8] = {0x00, 0x0E, 0x11, 0x11, 0x11, 0x0A, 0x1B, 0x00};  // omega
char customChar7[] = {0x0E, 0x10, 0x17, 0x12, 0x12, 0x12, 0x10, 0x0E};  // CT
char customChar8[] = {0x04, 0x04, 0x1F, 0x04, 0x04, 0x00, 0x1F, 0x00}; 
    init();
    
 systickInit();

 RCC->apb2enr |= RCC_APREB2ENR_IOPA_EN_MASK ;
 GPIOA->crl &=0x00000000;
   GPIOA->crl |=0x11111111;
   GPIOA->crh &=0x00000000;
   GPIOA->crh |= 0x00000111;
lcd_init();
 
 send_string("CUSTOM CHAR !!");
 
send_command(0x40);//starting of cgram
for(int i=0;i<8;i++)
{
   send_data(customChar1[i]);
}
set_cursor(1,0);
send_data(0);
send_command(0x40+8);
for(int i=0;i<8;i++)
{
   send_data(customChar2[i]);
}
set_cursor(1,2);
send_data(1);
send_command(0x40+16);
for(int i=0;i<8;i++)
{
   send_data(customChar3[i]);
}
set_cursor(1,4);
send_data(2);
send_command(0x40+24);
for(int i=0;i<8;i++)
{
   send_data(customChar4[i]);
}
set_cursor(1,6);
send_data(3);
send_command(0x40+32);
for(int i=0;i<8;i++)
{
   send_data(customChar5[i]);
}
set_cursor(1,8);
send_data(4);
send_command(0x40+40);
for(int i=0;i<8;i++)
{
   send_data(customChar6[i]);
}
set_cursor(1,10);
send_data(5);
send_command(0x40+48);
for(int i=0;i<8;i++)
{
   send_data(customChar7[i]);
}
set_cursor(1,12);
send_data(6);

send_command(0x40+56);
for(int i=0;i<8;i++)
{
   send_data(customChar8[i]);
}
set_cursor(1,14);
send_data(7);
 

while(1)
{

}
    
}
