#include "TemperatureReading.cpp"
#include "NominalMode.cpp"
#include "VoltageReading.cpp"
#include "math.h"


uint8_t temp_High, temp_Low, Magnetic_X1, Magnetic_X2, Magnetic_Y1, Magnetic_Y2, Magnetic_Z1, Magnetic_Z2, Angular_X1, Angular_X2, Angular_Y1, Angular_Y2, Angular_Z1, Angular_Z2, Voltage;  // Sensor data variables
uint16_t Magnetic_x, Magnetic_y, Magnetic_z, Angular_x, Angular_y, Angular_z;	//Sensor reading data vars
bool magneticCheck;
bool angularCheck;
bool detumble_continue_flag;
double denominator;
double magnetic_tolerance_value;
uint16_t timer_14_days = 0;	//14 day timer
bool timer_14_days_flag;	//14 day timer flag
uint8_t detumble_timer=0;	//detumble timer
bool timer_detumble__flag=0;	//detumble timer flag


bool CheckTolerance(){
	bool magenticCheck;
	bool angulerCheck;
	Magnetic_X1=ReadMagnetisSensorX1(); //read magnetic sensor x1
	Magnetic_X2=ReadMagnetisSensorX2(); //read magnetic sensor x2
	Magnetic_Y1=ReadMagnetisSensorY1();	//read magnetic sensor y1
	Magnetic_Y2=ReadMagnetisSensorY2();	//read magnetic sensor y2
	Magnetic_Z1=ReadMagnetisSensorZ1();	//read magnetic sensor z1
	Magnetic_Z2=ReadMagnetisSensorZ2();	//read magnetic sensor z2
	Angular_X1=ReadAngularRateSensorX1(); //read angular sensor x1
	Angular_X2=ReadAngularRateSensorX2(); //read angular sensor x2
	Angular_Y1=ReadAngularRateSensorY1(); //read angular sensor y1
	Angular_Y2=ReadAngularRateSensorY2(); //read angular sensor y2
	Angular_Z1=ReadAngularRateSensorZ1(); //read angular sensor z1
	Angular_Z2=ReadAngularRateSensorZ2(); //read angular sensor z2
	uint16_t Magnetic_x = ConvertHighAndLow(Magnetic_X1, Magnetic_X2);	//magnetic x convert high and low to 16 bit value
	uint16_t Magnetic_y = ConvertHighAndLow(Magnetic_Y1, Magnetic_Y2);  //magnetic y convert high and low to 16 bit value
	uint16_t Magnetic_z = ConvertHighAndLow(Magnetic_Z1, Magnetic_Z2);  //magnetic z convert high and low to 16 bit value
	uint16_t Angular_x = ConvertHighAndLow(Angular_X1, Angular_X2);     //angular x convert high and low to 16 bit value
	uint16_t Angular_y = ConvertHighAndLow(Angular_Y1, Angular_Y2);     //angular y convert high and low to 16 bit value
	uint16_t Angular_z = ConvertHighAndLow(Angular_Z1, Angular_Z2);     //angular z convert high and low to 16 bit value
	denominator = (sqrt((Magnetic_x)^2 + (Magnetic_y)^2 + (Magnetic_x)^2)); //calculate theta using acos(c.m/||c||m|) magnitude of c is one c is (1,0,0) c.m = magneticx
	magnetic_tolerance_value = acos(Magnetic_x/denominator);
	magneticCheck = CheckMagnetic(magnetic_tolerance_value);
	angularCheck = CheckAngular(Angular_x, Angular_y, Angular_z);
	if(magneticCheck == true && angularCheck==true){
		return true;
	else{
		return false;
	}
	}
}


