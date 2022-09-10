#ifndef PID_h

#define PID_h
#include "Arduino.h"



class PID
{
    private:
        signed double _kP;
        signed double _kI;
        signed double _kd;
        unsigned double _setValue;

    public:
        PID(
            signed double kP = 0.0,
            signed double kI = 0.0,
            signed double kD = 0.0
        );
        updateOn(unsigned double getValue);
        set(unsigned double setValue);
        get();
        currentError();
}
#endif