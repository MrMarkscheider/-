#include <Adafruit_NeoPixel.h>             // подключаем библиотеку

 

#define PIN_1 6 // Это выход #6, куда подключено управление лентой.
#define PIN_2 3 
#define PIN_3 5 
#define PIN_4 9        

#define NUMPIXELS 16                            //Число светодиодов в ленте

Adafruit_NeoPixel strip_1 = Adafruit_NeoPixel(NUMPIXELS, PIN_1, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip_2 = Adafruit_NeoPixel(NUMPIXELS, PIN_2, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip_3 = Adafruit_NeoPixel(NUMPIXELS, PIN_3, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip_4 = Adafruit_NeoPixel(NUMPIXELS, PIN_4, NEO_GRB + NEO_KHZ800);

void setup() {

  strip_1.begin();
  strip_1.show(); 
  strip_2.begin();
  strip_2.show(); 
  strip_3.begin();
  strip_3.show();
  strip_4.begin();
  strip_4.show();

}

void loop() {
  
for (int i = 0; i < 8; i++)

   {

    strip_1.setPixelColor(i, strip_1.Color(255, 0, 0)); //Задний стоп сигнал
    
    strip_1.show();

   }
   for (int i = 8; i < 16; i++)

   {

    strip_1.setPixelColor(i, strip_1.Color(0, 0, 255)); //правая задняя подсветка
    
    strip_1.show();

   }
//////////////////////////////////////////////////////////////////   
 for (int i = 8; i < 16; i++)

   {
    
    strip_2.setPixelColor(i, strip_2.Color(255, 0, 0)); //Задний стоп сигнал
    
    strip_2.show();

   }
   for (int i = 0; i < 8; i++)

   {

    strip_2.setPixelColor(i, strip_2.Color(0, 0, 255)); //левая задняя подсветка
    
    strip_2.show();

   }
///////////////////////////////////////////////////////////////
   for (int i = 8; i < 16; i++)

   {
    
    strip_4.setPixelColor(i, strip_4.Color(0, 255, 0)); //Передние фары
    
    strip_4.show();

   }
   for (int i = 0; i < 8; i++)

   {

    strip_4.setPixelColor(i, strip_4.Color(0, 0, 255)); //левая передняя подсветка
    
    strip_4.show();

   }
///////////////////////////////////////////////////////////////////
   for (int i = 8; i < 16; i++)

   {
    
    strip_3.setPixelColor(i, strip_3.Color(0, 0, 255)); //Передние фары
    
    strip_3.show();

   }
   for (int i = 0; i < 8; i++)

   {

    strip_3.setPixelColor(i, strip_3.Color(0, 255, 0)); //правая передняя подсветка
    
    strip_3.show();

   }
////////////////////////////////////////////////////////////////////
//Мигаем крайними светодиодами
////////////////////////////////////////////////////////////////////

   if (round(millis()/500)% 5==0) {//Скорость мигания послежних 2 светодиодов
    
    for (int i = 0; i < 2; i++){

    strip_1.setPixelColor(i, strip_1.Color(255, 255, 255));// Зажигаем 2 крайних светика белым с зади
    
    strip_1.show();
    
   }
   for (int i = 12; i < 16; i++)

    { 

    strip_1.setPixelColor(i, strip_1.Color(0, 255, 0));// Зажигаем 4 крайних светика зеленым с права
    
    strip_1.show();
    
   }
   for (int i = 14; i < 16; i++)
///////////////////////////////////////////////////////////////////////////////
    { 

    strip_2.setPixelColor(i, strip_2.Color(255, 255, 255));// Зажигаем 2 крайних светика белым с зади
    
    strip_2.show();
    
   }
   for (int i = 0; i < 4; i++)

    { 

    strip_2.setPixelColor(i, strip_2.Color(0, 255, 0));// Зажигаем 2 крайних светика зеленым с лева
    
    strip_2.show();
    
   }
   ////////////////////////////////////////////////////////////////////////
   for (int i = 14; i < 16; i++)

    { 

    strip_4.setPixelColor(i, strip_4.Color(255, 255, 255));// Зажигаем 2 крайних светика белым с переди
    
    strip_4.show();
    
   }
   for (int i = 0; i < 4; i++)

    { 

    strip_4.setPixelColor(i, strip_4.Color(0, 255, 0));// Зажигаем 2 крайних светика зеленым с лева
    
    strip_4.show();
    
   }
   /////////////////////////////////////////////////////////////////
   for (int i = 12; i < 16; i++)

    { 

    strip_3.setPixelColor(i, strip_3.Color(0, 255, 0));// Зажигаем 2 крайних светика белым с переди
    
    strip_3.show();
    
   }
   for (int i = 0; i < 2; i++)

    { 

    strip_3.setPixelColor(i, strip_4.Color(255, 255, 255));// Зажигаем 2 крайних светика зеленым с права
    
    strip_3.show();
    
   }
   }
    

}
