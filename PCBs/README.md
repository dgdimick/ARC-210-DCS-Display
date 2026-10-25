# ARC-210 PCBs

Updated October 12, 2026.

The following two PCB designs are final and have been physically test-fitted:

| PCB | Final version | Status |
| --- | --- | --- |
| [Rotary Encoders](Rotary%20Encoders/) | 1.4 | Final design; test fit confirmed |
| [Rotary Switches](Rotary%20Switches/) | 2.0 | Final design; test fit confirmed |

Use the KiCad project files in each linked folder. Each folder includes its wiring and assembly notes.

I’ve confirmed the mechanical fit of these designs. Testing an assembled, manufactured PCB is still on my list. Each project’s README explains the electrical checks and hardware tests completed so far.

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

The current design keeps the Teensy powered by USB. On the Master PCB, JP1 selects the TFT supply: **pins 1–2 select protected external 5 V; pins 2–3 select Teensy 3.3 V**. Fit only one shunt and remove power before moving it. JP1 does not select USB/VIN power. Keep the external protected 5 V rail separate from Teensy VIN and 3.3 V; the circuit uses a common ground. The TFT’s backlight is separate from the proposed button-lighting LEDs.

**Future button lighting will require the external 5 V supply and the associated power-input and protection circuitry to be installed.** USB/VIN power is not the planned source for this lighting option. It would also need a revised Master PCB with space for the lighting-control SCR, associated discrete components, and a pin header, plus a new Button PCB design. That Button PCB is not currently planned; the ARC-164 and ARC-184 projects will be completed before this option is revisited. Button-lighting LEDs are not part of the current build or parts estimate.

## Optional SQL On/Off PCB

The SQL On/Off PCB is optional when wiring directly to the switch’s solder lugs. The build uses five PCBs without it, or six with it. Dedicated SQL signal (GPIO 41) and GND solder pads are planned for the Master PCB; these pads have not yet been added. See the [direct-wiring notes](../parts/README.md#six-pcb-layout) for details.

## Estimated build cost

Thinking about building one? The [DIY parts purchasing estimate](../parts/README.md#estimated-build-cost) gives you an idea of the budget, including the faceplate, display, electronics, and PCB fabrication. You’ll source the parts yourself, and I’m sharing the files and guidance to help along the way.

## Questions and community builds

**Building your own panel, or just looking around?** [Introduce yourself in the welcome discussion](https://github.com/dgdimick/ARC-210-DCS-Display/discussions/1) and tell us what you fly. Questions, ideas, and progress photos are all welcome—even if you’re only getting started.

Visit [GitHub Discussions](https://github.com/dgdimick/ARC-210-DCS-Display/discussions) to ask questions, share ideas, and post photos of your builds.
