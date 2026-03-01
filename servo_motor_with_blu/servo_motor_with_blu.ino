#include <Servo.h>

Servo servo;
int angle = 5;      // Set minimum angle 5 degree
int servoPin = 9;   // attach servo motor to digital pin 9
byte incomingValue = 0;   // variable to store incoming bluetooth value

void setup() {
  Serial.begin(9600);
  servo.attach(servoPin);
  servo.write(10);
}
void loop() 

{ 
  if(Serial.available() > 0)
  {
    incomingValue = Serial.read();
    Serial.println(incomingValue);
    servo.write(incomingValue);
    delay(10);   
  }
}