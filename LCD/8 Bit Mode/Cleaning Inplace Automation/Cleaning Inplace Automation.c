#include<pic.h>

#define _XTAL_FREQ 20000000
#define RS RD5
#define RW RD6
#define EN RD7

__CONFIG(0x3D72);

void clear_screen();
void lcd_init();
void lcd_cmd(unsigned char);
void lcd_data(unsigned char);
void string(const char *s);
void delay(unsigned int);
void drain();

void main()
{
  TRISB=0X00;
  PORTB=0X00;
  TRISD=0X00;
  PORTD=0X00;
  TRISC=0X00;
  PORTC=0X00;
  
  lcd_init();
  string("PRESS TO START");
  
  while(1)
  {
    if(RC7==1)
    {
      //--------COLD WATER TREATMENT--------------------
      
      clear_screen();
      string("COLD WATER");
      lcd_cmd(0XC0);
      string("VALVE OPEN");
      RD0=1;
      delay(1000);
      RD0=0;
      delay(1000);
      
      clear_screen();
      string("COLD WATER");
      lcd_cmd(0XC0);
      string("VALVE CLOSE");
      RD0=1;
      delay(1000);
      RD0=0;
      delay(1000);
      
      drain(); // DRAINING PROCESS
      
      //--------HOT WATER TREATMENT----------------------
      
      clear_screen();
      string("HOT WATER");
      lcd_cmd(0XC0);
      string("VALVE OPEN");
      RD1=1;
      delay(1000);
      RD1=0;
      delay(1000);
      
      clear_screen();
      string("HOT WATER");
      lcd_cmd(0XC0);
      string("VALVE CLOSE");
      RD1=1;
      delay(1000);
      RD1=0;
      delay(1000);
      
      drain(); // DRAINING PROCESS
      
      //--------ACIDIC WARER TREATMENT--------------------
      
      clear_screen();
      string("ACIDIC WATER");
      lcd_cmd(0XC0);
      string("VALVE OPEN");
      RD2=1;
      delay(1000);
      RD2=0;
      delay(1000);
      
      clear_screen();
      string("ACIDIC WATER");
      lcd_cmd(0XC0);
      string("VALVE CLOSE");
      RD2=1;
      delay(1000);
      RD2=0;
      delay(1000);
      
      drain(); // DRAINING PROCESS
      
      //--------ALKALINE WARER TREATMENT--------------------
      
      clear_screen();
      string("ALKALINE WATER");
      lcd_cmd(0XC0);
      string("VALVE OPEN");
      RD3=1;
      delay(1000);
      RD3=0;
      delay(1000);
      
      clear_screen();
      string("ALKALINE WATER");
      lcd_cmd(0XC0);
      string("VALVE CLOSE");
      RD3=1;
      delay(1000);
      RD3=0;
      delay(1000);
      
      drain(); // DRAINING PROCESS
      
      //--------COLD WARER TREATMENT--------------------
      
      clear_screen();
      string("COLD WATER");
      lcd_cmd(0XC0);
      string("VALVE OPEN");
      RD0=1;
      delay(1000);
      RD0=0;
      delay(1000);
      
      clear_screen();
      string("COLD WATER");
      lcd_cmd(0XC0);
      string("VALVE CLOSE");
      RD0=1;
      delay(1000);
      RD0=0;
      delay(1000);
      
      drain(); // DRAINING PROCESS
     
      break;
    }
  }
  
}

void clear_screen()
{
  lcd_cmd(0x01);
  lcd_cmd(0x80);
}

void lcd_init()
{
  lcd_cmd(0x38);
  lcd_cmd(0x0C);
  lcd_cmd(0x14);
  lcd_cmd(0x01);
  lcd_cmd(0x80);
}

void lcd_cmd(unsigned char a)
{
  PORTB=a;
  RS=0;
  RW=0;
  EN=1;
  delay(10);
  EN=0;
}

void lcd_data(unsigned char a)
{
  PORTB=a;
  RS=1;
  RW=0;
  EN=1;
  delay(10);
  EN=0;
}

void string(const char *s)
{
  while(*s)
  {
    lcd_data(*s++);
    delay(10);
  }
}

void delay(unsigned int a)
{
  for(int i=0;i<a;i++)
  {
    __delay_ms(1);
  }
}

void drain()
{
  clear_screen();
  string("DRAIN OPEN");
  lcd_cmd(0XC0);
  string("VALVE OPEN");
  RD4=1;
  delay(1000);
  RD4=0;
  delay(1000);
  
  clear_screen();
  string("DRAIN CLOSE");
  lcd_cmd(0XC0);
  string("VALVE CLOSE");
  RD4=1;
  delay(1000);
  RD4=0;
  delay(1000);
}
