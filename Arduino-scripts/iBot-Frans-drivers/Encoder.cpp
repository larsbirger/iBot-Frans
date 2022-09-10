#include "Encoder.h"
#include "Arduino.h"


Encoder::Encoder(int pinA, int pinB)
{
    
  this->_direction = true;//default -> Forward
  this->_encoder0pinA = pinA;
  this->_encoder0pinB = pinB;
  pinMode(this->_encoder0pinB,INPUT);
  attachInterrupt(0, this->wheelSpeed, CHANGE);
}

Encoder::WheelSpeed()
{
    int Lstate = digitalRead(this->encoder0pinA);
  if((this->encoder0PinALast == LOW) && Lstate==HIGH)
  {
    int val = digitalRead(this->encoder0pinB);
    if(val == LOW && this->_direction)
    {
      this->_direction = false; //Reverse
    }
    else if(val == HIGH && !this->_direction)
    {
      this->_direction = true;  //Forward
    }
  }
  this->encoder0PinALast = Lstate;

  if(!this->_direction)  this->_duration++;
  else  this->_duration--;
}