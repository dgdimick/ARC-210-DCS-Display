[Back to the main project README](../README.md)

# DCS-BIOS setup — step by step

I use DCS-BIOS to send radio information between DCS and my panels, and TekConnect to manage their USB connections. This guide explains the PC files and the two changes needed by my current ARC-210 firmware.

**Current status:** The published ARC-210 firmware is a display/menu preview. Complete physical-control integration and final in-DCS validation are still pending. The ARC-164 and ARC-186 are planned builds; these ARC-210 edits do not add firmware support for those radios.

## What each file does

| File or app | What it does | What you need to do |
| --- | --- | --- |
| DCS-BIOS folder | Gets cockpit data from DCS and accepts control commands | Install it in your active DCS Saved Games profile |
| `Scripts/Export.lua` | Tells DCS to start DCS-BIOS and your other export tools | Add one DCS-BIOS loader line, keeping your existing integrations |
| `DCS-BIOS/lib/modules/aircraft_modules/A-10C.lua` | Defines the A-10 radio data exported by DCS-BIOS | Replace two existing `return` lines for this ARC-210 firmware |
| `Master_Program.ino.hex` | Runs the ARC-210 display/menu firmware on the Teensy | Load it with Teensy Loader |
| TekConnect | Connects DCS-BIOS to the panel's USB COM port | Select and connect the panel's port |

**You do not need to edit `BIOS.lua`, change DCS installation files, or put the ARC-210 changes into `Export.lua`.**

## 1. Close DCS and find the right folder

Fully close DCS before editing these files.

Open your Windows **Saved Games** folder and find the profile used by your DCS installation. Common locations are:

```text
C:\Users\YOURNAME\Saved Games\DCS\Scripts
C:\Users\YOURNAME\Saved Games\DCS.openbeta\Scripts
```

Use the profile your installation actually uses; the folder name may differ. This is not the DCS program folder under Steam or Program Files. Create the `Scripts` folder if it does not exist.

In File Explorer, turn on **View → Show → File name extensions** so you can distinguish `Export.lua` from `Export.lua.txt`. Open Lua files in a plain-text editor such as Notepad or Notepad++.

Before changing an existing file, copy it somewhere safe outside the DCS-BIOS folder. Back up both `Export.lua` and, if already installed, `A-10C.lua`.

## 2. Install DCS-Skunkworks DCS-BIOS

