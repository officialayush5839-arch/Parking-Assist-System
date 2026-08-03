# Engineering Notes

## Design Decisions
- **I2C LCD**: We opted for an I2C LCD over a standard parallel LCD to save digital pins on the Arduino Uno. Standard parallel takes up to 6 pins, while I2C takes only 2 analog pins (A4, A5).
- **Procedural Design**: For simplicity in an entry-level system, we used a procedural loop with `delay()`.
- **Thresholds**: 20cm and 50cm were chosen arbitrarily for a desktop model. In a real car, these would be scaled up (e.g., 100cm, 30cm).

## Optimization Opportunities
- Replace `delay()` with `millis()` for true non-blocking operation.
- Implement an Exponential Moving Average (EMA) filter on the distance readings to smooth out sensor noise and prevent flickering when the object is hovering right at a threshold.
- Adjust buzzer PWM frequency for a more pleasant tone.
