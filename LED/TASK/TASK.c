#include<pic.h>
#define _XTAL_FREQ 20000000
__CONFIG(0X3D72);
void delay(unsigned int);
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
      delay(500);
      //RB4=0;
      //delay(500);
      if(RC2==1)
      {
        delay(2000);
        break;
      }
      
    }
  }
}
void delay(unsigned int a)
{
  for(int i=0;i<a;i++)
    __delay_ms(1);
}