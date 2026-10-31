[Back to the main project README](../README.md)

# Power and future button lighting

**Last updated: October 31, 2026 at 1:52 AM MDT (America/Denver)**

The painted buttons supplied with the PC Flights panel used for this build are opaque: light will not pass through them, so LEDs behind them would not illuminate their legends. Future backlighting would also require suitable light-transmitting replacement buttons.

The Teensy is powered by USB, and **TFT VCC connects directly to the Teensy's 3.3 V rail** (`TEENSY_3V3`, U1 pad 15). I’ve tested the TFT at 3.3 V and found the brightness satisfactory. I removed the external protected 5 V input and Main Board JP1 power selector. I removed C5 (470 µF) and C6 (0.1 µF) to match the direct Teensy-to-TFT wiring I tested. C1/C2 and R1/R2 remain as the rotary-input filters. Keep total external 3.3 V consumption within PJRC's recommended 250 mA maximum; brightness confirmation is not a current measurement.

**The current Button Matrix PCB v3.2 does not support LED backlighting and would need to be redesigned.** I would need to design a new button board with LED support (Button LED PCB), use suitable light-transmitting buttons, and redesign the power and driver circuitry with the necessary Main Board changes. The current Main Board has no external lighting-power circuit. I may revisit this after completing the ARC-164 and ARC-186 projects; there is no finished design or release date. The TFT display backlight is separate from this future button-lighting option.

I may need **four-layer PCBs for both the replacement Main Board and button board**, increasing their cost. I haven’t confirmed the layer requirements or pricing; any upgrade costs are separate from the current build estimates and my current bare-PCB set.

My aim is to reuse the **rotary encoders, rotary switches, socket-mounted Teensy, faceplate, and other compatible parts outside the two replacement boards**. I still need to check compatibility during the redesign. Male Teensy headers and matching Main Board sockets would let you move the controller to a compatible replacement board. Illuminated legends would need suitable light-transmitting buttons.
