# ARC-210 Rotary Switch PCB — Version 1.2

Updated October 10, 2026.

This corrected KiCad 10 project replaces the withdrawn initial version. Switch terminal 1 is used for position 1. The seven resistor-ladder contacts are 1, 2, 4, 5, 7, 8 and 10; terminal 11 is unused. A1 is the common contact and analog output.

Open `Rotary Switches.kicad_pro`. The project includes its custom symbol and A12505RNCQ footprint, with relative library paths so they work after downloading.

- SW1: C&K A12505RNCQ, PCB terminals, 12.7 mm shaft, 45° indexing.
- R1–R6: 1 kΩ, 1%, 1/8 W.
- J1: pin 1 = 3.3 V; pin 2 = analog output; pin 3 = GND.

The 220 Ω resistor and 100 nF input filter belong near the Teensy on the master PCB.

## On/Off option added in version 1.2

I modified the PCB so it can also be used with the On/Off switch. **JP1**, marked **ON/OFF** on the back of the PCB near R2, is an open solder jumper between GND and the R1–R2 junction: R2 pad 1, also connected to switch terminal 2.

- **On/Off:** omit all six resistors R1–R6 and bridge JP1 with solder. Connect J1 pin 2 (switch common A1) to a Teensy input configured with a pull-up, and J1 pin 3 to GND. Selecting terminal 2 pulls the input LOW; an ungrounded contact reads HIGH. J1 pin 1 is not needed for this configuration. Set the switch travel and contact selection to match the panel markings.
- **Resistor ladder:** fit R1–R6 and leave JP1 open. Use the three J1 connections listed above.

The solder-lug A12515RNZQ still requires mechanical support and wires to the corresponding PCB connections; it does not fit the PCB-pin footprint directly.

Validation: KiCad electrical checks reported zero violations; PCB checks reported zero violations, zero unconnected pads and zero schematic parity issues under the project's configured checks. Physical fit and operation have not yet been verified on a manufactured board.

The optional supplier 3D model is not bundled. To display it, place `A12503RNCQE.stp` beside the project files. That model represents the shorter shaft and is a visual reference; use the actual A12505RNCQ dimensions for mechanical clearance.

PCB design licensing: CERN-OHL-P-2.0, as specified in the repository.
