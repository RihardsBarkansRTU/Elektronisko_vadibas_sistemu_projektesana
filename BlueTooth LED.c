#include "BluetoothSerial.h"// bluetooth biblioteka
String BT_Name= "Ierices_nosaukums";
BluetoothSerial ESP_BT;
String Text_Read_BT;

int led_pin = 26;

void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
ESP_BT.begin(BT_Name);
pinMode(led_pin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
//static String text;
if (ESP_BT.available())
  {
    Text_Read_BT=ESP_BT.readString();
     //text = Text_Read_BT;
    Serial.println("Text_Read_BT="+Text_Read_BT);
    Serial.println("456");
    if(Text_Read_BT == "ON")
    {
      digitalWrite(led_pin,1);
    }
    if(Text_Read_BT == "OFF")
    {
      digitalWrite(led_pin,0);
    }
  }
}
