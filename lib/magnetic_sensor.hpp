#ifndef PET_PASSAGE_LIB_MAGNETIC_SENSOR_H
#define PET_PASSAGE_LIB_MAGNETIC_SENSOR_H

#include <Arduino.h>

template <int Pin>
class MagneticSensor {
 public:
  void updateState();               // this will update the magState
  unsigned short getUpdateState();  // this will update and return a read
  unsigned short getState();        // this will return the current read
  void printState();                // this will print it for testing purposes

 private:
  unsigned short magState;  // stores the current state of a mag sensor
};

template <int F, int B>
class MagneticGroup {
  // methods that use mag sensors as a group
};

template<int Pin>
void MagneticSensor<Pin>::updateState()
{
    this->magState = digitalRead(Pin);
}

template<int Pin>
unsigned short MagneticSensor<Pin>::getUpdateState()
{
    this->magState = digitalRead(Pin);
    return magState;
}

template<int Pin>
unsigned short MagneticSensor<Pin>::getState()
{
    return magState;
}

template<int Pin>
void MagneticSensor<Pin>::printState()
{
    Serial.println(getRead());
}

#endif  // PET_PASSAGE_LIB_MAGNETIC_SENSOR_H