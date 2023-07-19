/*
 * senior_design.cpp
 *
 * Created: 2/19/2023 1:46:17 PM
 * Author : aress
 */ 

//https://docs.google.com/spreadsheets/d/1aOO-aKSErlTKVRmADC9FDCtId5tSETiSSi95qkqO_40/edit
// https://doc.riot-os.org/group__boards__atmega1284p.html
// https://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-42719-ATmega1284P_Datasheet.pdf
// https://docs.google.com/spreadsheets/d/1yCiimSmWYmrj__3zIB47OlVHga2FEKt6DgUsY0qXlRE/edit#gid=1914669022
//https://docs.google.com/document/d/1SK-xBBsnFJd9D6A3hK_reXP0_SJ2J7FlFwfXFoXnwUY/edit#heading=h.6z8emjxz85oq
#include <avr/io.h>
#include <avr/interrupt.h>
#include <clocks/Clock_Config.h>
#include <util/delay.h>
#include "DetumbleMode.cpp"

//inert mode ignored as the board will not be on these modes will all need to be implemented
//mode 0 = post-launch mode
//mode 1 = initialization mode 
//mode 2 = detumble mode 
//mode 3 = nominal mode
//mode 4 = transmission mode  
//mode 5 = heartbeat mode 
//mode 6 = relay mode
//mode 7 = safe mode
//mode 8 = reboot mode
//mode 9 = transmission shutdown mode
volatile uint8_t mode = 0;
volatile uint8_t timer_flag = 0; 
volatile uint8_t timer = 0;
volatile uint8_t voltage = 0;

//5v and 3v enable
//battery 1 and battery 2 test enable
//uhf transceiver enable
//

//#include "config.h" //add config file


ISR(TIMER1_COMPA_vect){
	// (30 min x 60 seconds) / 2s timer
	timer = timer+1;
	if (timer >= 900) {
		timer_flag = 1;
	}
	
}

int Post_Launch(void){
	//Data Direction Register (DDR) bit corresponding to the OC0A pin must be set in order to enable the output driver
	//clear timer on match non pwm
	//timers use 32kHz crystals, must use timer 1 for 16-bit counter, maximum timer value is 2.097s, when on the maximum n value, n = 1024
	//N/fio * (2^16), where fio is the crystal oscillator frequency
	//when n = 256, maximum timer value is .524s
	//for timer to compare match and reset at 2s, OCR1A value should be 62,499
	//in this mode we will want a 30 minute timer
	TCCR0A = (0<<WGM02)| (1<<WGM01)| (1<<WGM00);
	TCCR1A = (1<<COM0A1) | (0<<COM0A0);
	OCR1A = 624999;
	//setting clock
	TCCR1B = (1<<CS12)|(0<<CS11)|(1<<CS10);
	// powers system data would be checked here
	//single-cell li-ion battery fuel gauge uses i2c communication, and commands are two-bytes. p 24 has commands/address bytes to send info to
	//p 24 of
	while(timer_flag!=1){
		voltage = ReadVoltage(); // need to read power system vitals other than voltage from fuel gauage not sure what else this entails
	}
	mode = 1; //once timer is up enter initialization mode
	
}


int Void_Switch(void){
	switch (mode)
	{
		case 0:
		Post_Launch();	//post launch mode an operational mode that will happen if certain conditions are met
		break;
		case 1:
		InitializationMode(); //Initialization mode an operational mode that will happen if certain conditions are met will allocate power
		break;
		case 2:
		DeTumble_Mode(); //Detumble mode an operational mode that will happen if certain conditions are met read and check adcs data
		break;
		case 3:
		NominalMode();	//Nominal mode an operational mode that will happen if certain conditions are met propogate a queue for transmission
		break;
		
	}
}

int main(void)
{
while(1){
	_delay_ms(1000);
	//CTC mode/ clear timer on compare match mode
	mode = 0; //set mode to 0 for postlaunch
	TCCR0A = (0<<WGM02)| (1<<WGM01)| (1<<WGM00);
	TCCR1A = (1<<COM0A1) | (0<<COM0A0);
	OCR1A = 624999;
	//setting clock
	TCCR1B = (1<<CS12)|(0<<CS11)|(1<<CS10);
	Void_Switch();
	}
}
