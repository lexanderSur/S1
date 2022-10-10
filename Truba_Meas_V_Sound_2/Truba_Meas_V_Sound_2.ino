const byte PS_128 = (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);
const byte PS_16 = (1 << ADPS2);
const int size1 = 450; // размер массива для записи сигнала
const int size2 = 100; // число точек частоты
int i, j, f;
int fmin1=430;
int df=10;
byte signal1[size1];// массив сигнала
float ampl[size2];// массив значений частоты
float sd, delta, meansig;

void setup() {
  ADCSRA &= ~PS_128;  // сбросить масштаб 128
  ADCSRA |= PS_16;    // добавить масштаб 16 (1 МГц)
  Serial.begin(250000);
  while (! Serial) {};
  
  for (j = 0; j < size2; j ++)// цикл изменения частоты
  {
    int f = fmin1 + j * df;// расчёт текущей частоты
    tone(2, f, 35); // генерация сигнала
    delay(10);
    for (i = 0; i < size1; i ++)
    {
      signal1[i] = analogRead(A0) >> 2;
      delayMicroseconds(24);
    }
    noTone(2);// отключение генерации сигнала
    delay(80);
    for (i = 0; i < size1; i ++)
    {
    // Serial.print(i);
    //Serial.print("\t");
    //Serial.println(signal1[i]);
    }
    meansig = 0;
    for (i = 0; i < size1; i ++) meansig += signal1[i];
    meansig = meansig / size1; // расчёт среднего значения сигнала
    sd = 0;
    for (int i = 0; i < size1; i ++)
     {
      delta = signal1[i] - meansig; // отклонение от среднего
      sd += delta * delta; // расчёт суммы квадратов отклонений
     }
    sd = sqrt(sd / (size1 - 1)); // расчёт среднеквадратичного отклонения
    ampl[j] = sd;
   
   }
  for (j = 0; j < size2; j ++)
  {
    f = fmin1 + j * df;
    Serial.print(f);
    Serial.print("\t");
    Serial.println(ampl[j]);
  }
}

void loop() {
}
