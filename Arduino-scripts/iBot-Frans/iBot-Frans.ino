#include "PID.h"
/* #include "Task.h" */
#include "Encoder.h"
 /* #include "UnspecifiedDatatype.h"*/
#include "protothreads.h"


Encoder encoderA(4,5);
Encoder encoderB(6,7);

pt ptEncoder;

void setup()
{
    Serial.begin(57600);//Initialize the serial port
    PT_INIT(&ptEncoder);
}

void loop()
{
    PT_SCHEDULE(encoderThread(&ptEncoder));
}

int encoderThread(struct pt* pt)
{
    PT_BEGIN(pt);
    for (;;)
    {
        Serial.print("PulseA:");
        String msg = (String) encoderA.getDuration();
        Serial.print(msg);
        Serial.print(", PulseB:");
        msg = (String) encoderB.getDuration();
        Serial.println(msg);
        PT_SLEEP(pt,100);
    }
    PT_END(pt);
}