/**
 * Tinkerers' Laboratory IIT Hyderabad
 * 
 * Tinker Tech Camp 
 * Mechatronics Edition
 * 14 Feb 2026 - 15 Feb 2026
 * 
 * Exercise 06: Transistor Switch
 * 
 */

int transistorPin = 3; 

void setup() {
  pinMode(transistorPin, OUTPUT);
}

void loop() {
  digitalWrite(transistorPin, HIGH); // switches ON
  delay(1000);
  digitalWrite(transistorPin, LOW);  // switch OFF
  delay(1000);
}
