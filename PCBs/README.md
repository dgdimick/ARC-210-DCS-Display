# ARC-210 PCBs

**Last updated: October 31, 2026 at 12:41 AM MDT (America/Denver)**

Updated October 29, 2026.

## Buy a complete set of bare PCBs

I offer a **complete six-board ARC-210 bare-PCB set for US$40, plus shipping, handling, tax, VAT, and any other applicable tariffs, duties, or fees**. It includes **one Main Board, one Button Matrix board, one Rotary Encoder board, and three Rotary Switch boards**, including the optional SQL On/Off board.

I’m offering this as a **convenient complete set for one radio**: you get the boards you need without managing four separate PCB design uploads or ordering the manufacturer’s minimum quantity of every design. **Any savings depend on your location, shipping, handling, tax, VAT, tariffs, and other applicable fees**, so compare the full delivered totals. I’m not promising that my set will always be cheaper than ordering directly.

These are bare boards for you to populate and solder. Components, the faceplate, printed parts, and assembly are not included; assembled-board electrical testing is still pending. [Contact me in Discussions](https://github.com/dgdimick/ARC-210-DCS-Display/discussions) to check availability and shipping. You can also [order directly from JLCPCB](../Docs/PCB-Manufacturing-JLCPCB.md) using the manufacturing downloads below.

## Estimated total build cost

I’m distressed by the total cost of this project, and I worry it may put the build beyond some people’s budgets. I want to be open about that so you can decide whether it fits your budget before buying parts. Considering the controls, display, and functionality the panel is designed to provide, I still feel it’s worth the cost.

I’ve spent about two months working on the code, averaging four hours a night—roughly **240 hours**. I’m sharing the source code for free so other builders don’t have to do all that development work themselves. The parts still cost money, but I hope the time and effort this saves helps make the project worthwhile.

My PCBs are designed around the faceplate and layout I’m using, so they may not fit someone else’s custom panel. I’m sharing the [source code](../Firmware/Source/Master_Program/README.md) so other builders can reuse it or adapt it to their own controls, displays, and wiring. Some changes may be needed, but I hope it gives people a useful starting point and saves them development time.

I’ve also spent about **US$500 on extra parts during development**. Buying more parts as I work toward a finished project adds up. That is my development expense; it is not an extra charge to builders or part of the estimated cost to build one panel. I’m still very happy to share this project with others. We all enjoy adding to our SIMPITs, no matter how big or small they are.

One thing I’m very pleased about is that I’m developing the same ARC-210 panel hardware for every aircraft I’ve planned to support, including the A-10C II and C-130J. I’m designing a shared code base that will automatically use the appropriate controls and display data for the aircraft you’re flying, so you won’t need to reflash the Teensy when switching between supported aircraft—just fly the aircraft. **This automatic aircraft support is still being developed and tested; it is not a completed feature yet.** Aircraft-specific DCS-BIOS mappings will be handled within that shared setup.

I’ll label radio HEX downloads with the aircraft they support and a version number, increasing the version whenever I publish updated firmware so you can tell releases apart. Each new aircraft-support release will retain support for the previously supported aircraft. Adding an aircraft will require loading the updated HEX once, using the same Teensy Loader procedure as the first flash while the panel is connected by USB. After that, switching between aircraft included in that version will not require reflashing. **This cumulative aircraft support and automatic selection are still being developed and tested.**

Here are both PCB purchasing options using the same component estimates. These totals cover the panel’s parts, including the PC Flights faceplate, rather than just the bare boards. **All amounts are in US dollars (USD).**

| PCB purchasing option | PCB cost (USD) | Estimated total parts cost (USD) |
| --- | ---: | ---: |
| JLCPCB: five copies of each of four designs (20 bare boards, including spares) | US$41.10 | US$250.62–US$283.62 |
| My complete six-board bare-PCB set for one radio | US$40.00 | US$249.52–US$282.52 |

**Shipping, handling, tax, and VAT are separate and are not included in either total.** Tariffs, duties, and other applicable fees are also extra. These are estimates rather than fixed kit prices; either option rounds to about **US$250–US$285** for budgeting. Tools, labor, and cockpit mounting fasteners are excluded.

See the [parts-cost breakdown](../parts/README.md#estimated-build-cost) for component prices and allowances, and the [PCB manufacturing guide](../Docs/PCB-Manufacturing-JLCPCB.md) for the JLCPCB quote details. Compare the full delivered totals for your location before choosing how to buy the boards.

## PCB layout — five or six boards

The panel uses **five required PCBs**: one Main Board, one Button Matrix, one Rotary Encoder, and two multi-position Rotary Switch boards, all controlled by one Teensy 4.1. The **optional SQL On/Off PCB brings the total to six**; it can be omitted when wiring directly to the switch’s solder lugs. The SQL board uses the same Rotary Switch PCB design.

The [shaft spacer v.5](../Supporting%20STL%27s/Shaft_Spacer_v.5.stl) is **required in all installations** to support the longer SQL On/Off switch shaft, whether or not the optional PCB is fitted.

I’ve checked the physical fit of all four PCB designs, including the Button Matrix alignment:

| PCB | Final version | Status |
| --- | --- | --- |
| [Main Board](Master%20Board/) | 1.1 | Physical fit confirmed October 29, 2026; manufactured-board assembly and electrical testing pending |
| [Button Matrix](Button%20Matrix/) | 3.2 | Final design; v3.1 physical test fit and button alignment confirmed |
| [Rotary Encoders](Rotary%20Encoders/) | 1.4 | Final design; test fit confirmed |
| [Rotary Switches](Rotary%20Switches/) | 2.0 | Final design; test fit confirmed |

Use the KiCad project files in each linked folder. Each folder includes its wiring and assembly notes.

I’ve confirmed the mechanical fit of these designs. Testing an assembled, manufactured PCB is still on my list. Each project’s README explains the electrical checks and hardware tests completed so far.

## Required Rotary Encoder spacers

Print **six [Rotary Encoder spacers v.1](../Supporting%20STL%27s/Rotary_Encoder_Spacer_v.1.stl)**, one for each encoder, to center the encoder threads in the faceplate holes.

## Gerber and drill downloads

**Ordering for the first time?** My [JLCPCB manufacturing guide](../Docs/PCB-Manufacturing-JLCPCB.md) walks through ordering the bare boards from the manufacturer I use, including quantities, settings, and preview checks.

Button Matrix v3.2 manufacturing files generated October 30, 2026; other control-board files generated October 27, 2026; Main Board v1.1 files updated October 29, 2026:

| PCB | Version | Gerber and drill ZIP | Individual files and reports |
| --- | --- | --- | --- |
| Main Board | 1.1 | [Download ZIP](Master%20Board/Manufacturing/Main-Board-PCB-v1.1-Gerbers-Drill.zip) | [Browse files](Master%20Board/Manufacturing/) |
| Button Matrix | 3.2 | [Download ZIP](Button%20Matrix/Manufacturing/Button-Matrix-PCB-v3.2-Gerbers-Drill.zip) | [Browse files](Button%20Matrix/Manufacturing/) |
| Rotary Encoders | 1.4 | [Download ZIP](Rotary%20Encoders/Manufacturing/Rotary-Encoder-PCB-v1.4-Gerbers-Drill.zip) | [Browse files](Rotary%20Encoders/Manufacturing/) |
| Rotary Switches | 2.0 | [Download ZIP](Rotary%20Switches/Manufacturing/Rotary-Switch-PCB-v2.0-Gerbers-Drill.zip) | [Browse files](Rotary%20Switches/Manufacturing/) |

Each ZIP includes copper, solder-mask, silkscreen, and board-outline Gerbers, a Gerber job file, separate plated/non-plated Excellon drill files, a drill report, and manufacturing notes. Drill maps and ERC/DRC reports are available in each manufacturing folder.

Review the manufacturer's preview before ordering. The Button Matrix's printed fit check confirmed button alignment, and its slightly long edges were shortened for final v3.1. Manufactured-board testing remains pending for all four designs. Existing check exclusions and disabled categories are documented in the individual project READMEs and reports.

## Button Matrix PCB — version 3.2

**The current Button Matrix PCB v3.2 does not support LED backlighting.** I would need to redesign the button board with LED support, use suitable light-transmitting buttons, and make the required Main Board, power, and driver changes. I may revisit this after completing the ARC-164 and ARC-186 projects; there is no finished backlit button-board design or release date yet. See [Future Thoughts](../Docs/Future-Thoughts.md) for the lighting redesign plan.

**October 30, 2026:** v3.2 removes the duplicate SQL hole outline, retains the 12 mm NPTH, updates revision markings, and moves H3’s reference clear of the mask opening. Fresh KiCad exports and ERC/DRC checks pass under saved settings. No electrical changes; manufactured-board testing remains pending. The v3.1 notes below record the earlier outline and physical-fit work.

**Final design; v3.1 test fit confirmed — October 27, 2026:** The printed fit check confirmed that the buttons are correctly positioned. The slightly long board edges were shortened, and version **3.1** replaced v3.0 before the v3.2 hole correction. The physical test fit of the revised v3.1 board is confirmed. The updated KiCad and manufacturing files are uploaded.

The current unlit 16-button, 4 × 4 Button Matrix PCB is **version 3.2**. See the [Button Matrix README](Button%20Matrix/README.md) for front and back layout previews. The front carries the push-button switches; the back carries the matrix diodes and row/column connectors. A 12 mm pass-through provides clearance for the SQL On/Off switch.

The downloadable [version 3.2 KiCad files](Button%20Matrix/) now include the PCB layout, schematic, project settings, and custom 12 mm footprint library. The PCB includes routing; unused floating copper fills were removed. Checks found zero ERC violations, zero DRC errors, no unconnected items, and no schematic/PCB parity issues; DRC also reports zero warnings after removal of those fills. Physical fit and button alignment have been checked; manufactured-board assembly and electrical testing remain pending. A backlit version would require a redesigned button board; it is a possible future project, with no finished design or release date.

## Main Board PCB v1.1 and schematic

**Layout progress — October 28, 2026:** Component placement and routing are progressing on the Main Board. The [new Main Board layout picture](../images/Main-PCB-Layout-2026-10-28.png) shows the Teensy 4.1, TFT and control connectors, SQL On/Off solder connections, and back-side component arrangement. J9 is labelled **MODE** and J10 **MASTER**. A 26.2 mm circle provides a SQL switch body spacing guide without electrical pads. The rotary-switch mounting opening, anti-rotation slot, and four 3.5 mm mounting holes remain.

The current saved Main Board PCB and schematic have now been uploaded to match the layout-progress picture. October 29 checks after correcting the J4/TP1 values report zero ERC violations, zero DRC violations, zero unconnected items, and zero schematic/PCB mismatches under the saved settings. See the [Main Board README and picture](Master%20Board/README.md#main-pcb-3d-preview) and [3D Viewer instructions](Master%20Board/README.md#teensy-41-in-the-3d-viewer). I’ve checked the physical fit of Main Board v1.1. Final placement/routing review and current verification remain to be completed; the October 29 ERC/DRC and parity checks pass under the saved settings. Main Board v1.1 Gerber and drill files are now available above; physical fit is confirmed and manufactured-board testing remains pending.

The updated [Main Board PCB draft, schematic, and KiCad project](Master%20Board/) are available to download. The board now uses USB power and the Teensy's 3.3 V supply for TFT VCC; the external protected 5 V branch and power selector are removed. C5/C6 have been removed to match the tested direct TFT wiring; C1/C2 rotary-input filters remain. I’ve tested the TFT at 3.3 V and found the brightness satisfactory. Components are on B.Cu, facing away from the faceplate. The draft has zero unconnected items under the October 29 checks. I’ve checked the physical fit of Main Board v1.1. Final placement/routing review and current verification remain pending; Main Board v1.1 manufacturing files are provided above.

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

The Teensy is powered by USB, and **TFT VCC connects directly to the Teensy's 3.3 V rail** (`TEENSY_3V3`, U1 pad 15). I’ve tested the TFT at 3.3 V and found the brightness satisfactory. I removed the external protected 5 V input and Main Board JP1 power selector. I removed C5 (470 µF) and C6 (0.1 µF) to match the direct Teensy-to-TFT wiring I tested. C1/C2 and R1/R2 remain as the rotary-input filters. Keep total external 3.3 V consumption within PJRC's recommended 250 mA maximum; brightness confirmation is not a current measurement.

**The current Button Matrix PCB v3.2 does not support LED backlighting and would need to be redesigned.** I would need to design a new button board with LED support (Button LED PCB), use suitable light-transmitting buttons, and redesign the power and driver circuitry with the necessary Main Board changes. The current Main Board has no external lighting-power circuit. I may revisit this after completing the ARC-164 and ARC-186 projects; there is no finished design or release date. The TFT display backlight is separate from this future button-lighting option.

I may need to use **four-layer PCBs for both the replacement Main Board and button board**, which could increase the cost of both replacement boards. I haven’t confirmed the layer requirements or priced that redesign yet. This possible extra cost is not included in the current build estimates or my US$40 bare-PCB set price.

## Optional SQL On/Off PCB

The SQL On/Off PCB is optional when wiring directly to the switch’s solder lugs. The build uses five PCBs without it, or six with it. Dedicated **TP1 (SQL signal, GPIO 41 / U1 pad 33)** and **TP2 (GND)** solder-wire pads are now included in the Main Board schematic and PCB draft. The optional SQL1 header remains available. The pads are placed and routed in the current draft; I’ve checked the physical fit of Main Board v1.1; I still need to check the assembled board. See the [direct-wiring notes](../parts/README.md#six-pcb-layout) for details.

The [shaft spacer v.5](../Supporting%20STL%27s/Shaft_Spacer_v.5.stl) is **required in all installations** to support the **longer SQL On/Off switch shaft**, whether using the optional switch PCB or wiring directly to the switch’s solder lugs.

## Channel and SQL knobs

**The 17-part set has passed test fitting at 100% scale, with Channel v4.2 separately reprinted and confirmed after the earlier complete-layout test. The combined downloads now include that replacement.** Please keep checking [Project Updates](../Docs/Project-Updates.md) for changes.

[Channel knob v4.2](../Supporting%20STL%27s/Channel_Knob_v.4.2.stl) · [SQL knob v1.2](../Supporting%20STL%27s/SQL_Knob_v.1.2.stl)

**The Channel and SQL knobs are the same outside size, with the same small side hole; only the shaft holes differ.** Channel v4.2 has the smaller shaft hole; SQL v1.2 retains the larger shaft hole. Channel v4.2 uses the Frequency v10.1 shaft-hole profile (approximately 6.375 mm round diameter), with the Channel socket depth, outside dimensions, and small side hole unchanged. I printed Channel v4.2 at **100% scale** and confirmed the fit. SQL remains v1.2 with its previously tested socket. Print **one Channel v4.2 and one SQL v1.2**, each at 100%; these files are no longer interchangeable.

The SQL shaft support spacer v.5 remains required in all installations.

## Estimated build cost

Thinking about building one? The [DIY parts purchasing estimate](../parts/README.md#estimated-build-cost) gives you an idea of the budget, including the faceplate, display, electronics, and PCB fabrication. You’ll source the parts yourself, and I’m sharing the files and guidance to help along the way.

## Questions and community builds

**Building your own panel, or just looking around?** [Introduce yourself in the welcome discussion](https://github.com/dgdimick/ARC-210-DCS-Display/discussions/1) and tell us what you fly. Questions, ideas, and progress photos are all welcome—even if you’re only getting started.

Visit [GitHub Discussions](https://github.com/dgdimick/ARC-210-DCS-Display/discussions) to ask questions, share ideas, and post photos of your builds.

### Main Board v1.1 fabrication export

The current [Main Board Gerber/drill ZIP](Master%20Board/Manufacturing/Main-Board-PCB-v1.1-Gerbers-Drill.zip) is available, including the USB zip-tie slots. This standalone two-layer, 1.6 mm v1.1 export includes the ground pours. Main Board v1.1 physical fit is confirmed; current verification and electrical testing remain pending. See the [Main Board README](Master%20Board/README.md#standalone-manufacturing-files).

Main Board **v1.1** includes GND-connected copper pours on both layers, with isolated islands removed. Use its updated [v1.1 fabrication package](Master%20Board/Manufacturing/Main-Board-PCB-v1.1-Gerbers-Drill.zip).
