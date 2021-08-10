#ifndef PET_PASSAGE_COUTER_COUNTER_H_
#define PET_PASSAGE_COUTER_COUNTER_H_

#include "Arduino.h"

#include "door_fsm.hpp"
#include "lcd.hpp"

class Counter {
 public:
  Counter();
  Counter(uint8_t max);
  void updateCount(const DoorState &state);
  void setMaxCount(uint8_t maxCount);
  uint8_t getInsideCount();
  uint8_t getOutsideCount();
  void outputToScreen();

 private:
  uint8_t insideCount;
  uint8_t outsideCount;
  uint8_t maxCount;
  unsigned long lastTime;
  DoorState lastState;
  Lcd screen;
};

#include "counter.ipp"

#endif
