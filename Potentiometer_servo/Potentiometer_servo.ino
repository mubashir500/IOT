#include <Servo.h>

Servo myServo;
int potPin = A0;

void setup() {
  myServo.attach(9); // D9 for PWM servo
  Serial.begin(9600);
}

void loop() {
  int potValue = analogRead(potPin); // 0 to 1023
  int angle = map(potValue, 0, 1023, 0, 180);
  myServo.write(angle);
  
  Serial.print("Pot Value: ");
  Serial.print(potValue);
  Serial.print(" -> Servo Angle: ");
  Serial.println(angle);

  delay(10);
}
