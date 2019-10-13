/*
 * _7segment_3.c
 *
 * Created: 9/30/2019 5:41:41 PM
 *  Author: Ali Elsaadany
 */ 

#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#include <util/delay.h>
#include <avr/io.h>

unsigned short decoder (unsigned short number);

int main(void)
{
	DDRC=0XFF;
	DDRD=0X07;
	PORTC=0X00;
	unsigned char digit1,digit2,digit3;
	unsigned int counter=0;
	unsigned char d=10;
    while(1)
    {
		digit1 = counter%10;
		digit1= decoder(digit1);
		digit2=(counter/10)%10;
		digit2=decoder(digit2);
		digit3=(counter/100)%10;
		digit3=decoder(digit3);
		
		PORTC=digit1;
		PORTD|=(1<<PD0);
		_delay_ms(5);
		PORTD&=~(1<<PD0);
		
		PORTC=digit2;
		PORTD|=(1<<PD1);
		_delay_ms(5);
		PORTD&=~(1<<PD1);
		
		PORTC=digit3;
		PORTD|=(1<<PD2);
		_delay_ms(5);
		PORTD&=~(1<<PD2);
		
		if(d>0)
		{
			d--;
			if (d==0)
			{
				counter++;
				d=10;
				
		
			}
			if(counter>999)
			counter=0;
	
	 	}
		
		
        //TODO:: Please write your application code 
    }
}
unsigned short decoder (unsigned short number)
{
	switch(number)
	{
		case 0: return 0x3F; break;
		case 1: return 0x06; break;
		case 2: return 0x5B; break;
		case 3: return 0x4f; break;
		case 4: return 0x66; break;
		case 5: return 0x6D; break;
		case 6: return 0x7D; break;
		case 7: return 0x07; break;
		case 8: return 0x7F; break;
		case 9: return 0x6F; break;
		

	}
	
}