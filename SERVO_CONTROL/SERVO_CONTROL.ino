#include <Servo.h>
Servo S1;
void setup() {
  // put your setup code here, to run once:
  S1.attach(3);
}

void loop() {
  // put your main code here, to run repeatedly:
  S1.write(0);
  delay(1000);
  S1.write(30);
  delay(1000);
  S1.write(60);
  delay(1000);
  S1.write(90);
  delay(1000);
  S1.write(120);
  delay(1000);
  S1.write(150);
  delay(1000);
  S1.write(180);
  delay(1000);

}
