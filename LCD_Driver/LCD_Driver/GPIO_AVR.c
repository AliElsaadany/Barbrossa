/*
 * GPIO_AVR.c
 *
 * Created: 10/1/2019 6:14:50 PM
 *  Author: Ali Elsaadany
 */ 
#include "GPIO_AVR.h"

void Port_Direction ( char base , char state )
{
	if (state==output)
	(*(volatile unsigned char*)(base+1))=0xff; // DDRA = 0XFF
	else
	(*(volatile unsigned char*)(base+1))=0x00;
}

void Pin_Direction(char base , char pin , char state)
{
	if (state==output)
	(*(volatile unsigned char*)(base+1))|=(1<<pin);
	else
	(*(volatile unsigned char*)(base+1))&=~(1<<pin);
}

void Pin_Reset (char base , char pin )
{
	(*(volatile unsigned char*)(base+2))&=~(1<<pin);
}

void Pin_Set (char base , char pin )
{
	(*(volatile unsigned char*)(base+2))|=(1<<pin);
}

void Pin_Toggle (char base , char pin )
{
	(*(volatile unsigned char*)(base+2))^=(1<<pin);
}

void Port_Write (char base, char value )
{
	(*(volatile unsigned char*)(base+2))=value;
}

char Port_Read (char base )
{
	volatile unsigned char result;
	result= (*(volatile unsigned char*)(base));
	return result;
}


void Pin_Write(char base, char pin, char value)
{
	if (value==0)
	(*(volatile unsigned char*)(base+2))|=1<<pin ;
	else
	(*(volatile unsigned char*)(base+2)) &=~(1<<pin);
}

char Pin_Read (char base, char pin)
{
	volatile unsigned char result ;
	result= (*(volatile unsigned char*)(base)&&(1<<pin));
	return result;
}
