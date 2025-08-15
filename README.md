# ARC-210 Radio Control Panel for DCS A-10C II

**Updated Aug 15 2025**

This project replicates the look and functionality of the ARC-210 radio (VHF/UHF) used in the A-10C II Warthog module for Digital Combat Simulator (DCS). It is intended for use with a physical control panel powered by an ESP32-S3 microcontroller.

🔗 [See the official DCS website](https://www.digitalcombatsimulator.com/en/) for the game.

## Features

- Realistic interface modeled after the ARC-210 radio
- Powered by two ESP32-S3-WROOM-1 N16R8 boards — uses USB or 5V supply
- ILI9488 3.5" SPI TFT display (480x320) — powered by the control board
- Support for digital rotary encoders, rotary switches, and momentary switches
- Optional WS2812 LEDs for backlighting
- DCSBIOS integration for in-game control and feedback
- Red screen when DCSBIOS link has not been activated
- RESET button resets both ESP32-S3 chips
- ESP32-S3 chips can be updated via WiFi

  *Note: Placing both Rotary Switches in postion 8 and holding the GPS button for 5 seconds will force a reboot launching the over the air upgrade - code will need to be changed by user - wifi_config.h will need to be configured by the user* 

## Hardware

- **Microcontroller:** ESP32-S3-WROOM-1 N16R8  
🔗 [Amazon] https://www.amazon.com/dp/B0DB1WK3CW?ref_=ppx_hzsearch_conn_dt_b_fed_asin_title_1

- **Display:** ILI9488 SPI TFT (3.5")  
🔗 [Amazon] https://www.amazon.com/dp/B0CKRJ81B5?ref_=ppx_hzsearch_conn_dt_b_fed_asin_title_2

- **Encoders:** Rotary encoders (x7)  
🔗 [Mouser Electronics] https://www.mouser.com/ProductDetail/652-PEC11H4215FS0024 - Stronger rotataion

🔗 [Mouser Electronics] https://www.mouser.com/ProductDetail/Bourns/PEC11R-4215F-S0024?qs=Zq5ylnUbLm5lAqmKF80wzQ%3D%3D - these are backordered until Nov 2025


- **Rotary Switches:** 8 Postion Rotary Switches (45 degree angle, with stop)

🔗 [Mouser Electronics] https://www.mouser.com/ProductDetail/611-A12503RNCQE


- **Faceplate:**  
🔗 [PC Flights] https://pcflights.com/a-10c-thunderbolt-warthog-vhf-uhf-panel/

- **LEDs:** Up to 50 WS2812 RGB LEDs

- **Optional:** Arduino Mega 2560 version also supported — code changes required for display output; pins need to be changed and the TFT_eSPI library used

## Software

- Written in Arduino C++
- Uses `ILI9488-ESP32S3.h` custom display driver

🔗 [download]https://github.com/dgdimick/ILI9488-ESP32S3-Fast  
  *Note: Do not use TFT_eSPI due to ESP32 compatibility issues*

## Directories

- `ARC-210/`: Main source code and sketches
- `ARC-210/PCBs/`: KiCad files and Gerbers for button board and ESP32-S3 control board
- `ARC-210/Firmware/`: INO source files
- `ARC-210/Docs/`: Schematics, diagrams, and images
- `ARC-210/Supporting STL's/`: 3D-printable parts such as knobs, bezels, brackets, and mounts

## New: Supporting STL's

The `Supporting STL's` directory includes:
- **Knobs** for rotary encoders and rotary switches
- **Mounting hardware** for the TFT screen and PCBs
- **Brackets** for panel alignment

All STLs are print-ready and designed for FDM printers with 0.4mm nozzles. SLA printers may require scaling adjustments.

## Licensing

This project is released under the MIT License. See `LICENSE.md` for details.
