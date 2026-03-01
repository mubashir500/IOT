int trig=11;
int echo=12;
int d=8;
long duration;
int dantance;
void setup() {
  // put your setup code here, to run once:
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  Serial.begin(9600);
}
void loop() {
  // put your main code here, to run repeatedly:             


  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  duration=pulseIn(echo, HIGH);
  dantance=duration*0.034/2;
  Serial.println(dantance);
  delay(100);



}

  


