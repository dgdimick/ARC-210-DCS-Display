/*
  Slave_UART_Node.ino
  ESP32-S3 SLAVE -> Sends input events to MASTER over UART1 (GPIO13/14).

  Protocol (ASCII lines ending with '\n'):
    ENC<n>:+1    // encoder n increment
    ENC<n>:-1    // encoder n decrement
    RS<n>:<p>    // rotary switch n at position p (1..8)
    HB           // heartbeat every ~2s

  Wire to MASTER:
    Slave TX (GPIO13) -> Master RX (GPIO14)
    Slave RX (GPIO14) <- Master TX (GPIO13)
    GND <-> GND

  Board: ESP32S3 Dev Module (Arduino)
*/

#include <Arduino.h>

// ----------------------- UART CONFIG -----------------------
#define UART_BAUD     250000
#define UART_RX_PIN   14   // Slave RX  <- Master TX
#define UART_TX_PIN   13   // Slave TX  -> Master RX

// ----------------------- PIN MAPS --------------------------
// Edit these to match your hardware.
// Encoders: each has A/B pins and an ID index used in messages.
// Example has 5 encoders (you can add up to 9 easily).

struct EncPin {
  uint8_t pinA;
  uint8_t pinB;
  uint8_t id;   // appears in "ENC<id>:+/-1"
};

// Fill with your real pins:
EncPin ENCODERS[] = {
  // {A,  B,  id}
  { 6,  7,  1 },   // On/Off encoder example
  { 10, 11, 2 },   // Channel / Freq encoders...
  { 12, 15, 3 },
  { 16, 17, 4 },
  { 35, 36, 5 },
  // Add more as needed:
  // { 37, 38, 6 },
  // { 45, 18, 7 },
  // { 21, 26, 8 },
  // { 47, 48, 9 },
};
const uint8_t NUM_ENC = sizeof(ENCODERS) / sizeof(ENCODERS[0]);

// Rotary switches: one pin per position to GND (or VCC), with pullups/pulldowns.
// This sketch assumes: one active pin at a time, position reported as 1..N.
// Set ACTIVE_LOW = true if switch pulls to GND.
struct RotarySwitch {
  const uint8_t* pins;   // array of GPIOs
  uint8_t        count;  // number of positions (e.g., 7 or 8)
  uint8_t        id;     // RS<id>
  bool           activeLow;
};

// Example 2 rotary switches (edit pins to yours):
const uint8_t RS1_PINS[] = { 0, 1, 2, 3, 37, 38, 18, 21 }; // 8 pos
const uint8_t RS2_PINS[] = { 35, 36, 45, 47, 48, 26, 12 }; // 7 pos (example)

RotarySwitch ROT_SW[] = {
  { RS1_PINS, (uint8_t)(sizeof(RS1_PINS)/sizeof(RS1_PINS[0])), 1, true },
  { RS2_PINS, (uint8_t)(sizeof(RS2_PINS)/sizeof(RS2_PINS[0])), 2, true },
};
const uint8_t NUM_RS = sizeof(ROT_SW) / sizeof(ROT_SW[0]);

// ---------------- Quadrature Encoder (polling) -------------
struct EncState {
  uint8_t lastAB;     // last 2-bit state
  int8_t  accum;      // accumulate transitions
};
EncState ENC_STATE[16]; // up to 16 encoders if you expand

// State transition table for quadrature (Gray), returns -1/0/+1 per step
// Index with (prev<<2)|curr (both are 2-bit values: (A<<1)|B).
int8_t quadStep(int prev, int curr) {
  static const int8_t table[16] = {
    // prev:curr  00  01  10  11
    /*00*/        0, +1, -1,  0,
    /*01*/       -1,  0,  0, +1,
    /*10*/       +1,  0,  0, -1,
    /*11*/        0, -1, +1,  0
  };
  return table[(prev << 2) | curr];
}

// ---------------- Debounce helpers -------------------------
uint8_t fastRead(uint8_t pin) { return (uint8_t)digitalRead(pin); }

// ---------------- Reporting helpers ------------------------
void sendLine(const String& s) {
  Serial1.print(s);
  Serial1.print('\n');
}

void sendEncDelta(uint8_t id, int8_t delta) {
  if (delta > 0)      sendLine(String("ENC") + id + ":+1");
  else if (delta < 0) sendLine(String("ENC") + id + ":-1");
}

void sendRotary(uint8_t id, uint8_t pos) {
  // pos is 1..N
  sendLine(String("RS") + id + ":" + pos);
}

