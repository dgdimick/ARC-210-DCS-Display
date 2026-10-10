# Test Code

**You must successfully complete the Teensy_TFT_Hello_Works test before running the encoder test.** The encoder test requires a working TFT display to show encoder counts, direction, and input states.

1. Load the [TFT hello test](Teenys_TFT_Hello_Works/Teenys_TFT_Hello_Works.ino) and confirm that its output appears correctly on the TFT. (The existing folder and sketch are named `Teenys_TFT_Hello_Works`.)
2. If the display does not work, resolve the display wiring and setup before proceeding.
3. After the TFT test passes, load [ARC210_Encoder_Check_Teensy41.hex](ARC210_Encoder_Check_Teensy41.hex) onto the Teensy 4.1 and turn each encoder in both directions. Watch its row on the TFT for changing counts and direction.

Passing the hello test confirms the display is ready; it does not install a dependency. Loading the encoder HEX replaces the hello-test firmware.


## Seven-position rotary switch TFT test

The [rotary switch test](ARC210_Rotary_Switch_Test/) displays position 1–7, raw ADC reading and approximate voltage on the TFT. Connect the switch PCB's J1 pin 2 to physical Teensy **GPIO 14 (A0)**, fit all six resistors and leave JP1 open. J1 pin 1 goes to 3.3V and pin 3 to GND.

Download [ARC210_Rotary_Switch_Test.ino.hex](ARC210_Rotary_Switch_Test/ARC210_Rotary_Switch_Test.ino.hex) for Teensy Loader, or build the [sketch](ARC210_Rotary_Switch_Test/ARC210_Rotary_Switch_Test.ino). This test uses backlight **GPIO 4** and runs without DCS or an open Serial Monitor. See its [instructions](ARC210_Rotary_Switch_Test/README.md). Programming the HEX replaces the firmware on the Teensy.
