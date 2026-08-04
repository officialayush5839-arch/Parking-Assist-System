# Test Cases for 11_beep

Total Unique Test Cases: 6

### TC-BEEP-001: Verify beep toggle at diff=499, prevState=True
- **Requirement ID**: REQ-BEEP-499-True
- **Category**: Boundary
- **Inputs**: now=499, interval=500
- **Expected Result**: No action
- **Source block**: N/A

### TC-BEEP-002: Verify beep toggle at diff=499, prevState=False
- **Requirement ID**: REQ-BEEP-499-False
- **Category**: Boundary
- **Inputs**: now=499, interval=500
- **Expected Result**: No action
- **Source block**: N/A

### TC-BEEP-003: Verify beep toggle at diff=500, prevState=True
- **Requirement ID**: REQ-BEEP-500-True
- **Category**: Boundary
- **Inputs**: now=500, interval=500
- **Expected Result**: noTone(BUZZER)
- **Source block**: N/A

### TC-BEEP-004: Verify beep toggle at diff=500, prevState=False
- **Requirement ID**: REQ-BEEP-500-False
- **Category**: Boundary
- **Inputs**: now=500, interval=500
- **Expected Result**: tone(BUZZER, freq)
- **Source block**: N/A

### TC-BEEP-005: Verify beep toggle at diff=501, prevState=True
- **Requirement ID**: REQ-BEEP-501-True
- **Category**: State Transition
- **Inputs**: now=501, interval=500
- **Expected Result**: noTone(BUZZER)
- **Source block**: N/A

### TC-BEEP-006: Verify beep toggle at diff=501, prevState=False
- **Requirement ID**: REQ-BEEP-501-False
- **Category**: State Transition
- **Inputs**: now=501, interval=500
- **Expected Result**: tone(BUZZER, freq)
- **Source block**: N/A

