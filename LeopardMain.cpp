/*
** UC CubeCats
** Project LEOPARD
** On Board Computing
*/

#include "LeopardMain.h"

void getMuxSelectPins(int* mux_s0, int* mux_s1, int* mux_s2)
{
    *mux_s0 = LEOPARD::Pinout::payload_s0;
    *mux_s1 = LEOPARD::Pinout::payload_s1;
    *mux_s2 = LEOPARD::Pinout::payload_s2;
}
