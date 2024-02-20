#include <pic.h>
#define _XTAL_FREQ 20000000
__CONFIG(0X3D72);

#define RS RD6
#define EN RD7
#define RW RD5

void lcd_init();
void lcd_cmd(unsigned char);
void lcd_data(unsigned char);
void lcd_str(const char *s);
void manipulation(unsigned int);


void main()
{
  TRISB = 0X00;
  PORTB = 0X00;
  TRISD = 0X00;
  PORTD = 0X00;

  lcd_init();

  int n = 19;

  while (1)
  {
    lcd_cmd(0x01);
    for (int i = n; i >= 0; i--)
    {
      lcd_cmd(0x80);
      lcd_str("REV_COUNT=");
      manipulation(i);
      __delay_ms(10);
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
  __delay_ms(10);
  EN = 0;
}

void lcd_data(unsigned char value)
{
  PORTB = value;
  RS = 1;
  EN = 1;
  __delay_ms(10);
  EN = 0;
}

void lcd_str(const char *s)
{
  while (*s)
  {
    lcd_data(*s++);
  }
}

void manipulation(unsigned int a)
{
  int temp = a;
  int numDigits = 0;
  
  // Count the number of digits in the number
  while (temp > 0)
  {
    temp /= 10;
    numDigits++;
  }

  // Calculate position for displaying digits
  int position = 0x8A + numDigits - 1;
  int d = position + 1;

  // Extract and display each digit
  while (a > 0)
  { __delay_ms(10);
    lcd_cmd(d);
    lcd_data(" ");
    int digit = a % 10;
    lcd_cmd(position--);
    lcd_data(digit + '0');
    a /= 10;
  }
}