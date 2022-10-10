float voltage1, voltage2, id;

void setup() {
    Serial.begin(250000);
   for (int i = 0; i <= 30; i++) {
    voltage1 = analogRead(A0) * (5.0 / 1023.0);
    voltage2 = analogRead(A1) * (5.0 / 1023.0);
    id = (voltage2 - voltage1)/0.33;
    Serial.print(i);
    Serial.print("\t");
    Serial.print(voltage1);
    Serial.print("\t");
    Serial.println(id);
    delay(500); 
   }
 }


void loop() { 
}
