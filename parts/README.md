# Parts

**Last updated: October 31, 2026 at 12:26 AM MDT (America/Denver)**

Updated October 29, 2026.

[View the component list (BOM.csv)](BOM.csv)

The BOM lists schematic references, values, footprints, quantities, and do-not-populate flags for the ARC-210 Main Board. Its non-connector entries originate from a September 25 snapshot of the [KiCad project](../PCBs/Master%20Board/), with subsequent parts-selection updates. I checked the connector entries against the October 12 Main Board schematic and final control-board projects. The Main Board v1.1, Button Matrix v3.2, Rotary Encoder v1.4, and Rotary Switch v2.0 design and manufacturing files are published. I’ll keep improving the parts list as I assemble and test the manufactured boards. I still need to check a few component details and footprints, so please check the notes before placing an order. If anything is unclear, ask in Discussions. Panel hardware and supplier links are listed below because the schematic BOM does not describe every mechanical part.

## Power and future button lighting

The Teensy is powered by USB, and **TFT VCC connects directly to the Teensy's 3.3 V rail** (`TEENSY_3V3`, U1 pad 15). I’ve tested the TFT at 3.3 V and found the brightness satisfactory. I removed the external protected 5 V input and Main Board JP1 power selector. I removed C5 (470 µF) and C6 (0.1 µF) to match the direct Teensy-to-TFT wiring I tested. C1/C2 and R1/R2 remain as the rotary-input filters. Keep total external 3.3 V consumption within PJRC's recommended 250 mA maximum; brightness confirmation is not a current measurement.

Future button lighting would require a separate power and driver design, suitable light-transmitting buttons, and a new Button LED PCB. The current Main Board has no external lighting-power circuit. I’m leaving this lighting redesign for later and prioritizing the other radio projects.

## Estimated build cost

I’m distressed by the total cost of this project, and I worry it may put the build beyond some people’s budgets. I want to be open about that so you can decide whether it fits your budget before buying parts. Considering the controls, display, and functionality the panel is designed to provide, I still feel it’s worth the cost.

I’ve spent about two months working on the code, averaging four hours a night—roughly **240 hours**. I’m sharing the source code for free so other builders don’t have to do all that development work themselves. The parts still cost money, but I hope the time and effort this saves helps make the project worthwhile.

My PCBs are designed around the faceplate and layout I’m using, so they may not fit someone else’s custom panel. I’m sharing the [source code](../Firmware/Source/Master_Program/README.md) so other builders can reuse it or adapt it to their own controls, displays, and wiring. Some changes may be needed, but I hope it gives people a useful starting point and saves them development time.

I’ve also spent about **US$500 on extra parts during development**. Buying more parts as I work toward a finished project adds up. That is my development expense; it is not an extra charge to builders or part of the estimated cost to build one panel. I’m still very happy to share this project with others. We all enjoy adding to our SIMPITs, no matter how big or small they are.

One thing I’m very pleased about is that I’m developing the same ARC-210 panel hardware for every aircraft I’ve planned to support, including the A-10C II and C-130J. I’m designing a shared code base that will automatically use the appropriate controls and display data for the aircraft you’re flying, so you won’t need to reflash the Teensy when switching between supported aircraft—just fly the aircraft. **This automatic aircraft support is still being developed and tested; it is not a completed feature yet.** Aircraft-specific DCS-BIOS mappings will be handled within that shared setup.

I’ll label radio HEX downloads with the aircraft they support and a version number, increasing the version whenever I publish updated firmware so you can tell releases apart. Each new aircraft-support release will retain support for the previously supported aircraft. Adding an aircraft will require loading the updated HEX once, using the same Teensy Loader procedure as the first flash while the panel is connected by USB. After that, switching between aircraft included in that version will not require reflashing. **This cumulative aircraft support and automatic selection are still being developed and tested.**

To help you plan your build, I’ve put together an estimated parts budget of **US$250–US$285 before shipping, handling, tax, VAT, and other applicable fees**, including the PC Flights faceplate. All prices in this parts-cost table are in **US dollars (USD)** so you can convert them to your local currency. The links below point to independent suppliers; the figures are a budgeting guide rather than a kit price.

