const int LED_R = 7;
const int LED_B = 8;

String command = "";  // to store the incoming command

void setup() {
  Serial.begin(9600);    // start Serial at 9600 baud
  pinMode(LED_R, OUTPUT);
  pinMode(LED_B, OUTPUT);
  Serial.println("Commands: LEDR, LEDB, LEDOFF");
}

void loop() {
  // Check if data is available from Serial
  if (Serial.available() > 0) {
    char c = Serial.read();  // read one character

    // End of line means command is complete
    if (c == '\n') {
      processCommand(command); // handle the command
      command = "";            // reset string
    } 
    else {
      command += c;  // build up the string
    }
  }
}

void processCommand(String cmd) {
  cmd.trim(); // remove whitespace

  Serial.println(cmd);
  if (cmd == "LEDR") {
    Serial.println("Turning RED LED ON");
    digitalWrite(LED_R, HIGH);
  } 
  else if (cmd == "LEDB") {
    Serial.println("Turning BLUE LED ON");
    digitalWrite(LED_B, HIGH);
  } 
  else if (cmd == "LEDOFF") {
    Serial.println("Turning both LEDs OFF");
    digitalWrite(LED_B, LOW);
    digitalWrite(LED_R, LOW);
  } 
  else {
    Serial.print("Unknown command: ");
    Serial.println(cmd);
  }
}