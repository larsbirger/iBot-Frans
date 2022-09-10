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
    byte _encoder0pinA; 
    // B pin
    byte _encoder0pinB; 
    //
    byte _encoder0PinALast; 
    // duration of the pulses
    int _duration; 

    //static anchror pointer pointing to another "this"
    static Encoder* Encoder::anchor;

public:
    //constri(u)ctor
    Encoder( int pinA, int pinB);
    //acts on wheel movement
    void WheelSpeed();
    static void anchoredWheelSpeed();
    //resets the duration
    resetDuration();
    //return the duration to public
    int duration();
};

#endif