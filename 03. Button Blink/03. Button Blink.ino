/**
 * Tinkerers' Laboratory IIT Hyderabad
 * 
 * Tinker Tech Camp 
 * Mechatronics Edition
 * 14 Feb 2026 - 15 Feb 2026
 * 
 * Exercise 03: Button Blink
 * 
 */


//declare the pins
int ButtonPin = 2;
int LEDPin = 8;

int flag = 0;

//flag is to keep count of the number of times the button is pressed
//if the button is pressed for the first time, flag will be 0 and the LED will be turned on
//if the button is pressed for the second time, flag will be 1 and the LED  will be turned off

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