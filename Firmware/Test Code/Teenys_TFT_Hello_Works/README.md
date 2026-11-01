# Teensy TFT hello test

**Last updated: November 1, 2026 at 5:03 AM MST (America/Denver)**

Start here to check your build environment and get a first message on the TFT. Seeing that first screen is a useful milestone!

Download [ARC210_TFT_Hello_World_v1.0_Teensy41.hex](ARC210_TFT_Hello_World_v1.0_Teensy41.hex) and load it with Teensy Loader. This **V1.0** test uses backlight **GPIO 4** for the current Main Board and displays green HELLO WORLD and **TFT TEST V1.0** without DCS. Compiling from source is optional.

Open the sketch in your Arduino/Teensy development environment, select **Teensy 4.1**, and compile it. The sketch uses `ILI9488_t3.h`; make sure the matching display library is installed. Check the sketch's pin definitions against your TFT wiring, then upload your compiled build to the Teensy and look for the hello message. A successful compile checks the software setup; seeing the message also checks the display connection.

If you have trouble getting it to compile, please [post in GitHub Discussions](https://github.com/dgdimick/ARC-210-DCS-Display/discussions). Include the full compiler error, your IDE and Teensy software versions, and what you have tried. Questions are welcome—I want you to get it working and enjoy the build!

The existing folder and sketch are named `Teenys_TFT_Hello_Works`; keep those names together when opening the sketch.

[Back to the test-code guide](../README.md)
