/*
 * interrupt_ex1.c
 *
 * Created: 9/29/2019 12:17:20 PM
 *  Author: Ali Elsaadany
 */ 
#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#include <avr/interrupt.h>
#include <util/delay.h>
#include <avr/io.h>

#define LEDS PORTC


int main(void)
{
	DDRC = 0XFF;
	DDRD&=1<<2;
	LEDS=0X01;
	GICR=1<<INT0;
	MCUCR=0X00;
	sei();
    while(1)
    {
        if (LEDS == 0X80)
		LEDS =0X01;
		else
		LEDS=LEDS<<1;
		_delay_ms(1000);
    }
}

ISR(INT0_vect)
{
	unsigned char TEMP;
	_delay_ms(500);
	TEMP=LEDS;
	for(int i=0 ; i<5 ; i++ )
	{
		LEDS=0XFF;
		_delay_ms(500);
		LEDS=0X00;
		_delay_ms(500);
	}
	LEDS=TEMP ;
}
