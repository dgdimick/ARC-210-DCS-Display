[Back to the main project README](../README.md)

# Firmware and Hardware Information

Technical information and build resources for the ARC-210 panel.

## Teensy GPIO labels and KiCad pin numbers

[Read the Teensy GPIO and KiCad pin guide](Teensy-GPIO.md) before wiring the panel or working with the PCB files.

## Power and future button lighting

[Read the power and lighting notes](Power-and-Lighting.md) for USB power, the TFT supply, and future button-lighting requirements.

## PCB layout — five or six boards

[View the PCB layout page](../PCBs/PCB-Layout.md) for the mockup photo, board descriptions, and optional SQL On/Off direct-wiring details.

## Loading the HEX File onto a Teensy 4.1

[Read the HEX loading instructions](Loading-HEX-Files.md) to program the Teensy 4.1.

## ARC-210 Bench Testing App

[View the ARC-210 Bench Testing App guide](Bench-Testing-App.md) to test the panel with simulated DCS-BIOS data without running DCS.

## Tools Needed

[View the tools needed](Tools-Needed.md) to build and program the panel.

## Build guide

Start with the [step-by-step build guide](Build%20Guide/README.md) for parts, printing, PCB assembly, wiring, and hardware testing. Unfinished design and validation steps are marked **pending**.

## Parts

See the [parts directory](../parts/) for the [component list (BOM)](../parts/BOM.csv), hardware supplier links, and switch-fit and compatibility notes.

## Supporting STL Files

The `Supporting STL's` directory includes:

- Knobs for rotary encoders and rotary switches
- Mounting hardware for the TFT screen and PCBs
- Brackets for panel alignment

The [shaft spacer v.5](../Supporting%20STL%27s/Shaft_Spacer_v.5.stl) is **required in all installations** to support the **longer SQL On/Off switch shaft**, whether using the optional switch PCB or wiring directly to the switch’s solder lugs.

Print **six [Rotary Encoder spacers v.1](../Supporting%20STL%27s/Rotary_Encoder_Spacer_v.1.stl)**, one for each encoder, to center the encoder threads in the faceplate holes.

All STL files are intended to be print-ready for FDM printers using a 0.4 mm nozzle. Resin/SLA printers may require different settings or scaling.

## Software

- Written in Arduino C++
- Uses DCS-BIOS for communication with DCS
- Firmware and test files are maintained in this repository

## Why I had to use a Teensy

[Read why I chose the Teensy 4.1](Why-Teensy.md) for the GPIO requirements, display performance, programming workflow, and cost comparison.

## Firmware and hardware testing

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
