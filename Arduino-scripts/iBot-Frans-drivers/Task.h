#ifndef Task_h
#define Task_h
#include "time.h"
#include "unspecifiedDatatype.h"

//a generalisation of tasks to be run in a circle buffer
class Task
{
private:
    unsigned long _timeLastRun = 0;
    unsigned long _cycleTime = 0;

public:
    Task();
    unspecifiedDatatype task(unsigned long time = 0);
    virtual unspecifiedDatatype action();
};

#endif