#ifndef FlowRate_h
#define FlowRate_h

#include "Arduino.h"

class FlowRate
{
	public:
		FlowRate();               //Constructor(flowSensPin is assumed 2, calFactor is assumed 1)
	
		void begin();  // This attaches the interupt to the pin and method
		unsigned long startInterMeas();  //Called to when one would like to start an intermediated flow rate measurment						
		float getInterFlowRate();  //Called to get an intermediated flow rate meesurement you have to called
											//startInterMeas() before calling this again as it is the start
		
		
	private:
		static void marshall();  //The method that calls the right instance of the ISR (flowCountInc())
		void flowCountInc();	//Increments the counter.  This is called by the marshall when the interupt
									// flowSensPin RISING occurs
		int _flowSensPin;  //The pin used to flow rate seen by the hall effect sensor (must be interuptable)
		float _calFactor;  //mulitply this times the number of counts to get the amount of fluid in volume (your choice) per second
		volatile  unsigned long _flowCount;  //This is the counter that hold the number of times the hall effect tranducer has signalled
		static FlowRate* FlowRate::anchor; //this allows marshall() to call the right flowCountInc().
		unsigned long _flowCountInter;  //This is used to remember the count when an intermeditat flowRate may be requested
		unsigned long _startIntMeasTime;  //This is the time used to start the intermediate measurment of fluid volume
		
};

#endif