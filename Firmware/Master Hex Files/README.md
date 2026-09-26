# ARC-210 menu-system preview

README last updated: **September 25, 2026**.

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

Open this HEX in Teensy Loader, enable Auto, and press the Teensy's programming button. Reconnect your DCS-BIOS serial bridge after flashing if needed. The display starts blank until it receives powered-radio data; a blank screen without powered-radio updates from DCS-BIOS or dcsBiosDebug is expected. The Loader's “1% used” is memory usage, not upload progress.

## Test the menu system without running DCS

Use [dcsBiosDebug](https://github.com/dgdimick/dcsBiosDebug) to send simulated DCS-BIOS updates to the Teensy over USB serial. This lets you exercise the firmware's menu screens and navigation without launching DCS or loading a mission. See its [README and download links](https://github.com/dgdimick/dcsBiosDebug#downloads) for installation.

1. Load `Master_Program.ino.hex` onto the Teensy and connect the display hardware.
2. Close the DCS-BIOS serial bridge and any Serial Monitor using the Teensy's COM port.
3. In dcsBiosDebug, click **Find Serial Ports**, select the Teensy's COM port, and click **Connect**.
4. Load the matching A-10C aircraft JSON definition from your DCS-BIOS `doc/json` directory. Its output addresses and masks must match this firmware.
5. Add the ARC-210 power/master-switch and display-state outputs to **Active Indicators**. Send powered-radio values, including valid frequency/display data, and allow startup to finish. Connecting alone does not turn on the simulated radio; the screen can remain blank until the required data arrives.
6. Add the ARC-210 MENU, upper/middle/lower line-select key, and XMT/RCV button outputs. Simulate each press as **0 -> 1 -> 0**, allowing each state to be transmitted before changing it again. The firmware acts on the transition to 1, so release the button before testing another press.
7. Use these simulated updates to check the menu sequence, labels, layout, and navigation described above. Text outputs can be edited and sent with the **>** button; integer outputs can be changed with their sliders.

This is a bench test of the firmware's response to supplied data. dcsBiosDebug does not simulate DCS's radio logic or automatically provide the game's responses to hardware commands. Features such as WOD synchronization and game-dependent settings still need an in-DCS test. Disconnect dcsBiosDebug before reconnecting the normal DCS-BIOS serial bridge.

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

Firmware build: **September 23, 2026**, originally published September 24, 2026. The September 25 README update adds offline testing instructions; the HEX file has not changed or been recompiled.

SHA-256:

```text
607418aa3843d871f3b5ff98abc2ede7575086a80b34e2273da59c333469278c
```
