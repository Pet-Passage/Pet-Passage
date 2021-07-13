#ifndef PET_PASSAGE_LIB_MAGNETIC_SENSOR_H_
#define PET_PASSAGE_LIB_MAGNETIC_SENSOR_H_

template <unsigned int Pin>
class MagneticSensor {
 public:
  MagneticSensor();
  void init();
  void updateState();     // this will update the magState
  bool getState() const;  // this will return the current read
  explicit operator bool() const;
  bool operator!() const;

 private:
  bool state;  // stores the current state of a mag sensor
};

#include "magnetic_sensor.ipp"

#endif
