/* Hamshield
 * Example: Functional Test
 * This is a simple example to demonstrate HamShield receive
 * and transmit functionality.
 * Connect the HamShield to your Arduino. Screw the antenna 
 * into the HamShield RF jack. Plug a pair of headphones into 
 * the HamShield. Connect the Arduino to wall power and then 
 * to your computer via USB. After uploading this program to 
 * your Arduino, open the Serial Monitor. Serial Monitor will 
 * describe what you should be expecting to hear from your 
 * headphones. Tune a HandytTalkie to 446MHz to hear morse 
 * code example.
*/

#include <HamShield.h>

#define PWM_PIN 3
#define RESET_PIN A3
#define SWITCH_PIN 2

HamShield radio;

void setup() {
  // NOTE: if not using PWM out, it should be held low to avoid tx noise
  pinMode(PWM_PIN, OUTPUT);
  digitalWrite(PWM_PIN, LOW);
  
  // prep the switch
  pinMode(SWITCH_PIN, INPUT_PULLUP);
  
  // set up the reset control pin
  pinMode(RESET_PIN, OUTPUT);
  digitalWrite(RESET_PIN, HIGH);
  
  Serial.begin(9600);
  Serial.println("If the sketch freezes at radio status, there is something wrong with power or the shield");
  Serial.print("Radio status: ");
  int result = radio.testConnection();
  Serial.println(result,DEC);
  Serial.println("Setting radio to its defaults..");
  radio.initialize();
}

void loop() {
  radio.setModeReceive();
  radio.setSQLoThresh(0);
  radio.setSQOff();
  radio.setVolume1(0xF);
  radio.setVolume2(0xF);
  delay(1000);
  Serial.println("Changing frequency to 446.000 and waiting 10 seconds. You should hear static fading in.");
    radio.frequency(446000);
  for(int x = 0; x < 16; x++) { radio.setVolume1(x); delay(500); Serial.print(x); Serial.print(".."); } 
  for(int x = 0; x < 16; x++) { radio.setVolume2(x); delay(500); Serial.print(x); Serial.print(".."); }   
      radio.setVolume1(0xF);
    radio.setVolume2(0xF);

  delay(10000);
  Serial.println("Changing frequency to 450.000 and waiting 10 seconds. You should hear static.");
  radio.frequency(446000);
  delay(10000);
  Serial.println("Changing frequency to 220.000 and waiting 10 seconds. you should hear static.");
  radio.frequency(220000);
  delay(10000);
  Serial.println("Changing frequency to 144.520 and waiting 10 seconds. you should hear static.");
  radio.frequency(144520);
  delay(10000);
  Serial.println("Now lets scan for a weather radio station and listen for a while....");
  radio.setWXChannel(radio.scanWXChannel());
  Serial.println("If you hear weather radio, it means the scanWXChannel() and setWXChannel() and VHF works.");
  Serial.println("We will sit here for 30 seconds because weather is important.");
  delay(30000);
  Serial.println("We will now tune to 446.000 and send morse code");
  radio.frequency(446000);
  radio.setModeTransmit();
  radio.morseOut("HELLO PERSON");
  radio.setModeReceive();
  Serial.println("Now we are receiving on the call frequency. Starting over again.");
 
}

