[Back to the main project README](../README.md)

# Project updates

**Last updated: October 30, 2026 at 2:52 AM MDT (America/Denver)**
<!-- Refresh this timestamp whenever this page changes; use America/Denver local time. -->

**October 29, 2026 — PCB budget updated**

The PCB budget allowance is now approximately **$120** to reflect increased fabrication costs. The [estimated DIY purchasing cost](../parts/README.md#estimated-build-cost) is now **$320–$365 USD before shipping and tax**, including the faceplate. Earlier cost figures in the dated history below are superseded by this estimate.

**October 29, 2026 — Main Board v1.1 physical fit confirmed**

The Main Board fits! Its physical fit is now confirmed, alongside the Button Matrix, Rotary Encoder and Rotary Switch boards. Next comes assembling and electrically testing the manufactured boards.

**October 29, 2026 — Main Board v1.1: ground copper pours added**

Main Board **v1.1** adds GND-connected copper pours on both copper layers and removes isolated copper islands. The PCB, schematic revision and standalone Gerber/drill package are updated. This revision does not change the files already submitted for manufacture.

Current hardware status: PCB design is complete, and the boards have been ordered from JLCPCB for manufacture. Button Matrix v3.1, Rotary Encoder v1.4, Rotary Switch v2.0, and Main Board v1.1 source files and standalone Gerber/drill packages are published. Main Board v1.1 physical fit is confirmed. Current verification, assembly, and manufactured-board electrical testing remain pending. **The dated entries below record development history. Earlier circuit descriptions, missing-pad notes, and old board revisions are superseded by the current project files and instructions above.**

**October 29, 2026 — PCB design completed; boards sent for manufacture**

The PCB design has been completed and sent to **JLCPCB** for manufacture; the order has been placed and paid for. The standalone [Gerber and drill files](../PCBs/README.md#gerber-and-drill-downloads), including the [current Main Board v1.1 package](../PCBs/Master%20Board/Manufacturing/Main-Board-PCB-v1.1-Gerbers-Drill.zip), are available for builders. Once the boards arrive, the next steps are to assemble the boards and test the completed hardware; Main Board v1.1 physical fit is now confirmed.

**October 28, 2026 — Main Board placement and routing progress**

The latest [Main Board layout picture](../images/Main-PCB-Layout-2026-10-28.png) shows the Teensy 4.1, TFT and control connectors, SQL On/Off solder connections, and routing in progress. Component bodies face away from the faceplate on the back of the PCB. J9 is labelled **MODE** and J10 **MASTER**. A 26.2 mm circle marks the SQL switch body for spacing without adding electrical pads.

See the [Main Board README](../PCBs/Master%20Board/README.md#main-pcb-3d-preview) for the new picture and layout notes. The current saved PCB and schematic are now uploaded. October 29 checks after correcting the J4/TP1 values report zero ERC violations, zero DRC violations, zero unconnected items, and zero schematic/PCB mismatches under the saved settings. This picture shows the current working layout; Main Board v1.1 physical fit is confirmed. Final placement/routing review and current verification remain to be completed; the October 29 ERC/DRC and parity checks pass under the saved settings. At the time of this picture it was a draft; the current Main Board v1.1 fabrication files are now published.

**October 27, 2026 — Main PCB layout progress and Teensy 4.1 3D preview**

Initial component placement is progressing on the Main Board. The components are on the back of the board, with their bodies facing away from the faceplate. The draft includes the board outline, rotary-switch mounting hole and anti-rotation slot, four 3.5 mm mounting holes, and SQL On/Off solder-wire pads.

The Teensy 4.1 STEP model is now included and attached to U1 using a project-relative path. See the [new Main PCB 3D picture with the Teensy](../images/Main-PCB-Teensy-3D.png), or download the [Main Board project](../PCBs/Master%20Board/) and follow its [3D Viewer instructions](../PCBs/Master%20Board/README.md#teensy-41-in-the-3d-viewer).

The TFT uses the Teensy's 3.3 V supply directly, matching the tested wiring; the former protected 5 V circuit and C5/C6 are removed. **At the time of this update, placement, routing, current verification and the Main Board physical test fit were unfinished. Main Board v1.1 physical fit is now confirmed.** This historical layout-progress entry predates the published Main Board v1.1 fabrication files.

**October 27, 2026 — Main Board C5/C6 removed to match tested TFT wiring**

C5 (470 µF) and C6 (0.1 µF) have been removed from the [Main PCB draft and schematic](../PCBs/Master%20Board/) and the [parts BOM](../parts/BOM.csv). TFT VCC remains connected directly to the Teensy's 3.3 V supply, as used in the working build. C1/C2 and the associated rotary-input filters are retained. Placement and routing remain unfinished.

**October 27, 2026 — Main Board simplified to USB power and 3.3 V TFT supply**

The updated [Main Board PCB draft and schematic](../PCBs/Master%20Board/) are uploaded. The external protected 5 V branch and TFT power-selection jumper have been removed. TFT VCC now connects directly to the Teensy's 3.3 V supply, without the extra C5/C6 supply capacitors, matching the tested direct wiring. Brightness at 3.3 V is confirmed satisfactory.

The draft includes back-side component footprints, the board outline, rotary-switch mounting and anti-rotation cutouts, four 3.5 mm mounting holes, and SQL On/Off solder-wire pads TP1/TP2. ERC reports zero violations and the PCB matches the schematic; component placement, routing, current verification and physical test fit were unfinished at the time. Main Board v1.1 physical fit is now confirmed. This historical entry predates the published Main Board v1.1 fabrication files. Older dated updates below describe earlier circuit revisions.

**October 27, 2026 — Button Matrix PCB v3.1 finalized; test fit confirmed**

The **Button Matrix PCB v3.1 is the final design, and its physical test fit is confirmed**. The board edges were slightly too long and have been shortened; the printed fit check confirmed that the buttons are in the correct locations. The updated [KiCad files](../PCBs/Button%20Matrix/) and [v3.1 Gerber/drill manufacturing ZIP](../PCBs/Button%20Matrix/Manufacturing/Button-Matrix-PCB-v3.1-Gerbers-Drill.zip) are uploaded and ready for manufacture. Use v3.1 for new orders; it supersedes v3.0.

The final files pass ERC and DRC with zero reported violations, no unconnected items, and no schematic/PCB mismatches under the saved settings. Manufactured-board assembly and electrical testing remain pending. Only the Main Board PCB design remains to be completed.

**October 27, 2026 — Three PCB designs uploaded and ready for manufacture**

The earlier **Button Matrix PCB v3.0** (now superseded by v3.1), **Rotary Encoder PCB v1.4**, and **Rotary Switch PCB v2.0** were uploaded with their KiCad project files, Gerbers, and drill files. The manufacturing packages are ready to send to a PCB manufacturer; download them from the [PCB manufacturing files page](../PCBs/README.md#gerber-and-drill-downloads).

**Superseded by the v3.1 final-design update above:** the printed fit check confirmed button alignment, and the slightly long board edges were shortened. The rotary encoder and rotary switch designs have already been physically test-fitted. Testing assembled, manufactured boards remains to be completed.

**October 24, 2026 — Button PCB schematic now available in the public repository**

The then-current [Button Matrix v1.1 schematic and KiCad project](../PCBs/Button%20Matrix/) are now available publicly. The schematic passed ERC with zero violations under its saved settings. This is a schematic-only release; the Button PCB layout and routing remain unfinished. That schematic used separate four-pin row and column connectors; see the project README for the mapping to the Main Board’s eight-pin matrix header. This is the current unlit button matrix, not the proposed future Button LED PCB.

**October 24, 2026 — Main Board schematic now available in the public repository**

The [Main Board schematic and KiCad project](../PCBs/Master%20Board/) are now available in this public repository, with the custom symbol libraries needed to open them. Download the repository ZIP and keep the project folder together. This was a schematic-only release at the time. The current Main Board draft now includes the SQL solder pads and routing; see the October 29 check results above.

**October 24, 2026 — Optional SQL On/Off PCB and planned solder pads**

The **SQL On/Off PCB is optional** when using the solder-lug switch: wires can be soldered directly to the switch instead. This reduces the build from six PCBs to five. At the time of this update, labelled **SQL signal (GPIO 41) and GND solder pads** were planned. They are now implemented as TP1/TP2 and routed in the current Main Board draft. See the [direct-wiring notes](../parts/README.md#six-pcb-layout) for details.

**October 22, 2026 — Rotary switches work without input filters; position readings remain stable**

**Tested wiring:** Both seven-position rotary switches were tested and worked with each switch PCB’s J1 pin 2 connected directly to its Teensy input (GPIO 14 or GPIO 15), without the 220 Ω series resistor or 100 nF input-filter capacitor. The six 1 kΩ resistor-ladder resistors on each switch PCB were still fitted, and JP1 was left open. Some fluctuation was visible in the voltage readings on the TFT, but it did not affect the detected switch positions. This records the successful breadboard setup; the input-filter components shown in the Main Board schematic were not part of that test.

**October 22, 2026 — Future button-lighting option**

I may revisit button lighting in a future revision. This would require changes to the Master PCB to provide space for an SCR, the associated discrete components, and a lighting connector, along with the external 5 V power supply and its power-input and protection circuitry. It would also require a new Button LED PCB design, which is not currently planned. The **ARC-164 and ARC-186 projects will be completed first**, before I revisit this option.

**October 22, 2026 — Build cost estimate and button-switch update**

Added the initial DIY parts purchasing estimate, including the PC Flights faceplate, the correct 3.5-inch ILI9488 TFT display, and a provisional PCB allowance. **The original figures have been superseded:** use the [current parts estimate](../parts/README.md#estimated-build-cost), with an approximately **$120 PCB allowance** and **$320–$365 USD total before shipping and tax**. Manufacturing files for all four PCB designs are now published. The button switches are specified as **6 × 6 × 5 mm**, with 16 required per panel. See the [parts documentation and supplier link](../parts/README.md#current-button-switches) and [BOM](../parts/BOM.csv).

**October 22, 2026 — Discussions now open**

The [Discussions section](https://github.com/dgdimick/ARC-210-DCS-Display/discussions) is now open for questions and sharing builds. Join in to ask for help, share ideas, and post photos of your progress.

**October 22, 2026 — Shaft spacer v.5 clearance fix**

[Shaft_Spacer_v.5.stl](../Supporting%20STL%27s/Shaft_Spacer_v.5.stl) replaces v.4 to correct a clearance issue. The revised spacer has now been physically test-fitted and confirmed to fit and work.

**October 22, 2026 — All STLs finalized**

All STLs are now final. See the [Supporting STL files](../Supporting%20STL%27s/README.md) for the final versions and printing notes.

**October 22, 2026 — Button PCB work continues**

Work continues on the Button PCB.

**October 12, 2026 — Main Board schematic updated**

The updated [Main Board KiCad project](../PCBs/Master%20Board/) has been pushed to the Teensy repository. That schematic revision used one 14-pin connector matching the Rotary Encoder PCB and an eight-pin connector for the separate 4×4 button matrix. It includes corrected Teensy signal connections, the C106D SCR pin numbering and its project symbol library. In that superseded revision, a three-pin TFT power selector, **JP1**, selected **protected 5 V with pins 1–2** or **Teensy 3.3 V with pins 2–3**. That earlier selector required one jumper shunt, changed only with power removed. The selector and protected 5 V branch are absent from the current design. The schematic passed ERC with zero errors and warnings under its saved settings. The Main Board layout, routing and physical fit were unfinished at the time; Main Board v1.1 physical fit is now confirmed.

**October 12, 2026 — Rotary Encoder and Rotary Switch PCBs finalized; test fits confirmed**

The [Rotary Encoder PCB version 1.4](../PCBs/Rotary%20Encoders/) and [Rotary Switch PCB version 2.0](../PCBs/Rotary%20Switches/) are now **final designs**, and both have been **physically test-fitted**. See the [PCB status README](../PCBs/README.md). I have published **version 1.4** of the [Rotary Encoder KiCad project](../PCBs/Rotary%20Encoders/), with the latest saved PCB layout, updated board outline, v1.4 silkscreen label and [updated six-encoder 3D preview](../images/Rotary-Encoder-PCB-3D.png). Download the current project before building or ordering this board. The project includes the schematic, PCB, custom libraries and header wiring instructions. The version 1.3 check results documented in the project README are historical; the version 1.4 checks were subsequently rerun on October 27; see the Rotary Encoder README and manufacturing reports. I have confirmed that the printed rotary-encoder STL fits and all six encoders work in the final combined hardware test.

**October 10, 2026 — Splash-screen picture removed**

I removed `splash_screen.jpg` because [ARC-210-Face Plate.jpg](../images/ARC-210-Face%20Plate.jpg) is a better picture. The faceplate picture remains at the top of the [main README](../README.md).

**October 10, 2026 — Outdated Button PCB image removed**

I removed `Button_Ver2.0.jpg` because it does not show the final Button PCB. I am redesigning the 16-button board and removed the old picture to prevent confusion.

**October 10, 2026 — Final hardware test HEX**

The [final hardware test HEX](../Firmware/Test%20Code/ARC210_Final_Hardware_Test_Teensy41.hex) is now available for Teensy 4.1. This combined TFT test checks all 16 buttons, six rotary encoders, brightness controls, and both seven-position rotary switches on GPIO 14 and 15. All of these functions were confirmed working together on the panel. See the [test instructions](../Firmware/Test%20Code/ARC210_Button_Test/README.md).

**October 10, 2026 — Two PCBs remaining**

With the combined hardware test confirmed working, the remaining PCB work is the **Main Board** and a **redesign of the 16-button board** to improve button alignment with the faceplate.

**Updated October 10, 2026 — Rotary Switch PCB version 1.2 adds SQL On/Off support**

Two new 3D PCB pictures have been uploaded to the `images` directory: the [Rotary Switch PCB](../images/Rotary-Switch-PCB-3D.png) and [Rotary Encoder PCB](../images/Rotary-Encoder-PCB-3D.png). The rotary encoder PCB version 1.4 and rotary switch PCB version 2.0 are final designs, and both have been physically test-fitted. The corrected [Rotary Switch PCB project, version 2.0](../PCBs/Rotary%20Switches/), is now available with its schematic, PCB and custom libraries. Terminal 1 is used for the first position, and the PCB matches the corrected schematic. Version 2.0 uses a 27.99 mm circular board with the resistors and connector on the back. Its updated 3D preview shows the correct A12505RNCQ through-hole switch. Use the current version 2.0 files. I modified the PCB so it can also be used with the SQL On/Off switch. For SQL On/Off use, omit R1–R6 and solder across **JP1**, marked **ON/OFF** on the back of the PCB. JP1 connects the R1–R2 junction (R2 pad 1 / switch terminal 2) to GND; connect J1 pin 2 to a Teensy input with a pull-up. For the normal resistor ladder, install R1–R6 and leave JP1 open. The PCB pictures show the final rotary encoder and rotary switch designs.

Panel/button illumination LEDs have been dropped due to insufficient clearance with the TFT display. The [parts list](../parts/BOM.csv) now excludes the panel LEDs and their current-limiting resistors. The TFT display and its backlight remain. Existing schematic drawings may still show the former panel-lighting circuit.
