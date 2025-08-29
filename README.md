# ARC-210 Radio Control Panel for DCS A-10C II

**Updated Aug 28 2025**

This project replicates the look and functionality of the ARC-210 radio (VHF/UHF) used in the A-10C II Warthog module for Digital Combat Simulator (DCS). It is intended for use with a physical control panel powered by an Teensy 4.1 board.

🔗 [See the official DCS website](https://www.digitalcombatsimulator.com/en/) for the game.

## Features

- Realistic interface modeled after the ARC-210 radio
- Powered by 1 Teenys 4.1 - 43 GPIO's are needed
- ILI9488 3.5" SPI TFT display (480x320) — powered by the control board
- Support for digital rotary encoders, rotary switches, and momentary switches
- DCSBIOS integration for in-game control and feedback
- Red screen when DCSBIOS link has not been activated

## Tools Needed

- Soldering Iron
- 3d Printer or access to one

## Hardware
**Note:** This is a simple design, no extra components are needed.


- **Micro controller:** Teensy 4.1 w/o Ethernet  

    🔗 [SparkFun] https://www.sparkfun.com/teensy-4-1-without-ethernet.html

- **Display:** ILI9488 SPI TFT (3.5")  
    🔗 [Amazon] https://www.amazon.com/dp/B0CKRJ81B5?ref_=ppx_hzsearch_conn_dt_b_fed_asin_title_2

- **Encoders:** Rotary encoders (x7)  
    🔗 [Mouser Electronics] https://www.mouser.com/ProductDetail/652-PEC11H4215FS0024 - Stronger rotation torque

    🔗 [Mouser Electronics] https://www.mouser.com/ProductDetail/Bourns/PEC11R-4215F-S0024?qs=Zq5ylnUbLm5lAqmKF80wzQ%3D%3D -  rotation torque is not as strong; these are back ordered until Nov 2025


- **Rotary Switches:** 8 Position Rotary Switches (45 degree angle, with stop SP8T) 

    🔗 [Mouser Electronics] https://www.mouser.com/ProductDetail/611-A12503RNCQE


- **Faceplate:** A 10C "Thunderbolt" / "Warthog" VHF / UHF Cockpit Panel

    🔗 [PC Flights] https://pcflights.com/a-10c-thunderbolt-warthog-vhf-uhf-panel/
- **Button Switches:** 16 6x6x5 mm Miniature Micro Momentary Tactile Push Button Switch (SPST)

    🔗 [Amazon] https://www.amazon.com/dp/B01CGMP9GY?ref_=ppx_hzsearch_conn_dt_b_fed_asin_title_1
- **Diodes:** 16 1N4148 Small Signal Fast Switching Diodes High-Speed Axial 200mA 100V DO-35 (DO-204AH) IN4148 Silicon Dodes;      these are optional, you will just need to replace diodes with jumper wires

    🔗 [Amazon] https://www.amazon.com/100-Pieces-1N4148-Switching-High-Speed/dp/B079KJ91JZ/ref=sr_1_1_sspa?s=industrial&sr=1-1-spons&sp_csd=d2lkZ2V0TmFtZT1zcF9hdGY


## Software

- Written in Arduino C++

## Directories

- `ARC-210/`: Main source code and sketches
- `ARC-210/PCBs/`: KiCad files and Gerbers for button board and ESP32-S3 control board
- `ARC-210/Firmware/`: INO source files
- `ARC-210/Docs/`: Schematics, diagrams, and images
- `ARC-210/Supporting STL's/`: 3D-printable parts such as knobs, bezels, brackets, and mounts

## New: Supporting STL's

`Supporting STL's` directory includes:
- **Knobs** for rotary encoders and rotary switches
- **Mounting hardware** for the TFT screen and PCBs
- **Brackets** for panel alignment

All STLs are print-ready and designed for FDM printers with 0.4mm nozzles. SLA printers may require scaling adjustments.

## Licensing

This project is released under the MIT License. See `LICENSE.md` for details.
