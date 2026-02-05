int ButtonPin = 2;
int LEDPin = 8;

int flag = 0;

void setup()
{
  pinMode(ButtonPin, INPUT);
  pinMode(LEDPin, OUTPUT);
}

void loop()
{
  int button = digitalRead(ButtonPin);
  if(button)
  {
    if(flag == 0){
      digitalWrite(LEDPin, HIGH);
  	  flag = 1;
    }
    else{
      digitalWrite(LEDPin, LOW);
  	  flag = 0;
    }
  }
  delay(500);
}