#include <SoftwareSerial.h>

SoftwareSerial BT(10, 11); //RX TX

void setup() 
{
  Serial.begin(9600);   // PC serial
  BT.begin(9600);       // Bluetooth default baud

  Serial.println("Bluetooth Test Ready!");
}

void loop() 
{
  // From Bluetooth -> Serial Monitor
  if (BT.available())
  {
    char c = BT.read();
    Serial.write(c);
  }

  // From Serial Monitor -> Bluetooth
  if (Serial.available())
  {
    char c = Serial.read();
    BT.write(c);
  }
}
