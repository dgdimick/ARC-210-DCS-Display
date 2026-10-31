[Back to the main project README](../README.md)

# Future thoughts and plans

**Last updated: October 31, 2026 at 12:44 AM MDT (America/Denver)**

My current plan is to finish the **A-10C II (A-10C2) ARC-210 implementation**, then build and test the **ARC-164**, followed by the **ARC-186**. After those projects, I’ll return to additional aircraft support, starting with the **ARC-210 and C-130J**. Those aircraft extensions are later work, not the current implementation priority. I’m focusing on aircraft with a matching physical radio panel. **This order may change based on user feedback and interest.**

- I’ll probably redesign the display bracket after the PCBs are built. I still don’t like the current mounting method.

- I'm considering reworking the Main Board to carry the rotary-switch resistor ladders, allowing the switches to mount directly to the panel and be wired like the SQL On/Off switch. This would reduce the number of PCBs, but each seven-position switch would need roughly eight wires back to the Main Board, adding soldering and making the project harder for people to build. The likely cost savings would not justify the added build difficulty, so this is a low-priority idea. If I do decide to rework the Main Board, I may add LED backlighting at the same time. I would also need to redesign the current Button Matrix PCB, which does not support LED backlighting, and add the power and driver circuitry and suitable light-transmitting buttons described below. I have no finished lighting design or release date. 🟢 **The current rotary-switch PCB design remains the build approach.**

- I plan to add [C-130J ARC-210 support](C-130J-Support.md) within this repository using the existing hardware. I’m developing a shared code base that will select the aircraft automatically, without reflashing the Teensy when switching supported aircraft. This support is still in development. Shared firmware, DCS-BIOS mappings, menus, testing, and documentation are tracked in the [main work list](Remaining-Work.md). When I return to additional aircraft support, the C-130J will be my first ARC-210 candidate because I own it. Other aircraft would need their own investigation.

- I may revisit button lighting after completing the **ARC-164 and ARC-186 projects**. I have no finished Button LED PCB design or release date for this possible future redesign. I would need to redesign the button board to support LED backlighting; the current Button Matrix PCB v3.2 does not support it. The redesign would require suitable translucent buttons and a new button board with LED support (Button LED PCB), plus changes to the Main Board to make room for an SCR, its associated discrete components, and a lighting connector. I would also need an external 5 V supply and the associated power-input and protection circuitry. The current USB/3.3 V Main Board does not include this lighting circuitry. I may need to use four-layer PCBs for the replacement Main Board and button board, which could increase the cost of both replacement boards. I haven’t confirmed the layer requirements or priced that redesign yet; this possible extra cost is not included in the current build estimate or bare-PCB set price. I dropped button lighting from the current design because there wasn’t enough clearance with the TFT display, so I would need to resolve that mechanical clearance before adding it.

I recommend using **male pin headers on the Teensy and matching female socket strips on the Main Board** so the controller can be unplugged. If I release a compatible replacement Main Board, you could move your existing Teensy to it rather than buy another controller, saving some money. Soldering the Teensy’s header pins directly into the Main Board does not provide that removable connection.

My aim would be to reuse the **rotary encoders, rotary switches, socket-mounted Teensy, faceplate, and other parts that aren’t mounted on the Main Board or Button Matrix PCB**, so upgrading would not mean buying a whole new panel. I still need to confirm compatibility as I develop the redesign. The current opaque buttons would need suitable light-transmitting replacements for illuminated legends.

- I’ve asked PJRC about replacing Micro-USB with USB-C on a future Teensy 4.1 revision and posted on their forum to see what other builders think. A reversible connector would make cable connections behind the radio panels easier. This is a request and community discussion; no connector change has been confirmed.

## Other SIMPIT panels

Once I’ve finished the radio panels, I plan to build other panels for my SIMPIT, including the **SAS and emergency trim panels**. I’ll share those projects as they develop. These are future plans, and my priorities may change based on user feedback and interest.

## Using DCS trials for future aircraft support

For aircraft I don’t own, I plan to use the [DCS two-week trial program](https://www.digitalcombatsimulator.com/en/include/trial.php), where the module is eligible, to develop and test panel support. That could save me the cost of buying an aircraft just for development. I’ll check trial availability and prepare the mappings, shared firmware, and test plan before activating each trial so I can make the most of the time.

At about four hours a night, a two-week trial would give me roughly **56 hours**. I hope that will be enough for straightforward changes, but missing display exports or other complications could take longer. This is a development plan, not a promise that every aircraft can be finished within one trial.

I’ll also ask owners of those aircraft to help with ongoing testing, particularly after DCS or DCS-BIOS updates, and to report issues once my trial ends. If you own a candidate aircraft and would like to help, let me know in [Discussions](https://github.com/dgdimick/ARC-210-DCS-Display/discussions). My focus remains aircraft with a matching physical radio panel, and priorities may change based on user feedback and interest.

## A central directory for SIMPIT builders

I’d love to see a central GitHub repository that links to projects from SIMPIT builders like me. Having one place to find panels, code, PCB designs, printable parts, and build guides would make it easier for people to discover what others have shared and find useful projects for their own SIMPITs, no matter how big or small they are.

I’m imagining a community directory that links back to each builder’s own repository, so the original files, updates, and credit stay with the people doing the work. This is an idea I’d like to see happen, rather than a project I’ve committed to building myself. If you know of a directory like this or would like to discuss the idea, let me know in [Discussions](https://github.com/dgdimick/ARC-210-DCS-Display/discussions).
