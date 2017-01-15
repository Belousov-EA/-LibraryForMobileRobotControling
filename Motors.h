#ifndef MOTORS_H
#define MOTORS_H

#include "Actuator.h"

class SpeedData;

class Motors : public Actuator
{
  public:
    void init(int lp, int ld, bool lf, int rp, int rd, bool rf)
    {
      rightPowerPin = rp;
      rightDirectionPin = rd;
      rightForward = rf;
      leftPowerPin = lp;
      leftDirectionPin = ld;
      leftForward = lf;
    }
    
    virtual void call()
    {
      right = speedData->getAvgSpeed()*(1-speedData->getDifference());
      left = speedData->getAvgSpeed()*(1+speedData->getDifference());
      if((right>0)==rightForward)
      {
        digitalWrite(rightDirectionPin, LOW);
      }else
      {
        digitalWrite(rightDirectionPin, HIGH);
      }
      if ((left>0)==leftForward)
      {
        digitalWrite(leftDirectionPin, LOW);
      }else
      {
        digitalWrite(leftDirectionPin, HIGH);
      }
      analogWrite(rightPowerPin, int(constrain(abs(right*255), 0, 255)) );
      analogWrite(leftPowerPin, int(constrain(abs(left*255), 0, 255)) );
    }
    
    void setSpeedDataPtr(SpeedData* data)
    {
      speedData = data;
    }
  private:
    float right;
    float left;
    SpeedData*speedData;
    int leftPowerPin;
    int rightPowerPin;
    int leftDirectionPin;
    int rightDirectionPin;
    bool leftForward;
    bool rightForward;
};

#endif
