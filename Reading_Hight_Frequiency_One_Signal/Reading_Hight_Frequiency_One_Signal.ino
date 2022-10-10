#include <Servo.h> // Подключение библиотеки Servo
Servo Servo1; // Создаем объект
const byte PS_128 = (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);
const byte PS_16 = (1 << ADPS2);
const int size1=1000;
int size2=size1/2;
byte signal1[size1], signal2[size1];
int f=2000;// частота колебания
int servoPin = 9; // Пин для сервопривода

void setup()
{
 ADCSRA &= ~PS_128;  // сбросить масштаб 128
 ADCSRA |= PS_16;    // добавить масштаб 16 (1 МГц)
 Serial.begin(250000);
 while (! Serial) {};
 //Serial.println(PS_128, 200);
 //Serial.println(PS_16, 2);
 Servo1.attach(servoPin); // Подключение сервопривод к используемому номеру пина
 //tone(6, 20, 50);
 //tone(7, 1000, 15);
 pinMode(2, OUTPUT);
 digitalWrite(2, HIGH);
  //Servo1.write(0); // положение 0 градусов
  //delay(100);
 long startTime = micros();
 for (int i = 0; i < size1; i ++)
  {
   signal1[i]=analogRead(A0)>>2;
   //delayMicroseconds(35);
   //signal2[i]=analogRead(A2)>>2;
   if (i==size2){
     digitalWrite(2, LOW); 
   }
  }
 long endTime = micros()- startTime;
 //digitalWrite(2, LOW);
 float dt=endTime/size1/1000.0;
 for (int i = 0; i < size1; i ++)
  {
   float time1=i*dt;
   Serial.print(time1,3);
   Serial.print("\t");    
   Serial.println(signal1[i]);
   //Serial.print("\t"); 
   //Serial.println(signal2[i]);
  }
  noTone(6);
 //Serial.println(endTime); 
 }
 
void loop()
{
}
