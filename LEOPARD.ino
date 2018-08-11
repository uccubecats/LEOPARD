/*
** UC CubeCats
** Project LEOPARD
** On Board Computing
*/

#include "Arduino.h"
#include "bqJunior/bqJunior.h"
#include "leopard_common/leopard_common.h"
#include "hamshield/HamShield.h"
#include "hamshield/HamShield_comms.h"
#include "payload/payload.h"
#include "Wire.h"

int payload_sensor_iterator = 0;
Payload payload;

void setup()
{
  /************************ Power ************************/

  /******************** Communications ********************/

  /******************** Attitude System ********************/

  /******************** Payload Sensors ********************/

  // Set up the Mux "select configuration" pins as outputs:
  pinMode(PAYLOAD_S0_PIN, OUTPUT);
  digitalWrite(PAYLOAD_S0_PIN, HIGH);
  pinMode(PAYLOAD_S1_PIN, OUTPUT);
  digitalWrite(PAYLOAD_S1_PIN, HIGH);
  pinMode(PAYLOAD_S2_PIN, OUTPUT);
  digitalWrite(PAYLOAD_S2_PIN, HIGH);

  // Set up Z as an analog input
  pinMode(PAYLOAD_Z_PIN, INPUT);

  /******************** Storage Management ********************/
}

void loop() 
{
  /************************ Power ************************/
  // TODO: Determine amount of power on battery
  // TODO: Determine if system needs to go into different power mode and take action accordingly 

  /******************** Communications ********************/
  // TODO: Send heartbeat beacon every so often
  // TODO: Determine if packet was received, and analyze it if applicable
  // TODO: Determine if packet should be sent and take action if applicable
  // TODO: Determine if toggle Tx/Rx is in order and take action if it is so

  /******************** Attitude System ********************/
  // TODO: Read necessary data from magnetometer and store

  /******************** Payload Sensors ********************/

  // Configure Mux Pins for current payload sensor and read output
  configureMuxPin(payload_sensor_iterator);
  int inputValue = analogRead(PAYLOAD_Z_PIN);

  // TODO: Store value, analyze it if necessary

  // Increment Payload sensor counter
  payload_sensor_iterator = (payload_sensor_iterator + 1) % 8;

  /******************** Storage Management ********************/
  // TODO: Determine if storage too full and compress/delete data as necessary

  /******************** Other Management ********************/

  // Pause 1 second between each loop iteration
  delay(1000);
}

int select_pins[3] = {PAYLOAD_S0_PIN, PAYLOAD_S1_PIN, PAYLOAD_S2_PIN};

void configureMuxPin(int payload_sensor)
{
    for (int i = 0; i <= 3; i++)
    {
        if (payload_sensor & (1<<i))
            digitalWrite(select_pins[i], HIGH);
        else
            digitalWrite(select_pins[i], LOW);
    }
}