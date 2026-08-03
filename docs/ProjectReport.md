# Project Report: Arduino Parking Assist System

## Problem Statement
Maneuvering vehicles in tight parking spaces is prone to accidental collisions due to blind spots. A cost-effective and accurate distance measurement system is needed to alert drivers of proximity to obstacles.

## Objectives
- Measure distance accurately using an ultrasonic sensor.
- Provide real-time visual feedback using LEDs.
- Provide auditory alerts using a buzzer.
- Display precise distance and status on an LCD.

## Components
- Arduino Uno
- HC-SR04 Ultrasonic Sensor
- I2C 16x2 LCD
- LEDs (Green, Yellow, Red)
- Buzzer
- Resistors and Jumper Wires

## Methodology
The system continuously pings the ultrasonic sensor. The echo duration is converted to distance. This distance is classified into three zones (Safe, Warning, Danger), updating the LCD, LEDs, and buzzer appropriately.

## Algorithm
1. Ping HC-SR04.
2. Calculate distance.
3. Determine Zone.
4. Output to LEDs/Buzzer.
5. Update LCD.
6. Delay and repeat.

## Results
The system successfully detects obstacles between 2 cm and 400 cm. The LEDs accurately transition at the 50cm and 20cm thresholds, and the buzzer frequency increases as the obstacle gets closer.

## Advantages
- Cost-effective.
- Easy to install.
- Low power consumption.
- Immediate response.

## Limitations
- Single point of measurement (one sensor).
- Sensor performance degrades with sound-absorbing materials.
- Max range limited to 4m.

## Future Scope
See `FutureWork.md`.

## Conclusion
The Arduino Parking Assist System is a reliable, entry-level proof-of-concept for vehicle proximity detection, demonstrating fundamental sensor integration and feedback mechanisms.
