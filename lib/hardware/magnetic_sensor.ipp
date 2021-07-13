#ifndef PET_PASSAGE_LIB_MAGNETIC_SENSOR_I_
#define PET_PASSAGE_LIB_MAGNETIC_SENSOR_I_

#include <Arduino.h>

#include "magnetic_sensor.hpp"

template <unsigned int Pin>
MagneticSensor<Pin>::MagneticSensor() {
  state = false;
}

template <unsigned int Pin>
void MagneticSensor<Pin>::init() {
  pinMode(Pin, INPUT);
  updateState();
}

template <unsigned int Pin>
void MagneticSensor<Pin>::updateState() {
  switch (digitalRead(Pin)) {
    case 0:
      state = false;
      break;
    case 1:
      state = true;
      break;
    default:
      break;
  }
}

template <unsigned int Pin>
bool MagneticSensor<Pin>::getState() const {
  return state;
}

template <unsigned int Pin>
MagneticSensor<Pin>::operator bool() const {
  return state;
}

template <unsigned int Pin>
bool MagneticSensor<Pin>::operator!() const {
  return !state;
}

#endif
