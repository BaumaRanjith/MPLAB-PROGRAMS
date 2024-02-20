#include <pic.h>
__CONFIG(0X3D72);

#define _XTAL_FREQ 20000000
// Define the LCD pins
#define RS RD6
#define RW RD5
#define EN RD7
#define D0 RB0
#define D1 RB1
#define D2 RB2
#define D3 RB3
#define D4 RB4
#define D5 RB5
#define D6 RB6
#define D7 RB7

// Function prototypes
void LCD_Init();
void string(const char *s);
void LCD_Cmd(char cmd);
void LCD_Char(char data);
void LCD_CustomChar(unsigned char loc, unsigned char *ptr);

// Custom character data (example: heart symbol)
unsigned char heart[8] = {0b00000, 0b01010, 0b11111, 0b11111, 0b01110, 0b00100, 0b00000, 0b00000};
unsigned char cigarette[8] = {0b000001, 0b00010, 0b00010, 0b00001, 0b11111, 0b11111, 0b00000, 0b00000};
unsigned char man[8] = {0b01110, 0b01110, 0b00100, 0b11111, 0b00100, 0b01010, 0b01010, 0b00000};
unsigned char spade[8] = {0b00100, 0b01110, 0b10111, 0b11111, 0b00100, 0b01110, 0b11111, 0b00000};

void main() {
    // Initialize LCD
    LCD_Init();

    // Store custom character in CGRAM
    LCD_CustomChar(0, heart);
    //LCD_CustomChar(1, cigarette);
    LCD_CustomChar(2, man);
    LCD_CustomChar(3, spade);

    while (1) {
        // Display the custom character
        LCD_Cmd(0x80); // Set DDRAM address to 0x00 (first line)
        string("HEART=");
        LCD_Char(0);    // Display custom character (heart symbol)
        //string(", CIGARETTE=");
        //LCD_Char(1);    // Display custom character (cigarette symbol)
        LCD_Cmd(0xC0);
        string("MAN=");
        LCD_Char(2);    // Display custom character (man symbol)
        string(", SPADE=");
        LCD_Char(3);    // Display custom character (fish symbol)
    }
}

void LCD_Init() {
    TRISD = 0x00;
    TRISB = 0x00; // Set PORTB as output
    //__delay_ms(10);
    LCD_Cmd(0x38); // 8-bit mode, 2 lines, 5x8 font
    LCD_Cmd(0x0C); // Display ON, Cursor OFF, Blink OFF
    LCD_Cmd(0x06); // Increment cursor
    LCD_Cmd(0x01); // Clear display
    //__delay_ms(10);
}

void LCD_Cmd(char cmd) {
    RS = 0; // Command mode
    PORTB = cmd; // Send command
    RW=0;
    EN = 1;
    __delay_ms(10);
    EN = 0;
}

void LCD_Char(char data) {
    RS = 1; // Data mode
    PORTB = data; // Send data
    RW=0;
    EN = 1;
    __delay_ms(10);
    EN = 0;
}

void LCD_CustomChar(unsigned char loc, unsigned char *ptr) {
    if (loc < 8) {
        LCD_Cmd(0x40 + (loc * 8)); // Set CGRAM address
        for (unsigned char i = 0; i < 8; i++) {
            LCD_Char(ptr[i]);
        }
        LCD_Cmd(0x80); // Set DDRAM address to 0x00 (first line)
    }
}

void string(const char *s)
{
  while(*s)
  {
    LCD_Char(*s++);
  }
}
