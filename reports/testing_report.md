# Testing Report

## Heartbeat Monitor and Alert System

The system was tested using the Wokwi virtual simulation.

| Test Case | Input Condition | Expected Result | Result |
|---|---|---|---|
| 1 | No pulse / startup | System waits for valid BPM | PASS |
| 2 | Normal BPM (~75–80) | NORMAL, green LED ON, buzzer OFF | PASS |
| 3 | Low BPM (~50) | LOW, red LED ON, buzzer ON | PASS |
| 4 | High BPM (~120) | HIGH, red LED ON, buzzer ON | PASS |
| 5 | Changing BPM | Status changes according to BPM | PASS |
| 6 | OLED display | BPM and status displayed | PASS |
| 7 | Serial Monitor | Beat interval and BPM displayed | PASS |

## Observations

The simulated pulse input was varied using the potentiometer. The system successfully detected heartbeat events, calculated BPM from the interval between beats, smoothed the BPM readings, and compared the result with the configured thresholds.

## Hardware Limitation

Physical hardware testing was not performed because the required pulse sensor and other hardware components were unavailable. The implementation was therefore validated through virtual simulation.

## Conclusion

The virtual prototype successfully demonstrated the intended heartbeat monitoring and alert functionality.
