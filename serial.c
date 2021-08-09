#include <pic.h>                     /* LPC21xx definitions               */
#include "serial.h"



void init_serial (void)  {		         /* Initialize Serial Interface       */
  TRISC6 = 0;     					   /* Enable RxD0 and TxD0              */
  TRISC7 = 1;  
  TXEN   = 1;	                         /*8 bits, no Parity, 1 Stop bit      */
  CREN 	 = 1;	
  SPEN   = 1;
  SYNC = 0;							 /* 9600bps baud rate */
  RCIF   = 0;
  RCIE   = 1;					         /* DLAB = 0                          */
  BRGH   = 1;
  SPBRG = 129;	
  }



void sendchar (char SDat)  {                 /* Write character to Serial Port    */
TXREG = SDat; 
 while (!TRMT);
  }


int getchar (void)  {                    /* Read character from Serial Port   */
   	RCIF = 0;
  while (!RCIF);

	return (RCREG);
	
  }

void prints(const char *ptr){
 while(*ptr){
 sendchar (*ptr);
ptr++;
}
 }



