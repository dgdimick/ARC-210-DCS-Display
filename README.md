# ARC-210 Radio Control Panel for DCS A-10C II using a 3.5" SPI TFT display and DCS-BIOS — November 7, 2026

**Last updated: November 7, 2026 at 2:55 PM MST (America/Denver)**

I’m building a working ARC-210 radio panel for the DCS A-10C II using a Teensy 4.1, a 3.5-inch ILI9488 TFT display, custom PCBs, and 3D-printed parts, with DCS-BIOS for live radio data and cockpit control. I’m sharing the files and what I learn along the way so you can build your own.

**Frequency controls:** I use **rotary encoders** for the frequency controls in this build, rather than the **ten-position rotary switches used in the real ARC-210**. **For Version 2, I plan to replace those encoders with rotary switches and a new frequency-control PCB, while trying to reuse the existing Main Board.** See [Future thoughts and plans](Docs/Future-Thoughts.md) for the planned redesign; there is no release date yet.

## Current testing status

**The panel is now working connected to DCS.** [Watch the demonstration video](https://drive.google.com/file/d/1jLG8JLaTQ1RpAE6FKkDZAUxiwgUSQEKu/view?usp=drivesdk). I’m still waiting for the manufactured PCBs, expected by the end of November 2026; assembly and electrical testing of those boards are still to come.

**Assembly testing:** Use the [Final Hardware Test](Firmware/Test%20Code/ARC210_Button_Test/README.md). The individual TFT, button, encoder, and switch tests are optional troubleshooting tools; you don’t need to run them during normal assembly.

**What to expect before radio data arrives:**

- **v0.1.3 Diagnostic HEX:** The display stays on the splash screen while waiting for radio data. This is expected and does not mean the Teensy has frozen.
- **v0.1.2 Preview HEX:** The display stays blank until DCS-BIOS sends powered-radio data.

<p align="center">
  <img src="images/ARC-210-Face%20Plate.jpg" width="300" alt="ARC-210 Face Plate">
</p>

[See the official DCS website](https://www.digitalcombatsimulator.com/en/)

> **Note:** This repository is now included in the [A-10-Sim repository](https://github.com/dgdimick/A-10-Sim).

## Features

[View the features](Docs/Features.md) for the hardware capabilities and planned firmware support.

## Items that need to be completed

**Last updated: November 3, 2026 at 12:42 AM MST (America/Denver)**

[View the remaining work](Docs/Remaining-Work.md) for the testing, documentation, and design tasks still to complete.

**SQL On/Off:** I use the **C&K A12515RNZQ solder-lug rotary switch**, with its stop ring set to **two positions for 45° total travel**. Align the knob with the panel’s ON/OFF markings. See the [parts list](parts/README.md) for shaft-length and mounting details.

## Tools needed

[View the tools needed](Docs/Tools-Needed.md) to build and program the panel.

## Future thoughts and plans

**Future upgrades:** It may be as long as **two years** before I return to this project with upgrades or a new version. Please treat future-version ideas as long-term plans, with no promised release date.

[View Future thoughts and plans](Docs/Future-Thoughts.md) for possible redesigns, lighting, and support for other aircraft.

**The current Button Matrix PCB v3.2 does not support LED backlighting.** My Version 2 plan is a new frequency rotary-switch PCB, a new Button LED PCB, and a daughterboard for external regulated 5 V lighting power and control. The existing Main Board has enough suitable J4 connections for five rotary-switch resistor ladders and two backlight PWM controls; the proposed pin assignment is in [Future Thoughts](Docs/Future-Thoughts.md#proposed-reuse-of-the-existing-main-board). Reusing it still requires new control and lighting boards, updated wiring and firmware, and assembly testing. **Version 2 is a long way off, so please don't wait for it if you want to build the ARC-210.** I have no finished redesign, confirmed upgrade price, or release date. See [Future Thoughts](Docs/Future-Thoughts.md) for the details.

## Project updates

**Last updated: November 6, 2026 at 1:37 PM MST (America/Denver)**

**November 6, 2026 — ARC-210 connected to DCS**

[Watch the ARC-210 panel working with DCS](https://drive.google.com/file/d/1jLG8JLaTQ1RpAE6FKkDZAUxiwgUSQEKu/view?usp=drivesdk). This video shows my panel connected to DCS and working with the simulator.

I’m still waiting for the manufactured PCBs, which are **expected by the end of November 2026**. Once they arrive, I’ll assemble and test the boards; this demonstration does not yet validate the manufactured PCB assembly.

**November marks 16 months of work on this project.** It’s great to see the panel working with DCS after all that development and testing!

**November 1, 2026 at 5:44 AM MST — Use the US$58.20 PCB cart estimate**

I’m using **US$58.20** for the JLCPCB order in my build budget: **US$41.10 fabrication + US$32.10 estimated shipping − a US$15.00 coupon**. This is for five copies of each of the four designs, or 20 bare boards. Shipping shown in that cart is included; coupon availability, shipping, and any additional duties or fees can vary. I did not submit or pay for an order.

The panel parts estimate, including the faceplate, is now **US$267.72–US$300.72**, or about **US$268–US$301**. Delivery for other components and any additional applicable fees remain separate. See the [current quote breakdown](Docs/PCB-Manufacturing-JLCPCB.md#uploaded-file-checkout-estimate--november-1-2026) and [parts list](parts/README.md#estimated-build-cost).

[Read all project updates](Docs/Project-Updates.md) for the full dated development history.

<a id="buy-a-complete-set-of-bare-pcbs"></a>

## Bare PCB offer

I can provide **bare PCBs only**, not a kit of electronic components or an assembled panel. See my [ARC-210 bare PCB offer](Docs/ARC-210-Parts-Offers.md#bare-pcb-set) for the boards included, availability, shipping, and fees. **These offers are for the ARC-210 only; ARC-164 and ARC-186 sets are not available yet.** If you request them with my ARC-210 PCB set, I’ll include the complete 3D-printed parts set free of charge. Shipping and handling remain separate.

## No access to a 3D printer?

I offer separate 3D-printing help for builders who can’t build the panel because they don’t have access to a 3D printer. This supplies printed plastic only, not electronic components or a complete kit; buy the other components separately. See [ARC-210 3D-printing help](Docs/ARC-210-Parts-Offers.md#printed-parts) for the current price, PETG colors, availability, shipping, VAT, and import-charge details.

## My SIMPIT and test computer

[View my SIMPIT and test computer](Docs/My-SIMPIT-and-Test-Computer.md) for my computer configuration, monitors, and current USB setup.

## USB connections and powered hubs

[Read about the USB connection plan and purchased powered hubs](Docs/USB-Connections-and-Powered-Hubs.md) for why I am using USB instead of RS-485.

I also own three other SIMPIT panels that use USB. I have used them for over **1,000 hours in the past year without any issues**.

## DCS-BIOS

[My step-by-step setup guide](Docs/DCS-BIOS.md) covers installation, file changes, and TekConnect—the app I use to manage my connections.

- [Patched A-10C.lua](https://raw.githubusercontent.com/dgdimick/ARC-210-DCS-Display/master/Docs/DCS-BIOS/A-10C.lua) — ARC-210 changes included; for **DCS-BIOS v0.11.8**.
- [DCS-BIOS-only Export.lua](https://raw.githubusercontent.com/dgdimick/ARC-210-DCS-Display/master/Docs/DCS-BIOS/DCS-BIOS-only/Export.lua) — for setups without WWT or SRS.

Follow the guide before replacing files.

## [Estimated total build cost](parts/README.md#estimated-total-build-cost)

## [Why I used a Teensy](Docs/Why-Teensy.md)

## Firmware and hardware information

[Firmware and hardware information](Docs/Firmware-and-Hardware-Information.md) for wiring, power, PCB layout, parts, printable files, software, firmware loading, and testing guides.

## Project progress and beta testing

[View project progress and beta testing](Docs/Project-Progress-and-Beta-Testing.md) for the progress video and information on helping test the panel.

## [Sharing code and improvements](Firmware/README.md)

## Questions and community builds

If you’d like to build an ARC-210 but aren’t able to assemble it yourself, get in touch through [Discussions](https://github.com/dgdimick/ARC-210-DCS-Display/discussions). I’d be happy to talk about your situation and see how I can help.

**Planning a build, already working on one, or just looking around?** [Introduce yourself in the welcome discussion](https://github.com/dgdimick/ARC-210-DCS-Display/discussions/1) and tell me which panel interests you and what you fly. Questions, ideas, and progress photos are welcome—even if you haven’t started yet.

I’m sharing the files and build notes to help you make your own panel, with parts available from the linked suppliers. If you get stuck, ask in [GitHub Discussions](https://github.com/dgdimick/ARC-210-DCS-Display/discussions)—I’m happy to help where I can.

If you’re local to me in **New Mexico, USA**, I’d be happy to meet up and provide whatever help I can with your SIMPIT. Get in touch through [Discussions](https://github.com/dgdimick/ARC-210-DCS-Display/discussions) so we can talk about your build and arrange a time.

I welcome bug reports from anyone using the project—**even tiny bugs are worth reporting**. If something doesn’t work as expected, please let me know in the [Bugs discussion section](https://github.com/dgdimick/ARC-210-DCS-Display/discussions/categories/bugs). Tell me which firmware version and board revision you’re using, if applicable, what you did, what you expected, and what happened. Reports about the build instructions are welcome too. Your reports help me improve the project for everyone.

<a id="related-radio-project"></a>

## Related radio projects

I’m finishing the A-10C II ARC-210 first, then the ARC-164 and ARC-186, before returning to additional aircraft support. [My development priorities](Docs/Related-Radio-Projects.md) may change based on feedback and interest.

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

---

[**My Mission Statement — Why I Build and Share These Projects**](https://github.com/dgdimick/A-10-Sim/blob/master/Mission-Statement.md)
