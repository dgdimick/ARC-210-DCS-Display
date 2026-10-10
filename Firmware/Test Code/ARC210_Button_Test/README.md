# ARC-210 final combined hardware test

**Final hardware test HEX — October 10, 2026.** The builder confirmed all controls listed below working together on the panel.

Download [ARC210_Final_Hardware_Test_Teensy41.hex](../ARC210_Final_Hardware_Test_Teensy41.hex) and program it with Teensy Loader.

Includes the existing 16-button matrix, six rotary encoders and TFT brightness controls, plus two seven-position rotary switches on physical Teensy GPIO14 (A0) and GPIO15 (A1).

The TFT shows each switch position (SW14 and SW15), raw ADC reading, approximate voltage and number of positions tested. Serial Z resets test history and encoder counts. Hold B1 to dim or B2 to brighten, as in the original test.

Switch PCB wiring: J1 pin 1 to 3.3V, pin 2 to physical GPIO14/A0 for the first board or GPIO15/A1 for the second board, pin 3 to GND. Fit all six 1k resistors and leave JP1 open. Display backlight uses GPIO4.

Build for Teensy 4.1, USB Serial, using the ILI9488_t3 and Encoder libraries. This is a standalone hardware test and does not require DCS. Programming it replaces the firmware on the Teensy.


Compiled for Teensy 4.1 with Teensy core 1.62.0. HEX SHA-256: `8b540030c7f2831d7bc496467934c2daeb3d0237b45f5f25da5b69300f37f6a2`.
