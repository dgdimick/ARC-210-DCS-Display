# ARC-210 Radio Control Panel for DCS A-10C II using a 3.5" TFT SPI display and DCSBIOS

This project is an ARC-210 radio control panel for the DCS A-10C II using a Teensy 4.1, an ILI9488 TFT display,
and DCS-BIOS for live radio data and cockpit control.

<p align="center">
  <img src="images/ARC-210-Face%20Plate.jpg" width="300" alt="ARC-210 Face Plate">
</p>

**Updated September 25, 2026 — Parts list and menu-system preview**

The current HEX is available for testing the ARC-210 menu screens and navigation, including the HQ, COMSEC, and RADIO SETTINGS menus. This is a menu-system preview, not a finished radio implementation: some menu actions and synchronization still need work.

The current `Master_Program.ino.hex` works with DCS-BIOS while running DCS, but it is **display-only at this time**. It displays radio information from the game; physical panel controls do not yet operate the in-game radio.

The HQ MORE loop and detail screens are implemented. LOAD WOD has been tested against DCS: the displayed number matches, follows MLSK changes, and resets to 20 on re-entry in the tested session. MENU exits from the opening screen listing HQ MENUS / COMSEC / RADIO SETTINGS and is inactive on deeper pages.

Download [Master_Program.ino.hex](Firmware/Master%20Hex%20Files/Master_Program.ino.hex). Read the [preview notes and required DCS-BIOS export changes](Firmware/Master%20Hex%20Files/README.md) before testing. The display starts blank until it receives powered-radio data from DCS-BIOS.

Here is a short video showing the progress I have made so far:

