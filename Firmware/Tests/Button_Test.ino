// 4x4 Matrix test
// ====== Pin config (edit to your wiring) ======

static const uint8_t ROWS[] = { 4, 5, 6, 7 };        // 4 rows, GPIOs you chose
static const uint8_t COLS[] = { 8, 9, 10, 11 };      // 4 columns, GPIOs you chose

// Optional: logical names (index = r*4 + c)
const char* KEY_NAMES[16] = {
  "B01","B02","B03","B04",
  "B05","B06","B07","B08",
  "B09","B10","B11","B12",
  "B13","B14","B15","B16"
};

const uint16_t DEBOUNCE_MS = 10;   // debounce time
// ==============================================

const uint8_t NUM_ROWS = 4;
const uint8_t NUM_COLS = 4;

struct KeyState {
  bool stable;        // last debounced state (false=UP, true=DOWN)
  bool reading;       // last raw reading
  uint32_t tChange;   // time raw last changed
};
KeyState keys[16];

void setAllRowsHiZ() {
  for (uint8_t r = 0; r < NUM_ROWS; r++) pinMode(ROWS[r], INPUT); // Hi-Z
}

void driveRowLow(uint8_t r) {
  // drive selected row LOW, others Hi-Z to avoid sneak currents
  for (uint8_t i = 0; i < NUM_ROWS; i++) {
    if (i == r) {
      pinMode(ROWS[i], OUTPUT);
      digitalWrite(ROWS[i], LOW);
    } else {
      pinMode(ROWS[i], INPUT); // Hi-Z
    }
  }
}

void reportEvent(uint8_t r, uint8_t c, bool pressed) {
  const uint8_t idx = r * NUM_COLS + c;
  const char* name = KEY_NAMES[idx];
  // Print to USB serial; change to Serial1 if you want to send to master
  Serial.printf("%s:%s\n", name, pressed ? "DOWN" : "UP");
}

void setup() {
  Serial.begin(115200);
  delay(100);

  // Columns as inputs with pull-ups (active LOW when pressed)
  for (uint8_t c = 0; c < NUM_COLS; c++) pinMode(COLS[c], INPUT_PULLUP);
  setAllRowsHiZ();

  // Init key states
  for (uint8_t i = 0; i < 16; i++) {
    keys[i].stable  = false;
    keys[i].reading = false;
    keys[i].tChange = 0;
  }
  Serial.println("4x4 matrix scanner ready.");
}

void scanMatrixOnce() {
  for (uint8_t r = 0; r < NUM_ROWS; r++) {
    driveRowLow(r);
    delayMicroseconds(40); // small settle time for lines/diodes

    for (uint8_t c = 0; c < NUM_COLS; c++) {
      const uint8_t idx = r * NUM_COLS + c;

      // With pull-ups: pressed ⇒ column reads LOW
      bool raw = (digitalRead(COLS[c]) == LOW);

      if (raw != keys[idx].reading) {
        keys[idx].reading = raw;
        keys[idx].tChange = millis();   // start debounce timer
      } else {
        if ((millis() - keys[idx].tChange) >= DEBOUNCE_MS && raw != keys[idx].stable) {
          keys[idx].stable = raw;
          reportEvent(r, c, raw);       // emit press/release
        }
      }
    }
  }
  setAllRowsHiZ();
}

void loop() {
  scanMatrixOnce();  // fast, non-blocking
  // do other tasks here (encoders, UART, etc.)
}
