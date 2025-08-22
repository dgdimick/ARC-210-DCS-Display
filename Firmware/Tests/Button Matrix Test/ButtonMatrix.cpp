// ButtonMatrix.cpp

#include "ButtonMatrix.h"

KeyState keys[ROWS * COLS];
int active_button = 0;

void setAllRowsHiZ() {
  for (uint8_t r = 0; r < ROWS; r++) pinMode(rowPins[r], INPUT);
}

void driveRowLow(uint8_t r) {
  for (uint8_t i = 0; i < ROWS; i++) {
    if (i == r) {
      pinMode(rowPins[i], OUTPUT);
      digitalWrite(rowPins[i], LOW);
    } else {
      pinMode(rowPins[i], INPUT);
    }
  }
}

void ButtonMatrixSetup() {
  // Columns as pullups
  for (uint8_t c = 0; c < COLS; c++) pinMode(colPins[c], INPUT_PULLUP);
  setAllRowsHiZ();

  // Init states
  for (uint8_t i = 0; i < ROWS * COLS; i++) {
    keys[i].stable = false;
    keys[i].reading = false;
    keys[i].tChange = 0;
  }
}

int ButtonMatrixLoop() {
  bool any_button_pressed_now = false;
  int current_pressed_button = 0;

  for (uint8_t r = 0; r < ROWS; r++) {
    driveRowLow(r);
    delayMicroseconds(40);

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
        break;
      }
    }
    if (any_button_pressed_now) {
      break;
    }
  }

  setAllRowsHiZ();

  if (any_button_pressed_now && active_button == 0) {
    active_button = current_pressed_button;
    return active_button;
  } else if (!any_button_pressed_now && active_button != 0) {
    int released_button = active_button;
    active_button = 0;
    return -released_button; // Return a negative value for a released button
  }
  return 0; // Return 0 if no state change
}