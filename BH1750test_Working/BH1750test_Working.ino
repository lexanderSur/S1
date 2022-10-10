/*
    SCL -> SCL (A5 on Arduino Uno, Leonardo, etc or 21 on Mega and Due, on esp8266 free selectable)
    SDA -> SDA (A4 on Arduino Uno, Leonardo, etc or 20 on Mega and Due, on esp8266 free selectable)
    ADD -> (not connected) or GND
*/
#include <Wire.h>
#include <BH1750.h>
BH1750 lightMeter;
float lux;

void setup(){
  Serial.begin(250000);
  Wire.begin();
  lightMeter.begin();
  
}
void loop() {
  lux = lightMeter.readLightLevel();
  Serial.println(lux);
  delay(500);
}
