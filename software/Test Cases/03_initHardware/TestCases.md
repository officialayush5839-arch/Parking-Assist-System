# Test Cases for 03_initHardware

Total Unique Test Cases: 6

### TC-INITHARDWARE-001: Verify TRIG configured as OUTPUT
- **Requirement ID**: REQ-HW-TRIG
- **Category**: Hardware Verification
- **Inputs**: Pin=7, Mode=OUTPUT
- **Expected Result**: Pin 7 is set to OUTPUT
- **Source block**: pinMode(TRIG, OUTPUT);

### TC-INITHARDWARE-002: Verify ECHO configured as INPUT
- **Requirement ID**: REQ-HW-ECHO
- **Category**: Hardware Verification
- **Inputs**: Pin=6, Mode=INPUT
- **Expected Result**: Pin 6 is set to INPUT
- **Source block**: pinMode(ECHO, INPUT);

### TC-INITHARDWARE-003: Verify GREEN_LED configured as OUTPUT
- **Requirement ID**: REQ-HW-GREEN_LED
- **Category**: Hardware Verification
- **Inputs**: Pin=9, Mode=OUTPUT
- **Expected Result**: Pin 9 is set to OUTPUT
- **Source block**: pinMode(GREEN_LED, OUTPUT);

### TC-INITHARDWARE-004: Verify YELLOW_LED configured as OUTPUT
- **Requirement ID**: REQ-HW-YELLOW_LED
- **Category**: Hardware Verification
- **Inputs**: Pin=8, Mode=OUTPUT
- **Expected Result**: Pin 8 is set to OUTPUT
- **Source block**: pinMode(YELLOW_LED, OUTPUT);

### TC-INITHARDWARE-005: Verify RED_LED configured as OUTPUT
- **Requirement ID**: REQ-HW-RED_LED
- **Category**: Hardware Verification
- **Inputs**: Pin=10, Mode=OUTPUT
- **Expected Result**: Pin 10 is set to OUTPUT
- **Source block**: pinMode(RED_LED, OUTPUT);

### TC-INITHARDWARE-006: Verify BUZZER configured as OUTPUT
- **Requirement ID**: REQ-HW-BUZZER
- **Category**: Hardware Verification
- **Inputs**: Pin=13, Mode=OUTPUT
- **Expected Result**: Pin 13 is set to OUTPUT
- **Source block**: pinMode(BUZZER, OUTPUT);

