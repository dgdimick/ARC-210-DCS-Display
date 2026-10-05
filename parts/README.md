# Parts

Updated October 5, 2026.

[View the component list (BOM.csv)](BOM.csv)

The BOM lists schematic references, values, footprints, quantities, and do-not-populate flags for the ARC-210 master board. It is based on a September 25 snapshot of the [KiCad project](https://github.com/dgdimick/Teensy/tree/main/KiCad/ARC-210_Master_Board), with subsequent parts-selection updates, not a finalized purchasing list. Blank footprints and generic diode values still need confirmation. Panel hardware and supplier links are listed below because the schematic BOM does not describe every mechanical part.

## Two-PCB layout

The build uses two PCBs controlled by one Teensy 4.1:

- **Master PCB:** carries the Teensy, power circuitry, and display and control connections.
- **Front-panel PCB:** carries the push-button switches and panel LEDs behind the faceplate and connects to the master PCB.

The front-panel PCB does not require a second microcontroller. The board layouts and connections are still being developed.

## BOM coverage

[BOM.csv](BOM.csv) originated from the **ARC-210_Master_Board schematic** export and now includes the selected 6 × 6 × 6 mm push buttons and the SQL rotary-switch hardware. That schematic includes button and panel-LED circuits, so the CSV is not yet separated by physical PCB. It is not a pair of finalized board-specific purchasing lists. Use each component reference once; do not double the quantities because the build uses two boards. Final allocation between the master and front-panel PCBs will be documented as the layouts are completed.

## Current button switches

Use **16 switches per panel**, each **6 × 6 × 6 mm**, SPST momentary tactile, with four through-hole leads. The body still occupies 6 × 6 mm on the board.

The selected generic footprint is `Button_Switch_THT:SW_PUSH-6mm`. Confirm the purchased switches' lead spacing and contact pairing against it before fabrication.

## Hardware selection and supplier links

**Note:** This is intended to be a relatively simple design.

- **Microcontroller:** Teensy 4.1 without Ethernet  
  [SparkFun](https://www.sparkfun.com/teensy-4-1-without-ethernet.html)

- **Display:** ILI9488 SPI TFT, 3.5-inch  
  [Amazon](https://www.amazon.com/dp/B0CKRJ81B5?ref_=ppx_hzsearch_conn_dt_b_fed_asin_title_2)

- **Encoders:** Rotary encoders (x7)  
  [Mouser Electronics - PEC11H](https://www.mouser.com/ProductDetail/652-PEC11H4215FS0024) — stronger rotation torque  
  [Mouser Electronics - PEC11R](https://www.mouser.com/ProductDetail/Bourns/PEC11R-4215F-S0024?qs=Zq5ylnUbLm5lAqmKF80wzQ%3D%3D) — lighter rotation torque

- **Rotary switches:** C&K A12515RNZQ, 8-position, 45-degree indexing, SP8T, solder-lug terminals  
  [Mouser Electronics](https://www.mouser.com/ProductDetail/CK/A12515RNZQ)

- **SQL On/Off switch:** One additional C&K A12515RNZQ rotary switch, the same model used for the other rotary controls. The ON and OFF markings are two clicks (90 degrees) apart. This switch signals the Teensy.  
  [Mouser Electronics](https://www.mouser.com/ProductDetail/CK/A12515RNZQ)

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
