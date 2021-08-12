#ifndef PET_PASSAGE_COUTER_COUNTER_I_
#define PET_PASSAGE_COUTER_COUNTER_I_

#include "counter.hpp"

Counter::Counter() {
  insideCount = 1;
  outsideCount = 0;
  maxCount = 1;
  lastTime = millis();
  lastState = DoorState::Closed;
  screen.init();
}

Counter::Counter(uint8_t max) {  // overloaded constructor for a starting max
  insideCount = max;
  outsideCount = 0;
  maxCount = max;
  lastTime = millis();
  lastState = DoorState::Closed;
  screen.init();
}

void Counter::updateCount(const DoorState &state) {
  switch (state) {
    case DoorState::Closed:
      if ((millis() - lastTime) < 2000 && (millis() - lastTime) > 5 &&
          (outsideCount + insideCount) <= maxCount &&
          (outsideCount + insideCount) >= 1 && lastState == DoorState::OpenIn) {
        insideCount++;
        outsideCount--;
      } else if ((millis() - lastTime) < 2000 && (millis() - lastTime) > 5 &&
                 (outsideCount + insideCount) <= maxCount &&
                 (outsideCount + insideCount) >= 1 &&
                 lastState == DoorState::OpenOut) {
        insideCount--;
        outsideCount++;
      } else {
        Serial.println("Problem");
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
      Serial.print("uh oh");
      break;
  }
}

void Counter::setMaxCount(uint8_t maxCount) { this->maxCount = maxCount; }

uint8_t Counter::getInsideCount() { return this->insideCount; }

uint8_t Counter::getOutsideCount() { return this->outsideCount; }

void Counter::outputToScreen() {
  screen.updateScreen(insideCount, outsideCount);
}

#endif
