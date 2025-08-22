#pragma once
#include <Arduino.h>

/*
  Encoder.h — ARC-210 quadrature encoder helper for DCS-BIOS projects
  - Handles multiple encoders (3-pin type: Channel A, GND, Channel B)
  - Returns one step per detent (configurable edges-per-detent)
*/

#ifndef ARC210_MAX_ENCODERS
#define ARC210_MAX_ENCODERS 10
#endif

#ifndef ARC210_EDGES_PER_DETENT
#define ARC210_EDGES_PER_DETENT 4   // set to 2 if your encoder outputs 2 edges per click
#endif

namespace ARC210 {

struct Encoder {
  uint8_t pinA, pinB;
  volatile int16_t detentDelta;
  volatile int8_t  edgeAccum;
  volatile uint8_t prevState;
  bool invert;
};

static Encoder enc[ARC210_MAX_ENCODERS];
static int encCount = 0;

static const int8_t dirTable[16] = {
   0, -1, +1,  0,
  +1,  0,  0, -1,
  -1,  0,  0, +1,
   0, +1, -1,  0
};

static inline void IRAM_ATTR encoderISR() {
  for (int i = 0; i < encCount; i++) {
    uint8_t a = digitalRead(enc[i].pinA);
    uint8_t b = digitalRead(enc[i].pinB);
    uint8_t curr = (a << 1) | b;
    uint8_t idx  = (enc[i].prevState << 2) | curr;
    int8_t step  = dirTable[idx];
    if (step != 0) {
      if (enc[i].invert) step = -step;
      enc[i].edgeAccum += step;

      if (enc[i].edgeAccum >= ARC210_EDGES_PER_DETENT) {
        enc[i].detentDelta++;
        enc[i].edgeAccum = 0;
      } else if (enc[i].edgeAccum <= -ARC210_EDGES_PER_DETENT) {
        enc[i].detentDelta--;
        enc[i].edgeAccum = 0;
      }
    }
    enc[i].prevState = curr;
  }
}

// call this once in setup()
inline int add(uint8_t pinA, uint8_t pinB, bool invert=false) {
  if (encCount >= ARC210_MAX_ENCODERS) return -1;
  Encoder &e = enc[encCount];
  e.pinA = pinA; e.pinB = pinB; e.invert = invert;
  e.detentDelta = 0; e.edgeAccum = 0;
  pinMode(e.pinA, INPUT_PULLUP);
  pinMode(e.pinB, INPUT_PULLUP);
  e.prevState = (digitalRead(e.pinA) << 1) | digitalRead(e.pinB);
  attachInterrupt(digitalPinToInterrupt(e.pinA), encoderISR, CHANGE);
  attachInterrupt(digitalPinToInterrupt(e.pinB), encoderISR, CHANGE);
  return encCount++;
}

// poll this from loop()
inline int read(int idx) {
  if (idx < 0 || idx >= encCount) return 0;
  noInterrupts();
  int v = enc[idx].detentDelta;
  enc[idx].detentDelta = 0;
  interrupts();
  return v;
}

} // namespace ARC210
