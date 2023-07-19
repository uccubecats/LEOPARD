/*
 * I2CMode.cpp
 *
 * Created: 3/8/2023 1:15:50 PM
 *  Author: 13302
 */ 
//TW_READ = SLA+R = 1
//TW_WRITE= SLA+W = 0
//FIND SDA and SCL pins
//PORT C BIT 1 = SDA
//PORT C BIT 0 = SCL


#include <util/twi.h>

void TWI_init_master(void) // Function to initialize master
{
	// Set SCL and SDA pins as inputs
	DDRC &= ~((1 << PORTC0) | (1 << PORTC1));
	   
	// Set pull-up resistors for SCL and SDA pins
	PORTC |= (1 << PORTC0) | (1 << PORTC1);
	TWBR=0x01;    // Bit rate
	TWSR=(0<<TWPS1)|(0<<TWPS0);    // Setting prescalar bits
	TWCR |= (1 << TWEN);
	// SCL freq= F_CPU/(16+2(TWBR).4^TWPS)
}

void TWI_start(void)
{
	// Clear TWI interrupt flag, Put start condition on SDA, Enable TWI
	TWCR= (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
	while(!(TWCR & (1<<TWINT))); // Wait till start condition is transmitted
	while((TWSR & 0xF8)!= 0x08); // Check for the acknowledgement START condition has been transmitted
}


void TWI_write_address(unsigned char data) //writes data with write bit
{
	TWDR=data;    // Address and write instruction TWDR = data byte
	TWCR=(1<<TWINT)|(1<<TWEN);    // Clear TWI interrupt flag,Enable TWI
	while (!(TWCR & (1<<TWINT))); // Wait till complete TWDR byte received
	while((TWSR & 0xF8)!= 0x18);  // Check for the acknoledgement SLA+W has been transmitted ACK has been recieved
}

void TWI_read_address(unsigned char data) //writes data with read bit
{
	TWDR=data;    // Address and read instruction
	TWCR=(1<<TWINT)|(1<<TWEN);    // Clear TWI interrupt flag,Enable TWI
	while (!(TWCR & (1<<TWINT))); // Wait till complete TWDR byte received
	while((TWSR & 0xF8)!= 0x40);  // Check for the acknoledgement SLA+R has been transmitted ACK has been recieved
}

void TWI_write_data(unsigned char data)
{
	TWDR=data;    // put data in TWDR
	TWCR=(1<<TWINT)|(1<<TWEN);    // Clear TWI interrupt flag,Enable TWI
	while (!(TWCR & (1<<TWINT))); // Wait till complete TWDR byte transmitted
	while((TWSR & 0xF8) != 0x28); // Check for the acknoledgement 0xf8=11111000 0xf8 is status register DAta byte has been transmitted; ACK has beeen recieved
}

void TWI_stop(void)
{
	// Clear TWI interrupt flag, Put stop condition on SDA, Enable TWI
	TWCR= (1<<TWINT)|(1<<TWEN)|(1<<TWSTO);
	while(!(TWCR & (1<<TWSTO)));  // Wait till stop condition is transmitted
}

void TWI_Repeated_Start(void){
	TWCR= (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
	while(!(TWCR & (1<<TWINT))); // Wait till start condition is transmitted
	while((TWSR & 0xF8)!= 0x10); // Check for the acknowledgement REPEATED START condition has been transmitted
}


//TWI_read_slave_ack
uint8_t TWI_read_slave_ack(void)
{
	// enable ACK and receive data
	TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWEA);
	while (!(TWCR & (1 << TWINT)));
	
	// return received data
	return TWDR;
}

uint8_t TWI_read_slave_Nack(void)
{
	// Clear TWI interrupt flag,Get acknowlegement, Enable TWI
	TWCR= (1<<TWINT)||(1<<TWEN);
	while (!(TWCR & (1<<TWINT)));    // Wait for TWINT flag
	while((TWSR & 0xF8)!=0x58);        // Wait for acknowledgement
	//uint8_t recv_data=TWDR;                    // Get value from TWDR
	//PORTC=recv_data;
	return TWDR;                // send the receive value on PORTC
}
