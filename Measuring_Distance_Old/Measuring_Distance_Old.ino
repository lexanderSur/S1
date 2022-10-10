int trigPin = 4; // Укажем подключение выводов к пинам 
int echoPin = 2; 
int duration, distance; 

void setup() {
 Serial.begin(115200);
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
  
  for (int i=0; i <= 100; i++){
  digitalWrite(trigPin, LOW); // инициализируем пин Trig
  delayMicroseconds(2); 
  digitalWrite(trigPin, HIGH); // теперь установим высокий уровень на пине Trig
  delayMicroseconds(10); // ожидание 10 μs
  digitalWrite(trigPin, LOW); //установим низкий уровень на пине Trig
  duration = pulseIn(echoPin, HIGH); // длительность сигнала на пине Echo
  Serial.print(i); 
  Serial.print("\t"); 
  float distance = duration/58.0; // рассчитаем расстояние
  Serial.println(distance,1); // выведем значение в Монитор порта
  delay(50); 
  }
}

void loop() { 
  
}
