// sketch 04_11_analog_fast
const byte PS_128 = (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);
const byte PS_16 = (1 << ADPS2);
int signal1[500];// int signal1[250];
float du=5.0/1024.0;//, sig1, t, dt;
#include <Servo.h>

Servo myservo;  // create servo object to control a servo

void setup()
{
//myservo.attach(9);
ADCSRA &= ~PS_128;  // сбросить масштаб 128
ADCSRA |= PS_16;    // добавить масштаб 16 (1 МГц)
Serial.begin(250000);
while (! Serial) {};
//Serial.println(PS_128, 2);
//Serial.println(PS_16, 2);
//Serial.println("Starting Test");
//myservo.write(0);
long startTime = micros();
// Далее следует код тестирования
float mean;
for (int i = 0; i < 100; i ++)
mean+=analogRead(A0);
long endTime = micros()-startTime;
//float mean=0;
//for (int i = 0; i < 100; i ++)
//mean = mean + signal1[i];
mean = mean/100;
Serial.println(mean,3);
//float du1 = signal1[i]* du;
//Serial.print(i); 
//Serial.print("\t"); 
//int du=signal2[i];   
//Serial.println(du1,3);
//}
float dt=endTime/100.0;
Serial.println(dt);
}

void loop()
{
}
