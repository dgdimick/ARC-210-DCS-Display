# ARC-210 Rotary Encoder PCB

Published October 10, 2026. KiCad 10 project.

I have checked this six-encoder PCB against its schematic. The electrical check reported zero errors and warnings; the PCB check reported zero violations, zero unconnected pads and zero schematic parity issues under the project's saved check settings. Courtyard and certain footprint checks are disabled in those settings.

I printed the rotary-encoder STL and confirmed that it fits. I have also confirmed all six encoders working in the combined hardware test. A manufactured PCB still needs assembly and testing.

## Open the project

Download this folder and keep its contents together. Open `Rotary Encoders.kicad_pro` in KiCad 10. The custom symbol and footprint libraries are included and use project-relative paths. Install KiCad's standard symbol and footprint libraries as well.

Supplier encoder 3D models are optional and are not bundled. Existing model references now use project-relative paths: place the corresponding `.stp` files beside the project if you have them. The PEC11R model is a visual substitute; use the PEC11H part dimensions for mechanical checks. Missing models do not prevent opening or manufacturing the board.

## Parts and connections

- Six Bourns PEC11H-4220F-S0024 rotary encoders.
- J1: 14-pin header; use the assigned footprint to choose the connector.
- Both J1 pins 13 and 14 connect to GND, as do encoder common contacts and metal mounting tabs.
- The encoders' push-switch contacts S1 and S2 are deliberately unused and marked no-connect.

| J1 pin | Connection |
| --- | --- |
| 1 | SW1 B |
| 2 | SW1 A |
| 3 | SW2 A |
| 4 | SW2 B |
| 5 | SW3 B |
| 6 | SW3 A |
| 7 | SW4 A |
| 8 | SW4 B |
| 9 | SW5 B |
| 10 | SW5 A |
| 11 | SW6 B |
| 12 | SW6 A |
| 13 | GND (encoder commons and mounting tabs) |
| 14 | GND (encoder commons and mounting tabs) |

The tested physical Teensy GPIO pairs are: SW1 = 16/17, SW2 = 28/29, SW3 = 20/21, SW4 = 22/23, SW5 = 24/25 and SW6 = 26/27. Ensure all encoder commons share Teensy GND. The final [combined hardware test HEX](../../Firmware/Test%20Code/ARC210_Final_Hardware_Test_Teensy41.hex) provides counts and A/B diagnostics.

## Manufacturing files

This upload contains the editable project. Export copper, silkscreen, solder-mask and Edge.Cuts Gerbers plus drill files from KiCad for your PCB manufacturer. Review the manufacturer's preview before ordering.

PCB licensing: CERN-OHL-P-2.0, as specified in the repository.
