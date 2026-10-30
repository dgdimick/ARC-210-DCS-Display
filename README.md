# ARC-210 Radio Control Panel for DCS A-10C II using a 3.5" SPI TFT display and DCS-BIOS

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

**Last updated: October 30, 2026 at 3:15 AM MDT (America/Denver)**

[View the remaining work](Docs/Remaining-Work.md) for the testing, documentation, and design tasks still to complete.

## Tools needed

[View the tools needed](Docs/Tools-Needed.md) to build and program the panel.

## Future thoughts and plans

[View Future thoughts and plans](Docs/Future-Thoughts.md) for possible redesigns, lighting, and support for other aircraft.

## Project updates

**Last updated: October 30, 2026 at 3:25 AM MDT (America/Denver)**

**October 30, 2026 at 3:25 AM MDT — Button Matrix v3.2 manufacturing release**

Button Matrix **v3.2** now has matching PCB silkscreen, board revision, and schematic revision. The duplicate SQL clearance-hole outline is removed, leaving the intended **12.0 mm non-plated hole**. H3’s reference label was moved clear of the solder-mask opening. There are no electrical changes.

The [v3.2 Gerber/drill ZIP](PCBs/Button%20Matrix/Manufacturing/Button-Matrix-PCB-v3.2-Gerbers-Drill.zip) was freshly generated with KiCad 10.0.7. ERC and DRC report **zero violations, zero unconnected items, and zero schematic/PCB mismatches** under saved settings. Drill checks confirm 130 plated holes and five non-plated holes. These fresh exports and checks supersede the targeted correction’s verification limitation described below. Use v3.2 for future orders; the existing JLCPCB order still needs its separate engineering confirmation. Manufactured-board assembly and electrical testing remain pending.

[Read all project updates](Docs/Project-Updates.md) for the full dated development history.

## Separate USB connections for each radio

The **ARC-210, ARC-164, and ARC-186 will each use a dedicated Teensy 4.1 with its own USB connection to DCS-BIOS**. Three USB connections are manageable, and each radio can be built, tested, updated, and troubleshot independently.

RS-485 can reduce USB ports and COM-port connections when many cockpit panels share a communication bus, but it adds transceiver hardware, bus wiring, termination, addressing, and a master interface. For these three radios, separate USB connections keep assembly and setup simpler. **USB remains the planned connection for each radio.**

**RS-485 would normally use three GPIO pins per controller: hardware-serial TX, RX, and a transmit/receive direction-control pin. USB uses no header GPIO pins, leaving those connections available for controls and displays.** On a Teensy 4.1, that means 42 readily accessible I/O pins remain available with USB, compared with 39 after allocating three pins to RS-485, before accounting for the panel's other connections.

**One Teensy can also run multiple smaller panels through a single USB connection**, provided their combined pin count, processing needs, and power requirements fit within the controller's limits. Nearby panels can share a controller when the wiring is practical, so future expansion does not require a separate USB connection for every panel. The current radio plan remains unchanged: the ARC-210, ARC-164, and ARC-186 will each have their own dedicated Teensy 4.1.

## Firmware and hardware information

[Open Firmware and hardware information](Docs/Firmware-and-Hardware-Information.md) for wiring, power, PCB layout, parts, printable files, software, firmware loading, and testing guides.

## Project progress and beta testing

[View project progress and beta testing](Docs/Project-Progress-and-Beta-Testing.md) for the progress video and information on helping test the panel.

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
