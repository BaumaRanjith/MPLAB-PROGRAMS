#include<pic.h>
#define _XTAL_FREQ 20000000
__CONFIG(0X3D72);
void delay();
void main()
{
  TRISB=0X00;
  TRISC=0X00;
  PORTC=0X00;
  if(RC0==1)
  {
    for(int i=0;i<9;i++)
    {
      PORTB=0X03; // 0
      delay();
      PORTB=0X9F; // 1 
      delay();
      PORTB=0X25; // 2
      delay();
      PORTB=0X0D; // 3
      delay();
      PORTB=0X99; // 4
      delay();
      PORTB=0X49; // 5
      delay();
      PORTB=0X41; // 6 
      delay();
      PORTB=0X1F; // 7
      delay();
      PORTB=0X01; // 8
      delay();
      PORTB=0X19; // 9
      delay();
    }
  }
}
void delay()
{
  for(int i=0;i<50;i++)
    __delay_ms(10);
}