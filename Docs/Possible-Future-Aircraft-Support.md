[Back to related radio projects](Related-Radio-Projects.md) · [Back to the main project README](../README.md)

# Possible future aircraft support

**Last updated: October 31, 2026 at 12:24 AM MDT (America/Denver)**

My current plan is to finish the **A-10C II (A-10C2) ARC-210 implementation**, then build and test the **ARC-164**, followed by the **ARC-186**. After those projects, I’ll return to additional aircraft support, starting with the **ARC-210 and C-130J**. Those aircraft extensions are later work, not the current implementation priority. I’m focusing on aircraft with a matching physical radio panel. **This order may change based on user feedback and interest.**

I’m focusing future support on aircraft with **physical radio control panels** that match my hardware, so the panel will be useful to builders flying those aircraft. I’ll compare the controls and displays as well as the radio model before deciding which aircraft to support.

## C-130J ARC-210 — part of the main project

I’m developing **[C-130J ARC-210 support](C-130J-Support.md)** in this repository, reusing the existing panel hardware and one shared code base with aircraft-specific DCS-BIOS mappings and menus. I’m developing automatic aircraft selection so switching between supported aircraft will not require reflashing the Teensy—just fly the aircraft. This support is still being developed and needs implementation and testing. See the [main work list](Remaining-Work.md) for remaining tasks.

## Using DCS trials for future aircraft support

For aircraft I don’t own, I plan to use the [DCS two-week trial program](https://www.digitalcombatsimulator.com/en/include/trial.php), where the module is eligible, to develop and test panel support. That could save me the cost of buying an aircraft just for development. I’ll check trial availability and prepare the mappings, shared firmware, and test plan before activating each trial so I can make the most of the time.

At about four hours a night, a two-week trial would give me roughly **56 hours**. I hope that will be enough for straightforward changes, but missing display exports or other complications could take longer. This is a development plan, not a promise that every aircraft can be finished within one trial.

I’ll also ask owners of those aircraft to help with ongoing testing, particularly after DCS or DCS-BIOS updates, and to report issues once my trial ends. If you own a candidate aircraft and would like to help, let me know in [Discussions](https://github.com/dgdimick/ARC-210-DCS-Display/discussions). My focus remains aircraft with a matching physical radio panel, and priorities may change based on user feedback and interest.

## Other aircraft to investigate

| Project | Aircraft | Assessment |
| --- | --- | --- |
| ARC-164 | F-16C Viper | **Strongest next candidate:** the UHF backup panel matches the type reproduced by the PC Flights faceplate. It operates with C&I set to BACKUP. |
| ARC-164 | F-5E Tiger II | **Worth investigating:** a dedicated ARC-164 panel, with control and display differences to check. |
| ARC-164 | C-101EB | **Worth investigating:** a dedicated ARC-164 panel, with a different layout and functions to compare. |
| ARC-164 | F-4E Phantom II | **Lower priority:** dedicated radio controls exist, but the substantially different arrangement needs comparison before considering support. |
| ARC-186 | A-10C | **Worth investigating alongside the A-10C II target:** dedicated AM and FM panels need the appropriate radio-instance mappings. |
| ARC-186 | CH-47F Chinook | **Conditional candidate only:** its ARC-186 backup control head needs a hardware, operating-mode, and DCS-BIOS comparison first. |

The A-10 family remains my main focus. **These are candidates for investigation, not currently supported aircraft or promised releases. Each additional aircraft requires separate DCS-BIOS mappings, firmware integration, and testing.** I’ll need to verify inputs, display outputs, and control behavior for each module.

See the [ARC-164 physical-panel assessment](https://github.com/dgdimick/ARC-164-DCS-Display#physical-radio-panels-and-possible-future-support) and [ARC-186 physical-panel assessment](https://github.com/dgdimick/ARC-186-DCS-Display#physical-radio-panels-and-possible-future-support) for sources and project-specific details.
