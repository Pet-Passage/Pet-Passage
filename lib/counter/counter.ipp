#ifndef PET_PASSAGE_COUTER_COUNTER_I_
#define PET_PASSAGE_COUTER_COUNTER_I_

#include "counter.hpp"

Counter::Counter() {
  maxCount = 1;
  insideCount = maxCount;
  outsideCount = 0;
  lastTime = millis();
  lastState = DoorState::Closed;
  screen.init();
}

Counter::Counter(uint8_t max) {  // overloaded constructor for a starting max
  maxCount = max;
  insideCount = max;
  outsideCount = 0;
  lastTime = millis();
  lastState = DoorState::Closed;
  screen.init();
}

void Counter::updateCount(const DoorState &state) {
  switch (state) {
    case DoorState::Closed:
      if ((millis() - lastTime) < 300000 && (millis() - lastTime) > 400 &&
          outsideCount != 0 && ((outsideCount - 1) + (insideCount + 1)) >= 1 &&
          lastState == DoorState::OpenIn) {
        insideCount++;
        outsideCount--;
      } else if ((millis() - lastTime) < 300000 &&
                 (millis() - lastTime) > 400 && insideCount != 0 &&
                 ((outsideCount + 1) + (insideCount - 1)) >= 1 &&
                 lastState == DoorState::OpenOut) {
        insideCount--;
        outsideCount++;
      } else {
        Serial.println("Closed, no condition reached");
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
      Serial.print("State, no condition reached");
      break;
  }
}

void Counter::setMaxCount(uint8_t maxCount) { this->maxCount = maxCount; }

uint8_t Counter::getInsideCount() { return this->insideCount; }

uint8_t Counter::getOutsideCount() { return this->outsideCount; }

void Counter::outputToScreen() {
  //screen.updateScreen(insideCount, outsideCount);
}

#endif
