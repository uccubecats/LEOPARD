/*
** UC CubeCats
** Project LEOPARD
** On Board Computing
*/

#include <stdint.h>

namespace LEOPARD
{
    /******************** Digital Pinout ********************/
    
    // HAMShield
    const int comms_switch = 2;
    const int comms_MiC = 3;

    // Payload
    const int payload_s2 = 4;
    const int payload_s1 = 5;
    const int payload_s0 = 6;

    // SD Board
    const int sd_cs = 10;
    const int sd_mosi = 11;
    const int sd_miso = 12;
    const int sd_clk = 13;

    /******************** Analog Pinout ********************/

    // Payload
    const int payload_z = 14;
    
    // HamShield
    const int comms_nCS = 15;
    const int comms_SPKR = 16;
    const int comms_RST = 17;
    const int comms_DAT = 18;
    const int comms_CLK = 19;

    /******************** Functions ********************/

    void getMuxSelectPins(int *mux_s0, int *mux_s1, int *mux_s2);

};
