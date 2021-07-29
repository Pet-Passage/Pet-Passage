#ifndef PET_PASSAGE_HARDWARE_LED_BASE_H_
#define PET_PASSAGE_HARDWARE_LED_BASE_H_

#include <Arduino.h>

class LedBase {
 public:
  virtual void init() = 0;
  virtual void setLow() = 0;
  virtual void setHigh() = 0;

 protected:
  bool mode;
};

#endif
