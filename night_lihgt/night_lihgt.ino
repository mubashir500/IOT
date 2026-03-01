int ldr = A1;
int led = 3;

void setup() {
  // put your setup code here, to run once:

  pinMode(ldr, INPUT);
  pinMode(led, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

  int ldrread = analogRead(ldr);
  Serial.println(ldrread);
  if (ldrread>850){
    digitalWrite(led, HIGH);
  }

  else{
    digitalWrite(led, LOW);
  }
    delay(200);

}
