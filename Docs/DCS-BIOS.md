[Back to the main project README](../README.md)

# DCS-BIOS connections and setup

I use DCS-BIOS to connect my radio panels to DCS. The ARC-210, ARC-164, and ARC-186 will each have a dedicated Teensy 4.1 and USB connection, so I can build, test, and troubleshoot each radio independently. The ARC-164 and ARC-186 hardware and firmware are still under development.

## DCS-Skunkworks DCS-BIOS

The project I use is [DCS-Skunkworks DCS-BIOS](https://github.com/DCS-Skunkworks/dcs-bios).

- [DCS-BIOS releases](https://github.com/DCS-Skunkworks/dcs-bios/releases)
- [Installation instructions](https://github.com/DCS-Skunkworks/dcs-bios#installation)
- [DCS-BIOS documentation](https://github.com/DCS-Skunkworks/dcs-bios/wiki)

Follow the project's installation instructions for your DCS Saved Games folder. Back up existing export files before changing them.

## My Export.lua

My `Export.lua` loads WWT, DCS-BIOS, and SRS. DCS-BIOS is already enabled by the `BIOS.lua` line below.

[Download my Export.lua](https://raw.githubusercontent.com/dgdimick/ARC-210-DCS-Display/master/Docs/DCS-BIOS/Export.lua) (right-click and save the link as `Export.lua`).

```lua
local wwtlfs=require('lfs')
dofile(wwtlfs.writedir()..'Scripts/wwt/wwtExport.lua')
dofile(lfs.writedir() .. [[Scripts\DCS-BIOS\BIOS.lua]])

pcall(function() local dcsSr=require('lfs');dofile(dcsSr.writedir()..[[Mods\Services\DCS-SRS\Scripts\DCS-SimpleRadioStandalone.lua]]); end,nil)
```

The file belongs in the active DCS Saved Games profile’s `Scripts` folder. Back up your existing `Export.lua` first. This is my setup: the WWT and DCS-BIOS paths must exist, and other builders should merge the DCS-BIOS line into their own file while retaining their other integrations. Do not add the DCS-BIOS loader twice.

**The ARC-210 getter changes below belong in `A-10C.lua`, not `Export.lua`.** This download preserves the loader configuration I supplied; it does not apply those module changes. Fully close and restart DCS after changing either file.

## TekConnect — the connection app I use

I use [TekConnect](https://github.com/tekcreations/TekConnect) to manage my DCS-BIOS USB serial connections. It shows connection status and offers automatic port connection.

[Download the Windows app from the TekConnect releases page](https://github.com/tekcreations/TekConnect/releases).

DCS-BIOS supplies the cockpit data and control interface; TekConnect manages the serial connection to the panel controllers. The panel still needs the correct firmware and aircraft mappings.

Close the connection to a panel before opening its COM port in a bench-testing app or Serial Monitor. Reconnect it after programming or bench testing. For my cables, hubs, and reasons for staying with USB, see [USB connections and powered hubs](USB-Connections-and-Powered-Hubs.md).

## ARC-210 changes to the DCS-BIOS export

The current ARC-210 firmware was tested with **two local changes to the A-10C export file**:

`Saved Games/DCS/Scripts/DCS-BIOS/lib/modules/aircraft_modules/A-10C.lua`

These changes read additional ARC-210 display data for the HQ/WOD and power-up screens. Back up the file before editing the two existing getters. **Keep their lengths, ordering, and addresses unchanged, and do not add duplicate definitions.**

For `ARC210_VERIFY_WOD_ACTIVE_CHANNEL` (two characters, address `0x1338`):

```lua
return Functions.coerce_nil_to_string(arc_210_data["WOD_segment"] or arc_210_data["HQII_segment"] or arc_210_data["active_oper_date"] or arc_210_data["active_channel"])
```

For `ARC210_SELECTED_RT` (three characters, address `0x1320`):

```lua
return Functions.coerce_nil_to_string(arc_210_data["txt_RT"] or (arc_210_data["POWER UP LOADER"] and "PWR"))
```

**Fully close and restart DCS after editing the export.** Reloading a mission or flashing the Teensy does not reload it. DCS-BIOS updates may overwrite these local changes. The getters only read the game's display data.

See the [current ARC-210 firmware notes](../Firmware/Master%20Hex%20Files/README.md) for the HEX download and firmware limitations. The current published firmware is a display/menu preview; complete physical-control integration and final in-DCS validation remain pending. The [bench-testing guide](Bench-Testing-App.md) covers testing with simulated data without launching DCS.

## Aircraft mappings

Each panel needs the DCS-BIOS inputs and outputs for the intended aircraft and radio instance. Support for another aircraft requires separate mappings, firmware integration, and testing. A shared USB connection method does not establish aircraft compatibility.
