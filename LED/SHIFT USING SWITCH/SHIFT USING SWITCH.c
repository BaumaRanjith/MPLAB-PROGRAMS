#include<pic.h>
#define _XTAL_FREQ 20000000
__CONFIG(0X3D72);
void delay();
void main()
{
  TRISB=0X00;
  TRISC=0X00;
  PORTB=0X01;
  PORTC=0X00;
  while(1)
  {
    if(RC2==1) // Right Shift
    {
      PORTB=PORTB>>1;
      delay();
    }
    else if(RC0==1) // Left Shift
    {
      PORTB=PORTB<<1;
      delay();
    }
  }
}
void delay()
{
  for(int i=0;i<50;i++)
    __delay_ms(10);
}