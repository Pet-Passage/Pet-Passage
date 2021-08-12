#ifndef PET_PASSAGE_HARDWARE_LCD_H_
#define PET_PASSAGE_HARDWARE_LCD_H_

#include <Arduino.h>
#include <LiquidCrystal.h>

template <uint8_t RS, uint8_t E, uint8_t D4, uint8_t D5, uint8_t D6, uint8_t D7>
class Lcd {
 public:
  void init();
  void updateScreen(uint8_t insideCount, uint8_t outsideCount);
};

#include "lcd.ipp"

#endif
