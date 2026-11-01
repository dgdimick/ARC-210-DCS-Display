// ARC-210 dual seven-position resistor-ladder test V1.1 for Teensy 4.1.
// Each J1: 1 -> 3.3V, 2 -> GPIO 14/A0 (Master) or 15/A1 (Secondary), 3 -> GND.
// Fit R1-R6 (six 1k resistors); leave JP1 OPEN.
// Select Teensy 4.1 and USB Type: Serial in the Arduino IDE.

#include <Arduino.h>
#include <ILI9488_t3.h>

constexpr uint8_t TFT_CS = 10, TFT_DC = 9, TFT_RST = 8;
constexpr uint8_t TFT_MOSI = 11, TFT_SCK = 13, TFT_MISO = 12;
constexpr uint8_t TFT_BL = 4; // Confirmed physical GPIO, not KiCad terminal 6.
ILI9488_t3 tft(TFT_CS, TFT_DC, TFT_RST, TFT_MOSI, TFT_SCK, TFT_MISO);
uint32_t lastDisplay = 0;
bool buffered = false;
constexpr uint8_t SQL_PIN = 41;
bool sqlCandidate = false;
bool sqlOn = false;
uint32_t sqlChangedAt = 0;
uint32_t sqlLastReport = 0;

constexpr uint8_t SWITCH_PINS[2] = {14, 15};
const char* const SWITCH_NAMES[2] = {"MASTER", "SECONDARY"};
constexpr int ADC_MAX = 4095;
constexpr float SUPPLY_VOLTS = 3.3f; // Approximate; adjust to measured 3.3V rail.
constexpr int MAX_ERROR = 200;
constexpr uint32_t SETTLE_MS = 75;
constexpr uint32_t SAMPLE_MS = 5;
constexpr uint32_t REPORT_MS = 1000;

// Position 1 is terminal 1 (+3.3V); position 7 is terminal 10 (GND).
constexpr int EXPECTED[7] = {4095, 3413, 2730, 2048, 1365, 683, 0};
constexpr uint8_t TERMINAL[7] = {1, 2, 4, 5, 7, 8, 10};

struct SwitchState {
  int raw = 0;
  int candidate = -1;
  int stablePosition = -1;
  uint32_t candidateSince = 0;
  uint32_t lastReport = 0;
};
SwitchState switches[2];
uint32_t lastSample = 0;

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

void printReading(uint8_t index) {
  const SwitchState& state = switches[index];
  Serial.print(SWITCH_NAMES[index]);
  Serial.print(" GPIO "); Serial.print(SWITCH_PINS[index]);
  Serial.print(" | Position: ");
  if (state.stablePosition > 0) {
    Serial.print(state.stablePosition);
    Serial.print(" / 7 | terminal: ");
    Serial.print(TERMINAL[state.stablePosition - 1]);
  } else {
    Serial.print("UNSET / BETWEEN TAPS");
  }
  Serial.print(" | ADC: "); Serial.print(state.raw);
  Serial.print(" | approx voltage: ");
  Serial.print(state.raw * SUPPLY_VOLTS / ADC_MAX, 3);
  Serial.print(" V");
  if (state.candidate != state.stablePosition) Serial.print(" | settling");
  Serial.println();
}

