# ARC-210 seven-position rotary switch test

For the Teensy 4.1 and six-resistor rotary switch PCB. This standalone sketch shows switch position, raw ADC reading and approximate voltage on the ILI9488 TFT. USB Serial provides the same readings as an optional diagnostic. DCS and DCS-BIOS are not required.

## Wiring

| Rotary switch PCB | Teensy 4.1 |
| --- | --- |
| J1 pin 1 | 3.3V |
| J1 pin 2 | Physical pin 14 (A0) |
| J1 pin 3 | GND |

Fit all six 1k resistors R1-R6 and leave JP1 open. Use the Teensy's 3.3V rail, not 5V. The previously discussed 220-ohm series resistor and 100nF capacitor may be used at the Teensy input.

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
