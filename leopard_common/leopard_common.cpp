/*
** UC CubeCats
** Project LEOPARD
** On Board Computing
*/

#include "leopard_common.h"

void getMuxSelectPins(int* mux_s0, int* mux_s1, int* mux_s2)
{
    *mux_s0 = LEOPARD::payload_s0;
    *mux_s1 = LEOPARD::payload_s1;
    *mux_s2 = LEOPARD::payload_s2;
}
