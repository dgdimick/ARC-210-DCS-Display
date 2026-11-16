[Back to the main project README](../README.md)

# Power and future button lighting

**Last updated: November 16, 2026**

The painted buttons supplied with the PC Flights panel used for this build are opaque: light will not pass through them, so LEDs behind them would not illuminate their legends. Future backlighting would also require suitable light-transmitting replacement buttons.

The Teensy is powered by USB, and **TFT VCC connects directly to the Teensy's 3.3 V rail** (`TEENSY_3V3`, U1 pad 15). I’ve tested the TFT at 3.3 V and found the brightness satisfactory. The earlier Main Board revision removed the protected 5 V input and JP1 power selector. The revised board has a separate 5 V input for future button lighting. I removed C5 (470 µF) and C6 (0.1 µF) to match the direct Teensy-to-TFT wiring I tested. C1/C2 and R1/R2 remain as the rotary-input filters. Keep total external 3.3 V consumption within PJRC's recommended 250 mA maximum; brightness confirmation is not a current measurement.

**The current Button Matrix PCB v3.2 has unlit buttons.** The revised Main Board includes power and dimming circuitry for future LED button backlighting. My plan is to reuse that Main Board when I release a backlit Button Matrix PCB for light-transmitting buttons. There’s no release date for the button-board upgrade.

My aim is to reuse the **rotary encoders, rotary switches, socket-mounted Teensy, faceplate, and other compatible parts alongside the revised Main Board**. I still need to check compatibility during the redesign. Male Teensy headers and matching Main Board sockets would let you move the controller to a compatible replacement board. Illuminated legends would need suitable light-transmitting buttons.
