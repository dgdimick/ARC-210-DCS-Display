# ARC-210 menu-system preview

**Last updated: November 1, 2026 at 12:23 AM MDT (America/Denver)**

`ARC210_A-10C2_v0.1.2_Preview.hex` is the current Teensy 4.1 / ILI9488 480 × 320 display firmware, published for menu-screen and navigation testing. It is not a complete implementation of every radio function.

## Bench diagnostic build — v0.1.3

[Download ARC210_A-10C2_v0.1.3_Diagnostic.hex](ARC210_A-10C2_v0.1.3_Diagnostic.hex) if the display stays black or you need to trace bridge communication. It turns on the GPIO 4 backlight, shows its information screen immediately, and prints USB diagnostics once a second. Those messages show received bytes, MASTER, radio/display power, and frequency.

**Use this diagnostic for bench testing. Use the clean v0.1.2 preview for the upcoming live DCS test; that test is still pending.** I verified that the diagnostic display appeared and the corrected bridge delivered TR, powered-radio status, and frequency changes. [Diagnostic source](../Source/Diagnostics/Master_Program/README.md) is included. Nothing here adds full physical-control integration.

For bridge testing, load the aircraft JSON to populate categories, select the Teensy's COM port, click Connect, and click **Power On / Send All** in [V1.5.3 of my modified tester](https://github.com/dgdimick/dcsBiosDebug/tree/arc210-working). This sends RT status, MAN mode, MASTER = TR, and the selected frequency. Loading a JSON file alone does not send radio power.

## Aircraft labels and cumulative releases

| HEX filename | Aircraft coverage and release status |
| --- | --- |
| [ARC210_A-10C2_v0.1.2_Preview.hex](ARC210_A-10C2_v0.1.2_Preview.hex) | Current A-10C II (A-10C2) display/menu preview; full radio-control integration remains incomplete |
| `ARC210_A-10C2_C-130J_v0.2.0_Preview.hex` | Example filename for a future cumulative A-10C2 and C-130J preview; version illustrative, not available yet |

I’ll label radio HEX downloads with the aircraft they support and a version number, increasing the version whenever I publish updated firmware so you can tell releases apart. Each new aircraft-support release will retain support for the previously supported aircraft. Adding an aircraft will require loading the updated HEX once, using the same Teensy Loader procedure as the first flash while the panel is connected by USB. After that, switching between aircraft included in that version will not require reflashing. **This cumulative aircraft support and automatic selection are still being developed and tested.**

Later release filenames will list the additional aircraft while retaining the earlier aircraft labels. A filename describes the aircraft covered by that release; the preview label and release notes describe any unfinished functions. The C-130J entry above is a naming plan, not a download or a claim of completed support.

The previous [v0.1.0 preview](ARC210_A-10C2_v0.1.0_Preview.hex) preserves the original September 23 build, formerly named `Master_Program.ino.hex`. It remains available for comparison or rollback. The current v0.1.2 preview adds GPIO 4 backlight initialization to the v0.1.1 startup-label build. Earlier releases remain available for rollback.

## Firmware version numbers

The current download is **v0.1.2**. Its information screen shows **VERSION 0.1.2 PREVIEW** and **AIRCRAFT: A-10C2** during the existing radio-switch startup delay. The display still waits for powered-radio data; this does not add an always-visible USB plug-in screen. I still need to test this new build on the physical panel and in DCS.

I’ll use **major.minor.patch** version numbers: patch updates for fixes, minor updates for added features or aircraft, and major updates for substantial changes. Versions starting with **0** are still in development, and the **Preview** label makes unfinished releases easy to recognize. Each published firmware update will get a new version number; earlier aircraft support will be retained.

For example, a future `ARC210_A-10C2_C-130J_v0.2.0_Preview.hex` would list both aircraft and its version. That is an example, not a released file or a promised version number. Check the filename and release notes before flashing, and keep a note of the version you loaded. The current startup labels come from the shared `FirmwareInfo.h` definition in the [published source](../Source/Master_Program/README.md). I’ll update that definition with each release so the screen and filename agree.

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

1. Load `ARC210_A-10C2_v0.1.2_Preview.hex` onto the Teensy and connect the display hardware.
2. Close the DCS-BIOS serial bridge and any Serial Monitor using the Teensy's COM port.
3. In dcsBiosDebug, click **Find Serial Ports**, select the Teensy's COM port, and click **Connect**.
4. Load the matching A-10C aircraft JSON definition from your DCS-BIOS `doc/json` directory. Its output addresses and masks must match this firmware.
5. Add the ARC-210 power/master-switch and display-state outputs to **Active Indicators**. Send powered-radio values, including valid frequency/display data, and allow startup to finish. Connecting alone does not turn on the simulated radio; the screen can remain blank until the required data arrives.
6. Add the ARC-210 MENU, upper/middle/lower line-select key, and XMT/RCV button outputs. Simulate each press as **0 -> 1 -> 0**, allowing each state to be transmitted before changing it again. The firmware acts on the transition to 1, so release the button before testing another press.
7. Use these simulated updates to check the menu sequence, labels, layout, and navigation described above. Text outputs can be edited and sent with the **>** button; integer outputs can be changed with their sliders.

This is a bench test of the firmware's response to supplied data. dcsBiosDebug does not simulate DCS's radio logic or automatically provide the game's responses to hardware commands. Features such as WOD synchronization and game-dependent settings still need an in-DCS test. Disconnect dcsBiosDebug before reconnecting the normal DCS-BIOS serial bridge.

## DCS-BIOS export requirements

The earlier preview was tested with two local changes to the A-10C DCS-BIOS export. See the [dedicated DCS-BIOS page](../../Docs/DCS-BIOS.md#arc-210-changes-to-the-dcs-bios-export) for the required getters, backup and restart instructions, and TekConnect links.

## File verification

Both new builds compiled successfully for Teensy 4.1 using Teensy platform 1.62.0, DCS-BIOS 0.3.13, and ILI9488_t3 1.0. The clean v0.1.2 preview includes backlight initialization but still needs a live DCS test. I confirmed the physical display and USB radio-data updates with v0.1.3 Diagnostic and the V1.5.3 bridge. This is not proof that all menus or physical controls work in DCS.

SHA-256:

```text
3e9267740d68a6af26e31c8a4070adfa0f47bf9d06d09654836d0d0966120ea5  ARC210_A-10C2_v0.1.2_Preview.hex
d8267d7d2fb09f721ca710171a5b4c64c2f819f585cb17723d73561f7359acb9  ARC210_A-10C2_v0.1.3_Diagnostic.hex
```

## Estimated build cost

Thinking about building one? The [DIY parts purchasing estimate](../../parts/README.md#estimated-build-cost) gives you an idea of the budget, including the faceplate, display, electronics, and PCB fabrication. You’ll source the parts yourself, and I’m sharing the files and guidance to help along the way.

## Questions and community builds

**Building your own panel, or just looking around?** [Introduce yourself in the welcome discussion](https://github.com/dgdimick/ARC-210-DCS-Display/discussions/1) and tell us what you fly. Questions, ideas, and progress photos are all welcome—even if you’re only getting started.

Visit [GitHub Discussions](https://github.com/dgdimick/ARC-210-DCS-Display/discussions) to ask questions, share ideas, and post photos of your builds.
