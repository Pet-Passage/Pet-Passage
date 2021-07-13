#include <Arduino.h>

#include "magnetic_sensor_pair.hpp"

#define BPS 9600

enum class MagState { Closed = 1, OpenOut = 0, OpenIn = -1 };

MagneticSensorPair<2, 3, MagState> sensor;


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
  sensor.init();
}

// cppcheck-suppress unusedFunction
/**
 * @brief Continuously called throught executuion. Used to actively control the
 * board.
 * See https://www.arduino.cc/reference/en/language/structure/sketch/loop/
 */
void loop() {
  sensor.updateState();

  switch (sensor.getState())
  {
  case MagState::Closed:
    Serial.println("MagState: Closed");
    break;
  case MagState::OpenOut:
    Serial.println("MagState: Open (Out)");
    break;
  case MagState::OpenIn:
    Serial.println("MagState: Open (In)");
    break;
  default:
    Serial.println("MagState: INVALID!");
    break;
  }
}
