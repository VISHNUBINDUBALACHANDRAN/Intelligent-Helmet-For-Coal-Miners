/*
 *	Delay functions
 *	See delay.h for details
 *
 *	Make sure this code is compiled with full optimization!!!
 */

#include	"delay.h"

#include	"pic.h"

void DelayMs(unsigned char cnt){
	while(cnt-- > 0){
		DelayUs(250);
		DelayUs(250);
		DelayUs(250);
		DelayUs(250);
	}
}

void DelayS(unsigned char cnt){
	while(cnt-- > 0){
		DelayMs(250);
		DelayMs(250);
		DelayMs(250);
		DelayMs(250);
	}
}
