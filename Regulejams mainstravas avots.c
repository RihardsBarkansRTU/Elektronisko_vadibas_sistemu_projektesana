// https://www.instructables.com/ILI9341-Display-and-LOLIN-D32-Carrier-Board/ //sito majaslapu es (ne)taisiju (ja kas).c

#include <TFT_eSPI.h> // Hardware-specific library
#include <SPI.h>



TFT_eSPI tft = TFT_eSPI();       // Invoke custom library

#define TEXT_HEIGHT 20 // Height of text to be printed and scrolled
#define BOT_FIXED_AREA 0  // Number of lines in bottom fixed area (lines counted from bottom of screen)
#define TOP_FIXED_AREA 0  // Number of lines in top fixed area (lines counted from top of screen)
#define SIGNAL_PIN 27

uint16_t yStart = TOP_FIXED_AREA;
uint16_t yArea = 320 - TOP_FIXED_AREA - BOT_FIXED_AREA;
uint16_t yDraw = 320 - BOT_FIXED_AREA - TEXT_HEIGHT;
byte     pos[42];
uint16_t xPos = 0;

void setup() {
  Serial.begin(115200);
  randomSeed(analogRead(A0));
  tft.init();
  tft.setRotation(0);
  tft.fillScreen(ILI9341_BLACK);
  tft.setTextSize(4);
  tft.println("Frekvence [mHz]:");
}

void loop(void) {
  int xpos = 0;
  int ypos = 85;
  
  float freeze;
  static float frekvence = 0;
  static float perioda_sakums = millis();
  static float periods = 0;
  static float perioda_beigas = 0;
  static float i = 0;
  static float value = 0;
 
  tft.setTextColor(0x0000);
  tft.drawNumber(frekvence, xpos, ypos, 4);
  
  freeze = analogRead(SIGNAL_PIN);
  freeze = freeze / 38.3;


  value = (1+sin(i))*127.5;
  i=i+0.1;
  if(i>3.1415*2)
  {
    i = 0;
    perioda_beigas = millis();
    periods = perioda_beigas - perioda_sakums;
    frekvence = (1000/periods);
    frekvence = frekvence * 1000;
    perioda_sakums = millis();
  }
  Serial.println(value);
  Serial.println(periods);
  Serial.println(frekvence);
  Serial.println("-----");

  tft.setTextColor(0xFFFF);
  tft.drawNumber(frekvence, xpos, ypos, 4);
  delay(freeze);
}
