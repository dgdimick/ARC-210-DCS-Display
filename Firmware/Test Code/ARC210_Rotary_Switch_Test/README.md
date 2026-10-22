# ARC-210 seven-position rotary switch test

Use this standalone test to check your Teensy 4.1 and six-resistor rotary switch PCB. The ILI9488 TFT shows the switch position, raw ADC reading, and approximate voltage, so you can see how each position behaves. USB Serial provides the same readings if you’d like another way to check them. You can run this test without DCS or DCS-BIOS.

## Wiring

| Rotary switch PCB | Teensy 4.1 |
| --- | --- |
| J1 pin 1 | 3.3V |
| J1 pin 2 | Physical pin 14 (A0) |
| J1 pin 3 | GND |

Fit all six 1k resistors R1-R6 and leave JP1 open. Use the Teensy's 3.3V rail, not 5V. **Tested wiring:** Both seven-position rotary switches were tested and worked with each switch PCB’s J1 pin 2 connected directly to its Teensy input (GPIO 14 or GPIO 15), without the 220 Ω series resistor or 100 nF input-filter capacitor. The six 1 kΩ resistor-ladder resistors on each switch PCB were still fitted, and JP1 was left open. This records the successful breadboard setup; the input-filter components shown in the master schematic were not part of that test.

## Run

1. Open the supplied `ARC210_Rotary_Switch_Test.ino.hex` in Teensy Loader, connect the Teensy 4.1 and program it. This replaces the currently running firmware.
2. The TFT should immediately show `ARC-210 ROTARY SWITCH TEST`, even without the switch connected.
3. Rotate through all seven positions and watch the position, ADC and voltage readings on the TFT.
4. Optionally open Serial Monitor at 115200 baud for text readings.

To build from source, open `ARC210_Rotary_Switch_Test.ino` in the Arduino IDE, select Teensy 4.1 and USB Type **Serial**, then upload. It requires the `ILI9488_t3` library included in the Teensy installation used for this build.

TFT wiring: CS = 10, DC = 9, RESET = 8, MOSI = 11, SCK = 13, MISO = 12 (if connected), and backlight = **physical GPIO 4**. Backlight stays fully on. This uses the project's TFT hello-test initialization, with backlight corrected to the confirmed GPIO 4 assignment. If the screen stays blank, first check that this HEX was programmed and that the backlight and display wiring match these pins. No Serial Monitor connection is needed for the display to run.

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

Compiled for Teensy 4.1 with Teensy core 1.62.0 and its bundled ILI9488_t3 library. Hardware operation still needs checking on the actual panel.

## Estimated build cost

Thinking about building one? The [DIY parts purchasing estimate](../../../parts/README.md#estimated-build-cost) gives you an idea of the budget, including the faceplate, display, electronics, and PCB fabrication. You’ll source the parts yourself, and I’m sharing the files and guidance to help along the way.

## Questions and community builds

**Building your own panel, or just looking around?** [Introduce yourself in the welcome discussion](https://github.com/dgdimick/ARC-210-DCS-Display/discussions/1) and tell us what you fly. Questions, ideas, and progress photos are all welcome—even if you’re only getting started.

Visit [GitHub Discussions](https://github.com/dgdimick/ARC-210-DCS-Display/discussions) to ask questions, share ideas, and post photos of your builds.
