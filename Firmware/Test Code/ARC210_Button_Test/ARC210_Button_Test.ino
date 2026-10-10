#include <Arduino.h>
#include <SPI.h>
#include <ILI9488_t3.h>
#include <Encoder.h>
constexpr uint8_t PAIRS[6][2]={{16,17},{28,29},{20,21},{22,23},{24,25},{26,27}};
Encoder encoders[6];
int32_t counts[6]={};
char directions[6]={'-','-','-','-','-','-'};

// Numbers printed on the Teensy 4.1 board.
constexpr uint8_t ROWS[4]={30,31,32,33};
constexpr uint8_t COLS[4]={35,36,37,40};
ILI9488_t3 tft(10,9,8);
bool rawState[16]={}, pressed[16]={}, seen[16]={};
bool held[16]={};
int activeButton=-1;
uint32_t changedAt[16]={};
uint32_t lastScan=0,lastDraw=0;
bool dirty=true,buffered=false;
int lastKey=-1;
bool lastPressed=false;
constexpr uint8_t BLK_PIN=4;
int brightness=100;
int8_t brightnessDirection=0;
uint32_t brightnessTick=0;
bool brightnessRepeating=false;


// Seven-position switch: J1 1=3.3V, 2=physical GPIO14/A0 or GPIO15/A1, 3=GND.
// Fit six 1k resistors R1-R6 and leave JP1 open.
constexpr uint8_t ROTARY_PINS[2]={14,15};
constexpr int ROTARY_EXPECTED[7]={4095,3413,2730,2048,1365,683,0};
int rotaryRaw[2]={0,0},rotaryCandidate[2]={-1,-1},rotaryPosition[2]={-1,-1};
uint8_t rotarySeen[2]={0,0};
uint32_t rotaryCandidateSince[2]={0,0},rotarySampleAt=0,rotaryDisplayAt=0;

int decodeRotary(int raw) {
  int best=0,error=4096;
  for(int i=0;i<7;++i) {
    int e=abs(raw-ROTARY_EXPECTED[i]);
    if(e<error) { error=e;best=i+1; }
  }
  return error<=200 ? best : 0;
}

void scanRotary() {
  uint32_t now=millis();
  if((uint32_t)(now-rotarySampleAt)<5) return;
  rotarySampleAt=now;
  for(uint8_t i=0;i<2;++i) {
    rotaryRaw[i]=analogRead(ROTARY_PINS[i]);
    int position=decodeRotary(rotaryRaw[i]);
    if(position!=rotaryCandidate[i]) {
      rotaryCandidate[i]=position;rotaryCandidateSince[i]=now;
    }
    if(rotaryCandidate[i]!=rotaryPosition[i] && (uint32_t)(now-rotaryCandidateSince[i])>=75) {
      rotaryPosition[i]=rotaryCandidate[i];
      if(rotaryPosition[i]>0) rotarySeen[i]|=(1u<<(rotaryPosition[i]-1));
      dirty=true;
      if(Serial) {
        Serial.print("Rotary GPIO");Serial.print(ROTARY_PINS[i]);
        Serial.print(" position: ");Serial.print(rotaryPosition[i]);
        Serial.print(" ADC: ");Serial.println(rotaryRaw[i]);
      }
    }
  }
  if((uint32_t)(now-rotaryDisplayAt)>=200) {rotaryDisplayAt=now;dirty=true;}
}

void stepBrightness(int8_t direction) {
  int next=constrain(brightness+direction*5,5,100);
  if(next==brightness) return;
  brightness=next;
  analogWrite(BLK_PIN,(brightness*255+50)/100);
  dirty=true;
}

void updateBrightness() {
  // Only the accepted button controls brightness; B1/B2 indices are 0/4.
  int8_t direction=pressed[0]==pressed[4] ? 0 : (pressed[0] ? -1 : 1);
  uint32_t now=millis();
  if(direction!=brightnessDirection) {
    brightnessDirection=direction;
    brightnessTick=now;
    brightnessRepeating=false;
    if(direction) stepBrightness(direction);
  } else if(direction && (uint32_t)(now-brightnessTick)>=(brightnessRepeating ? 100u : 400u)) {
    stepBrightness(direction);
    brightnessTick=now;
    brightnessRepeating=true;
  }
}

void scanButtons() {
  const uint32_t now=millis();
  for(uint8_t r=0;r<4;++r) {
    // Schematic: diode cathodes (striped ends) connect to rows.
    // Only the selected row drives LOW; other rows remain high impedance.
    digitalWrite(ROWS[r],LOW);
    pinMode(ROWS[r],OUTPUT);
    delayMicroseconds(10);
    for(uint8_t c=0;c<4;++c) {
      uint8_t k=r*4+c;
      bool down=digitalRead(COLS[c])==LOW;
      if(down!=rawState[k]) { rawState[k]=down; changedAt[k]=now; }
      if(down!=held[k] && (uint32_t)(now-changedAt[k])>=20) {
        held[k]=down;
        // Ignore blocked presses until they are released and pressed again.
        if(down) {
          if(activeButton>=0) continue;
          activeButton=k;
        } else {
          if(activeButton!=k) continue;
          activeButton=-1;
        }
        pressed[k]=down;
        if(down) seen[k]=true;
        lastKey=k; lastPressed=down; dirty=true;
        Serial.print("Button "); Serial.print(c*4+r+1);
        Serial.println(down ? " PRESSED" : " RELEASED");
      }
    }
    pinMode(ROWS[r],INPUT);
  }
}

