#ifndef PET_PASSAGE_HARDWARE_LCD_I_
#define PET_PASSAGE_HARDWARE_LCD_I_

#include "lcd.hpp"

template <uint8_t RS, uint8_t E, uint8_t D4, uint8_t D5, uint8_t D6, uint8_t D7>
void Lcd<RS, E, D4, D5, D6, D7>::init(){
  LiquidCrystal lcd(RS,E,D4,D5,D6,D7);
  lcd.print("Welcome!");
}

template <uint8_t RS, uint8_t E, uint8_t D4, uint8_t D5, uint8_t D6, uint8_t D7>
void Lcd<RS, E, D4, D5, D6, D7>::updateScreen(uint8_t insideCount,
                                              uint8_t outsideCount) {
  LiquidCrystal lcd(RS, E, D4, D5, D6, D7);  // make actual numbers in ports.h
  lcd.begin(16, 2);
  lcd.print("Pets Outside: ");
  lcd.print(outsideCount);
  lcd.setCursor(0, 1);
  lcd.print("Pets Inside: ");
  lcd.print(insideCount);
}

#endif
