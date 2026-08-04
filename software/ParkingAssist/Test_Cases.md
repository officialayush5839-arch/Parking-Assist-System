# Parking Assist System - Test Cases

## Module: ParkingAssist.ino

### Function: `initHardware()`
**TC01: Verify TRIG pin configuration**
- **Function Name**: `initHardware`
- **Code Block**: `pinMode(TRIG, OUTPUT);`
- **Related Constant(s)**: `TRIG = 7`
- **Related Threshold(s)**: N/A
- **Decision Branch**: N/A
- **Requirement ID**: REQ-HW-01
- **Module**: ParkingAssist.ino
- **Description**: Verify that the TRIG pin is configured as an OUTPUT.

**TC02: Verify ECHO pin configuration**
- **Function Name**: `initHardware`
- **Code Block**: `pinMode(ECHO, INPUT);`
- **Related Constant(s)**: `ECHO = 6`
- **Related Threshold(s)**: N/A
- **Decision Branch**: N/A
- **Requirement ID**: REQ-HW-02
- **Module**: ParkingAssist.ino
- **Description**: Verify that the ECHO pin is configured as an INPUT.

**TC03: Verify GREEN_LED pin configuration**
- **Function Name**: `initHardware`
- **Code Block**: `pinMode(GREEN_LED, OUTPUT);`
- **Related Constant(s)**: `GREEN_LED = 9`
- **Related Threshold(s)**: N/A
- **Decision Branch**: N/A
- **Requirement ID**: REQ-HW-03
- **Module**: ParkingAssist.ino
- **Description**: Verify that the GREEN_LED pin is configured as an OUTPUT.

**TC04: Verify YELLOW_LED pin configuration**
- **Function Name**: `initHardware`
- **Code Block**: `pinMode(YELLOW_LED, OUTPUT);`
- **Related Constant(s)**: `YELLOW_LED = 8`
- **Related Threshold(s)**: N/A
- **Decision Branch**: N/A
- **Requirement ID**: REQ-HW-04
- **Module**: ParkingAssist.ino
- **Description**: Verify that the YELLOW_LED pin is configured as an OUTPUT.

**TC05: Verify RED_LED pin configuration**
- **Function Name**: `initHardware`
- **Code Block**: `pinMode(RED_LED, OUTPUT);`
- **Related Constant(s)**: `RED_LED = 10`
- **Related Threshold(s)**: N/A
- **Decision Branch**: N/A
- **Requirement ID**: REQ-HW-05
- **Module**: ParkingAssist.ino
- **Description**: Verify that the RED_LED pin is configured as an OUTPUT.

**TC06: Verify BUZZER pin configuration**
- **Function Name**: `initHardware`
- **Code Block**: `pinMode(BUZZER, OUTPUT);`
- **Related Constant(s)**: `BUZZER = 13`
- **Related Threshold(s)**: N/A
- **Decision Branch**: N/A
- **Requirement ID**: REQ-HW-06
- **Module**: ParkingAssist.ino
- **Description**: Verify that the BUZZER pin is configured as an OUTPUT.

### Function: `initLCD()`
**TC07: Verify LCD initialization**
- **Function Name**: `initLCD`
- **Code Block**: `lcd.begin(16,2);`
- **Related Constant(s)**: N/A
- **Related Threshold(s)**: N/A
- **Decision Branch**: N/A
- **Requirement ID**: REQ-LCD-01
- **Module**: ParkingAssist.ino
- **Description**: Verify that the LCD is initialized with 16 columns and 2 rows.

**TC08: Verify LCD clearing**
- **Function Name**: `initLCD`
- **Code Block**: `lcd.clear();`
- **Related Constant(s)**: N/A
- **Related Threshold(s)**: N/A
- **Decision Branch**: N/A
- **Requirement ID**: REQ-LCD-02
- **Module**: ParkingAssist.ino
- **Description**: Verify that the LCD screen is cleared upon initialization.

