# ARC-210 Master Board schematic

Published October 24, 2026, from the October 12, 2026 schematic revision.

## Download and open

Download this repository using **Code → Download ZIP**, extract it, and keep this entire folder together. Open `ARC-210_Master_Board.kicad_pro` in **KiCad 10**, then open the schematic.

You can also view or download [ARC-210_Master_Board.kicad_sch](ARC-210_Master_Board.kicad_sch) directly. Downloading only that file does not include the project library configuration.

This is a **schematic-only release**. The Master PCB outline, layout, routing, footprint assignments, protection-circuit testing, and physical test fit remain unfinished. No fabrication-ready PCB or Gerber set is included. The planned SQL direct-wiring solder pads have not yet been added.

## Signals and connectors

- **J1:** TFT connector. See the [TFT cable mapping](../../parts/README.md#pin-headers-and-mating-connectors--october-12-2026); it is not a straight-through cable.
- **J2:** separate 4 × 4 button matrix; pins 1–4 use GPIO 30, 31, 32, 33, and pins 5–8 use GPIO 35, 36, 37, 40.
- **J4:** 14-pin rotary-encoder connector; pins 13 and 14 are GND.
- **J10 pin 2:** rotary-switch signal through R1 to GPIO 14 / A0, KiCad U1 pad 36.
- **J9 pin 2:** rotary-switch signal through R2 to GPIO 15 / A1, KiCad U1 pad 37.
- **SQL1:** pin 1 is GPIO 41 / U1 pad 33; pin 2 is GND. The SQL On/Off switch PCB is optional when wiring its solder lugs directly. Dedicated Master PCB signal and ground solder pads are planned, not yet implemented.

**GPIO labels are not KiCad pad numbers.** For example, GPIO 4 is U1 pad 6, GPIO 14 is pad 36, and GPIO 15 is pad 37. Use the labels printed on the Teensy for wiring and firmware; use the matching symbol and `teensy:Teensy41` footprint when updating the PCB.

## Power and lighting

Keep the Teensy USB-powered. **JP1 pins 1–2 select protected external 5 V for TFT VCC; pins 2–3 select Teensy 3.3 V.** Fit one shunt only and remove power before changing it. No shunt means no TFT supply. JP1 does not select USB/VIN power. Keep protected external 5 V separate from Teensy VIN and 3.3 V, with a common ground.

For the 3.3 V option, keep the total external load within the Teensy's 250 mA limit. TFT startup and full-brightness current still need hardware verification.

Future button lighting requires the external 5 V supply and its input/protection circuitry, a revised Master PCB, and a new Button LED PCB. That lighting board is not currently planned; ARC-164 and ARC-184 come first. The PC Flights panel buttons used for this build are painted and opaque, so backlighting would also need suitable light-transmitting replacement buttons.

Q2 uses the project-local C106D SCR symbol: pin 1 = cathode/GND, pin 2 = anode/protected 5 V, pin 3 = gate.

## Rotary-switch test wiring

Both seven-position switches worked with their outputs connected directly to GPIO 14 and 15, without the schematic's 220 Ω series resistors or 100 nF filter capacitors. The six 1 kΩ ladder resistors on each switch board were fitted and JP1 on each switch board was open. Voltage fluctuations were visible on the TFT but did not affect the detected switch positions.

## Included libraries and checks

- `Libraries/symbols/teensy.kicad_sym`: Teensy symbols; accompanying license included.
- `Libraries/symbols/ARC210_Power.kicad_sym`: C106D SCR symbol.
- `Libraries/teensy.pretty/Teensy41.kicad_mod`: matching Teensy 4.1 footprint.
- `ARC210_Custom.pretty`: RXEF110 fuse footprint.
- `sym-lib-table` and `fp-lib-table`: project-relative library paths.

Install KiCad's standard symbol and footprint libraries too. Optional 3D models are not included and are not required to read the schematic.

The source project records an October 12 ERC result of zero errors and warnings under its saved settings, with some check categories disabled. This historical result does not validate power-protection performance or establish that the unfinished PCB is ready to manufacture.

PCB design license: CERN-OHL-P-2.0, as specified in the [main README](../../README.md#licensing). The bundled Teensy library retains its included license.

## Build cost and community

See the [DIY parts purchasing estimate](../../parts/README.md#estimated-build-cost) to plan your budget. This is primarily a DIY project, with files and guidance to help you source parts and fabrication independently.

Questions or build photos? Join [Discussions](https://github.com/dgdimick/ARC-210-DCS-Display/discussions), or [introduce yourself in the welcome discussion](https://github.com/dgdimick/ARC-210-DCS-Display/discussions/1).
