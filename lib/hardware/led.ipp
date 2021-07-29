#ifndef PET_PASSAGE_HARDWARE_LED_I_
#define PET_PASSAGE_HARDWARE_LED_I_

#include "Arduino.h"
#include "led.hpp"

template <uint8_t Pin>
void Led<Pin>::init() {
  pinMode(Pin, OUTPUT);
  setLow();  // writes to the light as off for default
}

template <uint8_t Pin>
void Led<Pin>::setLow()  // will switch the mode to the opposite
{
  digitalWrite(Pin, LOW);
}

template <uint8_t Pin>
void Led<Pin>::setHigh()  // will switch the mode to the opposite
{
  digitalWrite(Pin, HIGH);
}

#endif
