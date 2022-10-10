#include <math.h> //включает библиотеку для логарифмической функции

float rawCount; //create global variable for reading from A/D converter (0-1023)
float temperature; //create global variable for temperature in Celsius

void setup() {
  Serial.begin(250000); //setup communication to display
  for (int i=0; i <= 50; i++){
  rawCount=analogRead(A0); //read one data value (0-1023)
  temperature=thermistor(rawCount); //calculate temperature
  Serial.print(i);
  Serial.print("\t");
  Serial.println(temperature,1); // display temperature to one decimal)                               
  delay(100); //wait half second
  }
}

void loop() {
 
}

//This function calculates temperature from raw count
float thermistor(int raw) {
  float resistor=10000; //initialize value of fixed resistor in Vernier shield
  float resistance; //create local variable for resistance
  float temp; //create local variable for temperature
  resistance=log(resistor*raw/(1024-raw)); //calculate resistance
  temp = 1 / (0.001129148 + 0.000234125 * resistance + 0.0000000876741 * pow(resistance, 3));
  temp = temp - 273.15; //Convert Kelvin to Celsius                      
  return temp; //return the temperature
}
