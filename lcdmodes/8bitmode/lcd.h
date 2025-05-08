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

#endif 