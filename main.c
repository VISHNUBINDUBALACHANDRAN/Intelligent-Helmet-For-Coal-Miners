#include<pic.h>
#include"delay.h"
#include"lcd4bit.h"




#define HEAT    0
#define HUMID   1
#define LIGHT   2
#define GAS   3

#define BUZZ RC0

char disp_buf[10];
int heat = 0;
int light = 0;
int sound = 0;
int humid = 0;
int  gas = 0;


unsigned int read_adc(char chn){
unsigned int val;
char chm;
	ADCON0 = 0x81 | (chn << 3);              
	for(chm=0;chm<100;chm++);
	ADGO = 1;			
	while(ADGO==1);
	val = ADRESH;
	val = val << 8;		
	val = val | ADRESL;
	return val;
	}

void dtoa(char *ptr,unsigned int val,char digits){
ptr[digits] = 0;
	while(digits-- > 0){
		ptr[digits] = val%10 + '0';
		val /= 10;
		}
	}





int main(void){

ADCON1 = 0x80;
RBPU = 1;
TRISA0 = 1;
TRISA1 = 1;
TRISA2 = 1;
TRISA3 = 1;
TRISB = 0x01;
TRISD = 0x00;

lcd_init();

printlcd("     HELMET    ");
lcd_command(0XC0);
printlcd("              ");
DelayS(2);

lcd_command(0X80);
printlcd("HEAT:   C HUM:  ");
lcd_command(0XC0);
printlcd("LIGHT:  %  G:  %");


while(1){
	lcd_command(0X80);
	heat = read_adc(HEAT)*0.48;
	dtoa(disp_buf,heat,2);
	printlcd("HEAT:");
	printlcd(disp_buf);
	lcd_data(0xD8);
	printlcd("C HUM:");
	humid = read_adc(HUMID)/11;
	dtoa(disp_buf,humid,2);
	printlcd(disp_buf);


	lcd_command(0XC0);	
	light = read_adc(LIGHT)/11;
	dtoa(disp_buf,light,2);
	printlcd("LIGHT:");
	printlcd(disp_buf);
	printlcd("%  G:");

	gas = read_adc(GAS);
	dtoa(disp_buf,gas,2);
	printlcd(disp_buf);
	printlcd("%");


if(gas > 200 || heat > 40 || humid > 60){
	BUZZ = 1;
	}
else{
	BUZZ = 0;
	}
	}
}