### Function: `displayStartupMessage()`
**TC09: Verify top line of startup message**
- **Function Name**: `displayStartupMessage`
- **Code Block**: `lcd.print("PARKING ASSIST");`
- **Related Constant(s)**: N/A
- **Related Threshold(s)**: N/A
- **Decision Branch**: N/A
- **Requirement ID**: REQ-UI-01
- **Module**: ParkingAssist.ino
- **Description**: Verify that "PARKING ASSIST" is printed on the first line (0,0).

**TC10: Verify bottom line of startup message**
- **Function Name**: `displayStartupMessage`
- **Code Block**: `lcd.print("Initializing");`
- **Related Constant(s)**: N/A
- **Related Threshold(s)**: N/A
- **Decision Branch**: N/A
- **Requirement ID**: REQ-UI-02
- **Module**: ParkingAssist.ino
- **Description**: Verify that "Initializing" is printed on the second line (0,1).

**TC11: Verify startup message delay**
- **Function Name**: `displayStartupMessage`
- **Code Block**: `delay(2000);`
- **Related Constant(s)**: N/A
- **Related Threshold(s)**: N/A
- **Decision Branch**: N/A
- **Requirement ID**: REQ-UI-03
- **Module**: ParkingAssist.ino
- **Description**: Verify that a 2000ms delay occurs before clearing the message.

**TC12: Verify LCD clear after startup message**
- **Function Name**: `displayStartupMessage`
- **Code Block**: `lcd.clear();`
- **Related Constant(s)**: N/A
- **Related Threshold(s)**: N/A
- **Decision Branch**: N/A
- **Requirement ID**: REQ-UI-04
- **Module**: ParkingAssist.ino
- **Description**: Verify that the LCD screen is cleared after the startup delay.

### Function: `setup()`
**TC13: Verify setup sequence execution**
- **Function Name**: `setup`
- **Code Block**: Sequence of `initHardware()`, `initLCD()`, `displayStartupMessage()`
- **Related Constant(s)**: N/A
- **Related Threshold(s)**: N/A
- **Decision Branch**: N/A
- **Requirement ID**: REQ-SYS-01
- **Module**: ParkingAssist.ino
- **Description**: Verify that `initHardware`, `initLCD`, and `displayStartupMessage` are executed in order during system setup.

### Function: `loop()`
**TC14: Verify normal execution path**
- **Function Name**: `loop`
- **Code Block**: `if (distance < 0)` ... `else` logic
- **Related Constant(s)**: N/A
- **Related Threshold(s)**: `distance >= 0`
- **Decision Branch**: False (`distance >= 0`)
- **Requirement ID**: REQ-SYS-02
- **Module**: ParkingAssist.ino
- **Description**: Verify that for a valid distance, `updateLCD`, `updateAlerts`, and a 50ms delay are executed.

**TC15: Verify sensor error handling path**
- **Function Name**: `loop`
- **Code Block**: `if (distance < 0) { showSensorError(); return; }`
- **Related Constant(s)**: N/A
- **Related Threshold(s)**: `distance < 0`
- **Decision Branch**: True (`distance < 0`)
- **Requirement ID**: REQ-SYS-03
- **Module**: ParkingAssist.ino
- **Description**: Verify that if `readDistance()` returns < 0, `showSensorError()` is called and the loop terminates early.

### Function: `readDistance()`
**TC16: Verify successful distance measurement**
- **Function Name**: `readDistance`
- **Code Block**: `float distance = duration * SPEED_OF_SOUND_CM_PER_US / 2.0;`
- **Related Constant(s)**: `SPEED_OF_SOUND_CM_PER_US`, `MAX_DISTANCE_CM`, `SENSOR_TIMEOUT`
- **Related Threshold(s)**: `duration > 0` and `distance <= 400.0`
- **Decision Branch**: `if (duration == 0)` is False, `if (distance > MAX_DISTANCE_CM)` is False
- **Requirement ID**: REQ-SENS-01
- **Module**: ParkingAssist.ino
- **Description**: Verify that a valid echo pulse calculates and returns the correct distance.

**TC17: Verify pulse timeout handling**
- **Function Name**: `readDistance`
- **Code Block**: `if (duration == 0) return -1;`
- **Related Constant(s)**: `SENSOR_TIMEOUT`
- **Related Threshold(s)**: `duration == 0`
- **Decision Branch**: True
- **Requirement ID**: REQ-SENS-02
- **Module**: ParkingAssist.ino
- **Description**: Verify that if `pulseIn` times out (returns 0), the function returns -1.

