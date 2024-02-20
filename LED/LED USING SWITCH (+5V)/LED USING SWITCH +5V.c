#include<pic.h>
#define _XTAL_FREQ 20000000
__CONFIG(0X3D72);
void delay();
void main()
{
  TRISB=0X00;
  TRISC=0X00;
  PORTB=0X00;
  PORTC=0X00;
  if(RC4==1)		
  {
    while(1)
    {
      RB4=1;
      delay();
      RB4=0;
      delay();
    }
  }
}
void delay()
{
  for(int i=0;i<40;i++)
    __delay_ms(10);
}