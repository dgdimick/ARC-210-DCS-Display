[Back to the main project README](../README.md)

# Features

- DCS-BIOS integration for in-game control and feedback
- Interface modeled after the ARC-210 radio
- Powered by one **Teensy 4.1 at 600 MHz**, compared with **16 MHz** for the classic **Arduino Uno R3 and Mega 2560** — **37.5 times the CPU clock frequency**. See the [controller comparison](Why-Teensy.md) for details; clock frequency is not a direct measure of display refresh speed.
- ILI9488 3.5-inch SPI TFT display (480 × 320)
- All digital rotary encoders, rotary switches, and momentary switches are supported and working in the hardware tests.
- ARC-210 startup and initialization screens
- Live frequency display from DCS-BIOS
- AM/FM modulation display
- Submenus nested within the SAT menus will be available with firmware 2.0.
