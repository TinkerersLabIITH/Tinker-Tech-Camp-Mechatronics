int transistorPin = 3; 

void setup() {
  pinMode(transistorPin, OUTPUT);
}

void loop() {
  digitalWrite(transistorPin, HIGH); // switch ON
  delay(1000);
  digitalWrite(transistorPin, LOW);  // switch OFF
  delay(1000);
}
