#ifndef Encoder_h
#define Encoder_h

#include "Arduino.h"

class Encoder
{
private:
    bool _direction; //rotaion direction
    const byte _encoder0pinA; // A pin
    const byte _encoder0pinB; // B pin
    byte _encoder0PinALast; 
    int _duration; // duration of the pulses

public:
    Encoder( int pinA, int pinB);
    void WheelSpeed();
};

#endif