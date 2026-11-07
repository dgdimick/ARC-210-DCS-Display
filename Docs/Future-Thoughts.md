[Back to the main project README](../README.md)

# Future thoughts and plans

**Last updated: November 7, 2026 at 2:58 PM MST (America/Denver)**

I’m finishing the A-10C II ARC-210 first, then the ARC-164 and ARC-186, before returning to additional aircraft support. [My development priorities](Related-Radio-Projects.md) may change based on feedback and interest.

**Future upgrades:** It may be as long as **two years** before I return to this project with upgrades or a new version. Please treat future-version ideas as long-term plans, with no promised release date.

- **Version 2 — frequency rotary switches:** I plan to replace the frequency rotary encoders with **rotary switches like those used in the real A-10's ARC-210**. This will require **two new frequency rotary-switch PCBs to replace the current Rotary Encoder PCB**, along with firmware changes and mechanical fit checks. Using resistor ladders should free up Teensy signal pins compared with the encoders, and I checked that J4 provides enough analog inputs and PWM outputs to **reuse the existing Main Board for five rotary switches and two backlight controls**. See the proposed pin assignment below. I still need to verify the pin assignments, wiring, and compatibility.

- **Version 2 — lighting daughterboard:** I plan to make a **separate daughterboard to distribute the external regulated 5 V power needed for the LEDs**, with the lighting control and protection circuitry worked out during design. This is the proposed way to add lighting while trying to keep the existing Main Board. The daughterboard would not generate 5 V from the Teensy's 3.3 V supply; it would need an external regulated 5 V supply.

**Version 2 is a long way off.** I plan to finish the ARC-164 and ARC-186, then take a break to catch up on other things. It may be as long as two years before I return to ARC-210 upgrades, and I have no release date. **If you want to build an ARC-210, please don't wait for Version 2.**

- I’ll probably redesign the display bracket after the PCBs are built. I still don’t like the current mounting method.

- I plan to add [C-130J ARC-210 support](C-130J-Support.md) within this repository using the existing hardware. I’m developing a shared code base that will select the aircraft automatically, without reflashing the Teensy when switching supported aircraft. This support is still in development. Shared firmware, DCS-BIOS mappings, menus, testing, and documentation are tracked in the [main work list](Remaining-Work.md). When I return to additional aircraft support, the C-130J will be my first ARC-210 candidate because I own it. Other aircraft would need their own investigation.

- **Button lighting:** The current Button Matrix PCB v3.2 does not support LED backlighting. Version 2 lighting would still need a **new Button LED PCB**, suitable light-transmitting buttons, and clearance checks around the TFT display. My current plan is to put the external 5 V lighting power and control circuitry on the daughterboard rather than assume the Main Board must be replaced. Main Board reuse is a goal, not a confirmed compatibility claim. I have not finalized the board layout, layer count, lighting circuit, or upgrade cost. These future parts are not included in the current build estimate or PCB set price.

I recommend using **male pin headers on the Teensy and matching female socket strips on the Main Board** so the controller can be unplugged. If I release a compatible replacement Main Board, you could move your existing Teensy to it rather than buy another controller, saving some money. Soldering the Teensy’s header pins directly into the Main Board does not provide that removable connection.

My aim is to reuse the existing Main Board, socket-mounted Teensy, faceplate, and other compatible parts where possible. The frequency encoders and their PCB would be replaced for the rotary-switch version. Illuminated buttons would also need suitable light-transmitting replacements. Compatibility still needs to be checked as the redesign develops.

- I’ve asked PJRC about replacing Micro-USB with USB-C on a future Teensy 4.1 revision and posted on their forum to see what other builders think. A reversible connector would make cable connections behind the radio panels easier. This is a request and community discussion; no connector change has been confirmed.

### New PCBs required for Version 2

My current Version 2 plan requires **four new PCBs**:

| Board | Quantity | Purpose |
| --- | ---: | --- |
| Button Matrix board with LED support | 1 | Replace the current button board and support illuminated buttons |
| Frequency rotary-switch boards | 2 | Carry the five replacement frequency rotary switches and their resistor ladders |
| Power and dimming board | 1 | Distribute external regulated 5 V LED power and carry the lighting-control circuitry |

The power/dimming board is the lighting daughterboard described above, not an additional fifth board. I plan to reuse the existing Main Board and Teensy using the J4 signal assignments below. Mechanical fit, wiring, firmware, and assembled operation still need to be verified.

### Proposed reuse of the existing Main Board

