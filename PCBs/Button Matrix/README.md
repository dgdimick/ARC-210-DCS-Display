# ARC-210 Button Matrix PCB

PCB version **3.1 — Final design; physical test fit confirmed**. KiCad 10 project.

Updated October 27, 2026. The current PCB, schematic, project settings, and project-local footprint library are included in this folder.

This is the current **unlit 16-button, 4 × 4 matrix**. It is separate from the proposed future Button LED PCB, which is not currently planned.

## Download and open

Use **Code → Download ZIP** on the repository, extract it, and keep this folder together. Open `Button Matrix.kicad_pro` in KiCad 10, then open the schematic or PCB Editor. The [schematic](Button%20Matrix.kicad_sch) and [PCB layout](Button%20Matrix.kicad_pcb) are also available directly.

The design uses standard KiCad `Connector`, `Device`, `Switch`, and `Mechanical` symbols. Install KiCad’s standard libraries and keep `fp-lib-table` and `ButtonMatrix.pretty/` beside the project. The local library supplies H3’s 12 mm non-plated SQL On/Off switch pass-through footprint.

**PCB version 3.1:** The saved PCB includes placement and routing. Unused floating copper fills were removed on October 27, 2026. The slightly long board edges were shortened, and the printed fit check confirmed correct button positions. Testing an assembled manufactured board remains pending. A [Gerber and drill ZIP](Manufacturing/Button-Matrix-PCB-v3.1-Gerbers-Drill.zip) is included for manufacturing.

## Gerber and drill files

Download [Button-Matrix-PCB-v3.1-Gerbers-Drill.zip](Manufacturing/Button-Matrix-PCB-v3.1-Gerbers-Drill.zip) for a PCB manufacturer. Generated October 27, 2026 from the corrected version 3.1 PCB using KiCad 10.0.7.

The ZIP contains the seven Gerber X2 layers (front/back copper, solder mask, silkscreen, and board outline), a Gerber job file, separate metric Excellon PTH/NPTH drill files, and manufacturing notes. Both Gerbers and drills use the absolute origin without mirroring. The source specifies a two-layer, 1.6 mm board.

The exports were checked against the source: **130 plated holes and five non-plated holes**, including four 3.5 mm mounting holes and H3’s 12 mm SQL On/Off pass-through. [Individual files, drill maps, and drill report](Manufacturing/) are also available. Check the manufacturer's preview for the board outline, central opening, and drill placement before ordering. The printed fit check confirmed button alignment; manufactured-board assembly and electrical testing remain pending.

**Final v3.1 design; test fit confirmed — October 27, 2026:** The revised v3.1 board has been physically test-fitted and confirmed to fit. The buttons are in the correct locations. The board edges were slightly too long and have been shortened for version **3.1**, which is the final design. Use v3.1 for new orders. The obsolete v3.0 manufacturing ZIP has been removed; Git history retains earlier revisions.

## SQL On/Off switch shaft support

The [shaft spacer v.5](../../Supporting%20STL%27s/Shaft_Spacer_v.5.stl) is **required in all installations** to support the **longer SQL On/Off switch shaft**. Fit it whether using the optional SQL On/Off PCB or wiring directly to the switch’s solder lugs. H3’s 12 mm opening in the Button Matrix PCB provides pass-through clearance for the SQL On/Off switch.

## Layout reference pictures

These front and back pictures show the earlier **v3.0** layout. The final v3.1 files have slightly shortened board edges; use the current KiCad layout and manufacturing files for exact dimensions. The large opening is the SQL On/Off switch pass-through.

### Front — push-button switches

![Button Matrix PCB front view showing the 16 push-button switches](../../images/Button-Matrix-PCB-3D.png)

### Back — diodes and connectors

![Button Matrix PCB back view showing the diodes, row and column connectors, and routing](../../images/Button-Matrix-PCB-Back-3D.png)

## Buttons and connectors

Use 16 SPST momentary tactile switches, **6 × 6 × 5 mm**, with four through-hole leads. See the [parts list and supplier](../../parts/README.md#current-button-switches). Confirm the purchased switches’ contact pairing and footprint before fabrication. Verify the supplied footprint against your purchased switches before fabrication.

The schematic has **two separate four-pin connectors**, rather than one eight-pin connector:

| Button Matrix connector | Master Board J2 pin | Teensy GPIO label | KiCad Teensy U1 pad |
| --- | ---: | ---: | ---: |
| J1 pin 1 — row 1 | 1 | 30 | 22 |
| J1 pin 2 — row 2 | 2 | 31 | 23 |
| J1 pin 3 — row 3 | 3 | 32 | 24 |
| J1 pin 4 — row 4 | 4 | 33 | 25 |
| J2 pin 1 — column 1 | 5 | 35 | 27 |
| J2 pin 2 — column 2 | 6 | 36 | 28 |
| J2 pin 3 — column 3 | 7 | 37 | 29 |
| J2 pin 4 — column 4 | 8 | 40 | 32 |

The connector reference J2 on this button schematic is different from J2 on the Master Board. Use the table to wire between them. The supplied PCB uses these two four-pin connectors.

**Teensy printed GPIO labels differ from KiCad pad numbers.** For example, GPIO 30 is U1 pad 22. Use the Teensy labels for firmware and wiring, and the matching symbol/footprint pad numbers when working in KiCad.

## Diodes and testing

D5–D20 are the 16 matrix diodes. Their cathodes connect to the row lines. Confirm the intended 1N4148 parts, polarity, and supplied footprints before fabrication. See the [parts documentation](../../parts/README.md).

The [combined hardware test](../../Firmware/Test%20Code/ARC210_Button_Test/) documents the working matrix GPIO assignments and button tests. A successful breadboard test does not establish that the final PCB design has been assembled or tested.

KiCad 10.0.7 checks run October 27, 2026 reported **zero ERC violations, zero DRC errors, zero unconnected items, and zero schematic/PCB parity issues** under the saved settings. After removal of the unused no-net copper fills, DRC reports **zero warnings**. The board has no ground net and does not require a ground plane. See the [ERC summary](ERC-report.txt) and [DRC report](DRC-report.json). Some check categories are disabled. Button alignment was verified with the printed fit check; electrical operation of an assembled manufactured board has not yet been tested.

## Lighting

The PC Flights panel buttons used for this build are painted and opaque, so light will not pass through them to illuminate their legends. This design has no button-lighting LEDs.

A future lighting option would need suitable light-transmitting replacement buttons, a new Button LED PCB, and a revised Master PCB. It would require a separately designed power supply and driver circuit; the current USB/3.3 V Main Board no longer includes the former protected 5 V input. The ARC-164 and ARC-186 projects will be completed before that option is revisited.

## Build cost and community

See the [DIY parts purchasing estimate](../../parts/README.md#estimated-build-cost) for a build budget. Parts and fabrication are sourced independently; this is primarily a DIY project.

Need a hand? Ask in [Discussions](https://github.com/dgdimick/ARC-210-DCS-Display/discussions), share your build photos, or [introduce yourself](https://github.com/dgdimick/ARC-210-DCS-Display/discussions/1).

PCB design license: CERN-OHL-P-2.0, as specified in the [main README](../../README.md#licensing).
