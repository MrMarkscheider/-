#include "HX711.h"                       // библиотека тензодатчика
#include <Wire.h>                        // Протокол I2C
#include <LiquidCrystal_I2C.h>           // Библиотека дисплея
HX711 scale(A1, A0);   

byte bukva_B[8]   = {B11110,B10000,B10000,B11110,B10001,B10001,B11110,B00000,}; // Буква "Б"
byte bukva_G[8]   = {B11111,B10001,B10000,B10000,B10000,B10000,B10000,B00000,}; // Буква "Г"
byte bukva_D[8]   = {B01111,B00101,B00101,B01001,B10001,B11111,B10001,B00000,}; // Буква "Д"
byte bukva_ZH[8]  = {B10101,B10101,B10101,B11111,B10101,B10101,B10101,B00000,}; // Буква "Ж"
byte bukva_Z[8]   = {B01110,B10001,B00001,B00010,B00001,B10001,B01110,B00000,}; // Буква "З"
byte bukva_I[8]   = {B10001,B10011,B10011,B10101,B11001,B11001,B10001,B00000,}; // Буква "И"
byte bukva_IY[8]  = {B01110,B00000,B10001,B10011,B10101,B11001,B10001,B00000,}; // Буква "Й"
byte bukva_L[8]   = {B00011,B00111,B00101,B00101,B01101,B01001,B11001,B00000,}; // Буква "Л"
byte bukva_P[8]   = {B11111,B10001,B10001,B10001,B10001,B10001,B10001,B00000,}; // Буква "П"
byte bukva_Y[8]   = {B10001,B10001,B10001,B01010,B00100,B01000,B10000,B00000,}; // Буква "У"
byte bukva_F[8]   = {B00100,B11111,B10101,B10101,B11111,B00100,B00100,B00000,}; // Буква "Ф"
byte bukva_TS[8]  = {B10010,B10010,B10010,B10010,B10010,B10010,B11111,B00001,}; // Буква "Ц"
byte bukva_CH[8]  = {B10001,B10001,B10001,B01111,B00001,B00001,B00001,B00000,}; // Буква "Ч"
byte bukva_Sh[8]  = {B10101,B10101,B10101,B10101,B10101,B10101,B11111,B00000,}; // Буква "Ш"
byte bukva_Shch[8]= {B10101,B10101,B10101,B10101,B10101,B10101,B11111,B00001,}; // Буква "Щ"
byte bukva_Mz[8]  = {B10000,B10000,B10000,B11110,B10001,B10001,B11110,B00000,}; // Буква "Ь"
byte bukva_IYI[8] = {B10001,B10001,B10001,B11001,B10101,B10101,B11001,B00000,}; // Буква "Ы"
byte bukva_Yu[8]  = {B10010,B10101,B10101,B11101,B10101,B10101,B10010,B00000,}; // Буква "Ю"
byte bukva_Ya[8]  = {B01111,B10001,B10001,B01111,B00101,B01001,B10001,B00000,}; // Буква "Я"

const int numReadings = 10;
float readings[numReadings];      // Массив чтения по аналоговому входу
int index = 0;                    // Номер текущего чтения
float total = 0;                  // Всего считано
float average = 0;                // Среднее
float i = 0;// - Вывод значения на индикатор
float a = 0;
float currentValue = 0;

//float calibration_factor = -15.9;       // калибровочная константа тензодатчика для весов 5кг
float calibration_factor = -224.5;        // калибровочная константа тензодатчика-216.7для СТЕНДА -224,5 при длине луча 735 мм
float units;


LiquidCrystal_I2C lcd(0x3F,16,2);  // Устанавливаем дисплей

void setup() 
{
 
  lcd.init();               // инициализация ЖК дисплея                   
  lcd.backlight();          // Включаем подсветку дисплея
  
  scale.set_scale();
  scale.tare();                              //Сбрасываем на 0
  scale.set_scale(calibration_factor);       //Применяем калибровку

  

  lcd.createChar(1, bukva_Ya);      // Создаем символ под номером 1
  lcd.createChar(2, bukva_G);       // Создаем символ под номером 2
  lcd.createChar(3, bukva_I);       // Создаем символ под номером 3
  
  //lcd.setCursor(3, 0);         // перевод курсора 
  //lcd.print("TECTEP BM\2");    // пишем ТЕСТЕР ВМГ
 
  //lcd.setCursor(0, 1);    // перевод курсора на строку 1, символ 5
  //lcd.print("T\1\2A");    // пишем Тяга
  lcd.setCursor(15, 1);   // перевод курсора на строку 2, символ 11
  lcd.print("\2");    // пишем Грамм 

  lcd.setCursor(6, 0);    // перевод курсора 
  lcd.print("V");         // пишем Вольт 
  lcd.setCursor(15, 0);   // перевод курсора 
  lcd.print("A");         // пишем Ампер 
  lcd.setCursor(6, 1);   // перевод курсора 
  lcd.print("W");         // пишем Ампер 
}
void loop()
{            
          //Измеряем все что есть
  
  float total_gr = 0.0;             //Переменная тяги
  uint16_t total_i = 0;             //переменная тока
  uint16_t total_u = 0;             //переменная напряжения
  for (uint8_t i = 0; i < 10; i++)  // условие  цикла сложения
   {
   total_gr += scale.get_units(1);   //Суммирование граммов
   total_i += analogRead(6);         //Суммирование тока
   total_u += analogRead(7);         //Суммирование напряжения
   }

          //вычисляем среднее значение
          
float real_gr = total_gr / 10;
float real_i = (float(total_i) / 10 - 512.0)*5.0/1024/0.0133;
float real_u = float(total_u) / 10 * 0.027425;
  
  
  float wAt = float(real_i * real_u) ;     //Считаем мощность

  float gRwAt;
  
 if(wAt > 2) 
     {
     gRwAt =real_gr / wAt ;     //Считаем эффективность
     }
    else  
     {
     gRwAt = 0.0 ;     //выводим ноль
     }
  
  
  char myStr[6];                                // текстовый массив для текста
  
  dtostrf(real_u, 5, 1, myStr);                 //Подготовка 5 знакомест
  lcd.setCursor(0, 0);                          //Переводим курсор
  lcd.print(myStr);                             //выводим значение вольт

  dtostrf(real_i, 5, 1, myStr);                 //Подготовка 5 знакомест
  lcd.setCursor(8, 0);                          //Переводим курсор
  lcd.print(myStr);                             //выводим значение тока

  dtostrf(wAt, 4, 0, myStr);                    //Подготовка 5 знакомест
  lcd.setCursor(0, 1);                          //Переводим курсор
  lcd.print(myStr);                             //выводим значение мощности

  dtostrf(real_gr, 4, 0, myStr);                //Подготовка 5 знакомест
  lcd.setCursor(10, 1);                          //Переводим курсор
  lcd.print(myStr);                             //выводим значение тяга грамм

  dtostrf(gRwAt, 4, 1, myStr);                  //Подготовка 5 знакомест
  lcd.setCursor(5, 1);                          //Переводим курсор
  lcd.print(myStr);                             //выводим значение грамм/ватт
}
