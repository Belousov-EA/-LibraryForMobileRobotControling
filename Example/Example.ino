//#define DEBUG_ANALOG_SENSOR
//#define DEBUG_EXC
//#define DEBUG_SPEED

#include <SensorData.h>
#include <ExcData.h>
#include <SpeedData.h>
#include <AnalogSensor.h>
#include <ExcAlgorithm.h>
#include <SpeedAlgorithm.h>
#include <Motors.h>


#define SENSOR_COUNT 8

//initialization
  AnalogSensor<8> sensor;
  ExcAlgorithm<8> excAlgorithm;
  SpeedAlgorithm speedAlgorithm;
  Motors motors;


int sensors[SENSOR_COUNT] = {7, 6, 5, 4, 3, 2, 1, 0};
int white[SENSOR_COUNT]= {56,  48,  48,  45,  44,  44,  45,  50}; 
int black[SENSOR_COUNT]= {579,  482, 531, 500, 398, 487, 518, 618 };

float p = 1.5;
float d = 3.;
float midSpeed = 0.9;


void setup()
{  
  //init
    sensor.init(sensors);
    excAlgorithm.init(white, black);
    speedAlgorithm.init(p, d, midSpeed, 50);
    motors.init(5, 4, true, 6, 7, true);
    
  //get references
    excAlgorithm.setSensorDataPtr(sensor.getDataPtr());
    speedAlgorithm.setExcDataPtr(excAlgorithm.getDataPtr());
    motors.setSpeedDataPtr(speedAlgorithm.getDataPtr());
}

void loop() 
{
  //main process
    sensor.call();
    excAlgorithm.call();
    speedAlgorithm.call();
    motors.call();
}


