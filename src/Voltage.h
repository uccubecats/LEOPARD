#ifndef VOLTAGE_H
#define VOLTAGE_H


// Device (Slave) Addresses
#define VOLTAGE_SLAVE_ADDRESS_R		0xAB
#define VOLTAGE_SLAVE_ADDRESS_W		0xAA

// Internal Register Address
#define POINTER_ADDRESS				0x04

// Function Declaration
uint8_t ReadVoltage(void);

#endif // VOLTAGE_H