I checked the published Main Board's J4 encoder connector against its Teensy connections. **The existing Main Board has the signal connections needed for five rotary-switch resistor ladders and two independent backlight controls**, so I can plan around reusing it instead of replacing it solely to add these functions.

**Signal-pin count:** The five encoders being replaced use **ten signal connections**, two per encoder. Five rotary switches using resistor ladders need **five analog-input pins**, and one backlight dimming circuit needs **one PWM control pin**. **Five switch inputs + one dimming-circuit control output = 6 signal pins used, leaving 4 spare** out of those ten connections. The dimming circuit’s control pin is already included in the six; it is not an additional seventh pin. This retains the separate sixth encoder on its own two connections. If I add a second independent backlight dimmer, the total becomes **7 used and 3 spare**. Ground and supply connections are separate from this signal-pin count.

This is a proposed Version 2 assignment. GPIO numbers below are the labels on the Teensy, not KiCad symbol pad numbers.

| Proposed function | Main Board J4 pin | Teensy GPIO | Capability |
| --- | ---: | --- | --- |
| Frequency rotary switch 1 | 6 | 20 / A6 | Analog input |
| Frequency rotary switch 2 | 5 | 21 / A7 | Analog input |
| Frequency rotary switch 3 | 10 | 24 / A10 | Analog input |
| Frequency rotary switch 4 | 12 | 26 / A12 | Analog input |
| Frequency rotary switch 5 | 11 | 27 / A13 | Analog input |
| Backlight control 1 | 7 | 22 | PWM output |
| Backlight control 2 | 8 | 23 | PWM output |
| Remaining encoder A/B | 2 / 1 | 16 / 17 | Digital inputs |
| Shared ground | 13 / 14 | GND | Ground |

The table shows the two-dimmer option: J4 pins 3 and 4 (GPIO 28 and 29) and pin 9 (GPIO 25) remain available. With just one dimmer, J4 pin 8 (GPIO 23) is also spare, giving four spare signal connections. Spare connections must still be assigned according to each GPIO’s analog, digital, or PWM capabilities. See the [PJRC Teensy 4.1 reference](https://www.pjrc.com/store/teensy41.html) for analog and PWM capabilities.

The five resistor ladders must use **3.3 V**, keeping their outputs within the Teensy's input range. The two PWM signals would control **MOSFET lighting drivers on the daughterboard**; the LEDs would get power from an **external regulated 5 V supply**, with a shared ground. The Teensy pins would not supply LED power.

This confirms the required signal capability on the existing Main Board, not a completed or tested Version 2 design. I still need to design the two replacement frequency rotary-switch PCBs, Button Matrix board, and power/dimming board, finalize the wiring and remaining encoder assignment, update the firmware, and test the full assembly. The current encoder board cannot simply be plugged in unchanged under this new assignment.

## Other SIMPIT panels

After finishing the radio panels and taking the planned break, I would like to build other panels for my SIMPIT, including the **SAS and emergency trim panels**. I’ll share those projects as they develop. These are future plans, and my priorities may change based on user feedback and interest.

## Using DCS trials for future aircraft support

For aircraft I don’t own, I plan to use the [DCS two-week trial program](https://www.digitalcombatsimulator.com/en/include/trial.php), where the module is eligible, to develop and test panel support. That could save me the cost of buying an aircraft just for development. I’ll check trial availability and prepare the mappings, shared firmware, and test plan before activating each trial so I can make the most of the time.

At about four hours a night, a two-week trial would give me roughly **56 hours**. I hope that will be enough for straightforward changes, but missing display exports or other complications could take longer. This is a development plan, not a promise that every aircraft can be finished within one trial.

I’ll also ask owners of those aircraft to help with ongoing testing, particularly after DCS or DCS-BIOS updates, and to report issues once my trial ends. If you own a candidate aircraft and would like to help, let me know in [Discussions](https://github.com/dgdimick/ARC-210-DCS-Display/discussions). My focus remains aircraft with a matching physical radio panel, and priorities may change based on user feedback and interest.

## A central directory for SIMPIT builders

I’d love to see a central GitHub repository that links to projects from SIMPIT builders like me. Having one place to find panels, code, PCB designs, printable parts, and build guides would make it easier for people to discover what others have shared and find useful projects for their own SIMPITs, no matter how big or small they are.

I’m imagining a community directory that links back to each builder’s own repository, so the original files, updates, and credit stay with the people doing the work. This is an idea I’d like to see happen, rather than a project I’ve committed to building myself. If you know of a directory like this or would like to discuss the idea, let me know in [Discussions](https://github.com/dgdimick/ARC-210-DCS-Display/discussions).
