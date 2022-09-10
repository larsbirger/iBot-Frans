#include "Arduino.h"
#include "FlowRate.h"

FlowRate::FlowRate()
{
	anchor = this;
	_flowSensPin = 2;  //The pin used to flow rate seen by the hall effect sensor (must be interuptable
	_calFactor = 1.0;  //mulitply this times the number of counts to get the amount of fluid in volume (your choice) per second
	_flowCount = 0;  //The number of times the hall effect tranducer has sent a pulse
	_flowCountInter = 0; //the count start for an intermediate flow rate request
	
	pinMode(_flowSensPin, INPUT);           //Sets the pin as an input
}

void FlowRate::begin()   //This needs to be called to cause the pin to be linked to the Interupt
{
	char irqNum = digitalPinToInterrupt(_flowSensPin);  //If 2 is passed and you are compiling for an UNO you irqNum should be 0.
	if (irqNum != NOT_AN_INTERRUPT) 
	{  
		EIFR = bit(irqNum);         // cancel evt. pending interrupt
		attachInterrupt(irqNum, FlowRate::marshall, CHANGE); //Configures interruptpin 0 (pin 2 on the Arduino Uno) to run the function 
	}
}
static void FlowRate::marshall()
{
	anchor->flowCountInc();
}

FlowRate* FlowRate::anchor = nullptr;
					

unsigned long FlowRate::startInterMeas()  //Called to when one would like to start an intermediated 
{										//flow rate measurment
	_startIntMeasTime = millis();			
	noInterrupts(); 					//Disable the interrupts on the Arduino	
	_flowCountInter = _flowCount;
	interrupts();	//inable the interrupts on the Arduino	
	return _startIntMeasTime;
}

float FlowRate::getInterFlowRate()	//Called to get an intermediated flow rate measurment
{											
	unsigned long now = millis();
	float flowRate;
	noInterrupts(); //Disable the interrupts on the Arduino	
	flowRate = ((float(_flowCount)-float(_flowCountInter)) * _calFactor)/(float(now - _startIntMeasTime)/1000.0);	//Calcualate the flow rate
	interrupts();	//inable the interrupts on the Arduino	
	_startIntMeasTime = now;  //Update the start time for intermediate flowrate inquiziations.
	return flowRate;
}

void FlowRate::flowCountInc()	//This is used to increment the _flowCount variable
{   
	_flowCount++;
}