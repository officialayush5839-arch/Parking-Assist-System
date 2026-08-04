# Test Cases for 05_displayStartupMessage

Total Unique Test Cases: 3

### TC-DISPLAYSTARTUPMESSAGE-001: Verify startup line 0
- **Requirement ID**: REQ-STARTUP-0
- **Category**: Functional
- **Inputs**: N/A
- **Expected Result**: Cursor at (0,0) prints 'PARKING ASSIST'
- **Source block**: lcd.setCursor(0,0); lcd.print("PARKING ASSIST");

### TC-DISPLAYSTARTUPMESSAGE-002: Verify startup line 1
- **Requirement ID**: REQ-STARTUP-1
- **Category**: Functional
- **Inputs**: N/A
- **Expected Result**: Cursor at (0,1) prints 'Initializing'
- **Source block**: lcd.setCursor(0,1); lcd.print("Initializing");

### TC-DISPLAYSTARTUPMESSAGE-003: Verify startup delay duration
- **Requirement ID**: REQ-STARTUP-DLY
- **Category**: Timing Verification
- **Inputs**: N/A
- **Expected Result**: Execution blocks for exactly 2000 ms before lcd.clear()
- **Source block**: delay(2000); lcd.clear();

