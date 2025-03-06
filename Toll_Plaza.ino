#include <Servo.h>

Servo myservo;

int pos = 0; // Servo position
int cm = 0;  // Measured distance in cm
bool gateOpen = false; // Tracks if the gate is open

// Ultrasonic sensor pins
const int triggerPin = 6;
const int echoPin = 7;

// Delay constants
const int delayDown = 5000; // Time to wait before lowering gate
const int distanceThreshold = 30; // Distance threshold in cm

// Reads the ultrasonic sensor and returns distance in cm
long readUltrasonicDistance(int triggerPin, int echoPin) {
  pinMode(triggerPin, OUTPUT);
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  return pulseIn(echoPin, HIGH) * 0.034 / 2; // Calculate distance in cm
}

void setup() {
  myservo.attach(9); // Attach the servo motor to pin 9
  Serial.begin(9600);
  myservo.write(0); // Start with gate in the down position
}

void loop() {
  cm = readUltrasonicDistance(triggerPin, echoPin);
  Serial.print("Distance: ");
  Serial.print(cm);
  Serial.println(" cm");

  if (cm < distanceThreshold && !gateOpen) {
    // Vehicle detected and gate is not already open
    gateOpen = true; // Mark gate as open
    Serial.println("Vehicle detected. Raising gate.");
    for (pos = 0; pos <= 120; pos += 1) {
      myservo.write(pos);
      delay(15);
    }
    delay(5000); // Wait for 5 seconds before checking if vehicle has passed
  }

  if (gateOpen && cm > distanceThreshold) {
    // Vehicle has moved away, lower the gate
    Serial.println("Vehicle left. Lowering gate.");
    for (pos = 120; pos >= 0; pos -= 1) {
      myservo.write(pos);
      delay(15);
    }
    gateOpen = false; // Mark gate as closed
  }

  delay(100); // Short delay to prevent excessive sensor reads
}
