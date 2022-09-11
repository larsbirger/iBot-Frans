#include "PID.h"
/* #include "Task.h" */
#include "Encoder.h"
 /* #include "UnspecifiedDatatype.h"*/
#include "protothreads.h"


Encoder encoderA(4,5);
Encoder encoderB(6,7);

void setup()
{
    Serial.begin(57600);//Initialize the serial port
}

void loop()
{
    Serial.print("PulseA:");
    String msg = (String) encoderA.getDuration();
    Serial.print(msg);
    Serial.print(", PulseB:");
    msg = (String) encoderB.getDuration();
    Serial.println(msg);
    delay(100);

}

/*
int taskListLength = 254;
Task tasks[taskListLength];

void cycle()
{
    for (int i = taskListLength; i >= 0; i--)
    {
        tasks[i]->task(time.time);
    }
}
*/
