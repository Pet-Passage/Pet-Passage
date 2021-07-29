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
  current->setLow();
  switch (state) {
    case DoorState::Closed:
      closed.setHigh();
      current = &closed;
      break;
    case DoorState::OpenIn:
      openIn.setHigh();
      current = &openIn;
      break;
    case DoorState::OpenOut:
      openOut.setHigh();
      current = &openOut;
      break;
    default:
      error.setHigh();
      current = &error;
      break;
  }
}

#endif
