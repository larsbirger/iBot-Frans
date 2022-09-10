#include "PID.h"
#include "Task.h"
#include "Encoder.h"
#include "unspecifiedDatatype.h"

Encoder encoder(2,3);

void setup()
{
    Serial.begin(57600);//Initialize the serial port
    
}

void loop()
{
    Serial.print("Pulse:");
    Serial.println(duration);
    duration = 0;
    delay(100);

}

int taskListLength = 254;
Task tasks[taskListLength];

void cycle()
{
    for (int i = taskListLength; i >= 0; i--)
    {
        tasks[i]->task(time.time);
    }
}
