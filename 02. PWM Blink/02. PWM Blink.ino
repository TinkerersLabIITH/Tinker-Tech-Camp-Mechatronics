int output=9;   //Pin-9 is declared as output

void setup()                                                          
{
	pinMode(output, OUTPUT); //Pin-9 is declared as output 
//We dont need to declare the A0 pin as input since it is predefined as input                                                
}

void loop()
{ 
  	int brightness = 50;
	analogWrite(output, 255*brightness/100);    //Finally outputting the read value on pin-9 fading led
}  