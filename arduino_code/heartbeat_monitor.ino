#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// Pins
const int POT_PIN = A0;
const int GREEN_LED = 6;
const int RED_LED = 7;
const int BUZZER = 8;

// Thresholds
const int LOW_BPM = 60;
const int HIGH_BPM = 100;

// Heartbeat detection
bool beatDetected = false;

unsigned long lastBeatTime = 0;
unsigned long currentBeatTime = 0;

int bpm = 0;
int smoothedBPM = 0;

// Moving average
const int NUM_READINGS = 3;

int bpmReadings[NUM_READINGS];
int readingIndex = 0;
int readingCount = 0;

// Previous target BPM
int previousTargetBPM = 0;


// =================================================
// SETUP
// =================================================

void setup() {

  Serial.begin(9600);

  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(BUZZER, OUTPUT);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("OLED not found!");
    while (true);
  }

  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);

  display.setTextSize(2);
  display.setCursor(15, 10);
  display.println("HEART");

  display.setCursor(15, 35);
  display.println("MONITOR");

  display.display();

  delay(2000);

  for (int i = 0; i < NUM_READINGS; i++) {
    bpmReadings[i] = 0;
  }
}


// =================================================
// ADD BPM READING
// =================================================

void addBPMReading(int newBPM) {

  bpmReadings[readingIndex] = newBPM;

  readingIndex++;

  if (readingIndex >= NUM_READINGS) {
    readingIndex = 0;
  }

  if (readingCount < NUM_READINGS) {
    readingCount++;
  }

  long total = 0;

  for (int i = 0; i < readingCount; i++) {
    total += bpmReadings[i];
  }

  smoothedBPM = total / readingCount;
}


// =================================================
// RESET SMOOTHING
// =================================================

void resetSmoothing() {

  readingIndex = 0;
  readingCount = 0;
  smoothedBPM = 0;

  for (int i = 0; i < NUM_READINGS; i++) {
    bpmReadings[i] = 0;
  }
}


// =================================================
// MAIN LOOP
// =================================================

void loop() {

  int potValue = analogRead(POT_PIN);

  // Potentiometer controls simulated BPM
  int targetBPM = map(
    potValue,
    0,
    1023,
    40,
    140
  );


  // If BPM changes significantly,
  // clear old readings.
  if (abs(targetBPM - previousTargetBPM) > 10) {

    resetSmoothing();

    lastBeatTime = 0;
  }

  previousTargetBPM = targetBPM;


  // Calculate beat interval
  unsigned long beatInterval =
      60000UL / targetBPM;


  // Create simulated heartbeat
  unsigned long timeInCycle =
      millis() % beatInterval;

  int pulseSignal;

  if (timeInCycle < 80) {

    pulseSignal = 1023;

  } else {

    pulseSignal = 100;
  }


  // =================================================
  // HEARTBEAT DETECTION
  // =================================================

  if (pulseSignal > 700 && !beatDetected) {

    beatDetected = true;

    currentBeatTime = millis();

    if (lastBeatTime > 0) {

      unsigned long interval =
          currentBeatTime - lastBeatTime;

      bpm = 60000UL / interval;

      addBPMReading(bpm);

      Serial.print("Beat detected | ");
      Serial.print("Interval: ");
      Serial.print(interval);
      Serial.print(" ms | BPM: ");
      Serial.print(bpm);
      Serial.print(" | Smoothed BPM: ");
      Serial.println(smoothedBPM);
    }

    lastBeatTime = currentBeatTime;
  }


  // Reset beat detection
  if (pulseSignal < 700) {

    beatDetected = false;
  }


  // =================================================
  // STATUS
  // =================================================

  String status;

  if (smoothedBPM > 0 &&
      smoothedBPM < LOW_BPM) {

    status = "LOW";

    digitalWrite(GREEN_LED, LOW);
    digitalWrite(RED_LED, HIGH);
    digitalWrite(BUZZER, HIGH);
  }

  else if (smoothedBPM > HIGH_BPM) {

    status = "HIGH";

    digitalWrite(GREEN_LED, LOW);
    digitalWrite(RED_LED, HIGH);
    digitalWrite(BUZZER, HIGH);
  }

  else if (smoothedBPM > 0) {

    status = "NORMAL";

    digitalWrite(GREEN_LED, HIGH);
    digitalWrite(RED_LED, LOW);
    digitalWrite(BUZZER, LOW);
  }

  else {

    status = "WAIT";

    digitalWrite(GREEN_LED, LOW);
    digitalWrite(RED_LED, LOW);
    digitalWrite(BUZZER, LOW);
  }


  // =================================================
  // OLED
  // =================================================

  display.clearDisplay();

  display.setTextSize(1);
  display.setCursor(0, 0);
  display.println("HEARTBEAT MONITOR");

  display.setTextSize(2);
  display.setCursor(0, 18);

  if (smoothedBPM > 0) {

    display.print("BPM:");
    display.print(smoothedBPM);

  } else {

    display.print("BPM:--");
  }

  display.setTextSize(1);
  display.setCursor(0, 48);

  display.print("STATUS: ");
  display.println(status);

  display.display();

  delay(10);
}
