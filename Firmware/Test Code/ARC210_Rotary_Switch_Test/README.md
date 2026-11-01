# ARC-210 seven-position rotary switch test

**Last updated: November 1, 2026 at 5:21 AM MST (America/Denver)**

**Latest switch tester: V1.1 — [Download the current HEX](ARC210_Master_Secondary_Switch_Test_v1.1_Teensy41.hex).** Includes Master, Secondary, and SQL ON/OFF. V1.0 remains available only as an older version.

Current Main Board version: **1.1**.

**Optional troubleshooting test:** You don’t need to run this standalone switch test during normal assembly. Use the [Final Hardware Test](../ARC210_Button_Test/README.md) for the assembly check; use this test if you need to isolate a Master or Secondary switch problem.

Release **V1.1** checks both seven-position switches simultaneously: **Master on GPIO 14/A0** and **Secondary on GPIO 15/A1**. The ILI9488 TFT shows each switch in its own column with its position, raw ADC reading, and approximate voltage. USB Serial provides the same readings if you’d like another way to check them. You can run this test without DCS or DCS-BIOS.

## SQL ON/OFF indication — V1.1

I added the SQL ON/OFF indication in **V1.1** to make the SQL switch test clearer. The bottom line now shows **SQL: ON** or **SQL: OFF** instead of the JP1 reminder. It reads **GPIO 41** with an internal pull-up: a switch contact to GND reads ON; an open contact reads OFF. With no SQL switch installed, it should read OFF. This electrical indication depends on which switch contact is wired; check it against the faceplate markings. The input is debounced for 30 ms, and its state is also printed over USB Serial.

Master and Secondary still use their six-resistor ladders with **JP1 open**. The SQL direct-wiring option needs no resistor ladder; if using its optional PCB, omit the six resistors and close JP1. V1.1 compiled successfully; the new SQL indication still needs checking on the panel.

## Wiring

| Rotary switch PCB | Teensy 4.1 |
| --- | --- |
| J1 pin 1 | 3.3V |
| Master J1 pin 2 | GPIO 14 / A0 (label printed on the Teensy) |
| Secondary J1 pin 2 | GPIO 15 / A1 (label printed on the Teensy) |
| J1 pin 3 | GND |

On each switch PCB, fit all six 1k resistors R1-R6 and leave JP1 open. Use the Teensy's 3.3V rail, not 5V. **Tested wiring:** I tested both seven-position rotary switches, and they worked with each switch PCB’s J1 pin 2 connected directly to its Teensy input (GPIO 14 or GPIO 15), without the 220 Ω series resistor or 100 nF input-filter capacitor. The six 1 kΩ resistor-ladder resistors on each switch PCB were still fitted, and JP1 was left open. I saw some fluctuation in the TFT voltage readings, but it did not affect the detected switch positions. This records the successful breadboard setup; the input-filter components shown in the Main Board schematic were not part of that test.

## Run

1. Open the supplied `ARC210_Master_Secondary_Switch_Test_v1.1_Teensy41.hex` in Teensy Loader, connect the Teensy 4.1 and program it. This replaces the currently running firmware.
2. The TFT should immediately show `ARC-210 SWITCH TEST V1.1`, even without the switch connected.
3. Rotate each switch through all seven positions and watch its own position, ADC and voltage readings on the TFT. Both inputs use independent 75 ms settling timers.
4. Optionally open Serial Monitor at 115200 baud for text readings.

To build from source, open `ARC210_Rotary_Switch_Test.ino` in the Arduino IDE, select Teensy 4.1 and USB Type **Serial**, then upload. It requires the `ILI9488_t3` library included in the Teensy installation used for this build.

TFT wiring: CS = 10, DC = 9, RESET = 8, MOSI = 11, SCK = 13, MISO = 12 (if connected), and backlight = **GPIO 4 (label printed on the Teensy)**. Backlight stays fully on. This uses the project's TFT hello-test initialization, with backlight corrected to the confirmed GPIO 4 assignment. If the screen stays blank, first check that this HEX was programmed and that the backlight and display wiring match these pins. No Serial Monitor connection is needed for the display to run.

| Position | Switch terminal | Nominal voltage | Approximate 12-bit reading |
| --- | --- | --- | --- |
| 1 | 1 | 3.300V | 4095 |
| 2 | 2 | 2.750V | 3413 |
| 3 | 4 | 2.200V | 2730 |
| 4 | 5 | 1.650V | 2048 |
| 5 | 7 | 1.100V | 1365 |
| 6 | 8 | 0.550V | 683 |
| 7 | 10 | 0.000V | 0 |

The sketch averages ADC readings and requires a position to remain stable for 75ms. Readings between tap windows are reported as BETWEEN TAPS. An unplugged input can float to a valid reading, so this is not a continuity test. If the physical knob positions appear reversed, check switch orientation against the panel markings.

Uses the Teensy core's 12-bit ADC configuration and averaging: https://www.pjrc.com/store/teensy41.html and https://github.com/PaulStoffregen/cores/blob/master/teensy4/analog.c.

Compiled for Teensy 4.1 with Teensy core 1.62.0 and its bundled ILI9488_t3 library. The V1.1 build compiled successfully. It uses a framebuffer to draw updates in memory before sending them to the TFT, addressing the visible clear-and-redraw flicker in the earlier test. I still need to check both switch inputs and the smoother display on my physical panel.

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
