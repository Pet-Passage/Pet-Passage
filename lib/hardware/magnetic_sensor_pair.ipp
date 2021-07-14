#ifndef PET_PASSAGE_LIB_MAGNETIC_SENSOR_GROUP_I_
#define PET_PASSAGE_LIB_MAGNETIC_SENSOR_GROUP_I_

#include "magnetic_sensor_pair.hpp"

template <uint8_t F, uint8_t S, class State>
void MagneticSensorPair<F, S, State>::init() {
  first.init();
  second.init();
}

template <uint8_t F, uint8_t S, class State>
void MagneticSensorPair<F, S, State>::updateState() {
  first.updateState();
  second.updateState();
}

template <uint8_t F, uint8_t S, class State>
State MagneticSensorPair<F, S, State>::getState() const {
  return static_cast<State>(first.getState() - second.getState());
}

template <uint8_t F, uint8_t S, class State>
bool MagneticSensorPair<F, S, State>::operator==(const State &state) const {
  return getState() == state;
}

template <uint8_t F, uint8_t S, class State>
bool MagneticSensorPair<F, S, State>::operator!=(const State &state) const {
  return getState() != state;
}

#endif
