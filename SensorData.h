#ifndef SENSOR_DATA_H
#define SENSOR_DATA_H

#include "DataObject.h"

template <class outData, int sensorCount>
class SensorData : public DataObject
{
  public:
    
    int getSensorCount() const
    {return sensorCount;};
    
    outData getValue(int num) {return sensors[num];};
    outData getValue() {return sensors[0];};
    
    void setValue(outData value, int num) {sensors[num] = value;};
    void setValue(outData value) {sensors[0] = value;};
  private:
    outData sensors[sensorCount];   
};
#endif
