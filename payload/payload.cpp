/*
** UC CubeCats
** Project LEOPARD
** On Board Computing
*/

#include "payload.h"

void Payload::configureMuxPin(int payload_sensor)
{
    for (int i = 0; i <= 3; i++)
    {
        if (payload_sensor & (1<<i))
            digitalWrite(select_pins[i], HIGH);
        else
            digitalWrite(select_pins[i], LOW);
    }
}