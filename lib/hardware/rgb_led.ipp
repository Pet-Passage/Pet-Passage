#ifndef PET_PASSAGE_HARDWARE_RGB_LED_I_
#define PET_PASSAGE_HARDWARE_RGB_LED_I_

#include "rgb_led.hpp"

template <uint8_t R, uint8_t G, uint8_t B>
void RgbLed<R, G, B>::init() {
  pinMode(R, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(B, OUTPUT);
}

template <uint8_t R, uint8_t G, uint8_t B>
void RgbLed<R, G, B>::setColor(uint8_t red, uint8_t green, uint8_t blue) {
  analogWrite(R, red);
  analogWrite(G, green);
  analogWrite(B, blue);
}

#endif
