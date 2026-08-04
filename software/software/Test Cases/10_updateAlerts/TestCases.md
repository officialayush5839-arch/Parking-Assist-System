# Test Cases for 10_updateAlerts

Total Unique Test Cases: 9

### TC-UPDATEALERTS-001: Verify Alerts for distance=0
- **Requirement ID**: REQ-ALERT-0
- **Category**: Functional
- **Inputs**: distance=0
- **Expected Result**: Green OFF, Yellow OFF, Red ON, tone STOP
- **Source block**: if-else led/buzzer logic

### TC-UPDATEALERTS-002: Verify Alerts for distance=19.9
- **Requirement ID**: REQ-ALERT-19
- **Category**: Functional
- **Inputs**: distance=19.9
- **Expected Result**: Green OFF, Yellow OFF, Red ON, tone STOP
- **Source block**: if-else led/buzzer logic

### TC-UPDATEALERTS-003: Verify Alerts for distance=20.0
- **Requirement ID**: REQ-ALERT-20
- **Category**: Functional
- **Inputs**: distance=20.0
- **Expected Result**: Green OFF, Yellow OFF, Red ON, beep WARNING
- **Source block**: if-else led/buzzer logic

### TC-UPDATEALERTS-004: Verify Alerts for distance=49.9
- **Requirement ID**: REQ-ALERT-49
- **Category**: Functional
- **Inputs**: distance=49.9
- **Expected Result**: Green OFF, Yellow OFF, Red ON, beep WARNING
- **Source block**: if-else led/buzzer logic

### TC-UPDATEALERTS-005: Verify Alerts for distance=50.0
- **Requirement ID**: REQ-ALERT-50
- **Category**: Functional
- **Inputs**: distance=50.0
- **Expected Result**: Green OFF, Yellow OFF, Red ON, beep WARNING
- **Source block**: if-else led/buzzer logic

### TC-UPDATEALERTS-006: Verify Alerts for distance=99.9
- **Requirement ID**: REQ-ALERT-99
- **Category**: Functional
- **Inputs**: distance=99.9
- **Expected Result**: Green OFF, Yellow ON, Red OFF, beep CAUTION
- **Source block**: if-else led/buzzer logic

### TC-UPDATEALERTS-007: Verify Alerts for distance=100.0
- **Requirement ID**: REQ-ALERT-100
- **Category**: Functional
- **Inputs**: distance=100.0
- **Expected Result**: Green OFF, Yellow ON, Red OFF, beep CAUTION
- **Source block**: if-else led/buzzer logic

### TC-UPDATEALERTS-008: Verify Alerts for distance=101.0
- **Requirement ID**: REQ-ALERT-101
- **Category**: Functional
- **Inputs**: distance=101.0
- **Expected Result**: Green ON, Yellow OFF, Red OFF, noTone
- **Source block**: if-else led/buzzer logic

### TC-UPDATEALERTS-009: Verify Alerts for distance=400.0
- **Requirement ID**: REQ-ALERT-400
- **Category**: Functional
- **Inputs**: distance=400.0
- **Expected Result**: Green ON, Yellow OFF, Red OFF, noTone
- **Source block**: if-else led/buzzer logic

