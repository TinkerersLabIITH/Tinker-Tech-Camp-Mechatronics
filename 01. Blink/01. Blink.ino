/**
 * Tinkerers' Laboratory IIT Hyderabad
 * 
 * Tinker Tech Camp 
 * Mechatronics Edition
 * 14 Feb 2026 - 15 Feb 2026
 * 
 * Exercise 01: Blink
 * 
 */

// declare the pins
const int LED = 6;

// delay time in milliseconds
// this is the time for which the LED will be on or off
// in this case, it is set to 50 milliseconds
// you can change this value to make the LED blink faster or slower
const int hold = 50;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(LED, HIGH); // turn the LED on
  delay(hold);             // wait for hold milliseconds
  digitalWrite(LED, LOW);  // turn the LED off
  delay(hold);             // wait for hold milliseconds
}
