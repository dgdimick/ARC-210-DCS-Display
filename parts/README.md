# Parts

Updated October 12, 2026.

[View the component list (BOM.csv)](BOM.csv)

The BOM lists schematic references, values, footprints, quantities, and do-not-populate flags for the ARC-210 master board. Its non-connector entries originate from a September 25 snapshot of the [KiCad project](https://github.com/dgdimick/Teensy/tree/main/KiCad/ARC-210_Master_Board), with subsequent parts-selection updates. Connector entries were reconciled against the October 12 master schematic and final control-board projects. It is not yet a finalized purchasing list. Blank footprints and generic diode values still need confirmation. Panel hardware and supplier links are listed below because the schematic BOM does not describe every mechanical part.

## Six-PCB layout

My build uses six PCBs controlled by one Teensy 4.1: the master PCB, button PCB, rotary encoder PCB, and three small rotary switch PCBs. The separate control boards provide cleaner wiring and wire support.

The three rotary switch PCBs use the same design and are interchangeable. I fit six resistors on each of the two multi-position switch boards. For the SQL On/Off switch board, I omit all resistors and bridge the JP1 solder pad; its solder-lug switch connects to the board with wires.

## BOM coverage

[BOM.csv](BOM.csv) originated from the ARC-210 master-board schematic and includes subsequent panel-hardware selections. Panel-hardware entries are explicitly labelled so their references are not confused with master-board references. This is not yet a finalized set of board-specific purchasing lists; do not multiply quantities by the number of PCBs.

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

I still need to finalize the Main Controller PCB. The exact barrel-jack size, PTC ordering code, resistor wattages and unfinished footprints need to be confirmed against that final design. This section records the current schematic parts; it does not add an external power supply to the purchasing list.

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

Use **16 switches per panel**, each **6 × 6 × 6 mm**, SPST momentary tactile, with four through-hole leads. The body still occupies 6 × 6 mm on the board.

The selected generic footprint is `Button_Switch_THT:SW_PUSH-6mm`. Confirm the purchased switches' lead spacing and contact pairing against it before fabrication.

## Hardware selection and supplier links

**Note:** This is intended to be a relatively simple design.

- **Microcontroller:** Teensy 4.1 without Ethernet  
  [SparkFun](https://www.sparkfun.com/teensy-4-1-without-ethernet.html)

- **Display:** ILI9488 SPI TFT, 3.5-inch  
  [Amazon](https://www.amazon.com/dp/B0CKRJ81B5?ref_=ppx_hzsearch_conn_dt_b_fed_asin_title_2)

- **Encoders:** Six Bourns **PEC11H-4220F-S0024**, matching the current encoder PCB. These have PCB terminals and an integrated push switch. The older seven-encoder quantity and 4215 shaft-option links are superseded.  
  [Mouser — 652-PEC11H4220FS0024](https://www.mouser.com/en/ProductDetail/Bourns/PEC11H-4220F-S0024?qs=7MVldsJ5UayW2mw8xYm74g%3D%3D)

- **Multi-position rotary switches:** Two C&K **A12505RNCQ**, with 1/2-inch (12.7 mm) shafts, 45-degree indexing and **C PCB-pin terminals**. These replace the solder-lug versions for the two resistor-ladder PCBs. The circuit uses seven positions of each eight-position switch; verify the corrected wiring and stop-ring setting against the panel.  
  [Mouser — 611-A12505RNCQ](https://www.mouser.com/en/ProductDetail/CK/A12505RNCQ?qs=h7H1bHRqGz9AS0MdXl06Aw%3D%3D) · [C&K datasheet](https://www.ckswitches.com/media/1349/arotary.pdf)

- **SQL On/Off switch:** One C&K **A12515RNZQ**, with a 1-1/2-inch (38.1 mm) shaft, 45-degree indexing and **Z solder-lug terminals**. Mount it in a bracket and wire its contacts to the Teensy input. It does not mount directly in the PCB-pin footprint and does not need a resistor ladder. The panel's ON and OFF markings are two clicks (90 degrees) apart; confirm the contact selection and travel stops against those markings.  
  [Mouser](https://www.mouser.com/ProductDetail/CK/A12515RNZQ) · [C&K datasheet](https://www.ckswitches.com/media/1349/arotary.pdf)

- **Faceplate:** A-10C "Thunderbolt" / "Warthog" VHF/UHF cockpit panel  
  [PC Flights](https://pcflights.com/a-10c-thunderbolt-warthog-vhf-uhf-panel/)<br>
  PC Flights has supplied me with a drawing file to assist with the Button PCB layout.

- **Button switches:** 16 per panel, 6 × 6 × 6 mm SPST momentary tactile push-button switches, four-pin through-hole  
  [Amazon](https://www.amazon.com/dp/B0HGBSFY2L)

- **PCB standoffs:** Vibit 640-piece M3 nylon standoff assortment, including male–female and female–female spacers with screws. Select lengths to suit the final PCB spacing; the required lengths and quantity per panel are not yet finalized.  
  [Amazon](https://www.amazon.com/dp/B0H1QS5Q6N)

- **Diodes:** 16 × 1N4148 small-signal fast-switching diodes, DO-35  
  These are optional; jumper wires may be used in their place where appropriate.  
  [Amazon](https://www.amazon.com/100-Pieces-1N4148-Switching-High-Speed/dp/B079KJ91JZ/ref=sr_1_1_sspa?s=industrial&sr=1-1-spons&sp_csd=d2lkZ2V0TmFtZT1zcF9hdGY)


[Back to the project README](../README.md)

## Questions and community builds

Visit [GitHub Discussions](https://github.com/dgdimick/ARC-210-DCS-Display/discussions) to ask questions, share ideas, and post photos of your builds.
