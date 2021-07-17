#ifndef PET_PASSAGE_HARDWARE_LED_LIGHT_I_
#define PET_PASSAGE_HARDWARE_LED_LIGHT_I_

#include "Arduino.h"
#include "led_light.hpp"

template <uint8_t Pin>
LedLight<Pin>::LedLight() {
  this->mode = 0;  // sets mode to LOW
}

template <uint8_t Pin>
void LedLight<Pin>::init() {
  pinMode(Pin, OUTPUT);
  setLow();  // writes to the light as off for default
}

template <uint8_t Pin>
uint8_t LedLight<Pin>::getMode() {
  return this->mode;
}

template <uint8_t Pin>
void LedLight<Pin>::switchMode() {
  switch (mode) {
    case 0:
      setHigh();
      break;
    case 1:
      setLow();
      break;
    default:
      break;
  }
}

template <uint8_t Pin>
void LedLight<Pin>::setLow()  // will switch the mode to the opposite
{
  digitalWrite(Pin, LOW);
}

template <uint8_t Pin>
void LedLight<Pin>::setHigh()  // will switch the mode to the opposite
{
  digitalWrite(Pin, HIGH);
}

#endif
