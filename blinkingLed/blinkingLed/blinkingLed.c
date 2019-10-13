/*
 * blinkingLed.c
 *
 * Created: 9/27/2019 1:17:07 PM
 *  Author: Ali Elsaadany
 this is the first example of the online course " VLSI "
 make port c blink LEDs 
 */ 
#ifndef F_CPU

#define F_CPU 16000000UL // define the frequency of the CPU by 16MHz to match the delay with the real time - I think UL means unsigned long !

#endif

#include <util/delay.h>
#include <avr/io.h>

int main(void)
{
	DDRC=0XFF; // make port c output 
    while(1)
    {
		PORTC=0XFF; // out 5 volt to all pins in the port c 
		_delay_ms(1000); // wait for 1 second 
		PORTC=0X00;// out 0 vlot to all pins in the port c
		_delay_ms(1000);// wait for 1 second 
        
    }
}