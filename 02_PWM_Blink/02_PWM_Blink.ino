/**
 * Tinkerers' Laboratory IIT Hyderabad
 * 
 * Tinker Tech Camp 
 * Mechatronics Edition
 * 14 Feb 2026 - 15 Feb 2026
 * 
 * Exercise 02 : PWM Blink
 * 
 */

int output=9;   //Pin-9 is declared as output for LED

void setup()                                                          
{
	pinMode(output, OUTPUT); //Pin-9 is declared as output 
//We dont need to declare the A0 pin as input since it is predefined as input                                                
}

void loop()
{ 
	int delay_ms = 50; 
  	for(int brightness=0; brightness<=100; brightness+=10) { // loop to increase brightness from 0% to 100% in steps of 10%
		// set percentage of brightness

		// delay time in milliseconds
		

		// analogWrite argument must be between 0 and 255
		// so convert percentage to value between 0 and 255
		analogWrite(output, 255*brightness/100);    
		//Finally outputting the read value on pin-9 fading LED

		delay(delay_ms); // wait for delay milliseconds
		analogWrite(output, 0); // turn the LED off
		delay(delay_ms); // wait for delay milliseconds
	}
}  