# Test Code

**Last updated: October 30, 2026 at 9:15 PM MDT (America/Denver)**

Current Main Board version: **1.1**.

## Final hardware test HEX — October 10, 2026

**I have completed the final combined hardware test HEX file.** Download [ARC210_Final_Hardware_Test_Teensy41.hex](ARC210_Final_Hardware_Test_Teensy41.hex) and program it with Teensy Loader.

I have confirmed that all 16 buttons, six rotary encoders, TFT brightness controls and both seven-position rotary switches work together on my panel. I use GPIO14/A0 (label printed on the Teensy) and GPIO15/A1 for the switch inputs, and GPIO4 for the TFT backlight. The TFT shows encoder counts and A/B readings, button states and rotary positions, ADC readings, voltage and test coverage. No DCS connection is required.

See the [combined test instructions and source](ARC210_Button_Test/). Programming this test replaces the running firmware. I have kept the earlier individual tests below for troubleshooting.

**Start with the TFT hello test** so you know the display is working before checking the encoders. The encoder test uses the screen to show counts, direction, and input states. If the screen stays blank, the wiring notes are a good place to start. You’re welcome to ask for help in Discussions.

1. Load the [TFT hello test and compile instructions](Teenys_TFT_Hello_Works/README.md) and confirm that its output appears correctly on the TFT. (The existing folder and sketch are named `Teenys_TFT_Hello_Works`.)
2. If the display stays blank, work through the display wiring and setup first. Feel free to ask in Discussions if you get stuck.
3. After the TFT test passes, load [ARC210_Encoder_Check_Teensy41.hex](ARC210_Encoder_Check_Teensy41.hex) onto the Teensy 4.1 and turn each encoder in both directions. Watch its row on the TFT for changing counts and direction.

Passing the hello test confirms the display is ready; it does not install a dependency. Loading the encoder HEX replaces the hello-test firmware.


## Seven-position rotary switch TFT test

**Tested wiring:** I tested both seven-position rotary switches, and they worked with each switch PCB’s J1 pin 2 connected directly to its Teensy input (GPIO 14 or GPIO 15), without the 220 Ω series resistor or 100 nF input-filter capacitor. The six 1 kΩ resistor-ladder resistors on each switch PCB were still fitted, and JP1 was left open. I saw some fluctuation in the TFT voltage readings, but it did not affect the detected switch positions. This records the successful breadboard setup; the input-filter components shown in the Main Board schematic were not part of that test.

I also included a standalone [rotary switch test](ARC210_Rotary_Switch_Test/) that displays position 1–7, raw ADC reading and approximate voltage on the TFT. Connect the switch PCB's J1 pin 2 to Teensy **GPIO 14 (A0)**, fit all six resistors and leave JP1 open. J1 pin 1 goes to 3.3V and pin 3 to GND.

Download [ARC210_Rotary_Switch_Test.ino.hex](ARC210_Rotary_Switch_Test/ARC210_Rotary_Switch_Test.ino.hex) for Teensy Loader, or build the [sketch](ARC210_Rotary_Switch_Test/ARC210_Rotary_Switch_Test.ino). This test uses backlight **GPIO 4** and runs without DCS or an open Serial Monitor. See its [instructions](ARC210_Rotary_Switch_Test/README.md). Programming the HEX replaces the firmware on the Teensy.

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

Thinking about building one? The [DIY parts purchasing estimate](../../parts/README.md#estimated-build-cost) gives you an idea of the budget, including the faceplate, display, electronics, and PCB fabrication. You’ll source the parts yourself, and I’m sharing the files and guidance to help along the way.

## Questions and community builds

**Building your own panel, or just looking around?** [Introduce yourself in the welcome discussion](https://github.com/dgdimick/ARC-210-DCS-Display/discussions/1) and tell us what you fly. Questions, ideas, and progress photos are all welcome—even if you’re only getting started.

Visit [GitHub Discussions](https://github.com/dgdimick/ARC-210-DCS-Display/discussions) to ask questions, share ideas, and post photos of your builds.
