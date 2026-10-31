[Back to the main project README](../README.md)

# Future thoughts and plans

**Last updated: October 31, 2026 at 12:10 AM MDT (America/Denver)**

- I’ll probably redesign the display bracket after the PCBs are built. I still don’t like the current mounting method.

- I'm considering reworking the Main Board to carry the rotary-switch resistor ladders, allowing the switches to mount directly to the panel and be wired like the SQL On/Off switch. This would reduce the number of PCBs, but each seven-position switch would need roughly eight wires back to the Main Board, adding soldering and making the project harder for people to build. The likely cost savings would not justify the added build difficulty, so this is a low-priority idea. If I do decide to rework the Main Board, I may add LED backlighting at the same time, including the separate power and driver circuitry and suitable light-transmitting buttons described below. 🟢 **The current rotary-switch PCB design remains the build approach.**

- I plan to add [C-130J ARC-210 support](C-130J-Support.md) within this repository using the existing hardware. I’m developing a shared code base that will select the aircraft automatically, without reflashing the Teensy when switching supported aircraft. This support is still in development. Shared firmware, DCS-BIOS mappings, menus, testing, and documentation are tracked in the [main work list](Remaining-Work.md). The C-130J is the first additional aircraft I’m focusing on because I own it. Other aircraft would need their own investigation.

- I may revisit button lighting after completing the **ARC-164 and ARC-186 projects**. This is a future redesign, with no release date or finished Button LED PCB design. It would require suitable translucent buttons and a new Button LED PCB, plus changes to the Main Board to make room for an SCR, its associated discrete components, and a lighting connector. I would also need an external 5 V supply and the associated power-input and protection circuitry. The current USB/3.3 V Main Board does not include this lighting circuitry. I dropped button lighting from the current design because there wasn’t enough clearance with the TFT display, so I would need to resolve that mechanical clearance before adding it.

- I’ve asked PJRC about replacing Micro-USB with USB-C on a future Teensy 4.1 revision and posted on their forum to see what other builders think. A reversible connector would make cable connections behind the radio panels easier. This is a request and community discussion; no connector change has been confirmed.
