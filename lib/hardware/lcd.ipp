#ifndef PET_PASSAGE_HARDWARE_LCD_I_
#define PET_PASSAGE_HARDWARE_LCD_I_

#include "lcd.hpp"

template <uint8_t RS, uint8_t E, uint8_t D4, uint8_t D5, uint8_t D6, uint8_t D7>
void Lcd<RS, E, D4, D5, D6, D7>::init() {
  LiquidCrystal lcd(RS, E, D4, D5, D6, D7);
  lcd.print("Welcome!");
}

// 16 x 1

template <uint8_t RS, uint8_t E, uint8_t D4, uint8_t D5, uint8_t D6, uint8_t D7>
void Lcd<RS, E, D4, D5, D6, D7>::singleLineScreen(String input) {
  LiquidCrystal lcd(RS, E, D4, D5, D6, D7);
  lcd.begin(16, 1);
  if (input.length() <= 16) {
    lcd.print(input);
  } else {
    lcd.print("Input too long");
    Serial.println("Input too Long");
  }
}

// 16 x 2

template <uint8_t RS, uint8_t E, uint8_t D4, uint8_t D5, uint8_t D6, uint8_t D7>
void Lcd<RS, E, D4, D5, D6, D7>::doubleLineScreen(String lineOne,
                                                  String lineTwo) {
  LiquidCrystal lcd(RS, E, D4, D5, D6, D7);
  lcd.begin(16, 2);
  if (lineTwo.length() <= 16 && lineOne.length() <= 16) {
    lcd.print(lineOne);
    lcd.setCursor(0, 1);
    lcd.print(lineTwo);
  } else {
    lcd.print("Input too long");
    Serial.println("Input too Long");
  }
}

#endif
