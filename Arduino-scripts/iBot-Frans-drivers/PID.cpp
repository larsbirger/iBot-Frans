#include "Arduino.h"
#include "PID.h"

PID::PID(
    signed double kP = 0.0,
    signed double kI = 0.0,
    signed double kD = 0.0
)
{
    this._kP = kP;
    this._kI = kI;
    this._kD = kD;
}
        
PID::set(signed double setValue)
{
    this._setValue = setValue;
}
