#include <Servo.h>

int led1=10;
int led2=11;
int entryIrSensorPin = 8;
int exitIrSensorPin = 9;  
Servo S1;
 
int slot = 4;
int flag1=0;
int flag2=0;   

void setup() {
  Serial.begin(9600);
  
  
  pinMode(entryIrSensorPin, INPUT);
  pinMode(exitIrSensorPin, INPUT);
  S1.attach(7);
  
  S1.write(90);
}

void loop() {
  // put your main code here, to run repeatedly:

  if(digitalRead(entryIrSensorPin)==LOW && flag1==0){
    if(slot>0){
      flag1=1;
      S1.write(0);
      if(flag2==0){
      Serial.println("Car intering....");
      slot--;
      }
    }
  }

  if(digitalRead(exitIrSensorPin)==LOW && flag2==0){
        flag2=1;
        S1.write(0);
        if(flag1==0){
        Serial.println("Car exiting....");
        slot++;
        }
  }
  if(flag1==1 && flag2==1){
    delay(1000);
    S1.write(90);
    Serial.print("Avable slot :");
    Serial.println(slot);
    delay(1000);
    flag1=0;
    flag2=0;
  }
  if(slot<=0){
    digitalWrite(led1,LOW);
    digitalWrite(led2,HIGH);
  }
  else{
    digitalWrite(led1,HIGH);
    digitalWrite(led2,LOW);
  }


}
