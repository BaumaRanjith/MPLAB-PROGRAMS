#include<pic.h>
#define _XTAL_FREQ 20000000
__CONFIG(0X3D72);
void delay();
void main()
{
  TRISB=0X00;
  TRISC=0X00;
  PORTB=0X00;
  PORTC=0X10;
  if(RC4==0)
  {
    while(1)
    {
      RB4=1;
      delay();
      for(int i=0;i<8;i++)
      {
        PORTB=PORTB>>1;
        delay();
      }
    }
  }
}
void delay()
{
  for(int i=0;i<40;i++)
    __delay_ms(10);
}