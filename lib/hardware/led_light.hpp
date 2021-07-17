#ifndef PET_PASSAGE_HARDWARE_LED_LIGHT_H_
#define PET_PASSAGE_HARDWARE_LED_LIGHT_H_

#include "Arduino.h"

template <uint8_t Pin>
class LedLight {
 public:
  LedLight();
  void init();
  void switchMode();
  void setLow();
  void setHigh();
  uint8_t getMode();

 private:
  bool mode;
};

#include "led_light.ipp"

#endif
