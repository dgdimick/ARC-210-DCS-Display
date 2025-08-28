// --- DCS-BIOS must be defined before include ---
#define DCSBIOS_DEFAULT_SERIAL
#include <DcsBios.h>

#include "Encoder.h"   // your header-only helper

// ===============================================
// CONFIG: 6 encoders (fill with your actual pins)
// Safe example pins (adjust if you already use them)
const uint8_t A_PINS[6] = { 5,  7,  9, 11, 13, 15 };
const uint8_t B_PINS[6] = { 6,  8, 10, 12, 14, 16 };
// Optional per-encoder direction flip (true = invert)
const bool    INVERT[6] = { 0,  0,  0,  0,  0,  0 };

// DCS-BIOS control names (INC/DEC style). Change to your exports.
const char* CTRL_INC[6] = {
  "ARC210_FREQ_KNOB_INC",    // ENC0
  "ARC210_VOL_KNOB_INC",     // ENC1
  "ARC210_CHAN_KNOB_INC",    // ENC2
  "ARC210_SEC_KNOB_INC",     // ENC3
  "ARC210_PRIM_KNOB_INC",    // ENC4
  "ARC210_SQL_KNOB_INC"      // ENC5
};
const char* CTRL_DEC[6] = {
  "ARC210_FREQ_KNOB_DEC",
  "ARC210_VOL_KNOB_DEC",
  "ARC210_CHAN_KNOB_DEC",
  "ARC210_SEC_KNOB_DEC",
  "ARC210_PRIM_KNOB_DEC",
  "ARC210_SQL_KNOB_DEC"
};

// If your export uses a single control with "+1"/"-1", comment out CTRL_INC/DEC above
// and instead fill these, then toggle USE_PLUS_MINUS to 1.
#define USE_PLUS_MINUS 0
const char* CTRL_STEP[6] = {
  "ARC210_FREQ_KNOB", "ARC210_VOL_KNOB", "ARC210_CHAN_KNOB",
  "ARC210_SEC_KNOB",  "ARC210_PRIM_KNOB","ARC210_SQL_KNOB"
};

// Optional names for Serial debug
const char* ENC_NAME[6] = { "FREQ","VOL","CHAN","SEC","PRIM","SQL" };
// ===============================================

int encIdx[6];

void setup() {
  Serial.begin(115200);
  while (!Serial) {}
  Serial.println("ARC-210: 6-Encoder Service Starting...");

  DcsBios::setup();

  // Register all encoders
  for (int i = 0; i < 6; ++i) {
    encIdx[i] = ARC210::add(A_PINS[i], B_PINS[i], INVERT[i]);
    if (encIdx[i] < 0) {
      Serial.print("ERR: add() failed for encoder "); Serial.println(i);
    } else {
      Serial.print("Encoder "); Serial.print(i);
      Serial.print(" ("); Serial.print(ENC_NAME[i]); Serial.print(") pins A=");
      Serial.print(A_PINS[i]); Serial.print(" B="); Serial.println(B_PINS[i]);
    }
  }
}

void loop() {
  DcsBios::loop();

  for (int i = 0; i < 6; ++i) {
    int steps = ARC210::read(encIdx[i]);  // may be -N..+N if spun fast

#if USE_PLUS_MINUS
    // Single control with "+1"/"-1"
    while (steps > 0) {
      DcsBios::sendDcsBiosMessage(CTRL_STEP[i], "+1");
      Serial.print(ENC_NAME[i]); Serial.println(": CW  +1 detent");
      steps--;
    }
    while (steps < 0) {
      DcsBios::sendDcsBiosMessage(CTRL_STEP[i], "-1");
      Serial.print(ENC_NAME[i]); Serial.println(": CCW -1 detent");
      steps++;
    }
#else
    // Separate INC/DEC controls
    while (steps > 0) {
      DcsBios::sendDcsBiosMessage(CTRL_INC[i], "1");
      Serial.print(ENC_NAME[i]); Serial.println(": CW  +1 detent");
      steps--;
    }
    while (steps < 0) {
      DcsBios::sendDcsBiosMessage(CTRL_DEC[i], "1");
      Serial.print(ENC_NAME[i]); Serial.println(": CCW -1 detent");
      steps++;
    }
#endif
  }
}
