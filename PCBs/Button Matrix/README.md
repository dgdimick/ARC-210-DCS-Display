# ARC-210 Button Matrix schematic

Version **1.1**, published October 24, 2026. KiCad 10 project.

This is the current **unlit 16-button, 4 × 4 matrix**. It is separate from the proposed future Button LED PCB, which is not currently planned.

## Download and open

Use **Code → Download ZIP** on the repository, extract it, and keep this folder together. Open `Button Matrix.kicad_pro` in KiCad 10, then open the schematic. The [schematic file](Button%20Matrix.kicad_sch) is also available directly.

The design uses standard KiCad `Connector`, `Device`, and `Switch` symbols. Install KiCad’s standard symbol and footprint libraries.

**Schematic-only release:** PCB placement, routing, final footprint selection, and physical test fitting remain unfinished. No fabrication-ready PCB or Gerber set is included.

## Buttons and connectors

Use 16 SPST momentary tactile switches, **6 × 6 × 5 mm**, with four through-hole leads. See the [parts list and supplier](../../parts/README.md#current-button-switches). Confirm the purchased switches’ contact pairing and footprint before fabrication. The saved schematic uses the `SW_PUSH_6mm` footprint name; final footprint assignments still need review.

The schematic has **two separate four-pin connectors**, rather than one eight-pin connector:

| Button Matrix connector | Master Board J2 pin | Teensy GPIO label | KiCad Teensy U1 pad |
| --- | ---: | ---: | ---: |
| J1 pin 1 — row 1 | 1 | 30 | 22 |
| J1 pin 2 — row 2 | 2 | 31 | 23 |
| J1 pin 3 — row 3 | 3 | 32 | 24 |
| J1 pin 4 — row 4 | 4 | 33 | 25 |
| J2 pin 1 — column 1 | 5 | 35 | 27 |
| J2 pin 2 — column 2 | 6 | 36 | 28 |
| J2 pin 3 — column 3 | 7 | 37 | 29 |
| J2 pin 4 — column 4 | 8 | 40 | 32 |

The connector reference J2 on this button schematic is different from J2 on the Master Board. Use the table to wire between them. A final combined eight-pin Button PCB connector is still provisional.

**Teensy printed GPIO labels differ from KiCad pad numbers.** For example, GPIO 30 is U1 pad 22. Use the Teensy labels for firmware and wiring, and the matching symbol/footprint pad numbers when working in KiCad.

## Diodes and testing

D5–D20 are the 16 matrix diodes. Their cathodes connect to the row lines. The schematic retains generic diode values and one differing diode footprint, so confirm the intended 1N4148 parts and consistent footprint assignments before board fabrication. See the [parts documentation](../../parts/README.md).

The [combined hardware test](../../Firmware/Test%20Code/ARC210_Button_Test/) documents the working matrix GPIO assignments and button tests. A successful breadboard test does not establish that this unfinished PCB layout has been assembled or tested.

KiCad ERC run October 24, 2026 reported **zero errors and zero warnings** under the project’s saved settings. Some check categories are disabled; see the [ERC report](ERC-report.txt). ERC does not verify physical button alignment, footprint suitability, or an unrouted PCB.

## Lighting

The PC Flights panel buttons used for this build are painted and opaque, so light will not pass through them to illuminate their legends. This design has no button-lighting LEDs.

A future lighting option would need suitable light-transmitting replacement buttons, a new Button LED PCB, and a revised Master PCB. It would require the **external 5 V supply and its power-input/protection circuitry**. The ARC-164 and ARC-184 projects will be completed before that option is revisited.

## Build cost and community

See the [DIY parts purchasing estimate](../../parts/README.md#estimated-build-cost) for a build budget. Parts and fabrication are sourced independently; this is primarily a DIY project.

Need a hand? Ask in [Discussions](https://github.com/dgdimick/ARC-210-DCS-Display/discussions), share your build photos, or [introduce yourself](https://github.com/dgdimick/ARC-210-DCS-Display/discussions/1).

PCB design license: CERN-OHL-P-2.0, as specified in the [main README](../../README.md#licensing).
