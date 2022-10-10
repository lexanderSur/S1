#include <math.h> // включает библиотеку для степенной функции
float distance, illum; 
int size1=20; 
void setup() {
  Serial.begin(250000); 
   
  for (int i=0; i<size1; i++)
   {
    int illum = analogRead(A2);
    float illum1=3339000*pow(illum,-1.8);
    Serial.print(i);
    Serial.print("\t"); 
    Serial.print(illum1);  
    delay(200); 
  }
}
void loop() { 
}
