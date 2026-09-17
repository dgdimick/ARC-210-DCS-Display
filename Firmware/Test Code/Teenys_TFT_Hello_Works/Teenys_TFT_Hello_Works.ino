#include <ILI9488_t3.h>

#define TFT_CS    10
#define TFT_DC     9
#define TFT_RST    8
#define TFT_MOSI  11
#define TFT_SCK   13
#define TFT_MISO  12
#define TFT_BL     6

ILI9488_t3 tft(
  TFT_CS,
  TFT_DC,
  TFT_RST,
  TFT_MOSI,
  TFT_SCK,
  TFT_MISO
);

void setup() {
  pinMode(TFT_BL, OUTPUT);
  digitalWrite(TFT_BL, HIGH);

  tft.begin();
  tft.setRotation(1);

  tft.fillScreen(ILI9488_BLACK);

  tft.setTextColor(ILI9488_GREEN, ILI9488_BLACK);
  tft.setTextSize(4);

  tft.setCursor(70, 130);
  tft.print("HELLO WORLD");
}

void loop() {
}