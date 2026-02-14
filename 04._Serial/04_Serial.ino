/**
 * Tinkerers' Laboratory IIT Hyderabad
 * 
 * Tinker Tech Camp 
 * Mechatronics Edition
 * 14 Feb 2026 - 15 Feb 2026
 * 
 * Exercise 04: Serial Printing
 * 
 */

 int i;

// the int i will be incremented and printed in the loop 

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  i = 0;
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("Hello World ");
  Serial.println(i++);
  delay(1000);
}
