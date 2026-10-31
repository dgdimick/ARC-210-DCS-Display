[Back to the main project README](../README.md)

# C-130J ARC-210 support

**Last updated: October 31, 2026 at 12:22 AM MDT (America/Denver)**

My current plan is to finish the **A-10C II (A-10C2) ARC-210 implementation**, then build and test the **ARC-164**, followed by the **ARC-186**. After those projects, I’ll return to additional aircraft support, starting with the **ARC-210 and C-130J**. Those aircraft extensions are later work, not the current implementation priority. I’m focusing on aircraft with a matching physical radio panel. **This order may change based on user feedback and interest.**

I’m planning C-130J support as part of this ARC-210 project. After comparing the panel, I plan to reuse the same faceplate, controls, display, PCBs, and printed parts as my A-10C II build. Keeping the hardware and software work in one repository gives builders one place for files, questions, and updates.

I’m developing one shared ARC-210 code base for the planned aircraft, starting with the A-10C II and C-130J. It will automatically select the appropriate controls and display data for the aircraft you fly, using aircraft-specific DCS-BIOS mappings. **The plan is to switch between supported aircraft without reflashing the Teensy—just fly the aircraft. This support is still being developed and tested and is not available as a completed feature yet.**

I’ll label radio HEX downloads with the aircraft they support and a version number, increasing the version whenever I publish updated firmware so you can tell releases apart. Each new aircraft-support release will retain support for the previously supported aircraft. Adding an aircraft will require loading the updated HEX once, using the same Teensy Loader procedure as the first flash while the panel is connected by USB. After that, switching between aircraft included in that version will not require reflashing. **This cumulative aircraft support and automatic selection are still being developed and tested.**

## Shared hardware

The plan uses the existing **Teensy 4.1, 3.5-inch LCD display, buttons, switches, and encoders**. I haven’t identified a need for a separate PCB design.

