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

## Features

[View the features](Docs/Features.md) for the hardware capabilities and planned firmware support.

## Items that need to be completed

[View the remaining work](Docs/Remaining-Work.md) for the testing, documentation, and design tasks still to complete.

## Teensy GPIO labels and KiCad pin numbers

[Read the Teensy GPIO and KiCad pin guide](Docs/Teensy-GPIO.md) before wiring the panel or working with the PCB files.

## Power and future button lighting

[Read the power and lighting notes](Docs/Power-and-Lighting.md) for USB power, the TFT supply, and future button-lighting requirements.

<a id="six-pcb-layout"></a>

## PCB layout — five or six boards

[View the PCB layout page](PCBs/PCB-Layout.md) for the mockup photo, board descriptions, and optional SQL On/Off direct-wiring details.

## Future Thoughts and Plans

[View Future Thoughts and Plans](Docs/Future-Thoughts.md) for possible redesigns, lighting, and support for other aircraft.

## Project updates

[Read the project updates](Docs/Project-Updates.md) for the dated development history, PCB progress, and testing milestones.

## Firmware and hardware testing

[View the firmware and hardware testing guide](Docs/Firmware-and-Hardware-Testing.md) for the DCS-BIOS preview, test HEX files, and test instructions.

## Loading the HEX File onto a Teensy 4.1

[Read the HEX loading instructions](Docs/Loading-HEX-Files.md) to program the Teensy 4.1.

## ARC-210 Bench Testing App

[View the ARC-210 Bench Testing App guide](Docs/Bench-Testing-App.md) to test the panel with simulated DCS-BIOS data without running DCS.

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

[Read why I chose the Teensy 4.1](Docs/Why-Teensy.md) for the GPIO requirements, display performance, programming workflow, and cost comparison.

## Directories

- `ARC-210/` — project root
- `ARC-210/Firmware/` — firmware and test files
- `ARC-210/Firmware/Boot Loader/` — precompiled Teensy HEX files for loading with Teensy Loader or TyTools
- [`parts/`](parts/) — component list, hardware supplier links, and compatibility notes
- `ARC-210/Docs/` — schematics, diagrams, and documentation
- `ARC-210/images/` — project images
- `ARC-210/Supporting STL's/` — 3D-printable knobs, bezels, brackets, mounts, and other parts

## Questions and community builds

This is primarily a DIY project, and the files and build notes are here to help you make your own panel. Parts can be purchased from the linked suppliers. If you get stuck, feel free to ask in Discussions—I’m happy to help where I can.

**Building your own panel, or just looking around?** [Introduce yourself in the welcome discussion](https://github.com/dgdimick/ARC-210-DCS-Display/discussions/1) and tell us what you fly. Questions, ideas, and progress photos are all welcome—even if you’re only getting started.

Visit [GitHub Discussions](https://github.com/dgdimick/ARC-210-DCS-Display/discussions) to ask questions, share ideas, post build photos, and connect with other builders. Whether you are planning your first panel or already flying with one, you are welcome to join in!

<a id="related-radio-project"></a>

## Related radio projects

[Explore the ARC-164 and ARC-186 radio projects](Docs/Related-Radio-Projects.md) for project updates and build plans.

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
