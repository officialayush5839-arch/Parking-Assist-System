/*******************************************************
==========================================================
Project Name: Parking Assist System
Author: Vipul
Platform: Arduino Uno

Description:
This project uses an HC-SR04 ultrasonic sensor to measure
distance and provide visual and auditory feedback for parking
assistance. It features a 16x2 LCD display, three LEDs
(Green, Yellow, Red) for status indication, and a piezo buzzer
for auditory warnings.

Components:
- Arduino Uno
- HC-SR04 Ultrasonic Sensor
- 16x2 LCD
- Potentiometer
- Green LED
- Yellow LED
- Red LED
- Piezo Buzzer
==========================================================
*******************************************************/

#include <LiquidCrystal.h>

// ---------------- LCD ----------------
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// ---------------- Ultrasonic ----------------
const byte TRIG = 7;
const byte ECHO = 6;

// ---------------- LEDs ----------------
const byte GREEN_LED  = 9;
const byte YELLOW_LED = 8;
const byte RED_LED    = 10;

// ---------------- Buzzer ----------------
const byte BUZZER = 13;

// ---------------- Thresholds ----------------
const int SAFE_LIMIT = 100;
const int CAUTION_LIMIT = 50;
const int WARNING_LIMIT = 20;

// ---------------- Alert Configurations ----------------
const int BEEP_CAUTION_INTERVAL = 700;
const int BEEP_CAUTION_FREQ = 1000;
const int BEEP_WARNING_INTERVAL = 250;
const int BEEP_WARNING_FREQ = 1500;
const int BEEP_STOP_FREQ = 2000;

// ---------------- Sensor Configuration ----------------
const unsigned long SENSOR_TIMEOUT = 30000;
const float SPEED_OF_SOUND_CM_PER_US = 0.0343;
const float MAX_DISTANCE_CM = 400.0;

// ---------------- Variables ----------------
unsigned long previousBeep = 0;
bool beepState = false;
int lastDisplayedDistance = -1;
int lastDisplayedState = -1;

/*******************************************************
Function:
initHardware()

Purpose:
Configures pin modes for the sensor, LEDs, and buzzer.
*******************************************************/
void initHardware()
{
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);

  pinMode(GREEN_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);

  pinMode(BUZZER, OUTPUT);
}

/*******************************************************
Function:
initLCD()

Purpose:
Initializes the LCD and clears the screen.
*******************************************************/
void initLCD()
{
  lcd.begin(16,2);
  lcd.clear();
}

/*******************************************************
Function:
displayStartupMessage()

Purpose:
Shows an introductory message for 2 seconds.
*******************************************************/
void displayStartupMessage()
{
  lcd.setCursor(0,0);
  lcd.print("PARKING ASSIST");
  lcd.setCursor(0,1);
  lcd.print("Initializing");
  delay(2000);
  lcd.clear();
}

/*******************************************************
Function:
setup()

Purpose:
Initializes hardware pins, starts the LCD, and 
displays an introductory message.

Input:
None

Returns:
None

Dependencies:
LiquidCrystal library
*******************************************************/
void setup()
{
  initHardware();
  initLCD();
  displayStartupMessage();
}

/*******************************************************
Function:
loop()

Purpose:
Main execution loop. Measures distance, handles sensor
errors, and updates outputs based on distance.

Input:
None

Returns:
None

Dependencies:
readDistance(), showSensorError(), updateLCD(), updateAlerts()
*******************************************************/
void loop()
{
  float distance = readDistance();

  if (distance < 0)
  {
    showSensorError();
    return;
  }

  updateLCD(distance);
  updateAlerts(distance);

  delay(50);
}

/*******************************************************
Function:
readDistance()

Purpose:
Reads the HC-SR04 sensor and returns distance.

Input:
None

Returns:
Distance in centimeters.
Returns -1 on timeout.

Dependencies:
pulseIn()
*******************************************************/
float readDistance()
{
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);

  digitalWrite(TRIG, LOW);

  long duration = pulseIn(ECHO, HIGH, SENSOR_TIMEOUT);

  if (duration == 0)
      return -1;

  float distance = duration * SPEED_OF_SOUND_CM_PER_US / 2.0;

  if (distance > MAX_DISTANCE_CM)
      return -1;

  return distance;
}