void drawStatus() {
  tft.fillRect(0,32,480,288,ILI9488_BLACK);
  tft.setTextSize(2);
  for(uint8_t r=0;r<4;++r) for(uint8_t c=0;c<4;++c) {
    const uint8_t k=r*4+c;
    const int x=8+c*57,y=51+r*37;
    tft.fillRect(x,y,52,30,pressed[k] ? ILI9488_GREEN : ILI9488_BLACK);
    tft.drawRect(x,y,52,30,seen[k] ? ILI9488_GREEN : ILI9488_WHITE);
    tft.setTextColor(pressed[k] ? ILI9488_BLACK : ILI9488_WHITE);
    tft.setCursor(x+7,y+7); tft.print("B"); tft.print(c*4+r+1);
  }
  tft.setTextColor(ILI9488_WHITE);
  tft.setCursor(250,33); tft.print("ENC COUNT DIR A/B");
  for(uint8_t i=0;i<6;++i) {
    tft.setTextColor(ILI9488_GREEN);
    tft.setCursor(250,57+i*28); tft.print("R"); tft.print(i+1);
    tft.setCursor(286,57+i*28); tft.print(counts[i]);
    tft.setCursor(394,57+i*28); tft.print(directions[i]);
    tft.setCursor(420,57+i*28); tft.print(digitalRead(PAIRS[i][0]));
    tft.print("/");tft.print(digitalRead(PAIRS[i][1]));
    tft.setTextSize(1);tft.setCursor(250,74+i*28);
    tft.print("GPIO ");tft.print(PAIRS[i][0]);tft.print("/");tft.print(PAIRS[i][1]);
    tft.setTextSize(2);
  }
  tft.setTextColor(ILI9488_WHITE);
  uint8_t total=0; for(bool value:seen) if(value) ++total;
  tft.setCursor(8,216); tft.print("Tested: "); tft.print(total); tft.print("/16");
  tft.setCursor(8,243); tft.print("BLK: "); tft.print(brightness); tft.print("%");
  if(lastKey>=0) {
    tft.setCursor(8,270); tft.print("Last: B"); tft.print((lastKey%4)*4+lastKey/4+1);
    tft.print(lastPressed ? " pressed" : " released");
  }
  tft.setTextSize(1);
  tft.setCursor(8,300); tft.print("Hold B1: Dim  B2: Bright | Green: tested | Serial Z: reset");
  tft.setTextColor(ILI9488_CYAN);
  for(uint8_t i=0;i<2;++i) {
    int y=220+i*40;
    tft.setTextSize(2);
    tft.setCursor(250,y);tft.print("SW");tft.print(ROTARY_PINS[i]);tft.print(": ");
    if(rotaryPosition[i]>0) {tft.print(rotaryPosition[i]);tft.print("/7");}
    else tft.print("---");
    uint8_t tested=0;
    for(uint8_t k=0;k<7;++k) if(rotarySeen[i]&(1u<<k)) ++tested;
    tft.setTextSize(1);tft.setCursor(250,y+23);
    tft.print("ADC:");tft.print(rotaryRaw[i]);tft.print(" ");
    tft.print(rotaryRaw[i]*3.3f/4095,3);tft.print("V tested:");
    tft.print(tested);tft.print("/7");
  }
  if(buffered) tft.updateScreen();
  dirty=false;
}
void setup() {
  Serial.begin(115200);
  for(uint8_t pin:ROTARY_PINS) pinMode(pin,INPUT);
  analogReadResolution(12);
  analogReadAveraging(16);
  for(uint8_t i=0;i<6;++i) encoders[i].begin(PAIRS[i][0],PAIRS[i][1]);
  for(uint8_t pin:ROWS) pinMode(pin,INPUT);
  for(uint8_t pin:COLS) pinMode(pin,INPUT_PULLUP);
  pinMode(BLK_PIN,OUTPUT);
  analogWriteResolution(8);
  analogWriteFrequency(BLK_PIN,1000);
  analogWrite(BLK_PIN,255); // Start at full brightness.
  tft.begin(); tft.setRotation(1); tft.setTextWrap(false);
  buffered=tft.useFrameBuffer(true)!=0;
  tft.fillScreen(ILI9488_BLACK);
  tft.setTextSize(2); tft.setTextColor(ILI9488_GREEN);
  tft.setCursor(8,5); tft.print("ARC-210 CONTROLS TEST");
  tft.setTextSize(1); tft.setTextColor(ILI9488_WHITE);
  
  drawStatus();
}

void loop() {
  scanRotary();
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
      for(uint8_t k=0;k<16;++k) seen[k]=pressed[k];
      lastKey=-1; dirty=true;
      for(uint8_t i=0;i<2;++i) rotarySeen[i]=rotaryPosition[i]>0 ? (1u<<(rotaryPosition[i]-1)) : 0;
      for(uint8_t i=0;i<6;++i) { encoders[i].write(0); counts[i]=0; directions[i]='-'; }
    }
  }
  if((uint32_t)(millis()-lastScan)>=2) {lastScan=millis(); scanButtons(); updateBrightness();}
  if(dirty && (uint32_t)(millis()-lastDraw)>=40) {lastDraw=millis(); drawStatus();}
}




