#include <pic.h>
#include "delay.h"


 void write_command(unsigned char cmd) {
  PORTB = 0x00;
  RB1 = 0;
  RB2 = 0;
  PORTB   |= (cmd & 0xf0);
  RB3 = 1;
  RB3 = 0;
  DelayMs(1);

  }
 
void write_data(unsigned char dat) {
  PORTB = 0x00;
  RB1 = 1;
  RB2 = 0;
  PORTB  |= (dat & 0xf0);
  RB3 = 1;
  RB3 = 0;
  DelayMs(1);

  }

void lcd_data(char dat){
  write_data(dat);
  write_data((dat << 4));
  }

void lcd_command(char cmd){
  write_command(cmd);
  write_command((cmd << 4));
  }
  
void printlcd(const char *CPtr){
  while(*CPtr != '\0') {
    lcd_data(*CPtr);
    CPtr++;
    }
  }

void lcd_init(void) {                                          
 
  DelayMs(15);
  write_command(0x30); 
  DelayMs(5);
  write_command(0x30);
  DelayMs(2);
  write_command(0x30);
  DelayMs(1);
  write_command(0x20);

  lcd_command(0x01);                             /* clear display */
  lcd_command(0x06);                             /* auto address inc */
  lcd_command(0x0c);                             /* cursor off */
  lcd_command(0x80);                             /* first location */   
  
  }




