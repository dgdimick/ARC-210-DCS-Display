[Back to the main project README](../README.md)

# DCS-BIOS setup — step by step

**Last updated: October 30, 2026 at 9:15 PM MDT (America/Denver)**

<!-- Refresh this timestamp whenever this page changes; use the actual current America/Denver date and time, including MST or MDT. -->

I use [DCS-Skunkworks DCS-BIOS](https://github.com/DCS-Skunkworks/dcs-bios) to send radio information between DCS and my panels, and [TekConnect](https://github.com/tekcreations/TekConnect) to manage their USB connections. I’ve put the setup steps here so you can follow along, even if you haven’t used DCS-BIOS before. I’ll show you where the files go, which two lines to change for my ARC-210 firmware, and how to connect and test the panel.

**Current status:** The published ARC-210 firmware is a display/menu preview. Complete physical-control integration and final in-DCS validation are still pending. The ARC-164 and ARC-186 are planned builds; these ARC-210 edits do not add firmware support for those radios.

## What each file does

| File or app | What it does | What you need to do |
| --- | --- | --- |
| DCS-BIOS folder | Gets cockpit data from DCS and accepts control commands | Install it in the Saved Games folder used by your copy of DCS |
| `Scripts/Export.lua` | Tells DCS to start DCS-BIOS and your other export tools | Add one DCS-BIOS loader line, keeping your existing integrations |
| `DCS-BIOS/lib/modules/aircraft_modules/A-10C.lua` | Defines the A-10 radio data exported by DCS-BIOS | Install my patched v0.11.8 file, or make the two edits yourself |
| `Master_Program.ino.hex` | Runs the ARC-210 display/menu firmware on the Teensy | Load it with Teensy Loader |
| TekConnect | Connects DCS-BIOS to the panel's USB COM port—the numbered connection Windows assigns to it | Select and connect the panel's port |

**You do not need to edit `BIOS.lua`, change DCS installation files, or put the ARC-210 changes into `Export.lua`.**

## 1. Close DCS and find the right folder

Fully close DCS before editing these files.

Open your Windows **Saved Games** folder and find the folder used by your copy of DCS. Common locations are shown below; replace `YOURNAME` with your Windows user name:

```text
C:\Users\YOURNAME\Saved Games\DCS\Scripts
C:\Users\YOURNAME\Saved Games\DCS.openbeta\Scripts
```

Use the profile your installation actually uses; the folder name may differ. This is not the DCS program folder under Steam or Program Files. Create the `Scripts` folder if it does not exist.

In File Explorer, turn on **View → Show → File name extensions** so you can distinguish `Export.lua` from `Export.lua.txt`. Open Lua files in a plain-text editor such as Notepad or Notepad++.

Before changing an existing file, copy it somewhere safe outside the DCS-BIOS folder. Back up both `Export.lua` and, if already installed, `A-10C.lua`.

## 2. Install DCS-Skunkworks DCS-BIOS

Download [DCS-Skunkworks DCS-BIOS](https://github.com/DCS-Skunkworks/dcs-bios). My ready-to-use `A-10C.lua` download below is based on **v0.11.8**, so use that release if you want to copy the file without editing it.

1. Open the [DCS-BIOS v0.11.8 release page](https://github.com/DCS-Skunkworks/dcs-bios/releases/tag/v0.11.8).
2. Download `DCS-BIOS_v0.11.8.zip` under **Assets** and extract it. For a different version, use its own aircraft file and follow the manual edits in Step 4 instead of copying my complete replacement.
3. Copy its `DCS-BIOS` folder into your active profile's `Scripts` folder.
4. Check that this file exists:

```text
Saved Games\DCS\Scripts\DCS-BIOS\BIOS.lua
```

Make sure you haven’t accidentally put one `DCS-BIOS` folder inside another, such as `DCS-BIOS\DCS-BIOS\BIOS.lua`. The [official installation instructions](https://github.com/DCS-Skunkworks/dcs-bios#installation) and [documentation](https://github.com/DCS-Skunkworks/dcs-bios/wiki) are there if you need more help.

## 3. Tell DCS to load DCS-BIOS

Open `Scripts\Export.lua` in your active Saved Games profile. If it does not exist, create it as a plain-text file named **Export.lua**.

Look for a line loading `DCS-BIOS\BIOS.lua`. If it is already there, leave it in place. Otherwise, add this line at the end:

```lua
dofile(lfs.writedir() .. [[Scripts\DCS-BIOS\BIOS.lua]])
```

**Add this line only once, and keep the existing lines for your other tools.** This line tells DCS to start DCS-BIOS. Save the file and check that its name is not `Export.lua.txt`.

### Download a DCS-BIOS-only Export.lua

If you don’t use WWT, SRS, or any other export tools, [download this Export.lua with just the DCS-BIOS line](https://raw.githubusercontent.com/dgdimick/ARC-210-DCS-Display/master/Docs/DCS-BIOS/DCS-BIOS-only/Export.lua). Right-click the link, choose **Save link as**, and save it as `Export.lua` in your active DCS Saved Games profile’s `Scripts` folder. DCS-BIOS must already be installed as described in Step 2.

If you already have an `Export.lua`, back it up first. If it contains entries for other tools, add the single DCS-BIOS line to your existing file instead of replacing it with this download.

### My Export.lua example

My file also starts WWT and SRS. This is an example of several integrations sharing one file:

```lua
local wwtlfs=require('lfs')
dofile(wwtlfs.writedir()..'Scripts/wwt/wwtExport.lua')
dofile(lfs.writedir() .. [[Scripts\DCS-BIOS\BIOS.lua]])

pcall(function() local dcsSr=require('lfs');dofile(dcsSr.writedir()..[[Mods\Services\DCS-SRS\Scripts\DCS-SimpleRadioStandalone.lua]]); end,nil)
```

[Download my Export.lua](https://raw.githubusercontent.com/dgdimick/ARC-210-DCS-Display/master/Docs/DCS-BIOS/Export.lua) by right-clicking the link and saving it as `Export.lua`.

Here is what each line does:

| Line | What it does | Do you need it? |
| --- | --- | --- |
| `local wwtlfs=require('lfs')` | Loads Lua’s file-system helper and gives it the local name `wwtlfs`. The next line uses it to find your DCS Saved Games folder. | Keep it with the WWT line if you use WWT. The DCS-BIOS line below does not depend on this local name. |
| `dofile(wwtlfs.writedir()..'Scripts/wwt/wwtExport.lua')` | Starts the WWT export script from your Saved Games folder. | Only if you use WWT and have that script installed. Omit both WWT lines if you don’t use it. |
| `dofile(lfs.writedir() .. [[Scripts\DCS-BIOS\BIOS.lua]])` | Starts DCS-BIOS so it can exchange cockpit data and commands with external hardware and software. | **Yes, for this radio project.** Include it once, with DCS-BIOS installed in the matching folder. |
| The final line beginning with `pcall(function()` | Finds your Saved Games folder and starts the DCS SimpleRadio Standalone (SRS) script. `pcall` catches an error in this call so it does not stop the rest of this file from running. | Only if you use SRS. Keep the complete line together. It is separate from the radio panel’s DCS-BIOS connection. |

**If you only need DCS-BIOS, the single DCS-BIOS `dofile` line shown above is enough.** If you already use WWT, SRS, or other export tools, keep their installed loader lines as well. Blank lines only make the file easier to read; they do not start anything.

You only need the DCS-BIOS loader line for this project. Do not replace your existing file with my example unless it matches your installed tools: my WWT line needs `Scripts/wwt/wwtExport.lua` to exist. The download does not apply the two radio changes in the next step.

<a id="arc-210-changes-to-the-dcs-bios-export"></a>

## 4. Add the ARC-210 changes to A-10C.lua

### Option A — download the file with both changes already added

For **DCS-BIOS v0.11.8**, I’ve prepared an `A-10C.lua` containing the two changes below. You don’t need to edit the code yourself.

1. Back up your installed `A-10C.lua` outside the DCS-BIOS folder while DCS is closed.
2. [Download the patched A-10C.lua](https://raw.githubusercontent.com/dgdimick/ARC-210-DCS-Display/master/Docs/DCS-BIOS/A-10C.lua). Right-click the link and choose **Save link as**, keeping the filename `A-10C.lua`.
3. Copy it into `Scripts\DCS-BIOS\lib\modules\aircraft_modules\` in your active Saved Games profile, replacing the existing file.
4. Check that the filename is **A-10C.lua**, not `A-10C.lua.txt`.
5. Skip the manual edits below and continue to **Step 5**. Fully restart DCS before testing in Step 7.

This replacement is for **v0.11.8**. It will overwrite any other local changes in your existing aircraft file, so use Option B if you have a different version or other customizations to keep. I’ve checked that only the two intended lines differ from the official v0.11.8 module and that its output addresses match the firmware. **This newly packaged replacement has not yet been tested in a live DCS session.** See the [file details, exact patch, and license](DCS-BIOS/README.md).

### Option B — make the two edits yourself

Open this file inside the DCS-BIOS folder you installed:

```text
Scripts\DCS-BIOS\lib\modules\aircraft_modules\A-10C.lua
```

These two lines tell DCS-BIOS which display information to send to my ARC-210 firmware:

- **WOD/HQ line:** Checks the WOD segment, HQ II segment, operating date, and active channel in that order, and sends the first available value. This lets the panel show the value supplied for the current radio page.
- **Power-up line:** Sends the radio’s `txt_RT` display value when it is available. Otherwise, if the power-up loader is active, it sends `PWR` so my firmware can recognize that startup state.

For each change below, find the named block and replace only the line starting with `return`. The surrounding lines stay the same.

**Leave the rest of each block exactly as it is.** Don’t add another copy or change the `2` or `3` on its closing line. Those numbers set how much text is sent, and changing them or moving the blocks can change where the firmware expects to find the data.

If your file already contains the replacement line, that change is already done. If you can’t find one of the blocks, check your DCS-BIOS version or ask in [Discussions](https://github.com/dgdimick/ARC-210-DCS-Display/discussions) before editing further.

#### A. WOD/HQ display value

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

#### B. Power-up display value

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

Save `A-10C.lua`. Both changes only read the game's display data. The hexadecimal addresses above are reference details for my tested setup; you do not need to type them into either file. If a different DCS-BIOS version puts the data at different addresses, I’ll need to check the firmware against that version.

## 5. Load the ARC-210 firmware

1. Download [Master_Program.ino.hex](../Firmware/Master%20Hex%20Files/Master_Program.ino.hex).
2. Follow the [Teensy Loader instructions](Loading-HEX-Files.md) to put it on the Teensy 4.1.
3. Read the [firmware notes](../Firmware/Master%20Hex%20Files/README.md) for the current features and limitations.

The HEX goes onto the Teensy; it does not belong in the DCS `Scripts` folder. If TekConnect or a Serial Monitor has the panel connected, close that connection before programming and reconnect afterward.

## 6. Connect the panel with TekConnect

Download [TekConnect](https://github.com/tekcreations/TekConnect), the app I use to manage my DCS-BIOS USB serial connections. It shows connection status and offers automatic port connection.

1. Download `TekConnect.exe` from the [TekConnect releases page](https://github.com/tekcreations/TekConnect/releases) and run it on Windows.
2. Connect the Teensy using a USB **data** cable.
3. Open Windows **Device Manager → Ports (COM & LPT)** and identify its COM port. If unsure, unplug and reconnect it to see which port disappears and returns.
4. Select that port in TekConnect and connect it. If it asks for a baud rate (connection speed), use the setting required by that panel’s firmware. I haven’t listed one setting for every controller here.
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

Updates may replace `A-10C.lua`. Back up your files, install the update, and check the two blocks from Step 4 again. If you move beyond v0.11.8, use the manual edits on the new version’s file rather than copying my v0.11.8 replacement over it. Make only the needed `return`-line changes, then fully restart DCS and retest.

Each aircraft and radio instance needs the correct DCS-BIOS mappings and compatible firmware. These instructions do not establish support for additional aircraft or complete the planned ARC-164 and ARC-186 builds.
