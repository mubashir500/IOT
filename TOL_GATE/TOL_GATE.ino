#include <Servo.h>

int led1=10;
int led2=11;
int entryIrSensorPin = 8; 
int exitIrSensorPin = 9;   
Servo S1;

int carCount = 0;   
int maxCars = 4;    

void setup() {
  Serial.begin(9600);
  
  
  pinMode(entryIrSensorPin, INPUT);
  pinMode(exitIrSensorPin, INPUT);
  S1.attach(7);
  
  S1.write(90);
}

void loop() {

  int entrySensorState = digitalRead(entryIrSensorPin);
  int exitSensorState = digitalRead(exitIrSensorPin);
  digitalWrite(led1,HIGH);   

  if (entrySensorState == LOW && carCount < maxCars) {
    Serial.println("Car detected at entrance!");
    S1.write(0);     
    delay(2000);  
    S1.write(90);
    carCount++;      
    Serial.print("Car entered. Total cars inside: ");
    Serial.println(carCount);
  }
  
  
  if (exitSensorState == LOW && carCount > 0) {
    Serial.println("Car detected at exit!");
    S1.write(0);
    delay(2000);
    S1.write(90);  
    carCount--; 
    digitalWrite(led2,LOW);
    Serial.print("Car exited. Total cars inside: ");
    Serial.println(carCount);

  }
  
  
  if (carCount >= maxCars) {
    Serial.println("No more car allow!!!");
    S1.write(90);
    digitalWrite(led1,LOW);
    digitalWrite(led2,HIGH);
    
  }
  
  delay(500);
}
