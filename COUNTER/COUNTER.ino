int trig=3;
int echo=A0;
int buzz=8;
long duration;
int distance;
int pstate=0;
int cstate=0;
int count=0;

void setup() {
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(buzz, OUTPUT);
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
  distance=duration*0.034/2;
  delay(100);
  
  if (distance<10){
    cstate=1;
  } 
  else{
    cstate=0;
  }
  if (cstate!=pstate){
    if (cstate==1){
      digitalWrite(buzz,HIGH);
      count=count+1;
      Serial.print("Object: ");
      Serial.println(count);
      pstate=cstate;
    }
    else{
      digitalWrite(buzz,LOW);
      pstate=cstate;
    }
  }
}