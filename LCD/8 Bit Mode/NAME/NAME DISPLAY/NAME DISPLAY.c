#include<pic.h>
#define _XTAL_FREQ 20000000
__CONFIG(0X3D72);

#define RS RD6
#define EN RD7
#define RW RD5


void lcd_init();
void lcd_cmd(unsigned char);
void lcd_data(unsigned char);

void main()
{ 
  lcd_init();
    
  while(1)
  { 
    lcd_cmd(0x80);
    
    lcd_data('B');
    lcd_data('A');
    lcd_data('U');
    lcd_data('M');
    lcd_data('A');
  }
}

void lcd_init()
{
  TRISB=0X00;
  PORTB=0X00;
  TRISD=0X00;
  PORTD=0X00;
  
  lcd_cmd(0X38);
  lcd_cmd(0X0C);
  lcd_cmd(0X06);    
  lcd_cmd(0X01);
  lcd_cmd(0X80);
}

void lcd_cmd(unsigned char value)
{
  PORTB=value;
  RS=0;
  EN=1;
  __delay_ms(1);
  EN=0;
}

void lcd_data(unsigned char value)
{
  PORTB=value;
  RS=1;
  EN=1;
  __delay_ms(1);
  EN=0;
}



