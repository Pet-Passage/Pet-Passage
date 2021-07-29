#ifndef PET_PASSAGE_HARDWARE_LED_LIGHT_H_
#define PET_PASSAGE_HARDWARE_LED_LIGHT_H_

#include "Arduino.h"
#include "led_base.hpp"

template <uint8_t Pin>
class LedLight : public LedBase {
 public:
  void virtual init();
  void virtual setLow();
  void virtual setHigh();
};

#include "led_light.ipp"

#endif
