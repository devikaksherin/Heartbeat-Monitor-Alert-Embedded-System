#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

const int POT_PIN = A0;
const int GREEN_LED = 6;
const int RED_LED = 7;
const int BUZZER = 8;

const int LOW_BPM = 60;
const int HIGH_BPM = 100;

void setup() {

  Serial.begin(9600);

  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(BUZZER, OUTPUT);

  // Start OLED
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
}

void loop() {

  int sensorValue = analogRead(POT_PIN);

  // Convert potentiometer value into simulated BPM
  int bpm = map(sensorValue, 0, 1023, 40, 140);

  String status;

  // LOW condition
  if (bpm < LOW_BPM) {

    status = "LOW";

    digitalWrite(GREEN_LED, LOW);
    digitalWrite(RED_LED, HIGH);
    digitalWrite(BUZZER, HIGH);
  }

  // HIGH condition
  else if (bpm > HIGH_BPM) {

    status = "HIGH";

    digitalWrite(GREEN_LED, LOW);
    digitalWrite(RED_LED, HIGH);
    digitalWrite(BUZZER, HIGH);
  }

  // NORMAL condition
  else {

    status = "NORMAL";

    digitalWrite(GREEN_LED, HIGH);
    digitalWrite(RED_LED, LOW);
    digitalWrite(BUZZER, LOW);
  }

  // Serial Monitor
  Serial.print("BPM: ");
  Serial.print(bpm);
  Serial.print(" | STATUS: ");
  Serial.println(status);

  // OLED
  display.clearDisplay();

  display.setTextSize(1);
  display.setCursor(0, 0);
  display.println("HEARTBEAT MONITOR");

  display.setTextSize(2);
  display.setCursor(0, 18);
  display.print("BPM:");
  display.print(bpm);

  display.setTextSize(1);
  display.setCursor(0, 48);
  display.print("STATUS: ");
  display.println(status);

  display.display();

  delay(500);
}
