/*
** UC CubeCats
** Project LEOPARD
** On Board Computing
*/

#ifndef LEOPARD_COMMON_H
#define LEOPARD_COMMON_H

#include <stdint.h>
#include <list>

/******************** Digital Pinout ********************/

//Hamshield
#define COMMS_SWITCH_PIN    2
#define COMMS_MiC_PIN       3

// Payload
#define PAYLOAD_S2_PIN      4
#define PAYLOAD_S1_PIN      5
#define PAYLOAD_S0_PIN      6

// SD Board
#define SD_CS_PIN           10
#define SD_MOSI_PIN         11
#define SD_MISO_PIN         12
#define SD_CLK_PIN          13

/******************** Analog Pinout ********************/

// Payload
#define PAYLOAD_Z_PIN       A0
    
// HamShield
#define COMMS_nCS_PIN       A1
#define COMMS_SPKR_PIN      A2
#define COMMS_RST_PIN       A3
#define COMMS_DAT           A4
#define COMMS_CLK           A5

class LEOPARDCommon
{
    // Return list of selector pin values for MUX: {s0, s1, s2}
    std::list<int> getMuxSelectPins() {std::list<int> list({PAYLOAD_S0_PIN, PAYLOAD_S1_PIN, PAYLOAD_S2_PIN}); return list;};
};

#endif
