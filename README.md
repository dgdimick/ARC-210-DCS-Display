# ARC-210 Radio Control Panel for DCS A-10C II

This project replicates the look and functionality of the ARC-210 radio used in the A-10C II Warthog module for Digital Combat Simulator (DCS). It is intended for use with a physical control panel powered by an ESP32-S3 microcontroller.

## Features

- Realistic interface modeled after the ARC-210 radio
- Powered by an ESP32-S3
- ILI9488 SPI TFT display (480x320)
- Support for rotary encoders and momentary switches
- Optional WS2812 LEDs for backlighting
- DCS-BIOS integration for in-game control and feedback

## Hardware

- **Microcontroller:** ESP32-S3
- **Display:** ILI9488 SPI TFT (3.5")
- **Encoders:** Rotary encoders (x9)
- **Switches:** 16 momentary buttons
- **LEDs:** Up to 50 WS2812 RGB LEDs
- **Optional:** Arduino Mega 2560 version also supported - some code changes will be required

## Software

- Written in Arduino C++
- Uses `ILI9488-ESP32S3.h` (custom display driver)
- No use of TFT_eSPI due to ESP32 compatibility issues
- LVGL optionally supported

## Directories

- `ARC-210/`: Main source code and sketches
- `ARC-210/PCBs/`: KiCad files and Gerbers for button boards and main panel
- `ARC-210/Firmware/`: Precompiled binaries (optional)
- `ARC-210/Docs/`: Schematics, diagrams, and images
- `ARC-210/Supporting STL's/`: 3D-printable parts such as knobs, bezels, brackets, and mounts

## New: Supporting STL's

The `Supporting STL's` directory includes:
- **Knobs** for rotary encoders
- **Button caps** for momentary switches
- **Mounting hardware** for the TFT screen and PCBs
- **Brackets** for panel alignment

All STLs are print-ready and designed for FDM printers with 0.4mm nozzles.

## Licensing

This project is released under the MIT License. See `LICENSE` for details.

---

Feel free to modify this README or ask for a version with badges, a table of contents, or install/setup instructions.
