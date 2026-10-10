// ARC-210 seven-position resistor-ladder test for Teensy 4.1.
// J1: 1 -> 3.3V, 2 -> physical Teensy pin 14 (A0), 3 -> GND.
// Fit R1-R6 (six 1k resistors); leave JP1 OPEN.
// Select Teensy 4.1 and USB Type: Serial in the Arduino IDE.

#include <Arduino.h>
#include <ILI9488_t3.h>

constexpr uint8_t TFT_CS = 10, TFT_DC = 9, TFT_RST = 8;
constexpr uint8_t TFT_MOSI = 11, TFT_SCK = 13, TFT_MISO = 12;
constexpr uint8_t TFT_BL = 4; // Confirmed physical GPIO, not KiCad terminal 6.
ILI9488_t3 tft(TFT_CS, TFT_DC, TFT_RST, TFT_MOSI, TFT_SCK, TFT_MISO);
uint32_t lastDisplay = 0;
int displayedPosition = -99;

constexpr uint8_t SWITCH_PIN = 14;
constexpr int ADC_MAX = 4095;
constexpr float SUPPLY_VOLTS = 3.3f; // Approximate; adjust to measured 3.3V rail.
constexpr int MAX_ERROR = 200;
constexpr uint32_t SETTLE_MS = 75;
constexpr uint32_t SAMPLE_MS = 5;
constexpr uint32_t REPORT_MS = 1000;

// Position 1 is terminal 1 (+3.3V); position 7 is terminal 10 (GND).
constexpr int EXPECTED[7] = {4095, 3413, 2730, 2048, 1365, 683, 0};
constexpr uint8_t TERMINAL[7] = {1, 2, 4, 5, 7, 8, 10};

int candidate = -1;
int stablePosition = -1;
uint32_t candidateSince = 0;
uint32_t lastSample = 0;
uint32_t lastReport = 0;

// Return 1-7 for a reading close to a ladder tap, or 0 between taps.
int decodePosition(int raw) {
  int best = 0;
  int smallestError = ADC_MAX + 1;
  for (int i = 0; i < 7; ++i) {
    const int error = abs(raw - EXPECTED[i]);
    if (error < smallestError) {
      smallestError = error;
      best = i + 1;
    }
  }
  return smallestError <= MAX_ERROR ? best : 0;
}

void printReading(int raw) {
  Serial.print("Position: ");
  if (stablePosition > 0) {
    Serial.print(stablePosition);
    Serial.print(" / 7 | switch terminal: ");
    Serial.print(TERMINAL[stablePosition - 1]);
  } else {
    Serial.print("UNSET / BETWEEN TAPS");
  }
  Serial.print(" | ADC: ");
  Serial.print(raw);
  Serial.print(" | approx voltage: ");
  Serial.print(raw * SUPPLY_VOLTS / ADC_MAX, 3);
  Serial.print(" V");
  if (candidate != stablePosition) Serial.print(" | settling");
  Serial.println();
}

void updateDisplay(int raw) {
  if (displayedPosition != stablePosition) {
    tft.fillRect(15, 68, 450, 85, ILI9488_BLACK);
    tft.setTextSize(5);
    tft.setTextColor(stablePosition > 0 ? ILI9488_GREEN : ILI9488_YELLOW, ILI9488_BLACK);
    tft.setCursor(20, 82);
    if (stablePosition > 0) {
      tft.print("POS "); tft.print(stablePosition); tft.print(" / 7");
    } else {
      tft.setTextSize(3); tft.print("BETWEEN TAPS");
    }
    displayedPosition = stablePosition;
  }
  tft.fillRect(15, 160, 450, 90, ILI9488_BLACK);
  tft.setTextSize(3);
  tft.setTextColor(ILI9488_WHITE, ILI9488_BLACK);
  tft.setCursor(20, 166); tft.print("ADC: "); tft.print(raw);
  tft.setCursor(20, 202); tft.print("Volts: ");
  tft.print(raw * SUPPLY_VOLTS / ADC_MAX, 3); tft.print(" V");
  tft.fillRect(15, 254, 450, 25, ILI9488_BLACK);
  tft.setTextSize(2); tft.setCursor(20, 258);
  if (candidate != stablePosition) tft.print("Settling...");
  else if (stablePosition > 0) {
    tft.print("Switch terminal: "); tft.print(TERMINAL[stablePosition - 1]);
  } else tft.print("Check wiring / resistor values");
}

void setup() {
  pinMode(TFT_BL, OUTPUT);
  digitalWrite(TFT_BL, HIGH);
  tft.begin();
  tft.setRotation(1);
  tft.fillScreen(ILI9488_BLACK);
  tft.setTextColor(ILI9488_CYAN, ILI9488_BLACK);
  tft.setTextSize(2);
  tft.setCursor(20, 15); tft.print("ARC-210 ROTARY SWITCH TEST");
  tft.setCursor(20, 42); tft.print("Teensy 4.1 - GPIO 14 / A0");
  tft.setCursor(20, 292); tft.print("Six resistors fitted. JP1 OPEN.");
  pinMode(SWITCH_PIN, INPUT); // No pull-up on a resistor ladder.
  analogReadResolution(12);
  analogReadAveraging(16);
  Serial.begin(115200);
  Serial.println("ARC-210 seven-position rotary switch test");
  Serial.println("Input: physical GPIO 14 / A0. Six resistors fitted; JP1 OPEN.");
  Serial.println("Rotate through positions 1-7. Readings print on change and every second.");
  Serial.println("Nominal voltages: 3.300, 2.750, 2.200, 1.650, 1.100, 0.550, 0.000 V.");
  Serial.println("An unplugged/floating input cannot be reliably detected by this test.");
}

void loop() {
  const uint32_t now = millis();
  if (now - lastSample < SAMPLE_MS) return;
  lastSample = now;
  const int raw = analogRead(SWITCH_PIN);
  const int decoded = decodePosition(raw);
  if (decoded != candidate) {
    candidate = decoded;
    candidateSince = now;
  }
  bool changed = false;
  if (candidate != stablePosition && now - candidateSince >= SETTLE_MS) {
    stablePosition = candidate;
    changed = true;
  }
  if (changed || now - lastDisplay >= 150) {
    updateDisplay(raw);
    lastDisplay = now;
  }
  if (Serial && (changed || now - lastReport >= REPORT_MS)) {
    printReading(raw);
    lastReport = now;
  }
}
