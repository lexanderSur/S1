/* VernierTutorialThermistor (v2017)
 * This sketch reads the temperature from a Vernier Stainless
 * Steel Temperature Probe or a Surface Temperature Sensor once
 * every half second.
 * 
 * We use the Steinhart-Hart equation (in the function
 * Thermistor) to calculate temperature from the raw voltage
 * reading. Because of the use of log functions in the
 * Steinhart-Hart equation, this sketch requires the math.h
 * library.
 * 
 * Plug the temperature sensor into the Analog 2 port on the 
 * Vernier Arduino Interface Shield or into an Analog 
 * Protoboard Adapter wired to Arduino pin A2.
 */

#include <math.h> //include library for log function

float rawCount, mean; //create global variable for reading from A/D converter (0-1023)
float temperature; //create global variable for temperature in Celsius
int time1;

void setup() {
  Serial.begin(250000); //setup communication to displaypinMode(ledPin, OUTPUT);  
  pinMode(3, OUTPUT); // sets the pin as output
  pinMode(2, OUTPUT);
  digitalWrite(2, LOW);//Включение реле   
  analogWrite(3,255);  // analogRead values go from 0 to 1023, analogWrite values from 0 to 255
  time1=0;
  for (int j=0; j <= 600; j++){
  rawCount=analogRead(A0); //read one data value (0-1023)
  mean=0;
  time1=time1+1;
  for (int i=0; i <= 100; i++)
      mean=mean+analogRead(A1);
      mean=mean/100;
  temperature=thermistor(rawCount); //calculate temperature
  Serial.print(time1);
  Serial.print("\t"); 
  //Serial.print(mean, 0);
  //Serial.print("\t"); 
  Serial.println(temperature,1); // display temperature to one decimal)                               
  delay(1000); //wait half second
  }
 analogWrite(3,0);
}

void loop() {
  
}

//This function calculates temperature from raw count
float thermistor(int raw) {
  float resistor=100000; //initialize value of fixed resistor in Vernier shield
  float resistance; //create local variable for resistance
  float temp; //create local variable for temperature

  resistance=log(resistor*raw/(1024-raw)); //calculate resistance
  temp = 1 / (0.000643671 + (0.000224785 * resistance) + (0.00000008 * resistance * resistance * resistance)); //calculate temperature using the Steinhart-Hart equation
  temp = temp - 273.15; //Convert Kelvin to Celsius                      
  return temp; //return the temperature
}
