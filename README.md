# ARC-210 Radio Control Panel for DCS A-10C II

This project replicates the look and functionality of the ARC-210 radio used in the A-10C II Warthog module for Digital Combat Simulator (DCS). It is intended for use with a physical control panel powered by an ESP32-S3 microcontroller. https://www.digitalcombatsimulator.com/en/
## Features

- Realistic interface modeled after the ARC-210 radio
- Powered by an two ESP32-S3-WROOM-1 N16R8
- ILI9488 SPI TFT display (480x320) - I'm using the 3.5 inch display
- Support for rotary encoders and momentary switches
- Optional WS2812 LEDs for backlighting
- DCS-BIOS integration for in-game control and feedback

## Hardware

- **Microcontroller:** ESP32-S3-WROOM-1 N16R8 
    https://www.amazon.com/dp/B0DB1WK3CW?ref_=ppx_hzsearch_conn_dt_b_fed_asin_title_1
- **Display:** ILI9488 SPI TFT (3.5") 
    https://www.amazon.com/dp/B0CKRJ81B5?ref_=ppx_hzsearch_conn_dt_b_fed_asin_title_2
- **Encoders:** Rotary encoders (x9) https://www.mouser.com/ProductDetail/652-PEC11H4220KS0024 - code will change if I can source the correct switches for the modes (1 Pole 8 Positions Rotary Switch 45 degrees angle of throw)
- **Faceplate:** https://pcflights.com/a-10c-thunderbolt-warthog-vhf-uhf-panel/ 
- **LEDs:** Up to 50 WS2812 RGB LEDs
- **Optional:** Arduino Mega 2560 version also supported - code changes will be required for display output; pins need to be changed and TFT_eSPI library will needed be used

## Software

- Written in Arduino C++
- Uses `ILI9488-ESP32S3.h` (custom display driver) don't use of TFT_eSPI due to ESP32 compatibility issues

## Directories

- `ARC-210/`: Main source code and sketches
- `ARC-210/PCBs/`: KiCad files and Gerbers for button board and ESP32-S3 Control board
- `ARC-210/Firmware/`: INO source files
- `ARC-210/Docs/`: Schematics, diagrams, and images
- `ARC-210/Supporting STL's/`: 3D-printable parts such as knobs, bezels, brackets, and mounts

## New: Supporting STL's

The `Supporting STL's` directory includes:
- **Knobs** for rotary encoders
- **Mounting hardware** for the TFT screen and PCBs
- **Brackets** for panel alignment

All STLs are print-ready and designed for FDM printers with 0.4mm nozzles; SLA printers may have to adjust the print sizes

## Licensing

This project is released under the MIT License. See `LICENSE.md` for details.

---

