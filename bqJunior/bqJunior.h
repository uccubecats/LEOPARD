/*
** UC CubeCats
** Project LEOPARD
** On Board Computing
*/

#ifndef BQJUNIOR_H
#define BQJUNIOR_H

#include <stdint.h>

// Define register address values for sensor
// All values are first register of a pair unless denoted otherwise as a single register

#define CONTROL_ADDR            0x00    // Single register value
#define MODE_ADDR               0x01    // Single register value
#define AT_RATE_ADDR            0x02 
#define AT_RATE_TIME_EMPTY_ADDR 0x04 
#define TEMPERATURE_ADDR        0x06 
#define BATTERY_VOLT_ADDR       0x08 
#define STATUS_FLAG_ADDR        0x0A    // Single register value
#define RSOC_ADDR               0x0B    // Single register value
#define NACL_NACH_ADDR          0x0C 
#define LMDL_LMDH_ADDR          0x0E 
#define CACL_CACH_ADDR          0x10 
#define FCACL_FCACH_ADDR        0x12 
#define AVRG_CURRENT_ADDR       0x14 
#define TIME_EMPTY_ADDR         0x16 
#define TIME_FULL_ADDR          0x18 
#define STANDBY_CURRENT_ADDR    0x1A 
#define S_TIME_EMPTY_ADDR       0x1C 
#define CEDVL_CEDVH_ADDR        0x20 
#define TTCPL_TTCPH_ADDR        0x26 
#define CYCLL_CYCLH_ADDR        0x28 
#define CYCTL_CYCTH_ADDR        0x2A 
#define CSOC_ADDR               0x2C    // Single register value
#define EEPROM_ENABLE_ADDR      0x6E    // Single register value
#define EEPROM_ILMD_ADDR        0x76    // Single register value
#define EEPROM_SEVDF_ADDR       0x77    // Single register value
#define EEPROM_SEDV1_ADDR       0x78    // Single register value
#define EEPROM_ISLC_EDVT_ADDR   0x79    // Single register value
#define EEPROM_DMFSD_ADDR       0x7A    // Single register value
#define EEPROM_TAPER_ADDR       0x7B    // Single register value
#define EEPROM_PKCFG_ADDR       0x7C    // Single register value
#define EEPROM_GAF_DEDV_ADDR    0x7D    // Single register value
#define EEPROM_DCOMP_ADDR       0x7E    // Single register value
#define EEPROM_TCOMP_ADDR       0x7F    // Single register value

class bqJunior
{
public:
    // Functions to read from bqJunior registers
    // Single register reads in 8 bit number; double register reads in 16 bit number
    uint8_t readFromSingleRegister(uint8_t addr);   // TODO
    uint16_t readFromPairRegister(uint8_t addr);    // TODO
};

#endif
