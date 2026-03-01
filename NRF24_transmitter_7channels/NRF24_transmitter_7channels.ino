#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(9, 10); // CE, CSN

const uint64_t pipe = 0xE8E8F0F0E1LL;

struct Data {
  byte throttle;
  byte steering;
};

Data data;

void setup() {
  Serial.begin(9600);  // Start serial monitor
  radio.begin();
  radio.setAutoAck(false);
  radio.setDataRate(RF24_250KBPS);
  radio.openWritingPipe(pipe);
}

void loop() {
  int rawThrottle = analogRead(A0);
  int rawSteering = analogRead(A1);

  data.throttle = map(rawThrottle, 0, 1023, 0, 255);
  data.steering = map(rawSteering, 0, 1023, 0, 255);

  radio.write(&data, sizeof(data));

  // Print values to Serial Monitor
  Serial.print("Throttle: ");
  Serial.print(data.throttle);
  Serial.print(" | Steering: ");
  Serial.println(data.steering);

  delay(100);
}
