# ARC-210 menu-system preview

**Last updated: October 30, 2026 at 11:14 PM MDT (America/Denver)**

`Master_Program.ino.hex` is the current Teensy 4.1 / ILI9488 480 × 320 display firmware, published for menu-screen and navigation testing. It is not a complete implementation of every radio function.

## What to test

- HQ MORE sequence: OPER. DATE LOAD -> VERIFY WOD/MWOD -> WOD LOAD -> WOD ERASE -> HQ II FMT -> OPER. DATE LOAD -> VERIFY WOD/MWOD, repeating from there.
- HQ detail screens, including WOD and HQII number positioning.
- MENU opens the opening menu from the frequency screen and closes it from that opening menu only. On all deeper pages it is inactive.
- LOAD WOD number synchronization with DCS, including MLSK increments. In my test session, both displays reset to 20 on re-entry; this is supplied by DCS, not hard-coded.
- LOAD HQII FMT exits to frequency when a frequency knob or Channel knob moves.
- Existing COMSEC and RADIO SETTINGS screen navigation.

## Known limitations

I’m still working on some of the deeper SAT menus and investigating how they operate. I’d welcome input from anyone familiar with them.

Some detail-page actions remain unimplemented, including the WOD erase YES outcome. COMSEC BASEBAND/DIPHASE selection synchronization needs further work because the game label depends on underlying settings. Early aircraft-power startup screens may lag DCS; I’ve tested frequency-screen timing and power behavior. Found something that doesn’t behave as expected? Please share the menu page, the button or knob you used, and what happened on both the panel and the DCS screen. Those details make it much easier to track down. You can post your findings in Discussions.

## Loading and first startup

Open this HEX in Teensy Loader, enable Auto, and press the Teensy's programming button. Reconnect your DCS-BIOS serial bridge after flashing if needed. The display starts blank until it receives powered-radio data; a blank screen without powered-radio updates from DCS-BIOS or dcsBiosDebug is expected. The Loader's “1% used” is memory usage, not upload progress.

## Test the menu system without running DCS

Use the maintained [ARC-210 working branch of dcsBiosDebug](https://github.com/dgdimick/dcsBiosDebug/tree/arc210-working) to send simulated DCS-BIOS updates to the Teensy over USB serial. This lets you exercise the firmware's menu screens and navigation without launching DCS or loading a mission. See the [ARC-210 testing instructions](https://github.com/dgdimick/dcsBiosDebug/blob/arc210-working/ARC210_TESTING.md) for installation and the ARC-210 controls. The original executable does not contain those controls; use the Python script from the arc210-working branch. The manual JSON/Active Indicators procedure below describes the earlier generic workflow.

1. Load `Master_Program.ino.hex` onto the Teensy and connect the display hardware.
2. Close the DCS-BIOS serial bridge and any Serial Monitor using the Teensy's COM port.
3. In dcsBiosDebug, click **Find Serial Ports**, select the Teensy's COM port, and click **Connect**.
4. Load the matching A-10C aircraft JSON definition from your DCS-BIOS `doc/json` directory. Its output addresses and masks must match this firmware.
5. Add the ARC-210 power/master-switch and display-state outputs to **Active Indicators**. Send powered-radio values, including valid frequency/display data, and allow startup to finish. Connecting alone does not turn on the simulated radio; the screen can remain blank until the required data arrives.
6. Add the ARC-210 MENU, upper/middle/lower line-select key, and XMT/RCV button outputs. Simulate each press as **0 -> 1 -> 0**, allowing each state to be transmitted before changing it again. The firmware acts on the transition to 1, so release the button before testing another press.
7. Use these simulated updates to check the menu sequence, labels, layout, and navigation described above. Text outputs can be edited and sent with the **>** button; integer outputs can be changed with their sliders.

This is a bench test of the firmware's response to supplied data. dcsBiosDebug does not simulate DCS's radio logic or automatically provide the game's responses to hardware commands. Features such as WOD synchronization and game-dependent settings still need an in-DCS test. Disconnect dcsBiosDebug before reconnecting the normal DCS-BIOS serial bridge.

## DCS-BIOS export requirements

This firmware was tested with two local changes to the A-10C DCS-BIOS export. See the [dedicated DCS-BIOS page](../../Docs/DCS-BIOS.md#arc-210-changes-to-the-dcs-bios-export) for the required getters, backup and restart instructions, and TekConnect links.

## File verification

Firmware build: **September 23, 2026**, originally published September 24, 2026. The September 25 README update adds offline testing instructions; the HEX file has not changed or been recompiled.

SHA-256:

```text
607418aa3843d871f3b5ff98abc2ede7575086a80b34e2273da59c333469278c
```

## Estimated build cost

Thinking about building one? The [DIY parts purchasing estimate](../../parts/README.md#estimated-build-cost) gives you an idea of the budget, including the faceplate, display, electronics, and PCB fabrication. You’ll source the parts yourself, and I’m sharing the files and guidance to help along the way.

## Questions and community builds

**Building your own panel, or just looking around?** [Introduce yourself in the welcome discussion](https://github.com/dgdimick/ARC-210-DCS-Display/discussions/1) and tell us what you fly. Questions, ideas, and progress photos are all welcome—even if you’re only getting started.

Visit [GitHub Discussions](https://github.com/dgdimick/ARC-210-DCS-Display/discussions) to ask questions, share ideas, and post photos of your builds.
