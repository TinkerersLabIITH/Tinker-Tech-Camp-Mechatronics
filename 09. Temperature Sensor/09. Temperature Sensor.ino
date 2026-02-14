/**
 * Tinkerers' Laboratory IIT Hyderabad
 * 
 * Tinker Tech Camp 
 * Mechatronics Edition
 * 14 Feb 2026 - 15 Feb 2026
 * 
 * Exercise 09: Temperature Sensor
 * 
 */


#include <dht.h>
//Header file for DHT sensor library, which provides functions to read temperature and humidity from DHT sensors
dht DHT;

int sensor_pin = 7;
//pin attached to sensor data pin, which will be used to read the sensor values

void setup(){
  Serial.begin(9600);
}

void loop()
{
  //to get the temperature and humidity values, we call the read11 function of the DHT library
  //it reads from a DHT11 sensor 
  //the function returns a status code that indicates whether the reading was successful or if there was an error (like checksum failure or timeout). 
  //after reading, we print the temperature and humidity values to the Serial Monitor
  //we add a delay of 4 seconds before the next reading to avoid flooding the Serial Monitor with data
  //DHT sensors have a recommended reading interval of 2-5 seconds.

  int chk = DHT.read11(sensor_pin);
  Serial.print("Temperature = ");
  Serial.print(DHT.temperature);
   Serial.println();
 
  Serial.print("Humidity = ");
  Serial.print(DHT.humidity);
   Serial.println();
   Serial.println();
  delay(4000); 
}
