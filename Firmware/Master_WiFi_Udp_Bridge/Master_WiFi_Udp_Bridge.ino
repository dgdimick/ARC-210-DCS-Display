/*
  Master_WiFi_Udp_Bridge.ino
  ESP32-S3 master: Wi-Fi (UDP) <-> UART bridge for DCS-BIOS over the air.
  - Wi-Fi credentials in wifi_config.h (kept out of Git)
  - UDP to PC/HUB at HUB_IP:HUB_PORT
  - UART1 to slave (encoders/switches) on GPIO 13/14

  Board: ESP32S3 Dev Module (Arduino)
*/

#include <WiFi.h>
#include <WiFiUdp.h>
#include "wifi_config.h"

// ===================== User Settings =====================
// PC running DCS-BIOS Hub (set this to your PC's IP)
#define HUB_IP        IPAddress(192,168,1,50)
#define HUB_PORT      7778           // UDP port on the PC/HUB
#define LOCAL_PORT    7778           // UDP port this ESP listens on

// UART to the slave board (ESP32-S3)
#define UART_BAUD     250000
#define UART_RX_PIN   14             // ESP32-S3 RX  <- Slave TX
#define UART_TX_PIN   13             // ESP32-S3 TX  -> Slave RX
// =========================================================

WiFiUDP udp;
IPAddress hubIp = HUB_IP;

// Safe UDP payload size for typical LAN MTU
static const size_t UDP_BUF = 1472;
uint8_t rxBuf[UDP_BUF];

void connectWiFi() {
  WiFi.mode(WIFI_STA);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  Serial.print("WiFi: connecting to ");
  Serial.print(WIFI_SSID);
  Serial.println(" ...");

  uint32_t t0 = millis();
  while (WiFi.status() != WL_CONNECTED) {
    delay(250);
    Serial.print(".");
    if (millis() - t0 > 20000) {        // retry every ~20s
      Serial.println("\nWiFi: retrying...");
      WiFi.disconnect(true, true);
      delay(300);
      WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
      t0 = millis();
    }
  }
  Serial.print("\nWiFi: connected. IP = ");
  Serial.println(WiFi.localIP());
}

void setup() {
  Serial.begin(115200);                 // USB debug (optional)
  delay(200);
  Serial.println("\nESP32-S3 Master: UDP <-> UART bridge starting...");

  connectWiFi();

  if (!udp.begin(LOCAL_PORT)) {
    Serial.println("UDP: begin failed!");
  } else {
    Serial.print("UDP: listening on port ");
    Serial.println(LOCAL_PORT);
  }

  // Start UART1 to the slave
  Serial1.begin(UART_BAUD, SERIAL_8N1, UART_RX_PIN, UART_TX_PIN);
  Serial.println("UART1: started");
}

void forwardUdpToUart() {
  int packetSize = udp.parsePacket();
  if (packetSize <= 0) return;

  size_t len = udp.read(rxBuf, (packetSize > (int)UDP_BUF) ? UDP_BUF : packetSize);
  if (len > 0) {
    // PC/HUB -> (Master) -> Slave
    Serial1.write(rxBuf, len);
  }
}

void forwardUartToUdp() {
  static uint8_t txBuf[UDP_BUF];
  size_t n = 0;

  // Gather a bounded chunk to keep latency low
  while (Serial1.available() && n < UDP_BUF) {
    txBuf[n++] = (uint8_t)Serial1.read();
    if (n >= 256) break; // small packets reduce jitter
  }

  if (n > 0) {
    udp.beginPacket(hubIp, HUB_PORT);
    udp.write(txBuf, n);
    udp.endPacket();
  }
}

void loop() {
  // 1) Upstream (PC→ESP): UDP -> UART
  forwardUdpToUart();

  // 2) Downstream (ESP→PC): UART -> UDP
  forwardUartToUdp();

  // Add your local inputs/display handlers here if the master also has controls.
  // Example:
  // readInputsAndFormatMessages();
  // udpSend(...);
}

