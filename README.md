# ARC-210 Radio Control Panel for DCS A-10C II using a 3.5" TFT SPI display and DCSBIOS

I’m building a working ARC-210 radio panel for the DCS A-10C II using a Teensy 4.1, a 3.5-inch ILI9488 TFT display, custom PCBs, and 3D-printed parts, with DCS-BIOS for live radio data and cockpit control. I’m sharing the files and what I learn along the way so you can build your own.

> **Disclaimer:** This hobby flight-simulation project is provided without warranty, subject to its licenses. Read the [full disclaimer](#disclaimer) before building or using it.

<p align="center">
  <img src="images/ARC-210-Face%20Plate.jpg" width="300" alt="ARC-210 Face Plate">
</p>

This project replicates the look and functionality of the **ARC-210 VHF/UHF radio** used in the A-10C II Warthog module for Digital Combat Simulator (DCS).

It is intended for use with a physical control panel powered by a Teensy 4.1.

[See the official DCS website](https://www.digitalcombatsimulator.com/en/)

> **Note:** This repository is now included in the A-10-Sim repository.

## Related radio project

I’m also planning an [ARC-186 COMM-VHF radio panel](https://github.com/dgdimick/ARC-186-DCS-Display) for the DCS A-10C II. Follow its repository for project updates and build plans.

## Questions and community builds

This is primarily a DIY project, and the files and build notes are here to help you make your own panel. Parts can be purchased from the linked suppliers. If you get stuck, feel free to ask in Discussions—I’m happy to help where I can.

**Building your own panel, or just looking around?** [Introduce yourself in the welcome discussion](https://github.com/dgdimick/ARC-210-DCS-Display/discussions/1) and tell us what you fly. Questions, ideas, and progress photos are all welcome—even if you’re only getting started.

Visit [GitHub Discussions](https://github.com/dgdimick/ARC-210-DCS-Display/discussions) to ask questions, share ideas, post build photos, and connect with other builders. Whether you are planning your first panel or already flying with one, you are welcome to join in!

## Features

- Interface modeled after the ARC-210 radio
- Powered by one Teensy 4.1
- ILI9488 3.5-inch SPI TFT display (480 × 320)
- Support for digital rotary encoders, rotary switches, and momentary switches
- **Planned button support:** All panel buttons will be wired, and their in-game functions will be supported wherever DCS-BIOS provides the necessary controls. The current HEX remains display-only.
- DCS-BIOS integration for in-game control and feedback
- ARC-210 startup and initialization screens
- Live frequency display from DCS-BIOS
- AM/FM modulation display
- Submenus nested within the SAT menus will be available with firmware 2.0.

## Teensy GPIO labels and KiCad pin numbers

**Use the numbers printed on the Teensy (or the matching GPIO labels on your breakout adapter) when following the firmware and wiring instructions.** KiCad uses a separate set of pin/pad numbers for the Teensy symbol and its matching `teensy:Teensy41` footprint. These include power and ground connections, so they are not the same as GPIO numbers.

| Teensy printed label / firmware GPIO | KiCad U1 pin / footprint pad |
| --- | ---: |
| GND (one of several ground connections) | 1 |
| 0 | 2 |
| 4 — TFT backlight | 6 |
| 14 / A0 — rotary-switch input | 36 |
| 15 / A1 — rotary-switch input | 37 |

For example, connect a rotary-switch signal to the Teensy connection marked **14/A0**, which is **KiCad pad 36**—not pad 14. In KiCad, read the symbol’s pin name and net label to identify the signal. Updating the PCB from the schematic with the matching symbol and footprint maps the connections to the correct physical locations. This pad mapping applies to the Teensy library supplied with this project; other libraries may use different numbering.

## Power and future button lighting

The painted buttons supplied with the PC Flights panel used for this build are opaque: light will not pass through them, so LEDs behind them would not illuminate their legends. Future backlighting would also require suitable light-transmitting replacement buttons.

The Teensy is powered by USB, and **TFT VCC connects directly to the Teensy's 3.3 V rail** (`TEENSY_3V3`, U1 pad 15). TFT brightness at 3.3 V has been confirmed satisfactory. The external protected 5 V input and Main Board JP1 power selector have been removed. C5 (470 µF) and C6 (0.1 µF) have been removed to match the tested direct Teensy-to-TFT wiring. C1/C2 and R1/R2 remain as the rotary-input filters. Keep total external 3.3 V consumption within PJRC's recommended 250 mA maximum; brightness confirmation is not a current measurement.

Future button lighting would require a separate power and driver design, suitable light-transmitting buttons, and a new Button LED PCB. The current Main Board has no external lighting-power circuit. This lighting revision is not currently planned; the other radio projects remain the priority.

<a id="six-pcb-layout"></a>

## PCB layout — five or six boards

The panel uses five required PCBs: one Main Controller, one Button Matrix, one Rotary Encoder, and two multi-position Rotary Switch boards. An optional SQL On/Off switch PCB brings the total to six; it can be omitted when wiring directly to the switch’s solder lugs.

The [shaft spacer v.5](Supporting%20STL%27s/Shaft_Spacer_v.5.stl) is **required in all installations** to support the **longer SQL On/Off switch shaft**, whether or not the optional PCB is fitted.

All boards are controlled by one Teensy 4.1:


- **Master PCB:** carries the USB-powered Teensy, 3.3 V TFT supply, display and control connections.
- **Button PCB:** carries the push-button switches behind the faceplate and connects to the master PCB.
- **Rotary Encoder PCB:** carries the rotary encoders and connects to the master PCB.
- **Rotary Switch PCBs:** the two seven-position switches each use a PCB. A third PCB can be used for the SQL On/Off switch for cleaner wiring and wire support, or omitted when wiring the solder-lug switch directly.

The three Rotary Switch PCBs use the same design and are interchangeable; the SQL On/Off board is optional. For the **SQL On/Off rotary switch PCB**, install **no resistors** (omit R1–R6) and bridge the small **JP1 solder pad**, marked **ON/OFF**, with solder. For the other 2 seven-position rotary switch PCBs, install the six resistors and leave JP1 open.

The button, rotary encoder, and rotary switch PCBs do not require additional microcontrollers. The Button Matrix PCB v3.1, Rotary Encoder PCB v1.4, and Rotary Switch PCB v2.0 are final designs. The remaining PCB design task is the Main Controller board.

**SQL On/Off direct-wiring option:** The SQL On/Off PCB is optional when using the solder-lug switch. You can solder wires directly to the switch’s common lug and the selected contact lug, then connect them to the Master board’s SQL signal (GPIO 41) and GND connections. Select the contact to match the panel’s SQL On/Off positions and configure GPIO 41 with a pull-up. No resistor ladder is needed for this option. Dedicated **TP1 (SQL signal, GPIO 41 / U1 pad 33)** and **TP2 (GND)** solder-wire pads are now included in the Main schematic and PCB draft. The optional SQL1 header remains available; final pad placement and routing are pending.

## Items that need to be completed

1. Some SAT menus are already complete. The remaining work is on some menus three or four levels deep, which will be completed in firmware 2.0.
2. Test the finished breadboard design with DCS-BIOS and the DCS A-10C II aircraft to ensure the panel works correctly while in DCS.
3. Verify TFT startup and full-brightness current on the Teensy's 3.3 V supply, keeping total external 3.3 V load within 250 mA. Brightness at 3.3 V has been confirmed satisfactory; the external protected 5 V circuit and Main Board JP1 selector have been removed.
4. Finish the Main Board PCB design.
5. Test-fit the Main PCB when its design is complete. The TFT, Button Matrix, Rotary Encoders, and Rotary Switches have already been physically checked; the final Button Matrix v3.1 physical test fit and button alignment are confirmed.
6. Publish the Main Board PCB layout and its Gerber/drill manufacturing package once the design is complete. The final Button Matrix v3.1, Rotary Encoder v1.4, and Rotary Switch v2.0 KiCad project files, schematics, Gerbers, drill files, and manufacturing ZIPs have already been uploaded; see the [PCB downloads](PCBs/README.md#gerber-and-drill-downloads).
7. Complete the final assembly instructions, wiring diagrams and updated parts list.
8. Document firmware installation and the required DCS-BIOS configuration.
9. Test the manufactured boards and run an extended reliability test.
10. Document how builders can source components from independent suppliers, order PCBs from a manufacturer, print the STL parts, and program their own Teensy. This project provides files and build guidance; I’d prefer to keep this a DIY project rather than sell parts, kits, or completed panels. That said, a few people have already asked for help, so if you’re stuck and need a hand, feel free to reach out—I’d be happy to discuss what might be possible.
11. Look at other aircraft using the ARC-210 and decide whether I want to spend the time branching this project to support them. Only a small number of DCS aircraft have the ARC-210, but other sim-pit builders may want a working panel instead of a sticker. If I decide to branch this project, the first additional aircraft supported will be the C-130J, since it is the only other aircraft using the ARC-210 that I currently own.
12. Consider button lighting only as a future redesign with a separate power/driver circuit, suitable translucent buttons, and a new Button LED PCB. The current USB/3.3 V Main Board does not include this circuitry.

## Project updates

**October 28, 2026 — Main Board placement and routing progress**

The latest [Main Board layout picture](images/Main-PCB-Layout-2026-10-28.png) shows the Teensy 4.1, TFT and control connectors, SQL On/Off solder connections, and routing in progress. Component bodies face away from the faceplate on the back of the PCB. J9 is labelled **MODE** and J10 **MASTER**. A 26.2 mm circle marks the SQL switch body for spacing without adding electrical pads.

See the [Main Board README](PCBs/Master%20Board/README.md#main-pcb-3d-preview) for the new picture and layout notes. The current saved PCB and schematic are now uploaded. Fresh checks report zero ERC violations and zero unconnected items, with zero DRC violations and two schematic/PCB value warnings remaining after the October 29 correction. This picture shows the current working layout; final placement, routing, design checks, current verification, and Main Board physical test fit remain to be completed. The Main Board is still a draft, with no manufacturing release.

**October 27, 2026 — Main PCB layout progress and Teensy 4.1 3D preview**

Initial component placement is progressing on the Main Controller PCB. The components are on the back of the board, with their bodies facing away from the faceplate. The draft includes the board outline, rotary-switch mounting hole and anti-rotation slot, four 3.5 mm mounting holes, and SQL On/Off solder-wire pads.

The Teensy 4.1 STEP model is now included and attached to U1 using a project-relative path. See the [new Main PCB 3D picture with the Teensy](images/Main-PCB-Teensy-3D.png), or download the [Main Board project](PCBs/Master%20Board/) and follow its [3D Viewer instructions](PCBs/Master%20Board/README.md#teensy-41-in-the-3d-viewer).

The TFT uses the Teensy's 3.3 V supply directly, matching the tested wiring; the former protected 5 V circuit and C5/C6 are removed. **Placement, routing, current verification, and the Main PCB physical test fit remain unfinished.** This is a layout-progress update, not a manufacturing release.

**October 27, 2026 — Main Board C5/C6 removed to match tested TFT wiring**

C5 (470 µF) and C6 (0.1 µF) have been removed from the [Main PCB draft and schematic](PCBs/Master%20Board/) and the [parts BOM](parts/BOM.csv). TFT VCC remains connected directly to the Teensy's 3.3 V supply, as used in the working build. C1/C2 and the associated rotary-input filters are retained. Placement and routing remain unfinished.

**October 27, 2026 — Main Board simplified to USB power and 3.3 V TFT supply**

The updated [Main Board PCB draft and schematic](PCBs/Master%20Board/) are uploaded. The external protected 5 V branch and TFT power-selection jumper have been removed. TFT VCC now connects directly to the Teensy's 3.3 V supply, without the extra C5/C6 supply capacitors, matching the tested direct wiring. Brightness at 3.3 V is confirmed satisfactory.

The draft includes back-side component footprints, the board outline, rotary-switch mounting and anti-rotation cutouts, four 3.5 mm mounting holes, and SQL On/Off solder-wire pads TP1/TP2. ERC reports zero violations and the PCB matches the schematic; component placement, routing, current verification, and physical test fit remain unfinished. This is not a manufacturing release. Older dated updates below describe earlier circuit revisions.

**October 27, 2026 — Button Matrix PCB v3.1 finalized; test fit confirmed**

The **Button Matrix PCB v3.1 is the final design, and its physical test fit is confirmed**. The board edges were slightly too long and have been shortened; the printed fit check confirmed that the buttons are in the correct locations. The updated [KiCad files](PCBs/Button%20Matrix/) and [v3.1 Gerber/drill manufacturing ZIP](PCBs/Button%20Matrix/Manufacturing/Button-Matrix-PCB-v3.1-Gerbers-Drill.zip) are uploaded and ready for manufacture. Use v3.1 for new orders; it supersedes v3.0.

The final files pass ERC and DRC with zero reported violations, no unconnected items, and no schematic/PCB mismatches under the saved settings. Manufactured-board assembly and electrical testing remain pending. Only the Main Board PCB design remains to be completed.

**October 27, 2026 — Three PCB designs uploaded and ready for manufacture**

The **Button Matrix PCB v3.0**, **Rotary Encoder PCB v1.4**, and **Rotary Switch PCB v2.0** have been uploaded with their KiCad project files, Gerbers, and drill files. The manufacturing packages are ready to send to a PCB manufacturer; download them from the [PCB manufacturing files page](PCBs/README.md#gerber-and-drill-downloads).

**Superseded by the v3.1 final-design update above:** the printed fit check confirmed button alignment, and the slightly long board edges were shortened. The rotary encoder and rotary switch designs have already been physically test-fitted. Testing assembled, manufactured boards remains to be completed.

**October 24, 2026 — Button PCB schematic now available in the public repository**

The [Button Matrix v1.1 schematic and KiCad project](PCBs/Button%20Matrix/) are now available publicly. The schematic passed ERC with zero violations under its saved settings. This is a schematic-only release; the Button PCB layout and routing remain unfinished. The current schematic uses separate four-pin row and column connectors; see the project README for the mapping to the Master Board’s eight-pin matrix header. This is the current unlit button matrix, not the proposed future Button LED PCB.

**October 24, 2026 — Master Board schematic now available in the public repository**

The [Master Board schematic and KiCad project](PCBs/Master%20Board/) are now available in this public repository, with the custom symbol libraries needed to open them. Download the repository ZIP and keep the project folder together. This is a schematic release; the Master PCB layout and routing are not finished, and the planned SQL direct-wiring solder pads have not yet been added.

**October 24, 2026 — Optional SQL On/Off PCB and planned solder pads**

The **SQL On/Off PCB is optional** when using the solder-lug switch: wires can be soldered directly to the switch instead. This reduces the build from six PCBs to five. I plan to add labelled **SQL signal (GPIO 41) and GND solder pads** to the Master PCB to support this direct-wiring option. These pads **have not yet been added** to the PCB design. See the [direct-wiring notes](parts/README.md#six-pcb-layout) for details.

**October 22, 2026 — Rotary switches work without input filters; position readings remain stable**

**Tested wiring:** Both seven-position rotary switches were tested and worked with each switch PCB’s J1 pin 2 connected directly to its Teensy input (GPIO 14 or GPIO 15), without the 220 Ω series resistor or 100 nF input-filter capacitor. The six 1 kΩ resistor-ladder resistors on each switch PCB were still fitted, and JP1 was left open. Some fluctuation was visible in the voltage readings on the TFT, but it did not affect the detected switch positions. This records the successful breadboard setup; the input-filter components shown in the master schematic were not part of that test.

**October 22, 2026 — Future button-lighting option**

I may revisit button lighting in a future revision. This would require changes to the Master PCB to provide space for an SCR, the associated discrete components, and a lighting connector, along with the external 5 V power supply and its power-input and protection circuitry. It would also require a new Button LED PCB design, which is not currently planned. The **ARC-164 and ARC-184 projects will be completed first**, before I revisit this option.

**October 22, 2026 — Build cost estimate and button-switch update**

Added a [DIY parts purchasing estimate](parts/README.md#estimated-build-cost) of approximately **$275–$320 USD before shipping and tax**, including the PC Flights faceplate, the correct 3.5-inch ILI9488 TFT display, and a **$75 allowance for the six PCBs**. PCB pricing remains provisional until the main and button board layouts are finished. The button switches are now specified as **6 × 6 × 5 mm**, with 16 required per panel. The [parts documentation and supplier link](parts/README.md#current-button-switches) and [BOM](parts/BOM.csv) have been updated.

**October 22, 2026 — Discussions now open**

The [Discussions section](https://github.com/dgdimick/ARC-210-DCS-Display/discussions) is now open for questions and sharing builds. Join in to ask for help, share ideas, and post photos of your progress.

**October 22, 2026 — Shaft spacer v.5 clearance fix**

[Shaft_Spacer_v.5.stl](Supporting%20STL%27s/Shaft_Spacer_v.5.stl) replaces v.4 to correct a clearance issue. The revised spacer has now been physically test-fitted and confirmed to fit and work.

**October 22, 2026 — All STLs finalized**

All STLs are now final. See the [Supporting STL files](Supporting%20STL%27s/README.md) for the final versions and printing notes.

**October 22, 2026 — Button PCB work continues**

Work continues on the Button PCB.

**October 12, 2026 — Master Board schematic updated**

The updated [Master Board KiCad project](PCBs/Master%20Board/) has been pushed to the Teensy repository. The schematic now uses one 14-pin connector matching the Rotary Encoder PCB and an eight-pin connector for the separate 4×4 button matrix. It includes corrected Teensy signal connections, the C106D SCR pin numbering and its project symbol library. A three-pin TFT power selector, **JP1**, selects **protected 5 V with pins 1–2** or **Teensy 3.3 V with pins 2–3**. Fit only one jumper shunt and remove power before changing it. The schematic passed ERC with zero errors and warnings under its saved settings. The Main PCB layout, routing and physical test fit remain unfinished.

**October 12, 2026 — Rotary Encoder and Rotary Switch PCBs finalized; test fits confirmed**

The [Rotary Encoder PCB version 1.4](PCBs/Rotary%20Encoders/) and [Rotary Switch PCB version 2.0](PCBs/Rotary%20Switches/) are now **final designs**, and both have been **physically test-fitted**. See the [PCB status README](PCBs/README.md). I have published **version 1.4** of the [Rotary Encoder KiCad project](PCBs/Rotary%20Encoders/), with the latest saved PCB layout, updated board outline, v1.4 silkscreen label and [updated six-encoder 3D preview](images/Rotary-Encoder-PCB-3D.png). Download the current project before building or ordering this board. The project includes the schematic, PCB, custom libraries and header wiring instructions. The version 1.3 check results documented in the project README are historical; electrical and PCB design checks have not been rerun for this upload. I have confirmed that the printed rotary-encoder STL fits and all six encoders work in the final combined hardware test.

**October 10, 2026 — Splash-screen picture removed**

I removed `splash_screen.jpg` because [ARC-210-Face Plate.jpg](images/ARC-210-Face%20Plate.jpg) is a better picture. The faceplate picture remains at the top of this README.

**October 10, 2026 — Outdated Button PCB image removed**

I removed `Button_Ver2.0.jpg` because it does not show the final Button PCB. I am redesigning the 16-button board and removed the old picture to prevent confusion.

**October 10, 2026 — Final hardware test HEX**

The [final hardware test HEX](Firmware/Test%20Code/ARC210_Final_Hardware_Test_Teensy41.hex) is now available for Teensy 4.1. This combined TFT test checks all 16 buttons, six rotary encoders, brightness controls, and both seven-position rotary switches on GPIO 14 and 15. All of these functions were confirmed working together on the panel. See the [test instructions](Firmware/Test%20Code/ARC210_Button_Test/README.md).

**October 10, 2026 — Two PCBs remaining**

With the combined hardware test confirmed working, the remaining PCB work is the **Main Controller board** and a **redesign of the 16-button board** to improve button alignment with the faceplate.

**Updated October 10, 2026 — Rotary Switch PCB version 1.2 adds SQL On/Off support**

Two new 3D PCB pictures have been uploaded to the `images` directory: the [Rotary Switch PCB](images/Rotary-Switch-PCB-3D.png) and [Rotary Encoder PCB](images/Rotary-Encoder-PCB-3D.png). The rotary encoder PCB version 1.4 and rotary switch PCB version 2.0 are final designs, and both have been physically test-fitted. The corrected [Rotary Switch PCB project, version 2.0](PCBs/Rotary%20Switches/), is now available with its schematic, PCB and custom libraries. Terminal 1 is used for the first position, and the PCB matches the corrected schematic. Version 2.0 uses a 27.99 mm circular board with the resistors and connector on the back. Its updated 3D preview shows the correct A12505RNCQ through-hole switch. Use the current version 2.0 files. I modified the PCB so it can also be used with the SQL On/Off switch. For SQL On/Off use, omit R1–R6 and solder across **JP1**, marked **ON/OFF** on the back of the PCB. JP1 connects the R1–R2 junction (R2 pad 1 / switch terminal 2) to GND; connect J1 pin 2 to a Teensy input with a pull-up. For the normal resistor ladder, install R1–R6 and leave JP1 open. The PCB pictures show the final rotary encoder and rotary switch designs.

Panel/button illumination LEDs have been dropped due to insufficient clearance with the TFT display. The [parts list](parts/BOM.csv) now excludes the panel LEDs and their current-limiting resistors. The TFT display and its backlight remain. Existing schematic drawings may still show the former panel-lighting circuit.

## Firmware and hardware testing

### DCS-BIOS firmware preview

The current HEX is available for testing the ARC-210 menu screens and navigation, including the HQ, COMSEC, and RADIO SETTINGS menus. This is a menu-system preview, not a finished radio implementation: some menu actions and synchronization still need work.

The current `Master_Program.ino.hex` works with DCS-BIOS while running DCS, but it is **display-only at this time**. It displays radio information from the game; physical panel controls do not yet operate the in-game radio.

The HQ MORE loop and detail screens are implemented. LOAD WOD has been tested against DCS: the displayed number matches, follows MLSK changes, and resets to 20 on re-entry in the tested session. MENU exits from the opening screen listing HQ MENUS / COMSEC / RADIO SETTINGS and is inactive on deeper pages.

Download [Master_Program.ino.hex](Firmware/Master%20Hex%20Files/Master_Program.ino.hex). Read the [preview notes and required DCS-BIOS export changes](Firmware/Master%20Hex%20Files/README.md) before testing. The display starts blank until it receives powered-radio data from DCS-BIOS.

### Rotary encoder test HEX download

Download [ARC210_Encoder_Check_Teensy41.hex](Firmware/Test%20Code/ARC210_Encoder_Check_Teensy41.hex) for standalone testing of all six rotary encoders on a Teensy 4.1. The TFT displays each encoder's raw count, direction, and A/B input states. DCS is not required, and the backlight stays fully on using Teensy pin 4.

**Start with the TFT hello test** so you know the display is working before checking the encoders. A working TFT is required to see the results. If the screen stays blank, check the wiring notes and feel free to ask for help in Discussions. See the [test instructions](Firmware/Test%20Code/README.md) and [pin layout](Docs/ARC-210%20Teensy%204.1%20Pin%20layout.txt). Loading this HEX replaces the firmware currently on the Teensy.

The HEX file for the current state of the project is located in:

`Firmware/Master Hex Files/`

If you own a Teensy 4.1, you may already know how to install a HEX file. If not, here are the steps.

## Loading the HEX File onto a Teensy 4.1

1. Install and open **Teensy Loader, you can find it in the firmware directory**.
2. Open the supplied `Master_Program.ino.hex` file.
3. Connect the Teensy 4.1 to your computer by USB.
4. Press the button on the Teensy if it does not enter programming mode automatically.
5. Click **Program** in Teensy Loader.
6. Reboot the Teensy.

## ARC-210 Bench Testing App

The [working ARC-210 version of dcsBiosDebug](https://github.com/dgdimick/dcsBiosDebug/tree/arc210-working) is maintained in a separate repository. It provides buttons for menu testing and separate Frequency, Secondary, and Master controls for sending simulated DCS-BIOS data to your Teensy without running DCS.

Download the **arc210-working** branch using **Code → Download ZIP**, extract it, and keep its `icons` folder beside the Python script. With Python 3 and Tkinter installed, open a terminal in that folder and run:

```cmd
python -m pip install numpy pyserial Pillow
python dcsBiosDebug.py
```

Use the Python script, including the `.py` extension; the original bundled executable does not include the ARC-210 controls. Select your Teensy's serial port and click **Connect**. Choose **2 - TR** and click **Set Master** for the normal radio switch position, or **0 - OFF** to test power off.

See the [full testing instructions and compatibility notes](https://github.com/dgdimick/dcsBiosDebug/blob/arc210-working/ARC210_TESTING.md). The shortcuts use fixed A-10C II addresses and send data to the hardware, not commands to DCS. Some firmware states require additional exports through the normal instrument controls.

## Project progress and beta testing

Here is a short video showing the progress I have made so far:

[ARC-210 Project Progress Video](https://drive.google.com/file/d/162CAG3RlfPK6QnCSb0p5lkmVlXDZjPrU/view)

Want to help test the project? If you have a **Teensy 4.1** and a compatible **3.5-inch SPI TFT display**, I’d welcome your feedback on the menus, screen layouts, and fonts. Share what you find in [Discussions](https://github.com/dgdimick/ARC-210-DCS-Display/discussions).

The `Teensy_TFT_Hello_Works.ino` file in the `Firmware` directory contains the correct display pin assignments and can be used to verify that your display is connected correctly.

## Tools Needed

- Hot glue gun, or an electronics-grade, neutral-cure silicone adhesive such as **MG Chemicals 1035**, for securing wires and the TFT display
- Soldering iron
- 3D printer, or access to one
- Flush wire cutters
- USB Micro-B cable for programming the Teensy 4.1 and connecting the unit to the computer

## Parts

See the [parts directory](parts/) for the [component list (BOM)](parts/BOM.csv), hardware supplier links, and switch-fit and compatibility notes.

## Supporting STL Files

The `Supporting STL's` directory includes:

- Knobs for rotary encoders and rotary switches
- Mounting hardware for the TFT screen and PCBs
- Brackets for panel alignment

The [shaft spacer v.5](Supporting%20STL%27s/Shaft_Spacer_v.5.stl) is **required in all installations** to support the **longer SQL On/Off switch shaft**, whether using the optional switch PCB or wiring directly to the switch’s solder lugs.

All STL files are intended to be print-ready for FDM printers using a 0.4 mm nozzle. Resin/SLA printers may require different settings or scaling.

## Software

- Written in Arduino C++
- Uses DCS-BIOS for communication with DCS
- Firmware and test files are maintained in this repository

## Why I had to use a Teensy

The ARC-210 panel needs a lot of GPIO (general-purpose input/output) pins. It is not just driving a display: the same controller also has to read the knobs and switches, scan the buttons, and control the TFT backlight.

- Each rotary encoder needs two input pins to detect movement and direction.
- The 16 push buttons use a 4 × 4 matrix, which still needs eight GPIO pins for its rows and columns.
- The rotary-switch resistor ladders need analog inputs, and the squelch switch needs another input.
- The SPI TFT needs clock and data connections plus control signals for chip select, reset, and data/command selection.
- The TFT display backlight needs a control output.

These connections add up quickly. I chose the Teensy 4.1 because it gives this design enough pins to connect the controls and display directly, without adding GPIO expanders or another controller. Using one controller for the five- or six-board build also keeps the wiring and firmware easier to manage.

### Could I have used several Arduinos?

Yes. I could have split the buttons and switches onto one Arduino, the rotary encoders onto another, and the TFT onto a controller with enough processing speed and memory for the display. Depending on the DCS-BIOS connection setup, the boards could use separate USB connections or communicate through a main controller.

That would provide more GPIO, but it would also mean more wiring, connections, and separate firmware to maintain. Splitting the controls across boards would not increase the memory or processing speed of the board driving the TFT. An Uno or Mega would still have its own display limitations.

I chose the Teensy 4.1 because it combines the GPIO, processing speed, and memory needed for this design on one board. Several Arduinos were an option; one Teensy keeps this build simpler.

The standard processor clock speeds are:

| Board | CPU clock speed |
| --- | ---: |
| [Teensy 4.1](https://www.pjrc.com/store/teensy41.html) | **600 MHz** |
| [Arduino Uno R3](https://docs.arduino.cc/hardware/uno-rev3/) | **16 MHz** |
| [Arduino Mega 2560 Rev3](https://docs.arduino.cc/hardware/mega-2560/) | **16 MHz** |

The Teensy 4.1 has **37.5 times the CPU clock frequency** of these classic Arduino boards. That is a clock-speed comparison, not a measured 37.5-times improvement in screen refresh rate; processor architecture, memory, SPI speed, and the display code also affect the result.

Display response speed was another major factor in my choice. Compared with classic Arduino Uno and Mega boards, the Teensy 4.1 provides much more processing headroom for drawing the TFT while handling radio updates and controls. I would not expect those older boards to deliver the same screen response with this display and firmware. Actual refresh speed also depends on the SPI connection, display library, and drawing code; this comparison is not a claim about every Arduino model.

### The same Arduino programming workflow

The Teensy is programmed using the same **Arduino IDE** and **`.ino` sketches** used for Arduino boards. The familiar editor, C++ sketch structure, and `setup()` / `loop()` workflow remain the same, so there is no need to learn a different programming environment for this project.

Install [Teensy board support](https://www.pjrc.com/teensy/td_download.html) and select Teensy 4.1 in the IDE. [Teensy Loader](https://www.pjrc.com/teensy/loader.html) handles uploading the compiled firmware and is integrated with the Arduino upload workflow. To use the precompiled `Master_Program.ino.hex` supplied here, simply open it in Teensy Loader and program the board; you do not need to compile the sketch yourself.

The programming workflow is familiar, although pin assignments and hardware-specific libraries still need to match the Teensy rather than an Uno or Mega.

### Cost: one Teensy versus three Arduinos

For a board-only comparison, these US-dollar prices were checked on September 24, 2026:

| Option | Price per board | Quantity | Total |
| --- | ---: | ---: | ---: |
| [Teensy 4.1 without Ethernet — SparkFun](https://www.sparkfun.com/teensy-4-1-without-ethernet.html) | $29.60 | 1 | **$29.60** |
| [Official Arduino Uno R3 — Arduino US store](https://store-usa.arduino.cc/products/arduino-uno-rev3) | $27.60 | 3 | **$82.80** |

At those listed prices, one Teensy costs **$53.20 less** than three official Uno R3 boards, before tax, shipping, cables, headers, or other accessories. Lower-cost Arduino-compatible boards can change the comparison substantially. This is an illustrative cost comparison, not a claim that three Unos would run the current display firmware or provide equivalent screen performance. Prices may change.

![Teensy 4.1 schematic showing the panel connections](Docs/Why%20I%20used%20a%20Teensy.png)

The numbers around this schematic symbol are KiCad pad numbers; use the signal labels and the project wiring documentation to identify the corresponding Teensy GPIO pins.

## Directories

- `ARC-210/` — project root
- `ARC-210/Firmware/` — firmware and test files
- `ARC-210/Firmware/Boot Loader/` — precompiled Teensy HEX files for loading with Teensy Loader or TyTools
- [`parts/`](parts/) — component list, hardware supplier links, and compatibility notes
- `ARC-210/Docs/` — schematics, diagrams, and documentation
- `ARC-210/images/` — project images
- `ARC-210/Supporting STL's/` — 3D-printable knobs, bezels, brackets, mounts, and other parts

## PC Flights affiliation

I am not affiliated with [PC Flights](https://pcflights.com/) in any way. I simply chose to use their panels for my own cockpit projects. PC Flights has supplied me with a drawing file to assist with the Button PCB layout.

## Disclaimer

This is a hobby flight-simulation project, not equipment intended for use in real aircraft. Software, firmware, PCB designs, wiring information, and printable parts are provided "as is," without warranty, subject to their respective licenses.

Users are responsible for verifying compatibility, wiring, supply voltages, assembly, and safe operation before use. To the maximum extent permitted by applicable law, the authors and contributors disclaim liability for injury, equipment damage, data loss, or other losses arising from use of this project.

## Licensing

- **PCBs:** CERN Open Hardware Licence Version 2 - Permissive (CERN-OHL-P-2.0)
- **Teensy firmware:** MIT License
- **STL files:** Creative Commons Attribution 4.0 International (CC BY 4.0)

See the `Docs` directory for copies of the applicable licenses.
