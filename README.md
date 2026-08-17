# Heartbeat Monitor with Alert System

## 📌 Project Overview

This project is an educational embedded-systems prototype for monitoring simulated heart rate and generating alerts when the BPM falls below or rises above predefined thresholds.

The system was developed and validated using a Wokwi virtual simulation because physical hardware was not available.

## 🎯 Objectives

- Simulate heartbeat input
- Detect heartbeat events
- Calculate BPM using beat intervals
- Smooth BPM readings
- Display BPM and status on an OLED
- Indicate normal heart rate using a green LED
- Indicate abnormal heart rate using a red LED
- Activate a buzzer during abnormal conditions

## 🛠️ Technologies Used

- Arduino UNO
- Wokwi
- Arduino C/C++
- OLED Display
- Potentiometer as simulated pulse input
- LEDs
- Buzzer

## ⚙️ System Architecture

Simulated Pulse Input
        ↓
Arduino UNO
        ↓
Heartbeat Detection
        ↓
Beat Interval Calculation
        ↓
BPM Calculation
        ↓
BPM Smoothing
        ↓
Threshold Comparison
        ↓
OLED + LEDs + Buzzer

## 🚦 Alert Logic

| BPM | Status | Green LED | Red LED | Buzzer |
|---|---|---|---|---|
| Below 60 | LOW | OFF | ON | ON |
| 60–100 | NORMAL | ON | OFF | OFF |
| Above 100 | HIGH | OFF | ON | ON |

The thresholds are demonstration values for this educational prototype and are not intended for medical diagnosis.

## 🔌 Pin Configuration

| Component | Arduino UNO Pin |
|---|---|
| Simulated pulse input | A0 |
| OLED SDA | A4 |
| OLED SCL | A5 |
| Green LED | D6 |
| Red LED | D7 |
| Buzzer | D8 |

## 🧪 Testing

The system was tested under:

- Normal BPM condition
- Low BPM condition
- High BPM condition
- Changing BPM conditions
- OLED display output
- LED status indication
- Buzzer alert
- Serial Monitor BPM output

## ⚠️ Current Limitation

The current implementation is a virtual simulation. A physical pulse sensor was not available for hardware validation.

## 🔮 Future Improvements

- Interface a physical Pulse Sensor or MAX30102
- Test using real sensor data
- Improve noise filtering
- Add wireless monitoring
- Add mobile notifications
- Develop a compact PCB-based version

## 📚 Project Status
## 🔗 Wokwi Simulation

[▶️ Run the Heartbeat Monitor Simulation on Wokwi](https://wokwi.com/projects/472491181972524033)
**Virtual simulation: Completed ✅**

**Physical hardware implementation: Future work 🔧**

## 👩‍💻 Author

Devika KS

