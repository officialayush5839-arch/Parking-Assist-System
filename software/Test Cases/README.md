# Parking Assist System QA Architecture

Welcome to the comprehensive module-wise testing repository for the Parking Assist System. This repository resembles QA documentation produced by industry leaders like Bosch, Siemens, or Rockwell Automation for embedded systems projects. Documentation is clean, traceable, reproducible, and maintainable.

## Folder Hierarchy & Naming
The test architecture is broken down strictly by function and scope. 
- **`01_Project_Header`**: Core test plans and overarching definitions.
- **`02_Global_Constants`**: Validation of system-wide definitions.
- **`03_initHardware` to `12_showSensorError`**: Unit tests per function.
- **`13_Integration_Testing`**: System integration interactions.
- **`14_System_Testing`**: End-to-end user-level validation.

Inside each module folder, you will find:
1. `TestCases.xlsx` - A master spreadsheet with all derived test cases.
2. `TestCases.md` - Markdown readable version of the test suite.
3. `Coverage.md` - Coverage analysis against the source.
4. `Requirements.md` - Traced requirements for the module.
5. `TestReport.md` - Stub for post-execution results.
6. `Summary.md` - Overview of the module's QA status.

## Coverage Philosophy
Test cases are purely code-derived. We do not artificially inflate test counts. If an analysis of control flow, decision points, thresholds, and state transitions yields precisely 42 scenarios, only 42 scenarios are generated. 

## Test Methodology
The suite includes the following test types: Functional, Boundary, Branch, Decision, Condition, State Transition, Hardware Verification, Sensor Failure, Timeout, Error Handling. Tests are deterministically generated based on hardware interaction logic (e.g., specific GPIO states and threshold boundaries).

## Traceability Approach
Every generated test case references:
- **Function Name**: The exact C++ function being tested.
- **Requirement ID**: Derived system requirement.
- **Source Code Block**: The specific logic line (e.g. `if (distance > SAFE_LIMIT)`).
- **Threshold & Constant**: Defined bounds from `config.yaml`.
- **Decision Branch**: True/False branch validation.

There are no orphan test cases.

## Execution & Reporting
- **How to Execute**: Follow the 'Procedure' steps detailed in `TestCases.xlsx` manually or via an automated Hardware-in-the-loop (HIL) rig.
- **How to Record Actual Results**: Fill out the 'Actual Result' and 'Status' (PASS/FAIL/BLOCKED) columns in the provided Excel files. Do not fabricate results; leave them blank until physical execution.
