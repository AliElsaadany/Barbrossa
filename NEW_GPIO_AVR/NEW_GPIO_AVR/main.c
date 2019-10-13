/*
 * NEW_GPIO_AVR.c
 *
 * Created: 10/10/2019 2:06:14 PM
 *  Author: Ali Elsaadany
 */ 


#include <avr/io.h>
#include "GPIO_AVR.h"

int main(void)
{
   	Port_Direction(C,output);
   	Port_Direction(B,input);
   	while(1)
   	{
	   	if(Pin_Read(B,3))
	   	Pin_Reset(C,4);
	   	else
	   	Pin_Set(C,4);


   	}

}