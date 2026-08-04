# Function Coverage Report

## Module: ParkingAssist.ino

------------------------------------------------
**Function Name**: `initHardware`
**Purpose**: Configures pin modes for the sensor, LEDs, and buzzer.
**Lines of Code**: 9
**Decision Points**: 0
**Conditions**: 0
**Branches**: 0
**Loops**: 0
**Thresholds**: None
**State Variables**: None
**Hardware Components Used**: TRIG pin, ECHO pin, GREEN_LED pin, YELLOW_LED pin, RED_LED pin, BUZZER pin
**Outputs**: Pin configuration
**Failure Modes**: None handled programmatically
**Recovery Paths**: N/A
**Total Meaningful Test Cases Generated**: 6
**Estimated Statement Coverage**: 100%
**Estimated Branch Coverage**: N/A
**Estimated Condition Coverage**: N/A
**Estimated Requirement Coverage**: 100%
**Coverage Limitations**: Cannot test actual electrical continuity in code.
**Future Testing Recommendations**: Hardware-in-the-loop (HIL) testing to verify electrical pin state.

------------------------------------------------
**Function Name**: `initLCD`
**Purpose**: Initializes the LCD and clears the screen.
**Lines of Code**: 4
**Decision Points**: 0
**Conditions**: 0
**Branches**: 0
**Loops**: 0
**Thresholds**: None
**State Variables**: None
**Hardware Components Used**: 16x2 LCD
**Outputs**: LCD initialization commands
**Failure Modes**: I2C/Parallel bus failure (not handled)
**Recovery Paths**: N/A
**Total Meaningful Test Cases Generated**: 2
**Estimated Statement Coverage**: 100%
**Estimated Branch Coverage**: N/A
**Estimated Condition Coverage**: N/A
**Estimated Requirement Coverage**: 100%
**Coverage Limitations**: Assumes LiquidCrystal library correctness.
**Future Testing Recommendations**: Validate timings using an oscilloscope.

------------------------------------------------
**Function Name**: `displayStartupMessage`
**Purpose**: Shows an introductory message for 2 seconds.
**Lines of Code**: 8
**Decision Points**: 0
**Conditions**: 0
**Branches**: 0
**Loops**: 0
**Thresholds**: None
**State Variables**: None
**Hardware Components Used**: 16x2 LCD
**Outputs**: Text to LCD
**Failure Modes**: None handled
**Recovery Paths**: N/A
**Total Meaningful Test Cases Generated**: 4
**Estimated Statement Coverage**: 100%
**Estimated Branch Coverage**: N/A
**Estimated Condition Coverage**: N/A
**Estimated Requirement Coverage**: 100%
**Coverage Limitations**: Hardcoded delay blocks execution.
**Future Testing Recommendations**: Verify user visual acceptance.

------------------------------------------------
**Function Name**: `setup`
**Purpose**: Initializes hardware pins, starts the LCD, and displays an introductory message.
**Lines of Code**: 6
**Decision Points**: 0
**Conditions**: 0
**Branches**: 0
**Loops**: 0
**Thresholds**: None
**State Variables**: None
**Hardware Components Used**: All System Hardware
**Outputs**: System Ready State
**Failure Modes**: None handled
**Recovery Paths**: N/A
**Total Meaningful Test Cases Generated**: 1
**Estimated Statement Coverage**: 100%
**Estimated Branch Coverage**: N/A
**Estimated Condition Coverage**: N/A
**Estimated Requirement Coverage**: 100%
**Coverage Limitations**: High-level integration function, relies on sub-function coverage.
**Future Testing Recommendations**: End-to-end boot sequence timing analysis.

------------------------------------------------
**Function Name**: `loop`
**Purpose**: Main execution loop. Measures distance, handles sensor errors, and updates outputs based on distance.
**Lines of Code**: 14
**Decision Points**: 1
**Conditions**: 1
**Branches**: 2
**Loops**: 1 (Implicit via Arduino core)
**Thresholds**: `distance < 0`
**State Variables**: None
**Hardware Components Used**: HC-SR04, LEDs, Buzzer, LCD
**Outputs**: System state updates
**Failure Modes**: Sensor disconnect or timeout
**Recovery Paths**: Returns early, waiting for valid reading in next cycle.
**Total Meaningful Test Cases Generated**: 2
**Estimated Statement Coverage**: 100%
**Estimated Branch Coverage**: 100%
**Estimated Condition Coverage**: 100%
**Estimated Requirement Coverage**: 100%
**Coverage Limitations**: Timing variations dependent on sensor reading time.
**Future Testing Recommendations**: Run loop time jitter analysis.

