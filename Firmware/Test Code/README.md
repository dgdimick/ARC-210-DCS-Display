# Test Code

## Final hardware test HEX — October 10, 2026

**I have completed the final combined hardware test HEX file.** Download [ARC210_Final_Hardware_Test_Teensy41.hex](ARC210_Final_Hardware_Test_Teensy41.hex) and program it with Teensy Loader.

I have confirmed that all 16 buttons, six rotary encoders, TFT brightness controls and both seven-position rotary switches work together on my panel. I use physical GPIO14/A0 and GPIO15/A1 for the switch inputs, and GPIO4 for the TFT backlight. The TFT shows encoder counts and A/B readings, button states and rotary positions, ADC readings, voltage and test coverage. No DCS connection is required.

See the [combined test instructions and source](ARC210_Button_Test/). Programming this test replaces the running firmware. I have kept the earlier individual tests below for troubleshooting.

**I recommend passing the Teensy_TFT_Hello_Works test before running the encoder test.** The encoder test requires a working TFT display to show encoder counts, direction, and input states.

1. Load the [TFT hello test](Teenys_TFT_Hello_Works/Teenys_TFT_Hello_Works.ino) and confirm that its output appears correctly on the TFT. (The existing folder and sketch are named `Teenys_TFT_Hello_Works`.)
2. If the display does not work, resolve the display wiring and setup before proceeding.
3. After the TFT test passes, load [ARC210_Encoder_Check_Teensy41.hex](ARC210_Encoder_Check_Teensy41.hex) onto the Teensy 4.1 and turn each encoder in both directions. Watch its row on the TFT for changing counts and direction.

Passing the hello test confirms the display is ready; it does not install a dependency. Loading the encoder HEX replaces the hello-test firmware.


## Seven-position rotary switch TFT test

I also included a standalone [rotary switch test](ARC210_Rotary_Switch_Test/) that displays position 1–7, raw ADC reading and approximate voltage on the TFT. Connect the switch PCB's J1 pin 2 to physical Teensy **GPIO 14 (A0)**, fit all six resistors and leave JP1 open. J1 pin 1 goes to 3.3V and pin 3 to GND.

Download [ARC210_Rotary_Switch_Test.ino.hex](ARC210_Rotary_Switch_Test/ARC210_Rotary_Switch_Test.ino.hex) for Teensy Loader, or build the [sketch](ARC210_Rotary_Switch_Test/ARC210_Rotary_Switch_Test.ino). This test uses backlight **GPIO 4** and runs without DCS or an open Serial Monitor. See its [instructions](ARC210_Rotary_Switch_Test/README.md). Programming the HEX replaces the firmware on the Teensy.
