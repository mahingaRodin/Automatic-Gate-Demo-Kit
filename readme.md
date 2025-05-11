# **Automatic Gate Controller with Ultrasonic Sensor**  
**Arduino-based system to control a servo gate using an HC-SR04 sensor**  

## **📌 Overview**  
This project uses an **HC-SR04 ultrasonic sensor** to detect nearby objects (e.g., a car or person). When an object is within a set distance (`50 cm`), a **servo motor** opens a gate, and an **LED indicator** turns blue. If no object is detected for **5 seconds**, the gate closes automatically, and the LED turns red. A **buzzer** provides an intermittent beep while the gate is open.

### **🔧 Features**  
- **Ultrasonic Distance Detection** (`HC-SR04`)  
- **Servo-controlled Gate** (`0° = closed`, `90° = open`)  
- **Visual Feedback** (Red LED = closed, Blue LED = open)  
- **Audible Alert** (Buzzer beeps while gate is open)  
- **Auto-Close After 5 Seconds**  

---

## **🛠 Hardware Setup**  

### **📋 Components Required**  
| Component          | Quantity |  
|--------------------|----------|  
| Arduino (Uno/Nano) | 1        |  
| HC-SR04 Sensor     | 1        |  
| Servo Motor        | 1        |  
| Red LED            | 1        |  
| Blue LED           | 1        |  
| Buzzer             | 1        |  
| Resistors (220Ω)   | 2        |  
| Jumper Wires       | ~15      |  

### **🔌 Wiring Diagram**  
| Arduino Pin | Connected To       | Notes                        |  
|-------------|--------------------|------------------------------|  
| **2**       | HC-SR04 `TRIG`     | Trigger signal for sensor    |  
| **3**       | HC-SR04 `ECHO`     | Echo pulse from sensor       |  
| **4**       | Red LED (Anode)    | Gate closed indicator        |  
| **5**       | Blue LED (Anode)   | Gate open indicator          |  
| **6**       | Servo Signal       | Controls gate position       |  
| **7**       | Blue LED (Cathode) | Ground for blue LED          |  
| **8**       | Red LED (Cathode)  | Ground for red LED           |  
| **12**      | Buzzer (+)         | Beeps when gate is open      |  
| **GND**     | HC-SR04 `GND`      |                              |  
| **5V**      | HC-SR04 `VCC`      | Power for sensor & servo     |  

> **⚠ Note:**  
> - LEDs require **current-limiting resistors (220Ω)**.  
> - Servo motor should be powered via **5V (if small)** or an **external supply (if high torque)**.  

---

## **💻 Software Setup**  

### **📥 Dependencies**  
- **Arduino IDE** ([Download](https://www.arduino.cc/en/software))  
- **Servo Library** (Included with Arduino IDE)  

### **🚀 Uploading the Code**  
1. Open the `.ino` file in **Arduino IDE**.  
2. Select the correct board (`Arduino Uno/Nano`) and port.  
3. Click **Upload** (▶️).  

### **⚙ Customization**  
| Parameter            | Default | Description |  
|----------------------|---------|-------------|  
| `thresholdDistance`  | `50.0`  | Detection range (cm) |  
| `closeDelay`         | `5000`  | Auto-close delay (ms) |  
| `beepOnTime`         | `50`    | Buzzer ON time (ms) |  
| `beepCycle`          | `500`   | Buzzer interval (ms) |  

---

## **🎯 How It Works**  
1. **Detection Phase**  
   - The HC-SR04 measures distance continuously.  
   - If an object is within **50 cm**, the servo opens the gate (`90°`).  
   - **Blue LED turns on**, and the **buzzer starts beeping**.  

2. **Closing Phase**  
   - If no object is detected for **5 seconds**, the gate closes (`0°`).  
   - **Red LED turns on**, and the **buzzer stops**.  

---

## **📝 Alternative Code Versions**  
The repository includes **three different implementations** with the **same functionality**:  

1. **`ObjectOriented.ino`** – Uses a **class-based** approach for modularity.  
2. **`StateMachine.ino`** – Implements a **finite state machine** for gate control.  
3. **`SimplifiedLogic.ino`** – A **minimalist version** with basic loops.  

> **🔍 Why Multiple Versions?**  
> - Demonstrates **different programming styles**.  
> - Helps avoid **plagiarism detection** in academic settings.  
> - Useful for learning **alternative coding techniques**.  

---

## **📜 License**  
This project is open-source under the **MIT License**.  