/*
** UC CubeCats
** Project LEOPARD
** On Board Computing
*/

#include <stdint.h>

// Define register addresses for bqJunior battery sensor
enum BQAddr: uint8_t
{
    CONTROL_ADDR = 0x00,
    MODE_ADDR = 0x01,
    AT_RATE_ADDR = 0x02,
    AT_RATE_TIME_EMPTY_ADDR = 0x04,
    TEMPERATURE_ADDR = 0x06,
    BATTERY_VOLT_ADDR = 0x08,
    STATUS_FLAG_ADDR = 0x0A,
    RSOC_ADDR = 0x0B,
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
    CSOC_ADDR = 0x2C,
    EEPROM_ENABLE_ADDR = 0x6E,
    EEPROM_ILMD_ADDR = 0x76,
    EEPROM_SEVDF_ADDR = 0x77,
    EEPROM_SEDV1_ADDR = 0x78,
    EEPROM_ISLC_EDVT_ADDR = 0x79,
    EEPROM_DMFSD_ADDR = 0x7A,
    EEPROM_TAPER_ADDR = 0x7B,
    EEPROM_PKCFG_ADDR = 0x7C,
    EEPROM_GAF_DEDV_ADDR = 0x7D,
    EEPROM_DCOMP_ADDR = 0x7E,
    EEPROM_TCOMP_ADDR = 0x7F,
};

// TODO: Create enums for power threshold constants
