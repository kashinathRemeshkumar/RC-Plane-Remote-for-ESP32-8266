# XY Joystick + Slider Control with ESP8266 (RemoteXY)

This project demonstrates how to use an **ESP8266** with the [RemoteXY](https://remotexy.com/) library to create a **Wi-Fi based joystick and slider controller**.  
It provides an interactive mobile interface for controlling hardware using a virtual **XY joystick** and a **throttle slider**.

## Features
- 📡 Creates a Wi-Fi access point (`SSID: esp`, `Password: 12345678`)  
- 🎮 Virtual **XY Joystick** (X, Y values range from -100 to +100)  
- 🎚️ **Throttle Slider** with real-time **meter feedback**  
- 🔌 Controls GPIO pins (`D0–D4`) on the ESP8266 for hardware interaction  
- 📱 Fully compatible with the **RemoteXY mobile app**  

## Hardware Required
- ESP8266 (NodeMCU / Wemos D1 Mini recommended)  
- Power supply (USB or external 5V)  
- Optional: motor driver, servos, or actuators to connect with GPIO pins  

## Setup Instructions
1. Install the [Arduino IDE](https://www.arduino.cc/en/software).  
2. Install the **ESP8266 board package** via Boards Manager.  
3. Install the **RemoteXY** library from Arduino Library Manager.  
4. Open `xyjoystic_slider.ino` in Arduino IDE.  
5. Upload the code to your ESP8266 board.  
6. Connect your phone to the ESP Wi-Fi hotspot (`esp / 12345678`).  
7. Open the **RemoteXY app** and import the project configuration.  

## RemoteXY UI
The app interface includes:
- **Joystick (X, Y)** → controls movement directions  
- **Throttle Slider** → controls speed/power  
- **Throttle Meter** → real-time feedback  

## Pin Mapping
| Function       | ESP8266 Pin |
|----------------|-------------|
| Throttle Out   | D0          |
| Joystick X     | D1          |
| Joystick Y     | D2          |
| Joystick NX    | D3          |
| Joystick NY    | D4          |

## Example Applications
- RC car / tank control  
- Servo or motor control  
- DIY robotics projects  
- Wireless remote-control systems  

## License
This project is released under the MIT License. Feel free to use and modify.
