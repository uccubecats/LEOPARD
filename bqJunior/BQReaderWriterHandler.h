/*
** UC CubeCats
** Project LEOPARD
** On Board Computing
*/

#include "BQCore.h"

class BQReaderWriterHandler {
    
    // Read values from either one or two registers
    uint8_t readFromSingleRegister(uint8_t addr);
    uint16_t readFromPairRegister(uint8_t addr);

    // Values for register reads
    uint8_t r_control;
    uint8_t r_mode;
    uint16_t r_at_rate;
    uint16_t r_at_rate_time_empty;
    uint16_t r_temperature;
    uint16_t r_battery_volt;
    uint8_t r_statu_flag;
    uint8_t r_rsoc;
    uint16_t r_nacl_nach;
    uint16_t r_lmdl_lmdh;
    uint16_t r_cacl_cach;
    uint16_t r_fcacl_fcach;
    uint16_t r_avrg_current;
    uint16_t r_time_empty;
    uint16_t r_time_full;
    uint16_t r_standby_current;
    uint16_t r_s_time_empty;
    uint16_t r_cedvl_cedvh;
    uint16_t r_ttcpl_ttcph;
    uint16_t r_cycll_cyclh;
    uint16_t r_cyctl_cycth;
    uint8_t r_csoc;
    uint8_t r_eeprom_enable;
    uint8_t r_eeprom_ilmd;
    uint8_t r_eeprom_sevdf;
    uint8_t r_eeprom_sedv1;
    uint8_t r_eeprom_islc_edvt;
    uint8_t r_eeprom_dmfsd;
    uint8_t r_eeprom_taper;
    uint8_t r_eeprom_pkcfg;
    uint8_t r_eeprom_gaf_dedv;
    uint8_t r_eeprom_dcomp;
    uint8_t r_eeprom_tcomp;
};