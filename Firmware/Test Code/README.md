# Test Code

**You must successfully complete the Teensy_TFT_Hello_Works test before running the encoder test.** The encoder test requires a working TFT display to show encoder counts, direction, and input states.

1. Load the [TFT hello test](Teenys_TFT_Hello_Works/Teenys_TFT_Hello_Works.ino) and confirm that its output appears correctly on the TFT. (The existing folder and sketch are named `Teenys_TFT_Hello_Works`.)
2. If the display does not work, resolve the display wiring and setup before proceeding.
3. After the TFT test passes, load [ARC210_Encoder_Check_Teensy41.hex](ARC210_Encoder_Check_Teensy41.hex) onto the Teensy 4.1 and turn each encoder in both directions. Watch its row on the TFT for changing counts and direction.

Passing the hello test confirms the display is ready; it does not install a dependency. Loading the encoder HEX replaces the hello-test firmware.
