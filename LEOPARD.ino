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
#include "SD.h"
#include "SparkFunLSM9DS1.h"
#include <Time.h>
#include <TimeLib.h>
#include "Wire.h"

void setup()
{
    // DEBUG
    Serial.begin(9600);
    Serial.println(F("Begin execution."));

    // Begin I2C Interface
    // Used by ADCS and Power sensors
    Wire.begin();

    // Begin SPI Interface - auto configured by SD.begin()
    // Initialize SD card reader/writer board
    boolean sd_init_success = SD.begin();

    // DEBUG
    if (!sd_init_success)
    {
        Serial.println(F("SD init failed"));
    }

    // Set up the Payload Mux "select configuration" pins as outputs:
    pinMode(PAYLOAD_S0_PIN, OUTPUT);
    digitalWrite(PAYLOAD_S0_PIN, HIGH);
    pinMode(PAYLOAD_S1_PIN, OUTPUT);
    digitalWrite(PAYLOAD_S1_PIN, HIGH);
    pinMode(PAYLOAD_S2_PIN, OUTPUT);
    digitalWrite(PAYLOAD_S2_PIN, HIGH);

    // Set up Z pin as the analog input for Payload Mux
    pinMode(PAYLOAD_Z_PIN, INPUT);

    // TODO: Set up a digital pin to manage current allocation to payload sensors

}

void loop() 
{
    dataCollectionLoop();
    commsLoop();
    powerLoop();
}

void dataCollectionLoop()
{
    LSM9DS1 adcs;
    Payload payload;
    uint16_t payload_values[8];
    packet::DataCollection dataCollection;

    // Set timestamp to current time (UTC)
    uint32_t timestamp = (uint32_t) now();

    // Read current values from the ADCS sensor
    adcs.readGyro();
    adcs.readMag();
    adcs.readAccel();

    // Configure Mux Pins for current payload sensor and read output
    for (byte pin=0; pin<=7; pin++)
    {
        // Configure MUX select pins for reading from current pin
        payload.configureMuxPin(pin);

        // Read input from current selected sonsor and convert value to volt value
        float reading = analogRead(PAYLOAD_Z_PIN) * 5.0 / 1023.0;

        // Store current sensor value in collection struct
        payload_values[pin] = reading;
    }

    // Save all recorded values to dataCollection
    dataCollection.timestamp_collection = timestamp;
    dataCollection.gyro_x, dataCollection.gyro_y, dataCollection.gyro_z = adcs.gx, adcs.gy, adcs.gz;
    dataCollection.mag_x, dataCollection.mag_y, dataCollection.mag_z = adcs.mx, adcs.my, adcs.mz;
    dataCollection.accel_x, dataCollection.accel_y, dataCollection.accel_z = adcs.ax, adcs.ay, adcs.az;
    dataCollection.sensor_0 = payload_values[0];
    dataCollection.sensor_1 = payload_values[1];
    dataCollection.sensor_2 = payload_values[2];
    dataCollection.sensor_3 = payload_values[3];
    dataCollection.sensor_4 = payload_values[4];
    dataCollection.sensor_5 = payload_values[5];
    dataCollection.sensor_6 = payload_values[6];
    dataCollection.sensor_7 = payload_values[7];
    
    // Save filename as current timestamp
    String filename = QUEUE_DIR + (String)(timestamp) + ".txt";
    File data_file = SD.open(filename, FILE_WRITE);
    //data_file.println("[%i, %i, %i]", adcs.gx, adcs.gy, adcs.gz);
    data_file.close();

    // Pause 1 minute between each loop iteration
    delay(60000);

}

void commsLoop()
{
    // TODO: Determine if packet was received, and analyze it if applicable
    // TODO: Determine if packet should be sent and take action if applicable
    // TODO: Determine if toggle Tx/Rx is in order and take action if it is so
}

void powerLoop()
{
    // TODO: Determine amount of power on battery
    // TODO: Determine if system needs to go into different power mode and take action accordingly
}
