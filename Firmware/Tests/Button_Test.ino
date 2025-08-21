// Your main sketch file (e.g., Button_Test.ino)

#include "ButtonMatrix.h"

void setup() {
  Serial.begin(115200);
  delay(300);
  ButtonMatrixSetup();
  Serial.println("4x4 Button Matrix Test. Press any button...");
}

void loop() {
  int button_state = ButtonMatrixLoop();

  if (button_state > 0) {
    Serial.print("Button pressed: ");
    Serial.println(button_state);
  } else if (button_state < 0) {
    Serial.print("Button released: ");
    Serial.println(-button_state);
  }
}