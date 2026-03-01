// Pin setup
const int irSensorPin = 2; // IR sensor connected to digital pin 2

// RPM calculation variables
volatile int count = 0; // Counts the number of white strip detections
unsigned long lastMillis = 0;
int rpm = 0; // RPM value to display as an integer
int divisor = 5; // To handle multiple strips (1 for single strip, 2 for diameter, etc.)

void setup() {
  pinMode(irSensorPin, INPUT);  // Set IR sensor pin as input
  attachInterrupt(digitalPinToInterrupt(irSensorPin), countWhiteStripe, RISING); // Interrupt on rising edge

  Serial.begin(9600); // Start Serial communication
  Serial.println("RPM Counter Started");
}

void loop() {
  unsigned long currentMillis = millis();
 
  // Calculate RPM every 1 second (1000 milliseconds)
  if (currentMillis - lastMillis >= 1000) {
    lastMillis = currentMillis;
   
    // Calculate RPM as an integer: (count * 60) / divisor
    rpm = (count * 60) / divisor; // Adjust RPM based on number of stripes
   
    // Output RPM to Serial Monitor
    Serial.print("RPM: ");
    Serial.println(rpm);
   
    count = 0; // Reset count for next interval
  }
}

void countWhiteStripe() {
  // Increment count every time the white tape passes the IR sensor
  count++;
}
