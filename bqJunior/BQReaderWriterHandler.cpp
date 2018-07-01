/*
** UC CubeCats
** Project LEOPARD
** On Board Computing
*/

#include <stdint.h>
#include "BQCore.h"

uint8_t readFromSingleRegister(uint8_t addr)
{
    // TODO: Finish
    // make sure to account for even/odd register differences
    uint8_t temp = BQAddr::AT_RATE_ADDR;
    return 0;
}

uint16_t readFromPairRegister(uint8_t addr)
{
    // TODO: Finish
    // implement i2c incremental read
    return 0;
}
