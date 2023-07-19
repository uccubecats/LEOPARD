#include "I2Cmode.cpp"
#include "TemperatureReading.cpp"
#include "NominalMode.cpp"
#include "VoltageReading.cpp"

#define STACK_SIZE 14  // Stack size

uint8_t temp_High, temp_Low, Magnetic_X1, Magnetic_X2, Magnetic_Y1, Magnetic_Y2, Magnetic_Z1, Magnetic_Z2, Angular_X1, Angular_X2, Angular_Y1, Angular_Y2, Angular_Z1, Angular_Z2, Voltage;  // Sensor data variables
bool nominal_flag; //this is a flag that will be recieved through ground transmission currently comms not implemented

void GetData(){
	temp_High=ReadTempetureHigh();	//Read high temp value
	temp_Low=ReadTempetureLow();	//Read low temp value
	Magnetic_X1=ReadMagnetisSensorX1();	//Read MagneticX1 sensor value
	Magnetic_X2=ReadMagnetisSensorX2();	//Read MagneticX2 sensor value
	Magnetic_Y1=ReadMagnetisSensorY1();	//Read MagneticY1 sensor value
	Magnetic_Y2=ReadMagnetisSensorY2();	//Read MagneticY2 sensor value
	Magnetic_Z1=ReadMagnetisSensorZ1(); //Read MagneticZ1 sensor value
	Magnetic_Z2=ReadMagnetisSensorZ2();	//Read MagneticZ2 sensor value
	Angular_X1=ReadAngularRateSensorX1(); //Read MagneticX1 sensor value
	Angular_X2=ReadAngularRateSensorX2(); //Read MagneticX2 sensor value
	Angular_Y1=ReadAngularRateSensorY1(); //Read MagneticY1 sensor value
	Angular_Y2=ReadAngularRateSensorY2(); //Read MagneticY2 sensor value
	Angular_Z1=ReadAngularRateSensorZ1(); //Read MagneticZ1 sensor value
	Angular_Z2=ReadAngularRateSensorZ2(); //Read MagneticZ2 sensor value
	Voltage = ReadVoltage();
	push_stack(&temp_High);		  //push temp high to stack
	push_stack(&temp_Low);        //push temp low to stack
	push_stack(&Magnetic_X1);	  //push magnetic x1 to the stack
	push_stack(&Magnetic_X2);	  //push magnetic x2 to the stack
	push_stack(&Magnetic_Y1);	  //push magnetic y1 to the stack
	push_stack(&Magnetic_Y2);	  //push magnetic y2 to the stack
	push_stack(&Magnetic_Z1);	  //push magnetic z1 to the stack
	push_stack(&Magnetic_Z2);	  //push magnetic z2 to the stack
	push_stack(&Angular_X1);	  //push magnetic x1 to the stack
	push_stack(&Angular_X2);	  //push magnetic x2 to the stack
	push_stack(&Angular_Y1);	  //push magnetic y1 to the stack
	push_stack(&Angular_Y2);	  //push magnetic y2 to the stack
	push_stack(&Angular_Z1);	  //push magnetic z1 to the stack
	push_stack(&Angular_Z2);	  //push magnetic z2 to the stack
	push_stack(&Voltage);		  //push voltage to stack 
}

// Define a stack structure
struct stack {
	uint8_t *data_ptr[STACK_SIZE];
	int top;
} stack;

// Function to initialize the stack
void init_stack()
{
	stack.top = -1;  // Set top index to -1 to indicate an empty stack
}

// Function to push a pointer onto the stack
void push_stack(uint8_t *ptr)
{
	if (stack.top == STACK_SIZE - 1) {
		// Stack is full, handle error
		return;
	}
	stack.top++;                // Increment top index
	stack.data_ptr[stack.top] = ptr;  // Push pointer onto the stack
}

// Function to pop a pointer from the stack
uint8_t* pop_stack()
{
	if (stack.top == -1) {
		// Stack is empty, handle error
		return NULL;
	}
	uint8_t *ptr = stack.data_ptr[stack.top];  // Pop pointer from the stack
	stack.top--;                // Decrement top index
	return ptr;
}

// Function to add data to the transmission queue
//void add_data_to_queue(uint8_t data)
//{
	//TWDR = data;            // Load data into the TWDR register
	//TWCR = (1<<TWINT) |     // Clear the TWINT flag to start transmission
	//(1<<TWEN) |      // Enable TWI interface
	//(1<<TWEA);       // Enable acknowledge bit
	//while (!(TWCR & (1<<TWINT)));  // Wait for transmission to complete
//}
bool GetNominalFlag(){
	return 0;	//this will be implemented later when ground transmission works and if this flag is set to 0 we exit nominal mode
}

int NominalMode(void)	//propogate transmissioin queue in the form of a stack
{
	while(mode == 3){
		if(nominal_flag == 0){
			// Initialize the stack
			init_stack();
			GetData();	//call function to get all sensor readings and push to the stack
		}
		else{
			mode = 3; //mode = something else off nominal mode not implemented so for now it goes to detumble mode
		}
	}
	
}



