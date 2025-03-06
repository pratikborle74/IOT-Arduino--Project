#include <Wire.h>
#include "MAX30105.h"
#include "spo2_algorithm.h"
#include <LiquidCrystal_I2C.h>

// Define new I2C instance (if A4/A5 are busy)
TwoWire myWire = TwoWire(1);  // Use a different I2C bus

MAX30105 particleSensor;
LiquidCrystal_I2C lcd(0x27, 16, 2);  // LCD Address (change to 0x3F if needed)

// Variables for SpO2 and Heart Rate Calculation
#define BUFFER_SIZE 100
uint32_t irBuffer[BUFFER_SIZE];  // IR LED sensor data
uint32_t redBuffer[BUFFER_SIZE]; // Red LED sensor data
int32_t spo2;
int8_t validSPO2;
int32_t heartRate;
int8_t validHeartRate;

void setup() {
  Serial.begin(115200);
  Serial.println("MAX30102 Heart Rate & SpO2 Monitoring");

  // Start custom I2C on different pins if needed (e.g., SDA = D2, SCL = D3)
  myWire.begin(2, 3);  // Change pins as per your setup

  // Initialize MAX30102 sensor with custom I2C
  if (!particleSensor.begin(myWire, I2C_SPEED_FAST)) {
    Serial.println("MAX30102 not found! Check wiring.");
    while (1);
  }

  // Sensor configuration
  particleSensor.setup(0x1F, 4, 2, 400, 411, 2048);
  particleSensor.setPulseAmplitudeRed(0x1F);
  particleSensor.setPulseAmplitudeGreen(0);

  // Initialize LCD
  lcd.begin(16, 2);
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Initializing...");
  delay(2000);
}

void loop() {
  // Collect 100 samples
  for (int i = 0; i < BUFFER_SIZE; i++) {
    while (!particleSensor.check()) delay(1);
    irBuffer[i] = particleSensor.getIR();
    redBuffer[i] = particleSensor.getRed();
  }

  // Calculate Heart Rate and SpO2
  maxim_heart_rate_and_oxygen_saturation(irBuffer, BUFFER_SIZE, redBuffer, 
                                         &spo2, &validSPO2, &heartRate, &validHeartRate);

  // Print data to Serial Monitor
  Serial.print("Heart Rate: ");
  if (validHeartRate) Serial.print(heartRate);
  else Serial.print("N/A");
  Serial.print(" bpm, SpO2: ");
  if (validSPO2) Serial.print(spo2);
  else Serial.print("N/A");
  Serial.println(" %");

  // Display values on LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("HR: ");
  if (validHeartRate) lcd.print(heartRate);
  else lcd.print("--");
  lcd.print(" bpm  ");

  lcd.setCursor(0, 1);
  lcd.print("SpO2: ");
  if (validSPO2) lcd.print(spo2);
  else lcd.print("--");
  lcd.print(" %  ");

  delay(1000);  // Refresh every second
}
