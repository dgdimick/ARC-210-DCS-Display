[Back to the main project README](../README.md)

# Firmware and hardware testing

### DCS-BIOS firmware preview

The current HEX is available for testing the ARC-210 menu screens and navigation, including the HQ, COMSEC, and RADIO SETTINGS menus. This is a menu-system preview, not a finished radio implementation: some menu actions and synchronization still need work.

The current `Master_Program.ino.hex` works with DCS-BIOS while running DCS, but it is **display-only at this time**. It displays radio information from the game; physical panel controls do not yet operate the in-game radio.

The HQ MORE loop and detail screens are implemented. LOAD WOD has been tested against DCS: the displayed number matches, follows MLSK changes, and resets to 20 on re-entry in the tested session. MENU exits from the opening screen listing HQ MENUS / COMSEC / RADIO SETTINGS and is inactive on deeper pages.

Download [Master_Program.ino.hex](../Firmware/Master%20Hex%20Files/Master_Program.ino.hex). Read the [preview notes and required DCS-BIOS export changes](../Firmware/Master%20Hex%20Files/README.md) before testing. The display starts blank until it receives powered-radio data from DCS-BIOS.

### Rotary encoder test HEX download

Download [ARC210_Encoder_Check_Teensy41.hex](../Firmware/Test%20Code/ARC210_Encoder_Check_Teensy41.hex) for standalone testing of all six rotary encoders on a Teensy 4.1. The TFT displays each encoder's raw count, direction, and A/B input states. DCS is not required, and the backlight stays fully on using Teensy pin 4.

**Start with the TFT hello test** so you know the display is working before checking the encoders. A working TFT is required to see the results. If the screen stays blank, check the wiring notes and feel free to ask for help in Discussions. See the [test instructions](../Firmware/Test%20Code/README.md) and [pin layout](../Docs/ARC-210%20Teensy%204.1%20Pin%20layout.txt). Loading this HEX replaces the firmware currently on the Teensy.

The HEX file for the current state of the project is located in:

`Firmware/Master Hex Files/`

For installation steps, see [Loading the HEX File onto a Teensy 4.1](Loading-HEX-Files.md).
