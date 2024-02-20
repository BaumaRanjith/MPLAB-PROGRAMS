#include<pic.h> 			// header 
__CONFIG(0X3D72);			// operates in normal mode
#define _XTAL_FREQ 20000000 // frequency defined 20MHz 	
void delay();				// function definition
void main(void)					// main function
{
	TRISB=0X00;
	PORTB=0X00;
	while(1)
	{
		RB6=1;
		delay();
		RB6=0;
		delay();	
	}
}
void delay()				// delay function
{
	for(int i=0;i<50;i++)
		__delay_ms(10);	
}
