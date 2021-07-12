#ifndef MAGNETIC_SENSOR
#define MAGNETIC_SENSOR

#include <Arduino.h>

template <int Pin>
class MagneticSensor {
 public:
  void updateRead();               // this will update the magState
  unsigned short getUpdateRead();  // this will update and return a read
  unsigned short getRead();        // this will return the current read
  void printRead();                // this will print it for testing purposes

 private:
  unsigned short magState;  // stores the current state of a mag sensor
};

template <int F, int B>
class MagneticGroup {
  // methods that use mag sensors as a group
};

template<int Pin>
void MagneticSensor<Pin>::updateRead()
{
    this->magState = digitalRead(Pin);
}

template<int Pin>
unsigned short MagneticSensor<Pin>::getUpdateRead()
{
    this->magState = digitalRead(Pin);
    return magState;
}

template<int Pin>
unsigned short MagneticSensor<Pin>::getRead()
{
    return magState;
}

template<int Pin>
void MagneticSensor<Pin>::printRead()
{
    Serial.println(getRead());
}

#endif  // MAGNETIC_SENSOR