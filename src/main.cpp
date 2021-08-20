#include <Arduino.h>

#include "door_fsm.hpp"
#include "ports.h"
#include "rgb_led.hpp"

#define BPS 9600
#define HIGH_LED 255

DoorStateManager<FRONT_MAG_PORT, BACK_MAG_PORT>
    stateManager;  // NOLINT(cert-err58-cpp)

RgbLed<RGB_LED_R_PORT, RGB_LED_G_PORT, RGB_LED_B_PORT>
    lightManager;  // NOLINT(cert-err58-cpp)

void setLED(const DoorState &state) {  // takes state and sets the RGB LED color
  switch (state) {
    case DoorState::Closed:
      lightManager.setColor(0, HIGH_LED, 0);
      break;
    case DoorState::OpenIn:
      lightManager.setColor(HIGH_LED, HIGH_LED, 0);
      break;
    case DoorState::OpenOut:
      lightManager.setColor(0, 0, HIGH_LED);
      break;
    default:
      lightManager.setColor(HIGH_LED, 0, 0);
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
  lightManager.init();

  setLED(stateManager.getState());

  Serial.println("Time, Data");
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
  stateManager.onChange<1>(&setLED);
}
