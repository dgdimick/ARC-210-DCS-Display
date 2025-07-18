#include <SPI.h>
#include <ILI9488-ESP32S3.h>
#include <Adafruit_NeoPixel.h>

// === Display Pins ===
#define TFT_CS   10
#define TFT_DC    9
#define TFT_RST   8
ILI9488 tft = ILI9488(TFT_CS, TFT_DC, TFT_RST);

// === WS2812 LED ===
#define WS2812_PIN 4
#define NUM_PIXELS 1
Adafruit_NeoPixel strip(NUM_PIXELS, WS2812_PIN, NEO_GRB + NEO_KHZ800);

// === Onboard LED ===
#define LED_PIN 48

// === Switch Pins (excluding GPIO 11, 12, and 13) ===
const int switchPins[16] = {
  1, 2, 3, 5,
  6, 7, 14, 15,
  16, 17, 18, 19,
  20, 21, 38, 39
};

bool buttonState[16] = {0};

void setup() {
  Serial.begin(115200);

  pinMode(LED_PIN, OUTPUT);

  for (int i = 0; i < 16; i++) {
    pinMode(switchPins[i], INPUT_PULLUP);
  }

  // === Display Setup ===
  tft.begin();
  tft.setRotation(1);
  tft.fillScreen(ILI9488_BLACK);
  tft.setTextSize(3);
  tft.setTextColor(ILI9488_GREEN, ILI9488_BLACK);
  tft.setCursor(20, 140);
  tft.print("Waiting for press");

  // === WS2812 LED Ready Indicator ===
  strip.begin();
  strip.setPixelColor(0, strip.Color(255, 0, 0)); // Red (Ready)
  strip.show();
}

void loop() {
  bool anyPressed = false;
  int pressedIndex = -1;

  for (int i = 0; i < 16; i++) {
    bool currentState = digitalRead(switchPins[i]) == LOW;
    if (currentState && !buttonState[i]) {
      Serial.print("Button ");
      Serial.print(i);
      Serial.println(" pressed");
      pressedIndex = i;
    }
    buttonState[i] = currentState;
    if (currentState) anyPressed = true;
  }

  digitalWrite(LED_PIN, anyPressed ? HIGH : LOW);

  if (pressedIndex >= 0) {
    tft.fillRect(0, 140, 480, 40, ILI9488_BLACK);
    tft.setCursor(20, 140);
    tft.print("Button ");
    tft.print(pressedIndex);
    tft.print(" pressed");
  }

  delay(10);
}
