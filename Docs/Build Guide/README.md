# ARC-210 Build Guide

Draft started October 29, 2026.

This guide covers the ARC-210 panel using one Teensy 4.1, a 3.5-inch ILI9488 SPI TFT, and the published control boards. It is a work in progress. **Pending** means the step still needs final design work, assembly validation, measurements, or photographs; it is not a confirmed assembly procedure.

## Build status

| Area | Current status |
| --- | --- |
| Button Matrix PCB v3.1 | Final design; physical fit and button alignment confirmed; manufacturing files published |
| Rotary Encoder PCB v1.4 | Final design; physical fit confirmed; manufacturing files published |
| Rotary Switch PCB v2.0 | Final design; physical fit confirmed; manufacturing files published |
| Main Board | Routed draft; October 29 ERC/DRC and parity checks pass under saved settings; final review, current verification, physical fit, and manufacturing release pending |
| Printed parts | Published knobs, bracket, and spacers available; SQL ON/OFF knob design and printing pending |
| Electrical testing | Combined breadboard hardware test confirmed; assembled manufactured-board testing pending |
| Radio firmware | Menu/display preview available; complete physical-control integration and final in-DCS validation pending |

Passing KiCad checks does not establish that an assembled board has been tested.

## 1. Gather files, parts, and tools

1. Download the repository using **Code → Download ZIP**, then extract it. Keep each KiCad project folder and its libraries together.
2. Read the [parts README](../../parts/README.md), [BOM](../../parts/BOM.csv), and [PCB overview](../../PCBs/README.md). Use the current project versions listed above.
3. Gather a soldering iron, solder, flush cutters, multimeter, suitable hand tools, and access to a 3D printer. Have the PC Flights faceplate and specified controls available for fit checks.
4. Use a **USB Micro-B data cable** to power and program the Teensy 4.1 and carry USB communications. A charge-only cable is unsuitable.

For removable mounting, use **two 1 × 24 female PCB socket strips, 2.54 mm (0.1-inch) pitch**, on the Main Board, with matching male headers on the Teensy. **These sockets are optional but recommended.** They allow the Teensy to be removed when replacing or updating the Main Board for new features, such as future LED support, or when the Teensy itself is damaged and needs replacement. **Pending:** final socket height, header lead length, standoff lengths, fastener quantities, and cable lengths must be confirmed against the finished assembly.

The build uses **five required boards**: one Main Board, one Button Matrix, one Rotary Encoder, and two Rotary Switch boards. A third Rotary Switch PCB is optional for the SQL On/Off switch, bringing the total to six.

## 2. Print and check the mechanical parts

Use the [Supporting STL instructions](../../Supporting%20STL%27s/README.md) for revision and fit notes.

| Part | Quantity / action |
| --- | --- |
| [Frequency knob v.10](../../Supporting%20STL%27s/Freq_Knob_v.10.stl) | Print for the frequency controls; confirm fit on each shaft |
| [Mode knob v.4](../../Supporting%20STL%27s/Mode_Knob_v.4.stl) | Print for the Mode control |
| [Channel knob v.3](../../Supporting%20STL%27s/Channel_Knob_v.3.stl) | Print for the Channel control |
| [TFT bracket v.5](../../Supporting%20STL%27s/Deep_Bracket_v.5.stl) | Print one |
| [Rotary Encoder spacer v.1](../../Supporting%20STL%27s/Rotary_Encoder_Spacer_v.1.stl) | **Print six**, one per encoder, to center the threads in the faceplate holes |
| [SQL shaft spacer v.5](../../Supporting%20STL%27s/Shaft_Spacer_v.5.stl) | **Print one; required in all installations** to support the longer SQL On/Off switch shaft |
| SQL ON/OFF knob | **Pending: design and print**; finished STL not yet published |

The SQL shaft spacer is required whether using the optional SQL PCB or wiring directly to the switch's solder lugs. It is a separate part from the unfinished SQL knob.

Dry-fit printed parts before permanent assembly. The Supporting STL README records earlier knob-scaling experience; printer tolerances and current revisions need their own fit check. **Pending:** illustrated printing settings and a complete knob-to-control installation chart.

## 3. Order the finalized control PCBs

