#ifndef ACTUATOR_H
#define ACTUATOR_H

#include <Arduino.h>

class Actuator
{
  public:
    virtual void call() = 0;
};

#endif