- [Parts list and hardware choices](../parts/README.md)
- [PCB files and manufacturing downloads](../PCBs/README.md)
- [Final 17-part STL and 3MF print set](../Supporting%20STL%27s/README.md#complete-17-part-print-set)
- [Assembly guide](Build%20Guide/README.md)

I have printed the complete 17-part set at 100% scale, and all parts passed test fitting. C-130J software compatibility still needs testing, and manufactured-board assembly and electrical testing remain on the main work list.

## DCS-BIOS code findings

I reviewed the DCS-Skunkworks DCS-BIOS source at commit `85e3ba6b2e58fb9b1f7b1234b3e937db6ad47564`. These are source-code findings, not results from a C-130J mission test.

**The module exposes one ARC-210 control panel and one ARC-210 radio device**, rather than two numbered ARC-210 instances. UHF1/UHF2, VHF1/VHF2, and HF1/HF2 have their own separate frequency definitions. The ARC-210 frequency definition is:

```lua
C_130J:defineReadWriteRadio("RADIO_ARC210", 92, 7, 3, 1000, "ARC-210")
```

`RADIO_ARC210` provides a frequency output and an input to set the frequency through device **92**. The common radio helper reads `get_frequency()` and writes `set_frequency()`; it does not export the complete LCD. See the [C-130J radio definitions](https://github.com/DCS-Skunkworks/dcs-bios/blob/85e3ba6b2e58fb9b1f7b1234b3e937db6ad47564/Scripts/DCS-BIOS/lib/modules/aircraft_modules/C-130J.lua#L1982) and [radio helper implementation](https://github.com/DCS-Skunkworks/dcs-bios/blob/85e3ba6b2e58fb9b1f7b1234b3e937db6ad47564/Scripts/DCS-BIOS/lib/modules/Module.lua).

The panel mappings use device **69**, named `VOLUME_MANAGER`, for the clickable controls. DCS-BIOS handles the distinction between that control device and radio device 92.

| Panel function | C-130J mapping |
|---|---|
| Five frequency selectors | `ARC210_100MHZ`, `ARC210_10MHZ`, `ARC210_1MHZ`, `ARC210_100KHZ`, `ARC210_25KHZ` |
| Channel knob | `ARC210_CHNL_KNOB` |
| Operating-mode switch | `ARC210_OPER_MODE` |
| Frequency-mode switch | `ARC210_FREQ_MODE` |
| Squelch | `ARC210_SQUELCH_SWITCH` |
| RT selection | `ARC210_RT_SELECT` |
| Buttons | TOD SND/RCV, GPS, three LSKs, MENU/TIME, AM/FM, XMT/REC, OFFSET/RCV, ENTER, and brightness increase/decrease |

See the [ARC-210 panel definitions](https://github.com/DCS-Skunkworks/dcs-bios/blob/85e3ba6b2e58fb9b1f7b1234b3e937db6ad47564/Scripts/DCS-BIOS/lib/modules/aircraft_modules/C-130J.lua#L1725). `RT SELECT` is mapped, but these definitions alone do not establish which additional RTs it selects or how their display data is exposed. I still need to check that in the aircraft.

**The main gap is the LCD and menu exports.** I found no ARC-210 exports for menu text, active preset, selected RT, modulation label, or the other screen fields in this C-130J source. The [A-10C implementation](https://github.com/DCS-Skunkworks/dcs-bios/blob/85e3ba6b2e58fb9b1f7b1234b3e937db6ad47564/Scripts/DCS-BIOS/lib/modules/aircraft_modules/A-10C.lua#L1141) parses its ARC-210 display and exports those fields individually. Its indicator number and field names cannot simply be assumed to apply to the C-130J.

The existing controls and frequency export give me a useful starting point. For full LCD support, I need to inspect the C-130J's live display indications and available parameters, identify the missing fields, add the necessary DCS-BIOS exports, and test them against the cockpit. If some data is unavailable, I will document that limitation. Full support will require more than changing the A-10's control names and addresses.

## Helios findings and LCD export plan

I found a concrete starting point in Helios's C-130J implementation. Its [C-130J export script](https://github.com/HeliosVirtualCockpit/Helios/blob/master/Aircraft%20C-130J%20Plugin/Interfaces/ExportC130JFunctions.lua) reads **indicator 44** using `helios.encodeIndication(44)` and sends the indication data to its [ARC-210 display parser](https://github.com/HeliosVirtualCockpit/Helios/blob/master/Aircraft%20C-130J%20Plugin/Interfaces/Functions/ARC210Display.cs). This is text-data handling, which gives me a useful reference for adding DCS-BIOS exports.

| Display content | Fields handled by the Helios parser |
|---|---|
| Frequency | `freq_label_mhz`, `dot_mark`, `freq_label_khz` |
| Selected RT | `txt_RT` |
| Active preset | `active_channel` |
| Modulation | `modulation_label` |
| Transmit/receive label | `xmit_recv_label` |
| Menu and soft-key labels | `top_line_label`, `mid_line_label`, `bot_line_label` |
| Security information | `comsec_mode`, `comsec_submode`, `ky_label`, `ky_submode_label` |
| ECCM and segment information | `active_eccm_channel_index`, `WOD_segment`, `HQII_segment` |
| SATCOM information | `satcom_top_channel_label`, `satcom_channel_type_label`, `satcom_connection_status`, `satcom_activated_status`, `satcom_activated_time_remain` |

The parser also handles startup screens, multiline values, alternate field names, and page-dependent labels. It clears values that are no longer present. These names are findings from the Helios source, not a guarantee that every field is available or correct in my installed DCS version.

The [Helios ARC-210 viewport patch](https://github.com/HeliosVirtualCockpit/Helios/blob/master/Patching/Patches/DCS/002_009_00028_26385_00000/Viewports/mods/Aircraft/C130J/Cockpit/Scripts/ARC_210/init.lua.gpatch) adds viewport handling and screen positioning; it does not add the text fields listed above. Based on that, my first approach will be a **DCS-BIOS-only change**, checking whether the existing indication already exposes the data I need.

My implementation plan is to:

1. Confirm the ARC-210 indicator number in the installed C-130J cockpit scripts and capture its live `list_indication()` output. Indicator 44 is the starting point from Helios, not an assumed permanent ID.
2. Read and parse the indication once per DCS-BIOS export cycle, using `Module.parse_indication()` if it correctly handles the captured pages. Compare its results with the raw data, especially multiline values and changing field names.
3. Add named string outputs in `C-130J.lua` for the frequency components, preset, selected RT, modulation, menu labels, and other required LCD fields. Choose suitable lengths and allocate addresses through DCS-BIOS's normal helpers, then update the Teensy mappings to match.
4. Normalize page-dependent fields where needed and clear missing fields so previous menu text does not remain on the LCD. Verify power-off blanking and startup screens too.
5. Add captured page samples to the bench-testing workflow, then test normal radio operation, RT selection, frequency changes, and all available menu pages against the cockpit. Document any data that remains unavailable.

**This is an implementation plan, not a working or tested export release.** DCS is on my other computer, so I still need its C-130J cockpit scripts and live indication captures to verify the indicator, field contents, and parser behavior. The Helios references help identify the route; they do not require builders to install Helios for the planned DCS-BIOS connection.

## Work needed for C-130J support

The main [Things that need to be completed list](Remaining-Work.md) tracks C-130J support. The work includes:

1. **Compare operation:** Check the aircraft’s current ARC-210 functions, controls, display pages, startup behavior, and menus against my existing panel.
2. **DCS-BIOS mappings and missing LCD exports:** Verify the existing panel controls and `RADIO_ARC210` frequency export in DCS. Follow the [LCD export plan](#helios-findings-and-lcd-export-plan): verify indicator 44 against the installed module, capture and parse live indications, add named string outputs for the required LCD and menu fields, and clear fields that disappear between pages. Check RT SELECT behavior and document any unavailable data or export changes.
3. **Shared firmware and automatic aircraft selection:** Add the C-130J mappings and menu behavior to the same code base as the A-10C II. Detect the aircraft automatically and switch mappings without requiring users to reflash the Teensy. Implement and test aircraft changes, including clearing stale controls and display data. This is planned work, not a completed feature.
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
