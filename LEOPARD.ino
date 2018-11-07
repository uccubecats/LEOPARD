/*
** UC CubeCats
** Project LEOPARD
** On Board Computing
*/

#include "Arduino.h"
#include "HamShield_comms.h"
#include "leopard_common.h"
#include "packet.h"
#include "payload.h"
#include <SD.h>
#include "SparkFunLSM9DS1.h"
#include <Time.h>
#include <TimeLib.h>
#include "Wire.h"

void setup()
{
    // DEBUG
    Serial.begin(9600);

    /************************ Power ************************/

    // TODO: Figure out if anythin is needed here for I2C

    /******************** Communications ********************/

    // TODO: Setup pins for Hamshield

    /******************** Attitude System ********************/

    // TODO: Figure out if anythin is needed here for I2C

    /******************** Payload Sensors ********************/

    // Set up the Mux "select configuration" pins as outputs:
    pinMode(PAYLOAD_S0_PIN, OUTPUT);
    digitalWrite(PAYLOAD_S0_PIN, HIGH);
    pinMode(PAYLOAD_S1_PIN, OUTPUT);
    digitalWrite(PAYLOAD_S1_PIN, HIGH);
    pinMode(PAYLOAD_S2_PIN, OUTPUT);
    digitalWrite(PAYLOAD_S2_PIN, HIGH);

    // Set up Z pin as the analog input
    pinMode(PAYLOAD_Z_PIN, INPUT);

    // TODO: Set up a digital pin to manage current allocation to payload sensors

    /******************** Storage Management ********************/

    // Set up pin for SD card
    // Automatically configures pinmode for standard SPI configuration (pins 10-13)
    boolean sd_init_success = SD.begin();

    // DEBUG
    if (!sd_init_success)
    {
        Serial.println(F("SD init failed"));
    }
    else
    {
        Serial.println(F("SD init succeeded"));
    }
}

void loop() 
{
    LSM9DS1 adcs;
    Payload payload;

    // Set timestamp to current time (UTC)
    unsigned long timestamp = (unsigned long) now();

    /************************ Power Management ************************/
    // TODO: Determine amount of power on battery
    // TODO: Determine if system needs to go into different power mode and take action accordingly

    /******************** Packetization ********************/

    /******************** Communications ********************/
    // TODO: Determine if packet was received, and analyze it if applicable
    // TODO: Determine if packet should be sent and take action if applicable
    // TODO: Determine if toggle Tx/Rx is in order and take action if it is so

    /******************** Data Collection ********************/

    // Read current values from the ADCS sensor
    adcs.readGyro();
    adcs.readMag();
    adcs.readAccel();
    adcs.readTemp();

    // Read values for 3 axis data for gyroscope, magnetometer, accelerometer,
    // and for temperature of the chip.
    //adcs.temperature, adcs.gx, adcs.gy, adcs.gz, adcs.mx, adcs.my, adcs.mz, adcs.ax, adcs.ay, adcs.az;

    // Configure Mux Pins for current payload sensor and read output
    for (byte pin=0; pin<=7; pin++)
    {
        // Configure MUX select pins for reading from current pin
        payload.configureMuxPin(pin);

        // Read input from current selected sonsor and convert value to volt value
        float reading = analogRead(PAYLOAD_Z_PIN) * 5.0 / 1023.0;

        // Store current sensor value in payload vector
        payload.setPayloadReading(pin, reading);
    }

    /******************** Storage Management ********************/
    
    // Save filename as current timestamp
    String filename = (String)(timestamp) + ".txt";   // TODO: Convert timestamp to strong
    File data_file = SD.open(filename, FILE_WRITE);
    //data_file.println("[%i, %i, %i]", adcs.gx, adcs.gy, adcs.gz);
    data_file.close();

    // TODO: Determine if storage too full and delete data if necessary

    /******************** Other ********************/

    // Pause 1 minute between each loop iteration
    delay(60000);

}
