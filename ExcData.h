#ifndef EXC_DATA
#define EXC_DATA

#include "DataObject.h"

class ExcData : public DataObject
{
  public:
    
    float getExc(){return exc;};
    void setExc(float Exc){exc = Exc;};
    
    float getDarks(){return darks;};
    void setDarks(float Darks){darks = Darks;};

    float getValid() {return valid;};
    void setValid(float Valid){valid = Valid;};

    unsigned long getExcTime() {return excTime;};
    void setExcTime(unsigned long ExcTime) {excTime = ExcTime;};

    unsigned long getLastTime() {return lastTime;};
    void setLastTime(unsigned long LastTime){lastTime = LastTime;};
  private:
    float exc;
    float darks;
    float valid;
    unsigned long excTime;
    unsigned long lastTime;
};

#endif
