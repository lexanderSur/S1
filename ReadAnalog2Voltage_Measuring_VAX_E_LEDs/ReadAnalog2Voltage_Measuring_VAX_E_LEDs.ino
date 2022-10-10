#include <Wire.h>
#include <BH1750.h>
BH1750 lightMeter;
float voltage1, voltage2, id, lux;

void setup() {
    Serial.begin(250000);
     Wire.begin();
     lightMeter.begin();
     
   for (int i = 0; i <= 30; i++) {
    voltage1 = analogRead(A0) * (5.0 / 1023.0);
    voltage2 = analogRead(A1) * (5.0 / 1023.0);
    id = (voltage2 - voltage1)/0.33;
    lux = lightMeter.readLightLevel();
    Serial.print(i);
    Serial.print("\t");
    Serial.print(voltage1);
    Serial.print("\t");
    Serial.print(id);
    Serial.print("\t");
    Serial.println(lux);
    delay(500); 
   }
 }


void loop() { 
}
