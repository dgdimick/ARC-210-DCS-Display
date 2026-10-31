# ARC-210 Radio Control Panel for DCS A-10C II using a 3.5" SPI TFT display and DCS-BIOS — October 30, 2026

**Last updated: October 30, 2026 at 11:55 PM MDT (America/Denver)**

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

**Last updated: October 30, 2026 at 11:44 PM MDT (America/Denver)**

[View the remaining work](Docs/Remaining-Work.md) for the testing, documentation, and design tasks still to complete.

## Tools needed

[View the tools needed](Docs/Tools-Needed.md) to build and program the panel.

## Future thoughts and plans

[View Future thoughts and plans](Docs/Future-Thoughts.md) for possible redesigns, lighting, and support for other aircraft.

## Project updates

**Last updated: October 30, 2026 at 11:51 PM MDT (America/Denver)**

**October 30, 2026 at 11:50 PM MDT — Updated estimated build cost: US$250–US$285**

My estimated parts cost is now **US$250–US$285, including the PC Flights faceplate**. All amounts are in **US dollars (USD)** and **exclude shipping, handling, tax, VAT, and other applicable fees**.

This estimate uses **US$41.10 for JLCPCB fabrication**: five copies of each of the four PCB designs, or **20 bare boards total**, with spare boards after building one panel. Supplier prices and final PCB quotes can change. This replaces the earlier US$120 PCB allowance and US$320–US$365 build estimate.

Using my **US$40 complete six-board bare-PCB set**, the estimated total parts cost is **US$249.52–US$282.52**, compared with **US$250.62–US$283.62** using JLCPCB. Both include the faceplate and use the same component estimates; either rounds to about **US$250–US$285** for budgeting. **Shipping, handling, tax, and VAT are separate**, as are any other applicable fees. All figures are in **US dollars (USD)**.

See the [parts-cost breakdown](parts/README.md#estimated-build-cost) and [JLCPCB cost comparison](Docs/PCB-Manufacturing-JLCPCB.md).

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

## Buy a complete set of bare PCBs

I offer a **complete six-board ARC-210 bare-PCB set for US$40, plus shipping, VAT, and any other applicable taxes, duties, or fees**. The set includes **one Main Board, one Button Matrix board, one Rotary Encoder board, and three Rotary Switch boards**, including the optional SQL On/Off board.

I’m offering this as a **convenient complete set for one radio**: you get the boards you need without managing four separate PCB design uploads or ordering the manufacturer’s minimum quantity of every design. **Any savings depend on your location, shipping, VAT, tariffs, and other applicable fees**, so compare the full delivered totals. I’m not promising that my set will always be cheaper than ordering directly. **You’ll supply the components and solder the boards yourself**; the price is for bare PCBs, not an assembled radio, electronics, faceplate, or printed parts. Assembled-board electrical testing is still pending.

[Contact me in GitHub Discussions](https://github.com/dgdimick/ARC-210-DCS-Display/discussions) to check availability and arrange a shipping quote. You can also [order the boards directly from JLCPCB](Docs/PCB-Manufacturing-JLCPCB.md) using the shared files.

## Firmware and hardware information

[Open Firmware and hardware information](Docs/Firmware-and-Hardware-Information.md) for wiring, power, PCB layout, parts, printable files, software, firmware loading, and testing guides.

## Project progress and beta testing

[View project progress and beta testing](Docs/Project-Progress-and-Beta-Testing.md) for the progress video and information on helping test the panel.

## Questions and community builds

**Planning a build, already working on one, or just looking around?** [Introduce yourself in the welcome discussion](https://github.com/dgdimick/ARC-210-DCS-Display/discussions/1) and tell me which panel interests you and what you fly. Questions, ideas, and progress photos are welcome—even if you haven’t started yet.

I’m sharing the files and build notes to help you make your own panel, with parts available from the linked suppliers. If you get stuck, ask in [GitHub Discussions](https://github.com/dgdimick/ARC-210-DCS-Display/discussions)—I’m happy to help where I can.

<a id="related-radio-project"></a>

## Related radio projects

I’m developing [C-130J ARC-210 support](Docs/C-130J-Support.md) here in the main project. The same ARC-210 hardware should work with both the **A-10C II and C-130J**, using the appropriate aircraft-specific firmware and DCS-BIOS mappings. C-130J operation still needs to be implemented and tested.

[Explore the ARC-164 and ARC-186 projects and planned C-130J ARC-210 support](Docs/Related-Radio-Projects.md) for project updates and build plans.

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
