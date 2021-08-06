#ifndef PET_PASSAGE_COUTER_COUNTER_H_
#define PET_PASSAGE_COUTER_COUNTER_H_

#include <Arduino.h>

class Counter {
  Counter();
  void updateCount();
  void setMaxCount(uint8_t maxCount);
  uint8_t getInsideCount();
  uint8_t getOutsideCount();
  uint8_t insideCount;
  uint8_t outsideCount;
  uint8_t maxCount;
};

#endif
