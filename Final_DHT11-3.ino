#include "DHT.h"
#include <LiquidCrystal_I2C.h>

#define DHTPIN 4          // Pin connected to DHT sensor
#define DHTTYPE DHT11     // DHT 11 sensor type

DHT dht(DHTPIN, DHTTYPE);           // Initialize DHT sensor
LiquidCrystal_I2C lcd(0x27, 16, 2); // Initialize LCD at address 0x27

// Calibration offsets
#define TEMP_OFFSET -16.0 // Offset to calibrate the temperature

// Smoothing parameters
float displayedTemperature = 0.0;
float displayedHumidity = 0.0;
const float smoothFactor = 0.2; // Smoothing factor (higher = faster adjustment)

void setup() {
  dht.begin();           // Initialize DHT sensor
  lcd.init();            // Initialize LCD
  lcd.backlight();       // Turn on LCD backlight
  lcd.clear();
}

void loop() {
  float rawTemperature = dht.readTemperature();  // Read raw temperature
  float calibratedTemperature = rawTemperature + TEMP_OFFSET; // Apply calibration
  float rawHumidity = dht.readHumidity();       // Read raw humidity

  // Correct humidity based on calibrated temperature
  float correctedHumidity = rawHumidity * (1.0 + (rawTemperature - calibratedTemperature) * 0.05);

  // Enforce humidity limits
  if (correctedHumidity > 100.0) correctedHumidity = 100.0; // Cap at 100%
  if (correctedHumidity < 0.0) correctedHumidity = 0.0;     // Ensure non-negative values

  // Smoothly update the displayed temperature and humidity
  if (!isnan(calibratedTemperature)) {
    displayedTemperature += smoothFactor * (calibratedTemperature - displayedTemperature);
  }
  if (!isnan(correctedHumidity)) {
    displayedHumidity += smoothFactor * (correctedHumidity - displayedHumidity);
  }

  // Display error message if sensor readings are invalid
  if (isnan(rawHumidity) || isnan(rawTemperature)) {
    lcd.setCursor(0, 0);
    lcd.print("Error reading data!");
    delay(2000);
    return; // Skip further processing
  }

  // Display humidity on LCD
  lcd.setCursor(0, 0);
  lcd.print("Humidity=");
  lcd.setCursor(9, 0);  // Position after "Humidity="
  lcd.print(displayedHumidity, 1); // Print smoothed humidity
  lcd.print("%");

  // Display temperature on LCD
  lcd.setCursor(0, 1);
  lcd.print("Temp=");
  lcd.setCursor(5, 1);  // Position after "Temp="
  lcd.print(displayedTemperature, 1); // Print smoothed temperature
  lcd.print("C");

  delay(500); // Short delay to allow smoother updates
}
