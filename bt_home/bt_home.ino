const int relayPin = 13;          // Relay pin
bool relayState = false;          // Current relay state

void setup() {
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, HIGH);   // Active LOW relay → HIGH = OFF
  Serial.begin(9600);             // Bluetooth communication
  Serial.println("Light Control Ready (Voice + Button)");
}

void loop() {
  // Check if any data is available from Bluetooth
  while (Serial.available() > 0) {
    String command = Serial.readStringUntil('\n');  // Read until newline
    command.trim();                                 // Remove spaces/newlines
    command.toLowerCase();                          // Case-insensitive

    // --- Handle numeric button input ('1'/'0') ---
    if (command == "1") {
      setRelay(true, "button");
    }
    else if (command == "0") {
      setRelay(false, "button");
    }

    // --- Handle voice commands ('light on'/'light off') ---
    else if (command == "light on") {
      setRelay(true, "voice");
    }
    else if (command == "light off") {
      setRelay(false, "voice");
    }
    else {
      Serial.print("Unknown command: ");
      Serial.println(command);
    }
  }
}

// Function to set relay state and print feedback
void setRelay(bool state, String source) {
  relayState = state;
  digitalWrite(relayPin, relayState ? LOW : HIGH); // LOW = ON, HIGH = OFF
  Serial.print("Light is ");
  Serial.print(relayState ? "ON" : "OFF");
  Serial.print(" (");
  Serial.print(source);
  Serial.println(")");
}
