#ifndef PET_PASSAGE_HARDWARE_LED_H_
#define PET_PASSAGE_HARDWARE_LED_H_

#include "Arduino.h"
#include "led_base.hpp"

template <uint8_t Pin>
struct Led final : public LedBase {
  void init() override;
  void setLow() override;
  void setHigh() override;
};

#include "led.ipp"

#endif
