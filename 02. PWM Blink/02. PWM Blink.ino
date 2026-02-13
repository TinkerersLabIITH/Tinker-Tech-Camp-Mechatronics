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
  	// set percentage of brightness
	int brightness = 50;

	// delay time in milliseconds
	int delay = 1000; 

	// analogWrite argument must be between 0 and 255
	// so convert percentage to value between 0 and 255
	analogWrite(output, 255*brightness/100);    
	//Finally outputting the read value on pin-9 fading LED

	delay(delay); // wait for delay milliseconds
	analogWrite(output, 0); // turn the LED off
	delay(delay); // wait for delay milliseconds

}  