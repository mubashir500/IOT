#include <Servo.h>
Servo hll;
void setup() {
  // put your setup code here, to run once:
  hll.attach(4);
}

void loop() {
  // put your main code here, to run repeatedly:
  hll.write(0);
  delay(1000);
  hll.write(90);
  delay(1000);
  hll.write(180);
  delay(1000);
  
}
