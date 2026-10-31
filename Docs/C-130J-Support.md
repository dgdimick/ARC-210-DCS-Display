[Back to the main project README](../README.md)

# C-130J ARC-210 support

**Last updated: October 30, 2026 at 9:48 PM MDT (America/Denver)**

I’m planning C-130J support as part of this ARC-210 project. After comparing the panel, I plan to reuse the same faceplate, controls, display, PCBs, and printed parts as my A-10C II build. Keeping the hardware and software work in one repository gives builders one place for files, questions, and updates.

**The same ARC-210 hardware should work with both the A-10C II and C-130J**, using the appropriate aircraft-specific firmware and DCS-BIOS mappings. C-130J implementation and testing are still pending; there is no C-130J firmware release or release date yet.

## Shared hardware

The plan uses the existing **Teensy 4.1, 3.5-inch LCD display, buttons, switches, and encoders**. I haven’t identified a need for a separate PCB design.

- [Parts list and hardware choices](../parts/README.md)
- [PCB files and manufacturing downloads](../PCBs/README.md)
- [Final 17-part STL and 3MF print set](../Supporting%20STL%27s/README.md#complete-17-part-print-set)
- [Assembly guide](Build%20Guide/README.md)

I have printed the complete 17-part set at 100% scale, and all parts passed test fitting. C-130J software compatibility still needs testing, and manufactured-board assembly and electrical testing remain on the main work list.

## Work needed for C-130J support

The main [Things that need to be completed list](Remaining-Work.md) tracks C-130J support. The work includes:

1. **Compare operation:** Check the aircraft’s current ARC-210 functions, controls, display pages, startup behavior, and menus against my existing panel.
2. **DCS-BIOS mappings:** Identify the C-130J radio inputs and outputs, check which are available, and document any needed export changes.
3. **Firmware adaptation:** Reuse the existing control and display code where practical and add the C-130J mappings. The amount of reusable code depends on the module’s behavior and available data.
4. **Menu system:** Adapt the pages and display values and test the complete menu system against the aircraft.
5. **Bench-testing app:** Add C-130J ARC-210 mappings and simulated data to my modified debug app so the panel can be tested independently.
6. **Testing in DCS:** Check controls, display updates, power changes, reconnection, and extended reliability, including operation with the other USB devices connected.
7. **Documentation:** Publish firmware loading, aircraft setup, DCS-BIOS changes, and troubleshooting instructions, linking to the shared hardware guides where they apply.

## DCS-BIOS and bench testing

My [step-by-step DCS-BIOS guide](DCS-BIOS.md) covers installation and TekConnect, the app I use to manage USB serial connections. **Its patched A-10C.lua is for the A-10C ARC-210 and does not configure the C-130J.** I’ll document any C-130J-specific changes here after checking them.

I use a [modified version of dcsBiosDebug](https://github.com/dgdimick/dcsBiosDebug/tree/arc210-working), based on [tldBear’s original app](https://github.com/tldBear/dcsBiosDebug). The existing A-10 shortcuts do not establish C-130J support. See the [bench-testing guide](Bench-Testing-App.md) for the current app.

## Shared setup and questions

- [USB connections and powered hubs](USB-Connections-and-Powered-Hubs.md)
- [My SIMPIT and test computer](My-SIMPIT-and-Test-Computer.md) — my setup, not minimum requirements.
- [Related radio projects](Related-Radio-Projects.md)

**Planning a build?** You’re welcome to ask questions or share ideas in [the main ARC-210 Discussions](https://github.com/dgdimick/ARC-210-DCS-Display/discussions), even if you haven’t started yet.

I am not affiliated with PC Flights. I chose their faceplate for my own cockpit build. This is a hobby flight-simulation project; the shared files retain the licenses stated in the main repository.