uint16_t* GetData(){
	Magnetic_X1=ReadMagnetisSensorX1(); //read magnetic sensor x1
	Magnetic_X2=ReadMagnetisSensorX2();	//read magnetic sensor x2
	Magnetic_Y1=ReadMagnetisSensorY1();	//read magnetic sensor y1
	Magnetic_Y2=ReadMagnetisSensorY2();	//read magnetic sensor y2
	Magnetic_Z1=ReadMagnetisSensorZ1();	//read magnetic sensor z1
	Magnetic_Z2=ReadMagnetisSensorZ2();	//read magnetic sensor z2
	Angular_X1=ReadAngularRateSensorX1(); //read angular sensor x1;
	Angular_X2=ReadAngularRateSensorX2(); //read angular sensor x2;
	Angular_Y1=ReadAngularRateSensorY1(); //read angular sensor y1;
	Angular_Y2=ReadAngularRateSensorY2(); //read angular sensor y2;
	Angular_Z1=ReadAngularRateSensorZ1(); //read angular sensor z1;
	Angular_Z2=ReadAngularRateSensorZ2(); //read angular sensor z2;
	uint16_t Magnetic_x = ConvertHighAndLow(Magnetic_X1, Magnetic_X2); //magnetic x convert high and low to 16 bit value
	uint16_t Magnetic_y = ConvertHighAndLow(Magnetic_Y1, Magnetic_Y2); //magnetic y convert high and low to 16 bit value
	uint16_t Magnetic_z = ConvertHighAndLow(Magnetic_Z1, Magnetic_Z2); //magnetic z convert high and low to 16 bit value
	uint16_t Angular_x = ConvertHighAndLow(Angular_X1, Angular_X2);	   //angular x convert high and low to 16 bit value
	uint16_t Angular_y = ConvertHighAndLow(Angular_Y1, Angular_Y2);	   //angular y convert high and low to 16 bit value
	uint16_t Angular_z = ConvertHighAndLow(Angular_Z1, Angular_Z2);	   //angular z convert high and low to 16 bit value
	uint16_t dataArray[6]; // store all values in a uint16_t arrray
	dataArray[0] = Magnetic_x;
	dataArray[1] = Magnetic_y;
	dataArray[2] = Magnetic_z;
	dataArray[3] = Angular_x;
	dataArray[4] = Angular_y;
	dataArray[5] = Angular_z;
	return dataArray;
}

ISR(TIMER1_COMPA_vect){
	// (24 x 14 x 60 min x 60 seconds) / 2s timer
	timer_14_days = timer_14_days +1;
	if (timer_14_days >= 604800) {
		timer_14_days_flag = 1;
	}
	// ( 60 min x 60 seconds) / 2s timer
	detumble_timer = detumble_timer+1;
	if (detumble_timer >= 1800) {
		timer_detumble__flag = 1;
	}
	
	
	
}


uint16_t ConvertHighAndLow(uint8_t low_byte, uint8_t high_byte){
	uint8_t result;
	result = (((uint16_t) high_byte) << 8) | low_byte;
}

bool CheckMagnetic(double tolerance ){
	if(tolerance<.2618){	//this is the value of 15 degrees check manetic field created angle is less then 15 degrees
		return true;
	}
	else{
		return false;
	}
	
}

bool CheckAngular(uint16_t angular_x, uint16_t angular_y, uint16_t angular_z ){
	if(angular_x < 0.005 && angular_y == 0<0.005 && angular_z < 0.005){	//check angular velocities are all less than 0.005
		return true;
	}
	else{	
		return false;
	}
	
}

int DeTumble_Mode(void){
	
	while(mode == 2){
		if(timer_14_days_flag==1){
			mode = 3;	//this goes to heartbeat mode but not implemented so for now i send it back to nominal
		}
		else{
			if(CheckTolerance() == true && detumble_continue_flag == 1){
				timer_detumble__flag = 0 // start detumble timer
				while(timer_detumble__flag==0){	//while detumble timer is occuring
					if(CheckTolerance()==true){ //if angular and magnetic tolerances are met
						detumble_continue_flag = 1; //keep flag
					}
					else{
						timer_detumble__flag = 1; // stop detuble timer
						detumble_continue_flag = 0 //remove flag
					}
				}
				else{
					uint16_t* data = GetData();
				}		
			}
		
		
		}
	}
}
