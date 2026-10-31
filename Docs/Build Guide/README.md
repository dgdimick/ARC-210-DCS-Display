# ARC-210 Build Guide

**Last updated: October 31, 2026 at 12:52 AM MDT (America/Denver)**

While I could have used surface-mount (SMD) parts to make the boards smaller, I chose through-hole components to make the project easier for everyone to build and solder with basic tools.

Draft started October 29, 2026.

I’m putting this guide together to help you build your own ARC-210 panel using a Teensy 4.1, a 3.5-inch ILI9488 LCD display connected by SPI, and my control boards. If this is your first panel, start by reading through the guide, then take the build one board at a time. You’re welcome to ask questions in [Discussions](https://github.com/dgdimick/ARC-210-DCS-Display/discussions)—I’m happy to help where I can.

**This guide is still a work in progress.** I mark unfinished details as **Pending** so you can see where I still need to finish the design, check an assembled board, take measurements, or add photographs. Check those notes before ordering parts or making a permanent connection; I’ll fill them in as I complete the build.

## Before you begin

- **PCB** means printed circuit board. The **BOM** is the bill of materials, or shopping list. You can use the ready-made manufacturing ZIP files without editing the KiCad designs.
- **Dry-fit** means putting parts together temporarily to check alignment and clearance. Do this before soldering or tightening anything that would make adjustment difficult, even though the full-panel fit check is described in step 7.
- Board labels such as **J1**, **R1**, and **D5** identify a connector, resistor, or diode. Each PCB has its own labels, so check which board a step refers to.
- **Front** means the side facing the faceplate; **back** means the side facing into the cockpit enclosure. Check each board’s instructions and pictures before fitting parts.
- A **HEX file** is the compiled firmware you load onto the Teensy. The supplied HEX files let you program it without compiling the source yourself. **TFT** refers to the LCD display in the wiring and test instructions.
- **GND** means ground, and **GPIO** means a controller input/output pin. Use the GPIO numbers printed on the Teensy when following the wiring instructions.
- I recommend checking your work after each board rather than waiting until the whole panel is assembled. Step 9 links to the hardware tests; step 10 covers the radio firmware and DCS-BIOS setup.


## Build status

| Area | Current status |
| --- | --- |
| Button Matrix PCB v3.2 | Final design; physical fit and button alignment confirmed; manufacturing files published |
| Rotary Encoder PCB v1.4 | Final design; physical fit confirmed; manufacturing files published |
| Rotary Switch PCB v2.0 | Final design; physical fit confirmed; manufacturing files published |
| Main Board v1.1 | Gerber/drill files published; October 29 ERC/DRC and parity checks pass under saved settings; physical fit confirmed October 29, 2026; final review, current verification and assembled-board testing pending |
| Printed parts | All 17 parts have passed test fitting at 100%; Channel v4.2 was checked separately after the earlier complete-layout print |
| Electrical testing | Combined breadboard hardware test confirmed; assembled manufactured-board testing pending |
| Radio firmware | Menu/display preview available; complete physical-control integration and final in-DCS validation pending |

KiCad’s electrical and layout checks help me find design mistakes. I still need to test the assembled manufactured boards; the table above keeps that separate from the physical-fit checks.

## 1. Gather files, parts, and tools

1. Download the repository using **Code → Download ZIP**, then extract it. Keep each KiCad project folder and its libraries together.
2. Read the [parts list](../../parts/README.md), [BOM](../../parts/BOM.csv), and [PCB overview](../../PCBs/README.md). Use the current project versions listed above.
3. Gather a soldering iron, solder, flush cutters, multimeter, suitable hand tools, and access to a 3D printer. Have the PC Flights faceplate and specified controls available for fit checks.
4. Use a **USB Micro-B data cable** to power and program the Teensy 4.1 and carry USB communications. A charge-only cable will supply power but won’t let you program the Teensy or send radio data.

I recommend buying a **Teensy 4.1 with pre-soldered male header pins**: [SparkFun Teensy 4.1 (Headers)](https://www.sparkfun.com/teensy-4-1-headers.html), or this [Amazon Teensy 4.1 with Pins listing](https://www.amazon.com/PJRC-Teensy-4-1-with-Pins/dp/B08CTM3279) as an alternative example. The pre-fitted pins avoid having to solder the two long header rows yourself. The Main Board's two 1 × 24 female sockets are separate parts; they are optional but recommended for removing the Teensy during board upgrades or replacement.

For removable mounting, use **two 1 × 24 female PCB socket strips, 2.54 mm (0.1-inch) pitch**, on the Main Board, with matching male headers on the Teensy. Each strip has one row of 24 sockets; the Teensy’s pins plug into them. **These sockets are optional but recommended.** They allow the Teensy to be removed when replacing or updating the Main Board for new features, such as future LED support, or when the Teensy itself is damaged and needs replacement. **Pending:** final socket height, header lead length, standoff lengths, fastener quantities, and cable lengths must be confirmed against the finished assembly.

The build uses **five required boards**: one Main Board, one Button Matrix, one Rotary Encoder, and two Rotary Switch boards. A third Rotary Switch PCB is optional for the SQL On/Off switch, bringing the total to six.

The PCBs require mounting stand-offs. Use the [Vibit M3 nylon stand-off kit](https://www.amazon.com/dp/B0H1QS5Q6N), budgeted at **$10 per kit** in the BOM. Choose the total stand-off height by the clearance your build needs: approximately **22–26 mm**, depending on the SQL ON/OFF rotary switch shaft length. Dry-fit the boards, switch and faceplate, then select the height that provides the required clearance and correct shaft position before tightening the mounting hardware. The number of individual stand-offs remains pending.

## 2. Print and check the mechanical parts

**The 17-part set has passed test fitting at 100% scale, with Channel v4.2 separately reprinted and confirmed after the earlier complete-layout test. The combined downloads now include that replacement.** Please keep checking [Project Updates](../Project-Updates.md) for changes.

The easiest starting point is the [master STL or 3MF download](../../Supporting%20STL%27s/README.md#complete-17-part-print-set), which contains all 17 required parts. Print the master set once at **100% scale**, or use the individual files below in the listed quantities. You don’t need to print both the master set and the individual parts.

| Part | Quantity / action |
| --- | --- |
| [Frequency knob v.10.1](../../Supporting%20STL%27s/Freq_Knob_v.10.1.stl) | Print five at 100%; confirm fit on each shaft |
| [Mode knob v.4](../../Supporting%20STL%27s/Mode_Knob_v.4.stl) | Print two at 100% |
| [Channel knob v.4.2](../../Supporting%20STL%27s/Channel_Knob_v.4.2.stl) | Print one at 100% |
| [TFT bracket v.5](../../Supporting%20STL%27s/Deep_Bracket_v.5.stl) | Print one at 100% |
| [Rotary Encoder spacer v.1](../../Supporting%20STL%27s/Rotary_Encoder_Spacer_v.1.stl) | **Print six**, one per encoder, to center the threads in the faceplate holes |
| [SQL shaft spacer v.5](../../Supporting%20STL%27s/Shaft_Spacer_v.5.stl) | **Print one; required in all installations** to support the longer SQL On/Off switch shaft |
| [SQL knob v1.2](../../Supporting%20STL%27s/SQL_Knob_v.1.2.stl) | Print one at 100%; retains the larger SQL socket |

The SQL shaft spacer is required whether using the optional SQL PCB or wiring directly to the switch's solder lugs. It is a separate part from the SQL knob.

**The Channel and SQL knobs are the same outside size, with the same small side hole; only the shaft holes differ.** Channel v4.2 has the smaller shaft hole; SQL v1.2 retains the larger shaft hole. Channel v4.2 uses the Frequency v10.1 shaft-hole profile (approximately 6.375 mm round diameter), with the Channel socket depth, outside dimensions, and small side hole unchanged. I printed Channel v4.2 at **100% scale** and confirmed the fit. SQL remains v1.2 with its previously tested socket. Print **one Channel v4.2 and one SQL v1.2**, each at 100%; these files are no longer interchangeable.

Dry-fit printed parts before permanent assembly. All current files print at 100% with the current hardware. Printer tolerances and shaft sizes vary, so check the fit on your own hardware. **Pending:** illustrated printing settings and a complete knob-to-control installation chart.

## 3. Order the PCBs

**You can buy a complete six-board set of bare PCBs from me for US$40, plus shipping, handling, tax, VAT, and any other applicable tariffs, duties, or fees.** The set includes one Main Board, one Button Matrix board, one Rotary Encoder board, and three Rotary Switch boards, including the optional SQL board. You’ll supply the components and solder the boards yourself; the price does not include electronics, the faceplate, printed parts, or assembly. [Contact me in Discussions](https://github.com/dgdimick/ARC-210-DCS-Display/discussions) to check availability and shipping. You’re also welcome to order directly from JLCPCB using the steps below.

I’m offering this as a **convenient complete set for one radio**: you get the boards you need without managing four separate PCB design uploads or ordering the manufacturer’s minimum quantity of every design. **Any savings depend on your location, shipping, handling, tax, VAT, tariffs, and other applicable fees**, so compare the full delivered totals. I’m not promising that my set will always be cheaper than ordering directly.

My own order for all the boards cost **about US$75**. That is an approximate total for my board order, not the manufacturing cost of a single six-board set or a guaranteed quote for another builder. My complete-set price remains **US$40 plus shipping, handling, tax, VAT, and other applicable fees**.

**JLCPCB’s prices shown in my comparison and demo are fabrication prices only. They do not include shipping, handling, tax, VAT, tariffs, duties, or other applicable fees.** Check the full delivered total before comparing a manufacturer order with a board set from me. Assembled-board electrical testing is still pending.

### Estimated total build cost

I’m distressed by the total cost of this project, and I worry it may put the build beyond some people’s budgets. I want to be open about that so you can decide whether it fits your budget before buying parts. Considering the controls, display, and functionality the panel is designed to provide, I still feel it’s worth the cost.

I’ve spent about two months working on the code, averaging four hours a night—roughly **240 hours**. I’m sharing the source code for free so other builders don’t have to do all that development work themselves. The parts still cost money, but I hope the time and effort this saves helps make the project worthwhile.

My PCBs are designed around the faceplate and layout I’m using, so they may not fit someone else’s custom panel. I’m sharing the [source code](../../Firmware/Source/Master_Program/README.md) so other builders can reuse it or adapt it to their own controls, displays, and wiring. Some changes may be needed, but I hope it gives people a useful starting point and saves them development time.

I’ve also spent about **US$500 on extra parts during development**. Buying more parts as I work toward a finished project adds up. That is my development expense; it is not an extra charge to builders or part of the estimated cost to build one panel. I’m still very happy to share this project with others. We all enjoy adding to our SIMPITs, no matter how big or small they are.

One thing I’m very pleased about is that I’m developing the same ARC-210 panel hardware for every aircraft I’ve planned to support, including the A-10C II and C-130J. I’m designing a shared code base that will automatically use the appropriate controls and display data for the aircraft you’re flying, so you won’t need to reflash the Teensy when switching between supported aircraft—just fly the aircraft. **This automatic aircraft support is still being developed and tested; it is not a completed feature yet.** Aircraft-specific DCS-BIOS mappings will be handled within that shared setup.

I’ll label radio HEX downloads with the aircraft they support and a version number, increasing the version whenever I publish updated firmware so you can tell releases apart. Each new aircraft-support release will retain support for the previously supported aircraft. Adding an aircraft will require loading the updated HEX once, using the same Teensy Loader procedure as the first flash while the panel is connected by USB. After that, switching between aircraft included in that version will not require reflashing. **This cumulative aircraft support and automatic selection are still being developed and tested.**

To help you budget, here are both PCB purchasing options using the same component estimates, including the PC Flights faceplate. **All amounts are in US dollars (USD).**

| PCB purchasing option | PCB cost (USD) | Estimated total parts cost (USD) |
| --- | ---: | ---: |
| JLCPCB: five copies of each of four designs (20 bare boards, including spares) | US$41.10 | US$250.62–US$283.62 |
| My complete six-board bare-PCB set for one radio | US$40.00 | US$249.52–US$282.52 |

**Shipping, handling, tax, and VAT are separate and are not included in either total.** Tariffs, duties, and other applicable fees are also extra. These are estimates rather than fixed kit prices; either option rounds to about **US$250–US$285** for budgeting. Tools, labor, and cockpit mounting fasteners are excluded.

See the [parts-cost breakdown](../../parts/README.md#estimated-build-cost) for the component prices and allowances. Compare the full delivered totals for your location before choosing how to buy the boards.

I use **JLCPCB** for PCB manufacturing. Follow my [step-by-step JLCPCB ordering guide](../PCB-Manufacturing-JLCPCB.md) for the ZIP files, board quantities, quote settings, preview checks, and engineering questions.

Download the manufacturing packages from the [Gerber and drill table](../../PCBs/README.md#gerber-and-drill-downloads). Gerber files describe the board layers, and drill files describe the holes. Each manufacturing ZIP keeps those files together for uploading to a PCB manufacturer; keep it zipped for that upload.

| Design | Boards per panel |
| --- | ---: |
| Main Board v1.1 | 1 |
| Button Matrix v3.2 | 1 |
| Rotary Encoder v1.4 | 1 |
| Rotary Switch v2.0 | 2 required, plus 1 optional for SQL On/Off |

Review the manufacturer's preview against the project outline and drill information. These control boards specify two layers and 1.6 mm thickness; consult each manufacturing README for details.

**Main Board Version 1.1:** [Gerber and drill package](../../PCBs/Master%20Board/Manufacturing/Main-Board-PCB-v1.1-Gerbers-Drill.zip) is available for a two-layer, 1.6 mm PCB. I’ve checked the physical fit of Main Board v1.1; final routing review, current verification and assembled-board testing remain pending; this is not yet a validated production release.

## 4. Assemble the Button Matrix PCB

**The current Button Matrix PCB v3.2 does not support LED backlighting.** I would need to redesign the button board with LED support, use suitable light-transmitting buttons, and make the required Main Board, power, and driver changes. I may revisit this after completing the ARC-164 and ARC-186 projects; there is no finished backlit button-board design or release date yet. See [Future Thoughts](../Future-Thoughts.md) for the lighting redesign plan.

I may need to use **four-layer PCBs for both the replacement Main Board and button board**, which could increase the cost of both replacement boards. I haven’t confirmed the layer requirements or priced that redesign yet. This possible extra cost is not included in the current build estimates or my US$40 bare-PCB set price.

I recommend using **male pin headers on the Teensy and matching female socket strips on the Main Board** so the controller can be unplugged. If I release a compatible replacement Main Board, you could move your existing Teensy to it rather than buy another controller, saving some money. Soldering the Teensy’s header pins directly into the Main Board does not provide that removable connection.

My aim would be to reuse the **rotary encoders, rotary switches, socket-mounted Teensy, faceplate, and other parts that aren’t mounted on the Main Board or Button Matrix PCB**, so upgrading would not mean buying a whole new panel. I still need to confirm compatibility as I develop the redesign. The current opaque buttons would need suitable light-transmitting replacements for illuminated legends.

Start with the [Button Matrix instructions and connector table](../../PCBs/Button%20Matrix/README.md). This board holds the sixteen front-panel buttons. Compare the front and back pictures there before fitting parts.

**The switches go on the front side of the PCB, facing the faceplate. The diodes and pin connectors go on the opposite (back) side.** The silkscreen markings show which side each component belongs on, so check those markings before soldering.

**Photo reminder for my next assembly:** Once the manufactured PCBs arrive and I start building, I’ll add front-and-back photos here showing the switches on the front and the diodes and pin connectors on the back, with the silkscreen markings visible.

- Fit sixteen **6 × 6 × 5 mm** SPST momentary tactile switches on the front.
- Fit D5–D20, the sixteen 1N4148 diodes, and the row/column connectors on the back. Follow the schematic and polarity markings; the diode cathodes connect to the row lines. The band on a 1N4148 diode marks its cathode end—check that it matches the board marking before soldering.
- J1 and J2 are separate four-pin row and column connectors. They connect to the Main Board's eight-pin J2 according to the project's mapping.
- The large 12 mm opening provides SQL switch pass-through clearance.
- After soldering, use flush cutters to trim the diode leads and pin-header pins protruding from the **front side of the PCB** so the board can sit flush behind the faceplate. Trim close to the solder joints without cutting into the joints or PCB pads, then remove the clipped pieces before mounting the board.

After trimming, I went back and added a small amount of solder to the diode holes to ensure a good connection. Keep the solder low enough for the PCB to sit flush behind the faceplate.

<p align="center">
  <a href="../../images/Button-Matrix-Front-Trimmed-Leads.jpg">
    <img src="../../images/Button-Matrix-Front-Trimmed-Leads.jpg" width="350" alt="Front of the Button Matrix PCB after trimming the protruding diode leads and pin-header pins">
  </a>
</p>

*Front of my Button Matrix PCB after trimming the diode leads and pin-header pins. Click the photo to view it full size.*

Button positions and the final v3.1 board fit have been checked. **Pending:** photographed soldering order, manufactured-board assembly, and electrical validation.

## 5. Assemble the Rotary Encoder PCB

Start with the [Rotary Encoder instructions](../../PCBs/Rotary%20Encoders/README.md). This board holds the five frequency encoders and the channel encoder. An encoder reports which way you turn it; it is different from the fixed-position rotary switches in step 6.

- Use six Bourns **PEC11H-4220F-S0024** encoders.
- Fit the 14-pin connector using the board orientation shown in its project. J1 pins 13 and 14 are GND.
- The encoders' push-switch contacts are unused in this design.
- Fit the **six printed encoder spacers**, one at each encoder's threaded faceplate mounting section.

I’ve checked the PCB’s physical fit, and all six encoders worked in my combined hardware test. **Pending:** photographed assembly order and electrical testing of a manufactured board.

## 6. Assemble the Rotary Switch boards and SQL switch

Refer to the [Rotary Switch instructions](../../PCBs/Rotary%20Switches/README.md).

For each of the two seven-position controls, use the C&K **A12505RNCQ PCB-terminal switch**, fit all six 1 kΩ resistors R1–R6, and leave JP1 open. J1 pin 1 is 3.3 V, pin 2 is the signal, and pin 3 is GND. Set the travel stops and knob orientation to suit the faceplate.

The SQL On/Off switch is the **A12515RNZQ solder-lug version with the longer shaft**. It does not fit directly into the PCB-terminal footprint.

- **Direct wiring:** connect the switch common to the Main Board SQL signal and the selected contact to GND. Select the contact and travel stops to match the panel's ON/OFF positions.
- **Optional SQL PCB:** use wires from the solder-lug switch to the corresponding board connections. Leave R1–R6 unpopulated and bridge the board's JP1 ON/OFF solder jumper. Bridging means joining the jumper’s two pads with a small amount of solder. Follow its README for the contact and connector mapping.
- Fit **shaft spacer v.5 in either configuration**.

**Pending:** detailed SQL mounting photographs, final stack spacing and wire routing, and manufactured-board assembly validation.

## 7. Dry-fit the faceplate, TFT, and boards

Use the current TFT bracket, encoder spacers, switch shaft spacer, and faceplate. Check button movement and shaft alignment before soldering or fastening makes adjustment difficult.

The Main Board component bodies face **away from the faceplate**, on the back of the board. Version 1.1 includes the switch shaft and anti-rotation openings and four 3.5 mm mounting holes.

**Main Board v1.1 physical fit confirmed — October 29, 2026.**

**Pending:** exact standoff and socket heights, fastener lengths, TFT-to-board component clearance, final assembly order, and step-by-step photographs.

### USB cable strain relief — zip-tie slots added; physical validation pending

The [current Main Board PCB](../../PCBs/Master%20Board/README.md#usb-cable-zip-tie-slots) includes **two 4 × 2 mm oblong slots** below the Teensy's USB connector, aligned with its two pin rows. These are Edge.Cuts milling contours and are intended for a small **2.5 mm zip tie**.

After checking the fit of the actual cable and boot, pass the tie through the two slots and around the cable so pulls are taken by the PCB support rather than the Micro-B connector. Avoid overtightening and leave enough slack to unplug the cable and remove the socketed Teensy for service.

**Pending:** physical fit and strain-relief validation with the actual cable/tie, an installation photograph, and the design/printing of any additional cable support. The slots are included in the published Main Board v1.1 manufacturing files; physical validation remains pending.

## 8. Main Board assembly and wiring — pending final validation

Use the [current Main Board schematic and README](../../PCBs/Master%20Board/README.md) for the detailed connections and board pictures. This section records the v1.1 connections; I’ll add assembly photos and fit details as I test the boards.

| Main Board connection | Purpose |
| --- | --- |
| J1 | TFT cable; **not straight-through**—use the [TFT cable mapping](../../parts/README.md#pin-headers-and-mating-connectors--october-12-2026) |
| J2 | Button Matrix cable; split into the two four-pin board connectors as documented |
| J4 | Rotary Encoder board; 14-pin cable, pin-for-pin |
| J9 — MODE | Signal on pin 2 to GPIO 15 / A1 through R2 |
| J10 — MASTER | Signal on pin 2 to GPIO 14 / A0 through R1 |
| SQL1 | Pin 1 SQL signal / GPIO 41; pin 2 GND |
| TP1 / TP2 | Alternative SQL solder-wire connections: TP1 signal, TP2 GND |

J9 and J10 each use pin 1 = 3.3 V, pin 2 = signal, pin 3 = GND. For the optional SQL switch-board cable, follow the specific SQL mapping in the parts README; do not assume all three-pin cables have identical use.

The Teensy is USB-powered. TFT VCC comes directly from **Teensy 3.3 V**. The removed protected 5 V circuit, Main Board JP1 selector, and C5/C6 are not fitted. C1/C2 and R1/R2 remain as rotary-input filters. The separate Rotary Switch PCB's JP1 is still used as described in step 6.

Use the **GPIO labels printed on the Teensy** for wiring instructions; they are not the KiCad symbol's pad numbers. Before connecting USB, leave power disconnected and check the cables with your multimeter. Confirm that each wire reaches its intended pin (continuity), connectors face the right way, and there are no unintended solder bridges or shorts between power and ground.

**Pending:** final Main Board fabrication and assembly, full-panel current verification, cable lengths and routing, and photographed continuity checks.

## 9. Test the hardware in stages

I tested the existing test firmware on my development hardware. **Validation of the assembled manufactured boards remains pending.**

1. Start with the [TFT hello test and test-code instructions](../../Firmware/Test%20Code/README.md). Confirm that the display works.
2. Use the standalone encoder and rotary-switch tests there if a control needs troubleshooting.
3. Load the [final combined hardware test HEX](../../Firmware/Test%20Code/ARC210_Final_Hardware_Test_Teensy41.hex) and follow the [combined-test instructions](../../Firmware/Test%20Code/ARC210_Button_Test/README.md).
4. Check all sixteen buttons, six encoders in both directions, both seven-position switches, and TFT brightness control.
5. **Pending:** a documented end-to-end SQL On/Off test and complete manufactured-panel acceptance checklist. I still need to document SQL testing separately; the combined test alone does not confirm its operation.

Loading a test HEX replaces the firmware currently on the Teensy. The standalone tests do not require DCS. Disconnect USB before changing wiring.

## 10. Load the radio firmware and configure DCS-BIOS

Follow the [DCS-BIOS setup guide](../DCS-BIOS.md) for installation, the downloadable Lua files or manual edits, firmware loading, TekConnect, and connection checks. The [firmware README](../../Firmware/Master%20Hex%20Files/README.md) lists the current HEX and its features and limitations.

The current radio HEX is a **display/menu preview**; physical controls do not yet provide complete in-game radio operation. The screen can remain blank until powered-radio data arrives. For offline testing, use the [ARC-210 dcsBiosDebug instructions](https://github.com/dgdimick/dcsBiosDebug/blob/arc210-working/ARC210_TESTING.md).

**Pending:** complete physical-control firmware integration, final DCS-BIOS installation screenshots, and full in-DCS acceptance testing on the manufactured assembly.

## 11. Troubleshooting and remaining guide work

| Symptom | First check |
| --- | --- |
| Teensy cannot be programmed or no USB data | Use a Micro-B data cable and the Teensy's programming button; follow the firmware loading instructions |
| TFT blank during a hardware test | Start with the hello test; verify J1's non-straight-through mapping and backlight GPIO 4 |
| TFT blank with radio firmware | Confirm powered-radio updates are being received, as explained in the firmware README |
| Encoder or matrix input missing | Check the connector mapping, continuity, diode polarity, and standalone test results |
| Rotary-switch readings wrong | Check 3.3 V/signal/GND, resistor population, JP1 configuration, and travel stops |

**Pending:** assembly photographs, annotated connector-orientation diagrams, measured mounting hardware, validated manufactured-board procedures, and final acceptance results.

If you get stuck, tell me which step you’re on, the board version, and what you’re seeing in [GitHub Discussions](https://github.com/dgdimick/ARC-210-DCS-Display/discussions). A clear photo can help me understand the problem. Questions and progress photos are welcome, even if this is your first panel.

I welcome bug reports from anyone using the project—**even tiny bugs are worth reporting**. If something doesn’t work as expected, please let me know in [Issues](https://github.com/dgdimick/ARC-210-DCS-Display/issues) or [Discussions](https://github.com/dgdimick/ARC-210-DCS-Display/discussions). Tell me which firmware version and board revision you’re using, if applicable, what you did, what you expected, and what happened. Reports about the build instructions are welcome too. Your reports help me improve the project for everyone.

## Sharing code and improvements

My main firmware code is shared under the [MIT License](../../Docs/LICENSE-MIT.txt), and I’m happy to provide it to anyone who asks. You can also find the [published source here](../../Firmware/Source/Master_Program/README.md). If you adapt it or add improvements, I’d love to work with you and bring useful changes back into this project so other builders—and my other panel projects—can benefit too.

Please share your changes through a pull request or get in touch in [Discussions](https://github.com/dgdimick/ARC-210-DCS-Display/discussions). Contributing changes back is welcome, but it isn’t an extra condition of the MIT License. Third-party code keeps its own license. The PCB designs retain their separate hardware license.

[Back to documentation](../README.md) · [Back to main README](../../README.md)
