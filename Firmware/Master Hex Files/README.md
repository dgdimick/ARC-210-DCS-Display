# ARC-210 menu-system preview — September 24, 2026

`Master_Program.ino.hex` is the current Teensy 4.1 / ILI9488 480 × 320 display firmware, published for menu-screen and navigation testing. It is not a complete implementation of every radio function.

## What to test

- HQ MORE sequence: OPER. DATE LOAD -> VERIFY WOD/MWOD -> WOD LOAD -> WOD ERASE -> HQ II FMT -> OPER. DATE LOAD -> VERIFY WOD/MWOD, repeating from there.
- HQ detail screens, including WOD and HQII number positioning.
- MENU opens the opening menu from the frequency screen and closes it from that opening menu only. On all deeper pages it is inactive.
- LOAD WOD number synchronization with DCS, including MLSK increments. In the tested session both displays reset to 20 on re-entry; this is supplied by DCS, not hard-coded.
- LOAD HQII FMT exits to frequency when a frequency knob or Channel knob moves.
- Existing COMSEC and RADIO SETTINGS screen navigation.

## Known limitations

Some detail-page actions remain unimplemented, including the WOD erase YES outcome. COMSEC BASEBAND/DIPHASE selection synchronization needs further work because the game label depends on underlying settings. Early aircraft-power startup screens may lag DCS; frequency-screen timing and power behavior have been tested. Report the exact page, button/knob, and both DCS and physical-screen behavior when reporting an issue.

## Loading and first startup

Open this HEX in Teensy Loader, enable Auto, and press the Teensy's programming button. Reconnect your DCS-BIOS serial bridge after flashing if needed. The display starts blank until it receives powered-radio data; a blank screen without DCS-BIOS running is expected. The Loader's “1% used” is memory usage, not upload progress.

## DCS-BIOS export requirements

This build was tested with local changes to the A-10C DCS-BIOS export. Stock exports do not provide all the values used by these HQ screens. Back up your installed `Saved Games/DCS/Scripts/DCS-BIOS/lib/modules/aircraft_modules/A-10C.lua` before adapting the two existing getters below. Keep their existing lengths, ordering, and addresses; do not add duplicate definitions.

For `ARC210_VERIFY_WOD_ACTIVE_CHANNEL` (two characters, address `0x1338`), use:

```lua
return Functions.coerce_nil_to_string(arc_210_data["WOD_segment"] or arc_210_data["HQII_segment"] or arc_210_data["active_oper_date"] or arc_210_data["active_channel"])
```

For `ARC210_SELECTED_RT` (three characters, address `0x1320`), use:

```lua
return Functions.coerce_nil_to_string(arc_210_data["txt_RT"] or (arc_210_data["POWER UP LOADER"] and "PWR"))
```

Fully close and restart DCS after these changes. Reloading a mission or flashing the Teensy does not reload the Lua export. DCS-BIOS updates may overwrite these customizations. These getters only read the game's display data.

## File verification

This is the tested September 23 build published on September 24; it was copied without recompiling.

SHA-256:

```text
607418aa3843d871f3b5ff98abc2ede7575086a80b34e2273da59c333469278c
```
