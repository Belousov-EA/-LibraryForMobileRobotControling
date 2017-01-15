#ifndef SENSOR_H
#define SENSOR_H

#include <Arduino.h>

class Sensor
{
  public:
    virtual void call() = 0;
};
#endif