This is primarily a DIY project. I share the files and build notes to help you make your own panel. You can purchase components from the linked suppliers and print the STL parts yourself or use a printing service. **Contact me in [Discussions](https://github.com/dgdimick/ARC-210-DCS-Display/discussions) about buying one complete set of bare PCBs from me**, as a convenient way to get the boards for one radio without ordering extra copies of every design. The **complete six-board set is US$40, plus shipping, handling, tax, VAT, and any other applicable tariffs, duties, or fees**: one Main Board, one Button Matrix, one Rotary Encoder, and three Rotary Switch boards, including the optional SQL board. Components and assembly are not included. Contact me to confirm availability and shipping. You can also order the boards directly using my [PCB manufacturing guide](../Docs/PCB-Manufacturing-JLCPCB.md). If you’re stuck, I’m happy to help where I can.

I’m offering this as a **convenient complete set for one radio**: you get the boards you need without managing four separate PCB design uploads or ordering the manufacturer’s minimum quantity of every design. **Any savings depend on your location, shipping, handling, tax, VAT, tariffs, and other applicable fees**, so compare the full delivered totals. I’m not promising that my set will always be cheaper than ordering directly.

My own order for all the boards cost **about US$75**. That is an approximate total for my board order, not the manufacturing cost of a single six-board set or a guaranteed quote for another builder. My complete-set price remains **US$40 plus shipping, handling, tax, VAT, and other applicable fees**.

Prices checked October 22, 2026, except the recommended Teensy with headers (October 29) and the JLCPCB fabrication estimate (October 30). The PCB cost uses the **US$41.10 JLCPCB estimate** from my [manufacturing cost comparison](../Docs/PCB-Manufacturing-JLCPCB.md). It covers five copies of each of the four designs—**20 bare boards total**, enough for one panel with spare boards. Small hardware costs remain allowances, and supplier prices can change.

| Part / sourcing reference | Quantity needed | Estimated builder cost (USD) |
| --- | ---: | ---: |
| [PC Flights faceplate with painted buttons](https://pcflights.com/a-10c-thunderbolt-warthog-vhf-uhf-panel/) | 1 | $51.00 |
| [Teensy 4.1 with headers — recommended](https://www.sparkfun.com/teensy-4-1-headers.html) | 1 | $35.95 (checked October 29, 2026) |
| [Hosyond 3.5-inch ILI9488 SPI TFT display](https://www.amazon.com/dp/B0BWJHK4M6) | 1 | About $18 |
| [Bourns PEC11H-4220F-S0024 rotary encoders](https://www.mouser.com/ProductDetail/Bourns/PEC11H-4220F-S0024?qs=7MVldsJ5UayW2mw8xYm74g%3D%3D) | 6 | $19.74 |
| [C&K A12505RNCQ multi-position rotary switches](https://www.digikey.com/en/products/detail/c-k/A12505RNCQ/2043159) | 2 | $26.82 |
| [C&K A12515RNZQ SQL On/Off rotary switch](https://www.digikey.com/en/products/detail/c-k/A12515RNZQ/678340) | 1 | $12.01 |
| [6 × 6 × 5 mm tactile button switches](https://www.amazon.com/dp/B01CGMP9GY) and [matrix diodes](#hardware-selection-and-supplier-links) | 16 each | $5–$10 |
| [Resistors, capacitors and remaining electronics](BOM.csv) | Allowance pending an updated full-panel parts estimate; removed power/protection parts are excluded | $10–$20 |
| [Headers, Teensy sockets, cable connectors and wire](#pin-headers-and-mating-connectors--october-12-2026) | Parts needed for one build | $15–$25 |
| [Required PCB standoff kit and screws](https://www.amazon.com/dp/B0H1QS5Q6N) | 1 kit | $10 |
| [3D-printed knobs, brackets and spacers](../Supporting%20STL%27s/README.md) | Filament used | $3–$8 |
| [Bare PCBs from JLCPCB](../Docs/PCB-Manufacturing-JLCPCB.md) | Five copies of each of four designs: 20 boards total; one panel uses five or six | US$41.10 fabrication estimate; excludes shipping, handling, tax, and VAT |
| USB Micro-B data cable — for powering and programming the Teensy 4.1 | 1 | $3–$6 |
| **Estimated DIY purchasing cost using JLCPCB (rounded)** | | **US$250–US$285** |

Both options use the same component estimates and include the PC Flights faceplate. These calculated totals are estimates, not fixed kit prices; rounded for budgeting, either option is about **US$250–US$285**.

| PCB purchasing option | PCB cost (USD) | Estimated total parts cost (USD) |
| --- | ---: | ---: |
| JLCPCB: five copies of each of four designs (20 bare boards) | US$41.10 | US$250.62–US$283.62 |
| My complete six-board bare-PCB set for one radio | US$40.00 | US$249.52–US$282.52 |

**Shipping, handling, tax, and VAT are separate and are not included in either total.** Tariffs, duties, and other applicable fees are also extra. Compare the delivered totals for your location.

Use a **USB Micro-B data cable** for powering and programming the **Teensy 4.1**. The cable must carry data as well as power; a charge-only cable cannot program the Teensy or carry the panel’s USB communications.

The current Main Board is USB-powered and does not use an external 5 V adapter. A future button-lighting redesign would need its own power arrangement, which is outside the current build estimate.

This estimate excludes tools, labor, cockpit mounting fasteners, **shipping, handling, tax, VAT**, tariffs, duties, and other applicable fees. The JLCPCB minimum quantities are included in the PCB row and leave spare boards. Buying component assortments may increase the initial purchase cost and leave spare components.

**PCB pricing is an estimate:** the US$41.10 fabrication subtotal depends on the quoted settings and quantities; check the current price and all extra charges before ordering. Main Board v1.1, Button Matrix v3.2, Rotary Encoder v1.4, and Rotary Switch v2.0 manufacturing files are published. See the component details and wiring requirements below.

<a id="six-pcb-layout"></a>

## PCB layout — five or six boards

The panel uses five required PCBs: one Main Board, one Button Matrix, one Rotary Encoder, and two multi-position Rotary Switch boards. An optional SQL On/Off switch PCB brings the total to six; it can be omitted when wiring directly to the switch’s solder lugs.

The [shaft spacer v.5](../Supporting%20STL%27s/Shaft_Spacer_v.5.stl) is **required in all installations** to support the **longer SQL On/Off switch shaft**, whether or not the optional PCB is fitted.

All boards are controlled by one Teensy 4.1. The estimate above allows for all six boards.

The three rotary switch PCBs use the same design and are interchangeable. I fit six resistors on each of the two multi-position switch boards. When using the optional SQL On/Off switch board, I omit all resistors and bridge the JP1 solder pad; its solder-lug switch connects to the board with wires.

**SQL On/Off direct-wiring option:** The SQL On/Off PCB is optional when using the solder-lug switch. You can solder wires directly to the switch’s common lug and the selected contact lug, then connect them to the Main Board’s SQL signal (GPIO 41) and GND connections. Select the contact to match the panel’s SQL On/Off positions and configure GPIO 41 with a pull-up. No resistor ladder is needed for this option. Dedicated **TP1 (SQL signal, GPIO 41 / U1 pad 33)** and **TP2 (GND)** solder-wire pads are now included in the Main Board schematic and PCB draft. The optional SQL1 header remains available. The pads are placed and routed in the current draft; I’ve checked the physical fit of Main Board v1.1; I still need to check the assembled board.

## Rotary-switch test wiring

**Tested wiring:** I tested both seven-position rotary switches, and they worked with each switch PCB’s J1 pin 2 connected directly to its Teensy input (GPIO 14 or GPIO 15), without the 220 Ω series resistor or 100 nF input-filter capacitor. The six 1 kΩ resistor-ladder resistors on each switch PCB were still fitted, and JP1 was left open. I saw some fluctuation in the TFT voltage readings, but it did not affect the detected switch positions. This records the successful breadboard setup; the input-filter components shown in the Main Board schematic were not part of that test.

## BOM coverage

[BOM.csv](BOM.csv) originated from the ARC-210 Main Board schematic and includes subsequent panel-hardware selections. Panel-hardware entries are explicitly labelled so their references are not confused with Main Board references. The board-specific purchasing lists are still being refined. The quantities already account for the documented build, so there’s no need to multiply them by the number of PCBs.

The corrected [Rotary Switch KiCad project, version 2.0](../PCBs/Rotary%20Switches/), replaces the withdrawn initial version. Version 2.0 retains the corrected pin assignments and adds an ON/OFF solder jumper for SQL On/Off. Omit R1–R6 and bridge JP1 for SQL On/Off operation; fit the resistors and leave JP1 open for resistor-ladder operation. See the project instructions for wiring and pull-up configuration.

## Panel illumination removed — October 6, 2026

The panel/button illumination LEDs have been dropped because there is insufficient clearance with the TFT display in the current mechanical layout. The buttons supplied with the PC Flights panel used for this build are painted and opaque, so light will not pass through them. Adding LEDs behind these buttons would not illuminate their legends; backlit buttons would require suitable light-transmitting replacements. The parts list no longer includes the 16 panel LEDs (D21–D36) or their 16 current-limiting resistors (R21–R36). The TFT display and its backlight remain. The separate power-indicator LED was removed with the protected 5 V branch.

This update changes the documentation and parts list only; existing schematic drawings may still show the former panel-lighting circuit.

## Main Board direct TFT power

The Teensy is powered by USB, and **TFT VCC connects directly to the Teensy's 3.3 V rail** (`TEENSY_3V3`, U1 pad 15). I’ve tested the TFT at 3.3 V and found the brightness satisfactory. I removed the external protected 5 V input and Main Board JP1 power selector. I removed C5 (470 µF) and C6 (0.1 µF) to match the direct Teensy-to-TFT wiring I tested. C1/C2 and R1/R2 remain as the rotary-input filters. Keep total external 3.3 V consumption within PJRC's recommended 250 mA maximum; brightness confirmation is not a current measurement.

C5 (470 µF) and C6 (0.1 µF) are no longer fitted or required purchases. The Main Board has no added TFT supply capacitors; its TFT connections match the tested direct Teensy wiring.

J3, F2, D1, D2, D3, Q2, R15–R17, C5/C6, and the Main Board JP1 header/shunt are removed and are not required purchases for this revision. The [BOM](BOM.csv) has been updated to remove those entries. The obsolete Q3, R37, and R38 entries, absent from every current board schematic, have also been removed from the BOM. The matrix diode entries specify 1N4148 with the current DO-35 footprint, including corrected D8. The cost allowance still needs review before purchasing; use the current board schematics as the authority for fitted parts.

The 100 nF rotary-input capacitors C1/C2 and series resistors R1/R2 are retained. SQL solder-wire pads TP1/TP2 are placed and routed in the Main Board draft; I’ve checked the physical fit of Main Board v1.1; I still need to check the assembled board.

## Teensy GPIO labels and KiCad pin numbers

**Use the numbers printed on the Teensy (or the matching GPIO labels on your breakout adapter) when following the firmware and wiring instructions.** KiCad uses a separate set of pin/pad numbers for the Teensy symbol and its matching `teensy:Teensy41` footprint. These include power and ground connections, so they are not the same as GPIO numbers.

| Teensy printed label / firmware GPIO | KiCad U1 pin / footprint pad |
| --- | ---: |
| GND (one of several ground connections) | 1 |
| 0 | 2 |
| 4 — TFT backlight | 6 |
| 14 / A0 — rotary-switch input | 36 |
| 15 / A1 — rotary-switch input | 37 |

For example, connect a rotary-switch signal to the Teensy connection marked **14/A0**, which is **KiCad pad 36**—not pad 14. In KiCad, read the symbol’s pin name and net label to identify the signal. Updating the PCB from the schematic with the matching symbol and footprint maps the connections to the correct physical locations. This pad mapping applies to the Teensy library supplied with this project; other libraries may use different numbering.

<a id="pin-headers-and-mating-connectors--october-12-2026"></a>

## Pin headers and mating connectors — October 27, 2026

Quantities below are for **one complete panel with the optional SQL On/Off PCB installed**, including all three rotary-switch PCBs. If you wire the solder-lug SQL switch directly, omit its PCB-side header and cable connectors as appropriate for your wiring method. Dedicated **TP1 (SQL signal, GPIO 41 / U1 pad 33)** and **TP2 (GND)** solder-wire pads are now included in the Main Board schematic and PCB draft. The optional SQL1 header remains available. The pads are placed and routed in the current draft; I’ve checked the physical fit of Main Board v1.1; I still need to check the assembled board. Use single-row **2.54 mm pitch** headers and matching female cable connectors. The removed six separate encoder headers and two 9-pin rotary-switch headers are obsolete.

| Location / use | Board-side male header | Quantity | Mating cable housings |
| --- | --- | ---: | --- |
| Main Board J4 and Encoder PCB J1 | 1x14 | 2 | Two 1x14 female |
| Main Board J2 | 1x08 | 1 | One 1x08 female |
| Button Matrix PCB J1/J2 | 1x04 | 2 | Two 1x04 female |
| Main Board J9/J10 and two multi-position switch PCBs | 1x03 | 4 | Four 1x03 female |
| Main Board SQL1 | 1x02 | 1 | One 1x02 female |
| SQL On/Off switch PCB J1 | 1x03 | 1 | One 1x03 female; use pins 2 and 3 only |
| Main Board J1, TFT connection | 1x08 | 1 | One 1x08 female at master; one 1x14 female at TFT module |
| Teensy mounting | Two 1x24 male strips on Teensy | 2 | Two 1x24 female PCB socket strips on master |

Totals: **two 1x14, two 1x08, two 1x04, five 1x03 and one 1x02 male board headers**, plus two 1x24 Teensy male strips if not already fitted. Cable housings total **three 1x14, two 1x08, two 1x04, five 1x03 and one 1x02 female**, separate from the two 1x24 board sockets. Use at least **76 female crimp contacts**, plus spares, matched to the housing manufacturer's series. Wire lengths depend on the final panel layout. Preterminated female cables can replace housings and crimp contacts without counting both.

The TFT module normally already has its 14-pin male header. Check before purchasing an additional one. The final [Button Matrix v3.2](../PCBs/Button%20Matrix/) uses separate four-pin row and column connectors. Split the Main Board J2 eight-wire matrix cable accordingly: pins 1–4 to Button Matrix J1, and pins 5–8 to Button Matrix J2. Main J2 and J9/J10 now have 2.54 mm header footprints assigned. Check connector stack height and cable clearance when arranging the Main PCB. Unused Teensy USB-host, Ethernet and auxiliary headers are not required.

**Cable mapping matters:** the encoder cable is pin-for-pin between the two 14-pin headers. The matrix cable uses rows on pins 1–4 and columns on pins 5–8. Multi-position switch cables use 1 = 3.3 V, 2 = signal and 3 = GND. When using the optional SQL On/Off PCB, its cable maps master SQL1 pin 1 to switch-board J1 pin 2, and SQL1 pin 2 to switch-board J1 pin 3; switch-board pin 1 stays unused.

The TFT cable is **not straight-through**. With the current Main Board schematic and MSP3520 module manual, connect:

| Main Board J1 pin | Signal | TFT module pin |
| --- | --- | --- |
| 1 | Teensy 3.3 V (direct supply) | 1 |
| 2 | GND | 2 |
| 3 | RESET / GPIO8 | 4 |
| 4 | CS / GPIO10 | 3 |
| 5 | SCK / GPIO13 | 7 |
| 6 | DC/RS / GPIO9 | 5 |
| 7 | MOSI / GPIO11 | 6 |
| 8 | Backlight control / GPIO4 | 8 |

TFT module pins 9–14 are unused in this connection. Use the module's printed signal labels to identify pins, and check cable continuity before power-up. When using the optional SQL On/Off PCB, its ON/OFF solder bridge needs solder only, not another shunt; direct wiring does not use this bridge.

## Current button switches

Use **16 switches per panel**, each **6 × 6 × 5 mm**, SPST momentary tactile, with four through-hole leads. The body still occupies 6 × 6 mm on the board.

The selected generic footprint is `Button_Switch_THT:SW_PUSH-6mm`. Confirm the purchased switches' lead spacing and contact pairing against it before fabrication.

## Complete master print set

**The 17-part set has passed test fitting at 100% scale, with Channel v4.2 separately reprinted and confirmed after the earlier complete-layout test. The combined downloads now include that replacement.** Please keep checking [Project Updates](../Docs/Project-Updates.md) for any changes.

The [master STL](../Supporting%20STL%27s/ARC-210-Complete-Print-Set-All-17.stl) and [master 3MF](../Supporting%20STL%27s/ARC-210-Complete-Print-Set-All-17.3mf) contain **17 parts**: all nine knobs, **one display bracket, six encoder spacers, and one SQL shaft spacer**. Print one set at **100% scale**. I have printed the complete 17-part layout at **100% scale**, and all parts passed test fitting. See the [master layout notes](../Supporting%20STL%27s/README.md#complete-17-part-print-set) for dimensions and slicing guidance.

**Master downloads checked — October 30, 2026:** I checked the master STL and 3MF and confirmed that both include **Channel v4.2 and SQL v1.2, with all 17 parts at 100% scale**. The knob geometry matches the individual STL downloads, the 3MF uses millimeter units with no scaling applied, and the master STL matches the 17-part 3MF geometry. This is a file check; the replacement Channel v4.2 was physically test-fitted separately from the earlier complete-layout print.

## Required 3D-printed knobs

**All current knobs print at 100% slicer scale with the current hardware:** Frequency v10.1, Mode v4, Channel v4.2, and SQL v1.2. The shaft-fit adjustments are already built into these files; no additional scaling is needed.

Print the following quantities for one ARC-210 panel:

| Knob | Quantity to print | STL |
| --- | ---: | --- |
| Frequency | 5 | [Freq_Knob_v.10.1.stl](../Supporting%20STL%27s/Freq_Knob_v.10.1.stl) |
| Mode | 2 | [Mode_Knob_v.4.stl](../Supporting%20STL%27s/Mode_Knob_v.4.stl) |
| Channel | 1 | [Channel_Knob_v.4.2.stl](../Supporting%20STL%27s/Channel_Knob_v.4.2.stl) |
| SQL ON/OFF | 1 | [SQL_Knob_v.1.2.stl](../Supporting%20STL%27s/SQL_Knob_v.1.2.stl) |

Print the nine-knob layout using the [combined STL](../Supporting%20STL%27s/ARC-210-Knob-Set-V3-All-9.stl) or [combined 3MF](../Supporting%20STL%27s/ARC-210-Knob-Set-V3-All-9.3mf). Both contain **5 Frequency, 2 Mode, 1 Channel, and 1 SQL knob (nine total)**; the 3MF keeps them as separate objects. See the [combined-layout printing notes](../Supporting%20STL%27s/README.md#complete-nine-knob-print-layout) before slicing. Print the combined file once at **100% scale** for all nine knobs. Channel v4.2 and SQL v1.2 have the same outside size and small side hole; Channel has the smaller shaft hole.

## Channel and SQL knobs

[Channel knob v4.2](../Supporting%20STL%27s/Channel_Knob_v.4.2.stl) · [SQL knob v1.2](../Supporting%20STL%27s/SQL_Knob_v.1.2.stl)

**The Channel and SQL knobs are the same outside size, with the same small side hole; only the shaft holes differ.** Channel v4.2 has the smaller shaft hole; SQL v1.2 retains the larger shaft hole. Channel v4.2 uses the Frequency v10.1 shaft-hole profile (approximately 6.375 mm round diameter), with the Channel socket depth, outside dimensions, and small side hole unchanged. I printed Channel v4.2 at **100% scale** and confirmed the fit. SQL remains v1.2 with its previously tested socket. Print **one Channel v4.2 and one SQL v1.2**, each at 100%; these files are no longer interchangeable.

The SQL shaft support spacer v.5 remains required in all installations.

## USB cable strain-relief support — design pending

I still need to **design and 3D print the USB cable strain-relief support**. It should secure the cable to the Main Board mounting structure or panel so cable pulls do not load the Teensy's Micro-B connector, while leaving enough slack to unplug the cable and remove the Teensy. Its finished STL and physical fit verification are pending.

## Required 3D-printed spacers

- **Rotary Encoder spacers: print six.** Use [Rotary_Encoder_Spacer_v.1.stl](../Supporting%20STL%27s/Rotary_Encoder_Spacer_v.1.stl), one per encoder, to center the encoder threads in the faceplate holes.
- **SQL On/Off shaft spacer: print one.** Use [Shaft_Spacer_v.5.stl](../Supporting%20STL%27s/Shaft_Spacer_v.5.stl) in all installations to support the longer SQL switch shaft, whether or not its optional PCB is fitted.

Both spacer quantities are included in the [BOM](BOM.csv).

## Hardware selection and supplier links

**Note:** This is intended to be a relatively simple design.

- **Microcontroller:** Teensy 4.1 with pre-soldered headers — recommended.
  [SparkFun](https://www.sparkfun.com/teensy-4-1-headers.html) · [Amazon example](https://www.amazon.com/PJRC-Teensy-4-1-with-Pins/dp/B08CTM3279)

I recommend buying a **Teensy 4.1 with pre-soldered male header pins**: [SparkFun Teensy 4.1 (Headers)](https://www.sparkfun.com/teensy-4-1-headers.html), or this [Amazon Teensy 4.1 with Pins listing](https://www.amazon.com/PJRC-Teensy-4-1-with-Pins/dp/B08CTM3279) as an alternative example. The pre-fitted pins avoid having to solder the two long header rows yourself. The Main Board's two 1 × 24 female sockets are separate parts; they are optional but recommended for removing the Teensy during board upgrades or replacement.

- **Display:** ILI9488 SPI TFT, 3.5-inch
  [Amazon](https://www.amazon.com/dp/B0BWJHK4M6)

- **Encoders:** Six Bourns **PEC11H-4220F-S0024**, matching the current encoder PCB. These have PCB terminals and an integrated push switch. The older seven-encoder quantity and 4215 shaft-option links are superseded.
  [Mouser — 652-PEC11H4220FS0024](https://www.mouser.com/ProductDetail/Bourns/PEC11H-4220F-S0024?qs=7MVldsJ5UayW2mw8xYm74g%3D%3D)

- **Multi-position rotary switches:** Two C&K **A12505RNCQ**, with 1/2-inch (12.7 mm) shafts, 45-degree indexing and **C PCB-pin terminals**. These replace the solder-lug versions for the two resistor-ladder PCBs. The circuit uses seven positions of each eight-position switch; verify the corrected wiring and stop-ring setting against the panel.
  [Mouser — 611-A12505RNCQ](https://www.mouser.com/en/ProductDetail/CK/A12505RNCQ?qs=h7H1bHRqGz9AS0MdXl06Aw%3D%3D) · [C&K datasheet](https://www.ckswitches.com/media/1349/arotary.pdf)

- **SQL On/Off switch:** One C&K **A12515RNZQ**, with a 1-1/2-inch (38.1 mm) shaft, 45-degree indexing and **Z solder-lug terminals**. Mount it in a bracket, fit the [required shaft spacer v.5](../Supporting%20STL%27s/Shaft_Spacer_v.5.stl) to support its longer shaft in all installations, and wire its contacts to the Teensy input. It does not mount directly in the PCB-pin footprint and does not need a resistor ladder. The panel's ON and OFF markings are two clicks (90 degrees) apart; confirm the contact selection and travel stops against those markings.
  [Mouser](https://www.mouser.com/ProductDetail/CK/A12515RNZQ) · [C&K datasheet](https://www.ckswitches.com/media/1349/arotary.pdf)

- **Faceplate:** A-10C "Thunderbolt" / "Warthog" VHF/UHF cockpit panel
  [PC Flights](https://pcflights.com/a-10c-thunderbolt-warthog-vhf-uhf-panel/)<br>
  PC Flights has supplied me with a drawing file to assist with the Button PCB layout.

- **Button switches:** 16 per panel, 6 × 6 × 5 mm SPST momentary tactile push-button switches, four-pin through-hole
  [Amazon](https://www.amazon.com/dp/B01CGMP9GY)

- **PCB standoffs — required to install the PCBs; $10 per kit:** Vibit 640-piece M3 nylon standoff assortment, including male–female and female–female spacers with screws. The number of individual standoffs needed per panel is not yet finalized.
  [Amazon](https://www.amazon.com/dp/B0H1QS5Q6N)

  **Choose the stand-off height by the clearance your build needs.** Expect approximately **22–26 mm of total stand-off height**, depending on the shaft length of your SQL ON/OFF rotary switch. Dry-fit the boards, switch and faceplate, then select the height that provides the required clearance and correct shaft position before tightening the mounting hardware.

- **Diodes:** 16 × 1N4148 small-signal fast-switching diodes, DO-35
  The current Button Matrix PCB uses D5–D20; fit the 16 diodes as shown in its schematic.
  [Amazon](https://www.amazon.com/100-Pieces-1N4148-Switching-High-Speed/dp/B079KJ91JZ/ref=sr_1_1_sspa?s=industrial&sr=1-1-spons&sp_csd=d2lkZ2V0TmFtZT1zcF9hdGY)


[Back to the project README](../README.md)

## Questions and community builds

**Building your own panel, or just looking around?** [Introduce yourself in the welcome discussion](https://github.com/dgdimick/ARC-210-DCS-Display/discussions/1) and tell us what you fly. Questions, ideas, and progress photos are all welcome—even if you’re only getting started.

Visit [GitHub Discussions](https://github.com/dgdimick/ARC-210-DCS-Display/discussions) to ask questions, share ideas, and post photos of your builds.
