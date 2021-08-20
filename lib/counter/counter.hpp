#ifndef PET_PASSAGE_COUTER_COUNTER_H_
#define PET_PASSAGE_COUTER_COUNTER_H_

#include "Arduino.h"
#include "door_fsm.hpp"
#include "lcd.hpp"
#include "ports.h"

class Counter {
 public:
  Counter();
  Counter(uint8_t max);
  void updateCount(const DoorState &state);
  void setMaxCount(uint8_t maxCount);
  void outputToScreen();
  uint8_t getOutsideCount();
  uint8_t getInsideCount();

 private:
  uint8_t insideCount;
  uint8_t outsideCount;
  uint8_t maxCount;
  unsigned long lastTime;
  DoorState lastState;
  Lcd<RS_SCREEN_PORT, E_SCREEN_PORT, D4_SCREEN_PORT, D5_SCREEN_PORT,
      D6_SCREEN_PORT, D7_SCREEN_PORT>
      screen;
};

#include "counter.ipp"

#endif
