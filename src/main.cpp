/*
  LCD_I2C by Everything2067.
  Presents a demo for your I2C LCD.
  You may also use this to test the LCD as well.
  This program will count a variable and display it on the LCD, blinking the backlight too.
  Make sure the backlight jumper is in place and the constrast setting is set properly.
*/

// Definitions for columns and rows. You can change this as per your need.
#define COLUMNS 16
#define ROWS    2

// Definitions for I2C backpack chip addresses.
// Select as per the chip and the I2C Address setting.

// TI PCF8574
#define ADDRESS 0x27
// #define ADDRESS 0x26
// #define ADDRESS 0x25
// #define ADDRESS 0x24
// #define ADDRESS 0x23
// #define ADDRESS 0x22
// #define ADDRESS 0x21
// #define ADDRESS 0x20

// NXP PCF8574
// #define ADDRESS 0x3F
// #define ADDRESS 0x3E
// #define ADDRESS 0x3D
// #define ADDRESS 0x3C
// #define ADDRESS 0x3B
// #define ADDRESS 0x3A
// #define ADDRESS 0x39
// #define ADDRESS 0x38

// Including required libraries
#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

// Custom character ✅
uint8_t Check[8] =
{
0b00000,
0b00001,
0b00011,
0b10110,
0b11100,
0b01000,
0b00000,
0b00000
};

// Variable for counting
int count;

// Creating LCD Object
LiquidCrystal_I2C lcd(ADDRESS, COLUMNS, ROWS);

void setup() {
  // Initialise LCD
  lcd.init();
  lcd.clear();
  lcd.createChar(0, Check);

  // Print the first line
  lcd.setCursor(0, 0);
  lcd.print("Hello! Testing ");
  lcd.write(0);

  lcd.setCursor(0, 1);
}

void loop() {
  // Keep on printing the count
  lcd.setCursor(0, 1);
  lcd.backlight();
  lcd.print(count);
  count++;
  delay(1000);

  // Repeat to turn off backlight
  lcd.setCursor(0, 1);
  lcd.noBacklight();
  lcd.print(count);
  count++;
  delay(1000);
}