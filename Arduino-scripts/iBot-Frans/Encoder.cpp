#include "Encoder.h"
#include "Arduino.h"

//sets the anchor to default to a nullpointer cause
//c++ doesnt like dynamic typing... god i despise fishtyping
Encoder* Encoder::anchor = nullptr;

//constri(u)ctor
Encoder::Encoder(int pinA, int pinB)
{
  anchor = this; // assigning the anchor
  this->_direction = true; //default -> Forward
  this->_encoder0pinA = pinA;
  this->_encoder0pinB = pinB;
  pinMode(this->_encoder0pinB,INPUT);
  attachInterrupt(0, Encoder::anchoredWheelSpeed, CHANGE);
}

//anchored WheelSpeed() to place in interrupt
static void Encoder::anchoredWheelSpeed()
{
  anchor->WheelSpeed(); //yes this does plain and simply call the
                        //wheelSpeed() method from itsel through a pointer
}

//function for how the encoder acts on wheel displacement
void Encoder::WheelSpeed()
{
  // current state of the A pin
  int Lstate = digitalRead(this->_encoder0pinA);

  /*explanation of if block:
  *if the state of the A pin goes from LOW to HIGH,
    *if the state of the B pin is LOW,
      toggle the direction of rotation
  */
  if((this->_encoder0PinALast == LOW) && Lstate==HIGH)
  {
    //current state of the B pin
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
  
  this->_encoder0PinALast = Lstate; // stores the state of the A pin for next time

  /*explanation of if block:
  *if the direction is false,
    *increment duration by one
  *else
    *decrement duration by one
  */
  if(!this->_direction)  this->_duration++;
  else  this->_duration--;
};

//reset the duration
Encoder::resetDuration()
{
    this->_duration = 0;  //yes, i should make this a public variable,
                          //but in case i need housekeeping i'm still
                          //keeping this in a "get" and "set" (in this time "reset")
};

//get the duration
Encoder::getDuration()
{
    return this->_duration;
};
