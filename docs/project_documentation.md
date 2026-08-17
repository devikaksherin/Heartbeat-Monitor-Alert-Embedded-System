# Project Documentation

## 1. Project Title

Heartbeat Monitor with Alert System

## 2. Problem Statement

The project demonstrates an embedded-system prototype capable of monitoring a simulated heartbeat signal, calculating heart rate in BPM, displaying the result, and generating alerts when the BPM crosses predefined thresholds.

## 3. Objectives

- Simulate a heartbeat signal.
- Detect heartbeat events.
- Calculate BPM using the interval between beats.
- Apply basic BPM smoothing.
- Display BPM and status on an OLED.
- Provide visual alerts using LEDs.
- Provide an audible alert using a buzzer.

## 4. System Components

- Arduino UNO
- Potentiometer for simulated pulse input
- OLED display
- Green LED
- Red LED
- Buzzer
- Resistors
- Wokwi simulation environment

## 5. System Workflow

Simulated Pulse Input
        ↓
Heartbeat Detection
        ↓
Beat Interval Measurement
        ↓
BPM Calculation
        ↓
BPM Smoothing
        ↓
Threshold Comparison
        ↓
OLED + LED + Buzzer

## 6. BPM Calculation

BPM is calculated from the time interval between two detected heartbeat events.

BPM = 60000 / Beat Interval (milliseconds)

## 7. Alert Conditions

| Condition | Status | Green LED | Red LED | Buzzer |
|---|---|---|---|---|
| BPM < 60 | LOW | OFF | ON | ON |
| 60 ≤ BPM ≤ 100 | NORMAL | ON | OFF | OFF |
| BPM > 100 | HIGH | OFF | ON | ON |

These thresholds are demonstration values for the educational prototype and are not intended for medical diagnosis.

## 8. Simulation

The project was implemented and tested using a Wokwi virtual simulation because physical hardware was unavailable.

A potentiometer is used to control the simulated heartbeat rate.

## 9. Testing

The system was tested under normal, low, and high BPM conditions. OLED output, LED indicators, buzzer alerts, heartbeat detection, BPM calculation, and Serial Monitor output were verified.

## 10. Limitations

Physical hardware testing was not performed because the required hardware was unavailable.

The current project therefore demonstrates a virtual prototype rather than a medically validated monitoring device.

## 11. Future Improvements

- Interface a physical pulse sensor.
- Test with real sensor signals.
- Improve signal filtering and noise rejection.
- Add wireless monitoring.
- Add mobile or cloud-based notifications.
- Develop a compact PCB implementation.

## 12. Conclusion

The project successfully demonstrates the fundamental stages of an embedded heartbeat monitoring and alert system through virtual simulation, including heartbeat detection, BPM calculation, smoothing, display, and threshold-based alerts.
