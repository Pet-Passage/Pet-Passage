#ifndef PET_PASSAGE_HARDWARE_LED_LIGHT_GROUP_I_
#define PET_PASSAGE_HARDWARE_LED_LIGHT_GROUP_I_

#include "led_light_group.hpp"

template <uint8_t OI, uint8_t C, uint8_t OO, uint8_t E>
void LedLightGroup<OI, C, OO, E>::init() {
  openIn.init();
  closed.init();
  openOut.init();
  error.init();
}

template <uint8_t OI, uint8_t C, uint8_t OO, uint8_t E>
void LedLightGroup<OI, C, OO, E>::updateActive(const DoorState &state) {
  switch (state) {
    case DoorState::Closed:
      closed.setHigh();
      openIn.setLow();
      openOut.setLow();
      error.setLow();
      break;
    case DoorState::OpenIn:
      closed.setLow();
      openIn.setHigh();
      openOut.setLow();
      error.setLow();
      break;
    case DoorState::OpenOut:
      closed.setLow();
      openIn.setLow();
      openOut.setHigh();
      error.setLow();
      break;
    default:
      closed.setLow();
      openIn.setLow();
      openOut.setLow();
      error.setHigh();
      break;
  }
}

#endif
