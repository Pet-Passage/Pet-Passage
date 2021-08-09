#ifndef PET_PASSAGE_HARDWARE_LCD_H_
#define PET_PASSAGE_HARDWARE_LCD_H_

#include <Arduino.h>
#include <LiquidCrystal.h>

struct Lcd {
  void updateScreen(uint8_t insideCount, uint8_t outsideCount);
};

#include "lcd.ipp"

#endif
