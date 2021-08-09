#include <pic.h>

 void write_command(unsigned char cmd);
void write_data(unsigned char dat);

void lcd_data(char dat);
void lcd_command(char cmd);
  
void printlcd(const char *CPtr);


void lcd_init(void);
