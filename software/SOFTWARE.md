# Software Overview

## Software Architecture
The software is designed as a single-threaded loop running on an Arduino. It follows a procedural paradigm with setup initialization and a continuous execution loop that periodically polls the sensor and updates outputs.

## Code Flow
1. **Initialization (`setup`)**: Pin modes are set, I2C LCD is initialized, serial communication is started.
2. **Main Loop (`loop`)**:
   - Trigger ultrasonic pulse.
   - Read echo time.
   - Calculate distance.
   - Update LEDs and buzzer based on distance.
   - Update LCD.
   - Delay before next reading.

## Distance Calculation
Distance (cm) = (Echo Time in microseconds / 2) / 29.1
(Speed of sound is approx 343 m/s).

## LCD Update Logic
The LCD is cleared when status changes or distance crosses thresholds to avoid flickering. The first line displays "Distance: XX cm" and the second line displays "Status: [SAFE/WARN/DANGER]".

## Alert Logic
- **Safe (>50cm)**: Green LED on. Buzzer off.
- **Warning (20-50cm)**: Yellow LED on. Buzzer beeps slowly.
- **Danger (<20cm)**: Red LED on. Buzzer beeps rapidly or remains solid.

## Error Handling
If distance reading is out of bounds (e.g., > 400cm or 0), the system displays "Out of range" and acts as if in a Safe state.

## Non-blocking Design
Future iterations can use `millis()` instead of `delay()` for buzzer beeps and sensor polling to achieve a truly non-blocking architecture. Currently, a small delay is used in `loop()`.

## Timing Diagram
- 10us trigger pulse
- Variable echo high time
- 50ms processing
- 100ms loop delay

## Known Limitations
- The `delay()` function halts the processor, which can cause slight latency in UI updates if delays are large.
- Single sensor lacks directional awareness.
