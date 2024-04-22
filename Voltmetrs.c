#include <LiquidCrystal.h>

enum pinConfig  {
  signal_pin = 4,
  contrast_pin = 3,
};
/*
int readValue(int signal_pin) {
  // volts to 1,655
  return map(analogRead(signal_pin),0,1840,0,1570);
}
*/

//Create An LCD Object. Signals: [ RS, EN, D4, D5, D6, D7 ]
LiquidCrystal My_LCD(13, 33, 25, 26, 27, 14);
 
void setup()
{
  //Serial.begin(2000000);
  //Initialize The LCD. Parameters: [ Columns, Rows ]
  
  //pinMode(signal_pin,INPUT);
  //pinMode(contrast_pin,OUTPUT);

  My_LCD.begin(16, 2);
  // Clears The LCD Display
  My_LCD.clear();
  //My_LCD.setCursor(1, 1);
 
  //Display The First Message In Home Position (0, 0)
  
  // Set The Cursor Position To: [ Col 5, Row 1]
  // The Next Message Will Start From The 6th Char Position in The 2nd Row
  // Note: 1st Row Has An Index of 0, The 2nd Row Has An Index of 1
  //My_LCD.setCursor(5, 1);
  // Display The Second Message In Position (5, 1)
  //My_LCD.print("GG izi");
}
 
void loop()
{
  //readValue(signal_pin);
  int value = analogRead(signal_pin);
  // /1.1238;
  //Serial.println(value);
  My_LCD.print("Spriegums: ");
  My_LCD.setCursor(0, 1);
  My_LCD.print(value*1.182/1000);
  My_LCD.print(" V");
  My_LCD.setCursor(0, 0);
  

  //My_LCD.print(analogRead(signal_pin));
  //My_LCD.print(value/1);
  //My_LCD.print(".");
  //My_LCD.print(value%1);



  //My_LCD.print("Spriegums, V");
  //My_LCD.setCursor(0, 1);
  //My_LCD.print(value);

  delay(200);
  My_LCD.clear();
  

  
}
