#include<pic.h>
#define _XTAL_FREQ 20000000
__CONFIG(0X3D72);
void delay();
void main()
{
  TRISB=0X00;
  PORTB=0X00;
  TRISC=0X00;
  PORTC=0X00;
  int count=0;
  while(1)
  {  
    if(RC0==1)
    {
      count++;
      delay();
    }
    if(RC1==1)
    {
      count--;
      delay();
    }
    if(count>9)
    { 
      count=9;
    }    
    if(count<0)
    { 
      count=0;
    }
    switch(count)
    {
      case 0:
        PORTB=0X03; // 0
        break;
      case 1:
        PORTB=0X9F; // 1
        break; 
      case 2:
        PORTB=0X25; // 2
        break;
      case 3:
        PORTB=0X0D; // 3
        break;
      case 4:
        PORTB=0X99; // 4
        break;
      case 5:
        PORTB=0X49; // 5
        break;
      case 6:
        PORTB=0X41; // 6 
        break;
      case 7:
        PORTB=0X1F; // 7
        break;
      case 8:
        PORTB=0X01; // 8
        break;
      case 9:
        PORTB=0X19; // 9
        break;
    }
  }
}
void delay()
{
  for(int i=0;i<25;i++)
    __delay_ms(10);
}