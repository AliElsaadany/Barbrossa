/*
 * dcmotorex3.c
 *
 * Created: 9/28/2019 3:06:02 PM
 *  Author: Ali Elsaadany
 */ 
#ifndef F_CPU
#define F_CPU 16000000UL 
#endif

#include <util/delay.h>
#include <avr/io.h>

int main(void)
{
	DDRC=0XFF;
	
    while(1)
    {
		PORTC=0X01;
		_delay_ms(1000);
		PORTC=0X00;
		_delay_ms(1000);
		PORTC=0X02;
		_delay_ms(1000);
		PORTC=0X00;
		_delay_ms(1000);
		
        //TODO:: Please write your application code 
    }
}