#ifndef PET_PASSAGE_HARDWARE_LCD_H
#define PET_PASSAGE_HARDWARE_LCD_H

#include <Arduino.h>
#include <LiquidCrystal.h>

class Lcd {
  void init();
  void updateScreen();
};

#endif