Download the manufacturing packages from the [Gerber and drill table](../../PCBs/README.md#gerber-and-drill-downloads).

| Design | Boards per panel |
| --- | ---: |
| Button Matrix v3.1 | 1 |
| Rotary Encoder v1.4 | 1 |
| Rotary Switch v2.0 | 2 required, plus 1 optional for SQL On/Off |

Review the manufacturer's preview against the project outline and drill information. These control boards specify two layers and 1.6 mm thickness; consult each manufacturing README for details.

**Pending — Main Board:** no Main Board manufacturing package is released. Do not treat the draft as a final fabrication release.

## 4. Assemble the Button Matrix PCB

Refer to the [Button Matrix instructions and connector table](../../PCBs/Button%20Matrix/README.md).

- Fit sixteen **6 × 6 × 5 mm** SPST momentary tactile switches on the front.
- Fit D5–D20, the sixteen 1N4148 diodes, and the row/column connectors on the back. Follow the schematic and polarity markings; the diode cathodes connect to the row lines.
- J1 and J2 are separate four-pin row and column connectors. They connect to the Main Board's eight-pin J2 according to the project's mapping.
- The large 12 mm opening provides SQL switch pass-through clearance.

Button positions and the final v3.1 board fit have been checked. **Pending:** photographed soldering order, manufactured-board assembly, and electrical validation.

## 5. Assemble the Rotary Encoder PCB

Refer to the [Rotary Encoder instructions](../../PCBs/Rotary%20Encoders/README.md).

- Use six Bourns **PEC11H-4220F-S0024** encoders.
- Fit the 14-pin connector using the board orientation shown in its project. J1 pins 13 and 14 are GND.
- The encoders' push-switch contacts are unused in this design.
- Fit the **six printed encoder spacers**, one at each encoder's threaded faceplate mounting section.

The PCB has been physically checked, and all six encoders worked in the combined hardware test. **Pending:** photographed assembly order and electrical testing of a manufactured board.

## 6. Assemble the Rotary Switch boards and SQL switch

Refer to the [Rotary Switch instructions](../../PCBs/Rotary%20Switches/README.md).

For each of the two seven-position controls, use the C&K **A12505RNCQ PCB-terminal switch**, fit all six 1 kΩ resistors R1–R6, and leave JP1 open. J1 pin 1 is 3.3 V, pin 2 is the signal, and pin 3 is GND. Set the travel stops and knob orientation to suit the faceplate.

The SQL On/Off switch is the **A12515RNZQ solder-lug version with the longer shaft**. It does not fit directly into the PCB-terminal footprint.

- **Direct wiring:** connect the switch common to the Main Board SQL signal and the selected contact to GND. Select the contact and travel stops to match the panel's ON/OFF positions.
- **Optional SQL PCB:** use wires from the solder-lug switch to the corresponding board connections. Omit R1–R6 and bridge the board's JP1 ON/OFF solder jumper. Follow its README for the contact and connector mapping.
- Fit **shaft spacer v.5 in either configuration**.

**Pending:** detailed SQL mounting photographs, final stack spacing and wire routing, the SQL knob, and manufactured-board assembly validation.

## 7. Dry-fit the faceplate, TFT, and boards

Use the current TFT bracket, encoder spacers, switch shaft spacer, and faceplate. Check button movement and shaft alignment before soldering or fastening makes adjustment difficult.

The Main Board component bodies face **away from the faceplate**, on the back of the board. Its draft includes the switch shaft and anti-rotation openings and four 3.5 mm mounting holes.

**Pending:** the final Main Board fit check, exact standoff and socket heights, fastener lengths, TFT-to-board clearance, final assembly order, and step-by-step photographs. The Main Board's layout-spacing guide does not replace a physical fit check.

### USB cable strain relief — pending design

Design and print a support that secures the USB cable to the Main Board mounting structure or panel, so cable pulls and movement are carried by the support rather than the Teensy's Micro-B connector. Leave enough slack to unplug the cable and remove the socketed Teensy for service. Final mounting points, cable clearance, dimensions, STL, and physical fit testing are **pending**.

## 8. Main Board assembly and wiring — pending final validation

Use the [current Main Board schematic and README](../../PCBs/Master%20Board/README.md) as the authority. This section records the draft's connections, not a final assembly release.

| Main Board connection | Purpose |
| --- | --- |
| J1 | TFT cable; **not straight-through**—use the [TFT cable mapping](../../parts/README.md#pin-headers-and-mating-connectors--october-12-2026) |
| J2 | Button Matrix cable; split into the two four-pin board connectors as documented |
| J4 | Rotary Encoder board; 14-pin cable, pin-for-pin |
| J9 — MODE | Signal on pin 2 to GPIO 15 / A1 through R2 |
| J10 — MASTER | Signal on pin 2 to GPIO 14 / A0 through R1 |
| SQL1 | Pin 1 SQL signal / GPIO 41; pin 2 GND |
| TP1 / TP2 | Alternative SQL solder-wire connections: TP1 signal, TP2 GND |

J9 and J10 each use pin 1 = 3.3 V, pin 2 = signal, pin 3 = GND. For the optional SQL switch-board cable, follow the specific SQL mapping in the parts README; do not assume all three-pin cables have identical use.

The Teensy is USB-powered. TFT VCC comes directly from **Teensy 3.3 V**. The removed protected 5 V circuit, Main Board JP1 selector, and C5/C6 are not fitted. C1/C2 and R1/R2 remain as rotary-input filters. The separate Rotary Switch PCB's JP1 is still used as described in step 6.

Use the **GPIO labels printed on the Teensy** for wiring instructions; they are not the KiCad symbol's pad numbers. With power disconnected, verify cable continuity, orientation, solder bridges, and power-to-ground connections before connecting USB.

**Pending:** final Main Board fabrication and assembly, full-panel current verification, cable lengths and routing, and photographed continuity checks.

## 9. Test the hardware in stages

The existing test firmware was confirmed on the development hardware. **Validation of the assembled manufactured boards remains pending.**

1. Start with the [TFT hello test and test-code instructions](../../Firmware/Test%20Code/README.md). Confirm that the display works.
2. Use the standalone encoder and rotary-switch tests there if a control needs troubleshooting.
3. Load the [final combined hardware test HEX](../../Firmware/Test%20Code/ARC210_Final_Hardware_Test_Teensy41.hex) and follow the [combined-test instructions](../../Firmware/Test%20Code/ARC210_Button_Test/README.md).
4. Check all sixteen buttons, six encoders in both directions, both seven-position switches, and TFT brightness control.
5. **Pending:** a documented end-to-end SQL On/Off test and complete manufactured-panel acceptance checklist. Do not assume the combined test covers SQL.

Loading a test HEX replaces the firmware currently on the Teensy. The standalone tests do not require DCS. Disconnect USB before changing wiring.

## 10. Load the radio firmware and configure DCS-BIOS

Follow the [firmware README](../../Firmware/Master%20Hex%20Files/README.md) for the current HEX, Teensy Loader steps, startup behavior, and required DCS-BIOS export changes. Back up the existing export file before applying the documented changes.

The current radio HEX is a **display/menu preview**; physical controls do not yet provide complete in-game radio operation. The screen can remain blank until powered-radio data arrives. For offline testing, use the [ARC-210 dcsBiosDebug instructions](https://github.com/dgdimick/dcsBiosDebug/blob/arc210-working/ARC210_TESTING.md).

**Pending:** complete physical-control firmware integration, final DCS-BIOS installation screenshots, and full in-DCS acceptance testing on the manufactured assembly.

## 11. Troubleshooting and remaining guide work

| Symptom | First check |
| --- | --- |
| Teensy cannot be programmed or no USB data | Use a Micro-B data cable and the Teensy's programming button; follow the firmware loading instructions |
| TFT blank during a hardware test | Start with the hello test; verify J1's non-straight-through mapping and backlight GPIO 4 |
| TFT blank with radio firmware | Confirm powered-radio updates are being received, as explained in the firmware README |
| Encoder or matrix input missing | Check the connector mapping, continuity, diode polarity, and standalone test results |
| Rotary-switch readings wrong | Check 3.3 V/signal/GND, resistor population, JP1 configuration, and travel stops |

**Pending:** assembly photographs, annotated connector-orientation diagrams, measured mounting hardware, validated manufactured-board procedures, SQL knob files, and final acceptance results.

Ask questions or share build photos in [GitHub Discussions](https://github.com/dgdimick/ARC-210-DCS-Display/discussions).

[Back to documentation](../README.md) · [Back to main README](../../README.md)
