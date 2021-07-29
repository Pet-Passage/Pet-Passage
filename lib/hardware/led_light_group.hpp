#ifndef PET_PASSAGE_HARDWARE_LED_LIGHT_GROUP_H_
#define PET_PASSAGE_HARDWARE_LED_LIGHT_GROUP_H_

#include "door_fsm.hpp"
#include "led_light.hpp"

template <uint8_t OI, uint8_t C, uint8_t OO, uint8_t E>
class LedLightGroup {
 public:
  void init();
  void updateActive(const DoorState& state);

 private:
  LedLight<OI> openIn;
  LedLight<C> closed;
  LedLight<OO> openOut;
  LedLight<E> error;
  LedBase* current{nullptr};
};

#include "led_light_group.ipp"

#endif
