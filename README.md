# 🌆 Smart City Infrastructure - IoT Project  

An **IoT-based Smart City Infrastructure** designed to enhance urban safety, health monitoring, and environmental tracking. This project integrates multiple subsystems to create a smarter, more connected city.  

---

## 📌 Project Overview  

This project focuses on **real-time monitoring** and **automated alert systems** for:  
✔️ **Vehicle Accident Detection** using an accelerometer and GSM alerts.  
✔️ **Oximeter Health Monitoring** for heart rate and oxygen levels.  
✔️ **Environmental Monitoring** of temperature and humidity.  

🔹 Built with **Arduino** and various IoT sensors, this system can improve emergency response times, monitor public health, and contribute to a smarter urban infrastructure.  

---

## 🚀 Features  

### 🚗 Vehicle Accident Detection System  
✔️ **Accelerometer (ADXL345)** detects sudden impact.  
✔️ **GSM Module** sends **real-time emergency alerts with GPS location**.  
✔️ Enhances **road safety and reduces emergency response time**.  

### ❤️ Oximeter Health Monitoring System  
✔️ **Real-time SpO2 (Oxygen Saturation) & Heart Rate** monitoring.  
✔️ Uses **MAX30102** sensor for accurate readings.  
✔️ **OLED Display** for visualizing health data.  
✔️ Alerts when critical levels are detected.  

### 🌡️ Environmental Monitoring System  
✔️ Tracks **temperature and humidity** using **DHT11** sensor.  
✔️ Displays data on **LCD screen** for real-time monitoring.  
✔️ Can be **integrated with cloud platforms** for long-term data analysis.  

---

## 🛠 Hardware Components  

- **Arduino Uno / Nano**  
- **ADXL345 Accelerometer**  
- **GSM Module (SIM800L/SIM900)**  
- **MAX30102 Oximeter Sensor**  
- **DHT11 Temperature and Humidity Sensor**  
- **LCD and OLED Displays**  
- **Buzzer & LEDs** for alerts  
- **Power Supply (Battery or Adapter)**  

---

## 💻 Software Requirements  

- **Arduino IDE** for programming.  
- **Required Libraries**:  
  - `MFRC522.h` (for RFID module, if needed)  
  - `Adafruit_GFX.h`, `Adafruit_SSD1306.h` (for OLED display)  
  - `Wire.h` (for I2C communication)  
  - `DHT.h` (for temperature and humidity sensor)  
- **GSM Communication Setup** for sending alerts.  
- **Cloud Integration (Optional)** for real-time data logging.  

---

## 📂 Installation & Setup  

### 1️⃣ **Clone the Repository**  
```sh
git clone https://github.com/pratikborle74/Smart-City-IoT.git
cd Smart-City-IoT
```

### 2️⃣ **Install Required Libraries in Arduino IDE**  
Ensure all necessary libraries are installed in **Arduino IDE**.  

### 3️⃣ **Hardware Setup**  
Connect the sensors and modules as per the circuit diagram (to be included in the repository).  

### 4️⃣ **Upload the Code**  
- Open the respective `.ino` files in **Arduino IDE**.  
- Select the correct **board (Arduino Uno/Nano)** and **COM port**.  
- Compile and upload the code.  

### 5️⃣ **Testing & Debugging**  
- Verify **sensor readings** on the serial monitor.  
- Test **GSM alerts** for accident detection.  
- Check **display output** for health and environmental data.  

---

## 🔄 How It Works  

1️⃣ **Accident Detection**  
   - If an accident occurs, the **ADXL345 accelerometer** detects impact.  
   - The **GSM module** sends emergency alerts with location details.  

2️⃣ **Health Monitoring**  
   - The **MAX30102 sensor** continuously monitors **oxygen levels and heart rate**.  
   - Data is displayed on an **OLED screen** and alerts are triggered for critical levels.  

3️⃣ **Environmental Monitoring**  
   - The **DHT11 sensor** records temperature & humidity in real time.  
   - Data is displayed on an **LCD screen** for immediate tracking.  

---

## 📊 Future Enhancements  

✅ **AI-Based Crash Detection** for more accurate accident predictions.  
✅ **Cloud-Based Data Storage** for real-time monitoring & analytics.  
✅ **Integration with Smart City Networks** to enable automated emergency responses.  

---

## 📜 License  

This project is licensed under the **MIT License** – you are free to use, modify, and distribute it with attribution.  

---

## 🤝 Contributors  

- **Pratik Borle** - Project Lead & Developer  
- **Team Members**: Ananya Jadhav, Aagam Oswal, Shreya Garudkar

📩 For contributions or issues, please open a pull request or issue in the repository.  

---

## **👤 Author**  
**Pratik Borle**  
📧 Email: [pratikborle64@gmail.com](mailto:pratikborle64@gmail.com)  
🔗 GitHub: [pratikborle74](https://github.com/pratikborle74)  

🚀 *If you find this project useful, don't forget to ⭐ the repository!*
