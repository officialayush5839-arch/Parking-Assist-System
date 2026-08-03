# Hardware Overview

## Project Overview
The Arduino Parking Assist System uses an ultrasonic sensor to measure distance to obstacles and provides visual (LED) and audible (Buzzer) feedback along with an LCD display.

## Working Principle
1. The HC-SR04 ultrasonic sensor sends a ping.
2. The Arduino measures the echo time to calculate distance.
3. Based on distance thresholds, specific LEDs are lit and a buzzer sounds at varying frequencies.
4. The distance and status are displayed on the 16x2 I2C LCD.

## Component List
- Arduino Uno
- HC-SR04 Ultrasonic Sensor
- 16x2 I2C LCD Display
- 3 LEDs (Green, Yellow, Red)
- Active Buzzer
- 330 ohm resistors
- Jumper Wires

## Power Requirements
- Voltage: 5V (from Arduino or external power supply)
- Current: ~150mA maximum

## Complete Wiring Explanation
See `circuit-overview.md` and `pin-configuration.md`.

## Pin Mapping Table
See `pin-configuration.md`.

## Sensor Working
The HC-SR04 sensor operates at 5V, using a Trigger pin to send a 10us ultrasonic pulse. The Echo pin outputs a high signal whose duration corresponds to the time it takes for the pulse to return.

## LCD Working
The 16x2 LCD uses an I2C module (typically at address 0x27) connected to A4 (SDA) and A5 (SCL) to minimize pin usage.

## LED Logic
- > 50 cm: Green ON, Yellow OFF, Red OFF
- 20 cm - 50 cm: Green OFF, Yellow ON, Red OFF
- < 20 cm: Green OFF, Yellow OFF, Red ON

## Buzzer Logic
- > 50 cm: OFF
- 20 cm - 50 cm: Beeps at a slow rate
- < 20 cm: Continuous Beep or fast beeping

## Safety Notes
- Do not exceed 5V on any components except if using a separate power supply for the Arduino via VIN.
- Use current-limiting resistors for the LEDs.

## Hardware Limitations
- Sensor range is typically 2cm to 400cm.
- Sound reflection from soft objects might be inaccurate.

## Future Enhancements
- See `FutureWork.md` (to be created).

<!-- TODO: insert hardware-overview-diagram.png -->
