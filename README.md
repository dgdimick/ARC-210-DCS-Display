# ARC-210 Radio Control Panel for DCS A-10C II using a 3.5" SPI TFT display and DCS-BIOS — October 31, 2026

**Last updated: October 31, 2026 at 12:52 AM MDT (America/Denver)**

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

**Last updated: October 31, 2026 at 12:22 AM MDT (America/Denver)**

[View the remaining work](Docs/Remaining-Work.md) for the testing, documentation, and design tasks still to complete.

## Tools needed

[View the tools needed](Docs/Tools-Needed.md) to build and program the panel.

## Future thoughts and plans

[View Future thoughts and plans](Docs/Future-Thoughts.md) for possible redesigns, lighting, and support for other aircraft.

**The current Button Matrix PCB v3.2 does not support LED backlighting.** I would need to redesign it and the Main Board, possibly using four-layer PCBs that cost more. My aim is to reuse the encoders, rotary switches, socket-mounted Teensy, and faceplate, subject to compatibility checks. I have no finished design, confirmed upgrade price, or release date. Upgrade costs are separate from the current estimates and PCB set price. See [Future Thoughts](Docs/Future-Thoughts.md) for the details.

## Project updates

**Last updated: October 31, 2026 at 12:20 AM MDT (America/Denver)**

**October 31, 2026 at 12:20 AM MDT — v0.1.1 preview adds firmware and aircraft startup labels**

I’ve built **v0.1.1 Preview** with **VERSION 0.1.1 PREVIEW** and **AIRCRAFT: A-10C2** on the radio-switch startup information screen. The labels come from one shared firmware definition, and the release filename matches. C-130J support and automatic aircraft selection are still being developed; this preview does not add them.

Compilation and font-layout checks passed. **Physical-panel and in-DCS testing of this build are still pending.** The existing startup timing and powered-radio requirement remain. I’ve kept v0.1.0 available for rollback and included the source used for the new build.

Download the [v0.1.1 preview](Firmware/Master%20Hex%20Files/ARC210_A-10C2_v0.1.1_Preview.hex) and read the [firmware notes](Firmware/Master%20Hex%20Files/README.md).

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

## Estimated total build cost

I’m distressed by the total cost of this project, and I worry it may put the build beyond some people’s budgets. I want to be open about that so you can decide whether it fits your budget before buying parts. Considering the controls, display, and functionality the panel is designed to provide, I still feel it’s worth the cost.

I’ve spent about two months working on the code, averaging four hours a night—roughly **240 hours**. I’m sharing the source code for free so other builders don’t have to do all that development work themselves. The parts still cost money, but I hope the time and effort this saves helps make the project worthwhile.

My PCBs are designed around the faceplate and layout I’m using, so they may not fit someone else’s custom panel. I’m sharing the [source code](Firmware/Source/Master_Program/README.md) so other builders can reuse it or adapt it to their own controls, displays, and wiring. Some changes may be needed, but I hope it gives people a useful starting point and saves them development time.

I’ve also spent about **US$500 on extra parts during development**. Buying more parts as I work toward a finished project adds up. That is my development expense; it is not an extra charge to builders or part of the estimated cost to build one panel. I’m still very happy to share this project with others. We all enjoy adding to our SIMPITs, no matter how big or small they are.

One thing I’m very pleased about is that I’m developing the same ARC-210 panel hardware for every aircraft I’ve planned to support, including the A-10C II and C-130J. I’m designing a shared code base that will automatically use the appropriate controls and display data for the aircraft you’re flying, so you won’t need to reflash the Teensy when switching between supported aircraft—just fly the aircraft. **This automatic aircraft support is still being developed and tested; it is not a completed feature yet.** Aircraft-specific DCS-BIOS mappings will be handled within that shared setup.

I’ll label radio HEX downloads with the aircraft they support and a version number, increasing the version whenever I publish updated firmware so you can tell releases apart. Each new aircraft-support release will retain support for the previously supported aircraft. Adding an aircraft will require loading the updated HEX once, using the same Teensy Loader procedure as the first flash while the panel is connected by USB. After that, switching between aircraft included in that version will not require reflashing. **This cumulative aircraft support and automatic selection are still being developed and tested.**

Both options include the PC Flights faceplate and use the same component estimates. **All amounts are in US dollars (USD).**

| PCB purchasing option | PCB cost (USD) | Estimated total parts cost (USD) |
| --- | ---: | ---: |
| JLCPCB: five copies of each of four designs (20 bare boards, including spares) | US$41.10 | US$250.62–US$283.62 |
| My complete six-board bare-PCB set for one radio | US$40.00 | US$249.52–US$282.52 |

