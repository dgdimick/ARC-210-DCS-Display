[Back to the main project README](../README.md)

# Firmware and hardware information

**Last updated: October 30, 2026 at 9:14 PM MDT (America/Denver)**
<!-- Refresh this timestamp whenever this page changes; use the actual current America/Denver date and time, including MST or MDT. -->

I’ve gathered the wiring, hardware, firmware, and testing resources for my ARC-210 panel here.

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

## Tools needed

[View the tools needed](Tools-Needed.md) to build and program the panel.

## Build guide

Start with the [step-by-step build guide](Build%20Guide/README.md) for parts, printing, PCB assembly, wiring, and hardware testing. Unfinished design and validation steps are marked **pending**.

## Parts

See the [parts directory](../parts/) for the [component list (BOM)](../parts/BOM.csv), hardware supplier links, and switch-fit and compatibility notes.

## Supporting STL Files

**I have printed the complete 17-part layout at 100% scale, and all parts passed test fitting. I consider the current STL designs final.** Please keep checking [Project Updates](Project-Updates.md) for changes.

The [complete master STL and 3MF](../Supporting%20STL%27s/README.md#complete-17-part-print-set) contain **nine knobs, one display bracket, six encoder spacers, and one SQL shaft spacer**. Print one set at **100% scale**. Individual files remain available.

The [shaft spacer v.5](../Supporting%20STL%27s/Shaft_Spacer_v.5.stl) is **required in all installations** to support the **longer SQL On/Off switch shaft**, whether using the optional switch PCB or wiring directly to the switch’s solder lugs.

Print **six [Rotary Encoder spacers v.1](../Supporting%20STL%27s/Rotary_Encoder_Spacer_v.1.stl)**, one for each encoder, to center the encoder threads in the faceplate holes.

All STL files are intended to be print-ready for FDM printers using a 0.4 mm nozzle. Resin/SLA printers may require different settings or scaling.

## Software

- Written in Arduino C++
- Uses DCS-BIOS for communication with DCS
- I keep the firmware and test files in this repository

### DCS-BIOS connections

[Read my DCS-BIOS setup and connection guide](DCS-BIOS.md) for the DCS-Skunkworks project, TekConnect downloads, and the ARC-210 export changes.

## Why I had to use a Teensy

[Read why I chose the Teensy 4.1](Why-Teensy.md) for the GPIO requirements, display performance, programming workflow, and cost comparison.

## Loading the current working HEX file

1. Download [Master_Program.ino.hex](../Firmware/Master%20Hex%20Files/Master_Program.ino.hex), the current radio display/menu firmware.
2. Read the [firmware preview notes](../Firmware/Master%20Hex%20Files/README.md) and follow the [DCS-BIOS setup guide](DCS-BIOS.md) for installation, file changes, and TekConnect.
3. Follow the [HEX loading instructions](Loading-HEX-Files.md) to program the Teensy 4.1. This replaces any hardware-test firmware.
4. Reconnect the DCS-BIOS serial bridge after programming and supply powered-radio data from DCS, or use the [ARC-210 Bench Testing App](Bench-Testing-App.md). A blank screen before powered-radio data arrives is expected.

### Current firmware capabilities and limitations

The current HEX is available for testing the ARC-210 menu screens and navigation, including the HQ, COMSEC, and RADIO SETTINGS menus. This is a menu-system preview, not a finished radio implementation: some menu actions and synchronization still need work.

The current `Master_Program.ino.hex` works with DCS-BIOS while running DCS, but it is **display-only at this time**. It displays radio information from the game; physical panel controls do not yet operate the in-game radio.

The HQ MORE loop and detail screens are implemented. LOAD WOD has been tested against DCS: the displayed number matches, follows MLSK changes, and resets to 20 on re-entry in the tested session. MENU exits from the opening screen listing HQ MENUS / COMSEC / RADIO SETTINGS and is inactive on deeper pages.

Download [Master_Program.ino.hex](../Firmware/Master%20Hex%20Files/Master_Program.ino.hex). Read the [firmware preview notes](../Firmware/Master%20Hex%20Files/README.md) and complete the [DCS-BIOS setup guide](DCS-BIOS.md) before testing. The display starts blank until it receives powered-radio data from DCS-BIOS.

## Firmware and hardware testing

Start with the TFT hello test, then use the individual tests to troubleshoot or the combined test to check the controls together. These hardware tests run without DCS. Loading a test replaces the firmware currently on the Teensy.

| Test | Files | Instructions |
| --- | --- | --- |
| TFT hello / display setup | [Sketch](../Firmware/Test%20Code/Teenys_TFT_Hello_Works/Teenys_TFT_Hello_Works.ino) — compile and upload; no precompiled HEX is supplied | [Display setup and compile instructions](../Firmware/Test%20Code/Teenys_TFT_Hello_Works/README.md) |
| Six rotary encoders | [ARC210_Encoder_Check_Teensy41.hex](../Firmware/Test%20Code/ARC210_Encoder_Check_Teensy41.hex) | [Encoder test instructions](../Firmware/Test%20Code/README.md) |
| Earlier button-matrix test | [ARC210_Button_Test_Teensy41.hex](../Firmware/Test%20Code/ARC210_Button_Test_Teensy41.hex) | [Current button and combined-test documentation](../Firmware/Test%20Code/ARC210_Button_Test/README.md) |
| Seven-position rotary switch | [HEX](../Firmware/Test%20Code/ARC210_Rotary_Switch_Test/ARC210_Rotary_Switch_Test.ino.hex) · [Sketch](../Firmware/Test%20Code/ARC210_Rotary_Switch_Test/ARC210_Rotary_Switch_Test.ino) | [Rotary-switch instructions](../Firmware/Test%20Code/ARC210_Rotary_Switch_Test/README.md) |
| Final combined hardware test: 16 buttons, six encoders, TFT brightness, and two seven-position switches | [ARC210_Final_Hardware_Test_Teensy41.hex](../Firmware/Test%20Code/ARC210_Final_Hardware_Test_Teensy41.hex) · [Current combined-test sketch](../Firmware/Test%20Code/ARC210_Button_Test/ARC210_Button_Test.ino) | [Combined-test instructions](../Firmware/Test%20Code/ARC210_Button_Test/README.md) |

The button-test folder now documents the combined test; its current sketch is not presented as the source for the earlier button-only HEX. See the [complete test-code directory](../Firmware/Test%20Code/) for all published test files and the [pin layout](ARC-210%20Teensy%204.1%20Pin%20layout.txt) for wiring. The encoder test displays raw counts, direction, and A/B states on the TFT, so confirm the display works first.
