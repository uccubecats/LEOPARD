/*
** UC CubeCats
** Project LEOPARD
** On Board Computing
*/

#ifndef PACKET_H
#define PACKET_H

#include <stdint.h>

class packet
{
public:
    enum command_type {
        power_mode_change,
        hamshield_mode_change,
        release_antenna,
        clear_queue,
        data_frequency_change,
        set_time,
        reboot_system,
        end_of_life
    };

    uint8_t* getHeartBeatPacket(/*TODO*/);
    uint8_t* getDataPacket(/*TODO*/);
    
    uint8_t* getTLV(uint8_t* value);   // TODO
    uint8_t* calculateLength(uint8_t* value);
};

#endif
