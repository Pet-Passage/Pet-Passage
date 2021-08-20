#ifndef PET_PASSAGE_HARDWARE_RGB_LED_H_
#define PET_PASSAGE_HARDWARE_RGB_LED_H_

#include "Arduino.h"

template <uint8_t R, uint8_t G, uint8_t B>
struct RgbLed {
 public:
  void init();  // call on setup, will set pinmode for ports
  void setColor(uint8_t red, uint8_t green,
                uint8_t blue);  // sets color of rgb, passing in each color as
                                // an RGB value
};

#include "rgb_led.ipp"

#endif
