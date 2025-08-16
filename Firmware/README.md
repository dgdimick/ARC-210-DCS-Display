# ARC-210 Wi-Fi DCS-BIOS Bridge

This repository provides firmware for running **DCS-BIOS over Wi-Fi** using two ESP32-S3 boards:

- **Master ESP32-S3**: Bridges UDP packets from the PC running DCS-BIOS Hub to UART.
- **Slave ESP32-S3**: Handles your ARC-210 panel inputs (encoders, switches, display) and communicates with the master via UART.

---

## Repository Layout

```
ARC-210/
└── Firmware/
    ├── Master_WiFi_Udp_Bridge/
    │   ├── Master_WiFi_Udp_Bridge.ino
    │   └── wifi_config.h.example
    ├── Slave_UART_Node/
    │   └── Slave_UART_Node.ino
    └── .gitignore
```

---

## Master Sketch

Located at `Firmware/Master_WiFi_Udp_Bridge/Master_WiFi_Udp_Bridge.ino`.

This sketch:
- Connects the ESP32-S3 to your Wi-Fi network.
- Opens a UDP socket to communicate with the DCS-BIOS Hub running on your PC.
- Bridges messages between UDP (Hub) and UART (Slave ESP32-S3).

---

## Slave Sketch

Located at `Firmware/Slave_UART_Node/Slave_UART_Node.ino`.

This sketch:
- Listens for UART messages from the master.
- Processes your ARC-210 inputs (rotary encoders, switches, etc.).
- Sends formatted DCS-BIOS messages back via UART.

---

## Wi-Fi Configuration

Your real Wi-Fi credentials are kept private using a template file.

- Copy `wifi_config.h.example` → `wifi_config.h`.
- Enter your SSID and password in `wifi_config.h`.
- `.gitignore` ensures your real credentials are not committed to GitHub.

---

## Wiring

**PC/HUB** ←→ UDP :7778 ←→ **Master ESP32-S3** ←→ UART (GPIO13/14) ←→ **Slave ESP32-S3**

Wire connections:
- Master TX (GPIO 13) → Slave RX
- Master RX (GPIO 14) ← Slave TX
- GND ↔ GND
- 5V VIN or USB power

---

## Setup Instructions

1. Copy `Firmware/Master_WiFi_Udp_Bridge/wifi_config.h.example` → `wifi_config.h` and edit with your network credentials.
2. In `Master_WiFi_Udp_Bridge.ino`, set `HUB_IP` to your PC’s IP and `HUB_PORT` to your DCS-BIOS Hub UDP port.
3. Flash **Master_WiFi_Udp_Bridge** to the master ESP32-S3.
4. Flash **Slave_UART_Node** (or your ARC-210 sketch) to the slave ESP32-S3.
5. Connect UART wiring as described above.
6. In DCS-BIOS Hub, add a **Network/UDP device** pointing to the master’s IP on port `7778`.

---

## Power

- Power both boards from 5V USB or external 5V to VIN.
- Ensure grounds are common.
- Only one USB connection (master) is required during runtime.

---

## Notes

- Tested with **ESP32-S3 Dev Module** (Arduino).
- Baud rate: **250000** for UART.
- Safe UDP payload size: **1472 bytes**.
- For PlatformIO users, a `platformio.ini` can be added.

---
