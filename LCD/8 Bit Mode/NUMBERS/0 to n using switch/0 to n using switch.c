#include <pic.h>
#define _XTAL_FREQ 20000000
__CONFIG(0X3D72);

#define RS RD5
#define RW RD6
#define EN RD7

void lcd_init();
void lcd_cmd(unsigned char);
void lcd_data(unsigned char);
void lcd_str(const char *s);
void manipulation(unsigned int);
void delay(unsigned int);

void main()
{
  TRISB = 0X00;
  PORTB = 0X00;
  TRISD = 0X00;
  PORTD = 0X00;
  TRISC = 0X00;
  PORTC = 0X00;

  lcd_init();
  lcd_cmd(0x80);
  lcd_str("PRESS TO START");

  while (1)
  {
    int a=999;
    if(RC7==1)
    {
      lcd_cmd(0x01);
      for (int i = 0; i <= a; i++)
      {
        lcd_cmd(0x80);
        lcd_str("COUNT=");
        manipulation(i);
        if (i == a)
          break;
      }
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

void lcd_cmd(unsigned char value)
{
  PORTB = value;
  RS = 0;
  EN = 1;
  delay(10);
  EN = 0;
}

void lcd_data(unsigned char value)
{
  PORTB = value;
  RS = 1;
  EN = 1;
  delay(10);
  EN = 0;
}

void lcd_str(const char *s)
{
  while (*s)
  {
    lcd_data(*s++);
    delay(100);
  }
}

void delay(unsigned int d)
{
  for(int i=0;i<d;i++)
  __delay_ms(1);
}

void manipulation(unsigned int a)
{
  int temp = a;
  int numDigits = 0;
  // Count the number of digits in the number
  
  if(temp==0)
  {
    lcd_cmd(0x86);
    lcd_data('0');
  }
  
  while (temp)
  {
    temp /= 10;
    numDigits++;
  }
  // Calculate position for displaying digits
  int position = 0x86 + numDigits - 1;
  // Extract and display each digit
  for (int i = 0; i < numDigits; i++)
  {
    int digit = a % 10;
    lcd_cmd(position--);
    lcd_data(digit + '0');
    a /= 10;
  }
}