**TC18: Verify out-of-range upper bound handling**
- **Function Name**: `readDistance`
- **Code Block**: `if (distance > MAX_DISTANCE_CM) return -1;`
- **Related Constant(s)**: `MAX_DISTANCE_CM = 400.0`
- **Related Threshold(s)**: `distance > 400.0`
- **Decision Branch**: True
- **Requirement ID**: REQ-SENS-03
- **Module**: ParkingAssist.ino
- **Description**: Verify that calculated distance > 400.0 cm is rejected and returns -1.

**TC19: Verify maximum valid boundary**
- **Function Name**: `readDistance`
- **Code Block**: `if (distance > MAX_DISTANCE_CM)`
- **Related Constant(s)**: `MAX_DISTANCE_CM = 400.0`
- **Related Threshold(s)**: `distance == 400.0`
- **Decision Branch**: False
- **Requirement ID**: REQ-SENS-04
- **Module**: ParkingAssist.ino
- **Description**: Verify that calculated distance of exactly 400.0 cm is accepted and returned.

### Function: `updateLCD()`
**TC20: Verify SAFE state LCD update**
- **Function Name**: `updateLCD`
- **Code Block**: `if (distance > SAFE_LIMIT) currentState = 0;`
- **Related Constant(s)**: `SAFE_LIMIT = 100`
- **Related Threshold(s)**: `distance > 100`
- **Decision Branch**: `distance > SAFE_LIMIT` is True
- **Requirement ID**: REQ-LCD-03
- **Module**: ParkingAssist.ino
- **Description**: Verify that distance > 100 sets state to SAFE and updates LCD accordingly.

**TC21: Verify CAUTION state upper boundary**
- **Function Name**: `updateLCD`
- **Code Block**: `else if (distance > CAUTION_LIMIT) currentState = 1;`
- **Related Constant(s)**: `SAFE_LIMIT = 100`, `CAUTION_LIMIT = 50`
- **Related Threshold(s)**: `distance == 100`
- **Decision Branch**: `distance > SAFE_LIMIT` False, `distance > CAUTION_LIMIT` True
- **Requirement ID**: REQ-LCD-04
- **Module**: ParkingAssist.ino
- **Description**: Verify that distance = 100 sets state to CAUTION and updates LCD.

**TC22: Verify WARNING state upper boundary**
- **Function Name**: `updateLCD`
- **Code Block**: `else if (distance >= WARNING_LIMIT) currentState = 2;`
- **Related Constant(s)**: `CAUTION_LIMIT = 50`, `WARNING_LIMIT = 20`
- **Related Threshold(s)**: `distance == 50`
- **Decision Branch**: `distance > CAUTION_LIMIT` False, `distance >= WARNING_LIMIT` True
- **Requirement ID**: REQ-LCD-05
- **Module**: ParkingAssist.ino
- **Description**: Verify that distance = 50 sets state to WARNING and updates LCD.

**TC23: Verify WARNING state lower boundary**
- **Function Name**: `updateLCD`
- **Code Block**: `else if (distance >= WARNING_LIMIT) currentState = 2;`
- **Related Constant(s)**: `WARNING_LIMIT = 20`
- **Related Threshold(s)**: `distance == 20`
- **Decision Branch**: `distance >= WARNING_LIMIT` True
- **Requirement ID**: REQ-LCD-06
- **Module**: ParkingAssist.ino
- **Description**: Verify that distance = 20 sets state to WARNING and updates LCD.

**TC24: Verify STOP state boundary**
- **Function Name**: `updateLCD`
- **Code Block**: `else currentState = 3;`
- **Related Constant(s)**: `WARNING_LIMIT = 20`
- **Related Threshold(s)**: `distance < 20`
- **Decision Branch**: `distance >= WARNING_LIMIT` False
- **Requirement ID**: REQ-LCD-07
- **Module**: ParkingAssist.ino
- **Description**: Verify that distance < 20 (e.g. 19.9) sets state to STOP! and updates LCD.

