#ifndef Encoder_h
#define Encoder_h

#include "Arduino.h"

//a class to handle the wheel engine encoder
class Encoder 
{
private:
    //rotaion direction
    bool _direction; 
    // A pin
    const byte _encoder0pinA; 
    // B pin
    const byte _encoder0pinB; 
    //
    byte _encoder0PinALast; 
    // duration of the pulses
    int _duration; 

public:
    //constri(u)ctor
    Encoder( int pinA, int pinB);
    //acts on wheel movement
    void WheelSpeed();
    //resets the duration
    void resetDuration();
    //return the duration to public
    int duration();
};

#endif