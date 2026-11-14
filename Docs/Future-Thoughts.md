[Back to the main project README](../README.md)

# Future thoughts and plans

**Last updated: November 14, 2026 at 1:20 AM MST (America/Denver)**

I’m finishing the A-10C II ARC-210 first, then the ARC-164 and ARC-186, before returning to additional aircraft support. [My development priorities](Related-Radio-Projects.md) may change based on feedback and interest.

**Future upgrades:** It may be as long as **two years** before I return to this project with upgrades or a new version. Please treat future-version ideas as long-term plans, with no promised release date.

- **Version 2 Main Board layout:** On the new Main Board, I plan to move the Teensy to the rear edge of the PCB with the USB port facing toward the center of the board. That will give me more options for routing the USB cable behind the panel. I may also add two tie-wrap locations so builders can secure the cable along the route that works best for their setup.

**Version 2 is a long way off.** I plan to finish the ARC-164 and ARC-186, then take a break to catch up on other things. It may be as long as two years before I return to ARC-210 upgrades, and I have no release date. **If you want to build an ARC-210, please don't wait for Version 2.**

- I’ll probably redesign the display bracket after the PCBs are built. I still don’t like the current mounting method.

- I plan to add [C-130J ARC-210 support](C-130J-Support.md) within this repository using the existing hardware. I’m developing a shared code base that will select the aircraft automatically, without reflashing the Teensy when switching supported aircraft. This support is still in development. The remaining implementation and test work is listed below. When I return to additional aircraft support, the C-130J will be my first ARC-210 candidate because I own it. Other aircraft would need their own investigation.
  - Add [C-130J support](C-130J-Support.md) using the existing ARC-210 hardware and one shared code base: implement automatic aircraft selection so users can switch between supported aircraft without reflashing the Teensy, and test that switching behavior; verify the existing DCS-BIOS controls and frequency export; follow the [Helios-based LCD export plan](C-130J-Support.md#helios-findings-and-lcd-export-plan), starting by verifying indicator 44 in the installed module, capturing live indications, parsing them once per export cycle, adding named string outputs for the LCD/menu fields, and clearing fields that disappear between pages; check RT SELECT behavior; and complete firmware and menu changes, testing, and documentation. Document any unavailable display data.

- **Button lighting:** The new Button Matrix Board will need buttons that let light through. The V2 parts are outside the current build estimate.

I recommend using **male pin headers on the Teensy and matching female socket strips on the Main Board** so the controller can be unplugged. If I release a compatible replacement Main Board, you could move your existing Teensy to it rather than buy another controller, saving some money. Soldering the Teensy’s header pins directly into the Main Board does not provide that removable connection.

- I’ve asked PJRC about replacing Micro-USB with USB-C on a future Teensy 4.1 revision and posted on their forum to see what other builders think. A reversible connector would make cable connections behind the radio panels easier. This is a request and community discussion; no connector change has been confirmed.

### Version 2 board layout

I plan to build **three new PCBs**, reuse my **Teensy 4.1**, and keep the existing TFT wiring, including VCC and backlight control.

| Board | What goes on it |
| --- | --- |
| Main Board | Existing Teensy 4.1, regulated 5 V input and distribution for the button lighting, the backlight driver, and two FREQ rotary switches |
| Button Matrix Board | Buttons, diodes, and backlight LEDs |
| Long Shaft Switch Board | Three FREQ rotary switches, MODE, MASTER, SQL On/Off, and the CHANNEL rotary encoder |

This layout requires **eight new rotary switches** (five FREQ, MODE, MASTER, and SQL On/Off) and **one new CHANNEL rotary encoder**. I still need to check shaft reach and clearance around the TFT bracket, design the boards, update the firmware, and test the assembly.

The five FREQ resistor ladders use 3.3 V and one analog input each. The backlight driver uses one PWM control pin. That uses six of the ten pins freed by the five FREQ encoders, leaving four spare. CHANNEL still uses two signal pins.

## Other SIMPIT panels

After finishing the radio panels and taking the planned break, I would like to build other panels for my SIMPIT, including the **SAS and emergency trim panels**. I’ll share those projects as they develop. These are future plans, and my priorities may change based on user feedback and interest.

## Using DCS trials for future aircraft support

For aircraft I don’t own, I plan to use the [DCS two-week trial program](https://www.digitalcombatsimulator.com/en/include/trial.php), where the module is eligible, to develop and test panel support. That could save me the cost of buying an aircraft just for development. I’ll check trial availability and prepare the mappings, shared firmware, and test plan before activating each trial so I can make the most of the time.

At about four hours a night, a two-week trial would give me roughly **56 hours**. I hope that will be enough for straightforward changes, but missing display exports or other complications could take longer. This is a development plan, not a promise that every aircraft can be finished within one trial.

I’ll also ask owners of those aircraft to help with ongoing testing, particularly after DCS or DCS-BIOS updates, and to report issues once my trial ends. If you own a candidate aircraft and would like to help, let me know in [Discussions](https://github.com/dgdimick/ARC-210-DCS-Display/discussions). My focus remains aircraft with a matching physical radio panel, and priorities may change based on user feedback and interest.

## A central directory for SIMPIT builders

I’d love to see a central GitHub repository that links to projects from SIMPIT builders like me. Having one place to find panels, code, PCB designs, printable parts, and build guides would make it easier for people to discover what others have shared and find useful projects for their own SIMPITs, no matter how big or small they are.

I’m imagining a community directory that links back to each builder’s own repository, so the original files, updates, and credit stay with the people doing the work. This is an idea I’d like to see happen, rather than a project I’ve committed to building myself. If you know of a directory like this or would like to discuss the idea, let me know in [Discussions](https://github.com/dgdimick/ARC-210-DCS-Display/discussions).
