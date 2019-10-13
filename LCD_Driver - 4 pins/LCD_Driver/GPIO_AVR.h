/*
 * GPIO_AVR.h
 *
 * Created: 10/10/2019 1:57:03 PM
 *  Author: Ali Elsaadany
 */ 


#ifndef GPIO_AVR_H_
#define GPIO_AVR_H_

#include "AVR_PORTS.h"
#include "AVR_INPUT_AND_OUTPUT.h"
#define F_CPU 8000000ul
void Port_Direction(char base, char state);
void Pin_Direction(char base , char pin , char state);
void Pin_Reset (char base , char pin );
void Pin_Set (char base , char pin );
void Pin_Toggle (char base , char pin );
void Port_Write(char base , char value);
char Port_Read (char base );
void Pin_Write(char base, char pin, char value);
char Pin_Read (char base, char pin);




#endif /* GPIO_AVR_H_ */