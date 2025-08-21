// ButtonMatrix.h

#ifndef BUTTON_MATRIX_H
#define BUTTON_MATRIX_H

#include <Arduino.h>

const uint8_t ROWS = 4, COLS = 4;
const uint8_t rowPins[ROWS] = {4, 5, 6, 7}; // GPIO's used for the ROWS pins
const uint8_t colPins[COLS] = {8, 9, 10, 11}; // GPIO's used for COLS Pins
const uint16_t DEBOUNCE_MS = 12;

// Updated button map with the new remapping
const int buttonMap[ROWS][COLS] = {
  {16, 12, 8, 4},
  {15, 11, 7, 3},
  {13, 9, 5, 1},
  {14, 10, 6, 2}
};

struct KeyState {
  bool stable;
  bool reading;
  uint32_t tChange;
};

// Function prototypes
void ButtonMatrixSetup();
int ButtonMatrixLoop();

#endif