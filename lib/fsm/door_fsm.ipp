#ifndef PET_PASSAGE_FSM_DOOR_FSM_I_
#define PET_PASSAGE_FSM_DOOR_FSM_I_

#include "door_fsm.hpp"

template <uint8_t F, uint8_t S>
DoorStateManager<F, S>::DoorStateManager() {
  state = DoorState::Initializing;
}

template <uint8_t F, uint8_t S>
void DoorStateManager<F, S>::init() {
  sensorPair.init();
  state = sensorPair.getState();
}

template <uint8_t F, uint8_t S>
void DoorStateManager<F, S>::update() {
  sensorPair.updateState();
  DoorState prevState = state;
  switch (sensorPair.getState()) {
    case DoorState::OpenIn:
      if (state == DoorState::Closed) {
        state = DoorState::OpenIn;
      }
      break;
    case DoorState::Closed:
      if (state == DoorState::OpenIn || state == DoorState::OpenOut) {
        state = DoorState::Closed;
      }
      break;
    case DoorState::OpenOut:
      if (state == DoorState::Closed) {
        state = DoorState::OpenOut;
      }
      break;
    default:
      break;
  }
  if (prevState != state) {
    for (int i = 0; i < DOORSTATE_MAX_HOOKS && hooks[i] != nullptr; i++) {
      hooks[i](state);
    }
  }
}

template <uint8_t F, uint8_t S>
template <int I>
constexpr void DoorStateManager<F, S>::onChange(hook_fn_t hook) {
  static_assert(I < DOORSTATE_MAX_HOOKS,
                "Index greater than the max number of hooks");
  hooks[I] = hook;
}

#endif
