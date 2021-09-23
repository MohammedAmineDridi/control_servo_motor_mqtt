
/******************************************
 *
 * This example works for both Industrial and STEM users.
 * If you are using the old educational platform,
 * please consider to migrate your account to a STEM plan
 *
 * Developed by Jose Garcia, https://github.com/jotathebest/
 *
 * ****************************************/

/****************************************
 * Include Libraries
****************************************/
#include <Servo.h>

Servo servo;

#include "Ubidots.h"

/****************************************
 * Define Constants
 ****************************************/
#define TOKEN "BBFF-3TAXSd8Te2QRiny5HeqIR5AeZwftp0"     // Your Ubidots TOKEN
#define WIFINAME "ya ga7af"  // Your SSID
#define WIFIPASS "ga7af2019"  // Your Wifi Pass

Ubidots ubidots(TOKEN);


void setup() {
    // servo motor .

  servo.attach(2); //D4
  servo.write(0);
  delay(2000);

  // put your setup code here, to run once:
  Serial.begin(115200);
  // ubidots.setDebug(true);  // Pass a true or false bool value to activate debug messages
  ubidots.wifiConnect(WIFINAME, WIFIPASS);
  // ubidots.begin(callback);
}

void loop() {


 float value = ubidots.get("dev_test1", "motor_value");

Serial.println("la valeur de 'motor_value' de device ' dev_test1 ' = " + String(value) ) ;
    /*
  client.ubidotsPublish("source2");
  client.loop();
  */
  servo.write(value*2);
  delay(500);
}
