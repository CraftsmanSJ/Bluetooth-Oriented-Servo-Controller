# Bluetooth-Controlled Servo Motor Using ESP32  

## Overview  
This project demonstrates how to control two servo motors (Servo1 and Servo2) using an ESP32 microcontroller via Bluetooth communication. 
The project uses the **ESP32-WROOM32E** module, the **ESP32Servo** library for servo control, and the **BluetoothSerial** library for Bluetooth communication.  

Users can send commands from a smartphone app to control the position of each servo motor.
For added functionality, the gyroscope feature of the app can be used to dynamically control the servos based on device orientation.  

---

## Features  
1. **Bluetooth Communication:**  
   - Establishes a Bluetooth connection between the ESP32 and a smartphone using the **Bluetooth Electronics** app.  

2. **Servo Motor Control:**  
   - Two servos, **Servo1** and **Servo2**, are controlled based on commands sent via Bluetooth.  

3. **Gyroscope Integration:**  
   - Uses the smartphone's accelerometer to adjust servo positions in real-time based on device orientation.

-Other options can also be integrated just the message settings need to be changed.

---

## Components Required  
1. **ESP32-WROOM32E Module**  
2. **Two Servo Motors** (Servo1 and Servo2)  
3. **Connecting Wires**  
4. **Power Supply**  (Connect to 5v for better outputs)

---

## How to Make It Work  

### 1. **Hardware Setup**  
- **Connect Servo1 to Pin 17** of the ESP32. (customize as per preference)
- **Connect Servo2 to Pin 18** of the ESP32. (customize as per preference)
- Provide appropriate power and ground connections to the servos and ESP32. 

### 2. **Code Setup**  
1. Install the **ESP32Servo** library:  
   - In the Arduino IDE, go to **Tools > Manage Libraries**, search for **ESP32Servo**, and install it.  

2. Upload the provided code to the ESP32 module using the Arduino IDE.  

### 3. **App Setup (Bluetooth Electronics)**  
1. Download and install the **Bluetooth Electronics** app from the Play Store.  
2. Pair your smartphone with the ESP32 (default Bluetooth name is `ESP`).  

#### **For Gyroscope Control:**  
1. Create a custom interface in the app:  
   - Select an empty panel.  
   - On the right-hand side, choose the **Accelerometer option**.  
   - Drag and drop **Roll** and **Pitch** options from the bottom panel.  

2. Configure the messages for each control:  
   - Click the **Roll** icon and set the message to `A `. (Do not forget the space its necessary for message differentiation)
   - Click the **Pitch** icon and set the message to `B `.  

3. Connect the ESP32 to the app.  
4. Run the custom panel, and the servos will respond to the gyroscope inputs.  

---

## How the Code Works  
1. **Bluetooth Communication:**  
   - The ESP32 receives commands from the app.  
   - If the command is `A`, the code parses an integer value for Servo1.  
   - If the command is `B`, the code parses an integer value for Servo2.  

2. **Servo Control:**  
   - The parsed values set the angle of the respective servos using the `write()` function.  

3. **Gyroscope Integration:**  
   - The app sends **Roll (A)** and **Pitch (B)** values based on device orientation.  
   - These values are received by the ESP32 and applied to the servos.  

---

## Customization  
- Change the **servo pins** in the code if needed:  
  ```cpp
  s1.attach(17);  // Attach servo s1 to desired pin
  s2.attach(18);  // Attach servo s2 to desired pin
