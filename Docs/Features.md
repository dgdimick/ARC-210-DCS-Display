[Back to the main project README](../README.md)

# Features

**Last updated: October 31, 2026 at 12:39 AM MDT (America/Denver)**

- DCS-BIOS integration for in-game control and feedback
- I’ve modeled all buttons, switches, and the display after the ARC-210 radio. The **3.5" LCD display** recreates the startup and initialization screens and shows the live frequency and AM/FM modulation from DCS-BIOS.
- **Teensy 4.1: 600 MHz**, versus **Arduino Uno and Mega: 16 MHz**. [More details](Why-Teensy.md).
- All menus work except some of the deeper SAT menus, which I’m still working on.

- **Planned aircraft support, still in development:** I’m building a shared ARC-210 code base with automatic aircraft selection, so switching supported aircraft will not require reflashing the Teensy. See the [support plan](C-130J-Support.md).

**Button lighting:** The current Button Matrix PCB v3.2 does not support LED backlighting. I would need to redesign the button board and the associated power and driver circuitry to add it. I have no finished design or release date for this possible future feature; see the [power and lighting notes](Power-and-Lighting.md).
