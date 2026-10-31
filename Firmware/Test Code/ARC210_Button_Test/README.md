# ARC-210 final combined hardware test

**Last updated: October 30, 2026 at 9:15 PM MDT (America/Denver)**

Current Main Board version: **1.1**.

**Final hardware test HEX — October 10, 2026.** I’ve confirmed all the controls listed below working together on my panel. You can use this test to check your own wiring and controls before moving on to the radio firmware.

Download [ARC210_Final_Hardware_Test_Teensy41.hex](../ARC210_Final_Hardware_Test_Teensy41.hex) and program it with Teensy Loader.

Includes the existing 16-button matrix, six rotary encoders and TFT brightness controls, plus two seven-position rotary switches on Teensy GPIO14 (A0) and GPIO15 (A1), using the labels printed on the Teensy.

The TFT shows each switch position (SW14 and SW15), raw ADC reading, approximate voltage and number of positions tested. Serial Z resets test history and encoder counts. Hold B1 to dim or B2 to brighten, as in the original test.

Switch PCB wiring: J1 pin 1 to 3.3V, pin 2 to GPIO14/A0 (label printed on the Teensy) for the first board or GPIO15/A1 for the second board, pin 3 to GND. Fit all six 1k resistors and leave JP1 open. Display backlight uses GPIO4.

**Tested wiring:** I tested both seven-position rotary switches, and they worked with each switch PCB’s J1 pin 2 connected directly to its Teensy input (GPIO 14 or GPIO 15), without the 220 Ω series resistor or 100 nF input-filter capacitor. The six 1 kΩ resistor-ladder resistors on each switch PCB were still fitted, and JP1 was left open. I saw some fluctuation in the TFT voltage readings, but it did not affect the detected switch positions. This records the successful breadboard setup; the input-filter components shown in the Main Board schematic were not part of that test.

Build for Teensy 4.1, USB Serial, using the ILI9488_t3 and Encoder libraries. This is a standalone hardware test and does not require DCS. Programming it replaces the firmware on the Teensy.


Compiled for Teensy 4.1 with Teensy core 1.62.0. HEX SHA-256: `8b540030c7f2831d7bc496467934c2daeb3d0237b45f5f25da5b69300f37f6a2`.

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

## Estimated build cost

Thinking about building one? The [DIY parts purchasing estimate](../../../parts/README.md#estimated-build-cost) gives you an idea of the budget, including the faceplate, display, electronics, and PCB fabrication. You’ll source the parts yourself, and I’m sharing the files and guidance to help along the way.

## Questions and community builds

**Building your own panel, or just looking around?** [Introduce yourself in the welcome discussion](https://github.com/dgdimick/ARC-210-DCS-Display/discussions/1) and tell us what you fly. Questions, ideas, and progress photos are all welcome—even if you’re only getting started.

Visit [GitHub Discussions](https://github.com/dgdimick/ARC-210-DCS-Display/discussions) to ask questions, share ideas, and post photos of your builds.
