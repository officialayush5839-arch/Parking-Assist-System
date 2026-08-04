# Test Cases for 12_showSensorError

Total Unique Test Cases: 3

### TC-SHOWSENSORERROR-001: Verify error logic when lastDisplayedState=0
- **Requirement ID**: REQ-ERR-0
- **Category**: Decision
- **Inputs**: N/A
- **Expected Result**: Prints Error to LCD, state updated to 4. LEDs LOW, noTone.
- **Source block**: N/A

### TC-SHOWSENSORERROR-002: Verify error logic when lastDisplayedState=3
- **Requirement ID**: REQ-ERR-3
- **Category**: Decision
- **Inputs**: N/A
- **Expected Result**: Prints Error to LCD, state updated to 4. LEDs LOW, noTone.
- **Source block**: N/A

### TC-SHOWSENSORERROR-003: Verify error logic when lastDisplayedState=4
- **Requirement ID**: REQ-ERR-4
- **Category**: Decision
- **Inputs**: N/A
- **Expected Result**: LCD print skipped. LEDs LOW, noTone.
- **Source block**: N/A

