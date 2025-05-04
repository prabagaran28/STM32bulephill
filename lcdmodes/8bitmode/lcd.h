#ifndef LCD_H
#define LCD_H

#define EANBLE_RS 1
#define ENABLE_RW 1 
#define ENABLE_EN  1

void lcd_init(void);

void set_cursor();

void send_data(unsigned char data);

void send_command(unsigned char cmd) ;
void send_string4bitmode(char* ptr);
void send_string(char* ptr);
void set_cursor(unsigned int row ,unsigned int col);
void send_command4bitmode(unsigned char cmd);
void send_data4bitmode(unsigned char data);
void set_cursor4bitmode(unsigned int row ,unsigned int col);
void lcd_init4bitmode(void);
#endif