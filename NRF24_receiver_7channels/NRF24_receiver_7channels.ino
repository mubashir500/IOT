#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <Servo.h>

RF24 radio(9, 10);
const uint64_t pipe = 0xE8E8F0F0E1LL;

struct Data {
  byte throttle;
  byte steering;
};

Data data;

Servo steeringServo;

unsigned long lastSignalTime = 0;

const int ENA = 5;  // PWM
const int IN1 = 6;
const int IN2 = 7;

void setup() {
  Serial.begin(9600);  // Start Serial Monitor

  steeringServo.attach(3);
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  radio.begin();
  radio.setAutoAck(false);
  radio.setDataRate(RF24_250KBPS);
  radio.openReadingPipe(1, pipe);
  radio.startListening();
}

void loop() {
  if (radio.available()) {
    radio.read(&data, sizeof(data));
    lastSignalTime = millis();

    Serial.print("Received Throttle: ");
    Serial.print(data.throttle);
    Serial.print(" | Steering: ");
    Serial.println(data.steering);
  }

  if (millis() - lastSignalTime > 1000) {
    stopMotor();
    Serial.println("Signal Lost! Motor Stopped.");
    return;
  }

  int angle = map(data.steering, 0, 255, 0, 180);
  steeringServo.write(angle);

  int throttleMid = 127;
  int deadZone = 10;

  if (data.throttle > throttleMid + deadZone) {
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    int speed = map(data.throttle, throttleMid + deadZone, 255, 0, 255);
    analogWrite(ENA, speed);
    Serial.println("Moving Forward");
  } 
  else if (data.throttle < throttleMid - deadZone) {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    int speed = map(data.throttle, throttleMid - deadZone, 0, 0, 255);
    analogWrite(ENA, speed);
    Serial.println("Moving Reverse");
  } 
  else {
    stopMotor();
    Serial.println("Stopped (Neutral)");
  }
}

void stopMotor() {
  analogWrite(ENA, 0);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
}
