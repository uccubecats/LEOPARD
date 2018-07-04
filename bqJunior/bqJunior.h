/*
** UC CubeCats
** Project LEOPARD
** On Board Computing
*/

#ifndef bqJunior_h
#define bqJunior_h

#include <stdint.h>

class bqJunior
{
public:
    // Define register address values for sensor
    //All values are the first register of a pair, unless a single register denoted otherwise
    enum bqAddr: uint8_t
    {
        CONTROL_ADDR = 0x00,                // Single register value
        MODE_ADDR = 0x01,                   // Single register value
        AT_RATE_ADDR = 0x02,
        AT_RATE_TIME_EMPTY_ADDR = 0x04,
        TEMPERATURE_ADDR = 0x06,
        BATTERY_VOLT_ADDR = 0x08,
        STATUS_FLAG_ADDR = 0x0A,            // Single register value
        RSOC_ADDR = 0x0B,                   // Single register value
        NACL_NACH_ADDR = 0x0C,
        LMDL_LMDH_ADDR = 0x0E,
        CACL_CACH_ADDR = 0x10,
        FCACL_FCACH_ADDR = 0x12,
        AVRG_CURRENT_ADDR = 0x14,
        TIME_EMPTY_ADDR = 0x16,
        TIME_FULL_ADDR = 0x18,
        STANDBY_CURRENT_ADDR = 0x1A,
        S_TIME_EMPTY_ADDR = 0x1C,
        CEDVL_CEDVH_ADDR = 0x20,
        TTCPL_TTCPH_ADDR = 0x26,
        CYCLL_CYCLH_ADDR = 0x28,
        CYCTL_CYCTH_ADDR = 0x2A,
        CSOC_ADDR = 0x2C,                   // Single register value
        EEPROM_ENABLE_ADDR = 0x6E,          // Single register value
        EEPROM_ILMD_ADDR = 0x76,            // Single register value
        EEPROM_SEVDF_ADDR = 0x77,           // Single register value
        EEPROM_SEDV1_ADDR = 0x78,           // Single register value
        EEPROM_ISLC_EDVT_ADDR = 0x79,       // Single register value
        EEPROM_DMFSD_ADDR = 0x7A,           // Single register value
        EEPROM_TAPER_ADDR = 0x7B,           // Single register value
        EEPROM_PKCFG_ADDR = 0x7C,           // Single register value
        EEPROM_GAF_DEDV_ADDR = 0x7D,        // Single register value
        EEPROM_DCOMP_ADDR = 0x7E,           // Single register value
        EEPROM_TCOMP_ADDR = 0x7F            // Single register value
    };

    // TODO: Create enums for power threshold constants

    // Functions to read from bqJunior registers
    // Single register reads in 8 bit number; double register reads in 16 bit number
    uint8_t readFromSingleRegister(uint8_t addr);
    uint16_t readFromPairRegister(uint8_t addr);

};

#endif