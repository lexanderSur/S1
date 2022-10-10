int trigPin = 4; // Укажем подключение выводов к пинам 
int echoPin = 2; 
int duration, distance; 

void setup() {
 Serial.begin(250000);
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
  
  for (int i=0; i <= 200; i++){
  digitalWrite(trigPin, LOW); // инициализируем пин Trig
  delayMicroseconds(2); 
  digitalWrite(trigPin, HIGH); // теперь установим высокий уровень на пине Trig
  delayMicroseconds(10); // ожидание 10 μs
  digitalWrite(trigPin, LOW); //установим низкий уровень на пине Trig
  duration = pulseIn(echoPin, HIGH); // длительность сигнала на пине Echo
  float dt = i*0.05;
  int sensorValue = analogRead(A0);
  float voltage = sensorValue *(5.0/1023.0);
  float R=26.85*pow(voltage, -1.19);
  Serial.print(dt); 
  Serial.print("\t"); 
  float distance = duration/58.0; // рассчитаем расстояние
  Serial.print(R,1);
  Serial.print("\t");  
  Serial.println(distance,1); // выведем значение в Монитор порта
  delay(50); 
  }
}

void loop() {  
}
