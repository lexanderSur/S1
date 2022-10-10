const byte PS_128 = (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);
const byte PS_16 = (1 << ADPS2);
const int size1=1000;
byte signal1[size1];
int f=2000;// частота колебания
void setup()
{
 ADCSRA &= ~PS_128;  // сбросить масштаб 128
 ADCSRA |= PS_16;    // добавить масштаб 16 (1 МГц)
 Serial.begin(250000);
 while (! Serial) {};
 //pinMode(2, OUTPUT);
 //digitalWrite(2, HIGH);
 delay(100);
 tone(6, 2000, 100);
 long startTime = micros();
 for (int i = 0; i < size1; i ++)
  {
   signal1[i]=analogRead(A0)>>2;
   //delayMicroseconds(35);
   }
 long endTime = micros()- startTime;
 float dt=endTime/size1/1000.0;
 //digitalWrite(2, LOW);
 for (int i = 0; i < size1; i ++)
  {
   float time1=i*dt;
   Serial.print(time1,3);
   Serial.print("\t");    
   Serial.println(signal1[i]);
  }
  noTone(6);
 }
 
void loop()
{
}
