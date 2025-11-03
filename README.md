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
- Displays live count on a bright 4-digit LED display  
- Beeps when a push-up is detected  
- Includes a reset button to start fresh  
- Optional Serial Monitor output for debugging

---

## How It Works
- When you move **close to the sensor** (<10 cm), it sets `trigDown = true`.  
- When you move **away** (15–30 cm), it sets `trigUp = true`.  
- When both movements occur, one push-up is counted.  
- The buzzer beeps and the display increments.
	
## Technologies
---

## Hardware Required
| Component | Quantity | Description |
|------------|-----------|-------------|
| Arduino Uno R4 WiFi (or compatible) | 1 | Main microcontroller |
| HC-SR04 Ultrasonic Sensor | 1 | Detects push-up movement |
| TM1637 4-Digit Display | 1 | Shows the current count |
| Passive Buzzer | 1 | Provides sound feedback |
| Push Button | 1 | Resets the counter |
| Jumper Wires | several | For connections |
| Breadboard | optional | For prototyping |

---

## Wiring Diagram

| Component | Arduino Pin | Notes |
|------------|--------------|-------|
| **HC-SR04 Trig** | 3 | Trigger pin |
| **HC-SR04 Echo** | 2 | Echo pin |
| **TM1637 CLK** | 11 | Clock pin |
| **TM1637 DIO** | 12 | Data pin |
| **Buzzer** | 7 | Output signal |
| **Reset Button** | 4 | Connect to GND when pressed |
| **Power** | 5V & GND | Shared by all components |

> 💡 Use the internal pull-up resistor for the reset button (`INPUT_PULLUP` in code).

---

## Code Overview
The sketch uses:
- `pulseIn()` to measure distance via the HC-SR04
- Simple logic to detect “up” and “down” movements
- The `TM1637Display` library to show the count
- A buzzer tone to give feedback

---

## How to Upload
1. Open the Arduino IDE  
2. Install the **TM1637Display** library by Avishay Orpaz (`Sketch > Include Library > Manage Libraries...`)  
3. Select your board (**Arduino Uno R4 WiFi**)  
4. Copy the `.ino` file into a new sketch folder  
5. Click **Upload**



---

## 🧰 Example Output
**Serial Monitor:**
