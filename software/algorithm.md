# System Algorithm

1. **Setup Phase:**
   - Configure Trigger pin as Output.
   - Configure Echo pin as Input.
   - Configure LED pins (Red, Yellow, Green) as Output.
   - Configure Buzzer pin as Output.
   - Initialize Serial communication at 9600 baud.
   - Initialize I2C LCD (16x2) and turn on backlight.

2. **Measurement Phase:**
   - Write LOW to Trigger pin for 2 microseconds.
   - Write HIGH to Trigger pin for 10 microseconds.
   - Write LOW to Trigger pin.
   - Read the duration of the HIGH pulse on the Echo pin using `pulseIn()`.

3. **Calculation Phase:**
   - Convert duration to distance in cm: `distance = (duration / 2) * 0.0343;`

4. **Feedback Logic Phase:**
   - **If distance < 20 cm:**
     - Turn ON Red LED, turn OFF Green and Yellow LEDs.
     - Activate Buzzer with high frequency/continuous tone.
     - Print "Danger!" on LCD.
   - **Else If distance >= 20 cm AND distance <= 50 cm:**
     - Turn ON Yellow LED, turn OFF Green and Red LEDs.
     - Activate Buzzer with moderate interval beeps.
     - Print "Warning" on LCD.
   - **Else (distance > 50 cm):**
     - Turn ON Green LED, turn OFF Yellow and Red LEDs.
     - Turn OFF Buzzer.
     - Print "Safe" on LCD.

5. **Loop Delay Phase:**
   - Wait 100-200 milliseconds before taking the next reading to prevent echo overlap.
