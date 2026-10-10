# Parts

Updated October 10, 2026.

[View the component list (BOM.csv)](BOM.csv)

The BOM lists schematic references, values, footprints, quantities, and do-not-populate flags for the ARC-210 master board. It is based on a September 25 snapshot of the [KiCad project](https://github.com/dgdimick/Teensy/tree/main/KiCad/ARC-210_Master_Board), with subsequent parts-selection updates, not a finalized purchasing list. Blank footprints and generic diode values still need confirmation. Panel hardware and supplier links are listed below because the schematic BOM does not describe every mechanical part.

## Five-PCB layout

The build uses five PCBs controlled by one Teensy 4.1: the master PCB, button PCB, rotary encoder PCB, and two small rotary switch PCBs. The separate control boards provide cleaner wiring and wire support.

## BOM coverage

[BOM.csv](BOM.csv) originated from the ARC-210 master-board schematic and includes subsequent panel-hardware selections. Panel-hardware entries are explicitly labelled so their references are not confused with master-board references. This is not yet a finalized set of board-specific purchasing lists; do not multiply quantities by the number of PCBs.

The corrected [Rotary Switch KiCad project, version 1.2](../PCBs/Rotary%20Switches/), replaces the withdrawn initial version. Version 1.2 retains the corrected pin assignments and adds an ON/OFF solder jumper. Omit R1–R6 and bridge JP1 for On/Off operation; fit the resistors and leave JP1 open for resistor-ladder operation. See the project instructions for wiring and pull-up configuration.

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

The TFT backlight control on the Main Controller also uses **Q3: IRLZ44N MOSFET**, **R37: 10 kΩ**, and **R38: 100 Ω**, one of each. These are also listed in the BOM.

I still need to finalize the Main Controller PCB. The exact barrel-jack size, PTC ordering code, resistor wattages and unfinished footprints need to be confirmed against that final design. This section records the current schematic parts; it does not add an external power supply to the purchasing list.

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
  [PC Flights](https://pcflights.com/a-10c-thunderbolt-warthog-vhf-uhf-panel/)

- **Button switches:** 16 per panel, 6 × 6 × 6 mm SPST momentary tactile push-button switches, four-pin through-hole  
  [Amazon](https://www.amazon.com/dp/B0HGBSFY2L)

- **PCB standoffs:** Vibit 640-piece M3 nylon standoff assortment, including male–female and female–female spacers with screws. Select lengths to suit the final PCB spacing; the required lengths and quantity per panel are not yet finalized.  
  [Amazon](https://www.amazon.com/dp/B0H1QS5Q6N)

- **Diodes:** 16 × 1N4148 small-signal fast-switching diodes, DO-35  
  These are optional; jumper wires may be used in their place where appropriate.  
  [Amazon](https://www.amazon.com/100-Pieces-1N4148-Switching-High-Speed/dp/B079KJ91JZ/ref=sr_1_1_sspa?s=industrial&sr=1-1-spons&sp_csd=d2lkZ2V0TmFtZT1zcF9hdGY)


[Back to the project README](../README.md)
