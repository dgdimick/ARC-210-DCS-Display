[Back to the main project README](../README.md)

# ARC-210 Bench Testing App

**Last updated: November 1, 2026 at 4:01 AM MST (America/Denver)**

I’m developing one shared ARC-210 code base for the planned aircraft, starting with the A-10C II and C-130J. It will automatically select the appropriate controls and display data for the aircraft you fly, using aircraft-specific DCS-BIOS mappings. **The plan is to switch between supported aircraft without reflashing the Teensy—just fly the aircraft. This support is still being developed and tested and is not available as a completed feature yet.** See the [aircraft support plan](C-130J-Support.md).

<!-- Refresh this timestamp whenever this page changes; use the actual current America/Denver date and time, including MST or MDT. -->

For installation, Lua file changes, and connecting the panel to DCS with TekConnect, use the [DCS-BIOS setup guide](DCS-BIOS.md). This page covers testing with simulated data.

I use a [modified version of dcsBiosDebug](https://github.com/dgdimick/dcsBiosDebug/tree/arc210-working), based on [tldBear’s original, unmodified app](https://github.com/tldBear/dcsBiosDebug). I modified my version to provide better support for the ARC-210, adding buttons for menu testing and separate Frequency, Secondary, and Master controls. These controls send simulated DCS-BIOS data to the Teensy so I can test the panel without running DCS.

Download the **arc210-working** branch using **Code → Download ZIP**, extract it, and keep its `icons` folder beside the Python script. With Python 3 and Tkinter installed, open a terminal in that folder and run:

```cmd
python -m pip install numpy pyserial Pillow
python dcsBiosDebug.py
```

Use the Python script, including the `.py` extension; the original bundled executable does not include the ARC-210 controls. Select your Teensy's serial port and click **Connect**. Choose **2 - TR** and click **Set Master** for the normal radio switch position, or **0 - OFF** to test power off.

See the [full testing instructions and compatibility notes](https://github.com/dgdimick/dcsBiosDebug/blob/arc210-working/ARC210_TESTING.md). The shortcuts use fixed A-10C II addresses and send data to the hardware, not commands to DCS. Some firmware states require additional exports through the normal instrument controls.

## V1.5.4 — OFF → ON display-power fix

I tested an OFF → ON sequence with my physical panel and found that it completed initialization but then went blank. The bridge was sending the MASTER selector without the separate RT/display-power indication that DCS normally exports. **V1.5.4 fixes Set Master** to send a blank RT indication for OFF and restore RT for powered positions, while preserving the other selector bits sharing that address.

I confirmed the corrected sequence works with the existing **v0.1.3 Diagnostic HEX**; this bridge fix does not require reflashing the Teensy. To test it, choose **0 - OFF** and click **Set Master**, then choose **1 - TR-G** or **2 - TR** and click **Set Master** again. After initialization, the radio display should remain on. Live DCS testing is still pending.

## V1.5.3 — complete power-state shortcut and serial recovery

I tested the corrected bridge with v0.1.3 Diagnostic on my physical panel. The display worked, and the Teensy reported MASTER = TR, radio/display power on, and frequency 133.123. Live DCS testing is still pending.

Click **Find Serial Ports**, select the Teensy's port from the adjacent dropdown, then click **Connect**. Finding ports does not select one automatically. Load your DCS-BIOS `doc/json/A-10C.json` through **Choose DCSBios JSON file** to populate the categories; the JSON is not bundled and no DCS installation is needed to send simulated data.

Click **Power On / Send All** to send RT status, MAN mode, MASTER = TR, and the frequency. Then use **Set FREQ**, **Set Secondary**, **Set Master**, or the menu buttons to test individual updates. The shortcut does not emulate every game response or menu field.

### After unplugging, resetting, or reflashing the Teensy

After reconnecting the Teensy, select its serial port and click **Connect**, then click **Power On / Send All**. The bridge’s displayed settings do not automatically restore the complete radio state after the Teensy restarts. The diagnostic build can stay on its boot screen until it receives that state, even when the bridge already shows a powered-on MASTER setting.

I checked this on my panel: sending the complete state changed the Teensy’s diagnostic output from `master=0`, `radioOn=0`, and `freq=---.---` to `master=2`, `radioOn=1`, and a valid frequency, and the display left the boot screen. Simply closing and reopening the serial connection without restarting the Teensy may retain the existing state; that is different from unplugging its USB power.

The **Power On / Send All** shortcut sets **MAN** and **2 - TR** and sends the frequency shown in the bridge. Use **Set Secondary** or **Set Master** afterward if you want to test other positions.

V1.5.3 preserves neighboring selector bits when sending odd-length string fields such as RT and keeps the receive loop running after a USB disconnect. Reconnect the COM port after flashing. Use the [diagnostic HEX](../Firmware/Master%20Hex%20Files/ARC210_A-10C2_v0.1.3_Diagnostic.hex) for serial feedback; use the [clean preview](../Firmware/Master%20Hex%20Files/ARC210_A-10C2_v0.1.2_Preview.hex) for the planned live DCS test.
