#include<pic.h>
#define _XTAL_FREQ 20000000
__CONFIG (0x3D72);
void delay();
void main()
{
  TRISB=0x00;
  PORTB=0x01;
  delay();
  for(int i=0;i<8;i++)
  {
    PORTB=PORTB<<1;
    delay();
  }
}
void delay()
{
  for(int i =0;i<40;i++)
    __delay_ms(10);
}
