#ifndef LCD_H
#define LCD_H

#define HIGH 1 
#define LOW  0
void lcd_init(void);

void send_data(unsigned char data);
void send_cmd(unsigned char cmd);
void set_cursor(unsigned int row ,unsigned int col);
void lcd_rs(unsigned char low_high);
void lcd_rw(unsigned char low_high);
void lcd_e(unsigned char low_high);
void send_str(unsigned char *ptr);
void lcdcommand4bit(unsigned char data); 
void lcddata4bit(unsigned char data);
void send4bitstr(unsigned char *p); 
void setcursor4bit(unsigned short int row, unsigned short int col );
void lcdint4bit(void);
#endif 