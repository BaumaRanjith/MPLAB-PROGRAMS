#include<pic.h>
#include<string.h>

#define _XTAL_FREQ 20000000
__CONFIG(0X3D72);

#define RS RD6
#define RW RD5
#define EN RD7

int i=0;

void lcd_init();
void lcd_cmd(unsigned char);
void lcd_data(unsigned char);
void lcd_str(const char *str);

void main()
{ 
  TRISB=0X00;
  PORTB=0X00;
  TRISD=0X00;
  PORTD=0X00;
  
  lcd_init();
  
  RD0=1;
  
  while(1)
  {
    if(RD0==0)
    {
      lcd_cmd(0x80);
      lcd_str("BAUMA RANJITH");
    }
      
  } 
}

void lcd_init()
{
  lcd_cmd(0X38);
  lcd_cmd(0X0C);
  lcd_cmd(0X06);    
  lcd_cmd(0X01);
  lcd_cmd(0X80);
}

void lcd_cmd(unsigned char c)
{
  PORTB=c;
  RS=0;
  EN=1;
  //__delay_ms(1);
  for(int i=0;i<30000;i++);
  EN=0;
}

void lcd_data(unsigned char b)
{
  PORTB=b;
  RS=1;
  EN=1;
  //__delay_ms(1);
  for(int i=0;i<30000;i++);
  EN=0;
}

void lcd_str(const char *str)
{
  while(*str)
  {
    lcd_data(*str++);
  }
}

