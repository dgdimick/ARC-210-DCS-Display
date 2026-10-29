# Teensy TFT hello test

Start here to check your build environment and get a first message on the TFT. Seeing that first screen is a useful milestone!

I have intentionally **not provided a precompiled HEX file for this test**. I want you to compile the [sketch](Teenys_TFT_Hello_Works.ino) yourself so you can confirm that your Teensy build environment, board support and required libraries are installed and working correctly before moving on to the rest of the project.

Open the sketch in your Arduino/Teensy development environment, select **Teensy 4.1**, and compile it. The sketch uses `ILI9488_t3.h`; make sure the matching display library is installed. Check the sketch's pin definitions against your TFT wiring, then upload your compiled build to the Teensy and look for the hello message. A successful compile checks the software setup; seeing the message also checks the display connection.

If you have trouble getting it to compile, please [post in GitHub Discussions](https://github.com/dgdimick/ARC-210-DCS-Display/discussions). Include the full compiler error, your IDE and Teensy software versions, and what you have tried. Questions are welcome—we want you to get it working and enjoy the build!

The existing folder and sketch are named `Teenys_TFT_Hello_Works`; keep those names together when opening the sketch.

[Back to the test-code guide](../README.md)
