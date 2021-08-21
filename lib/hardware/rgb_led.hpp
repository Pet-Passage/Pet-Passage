#ifndef PET_PASSAGE_HARDWARE_RGB_LED_H_
#define PET_PASSAGE_HARDWARE_RGB_LED_H_

#include "Arduino.h"

template <uint8_t R, uint8_t G, uint8_t B>
struct RgbLed {
 public:
  /**
   * Sets the pin mode for each port given in template
   */
  void init();
  /**
   * Sets the color of an LED light off a given RGB code
   *
   * @param red uint8_t for the Red of RGB code
   * @param green uint8_t for the Green RGB code
   * @param blue uint8_t for the Blue RGB code
   */
  void setColor(uint8_t red, uint8_t green, uint8_t blue);
};

#include "rgb_led.ipp"

#endif
