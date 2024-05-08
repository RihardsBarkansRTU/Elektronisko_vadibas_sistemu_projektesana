#include <math.h>

#define DAC1 25

void setup() {
  Serial.begin(115200);
}

void loop(void) {

  static float start_periods = millis();
  static float perioda_laiks = 0;
  float end_periods = 0;
  static float i = 0;
  static float value = 0;
  static float periodi = 0;
  value = (1+sin(i))*127.5;
  //dacWrite(DAC1, value);
  Serial.print("Vērtība: ");
  Serial.println(value);
  delay(2);

  i=i+0.1;
  if(i>3.1415*2)
  {
    i=0;
    periodi++;
    if (periodi == 1)
    {
      end_periods = millis();
      perioda_laiks = end_periods - start_periods;
    }
  }
  if(perioda_laiks != 0)  Serial.println(perioda_laiks);
  
}

//pievienot Hz mērvienības
