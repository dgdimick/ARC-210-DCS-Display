[Back to related radio projects](Related-Radio-Projects.md) · [Back to the main project README](../README.md)

# Possible future aircraft support

**Last updated: October 30, 2026 at 9:48 PM MDT (America/Denver)**

I’ll focus future support on aircraft with **physical radio control panels** that my hardware can reasonably represent. Sharing the radio's transceiver model alone is not enough.

## C-130J ARC-210 — part of the main project

I’m developing **[C-130J ARC-210 support](C-130J-Support.md)** in this repository, reusing the existing panel hardware with aircraft-specific firmware, DCS-BIOS mappings, and menus. Implementation and testing remain pending; see the [main work list](Remaining-Work.md) for remaining tasks.

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
