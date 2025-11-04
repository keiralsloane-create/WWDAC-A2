# HC-SR04 Push-Up Counter with TM1637 Display

## Table of contents
* [General info](#general-info)
* [Technologies](#technologies)
* [Setup](#setup)



## General info
This project is an Arduino-based **push-up counter** that uses an **HC-SR04 ultrasonic sensor** to detect motion and a **TM1637 4-digit display** to show your count. A buzzer gives feedback for every completed push-up.

---

## Features
- Counts each full push-up automatically  
- Displays live count on a 4-digit LED display  
- Beeps when a push-up is detected  
- Includes a reset button to clear and restart  

---

## How It Works
- When you move **close to the sensor** (<10 cm), it sets `trigDown = true`.  
- When you move **away** (15–30 cm), it sets `trigUp = true`.  
- When both movements occur, one push-up is counted.  
- The buzzer beeps and the display increases by 1
	
## Technologies
---

## Hardware Required
| Component | Quantity | Description |
|------------|-----------|-------------|
| Arduino Uno R4 WiFi (or compatible) | 1 | Main microcontroller |
| HC-SR04 Ultrasonic Sensor | 1 | Detects push-up movement |
| TM1637 4-Digit Display | 1 | Displays current rep count |
| Passive Buzzer | 1 | Provides sound feedback |
| Push Button | 1 | Resets the counter |
| Jumper Wires | 13 | For connections |
| Breadboard | 1 | For prototyping |

---

## Setup
## Wiring Diagram

| Component | Arduino Pin | Notes |
|------------|--------------|-------|
| **HC-SR04 Trig** | 3 | Trigger pin |
| **HC-SR04 Echo** | 2 | Echo pin |
| **TM1637 CLK** | 11 | Clock pin |
| **TM1637 DIO** | 12 | Data pin |
| **Buzzer** | 7 | Output signal |
| **Reset Button** | 4 | Connect to GND when pressed |
| **Power** | 5V, 3.3v & GND | All components |

---

## Code Overview
This sketch uses:
- `pulseIn()` to measure distance via the HC-SR04
- Simple logic to detect “up” and “down” movements
- The `TM1637Display` library to show the count
- A buzzer sound to give feedback