**Shipping, handling, tax, and VAT are separate and are not included in either total.** Tariffs, duties, and other applicable fees are also extra. These are estimates rather than fixed kit prices; either option rounds to about **US$250–US$285** for budgeting. Tools, labor, and cockpit mounting fasteners are excluded.

See the [parts-cost breakdown](parts/README.md#estimated-build-cost) for component prices and allowances, and the [PCB manufacturing guide](Docs/PCB-Manufacturing-JLCPCB.md) for quote details. Compare the full delivered totals for your location.

## Buy a complete set of bare PCBs

I offer a **complete six-board ARC-210 bare-PCB set for US$40, plus shipping, handling, tax, VAT, and any other applicable tariffs, duties, or fees**. The set includes **one Main Board, one Button Matrix board, one Rotary Encoder board, and three Rotary Switch boards**, including the optional SQL On/Off board.

I’m offering this as a **convenient complete set for one radio**: you get the boards you need without managing four separate PCB design uploads or ordering the manufacturer’s minimum quantity of every design. **Any savings depend on your location, shipping, handling, tax, VAT, tariffs, and other applicable fees**, so compare the full delivered totals. I’m not promising that my set will always be cheaper than ordering directly. **You’ll supply the components and solder the boards yourself**; the price is for bare PCBs, not an assembled radio, electronics, faceplate, or printed parts. Assembled-board electrical testing is still pending.

[Contact me in GitHub Discussions](https://github.com/dgdimick/ARC-210-DCS-Display/discussions) to check availability and arrange a shipping quote. You can also [order the boards directly from JLCPCB](Docs/PCB-Manufacturing-JLCPCB.md) using the shared files.

## Firmware and hardware information

[Open Firmware and hardware information](Docs/Firmware-and-Hardware-Information.md) for wiring, power, PCB layout, parts, printable files, software, firmware loading, and testing guides.

## Project progress and beta testing

[View project progress and beta testing](Docs/Project-Progress-and-Beta-Testing.md) for the progress video and information on helping test the panel.

## Sharing code and improvements

My main firmware code is shared under the [MIT License](Docs/LICENSE-MIT.txt), and I’m happy to provide it to anyone who asks. You can also find the [published source here](Firmware/Source/Master_Program/README.md). If you adapt it or add improvements, I’d love to work with you and bring useful changes back into this project so other builders—and my other panel projects—can benefit too.

Please share your changes through a pull request or get in touch in [Discussions](https://github.com/dgdimick/ARC-210-DCS-Display/discussions). Contributing changes back is welcome, but it isn’t an extra condition of the MIT License. Third-party code keeps its own license.

## Questions and community builds

**Planning a build, already working on one, or just looking around?** [Introduce yourself in the welcome discussion](https://github.com/dgdimick/ARC-210-DCS-Display/discussions/1) and tell me which panel interests you and what you fly. Questions, ideas, and progress photos are welcome—even if you haven’t started yet.

I’m sharing the files and build notes to help you make your own panel, with parts available from the linked suppliers. If you get stuck, ask in [GitHub Discussions](https://github.com/dgdimick/ARC-210-DCS-Display/discussions)—I’m happy to help where I can.

I welcome bug reports from anyone using the project—**even tiny bugs are worth reporting**. If something doesn’t work as expected, please let me know in [Issues](https://github.com/dgdimick/ARC-210-DCS-Display/issues) or [Discussions](https://github.com/dgdimick/ARC-210-DCS-Display/discussions). Tell me which firmware version and board revision you’re using, if applicable, what you did, what you expected, and what happened. Reports about the build instructions are welcome too. Your reports help me improve the project for everyone.

<a id="related-radio-project"></a>

## Related radio projects

My current plan is to finish the **A-10C II (A-10C2) ARC-210 implementation**, then build and test the **ARC-164**, followed by the **ARC-186**. After those projects, I’ll return to additional aircraft support, starting with the **ARC-210 and C-130J**. Those aircraft extensions are later work, not the current implementation priority. I’m focusing on aircraft with a matching physical radio panel. **This order may change based on user feedback and interest.**

I’m developing [C-130J ARC-210 support](Docs/C-130J-Support.md) here in the main project. The same ARC-210 hardware should work with both the **A-10C II and C-130J**, through a shared code base with automatic aircraft selection and aircraft-specific DCS-BIOS mappings, without reflashing the Teensy when switching aircraft. This support, including C-130J operation, still needs to be implemented and tested.

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
