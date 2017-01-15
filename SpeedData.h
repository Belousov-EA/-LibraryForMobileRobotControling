#ifndef SPEED_DATA
#define SPEED_DATA

#include "DataObject.h"

class SpeedData : DataObject
{
  public:    
    float getAvgSpeed() {return avgSpeed;};
    void setAvgSpeed(float AvgSpeed) {avgSpeed = AvgSpeed;};

     float getDifference() {return difference;};
     void setDifference(float Difference) {difference = Difference;};
  private:
    float avgSpeed;
    float difference;
};
#endif
