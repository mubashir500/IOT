int motor1f = 5;
int motor1b = 6;
int motor2f = 9;
int motor2b = 10;
void setup() {
  // put your setup code here, to run once:
  pinMode(motor1f, OUTPUT);
  pinMode(motor1b, OUTPUT);
  pinMode(motor2f, OUTPUT);
  pinMode(motor2b, OUTPUT);
}
void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(motor1f, HIGH);
  digitalWrite(motor1b, LOW);
  digitalWrite(motor2f, HIGH);
  digitalWrite(motor2b, LOW);
  delay(3000);
  digitalWrite(motor1f, LOW);
  digitalWrite(motor1b, LOW);
  digitalWrite(motor2f, LOW);
  digitalWrite(motor2b, LOW);
  delay(2000);
  digitalWrite(motor1f, HIGH);
  digitalWrite(motor1b, LOW);
  digitalWrite(motor2f, LOW);
  digitalWrite(motor2b, HIGH);
  delay(500);
}
