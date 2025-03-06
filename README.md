# IOT-Arduino--Project
It's my first year's SEM 1 project on IoT.

# Smart City Infrastructure - IoT Project

## Overview
This project focuses on developing an IoT-based Smart City Infrastructure, integrating multiple subsystems to enhance urban safety, health monitoring, and environmental tracking. The key components of this project include:
- **Vehicle Accident Detection System**: Detects accidents using an accelerometer and sends real-time alerts.
- **Oximeter Health Monitoring System**: Monitors heart rate and oxygen saturation using a MAX30102 sensor.
- **Environmental Monitoring System**: Tracks temperature and humidity using a DHT11 sensor.

## Features
### Vehicle Accident Detection System
- **Accelerometer (ADXL345)** detects sudden impact.
- **GSM Module** sends emergency alerts with GPS location.
- Reduces emergency response time and enhances road safety.

### Oximeter Health Monitoring System
- Measures **SpO2 (Oxygen Saturation) and Heart Rate**.
- Uses **MAX30102** sensor for real-time health monitoring.
- Displays health data on **OLED Display**.
- Sends alerts if critical levels are detected.

### Environmental Monitoring System
- Tracks **temperature and humidity** using the **DHT11 sensor**.
- Displays real-time data on an **LCD screen**.
- Can be integrated with cloud platforms for data analytics.

## Hardware Components
- **Arduino Uno / Nano**
- **ADXL345 Accelerometer**
- **GSM Module** (for accident detection alerts)
- **MAX30102 Oximeter Sensor**
- **DHT11 Temperature and Humidity Sensor**
- **LCD and OLED Displays**
- **Buzzer, LEDs, and Power Supply**

## Software Requirements
- **Arduino IDE** for microcontroller programming.
- **Libraries**:
  - `MFRC522.h` for RFID module
  - `Adafruit_GFX.h` and `Adafruit_SSD1306.h` for OLED display
  - `Wire.h` for I2C communication
  - `DHT.h` for environmental monitoring
- **GSM Communication Setup**
- **Cloud Integration (Optional)** for real-time data monitoring

## Installation and Setup
1. Clone this repository:
   ```sh
   git clone https://github.com/yourusername/Smart-City-IoT.git
   ```
2. Install required libraries in the **Arduino IDE**.
3. Connect the hardware components as per the circuit diagrams.
4. Upload the respective codes to Arduino Uno/Nano.
5. Test each module separately before full integration.

## How It Works
- **Accident Detection**: If an accident occurs, the accelerometer detects impact and the GSM module sends emergency alerts.
- **Health Monitoring**: The oximeter sensor continuously measures health parameters and triggers alerts if abnormal readings are detected.
- **Environmental Tracking**: Temperature and humidity data are logged and displayed for analysis and decision-making.

## Future Enhancements
- **AI-Based Crash Detection**: Integrating machine learning for accurate accident predictions.
- **Cloud-Based Monitoring**: Storing all data on a cloud server for real-time analytics.
- **Integration with Smart City Networks**: Enabling automated emergency responses and adaptive urban management.

## Contributors
- **Pratik Borle** - Project Lead & Developer
- **Team Members - Ananya Jhadahv, Aagam Oswal, Shreya Garudkar** (if applicable)

## Contact
For queries or contributions, contact pratikborle64@gmail.com or open an issue in the repository.

