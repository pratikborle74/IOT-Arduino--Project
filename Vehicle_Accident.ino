#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_ADXL345_U.h>
#include <SoftwareSerial.h>

// Create an instance of the ADXL345 sensor
Adafruit_ADXL345_Unified accel = Adafruit_ADXL345_Unified();

// SIM800L configuration
SoftwareSerial sim800(2, 3); // RX = D2, TX = D3
#define PHONE_NUMBER "+91XXXXXXXXXX" // Replace with the target phone number

// Set a threshold for what will be considered an "accident"
#define ACCIDENT_THRESHOLD 15.0 // G-force threshold for detecting an accident

void setup() {
  // Start Serial communication
  Serial.begin(9600);
  sim800.begin(9600);

  // Initialize the ADXL345 sensor
  if (!accel.begin()) {
    Serial.println("Could not find a valid ADXL345 sensor.");
    while (1);
  }

  // Set the range of the accelerometer
  accel.setRange(ADXL345_RANGE_16_G); // Choose range: 2G, 4G, 8G, 16G

  // Initialize SIM800L
  initializeSIM800();
}

void loop() {
  // Create an event to hold the accelerometer data
  sensors_event_t event;  
  accel.getEvent(&event);

  // Print accelerometer data to Serial Monitor
  Serial.print("X: "); Serial.print(event.acceleration.x); Serial.print(" ");
  Serial.print("Y: "); Serial.print(event.acceleration.y); Serial.print(" ");
  Serial.print("Z: "); Serial.print(event.acceleration.z); Serial.print(" ");
  Serial.println("m/s^2");

  // Calculate the magnitude of the acceleration vector
  float magnitude = sqrt(pow(event.acceleration.x, 2) +
                         pow(event.acceleration.y, 2) +
                         pow(event.acceleration.z, 2));

  // Check if the magnitude exceeds the threshold
  if (magnitude > ACCIDENT_THRESHOLD) {
    Serial.println("Accident detected!");
    sendSMS("Accident detected! Please check.");
    delay(10000); // Avoid sending multiple messages in quick succession
  }

  delay(500); // Adjust delay as needed
}

void initializeSIM800() {
  // Wait for the SIM800L module to respond
  Serial.println("Initializing SIM800L...");
  sim800.println("AT"); // Check communication
  delay(1000);
  sim800.println("AT+CMGF=1"); // Set SMS mode to text
  delay(1000);
  sim800.println("AT+CNMI=1,2,0,0,0"); // Configure message notifications
  delay(1000);
  Serial.println("SIM800L initialized.");
}

void sendSMS(const char *message) {
  sim800.println("AT+CMGS=\"" PHONE_NUMBER "\""); // Set the recipient's phone number
  delay(1000);
  sim800.print(message); // Message content
  delay(1000);
  sim800.write(26); // Send Ctrl+Z to indicate the end of the message
  delay(5000); // Wait for the message to be sent
  Serial.println("SMS sent!");
}
