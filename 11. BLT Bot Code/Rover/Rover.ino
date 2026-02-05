/** TINKERERS' LABORATORY IIT HYDERABAD
 *  TINKER TECH CAMP 2025
 *  MECHATRONICS EDITION
 *
 *  Date: 6th Sep, 2025
 *  Time: 00:15
 */

//Header Inclusions:
#include <HCSR04.h>
#include <Servo.h>
#include <SoftwareSerial.h>
#include "dht.h"

// dht object
dht DHT;
const int DHT_Pin = 13;

//Motor Pins:
const int Motor_L_F = 8;
const int Motor_L_B = 9;
const int Motor_R_F = 10;
const int Motor_R_B = 11;

// Ultrasonic Sensor Components Definition:
#define Echo  6
#define Trig  7

// Ultrasonic Sensor Input Declaration:
int Front_D = 0;
int Left_D = 0;
int Right_D = 0;
// Max distance to obastacle:
int Max_D = 25;

UltraSonicDistanceSensor distanceSensor(Trig, Echo);  
// Initializing sensor

SoftwareSerial BT(2, 3); // RX, TX
int BT_input;
char BTI;

int chk;

Servo Servo_1;  // create servo object to control a servo
int pos = 0;    // variable to store the servo position

const int debug = 1;

int temp, humidity, dist;

void setup() 
{
  Serial.begin(9600);
  BT.begin(9600);

  // Define Motor Pin as output
  pinMode(Motor_L_F, OUTPUT);
  pinMode(Motor_L_B, OUTPUT);
  pinMode(Motor_R_F, OUTPUT);
  pinMode(Motor_R_B, OUTPUT);
  pinMode(DHT_Pin, INPUT);

  Servo_1.attach(5);  
  // attaches the servo on pin 9 to the servo object
  int pos = 90;
  Servo_1.write(pos);
  delay(1000);

}

void loop() 
{
  if (BT.available())
  {   
   BTI = BT.read();
   if(debug) {
    Serial.print("Recieved: ");
    Serial.println(BTI);
   }
   switch (BTI)
   {
      case 'F':
      Forward();
      if(debug) Serial.println("Moving Forward");
      break;

      case 'B':
      Back();
      if(debug) Serial.println("Moving Backward");
      break;

      case 'R':
      Right();
      if(debug) Serial.println("Moving Right");
      break;

      case 'L':
      Left();
      if(debug) Serial.println("Moving Left");
      break;

      case 'S':
      Stop();
      if(debug) Serial.println("Moving Stop");
      break;

      // Get Temp
      case 'T':
      chk = DHT.read11(DHT_Pin);
      temp = DHT.temperature;
      BT.print(temp);
      if(debug) {
        Serial.print("Temperature: ");
        Serial.println(temp);
      }
      break;

      // Get Humidity
      case 'H':
      chk = DHT.read11(DHT_Pin);
      humidity = DHT.humidity;
      BT.print(humidity);
      if(debug) {
        Serial.print("Humidity: ");
        Serial.println(humidity);
      }
      break;

      // Get Distance
      case 'D':
      dist = distanceSensor.measureDistanceCm();
      BT.print(dist);
      if(debug) {
        Serial.print("Distance: ");
        Serial.println(dist);
      }
      break;

      // move servo pos left
      case 'l':
      pos += 5;
      pos = pos > 180 ? 180 : pos; 
      Servo_1.write(pos);
      if(debug) {
        Serial.print("Servo left, theta: ");
        Serial.println(pos);
      }
      break;

      // move servo pos right
      case 'r':
      pos -= 5;
      pos = pos < 0 ? 0 : pos; 
      if(debug) {
        Serial.print("Servo right, theta: ");
        Serial.println(pos);
      }
      Servo_1.write(pos);
      break;

      default:
      Stop();
   }
   }

}


void Forward()
{
  // Run Left Motor In Forward Direction
  digitalWrite(Motor_L_F, HIGH);
  digitalWrite(Motor_L_B, LOW);

  //Run Right Motor in Forward Direction
  digitalWrite(Motor_R_F, HIGH);
  digitalWrite(Motor_R_B, LOW);
  delay(500);
  
  digitalWrite(Motor_L_F, LOW);
  digitalWrite(Motor_L_B, LOW);

  digitalWrite(Motor_R_F, LOW);
  digitalWrite(Motor_R_B, LOW);

}

void Right()
{
  //Stop Right Motor
  digitalWrite(Motor_R_F, LOW);
  digitalWrite(Motor_R_B, LOW);

  //Run Left Motor in Forward Direction
  digitalWrite(Motor_L_F, HIGH);
  digitalWrite(Motor_L_B, LOW);
  delay(100);

  digitalWrite(Motor_L_F, LOW);
  digitalWrite(Motor_L_B, LOW);

  digitalWrite(Motor_R_F, LOW);
  digitalWrite(Motor_R_B, LOW);

}

void Left()
{
  //Stop Left Motor
  digitalWrite(Motor_L_F, LOW);
  digitalWrite(Motor_L_B, LOW);

  //Run Right Motor in Forward Direction
  digitalWrite(Motor_R_F, HIGH);
  digitalWrite(Motor_R_B, LOW);
  delay(100);

  digitalWrite(Motor_L_F, LOW);
  digitalWrite(Motor_L_B, LOW);

  digitalWrite(Motor_R_F, LOW);
  digitalWrite(Motor_R_B, LOW);

}

void Back()
{
  // Run Left Motor In Forward Direction
  digitalWrite(Motor_L_F, LOW);
  digitalWrite(Motor_L_B, HIGH);

  //Run Right Motor in Forward Direction
  digitalWrite(Motor_R_F, LOW);
  digitalWrite(Motor_R_B, HIGH);
  delay(500);

  digitalWrite(Motor_L_F, LOW);
  digitalWrite(Motor_L_B, LOW);

  digitalWrite(Motor_R_F, LOW);
  digitalWrite(Motor_R_B, LOW);

}

void Stop()
{
  // Run Left Motor In Forward Direction
  digitalWrite(Motor_L_F, LOW);
  digitalWrite(Motor_L_B, LOW);

  //Run Right Motor in Forward Direction
  digitalWrite(Motor_R_F, LOW);
  digitalWrite(Motor_R_B, LOW);
}
