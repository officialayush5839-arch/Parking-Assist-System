# Test Cases for 07_loop

Total Unique Test Cases: 4

### TC-LOOP-001: Verify loop control flow for distance=-1
- **Requirement ID**: REQ-LOOP-D-1
- **Category**: Decision
- **Inputs**: distance=-1
- **Expected Result**: Calls showSensorError() and returns early
- **Source block**: N/A

### TC-LOOP-002: Verify loop control flow for distance=0
- **Requirement ID**: REQ-LOOP-D0
- **Category**: Decision
- **Inputs**: distance=0
- **Expected Result**: Calls updateLCD, updateAlerts, and delays 50ms
- **Source block**: N/A

### TC-LOOP-003: Verify loop control flow for distance=50
- **Requirement ID**: REQ-LOOP-D50
- **Category**: Decision
- **Inputs**: distance=50
- **Expected Result**: Calls updateLCD, updateAlerts, and delays 50ms
- **Source block**: N/A

### TC-LOOP-004: Verify loop control flow for distance=400
- **Requirement ID**: REQ-LOOP-D400
- **Category**: Decision
- **Inputs**: distance=400
- **Expected Result**: Calls updateLCD, updateAlerts, and delays 50ms
- **Source block**: N/A

