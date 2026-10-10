# Rotary Switch PCB — KiCad project

Updated October 10, 2026.

Work in progress: a small resistor-ladder PCB for one ARC-210 multi-position rotary switch. Mechanical fit and operation have not yet been verified with an assembled board.

## Open the project

Use KiCad 10 and open `Rotary Switches.kicad_pro`. The custom symbol and footprint libraries are included and use project-relative paths. Standard resistors and headers use the KiCad libraries.

## Parts and connections

Use a C&K A125 switch with 45-degree indexing and **C (PCB through-hole) terminals**, such as A12505RNCQ (1/2-inch shaft) or A12503RNCQE (3/8-inch shaft). The footprint retains its library name A12515RNCQ; verify the selected part's dimensions before fabrication. Solder-lug Z versions do not fit this PCB footprint.

Six individual 1 kΩ, 1% resistors form the seven-position ladder. R1 is marked 1/8 W; use the same specification for all six resistors. Switch terminal 1 is unused; terminals 2, 4, 5, 7, 8, 10 and 11 provide the seven ladder positions. **Seven switch positions are used by this PCB.** Although the A125 is sold as an eight-position switch, set its stop ring to limit travel to the seven wired positions, leaving terminal 1 outside the permitted travel. Verify the terminal sequence and knob alignment against the faceplate before assembly.

J1: pin 1 = +3.3 V, pin 2 = ROTARY_ADC, pin 3 = GND. The 220 Ω series resistor and 100 nF filter capacitor belong near the Teensy on the master PCB. This project is not the separately wired two-position On/Off switch.

## Optional 3D model

The third-party A12503RNCQE.stp model is not bundled. Obtain it from the manufacturer or its CAD provider and place it beside the project file. The included model references use `${KIPRJMOD}/A12503RNCQE.stp`. This model shows the 3/8-inch shaft; other shaft options will look different. Model absence does not affect the copper or drill layout.

## Validation

KiCad 10 checks on the shared copy reported 0 DRC violations, 0 unconnected items and 0 ERC messages. These results follow the project's current rules and exclusions; they do not establish physical fit or tested hardware operation.

Project-authored PCB design: CERN-OHL-P-2.0, as described in the repository licensing section. Third-party library content remains subject to its original provider's terms.
