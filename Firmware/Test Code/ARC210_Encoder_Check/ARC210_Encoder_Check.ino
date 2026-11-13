#include <Arduino.h>
#include <SPI.h>
#include <ILI9488_t3.h>
#include <Encoder.h>
constexpr uint8_t PAIRS[6][2]={{16,17},{28,29},{20,21},{22,23},{24,25},{26,27}};
Encoder encoders[6];
int32_t counts[6]={};
char directions[6]={'-','-','-','-','-','-'};

// Numbers printed on the Teensy 4.1 board.
ILI9488_t3 tft(10,9,8);
bool dirty=true,buffered=false;
uint32_t lastDraw=0;
constexpr uint8_t BLK_PIN=4;

void drawStatus() {
  tft.fillRect(0,32,480,288,ILI9488_BLACK);
  tft.setTextSize(2);
  tft.setTextColor(ILI9488_WHITE);
  tft.setCursor(8,33); tft.print("ENC COUNT DIR A/B");
  for(uint8_t i=0;i<6;++i) {
    tft.setTextColor(ILI9488_GREEN);
    tft.setCursor(8,57+i*28); tft.print("R"); tft.print(i+1);
    tft.setCursor(44,57+i*28); tft.print(counts[i]);
    tft.setCursor(152,57+i*28); tft.print(directions[i]);
    tft.setCursor(178,57+i*28); tft.print(digitalRead(PAIRS[i][0]));
    tft.print("/");tft.print(digitalRead(PAIRS[i][1]));
    tft.setTextSize(1);tft.setCursor(8,74+i*28);
    tft.print("GPIO ");tft.print(PAIRS[i][0]);tft.print("/");tft.print(PAIRS[i][1]);
    tft.setTextSize(2);
  }
  tft.setTextColor(ILI9488_WHITE);
  if(buffered) tft.updateScreen();
  dirty=false;
}
void setup() {
  Serial.begin(115200);
  for(uint8_t i=0;i<6;++i) encoders[i].begin(PAIRS[i][0],PAIRS[i][1]);
  pinMode(BLK_PIN,OUTPUT);
  analogWriteResolution(8);
  analogWriteFrequency(BLK_PIN,1000);
  analogWrite(BLK_PIN,255); // Start at full brightness.
  tft.begin(); tft.setRotation(1); tft.setTextWrap(false);
  buffered=tft.useFrameBuffer(true)!=0;
  tft.fillScreen(ILI9488_BLACK);
  tft.setTextSize(2); tft.setTextColor(ILI9488_GREEN);
  tft.setCursor(8,5); tft.print("ARC-210 ENCODER CHECK V1.0");
  tft.setTextSize(1); tft.setTextColor(ILI9488_WHITE);

  drawStatus();
}

void loop() {
  static uint32_t encoderReportAt=0;
  if(Serial && (uint32_t)(millis()-encoderReportAt)>=1000) {
    encoderReportAt=millis();Serial.print("Encoder inputs/counts: ");
    for(uint8_t i=0;i<6;++i) {
      Serial.print("R");Serial.print(i+1);Serial.print("=");
      Serial.print(digitalRead(PAIRS[i][0]));Serial.print("/");
      Serial.print(digitalRead(PAIRS[i][1]));Serial.print("[");
      Serial.print(encoders[i].read());Serial.print("] ");
    }
    Serial.println();
  }
  for(uint8_t i=0;i<6;++i) {
    int32_t value=encoders[i].read();
    if(value!=counts[i]) {
      directions[i]=((uint32_t)value-(uint32_t)counts[i])<0x80000000u ? '+' : '-';
      counts[i]=value; dirty=true;
    }
  }
  if(Serial.available()) {
    char c=Serial.read();
    if(c=='z' || c=='Z') {
      for(uint8_t i=0;i<6;++i) { encoders[i].write(0); counts[i]=0; directions[i]='-'; }
    }
  }
  if(dirty && (uint32_t)(millis()-lastDraw)>=40) {lastDraw=millis(); drawStatus();}
}