I use [DCS-Skunkworks DCS-BIOS](https://github.com/DCS-Skunkworks/dcs-bios).

1. Open the [DCS-BIOS releases page](https://github.com/DCS-Skunkworks/dcs-bios/releases).
2. Download the `DCS-BIOS_x.y.z.zip` release package and extract it.
3. Copy its `DCS-BIOS` folder into your active profile's `Scripts` folder.
4. Check that this file exists:

```text
Saved Games\DCS\Scripts\DCS-BIOS\BIOS.lua
```

Avoid an extra nested folder such as `DCS-BIOS\DCS-BIOS\BIOS.lua`. For the current upstream procedure, see the [official installation instructions](https://github.com/DCS-Skunkworks/dcs-bios#installation) and [documentation](https://github.com/DCS-Skunkworks/dcs-bios/wiki).

## 3. Tell DCS to load DCS-BIOS

Open `Scripts\Export.lua` in your active Saved Games profile. If it does not exist, create it as a plain-text file named **Export.lua**.

Look for a line loading `DCS-BIOS\BIOS.lua`. If it is already there, leave it in place. Otherwise, add this line at the end:

```lua
dofile(lfs.writedir() .. [[Scripts\DCS-BIOS\BIOS.lua]])
```

**Add the loader only once. Keep the existing lines for your other tools.** Save the file and check that its name is not `Export.lua.txt`.

### My Export.lua example

My file also starts WWT and SRS. This is an example of several integrations sharing one file:

```lua
local wwtlfs=require('lfs')
dofile(wwtlfs.writedir()..'Scripts/wwt/wwtExport.lua')
dofile(lfs.writedir() .. [[Scripts\DCS-BIOS\BIOS.lua]])

pcall(function() local dcsSr=require('lfs');dofile(dcsSr.writedir()..[[Mods\Services\DCS-SRS\Scripts\DCS-SimpleRadioStandalone.lua]]); end,nil)
```

[Download my Export.lua](https://raw.githubusercontent.com/dgdimick/ARC-210-DCS-Display/master/Docs/DCS-BIOS/Export.lua) by right-clicking the link and saving it as `Export.lua`.

You only need the DCS-BIOS loader line for this project. Do not replace your existing file with my example unless it matches your installed tools: my WWT line needs `Scripts/wwt/wwtExport.lua` to exist. The download does not apply the two radio changes in the next step.

<a id="arc-210-changes-to-the-dcs-bios-export"></a>

## 4. Change two lines in A-10C.lua

Open this file inside the DCS-BIOS folder you installed:

```text
Scripts\DCS-BIOS\lib\modules\aircraft_modules\A-10C.lua
```

These edits let my firmware read additional HQ/WOD and power-up display information. **Change only the two existing `return` lines shown below. Do not paste in extra copies of the definitions, move them, or change their string lengths.** Their position and lengths affect the output addresses used by the firmware.

If your file already contains the replacement line, no further change is needed. If the named definition or expected code is missing, check your DCS-BIOS version before proceeding rather than adding a new definition.

### A. WOD/HQ display value

Press **Ctrl+F**, search for `ARC210_VERIFY_WOD_ACTIVE_CHANNEL`, and find this block:

```lua
A_10C:defineString("ARC210_VERIFY_WOD_ACTIVE_CHANNEL", function()
    return Functions.coerce_nil_to_string(arc_210_data["active_channel"])
end, 2, "ARC-210 Display", "Active Channel (WOD Page)")
```

Replace only its `return` line with:

```lua
return Functions.coerce_nil_to_string(arc_210_data["WOD_segment"] or arc_210_data["HQII_segment"] or arc_210_data["active_oper_date"] or arc_210_data["active_channel"])
```

Leave the opening definition and closing `end, 2, ...` line unchanged. This is the two-character output used at address `0x1338` in my tested setup.

### B. Power-up display value

Search for `ARC210_SELECTED_RT` and find this block:

```lua
A_10C:defineString("ARC210_SELECTED_RT", function()
    return Functions.coerce_nil_to_string(arc_210_data["txt_RT"])
end, 3, "ARC-210 Display", "Selected RT")
```

Replace only its `return` line with:

```lua
return Functions.coerce_nil_to_string(arc_210_data["txt_RT"] or (arc_210_data["POWER UP LOADER"] and "PWR"))
```

Leave the opening definition and closing `end, 3, ...` line unchanged. This is the three-character output used at address `0x1320` in my tested setup.

Save `A-10C.lua`. Both changes only read the game's display data. If your DCS-BIOS version assigns different output addresses, the firmware must be checked against that version; changing these return values does not relocate the outputs.

## 5. Load the ARC-210 firmware

1. Download [Master_Program.ino.hex](../Firmware/Master%20Hex%20Files/Master_Program.ino.hex).
2. Follow the [Teensy Loader instructions](Loading-HEX-Files.md) to put it on the Teensy 4.1.
3. Read the [firmware notes](../Firmware/Master%20Hex%20Files/README.md) for the current features and limitations.

The HEX goes onto the Teensy; it does not belong in the DCS `Scripts` folder. If TekConnect or a Serial Monitor has the panel connected, close that connection before programming and reconnect afterward.

## 6. Connect the panel with TekConnect

I use [TekConnect](https://github.com/tekcreations/TekConnect) to manage my DCS-BIOS USB serial connections. It shows connection status and offers automatic port connection.

1. Download `TekConnect.exe` from the [TekConnect releases page](https://github.com/tekcreations/TekConnect/releases) and run it on Windows.
2. Connect the Teensy using a USB **data** cable.
3. Open Windows **Device Manager → Ports (COM & LPT)** and identify its COM port. If unsure, unplug and reconnect it to see which port disappears and returns.
4. Select that port in TekConnect and connect it. Use serial settings appropriate to the panel firmware; this guide does not assume a baud rate for every controller.
5. Once the connection works, use TekConnect's automatic connection option if you want it to connect the port for you.

Only one application should use a panel's COM port at a time. Close Serial Monitor, other serial bridges, or the bench-testing app before connecting it in TekConnect. TekConnect manages the connection; it does not install DCS-BIOS, patch the Lua files, or program the Teensy.

## 7. Restart DCS and check the display

**Start DCS again after saving the Lua files.** Reloading a mission or flashing the Teensy alone does not reload the DCS export scripts.

Load an A-10C II mission, power the aircraft and ARC-210, and check that the physical display receives the game's radio information. A blank display before powered-radio data arrives is expected with this firmware. Test the frequency display first, then the relevant HQ/WOD pages.

| If this happens | Check this first |
| --- | --- |
| No panel COM port appears | USB data cable, USB connection, and Teensy firmware |
| TekConnect cannot open the port | Correct COM port; close any other application using it |
| Port connects but the display stays blank | Powered radio in an active mission, correct Saved Games profile, DCS-BIOS loader, and a full DCS restart |
| Ordinary radio data works but HQ/WOD or power-up details differ | The two `A-10C.lua` edits and the firmware/DCS-BIOS version match |
| It stopped working after a DCS-BIOS update | Check whether the update replaced the two local getter changes |

If an edit causes problems, close DCS, restore your backup, and restart it. For more detail, check `Logs\dcs.log` in the same Saved Games profile for Lua/export errors.

For testing without DCS, see my [bench-testing guide](Bench-Testing-App.md). Disconnect TekConnect from that panel before starting the bench app, and reconnect it afterward. For cables, hubs, and my USB setup, see [USB connections and powered hubs](USB-Connections-and-Powered-Hubs.md).

## After a DCS-BIOS update

Updates may replace `A-10C.lua`. Back up your files, install the update, and check the two getters again. Reapply only the needed return-line changes to the new version rather than replacing the entire updated module with an older file. Then fully restart DCS and retest.

Each aircraft and radio instance needs the correct DCS-BIOS mappings and compatible firmware. These instructions do not establish support for additional aircraft or complete the planned ARC-164 and ARC-186 builds.
