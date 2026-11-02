[Back to the main project README](../README.md)

# Loading the HEX File onto a Teensy 4.1

**Last updated: November 1, 2026 at 8:09 PM MST (America/Denver)**

I’m developing one shared ARC-210 code base for the planned aircraft, starting with the A-10C II and C-130J. It will automatically select the appropriate controls and display data for the aircraft you fly, using aircraft-specific DCS-BIOS mappings. **The plan is to switch between supported aircraft without reflashing the Teensy—just fly the aircraft. This support is still being developed and tested and is not available as a completed feature yet.** See the [aircraft support plan](C-130J-Support.md).

New aircraft support will require loading an updated HEX once; after that, I plan to switch between aircraft supported by that version without reflashing. This is still in development. See the [firmware version and aircraft-support plan](../Firmware/Master%20Hex%20Files/README.md).

For the complete radio connection setup, file changes, and TekConnect instructions, follow the [DCS-BIOS setup guide](DCS-BIOS.md). The steps below cover programming the Teensy only.

For assembly checks, use the [Final Hardware Test](../Firmware/Test%20Code/ARC210_Button_Test/README.md). The individual TFT, button, encoder, and switch tests are optional troubleshooting tools, not additional required assembly steps.

## Ready to load the HEX file? Here's how you do it

1. Install and open **Teensy Loader**.
2. Open the supplied `ARC210_A-10C2_v0.1.2_Preview.hex` file.
3. Connect the Teensy 4.1 to your computer by USB.
4. Click **Auto** in Teensy Loader to enable automatic programming and rebooting.
5. Press the button on the Teensy if it does not enter programming mode automatically.
6. Wait for Teensy Loader to finish programming and reboot the Teensy. If you’re programming manually instead, click **Program**, then **Reboot**.

**What to expect while waiting for DCS-BIOS data:**

- **v0.1.3 Diagnostic HEX:** The splash screen is displayed while waiting for radio input.
- **v0.1.2 Preview HEX:** The display stays blank until DCS-BIOS sends powered-radio data.

Both are normal waiting states and do not, by themselves, mean the Teensy has frozen or programming failed. Connecting USB alone does not supply the radio state. Follow the [DCS-BIOS setup guide](DCS-BIOS.md), connect the panel in TekConnect, and power the aircraft and radio in DCS.


The current v0.1.2 preview shows its version and **A-10C2** aircraft label during the radio-switch startup information screen, after powered-radio data arrives. This new build still needs physical-panel and in-DCS testing; see the [release notes](../Firmware/Master%20Hex%20Files/README.md).
