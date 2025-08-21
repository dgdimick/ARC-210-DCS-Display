// 4x4 button matrix (no Keypad lib, no diodes)
// Rows: GPIO 4,5,6,7 (driven LOW one at a time)
// Cols: GPIO 8,9,10,11 (INPUT_PULLUP; pressed reads LOW)

#include <Arduino.h>

const uint8_t ROWS = 4, COLS = 4;
const uint8_t rowPins[ROWS] = {4, 5, 6, 7};
const uint8_t colPins[COLS] = {8, 9, 10, 11};

const uint16_t DEBOUNCE_MS = 12;

// Updated button map with the new remapping
const int buttonMap[ROWS][COLS] = {
  // Col 1, Col 2, Col 3, Col 4
  {16, 12, 8, 4},
  {15, 11, 7, 3},
  {13, 9, 5, 1},
  {14, 10, 6, 2}
};

struct KeyState {
  bool stable;       // debounced state (false=UP, true=DOWN)
  bool reading;      // latest raw read
  uint32_t tChange;  // time raw last changed
};
KeyState keys[ROWS * COLS];

// Variable to store the currently active button
int active_button = 0; 

void setAllRowsHiZ() {
  for (uint8_t r = 0; r < ROWS; r++) pinMode(rowPins[r], INPUT); // Hi-Z
}

void driveRowLow(uint8_t r) {
  for (uint8_t i = 0; i < ROWS; i++) {
    if (i == r) {
      pinMode(rowPins[i], OUTPUT);
      digitalWrite(rowPins[i], LOW);
    } else {
      pinMode(rowPins[i], INPUT); // Hi-Z
    }
  }
}

void setup() {
  Serial.begin(115200);
  delay(300);

  // Columns as pullups (pressed -> LOW)
  for (uint8_t c = 0; c < COLS; c++) pinMode(colPins[c], INPUT_PULLUP);
  setAllRowsHiZ();

  // Init states
  for (uint8_t i = 0; i < ROWS * COLS; i++) {
    keys[i].stable = false;
    keys[i].reading = false;
    keys[i].tChange = 0;
  }

  Serial.println("4x4 Button Matrix Test. Press any button...");
}

void loop() {
  bool any_button_pressed_now = false;
  int current_pressed_button = 0;

  // First, check for any new button presses
  for (uint8_t r = 0; r < ROWS; r++) {
    driveRowLow(r);
    delayMicroseconds(40); // settle time

    for (uint8_t c = 0; c < COLS; c++) {
      const uint8_t idx = r * COLS + c;
      bool raw = (digitalRead(colPins[c]) == LOW);

      if (raw != keys[idx].reading) {
        keys[idx].reading = raw;
        keys[idx].tChange = millis();
      } else if ((millis() - keys[idx].tChange) >= DEBOUNCE_MS && raw != keys[idx].stable) {
        keys[idx].stable = raw;
      }

      if (keys[idx].stable) {
        any_button_pressed_now = true;
        current_pressed_button = buttonMap[r][c];
        break; // Found a pressed button, no need to check others in this inner loop
      }
    }
    if (any_button_pressed_now) {
      break; // Found a pressed button, exit the outer loop
    }
  }

  setAllRowsHiZ();

  // Logic to handle button state
  if (any_button_pressed_now && active_button == 0) {
    // A new button has been pressed and no other button is currently active
    active_button = current_pressed_button;
    Serial.print("Button pressed: ");
    Serial.println(active_button);
  } else if (!any_button_pressed_now && active_button != 0) {
    // The previously pressed button has been released
    Serial.print("Button released: ");
    Serial.println(active_button);
    active_button = 0; // Reset the active button
  }
}