# ARC-210 Radio Control Panel for DCS A-10C II using a 3.5" TFT SPI display and DCSBIOS

I’m building a working ARC-210 radio panel for the DCS A-10C II using a Teensy 4.1, a 3.5-inch ILI9488 TFT display, custom PCBs, and 3D-printed parts, with DCS-BIOS for live radio data and cockpit control. I’m sharing the files and what I learn along the way so you can build your own.

> **Disclaimer:** This hobby flight-simulation project is provided without warranty, subject to its licenses. Read the [full disclaimer](#disclaimer) before building or using it.

<p align="center">
  <img src="images/ARC-210-Face%20Plate.jpg" width="300" alt="ARC-210 Face Plate">
</p>

This project replicates the look and functionality of the **ARC-210 VHF/UHF radio** used in the A-10C II Warthog module for Digital Combat Simulator (DCS).

It is intended for use with a physical control panel powered by a Teensy 4.1.

[See the official DCS website](https://www.digitalcombatsimulator.com/en/)

> **Note:** This repository is now included in the A-10-Sim repository.

<a id="related-radio-project"></a>

## Related radio projects

[Explore the ARC-164 and ARC-186 radio projects](Docs/Related-Radio-Projects.md) for project updates and build plans.

## Questions and community builds

This is primarily a DIY project, and the files and build notes are here to help you make your own panel. Parts can be purchased from the linked suppliers. If you get stuck, feel free to ask in Discussions—I’m happy to help where I can.

**Building your own panel, or just looking around?** [Introduce yourself in the welcome discussion](https://github.com/dgdimick/ARC-210-DCS-Display/discussions/1) and tell us what you fly. Questions, ideas, and progress photos are all welcome—even if you’re only getting started.

Visit [GitHub Discussions](https://github.com/dgdimick/ARC-210-DCS-Display/discussions) to ask questions, share ideas, post build photos, and connect with other builders. Whether you are planning your first panel or already flying with one, you are welcome to join in!

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
- Submenus nested within the SAT menus will be available with firmware 2.0.

## Teensy GPIO labels and KiCad pin numbers

**Use the numbers printed on the Teensy (or the matching GPIO labels on your breakout adapter) when following the firmware and wiring instructions.** KiCad uses a separate set of pin/pad numbers for the Teensy symbol and its matching `teensy:Teensy41` footprint. These include power and ground connections, so they are not the same as GPIO numbers.

| Teensy printed label / firmware GPIO | KiCad U1 pin / footprint pad |
| --- | ---: |
| GND (one of several ground connections) | 1 |
| 0 | 2 |
| 4 — TFT backlight | 6 |
| 14 / A0 — rotary-switch input | 36 |
| 15 / A1 — rotary-switch input | 37 |

For example, connect a rotary-switch signal to the Teensy connection marked **14/A0**, which is **KiCad pad 36**—not pad 14. In KiCad, read the symbol’s pin name and net label to identify the signal. Updating the PCB from the schematic with the matching symbol and footprint maps the connections to the correct physical locations. This pad mapping applies to the Teensy library supplied with this project; other libraries may use different numbering.

## Power and future button lighting

The painted buttons supplied with the PC Flights panel used for this build are opaque: light will not pass through them, so LEDs behind them would not illuminate their legends. Future backlighting would also require suitable light-transmitting replacement buttons.

The Teensy is powered by USB, and **TFT VCC connects directly to the Teensy's 3.3 V rail** (`TEENSY_3V3`, U1 pad 15). TFT brightness at 3.3 V has been confirmed satisfactory. The external protected 5 V input and Main Board JP1 power selector have been removed. C5 (470 µF) and C6 (0.1 µF) have been removed to match the tested direct Teensy-to-TFT wiring. C1/C2 and R1/R2 remain as the rotary-input filters. Keep total external 3.3 V consumption within PJRC's recommended 250 mA maximum; brightness confirmation is not a current measurement.

Future button lighting would require a separate power and driver design, suitable light-transmitting buttons, and a new Button LED PCB. The current Main Board has no external lighting-power circuit. This lighting revision is not currently planned; the other radio projects remain the priority.

<a id="six-pcb-layout"></a>

## PCB layout — five or six boards

[View the PCB layout page](PCBs/PCB-Layout.md) for the mockup photo, board descriptions, and optional SQL On/Off direct-wiring details.

## Items that need to be completed

[View the remaining work](Docs/Remaining-Work.md) for the testing, documentation, and design tasks still to complete.

## Future Thoughts and Plans

[View Future Thoughts and Plans](Docs/Future-Thoughts.md) for possible redesigns, lighting, and support for other aircraft.

## Project updates

[Read the project updates](Docs/Project-Updates.md) for the dated development history, PCB progress, and testing milestones.

## Firmware and hardware testing

### DCS-BIOS firmware preview

The current HEX is available for testing the ARC-210 menu screens and navigation, including the HQ, COMSEC, and RADIO SETTINGS menus. This is a menu-system preview, not a finished radio implementation: some menu actions and synchronization still need work.

The current `Master_Program.ino.hex` works with DCS-BIOS while running DCS, but it is **display-only at this time**. It displays radio information from the game; physical panel controls do not yet operate the in-game radio.

The HQ MORE loop and detail screens are implemented. LOAD WOD has been tested against DCS: the displayed number matches, follows MLSK changes, and resets to 20 on re-entry in the tested session. MENU exits from the opening screen listing HQ MENUS / COMSEC / RADIO SETTINGS and is inactive on deeper pages.

Download [Master_Program.ino.hex](Firmware/Master%20Hex%20Files/Master_Program.ino.hex). Read the [preview notes and required DCS-BIOS export changes](Firmware/Master%20Hex%20Files/README.md) before testing. The display starts blank until it receives powered-radio data from DCS-BIOS.

### Rotary encoder test HEX download

Download [ARC210_Encoder_Check_Teensy41.hex](Firmware/Test%20Code/ARC210_Encoder_Check_Teensy41.hex) for standalone testing of all six rotary encoders on a Teensy 4.1. The TFT displays each encoder's raw count, direction, and A/B input states. DCS is not required, and the backlight stays fully on using Teensy pin 4.

**Start with the TFT hello test** so you know the display is working before checking the encoders. A working TFT is required to see the results. If the screen stays blank, check the wiring notes and feel free to ask for help in Discussions. See the [test instructions](Firmware/Test%20Code/README.md) and [pin layout](Docs/ARC-210%20Teensy%204.1%20Pin%20layout.txt). Loading this HEX replaces the firmware currently on the Teensy.

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

## ARC-210 Bench Testing App

The [working ARC-210 version of dcsBiosDebug](https://github.com/dgdimick/dcsBiosDebug/tree/arc210-working) is maintained in a separate repository. It provides buttons for menu testing and separate Frequency, Secondary, and Master controls for sending simulated DCS-BIOS data to your Teensy without running DCS.

Download the **arc210-working** branch using **Code → Download ZIP**, extract it, and keep its `icons` folder beside the Python script. With Python 3 and Tkinter installed, open a terminal in that folder and run:

```cmd
python -m pip install numpy pyserial Pillow
python dcsBiosDebug.py
```

Use the Python script, including the `.py` extension; the original bundled executable does not include the ARC-210 controls. Select your Teensy's serial port and click **Connect**. Choose **2 - TR** and click **Set Master** for the normal radio switch position, or **0 - OFF** to test power off.

See the [full testing instructions and compatibility notes](https://github.com/dgdimick/dcsBiosDebug/blob/arc210-working/ARC210_TESTING.md). The shortcuts use fixed A-10C II addresses and send data to the hardware, not commands to DCS. Some firmware states require additional exports through the normal instrument controls.

## Project progress and beta testing

Here is a short video showing the progress I have made so far:

[ARC-210 Project Progress Video](https://drive.google.com/file/d/162CAG3RlfPK6QnCSb0p5lkmVlXDZjPrU/view)

Want to help test the project? If you have a **Teensy 4.1** and a compatible **3.5-inch SPI TFT display**, I’d welcome your feedback on the menus, screen layouts, and fonts. Share what you find in [Discussions](https://github.com/dgdimick/ARC-210-DCS-Display/discussions).

The `Teensy_TFT_Hello_Works.ino` file in the `Firmware` directory contains the correct display pin assignments and can be used to verify that your display is connected correctly.

## Tools Needed

- Hot glue gun, or an electronics-grade, neutral-cure silicone adhesive such as **MG Chemicals 1035**, for securing wires and the TFT display
- Soldering iron
- 3D printer, or access to one
- Flush wire cutters
- USB Micro-B cable for programming the Teensy 4.1 and connecting the unit to the computer

## Build guide

Start with the [step-by-step build guide](Docs/Build%20Guide/README.md) for parts, printing, PCB assembly, wiring, and hardware testing. Unfinished design and validation steps are marked **pending**.

## Parts

See the [parts directory](parts/) for the [component list (BOM)](parts/BOM.csv), hardware supplier links, and switch-fit and compatibility notes.

## Supporting STL Files

The `Supporting STL's` directory includes:

- Knobs for rotary encoders and rotary switches
- Mounting hardware for the TFT screen and PCBs
- Brackets for panel alignment

The [shaft spacer v.5](Supporting%20STL%27s/Shaft_Spacer_v.5.stl) is **required in all installations** to support the **longer SQL On/Off switch shaft**, whether using the optional switch PCB or wiring directly to the switch’s solder lugs.

Print **six [Rotary Encoder spacers v.1](Supporting%20STL%27s/Rotary_Encoder_Spacer_v.1.stl)**, one for each encoder, to center the encoder threads in the faceplate holes.

All STL files are intended to be print-ready for FDM printers using a 0.4 mm nozzle. Resin/SLA printers may require different settings or scaling.

## Software

- Written in Arduino C++
- Uses DCS-BIOS for communication with DCS
- Firmware and test files are maintained in this repository

## Why I had to use a Teensy

The ARC-210 panel needs a lot of GPIO (general-purpose input/output) pins. It is not just driving a display: the same controller also has to read the knobs and switches, scan the buttons, and control the TFT backlight.

- Each rotary encoder needs two input pins to detect movement and direction.
- The 16 push buttons use a 4 × 4 matrix, which still needs eight GPIO pins for its rows and columns.
- The rotary-switch resistor ladders need analog inputs, and the squelch switch needs another input.
- The SPI TFT needs clock and data connections plus control signals for chip select, reset, and data/command selection.
- The TFT display backlight needs a control output.

These connections add up quickly. I chose the Teensy 4.1 because it gives this design enough pins to connect the controls and display directly, without adding GPIO expanders or another controller. Using one controller for the five- or six-board build also keeps the wiring and firmware easier to manage.

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

## Directories

- `ARC-210/` — project root
- `ARC-210/Firmware/` — firmware and test files
- `ARC-210/Firmware/Boot Loader/` — precompiled Teensy HEX files for loading with Teensy Loader or TyTools
- [`parts/`](parts/) — component list, hardware supplier links, and compatibility notes
- `ARC-210/Docs/` — schematics, diagrams, and documentation
- `ARC-210/images/` — project images
- `ARC-210/Supporting STL's/` — 3D-printable knobs, bezels, brackets, mounts, and other parts

## PC Flights affiliation

I am not affiliated with [PC Flights](https://pcflights.com/) in any way. I simply chose to use their panels for my own cockpit projects. PC Flights has supplied me with a drawing file to assist with the Button PCB layout.

## Disclaimer

This is a hobby flight-simulation project, not equipment intended for use in real aircraft. Software, firmware, PCB designs, wiring information, and printable parts are provided "as is," without warranty, subject to their respective licenses.

Users are responsible for verifying compatibility, wiring, supply voltages, assembly, and safe operation before use. To the maximum extent permitted by applicable law, the authors and contributors disclaim liability for injury, equipment damage, data loss, or other losses arising from use of this project.

## Licensing

- **PCBs:** CERN Open Hardware Licence Version 2 - Permissive (CERN-OHL-P-2.0)
- **Teensy firmware:** MIT License
- **STL files:** Creative Commons Attribution 4.0 International (CC BY 4.0)

See the `Docs` directory for copies of the applicable licenses.
