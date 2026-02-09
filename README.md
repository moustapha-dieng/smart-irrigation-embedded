# 🌱 Smart Irrigation System – Embedded Project

## 📌 Overview
This project is a **smart irrigation system** developed using an **Arduino microcontroller** and a **soil moisture sensor**.  
The system automatically controls a **water pump** based on real-time soil humidity measurements, optimizing water usage.

This project was designed and implemented as a **personal embedded systems project**, with a focus on:
- modular C/C++ architecture
- hardware–software interaction
- clean documentation and version control

---

## 🎯 Project Objectives
- Measure soil moisture in real time
- Automatically activate irrigation when soil is dry
- Stop irrigation when sufficient humidity is detected
- Build a modular and scalable embedded architecture
- Practice professional tools (Git, GitHub, documentation)

---

## 🧠 System Architecture

### Hardware Components
- Arduino (Uno / compatible)
- Soil moisture sensor (analog)
- Relay module
- DC water pump
- External power supply (battery pack)
- Status LED
- Connecting wires and tubing

### Software Architecture
The code is structured in a **modular way**:


---

## ⚙️ How It Works
1. The soil moisture sensor provides an **analog value**.
2. The Arduino reads and compares the value to a **threshold**.
3. If the soil is **too dry**:
   - The LED turns ON
   - The relay activates the water pump
4. If the soil is **sufficiently wet**:
   - The LED turns OFF
   - The pump stops

---

## 🧪 Testing
- Sensor values were monitored via the **Serial Monitor**
- System behavior was validated by placing the sensor in:
  - dry soil
  - water
- Relay and pump activation were tested independently before full integration

---

## 📷 Project Media
Photos and videos of the setup and tests are available in the `media/` folder.

---

## 🛠 Tools & Technologies
- Arduino IDE
- C / C++
- VS Code
- Git & GitHub
- Basic electronics (relay, sensors, actuators)

---

## 🚀 Future Improvements
- Use ESP32 with Wi-Fi
- Add mobile/web dashboard
- Weather-based irrigation logic
- Low-power optimization
- Enclosure and outdoor deployment

---

## 👨‍🎓 Author
**Moustapha Dieng**  
Embedded Systems / Engineering Student.