// ---------------- Setup ------------------------------
void setupEncoders() {
  for (uint8_t i = 0; i < NUM_ENC; ++i) {
    pinMode(ENCODERS[i].pinA, INPUT_PULLUP);
    pinMode(ENCODERS[i].pinB, INPUT_PULLUP);
    uint8_t a = fastRead(ENCODERS[i].pinA);
    uint8_t b = fastRead(ENCODERS[i].pinB);
    ENC_STATE[i].lastAB = (a << 1) | b;
    ENC_STATE[i].accum  = 0;
  }
}

void setupRotarySwitches() {
  for (uint8_t r = 0; r < NUM_RS; ++r) {
    for (uint8_t i = 0; i < ROT_SW[r].count; ++i) {
      if (ROT_SW[r].activeLow) pinMode(ROT_SW[r].pins[i], INPUT_PULLUP);
      else                     pinMode(ROT_SW[r].pins[i], INPUT_PULLDOWN);
    }
  }
}

// Returns 1..N if one valid position is active, 0 if none/invalid
uint8_t readRotaryPosition(const RotarySwitch& rs) {
  int activeIndex = -1;
  for (uint8_t i = 0; i < rs.count; ++i) {
    bool active = rs.activeLow ? (digitalRead(rs.pins[i]) == LOW)
                               : (digitalRead(rs.pins[i]) == HIGH);
    if (active) {
      if (activeIndex >= 0) {
        // More than one active -> invalid
        return 0;
      }
      activeIndex = i;
    }
  }
  return (activeIndex >= 0) ? (activeIndex + 1) : 0;
}

// Track last reported positions for each rotary switch
uint8_t RS_LAST_POS[8]; // up to 8 rotary switches

// ------------------- Setup / Loop --------------------------
void setup() {
  Serial.begin(115200); // USB debug (optional)
  delay(200);
  Serial1.begin(UART_BAUD, SERIAL_8N1, UART_RX_PIN, UART_TX_PIN);
  delay(50);

  setupEncoders();
  setupRotarySwitches();

  for (uint8_t i = 0; i < NUM_RS; ++i) RS_LAST_POS[i] = 0;

  Serial.println("Slave UART node ready.");
  sendLine("HB"); // initial heartbeat
}

uint32_t tHeartbeat = 0;
uint32_t tLastRotaryScan = 0;

void loop() {
  // ---- Scan encoders (poll fast) ----
  for (uint8_t i = 0; i < NUM_ENC; ++i) {
    uint8_t a = fastRead(ENCODERS[i].pinA);
    uint8_t b = fastRead(ENCODERS[i].pinB);
    uint8_t curr = (a << 1) | b;
    int8_t step = quadStep(ENC_STATE[i].lastAB, curr);
    ENC_STATE[i].lastAB = curr;

    if (step != 0) {
      // Accumulate transitions to filter bounce: valid detent often = +/-4
      ENC_STATE[i].accum += step;
      if (ENC_STATE[i].accum >= +4) {
        sendEncDelta(ENCODERS[i].id, +1);
        ENC_STATE[i].accum = 0;
      } else if (ENC_STATE[i].accum <= -4) {
        sendEncDelta(ENCODERS[i].id, -1);
        ENC_STATE[i].accum = 0;
      }
    }
  }

  // ---- Scan rotary switches (slower, debounced) ----
  uint32_t now = millis();
  if (now - tLastRotaryScan >= 10) { // ~100 Hz
    tLastRotaryScan = now;
    for (uint8_t r = 0; r < NUM_RS; ++r) {
      uint8_t pos = readRotaryPosition(ROT_SW[r]);
      // Simple debounce / change detect
      static uint8_t stableCount[8] = {0};
      if (pos == RS_LAST_POS[r]) {
        // stable, do nothing
        stableCount[r] = 0;
      } else {
        // require a few consecutive reads before reporting
        if (pos != 0) {
          if (++stableCount[r] >= 5) { // ~50 ms confirmation
            RS_LAST_POS[r] = pos;
            stableCount[r] = 0;
            sendRotary(ROT_SW[r].id, pos);
          }
        } else {
          // invalid or none active; don't report, just reset counter
          stableCount[r] = 0;
        }
      }
    }
  }

  // ---- Heartbeat every ~2s ----
  if (now - tHeartbeat >= 2000) {
    tHeartbeat = now;
    sendLine("HB");
  }

  // ---- Handle any incoming commands from master (optional) ----
  // Example: consume lines for future features (LED control, etc.)
  while (Serial1.available()) {
    // read and ignore for now
    Serial1.read();
  }
}
