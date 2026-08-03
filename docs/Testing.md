# Testing Documentation

## Functional Testing
All core functionalities are tested individually.

## Distance Testing
Measurements verified with a tape measure:
- Expected: 10cm, Actual: 10cm ±1cm
- Expected: 50cm, Actual: 50cm ±2cm
- Expected: 200cm, Actual: 200cm ±5cm

## LED Testing
- Obstacle > 50cm: Green LED ON, others OFF (Pass)
- Obstacle 20-50cm: Yellow LED ON, others OFF (Pass)
- Obstacle < 20cm: Red LED ON, others OFF (Pass)

## LCD Testing
- Verify I2C address.
- Verify text updates without flickering.
- Verify exact distance string formatting.

## Buzzer Testing
- No sound at > 50cm.
- Beeping at 20-50cm.
- Continuous/Fast beep at < 20cm.

## Sensor Failure Testing
- Disconnect Echo Pin: Distance defaults to 0, system goes to "Danger". (Pass/Fail criteria depends on fail-safe design).

## Expected Results Table

| Test Case | Condition | Expected Output (LED) | Expected Output (Buzzer) | Expected Output (LCD) |
|-----------|-----------|-----------------------|--------------------------|-----------------------|
| 1 | Dist = 60cm | Green | OFF | Distance: 60 cm / SAFE |
| 2 | Dist = 30cm | Yellow | Slow Beep | Distance: 30 cm / WARN |
| 3 | Dist = 10cm | Red | Fast/Solid | Distance: 10 cm / DANGER|
