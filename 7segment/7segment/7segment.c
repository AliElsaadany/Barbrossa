/*
 * _7segment.c
 *
 * Created: 9/30/2019 5:19:32 PM
 *  Author: Ali Elsaadany
 */ 
#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#include <util/delay.h>
#include <avr/io.h>

int main(void)
{
	unsigned char num =0 ;
	DDRC=0XFF;
	
    while(1)
    {
		//num++;
		if(num==10)
		{
			num=0;
		}			
        //TODO:: Please write your application code 
  
	PORTC=num;
	_delay_ms(500);
	num++;
		}	
}