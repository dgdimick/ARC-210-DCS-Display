// ===== Matrix config =====
This file is to test the Button hardware

static const uint8_t ROWS[] = { 4, 5, 6, 7 };                   // <-- set your GPIOs
static const uint8_t COLS[] = { 8, 9, 10, 11, 12, 15, 16 };     // <-- set your GPIOs
// Active when a key connects row to column (pulling the column LOW)

const uint8_t NUM_ROWS = sizeof(ROWS) / sizeof(ROWS[0]);
const uint8_t NUM_COLS = sizeof(COLS) / sizeof(COLS[0]);

// Debounce timing
const uint16_t DEBOUNCE_MS = 10;

// Optional: logical naming map (index = r*NUM_COLS + c)
const char* KEY_NAMES[] = {
  // R0:
  "B01","B02","B03","B04","B05","B06","B07",
  // R1:
  "B08","B09","B10","B11","B12","B13","B14",
  // R2:
  "B15","B16","B17","B18","B19","B20","B21",
  // R3:
  "B22","B23","B24","B25","B26","B27","B28",
};

// ===== Internals =====
struct KeyState {
  bool stable;           // last stable state (false=up, true=down)
  bool reading;          // last raw reading
  uint32_t tChange;      // last time reading changed (for debounce)
};
KeyState keys[8*16];     // supports up to 8x16; adjust if bigger

void setAllRowsHiZ() {
  for (uint8_t r = 0; r < NUM_ROWS; r++) pinMode(ROWS[r], INPUT);  // Hi-Z
}

void driveRowLow(uint8_t r) {
  // Drive selected row LOW; others Hi-Z
  for (uint8_t i = 0; i < NUM_ROWS; i++) {
    if (i == r) {
      pinMode(ROWS[i], OUTPUT);
      digitalWrite(ROWS[i], LOW);
    } else {
      pinMode(ROWS[i], INPUT); // Hi-Z
    }
  }
}

void printEvent(uint8_t r, uint8_t c, bool pressed) {
  const uint16_t idx = r * NUM_COLS + c;
  const char* name = (idx < (sizeof(KEY_NAMES)/sizeof(KEY_NAMES[0]))) ? KEY_NAMES[idx] : nullptr;
  if (name) {
    Serial.printf("%s:%s\n", name, pressed ? "DOWN" : "UP");
  } else {
    Serial.printf("R%uC%u:%s\n", r, c, pressed ? "DOWN" : "UP");
  }
}

void setup() {
  Serial.begin(115200);
  delay(100);

  // Columns as inputs with pullups; active when read LOW
  for (uint8_t c = 0; c < NUM_COLS; c++) {
    pinMode(COLS[c], INPUT_PULLUP);
  }
  setAllRowsHiZ();

  // Init key states
  for (uint8_t r = 0; r < NUM_ROWS; r++) {
    for (uint8_t c = 0; c < NUM_COLS; c++) {
      const uint16_t idx = r * NUM_COLS + c;
      keys[idx].stable  = false;
      keys[idx].reading = false;
      keys[idx].tChange = 0;
    }
  }

  Serial.println("Matrix scanner ready.");
}

void scanMatrixOnce() {
  // Scan each row: drive it LOW, read all columns
  for (uint8_t r = 0; r < NUM_ROWS; r++) {
    driveRowLow(r);
    delayMicroseconds(50); // settle time for lines/diodes

    for (uint8_t c = 0; c < NUM_COLS; c++) {
      const uint16_t idx = r * NUM_COLS + c;

      // Active LOW: pressed when column reads LOW
      bool raw = (digitalRead(COLS[c]) == LOW);

      if (raw != keys[idx].reading) {
        // raw changed; start debounce timer
        keys[idx].reading = raw;
        keys[idx].tChange = millis();
      } else {
        // raw stable; if past debounce and differs from stable -> commit
        if ((millis() - keys[idx].tChange) >= DEBOUNCE_MS && raw != keys[idx].stable) {
          keys[idx].stable = raw;
          printEvent(r, c, raw);
        }
      }
    }
  }

  // Return rows to Hi-Z when not actively scanning (reduces sneak currents)
  setAllRowsHiZ();
}

void loop() {
  scanMatrixOnce();   // non-blocking; ~ a few hundred scans/sec
  // Do other work here (encoders, UART, etc.)
}
