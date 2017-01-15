#ifndef SPEED_ALGORITHM_H
#define SPEED_ALGORITHM_H

#include "Algorithm.h"
#include "SpeedData.h"

class ExcData;

class SpeedAlgorithm : public Algorithm
{
  public:
    void init(float P, float D, float MidSpeed, unsigned long VozvratTime)
    {
      p = P;
      d = D;
      midSpeed = MidSpeed;
      vozvratTime = VozvratTime;
      #ifdef DEBUG_SPEED
      Serial.begin(115200);
      #endif
    }
    
    virtual void call()
    {
      if(excData->getDarks()!=0)
      {
        data.setDifference ( excData -> getExc()*p+(excData -> getExc()-lastExc)*d/(excData->getExcTime() - lastTime));
    
        lastTime = excData->getExcTime();
        lastExc = excData->getExc();
        data.setAvgSpeed(midSpeed);
      }else
      {
        vozvrat();
      }      
      #ifdef DEBUG_SPEED
      Serial.print("avgSpeed ");
      Serial.print(data.getAvgSpeed());
      Serial.print(" , difference ");
      Serial.println(data.getDifference()); 
      #endif  
    }

    
    
    void setExcDataPtr(ExcData* data)
    {
      this -> excData = data;
    }

    SpeedData* getDataPtr()
    {
      return &data;
    }
    
  private:
    void vozvrat()
    {
      if(excData->getExcTime()-excData->getLastTime()>vozvratTime)
      {
        if(excData->getValid()>0)
        {
          data.setDifference(p);
          lastExc = 1.00;
        }else
        {
          data.setDifference(-p);
          lastExc = -1.00;
        }
        data.setAvgSpeed(midSpeed);
      }
      if(excData -> getExcTime() - excData -> getLastTime()>100)
      {
        data.setAvgSpeed(0.00);
        data.setDifference(0.00);
      }
    }
    
    float p;
    float d;
    float midSpeed;
    unsigned long vozvratTime;
    ExcData* excData;
    float lastExc;
    unsigned long lastTime;
    SpeedData data;
};

#endif
