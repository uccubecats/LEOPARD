/*
** UC CubeCats
** Project LEOPARD
** On Board Computing
*/

#include <stdint.h>

namespace LEOPARD
{
    // HAMShield Pins
    // Digital
    const int comms_switch = 2;
    const int comms_MiC = 3;

    // Analog
    const int comms_nCS = A1;
    const int comms_SPKR = 2,
    const int comms_RST = 3,
    const int comms_DAT = 4,
    const int comms_CLK = 5,

    // Payload Pins
    // Digital
    payload_s2 = 4,
    payload_s1 = 5,
    payload_s0 = 6,

    // Analog
    payload_z = 0,

    // SD Board Pins
    // Digital
    sd_cs = 10,
    sd_mosi = 11,
    sd_miso = 12,
    sd_clk = 13

    class LeopardMain
    {
    public:
        void getMuxSelectPins(int *mux_s0, int *mux_s1, int *mux_s2);
    };
}; // namespace LEOPARD
