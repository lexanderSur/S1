float illum; 
int size1=50; 
void setup() {
  Serial.begin(250000); 
  Vernier.autoID(); 
  
  for (int i=0; i<size1; i++)
   {
    int illum = analogRead(A0);
    float illum1=illum/1024.0*154.0*5.0;
    Serial.print(illum1);  
    Serial.print("\t"); 
    int illum2 = analogRead(A2);
    Serial.println(illum2);
    delay(200); 
  }
}
void loop() { 
}
