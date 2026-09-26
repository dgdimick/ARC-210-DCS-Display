# Parts

Updated September 25, 2026.

[View the component list (BOM.csv)](BOM.csv)

The BOM lists schematic references, values, footprints, quantities, and do-not-populate flags for the ARC-210 master board. It is a September 25 snapshot of the [KiCad project](https://github.com/dgdimick/Teensy/tree/main/KiCad/ARC-210_Master_Board), not a finalized purchasing list. Blank footprints and generic diode values still need confirmation. Panel hardware and supplier links are listed below because the schematic BOM does not describe every mechanical part.

## Two-PCB layout

The build uses two PCBs controlled by one Teensy 4.1:

- **Master PCB:** carries the Teensy, power circuitry, and display and control connections.
- **Front-panel PCB:** carries the push-button switches and panel LEDs behind the faceplate and connects to the master PCB.

The front-panel PCB does not require a second microcontroller. The board layouts and connections are still being developed.

## BOM coverage

[BOM.csv](BOM.csv) is exported from the current **ARC-210_Master_Board schematic**. That schematic includes button and panel-LED circuits, so the CSV is not yet separated by physical PCB. It is not a pair of finalized board-specific purchasing lists. Use each component reference once; do not double the quantities because the build uses two boards. Final allocation between the master and front-panel PCBs will be documented as the layouts are completed.

## Current button-switch candidate

The current candidate is a [12 × 12 × 12 mm tactile switch](https://www.amazon.com/dp/B07HCCMHSL). Its terminal spacing and contact pairing still need verification before assigning a footprint. With 15 mm button centers, 12 mm bodies leave a nominal 3 mm gap; panel height, caps, pins, and pads also need clearance. The 6 × 6 × 5 mm switch below is the earlier candidate, retained for reference.

## Hardware selection and supplier links

**Note:** This is intended to be a relatively simple design.

- **Microcontroller:** Teensy 4.1 without Ethernet  
  [SparkFun](https://www.sparkfun.com/teensy-4-1-without-ethernet.html)

- **Display:** ILI9488 SPI TFT, 3.5-inch  
  [Amazon](https://www.amazon.com/dp/B0CKRJ81B5?ref_=ppx_hzsearch_conn_dt_b_fed_asin_title_2)

- **Encoders:** Rotary encoders (x7)  
  [Mouser Electronics - PEC11H](https://www.mouser.com/ProductDetail/652-PEC11H4215FS0024) — stronger rotation torque  
  [Mouser Electronics - PEC11R](https://www.mouser.com/ProductDetail/Bourns/PEC11R-4215F-S0024?qs=Zq5ylnUbLm5lAqmKF80wzQ%3D%3D) — lighter rotation torque

- **Rotary switches:** 8-position rotary switches, 45-degree indexing with stop, SP8T  
  [Mouser Electronics](https://www.mouser.com/ProductDetail/611-A12503RNCQE)

- **SQL On/Off switch:** This part is a little clunky, but I selected it to help keep the project cost down.  
  [Home Depot](https://www.homedepot.com/p/Gardner-Bender-6-Amp-Single-Pole-Rotary-Switch-Brass-GSW-61/100095964)

- **Faceplate:** A-10C "Thunderbolt" / "Warthog" VHF/UHF cockpit panel  
  [PC Flights](https://pcflights.com/a-10c-thunderbolt-warthog-vhf-uhf-panel/)

- **Button switches:** 16 × 6 × 6 × 5 mm miniature momentary tactile push-button switches (SPST)  
 > **Note:** These switches may change as I continue developing the PCB. I was not satisfied with the first version.  
  [Amazon](https://www.amazon.com/dp/B01CGMP9GY?ref_=ppx_hzsearch_conn_dt_b_fed_asin_title_1)

- **Diodes:** 16 × 1N4148 small-signal fast-switching diodes, DO-35  
  These are optional; jumper wires may be used in their place where appropriate.  
  [Amazon](https://www.amazon.com/100-Pieces-1N4148-Switching-High-Speed/dp/B079KJ91JZ/ref=sr_1_1_sspa?s=industrial&sr=1-1-spons&sp_csd=d2lkZ2V0TmFtZT1zcF9hdGY)


[Back to the project README](../README.md)
