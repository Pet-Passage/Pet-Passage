#ifndef PET_PASSAGE_FSM_DOOR_FSM_H_
#define PET_PASSAGE_FSM_DOOR_FSM_H_

#include "Arduino.h"
#include "magnetic_sensor_pair.hpp"

#define DOORSTATE_MAX_HOOKS 2

enum class DoorState : int8_t { OpenIn = -1, Closed = 1, OpenOut = 0 };

typedef void (*hook_fn_t)(DoorState &state);

template <uint8_t F, uint8_t S>
class DoorStateManager {
 public:
  void init();
  void update();
  template <int I>
  constexpr void onChange(hook_fn_t hook);

 private:
  DoorState state;
  MagneticSensorPair<F, S, DoorState> sensorPair;
  hook_fn_t hooks[DOORSTATE_MAX_HOOKS]{nullptr};
};

#include "door_fsm.ipp"

#endif
