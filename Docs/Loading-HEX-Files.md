[Back to the main project README](../README.md)

# Loading the HEX File onto a Teensy 4.1

**Last updated: October 31, 2026 at 12:10 AM MDT (America/Denver)**

I’m developing one shared ARC-210 code base for the planned aircraft, starting with the A-10C II and C-130J. It will automatically select the appropriate controls and display data for the aircraft you fly, using aircraft-specific DCS-BIOS mappings. **The plan is to switch between supported aircraft without reflashing the Teensy—just fly the aircraft. This support is still being developed and tested and is not available as a completed feature yet.** See the [aircraft support plan](C-130J-Support.md).

For the complete radio connection setup, file changes, and TekConnect instructions, follow the [DCS-BIOS setup guide](DCS-BIOS.md). The steps below cover programming the Teensy only.

1. Install and open **Teensy Loader**.
2. Open the supplied `Master_Program.ino.hex` file.
3. Connect the Teensy 4.1 to your computer by USB.
4. Press the button on the Teensy if it does not enter programming mode automatically.
5. Click **Program** in Teensy Loader.
6. Reboot the Teensy.
