/*
** UC CubeCats
** Project LEOPARD
** On Board Computing
*/

#ifndef PAYLOAD_H
#define PAYLOAD_H

#include "Wire.h"

class Payload {
    public:
        int select_pins[3] = {PAYLOAD_S0_PIN, PAYLOAD_S1_PIN, PAYLOAD_S2_PIN};
        void configureMuxPin(int payload_sensor);
};

#endif
