# Test Cases for 08_readDistance

Total Unique Test Cases: 7

### TC-READDISTANCE-001: Verify distance calculation for pulse duration=0us
- **Requirement ID**: REQ-READ-0
- **Category**: Boundary
- **Inputs**: duration=0
- **Expected Result**: Returns -1 (Timeout)
- **Source block**: N/A

### TC-READDISTANCE-002: Verify distance calculation for pulse duration=1us
- **Requirement ID**: REQ-READ-1
- **Category**: Boundary
- **Inputs**: duration=1
- **Expected Result**: Returns 0.02 cm
- **Source block**: N/A

### TC-READDISTANCE-003: Verify distance calculation for pulse duration=583us
- **Requirement ID**: REQ-READ-583
- **Category**: Functional
- **Inputs**: duration=583
- **Expected Result**: Returns 10.00 cm
- **Source block**: N/A

### TC-READDISTANCE-004: Verify distance calculation for pulse duration=1166us
- **Requirement ID**: REQ-READ-1166
- **Category**: Functional
- **Inputs**: duration=1166
- **Expected Result**: Returns 20.00 cm
- **Source block**: N/A

### TC-READDISTANCE-005: Verify distance calculation for pulse duration=23323us
- **Requirement ID**: REQ-READ-23323
- **Category**: Boundary
- **Inputs**: duration=23323
- **Expected Result**: Returns 399.99 cm
- **Source block**: N/A

### TC-READDISTANCE-006: Verify distance calculation for pulse duration=23324us
- **Requirement ID**: REQ-READ-23324
- **Category**: Boundary
- **Inputs**: duration=23324
- **Expected Result**: Returns -1 (Out of Range)
- **Source block**: N/A

### TC-READDISTANCE-007: Verify distance calculation for pulse duration=50000us
- **Requirement ID**: REQ-READ-50000
- **Category**: Functional
- **Inputs**: duration=50000
- **Expected Result**: Returns -1 (Out of Range)
- **Source block**: N/A

