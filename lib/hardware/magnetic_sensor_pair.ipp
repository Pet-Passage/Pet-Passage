#ifndef PET_PASSAGE_LIB_MAGNETIC_SENSOR_GROUP_I_
#define PET_PASSAGE_LIB_MAGNETIC_SENSOR_GROUP_I_

#include "magnetic_sensor_pair.hpp"

template<unsigned int F, unsigned int S, class State>
void MagneticSensorPair<F, S, State>::init() {
  first.init();
  second.init();
}

template <unsigned int F, unsigned int S, class State>
void MagneticSensorPair<F, S, State>::updateState() {
  first.updateState();
  second.updateState();
}

template <unsigned int F, unsigned int S, class State>
State MagneticSensorPair<F, S, State>::getState() const {
  return static_cast<State>(first.getState() - second.getState());
}

template <unsigned int F, unsigned int S, class State>
bool MagneticSensorPair<F, S, State>::operator==(const State &state) const {
  return getState() == state;
}

template <unsigned int F, unsigned int S, class State>
bool MagneticSensorPair<F, S, State>::operator!=(const State &state) const {
  return getState() != state;
}

#endif