/*******************************************************
Function:
updateLCD()

Purpose:
Updates the 16x2 LCD display with current distance and
status text.

Input:
distance (float): Measured distance in centimeters.

Returns:
None

Dependencies:
LiquidCrystal library
*******************************************************/
void updateLCD(float distance)
{
  int currentDistance = (int)distance;
  int currentState;

  if (distance > SAFE_LIMIT) currentState = 0;
  else if (distance > CAUTION_LIMIT) currentState = 1;
  else if (distance >= WARNING_LIMIT) currentState = 2;
  else currentState = 3;

  if (currentDistance != lastDisplayedDistance || lastDisplayedState == 4) {
    lcd.setCursor(0,0);
    lcd.print("Dist:");
    lcd.print(currentDistance);
    lcd.print(" cm   ");
    lastDisplayedDistance = currentDistance;
  }

  if (currentState != lastDisplayedState) {
    lcd.setCursor(0,1);
    if (currentState == 0) lcd.print("SAFE            ");
    else if (currentState == 1) lcd.print("CAUTION         ");
    else if (currentState == 2) lcd.print("WARNING         ");
    else lcd.print("STOP!           ");
    lastDisplayedState = currentState;
  }
}

/*******************************************************
Function:
updateAlerts()

Purpose:
Controls LEDs and Buzzer based on distance thresholds.

Input:
distance (float): Measured distance in centimeters.

Returns:
None

Dependencies:
beep()
*******************************************************/
void updateAlerts(float distance)
{
  unsigned long currentTime = millis();

  bool greenOn = false;
  bool yellowOn = false;
  bool redOn = false;

  if (distance > SAFE_LIMIT) {
      greenOn = true;
      noTone(BUZZER);
  } else if (distance > CAUTION_LIMIT) {
      yellowOn = true;
      beep(currentTime, BEEP_CAUTION_INTERVAL, BEEP_CAUTION_FREQ);
  } else if (distance >= WARNING_LIMIT) {
      redOn = true;
      beep(currentTime, BEEP_WARNING_INTERVAL, BEEP_WARNING_FREQ);
  } else {
      redOn = true;
      tone(BUZZER, BEEP_STOP_FREQ);
  }

  digitalWrite(GREEN_LED, greenOn ? HIGH : LOW);
  digitalWrite(YELLOW_LED, yellowOn ? HIGH : LOW);
  digitalWrite(RED_LED, redOn ? HIGH : LOW);
}

/*******************************************************
Function:
beep()

Purpose:
Generates a non-blocking tone on the buzzer with a 
specified interval and frequency.

Input:
now (unsigned long): Current time in milliseconds.
interval (int): Time between toggles in milliseconds.
frequency (int): Tone frequency in Hertz.

Returns:
None

Dependencies:
tone(), noTone()
*******************************************************/
void beep(unsigned long now, int interval, int frequency)
{
  if (now - previousBeep >= (unsigned long)interval)
  {
      previousBeep = now;
      beepState = !beepState;

      if (beepState) {
          tone(BUZZER, frequency);
      } else {
          noTone(BUZZER);
      }
  }
}

/*******************************************************
Function:
showSensorError()

Purpose:
Displays an error message on the LCD and turns off all
LEDs and the buzzer.

Input:
None

Returns:
None

Dependencies:
LiquidCrystal library, noTone()
*******************************************************/
void showSensorError()
{
  if (lastDisplayedState != 4) {
      lcd.setCursor(0, 0);
      lcd.print("Sensor Error   ");
      lcd.setCursor(0, 1);
      lcd.print("Check Wiring   ");
      lastDisplayedState = 4;
      lastDisplayedDistance = -1;
  }

  digitalWrite(GREEN_LED, LOW);
  digitalWrite(YELLOW_LED, LOW);
  digitalWrite(RED_LED, LOW);

  noTone(BUZZER);
}
