# Parts

Updated October 22, 2026.

[View the component list (BOM.csv)](BOM.csv)

The BOM lists schematic references, values, footprints, quantities, and do-not-populate flags for the ARC-210 master board. Its non-connector entries originate from a September 25 snapshot of the [KiCad project](https://github.com/dgdimick/Teensy/tree/main/KiCad/ARC-210_Master_Board), with subsequent parts-selection updates. Connector entries were reconciled against the October 12 master schematic and final control-board projects. The parts list is still being refined as I finish the main and button PCBs. A few component details and footprints need confirming, so please check the notes before placing an order. If anything is unclear, ask in Discussions. Panel hardware and supplier links are listed below because the schematic BOM does not describe every mechanical part.

## Power and future button lighting

The current design keeps the Teensy powered by USB. On the Master PCB, JP1 selects the TFT supply: **pins 1–2 select protected external 5 V; pins 2–3 select Teensy 3.3 V**. Fit only one shunt and remove power before moving it. JP1 does not select USB/VIN power. Keep the external protected 5 V rail separate from Teensy VIN and 3.3 V; the circuit uses a common ground. The TFT’s backlight is separate from the proposed button-lighting LEDs.

**Future button lighting will require the external 5 V supply and the associated power-input and protection circuitry to be installed.** USB/VIN power is not the planned source for this lighting option. It would also need a revised Master PCB with space for the lighting-control SCR, associated discrete components, and a pin header, plus a new Button PCB design. That Button PCB is not currently planned; the ARC-164 and ARC-184 projects will be completed before this option is revisited. Button-lighting LEDs are not part of the current build or parts estimate.

## Estimated build cost

To help you plan your build, I’ve put together an estimated parts budget of **$275–$320 USD before shipping and tax**, including the PC Flights faceplate. The links below point to independent suppliers; the figures are a budgeting guide rather than a kit price.

This is primarily a DIY project. I share the files and build notes to help you make your own panel. You’ll purchase components from the linked suppliers, arrange PCB fabrication with a manufacturer, and print the STL parts yourself or use a printing service. If you’re stuck and need a hand, feel free to ask in [Discussions](https://github.com/dgdimick/ARC-210-DCS-Display/discussions)—I’m happy to help where I can.

Prices checked October 22, 2026. Small hardware and PCB costs are allowances rather than supplier quotes.

| Part / sourcing reference | Quantity needed | Estimated builder cost |
| --- | ---: | ---: |
| [PC Flights faceplate with painted buttons](https://pcflights.com/a-10c-thunderbolt-warthog-vhf-uhf-panel/) | 1 | $51.00 |
| [Teensy 4.1 without Ethernet](https://www.sparkfun.com/teensy-4-1-without-ethernet.html) | 1 | $29.60 |
| [Hosyond 3.5-inch ILI9488 SPI TFT display](https://www.amazon.com/dp/B0BWJHK4M6) | 1 | About $18 |
| [Bourns PEC11H-4220F-S0024 rotary encoders](https://www.mouser.com/ProductDetail/Bourns/PEC11H-4220F-S0024?qs=7MVldsJ5UayW2mw8xYm74g%3D%3D) | 6 | $19.74 |
| [C&K A12505RNCQ multi-position rotary switches](https://www.digikey.com/en/products/detail/c-k/A12505RNCQ/2043159) | 2 | $26.82 |
| [C&K A12515RNZQ SQL On/Off rotary switch](https://www.digikey.com/en/products/detail/c-k/A12515RNZQ/678340) | 1 | $12.01 |
| [6 × 6 × 5 mm tactile button switches](https://www.amazon.com/dp/B01CGMP9GY) and [matrix diodes](#hardware-selection-and-supplier-links) | 16 each | $5–$10 |
| [Resistors, capacitors, power/protection components and backlight MOSFET](BOM.csv) | Parts needed for one build | $10–$20 |
| [Headers, Teensy sockets, cable connectors and wire](#pin-headers-and-mating-connectors--october-12-2026) | Parts needed for one build | $15–$25 |
| [Screws and PCB standoffs](https://www.amazon.com/dp/B0H1QS5Q6N) | Allowance | $8–$15 |
| [3D-printed knobs, brackets and spacers](../Supporting%20STL%27s/README.md) | Filament used | $3–$8 |
| [Bare PCBs](../PCBs/README.md) | Six boards, ordered from a PCB manufacturer | $75 budget allowance |
| USB cable | 1 | $3–$6 |
| **Estimated DIY purchasing cost** | | **$275–$320** |

For the current build without button lighting, an external regulated 5 V power adapter is optional when using the documented Teensy 3.3 V TFT supply option within its current limit. Allow approximately **$8–$15** for the adapter. **The external 5 V supply becomes required for any future button-lighting revision.**

This estimate excludes tools, labor, cockpit mounting fasteners, shipping, tax and tariffs. Buying component assortments or minimum PCB quantities may increase the initial purchase cost and leave spare parts.

**PCB pricing is provisional:** the main and button PCB layouts must be completed before an accurate fabrication quote is available. See the component details and wiring requirements below.

## Six-PCB layout

My build uses up to six PCBs controlled by one Teensy 4.1: the master PCB, button PCB, rotary encoder PCB, and three small rotary switch PCBs. The SQL On/Off PCB is optional, reducing the build to five boards if the solder-lug switch is wired directly. The estimate above allows for all six boards.

The three rotary switch PCBs use the same design and are interchangeable. I fit six resistors on each of the two multi-position switch boards. For the SQL On/Off switch board, I omit all resistors and bridge the JP1 solder pad; its solder-lug switch connects to the board with wires.

**SQL On/Off direct-wiring option:** The SQL On/Off PCB is optional when using the solder-lug switch. You can solder wires directly to the switch’s common lug and the selected contact lug, then connect them to the Master board’s SQL signal (GPIO 41) and GND connections. Select the contact to match the panel’s SQL On/Off positions and configure GPIO 41 with a pull-up. No resistor ladder is needed for this option. Dedicated, labelled SQL signal and GND solder pads are planned for the Master PCB so these wires can be soldered directly to it instead of using the switch PCB and cable headers; these pads have not yet been added to the PCB design.

## Rotary-switch test wiring

**Tested wiring:** Both seven-position rotary switches were tested and worked with each switch PCB’s J1 pin 2 connected directly to its Teensy input (GPIO 14 or GPIO 15), without the 220 Ω series resistor or 100 nF input-filter capacitor. The six 1 kΩ resistor-ladder resistors on each switch PCB were still fitted, and JP1 was left open. Some fluctuation was visible in the voltage readings on the TFT, but it did not affect the detected switch positions. This records the successful breadboard setup; the input-filter components shown in the master schematic were not part of that test.

## BOM coverage

[BOM.csv](BOM.csv) originated from the ARC-210 master-board schematic and includes subsequent panel-hardware selections. Panel-hardware entries are explicitly labelled so their references are not confused with master-board references. The board-specific purchasing lists are still being refined. The quantities already account for the documented build, so there’s no need to multiply them by the number of PCBs.

The corrected [Rotary Switch KiCad project, version 2.0](../PCBs/Rotary%20Switches/), replaces the withdrawn initial version. Version 2.0 retains the corrected pin assignments and adds an ON/OFF solder jumper for SQL On/Off. Omit R1–R6 and bridge JP1 for SQL On/Off operation; fit the resistors and leave JP1 open for resistor-ladder operation. See the project instructions for wiring and pull-up configuration.

## Panel illumination removed — October 6, 2026

The panel/button illumination LEDs have been dropped because there is insufficient clearance with the TFT display in the current mechanical layout. The PC Flights panel I am using also has no buttons that can be illuminated by the LEDs—all of the buttons are painted. The parts list no longer includes the 16 panel LEDs (D21–D36) or their 16 current-limiting resistors (R21–R36). The TFT display and its backlight remain, as does the separate power indicator LED.

This update changes the documentation and parts list only; existing schematic drawings may still show the former panel-lighting circuit.

## Main Controller power and protection parts

I am including the following power-input and protection components from the current Main Controller schematic. These entries are already included in [BOM.csv](BOM.csv); the quantities below are for one Main Controller board.

| Reference | Part / value | Quantity |
| --- | --- | ---: |
| J3 | DC barrel power-input jack, labelled 5.0–5.5 V input in the current schematic | 1 |
| F2 | Resettable PTC fuse, 1.1 A hold current | 1 |
| D1 | SB560 Schottky diode | 1 |
| C5 | 470 µF, 10 V electrolytic capacitor | 1 |
| C6 | 100 nF (0.1 µF) capacitor | 1 |
| D2 | Green power indicator LED, 5 mm footprint | 1 |
| R15 | 1 kΩ resistor | 1 |
| D3 | 1N4734A, 5.6 V Zener diode | 1 |
| R16 | 220 Ω resistor | 1 |
| R17 | 1 kΩ resistor | 1 |
| Q2 | C106D SCR | 1 |
| JP1 | 3-pin header, 2.54 mm pitch, for TFT power selection | 1 |
| JP1 accessory | 2-pin jumper shunt, 2.54 mm pitch | 1 |

Fit the JP1 shunt across **pins 1–2 for protected 5 V** or **pins 2–3 for Teensy 3.3 V**. Fit only one shunt and remove power before changing it. This Main Controller header jumper is separate from the rotary-switch PCB solder jumper also named JP1.

The TFT backlight control on the Main Controller also uses **Q3: IRLZ44N MOSFET**, **R37: 10 kΩ**, and **R38: 100 Ω**, one of each. These are also listed in the BOM.

I still need to finalize the Main Controller PCB. The exact barrel-jack size, PTC ordering code, resistor wattages and unfinished footprints need to be confirmed against that final design. This section records the current schematic parts. The external adapter is budgeted separately above; it is required for the future button-lighting option.

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

## Pin headers and mating connectors — October 12, 2026

Quantities below are for **one complete panel**, including all three rotary-switch PCBs. Use single-row **2.54 mm pitch** headers and matching female cable connectors. The removed six separate encoder headers and two 9-pin rotary-switch headers are obsolete.

| Location / use | Board-side male header | Quantity | Mating cable housings |
| --- | --- | ---: | --- |
| Master J4 and Encoder PCB J1 | 1x14 | 2 | Two 1x14 female |
| Master J2 and Button PCB | 1x08 | 2 | Two 1x08 female |
| Master J9/J10 and two multi-position switch PCBs | 1x03 | 4 | Four 1x03 female |
| Master SQL1 | 1x02 | 1 | One 1x02 female |
| SQL On/Off switch PCB J1 | 1x03 | 1 | One 1x03 female; use pins 2 and 3 only |
| Master J1, TFT connection | 1x08 | 1 | One 1x08 female at master; one 1x14 female at TFT module |
| Master JP1, power selector | 1x03 | 1 | One 2-pin jumper shunt |
| Teensy mounting | Two 1x24 male strips on Teensy | 2 | Two 1x24 female PCB socket strips on master |

Totals: **two 1x14, three 1x08, six 1x03 and one 1x02 male board headers**, plus two 1x24 Teensy male strips if not already fitted. Cable housings total **three 1x14, three 1x08, five 1x03 and one 1x02 female**, separate from the two 1x24 board sockets and JP1 shunt. Use at least **76 female crimp contacts**, plus spares, matched to the housing manufacturer's series. Wire lengths depend on the final panel layout. Preterminated female cables can replace housings and crimp contacts without counting both.

The TFT module normally already has its 14-pin male header. Check before purchasing an additional one. The button PCB's 8-pin header is provisional until its design is finished; Master J2 and J9/J10 still need footprint assignments. Check connector stack height and cable clearance before finalizing the Main and Button PCBs. Unused Teensy USB-host, Ethernet and auxiliary headers are not required by the current panel wiring.

**Cable mapping matters:** the encoder cable is pin-for-pin between the two 14-pin headers. The matrix cable uses rows on pins 1–4 and columns on pins 5–8. Multi-position switch cables use 1 = 3.3 V, 2 = signal and 3 = GND. The SQL On/Off cable maps master SQL1 pin 1 to switch-board J1 pin 2, and SQL1 pin 2 to switch-board J1 pin 3; switch-board pin 1 stays unused.

The TFT cable is **not straight-through**. With the current master schematic and MSP3520 module manual, connect:

| Master J1 pin | Signal | TFT module pin |
| --- | --- | --- |
| 1 | Selected VCC | 1 |
| 2 | GND | 2 |
| 3 | RESET / GPIO8 | 4 |
| 4 | CS / GPIO10 | 3 |
| 5 | SCK / GPIO13 | 7 |
| 6 | DC/RS / GPIO9 | 5 |
| 7 | MOSI / GPIO11 | 6 |
| 8 | Backlight control / GPIO4 | 8 |

TFT module pins 9–14 are unused in this connection. Use the module's printed signal labels to identify pins, and check cable continuity before power-up. The SQL On/Off rotary-switch ON/OFF solder bridge needs solder only, not another shunt.

## Current button switches

Use **16 switches per panel**, each **6 × 6 × 5 mm**, SPST momentary tactile, with four through-hole leads. The body still occupies 6 × 6 mm on the board.

The selected generic footprint is `Button_Switch_THT:SW_PUSH-6mm`. Confirm the purchased switches' lead spacing and contact pairing against it before fabrication.

## Hardware selection and supplier links

**Note:** This is intended to be a relatively simple design.

- **Microcontroller:** Teensy 4.1 without Ethernet  
  [SparkFun](https://www.sparkfun.com/teensy-4-1-without-ethernet.html)

- **Display:** ILI9488 SPI TFT, 3.5-inch  
  [Amazon](https://www.amazon.com/dp/B0BWJHK4M6)

- **Encoders:** Six Bourns **PEC11H-4220F-S0024**, matching the current encoder PCB. These have PCB terminals and an integrated push switch. The older seven-encoder quantity and 4215 shaft-option links are superseded.  
  [Mouser — 652-PEC11H4220FS0024](https://www.mouser.com/ProductDetail/Bourns/PEC11H-4220F-S0024?qs=7MVldsJ5UayW2mw8xYm74g%3D%3D)

- **Multi-position rotary switches:** Two C&K **A12505RNCQ**, with 1/2-inch (12.7 mm) shafts, 45-degree indexing and **C PCB-pin terminals**. These replace the solder-lug versions for the two resistor-ladder PCBs. The circuit uses seven positions of each eight-position switch; verify the corrected wiring and stop-ring setting against the panel.  
  [Mouser — 611-A12505RNCQ](https://www.mouser.com/en/ProductDetail/CK/A12505RNCQ?qs=h7H1bHRqGz9AS0MdXl06Aw%3D%3D) · [C&K datasheet](https://www.ckswitches.com/media/1349/arotary.pdf)

- **SQL On/Off switch:** One C&K **A12515RNZQ**, with a 1-1/2-inch (38.1 mm) shaft, 45-degree indexing and **Z solder-lug terminals**. Mount it in a bracket and wire its contacts to the Teensy input. It does not mount directly in the PCB-pin footprint and does not need a resistor ladder. The panel's ON and OFF markings are two clicks (90 degrees) apart; confirm the contact selection and travel stops against those markings.  
  [Mouser](https://www.mouser.com/ProductDetail/CK/A12515RNZQ) · [C&K datasheet](https://www.ckswitches.com/media/1349/arotary.pdf)

- **Faceplate:** A-10C "Thunderbolt" / "Warthog" VHF/UHF cockpit panel  
  [PC Flights](https://pcflights.com/a-10c-thunderbolt-warthog-vhf-uhf-panel/)<br>
  PC Flights has supplied me with a drawing file to assist with the Button PCB layout.

- **Button switches:** 16 per panel, 6 × 6 × 5 mm SPST momentary tactile push-button switches, four-pin through-hole  
  [Amazon](https://www.amazon.com/dp/B01CGMP9GY)

- **PCB standoffs:** Vibit 640-piece M3 nylon standoff assortment, including male–female and female–female spacers with screws. Select lengths to suit the final PCB spacing; the required lengths and quantity per panel are not yet finalized.  
  [Amazon](https://www.amazon.com/dp/B0H1QS5Q6N)

- **Diodes:** 16 × 1N4148 small-signal fast-switching diodes, DO-35  
  These are optional; jumper wires may be used in their place where appropriate.  
  [Amazon](https://www.amazon.com/100-Pieces-1N4148-Switching-High-Speed/dp/B079KJ91JZ/ref=sr_1_1_sspa?s=industrial&sr=1-1-spons&sp_csd=d2lkZ2V0TmFtZT1zcF9hdGY)


[Back to the project README](../README.md)

## Questions and community builds

**Building your own panel, or just looking around?** [Introduce yourself in the welcome discussion](https://github.com/dgdimick/ARC-210-DCS-Display/discussions/1) and tell us what you fly. Questions, ideas, and progress photos are all welcome—even if you’re only getting started.

Visit [GitHub Discussions](https://github.com/dgdimick/ARC-210-DCS-Display/discussions) to ask questions, share ideas, and post photos of your builds.
