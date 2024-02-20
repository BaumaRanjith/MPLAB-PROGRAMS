#include<pic.h>   // header 
#define _XTAL_FREQ 20000000   // defining clock frequency
__CONFIG(0X3D72);  // operates in normal mode
void delay();   // function definition
void main()   // main function
{
  TRISB=0X00;     
  TRISC=0X00; 
  PORTB=0X00;
  PORTC=0X10;     // switch port ON (RC4 = 1)
  if(RC4==0)    // switch port OFF
  {
    while(1)
    {
      RB4=1;    // led ON
      delay();
      RB4=0;    // led OFF
      delay();
    }
  }
}
void delay()  // delay for 0.5sec
{
  for(int i=0;i<50;i++) 
    __delay_ms(10); 
}