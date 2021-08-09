#ifndef PET_PASSAGE_COUTER_COUNTER_I_
#define PET_PASSAGE_COUTER_COUNTER_I_

#include "counter.hpp"

Counter::Counter() {
  insideCount = 0;
  outsideCount = 0;
  maxCount = 0;
  lastTime = millis();
  lastState = DoorState::Closed;
}

Counter::Counter(uint8_t max) {  // overloaded constructor for a starting max
  insideCount = 0;
  outsideCount = 0;
  maxCount = max;
  lastTime = millis();
  lastState = DoorState::Closed;
}

void Counter::updateCount(const DoorState &state) {
  switch (state) {
    case DoorState::Closed:
      if (millis() - lastTime < 200 && millis() - lastTime > 5 && lastState == DoorState::OpenIn) {
        insideCount++;
        outsideCount--;
      } else if (millis() - lastTime < 200 && millis() - lastTime > 5 && lastState == DoorState::OpenOut) {
        insideCount--;
        outsideCount++;
      }
      lastTime = millis();
      break;
    case DoorState::OpenIn:
      lastState = DoorState::OpenIn;
      lastTime = millis();
      break;
    case DoorState::OpenOut:
      lastState = DoorState::OpenOut;
      lastTime = millis();
      break;
    default:
      break;
  }
}

void Counter::setMaxCount(uint8_t maxCount) { this->maxCount = maxCount; }

uint8_t Counter::getInsideCount() { return this->insideCount; }

uint8_t Counter::getOutsideCount() { return this->outsideCount; }

#endif
