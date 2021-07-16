#include <Arduino.h>

#include "door_fsm.hpp"
#include "ports.h"

#define BPS 9600

DoorStateManager<FRONT_MAG_PORT, BACK_MAG_PORT> stateManager;  // NOLINT(cert-err58-cpp)

void setLED(DoorState &state) {
  switch (state) {
    case DoorState::Closed:
      digitalWrite(CLOSED_LED_PORT, HIGH);
      digitalWrite(OPEN_IN_LED_PORT, LOW);
      digitalWrite(OPEN_OUT_LED_PORT, LOW);
      digitalWrite(ERROR_LED_PORT, LOW);
      break;
    case DoorState::OpenIn:
      digitalWrite(CLOSED_LED_PORT, LOW);
      digitalWrite(OPEN_IN_LED_PORT, HIGH);
      digitalWrite(OPEN_OUT_LED_PORT, LOW);
      digitalWrite(ERROR_LED_PORT, LOW);
      break;
    case DoorState::OpenOut:
      digitalWrite(CLOSED_LED_PORT, LOW);
      digitalWrite(OPEN_IN_LED_PORT, LOW);
      digitalWrite(OPEN_OUT_LED_PORT, HIGH);
      digitalWrite(ERROR_LED_PORT, LOW);
      break;
    default:
      digitalWrite(CLOSED_LED_PORT, LOW);
      digitalWrite(OPEN_IN_LED_PORT, LOW);
      digitalWrite(OPEN_OUT_LED_PORT, LOW);
      digitalWrite(ERROR_LED_PORT, HIGH);
      break;
  }
}

// cppcheck-suppress unusedFunction
/**
 * @brief Called when the program starts. Initializes variables, pin modes,
 * start using libraries, etc. Only runs once, after each powerup or reset of
 * the board.
 * See https://www.arduino.cc/reference/en/language/structure/sketch/setup/
 */
void setup() {
  Serial.begin(BPS);
  while (!Serial) {
  }
  stateManager.init();
  pinMode(CLOSED_LED_PORT, OUTPUT);
  pinMode(OPEN_IN_LED_PORT, OUTPUT);
  pinMode(OPEN_OUT_LED_PORT, OUTPUT);
  pinMode(ERROR_LED_PORT, OUTPUT);
}

// cppcheck-suppress unusedFunction
/**
 * @brief Continuously called throught executuion. Used to actively control the
 * board.
 * See https://www.arduino.cc/reference/en/language/structure/sketch/loop/
 */
void loop() {
  stateManager.update();
  stateManager.onChange<0>(
      [](DoorState &state) { Serial.println(static_cast<int>(state)); });
  stateManager.onChange<1>(&setLED);
}
