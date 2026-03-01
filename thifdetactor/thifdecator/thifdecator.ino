int ir = 3;
int buzzer = 5;

void setup() {
  // put your setup code here, to run once:
  pinMode(ir, INPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);  
}

void loop() {
  // put your main code here, to run repeatedly:
  int irred = digitalRead(ir);
  Serial.println(irred);
  if (irred == 0){
    analogWrite(buzzer, 200);
    delay(30);
  }
  else
  {
    analogWrite(buzzer, 0);
  }

}
