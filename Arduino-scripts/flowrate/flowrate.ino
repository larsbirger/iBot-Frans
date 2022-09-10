#include "FlowRate.h"

FlowRate flowSens1;  //Create a flow rate sensor.

unsigned long restFlRtFreq = 0;  //The time the Flow rate was last checked.
int checkFlRtFreq = 2000;  //This is how often we want to get the flow rate for an intermediate check

void setup() 
{
  Serial.begin(9600);  //Start Serial
  Serial.println("<Arduino Ready...>");

  flowSens1.begin();  
  restFlRtFreq = flowSens1.startInterMeas();
}

void loop() 
{
  if(millis()-restFlRtFreq > checkFlRtFreq)  //if 2 seconds have gone by 
  {
    Serial.print("Intermediate Flow Rate Measurement is:");Serial.print(flowSens1.getInterFlowRate());  //print out the intermediate flow rate.
    restFlRtFreq = flowSens1.startInterMeas();  //Reset the intermediate measuremnt start time as well as when we come back into this if statement
  }
  
}