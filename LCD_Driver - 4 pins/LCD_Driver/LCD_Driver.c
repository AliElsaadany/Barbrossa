/*
 * LCD_Driver.c
 *
 * Created: 10/11/2019 6:27:03 PM
 *  Author: Ali Elsaadany
 */ 




#include <avr/io.h>
#include "GPIO_AVR.h"
#include "LCD_Driver.h"
#include <util/delay.h>

void LCD_Init();
void LCD_Data(unsigned char letter);
void LCD_Command (unsigned char cmd);
void LCD_String(char* str);

int main(void)
{
	LCD_Init();
	LCD_String("jana");
    
}

void LCD_Init()
{
	Port_Direction(data,output);
	Port_Direction(command,output);
	Port_Write(data,0x00);
	Pin_Reset(command,EN);
	
	if (mode == 8)
	{
		LCD_Command(0X38);
		
		
	}		
	else if (mode==4)
	{
		LCD_Command(0X33);
		LCD_Command(0X32);
		LCD_Command(0X28);

	}
	
	LCD_Command(0X0E);
	LCD_Command(0X01);
	_delay_ms(2000);
	LCD_Command(0X06);
	
	
}	

void LCD_Data(unsigned char out)
{
	Pin_Set(command,RS);
	_delay_ms(1);
	if(mode==8)
	{
		Port_Write(data,out);
		_delay_ms(1);

	}
	else if (mode==4)
	{
		Port_Write(data,(out&0XF0));
		Pin_Set(command,RS);
		Pin_Set(command,EN);
		_delay_ms(1);
		Pin_Reset(command,EN);
		_delay_ms(100);
		Port_Write(data,(out<<4));
	}
	
	Pin_Set(command,EN);
	_delay_ms(1);
	Pin_Reset(command,EN);
	_delay_ms(100);
	
	
}

void LCD_Command (unsigned char cmd)
{
	
	
	if (mode == 8)
	{
		
		Port_Write(data,cmd);
		_delay_ms(1);
		

	}
	else if (mode==4)
	{
		Port_Write(data,(cmd&0XF0));
		Pin_Reset(command,RS);
		Pin_Reset(command,EN);
		_delay_ms(1);
		Pin_Set(command,EN);
		_delay_ms(100);
		Port_Write(data,(cmd<<4));

	}
	Pin_Reset(command,RS);
	Pin_Set(command,EN);
	_delay_ms(1);
	Pin_Reset(command,EN);
	_delay_ms(100); 
}

void LCD_String(char* str)
{
	unsigned char i=0;
	while(str[i]!=0)
	{
		LCD_Data(str[i]);
		i++;
	}
}