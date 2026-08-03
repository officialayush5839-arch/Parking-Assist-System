# Circuit Overview

This document provides a high-level overview of the circuit.

<!-- TODO: insert wiring-diagram.png -->

## Main Connections
- The HC-SR04 sensor is connected to digital pins for Trigger and Echo.
- The I2C LCD uses the I2C bus (A4/A5 on standard Arduino Uno).
- LEDs are connected to digital output pins with series current-limiting resistors.
- The buzzer is connected to a PWM-capable digital pin for variable tones.

Ensure common ground is shared among all components.
