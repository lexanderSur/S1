#include <Servo.h> // Подключение библиотеки Servo
Servo Servo1; // Создаем объект
const byte PS_128 = (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);
const byte PS_16 = (1 << ADPS2);
const int size1=1000;
int size2=size1/2;
byte signal1[size1], signal2[size1];
int servoPin = 9; // Пин для сервопривода

void setup(){
 ADCSRA &= ~PS_128;  // сбросить масштаб 128
 ADCSRA |= PS_16;    // добавить масштаб 16 (1 МГц)
 Serial.begin(250000);
 while (! Serial) {};
 Servo1.attach(servoPin); // Подключение сервопривод к используемому номеру пина
 Servo1.write(0); // положение 0 градусов
 delay(100);
 long startTime = micros();
 for (int i = 0; i < size1; i ++)
  {
   signal1[i]=analogRead(A0)>>2;
  }
 long endTime = micros()- startTime;
 float dt=endTime/size1/1000.0;
 for (int i = 0; i < size1; i ++)
  {
   float time1=i*dt;
   Serial.print(time1,3);
   Serial.print("\t");    
   Serial.println(signal1[i]);
  }
 }
 
void loop()
{
}
