#ifndef ANALOG_SENSOR_H
#define ANALOG_SENSOR_H


#include "SensorData.h"
#include "Sensor.h"


template <int sensorCount>
class AnalogSensor : public Sensor
{
  public:
    virtual void call()
    {
      for(int i = 0; i<sensorCount; i++)
      {
        data.setValue(analogRead(sensors[i]), i);
      }
      #ifdef DEBUG_ANALOG_SENSOR
      for( int i = 0; i<8; i++)
      {
        Serial.print(data.getValue(i));
        Serial.print('\t');
      }
      Serial.println();
      #endif
    }


    
    void init(int Sensors[])
    {
      for(int i=0; i<sensorCount; i++)
      {
        sensors[i] = Sensors[i];
      }
      #ifdef DEBUG_ANALOG_SENSOR
        Serial.begin(115200);
      #endif
    }

    SensorData<int, sensorCount>* getDataPtr()
    {
      return &data;
    }
    
  private:
    int sensors[sensorCount];
    SensorData<int, sensorCount> data;
};
#endif
