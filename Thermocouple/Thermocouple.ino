// Этот пример является общедоступным.               // www.ladyada.net/learn/sensors/thermocouple
                                                     // Переведено www.iarduino.ru
#include      <max6675.h>                            // Подключаем библиотеку max6675 для работы с датчиком температуры 
const uint8_t thermoDO  = 4;                         // Определяем константу с указанием № вывода Arduino к которому подключён вывод DO  ( SO, MISO ) модуля на чипе MAX6675
const uint8_t thermoCS  = 5;                         // Определяем константу с указанием № вывода Arduino к которому подключён вывод CS  ( SS )       модуля на чипе MAX6675
const uint8_t thermoCLK = 6;                         // Определяем константу с указанием № вывода Arduino к которому подключён вывод CLK ( SCK )      модуля на чипе MAX6675
MAX6675       thermo(thermoCLK, thermoCS, thermoDO); // Объявляем объект thermo для работы с функциями и методами библиотеки MAX6675, указывая выводы ( CLK , CS , DO )
                                                     // 
void setup(){                                        // 
    Serial.begin(250000);                              // Инициируем передачу данных в монитор последовательного порта на скорости 9600 бит/сек
    delay(500);    
    for (int i=0; i <= 1200; i++){// продолжительность 20 минут
     float m1=0;
     for (int j=0; j <= 10; j++){
     float t1=thermo.readCelsius();
     m1 += t1;
     }
     float t1 = m1/10; // усреднение по 10 отсчётам
    Serial.print (i);       
    Serial.print ("\t"); 
    Serial.println(t1);    // Выводим температуру в °C
    delay(1000);
    }  
}                                                    //

void loop(){                                         //
  }                                                    //
