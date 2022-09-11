#ifndef Encoder_h
#define Encoder_h

#include "Arduino.h"

//a class to handle the wheel engine encoder
class Encoder 
{
private:
    //rotation direction
    bool _direction; 
    //the A pin
    byte _encoder0pinA; 
    //the B pin
    byte _encoder0pinB; 
    //last state of the A pin
    byte _encoder0PinALast; 
    //duration of the pulses
    int _duration; 

    //static anchror pointer pointing to another "this"
    static Encoder* Encoder::anchor;

public:
    //constri(u)ctor
    Encoder( int pinA, int pinB);
    //function for how the encoder acts on wheel displacement
    void WheelSpeed();
    //anchored WheelSpeed() to place in interrupt
    static void anchoredWheelSpeed();
    //resets the duration
    resetDuration();
    //get the duration
    int getDuration();
};

#endif