[ARC-210 Project Progress Video](https://drive.google.com/file/d/15TccQAfNhI_mp24V_y9ZMpBznJ80Qydf/view?usp=sharing)

I am looking for **beta testers** to help with screen layouts, placement of the lines, and font suggestions. If you have a **3.5-inch SPI TFT display** and a **Teensy 4.1** lying around, you have the basic hardware needed to beta test.

The `Teensy_TFT_Hello_Works.ino` file in the `Firmware` directory contains the correct display pin assignments and can be used to verify that your display is connected correctly.

The HEX file for the current state of the project is located in:

`Firmware/Master Hex Files/`

If you own a Teensy 4.1, you may already know how to install a HEX file. If not, here are the steps.

## Loading the HEX File onto a Teensy 4.1

1. Install and open **Teensy Loader, you can find it in the firmware directory**.
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
- **Planned button support:** All panel buttons will be wired, and their in-game functions will be supported wherever DCS-BIOS provides the necessary controls. The current HEX remains display-only.
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

## Why I had to use a Teensy

The ARC-210 panel needs a lot of GPIO (general-purpose input/output) pins. It is not just driving a display: the same controller also has to read the knobs and switches, scan the buttons, and control the lighting.

- Each rotary encoder needs two input pins to detect movement and direction.
- The 16 push buttons use a 4 × 4 matrix, which still needs eight GPIO pins for its rows and columns.
- The rotary-switch resistor ladders need analog inputs, and the squelch switch needs another input.
- The SPI TFT needs clock and data connections plus control signals for chip select, reset, and data/command selection.
- The display backlight and panel lighting need their own control outputs.

These connections add up quickly. I chose the Teensy 4.1 because it gives this design enough pins to connect the controls and display directly, without adding GPIO expanders or another controller. Using one controller for both PCBs also keeps the wiring and firmware easier to manage.

### Could I have used several Arduinos?

Yes. I could have split the buttons and switches onto one Arduino, the rotary encoders onto another, and the TFT onto a controller with enough processing speed and memory for the display. Depending on the DCS-BIOS connection setup, the boards could use separate USB connections or communicate through a main controller.

That would provide more GPIO, but it would also mean more wiring, connections, and separate firmware to maintain. Splitting the controls across boards would not increase the memory or processing speed of the board driving the TFT. An Uno or Mega would still have its own display limitations.

I chose the Teensy 4.1 because it combines the GPIO, processing speed, and memory needed for this design on one board. Several Arduinos were an option; one Teensy keeps this build simpler.

The standard processor clock speeds are:

| Board | CPU clock speed |
| --- | ---: |
| [Teensy 4.1](https://www.pjrc.com/store/teensy41.html) | **600 MHz** |
| [Arduino Uno R3](https://docs.arduino.cc/hardware/uno-rev3/) | **16 MHz** |
| [Arduino Mega 2560 Rev3](https://docs.arduino.cc/hardware/mega-2560/) | **16 MHz** |

The Teensy 4.1 has **37.5 times the CPU clock frequency** of these classic Arduino boards. That is a clock-speed comparison, not a measured 37.5-times improvement in screen refresh rate; processor architecture, memory, SPI speed, and the display code also affect the result.

Display response speed was another major factor in my choice. Compared with classic Arduino Uno and Mega boards, the Teensy 4.1 provides much more processing headroom for drawing the TFT while handling radio updates and controls. I would not expect those older boards to deliver the same screen response with this display and firmware. Actual refresh speed also depends on the SPI connection, display library, and drawing code; this comparison is not a claim about every Arduino model.

### The same Arduino programming workflow

The Teensy is programmed using the same **Arduino IDE** and **`.ino` sketches** used for Arduino boards. The familiar editor, C++ sketch structure, and `setup()` / `loop()` workflow remain the same, so there is no need to learn a different programming environment for this project.

Install [Teensy board support](https://www.pjrc.com/teensy/td_download.html) and select Teensy 4.1 in the IDE. [Teensy Loader](https://www.pjrc.com/teensy/loader.html) handles uploading the compiled firmware and is integrated with the Arduino upload workflow. To use the precompiled `Master_Program.ino.hex` supplied here, simply open it in Teensy Loader and program the board; you do not need to compile the sketch yourself.

The programming workflow is familiar, although pin assignments and hardware-specific libraries still need to match the Teensy rather than an Uno or Mega.

### Cost: one Teensy versus three Arduinos

For a board-only comparison, these US-dollar prices were checked on September 24, 2026:

| Option | Price per board | Quantity | Total |
| --- | ---: | ---: | ---: |
| [Teensy 4.1 without Ethernet — SparkFun](https://www.sparkfun.com/teensy-4-1-without-ethernet.html) | $29.60 | 1 | **$29.60** |
| [Official Arduino Uno R3 — Arduino US store](https://store-usa.arduino.cc/products/arduino-uno-rev3) | $27.60 | 3 | **$82.80** |

At those listed prices, one Teensy costs **$53.20 less** than three official Uno R3 boards, before tax, shipping, cables, headers, or other accessories. Lower-cost Arduino-compatible boards can change the comparison substantially. This is an illustrative cost comparison, not a claim that three Unos would run the current display firmware or provide equivalent screen performance. Prices may change.

![Teensy 4.1 schematic showing the panel connections](Docs/Why%20I%20used%20a%20Teensy.png)

The numbers around this schematic symbol are KiCad pad numbers; use the signal labels and the project wiring documentation to identify the corresponding Teensy GPIO pins.

## Two-PCB layout

The build uses two PCBs controlled by one Teensy 4.1:

- **Master PCB:** carries the Teensy, power circuitry, and display and control connections.
- **Front-panel PCB:** carries the push-button switches and panel LEDs behind the faceplate and connects to the master PCB.

The front-panel PCB does not require a second microcontroller. The board layouts and connections are still being developed.

## Parts

See the [parts directory](parts/) for the [component list (BOM)](parts/BOM.csv), hardware supplier links, and switch-fit and compatibility notes.

## Software

- Written in Arduino C++
- Uses DCS-BIOS for communication with DCS
- Firmware and test files are maintained in this repository

## ARC-210 Bench Testing App

The [working ARC-210 version of dcsBiosDebug](https://github.com/dgdimick/dcsBiosDebug/tree/arc210-working) is maintained in a separate repository. It provides buttons for menu testing and separate Frequency, Secondary, and Master controls for sending simulated DCS-BIOS data to your Teensy without running DCS.

Download the **arc210-working** branch using **Code → Download ZIP**, extract it, and keep its `icons` folder beside the Python script. With Python 3 and Tkinter installed, open a terminal in that folder and run:

```cmd
python -m pip install numpy pyserial Pillow
python dcsBiosDebug.py
```

Use the Python script, including the `.py` extension; the original bundled executable does not include the ARC-210 controls. Select your Teensy's serial port and click **Connect**. Choose **2 - TR** and click **Set Master** for the normal radio switch position, or **0 - OFF** to test power off.

See the [full testing instructions and compatibility notes](https://github.com/dgdimick/dcsBiosDebug/blob/arc210-working/ARC210_TESTING.md). The shortcuts use fixed A-10C II addresses and send data to the hardware, not commands to DCS. Some firmware states require additional exports through the normal instrument controls.

## Directories

- `ARC-210/` — project root
- `ARC-210/Firmware/` — firmware and test files\n- `ARC-210/Firmware/Boot Loader/` — precompiled Teensy HEX files for loading with Teensy Loader or TyTools
- [`parts/`](parts/) — component list, hardware supplier links, and compatibility notes
- `ARC-210/Docs/` — schematics, diagrams, and documentation
- `ARC-210/images/` — project images
- `ARC-210/Supporting STL's/` — 3D-printable knobs, bezels, brackets, mounts, and other parts

## Supporting STL Files

The `Supporting STL's` directory includes:

- Knobs for rotary encoders and rotary switches
- Mounting hardware for the TFT screen and PCBs
- Brackets for panel alignment

All STL files are intended to be print-ready for FDM printers using a 0.4 mm nozzle. Resin/SLA printers may require different settings or scaling.

## PC Flights affiliation

I am not affiliated with PC Flights in any way. I simply chose to use their panels for my own cockpit projects.

## Licensing

- **PCBs:** CERN Open Hardware Licence Version 2 - Permissive (CERN-OHL-P-2.0)
- **Teensy firmware:** MIT License
- **STL files:** Creative Commons Attribution 4.0 International (CC BY 4.0)

See the `Docs` directory for copies of the applicable licenses.
