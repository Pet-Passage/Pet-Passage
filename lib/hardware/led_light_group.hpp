#ifndef PET_PASSAGE_HARDWARE_LED_LIGHT_GROUP_H_
#define PET_PASSAGE_HARDWARE_LED_LIGHT_GROUP_H_

#include "door_fsm.hpp"
#include "led.hpp"

template <uint8_t OI, uint8_t C, uint8_t OO, uint8_t E>
class LedLightGroup final {
 public:
  void init();
  void updateActive(const DoorState& state);

 private:
  Led<OI> openIn;
  Led<C> closed;
  Led<OO> openOut;
  Led<E> error;
  LedBase* current{nullptr};
};

#include "led_light_group.ipp"

#endif
