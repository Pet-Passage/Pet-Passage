#ifndef PET_PASSAGE_LIB_MAGNETIC_SENSOR_GROUP_H_
#define PET_PASSAGE_LIB_MAGNETIC_SENSOR_GROUP_H_

#include "magnetic_sensor.hpp"

template <uint8_t F, uint8_t S, class State>
class MagneticSensorPair {
 public:
  void init();
  void updateState();
  State getState() const;
  bool operator==(const State &state) const;
  bool operator!=(const State &state) const;

 private:
  MagneticSensor<F> first;
  MagneticSensor<S> second;
};

#include "magnetic_sensor_pair.ipp"

#endif
