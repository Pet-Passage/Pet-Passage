#include <Arduino.h>

#include "magnetic_sensor_pair.hpp"
#include "ports.h"

#define BPS 9600

enum class MagState { Closed = 1, OpenOut = 0, OpenIn = -1 };

MagneticSensorPair<FRONT_MAG_PORT, BACK_MAG_PORT, MagState>
    sensor;  // NOLINT(cert-err58-cpp)

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
  sensor.updateState();

  Serial.println(static_cast<int>(sensor.getState()));

  switch (sensor.getState()) {
    case MagState::Closed:
      digitalWrite(CLOSED_LED_PORT, HIGH);
      digitalWrite(OPEN_IN_LED_PORT, LOW);
      digitalWrite(OPEN_OUT_LED_PORT, LOW);
      digitalWrite(ERROR_LED_PORT, LOW);
      break;
    case MagState::OpenIn:
      digitalWrite(CLOSED_LED_PORT, LOW);
      digitalWrite(OPEN_IN_LED_PORT, HIGH);
      digitalWrite(OPEN_OUT_LED_PORT, LOW);
      digitalWrite(ERROR_LED_PORT, LOW);
      break;
    case MagState::OpenOut:
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
