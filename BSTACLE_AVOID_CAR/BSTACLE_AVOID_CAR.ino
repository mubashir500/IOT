#include <Servo.h>

// Define servo motor pin
int servoPin = 5;
Servo servo_motor;

// Define motor control pins
int LeftMotorForward = 8;
int LeftMotorBackward = 9;
int RightMotorForward = 10;
int RightMotorBackward = 11;

// Define ultrasonic sensor pins
int trigPin = 7;
int echoPin = 6;

// Variables for duration and distance
long duration;
int distance;
int thresholdDistance = 30;

void setup() {
  Serial.begin(9600);

  // Motor control pins setup
  pinMode(LeftMotorForward, OUTPUT);
  pinMode(LeftMotorBackward, OUTPUT);
  pinMode(RightMotorForward, OUTPUT);
  pinMode(RightMotorBackward, OUTPUT);

  // Ultrasonic sensor pins setup
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // Servo motor setup
  servo_motor.attach(servoPin);
  servo_motor.write(90);  // Initial position
  delay(2000);  // Allow servo to settle
}

void loop(){
  measureDistance();

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance <= thresholdDistance) {
    avoidObstacle();
  } else {
    moveForward();
  }

  delay(100);  // Adjust as needed
}

void measureDistance() {
  // Trigger ultrasonic sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Measure the duration of the echo pulse
  duration = pulseIn(echoPin, HIGH);

  // Calculate distance in centimeters
  distance = duration * 0.034 / 2;

  // Handle out-of-range values
  if (distance == 0 || distance > 400) {
    distance = 400;  // Set to maximum distance (4 meters) if no echo or out of range
  }
}

void moveForward() {
  digitalWrite(LeftMotorForward, HIGH);
  digitalWrite(LeftMotorBackward, LOW);
  digitalWrite(RightMotorForward, HIGH);
  digitalWrite(RightMotorBackward, LOW);
}
void avoidObstacle() {
  moveStop();
  delay(300);
  moveBackward();
  delay(400);
  moveStop();
  delay(300);

  int distanceRight;
  lookRight();
  distanceRight = distance;  // Store the measured distance to the right

  delay(300);

  int distanceLeft;
  lookLeft();
  distanceLeft = distance;  // Store the measured distance to the left

  delay(300);

  if (distanceRight >= distanceLeft) {
    turnRight();
  } else {
    turnLeft();
  }

  moveStop();
}

void moveStop() {
  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(LeftMotorBackward, LOW);
  digitalWrite(RightMotorForward, LOW);
  digitalWrite(RightMotorBackward, LOW);
}
void moveBackward() {
  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(LeftMotorBackward, HIGH);
  digitalWrite(RightMotorForward, LOW);
  digitalWrite(RightMotorBackward, HIGH);
}

void turnRight() {
  digitalWrite(LeftMotorForward, HIGH);
  digitalWrite(LeftMotorBackward, LOW);
  digitalWrite(RightMotorForward, LOW);
  digitalWrite(RightMotorBackward, HIGH);
  delay(500);
}

void turnLeft() {
  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(LeftMotorBackward, HIGH);
  digitalWrite(RightMotorForward, HIGH);
  digitalWrite(RightMotorBackward, LOW);
  delay(500);
}

void lookRight() {
  servo_motor.write(0);
  delay(500);
  measureDistance();
  servo_motor.write(90);
}

void lookLeft() {
  servo_motor.write(180);
  delay(500);
  measureDistance();
  servo_motor.write(90);
}
