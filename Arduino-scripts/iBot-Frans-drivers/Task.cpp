#include "Task.h"
#include "unspecifiedDatatype.h"

Task::Task()
{
    this->_timeLastRun = 0;
    this->_cycleTime = 0;
};
unspecifiedDatatype Task::task(unsigned long time)
{
    if (time - this->_timeLastRun >= this->_cycleTime)
    {
        return this->action()
    }
};
unspecifiedDatatype Task::action(){};