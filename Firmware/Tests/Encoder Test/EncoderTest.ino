#include "Encoder.h"

#define ENC1_A 5
#define ENC1_B 6

int enc1;

void setup() {
  Serial.begin(115200);
  while (!Serial) {}
  enc1 = ARC210::add(ENC1_A, ENC1_B, /*invert=*/false);
  Serial.println("Encoders ready.");
}

void loop() {
  int step = ARC210::read(enc1);  // -1, 0, +1 since last call
  if (step) {
    if (step > 0) Serial.println("ENC1: CW  +1 detent");
    else          Serial.println("ENC1: CCW -1 detent");
    // Map to ARC-210 action here (e.g., freq up/down)
  }
}
