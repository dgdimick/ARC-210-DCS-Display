# ARC-210 Rotary Switch PCB — Version 1.1

Updated October 10, 2026.

This corrected KiCad 10 project replaces the withdrawn initial version. Switch terminal 1 is used for position 1. The seven resistor-ladder contacts are 1, 2, 4, 5, 7, 8 and 10; terminal 11 is unused. A1 is the common contact and analog output.

Open `Rotary Switches.kicad_pro`. The project includes its custom symbol and A12505RNCQ footprint, with relative library paths so they work after downloading.

- SW1: C&K A12505RNCQ, PCB terminals, 12.7 mm shaft, 45° indexing.
- R1–R6: 1 kΩ, 1%, 1/8 W.
- J1: pin 1 = 3.3 V; pin 2 = analog output; pin 3 = GND.

The 220 Ω resistor and 100 nF input filter belong near the Teensy on the master PCB.

The solder-lug A12515RNZQ used for SQL on/off requires wiring and mechanical support. Its connections must be arranged for the required on/off positions rather than the seven-position resistor ladder.

Validation: KiCad electrical checks reported zero violations; PCB checks reported zero violations, zero unconnected pads and zero schematic parity issues under the project's configured checks. Physical fit and operation have not yet been verified on a manufactured board.

The optional supplier 3D model is not bundled. To display it, place `A12503RNCQE.stp` beside the project files. That model represents the shorter shaft and is a visual reference; use the actual A12505RNCQ dimensions for mechanical clearance.

PCB design licensing: CERN-OHL-P-2.0, as specified in the repository.
