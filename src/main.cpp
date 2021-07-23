#include <Arduino.h>

#include "led_light_group.hpp"
#include "ports.h"

#define BPS 9600

DoorStateManager<FRONT_MAG_PORT, BACK_MAG_PORT>
    stateManager;  // NOLINT(cert-err58-cpp)

LedLightGroup<OPEN_IN_LED_PORT, CLOSED_LED_PORT, OPEN_OUT_LED_PORT,
              ERROR_LED_PORT>
    ledManager;  // NOLINT(cert-err58-cpp)

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
  ledManager.init();
  Serial.println("Time, State");
}

// cppcheck-suppress unusedFunction
/**
 * @brief Continuously called throught executuion. Used to actively control the
 * board.
 * See https://www.arduino.cc/reference/en/language/structure/sketch/loop/
 */
void loop() {
  stateManager.update();
  stateManager.onChange<0>([](const DoorState &state) {
    Serial.print(millis());
    Serial.print(",");
    Serial.println(static_cast<int>(state));
  });
  stateManager.onChange<1>(
      [](const DoorState &state) { ledManager.updateActive(state); });
}
