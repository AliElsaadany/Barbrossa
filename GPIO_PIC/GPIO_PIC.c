#define output 0
#define input 1

#define A 0x05 // the base address for port A  -- PORTA|0X80= TRISA --
#define B 0x06
#define C 0x07
#define D 0x08
#define E 0x09

void Port_Direction(char base, char state);
void Pin_Direction(char base , char pin , char state);
void Pin_Reset (char base , char pin );
void Pin_Set (char base , char pin );
void Pin_Toggle (char base , char pin );
void Port_Write(char base , char value);
char Port_Read (char base );
void Pin_Write(char base, char pin, char value);
char Pin_Read (char base, char pin);





void main()
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


void Port_Direction(char base, char state)
{
 if(state==output)
   (*(volatile unsigned char*)(base|0x80))=0x00;// TRISA=0X00
 else
   (*(volatile unsigned char*)(base|0x80))=0xff;
}

void Pin_Direction(char base , char pin , char state)
{
 if (state==output)
   (*(volatile unsigned char*)(base|0x80))&=~(1<<pin);
 else
   (*(volatile unsigned char*)(base|0x80))|=(1<<pin);
}

void Pin_Reset (char base , char pin )
{
 (*(volatile unsigned char*)(base))&=~(1<<pin);
}

void Pin_Set (char base , char pin )
{
 (*(volatile unsigned char*)(base))|=(1<<pin);
}

void Pin_Toggle (char base , char pin )
{
 (*(volatile unsigned char*)(base))^=(1<<pin);
}

void Port_Write(char base , char value)
{
(*(volatile unsigned char*)(base))=value;

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
   (*(volatile unsigned char*)(base))|=1<<pin ;
 else
   (*(volatile unsigned char*)(base)) &=~(1<<pin);
}

char Pin_Read (char base, char pin)
{
 volatile unsigned char result ;
 result= (*(volatile unsigned char*)(base)&(1<<pin));
 return result;
}