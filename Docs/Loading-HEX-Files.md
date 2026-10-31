[Back to the main project README](../README.md)

# Loading the HEX File onto a Teensy 4.1

**Last updated: October 31, 2026 at 12:20 AM MDT (America/Denver)**

I’m developing one shared ARC-210 code base for the planned aircraft, starting with the A-10C II and C-130J. It will automatically select the appropriate controls and display data for the aircraft you fly, using aircraft-specific DCS-BIOS mappings. **The plan is to switch between supported aircraft without reflashing the Teensy—just fly the aircraft. This support is still being developed and tested and is not available as a completed feature yet.** See the [aircraft support plan](C-130J-Support.md).

I’ll label radio HEX downloads with the aircraft they support and a version number, increasing the version whenever I publish updated firmware so you can tell releases apart. Each new aircraft-support release will retain support for the previously supported aircraft. Adding an aircraft will require loading the updated HEX once, using the same Teensy Loader procedure as the first flash while the panel is connected by USB. After that, switching between aircraft included in that version will not require reflashing. **This cumulative aircraft support and automatic selection are still being developed and tested.**

For the complete radio connection setup, file changes, and TekConnect instructions, follow the [DCS-BIOS setup guide](DCS-BIOS.md). The steps below cover programming the Teensy only.

1. Install and open **Teensy Loader**.
2. Open the supplied `ARC210_A-10C2_v0.1.1_Preview.hex` file.
3. Connect the Teensy 4.1 to your computer by USB.
4. Press the button on the Teensy if it does not enter programming mode automatically.
5. Click **Program** in Teensy Loader.
6. Reboot the Teensy.

The current v0.1.1 preview shows its version and **A-10C2** aircraft label during the radio-switch startup information screen, after powered-radio data arrives. This new build still needs physical-panel and in-DCS testing; see the [release notes](../Firmware/Master%20Hex%20Files/README.md).
