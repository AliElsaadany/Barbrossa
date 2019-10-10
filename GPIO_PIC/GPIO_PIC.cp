#line 1 "E:/embedded diploma kirlus/study/mazidi_examples/VLSI_EX/GPIO_PIC.c"









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
 Port_Direction( 0x07 , 0 );
 Port_Direction( 0x06 , 1 );
 while(1)
 {
 if(Pin_Read( 0x06 ,3))
 Pin_Reset( 0x07 ,4);
 else
 Pin_Set( 0x07 ,4);


 }

}


void Port_Direction(char base, char state)
{
 if(state== 0 )
 (*(volatile unsigned char*)(base|0x80))=0x00;
 else
 (*(volatile unsigned char*)(base|0x80))=0xff;
}

void Pin_Direction(char base , char pin , char state)
{
 if (state== 0 )
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
