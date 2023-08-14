# Touch Sensor with Moving Average

This Arduino sketch demonstrates touch sensor control using a moving average to stabilize readings. It offers two options: one for Arduino boards and another for ESP32 boards. The sketch uses a capacitive touch sensor to toggle an output pin (motor) based on touch events detected by the moving average of sensor readings.

## Requirements

- **Option 1 (Arduino):**
  - Arduino board (e.g., Arduino Uno)
  - Capacitive touch sensor connected to pins 6 and 5
  - Motor driver circuit connected to pin 7 for motor control
  - [CapacitiveSensor library](https://playground.arduino.cc/Main/CapacitiveSensor/) installed

- **Option 2 (ESP32):**
  - ESP32 board (e.g., ESP32 DevKit)
  - Capacitive touch sensor connected to pin 4
  - Motor driver circuit connected to pin 12 for motor control

## Getting Started

Choose the appropriate option for your hardware and follow the respective setup instructions:

### Option 1: Arduino

1. Connect the capacitive touch sensor to pins 6 and 5 of the Arduino.
2. Connect a motor driver circuit to pin 7 of the Arduino for motor control.
3. Install the [CapacitiveSensor library](https://playground.arduino.cc/Main/CapacitiveSensor/) if not already installed.
4. Upload the provided sketch to your Arduino board.
5. Open the Serial Monitor at a baud rate of 9600 to view the sensor readings and calculated values.

### Option 2: ESP32

1. Connect the capacitive touch sensor to pin 4 of the ESP32.
2. Connect a motor driver circuit to pin 12 of the ESP32 for motor control.
3. Upload the provided sketch to your ESP32 board.
4. Open the Serial Monitor at a baud rate of 9600 to view the sensor readings and calculated values.

![Circuit Diagram](https://github.com/mikewharton/touch-sensor/blob/main/circuit_diagram.png)

## Code Explanation

The provided sketches follow similar steps and logic:

1. Initialize necessary variables and constants.
2. Set up the pinMode for the motor and capacitive touch sensor.
3. If you're using the Arduino option, set the capacitive sensor autocalibration.
4. In the loop:
   - Read the sensor value and calculate the moving average using the `avgMoving` function.
   - Toggle the motor based on the calculated moving average and threshold values.
   - Update previous values and optionally print sensor information to the Serial Monitor.

## Adjusting Parameters

You can adjust the following parameters in the sketches to customize behavior:

- `const int mPin`: Output pin for controlling the motor.
- `const byte n`: Number of readings to consider for the moving average.
- `const float th`: Threshold for detecting touch events.
- `delay(5)`: Adjust the delay time between readings if necessary.
