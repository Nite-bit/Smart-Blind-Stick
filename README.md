# 🚶 Advanced Smart Blind Stick – Obstacle Detection & Safety Assistance

An Arduino-based smart blind stick designed to help visually impaired people detect nearby obstacles and receive alerts through sound and vibration.

The project uses ultrasonic sensors to measure the distance between the user and obstacles. Additional safety features, including water detection, wireless RF alerts, and a rechargeable battery system, are planned for future development.

---

## 📌 Project Overview

Traditional white canes help visually impaired people detect obstacles through physical contact. However, they may not identify obstacles at a distance or certain overhead objects.

The **Advanced Smart Blind Stick** aims to improve obstacle awareness by using electronic sensors and alert mechanisms.

The system is being developed in multiple stages, starting with two ultrasonic sensors.

### Main Objectives

- Detect obstacles in front of the user.
- Detect upper-level obstacles such as hanging objects and branches.
- Provide distance-based alerts.
- Alert users through a buzzer and vibration motor.
- Detect water on the walking path.
- Support wireless emergency notifications.
- Operate using a rechargeable battery.

---

## ✨ Planned Features

| Feature | Description | Development status |
|---|---|---|
| Front obstacle detection | Detects obstacles using an ultrasonic sensor | In testing |
| Upper obstacle detection | Detects overhead obstacles using a second sensor | In testing |
| Distance measurement | Measures obstacle distance in centimetres | In testing |
| Buzzer alert | Provides audio alerts according to distance | In testing |
| Vibration alert | Provides vibration for nearby obstacles | In testing |
| Water detection | Detects water using a water sensor | In testing |
| RF communication | Sends wireless alerts to a receiver | Planned |
| Rechargeable battery | Provides portable power | In testing |

---

## 🛠️ Hardware Requirements

### Current development components

- Arduino Nano
- 2 × HC-SR04 Ultrasonic Sensors
- Jumper wires
- Breadboard (optional)
- USB cable
- Water detection sensor
- Buzzer
- Vibration motor
- ON/OFF switch
- Mini boost converter
- TP4056 charging and protection module
- 3.7V rechargeable lithium-ion battery

### Additional planned components

- NPN transistor (BC547 or 2N2222) or suitable motor driver
- 433 MHz RF transmitter
- 433 MHz RF receiver
---

## 🔌 Circuit Connections

### 1. Planned Integrated Pin Configuration

| Component | Arduino Nano Pin |
|---|---|
| Front Ultrasonic TRIG | D7 |
| Front Ultrasonic ECHO | D8 |
| Upper Ultrasonic TRIG | D4 |
| Upper Ultrasonic ECHO | D5 |
| Water Sensor Analog Output | A0 |
| Buzzer | D10 |
| Vibration Motor Driver | D11 |
| RF Transmitter DATA | D12 |
| RF Receiver DATA | D2 (separate receiver Arduino) |

**Note:** This is the proposed pin configuration for the integrated system. It is not yet a completed, tested circuit.

---

## ⚙️ Working Principle

### 1. Front Obstacle Detection

The front ultrasonic sensor sends ultrasonic waves and measures the time taken for the reflected waves to return.

The Arduino calculates the distance using:

`Distance = (Time × Speed of Sound) / 2`

### 2. Upper Obstacle Detection

The second ultrasonic sensor is mounted on the upper part of the stick.

It helps detect obstacles that may be missed by the lower sensor, such as:

- Hanging branches
- Signboards
- Overhead objects
- Other obstacles around head height

### 3. Distance-Based Alerts 

The following alert logic is proposed:

| Obstacle Distance | Buzzer | Vibration Motor |
|---|---|---|
| More than 40 cm | OFF | OFF |
| 21–40 cm | Slow beep | OFF |
| 11–20 cm | Fast beep | OFF |
| 10 cm or less | Continuous sound | ON |

### 4. Water Detection 

A water sensor detect water on the walking path.

When water is detected:
- The buzzer will activate.
- The vibration motor will turn ON.
- The system will provide an alert to the user.

### 5. Wireless RF Communication (Planned)

A 433 MHz RF transmitter will send alert signals to a separate RF receiver.

The receiver can be connected to another Arduino to activate a buzzer or LED for a caregiver.

---

## 💻 Software Requirements

- Arduino IDE
- Arduino Nano board package
- USB-to-Serial driver appropriate for your Arduino Nano
- RCSwitch library (for the future RF communication feature)


## 🔋 Power Supply System (Planned)

The project is intended to use a rechargeable 3.7V lithium-ion battery.

Proposed power arrangement:

1. 3.7V battery connects to the TP4056 battery terminals.
2. The protected output connects to the boost converter through an ON/OFF switch.
3. The boost converter is adjusted to a regulated 5V output.
4. The regulated supply powers the Arduino and compatible 5V components.

**Important:** Verify the module pin labels, battery specifications, motor voltage, and converter output before connecting the circuit. A standard TP4056 board does not necessarily support safe simultaneous charging and powering of the project. Use a suitable protected power-path arrangement if simultaneous operation is required.

---

**Made with ❤️ to support safer and more independent mobility.**
