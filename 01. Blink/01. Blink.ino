// declare the pins
const int LED = 6;

const int hold = 50;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int brightness = 0; brightness <= 255; brightness = brightness + 10) {
    analogWrite(LED, brightness);
    delay(hold);
    // analogWrite(LED, 0);
    // delay(hold);
  }
}
