# ARC-210 Radio Control Panel for DCS A-10C II

<p align="center">
  <img src="images/ARC-210-Face%20Plate.jpg" width="300" alt="ARC-210 Face Plate">
</p>

**Updated September 19, 2026**

I have some of the screens completed. Frequencies are being passed from DCS-BIOS, the boot screens are correct, and the boot timing is working properly. The **UNAVAILABLE** screen is also correct for the appropriate settings on the Frequency and Mode switches. The AM/FM display is now being developed and tested.

Here is a short video showing the progress I have made so far:

[ARC-210 Project Progress Video](https://drive.google.com/file/d/15TccQAfNhI_mp24V_y9ZMpBznJ80Qydf/view?usp=sharing)

I am looking for **beta testers** to help with screen layouts, placement of the lines, and font suggestions. If you have a **3.5-inch SPI TFT display** and a **Teensy 4.1** lying around, you have the basic hardware needed to beta test.

The `Teensy_TFT_Hello_Works.ino` file in the `Firmware` directory contains the correct display pin assignments and can be used to verify that your display is connected correctly.

The HEX file for the current state of the project is located in:

`Firmware/Master Hex Files/`

If you own a Teensy 4.1, you may already know how to install a HEX file. If not, here are the steps.

## Loading the HEX File onto a Teensy 4.1

1. Install and open **Teensy Loader**.
2. Open the supplied `Master_Program.ino.hex` file.
3. Connect the Teensy 4.1 to your computer by USB.
4. Press the button on the Teensy if it does not enter programming mode automatically.
5. Click **Program** in Teensy Loader.
6. Reboot the Teensy.

> **Note:** This repository is now included in the A-10-Sim repository.

This project replicates the look and functionality of the **ARC-210 VHF/UHF radio** used in the A-10C II Warthog module for Digital Combat Simulator (DCS).

It is intended for use with a physical control panel powered by a Teensy 4.1.

[See the official DCS website](https://www.digitalcombatsimulator.com/en/)

## Features

- Interface modeled after the ARC-210 radio
- Powered by one Teensy 4.1
- ILI9488 3.5-inch SPI TFT display (480 × 320)
- Support for digital rotary encoders, rotary switches, and momentary switches
- DCS-BIOS integration for in-game control and feedback
- ARC-210 startup and initialization screens
- Live frequency display from DCS-BIOS
- AM/FM modulation display
- UNAVAILABLE screen for the appropriate Frequency and Mode switch selections

## Tools Needed

- Soldering iron
- 3D printer, or access to one
- Flush wire cutters
- USB Micro-B cable for programming the Teensy 4.1 and connecting the unit to the computer

## Hardware

**Note:** This is intended to be a relatively simple design.

- **Microcontroller:** Teensy 4.1 without Ethernet  
  [SparkFun](https://www.sparkfun.com/teensy-4-1-without-ethernet.html)

- **Display:** ILI9488 SPI TFT, 3.5-inch  
  [Amazon](https://www.amazon.com/dp/B0CKRJ81B5?ref_=ppx_hzsearch_conn_dt_b_fed_asin_title_2)

- **Encoders:** Rotary encoders (x7)  
  [Mouser Electronics - PEC11H](https://www.mouser.com/ProductDetail/652-PEC11H4215FS0024) — stronger rotation torque  
  [Mouser Electronics - PEC11R](https://www.mouser.com/ProductDetail/Bourns/PEC11R-4215F-S0024?qs=Zq5ylnUbLm5lAqmKF80wzQ%3D%3D) — lighter rotation torque

- **Rotary switches:** 8-position rotary switches, 45-degree indexing with stop, SP8T  
  [Mouser Electronics](https://www.mouser.com/ProductDetail/611-A12503RNCQE)

- **SQL On/Off switch:** This part is a little clunky, but I selected it to help keep the project cost down.  
  [Home Depot](https://www.homedepot.com/p/Gardner-Bender-6-Amp-Single-Pole-Rotary-Switch-Brass-GSW-61/100095964)

- **Faceplate:** A-10C "Thunderbolt" / "Warthog" VHF/UHF cockpit panel  
  [PC Flights](https://pcflights.com/a-10c-thunderbolt-warthog-vhf-uhf-panel/)

- **Button switches:** 16 × 6 × 6 × 5 mm miniature momentary tactile push-button switches (SPST)  
 > **Note:** These switches may change as I continue developing the PCB. I was not satisfied with the first version.  
  [Amazon](https://www.amazon.com/dp/B01CGMP9GY?ref_=ppx_hzsearch_conn_dt_b_fed_asin_title_1)

- **Diodes:** 16 × 1N4148 small-signal fast-switching diodes, DO-35  
  These are optional; jumper wires may be used in their place where appropriate.  
  [Amazon](https://www.amazon.com/100-Pieces-1N4148-Switching-High-Speed/dp/B079KJ91JZ/ref=sr_1_1_sspa?s=industrial&sr=1-1-spons&sp_csd=d2lkZ2V0TmFtZT1zcF9hdGY)

## Software

- Written in Arduino C++
- Uses DCS-BIOS for communication with DCS
- Firmware and test files are maintained in this repository

## Directories

- `ARC-210/` — project root
- `ARC-210/Firmware/` — firmware and test files\n- `ARC-210/Firmware/Boot Loader/` — precompiled Teensy HEX files for loading with Teensy Loader or TyTools
- `ARC-210/Docs/` — schematics, diagrams, and documentation
- `ARC-210/images/` — project images
- `ARC-210/Supporting STL's/` — 3D-printable knobs, bezels, brackets, mounts, and other parts

## Supporting STL Files

The `Supporting STL's` directory includes:

- Knobs for rotary encoders and rotary switches
- Mounting hardware for the TFT screen and PCBs
- Brackets for panel alignment

All STL files are intended to be print-ready for FDM printers using a 0.4 mm nozzle. Resin/SLA printers may require different settings or scaling.

## Licensing

- **PCBs:** CERN Open Hardware Licence Version 2 - Permissive (CERN-OHL-P-2.0)
- **Teensy firmware:** MIT License
- **STL files:** Creative Commons Attribution 4.0 International (CC BY 4.0)

See the `Docs` directory for copies of the applicable licenses.