**TC25: Verify redundant LCD update prevention (Distance)**
- **Function Name**: `updateLCD`
- **Code Block**: `if (currentDistance != lastDisplayedDistance || lastDisplayedState == 4)`
- **Related Constant(s)**: N/A
- **Related Threshold(s)**: `currentDistance == lastDisplayedDistance`
- **Decision Branch**: False
- **Requirement ID**: REQ-LCD-08
- **Module**: ParkingAssist.ino
- **Description**: Verify that if the integer distance hasn't changed and no error state exists, the distance row is not unnecessarily redrawn.

**TC26: Verify redundant LCD update prevention (State)**
- **Function Name**: `updateLCD`
- **Code Block**: `if (currentState != lastDisplayedState)`
- **Related Constant(s)**: N/A
- **Related Threshold(s)**: `currentState == lastDisplayedState`
- **Decision Branch**: False
- **Requirement ID**: REQ-LCD-09
- **Module**: ParkingAssist.ino
- **Description**: Verify that if the state hasn't changed, the status row is not unnecessarily redrawn.

**TC27: Verify recovery from sensor error on LCD**
- **Function Name**: `updateLCD`
- **Code Block**: `if (... || lastDisplayedState == 4)`
- **Related Constant(s)**: N/A
- **Related Threshold(s)**: `lastDisplayedState == 4`
- **Decision Branch**: True
- **Requirement ID**: REQ-LCD-10
- **Module**: ParkingAssist.ino
- **Description**: Verify that if recovering from an error state (state 4), the distance row is forced to update regardless of previous distance value.

### Function: `updateAlerts()`
**TC28: Verify SAFE state alerts**
- **Function Name**: `updateAlerts`
- **Code Block**: `if (distance > SAFE_LIMIT)`
- **Related Constant(s)**: `SAFE_LIMIT = 100`
- **Related Threshold(s)**: `distance > 100`
- **Decision Branch**: True
- **Requirement ID**: REQ-ALRT-01
- **Module**: ParkingAssist.ino
- **Description**: Verify green LED is ON, others OFF, and buzzer is silenced with `noTone()`.

**TC29: Verify CAUTION state alerts**
- **Function Name**: `updateAlerts`
- **Code Block**: `else if (distance > CAUTION_LIMIT)`
- **Related Constant(s)**: `CAUTION_LIMIT = 50`
- **Related Threshold(s)**: `distance > 50` and `<= 100`
- **Decision Branch**: True
- **Requirement ID**: REQ-ALRT-02
- **Module**: ParkingAssist.ino
- **Description**: Verify yellow LED is ON, others OFF, and `beep` is called with `BEEP_CAUTION_INTERVAL` and `BEEP_CAUTION_FREQ`.

**TC30: Verify WARNING state alerts**
- **Function Name**: `updateAlerts`
- **Code Block**: `else if (distance >= WARNING_LIMIT)`
- **Related Constant(s)**: `WARNING_LIMIT = 20`
- **Related Threshold(s)**: `distance >= 20` and `<= 50`
- **Decision Branch**: True
- **Requirement ID**: REQ-ALRT-03
- **Module**: ParkingAssist.ino
- **Description**: Verify red LED is ON, others OFF, and `beep` is called with `BEEP_WARNING_INTERVAL` and `BEEP_WARNING_FREQ`.

**TC31: Verify STOP state alerts**
- **Function Name**: `updateAlerts`
- **Code Block**: `else { redOn = true; tone(BUZZER, BEEP_STOP_FREQ); }`
- **Related Constant(s)**: `WARNING_LIMIT = 20`, `BEEP_STOP_FREQ`
- **Related Threshold(s)**: `distance < 20`
- **Decision Branch**: False for all preceding `if` conditions
- **Requirement ID**: REQ-ALRT-04
- **Module**: ParkingAssist.ino
- **Description**: Verify red LED is ON, others OFF, and continuous tone at `BEEP_STOP_FREQ` is output.

