/* VernierSD_Mean_From_N
 * Этот скетч рассчитывает зависимость средеквадратичного значения
 * среднего в зависимости от числа усредняемых отсчётов. 
 * Зависимость может быть рассчитана как для исходных значений
 * датчиков (в единицах АЦП) при их подключении к порту Analog 2, так
 * и в единицах измеряемых величин при подключении к порту Analog 1. 
 * В скетче задаются минимально и максимально число усредняемых 
 * выборок и число средних значений для расчёта СКО.
 * Для работы Монитора порта на скорости 115200 необходимо
 * выбрать в нём соответствующую опцию
 */
const int jm1=2; // минимальное число усредняемых выборок 
const int jm2=30; // максимальное число усредняемых выборок
const int km=50; // число средних значений для расчёта СКО
int i, k, jm; float mean[61]; float sum, sum1, meank, sd, delta;

void setup() {
  Serial.begin(250000); // устанавливает скорость передачи данных
 
  for (jm = jm1; jm <= jm2; jm++)// цикл изменения числа
    // усредняемых отсчётов
   { 
   sum1=0;
   for (k = 1; k <= km; k++)// цикл накопления средних 
    // значений для расчёта СКО среднего
    {
    sum=0; 
    for (i = 1; i <= jm; i++)
     {
     sum = sum + analogRead(A0)*5.0/1024.0; // накапливает сумму показаний датчика
     // для расчёта в единицах АЦП необходимо заменить
     // Vernier.readSensor()на analogRead(A2) 
     }
    meank = sum/jm; // рассчитывает среднее 
    sum1 = sum1 + meank; // накапливает сумму средних значений 
    mean[k] = meank;// запоминает средние значения в массиве
    }
    meank = sum1/km; // рассчитывает среднее средних значений
    sd=0;
    for (k = 1; k <= km; k++)
     {
      delta = mean[k]-meank; // находит отклонение от среднего 
      sd = sd + delta*delta; // накапливает сумму квадратов отклонений
     }
    sd = sqrt(sd/(km-1));// находит среднеквадратичное отклонение
   
   Serial.print(jm); // выводит количество усредняемых отсчётов
   Serial.print("\t");
   Serial.println(sd,4); // выводит СКО
   }
}
void loop() {
}