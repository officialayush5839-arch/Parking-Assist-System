/*
==========================================================
PARKING ASSIST SYSTEM
CS220 Capstone Project

Components
- Arduino Uno
- HC-SR04 Ultrasonic Sensor
- 16x2 LCD
- Potentiometer
- Green LED
- Yellow LED
- Red LED
- Piezo Buzzer

Author: Vipul
==========================================================
*/

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

// ---------------- Variables ----------------
unsigned long previousBeep = 0;
bool beepState = false;

void setup()
{
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);

  pinMode(GREEN_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);

  pinMode(BUZZER, OUTPUT);

  lcd.begin(16,2);

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("PARKING ASSIST");
  lcd.setCursor(0,1);
  lcd.print("Initializing");
  delay(2000);

  lcd.clear();
}

void loop()
{
  float distance = readDistance();

  if(distance < 0)
  {
    showSensorError();
    return;
  }

  updateLCD(distance);
  updateAlerts(distance);

  delay(50);
}

//====================================================
// Distance Function
//====================================================
float readDistance()
{
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);

  digitalWrite(TRIG, LOW);

  long duration = pulseIn(ECHO, HIGH, 30000);

  if(duration == 0)
      return -1;

  return duration * 0.0343 / 2.0;
}

//====================================================
// LCD
//====================================================
void updateLCD(float distance)
{
  lcd.setCursor(0,0);
  lcd.print("Dist:");
  lcd.print((int)distance);
  lcd.print(" cm   ");

  lcd.setCursor(0,1);

  if(distance > SAFE_LIMIT)
      lcd.print("SAFE            ");

  else if(distance > CAUTION_LIMIT)
      lcd.print("CAUTION         ");

  else if(distance >= WARNING_LIMIT)
      lcd.print("WARNING         ");

  else
      lcd.print("STOP!           ");
}

//====================================================
// LED + Buzzer
//====================================================
void updateAlerts(float distance)
{
  unsigned long currentTime = millis();

  digitalWrite(GREEN_LED, LOW);
  digitalWrite(YELLOW_LED, LOW);
  digitalWrite(RED_LED, LOW);

  if(distance > SAFE_LIMIT)
  {
      digitalWrite(GREEN_LED, HIGH);
      noTone(BUZZER);
  }

  else if(distance > CAUTION_LIMIT)
  {
      digitalWrite(YELLOW_LED, HIGH);
      beep(currentTime,700,1000);
  }

  else if(distance >= WARNING_LIMIT)
  {
      digitalWrite(RED_LED, HIGH);
      beep(currentTime,250,1500);
  }

  else
  {
      digitalWrite(RED_LED, HIGH);
      tone(BUZZER,2000);
  }
}

//====================================================
// Beeper
//====================================================
void beep(unsigned long now,int interval,int frequency)
{
  if(now-previousBeep>=interval)
  {
      previousBeep=now;

      beepState=!beepState;

      if(beepState)
          tone(BUZZER,frequency);
      else
          noTone(BUZZER);
  }
}

//====================================================
// Sensor Error
//====================================================
void showSensorError()
{
  lcd.setCursor(0,0);
  lcd.print("Sensor Error   ");
  lcd.setCursor(0,1);
  lcd.print("Check Wiring   ");

  digitalWrite(GREEN_LED,LOW);
  digitalWrite(YELLOW_LED,LOW);
  digitalWrite(RED_LED,LOW);

  noTone(BUZZER);
}