### Function: `beep()`
**TC32: Verify beep toggles state on interval**
- **Function Name**: `beep`
- **Code Block**: `if (now - previousBeep >= (unsigned long)interval)`
- **Related Constant(s)**: N/A
- **Related Threshold(s)**: Time elapsed >= `interval`
- **Decision Branch**: True
- **Requirement ID**: REQ-BEEP-01
- **Module**: ParkingAssist.ino
- **Description**: Verify that when interval has elapsed, `beepState` toggles and `previousBeep` is updated.

**TC33: Verify beep outputs tone when state is true**
- **Function Name**: `beep`
- **Code Block**: `if (beepState) { tone(BUZZER, frequency); }`
- **Related Constant(s)**: N/A
- **Related Threshold(s)**: `beepState == true`
- **Decision Branch**: True
- **Requirement ID**: REQ-BEEP-02
- **Module**: ParkingAssist.ino
- **Description**: Verify that when `beepState` evaluates to true, `tone()` is called with provided frequency.

**TC34: Verify beep outputs silence when state is false**
- **Function Name**: `beep`
- **Code Block**: `else { noTone(BUZZER); }`
- **Related Constant(s)**: N/A
- **Related Threshold(s)**: `beepState == false`
- **Decision Branch**: False
- **Requirement ID**: REQ-BEEP-03
- **Module**: ParkingAssist.ino
- **Description**: Verify that when `beepState` evaluates to false, `noTone()` is called.

**TC35: Verify beep ignores early calls**
- **Function Name**: `beep`
- **Code Block**: `if (now - previousBeep >= (unsigned long)interval)`
- **Related Constant(s)**: N/A
- **Related Threshold(s)**: Time elapsed < `interval`
- **Decision Branch**: False
- **Requirement ID**: REQ-BEEP-04
- **Module**: ParkingAssist.ino
- **Description**: Verify that if interval has not elapsed, no action is taken.

**TC36: Verify boundary beep interval condition**
- **Function Name**: `beep`
- **Code Block**: `if (now - previousBeep >= (unsigned long)interval)`
- **Related Constant(s)**: N/A
- **Related Threshold(s)**: Time elapsed == `interval`
- **Decision Branch**: True
- **Requirement ID**: REQ-BEEP-05
- **Module**: ParkingAssist.ino
- **Description**: Verify that exact interval match toggles the buzzer state.

### Function: `showSensorError()`
**TC37: Verify error message initialization**
- **Function Name**: `showSensorError`
- **Code Block**: `if (lastDisplayedState != 4)`
- **Related Constant(s)**: `Error State = 4`
- **Related Threshold(s)**: `lastDisplayedState != 4`
- **Decision Branch**: True
- **Requirement ID**: REQ-ERR-01
- **Module**: ParkingAssist.ino
- **Description**: Verify that if not already in error state, "Sensor Error Check Wiring" is printed to LCD.

**TC38: Verify error state assignment**
- **Function Name**: `showSensorError`
- **Code Block**: `lastDisplayedState = 4; lastDisplayedDistance = -1;`
- **Related Constant(s)**: N/A
- **Related Threshold(s)**: `lastDisplayedState != 4`
- **Decision Branch**: True
- **Requirement ID**: REQ-ERR-02
- **Module**: ParkingAssist.ino
- **Description**: Verify that entering error sets state trackers correctly to prevent redundant LCD refreshes.

**TC39: Verify error state prevents redundant LCD updates**
- **Function Name**: `showSensorError`
- **Code Block**: `if (lastDisplayedState != 4)`
- **Related Constant(s)**: N/A
- **Related Threshold(s)**: `lastDisplayedState == 4`
- **Decision Branch**: False
- **Requirement ID**: REQ-ERR-03
- **Module**: ParkingAssist.ino
- **Description**: Verify that if already in error state 4, no new LCD commands are sent.

**TC40: Verify error disables alerts**
- **Function Name**: `showSensorError`
- **Code Block**: `digitalWrite(... LOW); noTone(BUZZER);`
- **Related Constant(s)**: N/A
- **Related Threshold(s)**: N/A
- **Decision Branch**: N/A
- **Requirement ID**: REQ-ERR-04
- **Module**: ParkingAssist.ino
- **Description**: Verify that all three LEDs are turned off and the buzzer is silenced via `noTone()`.
