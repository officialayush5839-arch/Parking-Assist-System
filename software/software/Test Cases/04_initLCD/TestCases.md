# Test Cases for 04_initLCD

Total Unique Test Cases: 2

### TC-INITLCD-001: Verify LCD initialization layout
- **Requirement ID**: REQ-LCD-01
- **Category**: Functional
- **Inputs**: N/A
- **Expected Result**: lcd.begin(16,2) is executed, setting up 16 columns and 2 rows.
- **Source block**: lcd.begin(16,2);

### TC-INITLCD-002: Verify LCD buffer clearing
- **Requirement ID**: REQ-LCD-02
- **Category**: Functional
- **Inputs**: N/A
- **Expected Result**: lcd.clear() is executed, screen is blank.
- **Source block**: lcd.clear();

