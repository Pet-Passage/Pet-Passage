#ifndef PET_PASSAGE_COUTER_COUNTER_H_
#define PET_PASSAGE_COUTER_COUNTER_H_

#include "Arduino.h"
#include "door_fsm.hpp"
#include "lcd.hpp"
#include "ports.h"
#include "string.h"

class Counter {
 public:
  Counter();
  explicit Counter(uint8_t max);
  void updateCount(const DoorState &state);
  void setMaxCount(uint8_t maxCount);
  void outputToScreen();
  int getOutsideCount();
  int getInsideCount();

 private:
  int insideCount;
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
