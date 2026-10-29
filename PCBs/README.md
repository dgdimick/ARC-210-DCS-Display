# ARC-210 PCBs

Updated October 27, 2026.

The following three PCB designs are final. Physical fit and button alignment have been checked:

| PCB | Final version | Status |
| --- | --- | --- |
| [Button Matrix](Button%20Matrix/) | 3.1 | Final design; v3.1 physical test fit and button alignment confirmed |
| [Rotary Encoders](Rotary%20Encoders/) | 1.4 | Final design; test fit confirmed |
| [Rotary Switches](Rotary%20Switches/) | 2.0 | Final design; test fit confirmed |

Use the KiCad project files in each linked folder. Each folder includes its wiring and assembly notes.

I’ve confirmed the mechanical fit of these designs. Testing an assembled, manufactured PCB is still on my list. Each project’s README explains the electrical checks and hardware tests completed so far.

## Gerber and drill downloads

Manufacturing files generated October 27, 2026:

| PCB | Version | Gerber and drill ZIP | Individual files and reports |
| --- | --- | --- | --- |
| Button Matrix | 3.1 | [Download ZIP](Button%20Matrix/Manufacturing/Button-Matrix-PCB-v3.1-Gerbers-Drill.zip) | [Browse files](Button%20Matrix/Manufacturing/) |
| Rotary Encoders | 1.4 | [Download ZIP](Rotary%20Encoders/Manufacturing/Rotary-Encoder-PCB-v1.4-Gerbers-Drill.zip) | [Browse files](Rotary%20Encoders/Manufacturing/) |
| Rotary Switches | 2.0 | [Download ZIP](Rotary%20Switches/Manufacturing/Rotary-Switch-PCB-v2.0-Gerbers-Drill.zip) | [Browse files](Rotary%20Switches/Manufacturing/) |

Each ZIP includes copper, solder-mask, silkscreen, and board-outline Gerbers, a Gerber job file, separate plated/non-plated Excellon drill files, a drill report, and manufacturing notes. Drill maps and ERC/DRC reports are available in each manufacturing folder.

Review the manufacturer's preview before ordering. The Button Matrix's printed fit check confirmed button alignment, and its slightly long edges were shortened for final v3.1. Manufactured-board testing remains pending for all three designs. Existing check exclusions and disabled categories are documented in the individual project READMEs and reports.

## Button Matrix PCB — version 3.1

**Final design; v3.1 test fit confirmed — October 27, 2026:** The printed fit check confirmed that the buttons are correctly positioned. The slightly long board edges were shortened, and version **3.1** is the final design, replacing v3.0. The physical test fit of the revised v3.1 board is confirmed. The updated KiCad and manufacturing files are uploaded.

The current unlit 16-button, 4 × 4 Button Matrix PCB is **version 3.1**. See the [Button Matrix README](Button%20Matrix/README.md) for front and back layout previews. The front carries the push-button switches; the back carries the matrix diodes and row/column connectors. A 12 mm pass-through provides clearance for the SQL On/Off switch.

The downloadable [version 3.1 KiCad files](Button%20Matrix/) now include the PCB layout, schematic, project settings, and custom 12 mm footprint library. The PCB includes routing; unused floating copper fills were removed. Checks found zero ERC violations, zero DRC errors, no unconnected items, and no schematic/PCB parity issues; DRC also reports zero warnings after removal of those fills. Physical fit and button alignment have been checked; manufactured-board assembly and electrical testing remain pending. This board is separate from the future Button LED PCB, which is not currently planned.

## Main Board PCB draft and schematic

**Layout progress — October 27, 2026:** Initial component placement is underway, with component bodies on the back of the board facing away from the faceplate. The draft includes the rotary-switch mounting opening and anti-rotation slot, four 3.5 mm mounting holes, and SQL On/Off solder-wire pads.

The Teensy 4.1 STEP model is included and attached to U1 with a project-relative path. See the [Main PCB 3D picture with the Teensy](../images/Main-PCB-Teensy-3D.png) and the [Main Board 3D Viewer instructions](Master%20Board/README.md#teensy-41-in-the-3d-viewer). Placement, routing, current verification, and physical test fit remain unfinished; the Main Board is not ready for manufacture.

The updated [Main Board PCB draft, schematic, and KiCad project](Master%20Board/) are available to download. The board now uses USB power and the Teensy's 3.3 V supply for TFT VCC; the external protected 5 V branch and power selector are removed. C5/C6 have been removed to match the tested direct TFT wiring; C1/C2 rotary-input filters remain. TFT brightness at 3.3 V is confirmed satisfactory. Components are on B.Cu, facing away from the faceplate. Placement, routing, current verification, and physical test fit remain unfinished; no Main Board manufacturing files are provided.

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

## Optional SQL On/Off PCB

The SQL On/Off PCB is optional when wiring directly to the switch’s solder lugs. The build uses five PCBs without it, or six with it. Dedicated **TP1 (SQL signal, GPIO 41 / U1 pad 33)** and **TP2 (GND)** solder-wire pads are now included in the Main schematic and PCB draft. The optional SQL1 header remains available; final pad placement and routing are pending. See the [direct-wiring notes](../parts/README.md#six-pcb-layout) for details.

The [shaft spacer v.5](../Supporting%20STL%27s/Shaft_Spacer_v.5.stl) is **required in all installations** to support the **longer SQL On/Off switch shaft**, whether using the optional switch PCB or wiring directly to the switch’s solder lugs.

## Estimated build cost

Thinking about building one? The [DIY parts purchasing estimate](../parts/README.md#estimated-build-cost) gives you an idea of the budget, including the faceplate, display, electronics, and PCB fabrication. You’ll source the parts yourself, and I’m sharing the files and guidance to help along the way.

## Questions and community builds

**Building your own panel, or just looking around?** [Introduce yourself in the welcome discussion](https://github.com/dgdimick/ARC-210-DCS-Display/discussions/1) and tell us what you fly. Questions, ideas, and progress photos are all welcome—even if you’re only getting started.

Visit [GitHub Discussions](https://github.com/dgdimick/ARC-210-DCS-Display/discussions) to ask questions, share ideas, and post photos of your builds.
