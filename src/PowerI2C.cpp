/*
 * PowerI2C.cpp
 *
 * Created: 3/10/2023 12:34:19 PM
 *  Author: 13302
 */ 
/*
 * IMUI2c.cpp
 *
 * Created: 3/9/2023 12:50:31 PM
 *  Author: 13302
 */ 
//Transfer when master is reading one byte
//1.Start condition
//2.SAD+W(Send 7 bit slave address plus write)
//3.SAK(Slave Acknowledge)
//4.SUB(Send Address In slave you would like to read from)
//5.SAK
//6.SR(Repeated Start Now we are in MT mode)
//7.SAD+R(Send 7 bit slave address plus read)
//8.SAK
//9.DATA(Recieved by master from slave)
//10.NMAK(No Master Acknowledge)
//11.SP(STOP)

//Device(Slave) Address
//Ack
//Internal Register Address
//Ack
//Data
//Ack
//Stop

//1

#define VOLTAGE_SLAVE_ADDRESS_R				0xAB;	
#define VOLTAGE_SLAVE_ADDRESS_W				0xAA;
#define POINTER_ADDRESS 0x04;


//NO ACCELEROMETER
//MAGNETIC FEILD
//ANGULAR RATE
//TIMESTAMP DATE

				
#include "I2Cmode.cpp"
#include "Voltage.h"

uint8_t ReadVoltage(void){
	uint8_t voltage;
	TWI_init_master();
	TWI_start();
	TWI_write_address(VOLTAGE_SLAVE_ADDRESS_W); //write slave address+w make sure we get an ack
	TWI_write_data(POINTER_ADDRESS);
	TWI_Repeated_Start();
	TWI_read_address(VOLTAGE_SLAVE_ADDRESS_R);
	voltage = TWI_read_slave_Nack();
	TWI_stop();
	return voltage;
}
