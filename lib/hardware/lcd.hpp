#ifndef PET_PASSAGE_HARDWARE_LCD_H_
#define PET_PASSAGE_HARDWARE_LCD_H_

#include <Arduino.h>
#include <LiquidCrystal.h>
#include <string.h>

template <uint8_t RS, uint8_t E, uint8_t D4, uint8_t D5, uint8_t D6, uint8_t D7>
class Lcd {
 public:
  void init();
  void singleLineScreen(String input);
  void doubleLineScreen(String lineOne, String lineTwo);
};

#include "lcd.ipp"

#endif