------------------------------------------------
**Function Name**: `readDistance`
**Purpose**: Reads the HC-SR04 sensor and returns distance.
**Lines of Code**: 22
**Decision Points**: 2
**Conditions**: 2
**Branches**: 3
**Loops**: 0
**Thresholds**: `duration == 0`, `distance > MAX_DISTANCE_CM`
**State Variables**: None
**Hardware Components Used**: HC-SR04 Ultrasonic Sensor
**Outputs**: Distance in cm (float)
**Failure Modes**: Sensor timeout, object out of range
**Recovery Paths**: Returns -1 for caller to handle.
**Total Meaningful Test Cases Generated**: 4
**Estimated Statement Coverage**: 100%
**Estimated Branch Coverage**: 100%
**Estimated Condition Coverage**: 100%
**Estimated Requirement Coverage**: 100%
**Coverage Limitations**: Acoustic interference cannot be tested in unit tests.
**Future Testing Recommendations**: Test with physical obstacles of varying materials (acoustic absorption).

------------------------------------------------
**Function Name**: `updateLCD`
**Purpose**: Updates the 16x2 LCD display with current distance and status text.
**Lines of Code**: 27
**Decision Points**: 5
**Conditions**: 6
**Branches**: 6
**Loops**: 0
**Thresholds**: `SAFE_LIMIT`, `CAUTION_LIMIT`, `WARNING_LIMIT`
**State Variables**: `lastDisplayedDistance`, `lastDisplayedState`
**Hardware Components Used**: 16x2 LCD
**Outputs**: LCD Text Updates
**Failure Modes**: Invalid floating point numbers (not handled)
**Recovery Paths**: State tracks 4 (Error) to force full redraw on recovery.
**Total Meaningful Test Cases Generated**: 8
**Estimated Statement Coverage**: 100%
**Estimated Branch Coverage**: 100%
**Estimated Condition Coverage**: 100%
**Estimated Requirement Coverage**: 100%
**Coverage Limitations**: Contrast/backlight issues cannot be caught.
**Future Testing Recommendations**: Test in extreme temperatures for display lag.

------------------------------------------------
**Function Name**: `updateAlerts`
**Purpose**: Controls LEDs and Buzzer based on distance thresholds.
**Lines of Code**: 25
**Decision Points**: 3
**Conditions**: 3
**Branches**: 4
**Loops**: 0
**Thresholds**: `SAFE_LIMIT`, `CAUTION_LIMIT`, `WARNING_LIMIT`
**State Variables**: None
**Hardware Components Used**: GREEN_LED, YELLOW_LED, RED_LED, BUZZER
**Outputs**: LED states (HIGH/LOW), Buzzer tone
**Failure Modes**: None
**Recovery Paths**: Disables unused outputs for given state.
**Total Meaningful Test Cases Generated**: 4
**Estimated Statement Coverage**: 100%
**Estimated Branch Coverage**: 100%
**Estimated Condition Coverage**: 100%
**Estimated Requirement Coverage**: 100%
**Coverage Limitations**: Assumes hardware correctly sinks/sources current.
**Future Testing Recommendations**: Verify power draw when all warnings are active.

------------------------------------------------
**Function Name**: `beep`
**Purpose**: Generates a non-blocking tone on the buzzer with a specified interval and frequency.
**Lines of Code**: 14
**Decision Points**: 2
**Conditions**: 2
**Branches**: 4
**Loops**: 0
**Thresholds**: `now - previousBeep >= interval`
**State Variables**: `previousBeep`, `beepState`
**Hardware Components Used**: BUZZER
**Outputs**: Buzzer Tone ON/OFF
**Failure Modes**: Timer overflow (millis rollover not fully handled natively if not carefully subtracted, but typical `now - prev >= interval` is safe).
**Recovery Paths**: Toggles state correctly.
**Total Meaningful Test Cases Generated**: 5
**Estimated Statement Coverage**: 100%
**Estimated Branch Coverage**: 100%
**Estimated Condition Coverage**: 100%
**Estimated Requirement Coverage**: 100%
**Coverage Limitations**: Millis rollover requires 49 days of continuous uptime to occur.
**Future Testing Recommendations**: Long-duration stability test (50+ days).

------------------------------------------------
**Function Name**: `showSensorError`
**Purpose**: Displays an error message on the LCD and turns off all LEDs and the buzzer.
**Lines of Code**: 17
**Decision Points**: 1
**Conditions**: 1
**Branches**: 2
**Loops**: 0
**Thresholds**: `lastDisplayedState != 4`
**State Variables**: `lastDisplayedState`, `lastDisplayedDistance`
**Hardware Components Used**: LCD, LEDs, BUZZER
**Outputs**: LCD Text, LOW to LEDs, noTone
**Failure Modes**: LCD disconnection
**Recovery Paths**: Redundant calls are optimized away.
**Total Meaningful Test Cases Generated**: 4
**Estimated Statement Coverage**: 100%
**Estimated Branch Coverage**: 100%
**Estimated Condition Coverage**: 100%
**Estimated Requirement Coverage**: 100%
**Coverage Limitations**: None for logic path.
**Future Testing Recommendations**: Verify user comprehension of error message.
