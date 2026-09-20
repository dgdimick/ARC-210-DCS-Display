# ARC-210 Radio Control Panel for DCS A-10C II

**Updated Sept 19th 2026**

I have some of the screens done, the Freq's are being passed from DCSBIOS,
the boot screens are correct, timing was a pain to get correct, and the
UNAVILABLE screen is correct for the appropriate setting on the Freq and Mode
switches. The AM/FM display. 
Here's a short video showing the progress I have made so far.
https://drive.google.com/file/d/15TccQAfNhI_mp24V_y9ZMpBznJ80Qydf/view?usp=sharing

I am looking for BETA Tester to help with the screen layouts, placement of the
lines and even if you have a better font to suggest. If you have a 3.5" TFT SPI display
and a Teensy 4.1 laying around you have all the tools needed to BETA Test. 
The Teensy_TFT_Hello_Works .ino file in the Firmware has the correct pins you'll need to
test if you have the correct pins locations to get you started, and the Hex for the current
state of the project are located in the Firmware/Maser Hex Files sub directory.

I assume if you own a teensy 4.1 you know how to install a HEX file, however, here are the steps

To load the HEX file onto a Teensy 4.1:

1. Install/open Teensy Loader.
2. Open the supplied Master_Program.ino.hex file.
3. Connect the Teensy 4.1 by USB.
4. Press the button on the Teensy if it does not enter program mode automatically.
5. Click Program in Teensy Loader.
6. Reboot the Teensy.


**Note:** This repository is now included in the A-10-Sim repository.

This project replicates the look and functionality of the ARC-210 radio (VHF/UHF)
used in the A-10C II Warthog module for Digital Combat Simulator (DCS).
It is intended for use with a physical control panel powered by an Teensy 4.1 board.

🔗 [See the official DCS website](https://www.digitalcombatsimulator.com/en/) for the game.

## Features

- Realistic interface modeled after the ARC-210 radio
- Powered by 1 Teenys 4.1
- ILI9488 3.5" SPI TFT display (480x320) — powered by the control board
- Support for digital rotary encoders, rotary switches, and momentary switches
- DCSBIOS integration for in-game control and feedback
- Red screen when DCSBIOS link has not been activated

## Tools Needed

- Soldering Iron
- 3d Printer or access to one
- Wire Cutters (Flush)
- USB micro cable, used to program the Teensy 4.1 board and connect the unit to your computer via DCSBIOS

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

- **SQL On/Off Switch:** Sorry is it's a bit clunky, I tried to keep the cost down for the project

🔗 [Home Depot]  https://www.homedepot.com/p/Gardner-Bender-6-Amp-Single-Pole-Rotary-Switch-Brass-GSW-61/100095964

- **Faceplate:** A 10C "Thunderbolt" / "Warthog" VHF / UHF Cockpit Panel

    🔗 [PC Flights] https://pcflights.com/a-10c-thunderbolt-warthog-vhf-uhf-panel/
- **Button Switches:** 16 6x6x5 mm Miniature Micro Momentary Tactile Push Button Switch (SPST)
- **NOTE:** These switches will probably change as I develop the PCB, I didn't like the first one I built

    🔗 [Amazon] https://www.amazon.com/dp/B01CGMP9GY?ref_=ppx_hzsearch_conn_dt_b_fed_asin_title_1
- **Diodes:** 16 1N4148 Small Signal Fast Switching Diodes High-Speed Axial 200mA 100V DO-35 (DO-204AH) IN4148 Silicon Dodes;      these are optional, you will just need to replace diodes with jumper wires

    🔗 [Amazon] https://www.amazon.com/100-Pieces-1N4148-Switching-High-Speed/dp/B079KJ91JZ/ref=sr_1_1_sspa?s=industrial&sr=1-1-spons&sp_csd=d2lkZ2V0TmFtZT1zcF9hdGY


## Software

- Written in Arduino C++
- Source available on request.

## Directories

- `ARC-210/`: 
- `ARC-210/Firmware/`: .hex files
- `ARC-210/Docs/`: Schematics, diagrams, and images
- `ARC-210/Supporting STL's/`: 3D-printable parts such as knobs, bezels, brackets, and mounts

## New: Supporting STL's

`Supporting STL's` directory includes:
- **Knobs** for rotary encoders and rotary switches
- **Mounting hardware** for the TFT screen and PCBs
- **Brackets** for panel alignment

All STLs are print-ready and designed for FDM printers with 0.4mm nozzles. SLA printers may require scaling adjustments.

## Licensing

- **The PCB's are under the CERN Open Hardware Licence Version 2 - Permissive (CERN-OHL-P-2.0)
- **The Teensy Frimware are under the MIT Licence
- **The STL's are under the Creative Commons Attributiion 4.0 International 

See the Docs Directory for a copy of the each licence.