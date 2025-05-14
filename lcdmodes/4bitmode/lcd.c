#include"lcd.h"
#include"systick.h" 
#include"gpio.h"
void lcd_rs(unsigned char low_high)
{
    write_pin(GPIOA,8,low_high);    
}   
void lcd_rw(unsigned char low_high)
{
   write_pin(GPIOA,9,low_high);
}
void lcd_e(unsigned char low_high)
{
    write_pin(GPIOA,10,low_high);
}
void lcd_init()
{


	delay_milli(20);
	send_cmd(0x3C); // 8 bit communication mode / 2 lines
	delay_milli(5);
	send_cmd(0x0F); // Display ON
	delay_milli(5);
	send_cmd(0x01); // Clear Display
	delay_milli(5);
	send_cmd(0x02); // Get back to initial address
	delay_milli(5);

}

void send_data(unsigned  char data)
{


	lcd_rs(HIGH);
	lcd_rw(LOW);
	delay_micro(10);
	lcd_e(HIGH);
	delay_micro(5);
	GPIOA->odr &= 0xff00;
	GPIOA->odr |= data;
	delay_micro(10);
	lcd_e(LOW);    

 }

void send_cmd(unsigned char cmd)
{
    
	
	lcd_rs(LOW);
	lcd_rw(LOW);
	delay_micro(10);
	lcd_e(HIGH);
	delay_micro(5);
	GPIOA->odr &= 0xff00;
	GPIOA->odr |= cmd;
	delay_micro(10);
	lcd_e(LOW);

}

void set_cursor(unsigned int row ,unsigned int col)
{
    if(row==0)
    {
        send_cmd(0x80+col);
    }
    if(row==1)
    {
        send_cmd(0xc0+col);
    }

}

void send_str(unsigned char* ptr)
{
        while(*ptr)
		{
			send_data(*ptr);
			ptr++;
			delay_micro(100);
		}
		
}


void lcdcommand4bit(unsigned char data)
{
	
	lcd_rs(LOW);
	lcd_rw(LOW);
	delay_micro(10);
	lcd_e(HIGH);
	delay_micro(5);
	GPIOA->odr &= 0xff0f;
	GPIOA->odr |= (data & 0x00f0);
	delay_micro(10);
	lcd_e(LOW);
	
	delay_micro(20);
	
	lcd_e(HIGH);
	delay_micro(5);
	GPIOA->odr &= 0xff0f;
	GPIOA->odr |= ((data << 4) & 0x00f0);
	delay_micro(10);
	lcd_e(LOW);
}

void lcddata4bit(unsigned char data)
{

	lcd_rs(HIGH);
	lcd_rw(LOW);
	delay_micro(10);
	lcd_e(HIGH);
	delay_micro(5);
	GPIOA->odr &= 0xff0f;
	GPIOA->odr |= (data & 0x00f0);
	delay_micro(10);
	lcd_e(LOW);
	
	delay_micro(20);
	
	lcd_e(HIGH);
	delay_micro(5);
	GPIOA->odr &= 0xff0f;
	GPIOA->odr |= ((data << 4) & 0x00f0);
	delay_micro(10);
	lcd_e(LOW);
}

void send4bitstr(unsigned char *p)
{
      while(*p)
	  {
		lcddata4bit(*p);
		p++;
		delay_micro(100);
	  }
}

void setcursor4bit(unsigned short int row, unsigned short int col )
{
	if(row==0)
    {
        lcdcommand4bit(0x80+col);
    }
    if(row==1)
    {
        lcdcommand4bit(0xc0+col);
    }

}

void lcdint4bit()
{
	
	
	delay_milli(20);
	lcd_rs(LOW);
	lcd_rw(LOW);
	delay_micro(10);
	lcd_e(HIGH);
	delay_micro(5);
	GPIOA->odr &= 0xff0f;
	GPIOA->odr |= 0x30; // 8 bit communication mode 
	delay_micro(10);
	lcd_e(LOW);
	
	delay_milli(10);
	
	lcd_rs(LOW);
	lcd_rw(LOW);
	delay_micro(10);
	lcd_e(HIGH);
	delay_micro(5);
	GPIOA->odr &= 0xff0f;
	GPIOA->odr |= 0x30; // 8 bit communication mode 
	delay_micro(10);
	lcd_e(LOW);
	
	delay_milli(1);
	
	lcd_rs(LOW);
	lcd_rw(LOW);
	delay_micro(10);
	lcd_e(HIGH);
	delay_micro(5);
	GPIOA->odr &= 0xff0f;
	GPIOA->odr |= 0x30; // 8 bit communication mode 
	delay_micro(10);
	lcd_e(LOW);
	
	delay_milli(1);
	
	lcd_rs(LOW);
	lcd_rw(LOW);
	delay_micro(10);
	lcd_e(HIGH);
	delay_micro(5);
	GPIOA->odr &= 0xff0f;
	GPIOA->odr |= 0x20; // 4 bit communication mode 
	delay_micro(10);
	lcd_e(LOW);
	
	
	lcdcommand4bit(0x2C); // 4 bit communication mode / 2 lines
	delay_milli(5);
	lcdcommand4bit(0x0C); // Display ON
	delay_milli(5);
	lcdcommand4bit(0x01); // Clear Display
	delay_milli(5);
	lcdcommand4bit(0x02); // Get back to initial address
	delay_milli(5);
}
	
