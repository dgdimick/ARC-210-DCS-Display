# ARC-210 Radio Control Panel for DCS A-10C II using a 3.5" SPI TFT display and DCS-BIOS — October 30, 2026

**Last updated: October 30, 2026 at 9:15 PM MDT (America/Denver)**

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

**Last updated: October 30, 2026 at 9:15 PM MDT (America/Denver)**

[View the remaining work](Docs/Remaining-Work.md) for the testing, documentation, and design tasks still to complete.

## Tools needed

[View the tools needed](Docs/Tools-Needed.md) to build and program the panel.

## Future thoughts and plans

[View Future thoughts and plans](Docs/Future-Thoughts.md) for possible redesigns, lighting, and support for other aircraft.

## Project updates

**Last updated: October 30, 2026 at 9:15 PM MDT (America/Denver)**

**October 30, 2026 at 8:25 PM MDT — Final 17-part STL set; all parts printed and test-fitted at 100%**

The complete master [STL](Supporting%20STL%27s/ARC-210-Complete-Print-Set-All-17.stl) and [3MF](Supporting%20STL%27s/ARC-210-Complete-Print-Set-All-17.3mf) contain **17 parts**: **5 Frequency knobs v10.1, 2 Mode knobs v4, 1 Channel knob v4.1, 1 SQL knob v1.2, 1 display bracket v5, 6 encoder spacers v1, and 1 SQL shaft spacer v5**. The Channel and SQL knobs are the same knob design.

**I have printed the complete 17-part layout at 100% scale, and every part passed test fitting. I consider these current STL designs final.** Print one complete set at **100% scale**; no additional scaling is needed with the current hardware.

See the [STL instructions](Supporting%20STL%27s/README.md#complete-17-part-print-set) for individual downloads, the nine-knob-only layout, and slicing guidance. Please keep checking [Project Updates](Docs/Project-Updates.md) for changes.

[Read all project updates](Docs/Project-Updates.md) for the full dated development history.

## My SIMPIT and test computer

[View my SIMPIT and test computer](Docs/My-SIMPIT-and-Test-Computer.md) for my computer configuration, monitors, and current USB setup. **This describes my own development and flight-simulation setup, not minimum requirements for the radio panels.**

## USB connections and powered hubs

[Read about the USB connection plan and purchased powered hubs](Docs/USB-Connections-and-Powered-Hubs.md) for why I am using USB instead of RS-485;<br>
GPIO availability, sharing a Teensy across smaller panels, and expansion using my existing cockpit USB setup.

I also own three other SIMPIT panels that use USB. I have used them for over **1,000 hours in the past year without any issues**.

## DCS-BIOS

[My step-by-step setup guide](Docs/DCS-BIOS.md) covers installation, file changes, and TekConnect—the app I use to manage my connections.

- [Patched A-10C.lua](https://raw.githubusercontent.com/dgdimick/ARC-210-DCS-Display/master/Docs/DCS-BIOS/A-10C.lua) — ARC-210 changes included; for **DCS-BIOS v0.11.8**.
- [DCS-BIOS-only Export.lua](https://raw.githubusercontent.com/dgdimick/ARC-210-DCS-Display/master/Docs/DCS-BIOS/DCS-BIOS-only/Export.lua) — for setups without WWT or SRS.

Follow the guide before replacing files.

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
