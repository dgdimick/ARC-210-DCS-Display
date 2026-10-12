# ARC-210 Rotary Switch PCB — Version 2.0

Updated October 12, 2026.

Version 2.0 uses a 27.99 mm circular PCB outline, approximately 1 mm outside the switch body, with the resistors and connector repositioned inside the outline. The PCB silkscreen and board revision identify version 2.0. This KiCad 10 project replaces the previously published board. Switch terminal 1 is used for position 1. The resistor ladder uses **six resistors (R1–R6)** to provide seven switch-position voltages. The switch contacts used are 1, 2, 4, 5, 7, 8 and 10; terminal 11 is unused. A1 is the common contact and analog output.

Open `Rotary Switches.kicad_pro`. The project includes its custom symbol and A12505RNCQ footprint, with relative library paths so they work after downloading.

- SW1: C&K A12505RNCQ, PCB terminals, 12.7 mm shaft, 45° indexing.
- R1–R6: **six resistors**, each 1 kΩ, 1%, 1/8 W.
- J1: pin 1 = 3.3 V; pin 2 = analog output; pin 3 = GND.

The 220 Ω resistor and 100 nF input filter belong near the Teensy on the master PCB.

## On/Off option added in version 1.2

I modified the PCB so it can also be used with the On/Off switch. **JP1**, marked **ON/OFF** on the back of the PCB near R2, is an open solder jumper between GND and the R1–R2 junction: R2 pad 1, also connected to switch terminal 2.

- **On/Off:** omit all six resistors R1–R6 and bridge JP1 with solder. Connect J1 pin 2 (switch common A1) to a Teensy input configured with a pull-up, and J1 pin 3 to GND. Selecting terminal 2 pulls the input LOW; an ungrounded contact reads HIGH. J1 pin 1 is not needed for this configuration. Set the switch travel and contact selection to match the panel markings.
- **Resistor ladder:** fit all six resistors R1–R6 and leave JP1 open. Use the three J1 connections listed above.

The solder-lug A12515RNZQ still requires mechanical support and wires to the corresponding PCB connections; it does not fit the PCB-pin footprint directly.

Validation for version 2.0: KiCad PCB DRC, with zones refilled, reported zero non-excluded violations and zero unconnected pads under the saved project settings. The project contains 15 specific PTH-inside-switch-courtyard exclusions for the rear-side resistors and connector; their lead and solder-joint clearance to the switch body still requires physical verification. Several other check categories are disabled in the project. Electrical schematic checks and schematic parity were not rerun for this upload. Physical fit and operation have not yet been verified on a manufactured board.

## Optional switch 3D model

Download [LIB_A12515RNZQ.zip](LIB_A12515RNZQ.zip), the original supplier library archive. Extract `A12515RNZQ/3D/A12515RNZQ.stp` and place the STP file beside `Rotary Switches.kicad_pcb`.

In KiCad PCB Editor, open SW1's Footprint Properties → 3D Models and confirm the model reference is `${KIPRJMOD}/A12515RNZQ.stp` (already assigned in version 2.0). The existing offset is X = -10.5 mm, Y = 3 mm, Z = 7.5 mm, with scale = 1 and rotation X = -90°, Y = 0°, Z = 0°. These settings were carried over from the previous model; verify and adjust the new model's alignment in the 3D Viewer. Make the same model change in the library footprint for future placements.

**This is the A12515RNZQ solder-lug model, not the A12505RNCQ PCB-terminal part.** Use it as a visual reference only; it does not establish fit or mechanical clearance for the PCB part. Adding a 3D model does not change the footprint's pads or make the solder-lug part fit them.

PCB design licensing: CERN-OHL-P-2.0, as specified in the repository.
