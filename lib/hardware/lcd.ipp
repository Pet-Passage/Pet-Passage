#ifndef PET_PASSAGE_HARDWARE_LCD_I_
#define PET_PASSAGE_HARDWARE_LCD_I_

#include "lcd.hpp"

void Lcd::updateScreen(uint8_t insideCount, uint8_t outsideCount) {
  LiquidCrystal lcd(1, 2, 3, 4, 5, 6);  // make actual numbers in ports.h
  lcd.begin(16, 2);
  lcd.print("Pets Outside:" + insideCount);
  lcd.setCursor(0, 1);
  lcd.print("Pets Inside:" + outsideCount);
}

#endif
