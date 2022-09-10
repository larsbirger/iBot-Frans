#include "Encoder.h"
#include "Arduino.h"


//constri(u)ctor
Encoder::Encoder(int pinA, int pinB)
{
  anchor = this; // assigning the anchor
  //default -> Forward
  this->_direction = true;
  this->_encoder0pinA = pinA;
  this->_encoder0pinB = pinB;
  pinMode(this->_encoder0pinB,INPUT);
  attachInterrupt(0, Encoder::anchoredWheelSpeed, CHANGE);
}

//anchored WheelSpeed() to place in interrupt
static void Encoder::anchoredWheelSpeed()
{
    anchor->WheelSpeed();
}

Encoder* Encoder::anchor = nullptr;

//acts on wheel movement
void Encoder::WheelSpeed()
{
    int Lstate = digitalRead(this->_encoder0pinA);
  if((this->_encoder0PinALast == LOW) && Lstate==HIGH)
  {
    int val = digitalRead(this->_encoder0pinB);
    if(val == LOW && this->_direction)
    {
      this->_direction = false; //Reverse
    }
    else if(val == HIGH && !this->_direction)
    {
      this->_direction = true;  //Forward
    }
  }
  this->_encoder0PinALast = Lstate;

  if(!this->_direction)  this->_duration++;
  else  this->_duration--;
};

//resets the duration
Encoder::resetDuration()
{
    this->_duration;
};

//return the duration to public
Encoder::duration()
{
    return this->_duration + 0;
};