void updateDisplay() {
  tft.fillRect(12, 282, 456, 24, ILI9488_BLACK);
  tft.setTextSize(2);
  tft.setTextColor(sqlOn ? ILI9488_GREEN : ILI9488_WHITE, ILI9488_BLACK);
  tft.setCursor(12, 282);
  tft.print("SQL: "); tft.print(sqlOn ? "ON" : "OFF");
  tft.print("  GPIO 41");
  for (uint8_t i = 0; i < 2; ++i) {
    const SwitchState& state = switches[i];
    const int x = 12 + i * 240;
    tft.fillRect(x, 100, 220, 166, ILI9488_BLACK);
    tft.setTextSize(3);
    tft.setTextColor(state.stablePosition > 0 ? ILI9488_GREEN : ILI9488_YELLOW, ILI9488_BLACK);
    tft.setCursor(x, 102);
    if (state.stablePosition > 0) {
      tft.print("POS "); tft.print(state.stablePosition); tft.print(" / 7");
    } else {
      tft.setTextSize(2); tft.print("BETWEEN TAPS");
    }
    tft.setTextSize(2);
    tft.setTextColor(ILI9488_WHITE, ILI9488_BLACK);
    tft.setCursor(x, 150); tft.print("ADC: "); tft.print(state.raw);
    tft.setCursor(x, 180); tft.print("Volts: ");
    tft.print(state.raw * SUPPLY_VOLTS / ADC_MAX, 3); tft.print(" V");
    tft.setCursor(x, 210);
    if (state.stablePosition > 0) {
      tft.print("Terminal: "); tft.print(TERMINAL[state.stablePosition - 1]);
    }
    tft.setCursor(x, 240);
    if (state.candidate != state.stablePosition) tft.print("Settling...");
    else if (state.stablePosition <= 0) tft.print("Check wiring");
  }
}

void setup() {
  pinMode(TFT_BL, OUTPUT);
  digitalWrite(TFT_BL, HIGH);
  tft.begin();
  tft.setRotation(1);
  buffered = tft.useFrameBuffer(true) != 0;
  tft.fillScreen(ILI9488_BLACK);
  tft.setTextColor(ILI9488_CYAN, ILI9488_BLACK);
  tft.setTextSize(2);
  tft.setCursor(12, 15); tft.print("ARC-210 SWITCH TEST V1.1");
  tft.drawFastVLine(239, 65, 200, ILI9488_CYAN);
  for (uint8_t i = 0; i < 2; ++i) {
    const int x = 12 + i * 240;
    tft.setCursor(x, 58); tft.print(SWITCH_NAMES[i]);
    tft.setCursor(x, 80); tft.print("GPIO "); tft.print(SWITCH_PINS[i]);
    pinMode(SWITCH_PINS[i], INPUT); // No pull-ups on resistor ladders.
  }
  pinMode(SQL_PIN, INPUT_PULLUP);
  sqlCandidate = sqlOn = digitalRead(SQL_PIN) == LOW;
  updateDisplay();
  analogReadResolution(12);
  analogReadAveraging(16);
  Serial.begin(115200);
  Serial.println("ARC-210 dual rotary switch test V1.1");
  Serial.println("MASTER: GPIO14/A0; SECONDARY: GPIO15/A1. 3.3V ladders only.");
  Serial.println("An unplugged/floating input cannot be reliably detected by this test.");
  if (buffered) tft.updateScreen();
}

void loop() {
  const uint32_t now = millis();
  if (now - lastSample < SAMPLE_MS) return;
  lastSample = now;
  bool anyChanged = false;
  const bool sqlReading = digitalRead(SQL_PIN) == LOW;
  if (sqlReading != sqlCandidate) {
    sqlCandidate = sqlReading;
    sqlChangedAt = now;
  }
  if (sqlOn != sqlCandidate && now - sqlChangedAt >= 30) {
    sqlOn = sqlCandidate;
    anyChanged = true;
  }
  if (Serial && (anyChanged || now - sqlLastReport >= REPORT_MS)) {
    Serial.print("SQL GPIO41: "); Serial.println(sqlOn ? "ON" : "OFF");
    sqlLastReport = now;
  }
  for (uint8_t i = 0; i < 2; ++i) {
    SwitchState& state = switches[i];
    state.raw = analogRead(SWITCH_PINS[i]);
    const int decoded = decodePosition(state.raw);
    if (decoded != state.candidate) {
      state.candidate = decoded;
      state.candidateSince = now;
    }
    bool changed = false;
    if (state.candidate != state.stablePosition && now - state.candidateSince >= SETTLE_MS) {
      state.stablePosition = state.candidate;
      changed = true;
    }
    anyChanged |= changed;
    if (Serial && (changed || now - state.lastReport >= REPORT_MS)) {
      printReading(i);
      state.lastReport = now;
    }
  }
  if (anyChanged || now - lastDisplay >= 150) {
    updateDisplay();
    if (buffered) tft.updateScreen();
    lastDisplay = now;
  }
}
